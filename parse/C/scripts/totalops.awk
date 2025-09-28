#
# totalops.awk, 15 Jun 06

BEGIN {
	num_pairs=0
	num_paren_pairs=0
	op_prec["*"]=13 ; op_prec["/"]=13 ; op_prec["%"]=13
	op_prec["+"]=12 ; op_prec["-"]=12
	op_prec["<<"]=11 ; op_prec[">>"]=11
	op_prec["<"]=10 ; op_prec[">"]=10 ; op_prec["<="]=10 ; op_prec[">="]=10
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
	op_str["?"]="quest" ; op_str[":"]="colon"
# Map operators to 'category representative' operator used in experiment
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
	all_ops_count=split("* / % + - << >> < > <= >= == != & ^ | && ||", op_list)
	}

$0 == "Total operator/operand count" {
	count_ops=1
	next
	}

$1 == "Expressions" {
	count_ops=0
	next
	}

	{
	if ((count_ops != 1) || (op_str[$2] == ""))
	   next
	if (($2 == ":") || ($2 == "?"))
	   next
	op_count[$2]=$1
	total_ops+=$1
	next
	}

END {
	TEMP_FILE="dy" systime()
	
	print "Binary operator totals " total_ops

	printf("") > TEMP_FILE
	for (op in op_count)
	   printf("%s  %5.2f\n", op, 100.0*op_count[op]/total_ops) >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -gr -k2 < " TEMP_FILE)
	
	system("rm " TEMP_FILE)
	}

