#
# cntids.sh,  8 Jul 03

SRC_DIR="../programs"
BIN_DIR=".."

for f in *.id.gz
   do
   echo $f
   prog_name=`basename $f .id.gz`
   gzcat $f | awk -f cntids.awk | sort -rgk 2 > ${prog_name}.cnt
   done

