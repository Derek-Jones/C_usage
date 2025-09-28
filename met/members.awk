# members.awk,  5 Oct 08
#
# needs mkctype.awk

BEGIN {
        init_types()
	in_struct=0
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

$1 == ".DATE" {
	new_tran_unit=1
	next
	}

$1 == ".GLOBAL" {
	in_global=(seen_file_before == 0)
	next
	}

$1 == ".STRUCT" {
	in_struct=1
	next
	}

$1 == ".UNION" {
	in_struct=0
	next
	}

$1 == ".MEMBER" {
	pr_type=""
	mk_pr_type($3)
	if (in_struct == 1)
	   {
	   st_member_type[pr_type]++
	   total_st_members++
	} else {
	   un_member_type[pr_type]++
	   total_un_members++
	   }
	next
	}

END {
        print "File: st_member_type.t"
	others=0
	for (i in st_member_type)
	   {
	   percent=100*(st_member_type[i]/total_st_members)
	   if (percent < 1)
	      others+=percent
	   else
	      printf(" %s ,, %2.1f\n", i, percent)
	   }
        printf(" other-types ,, %2.1f\n", others)
	print "End File"

        print "File: un_member_type.t"
	others=0
	for (i in un_member_type)
	   {
	   percent=100*(un_member_type[i]/total_un_members)
	   if (percent < 1)
	      others+=percent
	   else
	      printf(" %s ,, %2.1f\n", i, percent)
	   }
        printf(" other-types ,, %2.1f\n", others)
	print "End File"

	}

