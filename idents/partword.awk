# partword.awk,  4 Feb 08
#


BEGIN {
	in_idents=0
	seen_File=0
	TMP_UNKN="UNKNOWN.id"
	TMP_GUESS="GUESSED.id"
	printf("") > TMP_UNKN
	printf("") > TMP_GUESS
	}

seen_File == 1 {
	next
	}

$1 == "File:" {
	seen_File=1
	next
	}

$1 == "$___$" {
	in_idents=1
	next
	}

NF < 3 {
	if (in_idents == 1)
	  {
	   if (word[$2] != 0)
	      {
	      print $1 " w " $2 >> TMP_GUESS
	      }
	   else if (word_4[$2] != "")
	      {
	      print $1 " 4 " $2 " " word_4[$2] >> TMP_GUESS
	      }
	   else if (word_3[$2] != "")
	      {
	      print $1 " 3 " $2 " " word_3[$2] >> TMP_GUESS
	      }
	   else if (word_abbrev[$2] != "")
	      {
	      print $1 " a " $2 " " word_abbrev[$2] >> TMP_GUESS
	      }
	   else
	      print $1 " u " $2 >> TMP_UNKN
	   }
       else
	   {
	   tolow=tolower($1)
	   word[tolow]=1
	   word_3[substr(tolow, 1, 3)]=word_3[substr(tolow, 1, 3)] " " tolow
	   word_4[substr(tolow, 1, 4)]=word_4[substr(tolow, 1, 4)] " " tolow
           ch=substr($1, 1, 1)
           if ((ch == "a") || (ch == "e") || (ch == "i") || (ch == "o") || (ch == "u"))
	      next
	   str_len=length(tolow)
           last_ch=" "
	   abbrev_word=""
           for (i=1; i <= str_len; i++)
              {
              ch=substr($1, i, 1)
              if ((ch == "a") || (ch == "e") || (ch == "i") || (ch == "o") || (ch == "u"))
		 dummy=1
	      else
		 {
		 if (last_ch != ch)
                    abbrev_word=abbrev_word ch
		 }
	      last_ch=ch
              }
	   word_abbrev[abbrev_word]=word_abbrev[abbrev_word] " " tolow
	   }
	next
	}

END {
	printf("$___$") >> TMP_GUESS

	TEMP_FILE="Te" systime()
	system("sort -k 3 < " TMP_UNKN " > " TEMP_FILE)
	system(" mv " TEMP_FILE " " TMP_UNKN)
#    printf("") > TEMP_FILE
#    for (ind in words_in_id)
#       print ind " " 0+words_in_id[ind] >> TEMP_FILE
#    close(TEMP_FILE)
#    
#    system("rm " TEMP_FILE)
    }

