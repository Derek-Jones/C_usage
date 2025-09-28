#
# getblock.sh,  9 Mar 08

source ../config.files

if [ "$1" == "all" ]
then
#   echo -n "" > all.rules
#   for f in $SRC_DIR
#      do
#      echo "File: $f" >> all.rules
#      find $f -follow -name "*.c" -exec $NGRAM_DIR/findexec.sh {} \; | parcnt rulecount >> all.rules
#      done
   find $PROG_DIR -follow -name "*.c" -exec $NGRAM_DIR/findexec.sh {} \; | parcnt block $2 > all.block
else
   for f in $SRC_DIR
      do
      echo $f
      prog_name=`basename $f`
#   find $f -follow -name "*.h" -exec $NGRAM_DIR/findexec.sh {} \; | $NGRAM_DIR/ngram block | gzip --stdout > ${prog_name}.h.block.gz
      find $f -follow -name "*.c" -exec $NGRAM_DIR/findexec.sh {} \; | parcnt block | gzip --stdout > ${prog_name}.c.block.gz
      done
fi

