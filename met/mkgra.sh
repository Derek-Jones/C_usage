# mkgra.sh, 25 Sep 25
#
# Top level coordinator to graph template building

source ../config.files

#GEN_DATA=1

if [ $GEN_DATA == 1 ]; then
   zcat *$MET_SUFF | awk -f externid.awk | gzip --stdout > $LOC_DIA_DIR/externid.gz
   zcat $WORD_LIST $LOC_DIA_DIR/*externid.gz | awk -v F_SUFF="ex" -f $IDENT_DIR/idlen.awk > $LOC_DIA_DIR/all_prog.len
   fi
$MKGRA exidlen.g $LOC_DIA_DIR/all_prog.len

if [ $GEN_DATA == 1 ]; then
   zcat *$MET_SUFF | awk -f numglob.awk > $LOC_DIA_DIR/numglob
   fi
$MKGRA globcount.g $LOC_DIA_DIR/numglob

if [ $GEN_DATA == 1 ]; then
   zcat *$MET_SUFF | awk -f linkage.awk > $LOC_DIA_DIR/linkage
   fi
$MKGRA linkage.g $LOC_DIA_DIR/linkage

if [ $GEN_DATA == 1 ]; then
   zcat *$MET_SUFF | awk -f nestdecl.awk > $LOC_DIA_DIR/nestdecl
   fi
$MKGRA nestdecl.g $LOC_DIA_DIR/nestdecl

if [ $GEN_DATA == 1 ]; then
   zcat *$MET_SUFF | awk -f objsize.awk > $LOC_DIA_DIR/objsize
   fi
$MKGRA objsize.g $LOC_DIA_DIR/objsize

if [ $GEN_DATA == 1 ]; then
   zcat *$MET_SUFF | awk -f numexterns.awk > $LOC_DIA_DIR/numexterns
   fi
$MKGRA extcount.g $LOC_DIA_DIR/numexterns

if [ $GEN_DATA == 1 ]; then
   zcat *$MET_SUFF | awk -f incnest.awk > $LOC_DIA_DIR/incnest
   fi
$MKGRA incnest.g $LOC_DIA_DIR/incnest

if [ $GEN_DATA == 1 ]; then
   zcat *$MET_SUFF | awk -f sameinc.awk > $LOC_DIA_DIR/sameinc
   fi
$MKGRA sameinc.g $LOC_DIA_DIR/sameinc

if [ $GEN_DATA == 1 ]; then
   zcat *$MET_SUFF | awk -f mkctype.awk -f numlocal.awk > $LOC_DIA_DIR/numlocal
   fi
$MKGRA loccount.g $LOC_DIA_DIR/numlocal
$MKGRA paramcnt.g $LOC_DIA_DIR/numlocal
$MKGRA blkdeclnest.g $LOC_DIA_DIR/numlocal

if [ $GEN_DATA == 1 ]; then
   zcat *$MET_SUFF | awk -f sameiddecl.awk > $LOC_DIA_DIR/sameiddecl
   fi
$MKGRA sameiddecl.g $LOC_DIA_DIR/sameiddecl

if [ $GEN_DATA == 1 ]; then
   zcat *$MET_SUFF | awk -f fdefinfo.awk > $LOC_DIA_DIR/fdefinfo
   fi
$MKGRA numstmt.g $LOC_DIA_DIR/fdefinfo
$MKGRA iterperfunc.g $LOC_DIA_DIR/fdefinfo
$MKGRA selectperfunc.g $LOC_DIA_DIR/fdefinfo
$MKGRA jumpperfunc.g $LOC_DIA_DIR/fdefinfo
$MKGRA cmpdperfunc.g $LOC_DIA_DIR/fdefinfo
$MKGRA idperfunc.g $LOC_DIA_DIR/fdefinfo
$MKGRA stmtperfunc.g $LOC_DIA_DIR/fdefinfo

if [ $GEN_DATA == 1 ]; then
   zcat *$MET_SUFF | awk -f arginfo.awk > $LOC_DIA_DIR/arginfo
   fi
$MKGRA numargs.g $LOC_DIA_DIR/arginfo

if [ $GEN_DATA == 1 ]; then
   zcat *$MET_SUFF | awk -f objuse.awk > $LOC_DIA_DIR/objuse
   fi
#$MKGRA totobjref.g $LOC_DIA_DIR/objuse
$MKGRA totobjuse.g $LOC_DIA_DIR/objuse
$MKGRA indobjuse.g $LOC_DIA_DIR/objuse
$MKGRA unrefed.g $LOC_DIA_DIR/objuse

if [ $GEN_DATA == 1 ]; then
   zcat *$MET_SUFF | awk -f gotos.awk > $LOC_DIA_DIR/goto
   fi
$MKGRA gotodist.g $LOC_DIA_DIR/goto
$MKGRA gotoscope.g $LOC_DIA_DIR/goto

$MKGRA obj_init.g $LOC_TAB_DIR/init

if [ $GEN_DATA == 1 ]; then
   zcat *$MET_SUFF | awk -f calluse.awk > $LOC_DIA_DIR/calluse
   fi
$MKGRA calluse.g $LOC_DIA_DIR/calluse

if [ $GEN_DATA == 1 ]; then
   zcat *$MET_SUFF | awk -f scope.awk > $LOC_DIA_DIR/scope
   fi
$MKGRA scopelines.g $LOC_DIA_DIR/scope

