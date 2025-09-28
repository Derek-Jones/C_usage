# funcall.awk, 30 Aug 03
#

BEGIN {
   total_calls=0
   }

# Calling function taking variable number of arguments
$3 == "(1361)" {
	total_msg[$3]++
	next
	}

# Calling function that has no prototype in scope
$3 == "(1362)" {
	total_msg[$3]++
	next
	}

# 'i' returns a value which is always ignored
$3 == "(1764)" {
	total_msg[$3]++
	next
	}

# Default declaration of 'f' as 'extern int ()'
$3 == "(1796)" {
	total_msg[$3]++
	next
	}

$1 == "expr_op_type_type" {
	if ($2 == 128)
	   total_calls++
	next
	}

   {
   next
   }

END {
	printf("Defined using ellipsis notation ,, %2.1f\n", 100*(total_msg["(1361)"]/total_calls))
	printf("No prototype in scope ,, %2.1f\n", 100*(total_msg["(1362)"]/total_calls))
	printf("Returns a value which is always ignored ,, %2.1f\n", 100*(total_msg["(1764)"]/total_calls))
	printf("Default declared as <c_code>extern int ()</c_code> ,, %2.1f\n", 100*(total_msg["(1796)"]/total_calls))
	}

