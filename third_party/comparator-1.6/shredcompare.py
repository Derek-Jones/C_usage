#!/usr/bin/env python
#
# shredcompare -- find common cliques in shred lists
#
import os, sys, time, stat, getopt, bsddb, struct

class SCF:
    "SCF-A file metadata container."
    def __init__(self, name):
        self.name = name
        self.fp = open(name)
        shif.totallines = 0
        self.comments = []
        self.hashcount = 0
        id = self.fp.readline()
        if not id.startswith("#SCF-A "):
            sys.stderr.write("shredcompare: %s is not a SCF-A file."%self.fp.name)
            sys.exit(1)
        while True:
            line = self.fp.readline()
            if line == '%%\n':
                break
            (tag, value) = line.split(":")
            value = value.strip()
            if tag == "Normalization":
                self.normalization = value.split(", ")
                self.normalization.sort()
            elif tag == "Shred-Size":
                self.shredsize = int(value)
            elif tag == "Hash-Method":
                self.hash = value
            elif tag == "Generator-Program":
                self.generator = value
            elif tag == "Comment":
                self.comments.append(value)
    def __check_match(self, other, attr):
        if getattr(self, attr) != getattr(other, attr):
            sys.stderr.write("shredcompare: %s of %s and %s doesn't match." \
                             % (attr, self.name, other.name))
            sys.exit(1)
    def compatible(self, other):
        self.__check_match(other, 'normalization')
        self.__check_match(other, 'shredsize')
        self.__check_match(other, 'hash')

class Shred:
    "Represent a range of lines."
    def __init__(self, file, start, end):
        self.file = file
        self.start = start
        self.end = end
    def dump(self):
        rfp = open(self.file)
        for i in range(self.start):
            rfp.readline()
        text = ""
        for i in range(self.start, self.end):
            text += rfp.readline()
        rfp.close()
        return text
    def __range(self):
        return range(self.start, self.end)
    def intersects(self, other):
        return self.file == other.file and \
           self.start in other.__range() or other.start in self.__range()
    def merge(self, other):
        self.start = min(self.start, other.start)
        self.end   = max(self.end,   other.end)
    # Make these sortable
    def __cmp__(self, other):
        return cmp((self.file, self.start, self.end), (other.file, other.start, other.end))
    def __hash__(self):
        return hash((self.file, self.start, self.end))
    # External representation
    def __str__(self):
        # 0-origin line numbers internally, 1-origin externally.
        return "%s:%d-%d" % (self.file, self.start, self.end)
    __repr__ = __str__

hashcount = total = 0

def merge_hashes(shif, dict):
    "Read and merge hashes corresponding to one file."
    global hashcount
    file = shif.fp.readline()
    if not file:
        return False
    file = file.strip()
    # Record count comes right after the filename
    (record_count,) = struct.unpack("!H", shif.fp.read(2))
    while record_count > 0:
        record_count -= 1
        # 4 bytes of start line number + 4 of end line number + 16 of MD5 hash
        (start, end, hashval) = struct.unpack("!HH16s", shif.fp.read(20))
        if dict.has_key(hashval):
            oldval = dict[hashval]
        else:
            oldval = ""
        dict[hashval] = oldval + file + "\t" + `start` + "\t" + `end` + "\n"
        hashcount += 1
        shif.hashcount += 1
        if hashcount % 10000 == 0:
            sys.stderr.write("\b\b\b%02.0f%%" % (shif.fp.tell() / (total * 0.01)))
    (shif.totallines,) = struct.unpack("!i", shif.fp.read(4))
    return True

def item_factory(db):
    "Hide the ugliness that is sequential DB access in a generator."
    try:
        yield db.first()
        while True:
            yield db.next()
    except:
        yield None

mark_time = None

def report_time(legend=None):
    "Report time since last call."
    global mark_time
    endtime = time.time()
    if mark_time:
        elapsed = endtime - mark_time 
        hours = elapsed/3600; elapsed %= 3600
        minutes = elapsed/60; elapsed %= 60
        seconds = elapsed
        sys.stderr.write("%% %s: %dh, %dm, %ds\n" % \
            (legend, hours, minutes, seconds))
    mark_time = endtime

def filesize(file):
    return os.stat(file)[stat.ST_SIZE]

def treefromfile(file):
    return file.split("/")[0]

