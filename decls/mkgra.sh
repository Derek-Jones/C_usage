# mkgra.sh, 25 Sep 25
#
# Top level coordinator to graph template building

source ../config.files

#GEN_DATA="1"

if [ $GEN_DATA == 1 ]; then
   zcat *.c.enum.gz | awk -f enum.awk > $LOC_DIA_DIR/econst.c
   zcat *.h.enum.gz | awk -f enum.awk > $LOC_DIA_DIR/econst.h
   fi
$MKGRA econst.g $LOC_DIA_DIR/econst.c $LOC_DIA_DIR/econst.h

if [ $GEN_DATA == 1 ]; then
   zcat *.c.decl.gz | awk -f esutag.awk > $LOC_DIA_DIR/esutag.c
   zcat *.h.decl.gz | awk -f esutag.awk > $LOC_DIA_DIR/esutag.h
   fi
$MKGRA esutag.g $LOC_DIA_DIR/esutag.c $LOC_DIA_DIR/esutag.h

