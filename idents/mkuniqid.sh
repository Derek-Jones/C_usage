#
# mkuniqid.sh, 25 Sep 25

INDIV_PROG="all"

if [ $INDIV_PROG = "all" ] || [ $INDIV_PROG = "ALL" ]; then
   for f in *.c.id.gz *.h.id.gz
      do
      echo $f
      prog_name=`basename $f .id.gz`
      zcat $f | sort -u > ${prog_name}.uniq
      done
   fi

zcat *.c.id.gz | sort -u > all_prog.c.uniq
zcat *.h.id.gz | sort -u > all_prog.h.uniq

