#
# shareid.sh, 12 Oct 07
#
# Count the number of identifiers shared by each pair of source
# code bases.  Output shared as percentage of all identifiers.

SHARE_FILE="shareid.t"

for col in *c.uniq
   do
   prog_name=`basename $col .c.uniq`
   echo -n " ,, " ${prog_name%%-*}
   done
echo ""
echo "NEW-LINE"
for col in *c.uniq
   do
   echo -n " ,, `wc -l < $col`"
   done
echo ""
echo "NEW-LINE"

for row in *c.uniq
   do
   prog_name=`basename $row .c.uniq`
   echo ${prog_name%%-*}
   row_lines=`wc -l < $row`
   for col in *.c.uniq
      do
      if test $row == $col
      then
         echo "--"
      else
         total_same=`join $row $col | wc -l`
# Rounding (rather than truncation) is acheived by adding in total_same/5 
# which is the equivalent effect of adding 0.5
	 expr \( \( $total_same \* 100 \) + \( $total_same \/ 5 \) \) \/ $row_lines
      fi
      done
   echo "NEW-LINE"
   done

