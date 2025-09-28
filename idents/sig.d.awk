# sig.d.awk,  2 Aug 03
#
#
BEGIN {
	}

$1 == "File:" {
	sub(".c.uniq", "", $2)
	split($2, name, "-")
	d_file=name[1] ".sig.d"
	total_ids=$3
	print "File: " d_file
	next
	}

$1 == "End" {
	print "End File"
	next
	}

	{
	if (100*($3/total_ids) > 0.001)
	   printf("%d %2.3f\n", $1, 100*($3/total_ids))
	next
	}

END {
    }

