# getresid.awk, 23 Jan 04
#

function start_file()
{
inc_depth=0
in_sys_hdr=0
hdr_seen_before=0
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

$3 ~ /\(130.\)/ ||
$3 == "(1310)" {
   resid[substr($3, 2, 4) " " substr($5, 2, length($5)-2)]++
   next
   }

   {
   next
   }

END {
	for (i in resid)
	   print i " " resid[i]
	}

