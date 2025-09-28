# linkage.awk,  5 Oct 08

BEGIN {
	new_tran_unit=0
	total_glob_init=0
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
	   num_external_func=0
	   num_internal_func=0
	   num_external_obj=0
	   num_internal_obj=0
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
	   ext_func[int((5+num_external_func)/10)]++
	   int_func[int((5+num_internal_func)/10)]++
	   ext_obj[int((5+num_external_obj)/10)]++
	   int_obj[int((5+num_internal_obj)/10)]++
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

$1 == ".DATE" {
	new_tran_unit=1
	next
	}

$1 == ".GLOBAL" {
	in_global=(seen_file_before == 0)
	next
	}

$1 ~ /^\./ {
	in_global=0
	next
	}

	{
	if (in_global == 1) {
	   if ($NF == "FUNC") {
	      if ($2 == "EXTERNAL")
	         num_external_func++
	      if ($2 == "INTERNAL")
	         num_internal_func++
	      }
	   if ($11 == "IDENT") {
	      if ($2 == "EXTERNAL")
	         num_external_obj++
	      if ($2 == "INTERNAL")
	         num_internal_obj++
	      }
	   }
	next
	}

END {
	TEMP_FILE="TeMp.tEmP"
	printf("") > TEMP_FILE
	for (i in ext_func)
	   print i " " ext_func[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: extfunc.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in int_func)
	   print i " " int_func[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: intfunc.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in ext_obj)
	   print i " " ext_obj[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: extobj.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in int_obj)
	   print i " " int_obj[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: intobj.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	system("rm " TEMP_FILE)
	}

