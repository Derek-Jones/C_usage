# breaknest.awk, 26 Aug 03
#

function print_cmpd_stack()
{
print line_num
for (c=cmpd_nest; c > 0; c--)
   print c " : " loop_hdr[c]
}

function start_file()
{
cmpd_nest=0
max_loop_nesting=0
loop_nest_depth=0
max_select_nesting=0
select_nest_depth=0
ifelse_nest_depth=0
max_ifelse_nesting=0
max_cmpd_nesting=0
break_cnt=0
continue_cnt=0
}

function push_cmpd_hdr(cmpd_hdr)
{
cmpd_nest++
if (max_cmpd_nesting < cmpd_nest)
   max_cmpd_nesting=cmpd_nest
if ((cmpd_hdr == "FOR") || (cmpd_hdr == "WHILE") || (cmpd_hdr == "DO"))
   loop_nest_depth++
if (max_loop_nesting < loop_nest_depth)
   max_loop_nesting=loop_nest_depth
if ((cmpd_hdr == "IF") || (cmpd_hdr == "ELSE"))
   ifelse_nest_depth++
if (max_ifelse_nesting < ifelse_nest_depth)
   max_ifelse_nesting=ifelse_nest_depth
if ((cmpd_hdr == "IF") || (cmpd_hdr == "ELSE") || (cmpd_hdr == "SWITCH"))
   select_nest_depth++
if (max_select_nesting < select_nest_depth)
   max_select_nesting=select_nest_depth
loop_hdr[cmpd_nest]=cmpd_hdr
loop_pop[cmpd_nest]=0
stack_break[cmpd_nest]=break_cnt
break_cnt=0
stack_continue[cmpd_nest]=continue_cnt
continue_cnt=0

# print "cmpd nest " cmpd_nest
}

function pop_cmpd_hdr()
{
if (cmpd_nest > 0) {
   if ((loop_hdr[cmpd_nest] == "FOR") || (loop_hdr[cmpd_nest] == "WHILE") || (loop_hdr[cmpd_nest] == "DO")) {
      break_per_loop[break_cnt]++
      continue_per_loop[continue_cnt]++
      break_cnt=stack_break[cmpd_nest]
      continue_cnt=stack_continue[cmpd_nest]
      loop_nest_depth--
      if (loop_nest_depth == 0) {
         loop_nesting[max_loop_nesting]++
         max_loop_nesting=0
         }
   } else if (loop_hdr[cmpd_nest] == "SWITCH") {
      break_per_switch[break_cnt]++
      break_cnt=stack_break[cmpd_nest]
      continue_cnt=continue_cnt+stack_continue[cmpd_nest]
      select_nest_depth--
      if (select_nest_depth == 0) {
         select_nesting[max_select_nesting]++
         max_select_nesting=0
         }
   } else {
      break_cnt=break_cnt+stack_break[cmpd_nest]
      continue_cnt=continue_cnt+stack_continue[cmpd_nest]
      if ((loop_hdr[cmpd_nest] == "IF") || (loop_hdr[cmpd_nest] == "ELSE")) {
	 ifelse_nest_depth--
         select_nest_depth--
         if (select_nest_depth == 0) {
            select_nesting[max_select_nesting]++
            max_select_nesting=0
            }
	 }
      }
   cmpd_nest--
   if (loop_pop[cmpd_nest] == 1)
      pop_cmpd_hdr()
   }
}

function cmpd_header(num_semi)
{
if (((semi_expected == 1) && (last_cmpd == ";")) ||
    ((last_cmpd != ";") && (last_cmpd != "{") && ($1 != "{")))
   loop_pop[cmpd_nest]=1
push_cmpd_hdr($1)
semi_expected=num_semi
last_cmpd=$1
}

BEGIN {
	start_file()
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
	if (cmpd_nest > 0) {
	   pop_cmpd_hdr()
	   }
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

$1 == "CASE" {
	if (loop_hdr[cmpd_nest] != "SWITCH") {
	   #print_cmpd_stack()
	   case_nested++
	   }
	next
	}

$1 == "__E__O__F__" {
	if (cmpd_nest != 0)
	   {
	   print "cmpd nest " cmpd_nest
	   print_cmpd_stack()
	   }
	start_file()
	next
	}

	{
	next
	}

END {
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
	for (i in loop_nesting)
	   loop_check=loop_check+i*loop_nesting[i]
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
	for (i in loop_nesting)
	   print i " " loop_nesting[i] >> TEMP_FILE
	print "File: loop_nesting.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
        printf("") > TEMP_FILE
	for (i in select_nesting)
	   print i " " select_nesting[i] >> TEMP_FILE
	print "File: select_nesting.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	system("rm " TEMP_FILE)
	}

