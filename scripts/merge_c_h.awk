# merge_c_h.awk, 16 dec 03
#
# merge in last column from .h file with line from .c file

BEGIN {
	in_dot_h=1
	t_num=0
	}

$1 == "END_DOT_H" {
	in_dot_h=0
	t_num=0
	next
	}

        {
	t_num++
	if (in_dot_h == 0)
	   print $0 " (" h_2[t_num] ")"
	else {
	   h_2[t_num]=$NF
	   }
	next
	}

END {
    }

