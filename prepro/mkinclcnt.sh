# mkinclcnt.sh, 25 Sep 25
#
# Count #include usage information

source ../config.files

if [ $INDIV_PROG = "all" ] || [ $INDIV_PROG = "ALL" ]; then
   echo "Extracting #include counts for single programs"
   for f in $PP_DIR/*$C_DIRECT_SUFF
      do
      echo $f
      prog_name=`basename $f $C_DIRECT_SUFF`
      zcat $f | awk -f numincl.awk > $LOC_DIA_DIR/${prog_name}.incl.cnt
      done
   fi

zcat $PP_DIR/*$C_DIRECT_SUFF | awk -f numincl.awk > $LOC_DIA_DIR/all.incl.cnt

