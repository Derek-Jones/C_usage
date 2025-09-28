# mergeesu.awk, 10 Aug 03
#
# keyword token frequencies

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
	   print $1 " " $2 " ,, " $4 " ,, " h_4[t_num]
	else {
	   h_4[t_num]=$4
	   }
	next
	}

END {
    }

