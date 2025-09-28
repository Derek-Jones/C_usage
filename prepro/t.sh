# mkgra.sh, 25 Sep 25
#
# Top level coordinator to graph template building

source ../config.files

#GEN_DATA="1"

if [ $GEN_DATA == 1 ]; then
   zcat $PP_DIR/*$C_DIRECT_SUFF | awk -f ifnest.awk > $LOC_DIA_DIR/ifnest
   zcat $PP_DIR/*$H_DIRECT_SUFF | awk -f ifnest.awk > $LOC_DIA_DIR/ifnest.h
   fi
$MKGRA ppifnest.g $LOC_DIA_DIR/ifnest $LOC_DIA_DIR/ifnest.h

