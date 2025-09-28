#
# chisqr.awk, 26 Mar 05

BEGIN {
	total=0
	num_points=0
	}

	{
	num_points++
	pt_valu[$1]=$2
	total+=$2
	next
	}

END {
	chi_sq=0
	for (i=1; i <= num_points; i++)
	   {
	   value_seen=pt_valu[i]
	   value_expected=total*log(1+1.0/i)/log(10)
	   total_expected+=value_expected
	   print "expected " value_expected ", seen " value_seen
	   ch_sq+=(value_seen-value_expected)*(value_seen-value_expected)/value_expected
	   }
	print total_expected
	print "Total = " total ", num points = " num_points ", chi square = "ch_sq
	}
