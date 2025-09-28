# mkalltab.sh, 17 Feb 05

for f in *
   do
   if [ -d $f -a -f $f/mktab.sh ];
      then
      echo "Directory $f"
      (cd $f ; ./mktab.sh)
      fi
   done

