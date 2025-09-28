# postfixop.awk, 26 Dec 03
#
# needs type_ops.awk

BEGIN {
	in_simp=0
	in_unsimp=0
	in_ops=0
	}

$0 == "File: op_type" {
	in_unsimp=1
	next
	}

$0 == "File: op_sim_type" {
	in_simp=1
	next
	}

$0 == "File: counts" {
	in_ops=1
	next
	}

$0 == "End File" {
        in_simp=0
        in_unsimp=0
        in_ops=0
        next
        }

index(" v++ v-- [ ", " " $1 " ") != 0 {
# no point in counting . and ->
	if (in_simp == 1) {
	   #print $0
	   split($0, op_info, "#")
	   get_base_type(op_info[2])
           op_info[2]=simp_type
	   gsub(" ", "", op_info[1])
	   percent=100*(op_info[4]/total_op[op_info[1]])
	   # the array information also includes the index type
	   if ($1 == "[")
	      array_elem[op_info[2]]+=percent
	   else
	      {
	      if (percent < 1.0)
	         others[op_info[1]]+=percent
	      else
	         printf(" %s ,, %s ,, %2.1f\n", op_info[1], op_info[2], percent)
	      }
	} else if (in_ops == 1) {
	   total_op[$1]=$2
	   }
	next
	}

        {
	next
	}

END {
	for (i in array_elem)
	   if (array_elem[i] < 1.0)
	      others["["]+=array_elem[i]
	   else
	      printf(" [ ,, %s ,, %2.1f\n", i, array_elem[i])
	for (i in others)
	   if (others[i] >= 1.0)
	      printf(" %s ,, other-types ,, %2.1f\n", i, others[i])
	}

