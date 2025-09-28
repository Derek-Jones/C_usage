#
# mkbinpair.sh,  7 Mar 12

TEMP_FILE="$$"

scripts/get_opcnts.sh all

awk -f scripts/cntop.awk < all.opcnt > $TEMP_FILE

sed '/cut-here/,$d' < $TEMP_FILE | awk -f scripts/pairop.awk

rm $TEMP_FILE 
