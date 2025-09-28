# defined.awk, 18 Jul 03
#
# occurrences of defined

BEGIN {
	num_seen=0
	}

$0 ~ /^abstract count/ {
	total_if_elif=$3+$4
	next
	}

$0 ~ /^not abstracted/ {
	printf("others ,, %2.1f\n", not_printed)
	exit
	next
	}

$0 ~ /DEFINED/ {
	num_seen++
	freq=100*($1/total_if_elif)
	if (num_seen <= 10) {
	   $1=""
	   printf("%s ,, %2.1f\n", $0, freq)
	} else {
	   not_printed+=freq
	}
	next
	}

	{
	next
	}

END {
    }

