# macroid.awk, 28 Dec 03
#

function start_file()
{
in_sys_hdr=0
hdr_seen_before=0
inc_depth=0
}


BEGIN {
   start_file()
   num_define=0
   num_param=0
   }

$1 == "include_open" {
   inc_depth++
   sys_hdr_stack[inc_depth]=in_sys_hdr
   in_sys_hdr= ($2 == "h_hdr")
   hdr_seen_stack[inc_depth]=hdr_seen_before
   hdr_seen_before= (hdrs_seen[$3] != 0)
   hdrs_seen[$3]=1
   next
   }

$1 == "include_close" {
   in_sys_hdr=sys_hdr_stack[inc_depth]
   hdr_seen_before=hdr_seen_stack[inc_depth]
   inc_depth--
   next
   }

$0 ~ /Copyright \(c\) 1990-.* Knowledge Software Ltd/ {
	if (inc_depth != 0)
	   print "inc_depth " inc_depth
	start_file()
	next
	}

in_sys_hdr == 1 {
	next
	}

hdr_seen_before == 1 {
	next
	}

$1 == "macro_define" {
	num_define++
	macro_def[$2]++
	next
	}

$1 == "macro_parameter" {
	num_param++
	macro_param[$2]++
	next
	}

	{
	next
	}

END {
	print "File: macro_definition " num_define
	for (m in macro_def)
	   print m " " macro_def[m]
	print "END macro_definition"
	
	print "File: macro_parameter " num_param
	for (m in macro_param)
	   print m " " macro_param[m]
	print "END macro_parameter"
	}

