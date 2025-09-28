# mergesptoksp.awk, 10 Aug 03
#
# space token frequencoes

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
	   print $1 " ,, " $2 " " $3 " ,, " h_2[t_num] " " h_3[t_num] " ,, " $4 " ,, " $5 " ,, " $6 " ,, " $7
	else {
	   h_2[t_num]=$2
	   h_3[t_num]=$3
	   }
	next
	}

END {
    }

