# iswcntrl.awk, 16 Jul 03
#

BEGIN {
	}

$1 == "abstract" {
	if (KEY_TOK == "#IF")
	   num_key_tok=$3
	if (KEY_TOK == "#ELIF")
	   num_key_tok=$4
	if (KEY_TOK == "IF")
	   num_key_tok=$3
	if (KEY_TOK == "WHILE")
	   num_key_tok=$4
	if (KEY_TOK == "SWITCH")
	   num_key_tok=$5
	if (KEY_TOK == "FOR")
	   num_key_tok=$6
	next
	}

$2 == KEY_TOK {
	freq=100*($1/num_key_tok)
	if (freq < 1.0) {
	   printf("others ,, %2.1f\n", 100-total_freq)
	   exit
	   }
	total_freq+=freq
	if ((NF == 3) ||
	    (KEY_TOK == "#IF") ||
	    (KEY_TOK == "#ELIF"))
	   printf(" %s", $3)
	for (i=4; i < NF; i++)
	   printf(" %s", $i)
	if ((NF != 3) &&
	    ((KEY_TOK == "#IF") ||
	     (KEY_TOK == "#ELIF")))
	   printf(" %s", $NF)
	printf(" ,, %2.1f\n", freq)
	next
	}

	{
	next
	}

END {
    }

