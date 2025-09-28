#
# fielduse.awk, 23 Feb 13

function process_members()
{
num_types_seen=asort(types_seen)
if ((num_types_seen != 1) && (num_fields > 3) && (num_types_seen != num_fields))
   {
   type_pattern=""
   for (t=1; t<= num_types_seen; t++)
      type_pattern=type_pattern " " types_seen[t]
   printf("%2d  %2d  %2d  %5.2f %s\n", \
		num_fields, type_changes-1, num_types_seen, \
		(1.0*type_changes)/num_types_seen, \
		type_pattern)
   total_type_pattern[num_fields "," type_pattern]++
   minch_type_pattern[num_fields "," type_pattern]+= (type_changes==num_types_seen)
   ratio_change_seen[(10*type_changes)/num_types_seen]++
   }
delete types_seen
in_struct=0
}

BEGIN {
	in_struct=0
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

$1 == ".STRUCT" {
	if (in_struct == 1)
	   process_members()
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
	if (last_type != cur_type)
	   {
# type_changes will be one greater than the actual number of changes.
	   type_changes++
	   last_type=cur_type
	   }
	num_fields++
	types_seen[last_type]++
	next
	}

(in_struct == 1) {
	process_members()
	next
	}

END {
	TEMP_FILE="TeMp.tEmP"
	printf("") > TEMP_FILE
	for (i in ratio_change_seen)
	      printf("%4d %5.2f\n", ratio_change_seen[i], i/10.0) >> TEMP_FILE
	close(TEMP_FILE)
	print "File: ratio_change_seen"
	system("sort -gr -k 2 < " TEMP_FILE)

	printf("") > TEMP_FILE
	for (i in total_type_pattern)
	      printf("%s,%d,%d\n", i, total_type_pattern[i], \
				minch_type_pattern[i]) >> TEMP_FILE
#	      printf("%-18s %4d %5.1f\n", i, total_type_pattern[i], \
#			   (100.0*minch_type_pattern[i])/total_type_pattern[i]) >> TEMP_FILE
	close(TEMP_FILE)
	print "File: type_patterns"
	system("sort -g < " TEMP_FILE)

	system("rm " TEMP_FILE)
	}

