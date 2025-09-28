# blocknest.awk, 15 Mar 08
#
# Count the nesting of various kinds of block structured constructs
#

function print_cmpd_stack()
{
print line_num
for (c=cmpd_hdr_nest; c > 0; c--)
   print c " : " loop_hdr[c]
}

function zero_counters()
{
block_nest=0
cmpd_nest=0
cmpd_hdr_nest=0
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
cur_max_cmpd_hdr_nest=0
cur_max_cmpd_nest=0
cur_max_select_nest=0
cur_max_loop_nest=0
cur_max_ifelse_nest=0
seen_func_def=0
last_was_cmpd_hdr=0
}

function end_func()
#
# Count the deepest nesting encountered for various
# constructs.
{
if (!seen_func_def)
   return
if (cmpd_hdr_nest != 0)
   {
   print "cmpd_hdr_nest " cmpd_hdr_nest
   print_cmpd_stack()
   }
total_funcs++
max_block_nest[cur_max_block_nest]++
max_cmpd_nest[cur_max_cmpd_nest]++
max_select_nest[cur_max_select_nest]++
max_loop_nest[cur_max_loop_nest]++
max_ifelse_nest[cur_max_ifelse_nest]++

   {
# The following is needed because a parse error can result in
# a nesting level containing no statements.
   for (n=0; n <= cur_max_cmpd_hdr_nest; n++)
   if (nest_stmt_total[n] == "")
      nest_stmt_total[n]=1

# Set to zero those cases where a kind of statement could have
# occurred, but did not.
   for (ks in kind_stmt)
      for (n=0; n <= cur_max_cmpd_hdr_nest; n++)
         if (nest_stmt_freq[ks " " n] == "")
            nest_stmt_freq[ks " " n]=0

   print "start stmt-nest"
   for (i in nest_stmt_freq)
      {
      split(i, hdr_nest)
      if (hdr_nest[1] == "IX")
	 {
	 continue
	 }
#print i " " nest_stmt_total[hdr_nest[2]]
#      print i " " nest_stmt_freq[i]
      printf("%s  %4d  %4d   %5.2f\n", hdr_nest[1], hdr_nest[2], nest_stmt_freq[i], nest_stmt_freq[i]*100/nest_stmt_total[hdr_nest[2]])
      }
   for (n=0; n <= cur_max_cmpd_hdr_nest; n++)
      if (nest_stmt_freq["IX " n] != "")
	 {
	 all_ifs=nest_stmt_freq["IF " n] +nest_stmt_freq["IE " n]
         printf("%s  %4d  %4d   %2.4f\n", "IX", n, nest_stmt_freq["IX " n], nest_stmt_freq["IX " n]/all_ifs)
	 }
   print "end stmt-nest"
   delete nest_stmt_freq
   delete nest_stmt_total
   }
if (0)
   {
   print "start if-nest"
   for (i in if_stmt_freq)
      {
      split(i, hdr_nest)
#      print i " " if_stmt_freq[i]
      printf("%s  %4d  %4d   %5.2f\n", hdr_nest[1], hdr_nest[2], if_stmt_freq[i], if_stmt_freq[i]*100/nest_if_stmt[hdr_nest[2]])
      }
   print "end if-nest"
   delete if_stmt_freq
   delete nest_if_stmt
   }
zero_counters()
}

