# idkeyd.awk,  5 Sep 03
#
#
BEGIN {
	}

	{
	num_key_ids[$1 " ,, " $2]++
	next
	}

END {
	TEMP_FILE="TeMp.tEmP"
	printf("") > TEMP_FILE
	for (i in num_key_ids)
	   print i " ,, " num_key_ids[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: idkeyd.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	system("rm " TEMP_FILE)
	}

