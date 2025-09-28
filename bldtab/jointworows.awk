# jointworows.awk, 13 Aug 03
#
# Join two lots of rows of data

BEGIN {
	in_end_bit=0
	}

$1 == "END_BIT" {
	in_end_bit=1
	next
	}

        {
	if (in_end_bit == 0) {
	   num_val[$1]=$NF
	} else {
	   print $0 " ,, " num_val[$1]
	   }
	next
	}

END {
    }

