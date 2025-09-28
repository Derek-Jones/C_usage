# letfreq.awk,  9 Jul 03
#

BEGIN {
	}

	{
	total_lets+=$2
	letter[$1]=$2
	}

END {
    for (i in letter)
       printf("%c %2.2f\n", i, 100*(letter[i]/total_lets))
    }

