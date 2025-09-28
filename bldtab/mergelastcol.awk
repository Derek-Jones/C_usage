# mergelastcol.awk, 19 Aug 03
#
# merge the last column of numeric data from .c and .h files

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
	if (in_dot_h == 0) {
	   for (c=1; c <= NF; c++)
	      printf("%s ", $c)
	   printf(",, %s\n", h_last[t_num])
	} else {
	   h_last[t_num]=$NF
	   }
	next
	}

END {
    }

