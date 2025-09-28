# calluse.awk,  5 Oct 08

function sum_tran_info()
{
TU_func_defs[num_func_defs]++

num_defs_called=0
for (f in TU_func_def_name)
   if (TU_call_name[f] != 0)
      num_defs_called++
if (num_func_defs != 0)
   TU_func_defs_called[int(100*(num_defs_called/num_func_defs))]++

delete TU_call_name
delete TU_func_def_name
}

BEGIN {
	num_func_defs=0
	num_calls=0
	new_tran_unit=0
	seen_file_before=0
	num_funcs=0
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
	   num_func_defs=0
	   num_calls=0
	   }
	else
	   {
	   sfb_stack[start_depth]=seen_file_before
	   start_stack[start_depth]=start_name
	   start_depth++
	   }
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
	if ($2 == tran_unit_name)
	   {
	   tran_unit_name="###"
	   seen_file_before=0
	   delete files_seen
	   sum_tran_info()
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

$1 == ".DATE" {
	new_tran_unit=1
	next
	}

$1 == ".CALL" {
	num_calls++
	TU_call_name[$2]++
	call_name[$2]++
	next
	}

$1 == ".FUNC" {
	total_func_defs++
	num_func_defs++
	TU_func_def_name[$2]=1
	next
	}

	{
	next
	}

END {
	print "total func defs " total_func_defs
	TEMP_FILE="TeMp.tEmP"
	printf("") > TEMP_FILE
	for (i in TU_func_defs)
	   print i " " TU_func_defs[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: func_defs.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in TU_func_defs_called)
	   print i " " TU_func_defs_called[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: func_defs_called.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	print "File: func_call_names.d"
	for (c in call_name)
	   print c " " call_name[c]
	print "__@__ 0"
	print "End File"
	
	system("rm " TEMP_FILE)
	}

