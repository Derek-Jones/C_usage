#
# funcseq.awk, 13 Mar 05

$6 == "FD" {
	total_fd=$7
	print $0
	next
	}
	
$1 == ".." {
	for (i=2; i <= 6; i++)
	   if ($i == "FD") 
	      {
	      fd_seq="FD"
	      if ($7/total_fd > 0.001)
	         {
		 for (j=i+1; j <= 6; j++)
	            fd_seq=fd_seq " " $j
	         fd_seq=fd_seq " " int(1000*($7/total_fd))
	         all_fd_seq[fd_seq]=i
		 }
	      else
	         total_skipped[i]+=$7
	      next
	      }
	next
	}

$1 == "FD" {
	fd_seq="FD"
	if ((NF == 7) && ($7/total_fd > 0.01))
	   {
	   for (j=2; j <= 6; j++)
	       fd_seq=fd_seq " " $j
	   fd_seq=fd_seq " " int(1000*($7/total_fd))
	   all_fd_seq[fd_seq]=1
	   }
	else
	   total_skipped[1]+=$7
	next
	}

	{
	next
	}

END {
	TEMP_FILE="dy" systime()
	
	print "Total skipped "
	for (i=5; i != 0; i--)
	   printf("%d %6d %5.2f\n", i, total_skipped[i], 100*(total_skipped[i]/total_fd))
	printf("") > TEMP_FILE
	for (fs in all_fd_seq)
	   print all_fd_seq[fs] " " fs >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -gr -k1 < " TEMP_FILE)
	
	system("rm " TEMP_FILE)
	}

