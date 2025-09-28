# rettype.awk, 31 Aug 03
#
# needs mkctype.awk

BEGIN {
	num_calls=0
	init_types()
	}

$1 == ".CALL" {
	num_calls++
	pr_type=""
	mk_pr_type($4)
	ret_type[pr_type]++
	next
	}

	{
	next
	}

END {
	others=0
	for (i in ret_type) {
	   percent=100*(ret_type[i]/num_calls)
	   if (percent >= 1.0)
	      printf(" %s ,, %2.1f\n", i, percent)
	   else
	      others=others+percent
	   }
	printf(" other-types ,, %2.1f\n", others)
	}

