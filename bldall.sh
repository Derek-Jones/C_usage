#
# bldall.sh, 27 Sep 25

gcc ngram.c -o ngram

gcc 242.c -o 242
cp 242 idents/.
cp 242 prepro/.
cp 242 statements/.
cp 242 decl/.
cp 242 tables/.
cp 242 bldtab/.

mkdir tables/temp

exit 0

# Runs the proprietary tools

for f in *
   do
   if [ -d $f -a -f $f/bldall.sh ];
      then
      (cd $f ; ./bldall.sh)
      fi
   done

