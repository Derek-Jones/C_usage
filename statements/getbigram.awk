# getbigram.awk,  7 Jun 02
#
BEGIN {
	}

$2 ~ /tokdigram.d/ {
	in_digram=1
	next
	}

$3 ~ /tokdigram.d/ {
	in_digram=2
	next
	}

	{
	if (in_digram == 1) {
	   if (srch_val == $1) {
	      num_first++
	      first_list[num_first]=$0
	      if (($2 != "SPACE,") && ($2 != "LINE_START,")) {
		 first_total+=gensub(",", "", "g", $3)
		 }
	   } else if (srch_val == $2) {
	      num_second++
	      second_list[num_second]=$0
	      if ($1 != "SPACE,") {
		 second_total+=gensub(",", "", "g", $3)
	         }
	      }
	   }
	next
	}

END {
    print srch_val
    print "first total=" first_total ", second total=" second_total
    for (ind=1; ind <= num_first; ind++)
       print first_list[ind]
    for (ind=1; ind <= num_second; ind++)
       print second_list[ind]
    }


