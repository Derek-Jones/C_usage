# mergefirstcol.awk, 10 Aug 03
#
# merge the first column of numeric data from .c and .h files

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
	   for (c=1; c <= 4; c++)
	      printf("%s ", $c)
	   printf(",, %s\n", h_4[t_num])
	} else {
	   h_4[t_num]=$4
	   }
	next
	}

END {
    }

