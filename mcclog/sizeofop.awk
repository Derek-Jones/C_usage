# sizeofop.awk, 29 Aug 03
#
# needs type_ops.awk

BEGIN {
   in_data=0
   }

# the unsimplified type
$0 == "File: op_type" {
	in_data=1
	next
	}

$0 == "End File" {
        in_data=0
        next
        }

($1 == "sizeof") {
      {
      if (in_data == 0)
         next
      split($0, types, "#")
      get_base_type(types[2])
      sub("array-index", "[ ]", simp_type)
      types[2]=simp_type
      op_sim_type[types[2]] = op_sim_type[types[2]] + $NF
      num_op[$1]=num_op[$1]+$NF
      }
   next
   }

   {
   next
   }

END {
	#for (i in num_op)
	#   print i " # " num_op[i]
	for (i in op_sim_type) {
	   percent=100*(op_sim_type[i]/num_op["sizeof"])
	   gsub("\#", ",,", i)
	   if (percent < 1.0)
	      others["sizeof"]=others["sizeof"]+percent
	   else
	      printf(" %s ,, %2.1f\n", i, percent)
	   }
	if (others["sizeof"] >= 1.0)
	   printf(" other-types ,, %2.1f\n", others["sizeof"])
	}

