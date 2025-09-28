# count unique.awk, 10 Apr 03
#
# Count number of unique lines
#

BEGIN {
	}

	{
	directives[$0]++
	next
	}

END {
    for (d in directives) {
       print directives[d] " " d
       }
    }

