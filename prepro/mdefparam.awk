# mdefparam.awk, 20 Jul 03
#
# occurrences of defined

BEGIN {
	max_params=0
	}

$1 == "#DEFINE" &&
$2 == "FUNC_MAC" {
	num_params=0
	for (p=4; p <=NF; p++)
	   if ($p == "IDENT")
	      num_params++
	   else if ($p == ")") {
	      param_cnt[num_params]++
	      if (num_params > max_params) {
	         #print $0
		 max_params=num_params
		 }
	      next
	      }
	next
	}

	{
	next
	}

END {
    print "File: mdefparam.d"
    for (i=0; i <= max_params; i++)
       print i " " 0+param_cnt[i]
    print "End File"
    }

