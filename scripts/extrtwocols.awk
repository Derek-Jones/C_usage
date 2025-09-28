# extrtwocols.awk, 13 Jul 03
#
# Extract two columns of data

BEGIN {
	char_cnt=0
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
	   if (ADD_COMMA == "Y")
	      print $1 " ,, " $2
	   else
	      print $1 " " $2
	   }
	next
	}

END {
    }

