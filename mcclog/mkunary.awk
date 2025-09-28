# mkunary.awk, 29 Aug 03
#

BEGIN {
   }

   {
   gsub(/ ,, ,, /, " ,, ", $0)
   print $0
   next
   }

END {
	}

