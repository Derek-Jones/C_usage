#
# getprec.awk, 29 Oct 07
#
# 29 Oct 07 DJ Added prec_order parameter and support
#  5 Jul 06 DJ Initial release

function correct_answer(prec_order)
{
total_correct_op+=2
total_correct_prec_order[prec_order]++
op_count[first_op]++
op_count[second_op]++
op_correct[first_op]++
op_correct[second_op]++
correct_paren++
pair_correct[op_pair_str]++
}

function wrong_answer(prec_order)
{
total_wrong_op+=2
total_wrong_prec_order[prec_order]++
op_count[first_op]++
op_count[second_op]++
op_wrong[first_op]++
op_wrong[second_op]++
pair_wrong[op_pair_str]++
}

BEGIN {
	line_num=0
	in_answers=0
	num_answers=0
	correct_paren=0
	incorrect_paren=0
	first_high=1
	equal_prec=2
	second_high=3
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
	op_str["*"]="times" ; op_str["/"]="div" ; op_str["%"]="rem"
	op_str["+"]="plus" ; op_str["-"]="minus"
	op_str["<<"]="lshift" ; op_str[">>"]="rshift"
	op_str["<"]="lt" ; op_str[">"]="gt" ; op_str["<="]="le" ; op_str[">="]="ge"
	op_str["=="]="eq" ; op_str["!="]="ne"
	op_str["&"]="band"
	op_str["^"]="xor"
	op_str["|"]="bor"
	op_str["&&"]="land"
	op_str["||"]="lor"
	op_map_op["*"]="*" ; op_map_op["/"]="/" ; op_map_op["%"]="%"
	op_map_op["+"]="+" ; op_map_op["-"]="-"
	op_map_op["<<"]="<<" ; op_map_op[">>"]="<<"
	op_map_op["<"]="<" ; op_map_op[">"]="<" ; op_map_op["<="]="<" ; op_map_op[">="]="<"
	op_map_op["=="]="==" ; op_map_op["!="]="!="
	op_map_op["&"]="&"
	op_map_op["^"]="^"
	op_map_op["|"]="|"
	op_map_op["&&"]="&&"
	op_map_op["||"]="||"
#	all_ops_count=split("* / % + - << >> < > <= >= == != & ^ | && ||", op_list)
	all_ops_count=split("* / % + - << < == != & ^ | && ||", op_list)

	}

	{
	line_num++
	}

($2 == ":") && ($4 == ":") {
	start_num_answers=num_answers
	cur_total_correct_op=total_correct_op
	years_exp=$5;
	next
	}

$1 == "\\h'1i'" {
	if (in_answers == 0)
	   next
	e_parened=0
	first_op=$3
	second_op=$6
	if ($4 == "(")
	   e_parened=2
	else if ($5 == ")")
	   e_parened=1
	if (e_parened == 0)
	   {
	   if (($NF == "no_answer") || ($NF == "skipped") || ($NF == "up_to_compiler") || ($NF == "ambiguous_answer"))
	      next
	   print ">> " line_num " " $0
	   }
	if ((op_prec[first_op] == "") || (op_prec[second_op] == ""))
	   print ">> unknown operator " first_op " " second_op
	op_pair_str=first_op " " second_op
	total_pairs[op_pair_str]++
	if (op_prec[first_op] > op_prec[second_op])
	   {
	   if (e_parened == 1)
	      correct_answer(first_high)
	   else
	      wrong_answer(first_high)
	   }
	if (op_prec[first_op] == op_prec[second_op])
	   {
	   if (e_parened == 1)
	      correct_answer(equal_prec)
	   else
	      wrong_answer(equal_prec)
	   }
	if (op_prec[first_op] < op_prec[second_op])
	   {
	   if (e_parened == 2)
	      correct_answer(second_high)
	   else
	      wrong_answer(second_high)
	   }
	num_answers++
	next
	}

$0 == "Strategies" {
	in_answers=1
	next
	}

$0 == "FINISH" {
	in_answers=0
	printf("%d  %d  %5.2f\n", (num_answers-start_num_answers),  years_exp,\
 (100.0*(total_correct_op-cur_total_correct_op)/2)/(0.0001+num_answers-start_num_answers))
	total_years_exp+=years_exp
	next
	}

	{
	next
	}

