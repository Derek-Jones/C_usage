# mkgra.sh,  8 Jan 08
#
# Top level coordinator to graph template building

source ../config.files

#GEN_DATA=1

C_BLK_SUFFIX=".c.block.gz"
H_BLK_SUFFIX=".h.block.gz"

if [ $GEN_DATA == 1 ]; then
#  getblock.sh
   gzcat *$C_BLK_SUFFIX | awk -f scripts/ifelsematch.awk | awk -f scripts/blocknest.awk > $LOC_DIA_DIR/blk.c.cnt
   fi
$MKGRA brkcon.g $LOC_DIA_DIR/blk.c.cnt
$MKGRA loopnest.g $LOC_DIA_DIR/blk.c.cnt
$MKGRA selectnest.g $LOC_DIA_DIR/blk.c.cnt
$MKGRA cmpdnest.g $LOC_DIA_DIR/blk.c.cnt
$MKGRA stmtcase.g $LOC_DIA_DIR/blk.c.cnt

if [ $GEN_DATA == 1 ]; then
   get_opcnts.sh | awk -f scripts/exprop.awk > $LOC_DIA_DIR/exprop.c.cnt
   fi
$MKGRA exprop.g $LOC_DIA_DIR/exprop.c.cnt

