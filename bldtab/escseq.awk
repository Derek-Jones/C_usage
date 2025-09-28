# escseq.awk, 13 Jul 03
#
# extract escape sequences

BEGIN {
	char_cnt=0
	}

$2 ~ /escseq.d/ {
	in_data_freq=1
	next
	}

$1 ~ /End/ {
	if (in_data_freq == 1) exit
	next
	}

	{
	if (in_data_freq == 1) {
	   print "\\" $1 " ,, " $3 " ,, " $5
	   }
	next
	}

END {
    }

