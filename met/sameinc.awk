# sameinc.awk,  8 Sep 07

BEGIN {
	first_file=1
	num_files=0
	num_files_chk=0
	}

function sum_inc_counts()
{
for (f in all_included_file)
   times_all_included[all_included_file[f]]++
for (f in usr_included_file)
   times_usr_included[usr_included_file[f]]++
for (f in usr_n_1_included_file)
   times_usr_n_1_included[usr_n_1_included_file[f]]++
for (f in usr_n_3_included_file)
   times_usr_n_3_included[usr_n_3_included_file[f]]++
delete all_included_file
delete usr_included_file
delete usr_n_1_included_file
delete usr_n_3_included_file
}

$1 == ".INCLUDED" {
        all_included_file[$2]++
	next
	}

$1 == ".START" {
	start_nesting++;
	last_was_start=1
	nest_start_file[start_nesting]=$2
        usr_included_file[$2]++
        if (start_nesting > 1)
	   usr_n_1_included_file[$2]++
        if (start_nesting > 3)
	   usr_n_3_included_file[$2]++
        next
	}

$1 == ".END" {
	if (NF != 1) {
	   #
	   # File names can be different because of the appearance of
	   # #line directives in the source
	   if ($2 != nest_start_file[start_nesting]) {
	      #print ".START " nest_start_file[start_nesting] " .END " $2
	      }
	   if (start_nesting == 0) {
	      #print "<<<<<< negative .START/.END nesting: " $2
	      }
	   start_nesting--
	   }
	next
	}

$1 == ".FILE" {
	if (!first_file)
	   sum_inc_counts()
	first_file=0
	start_nesting=0
	num_files++
        next
	}

	{
	next
	}

END {
	if (!first_file)
	   sum_inc_counts()
	TEMP_FILE="Temp." systime()
	printf("") > TEMP_FILE

	for (i in times_all_included)
	   printf("%2d %9d %9d %9d %9d\n", i, times_usr_included[i], times_usr_n_1_included[i], times_usr_n_3_included[i], times_all_included[i]) >> TEMP_FILE
	close(TEMP_FILE)
	print num_files
	print "File: sameinc.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	system("rm " TEMP_FILE)
	}

