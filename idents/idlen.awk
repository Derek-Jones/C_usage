# idlen.awk,  9 Jul 03
#
# Calculate the number of identifiers having different
# lengths and how also the lengths of ones that match known
# words (or at least those in our dictionary)
#
BEGIN {
	max_id_len=0
	in_idents=0
	}

$1 == "__E__O__F__"  {
	next
	}

$1 == "$___$" {
	in_idents=1
	next
	}

	{
	if (in_idents == 1) {
	   cur_len=length($1)
	   if (cur_len > max_id_len) {
	      max_id_len=cur_len
	      }
	   all_id_len[cur_len]++
	   if (seen_id[$1] == 0) {
	      seen_id[$1]=1
	      uniq_id_len[cur_len]++
	      }
	   # dictionary has words in lower case
	   lower_id=tolower($1)
	   if (word[lower_id] == 0) {
	   # swapping can be a big problem when lots of source
	   # is involved
	      delete word[lower_id]
	   } else {
	      all_word_len[cur_len]++
	      if (word[lower_id] == 1) {
	         word[lower_id]=2
	         uniq_word_len[cur_len]++
	      }
	   }
	} else {
	   word[$1]=1
	}
	next
	}

END {
    print "File: " F_SUFF "idlen.d"
    for (ind=1; ind <= max_id_len; ind++)
       print ind " " 0+all_id_len[ind]
    print "End File"
    print "File: " F_SUFF "idlenuniq.d"
    for (ind=1; ind <= max_id_len; ind++)
       print ind " " 0+uniq_id_len[ind]
    print "End File"

    print "File: " F_SUFF "idwordlen.d"
    for (ind=1; ind <= max_id_len; ind++)
       print ind " " 0+all_word_len[ind]
    print "End File"
    print "File: " F_SUFF "idwordlenuniq.d"
    for (ind=1; ind <= max_id_len; ind++)
       print ind " " 0+uniq_word_len[ind]
    print "End File"
    }

