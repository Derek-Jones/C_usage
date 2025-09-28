# strlitinfo.awk, 19 Dec 07
#
# character constant usage

BEGIN {
	}

NF == 1 {
	num_prog++
	prog_name[num_prog]=$1
	first_line=1
	next
	}

        {
	if (first_line == 1) {
	   first_line=0
	   num_str[num_prog]=$1
	   str_len[num_prog]=$3
        } else {
	   uniq_num_str[num_prog]=$1
	   uniq_str_len[num_prog]=$3
	}
	next
	}

END {
    for (i=1; i <= num_prog; i++)
       printf(" ,, %s", prog_name[i])
    printf("\nNumber of strings")
    for (i=1; i <= num_prog; i++)
       printf(" ,, %d", num_str[i])
    printf("\nBytes in strings")
    for (i=1; i <= num_prog; i++)
       printf(" ,, %d", str_len[i])
    printf("\nNumber of unique strings")
    for (i=1; i <= num_prog; i++)
       printf(" ,, %d", uniq_num_str[i])
    printf("\nBytes in unique strings")
    for (i=1; i <= num_prog; i++)
       printf(" ,, %d", uniq_str_len[i])
    printf("\n")
    }

