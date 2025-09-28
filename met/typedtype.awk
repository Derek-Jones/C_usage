# typedtype.awk,  5 Oct 08
#
# needs mkctype.awk

function typedef_type(type_str)
{
num_typedef++
pr_type=""
mk_pr_type(type_str)
typed_type[pr_type]++
}

BEGIN {
	new_tran_unit=0
	seen_file_before=0
	init_types()
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

$1 == ".LOCAL" {
	if ($11 == "TYPEDEF")
	   typedef_type($12)
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
	   if ($9 == "TYPEDEF")
	      typedef_type($10)
	   }
	next
	}

END {
	print "num typedef " num_typedef
	print "File: typedef_type.t"
	others=0
	for (i in typed_type) {
	   percent=100*(typed_type[i]/num_typedef)
	   if (percent < 1.0)
	      others=others+percent
	   else
	      printf(" %s ,, %2.2f\n", i, percent)
	   }
	printf(" other-types ,, %2.2f\n", others)
	print "End File"
	}

