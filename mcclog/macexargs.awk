# macexargs.awk,  3 Sep 03
#

function start_file()
{
in_sys_hdr=0
hdr_seen_before=0
inc_depth=0
seen_produced=0
}

function start_macro_exp()
{
num_macro_defined=0
num_func_macro_defined=0
num_macro_expanded=0
num_func_expanded=0
}


BEGIN {
   total_macro_defined=0
   total_func_macro_defined=0
   start_file()
   start_macro_exp()
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
	if (seen_produced == 1) {
	   all_defined[int((5+num_macro_defined)/10)]++
	   func_defined[int((5+num_func_macro_defined)/10)]++
	   all_expands[int((5+num_macro_expanded)/10)]++
	   func_expands[int((5+num_func_expanded)/10)]++
	   total_macro_defined+=num_macro_defined
	   total_func_macro_defined+=num_func_macro_defined
	   delete hdrs_seen
	   }
	if (inc_depth != 0)
	   print "inc_depth " inc_depth
	start_file()
	start_macro_exp()
	next
	}

# a useful sanity check
$2 == "produced" {
	seen_produced=1
	next
	}

in_sys_hdr == 1 {
	next
	}

hdr_seen_before == 1 {
	next
	}

$0 == "func_macro_define" {
   num_func_macro_defined++
   next
   }

$1 == "macro_define" {
   num_macro_defined++
   next
   }

$1 == "expand_macro" {
   num_macro_expanded++
   next
   }

$1 == "function_macro_args" {
   num_func_expanded++
   func_mac_args[$2]++
   next
   }

	{
	next
	}

END {
	print "Total macros defined " total_macro_defined " total function-macros " total_func_macro_defined
	TEMP_FILE=systime() ".fa"
	printf("") > TEMP_FILE
	for (i in all_defined)
	   print i " " all_defined[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: all_macro_defines.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in func_defined)
	   print i " " func_defined[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: func_macro_defines.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in func_mac_args)
	   print i " " func_mac_args[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: macex_args.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in all_expands)
	   print i " " all_expands[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: all_m_expands.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in func_expands)
	   print i " " func_expands[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: func_m_expands.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	system("rm " TEMP_FILE)
	}

