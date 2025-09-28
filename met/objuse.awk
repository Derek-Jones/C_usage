# objuse.awk,  3 May 13
#
#  3 May 08 Added support for acc_per_obj.csv

function sum_tran_info()
{
num_tran_units++
# increment count of the number of times individual
# objects were accessed
for (o in tran_ext_obj_access)
   total_ind_ext_obj_access[tran_ext_obj_access[o]]++
for (o in tran_int_obj_access)
   total_ind_int_obj_access[tran_int_obj_access[o]]++
delete tran_ext_obj_access
delete tran_int_obj_access

for (o in tran_ext_obj_modify)
   total_ind_ext_obj_modify[tran_ext_obj_modify[o]]++
for (o in tran_int_obj_modify)
   total_ind_int_obj_modify[tran_int_obj_modify[o]]++
delete tran_ext_obj_modify
delete tran_int_obj_modify

}

function sum_func_info()
{
num_funcs++
# increment count of the number of times all
# objects were accessed
total_loc_obj_access[num_loc_obj_access]++
total_ext_obj_access[num_ext_obj_access]++
total_int_obj_access[num_int_obj_access]++
total_loc_obj_modify[num_loc_obj_modify]++
total_ext_obj_modify[num_ext_obj_modify]++
total_int_obj_modify[num_int_obj_modify]++

total_obj_access[num_obj_access]++
total_obj_modify[num_obj_modify]++
total_obj_ref[num_obj_access+num_obj_modify]++

if ((num_obj_access+num_obj_modify) == 0)
   print start_name " " func_name

# increment count of the number of times individual
# objects were accessed
for (o in loc_obj_access)
   ind_loc_obj_access[loc_obj_access[o]]++
for (o in ext_obj_access)
   ind_ext_obj_access[ext_obj_access[o]]++
for (o in int_obj_access)
   ind_int_obj_access[int_obj_access[o]]++
# count number of accesses per object for given total number of
# object accesses in function
for (o in loc_obj_access)
   acc_per_obj[num_loc_obj_access "," loc_obj_access[o]]++

delete loc_obj_access
delete ext_obj_access
delete int_obj_access

for (o in loc_obj_modify)
   ind_loc_obj_modify[loc_obj_modify[o]]++
for (o in ext_obj_modify)
   ind_ext_obj_modify[ext_obj_modify[o]]++
for (o in int_obj_modify)
   ind_int_obj_modify[int_obj_modify[o]]++
delete loc_obj_modify
delete ext_obj_modify
delete int_obj_modify

num_loc_obj_access=0
num_ext_obj_access=0
num_int_obj_access=0
num_loc_obj_modify=0
num_ext_obj_modify=0
num_int_obj_modify=0

num_obj_access=0
num_obj_modify=0

num_arg_unrefed=0
for (obj in decl_arg)
   if (id_scope_use[obj] == 0)
      num_arg_unrefed++
arg_unrefed[num_arg_unrefed]++

num_unrefed=0
num_nestedref=0
for (obj in decl_scope)
   {
   if (id_scope_use[obj] == 0)
      num_unrefed++
   else if (id_scope_use[obj] > decl_scope[obj])
      num_nestedref++
   }
obj_unrefed[num_unrefed]++
obj_nestedref[num_nestedref]++

delete decl_arg
delete decl_scope
delete id_scope_use
}

