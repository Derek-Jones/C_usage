#
# std_ident.sh, 25 Sep 25

source ../config.files

WORD_LIST="std_ident.txt.gz"

if [ $INDIV_PROG = "all" ] || [ $INDIV_PROG = "ALL" ]; then
   for f in *.id.gz
      do
      echo $f
      prog_name=`basename $f .id.gz`
      zcat $WORD_LIST $f | awk -f std_ident.awk > ${prog_name}.stdid
      done
   fi

zcat $WORD_LIST *.id.gz | awk -f std_ident.awk > all_prog.stdid

