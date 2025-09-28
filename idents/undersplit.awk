# undersplit.awk, 13 Jul 02
#
# split identifiers up using _ as the separator
#
BEGIN {
	}

	{
	sub(/^_+/, "", $1)
	sub(/_+$/, "", $1)
	if ($1 == "") {
	   next
	   }
	split($1, sub_ids, "_")
	for (ind in sub_ids)
	   under_ids[sub_ids[ind]]=1
	next
	}

END {
    for (ind in under_ids) {
       print ind
       }
    }

