# undeftab.awk, 20 Jul 03
#
# common sequences of directives, starting with #undef,
# that reference a given identifier

BEGIN {
	in_data=0
	}

$0 ~ /^number abstract undef/ {
	in_data_info=1
	total_undef_seq=$5
	next
	}

	{
	if (in_data_info) {
	   percent=100*($1/total_undef_seq)
	   if (percent > 1.0) {
	      $1=""
	      $2=""
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

