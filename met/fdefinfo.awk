# fdefinfo.awk,  8 Feb 04

function zero_counters()
{
num_uident=0
num_while=0
num_for=0
num_do=0
num_if=0
num_else=0
num_switch=0
num_cmpd=0
num_break=0
num_continue=0
num_return=0
num_goto=0
num_stmt=0
num_loop=0
num_ident=0
}

BEGIN {
	zero_counters()
	seen_func=0
	num_func=0
	num_curl=0
	num_single_bb=0
	num_looping=0
	num_nonlooping=0
	total_while=0
	total_for=0
	total_if=0
	total_switch=0
	total_expr=0
	total_return=0
	total_init=0
	}

$1 == ".INIT" {
	if (seen_func == 1)
	   total_init++
	next
	}

$1 == ".METRICS" {
	in_metrics=1
	next
	}

$1 == ".TOKS" {
	in_toks=1
	next
	}

$1 == ".FUNC" {
	seen_func=1
	num_func++
	has_return=0
	has_stmt=0
	zero_counters()
	func_start_line=$3
	next
	}

$1 == ".END" {
	if (seen_func == 1) {
	   lines_per_func[$2-func_start_line+1]++
	   if (has_return == 0)
	      returns_per_func[0]++
	   if (has_stmt == 0)
	      stmts_per_func[0]++
	   if ((num_loop == 0) && (num_if == 0) && (num_switch == 0))
	      num_single_bb++
	   else {
	      if (num_loop == 0)
	         num_nonlooping++
	      else
	         num_looping++
	      }
	   total_while+=num_while
	   total_for+=num_for
	   total_if+=num_if
	   total_switch+=num_switch
	   total_expr+=num_stmt-num_break-num_continue-num_goto-num_return-\
	   		num_if-num_switch- num_while-num_for
	   total_return+=num_return
	   func_ident[num_ident]++
	   func_uident[num_uident]++
	   func_while[num_while-num_do]++
	   func_for[num_for]++
	   func_do[num_do]++
	   func_iter[num_while+num_for]++
	   func_if[num_if]++
	   func_else[num_else]++
	   func_switch[num_switch]++
	   func_select[num_if+num_switch]++
	   func_cmpd[num_curl]++
	   func_continue[num_continue]++
	   func_break[num_break]++
	   func_return[num_return]++
	   func_goto[num_goto]++
	   func_jump[num_break+num_continue+num_goto+num_return]++
	   func_expr[num_stmt-num_break-num_continue-num_goto-num_return-\
	   		num_if-num_switch-\
			num_while-num_for]++
	   }
	in_metrics=0
	in_toks=0
	seen_func=0
	next
	}

$1 ~ /^\./ {
	in_metrics=0
	in_toks=0
	next
	}

	{
	if (in_metrics == 1)
	   {
	   for (i=1; i <= NF; i+=2)
	      if ($i == "STMTS") {
	         has_stmt=1
		 num_stmt=$(i+1)
		 stmts_per_func[$(i+1)]++
	         } else if ($i == "UNIQ_IDS") {
	         num_uident=$(i+1)
		 }
	   }
	if (in_toks == 1)
	   {
	   for (i=1; i <= NF; i+=2)
	      if ($i == "OPEN_CURL") {
	         num_curl=$(i+1)
		 } else if ($i == "IDENTIFIER") {
	         num_ident=$(i+1)
	         } else if ($i == "BREAK") {
	         num_break=$(i+1)
		 } else if ($i == "RETURN") {
	         returns_per_func[$(i+1)]++
		 num_return=$(i+1)
		 has_return=1
		 } else if ($i == "CONTINUE") {
	         num_continue=$(i+1)
		 } else if (($i == "WHILE") || ($i == "FOR") || ($i == "DO")) {
	         num_loop=$(i+1)
		 if ($i == "WHILE")
		    num_while=$(i+1)
		 if ($i == "FOR")
		    num_for=$(i+1)
		 if ($i == "DO")
		    num_do=$(i+1)
		 } else if ($i == "IF") {
	         num_if=$(i+1)
		 } else if ($i == "ELSE") {
	         num_else=$(i+1)
		 } else if ($i == "SWITCH") {
	         num_switch=$(i+1)
		 } else if ($i == "GOTO") {
	         num_goto=$(i+1)
		 }
	   }
	next
	}

