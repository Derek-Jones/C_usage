# joinfourrows.awk, 10 Nov 03
#
# Join four lots of rows of data

BEGIN {
	in_end_row=0
	row_num=1
	}

$0 == "row end" {
	in_end_row=1
	next
	}

$1 == "row" {
	row_num++
	next
	}

        {
	if (in_end_row == 0) {
	   if (row_num == 1)
	      num_val[$1]=$NF
	   else
	      num_val[$1]=num_val[$1] " ,, " $NF
	} else {
	   print $0 " ,, " num_val[$1]
	   }
	next
	}

END {
    }

