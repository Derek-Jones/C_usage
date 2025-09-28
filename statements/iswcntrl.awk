# iswcntrl.awk, 26 Aug 03
#

BEGIN {
	}

$1 == "abstract" &&
$2 == "count" {
	totals["IF"]=$3
	totals["WHILE"]=$4
	totals["SWITCH"]=$5
	if_total=totals[CMPD_HDR]
	others=100
	next
	}

$2 == CMPD_HDR {
	if ($1/if_total < 0.01)
	   exit
	others=others-100*($1/if_total)
	gsub("IDENT", "OBJECT", $0)
	if ($3 != "(")
	   printf(" %s", $3)
	for (i=4; i < NF; i++)
	   printf(" %s", $i)
	if (($3 != "(") && (NF > 4))
	   printf(" %s", $NF)
	printf(" ,, %2.1f\n", 100*($1/if_total))
	next
	}

	{
	next
	}

END {
	printf("others ,, %2.1f\n", others)
	}

