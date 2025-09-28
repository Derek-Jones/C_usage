# idcase.awk, 28 Dec 03
#
# Calculate the number of identifiers containing different
# characters.
#

function print_results()
{
total_idents=num_upper+num_lower+num_first_upper+num_mixed
total_unique=unique_upper+unique_lower+unique_first_upper+unique_mixed
pr_count++
pr_namespace[pr_count]=map_namespace[namespace]
pr_lower[pr_count]=sprintf("%2.1f (%2.1f)", 100*(num_upper/total_idents), 100*(unique_upper/total_unique))
pr_upper[pr_count]=sprintf("%2.1f (%2.1f)", 100*(num_lower/total_idents), 100*(unique_lower/total_unique))
pr_unders[pr_count]=sprintf("%2.1f (%2.1f)", 100*(num_no_unders/total_idents), 100*(unique_no_unders/total_unique))
pr_digits[pr_count]=sprintf("%2.1f (%2.1f)", 100*(num_no_digits/total_idents), 100*(unique_no_digits/total_unique))
pr_f_upper[pr_count]=sprintf("%2.1f (%2.1f)", 100*(num_first_upper/total_idents), 100*(unique_first_upper/total_unique))
}

function digit_underscore()
{
if (index($1, "_") == 0)
   {
   num_no_unders+=$2
   unique_no_unders++
   }
if (match($1, /[0-9]/) == 0)
   {
   num_no_digits+=$2
   unique_no_digits++
   }
}

BEGIN {
	in_namespace=0
	pr_count=0
	pr_namespace[0]=""
	pr_lower[0]="no lower-case"
	pr_upper[0]="no upper-case"
	pr_unders[0]="no underscore"
	pr_digits[0]="no digits"
	pr_f_upper[0]="only first character upper-case"
	map_namespace["local_objects"]="block scope objects"
	map_namespace["global_objects"]="file scope objects"
	map_namespace["enum_consts"]="enumeration constants"
	map_namespace["tags"]="tag names"
	map_namespace["typedefs"]="typedef names"
	map_namespace["func_defs"]="function definitions"
	map_namespace["func_decls"]="function declarations"
	map_namespace["labels"]="label names"
	map_namespace["func_params"]="function parameters"
	map_namespace["macro_definition"]="macro definitions"
	map_namespace["macro_parameter"]="macro parameters"
	map_namespace["members"]="struct/union members"
	}

$1 == "File:" {
	num_upper=0
	unique_upper=0
	num_lower=0
	unique_lower=0
	num_first_upper=0
	unique_first_upper=0
	num_mixed=0
	unique_mixed=0
	num_no_unders=0
	unique_no_unders=0
	num_no_digits=0
	unique_no_digits=0
	start_namespace=0
	namespace=$2
	in_namespace=1
	next
	}

in_namespace == 0 {
	next
	}

$1 == "__E__O__F__"  {
	next
	}

$1 ~ /^[^[:lower:]]+$/ {
	if (($1 == "END") && ($2 == namespace))
	   {
	   print_results()
	   in_namespace=0
	   next
	   }
	num_upper+=$2
	unique_upper++
	digit_underscore()
	next
	}

$1 ~ /^[^[:upper:]]+$/ {
	num_lower+=$2
	unique_lower++
	digit_underscore()
	next
	}

$1 ~ /^[[:upper:]].+$/ {
	num_first_upper+=$2
	unique_first_upper++
	digit_underscore()
	next
	}

	{
	num_mixed+=$2
	unique_mixed++
	digit_underscore()
	next
	}

END {
	for (p=0; p <= pr_count; p++)
	   print pr_namespace[p] " ,, " pr_lower[p] " ,, " pr_upper[p] " ,, " pr_unders[p] " ,, " pr_digits[p] " ,, " pr_f_upper[p]
	}
