# numexterns.awk,  5 Oct 08

BEGIN {
	num_externs=0
	num_funcs=0
	new_tran_unit=0
	seen_file_before=0
	new_tran_unit=0
	total_glob_init=0
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
	   num_externs=0
	   num_funcs=0
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
	in_global=0
	if ($2 == tran_unit_name)
	   {
	   tran_unit_name="###"
	   seen_file_before=0
	   delete files_seen
	   extern_count[int((num_externs+25)/50)]++
	   func_def_count[num_funcs]++
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

$1 == ".FUNC" {
	num_funcs++
	next
	}

$1 ~ /^\./ {
	in_global=0
	next
	}

	{
	if ((in_global == 1) && ($2 == "EXTERNAL")) {
	   num_externs++
	   }
	next
	}

END {
	extern_count[int((num_externs+25)/50)]++
	extern_count[0]--
	func_def_count[0]--
	TEMP_FILE="TeMp.tEmP"
	printf("") > TEMP_FILE
	for (i in extern_count)
	   print i " " extern_count[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: externcount.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	func_def_count[num_funcs]++
	func_def_count[0]--
	TEMP_FILE="TeMp.tEmP"
	printf("") > TEMP_FILE
	for (i in func_def_count)
	   print i " " func_def_count[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: funcdefcount.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	system("rm " TEMP_FILE)
	}

