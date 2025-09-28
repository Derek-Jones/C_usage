# getrefs.awk, 20 Aug 00
#
BEGIN {
	unreffed=0
	}

$0 ~ /ZZZ/ {
	unreffed=1
	next
	}

   {
	if (unreffed == 0)
	   is_reffed[$1] = 1
	else {
	   if (is_reffed[$1] != 1)
	      print $0
	   }
	next
	}

