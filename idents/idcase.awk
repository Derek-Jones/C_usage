# idcase.awk, 12 Jul 03
#
# Calculate the number of identifiers containing different
# characters.
#

function digit_underscore()
{
if (index($1, "_") == 0)
   num_no_unders++
if (match($1, /[0-9]/) == 0)
   num_no_digits++
}

BEGIN {
	max_id_len=0
	}

$1 == "__E__O__F__"  {
	next
	}

/^[[:upper:]0-9_]+$/ {
	num_upper++
	digit_underscore()
	next
	}

/^[[:lower:]0-9_]+$/ {
	num_lower++
	digit_underscore()
	next
	}

/^[[:upper:]].+$/ {
	num_first_upper++
	digit_underscore()
	next
	}

	{
	num_mixed++
	digit_underscore()
	next
	}

END {
    total_idents=num_upper+num_lower+num_first_upper+num_mixed
    printf("no lower-case %2.1f\n", 100*(num_upper/total_idents))
    printf("no upper-case %2.1f\n", 100*(num_lower/total_idents))
    printf("no underscore %2.1f\n", 100*(num_no_unders/total_idents))
    printf("no digits %2.1f\n", 100*(num_no_digits/total_idents))
    printf("only first character upper-case %2.1f\n", 100*(num_first_upper/total_idents))
    }
