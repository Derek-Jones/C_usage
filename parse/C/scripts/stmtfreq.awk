#
# stmtfreq.awk, 16 Mar 08

function init_stmt_freq()
{
for (i=0; i < 10; i++)
   stmt_freq[i]="NA"
}

BEGIN {
#	print "stmt = "stmt
#	print "nesting = "nesting
#stmt=ARGV[1]
#nesting=ARGV[2]
	init_stmt_freq()
	}

$1 == "Error" {
	next
	}

stmt == "ALL" {
	if ($1 == "IX")
	   {
	   if_expr_count[$1 " " $2]+=$3
	   }
	else
	   {
	   stmt_count[$1 " " $2]+=$3
	   total_nest_count[$2]+=$3
	   }
	next
	}

$1 == stmt {
	stmt_freq[$2]=$4
	next
	}

$1 == "end" {
	for (i=0; i < 10; i++)
	   printf(" %s", stmt_freq[i])
	printf("\n")
	init_stmt_freq()
	next
	}

END {
	TEMP_FILE="dy" systime()
	printf("") > TEMP_FILE
	for (c in stmt_count)
	   {
	   split(c, stmt_nest)
#
	   if (stmt_count[c] != 0)
	      printf("%s %6d %5.2f\n", c, stmt_count[c], 100.0*stmt_count[c]/total_nest_count[stmt_nest[2]]) >> TEMP_FILE
	   }
	if (stmt == "ALL")
	 for (c in if_expr_count)
	   {
	   split(c, if_expr_nest)
	   all_ifs=stmt_count["IF " if_expr_nest[2]] + stmt_count["IE " if_expr_nest[2]]
#
	   if (all_ifs)
	      printf("%s %6d %2.4f\n", c, if_expr_count[c], if_expr_count[c]/all_ifs) >> TEMP_FILE
	   }
	close(TEMP_FILE)
	system("sort -g -k2 -k3 < " TEMP_FILE)

	system("rm " TEMP_FILE)
	}

