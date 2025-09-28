# numglob.awk,  5 Oct 08

BEGIN {
	num_internal_id=0
	mult_internal_id=0
	new_tran_unit=0
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
	   num_globals=0
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
	   global_count[int((num_globals+5)/10)]++
	   for (i in internal_func)
	      {
	      num_internal_func++
	      if (internal_func[i] > 1)
	         mult_internal_func++
	      }
	   for (i in internal_obj)
	      {
	      num_internal_obj++
	      if (internal_obj[i] > 1)
	         mult_internal_obj++
	      }
	   start_name="###"
	   delete files_seen
	   delete internal_func
	   delete internal_obj
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

$1 ~ /^\./ {
	in_global=0
	next
	}

	{
	if (in_global == 1) {
	   num_globals++
	   if ($2 == "INTERNAL")
	      {
	      if ($NF == "FUNC")
	         internal_func[$1]++
	      else
	         internal_obj[$1]++
	      }
	   }
	next
	}

END {
	print "num internal func " num_internal_func
	print "multiply declared internal func " mult_internal_func
	print "num internal obj " num_internal_obj
	print "multiply declared internal obj " mult_internal_obj
	TEMP_FILE="TeMp.tEmP"
	printf("") > TEMP_FILE
	for (i in global_count)
	   print i " " global_count[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: globcount.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	system("rm " TEMP_FILE)
	}

