#
# fieldtype.awk,  5 Oct 08

function dump_stack()
{
print ">"
print start_depth " " start_name
for (s=start_depth-1; s>=0; s--)
   print s " " start_stack[s]
}


BEGIN {
	in_struct=0
	total_fields=0
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

$1 == ".FILE" {
	if (start_depth != 0)
	   print "!! " start_depth " " start_name
	seen_file_before=0
	start_depth=0
	start_name="###"
	}

seen_file_before == 1 {
	next
	}

$1 == ".STRUCT" {
	num_structs++
	in_struct=1
	num_fields=0
	type_changes=0
	last_type=""
	next
	}

(in_struct == 1) && ($1 == ".MEMBER") {
	cur_type=$3
	if (cur_type ~ /^array/)
	   cur_type="array"
	else if (cur_type ~ /^ptr_to/)
	   cur_type="ptr_to"
	cur_name=tolower($2)
	gsub(/_/, "", cur_name)
	name_type[cur_name " " cur_type]++
	file_name_type[cur_name " " cur_type]=file_name_type[cur_name " " cur_type] " " start_name
	field_name[cur_name]++
	total_fields++
	next
	}

(in_struct == 1) {
	in_struct=0
	next
	}

END {
	TEMP_FILE="TeMp.tEmP"
	printf("") > TEMP_FILE
	for (f in name_type)
	   if (name_type[f] > 1)
	      {
# How many different files was the field defined in?
	      num_files=split(file_name_type[f], fname, " ")
	      src_file=fname[1]
	      diff_files=1
	      for (nf=2; nf <= num_files; nf++)
		 if (src_file != fname[nf])
		    diff_files++
	      
	      split(f, n_t, " ")
	      print f " " name_type[f] " " field_name[n_t[1]]  " " diff_files >> TEMP_FILE
	      }
	unique_fields=0
	shared_fields=0
	for (f in field_name)
	   {
	   unique_fields++
	   if (field_name[f] > 1)
	      {
	      shared_fields++
	      print f " xxxxx " field_name[f] >> TEMP_FILE
	      }
	   }

	print "structs " num_structs " fields " total_fields " unique fields " unique_fields " shared fields " shared_fields
	system("sort < " TEMP_FILE)

	system("rm " TEMP_FILE)
	}

