#
# getcntrl.sh, 17 Feb 05

source ../config.files

for f in $SRC_DIR
   do
   echo $f
   prog_name=`basename $f`
   find $f -follow -name "*.c" -exec $NGRAM_DIR/findexec.sh {} \; | $NGRAM_DIR/ngram control | gzip --stdout > ${prog_name}$CNTRL_SUFF
   done

