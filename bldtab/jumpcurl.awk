# jumpcurl.awk, 17 Jul 03
#
# jump-statement; }

BEGIN {
	in_punct=0
	}

$2 ~ /cl_curl_prev_tok.d/ {
	in_data_freq=1
	next
	}

$1 ~ /End/ {
	if (in_data_freq == 1) exit
	next
	}

	{
	if (in_data_freq == 1) {
	   if ($1 == "BREAK")
	      print " " $1 " ,, " $3 " ,, " $4
	   if ($1 == "CONTINUE")
	      print " " $1 " ,, " $3 " ,, " $4
	   if ($1 == "GOTO")
	      print " " $1 " ,, " $3 " ,, " $4
	   if ($1 == "RETURN")
	      print " " $1 " ,, " $3 " ,, " $4
	   }
	next
	}

END {
    }

