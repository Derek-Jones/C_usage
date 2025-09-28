# lcv.awk, 29 Mar 03
#
# Count number of loop control variable
#

function print_lcv()
{
for (l in lcv_id) {
   print l
   }
}

BEGIN {
	FS=" ; "
	max_lcv=0
	}

	{
	gsub(/FOR /, "", $0)
	gsub(/INT_CONST /, "", $0)
	gsub(/amp; /, "", $0)
	gsub(/comma; /, "", $0)
	gsub(/NEW_LINE /, "", $0)
	gsub(/[_a-zA-Z0-9]+ \(/, "", $0)
	gsub(/[_a-zA-Z0-9]+ ->/, "", $0)
	gsub(/[_a-zA-Z0-9]+ \./, "", $0)
	split($1, init, " ")
	split($2, cntrl, " ")
	split($3, increment, " ")
	lcv_count=0
	for (lcv in cntrl) {
	   if (cntrl[lcv] ~ /[_a-zA-Z0-9]+/) {
	      lcv_count++
	      lcv_id[cntrl[lcv]]=1
	      }
	   }
	cntrl_lcv[lcv_count]++
	if (lcv_count > max_lcv) {
	   max_lcv=lcv_count
	}
	lcv_count=0
	for (lcv in increment) {
	   if ((lcv_id[increment[lcv]] == 1) && (increment[lcv] ~ /[_a-zA-Z0-9]+/)) {
	      lcv_count++
	      lcv_id[increment[lcv]]=2
	      }
	   }
	increment_lcv[lcv_count]++
	lcv_count=0
	for (lcv in init) {
	   if ((lcv_id[init[lcv]] == 2) && (init[lcv] ~ /[_a-zA-Z0-9]+/)) {
	      lcv_count++
	      # for when the same identifier occurs more than once
	      lcv_id[init[lcv]]=3
	      }
	   }
	init_lcv[lcv_count]++
	delete lcv_id
	next
	}

END {
	print "File: lcvcntrl.d"
	for (lcv=0; lcv < max_lcv; lcv++) {
	   print lcv " " 0+cntrl_lcv[lcv]
	   }
	print "End File"
	print "File: lcvinc.d"
	for (lcv=0; lcv < max_lcv; lcv++) {
	   print lcv " " 0+increment_lcv[lcv]
	   }
	print "End File"
	print "File: lcvinit.d"
	for (lcv=0; lcv < max_lcv; lcv++) {
	   print lcv " " 0+init_lcv[lcv]
	   }
	print "End File"
    }

