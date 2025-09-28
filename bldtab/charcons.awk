# charesc.awk, 14 Jul 03
#
# character constant usage

function print_data()
{
printf("<c_syntax>simple-escape-sequence</c_syntax> ,, %2.1f\n", 100*(total_char_esc-oct_esc-hex_esc-UNC_esc)/total_char_cons)
printf("<c_syntax>octal-escape-sequence</c_syntax> ,, %2.1f\n", 100*(oct_esc)/total_char_cons)
printf("<c_syntax>hexadecimal-escape-sequence</c_syntax> ,, %2.1f\n", 100*(hex_esc)/total_char_cons)
printf("<c_syntax>universal-character-name</c_syntax> ,, %2.1f\n", 100*(UCN_esc)/total_char_cons)
exit
}

BEGIN {
	oct_esc=0
	hex_esc=0
	UCN_esc=0
	}

$1 ~ /char-esc/ {
	total_char_esc=$2
	total_char_cons=$7
	printf("not an escape sequence ,, %2.1f\n", 100*(total_char_cons-total_char_esc)/total_char_cons)
	next
	}

$2 ~ /escseq.d/ {
	in_data_freq=1
	next
	}

$1 ~ /End/ {
	if (in_data_freq == 1) print_data()
	next
	}

        {
	if (in_data_freq == 1) {
	   if (($1 == "0") || ($1 == "1") ||($1 == "2") || ($1 == "3"))
	      oct_esc+=$2
	   if (($1 == "x") || ($1 == "X"))
	      hex_esc+=$2
	   if (($1 == "u") || ($1 == "U"))
	      UCN_esc+=$2
	}
	next
	}

END {
    }

