# mkgra.sh, 25 Sep 25
#
# Top level coordinator to graph template building

source ../config.files

#GEN_DATA=1

if [ $GEN_DATA == 1 ]; then
   zcat *$C_ID_SUFFIX | sort -u | wordambig > $LOC_DIA_DIR/all_prog.amb
   zcat *$C_ID_SUFFIX | awk -f undersplit.awk | wordambig > $LOC_DIA_DIR/all_prog.umb
   awk -f idambig.awk < $LOC_DIA_DIR/all_prog.amb > $LOC_DIA_DIR/idambig.d
   fi
$MKGRA idambig.g $LOC_DIA_DIR/idambig.d

if [ $GEN_DATA == 1 ]; then
   zcat $WORD_LIST *$C_ID_SUFFIX | awk -f wordsinid.awk > $LOC_DIA_DIR/under.c.wid
   fi
$MKGRA wordsinid.g $LOC_DIA_DIR/under.c.wid

exit

if [ $GEN_DATA == 1 ]; then
   zcat $WORD_LIST *$C_ID_SUFFIX | awk -f idlen.awk > $LOC_DIA_DIR/all_prog.c.len
   zcat $WORD_LIST *$H_ID_SUFFIX | awk -f idlen.awk > $LOC_DIA_DIR/all_prog.h.len
   fi
$MKGRA idlen.g $LOC_DIA_DIR/all_prog.c.len

idlev.sh > $LOC_DIA_DIR/all_prog.lev
$MKGRA idlev.g $LOC_DIA_DIR/all_prog.lev

$MKGRA idonline.g $C_CNT_FILE

if [ $GEN_DATA == 1 ]; then
   ./signif.sh > $LOC_DIA_DIR/idsignif
   awk -f sig.d.awk < $LOC_DIA_DIR/idsignif > $LOC_DIA_DIR/idsig.d
   fi
$MKGRA idsignif.g $LOC_DIA_DIR/idsig.d

if [ $GEN_DATA == 1 ]; then
   ./cntids.sh
   idzip.sh > $LOC_DIA_DIR/idzip
   fi
$MKGRA idzipf.g $LOC_DIA_DIR/idzip

if [ $GEN_DATA == 2 ]; then
   zcat engnames.gz *$C_ID_SUFFIX | awk -f wordsinid.awk > $LOC_DIA_DIR/under.c.nam
   fi

