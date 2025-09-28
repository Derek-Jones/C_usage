# lognotcont.sh, 25 Sep 25

TOK_COUNTS=`awk -v OP="!" -f keyopocc.awk < $C_CNT_FILE`

zcat $STMT_DIR/*$CNTRL_SUFF | awk -v COUNTS="$TOK_COUNTS" -f lognotcont.awk

