# cntrlexpr.awk, 18 Jul 09
#
# Count the properties of control expressions
#

function abstract(cntrl_expr)
{
do {
   made_change=gsub(/CHAR_CONST/, "INT_CONST", cntrl_expr)
   made_change+=gsub(/\( IDENT \) INT_CONST/, "INT_CONST", cntrl_expr)
   made_change+=gsub(/IDENT \( INT_CONST \)/, "FUNC", cntrl_expr)
   made_change+=gsub(/\( INT_CONST \) /, "INT_CONST ", cntrl_expr)
   made_change+=gsub(/-v INT_CONST/, "INT_CONST", cntrl_expr)
   made_change+=gsub(/~ INT_CONST/, "INT_CONST", cntrl_expr)
   made_change+=gsub(/SIZEOF IDENT/, "INT_CONST", cntrl_expr)
   made_change+=gsub(/SIZEOF \( [^()]+ \)/, "INT_CONST", cntrl_expr)
   made_change+=gsub(/INT_CONST [-+*%\/\&\|^] INT_CONST/, "INT_CONST", cntrl_expr)
   made_change+=gsub(/\( IDENT \) IDENT/, "IDENT", cntrl_expr)
   made_change+=gsub(/IDENT \[ (IDENT|INT_CONST|EXPR|FUNC) \]/, "IDENT", cntrl_expr)
   made_change+=gsub(/\&v IDENT -> (IDENT|EXPR)/, "IDENT", cntrl_expr)
   made_change+=gsub(/\&v \( IDENT \) -> (IDENT|EXPR)/, "IDENT", cntrl_expr)
   made_change+=gsub(/IDENT (->|\.) (IDENT|EXPR)/, "IDENT", cntrl_expr)
   made_change+=gsub(/\*v (IDENT|EXPR)/, "IDENT", cntrl_expr)
   made_change+=gsub(/\*v \( (IDENT|EXPR) \)/, "IDENT", cntrl_expr)
   if ($1 == "IF")
      {
   made_change+=gsub(/\+\+v IDENT/, "EXPR", cntrl_expr)
   made_change+=gsub(/--v IDENT/, "EXPR", cntrl_expr)
   made_change+=gsub(/IDENT v\+\+/, "EXPR", cntrl_expr)
   made_change+=gsub(/IDENT v--/, "EXPR", cntrl_expr)
      }
   made_change+=gsub(/ -v IDENT/, "EXPR", cntrl_expr)
   made_change+=gsub(/\&v IDENT/, "EXPR", cntrl_expr)
   made_change+=gsub(/\&v \( IDENT \)/, "EXPR", cntrl_expr)
   made_change+=gsub(/FUNC (->|\.) (IDENT|EXPR)/, "EXPR", cntrl_expr)
   made_change+=gsub(/\( [^()]+ \* \) /, "", cntrl_expr)
   made_change+=gsub(/\( (CHAR|INT|UNSIGNED)+ \) /, "", cntrl_expr)
   made_change+=gsub(/IDENT \( \)/, "FUNC", cntrl_expr)
   made_change+=gsub(/IDENT \( [^()]* \)/, "FUNC", cntrl_expr)
   made_change+=gsub(/IDENT \( [^()]+\( [^()]+ \)[^()]* \)/, "FUNC", cntrl_expr)
   made_change+=gsub(/(EXPR|FUNC) -> IDENT/, "EXPR", cntrl_expr)
   made_change+=gsub(/(IDENT|EXPR|FUNC|INT_CONST) [-+*%\/\&^] (IDENT|INT_CONST|EXPR|FUNC)/, "EXPR", cntrl_expr)
   made_change+=gsub(/(IDENT|EXPR|FUNC|INT_CONST) (<<|>>) (IDENT|INT_CONST|EXPR|FUNC)/, "EXPR", cntrl_expr)
   made_change+=gsub(/\( EXPR \)/, "EXPR", cntrl_expr)
   made_change+=gsub(/IDENT = (IDENT|FUNC|EXPR|INT_CONST)/, "ASSIGN", cntrl_expr)
   made_change+=gsub(/ASSIGN (->|\.) IDENT/, "ASSIGN", cntrl_expr)
   made_change+=gsub(/\( ASSIGN \)/, "ASSIGN", cntrl_expr)
   } while (made_change != 0)
abs_expr=cntrl_expr
}

function output_expr(cnt_expr, abs_expr)
{
TEMP_FILE="TeMp.tEmP"
print("") > TEMP_FILE
print "abstract count " num_if " " num_while " " num_switch " " num_for
for (i in abs_expr)
   print abs_expr[i] " " i >> TEMP_FILE
close(TEMP_FILE)
system("sort -gr < " TEMP_FILE)
print "not abstracted"
print "" > TEMP_FILE
for (i in cnt_expr)
   print cnt_expr[i] " " i >> TEMP_FILE
close(TEMP_FILE)
system("sort -gr < " TEMP_FILE)
system("rm " TEMP_FILE)
}


function operators()
{
if ($1 == "IF") {
   num_if_eq += (match($0,  /==/) != 0)
   num_if_ne += (match($0,  /!=/) != 0)
   num_if_leq += (match($0, /<=/) != 0)
   num_if_le += (match($0,  / < /) != 0)
   num_if_geq += (match($0, />=/) != 0)
   num_if_ge += (match($0,  / > /) != 0)
   num_if_land += (match($0, /\&\&/) != 0)
   num_if_lor += (match($0, /\|\|/) != 0)
   num_eq += gsub(/==/, "", $0)
   num_ne += gsub(/!=/, "", $0)
   num_leq += gsub(/ <= /, "", $0)
   num_le += gsub(/ < /, "", $0)
   num_geq += gsub(/ >= /, "", $0)
   num_ge += gsub(/ > /, "", $0)
   num_land += gsub(/\&\&/, "", $0)
   num_lor += gsub(/\|\|/, "", $0)
   }
}

BEGIN {
	}

	{
	if ($1 == "IF")
	   num_if++
	if ($1 == "WHILE")
	   num_while++
	if ($1 == "SWITCH")
	   num_switch++
	if ($1 == "FOR")
	   num_for++
	cntrl_cnt[$0]++
	gsub(" COMMENT_NL", "", $0)
	gsub(" COMMENT", "", $0)
	gsub(" NEW_LINE", "", $0)
	abstract($0)
	abstract_cnt[abs_expr]++
	operators()
	next
	}

END {
    output_expr(cntrl_cnt, abstract_cnt)
   print "== " num_if_eq   " " num_eq
   print "!= " num_if_ne   " " num_ne
   print "< "  num_if_le   " " num_le
   print "<= " num_if_leq  " " num_leq
   print "> "  num_if_ge   " " num_ge
   print ">= " num_if_geq  " " num_geq
   print "&& " num_if_land " " num_land
   print "|| " num_if_lor  " " num_lor
    }

