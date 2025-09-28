# eqptr.awk, 29 Aug 03
#
# needs type_ops.awk

BEGIN {
   in_data=0
   }

# the unsimplified type
$0 == "File: imp_to_from" {
	in_data=1
	next
	}

$0 == "End File" {
        in_data=0
        next
        }

   {
      {
      if (in_data == 0)
         next
      split($0, types, "#")
      op_is_ptr=0
      get_base_type(types[1])
      types[1]=simp_type
      get_base_type(types[2])
      types[2]=simp_type
      #print op_is_ptr " " $0
      if (op_is_ptr == 1)
         {
         imp_conv["( " types[1] " ) ,, " types[2]]=imp_conv["( " types[1] " ) ,, " types[2]] + $NF
         num_ptr=num_ptr+$NF
	 }
      }
   next
   }

   {
   next
   }

END {
	for (i in imp_conv) {
	   split(i, op_fields, "#")
	   percent=100*(imp_conv[i]/num_ptr)
	   if (percent < 1.0)
	      others=others+percent
	   else
	      printf(" %s ,, %2.1f\n", i, percent)
	   }
	if (others >= 1.0)
	   printf(" ( other-types * ) ,, other-types * ,, %2.1f\n", others)
	}

