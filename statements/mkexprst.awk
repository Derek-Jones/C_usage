# mkexprst.awk,  8 Dec 03
#
# Count the properties of control expressions
#

BEGIN {
	others=0
	}

$1 == "num_expr_stmt" {
	num_expr_stmt=$2
	next
	}

	{
	percent=100*($1/num_expr_stmt)
	if (percent < 1)
	   others+=percent
	else
	   {
	   e_stmt=$2
	   for (e=3; e <= NF; e++)
	      e_stmt=e_stmt " " $e
	   printf("%s ,, %2.0f\n", e_stmt, percent)
	   }
	next
	}

END {
	printf("other-expr-stmt ,, %2.0f\n", others)
	}

