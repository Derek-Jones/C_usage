# fcntrl.awk, 26 Aug 03
#

BEGIN {
	}

$1 == "abstract" &&
$2 == "count" {
	if_total=$6
	others=0
	next
	}

$2 == "FOR" {
	percent=100*($1/if_total)
	if (percent < 1)
	   others+=percent
	else
	   {
 	   printf("%2.1f ,,", 100*($1/if_total))
	   gsub("IDENT", "OBJECT", $0)
	   split($0, exprs, ";")
	   printf(" %s\n", exprs[2])
	   }
	next
	}

	{
	next
	}

END {
	printf("%2.1f ,, other-expr\n", others)
	}

