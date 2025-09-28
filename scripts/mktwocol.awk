# mktwocol.awk, 11 Aug 03
#
# Double up the columns in a table

BEGIN {
	num_lines=0
	}

	{
	num_lines++
	line[num_lines]=$0
	next
	}

END {
    num_rows=int((num_lines+1)/2)
    t=line[1]
    num_comma=gsub(" ,, ", "", t)
    c_line=" "
    for (c=1; c <= num_comma; c++)
       c_line=c_line " ,, "
    line[num_lines+1]=c_line
    for (l=1; l <= num_rows; l++)
       print " " line[l] " ,, " line[l+num_rows]
    }


