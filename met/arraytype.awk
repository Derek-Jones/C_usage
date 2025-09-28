# arraytype.awk,  1 Feb 04
#

BEGIN {
	num_arg_arrays=0
	num_local_arrays=0
	num_global_arrays=0
	}

$1 == ".ARG" {
	num_dims=gsub("array", "", $NF)
	arg_dims[num_dims]++
	if (num_dims > 0)
	   num_arg_arrays++
	next
	}

$1 == ".LOCAL" {
	if ($11 == "IDENT")
	   {
	   num_dims=gsub("array", "", $NF)
	   local_dims[num_dims]++
	   if (num_dims > 0)
	      num_local_arrays++
	   }
	next
	}

$1 == ".GLOBAL" {
	in_globals=1
	next
	}

$1 ~ /^\./ {
	in_globals=0
	next
	}

	{
	if ((in_globals == 1) && ($(NF-1) == "IDENT"))
	   {
	   num_dims=gsub("array", "", $NF)
	   global_dims[num_dims]++
	   if (num_dims > 0)
	      num_global_arrays++
	   }
	next
	}

END {
	print "File: array_dims"
	for (d=1; global_dims[d] != 0; d++)
	   printf(" %d ,, %2.1f ,, %2.1f ,, %2.1f\n",d, 100*(arg_dims[d]/num_arg_arrays), 100*(local_dims[d]/num_local_arrays), 100*(global_dims[d]/num_global_arrays))
	print "End File"
	}

