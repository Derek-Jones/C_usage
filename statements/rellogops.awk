# rellogops.awk, 18 Jul 09
#
# relational, equality and logical operators in controlling expression

BEGIN {
	split(OP_CNT, total_op, " ")
	}

$0 ~ /^abstract count/ {
	total_if=$3
	next
	}

$0 ~ /^not abstracted/ {
	printf(" == ,, %2.1f ,, %2.1f\n", 100*(num_if_eq/total_if), 100*(num_eq/total_op[1]))
	printf(" != ,, %2.1f ,, %2.1f\n", 100*(num_if_ne/total_if), 100*(num_ne/total_op[2]))
	printf(" < ,, %2.1f ,, %2.1f\n", 100*(num_if_lt/total_if), 100*(num_lt/total_op[3]))
	printf(" <= ,, %2.1f ,, %2.1f\n", 100*(num_if_le/total_if), 100*(num_le/total_op[4]))
	printf(" > ,, %2.1f ,, %2.1f\n", 100*(num_if_ge/total_if), 100*(num_gt/total_op[5]))
	printf(" >= ,, %2.1f ,, %2.1f\n", 100*(num_if_ge/total_if), 100*(num_ge/total_op[6]))
	printf("no relational/equality ,, %2.1f ,, &emdash;\n", 100*(num_no_ops/total_if))
	printf(" || ,, %2.1f ,, %2.1f\n", 100*(num_if_or/total_if), 100*(num_or/total_op[7]))
	printf(" && ,, %2.1f ,, %2.1f\n", 100*(num_if_and/total_if), 100*(num_and/total_op[8]))
	printf("no logical operators ,, %2.1f ,, &emdash;\n", 100*(num_no_log_ops/total_if))
	exit
	next
	}

$2 == KEY_TOK {
	   seen_op=0
	   num_ops=gsub("==", "", $0)
	   if (num_ops != 0) {
	      num_eq+=$1*num_ops
	      num_if_eq+=$1
	      seen_op=1
	   }
	   num_ops=gsub(" !=", "", $0)
	   if (num_ops != 0) {
	      num_ne+=$1*num_ops
	      num_if_ne+=$1
	      seen_op=1
	   }
	   num_ops=gsub(" <=", "", $0)
	   if (num_ops != 0) {
	      num_le+=$1*num_ops
	      num_if_le+=$1
	      seen_op=1
	   }
	   num_ops=gsub(" < ", "", $0)
	   if (num_ops != 0) {
	      num_lt+=$1*num_ops
	      num_if_lt+=$1
	      seen_op=1
	   }
	   num_ops=gsub(" >=", "", $0)
	   if (num_ops != 0) {
	      num_ge+=$1*num_ops
	      num_if_ge+=$1
	      seen_op=1
	   }
	   num_ops=gsub(" > ", "", $0)
	   if (num_ops != 0) {
	      num_gt+=$1*num_ops
	      num_if_gt+=$1
	      seen_op=1
	   }
	   if (seen_op == 0)
	      num_no_ops+=$1
	   seen_op=0
	   num_ops=gsub(/\|\|/, "", $0)
	   if (num_ops != 0) {
	      num_or+=$1*num_ops
	      num_if_or+=$1
	      seen_op=1
	   }
	   num_ops=gsub("&&", "", $0)
	   if (num_ops != 0) {
	      num_and+=$1*num_ops
	      num_if_and+=$1
	      seen_op=1
	   }
	   if (seen_op == 0)
	      num_no_log_ops+=$1
	next
	}

END {
    }

