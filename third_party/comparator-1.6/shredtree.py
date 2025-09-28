#!/usr/bin/env python
#
# shredtree -- generate hash list in SCF-A format for a given source tree

import sys, os, os.path, re, md5, getopt, struct

whitespace = re.compile(r"[ \t\n]+")

def eligible(file):
    "Is a file eligible for comparison?"
    (st_mode, st_ino, st_dev, st_nlink, st_uid, st_gid, st_size,
     st_atime, st_mtime, st_ctime) = os.stat(file)
    if st_size <= 0:
        return False
    elif c_only:
        return filter(lambda x: file.endswith(x), ('.c','h','.txt'))
    else:
        return True

def normalize(line):
    if ws:
        return whitespace.sub('', line)
    else:
        return line

def emit_chunk(display, file, linecount):
    startline = display[0][1]
    if debug:
        sys.stderr.write("%% %s:%d-%d\n" % (file, startline, linecount))
    m = md5.new()    
    for line in display:
        if debug:
            sys.stderr.write(`line[0]` + "\n")
        m.update(line[0])
    return struct.pack("!HH", startline, linecount) + m.digest()

def shredfile(file):
    "Emit shred tuples corresponding to a specified file."
    fp = open(file, "r")
    display = []
    outdata = ""
    chunk_count = accepted = linecount = 0;
    while True:
        line = fp.readline()
        if not line:
            break
	linecount += 1;
        line = normalize(line)
        if not line:
	    continue;
	accepted += 1

	# create new shred
        display.append((line, linecount))

	# flush completed chunk
        if accepted >= shredsize:
	    outdata += emit_chunk(display, file, linecount)
            chunk_count += 1

	# shreds in progress are shifted down */
        if len(display) >= shredsize:
            display = display[1:]

    fp.close()
    if linecount < shredsize:
	outdata += emit_chunk(display, file, linecount)
        chunk_count += 1
    # Write the actual data
    sys.stdout.write(file + "\n" + struct.pack("!H", chunk_count) + outdata)

if __name__ == '__main__':
    try:
        (optlist, args) = getopt.getopt(sys.argv[1:], 'cd:hs:wx')
    except getopt.GetoptError:
        sys.stderr.write("usage: shredtree [-c] [-d dir] [-w] [-s shredsize] tree\n")
        sys.exit(2)
    shredsize = 5
    ws = debug = c_only = False
    for (opt, val) in optlist:
        if opt == '-c':
            c_only = True
        elif opt == '-d':
            os.chdir(optarg);
        elif opt == '-h':
	    sys.stderr.write("usage: shredtree [-c] [-s size] [-w] path\n");
	    sys.stderr.write(" -c      = do .c, .h, and .txt files only.\n");
            sys.stderr.write(" -d dir  = go to directory before digesting\n");
	    sys.stderr.write(" -h      = help (display this message).\n");
	    sys.stderr.write(" -s size = set shred size (default %d)\n",
		    shredsize);
	    sys.stderr.write(" -w      = remove whitespace.\n");
	    sys.stderr.write(" -x      = debug, display chunks in output.\n");
	    sys.exit(0);
        elif opt == '-s':
            shredsize = int(val)
        elif opt == '-w':
            ws = True
        elif opt == '-x':
            debug = True
    if args:
        print "#SCF-A 1.1"
        print "Generator-Program: shredtree.py 1.0"
        print "Hash-Method: MD5"
        print "Normalization: %s" % ",".join(normalization);
        print "Shred-Size: %d" % shredsize
        normalization = []
        if ws: normalization.append("remove_whitespace")
        if not normalization:
            normalization.append("none")
        print "%%"
        totalbytes = 0
        filenames = []
        for root, dirs, files in os.walk(args[0]):
            for file in files:
                fullpath = os.path.join(root, file)
                if eligible(fullpath):
                    filenames.append(fullpath)
        filenames.sort()
        sys.stdout.write(struct.pack("!i", len(filenames)))
        for path in filenames:
            totalbytes = totalbytes + shredfile(path)
        sys.stdout.write(struct.pack("!i", totalbytes))
# End
