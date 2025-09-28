# skipif.awk,  6 Sep 03
#

function start_file()
{
inc_depth=0
tu_skipped_if=0
tu_skipped_else=0
dotc_skipped_if=0
dotc_skipped_else=0
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
	tu_if_total[int(tu_skipped_if/10)]++
	tu_else_total[int(tu_skipped_else/10)]++
	dotc_if_total[int(dotc_skipped_if/10)]++
	dotc_else_total[int(dotc_skipped_else/10)]++
	if (inc_depth != 0)
	   print "inc_depth " inc_depth
	start_file()
	next
	}

in_sys_hdr == 1 {
	next
	}

$1 == "Skipped_if" {
   tu_skipped_if=tu_skipped_if+$2
   if (inc_depth == 0) {
      dotc_skipped_if=dotc_skipped_if+$2
      skipped_if[$2]++
      }
   next
   }

$1 == "Skipped_else" {
   tu_skipped_else=tu_skipped_else+$2
   if (inc_depth == 0) {
      dotc_skipped_else=dotc_skipped_else+$2
      skipped_else[$2]++
      }
   next
   }

   {
   next
   }

END {
	TEMP_FILE="sf" systime()
	printf("") > TEMP_FILE
	for (i in skipped_if)
	   print i " " skipped_if[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: skipped_if.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in skipped_else)
	   print i " " skipped_else[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: skipped_else.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in tu_if_total)
	   print i " " tu_if_total[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: tu_if_total.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in tu_else_total)
	   print i " " tu_else_total[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: tu_else_total.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in dotc_if_total)
	   print i " " dotc_if_total[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: dotc_if_total.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in dotc_else_total)
	   print i " " dotc_else_total[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: dotc_else_total.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	system("rm " TEMP_FILE)
	}

