# undercnt.awk, 13 Jul 02
#
# split identifiers up using _ as the separator
#
BEGIN {
	max_splits=0
	}

	{
	sub(/^_+/, "", $1)
	sub(/_+$/, "", $1)
	if ($1 == "") {
	   next
	   }
	cur_splits=split($1, sub_ids, "_")-1
	num_splits[cur_splits]++
	if (cur_splits > max_splits) {
	   max_splits=cur_splits
	   }
	for (ind in sub_ids)
	   print sub_ids[ind]
	next
	}

END {
    print "Num_Splits Occurrences"
    for (ind=0; ind <= max_splits; ind++)
       print ind " " num_splits[ind]
    }

