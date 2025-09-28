# blocknest.awk, 18 Oct 07
#

function print_cmpd_stack()
{
print line_num
for (c=block_nest; c > 0; c--)
   print c " : " loop_hdr[c]
}

function zero_counters()
{
block_nest=0
cmpd_nest=0
loop_nest=0
select_nest=0
ifelse_nest=0
switch_nest=0
return_cnt=0
break_cnt=0
continue_cnt=0
last_was_push=0
case_stmt_cnt=0
loop_stmt_cnt=0
iter_stmt_cnt=0
cur_max_block_nest=0
cur_max_cmpd_nest=0
cur_max_select_nest=0
cur_max_loop_nest=0
cur_max_ifelse_nest=0
}

function end_file()
{
max_block_nest[cur_max_block_nest]++
max_cmpd_nest[cur_max_cmpd_nest]++
max_select_nest[cur_max_select_nest]++
max_loop_nest[cur_max_loop_nest]++
max_ifelse_nest[cur_max_ifelse_nest]++
zero_counters()
}

function push_cmpd_hdr(cmpd_hdr)
{
last_was_push=1
block_nest++
if (block_nest > cur_max_block_nest)
   cur_max_block_nest=block_nest
if (cmpd_hdr == "{")
   {
   cmpd_nest++
   if (cmpd_nest > cur_max_cmpd_nest)
      cur_max_cmpd_nest=cmpd_nest
   }
if ((cmpd_hdr == "FOR") || (cmpd_hdr == "WHILE") || (cmpd_hdr == "DO"))
   {
   loop_nest++
   if (loop_nest > cur_max_loop_nest)
      cur_max_loop_nest=loop_nest
   }
if ((cmpd_hdr == "IF") || (cmpd_hdr == "ELSE"))
   {
   ifelse_nest++
   if (ifelse_nest > cur_max_ifelse_nest)
      cur_max_ifelse_nest=ifelse_nest
   }
if ((cmpd_hdr == "IF") || (cmpd_hdr == "ELSE") || (cmpd_hdr == "SWITCH"))
   {
   select_nest++
   if (select_nest > cur_max_select_nest)
      cur_max_select_nest=select_nest
   }
if (cmpd_hdr == "SWITCH")
   {
   switch_nest++
   if (switch_nest > cur_max_switch_nest)
      cur_max_switch_nest=switch_nest
   switch_hdr[switch_nest]=case_stmt_cnt
   }
loop_hdr[block_nest]=cmpd_hdr
loop_pop[block_nest]=0
stack_return[block_nest]=return_cnt
return_cnt=0
stack_break[block_nest]=break_cnt
break_cnt=0
stack_continue[block_nest]=continue_cnt
continue_cnt=0

# print "block nest " block_nest
}

function pop_cmpd_hdr()
{
if (last_was_push == 1) {
   max_local_block_nest[block_nest]++ 
   max_local_cmpd_nest[cmpd_nest]++ 
   max_local_select_nest[select_nest]++
   max_local_loop_nest[loop_nest]++
   max_local_ifelse_nest[ifelse_nest]++
   }
last_was_push=0
if (block_nest > 0) {
   if ((loop_hdr[block_nest] == "FOR") || (loop_hdr[block_nest] == "WHILE") || (loop_hdr[block_nest] == "DO")) {
      break_per_loop[break_cnt]++
      continue_per_loop[continue_cnt]++
      exits_per_loop[break_cnt]++
      exits_per_loop[return_cnt]++
      return_cnt=stack_return[block_nest]
      break_cnt=stack_break[block_nest]
      continue_cnt=stack_continue[block_nest]
      loop_nest--
   } else if (loop_hdr[block_nest] == "SWITCH") {
      break_per_switch[break_cnt]++
      break_cnt=stack_break[block_nest]
      continue_cnt=continue_cnt+stack_continue[block_nest]
      select_nest--
      if (case_stmt_cnt != 0)
	 stmt_per_case[case_stmt_cnt]++
      case_stmt_cnt=switch_hdr[switch_nest]
      switch_nest--
   } else {
      break_cnt=break_cnt+stack_break[block_nest]
      continue_cnt=continue_cnt+stack_continue[block_nest]
      if ((loop_hdr[block_nest] == "IF") || (loop_hdr[block_nest] == "ELSE")) {
	 ifelse_nest--
         select_nest--
	 }
      if (loop_hdr[block_nest] == "{")
	 cmpd_nest--
      }
   block_nest--
   if (loop_pop[block_nest] == 1)
      pop_cmpd_hdr()
   }
}

function cmpd_header(num_semi)
{
if (((semi_expected == 1) && (last_cmpd == ";")) ||
    ((last_cmpd != ";") && (last_cmpd != "{") && ($1 != "{")))
   loop_pop[block_nest]=1
push_cmpd_hdr($1)
case_stmt_cnt++
semi_expected=num_semi
last_cmpd=$1
}

