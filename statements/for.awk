# for.awk, 10 Mar 06
#
# 10 Mar 06  num_* counts incremented for unique omitted sequences
# 29 Mar 03  Initial release
#
# Count the properties of 'for' control expressions
#

function abstract(cntrl_expr)
{
do {
   made_change=gsub(/\( IDENT \) INT_CONST/, "INT_CONST", cntrl_expr)
   made_change+=gsub(/\( IDENT \) IDENT/, "IDENT", cntrl_expr)
   made_change+=gsub(/IDENT \[ (IDENT|INT_CONST|EXPR|FUNC) \]/, "IDENT", cntrl_expr)
   made_change+=gsub(/IDENT (->|\.) (IDENT|EXPR)/, "IDENT", cntrl_expr)
   made_change+=gsub(/\( [^()]+ \* \) /, "", cntrl_expr)
   made_change+=gsub(/\( (CHAR|INT|UNSIGNED)+ \) /, "", cntrl_expr)
   made_change+=gsub(/IDENT \([^()]* \)/, "FUNC", cntrl_expr)
   made_change+=gsub(/IDENT \( [^()]+\( [^()]+ \)[^()]* \)/, "FUNC", cntrl_expr)
   made_change+=gsub(/(EXPR|FUNC) -> IDENT/, "EXPR", cntrl_expr)
   made_change+=gsub(/\* IDENT/, "EXPR", cntrl_expr)
   made_change+=gsub(/(IDENT|EXPR|FUNC|INT_CONST) [-+*%\/\&] (IDENT|INT_CONST|EXPR|FUNC)/, "EXPR", cntrl_expr)
   made_change+=gsub(/(IDENT|EXPR|FUNC|INT_CONST) << (IDENT|INT_CONST|EXPR|FUNC)/, "EXPR", cntrl_expr)
   made_change+=gsub(/(IDENT|EXPR|FUNC|INT_CONST) >> (IDENT|INT_CONST|EXPR|FUNC)/, "EXPR", cntrl_expr)
   made_change+=gsub(/\( EXPR \)/, "EXPR", cntrl_expr)
   made_change+=gsub(/SIZEOF \( [^()]+ \)/, "EXPR", cntrl_expr)
   made_change+=gsub(/-v INT_CONST/, "INT_CONST", cntrl_expr)
   made_change+=gsub(/IDENT = (IDENT|FUNC|EXPR|INT_CONST)/, "ASSIGN", cntrl_expr)
   made_change+=gsub(/ASSIGN (->|\.) IDENT/, "ASSIGN", cntrl_expr)
   made_change+=gsub(/\( ASSIGN \)/, "ASSIGN", cntrl_expr)
   } while (made_change != 0)
abs_expr=cntrl_expr
}

function operators()
{
if ($1 == "FOR") {
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

function output_expr(cnt_expr, abs_expr)
{
TEMP_FILE="TeMp.tEmP"
print("") > TEMP_FILE
for (i in cnt_expr) {
   print cnt_expr[i] " " i >> TEMP_FILE
   }
close(TEMP_FILE)
system("sort -gr < " TEMP_FILE)
print "abstract count"
print "" > TEMP_FILE
for (i in abs_expr) {
   print abs_expr[i] " " i >> TEMP_FILE
   }
close(TEMP_FILE)
system("sort -gr < " TEMP_FILE)
system("rm " TEMP_FILE)
}

BEGIN {
	FS=" ; "
	}

$0 ~ /^FOR \( / {
	num_for++
	gsub(" COMMENT_NL", "", $0)
	gsub(" COMMENT", "", $0)
	gsub(" NEW_LINE", "", $0)
	if ($0 ~ /\( ; ; \)/) {
	   num_noinit_control_increment++
	   }
	else
	   {
	   if ($0 ~ /\( ; ;/) {
	      num_noinit_control++
	      }
	   else
	      {
	      if (($0 ~ /\( ;/) &&
	          ($0 ~ /; \)/)) {
	         num_noinit_increment++
	         }
	      else
		 {
		 if ($0 ~ /\( ;/) {
	            num_noinit++
	            }
	         }
	      }
	   if ($0 ~ /; ; \)/) {
	      num_nocontrol_increment++
	      }
	   else
	      {
	      if ($0 ~ /; \)/) {
	         num_noincrement++
	         }
	      }
	   if ($0 ~ /; ;/) {
	      num_nocontrol++
	      }
	   }
	gsub(/FOR \( /, "", $1)
	init_cnt[$1]++
	abstract($1)
	init_abs[abs_expr]++
	cntrl_cnt[$2]++
	abstract($2)
	cntrl_abs[abs_expr]++
	gsub(/ \)/, "", $3)
	inc_cnt[$3]++
	abstract($3)
	inc_abs[abs_expr]++
	operators()
	next
	}

END {
   print "num for " num_for
   print "init counts"
   output_expr(init_cnt, init_abs)
   print "control counts"
   output_expr(cntrl_cnt, cntrl_abs)
   print "increment counts"
   output_expr(inc_cnt, inc_abs)
   print "no init " num_noinit
   print "no init control " num_noinit_control
   print "no init control increment " num_noinit_control_increment
   print "no init increment " num_noinit_increment
   print "no control " num_nocontrol
   print "no control increment " num_nocontrol_increment
   print "no increment " num_noincrement
   print "== " num_eq
   print "!= " num_ne
   print "< " num_le
   print "<= " num_leq
   print "> " num_ge
   print ">= " num_geq
   print "&& " num_land
   print "|| " num_lor
    }

