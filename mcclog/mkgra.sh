#
# mkgra.sh, 28 Sep 25
#
# Top level coordinator to graph template building

source ../config.files

#GEN_DATA="1"

if [ $GEN_DATA == 1 ]; then
   xzcat *.mcc.xz | awk -f incl.awk > $LOC_DIA_DIR/unnecincl
   fi
$MKGRA unnecincl.g $LOC_DIA_DIR/unnecincl

if [ $GEN_DATA == 1 ]; then
   xzcat *.mcc.xz | awk -f ecvals.awk > $LOC_DIA_DIR/ecvals
   fi
$MKGRA ecvals.g $LOC_DIA_DIR/ecvals

if [ $GEN_DATA == 1 ]; then
   xzcat *.mcc.xz | awk -f skipif.awk > $LOC_DIA_DIR/skipif
   fi
$MKGRA skipif.g $LOC_DIA_DIR/skipif

if [ $GEN_DATA == 1 ]; then
   xzcat *.mcc.xz | awk -f bitfield.awk > $LOC_DIA_DIR/bitfield
   fi
$MKGRA bitwidth.g $LOC_DIA_DIR/bitfield

if [ $GEN_DATA == 1 ]; then
   xzcat *.mcc.xz | awk -f macexargs.awk > $LOC_DIA_DIR/macexargs
   fi
$MKGRA macexargs.g $LOC_DIA_DIR/macexargs
$MKGRA macexpand.g $LOC_DIA_DIR/macexargs
$MKGRA macdefs.g $LOC_DIA_DIR/macexargs

$MKGRA caseden.g $LOC_TAB_DIR/switch

if [ $GEN_DATA == 1 ]; then
   xzcat *.mcc.xz | awk -f elements.awk > $LOC_DIA_DIR/elements
   fi
$MKGRA elements.g $LOC_DIA_DIR/elements

