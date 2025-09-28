# mergecol3.awk, 16 Aug 03
#
# merge on the third column

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
	   print $1 " " $2 " ,, " $3 " ,, " h_3[t_num]
	else {
	   h_3[t_num]=$3
	   }
	next
	}

END {
    }

