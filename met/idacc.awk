# idacc.awk, 29 Jul 03
# Needs more info in the .met file

function sum_func_info()
{
}

$1 == ".ACC" {
	next
	}

$1 == ".MOD" {
	next
	}

$1 == ".ARG" {
	num_args++
	next
	}

$1 == ".LOCAL" {
	if ($11 == "IDENT") {
	   num_local_ids++
	   if ($12 != "econst") {
	      num_objs++
	      }
	   }
	next
	}

$1 == ".FILE" {
	next
	}

$1 == ".FUNC" {
	in_func=1
	num_args=0
	num_locals=0
	all_arg_size=0
	all_local_size=0
	next
	}

$1 == ".START" {
	next
	}

$1 == ".END" {
	if (in_func == 1)
	   sum_func_info()
	in_func=0
	next
	}

	{
	next
	}

END {
	TEMP_FILE="TeMp.tEmP"
	printf("") > TEMP_FILE
	for (i in scope_info)
	   print i-1 " " scope_info[i] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: locscope.d"
	system("sort -g < " TEMP_FILE)
	print "End File"

	system("rm " TEMP_FILE)
	}

