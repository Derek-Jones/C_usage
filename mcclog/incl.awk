# incl.awk, 18 Dec 03
#

function end_trans_unit()
{
tu_unnec_incl[num_unnec_incl]++
num_unnec_incl=0
}

BEGIN {
   num_unnec_incl=0
   }

# Contents of <string.h> not referenced within source
$3 == "(1734)" {
   num_unnec_incl++
   u_incl_name[$6]++
   next
   }

# Contents of "dev.h" not referenced within source
$3 == "(1735)" {
   num_unnec_incl++
   u_incl_name[$6]++
   next
   }

# File has already been included at top level
$3 == "(1736)" {
   next
   }

$2 == "produced" {
	end_trans_unit()
	next
	}

   {
   next
   }

END {
	TEMP_FILE="ui" systime()
	printf("") > TEMP_FILE
	for (i in tu_unnec_incl)
	   print i " " tu_unnec_incl[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: unnecincl.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	for (i in u_incl_name)
	   print i " " u_incl_name[i]
	
	system("rm " TEMP_FILE)
	}

