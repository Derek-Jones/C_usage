# gotos.awk,  3 Dec 03
#

function sum_func_info()
{
for (l in label_def_line)
   if (label_use_line[l] == "")
      no_goto_to++
for (l in label_use_line) {
   num_lines=split(label_use_line[l], lines)
   for (n=1; n <= num_lines; n++)
      goto_distance[label_def_line[l]-lines[n]]++
   }
for (l in label_use_scope) {
   num_scopes=split(label_use_scope[l], scopes)
   for (s=1; s <= num_scopes; s++)
      scope_difference[label_def_scope[l]-scopes[s]]++
   }
in_func=0
delete label_def_scope
delete label_def_line
delete label_use_scope
delete label_use_line
}

BEGIN {
	in_func=0
	scope_num=0
	goto_same_scope=0
	no_goto_to=0
	}

$1 == ".END" {
	func_end_line=$2
	if (in_func == 1)
	   sum_func_info()
	next
	}

$1 == ".LABEL" {
	if ($2 == "define") {
	   label_scope[cur_scope]++
	   num_labels++
	   label_def_scope[$3]=scope_val
	   label_def_line[$3]=$4
	} else {
	   goto_scope[cur_scope]++
	   num_gotos++
	   label_use_scope[$3]=label_use_scope[$3] " " scope_val
	   label_use_line[$3]=label_use_line[$3] " " $4
	   }
	next
	}

$1 == ".SCOPE" {
	if (in_func != 1)
	   next
	# The scope level in the met file is
	#    1 for file scope
	#    2 for start of function scope
	if ($2 == "start") {
	   stack_scope[cur_scope]=scope_val
	   scope_num++
	   cur_scope=$3-1
	   scope_val=cur_scope
	} else {
	   cur_scope=$3-2
	   scope_val=stack_scope[cur_scope]
	   }
	next
	}

$1 == ".FUNC" {
	in_func=1
	cur_scope=1
	scope_val=1
	func_start_line=$3
	next
	}

	{
	next
	}

END {
	print "num labels " num_labels
	print "num gotos " num_gotos
	print "num not goto'ed to " no_goto_to
	backward_jump=0
	forward_jump=0
	for (l in goto_distance)
	   if (l <= 0)
	      backward_jump+=goto_distance[l]
	   else
	      forward_jump+=goto_distance[l]
	print "backward jump " backward_jump
	print "forward jump " forward_jump

	TEMP_FILE="gt" systime()
	printf("") > TEMP_FILE
	for (l in goto_distance)
	   print l " " goto_distance[l] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: goto_distance.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	      
	printf("") > TEMP_FILE
	for (l in goto_scope)
	   print l " " goto_scope[l] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: goto_scope.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	      
	printf("") > TEMP_FILE
	for (l in label_scope)
	   print l " " label_scope[l] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: label_scope.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	      
	printf("") > TEMP_FILE
	for (l in scope_difference)
	   print l " " scope_difference[l] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: goto_scope_diff.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	      
	system("rm " TEMP_FILE)
	}

