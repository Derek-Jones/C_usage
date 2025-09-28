# numlocal.awk,  5 Oct 08
#

function sum_func_info()
{
num_funcs++
total_loc_objs+=num_objs
total_params+=num_params
param_count[num_params]++
local_id_count[num_ids]++
local_obj_count[num_objs]++
local_tag_count[num_tags]++
local_econst_count[num_econsts]++
local_typedef_count[num_typedefs]++
size_all_params[all_param_size]++
size_all_locals[all_local_size]++
for (l in cur_scope)
   scope_info[l]+=cur_scope[l]
delete cur_scope
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

$1 == ".DATE" {
	new_tran_unit=1
	next
	}

$1 == ".GLOBAL" {
	in_global=(seen_file_before == 0)
	next
	}

$1 == ".ARG" {
	cur_scope[$4]++
	num_params++
	num_objs++
	param_size[$10]++
	all_param_size+=$10
	next
	}

$1 == ".LOCAL" {
	num_ids++
	if ($11 == "IDENT") {
	   num_ord_ids++
	   if ($12 == "econst")
	      num_econsts++
	   else {
	      cur_scope[$4]++
	      num_objs++
	      local_size[$10]++
	      all_local_size+=$10
	      }
	   }
	else if ($9 == "TAG")
	      num_tags++
	else if ($11 == "TYPEDEF")
	      num_typedefs++
	next
	}

$1 == ".FUNC" {
	in_func=1
	num_params=0
	num_objs=0
	num_econsts=0
	num_tags=0
	num_typedefs=0
	num_ids=0
	all_param_size=0
	all_local_size=0
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
	print "file-scope " total_glob_objs " function-defs " num_funcs " parameters " total_params " block-scope " total_loc_objs
	#
	# In the data written to the .met file,
	# file scope has scope 1, so block scope is scope 2,
	# so subtract off 1
	TEMP_FILE="TeMp.tEmP"
	printf("") > TEMP_FILE
	for (i in scope_info)
	   print i-1 " " scope_info[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: locscope.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	others=0
	for (i in param_count)
	   {
	   percent=100*(param_count[i]/num_funcs)
	   printf("%d %d %2.1f\n", i, param_count[i], percent) >> TEMP_FILE
	   }
	close(TEMP_FILE)
	print "File: paramcount.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in param_size)
	   print param_size[i] " " i >> TEMP_FILE
	close(TEMP_FILE)
	print "File: paramsize.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in size_all_params)
	   print size_all_params[i] " " i >> TEMP_FILE
	close(TEMP_FILE)
	print "File: totparamsize.d"
	system("sort -gr < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in local_obj_count)
	   print i " " local_obj_count[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: locobjcnt.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in local_tag_count)
	   print i " " local_tag_count[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: loctagcnt.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in local_typedef_count)
	   print i " " local_typedef_count[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: loctypedefcnt.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in local_econst_count)
	   print i " " local_econst_count[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: loceconstcnt.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in local_size)
	   print local_size[i] " " i >> TEMP_FILE
	close(TEMP_FILE)
	print "File: locsize.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in size_all_locals)
	   print size_all_locals[i] " " i >> TEMP_FILE
	close(TEMP_FILE)
	print "File: totlocalsize.d"
	system("sort -gr < " TEMP_FILE)
	print "End File"

	system("rm " TEMP_FILE)
	}

