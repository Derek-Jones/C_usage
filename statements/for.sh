#
# for.sh, 25 Sep 25

source ../config.files

if [ $INDIV_PROG = "all" ] || [ $INDIV_PROG = "ALL" ]; then
   for f in *$CNTRL_SUFF
      do
      echo $f
      prog_name=`basename $f $CNTRL_SUFF`
      zcat $f | awk -f for.awk > ${prog_name}.for.t
      done
   fi

zcat *$CNTRL_SUFF | awk -f for.awk > $ALLFOR_LINES

