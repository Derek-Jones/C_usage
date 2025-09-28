# postdirect.awk, 10 Apr 03
#
# Strip out trailing tokens from `ngram direct` output
# not used by mktab or mkgra

BEGIN {
	}

	{
	for (i=1; i < NF; i++) {
	   if ($i == "NEW_LINE") {
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

