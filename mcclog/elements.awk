# elements.awk,  9 Dec 03
#

function start_file()
{
inc_depth=0
in_sys_hdr=0
hdr_seen_before=0
in_switch=0
num_default=0
}

BEGIN {
   start_file()
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

$1 == "array_elements" {
   num_arrays++
   num_elems[$2]++
   next
   }

   {
   next
   }

END {
	TEMP_FILE="el" systime()
	print "num arrays " num_arrays
	
	printf("") > TEMP_FILE
	for (i in num_elems)
	   print i " " num_elems[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: num_elems.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	system("rm " TEMP_FILE)
	}

