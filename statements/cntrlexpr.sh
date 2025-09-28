#
# cntrlexpr.sh, 25 Sep 25

source ../config.files

if [ $INDIV_PROG = "all" ] || [ $INDIV_PROG = "ALL" ]; then
   for f in *$CNTRL_SUFF
      do
      echo $f
      prog_name=`basename $f $CNTRL_SUFF`
      zcat $f | awk -f cntrlexpr.awk > ${prog_name}.cntrl.t
      done
   fi

zcat *$CNTRL_SUFF | awk -f cntrlexpr.awk > $ALLCNTRL_LINES

