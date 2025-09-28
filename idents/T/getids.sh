#
# getids.sh,  8 Jul 03

SRC_DIR="../programs"
BIN_DIR=".."

for f in $SRC_DIR
   do
   echo $f
   prog_name=`basename $f`
   find $f -follow -name "*.c" -exec $BIN_DIR/findexec.sh {} \; | $BIN_DIR/ngram idents | gzip --stdout > ${prog_name}.id.gz
   done