function push_cmpd_hdr(cmpd_hdr)
{
#
# If last token was a compound header then we need to continue popping
# the stack of nested compound headers.
#
#print "last was cmpd hdr " last_was_cmpd_hdr
if (last_was_cmpd_hdr)
   loop_pop[cmpd_hdr_nest]=1

cmpd_hdr_nest++
if (cmpd_hdr_nest > cur_max_cmpd_hdr_nest)
   cur_max_cmpd_hdr_nest=cmpd_hdr_nest
last_was_push=1
if ((cmpd_hdr == "FO") || (cmpd_hdr == "WH") || (cmpd_hdr == "DO"))
   {
   loop_nest++
   if (loop_nest > cur_max_loop_nest)
      cur_max_loop_nest=loop_nest
   stack_return[cmpd_hdr_nest]=return_cnt
   return_cnt=0
   stack_break[cmpd_hdr_nest]=break_cnt
   break_cnt=0
   stack_continue[cmpd_hdr_nest]=continue_cnt
   continue_cnt=0
   }
else if ((cmpd_hdr == "IF") || (cmpd_hdr == "IE") || \
         (cmpd_hdr == "EL") || (cmpd_hdr == "SW"))
   {
   select_nest++
   if (select_nest > cur_max_select_nest)
      cur_max_select_nest=select_nest
   if ((cmpd_hdr == "IF") || (cmpd_hdr == "IE") || (cmpd_hdr == "EL"))
      {
      ifelse_nest++
      if (ifelse_nest > cur_max_ifelse_nest)
         cur_max_ifelse_nest=ifelse_nest
      }
   else if (cmpd_hdr == "SW")
      {
      switch_nest++
      if (switch_nest > cur_max_switch_nest)
         cur_max_switch_nest=switch_nest
      switch_hdr[switch_nest]=case_stmt_cnt
      case_stmt_cnt=0
      stack_break[cmpd_hdr_nest]=break_cnt
      break_cnt=0
      }
   }
loop_hdr[cmpd_hdr_nest]=cmpd_hdr
loop_pop[cmpd_hdr_nest]=0

#print "push: cmpd_hdr nest " cmpd_hdr_nest
#print "cur continue_cnt " continue_cnt " prev " stack_continue[cmpd_hdr_nest]
}

function pop_cmpd_hdr()
{
#print "pop: cmpd_hdr_nest " cmpd_hdr_nest " " loop_hdr[cmpd_hdr_nest]
#print "cur continue_cnt " continue_cnt " next " stack_continue[cmpd_hdr_nest]

last_was_cmpd_hdr=0
block_nest--

#
# Don't strip back the stack past this entry.  This will happen
# when the matching ELSE is processed.
if (loop_hdr[cmpd_hdr_nest] == "IE")
   {
   ifelse_nest--
   select_nest--
   cmpd_hdr_nest--
   return
   }
if (last_was_push == 1) {
   max_local_block_nest[block_nest]++ 
   max_local_cmpd_nest[cmpd_nest]++ 
   max_local_select_nest[select_nest]++
   max_local_loop_nest[loop_nest]++
   max_local_ifelse_nest[ifelse_nest]++
   }
last_was_push=0
if (cmpd_hdr_nest > 0) {
   if ((loop_hdr[cmpd_hdr_nest] == "FO") || (loop_hdr[cmpd_hdr_nest] == "WH") || (loop_hdr[cmpd_hdr_nest] == "DO")) {
      break_per_loop[break_cnt]++
      continue_per_loop[continue_cnt]++
      exits_per_loop[break_cnt+return_cnt]++
      return_cnt=stack_return[cmpd_hdr_nest]
      break_cnt=stack_break[cmpd_hdr_nest]
      continue_cnt=stack_continue[cmpd_hdr_nest]
      loop_nest--
   } else if (loop_hdr[cmpd_hdr_nest] == "SW") {
      break_per_switch[break_cnt]++
      break_cnt=stack_break[cmpd_hdr_nest]
      select_nest--
      if (case_stmt_cnt != 0)
	 stmt_per_case[case_stmt_cnt]++
      case_stmt_cnt=switch_hdr[switch_nest]
      switch_nest--
   } else if ((loop_hdr[cmpd_hdr_nest] == "IF") || \
	      (loop_hdr[cmpd_hdr_nest] == "IE") || \
	      (loop_hdr[cmpd_hdr_nest] == "EL")) {
	 ifelse_nest--
         select_nest--
	 }
   cmpd_hdr_nest--
   if (loop_pop[cmpd_hdr_nest] == 1)
      pop_cmpd_hdr()
   }
else
   print "cmpd_hdr_nest zero on pop"
}

function cmpd_header()
{
case_stmt_cnt++
push_cmpd_hdr($1)
last_was_cmpd_hdr=1
block_nest++
if (block_nest > cur_max_block_nest)
   cur_max_block_nest=block_nest
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
	total_files=0
	total_funcs=0
	loop_pop[0]=0
        kind_stmt["{_"]=1
        kind_stmt["}_"]=1
        kind_stmt["BR"]=1
        kind_stmt["CA"]=1
        kind_stmt["CO"]=1
        kind_stmt["DE"]=1
        kind_stmt["DO"]=1
        kind_stmt["EL"]=1
	kind_stmt["ES"]=1
        kind_stmt["FO"]=1
        kind_stmt["GO"]=1
        kind_stmt["IF"]=1
        kind_stmt["RE"]=1
        kind_stmt["SW"]=1
        kind_stmt["WH"]=1
	}

	{
	line_num++
	}

