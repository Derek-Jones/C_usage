# mkgra.sh, 25 Sep 25
#
# Top level coordinator to graph template building

source ../config.files

#GEN_DATA="1"

$MKGRA hashindent.g $C_CNT_FILE $H_CNT_FILE
$MKGRA incdefline.g $C_CNT_FILE $H_CNT_FILE

if [ $GEN_DATA == 1 ]; then
   zcat $PP_DIR/*$C_DIRECT_SUFF | awk -f numincl.awk > $LOC_DIA_DIR/all.incl.cnt
   fi
$MKGRA numincl.g $LOC_DIA_DIR/all.incl.cnt
$MKGRA samehdrname.g $LOC_DIA_DIR/all.incl.cnt

if [ $GEN_DATA == 1 ]; then
   zcat $PP_DIR/*$C_BODY_SUFF | awk -f mdefparam.awk > $LOC_DIA_DIR/mdefparam
   zcat $PP_DIR/*$H_BODY_SUFF | awk -f mdefparam.awk > $LOC_DIA_DIR/mdefparam.h
   fi
$MKGRA mdefparam.g $LOC_DIA_DIR/mdefparam $LOC_DIA_DIR/mdefparam.h

if [ $GEN_DATA == 1 ]; then
   zcat $PP_DIR/*$C_DIRECT_SUFF | awk -f define.awk > $LOC_DIA_DIR/define_ids
   zcat $PP_DIR/*$H_DIRECT_SUFF | awk -f define.awk > $LOC_DIA_DIR/define_ids.h
   fi
$MKGRA numdefine.g $LOC_DIA_DIR/define_ids $LOC_DIA_DIR/define_ids.h

if [ $GEN_DATA == 1 ]; then
   zcat $PP_DIR/*$C_DIRECT_SUFF | awk -f ifnest.awk > $LOC_DIA_DIR/ifnest
   zcat $PP_DIR/*$H_DIRECT_SUFF | awk -f ifnest.awk > $LOC_DIA_DIR/ifnest.h
   fi
$MKGRA ppifnest.g $LOC_DIA_DIR/ifnest $LOC_DIA_DIR/ifnest.h

