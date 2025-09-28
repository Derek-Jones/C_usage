#
# cntid-adj.txt, 11 Oct 10

BEGIN {
	while (getline < "adj-stef.txt")
	   adj[tolower($1)]=1
	}

	{
	for (w=2; w <= NF; w++)
	   if (adj[$w] == 1)
	      {
	      found_adj[$w]++
	      if (adj[$(w+1)] == 1)
		 {
		 adj_pair[$w " " $(w+1)]++
		 if (w+1 < NF)
		    adj_adj_x[$w " " $(w+1)]++
		 }
	      }
	next
	}

END {
	print ">>> single adjective"
	for (w in found_adj)
	   print w " " found_adj[w]
	print ">>> any adjective pair"
	for (w in adj_pair)
	   print w " " adj_pair[w]
	print ">>> adjective adjective something"
	for (w in adj_adj_x)
	   print w " " adj_adj_x[w]
	}

