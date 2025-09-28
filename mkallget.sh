# mkallget.sh, 25 Sep 25

for f in *
   do
   if [ -d $f -a -f $f/getall.sh ];
      then
      echo "Directory $f"
      (cd $f ; ./getall.sh)
      fi
   done

