#
# cntop.awk, 21 May 06

$1 == "OS" {
	total_expr++
	$1=""
	context_op_seq[$0]++
	$2=""
	op_seq[$0]++
	next
	}
	
$1 == "Os" {
	if (index($0, "(") != 0)
	   {
	   $1=""
	   context_op_seq[$0]++
	   $2=""
	   op_seq[$0]++
	   }
	next
	}
	
END {
	TEMP_FILE="dy" systime()
	
	print "Operator sequence totals " total_expr

	printf("") > TEMP_FILE
	for (os in op_seq)
	   printf("%7d  %s\n", op_seq[os], os) >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -gr -k1 < " TEMP_FILE)

	print "cut-here"
	
	printf("") > TEMP_FILE
	for (os in context_op_seq)
	   printf("%7d  %s\n", context_op_seq[os], os) >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -gr -k1 < " TEMP_FILE)
	
	system("rm " TEMP_FILE)
	}

