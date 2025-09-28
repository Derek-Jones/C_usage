# stripcomnl.awk, 10 Apr 03
#
# Strip out trailing COMMENT_NL's
# not used by mktab or mkgra

BEGIN {
	}

	{
	for (i=1; i <= NF; i++) {
	   if ($i == "COMMENT_NL") {
	      print ""
	      next
	      }
	   printf("%s ", $i)
	   }
	print ""
	next
	}

END {
    }

