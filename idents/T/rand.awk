
   {
   num_seen++
   r_and[num_seen "_" rand()]=$1
   next
   }

END {
   for (r in r_and) {
      print r_and[r]
      }
    }

