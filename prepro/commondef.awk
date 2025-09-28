# commondef.awk, 18 Jul 03
#
# common occurrences of #define

BEGIN {
	num_seen=0
	}

$0 ~ /^abstract count/ {
	total_defined=$3
	next
	}

$0 ~ /^not abstracted/ {
	printf("others ,, %2.1f\n", not_printed)
	exit
	next
	}

	{
	num_seen++
	percent=100*($1/total_defined)
	if (num_seen <= 10) {
	   $1=""
	   $2=""
	   printf("%s ,, %2.1f\n", $0, percent)
	} else {
	   not_printed+=percent
	}
	next
	}

END {
    }

