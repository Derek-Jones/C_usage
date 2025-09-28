# callchain.awk,  2 Aug 02

BEGIN {
	
	}

$1 == ".FILE" {
	cur_file=$2
	# Just in case something went wrong, ignore existing information
	if (num_funcs != 0) {
	   num_funcs=0
	   func_calls["q"]=1
	   delete func_calls
	   }
	next
	}

$1 == ".END" {
	if ($2 == cur_file) {
	   #print num_funcs " " $0
	   # All lists have at least one space character at each end
	   for (c in func_calls)
	      func_calls[c]=func_calls[c] " "
	   # Fixed points?  Wots wrong with exhaustive iteration?
	   for (f=1; f <= num_funcs; f++)
	      for (c in func_calls) {
	         num_calls=split(func_calls[c], call_name, " ")
	         #print c " " func_calls[c] " " num_calls
	         for (i=1; i <= num_calls; i++)
	            if (index(func_calls[c], " " c " ") == 0) {
		       num_nest_calls=split(func_calls[call_name[i]], nested_calls, " ")
	               for (j=1; j <= num_nest_calls; j++)
		          if (index(func_calls[c], " " nested_calls[j] " ") == 0)
	                     func_calls[c]=func_calls[c] nested_calls[j]
		       }
	         }
	   for (c in func_calls)
	      if (index(func_calls[c], " " c " ") != 0)
	         num_indirect_recur++
	   delete func_calls
	   num_funcs=0
	   #print "Self recursion " num_self_recur
	   #print "Indirect recursion " num_indirect_recur
	   num_self_recur=0
	   num_indirect_recur=0
	   }
	next
	}

$1 == ".FUNC" {
	cur_func=$2
	num_funcs++
	next
	}

$1 == ".CALL" {
	if ($2 == cur_func) {
	   num_self_recur++
	} else {
	   if (call_seen[$2] != 1) {
	      call_seen[$2]=1
	      func_calls[cur_func]=func_calls[cur_func] " " $2
	      }
	   }
	next
	}

	{
	next
	}

END {
	print "Self recursion " num_self_recur
	print "Indirect recursion " num_indirect_recur
	}

