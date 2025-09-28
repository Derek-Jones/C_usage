# incnest.awk, 29 Sep 02

$1 == ".INCLUDED" {
	next
	}

$1 == ".START" {
	start_nesting++;
	last_was_start=1
	start_file[start_nesting]=$2
	next
	}

$1 == ".END" {
	if (NF != 1) {
	   #
	   # File names can be different because of the appearance of
	   # #line directives in the source
	   if ($2 != start_file[start_nesting]) {
	      #print ".START " start_file[start_nesting] " .END " $2
	      }
	   if (last_was_start) {
	      max_inc_nesting[start_nesting]++
	      }
	   last_was_start=0
	   if (start_nesting == 0) {
	      #print "<<<<<< negative .START/.END nesting: " $2
	      }
	   start_nesting--
	   }
	next
	}

$1 == ".FILE" {
	if (start_nesting != 0) {
	   #print "<<<<<< positive .START/.END nesting: " $2 ", level: " start_nesting
	   }
	start_nesting=0
	next
	}

	{
	next
	}

END {
	TEMP_FILE="TeMp.tEmP"
	printf("") > TEMP_FILE

	for (i in max_inc_nesting)
	   print i " " max_inc_nesting[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: incnest.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	system("rm " TEMP_FILE)
	}