function get_obj_name(obj_str)
{
# Get the name of the 'outermost' object
#
name_len=match(obj_str, /[([\-.]/)
if (name_len == 0)
   obj_name=obj_str
else
   obj_name=substr(obj_str, 1, name_len-1)

#print obj_name
}

function set_id_scope_use()
{
# Set the outermost scope in which the object is referenced
#
if (id_scope_use[obj_name] == 0)
   id_scope_use[obj_name]=cur_scope
else if (id_scope_use[obj_name] > cur_scope)
   id_scope_use[obj_name]=cur_scope
}


BEGIN {
	in_func=0
	new_tran_unit=0
	seen_file_before=0
	num_funcs=0
	num_tran_units=0
	num_loc_idents=0
	num_loc_obj_access=0
	num_ext_obj_access=0
	num_int_obj_access=0
	num_loc_obj_modify=0
	num_ext_obj_modify=0
	num_int_obj_modify=0
	num_obj_access=0
	num_obj_modify=0
	nested_id_hides=0
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
	if (in_func == 1) {
	   get_obj_name($2)
	   num_loc_obj_modify++
	   loc_obj_modify[obj_name]++
	   }
	next
	}

$1 == ".ACC" {
	get_obj_name($3)
	num_obj_access++
	if ($2 == "NONE")
	   {
	   set_id_scope_use()
	   num_loc_obj_access++
	   loc_obj_access[obj_name]++
	   }
	else if ($2 == "EXTERN")
	   {
	   num_ext_obj_access++
	   ext_obj_access[obj_name]++
	   tran_ext_obj_access[obj_name]++
	   }
	else if ($2 == "STATIC")
	   {
	   num_int_obj_access++
	   int_obj_access[obj_name]++
	   tran_int_obj_access[obj_name]++
	   }
	next
	}

$1 == ".MOD" {
	get_obj_name($3)
	num_obj_modify++
	if ($2 == "NONE")
	   {
	   set_id_scope_use()
	   num_loc_obj_modify++
	   loc_obj_modify[obj_name]++
	   }
	else if ($2 == "EXTERN")
	   {
	   num_ext_obj_modify++
	   ext_obj_modify[obj_name]++
	   tran_ext_obj_modify[obj_name]++
	   }
	else if ($2 == "STATIC")
	   {
	   num_int_obj_modify++
	   int_obj_modify[obj_name]++
	   tran_int_obj_modify[obj_name]++
	   }
	next
	}

$1 == ".SCOPE" {
	if ($2 == "start")
	   cur_scope=$3-1
	else
	   cur_scope=$3-2
	next
	}

$1 == ".ARG" {
	num_loc_idents++
	decl_arg[$2]=1
	next
	}

$1 == ".LOCAL" {
	num_loc_idents++
	# How many ident definitions hide other locally ident definitions?
	# The following is not an exact test; it will count some definitions
	# as hiding when they are not.
	if ((decl_arg[$2] != 0) || (decl_scope[$2] > cur_scope))
	   nested_id_hides++
	decl_scope[$2]=cur_scope
	next
	}

$1 == ".FUNC" {
	in_func=1
	func_name=$2
	cur_scope=1
	next
	}

	{
	next
	}

END {
	print "num funcs " num_funcs
	print "num tran units " num_tran_units
	print "num idents " num_loc_idents " idents hidden by nested " nested_id_hides
	#
	# In the data written to the .met file,
	# file scope has scope 1, so block scope is scope 2,
	# so subtract off 1
	TEMP_FILE="TeMp.tEmP"
	printf("") > TEMP_FILE
	for (i in total_loc_obj_access)
	   print i " " total_loc_obj_access[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: loc_obj_access.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in total_int_obj_access)
	   print i " " total_int_obj_access[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: int_obj_access.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in total_ext_obj_access)
	   print i " " total_ext_obj_access[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: ext_obj_access.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in total_loc_obj_modify)
	   print i " " total_loc_obj_modify[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: loc_obj_modify.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in total_int_obj_modify)
	   print i " " total_int_obj_modify[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: int_obj_modify.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in total_ext_obj_modify)
	   print i " " total_ext_obj_modify[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: ext_obj_modify.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

# total over all linkages

	printf("") > TEMP_FILE
	for (i in total_obj_access)
	   print i " " total_obj_access[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: obj_access.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in total_obj_modify)
	   print i " " total_obj_modify[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: obj_modify.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in total_obj_ref)
	   print i " " total_obj_ref[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: obj_ref.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

# individual objects

	printf("") > TEMP_FILE
	for (i in ind_loc_obj_access)
	   print i " " ind_loc_obj_access[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: ind_loc_obj_access.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in ind_ext_obj_access)
	   print i " " ind_ext_obj_access[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: ind_ext_obj_access.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in ind_int_obj_access)
	   print i " " ind_int_obj_access[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: ind_int_obj_access.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in ind_loc_obj_modify)
	   print i " " ind_loc_obj_modify[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: ind_loc_obj_modify.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in ind_ext_obj_modify)
	   print i " " ind_ext_obj_modify[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: ind_ext_obj_modify.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in ind_int_obj_modify)
	   print i " " ind_int_obj_modify[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: ind_int_obj_modify.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

# translation unit references

	printf("") > TEMP_FILE
	for (i in total_ind_ext_obj_access)
	   print i " " total_ind_ext_obj_access[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: total_ind_ext_obj_access.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in total_ind_int_obj_access)
	   print i " " total_ind_int_obj_access[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: total_ind_int_obj_access.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in total_ind_ext_obj_modify)
	   print i " " total_ind_ext_obj_modify[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: total_ind_ext_obj_modify.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in total_ind_int_obj_modify)
	   print i " " total_ind_int_obj_modify[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: total_ind_int_obj_modify.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in arg_unrefed)
	   print i " " arg_unrefed[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: arg_unrefed.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in obj_unrefed)
	   print i " " obj_unrefed[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: obj_unrefed.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in obj_nestedref)
	   print i " " obj_nestedref[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: obj_nestedref.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in acc_per_obj)
	   print i "," acc_per_obj[i] >> TEMP_FILE
	print "File: acc_per_obj.csv"
	print "total access,object access,occurrences"
	system("sort -g < " TEMP_FILE)
	print "End File"

	system("rm " TEMP_FILE)
	}

