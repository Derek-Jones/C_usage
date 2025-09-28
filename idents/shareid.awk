# shareid.awk,  9 Jul 03
#
#
BEGIN {
	line_num=0
	}

	{
	line_num++
	if (line_num == 1) next
	if (line_num == 2) {
	   num_cols=NF
	   row_num=0
	   printf(" %s", $0)
	   for (i=1; i <= NF; i++) {
	      row_name[$i]=1
	   }
	} else {
	   if ((row_name[$1] == 1) || (row_name[$1 ","] == 1)) {
	      col_num=1
	      row_num++
	      printf("\n%-20s", $1)
	   } else {
	      if (col_num == 1) {
		 row_max=$1
	      }
	      if (row_num == col_num) {
	         printf(",     ")
	      }
	      if ((col_num == 1) || (row_num == 1)) {
		 printf(", %7d", $1)
	      } else {
	         printf(", %.2f", $1/row_max)
	      }
	      col_num++
	   }
	}
	}

END {
    printf(", \n")
    }

