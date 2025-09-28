# tokeneol.awk, 11 Jul 03
#
# tokens occurring immediately before new-line

BEGIN {
	}

$2 ~ /tokbigramnl.d/ {
	in_data_freq=1
	next
	}

$1 ~ /End/ {
	if (in_data_freq == 1)
	   exit
	next
	}

$2 == "NEW_LINE" {
	if (in_data_freq == 1) {
	   if (($1 != "NEW_LINE") && ($1 != "SPACE") && ($1 != "LINE_START"))
	      if ($5+$6 > 3.0)
	         print " " $1 " ,, " $5 " ,, " $6
	   }
	next
	}

        {
	next
	}

END {
    }

