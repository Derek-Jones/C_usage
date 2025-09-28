#
# fullexpr.sh, 27 Dec 07

source ../config.files

if [ "$1" == "all" ]
then
#   echo -n "" > all.rules
#   for f in $SRC_DIR
#      do
#      echo "File: $f" >> all.rules
#      find $f -follow -name "*.c" -exec $NGRAM_DIR/findexec.sh {} \; | parcnt rulecount >> all.rules
#      done
   find $PROG_DIR -follow -name "*.c" -exec $NGRAM_DIR/findexec.sh {} \; | parcnt rulecount > all.rules
else
   for f in $SRC_DIR
      do
      echo $f
      prog_name=`basename $f`
      find $f -follow -name "*.c" -exec $NGRAM_DIR/findexec.sh {} \; | parcnt rulecount > $prog_name.rules
      done
fi

