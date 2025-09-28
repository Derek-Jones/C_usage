# cntids.awk, 24 Dec 02
#
# Count the number of different identifiers
#
BEGIN {
	}

$1 == "__E__O__F__"  {
	next
	}

	{
	id_seen[$1]++
	next
	}

END {
	TEMP_FILE=systime() ".ci"
	
	printf("") > TEMP_FILE
	for (i in id_seen)
	   print i " " id_seen[i] >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -rgk 2 < " TEMP_FILE)

	system("rm " TEMP_FILE)
	}

