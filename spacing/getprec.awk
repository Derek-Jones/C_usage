#
# spaceprec.awk, 10 Jan 08
#

BEGIN {
	line_num=0
	op_prec["*"]=13 ; op_prec["/"]=13 ; op_prec["%"]=13
	op_prec["+"]=12 ; op_prec["-"]=12
	op_prec["<<"]=11 ;
# op_prec[">>"]=11
	op_prec["<"]=10 ;
# op_prec[">"]=10 ; op_prec["<="]=10 ; op_prec[">="]=10
	op_prec["=="]=9 ; op_prec["!="]=9
	op_prec["&"]=8
	op_prec["^"]=7
	op_prec["|"]=6
	op_prec["&&"]=5
	op_prec["||"]=4
#	all_ops_count=split("* / % + - << >> < > <= >= == != & ^ | && ||", op_list)
	all_ops_count=split("* / % + - << < == != & ^ | && ||", op_list)

	MULT="mult"
	ADD="add"
	RELAT="relat"
	EQUAL="equal"
	BITWISE="bitwise"
	LOGICAL="logical"
	SHIFT="<<"
	op_kind["*"]=MULT ; op_kind["/"]=MULT ; op_kind["%"]=MULT
	op_kind["+"]=ADD ; op_kind["-"]=ADD
	op_kind["<"]=RELAT ; op_kind[">"]=RELAT
        op_kind["<="]=RELAT ; op_kind[">="]=RELAT
	op_kind["=="]=EQUAL ; op_kind["!="]=EQUAL
	op_kind["&"]=BITWISE ; op_kind["^"]=BITWISE ; op_kind["|"]=BITWISE
	op_kind["&&"]=LOGICAL ; op_kind["||"]=LOGICAL
	op_kind["<<"]=SHIFT ; op_kind[">>"]=SHIFT
	}

	{
	if (line_num == 10)
	   line_num=0
	line_num++
	}

line_num == 1 {
	gsub(/id/, "I", $0)
	split($0, all_ops, "I")
	op_1=all_ops[2]
	kind_1=op_kind[op_1]
	op_2=all_ops[3]
	kind_2=op_kind[op_2]
	cur_total=0
	next
	}

line_num == 2 {
	nospace[kind_1 " " kind_2]+=$1
	nospace["total"]+=$1
	if (op_prec[op_1] > op_prec[op_2])
	   nospace["high_low"]+=$1
	else
	if (op_prec[op_1] < op_prec[op_2])
	   nospace["low_high"]+=$1
	else
	   nospace["same"]+=$1
	cur_total+=$1
	next
	}

line_num == 4 {
	space_nospace[kind_1 " " kind_2]+=$1
	space_nospace["total"]+=$1
	if (op_prec[op_1] > op_prec[op_2])
	   space_nospace["high_low"]+=$1
	else
	if (op_prec[op_1] < op_prec[op_2])
	   space_nospace["low_high"]+=$1
	else
	   space_nospace["same"]+=$1
	cur_total+=$1
	next
	}

line_num == 6 {
	space_space[kind_1 " " kind_2]+=$1
	space_space["total"]+=$1
	if (op_prec[op_1] > op_prec[op_2])
	   space_space["high_low"]+=$1
	else
	if (op_prec[op_1] < op_prec[op_2])
	   space_space["low_high"]+=$1
	else
	   space_space["same"]+=$1
	cur_total+=$1
	next
	}

line_num == 8 {
	nospace_space[kind_1 " " kind_2]+=$1
	nospace_space["total"]+=$1
	if (op_prec[op_1] > op_prec[op_2])
	   nospace_space["high_low"]+=$1
	else
	if (op_prec[op_1] < op_prec[op_2])
	   nospace_space["low_high"]+=$1
	else
	   nospace_space["same"]+=$1
	cur_total+=$1
	next
	}

line_num == 9 {
	line_9=$0
	next
	}

line_num == 10 {
	total_sp[kind_1 " " kind_2]+=cur_total
	total_sp["total"]+=cur_total
	if (op_prec[op_1] > op_prec[op_2])
	   total_sp["high_low"]+=cur_total
	else
	if (op_prec[op_1] < op_prec[op_2])
	   total_sp["low_high"]+=cur_total
	else
	   total_sp["same"]+=cur_total
#	if (cur_total != $1)
#	   print cur_total " " $1 "            " line_9
	next
	}

	{
	next
	}

END {
	TEMP_FILE="dy" systime()

	printf("nospace       %6d  hl  %6d  s  %6d  lh %6d\n", nospace["total"], nospace["high_low"], nospace["same"], nospace["low_high"])
	printf("space_nospace %6d  hl  %6d  s  %6d  lh %6d\n", space_nospace["total"], space_nospace["high_low"], space_nospace["same"], space_nospace["low_high"])
	printf("space_space   %6d  hl  %6d  s  %6d  lh %6d\n", space_space["total"], space_space["high_low"], space_space["same"], space_space["low_high"])
	printf("nospace_space %6d  hl  %6d  s  %6d  lh %6d\n", nospace_space["total"], nospace_space["high_low"], nospace_space["same"], nospace_space["low_high"])
	printf("total_sp      %6d  hl  %6d  s  %6d  lh %6d\n", total_sp["total"], total_sp["high_low"], total_sp["same"], total_sp["low_high"])
#	print "Op patterns"
#	printf("") > TEMP_FILE
	for (i in total_sp)
	   if (total_sp[i] > 50)
	      print i " " total_sp[i]
#	close(TEMP_FILE)
#	system("sort < " TEMP_FILE)

#	system("rm " TEMP_FILE)
	}

