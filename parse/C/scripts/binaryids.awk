#
# binaryids.awk,  3 Nov 07

BEGIN {
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
	op_map_op["*"]="*" ; op_map_op["/"]="*" ; op_map_op["%"]="*"
	op_map_op["+"]="+" ; op_map_op["-"]="+"
	op_map_op["<<"]=">>" ; op_map_op[">>"]=">>"
	op_map_op["<"]="<" ; op_map_op[">"]="<" ; op_map_op["<="]="<" ; op_map_op[">="]="<"
	op_map_op["=="]="==" ; op_map_op["!="]="=="
	op_map_op["&"]="|" ; op_map_op["^"]="|" ; op_map_op["|"]="|"
	op_map_op["&&"]="&&" ; op_map_op["||"]="&&"
	}

# Second operand is arithmetic
($1 == "<<") ||
($1 == ">>") {
	idents[op_map_op[$1] " " $2]++
	idents[op_map_op["+"] " " $3]++
	next
	}
$1 in op_str {
	idents[op_map_op[$1] " " $2]++
	idents[op_map_op[$1] " " $3]++
	next
	}

END {
	for (i in idents)
	   print i " " idents[i]
	}

