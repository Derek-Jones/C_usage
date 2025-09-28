# hashtab.awk, 18 Jul 03
#
# common occurrences of #

BEGIN {
	num_seen=0
	}

$0 ~ /^\#\# operands/ {
	in_data_info=1
	total_hashhash=$3
	next
	}

	{
	if (in_data_info) {
	   percent=100*($1/total_hashhash)
	   if (percent > 1.0) {
	      $1=""
	      printf("%s ,, %2.1f\n", $0, percent)
	   } else {
	      not_printed+=percent
	   }
	}
	next
	}

END {
	printf("others ,, %2.1f\n", not_printed)
    }

