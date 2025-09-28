# ecvals.awk, 27 Aug 03
#

function get_enum_val()
{
enum_val=or($NF, lshift(or($(NF-1), lshift(or($(NF-2), lshift($(NF-3), 8)), 8)), 8))
if ($2 == "-0") {
   enum_val=-enum_val
   num_neg_econst++
   }
}

function start_enum_def()
{
num_init=0
num_uninit=0
num_econst=0
}

function start_file()
{
in_sys_hdr=0
hdr_seen_before=0
inc_depth=0
}

BEGIN {
   num_neg_econst=0
   all_uninit=0
   num_edefs=0
   start_enum_def()
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

$1 == "enum_init" {
   num_init++
   get_enum_val()
   ec_vals[enum_val]++
   next
   }

$1 == "enum_uninit" {
   num_uninit++
   get_enum_val()
   ec_vals[enum_val]++
   next
   }

$1 == "enum_def_end" {
   if ((num_init == 0) && (num_uninit > 0))
      all_uninit++
   num_edefs++
   num_dup_vals=0
   num_dup_disjoint=0
   many_bits_disjoint=0
   min_val=0xffffffff+0
   max_val=-0xffffffff+0
   num_econst=0
   bits_disjoint=1
   for (i in ec_vals) {
      num_econst++
      if (i == 0)
         bits_disjoint=0
      #
      # the following is needed to prevent the value is being compared
      # as a character rather than a numeric value
      if (i+0 < min_val)
         min_val=i+0
      if (i+0 > max_val)
         max_val=i+0
      if (bits_disjoint == 1)
         for (j in ec_vals)
            if (i != j ) {
	       if (and(i, j) != 0)
	          bits_disjoint=0
	       }
     if (ec_vals[i] > 1) {
        num_dup_vals++
	#if (bits_disjoint == 1)
	#   num_dup_disjoint++
	}
      }
   if ((bits_disjoint == 1) && \
       !((num_econst == 2) && (ec_vals[1] == 1)))
      many_bits_disjoint=1
   if (100*(num_econst/(max_val-min_val+1)) > 100) {
      print "num_econst " num_econst " max_val " max_val " min_val " min_val
      for (i in ec_vals)
         print i
      }

   if (num_econst < (max_val-min_val+1))
      disjoint_density[bits_disjoint]++
   ec_min_val[min_val]++
   ec_max_val[max_val]++
   ec_density[int(100*(num_econst/(max_val-min_val+1)))]++
   ec_dup_vals[num_dup_vals]++
   ec_many_disjoint[many_bits_disjoint]++
   ec_bits_disjoint[bits_disjoint]++
   ec_uninit[num_uninit]++
   ec_init[num_init]++
   ec_total[num_econst]++
   start_enum_def()
   delete ec_vals
   next
   }

   {
   next
   }

END {
	print "num_neg_econst " num_neg_econst
	TEMP_FILE="ec" systime()
	printf("") > TEMP_FILE
	for (i in ec_total)
	   print i " " ec_total[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: ec_total.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in ec_uninit)
	   print i " " ec_uninit[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: ec_uninit.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in ec_init)
	   print i " " ec_init[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: ec_init.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in ec_density)
	   print i " " ec_density[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: ec_density.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in ec_dup_vals)
	   print i " " ec_dup_vals[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: ec_dup_vals.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in ec_bits_disjoint)
	   print i " " ec_bits_disjoint[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: ec_bits_disjoint.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in ec_many_disjoint)
	   print i " " ec_many_disjoint[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: ec_many_disjoint.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in disjoint_density)
	   print i " " disjoint_density[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: ec_disjoint_density.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in ec_min_val)
	   print i " " ec_min_val[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: ec_min_val.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in ec_max_val)
	   print i " " ec_max_val[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: ec_max_val.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	print "File: enum_const_role.t"
	printf("All value assigned implicitly ,, %2.1f\n", 100*(all_uninit/num_edefs))
	printf("All values are bitwise distinct and zero is not used ,, %2.1f\n", 100*(ec_bits_disjoint[1]/num_edefs))
	printf("One or more constants share the same value ,, %2.1f\n", 100*((num_edefs-ec_dup_vals[0])/num_edefs))
	printf("All values are continuous , i.e. , number of enumeration constants equals maximum value minus minimum value plus 1 ,, %2.1f\n", 100*(ec_density[100]/num_edefs))
	print "End File"

	system("rm " TEMP_FILE)
	}

