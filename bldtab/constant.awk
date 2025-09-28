# constant.awk, 11 Jul 03
#
# constant usage

BEGIN {
	}

$2 ~ /tokcnt.d/ {
	in_data_freq=1
	next
	}

$1 ~ /End/ {
	if (in_data_freq == 1) exit
	next
	}

$1 ~ /CHAR_CONST/ {
	if (in_data_freq == 1)
	   print "character-constant " $2
	next
	}

$1 ~ /INT_CONST/ {
	if (in_data_freq == 1)
	   print "integer-constant " $2
	next
	}

$1 ~ /FLOAT_CONST/ {
	if (in_data_freq == 1)
	   print "floating-constant " $2
	next
	}

$1 ~ /STRING/ {
	if (in_data_freq == 1)
	   print "string-literal " $2
	next
	}

        {
	next
	}

END {
    }

