#
# mkxml.sh, 13 Jul 03

SRC_DIR="temp/*"

for f in $SRC_DIR
   do
   echo $f
   awk -f mkxml.awk < $f > $f.t
   done

