# includehdr.awk, 18 Jul 03
#
# #include preprocessor directives

function header_form(hdr_form)
{
num_headers[hdr_form]++
if (index($2, "/") == 1)
   abs_path[hdr_form]++
if (index($2, "/") != 0)
   has_path[hdr_form]++
}


BEGIN {
	}

$1 == "\"" {
	header_form(1)
	next
	}

$1 == "\<" {
	header_form(2)
	next
	}

        {
	next
	}

END {
    all_headers=num_headers[1]+num_headers[2]
    printf("<h-char-sequence> ,, %2.1f ,, %2.1f ,, %d\n", 100*(num_headers[2]/all_headers), 100*(has_path[2]/num_headers[2]), abs_path[2])
    printf("\"q-char-sequence\" ,, %2.1f ,, %2.1f ,, %d\n", 100*(num_headers[1]/all_headers), 100*(has_path[1]/num_headers[1]), abs_path[2])
    }

