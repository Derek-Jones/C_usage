# arginfo.awk,  1 Aug 03

BEGIN {
	
	}

$1 == ".CALL" {
	num_args=NF-4
	arg_count[num_args]++
	next
	}

	{
	next
	}

END {
	TEMP_FILE="ca" systime()
        printf("") > TEMP_FILE
        for (i in arg_count)
           print i " " arg_count[i] >> TEMP_FILE
        close(TEMP_FILE)
        print "File: arg_count.d"
        system("sort -g < " TEMP_FILE)
        print "End File"

        system("rm " TEMP_FILE)
	}

