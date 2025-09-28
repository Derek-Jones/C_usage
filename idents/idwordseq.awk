#
# idwordseq.awk,  4 Feb 08

function count_name(id_name)
{
if (cur_word_list == "")
   cur_word_list=id_name
else
   cur_word_list=cur_word_list " " id_name
if (last_word == "")
   word_bigram[id_name]++
else
   word_bigram[last_word " " id_name]++
last_word=id_name
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
   else # Catch anything else
      {
      print ">>> " $0
      id_name=substr(id_name, 2)
      }
   }
}


BEGIN {
	file_num=0
	total_idents=0
	}

$1 ~ /^[a-zA-Z_]+/ {
	total_idents++
	cur_word_list=""
	last_word=""
	split($1, idents, "_")
	for (i in idents)
	   {
	   get_names(idents[i])
	   }
	id_word_list[cur_word_list]++
	next
	}

END {
	print "total idents " total_idents
	TEMP_FILE="dy" systime()
	print("") > TEMP_FILE
	for (i in word_bigram)
	   {
	   print word_bigram[i] " " i >> TEMP_FILE
	   }
	close(TEMP_FILE)
        system("sort -gr < " TEMP_FILE)

	print "File: word_list"

	print("") > TEMP_FILE
	for (i in id_word_list)
	   {
	   print id_word_list[i] " " i >> TEMP_FILE
	   }
	close(TEMP_FILE)
        system("sort -gr < " TEMP_FILE)

	system("rm " TEMP_FILE)
	}

