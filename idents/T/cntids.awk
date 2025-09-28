# cntids.awk, 24 Dec 02
#
# Count the number of different identifiers
#
BEGIN {
	}

	{
	id_seen[$1]++
	next
	}

END {
    for (ind in id_seen)
       print ind " " id_seen[ind]
    }

