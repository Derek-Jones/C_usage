# andcont.sh, 25 Sep 25

#echo "&&"
TOK_COUNTS=`awk -v OP="&&" -f keyopocc.awk < $C_CNT_FILE`
zcat $STMT_DIR/*$CNTRL_SUFF | awk -v OP="&&" -v COUNTS="$TOK_COUNTS" -f opcontext.awk
echo "END_BIT"

#echo "&"
TOK_COUNTS=`awk -v OP="&" -f keyopocc.awk < $C_CNT_FILE`
zcat $STMT_DIR/*$CNTRL_SUFF | awk -v OP="&" -v COUNTS="$TOK_COUNTS" -f opcontext.awk

