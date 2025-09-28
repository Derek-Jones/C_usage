# miscmsg.awk, 17 Dec 03
#

function print_msg()
{
print last_with_line_number
print $0
}

BEGIN {
   }

$1 == "^" ||
$1 == "int_promote" ||
$1 == "imp_cast" ||
$1 == "expr_op_type_type" {
	next
	}

$2 == "warning:" {
	# both internal and external linkage
	if ($3 == "(625)")
	   print $0
	# [U] 'return exp;' not found in function returning non-'void'
	if ($3 == "(744)")
	   print $0
	# [U] 'return;' found in function returning non-'void'
	if ($3 == "(745)")
	   print $0
	# [U] Function contains both 'return;' and 'return exp;
	if ($3 == "(754)")
	   print $0
	# Unreachable code
	if ($3 == "(1456)")
	   print_msg()
	# Identifier 'NO_DEFINE' replaced by zero in #if
	if ($3 == "(1766)")
	   print $0
	# Constant as 'if' controlling expression
	if ($3 == "(1806)")
	   print_msg()
	# Constant as loop controlling expression
	if ($3 == "(1807)")
	   print_msg()
	# Value analysis suggests condition is always TRUE
	if ($3 == "(1845)")
	   print_msg()
	# Value analysis suggests condition is always FALSE
	if ($3 == "(1846)")
	   print_msg()
	# Value analysis suggests do while condition is always TRUE
	if ($3 == "(1847)")
	   print_msg()
	# Value analysis suggests do while condition is always FALSE
	if ($3 == "(1848)")
	   print_msg()
	# Value analysis suggests while condition is always FALSE
	if ($3 == "(1849)")
	   print_msg()
	next
	}

# only save lines that have line numbers
$1 ~ /^[0-9]+$/ {
	last_with_line_number=$0
	next
	}

	{
	next
	}

END {
	}