END {
	TEMP_FILE="dy" systime()

	print "total years experience " total_years_exp
	print "Total answers " num_answers " correct " correct_paren
	print "Correct " total_correct_prec_order[first_high] " " \
			total_correct_prec_order[equal_prec] " " \
			total_correct_prec_order[second_high]
	print "Wrong " total_wrong_prec_order[first_high] " " \
			total_wrong_prec_order[equal_prec] " " \
			total_wrong_prec_order[second_high]
	for (op in total_pairs)
	   printf("%6s  %4d  %5.1f\n", op, total_pairs[op], (100.0*pair_correct[op])/total_pairs[op])

	for (op_1 in op_str)
	   for (op_2 in op_str)
	      {
	      pair_total= pair_correct[op_1 " " op_2] + pair_correct[op_2 " " op_1]
	      if (pair_total > 0)
		 if (op_prec[op_1] > op_prec[op_2])
		    print op_str[op_1] " " op_str[op_2] " " pair_total
		 else
		    if (op_prec[op_1] != op_prec[op_2])
		       print op_str[op_2] " " op_str[op_1] " " pair_total
	      }
	print ""

	print "op pairs wrong: alphabetical"
	printf("") > TEMP_FILE
	for (op_1 in op_str)
	   for (op_2 in op_str)
	      {
	      pair_total= pair_wrong[op_1 " " op_2] + pair_wrong[op_2 " " op_1]
	      if (pair_total > 0)
		 print op_str[op_1] " " op_str[op_2] " " pair_total >> TEMP_FILE
	      }
	close(TEMP_FILE)
	system("sort < " TEMP_FILE)

	print "op pairs wrong: precedence order"
	printf("") > TEMP_FILE
	for (op_1 in op_str)
	   for (op_2 in op_str)
	      {
	      pair_total= pair_wrong[op_1 " " op_2] + pair_wrong[op_2 " " op_1]
	      if (pair_total > 0)
		 if (op_prec[op_1] < op_prec[op_2])
		    print op_str[op_1] " " op_str[op_2] " " pair_total >> TEMP_FILE
		 else
		    if (op_prec[op_1] != op_prec[op_2])
		       print op_str[op_2] " " op_str[op_1] " " pair_total >> TEMP_FILE
	      }
	close(TEMP_FILE)
	system("sort < " TEMP_FILE)

	print "correct op pairs"
	printf("     ")
	for (op_1=1; op_1 <= all_ops_count; op_1++)
	   printf(", %6s", op_list[op_1])
	printf("\n")
	for (op_1=1; op_1 <= all_ops_count; op_1++)
	   {
	   printf("%2s", op_list[op_1])
	   for (op_2=1; op_2 <= op_1; op_2++)
	      {
	      pair_total= pair_correct[op_list[op_1] " " op_list[op_2]] + pair_correct[op_list[op_2] " " op_list[op_1]] + \
	                  pair_wrong[op_list[op_1] " " op_list[op_2]] + pair_wrong[op_list[op_2] " " op_list[op_1]]
	      correct_total= pair_correct[op_list[op_1] " " op_list[op_2]] + pair_correct[op_list[op_2] " " op_list[op_1]]
	      if (pair_total)
	         printf(", %3d(%2d)", int((100.0*correct_total)/pair_total), pair_total)
	      else
	         printf(", %7s", "-")
	      }
	   printf("\n")
	   }

	printf("") > TEMP_FILE
	print "ops in correct answers"
	for (op in op_correct)
	   printf("%s %5.2f %5d\n", op, 100.0*op_correct[op]/op_count[op], op_count[op]) >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -gr -k2 < " TEMP_FILE)

	printf("") > TEMP_FILE
	print "ops in wrong answers"
	for (op in op_wrong)
	   printf("%s %5.2f %5d\n", op, 100.0*op_wrong[op]/op_count[op], op_count[op]) >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -gr -k2 < " TEMP_FILE)

	system("rm " TEMP_FILE)
	}

