#
# getresid.sh, 28 Sep 25

source ../config.files

for f in *.mcc.xz
   do
   echo $f
   prog_name=`basename $f .mcc.xz`
   xzcat $f | awk -f getresid.awk | awk -f resid.awk > ${prog_name}.resid
   done

