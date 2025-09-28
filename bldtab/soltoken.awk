# soltoken.awk, 11 Jul 03
#
# tokens occurring first on a line

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

$1 == "NEW_LINE" {
	if (in_data_freq == 1) {
	   if (($6 >= 4.0) && ($2 != "NEW_LINE") && ($2 != "SPACE") && ($2 != "LINE_START"))
	      print " " $2 " ,, " $5 " ,, " $6
	   }
	next
	}

        {
	next
	}

END {
    }

