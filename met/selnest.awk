# selnest.awk,  3 Aug 03

$1 == ".ACC" ||
$1 == ".MOD" {
	if (((index($3, ".") != 0) || (index($3, "->.") != 0)) && \
	    ($3 != last_select) && ($4 != last_lnum)) {
	   last_select=$3
	   last_lnum=$4
	   num_indir=gsub(/->\./, "", $3)
	   num_dots=gsub(/\./, "", $3)
	   dot_total[num_dots]++
	   indir_total[num_indir]++
	   select_total[num_dots+num_indir]++
	   combin[num_dots+100*num_indir]++
	   }
	in_global=1
	next
	}

	{
	next
	}

END {
	TEMP_FILE="TeMp.tEmP"
	printf("") > TEMP_FILE
	for (i in dot_total)
	   print i " " dot_total[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: dottotal.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in indir_total)
	   print i " " indir_total[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: indirtotal.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in select_total)
	   print i " " select_total[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: seltotal.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in combin)
	   print i " " combin[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: selcombin.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	system("rm " TEMP_FILE)

	max_arrow=0
	max_dot=0
	for (i in combin) {
	   if ((i % 100) > max_dot)
	      max_dot=(i % 100)
	   if (int(i / 100) > max_arrow)
	      max_arrow=int(i / 100)
	   }
	print "File: seltable.d"
	#printf("  ")
	#for (a=0; a <= max_arrow; a++)
	#   printf(" ,, %d ", a)
	#printf("\n")
	for (d=0; d <= max_dot; d++) {
	   printf("%d", d)
	   for (a=0; a <= max_arrow; a++)
	      printf(" ,, %d ", combin[d+a*100])
	   printf("\n")
	   }
	print "End File"
	}

