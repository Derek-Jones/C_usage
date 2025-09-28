# keyword.awk, 11 Jul 03
#
# keyword usage

function print_data()
{
TEMP_FILE="kd" systime()
printf("") > TEMP_FILE
for (k in keyword_freq) {
   printf(" %s %2.2f %2.2f %2.2f\n", k, 100*(keyword_freq[k]/total_keywords), keyword_sol[k], keyword_eol[k]) >> TEMP_FILE
   }
close(TEMP_FILE)
system("sort -gr -k 2 < " TEMP_FILE)
system("rm " TEMP_FILE)
exit
}


BEGIN {
	char_cnt=0
	keywords=" AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE"
	keywords=keywords " ELSE ENUM EXTERN FLOAT FOR GOTO IF INT LONG"
	keywords=keywords " REGISTER RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH"
	keywords=keywords " TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE "
	}

$2 ~ /tokcnt.d/ {
	in_data_freq=1
	next
	}

$2 ~ /tokbigramnl.d/ {
	in_data_freq=2
	next
	}

$1 ~ /End/ {
	if (in_data_freq == 1) in_data_freq=0
	if (in_data_freq == 2) print_data()
	next
	}

        {
	if (in_data_freq == 1) {
	   if (index(keywords, $1 " ") != 0) {
	      keyword_freq[$1]=$3
	      total_keywords=total_keywords+$3
	      }
	}
	if (in_data_freq == 2) {
	   if ((index(keywords, $1 " ") != 0) && ($2 == "NEW_LINE")) keyword_eol[$1]=$5
	   if ((index(keywords, $2 " ") != 0) && ($1 == "NEW_LINE")) keyword_sol[$2]=$6
	}
	next
	}

END {
    }

