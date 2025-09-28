# relcont.sh, 25 Sep 25

#echo "<"
TOK_COUNTS=`awk -v OP="<" -f keyopocc.awk < $C_CNT_FILE`
zcat $STMT_DIR/*$CNTRL_SUFF | awk -v OP="<" -v COUNTS="$TOK_COUNTS" -f opcontext.awk
echo "row 2"

#echo "<="
TOK_COUNTS=`awk -v OP="<=" -f keyopocc.awk < $C_CNT_FILE`
zcat $STMT_DIR/*$CNTRL_SUFF | awk -v OP="<=" -v COUNTS="$TOK_COUNTS" -f opcontext.awk
echo "row 3"

#echo ">"
TOK_COUNTS=`awk -v OP=">" -f keyopocc.awk < $C_CNT_FILE`
zcat $STMT_DIR/*$CNTRL_SUFF | awk -v OP=">" -v COUNTS="$TOK_COUNTS" -f opcontext.awk
echo "row end"

#echo ">="
TOK_COUNTS=`awk -v OP=">=" -f keyopocc.awk < $C_CNT_FILE`
zcat $STMT_DIR/*$CNTRL_SUFF | awk -v OP=">=" -v COUNTS="$TOK_COUNTS" -f opcontext.awk

