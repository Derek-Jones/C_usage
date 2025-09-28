# bigram.awk, 10 Jul 03
#
# locate token bigram pairs

BEGIN {
	char_cnt=0
	NOT_SET="zzz"
	#print ANY_TOK
	#print MUST_TOK
	#print NOT_TOK
	if (FIRST_TOK == "") FIRST_TOK=NOT_SET
	if (SECOND_TOK == "") SECOND_TOK=NOT_SET
	#print "1st " FIRST_TOK " 2nd " SECOND_TOK
	}

$2 ~ /tokbigram.d/ {
	in_bigram_freq=1
	TEMP_FILE="bm" systime()
	print "" > TEMP_FILE
	next
	}

$1 ~ /End/ {
	if (in_bigram_freq == 0)
	   next
	close(TEMP_FILE)
	system("sort -gr -k 3 < " TEMP_FILE " | awk -f stripblank.awk")
	system("rm " TEMP_FILE)
	exit
	next
	}

        {
	if (in_bigram_freq == 1) {
	   # print "1 " $1 ":" index(MUST_TOK, " " $1 " ")
	   # print "2:" index(MUST_TOK, " " $2 " ") " " $0
	   # print "3 " $1 ":" index(FIRST_TOK, " " $1 " ")
	   # print "4 " $2 ":" index(SECOND_TOK, " " $2 " ")
	   if (((((index(ANY_TOK, " " $1 " ") != 0) ||   \
	          (index(ANY_TOK, " " $2 " ") != 0)) &&  \
	         ((MUST_TOK == "") ||                     \
	          (index(MUST_TOK, " " $1 " ") != 0) ||  \
	          (index(MUST_TOK, " " $2 " ") != 0))) ||  \
	        ((index(FIRST_TOK, " " $1 " ") != 0) &&  \
	         (index(SECOND_TOK, " " $2 " ") != 0)) || \
	        ((FIRST_TOK == NOT_SET) &&  \
	         (index(SECOND_TOK, " " $2 " ") != 0)) || \
	        ((index(FIRST_TOK, " " $1 " ") != 0) &&  \
	         (SECOND_TOK == NOT_SET))) && \
	       ((index(NOT_TOK, " " $1 " ") == 0) &&     \
	        (index(NOT_TOK, " " $2 " ") == 0))) {
	   # Require that the primary token(s) frequency be at least 1%
	      if (((PRIM_TOK == "") && \
	           (($5 >= 1) || ($6 >= 1)) && ($5+$6 >= 5)) || \
	          ((index(PRIM_TOK, " " $1 " ") != 0) && ($5 >= 1)) || \
	          ((index(PRIM_TOK, " " $2 " ") != 0) && ($6 >= 1)))
	         print " " $1 " " $2 " ,, " $5 " ,, " $6 >> TEMP_FILE
	   }
	}
	next
	}

END {
    }

