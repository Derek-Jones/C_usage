# cchar_op.awk, 18 Dec 07
#
# constant usage

function print_data()
{
print "Arithmetic operators, " cnt_arith_ops
print "Bit operators, " cnt_bit_ops
print "Equality operators, " cnt_equal_ops
print "Relational operators, " cnt_rel_ops
exit
}

function add_usage(op, use_percen)
{
if (index(bit_ops, " " op " ") != 0)
   cnt_bit_ops+=use_percen
if (index(arith_ops, " " op " ") != 0)
   cnt_arith_ops+=use_percen
if (index(rel_ops, " " op " ") != 0)
   cnt_rel_ops+=use_percen
if (index(equal_ops, " " op " ") != 0)
   cnt_equal_ops+=use_percen
}

BEGIN {
        bit_ops=" ~ << >> ! ^ & | ^= <<= >>= &= |= "
        arith_ops=" - + * / % += -= *= /= %= "
	rel_ops=" < <= > >= "
	equal_ops=" == != "
	}

$2 ~ /tokbigram.d/ {
	in_data_freq=1
	next
	}

$1 ~ /End/ {
	if (in_data_freq == 1)
	   print_data()
	next
	}

$1 == "CHAR_CONST" {
	if (in_data_freq == 1) {
	   add_usage($2, $5)
	   }
	next
	}

$2 == "CHAR_CONST" {
	if (in_data_freq == 1) {
	   add_usage($1, $6)
	   }
	next
	}

        {
	next
	}

END {
    }

