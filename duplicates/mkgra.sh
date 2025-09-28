# mkgra.sh, 25 Jan 04
#
# Top level coordinator to graph template building

source ../config.files

if [ $GEN_DATA == 1 ]; then
   cat *.dup | awk -f dups.awk > $LOC_DIA_DIR/dups
   fi
$MKGRA duplines.g $LOC_DIA_DIR/dups

