# pointedto.awk,  5 Oct 08
#
# needs mkctype.awk

function decl_nest(obj_type)
{
is_ptr=0
if (index(obj_type, "ptr_to_func") == 1) {
   # do nothing
   }
else if (index(obj_type, "ptr_to") == 1) {
   sub("ptr_to", "", obj_type)
   is_ptr=1
   }
else if (index(obj_type, "constptr_to") == 1) {
   sub("constptr_to", "", obj_type)
   is_ptr=1
   }
else if (index(obj_type, "volatileptr_to") == 1) {
   sub("volatileptr_to", "", obj_type)
   is_ptr=1
   }
if (is_ptr == 1) {
   pr_type=""
   mk_pr_type(obj_type)
   num_elem_type[pr_type]++
   num_array_types++
   }
}

BEGIN {
	init_types()	
	new_tran_unit=0
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
	in_global=0
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

$1 == ".DATE" {
	new_tran_unit=1
	next
	}

$1 == ".ARG" {
	decl_nest($NF)
	next
	}

$1 == ".LOCAL" {
	if ($11 == "IDENT")
	   decl_nest($NF)
	next
	}

$1 ~ /^\./ {
	in_global=0
	next
	}

	{
	if ((in_global == 1) && ($(NF-1) == "IDENT"))
	   decl_nest($NF)
	next
	}

END {
	TEMP_FILE="TeMp.tEmP"
	printf("") > TEMP_FILE
	other_types=0
	for (i in num_elem_type)
	   if (100*(num_elem_type[i]/num_array_types) > 1.0) {
	      printf("%s ,, %2.1f\n", i, 100*(num_elem_type[i]/num_array_types)) >> TEMP_FILE
	   } else {
	      other_types+=100*(num_elem_type[i]/num_array_types)
	   }
	printf("other-types ,, %2.1f\n", other_types) >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -gr -k 3 < " TEMP_FILE)

	system("rm " TEMP_FILE)
	}

