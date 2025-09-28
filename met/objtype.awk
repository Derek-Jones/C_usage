# objtype.awk,  5 Oct 08
#
# needs mkctype.awk

BEGIN {
	num_internal_id=0
	total_params=0
	num_ord_ids=0
	init_types()
	seen_file_before=0
	start_depth=0
	start_name="###"
	}

$1 == ".START" {
	# We only count the contents of any file once.
	# This means we undercount if different files have the same name
	sfb_stack[start_depth]=seen_file_before
	start_stack[start_depth]=start_name
	start_depth++
	seen_file_before=0
	start_name=$2
        gsub(/\.\.\//, "", start_name)
        if (files_seen[start_name] == 1)
           seen_file_before=1
        else
           files_seen[start_name]=1
	next
	}

$1 == ".END" {
        end_name=$2
        gsub(/\.\.\//, "", end_name)
        if (end_name == start_name)
	   {
	   start_depth--
	   start_name=start_stack[start_depth]
	   seen_file_before=sfb_stack[start_depth]
	   }
	next
	}

seen_file_before == 1 {
	next
	}

$1 == ".GLOBAL" {
	in_global=(seen_file_before == 0)
	next
	}

$1 == ".ARG" {
	total_params++
	pr_type=""
	mk_pr_type($12)
	param_type[pr_type]++
	next
	}

$1 == ".LOCAL" {
	if ($11 == "IDENT") {
	   if ($12 != "econst")
	      {
	      num_ord_ids++
	      pr_type=""
	      mk_pr_type($12)
	      local_type[pr_type]++
	      }
	   }
	next
	}

$1 ~ /^\./ {
	in_global=0
	next
	}

	{
	if ((in_global == 1) && ($11 == "IDENT") && ($12 != "econst")) {
	   pr_type=""
	   mk_pr_type($12)
	   if ($2 == "EXTERNAL")
	      {
	      num_ext_type++
	      ext_type[pr_type]++
	      }
	   else
	      {
	      num_int_type++
	      int_type[pr_type]++
	      }
	   }
	next
	}

END {
	print "File: loc_obj_type.t"
	others=0
	for (i in local_type)
	   {
	   percent=100*(local_type[i]/num_ord_ids)
	   if (percent < 1)
	      others+=percent
	   else
	      printf(" %s ,, %2.1f\n", i, percent)
	   }
	printf(" other-types ,, %2.1f\n", others)
	print "End File"

	print "File: param_type.t"
	others=0
	for (i in param_type)
	   {
	   percent=100*(param_type[i]/total_params)
	   if (percent < 1)
	      others+=percent
	   else
	      printf(" %s ,, %2.1f\n", i, percent)
	   }
	printf(" other-types ,, %2.1f\n", others)
	print "End File"
	
	print "File: ext_type.t"
	others=0
	for (t in ext_type)
	   {
	   percent=100*(ext_type[t]/num_ext_type)
	   if (percent < 1)
	      others+=percent
	   else
	      printf(" %s ,, %2.1f\n", t, percent)
	   }
	printf(" other-types ,, %2.1f\n", others)
	print "End File"

	print "File: int_type.t"
	others=0
	for (t in int_type)
	   {
	   percent=100*(int_type[t]/num_int_type)
	   if (percent < 1)
	      others+=percent
	   else
	      printf(" %s ,, %2.1f\n", t, percent)
	   }
	printf(" other-types ,, %2.1f\n", others)
	print "End File"

	}

