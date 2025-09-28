# sptoksp.awk, 10 Jul 03
#
# space token frequencoes

BEGIN {
	char_cnt=0
	}

$2 ~ /sptoksp.d/ {
	in_data_freq=1
	next
	}

$1 ~ /End/ {
	if (in_data_freq == 0)
	   next
	exit
	next
	}

        {
	if (in_data_freq == 1) {
	   print $1 " " $3 " (" $5 ") " $8 " " $14 " " $11 " " $17
	}
	next
	}

END {
    }

