#
# idlen.sh, 25 Sep 25

WORD_LIST="words.65.gz"

if [ $INDIV_PROG = "all" ] || [ $INDIV_PROG = "ALL" ]; then
   for f in *.id.gz
      do
      echo $f
      prog_name=`basename $f .id.gz`
      zcat $WORD_LIST $f | awk -f idlen.awk > ${prog_name}.len
      done
   fi

zcat $WORD_LIST *.id.gz | awk -f idlen.awk > all_prog.len

