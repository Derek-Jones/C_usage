# numlabels.awk,  4 Aug 03

$1 == ".METRICS" {
	in_metrics=1
	next
	}

$1 == ".FUNC" {
	num_funcs++
	next
	}

$1 ~ /^\./ {
	in_metrics=0
	next
	}

	{
	if ((in_metrics == 1) && (index($0, "LABELS ") != 0))
	   {
	   in_metrics=0
	   for (i=1; i <= NF; i++)
	      if ($i == "LABELS") {
	         num_labels[$(i+1)]++
		 next
		 }
	   }
	next
	}

END {
	TEMP_FILE="TeMp.tEmP"
	printf("") > TEMP_FILE
	for (i in num_labels)
	   if (100*(num_labels[i]/num_funcs) >= 0.1)
	      printf("%d ,, %2.1f\n", i, 100*(num_labels[i]/num_funcs)) >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)

	system("rm " TEMP_FILE)
	}

