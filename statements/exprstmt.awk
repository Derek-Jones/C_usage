# exprstmt.awk,  7 Dec 03
#
# Count the properties of control expressions
#

function abstract(cntrl_expr)
{
gsub(/CHAR_CONST/, "CONST", cntrl_expr)
gsub(/INT_CONST/, "CONST", cntrl_expr)
do {
   made_change=gsub(/\( IDENT \) CONST/, "CONST", cntrl_expr)
   made_change+=gsub(/\( IDENT \) IDENT/, "IDENT", cntrl_expr)
   made_change+=gsub(/IDENT \[ (IDENT|CONST|EXPR|FUNC) \]/, "IDENT", cntrl_expr)
   made_change+=gsub(/IDENT (->|\.) (IDENT|EXPR)/, "IDENT", cntrl_expr)
   made_change+=gsub(/IDENT \. (IDENT|EXPR)/, "IDENT", cntrl_expr)
   made_change+=gsub(/\( [^()]+ \* \) /, "", cntrl_expr)
   #made_change+=gsub(/\( (CHAR|INT|UNSIGNED)+ \) /, "", cntrl_expr)
   made_change+=gsub(/IDENT \([^()]* \)/, "FUNC", cntrl_expr)
   made_change+=gsub(/IDENT \( [^()]+\([^()]* \)[^()]* \)/, "FUNC", cntrl_expr)
   made_change+=gsub(/(EXPR|FUNC) -> IDENT/, "EXPR", cntrl_expr)
   #made_change+=gsub(/\* IDENT/, "EXPR", cntrl_expr)
   made_change+=gsub(/(IDENT|EXPR|FUNC|CONST) [-+*%\/\&] (IDENT|CONST|EXPR|FUNC)/, "EXPR", cntrl_expr)
   made_change+=gsub(/(IDENT|EXPR|FUNC|CONST) << (IDENT|CONST|EXPR|FUNC)/, "EXPR", cntrl_expr)
   made_change+=gsub(/(IDENT|EXPR|FUNC|CONST) >> (IDENT|CONST|EXPR|FUNC)/, "EXPR", cntrl_expr)
   made_change+=gsub(/\( EXPR \)/, "EXPR", cntrl_expr)
   made_change+=gsub(/SIZEOF \( [^()]+ \)/, "EXPR", cntrl_expr)
   made_change+=gsub(/-v CONST/, "CONST", cntrl_expr)
   #made_change+=gsub(/IDENT = (IDENT|FUNC|EXPR|CONST)/, "ASSIGN", cntrl_expr)
   #made_change+=gsub(/ASSIGN (->|\.) IDENT/, "ASSIGN", cntrl_expr)
   #made_change+=gsub(/\( ASSIGN \)/, "ASSIGN", cntrl_expr)
   } while (made_change != 0)
gsub(/CONST/, "constant", cntrl_expr)
abs_expr=cntrl_expr
}

BEGIN {
	}

$0 == "__E__O__F__" {
	next
	}

$0 == "" ||
($1 == "IDENT" && $2 == "IDENT") ||
$1 == "STRUCT" ||
$1 == "UNSIGNED" ||
$1 == "CHAR" ||
$1 == "INT" {
	next
	}

	{
	gsub(/^CASE .+ : /, "", $0)
	gsub(/^DEFAULT : /, "", $0)
	gsub(/^IDENT : /, "", $0)
	if ($0 == "")
	   next
	num_exprstmt++
	abstract($0)
	abstract_cnt[abs_expr]++
	next
	}

END {
	print "num_expr_stmt " num_exprstmt
	TEMP_FILE="es" systime()
	print("") > TEMP_FILE
	for (i in abstract_cnt)
   	   print abstract_cnt[i] " " i >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -gr < " TEMP_FILE)

	system("rm " TEMP_FILE)
	}

