# punctfreq.awk, 13 Jul 03
#
# punctuator frequencies

BEGIN {
	in_punct=0
	}

$2 ~ /tokcnt.d/ {
	in_data_freq=1
	next
	}

$1 ~ /End/ {
	if (in_data_freq == 1)
	   exit
	next
	}

	{
	if (in_data_freq == 1) {
	   if ($1 == "(")
	      in_punct=1
	   if ($1 == "IDENT")
	      in_punct=0
	   if ((in_punct == 1) || ($1 == "##") || ($1 == "#") || ($1 == ":c"))
	      print " " $1 " ,, " $2
	   }
	next
	}

END {
    }

