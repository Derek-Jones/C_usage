#
# pairop.awk,  6 Mar 12

function rel_prec(ops, op_1, op_2)
{
split(ops, toks)

if (op_prec[toks[op_1]] < op_prec[toks[op_2]])
   return 1
return 0
}

function is_ignore_op(oper)
{
return ((oper == ":") || (oper == "?") || (oper == ","))
}

function cnt_op_pair(op_1, op_2, op_count)
{
if (is_ignore_op(op_1) || is_ignore_op(op_2))
   return
ops_counted[op_1]+=op_count
ops_counted[op_2]+=op_count
seen_pair[op_1 op_2]=1
seen_pair[op_2 op_1]=1
num_pairs+=op_count
if (op_prec[op_1] < op_prec[op_2])
   cnt_pair_op[op_1 " " op_2] += op_count
else
   cnt_pair_op[op_2 " " op_1] += op_count
cnt_ordered_pair_op[op_1 " " op_2] += op_count
list_pair_op[op_str[op_1] "_" op_str[op_2] " " num_pairs] = $0
}


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

# Input format
#    count op op op op op ...
# where op can also be a ( or a )

	{
	for (op=2; op <=NF; op++)
	   op_totals[$op]+=$1
	for (op=2; op < NF; op++)
	   if (($op != "(") && ($op != ")"))
              if (($(op+1) != "(") && ($(op+1) != ")") && \
	          (seen_pair[$op $(op+1)] != 1))
	         cnt_op_pair($op, $(op+1), $1)
#
# op_1 ( ) op_2 is a pair separated by redundant ()
# actually op_1 ( stuff ) op_2 is also a pair, but we don't (yet) count it
#
              else if (($(op+1) == "(") && ($(op+2) == ")") && \
                       ($(op+3) != "(") && ($(op+3) != ")") && \
	               (seen_pair[$op $(op+3)] != 1))
	         cnt_op_pair($op, $(op+3), $1)
	delete seen_pair
	for (op=2; op < NF-2; op++)
	   {
	   if (($op == "(") && ($(op+2) == ")") &&         \
	       (op_str[$(op+1)] != "") && (op_str[$(op+3)] != "") && \
               (!is_ignore_op($(op+1))) && (!is_ignore_op($(op+3))))
	      {
	      num_paren_pairs+=$1
	      paren_ops_counted[$(op+1)]+=$1
	      paren_ops_counted[$(op+3)]+=$1
	      paren_op[$op " " $(op+1) " " $(op+2) " " $(op+3)] += $1
	      }
	   if ((op_str[$op] != "") && ($(op+1) == "(") &&  \
	       (op_str[$(op+2)] != "") && ($(op+3) == ")") && \
               (!is_ignore_op($(op+0))) && (!is_ignore_op($(op+2))))
	      {
	      num_paren_pairs+=$1
	      paren_ops_counted[$(op+0)]+=$1
	      paren_ops_counted[$(op+2)]+=$1
	      op_paren[$op " " $(op+1) " " $(op+2) " " $(op+3)] += $1
	      }
	   }
	next
	}

END {
	TEMP_FILE="dy" systime()
	
	print "Operator total pairs " num_pairs

	printf("") > TEMP_FILE
	for (op in cnt_pair_op)
	   printf("%7d  %s\n", cnt_pair_op[op], op) >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -gr -k1 < " TEMP_FILE)
	
	printf("") > TEMP_FILE
	for (op in list_pair_op)
	   printf("%20s %s\n", op, list_pair_op[op]) >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -k1,1 -k3,3gr " TEMP_FILE)

	num_pair_ops=0
	for (op in ops_counted)
	   num_pair_ops+=ops_counted[op]
	print "total ops in pairs " num_pair_ops
	print "op  percent-of-all-pairs  percent-in-pairs-div-all-occurrences"
	printf("") > TEMP_FILE
	for (op in ops_counted)
	   printf("%s  %5.2f  %5.2f\n", op, (100.0*ops_counted[op])/num_pair_ops, (100.0*ops_counted[op])/(0.00001+op_totals[op])) >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -k2,2gr " TEMP_FILE)

	num_pair_ops=0
	for (op in paren_ops_counted)
	   num_pair_ops+=paren_ops_counted[op]
	print "total paren ops in pairs " num_pair_ops
	printf("") > TEMP_FILE
	for (op in paren_ops_counted)
	   printf("%s  %5.2f  %5.2f\n", op, (100.0*paren_ops_counted[op])/num_pair_ops, (100.0*paren_ops_counted[op])/(0.00001+op_totals[op])) >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -k2,2gr " TEMP_FILE)

	print "op pair table " num_pairs
	printf("     ")
	for (op_1=1; op_1 <= all_ops_count; op_1++)
	   printf(", %6s", op_list[op_1])
	printf("\n")
	for (op_1=1; op_1 <= all_ops_count; op_1++)
	   {
	   printf("%6s", op_list[op_1])
	   for (op_2=1; op_2 <= op_1; op_2++)
	      if (cnt_pair_op[op_list[op_1] " " op_list[op_2]])
	         printf(" %4.3f", (100.0*cnt_pair_op[op_list[op_1] " " op_list[op_2]])/num_pairs)
	      else
	         printf(" %6s", "-")
	   printf("\n")
	   }

	
	print "op paren_op pair table " num_paren_pairs
	printf("     ")
	for (op_1=1; op_1 <= all_ops_count; op_1++)
	   printf(", ( %2s )", op_list[op_1])
	printf("\n")
	for (op_1=1; op_1 <= all_ops_count; op_1++)
	   {
	   printf("%5s", op_list[op_1])
	   for (op_2=1; op_2 <= all_ops_count; op_2++)
	      {
	      cur_paren_pairs=paren_op["( " op_list[op_2] " ) " op_list[op_1]]+op_paren[op_list[op_1] " ( " op_list[op_2] " )"]
	      if (op_2 <= op_1)
	         cur_op_pairs=cnt_pair_op[op_list[op_1] " " op_list[op_2]]
	      else
	         cur_op_pairs=cnt_pair_op[op_list[op_2] " " op_list[op_1]]
	      if (cur_paren_pairs)
		 {
	         if (cur_op_pairs)
	            printf(" %4.1f", (1.0*cur_paren_pairs)/cur_op_pairs)
		 else
	            printf("   * ")
		 }
	      else
	         printf(" %4s", "-")
	      }
	   printf("\n")
	   }

	print "paren op paren op"
	printf("") > TEMP_FILE
	for (op in paren_op)
	   {
	   if (rel_prec(op, 2, 4) == 1)
	      prec_gt="@"
	   else
	      prec_gt=""
	   printf("%7d   %s   %s\n", paren_op[op], op, prec_gt) >> TEMP_FILE
	   }
	close(TEMP_FILE)
	system("sort -gr " TEMP_FILE)
	
	print "op paren op paren"
	printf("") > TEMP_FILE
	for (op in op_paren)
	   {
	   if (rel_prec(op, 3, 1) == 1)
	      prec_gt="@"
	   else
	      prec_gt=""
	   printf("%7d   %s   %s\n", op_paren[op], op, prec_gt) >> TEMP_FILE
	   }
	close(TEMP_FILE)
	system("sort -gr " TEMP_FILE)
	
	system("rm " TEMP_FILE)
	}

