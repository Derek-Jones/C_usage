# mkps.sh, 25 Sep 25


GROFF="/usr/bin/groff -Tps"
   
for f in *.gra
   do
   filename=`basename $f .gra`
   grap $f | groff -p -P-b16 -Tps > ps/$filename.ps
#   grap $f | $GROFF -p > ps/$filename.ps
   ./bndpdf.sh ps/$filename.ps > ps/$filename.pdf
   done

