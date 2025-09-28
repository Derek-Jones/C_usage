# mkps.sh, 20 Dec 07

#GROFF="/usr/bin/groff -Tps"
GROFF="/usr/bin/groff -P-b16 -Tps"

echo ".gra"

for f in *.gra
   do
   filename=`basename $f .gra`
   grap $f | $GROFF -p > $filename.ps
   done

