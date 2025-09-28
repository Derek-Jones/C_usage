# defbody.awk, 26 Apr 03
#
# Count #define bodies
#

function abstract(cntrl_expr)
{
gsub(/FUNC_MAC \([^()]* \)/, "FUNC_MAC", cntrl_expr)
gsub(/IDENT \([^()]* \)/, "FUNC", cntrl_expr)
gsub(/IDENT \( [^()]+\( [^()]+ \)[^()]* \)/, "FUNC", cntrl_expr)
do {
   made_change=0
   made_change+=gsub(/- INT_CONST/, "INT_CONST", cntrl_expr)
   made_change+=gsub(/-v INT_CONST/, "INT_CONST", cntrl_expr)
   made_change+=gsub(/\( INT_CONST \)/, "INT_CONST", cntrl_expr)
   made_change+=gsub(/- CONST_EXPR/, "CONST_EXPR", cntrl_expr)
   made_change+=gsub(/\( CONST_EXPR \)/, "CONST_EXPR", cntrl_expr)
   made_change+=gsub(/\( IDENT \) INT_CONST/, "INT_CONST", cntrl_expr)
   made_change+=gsub(/(INT_CONST|CONST_EXPR) [-+*%\/&\|] (INT_CONST|CONST_EXPR)/, "CONST_EXPR", cntrl_expr)
   made_change+=gsub(/(INT_CONST|CONST_EXPR) (<<|>>) (INT_CONST|CONST_EXPR)/, "CONST_EXPR", cntrl_expr)
   } while (made_change != 0)
do {
   made_change=0
   made_change+=gsub(/\( IDENT \) IDENT/, "EXPR", cntrl_expr)
   made_change+=gsub(/IDENT \[ (IDENT|INT_CONST|EXPR|FUNC) \]/, "EXPR", cntrl_expr)
   made_change+=gsub(/(IDENT|EXPR) (->|\.) (IDENT|EXPR)/, "EXPR", cntrl_expr)
   made_change+=gsub(/IDENT \. (IDENT|EXPR)/, "EXPR", cntrl_expr)
   made_change+=gsub(/\( [^()]+ \* \) /, "", cntrl_expr)
   made_change+=gsub(/(IDENT|\( IDENT \)) \([^()]* \)/, "FUNC", cntrl_expr)
   made_change+=gsub(/(IDENT|\( IDENT \)) \( [^()]+\( [^()]+ \)[^()]* \)/, "FUNC", cntrl_expr)
   made_change+=gsub(/(EXPR|FUNC) -> IDENT/, "EXPR", cntrl_expr)
   made_change+=gsub(/(\*v|&v) (IDENT|EXPR)/, "EXPR", cntrl_expr)
   made_change+=gsub(/(IDENT|EXPR|FUNC|INT_CONST) [-+*%\/&\|] (IDENT|INT_CONST|EXPR|FUNC)/, "EXPR", cntrl_expr)
   made_change+=gsub(/(IDENT|EXPR|FUNC|INT_CONST) (<<|>>) (IDENT|INT_CONST|EXPR|FUNC)/, "EXPR", cntrl_expr)
   made_change+=gsub(/\( IDENT \)/, "IDENT", cntrl_expr)
   made_change+=gsub(/\( EXPR \)/, "EXPR", cntrl_expr)
   made_change+=gsub(/\( FUNC \)/, "FUNC", cntrl_expr)
   made_change+=gsub(/SIZEOF \( [^()]+ \)/, "EXPR", cntrl_expr)
   made_change+=gsub(/SIZEOF (IDENT|EXPR)/, "EXPR", cntrl_expr)
   made_change+=gsub(/IDENT = (IDENT|FUNC|EXPR|INT_CONST)/, "ASSIGN", cntrl_expr)
   made_change+=gsub(/ASSIGN (->|\.) IDENT/, "ASSIGN", cntrl_expr)
   made_change+=gsub(/\( ASSIGN \)/, "ASSIGN", cntrl_expr)
   } while (made_change != 0)
abs_expr=cntrl_expr
}

BEGIN {
	}

$1 == "#DEFINE"  {
        #
        # truncate last two tokens from input
        trunc_line=""
        for (pp=1; pp < NF-1; pp++)
           trunc_line=trunc_line " " $pp
        gsub(" COMMENT_NL", "", trunc_line)
        gsub(" COMMENT", "", trunc_line)
        gsub(" NEW_LINE", "", trunc_line)
        $0=trunc_line
        num_def++
	def_cnt[$0]++
	abstract($0)
	abstract_cnt[abs_expr]++
	next
	}

	{
	next
	}

END {
    print "abstract count " num_def
    TEMP_FILE="dy" systime()
    printf("") > TEMP_FILE
    for (h in abstract_cnt)
       print abstract_cnt[h] " " h >> TEMP_FILE
    close(TEMP_FILE)
    system("sort -gr < " TEMP_FILE)
    
    print "not abstracted"
    print "" > TEMP_FILE
    for (h in def_cnt)
       print def_cnt[h] " " h >> TEMP_FILE
    close(TEMP_FILE)
    system("sort -gr < " TEMP_FILE)
    print "End File"
    
    system("rm " TEMP_FILE)
    }

