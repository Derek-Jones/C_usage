#
# idzip.sh, 15 Jul 05

for f in *.cnt
   do
   echo $f
   id_name=idzip`echo  $f | cut -c -3`.d
   echo "File: $id_name"
   cut -d ' ' -f2 $f
   echo "End File"
   done