END {
	print "single bb " num_single_bb
	print "non-looping " num_nonlooping
	print "looping " num_looping
	print "total while " total_while " for " total_for " if " total_if " switch " total_switch
	print "total expr " total_expr " return " total_return " init " total_init

	# Following percentages taken from ngram output
	# (yes, visible counts used to tune translation counts)
	for_clause1=total_for*0.85
	for_expr1=total_for*0.88
	for_expr2=total_for*0.87
	total_ret_expr=total_return*0.87
	total_full_expr=total_while+for_clause1+for_expr1+for_expr2+\
			total_if+total_switch+\
	                total_expr+total_ret_expr+total_init
	print "File: full_expr_per_func.t"
	printf(" object declaration initializer ,, %2.1f\n", 100*(total_init/total_full_expr))
	printf(" expression statement ,, %2.1f\n", 100*(total_expr/total_full_expr))
	printf(" if controlling expression ,, %2.1f\n", 100*(total_if/total_full_expr))
	printf(" while controlling expression ,, %2.1f\n", 100*(total_while/total_full_expr))
	printf(" switch controlling expression ,, %2.1f\n", 100*(total_switch/total_full_expr))
	printf(" for controlling expression ,, %2.1f\n", 100*(for_expr2/total_full_expr))
	printf(" for clause-1 ,, %2.1f\n", 100*(for_clause1/total_full_expr))
	printf(" for expr-1 ,, %2.1f\n", 100*(for_expr1/total_full_expr))
	printf(" return expression ,, %2.1f\n", 100*(total_ret_expr/total_full_expr))
	print "End File"
	
	TEMP_FILE=systime() ".fd"
	printf("") > TEMP_FILE
	for (i in returns_per_func)
	   print i " " returns_per_func[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: returns_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	printf("") > TEMP_FILE
	for (i in stmts_per_func)
	   print i " " stmts_per_func[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: stmts_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	   
	printf("") > TEMP_FILE
	for (i in lines_per_func)
	   print i " " lines_per_func[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: lines_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	   
	printf("") > TEMP_FILE
	for (i in func_while)
	   print i " " func_while[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: while_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in func_for)
	   print i " " func_for[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: for_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in func_do)
	   print i " " func_do[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: do_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in func_if)
	   print i " " func_if[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: if_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in func_else)
	   print i " " func_else[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: else_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in func_switch)
	   print i " " func_switch[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: switch_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	printf("") > TEMP_FILE
	for (i in func_cmpd)
	   print i " " func_cmpd[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: cmpd_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in func_ident)
	   print i " " func_ident[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: allident_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	printf("") > TEMP_FILE
	for (i in func_uident)
	   print i " " func_uident[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: uident_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	printf("") > TEMP_FILE
	for (i in func_select)
	   print i " " func_select[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: select_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	printf("") > TEMP_FILE
	for (i in func_iter)
	   print i " " func_iter[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: iter_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	printf("") > TEMP_FILE
	for (i in func_break)
	   print i " " func_break[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: break_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	printf("") > TEMP_FILE
	for (i in func_continue)
	   print i " " func_continue[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: continue_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	printf("") > TEMP_FILE
	for (i in func_return)
	   print i " " func_return[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: return_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	printf("") > TEMP_FILE
	for (i in func_goto)
	   print i " " func_goto[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: goto_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	printf("") > TEMP_FILE
	for (i in func_jump)
	   print i " " func_jump[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: jump_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	printf("") > TEMP_FILE
	for (i in func_expr)
	   print i " " func_expr[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: expr_per_func.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	system("rm " TEMP_FILE)
	}

