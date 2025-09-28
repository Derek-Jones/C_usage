# keyopocc.awk, 11 Jul 03
#
# operator related keywords


BEGIN {
	}

$2 == "tokcnt.d" {
	in_data_freq=1
	next
	}

$1 == "End" {
	if (in_data_freq == 1) {
	   print num_for " " num_while " " num_if " " num_op
	   exit
	}
	next
	}

        {
	if (in_data_freq == 1) {
	   if ($1 == "FOR")
	      num_for=$3
	   if ($1 == "WHILE")
	      num_while=$3
	   if ($1 == "IF")
	      num_if=$3
	   if ($1 == OP)
	      num_op=$4
	}
	next
	}

END {
    }

