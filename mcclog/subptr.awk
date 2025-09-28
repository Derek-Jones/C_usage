# subptr.awk, 30 Aug 03
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

($1 == "-") {
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
      if (op_is_ptr == 2)
         {
         op_sim_type[types[2] " # " $1 " # " types[3]]=op_sim_type[types[2] " # " $1 " # " types[3]] + $NF
         num_op[$1]=num_op[$1]+$NF
	 }
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
	   split(i, op_fields, "#")
	   gsub(" ", "", op_fields[2])
	   percent=100*(op_sim_type[i]/num_op[op_fields[2]])
	   gsub("\#", ",,", i)
	   if (percent < 1.0)
	      others[op_fields[2]]=others[op_fields[2]]+percent
	   else
	      printf("%s ,, %2.1f\n", i, percent)
	   }
	if (others["-"] >= 1.0)
	   printf("other-types ,, &emdash; ,, other-types ,, %2.1f\n", others["."])
	}

