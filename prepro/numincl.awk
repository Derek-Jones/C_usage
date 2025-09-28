# numincl.awk, 24 Apr 03
#
# Count #include information
#

function header_properties(hq)
{
if ($2 ~ /^\/.+/) {
   num_abs_path++
   }
if (index($2, "/") != 0) {
   num_forward[hq]++
   }
if (index($2, "\\") != 0) {
   num_backward[hq]++
   }
if (hq == 1) {
   file_pos=split($2, hdr_inf, "/")
   q_len[length(hdr_inf[file_pos])]++
   }
}


BEGIN {
	stdhdr["assert.h"]=1
	stdhdr["inttypes.h"]=1
	stdhdr["signal.h"]=1
	stdhdr["stdlib.h"]=1
	stdhdr["complex.h"]=1
	stdhdr["iso646.h"]=1
	stdhdr["stdarg.h"]=1
	stdhdr["string.h"]=1
	stdhdr["ctype.h"]=1
	stdhdr["limits.h"]=1
	stdhdr["stdbool.h"]=1
	stdhdr["tgmath.h"]=1
	stdhdr["errno.h"]=1
	stdhdr["locale.h"]=1
	stdhdr["stddef.h"]=1
	stdhdr["time.h"]=1
	stdhdr["fenv.h"]=1
	stdhdr["math.h"]=1
	stdhdr["stdint.h"]=1
	stdhdr["wchar.h"]=1
	stdhdr["float.h"]=1
	stdhdr["setjmp.h"]=1
	stdhdr["stdio.h"]=1
	stdhdr["wctype.h"]=1
	}

$1 == "\""  {
	total_qinc++
	num_qinc++
	if (qinc[$2] == 0) {
	   uniq_qinc++
	   qhdr_str[$2]++
	   }
	qinc[$2]++
	header_properties(1)
	next
	}

$1 == "<"  {
	total_hinc++
	num_hinc++
	if (hinc[$2] == 0) {
	   uniq_hinc++
	   hhdr_str[$2]++
	   }
	hinc[$2]++
	header_properties(2)
	next
	}

$1 == "__E__O__F__"  {
	hinc_cnt[num_hinc]++
	qinc_cnt[num_qinc]++
	if (num_hinc > max_hinc) max_hinc=num_hinc
	if (num_qinc > max_qinc) max_qinc=num_qinc
	num_hinc=0
	num_qinc=0
	huniq_cnt[uniq_hinc]++
	quniq_cnt[uniq_qinc]++
	if (uniq_hinc > max_huniq) max_huniq=uniq_hinc
	if (uniq_qinc > max_quniq) max_quniq=uniq_qinc
	uniq_hinc=0
	uniq_qinc=0
	delete hinc
	delete qinc
	next
	}

	{
	next
	}

END {
    print "File: inclinfo.d"
    print "total h inc " total_hinc
    print "total q inc " total_qinc
    print "num abs path " num_abs_path
    print "num h forward " num_forward[2] ", q forward " num_forward[1]
    print "num h backward " num_backward[2] ", q backward " num_backward[1]
    print "End File"
    print "File: hinclcnt.d"
    for (i=0; i <= max_hinc; i++) {
       print i " " 0+hinc_cnt[i]
       }
    print "End File"
    print "File: hincluniq.d"
    for (i=0; i <= max_huniq; i++) {
       print i " " 0+huniq_cnt[i]
       }
    print "End File"
    print "File: qinclcnt.d"
    for (i=0; i <= max_qinc; i++) {
       print i " " 0+qinc_cnt[i]
       }
    print "End File"
    print "File: qincluniq.d"
    for (i=0; i <= max_quniq; i++) {
       print i " " 0+quniq_cnt[i]
       }
    print "End File"
    TEMP_FILE="nl" systime()
    print "" > TEMP_FILE
    for (h in qhdr_str)
       print h " " qhdr_str[h] >> TEMP_FILE
    close(TEMP_FILE)
    print "File: hdrqstr.d"
    system("sort -gr -k 2 < " TEMP_FILE)
    print "End File"
    print "" > TEMP_FILE
    for (h in hhdr_str)
       print h " " hhdr_str[h] >> TEMP_FILE
    close(TEMP_FILE)
    print "File: hdrhstr.d"
    system("sort -gr -k 2 < " TEMP_FILE)
    print "End File"

    # Print counts on the standard headers only
    print "" > TEMP_FILE
    for (h in stdhdr)
       print h " " 0+hhdr_str[h] >> TEMP_FILE
    close(TEMP_FILE)
    print "File: stdhdrh.d"
    system("sort < " TEMP_FILE)
    print "End File"

    print "" > TEMP_FILE
    for (h in q_len)
       print h " " q_len[h] >> TEMP_FILE
    close(TEMP_FILE)
    print "File: qhdrlen.d"
    system("sort -gr < " TEMP_FILE)
    print "End File"

    printf("") > TEMP_FILE
    num_uniq_str=0
    for (h in qhdr_str) {
       num_uniq_str++
       print h >> TEMP_FILE
       }
    close(TEMP_FILE)
    print "File: uniqqstr.d"
    print num_uniq_str
    system("colrm 14+2 < " TEMP_FILE " | sort -u | wc -l")
    system("colrm 8+2 < " TEMP_FILE " | sort -u | wc -l")
    system("colrm 6+2 < " TEMP_FILE " | sort -u | wc -l")
    print "End File"
    print "" > TEMP_FILE
    num_uniq_str=0
    for (h in hhdr_str) {
       num_uniq_str++
       print h >> TEMP_FILE
       }
    close(TEMP_FILE)
    print "File: uniqhstr.d"
    print num_uniq_str
    system("colrm 14+2 < " TEMP_FILE " | sort -u | wc -l")
    system("colrm 8+2 < " TEMP_FILE " | sort -u | wc -l")
    system("colrm 6+2 < " TEMP_FILE " | sort -u | wc -l")
    print "End File"
    
    system("rm " TEMP_FILE)
    }

