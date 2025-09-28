# getcopyf.awk,  7 Jul 03
# used by bldgra.sh

BEGIN {
   }

$1 ~ /^copy$/ {
   if ($2 != "thru")
      print substr($2, 2, length($2)-2) # there is a " on the end
   next
   }

   {
   next
   }

