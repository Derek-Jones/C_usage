# unaryop.awk, 29 Aug 03
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

$1 == "&v" {
	if (in_unsimp == 1) {
	   #print $0
	   split($0, op_info, "#")
	   get_base_type(op_info[2])
	   op_info[2]=simp_type
	   gsub(" ", "", op_info[1])
	   percent=100*(op_info[4]/total_op[op_info[1]])
	   if (percent < 1.0)
	      others[op_info[1]]=others[op_info[1]]+percent
	   else
	      op_sim_type[op_info[1] " ,, " op_info[2]] = op_sim_type[op_info[1] " ,, " op_info[2]] + percent
	} else if (in_ops == 1) {
	   total_op[$1]=$2
	   }
	next
	}

index(" ++v --v *v +v -v ~ ! ", " " $1 " ") != 0 {
	if (in_simp == 1) {
	   #print $0
	   split($0, op_info, "#")
	   gsub(" ", "", op_info[1])
	   percent=100*(op_info[4]/total_op[op_info[1]])
	   if (percent < 1.0)
	      others[op_info[1]]=others[op_info[1]]+percent
	   else
	      #printf("%2.1f ,, %s ,, %s ,, %s\n", percent)
	      printf("%s ,, %s ,, %2.1f\n", op_info[1], op_info[2], percent)
	} else if (in_ops == 1) {
	   total_op[$1]=$2
	   }
	next
	}

        {
	next
	}

END {
    for (i in op_sim_type)
       printf("%s ,, %2.1f\n", i, op_sim_type[i])
    for (i in others)
       if (others[i] >= 1.0)
          printf("%s ,, other-types ,, %2.1f\n", i, others[i])
       #printf("%2.1f ,, other-types ,, %s ,, other-types\n", others[i], i)
    }

