# summary.awk, 29 Sep 02

function print_ind_elem(str, array_vals)
{
total_vals=0
total_entries=0
print ""
print str
for (c in array_vals) {
   print c " " array_vals[c]
   total_vals+=array_vals[c]
   total_entries++
   }
print "Total " str "=" total_vals ", total entries=" total_entries
}

function sum_file_info()
{
# How many times a definition called internally/externally
for (c in func_defs) {
   int_def_calls[c]+=calls[c]
#
# referencing ext_def_calls will create it, with value zero,
# if it does not already exist.
   dummy=ext_def_calls[c]
   }
# Add up calls to functions defined in same/different file
for (c in calls) {
   ext_def_calls[c]+=calls[c]
   if (func_defs[c] == 1) {
      int_calls[c]+=calls[c]
   } else {
      ext_calls[c]+=calls[c]
      }
   }
delete calls
delete func_defs
}

function sum_func_info()
{
#
func_args[cur_func_args]++
func_arg_size[cur_func_arg_size]++
func_locals[cur_func_locals]++
func_local_size[cur_func_local_size]++

local_acc[$3]++
local_mod[$3]++

delete local_acc
delete local_mod
}


$1 ~ /.ACC/ {
	if ($2 == "NONE") {
	   total_local_acc++
	   local_acc[$3]++
	} else {
	   total_global_acc++
	   }
	next
	}

$1 ~ /.MOD/ {
	if ($2 == "NONE") {
	   total_local_mod++
	   local_mod[$3]++
	} else {
	   total_global_mod++
	   }
	next
	}

$1 ~ /.ARG/ {
	cur_func_args++
	arg_name[cur_func_args]=$2
	arg_used[cur_func_args]=$6
	arg_set[cur_func_args]=$8
	cur_func_arg_size+=$10
	next
	}

$1 ~ /.LOCAL/ {
	if ($11 == "IDENT") {
	   cur_func_locals++
	   local_name[cur_func_args]=$2
	   local_scope[cur_func_args]=$4
	   local_used[cur_func_args]=$6
	   local_setd[cur_func_args]=$8
	   cur_func_local_size+=$10
	   }
	next
	}

$1 ~ /.CALL/ {
	calls[$2]++
	next
	}

$1 ~ /.FILE/ {
	file_number++
	files[$2]=file_number
	next
	}

$1 ~ /.FUNC/ {
	in_func=1
	func_number++
	func_defs[$2]=1
	cur_func_args=0
	cur_func_arg_size=0
	cur_func_locals=0
	cur_func_local_size=0
	next
	}

$1 ~ /.GLOBAL/ {
	cur_globals++
	cur_global_size+=$10
	next
	}

$1 ~ /.INCLUDE/ {
	next
	}

$1 ~ /.START/ {
	start_nesting++;
	start_name[start_nesting]=$2
	next
	}

$1 ~ /.END/ {
	if (NF == 1) {
	   if (in_func == 1) {
	      sum_func_info()
	      }
        } else {
	   if (start_name[start_nesting] == $2) {
	      if (start_nesting == 0) {
		 print "<<<<<< negative .START/.END nesting: " $2
	         }
	      start_nesting--
	      if (start_nesting == 0) {
		 sum_file_info()
	         }
	      }
	   }
	next
	}

$1 ~ /.FILE/ {
	if (start_nesting == 0) {
	   print "<<<<<< positive .START/.END nesting: " $2 ", level: " start_nesting
	   }
	start_nesting=0
	next
	}

END {
	print "Total files=" file_number
	print "Total function definitions=" func_number

	print "Total locals accessed " total_local_acc
	print "Total globals accessed " total_global_acc
	print "Total locals modified " total_local_mod
	print "Total globals modified " total_global_mod

	print_ind_elem("#Internal calls", int_calls)
	print_ind_elem("#External calls", ext_calls)
	print_ind_elem("#Internal definition calls", int_def_calls)
	print_ind_elem("#External definition calls", ext_def_calls)
	
	print_ind_elem("#function number arguments", func_args)
	print_ind_elem("#function total size arguments", func_arg_size)
	print_ind_elem("#function number locals", func_locals)
	print_ind_elem("#function total size locals", func_local_size)
}

