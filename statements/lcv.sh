#
# lcv.sh, 25 Sep 25

source ../config.files

if [ $INDIV_PROG = "all" ] || [ $INDIV_PROG = "ALL" ]; then
   for f in *$FOR_SUFF
      do
      echo $f
      prog_name=`basename $f $FOR_SUFF`
      zcat $f | awk -f lcv.awk > ${prog_name}.lcv.d
      done
   fi

zcat *$FOR_SUFF | awk -f lcv.awk > $LOC_DIA_DIR/all_prog.lcv.d

