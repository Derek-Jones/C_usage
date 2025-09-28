# idnumber.awk, 24 Dec 02
#
# Calculate the number of identifiers having different
# lengths
#
BEGIN {
	id_num=0
	}

	{
	id_num++
	print id_num " " $2
	next
	}

END {
    }

