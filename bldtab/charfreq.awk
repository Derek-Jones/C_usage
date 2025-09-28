# charfreq.awk,  9 Jul 03
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
	exit
	next
	}

	{
	if (in_char_freq == 1) {
	   char_cnt++
	   # it is zero based
	   if (char_cnt <=128) {
	      print "@@" $1 "`@ ,, " $3 " ,, " $5
	      }
	   }
	next
	}

END {
    }

