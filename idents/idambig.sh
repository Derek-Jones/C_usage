#
# idambig.sh, 25 Sep 25

source ../config.files

if [ $INDIV_PROG = "all" ] || [ $INDIV_PROG = "ALL" ]; then
   for f in *.id.gz
      do
      echo $f
      prog_name=`basename $f .id.gz`
      out_file="${prog_name}.amb"
      zcat $f | sort -u | $NGRAM_DIR/wordambig > ${prog_name}.amb
      zcat $f | awk -f undersplit.awk | $NGRAM_DIR/wordambig > ${prog_name}.umb
      done
   fi

