#
# get_opcnts.sh,  8 Jan 08

source ../config.files

if [ "$1" == "all" ]
then
#   echo -n "" > all.opcnt
#   for f in $SRC_DIR
#      do
#      echo "File: $f" >> all.opcnt
#      find $f -follow -name "*.c" -exec $NGRAM_DIR/findexec.sh {} \; | parcnt opcnt >> all.opcnt
#      done
   find $PROG_DIR -follow -name "*.c" -exec $NGRAM_DIR/findexec.sh {} \; | parcnt opcnt > all.opcnt
else
   for f in $SRC_DIR
      do
      echo $f
      prog_name=`basename $f`
      find $f -follow -name "*.c" -exec $NGRAM_DIR/findexec.sh {} \; | parcnt opcnt > $prog_name.opcnt
      done
fi

