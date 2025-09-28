#
# getstrlit.sh, 13 Jul 03

source ../config.files

for f in $SRC_DIR
   do
   echo $f
   prog_name=`basename $f`
   find $f -follow -name "*.c" -exec $NGRAM_DIR/findexec.sh {} \; | $NGRAM_DIR/ngram strlit | gzip --stdout > ${prog_name}.str.gz
   done

