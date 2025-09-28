# releqcnt.awk, 17 Jul 03
#
# operator related keywords


BEGIN {
	}

$2 == "tokcnt.d" {
	in_data_freq=1
	next
	}

$1 == "End" {
	if (in_data_freq == 1) {
	   print num_eq " " num_ne " " num_lt " " num_le " " num_gt " " num_ge " " num_or " " num_and
	   exit
	}
	next
	}

        {
	if (in_data_freq == 1) {
	   if ($1 == "==")
	      num_eq=$4
	   if ($1 == "!=")
	      num_ne=$4
	   if ($1 == "<")
	      num_lt=$4
	   if ($1 == "<=")
	      num_le=$4
	   if ($1 == ">")
	      num_gt=$4
	   if ($1 == ">=")
	      num_ge=$4
	   if ($1 == "||")
	      num_or=$4
	   if ($1 == "&&")
	      num_and=$4
	}
	next
	}

END {
    }

