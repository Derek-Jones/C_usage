# castop.awk, 29 Aug 03
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

($1 == "cast") {
      {
      if (in_data == 0)
         next
      split($0, types, "#")
      op_is_ptr=0
      get_base_type(types[2])
      types[2]=simp_type
      get_base_type(types[3])
      types[3]=simp_type
      #print op_is_ptr " " $0
      op_sim_type["( " types[2] " ) # "  types[3]] = op_sim_type["( " types[2] " ) # "  types[3]] + $NF
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
	   percent=100*(op_sim_type[i]/num_op["cast"])
	   gsub("\#", ",,", i)
	   if (percent < 1.0)
	      others["cast"]=others["cast"]+percent
	   else
	      printf("%s ,, %2.1f\n", i, percent)
	   }
	printf("( other-types ) ,, other-types ,, %2.1f\n", others["cast"])
	}

