#
# cntids.sh, 25 Sep 25

source ../config.files

INDIV_PROG="all"

if [ $INDIV_PROG = "all" ] || [ $INDIV_PROG = "ALL" ]; then
   for f in *.id.gz
      do
      echo $f
      prog_name=`basename $f .id.gz`
      zcat $f | awk -f cntids.awk > ${prog_name}.cnt
      done
   fi

#zcat *.id.gz | awk -f cntids.awk > all_prog.cnt

