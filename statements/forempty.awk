# forempty.awk, 16 Jul 03
#

BEGIN {
	}

$0 ~ /^num for/ {
	num_for=$NF
	next
	}

$0 ~ /^no init control increment/ {
	printf("<c_syntax>clause-1</c_syntax> <c_syntax>expr-2</c_syntax> <c_syntax>expr-3</c_syntax> ,, %2.1f\n", 100*($NF/num_for))
	next
	}

$0 ~ /^no init control/ {
	printf("<c_syntax>clause-1</c_syntax> <c_syntax>expr-2</c_syntax> ,, %2.1f\n", 100*($NF/num_for))
	next
	}

$0 ~ /^no init increment/ {
	printf("<c_syntax>clause-1</c_syntax> <c_syntax>expr-3</c_syntax> ,, %2.1f\n", 100*($NF/num_for))
	next
	}

$0 ~ /^no init/ {
	printf("<c_syntax>clause-1</c_syntax> ,, %2.1f\n", 100*($NF/num_for))
	next
	}

$0 ~ /^no control increment/ {
	printf("<c_syntax>expr-2</c_syntax> <c_syntax>expr-3</c_syntax> ,, %2.1f\n", 100*($NF/num_for))
	next
	}

$0 ~ /^no control/ {
	printf("<c_syntax>expr-2</c_syntax> ,, %2.1f\n", 100*($NF/num_for))
	next
	}

$0 ~ /^no increment/ {
	printf("<c_syntax>expr-3</c_syntax> ,, %2.1f\n", 100*($NF/num_for))
	next
	}

	{
	next
	}

END {
    }

