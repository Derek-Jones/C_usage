# elemtype.awk, 24 Jul 02
#
# needs mkctype.awk

function decl_nest(obj_type)
{
if (index(obj_type, "array") == 1) {
   sub("array", "", obj_type)
   pr_type=""
   mk_pr_type(obj_type)
   num_elem_type[pr_type]++
   num_array_types++
   }
}

BEGIN {
	init_types()	
	}

$1 == ".ARG" {
	decl_nest($NF)
	next
	}

$1 == ".LOCAL" {
	if ($11 == "IDENT")
	   decl_nest($NF)
	next
	}

$1 == ".GLOBAL" {
	in_globals=1
	next
	}

$1 ~ /^\./ {
	in_globals=0
	next
	}

	{
	if ((in_globals == 1) && ($(NF-1) == "IDENT"))
	   decl_nest($NF)
	next
	}

END {
	TEMP_FILE="TeMp.tEmP"
	printf("") > TEMP_FILE
	other_types=0
	for (i in num_elem_type)
	   if (100*(num_elem_type[i]/num_array_types) > 1.0) {
	      printf("%s ,, %2.1f\n", i, 100*(num_elem_type[i]/num_array_types)) >> TEMP_FILE
	   } else {
	      other_types+=100*(num_elem_type[i]/num_array_types)
	   }
	printf("other-types ,, %2.1f\n", other_types) >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -gr -k 3 < " TEMP_FILE)

	system("rm " TEMP_FILE)
	}

