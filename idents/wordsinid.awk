# wordsinid.awk,  4 Jan 08
#
# Find words within identifiers, the underscore is treated as
# a separator.
#

function extract_name(id_name)
{
cur_word=tolower(substr(id_name, 1, RLENGTH))
if (word[cur_word] != 0)
   {
   num_Cc_words++
   word[cur_word]++
   }
return substr(id_name, 1+RLENGTH)
}

function camelcase_names(id_name)
{
num_Cc_words=0
cur_Cc_splits=0
while (length(id_name) != 0)
   {
   cur_Cc_splits++
   if (match(id_name, /^[a-z]+/) == 1)
      id_name=extract_name(id_name)
   else if (match(id_name, /^[A-Z][a-z]+/) == 1)
      id_name=extract_name(id_name)
   else if (match(id_name, /^[A-Z]+/) == 1)
      id_name=extract_name(id_name)
   else if (match(id_name, /^[0-9]+/) == 1)
      id_name=substr(id_name, 1+RLENGTH)
   else # Just in case some odd characters have slipped through
      id_name=substr(id_name, 2)
   }
Cc_num_splits[cur_Cc_splits]++
Cc_words_in_id[num_Cc_words]++
}


BEGIN {
	max_id_len=0
	in_idents=0
	}

$1 == "__E__O__F__"  {
	next
	}

$1 == "$___$" {
	in_idents=1
	next
	}

	{
	if (in_idents == 1)
	  {
	   sub(/_+$/, "", $1)
	   if ($1 == "")
	      {
	      next
	      }
	   cur_splits=split(tolower($1), sub_ids, "_")
	   num_splits[cur_splits]++
	   if (cur_splits == 1)
	      camelcase_names($1)
	   num_words=0
	   for (s=1; s <= cur_splits; s++)
	      {
	      if (word[sub_ids[s]] != 0)
	         {
	         num_words++
	         word[sub_ids[s]]++
		 }
	      }
	   words_in_id[num_words]++
	   }
       else
	   {
	   word[tolower($1)]=1
	   }
	next
	}

END {
    TEMP_FILE="TeMp.tEmP"
    printf("") > TEMP_FILE
    for (ind in words_in_id)
       print ind " " 0+words_in_id[ind] >> TEMP_FILE
    close(TEMP_FILE)
    print "File: idwords.d"
    system("sort -g < " TEMP_FILE)
    print "End File"
    printf("") > TEMP_FILE
    for (ind in num_splits)
       print ind " " 0+num_splits[ind] >> TEMP_FILE
    close(TEMP_FILE)
    print "File: idunders.d"
    system("sort -g < " TEMP_FILE)
    print "End File"
    
    printf("") > TEMP_FILE
    for (ind in Cc_words_in_id)
       print ind " " 0+Cc_words_in_id[ind] >> TEMP_FILE
    close(TEMP_FILE)
    print "File: idcamelwords.d"
    system("sort -g < " TEMP_FILE)
    print "End File"
    printf("") > TEMP_FILE
    for (ind in Cc_num_splits)
       print ind " " 0+Cc_num_splits[ind] >> TEMP_FILE
    close(TEMP_FILE)
    print "File: idcamel.d"
    system("sort -g < " TEMP_FILE)
    print "End File"
    
    printf("") > TEMP_FILE
    for (ind in word)
       if (word[ind] > 1)
          print ind " " word[ind]-1 >> TEMP_FILE
    close(TEMP_FILE)
    print "File: word_cnt.d"
    system("sort -k 2 -nr < " TEMP_FILE)
    print "End File"
    
    system("rm " TEMP_FILE)
    }

