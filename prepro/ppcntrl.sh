#
# ppcntrl.sh, 25 Sep 25
 
source ../config.files

if [ $INDIV_PROG = "all" ] || [ $INDIV_PROG = "ALL" ]; then
   for f in *$C_BODY_SUFF
      do
      echo $f
      prog_name=`basename $f $C_BODY_SUFF`
      zcat $f | awk -f ppcntrl.awk > ${prog_name}.ppbody.t
      done
   fi

zcat *$C_BODY_SUFF | awk -f ppcntrl.awk > $PPALLCNTRL_LINES

