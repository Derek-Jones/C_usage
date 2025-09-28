#
# get_binaryids.sh,  8 Jan 08

source ../config.files

if [ "$1" == "all" ]
then
   echo -n "" > all.bids
   for f in $SRC_DIR
      do
      echo "File: $f" >> all.bids
      find $f -follow -name "*.c" -exec $NGRAM_DIR/findexec.sh {} \; | parcnt dispexpr | awk -f scripts/binaryids.awk >> all.bids
      done
#   find $PROG_DIR -follow -name "*.c" -exec $NGRAM_DIR/findexec.sh {} \; | parcnt dispexpr | awk -f scripts/binaryids.awk | sort > all.bids
else
   for f in $SRC_DIR
      do
      echo $f
      prog_name=`basename $f`
      find $f -follow -name "*.c" -exec $NGRAM_DIR/findexec.sh {} \; | parcnt dispexpr | awk -f scripts/binaryids.awk | sort > $prog_name.bids
      done
fi

