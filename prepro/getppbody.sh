#
# getppbody.sh,  8 Jul 03

source ../config.files

SRC_DIR="../programs/*"

for f in $SRC_DIR
   do
   echo $f
   prog_name=`basename $f`
   find $f -follow -name "*.c" -exec $NGRAM_DIR/findexec.sh {} \; | $NGRAM_DIR/ngram ppbody | gzip --stdout > ${prog_name}.c.ppbody.gz
   find $f -follow -name "*.h" -exec $NGRAM_DIR/findexec.sh {} \; | $NGRAM_DIR/ngram ppbody | gzip --stdout > ${prog_name}.h.ppbody.gz
   done

