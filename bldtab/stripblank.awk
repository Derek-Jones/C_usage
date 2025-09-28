# stripblank.awk, 12 Aug 03
#

	{
	if ($0 != "")
	   print $0
	next
	}
