# enum.awk, 27 Jul 03
#
# enumeration information
#

BEGIN {
	}

$0 ~ /\{/ {
	gsub("NEW_LINE", "", $0)
	num_econsts=1
	for (i=4; i < NF; i++)
	   if ($i == ",")
	      if ($(i+1) != "}")
	         num_econsts++
	total_econsts[num_econsts]++
	next
	}

	{
	next
	}

END {
	TEMP_FILE="TeMp.tEmP"
	printf("") > TEMP_FILE
	for (i in total_econsts)
	   print i " " total_econsts[i] >> TEMP_FILE
	print "File: econst.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	system("rm " TEMP_FILE)
	}

