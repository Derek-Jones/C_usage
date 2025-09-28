# argtype.awk, 31 Aug 03
#
# needs mkctype.awk

BEGIN {
	num_args=0
	init_types()
	}

$1 == ".CALL" {
	for (a=5; a <= NF; a++) {
	   num_args++
	   pr_type=""
	   mk_pr_type($a)
	   arg_type[pr_type]++
	   }
	next
	}

	{
	next
	}

END {
	others=0
	for (i in arg_type) {
	   percent=100*(arg_type[i]/num_args)
	   if (percent >= 1.0)
	      printf(" %s ,, %2.1f\n", i, percent)
	   else
	      others=others+percent
	   }
	printf(" other-types ,, %2.1f\n", others)
	}

