#
# precspace.awk, 29 Oct 07

BEGIN {
	pat_num=0
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

function print_pat_freq(bin_op)
{
total_occur=pat_totals[bin_op " " bin_op " " 5]
}


$1 ~ "^\\w" {
	if (pat_num == 5)
	   pat_num=0
	pat_num++
	first_op=substr(/\\/, "", $2)
	second_op=substr(/\\/, "", $3)
	ops_seen[first_op]=1
	getline
	pat_count=$1
	pat_totals[first_op " " second_op " " pat_num]=pat_count
	next
	}


END {
	TEMP_FILE="dy" systime()

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

	system("rm " TEMP_FILE)
	}