BEGIN {
	zero_counters()
	line_num=0
	total_break=0
	total_continue=0
	total_do=0
	total_switch=0
	total_for=0
	total_while=0
	semi_expected=0
	loop_pop[0]=0
	}

	{
	line_num++
	}

$1 == "IF" {
	cmpd_header(1)
	next
	}

$1 == "ELSE" {
	cmpd_header(1)
	next
	}

$1 == "SWITCH" {
	cmpd_header(1)
	total_switch++
	next
	}

$1 == "DO" {
	cmpd_header(1)
	total_do++
	next
	}

$1 == "FOR" {
	cmpd_header(3)
	total_for++
	next
	}

$1 == "WHILE" {
	cmpd_header(1)
	total_while++
	next
	}

$1 == ";" {
	if (semi_expected == 1) {
	   pop_cmpd_hdr()
	   }
	last_cmpd=$1
	semi_expected--
	if (semi_expected < 1)
	   case_stmt_cnt++
	next
	}

$1 == "{" {
	if (semi_expected != 1)
	   push_cmpd_hdr($1)
	last_cmpd=$1
	semi_expected=0
	next
	}

$1 == "}" {
	if (block_nest > 0) {
	   pop_cmpd_hdr()
	   }
	next
	}

$1 == "RETURN" {
	return_cnt++
	next
	}

$1 == "BREAK" {
	total_break++
	break_cnt++
	next
	}

$1 == "CONTINUE" {
	total_continue++
	continue_cnt++
	next
	}

$1 == "DEFAULT" {
	if (case_stmt_cnt != 0)
	   stmt_per_case[case_stmt_cnt]++
	case_stmt_cnt=0
	next
	}

$1 == "CASE" {
	if (loop_hdr[block_nest] != "SWITCH") {
	   #print_cmpd_stack()
	   case_nested++
	   }
	if (case_stmt_cnt != 0)
	   stmt_per_case[case_stmt_cnt]++
	case_stmt_cnt=0
	next
	}

$1 == "__E__O__F__" {
	if (block_nest != 0)
	   {
	   print "block nest " block_nest
	   print_cmpd_stack()
	   }
	end_file()
	next
	}

	{
	next
	}

END {
	end_file()
	break_check=0
	for (i in break_per_switch)
	   break_check=break_check+i*break_per_switch[i]
	print "breaks in switch " break_check
	break_check=0
	for (i in break_per_loop)
	   break_check=break_check+i*break_per_loop[i]
	print "breaks in loop " break_check
	continue_check=0
	for (i in continue_per_loop)
	   continue_check=continue_check+i*continue_per_loop[i]
	print "continues in loop " continue_check
	loop_check=0
	for (i in max_loop_nest)
	   loop_check=loop_check+i*max_loop_nest[i]
	print "number of loops " loop_check
	print "total do " total_do
	print "total for " total_for
	print "total while " total_while
	print "total switch " total_switch
	print "total break " total_break
	print "total continue " total_continue
	print "nested case " case_nested
	TEMP_FILE="bl" systime()
        printf("") > TEMP_FILE
	for (i in break_per_switch)
	   print i " " break_per_switch[i] >> TEMP_FILE
	print "File: break_p_switch.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
        printf("") > TEMP_FILE
	for (i in break_per_loop)
	   print i " " break_per_loop[i] >> TEMP_FILE
	print "File: break_p_loop.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
        printf("") > TEMP_FILE
	for (i in continue_per_loop)
	   print i " " continue_per_loop[i] >> TEMP_FILE
	print "File: contin_p_loop.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
        printf("") > TEMP_FILE
	for (i in max_loop_nest)
	   print i " " max_loop_nest[i] >> TEMP_FILE
	print "File: loop_nesting.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
        printf("") > TEMP_FILE
	for (i in max_select_nest)
	   print i " " max_select_nest[i] >> TEMP_FILE
	print "File: select_nesting.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
        printf("") > TEMP_FILE
	for (i in max_ifelse_nest)
	   print i " " max_ifelse_nest[i] >> TEMP_FILE
	print "File: ifelse_nesting.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
        printf("") > TEMP_FILE
	for (i in max_cmpd_nest)
	   print i " " max_cmpd_nest[i] >> TEMP_FILE
	print "File: cmpd_nesting.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
        printf("") > TEMP_FILE
	for (i in max_block_nest)
	   print i " " max_block_nest[i] >> TEMP_FILE
	print "File: block_nesting.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
        printf("") > TEMP_FILE
	for (i in exits_per_loop)
	   print i " " exits_per_loop[i] >> TEMP_FILE
	print "File: exits_per_loop.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
        printf("") > TEMP_FILE
	for (i in stmt_per_case)
	   print i " " stmt_per_case[i] >> TEMP_FILE
	print "File: stmt_per_case.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	system("rm " TEMP_FILE)
	}

