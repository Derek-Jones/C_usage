# conskind.awk, 12 Jul 03
#
# constant usage

BEGIN {
	}

$2 ~ /cons_kind.d/ {
	in_data_freq=1
	next
	}

$1 ~ /End/ {
	if (in_data_freq == 1) exit
	next
	}

	{
	if (in_data_freq == 1)
	   print $1 " ,, " $2
	next
	}

END {
    }

