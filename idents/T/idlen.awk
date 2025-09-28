# idlen.awk, 13 Jul 02
#
# Calculate the number of identifiers having different
# lengths
#
BEGIN {
	max_id_len=0
	}

	{
	cur_len=length($1)
	if (cur_len > max_id_len) {
	   max_id_len=cur_len
	   }
	all_id_len[cur_len]++
	if (seen_id[$1] == 0) {
	   seen_id[$1]=1
	   uniq_id_len[cur_len]++
	   }
	next
	}

END {
    print "All Length occurrences"
    for (ind=1; ind <= max_id_len; ind++)
       print ind " " 0+all_id_len[ind]
    print "Unique Length occurrences"
    for (ind=1; ind <= max_id_len; ind++)
       print ind " " 0+uniq_id_len[ind]
    }

