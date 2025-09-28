# uniqcnt.awk,  9 Jul 03
#

BEGIN {
	}

$1 == "__E__O__F__"  {
	next
	}

	{
	count[$0]++
	}

END {
    for (i in count)
       print i " " count[i]
    }

