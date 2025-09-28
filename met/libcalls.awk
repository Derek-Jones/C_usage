# libcalls.awk, 28 Dec 03
#
# Count the number of different identifiers
#
BEGIN {
	in_call_data=0
	total_calls=0
	}

$1 == "__@__" {
	in_call_data=1
	next
	}

	{
	if (in_call_data == 0)
	   lib_call_name[$1]=-1
	else
	   {
	   total_calls+=$2
	   if (lib_call_name[$1] == -1)
	      lib_call_name[$1]=$2
	   }
	next
	}

END {
	#print total_calls
	for (i in lib_call_name)
	   if (lib_call_name[i] > 0)
	      {
	      percent=100*(lib_call_name[i]/total_calls)
	      if (percent >= 0.01)
	         printf(" %s ,, %1.3f\n", i, percent)
	      }
	}

