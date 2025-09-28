#
# wordambig.sh,  8 Jul 03

SRC_DIR="../programs"
BIN_DIR=".."

for f in *.id.gz
   do
   echo $f
   prog_name=`basename $f .id.gz`
   out_file="${prog_name}.amb"
   gzcat $f | sort -u | $BIN_DIR/wordambig > ${prog_name}.amb
   gzcat $f | awk -f undersplit.awk | $BIN_DIR/wordambig > ${prog_name}.umb
   done

