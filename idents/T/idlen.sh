#
# idlen.sh,  8 Jul 03

for f in *.id.gz
   do
   echo $f
   prog_name=`basename $f .id.gz`
   gzcat $f | awk -f idlen.awk > ${prog_name}.len
   done

