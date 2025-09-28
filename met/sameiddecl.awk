# sameiddecl.awk,  5 Oct 08
#

function sum_TU_info()
{
for (i in member_name)
   num_member_decls[member_name[i]]++
delete member_name
for (i in param_name)
   num_param_decls[param_name[i]]++
delete param_name
for (i in locobj_name)
   num_locobj_decls[locobj_name[i]]++
delete locobj_name
}

BEGIN {
	new_tran_unit=0
	num_ord_ids=0
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
	if ($2 == tran_unit_name)
	   {
	   tran_unit_name="###"
	   seen_file_before=0
	   delete files_seen
	   sum_TU_info()
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

$1 == ".MEMBER" {
	member_name[$2]++
	next
	}

$1 == ".ARG" {
	param_name[$2]++
	next
	}

$1 == ".LOCAL" {
	if (($11 == "IDENT") && ($12 != "econst"))
	      locobj_name[$2]++
	next
	}

$1 ~ /^\./ {
	in_global=0
	next
	}

	{
	if ((in_global == 1) && ($11 == "IDENT") && ($12 != "econst"))
	   total_glob_objs++
	next
	}

END {
	TEMP_FILE="TeMp.tEmP"

	printf("") > TEMP_FILE
	for (i in num_member_decls)
	   print i " " num_member_decls[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: same_member_id.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	printf("") > TEMP_FILE
	for (i in num_param_decls)
	   print i " " num_param_decls[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: same_param_id.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	printf("") > TEMP_FILE
	for (i in num_locobj_decls)
	   print i " " num_locobj_decls[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: same_locobj_id.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	system("rm " TEMP_FILE)
	}

