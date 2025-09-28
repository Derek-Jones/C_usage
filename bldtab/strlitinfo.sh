#
# strlitinfo.sh, 25 Sep 25

for f in *.str.gz
   do
   prog_name=`basename $f .str.gz`
   echo ${prog_name%%-*}
   zcat $f | wc
   zcat $f | sort -u | wc
   done

echo "prog_all"
zcat *.str.gz | wc
zcat *.str.gz | sort -u | wc

