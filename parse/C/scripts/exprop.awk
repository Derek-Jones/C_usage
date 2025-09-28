#
# exprop.awk,  8 Jan 08

$1 == "unary" {
	unary_total[$2]++
	arith_total[$4]++
	bit_total[$6]++
	eq_rel_total[$8]++
	op_total[$2+$4+$6+$8]++
	total_expr++
	next
	}

	{
	next
	}

END {
	print "Total expressions " total_expr
	print "File: unop_expr.d"
	for (i=0; i < 21; i++)
	   print i " " unary_total[i]
	print "End File"

	print "File: arop_expr.d"
	for (i=0; i < 21; i++)
	   print i " " arith_total[i]
	print "End File"

	print "File: bitop_expr.d"
	for (i=0; i < 21; i++)
	   print i " " bit_total[i]
	print "End File"

	print "File: eq_relop_expr.d"
	for (i=0; i < 21; i++)
	   print i " " eq_rel_total[i]
	print "End File"

	print "File: allop_expr.d"
	for (i=0; i < 21; i++)
	   print i " " op_total[i]
	print "End File"

	}

