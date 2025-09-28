# charcnt.awk, 15 Aug 03
#
# extract character frequencies

BEGIN {
	char_cnt=0
	}

$2 == "charfreq.d" {
	in_char_freq=1
	next
	}

$1 == "End" {
	if (in_char_freq == 0)
	   next
	print "total characters " all_ch_cnt
	print "total new-lines " all_newlines
	print "non-comment characters " noncom_ch_cnt
	print "non-comment new-lines " noncom_newlines
	exit
	next
	}

	{
	if (in_char_freq == 1) {
	   all_ch_cnt+=$2
	   noncom_ch_cnt+=$4
	   if ($1 == "\\n") {
	      all_newlines=$2
	      noncom_newlines=$4
	      }
	   }
	next
	}

END {
    }

