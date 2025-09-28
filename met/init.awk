# init.awk,  5 Oct 08
#
# needs mkctype.awk

function sum_tran_info()
{
if (num_int_obj > 0)
   TU_ext_init[int(100*(init_int/num_int_obj))]++
if (num_ext_obj > 0)
   TU_int_init[int(100*(init_ext/num_ext_obj))]++
delete glob_init
}

function sum_func_info()
{
if (num_loc_obj > 0)
   func_obj_init[int(100*(num_loc_init/num_loc_obj))]++
delete loc_init
}

BEGIN {
	new_tran_unit=0
	total_glob_init=0
	init_types()
	seen_file_before=0
	start_depth=0
	start_name="###"
	}

$1 == ".START" {
	# We only count the contents of any file once.
	# This means we undercount if different files have the same name
	if (new_tran_unit == 1)
	   {
	   new_tran_unit=0
	   tran_unit_name=$2
	   start_depth=0
	   init_int=0
	   num_int_obj=0
	   init_ext=0
	   num_ext_obj=0
	   }
	else
	   {
	   sfb_stack[start_depth]=seen_file_before
	   start_stack[start_depth]=start_name
	   start_depth++
	   }
	start_name=$2
	seen_file_before=0
        gsub(/\.\.\//, "", start_name)
        if (files_seen[start_name] == 1)
           seen_file_before=1
        else
           files_seen[start_name]=1
	next
	}

$1 == ".END" {
	if (in_func == 1)
	   sum_func_info()
	in_func=0
	in_global=0
	if ($2 == tran_unit_name)
	   {
	   sum_tran_info()
	   tran_unit_name="###"
	   seen_file_before=0
	   delete files_seen
	   }
        else
	   {
	end_name=$2
        gsub(/\.\.\//, "", end_name)
        if (end_name == start_name)
	   {
	   start_depth--
	   start_name=start_stack[start_depth]
	   seen_file_before=sfb_stack[start_depth]
	   }
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

$1 == ".DATE" {
	new_tran_unit=1
	next
	}

$1 == ".INIT" {
	if (in_func) {
	   loc_init[$2]=1
	   num_loc_init++
	} else {
	   glob_init[$2]=1
	   }
	next
	}

$1 == ".ARG" {
	next
	}

$1 == ".LOCAL" {
	if (($11 == "IDENT") && ($12 != "econst")) {
	   num_loc_obj++
	   if (loc_init[$2] == 1) {
	      total_loc_init++
	      type_loc_init[$NF]++
	      }
	   }
	next
	}

$1 == ".FUNC" {
	in_func=1
	num_loc_init=0
	num_loc_obj=0
	next
	}

$1 ~ /^\./ {
	in_global=0
	next
	}

	{
	# Only count objects that are defined
	if (in_global) {
	   if (($(NF-1) == "IDENT") && ($NF != "econst"))
	      if ($2 == "INTERNAL") {
		 num_int_obj++
		 if (glob_init[$1] == 1)
		    {
		    type_glob_init[$NF]++
		    total_glob_init++
		    init_int++
		    }
	      } else {
		 num_ext_obj++
		 if (glob_init[$1] == 1)
		    {
		    type_glob_init[$NF]++
		    total_glob_init++
		    init_ext++
		    }
	      }  
	   }
	next
	}

END {
	print "File: loc_init.d"
	for (i=0; i <= 100; i++)
	   print i " " func_obj_init[i]+0
	print "End File"

	print "File: tu_ext_init.d"
	for (i=0; i <= 100; i++)
	   print i " " TU_ext_init[i]+0
	print "End File"

	print "File: tu_int_init.d"
	for (i=0; i <= 100; i++)
	   print i " " TU_int_init[i]+0
	print "End File"

	print "File: loc_init_type.t"
	others=0
	for (t in type_loc_init)
	   {
	   percent=100*(type_loc_init[t]/total_loc_init)
	   if (percent < 1)
	      others+=percent
	   else {
	      pr_type=""
	      mk_pr_type(t)
	      printf(" %s ,, %2.1f\n", pr_type, percent)
	      }
	   }
	printf(" other-types ,, %2.1f\n", others)
	print "End File"

	print "File: glob_init_type.t"
	others=0
	for (t in type_glob_init)
	   {
	   percent=100*(type_glob_init[t]/total_glob_init)
	   if (percent < 1)
	      others+=percent
	   else {
	      pr_type=""
	      mk_pr_type(t)
	      printf(" %s ,, %2.1f\n", pr_type, percent)
	      }
	   }
	printf(" other-types ,, %2.1f\n", others)
	print "End File"
	}

