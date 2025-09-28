# sortlastcol.awk, 11 Aug 03
#
# Sort a list based on a numeric value in the right most column

BEGIN {
	swap_first="\"{for (n=2; n <=NF ; n++) printf(\\\"%s \\\", \\$n); print \\$1; next}\""
	#print swap_first
	}

	{
	num_lines++
	line[num_lines]=$0
	next
	}

END {
	TEMP_FILE="sl" systime()
	printf("") > TEMP_FILE
	num_cols=split(line[l], col_val, " ")
	# make the last column entry the first one
	for (l=1; l <= num_lines; l++) {
	   num_cols=split(line[l], col_val, " ")
	   printf("%s", col_val[num_cols]) >> TEMP_FILE
	   for (c=1; c < num_cols; c++)
	      printf(" %s", col_val[c]) >> TEMP_FILE
	   printf("\n") >> TEMP_FILE
	   }
	close(TEMP_FILE)
	system("sort -gr < " TEMP_FILE " | awk " swap_first)
	system("rm " TEMP_FILE)
	}


