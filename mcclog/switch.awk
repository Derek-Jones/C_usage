# switch.awk, 30 Nov 03
#
# needs mkctype.awk

function start_file()
{
inc_depth=0
in_sys_hdr=0
hdr_seen_before=0
in_switch=0
num_default=0
}

BEGIN {
   num_imp_cast=0
   char_type[0]="signedchar"
   char_type[1]="char"
   char_type[2]="unsignedchar"
   int_type[0]="short"
   int_type[1]="int"
   int_type[2]="long"
   int_sign[0]="signed"
   int_sign[1]=""
   int_sign[2]="unsigned"
   start_file()
   init_types()
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

$1 == "SWITCH" {
   in_switch=1
   num_switch++
   num_case_labels=0
   min_case_valu=0xfffffff
   max_case_valu=-0xfffffff
   if ($2 == 2)
   # signed plain unsigned
      switch_type[char_type[$3]]++
   else if ($2 == 3)
   #
   # short int long
      switch_type[int_sign[$3] int_type[$4]]++
   else if ($2 == 15)
      switch_type["bit-field"]++
   else if ($2 == 10)
      switch_type["enum"]++
   else
      switch_type[$2]++
      #switch_type["other-type"]++
   has_default=0
   if ($5 == "has") {
      has_default=1
      num_default++
      }
   next
   }

$1 == "End_SWITCH" {
   in_switch=0
   case_density[has_default " " int(25*num_case_labels/(max_case_valu-min_case_valu+1))]++
   case_span[has_default " " (max_case_valu-min_case_valu+1)]++
   delete valu_used
   next
   }

   {
   if (in_switch == 1) {
      for (i=$1; i <= $2; i++) {
         num_case_labels++
	 valu_used[i]=1
	 }
      if ($1 < min_case_valu)
         min_case_valu=$1
      if ($2 > max_case_valu)
         max_case_valu=$2
   }
   next
   }

END {
	TEMP_FILE="sw" systime()
	print num_switch " " num_default
	print "File: switch_cntrl_type.t"
	others=0
	for (i in switch_type)
	   {
	   percent=100*(switch_type[i]/num_switch)
	   if (percent < 0.1)
	      others=others+percent
	   else
	      {
	      pr_type=""
	      mk_pr_type(i)
	      printf(" %s ,, %2.1f\n", pr_type, percent)
	      }
	   }
	printf(" other-types ,, %2.1f\n", others)
	print "End File"
	
	printf("") > TEMP_FILE
	for (i in case_density)
	   print i " " case_density[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: case_density.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in case_span)
	   print i " " case_span[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: case_span.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	system("rm " TEMP_FILE)
	}

