# extrtable.awk, 13 Aug 03
#
# Extract a tables worth of data

BEGIN {
	char_cnt=0
	in_data_freq=0
	}

$2 == D_FILE {
	in_data_freq=1
	next
	}

$1 == "End" {
	if (in_data_freq == 1)
	   exit
	next
	}

	{
	if ((in_data_freq == 1) && ($0 != "")) {
	   print $0
	   }
	next
	}

END {
    }

