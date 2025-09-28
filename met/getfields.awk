#
# getfields.awk, 17 Nov 08

function dump_stack()
{
print ">"
print start_depth " " start_name
for (s=start_depth-1; s>=0; s--)
   print s " " start_stack[s]
}

function print_fields()
{
print "|start_struct| " num_fields
for (f=1; f <= num_fields; f++)
   print field_info[f]
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
	in_struct=1
	num_fields=0
	next
	}

(in_struct == 1) && ($1 == ".MEMBER") {
	num_fields++
	field_info[num_fields]=$0
	next
	}

(in_struct == 1) {
	print_fields()
	in_struct=0
	next
	}

END {
	}