if __name__ == '__main__':
    try:
        (optlist, args) = getopt.getopt(sys.argv[1:], 'd')
    except getopt.GetoptError:
        sys.stderr.write("usage: shredcompare [-h] file\n")
        sys.exit(2)
    for (opt, val) in optlist:
        if opt == '-h':
	    sys.stderr.write("usage: shredcompare [-d] file\n");
	    sys.stderr.write(" -h      = help (display this message).\n");
	    sys.exit(0);

    report_time()
    shiflist = []
    # Read input metadata
    for file in args:
        shiflist.append(SCF(file))
    # Metadata sanity check
    for i in range(len(args)-1):
        shiflist[i].compatible(shiflist[i+1])
    # Compute amount of data to be read
    total = sum(map(lambda x: filesize(x.name) - x.fp.tell(), shiflist))
    # Read in the filecounts, though this implementation won't use them.
    for shif in shiflist:
        shif.fp.read(struct.calcsize("!i"))
    # Read in all hashes
    hashdict = bsddb.hashopen(None, 'c')
    for shif in shiflist:
        sys.stderr.write("Reading %s...   " % shif.name)
        while merge_hashes(shif, hashdict):
            continue
        sys.stderr.write("\b\b\b100%%...done, %d entries\n" % shif.hashcount)
    report_time("Hash merge done, %d entries" % hashcount)
    # Nuke all unique hashes
    nonuniques = 0
    db_cursor = item_factory(hashdict)
    while True:
        item = db_cursor.next()
        if not item:
            break
        (key, match) = item
        if match.count("\n") == 1:
            del hashdict[key]
        else:
            nonuniques += 1
    report_time("%d range groups after removing unique hashes" % nonuniques);
    # Turn the remaining matches into match objects, because we're
    # going to want to do logic on them.  We deferred it this long
    # to lower memory usage.
    matches = []
    db_cursor = item_factory(hashdict)
    while True:
        item = db_cursor.next()
        if not item:
            break
        (key, match) = item
        # Decode the multiline strings we had to create to get around
        # the bsddb key and value constraint.
        match = map(lambda x: x.split("\t"), match.rstrip().split("\n"))
        match = map(lambda x: Shred(x[0], int(x[1]), int(x[2])), match)
        # Ignore matches in which all ranges are from the same tree
        for i in range(len(match)):
            if treefromfile(match[i].file) != treefromfile(match[(i+1)%len(match)].file):
                break
        else:
            continue
        # Test passed, record it. Sort first so the output will be in canonical form.
        match.sort()
        matches.append(match)
    # We're done with the database file.
    hashdict.close()
    report_time("Match objects converted")
    # Merge overlapping ranges if possible.
    # This is O(n**2) in the number of matching chunks.
    # Should performance ever become a problem, break this up into
    # separate passes over the chunks in each file. (Would correspond
    # to eliminating a bunch of off-diagonal entries.)
    # FIXME: code currently only does two-way merge.
    retry = True
    while retry:
        retry = False
        #print "Matches at start:", matches
        for i in range(len(matches)):
            for j in range(len(matches)):
                if i >= j:
                    continue
                # Neither shred must have been deleted
                if not matches[j] or not matches[i]:
                    continue
                #print "Checking:", matches[j], matches[i]
                # Toss them out if they don't intersect
                if not (matches[j][0].intersects(matches[i][0]) and \
                	matches[j][1].intersects(matches[i][1])):
                    #print "alpha and beta don't intersect"
                    continue
                # Merge lower chunk into upper; delete lower
                #print "Found a merge:", matches[j], matches[i]
                matches[j][0].merge(matches[i][0])
                matches[j][1].merge(matches[i][1])
                matches[i] = None
                retry = True
    matches = filter(lambda x: x, matches)
    print "Before sorting:", matches
    matches.sort()
    print "After sorting:", matches
    report_time("Reduction done")
    # OK, dump all matches.
    print "#SCF-B 1.1"
    print "Hash-Method: MD5"
    print "Normalization:", ",".join(shiflist[0].normalization)
    print "Merge-Program: shredcompare.py 1.1"
    print "Shred-Size: %d" % shiflist[0].shredsize
    print "%%"
    for shif in shiflist:
        print "%s:%d" % (shif.name,shif.totallines)
    print "%%"
    # FIXME: do something appropriate with comments
    for match in matches:
        for range in match:
            print `range`
        print "%%"