$1 == "FD" {
	end_func()
	seen_func_def=1
	next
	}

$1 == "__E__O__F__" {
	end_func()
	total_files++
	next
	}

seen_func_def == 1 {
	if (block_nest == 0)
	   {
	   if_stmt_freq[$1 " " 0]++
	   nest_if_stmt[0]++
	   }
	if ($1 == "IX")
	   {
	   nest_stmt_freq["IX " select_nest+loop_nest-1]+= $2+$3+1
	   }
	else
	   {
	   nest_stmt_freq[$1 " " select_nest+loop_nest]++
	   nest_stmt_total[select_nest+loop_nest]++
	   }
	if ((loop_hdr[cmpd_hdr_nest] == "IF") || \
	    (loop_hdr[cmpd_hdr_nest] == "IE") || \
	    (loop_hdr[cmpd_hdr_nest] == "EL"))
	   {
	   if_stmt_freq[$1 " " ifelse_nest]++
	   nest_if_stmt[ifelse_nest]++
	   }
	if (loop_hdr[cmpd_hdr_nest] == "FO")
	   for_stmt_freq[$1 " " loop_nest]++
	if (loop_hdr[cmpd_hdr_nest] == "WH")
	   while_stmt_freq[$1 " " loop_nest]++
	if (loop_hdr[cmpd_hdr_nest] == "DO")
	   do_stmt_freq[$1 " " loop_nest]++
	}

$1 == "IF" {
	cmpd_header()
	total_if++
	next
	}

$1 == "IE" {
	cmpd_header()
	total_if++
	next
	}

$1 == "EL" {
	cmpd_header()
	total_else++
	next
	}

$1 == "SW" {
	cmpd_header()
	total_switch++
	next
	}

$1 == "DO" {
	cmpd_header()
	total_do++
	next
	}

$1 == "FO" {
	cmpd_header()
	total_for++
	next
	}

$1 == "WH" {
	cmpd_header()
	total_while++
	next
	}

$1 == "{_" {
	block_nest++
	if (block_nest > cur_max_block_nest)
   	   cur_max_block_nest=block_nest
   	cmpd_nest++
   	if (cmpd_nest > cur_max_cmpd_nest)
      	   cur_max_cmpd_nest=cmpd_nest
	total_cmpd++
	last_was_cmpd_hdr=0
	next
	}

$1 == "DE" {
	if (case_stmt_cnt != 0)
	   stmt_per_case[case_stmt_cnt]++
	case_stmt_cnt=0
	next
	}

$1 == "CA" {
	if (loop_hdr[cmpd_hdr_nest] != "SWITCH") {
	   case_nested++
	   }
	if (case_stmt_cnt != 0)
	   stmt_per_case[case_stmt_cnt]++
	case_stmt_cnt=0
	next
	}

$1 == "}_" {
	block_nest--
   	cmpd_nest--
	if (cmpd_hdr_nest > 0)
	   pop_cmpd_hdr()
	next
	}

# Compound headers MUST appear before this point
	{
	if ($1 == "RE")
	   return_cnt++
	else if ($1 == "BR")
	   {
	   total_break++
	   break_cnt++
	   }
	else if ($1 == "CO")
	   {
	   total_continue++
	   continue_cnt++
	   }
	# else ES
	if (last_was_cmpd_hdr)
	   pop_cmpd_hdr()
	case_stmt_cnt++
	}

	{
	next
	}

END {
	end_func()
	print "total files " total_files
	print "total functions " total_funcs
	print "total { " total_cmpd
	print "total if " total_if
	print "total else " total_else
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
	print "File: loop_max_nesting.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
        printf("") > TEMP_FILE
	for (i in max_select_nest)
	   print i " " max_select_nest[i] >> TEMP_FILE
	print "File: select_max_nesting.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
        printf("") > TEMP_FILE
	for (i in max_ifelse_nest)
	   print i " " max_ifelse_nest[i] >> TEMP_FILE
	print "File: ifelse_max_nesting.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
        printf("") > TEMP_FILE
	for (i in max_cmpd_nest)
	   print i " " max_cmpd_nest[i] >> TEMP_FILE
	print "File: cmpd_max_nesting.d"
        close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	print "End File"
        printf("") > TEMP_FILE
	for (i in max_block_nest)
	   print i " " max_block_nest[i] >> TEMP_FILE
	print "File: block_max_nesting.d"
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

