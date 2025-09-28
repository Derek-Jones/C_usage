# ppcntrl.awk, 17 Jul 03
#
# Count the properties of preprocessor control expressions
#

function abstract(cntrl_expr)
{
do {
   made_change=0
   made_change+=gsub(/- INT_CONST/, "INT_CONST", cntrl_expr)
   made_change+=gsub(/-v INT_CONST/, "INT_CONST", cntrl_expr)
   made_change+=gsub(/\( IDENT \) INT_CONST/, "INT_CONST", cntrl_expr)
   made_change+=gsub(/\( IDENT \) IDENT/, "IDENT", cntrl_expr)
   made_change+=gsub(/IDENT \[ (IDENT|INT_CONST|EXPR|FUNC) \]/, "IDENT", cntrl_expr)
   made_change+=gsub(/IDENT (->|\.) (IDENT|EXPR)/, "IDENT", cntrl_expr)
   made_change+=gsub(/IDENT \. (IDENT|EXPR)/, "IDENT", cntrl_expr)
   } while (made_change != 0)
do {
   made_change=0
   made_change+=gsub(/IDENT \[ (IDENT|INT_CONST|EXPR|FUNC) \]/, "IDENT", cntrl_expr)
   made_change+=gsub(/IDENT (->|\.) (IDENT|EXPR)/, "IDENT", cntrl_expr)
   made_change+=gsub(/IDENT \. (IDENT|EXPR)/, "IDENT", cntrl_expr)
   made_change+=gsub(/\( [^()]+ \* \) /, "", cntrl_expr)
   made_change+=gsub(/\( (CHAR|INT|UNSIGNED)+ \) /, "", cntrl_expr)
   made_change+=gsub(/(EXPR|FUNC) -> IDENT/, "EXPR", cntrl_expr)
   made_change+=gsub(/(\*v|&v) (IDENT|EXPR)/, "EXPR", cntrl_expr)
   made_change+=gsub(/(IDENT|EXPR|FUNC|INT_CONST) [-+*%\/&\|] (IDENT|INT_CONST|EXPR|FUNC)/, "EXPR", cntrl_expr)
   made_change+=gsub(/(IDENT|EXPR|FUNC|INT_CONST) (<<|>>) (IDENT|INT_CONST|EXPR|FUNC)/, "EXPR", cntrl_expr)
   made_change+=gsub(/IDENT \([^()]* \)/, "FUNC", cntrl_expr)
   made_change+=gsub(/IDENT \( [^()]+\( [^()]+ \)[^()]* \)/, "FUNC", cntrl_expr)
   made_change+=gsub(/\( EXPR \)/, "EXPR", cntrl_expr)
   made_change+=gsub(/SIZEOF \( [^()]+ \)/, "EXPR", cntrl_expr)
   made_change+=gsub(/IDENT = (IDENT|FUNC|EXPR|INT_CONST)/, "ASSIGN", cntrl_expr)
   made_change+=gsub(/ASSIGN (->|\.) IDENT/, "ASSIGN", cntrl_expr)
   made_change+=gsub(/\( ASSIGN \)/, "ASSIGN", cntrl_expr)
   } while (made_change != 0)
abs_expr=cntrl_expr
}

function output_expr(cnt_expr, abs_expr)
{
TEMP_FILE="pl" systime()
printf("") > TEMP_FILE
print "abstract count " num_ppif " " num_ppelif
for (i in abs_expr) {
   print abs_expr[i] " " i >> TEMP_FILE
   }
close(TEMP_FILE)
system("sort -gr < " TEMP_FILE)
print "not abstracted"
print "" > TEMP_FILE
for (i in cnt_expr) {
   print cnt_expr[i] " " i >> TEMP_FILE
   }
close(TEMP_FILE)
system("sort -gr < " TEMP_FILE)
system("rm " TEMP_FILE)
}


function operators()
{
if ($1 == "IF") {
   num_eq += gsub(/==/, "", $0)
   num_ne += gsub(/!=/, "", $0)
   num_leq += gsub(/<=/, "", $0)
   num_le += gsub(/</, "", $0)
   num_geq += gsub(/>=/, "", $0)
   num_ge += gsub(/>/, "", $0)
   num_land += gsub(/\&\&/, "", $0)
   num_lor += gsub(/\|\|/, "", $0)
   }
}

BEGIN {
	}

$1 == "#IF" ||
$1 == "#ELIF" {
	if ($1 == "#IF")
	   num_ppif++
	if ($1 == "#ELIF")
	   num_ppelif++
	#
	# truncate last two tokens from input
	trunc_line=""
	for (pp=1; pp < NF-1; pp++)
	   trunc_line=trunc_line " " $pp
	gsub(" COMMENT_NL", "", trunc_line)
	gsub(" COMMENT", "", trunc_line)
	gsub(" NEW_LINE", "", trunc_line)
	$0=trunc_line
	cntrl_cnt[$0]++
	abstract($0)
	abstract_cnt[abs_expr]++
	operators()
	next
	}
	
	{
	next
	}

END {
    output_expr(cntrl_cnt, abstract_cnt)
   print "== " num_eq
   print "!= " num_ne
   print "< " num_le
   print "<= " num_leq
   print "> " num_ge
   print ">= " num_geq
   print "&& " num_land
   print "|| " num_lor
    }

