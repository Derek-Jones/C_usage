#
# get-adj-list.awk, 28 Sep 10
#
# Count occurrences of each word in a file

	{
	for (i=1; i <= NF; i++)
	  words[tolower($i)]++
	next
	}

END {
	for (w in words)
	   print w "  " words[w]
	}


