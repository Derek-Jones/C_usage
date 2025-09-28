# define.awk, 26 Apr 03
#
# Count #define ident_name information
#

BEGIN {
	}

$1 == "#DEFINE"  {
	num_def++
	if (def[$2] == 0) {
	   uniq_def++
	} else {
	   dup_def++
	}
	def[$2]++
	next
	}

$1 == "__E__O__F__"  {
	def_cnt[num_def]++
	if (num_def > max_num)
	   max_num=num_def
	num_def=0
	duniq_cnt[uniq_def]++
	if (uniq_def > max_uniq)
	   max_uniq=uniq_def
	uniq_def=0
	if (dup_def > max_dup)
	   max_dup=dup_def
	dup_def_cnt[dup_def]++
	dup_def=0
	delete def
	next
	}

	{
	next
	}

END {
    print "File: definecnt.d"
    for (i=0; i <= max_num; i++) {
       print i " " 0+def_cnt[i]
       }
    print "End File"
    print "File: defineuniq.d"
    for (i=0; i <= max_uniq; i++) {
       print i " " 0+duniq_cnt[i]
       }
    print "End File"
    print "File: definedup.d"
    for (i=0; i <= max_dup; i++) {
       print i " " 0+dup_def_cnt[i]
       }
    print "End File"
    }

