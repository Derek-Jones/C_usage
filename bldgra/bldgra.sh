# bldgra.sh,  9 Jul 03

source ../config.files

gra_ht=1.5             ; export gra_ht
gra_wid=2.2            ; export gra_wid
gra_prelude=".ps 8"    ; export gra_prelude
gra_date=`date`        ; export gra_date

echo "Building .gra and .d (.dh) files"

g_files="*.g"

if [ $# -gt 0 ]
   then
   g_files="$1"
   fi

if [ $# -gt 1 ]
   then
   C_CNT_FILE="$2"
   H_CNT_FILE=""
   fi
if [ $# -gt 2 ]
   then
   H_CNT_FILE="$3"
   fi

for f in $g_files
   do
echo "$f"
   name_prefix=`basename $f .g`
# get names of the copy files
   awk -f $BLD_GRA_DIR/getcopyf.awk < $f > $TEMP_FILE
   echo "0" > $MAX_DEC
# extract the values for all the referenced .d files
   for tf in `cat $TEMP_FILE`
      do
      if test ${tf##*.} = "d"
      then
         d_file=$tf
	 DATA_FILE="$C_CNT_FILE"
      elif test ${tf##*.} = "dh"
      then
         d_file=`basename $tf .dh`".d"
         DATA_FILE="$H_CNT_FILE"
      else
	 echo "Unsupported kind of count file $DATA_FILE"
      fi
      awk -v MAX_FILE="$MAX_DEC" -v d_file=$d_file -f $BLD_GRA_DIR/get_d.awk < $DATA_FILE > $GLOB_DIA_DIR/$tf
#echo "$DATA_FILE $tf"
#cat $MAX_DEC
      done
#cat $TEMP_FILE

# now build the .gra file
   awk -v maxy=`cat $MAX_DEC` -f $BLD_GRA_DIR/bldgra.awk < $f > $GLOB_DIA_DIR/${name_prefix}.gra
   done

#cat $TEMP_FILE
rm $TEMP_FILE $MAX_DEC

