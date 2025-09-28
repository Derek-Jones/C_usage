# sharetab.awk, 13 Aug 03
#
#
BEGIN {
	start_of_line=1
	}

$1 == "NEW-LINE" {
	print ""
	start_of_line=1
	next
	}

	{
	if (start_of_line == 0)
	   printf(" ,, ")
	printf(" %s ", $0)
	start_of_line=0
	next
	}

END {
    }

