# directopid.awk, 17 Jul 03
#
# preprocessor directives


function print_data()
{
#print num_pp_opid
orig_pp_opid=num_pp_opid
for (pp in pp_opid)
   if ((pp != "#") &&
       (pp != "##") &&
       (pp != "DEFINED"))
      num_pp_opid-=pp_opid[pp]
pp_opid["#"]-=(orig_pp_opid-num_pp_opid)
for (pp in pp_opid)
   printf("%s %2.1f\n", pp, 100*(pp_opid[pp]/num_pp_opid))
exit
}


BEGIN {
	}

$2 == "tokcnt.d" {
	in_data_freq=1
	next
	}

$1 == "End" {
	if (in_data_freq == 1) {
	   print_data()
	}
	next
	}

        {
	if (in_data_freq == 1) {
	   if (($1 ~ /^#/) ||
	       ($1 == "DEFINED")) {
	      num_pp_opid+=$NF
	      pp_opid[$1]=$NF
	      }
	}
	next
	}

END {
    }

