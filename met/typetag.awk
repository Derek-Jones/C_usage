# typetag.awk,  5 Oct 08

BEGIN {
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

$1 == ".LOCAL" {
	if ($(NF-1) == "TYPEDEF")
	   loc_typedef++
	else if ($NF == "TAG")
	   loc_tag++
	next
	}

$1 ~ /^\./ {
	in_global=0
	next
	}

	{
	if (in_global == 1) {
	   if ($(NF-1) == "TYPEDEF")
	      {
	      typedef_name[$1]=1
	      glob_typedef++
	      if (tag_name[$1] == 1)
	         type_tag_name++
	      }
	   else if ($NF == "TAG")
	      {
	      tag_name[$1]=1
	      glob_tag++
	      if (typedef_name[$1] == 1)
	         type_tag_name++
	      if (typedef_name[toupper($1)] == 1)
	         upper_type_tag_name++
	      }
	   }
	next
	}

END {
	print "local typedef " loc_typedef
	print "local tag " loc_tag
	print "global typedef " glob_typedef
	print "global tag " glob_tag
	print "shared names " type_tag_name
	print "upper case shared names " upper_type_tag_name
	}

