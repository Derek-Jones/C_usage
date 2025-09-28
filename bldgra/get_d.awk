# get_d.awk,  7 Jul 03
# used by bldgra.sh

# Write the largest value from the last column of
# the input to the file max_dec_valu.  Use any value
# currently in that file as the starting maximum.

BEGIN {
   getline max_dec_valu < MAX_FILE
#print "max dec valu " max_dec_valu
#print d_file
   }

function after_last_line()
{
#print "max dec valu " max_dec_valu
print max_dec_valu > MAX_FILE
exit
}

$2 ~ d_file {
   copy_line=1
   next
   }

/End File/ {
   if (copy_line == 1) {
      after_last_line()
      }
   next
   }

   {
   if (copy_line == 1) {
      if ($NF > max_dec_valu) {
         max_dec_valu=$NF
	 }
      for (i=2; i <= NF; i++) {
         if ($i == 0) $i="0.01"
	 }
      print $0
      }
   next
   }

