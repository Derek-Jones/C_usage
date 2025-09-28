#
# getids.sh,  8 Jul 03

source ../config.files

for f in $SRC_DIR
   do
   echo $f
   prog_name=`basename $f`
   find $f -follow -name "*.c" -exec $NGRAM_DIR/findexec.sh {} \; | $NGRAM_DIR/ngram idents | gzip --stdout > ${prog_name}.c.id.gz
   find $f -follow -name "*.h" -exec $NGRAM_DIR/findexec.sh {} \; | $NGRAM_DIR/ngram idents | gzip --stdout > ${prog_name}.h.id.gz
   done

