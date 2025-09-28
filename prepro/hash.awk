# hash.awk, 26 Apr 03
#
# Count # and ## usage
#

BEGIN {
	}

$1 == "#DEFINE"  {
	#
	# truncate last two tokens from input
	trunc_line=""
	for (pp=1; pp < NF-1; pp++)
	   trunc_line=trunc_line " " $pp
	gsub(" COMMENT_NL", "", trunc_line)
	gsub(" COMMENT", "", trunc_line)
	gsub(" NEW_LINE", "", trunc_line)
	$1=""
	$0=trunc_line
	if ($0 ~ / \# /) {
	   num_def_hash++
	   uniq_hash[$0]++
	   }
	if ($0 ~ / \#\# /) {
	   num_def_hashhash++
	   uniq_hashhash[$0]++
	   for (h=3; h < NF-1; h++)
	      if ($h == "##")
		 {
	         num_hashhash++
		 hashhash[$(h-1) " ## " $(h+1)]++
		 #
		 # Look for TOK ## TOK ## TOK
		 if ($(h-2) == "##") {
		    hhhh[$(h-3) " " $(h-2) " " $(h-1) " " $h " " $(h+1)]++
		    same_operand++
		    }
		 }
	   }
	num_def++
	next
	}

	{
	next
	}

#$1 ~ /^\#\#\#/  {

END {
    print "num def " num_def " num def hash " num_def_hash " num def hashhash " num_def_hashhash
    print "#"
    for (h in uniq_hash)
       print uniq_hash[h] " " h
    print "##"
    for (h in uniq_hashhash)
       print uniq_hashhash[h] " " h

    print "## operands " num_hashhash " " same_operand
    TEMP_FILE="hh" systime()
    printf("") > TEMP_FILE
    for (h in hashhash)
       print hashhash[h] " " h >> TEMP_FILE
    close(TEMP_FILE)
    system("sort -gr < " TEMP_FILE)
    system("rm " TEMP_FILE)
    print "###"
    for (h in hhhh)
       print hhhh[h] " " h
    }

