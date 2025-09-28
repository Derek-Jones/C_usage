# mkgra.sh, 25 Sep 25
#
# Top level coordinator to graph template building

source ../config.files

#GEN_DATA=1

C_BLK_SUFFIX=".c.block.gz"
H_BLK_SUFFIX=".h.block.gz"

if [ $GEN_DATA == 1 ]; then
   ./lcv.sh
   fi
$MKGRA lcv.g $LOC_DIA_DIR/all_prog.lcv.d

# Now in ../parse
#if [ $GEN_DATA == 1 ]; then
#   zcat *$C_BLK_SUFFIX | awk -f blocknest.awk > $LOC_DIA_DIR/blk.c.cnt
#   fi
#$MKGRA brkcon.g $LOC_DIA_DIR/blk.c.cnt
#$MKGRA loopnest.g $LOC_DIA_DIR/blk.c.cnt
#$MKGRA selectnest.g $LOC_DIA_DIR/blk.c.cnt
#$MKGRA cmpdnest.g $LOC_DIA_DIR/blk.c.cnt
#$MKGRA stmtcase.g $LOC_DIA_DIR/blk.c.cnt

if [ $GEN_DATA == 1 ]; then
   zcat *$C_BLK_SUFFIX | awk -f decl.awk > $LOC_DIA_DIR/decl.c.cnt
   zcat *$H_BLK_SUFFIX | awk -f decl.awk > $LOC_DIA_DIR/decl.h.cnt
   fi
$MKGRA sunest.g $LOC_DIA_DIR/decl.c.cnt $LOC_DIA_DIR/decl.h.cnt
$MKGRA sunummem.g $LOC_DIA_DIR/decl.c.cnt $LOC_DIA_DIR/decl.h.cnt

$MKGRA initlist.g $LOC_DIA_DIR/decl.c.cnt

