# mkallgra.sh, 17 Feb 05

for f in *
   do
   if [ -d $f -a -f $f/mkgra.sh ];
      then
      echo "Directory $f"
      (cd $f ; ./mkgra.sh)
      fi
   done

