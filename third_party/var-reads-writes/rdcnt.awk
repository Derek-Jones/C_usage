BEGIN {
   zero_rds=0
   rd_total=0
}

function cnt_subrange(start, end)
{
rd_cnt=0
for (rd in cnt) {
   if ((rd >= start) && (rd <= end)) {
      rd_total+=cnt[rd]
      rd_cnt+=cnt[rd]
      }
   }
print start " " end " " rd_cnt
}

function cnt_range(start, inc, iterations)
{
for (ind=0; ind<iterations; ind++) {
   cnt_subrange(start+inc*ind, start+inc*(ind+1)-1)
   }
}

   {
   cnt[$3]++
   if ($3 == 0) {
      zero_rds++
      }
   next
   }

END {
    power=1
    for (t_ind=0; t_ind<9; t_ind++) {
       cnt_range(1*power, 1*power,  9)
       power=power*10
       }
    print "total reads=" rd_total ", zero reads=" zero_rds
   }

