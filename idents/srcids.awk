# srcids.awk,  1 Aug 03
#
# Count the number of different identifiers
#
BEGIN {
	}

$0 == "__E__O__F__" {
	src_num_ids[num_ids]++
	num_ids=0
	src_uniq_ids[uniq_ids]++
	uniq_ids=0
	delete id_seen
	next
	}

	{
	num_ids++
	id_seen[$1]++
	if (id_seen[$1] != 1)
	   uniq_ids++
	next
	}

END {
	TEMP_FILE="TeMp.tEmP"
	printf("") > TEMP_FILE
	for (i in src_num_ids)
	   print i " " src_num_ids[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: srcnumids.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in src_uniq_ids)
	   print i " " src_uniq_ids[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: srcuniqids.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	system("rm " TEMP_FILE)
	}

