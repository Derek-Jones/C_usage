# idlocal.awk,  5 Oct 08
#

function sum_func_info()
{
num_funcs++
}

BEGIN {
	new_tran_unit=0
	num_ord_ids=0
	seen_file_before=0
	start_depth=0
	start_name="###"
	total_params=0
	num_funcs=0
	}

$1 == ".START" {
	# We only count the contents of any file once.
	# This means we undercount if different files have the same name
	if (new_tran_unit == 1)
	   {
	   new_tran_unit=0
	   tran_unit_name=$2
	   start_depth=0
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

$1 == ".MOD" {
	if ($2 == "EXTERN")
	   {
	   all_glob_mod[$3]++
	   total_ext_mod++
	   }
	else if ($2 == "STATIC")
	   {
	   total_sta_mod++
	   }
	else
	   total_non_mod++
	next
	}

$1 == ".ACC" {
	if ($2 == "EXTERN")
	   {
	   all_glob_acc[$3]++
	   total_ext_acc++
	   }
	else if ($2 == "STATIC")
	   {
	   total_sta_acc++
	   }
	else
	   total_non_acc++
	next
	}

$1 == ".ACC" {
	all_call[$2]++
	total_calls++
	next
	}

$1 == ".DATE" {
	new_tran_unit=1
	next
	}

$1 == ".GLOBAL" {
	in_global=(seen_file_before == 0)
	next
	}

$1 == ".ARG" {
	arg_id_defs[$2]++
	all_id_defs[$2]++
	total_args++
	next
	}

$1 == ".LOCAL" {
	loc_id_defs[$2]++
	all_id_defs[$2]++
	total_locs++
	next
	}

$1 == ".FUNC" {
	next
	}

$1 ~ /^\./ {
	in_global=0
	next
	}

	{
	next
	}

END {
	print "total-locs " total_locs " total-args " total_args
	print "ext-mod " total_ext_mod " sta_mod " total_sta_mod " non-mod " total_non_mod
	print "ext-acc " total_ext_acc " sta_acc " total_sta_acc " non-mod " total_non_acc
	TEMP_FILE=systime() ".li"
	
	printf("") > TEMP_FILE
	for (i in all_id_defs)
	   print all_id_defs[i] " " i >> TEMP_FILE
	close(TEMP_FILE)
	print "File: allids.d"
	system("sort -gr < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in arg_id_defs)
	   print arg_id_defs[i] " " i >> TEMP_FILE
	close(TEMP_FILE)
	print "File: argids.d"
	system("sort -gr < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in loc_id_defs)
	   print loc_id_defs[i] " " i >> TEMP_FILE
	close(TEMP_FILE)
	print "File: locids.d"
	system("sort -gr < " TEMP_FILE)
	print "End File"

	system("rm " TEMP_FILE)
	}

