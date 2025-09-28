# exprops.awk,  3 Jan 05
#

BEGIN {
	in_ops=0
	in_data=0
	}

# the simplified type
$0 == "File: op_sim_type" {
        in_data=1
        if (OP_FREQ == "")
           op_freq=1.0
        else
           op_freq=OP_FREQ
        next
        }

$0 == "File: counts" {
        in_ops=1
        next
        }

$0 == "End File" {
	in_ops=0
	in_data=0
	next
	}

index(OP_TOK, " " $1 " ") != 0 {
	if (in_data == 1) {
	   #print $0
	   split($0, op_info, "#")
	   gsub(" ", "", op_info[1])
	   percent=100*(op_info[4]/total_op[op_info[1]])
	   if (percent < op_freq)
	      others[op_info[1]]=others[op_info[1]]+percent
	   else
	      #printf("%2.1f ,, %s ,, %s ,, %s\n", percent, op_info[2], op_info[1], op_info[3])
	      printf("%s ,, %s ,, %s ,, %2.1f\n", op_info[2], op_info[1], op_info[3], percent)
	} else if (in_ops == 1)
	   total_op[$1]=$2
	next
	}

        {
	next
	}

END {
    for (i in others)
       if (others[i] >= op_freq)
          printf("other-types ,, %s ,, other-types ,, %2.1f\n", i, others[i])
       #printf("%2.1f ,, other-types ,, %s ,, other-types\n", others[i], i)
    }

