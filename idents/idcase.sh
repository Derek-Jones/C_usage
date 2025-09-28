#
# idcase.sh, 25 Sep 25

source ../config.files

INDIV_PROG="all"

if [ $INDIV_PROG = "all" ] || [ $INDIV_PROG = "ALL" ]; then
   for f in *.id.gz
      do
      #echo $f
      prog_name=`basename $f .id.gz`
      zcat $f | awk -f idcase.awk > ${prog_name}.case
      cat $prog_name.uniq | awk -f idcase.awk >> ${prog_name}.case
      done
   fi

zcat *.id.gz | awk -f idcase.awk > all_prog.case
cat *.uniq | awk -f idcase.awk >> all_prog.case

echo > $TEMP_FILE

for f in *.c.case
   do
   prog_name=`basename $f .c.case`
   echo ${prog_name%%-*} >> $TEMP_FILE
   cat $f >> $TEMP_FILE
   done

awk -f idcase.mkt < $TEMP_FILE

rm $TEMP_FILE
