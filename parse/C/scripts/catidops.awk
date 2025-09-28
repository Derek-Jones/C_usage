#
# catidops.awk, 28 Nov 07

function count_files(cur_id)
{
num_bits=file_ids[cur_id]
num_bits=and(num_bits, 0x55555555) + and(rshift(num_bits, 1), 0x55555555)
num_bits=and(num_bits, 0x33333333) + and(rshift(num_bits, 2), 0x33333333)
num_bits=and(num_bits, 0x0f0f0f0f) + and(rshift(num_bits, 4), 0x0f0f0f0f)
num_bits=and(num_bits, 0x00ff00ff) + and(rshift(num_bits, 8), 0x00ff00ff)
num_bits=and(num_bits, 0x0000ffff) + and(rshift(num_bits, 16), 0x0000ffff)

return num_bits
}

function count_name(id_name)
{
cat_id[op_map_op[$1] " " id_name]+=$3
all_ids[id_name]+=$3
file_ids[id_name]=or(file_ids[id_name], file_num)
}

function extract_name(id_name)
{
count_name(tolower(substr(id_name, 1, RLENGTH)))
return substr(id_name, 1+RLENGTH)
}

function get_names(id_name)
{
while (length(id_name) != 0)
   {
   if (match(id_name, /^[a-z]+/) == 1)
      id_name=extract_name(id_name)
   else if (match(id_name, /^[A-Z][a-z]+/) == 1)
      id_name=extract_name(id_name)
   else if (match(id_name, /^[A-Z]+/) == 1)
      id_name=extract_name(id_name)
   else if (match(id_name, /^[0-9]+/) == 1)
      id_name=substr(id_name, 1+RLENGTH)
   }
}


BEGIN {
	file_num=0
	total_idents=0
	total_mixed_case=0
	op_map_op["*"]="arith" ; op_map_op["/"]="arith" ; op_map_op["%"]="arith"
	op_map_op["+"]="arith" ; op_map_op["-"]="arith"
	op_map_op["<<"]="bitwise" ; op_map_op[">>"]="bitwise"
#	op_map_op["<"]="relat" ; op_map_op[">"]="relat" ; op_map_op["<="]="relat" ; op_map_op[">="]="relat"
	op_map_op["<"]="arith" ; op_map_op[">"]="arith" ; op_map_op["<="]="arith" ; op_map_op[">="]="arith"
	op_map_op["=="]="equal" ; op_map_op["!="]="equal"
	op_map_op["&"]="bitwise" ; op_map_op["^"]="bitwise" ; op_map_op["|"]="bitwise"
	op_map_op["&&"]="logical" ; op_map_op["||"]="logical"
	}

# Simple way for counting how many times an identifier appears in
# different files.
$1 == "File:" {
	if (file_num == 0)
	   file_num=1
	else
	   file_num=lshift(file_num, 1)
	next
	}

$2 ~ /^[a-zA-Z_]+/ {
	total_idents++
	if (!((tolower($2) == $2) || (toupper($2) == $2)))
	   total_mixed_case++
	split($2, idents, "_")
	for (i in idents)
	   {
	   get_names(idents[i])
	   }
	next
	}

END {
	TEMP_FILE="dy" systime()
	print("") > TEMP_FILE
	for (i in all_ids)
	   {
	   if (all_ids[i] > 0)
	      printf("%2d %7d %12s    a%5.1f  b%5.1f L%5.1f e%5.1f\n", \
			count_files(i), all_ids[i], i,  \
			(100.0*cat_id["arith " i])/all_ids[i], \
			(100.0*cat_id["bitwise " i])/all_ids[i], \
			(100.0*cat_id["logical " i])/all_ids[i], \
			(100.0*cat_id["equal "i])/all_ids[i] ) \
							>> TEMP_FILE
#			(100.0*cat_id["relat " i])/all_ids[i])
	   }
	close(TEMP_FILE)
        system("sort -gr --key=2 < " TEMP_FILE)

	print "total idents " total_idents
	print "total mixed case " total_mixed_case

#	print("") > TEMP_FILE
#	for (i in cat_id)
#	   {
#	   if (cat_id[i] > 2)
#	      print i " " cat_id[i] >> TEMP_FILE
#	   }
#	close(TEMP_FILE)
#	system("sort < " TEMP_FILE)
#
#	print "-------------------"
#
#	print("") > TEMP_FILE
#	for (i in cat_id)
#	   print i " " cat_id[i] >> TEMP_FILE
#	close(TEMP_FILE)
#	system("sort < " TEMP_FILE)
	system("rm " TEMP_FILE)
	}

