#
# fieldreuse.awk, 21 Nov 08

BEGIN {
	}

$2 == "xxxxx" {
	reuse_cnt[$1]=$3
	shared_name_cnt[$3]++
	next
	}

	{
	type_cnt[$2]+=$3
	file_cnt[$5]++
	diff_types[$1]++
	diff_type_cnt[$1]+=$3
	next
	}

END {
	TEMP_FILE="TeMp.tEmP"

	printf("") > TEMP_FILE
	print "File: types_reused"
	total_type_cnt=0
	for (t in type_cnt)
	   total_type_cnt+=type_cnt[t]
	for (t in type_cnt)
	   printf("%s  %5d  %5.2f\n", t, type_cnt[t], (100.0*type_cnt[t])/total_type_cnt) >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -gr -k 2 < " TEMP_FILE)

	printf("") > TEMP_FILE
	print "File: file_count"
	total_file_cnt=0
	for (t in file_cnt)
	   total_file_cnt+=file_cnt[t]
	for (t in file_cnt)
	   printf("%s  %5d  %5.2f\n", t, file_cnt[t], (100.0*file_cnt[t])/total_file_cnt) >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)

	system("rm " TEMP_FILE)

	dt_total=0
	for (t in diff_types)
	   {
	   dt_total++
	   dtm_sum[diff_types[t]]++
	   dta_sum[diff_types[t] + (reuse_cnt[t]-diff_type_cnt[t])]++
	   }
	print "File: misc"
	print dt_total
	print "File: diff_mult_types"
	for (t=1; t < 10; t++)
	   printf("%2d  %4d  %5.2f\n", t, dtm_sum[t], (100.0*dtm_sum[t])/dt_total)
	print "File: diff_all_types"
	for (t=1; t < 10; t++)
	   printf("%2d  %4d  %5.2f\n", t, dta_sum[t], (100.0*dta_sum[t])/dt_total)
	total_shared_names=0
	for (sn=2; sn < 200; sn++)
	   total_shared_names+=shared_name_cnt[sn]
	print "File: misc "
	print  total_shared_names
	print "File: shared_names"
	for (sn=2; sn < 10; sn++)
	   printf("%3d  %5d  %5.2f\n", sn, shared_name_cnt[sn], \
				(100.0*shared_name_cnt[sn])/total_shared_names)
	}

