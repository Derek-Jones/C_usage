#
# stmtseq.awk, 13 Mar 05

function init_stmt_seq()
{
stmt_seq=""
for (i=0; i < 6; i++)
   stmt_seq=stmt_seq ".. "
}

function start_DC()
{
if (es_seq_len != 0)
   {
   all_es_seq_len[es_seq_len]++
#
# Turn OC ES CC into ES
#
   if (($0 == "CC") && (substr(stmt_seq, 17) == "OC"))
      {
      stmt_seq=substr(stmt_seq, 1, 16) "ES"
      OC_ES_CC=1
      }
   else
      {
      all_stmt_seq[stmt_seq]++
      stmt_seq=substr(stmt_seq, 4) " ES"
      }
   if (length($0) == 2)
      es_followed_by[$0]++
   es_seq_len=0
   }
last_es_seq_len=es_seq_len
prev_cmpd_hdr=0
}

function start_ES()
{
if (dc_seq_len != 0)
   {
   all_dc_seq_len[dc_seq_len]++
   all_stmt_seq[stmt_seq]++
   stmt_seq=substr(stmt_seq, 4) " DC"
   if (length($0) == 2)
      dc_followed_by[$0]++
   dc_seq_len=0
   }
last_dc_seq_len=dc_seq_len
}

function end_DC_ES()
{
OC_ES_CC=0
start_ES()
start_DC()

if (length($0) == 2)
   {
   if (OC_ES_CC == 1)
      OC_ES_CC=0
   else
      {
      all_stmt_seq[stmt_seq]++
      if ($0 == "FD")
         init_stmt_seq()
      stmt_seq=substr(stmt_seq, 4) " " $0
      }
   }
}

BEGIN {
	curl_depth=0
	es_seq_len=0
	dc_seq_len=0
	prev_cmpd_hdr=0
	init_stmt_seq()
	}

	{
	if (length($0) == 2)
	   {
	   total_all_stmt++
	   total_stmt[$0]++
	   }
	# no next, we want to fall through
	}

$0 == "ES" {
	start_ES()
	es_seq_len++
	if (prev_cmpd_hdr == 1)
	   {
	   all_stmt_seq[stmt_seq]++
	   stmt_seq=substr(stmt_seq, 4) " Es"
	   all_es_seq_len[1]++
	   es_seq_len=0
	   prev_cmpd_hdr=0
	   es_followed_by["cc"]++
	   }
	next
	}

$0 == "DC" {
	start_DC()
	# Uncomment to include DC counts
	#dc_seq_len++
	next
	}

	{
	prev_cmpd_hdr=0
	end_DC_ES()
	# no next, we want to fall through
	}

$0 == "IF" {
	prev_cmpd_hdr=1
	next
	}

$0 == "EL" {
	prev_cmpd_hdr=1
	next
	}

$0 == "OC" {
	curl_depth++
	next
	}

$0 == "CC" {
	curl_depth--
	next
	}

$0 == "FD" {
	curl_depth=1
	next
	}

$0 == "FO" {
	prev_cmpd_hdr=1
	next
	}

$0 == "WH" {
	prev_cmpd_hdr=1
	next
	}

$0 == "RE" {
	next
	}

$0 == "BR" {
	next
	}

$0 == "GO" {
	next
	}

$0 == "SW" {
	next
	}

$0 == "CO" {
	next
	}

$0 == "DO" {
	next
	}

END {
	TEMP_FILE="dy" systime()
	print "Total statements " total_all_stmt
	printf("") > TEMP_FILE
	for (es in total_stmt)
	   print es " " total_stmt[es] >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -gr -k2 < " TEMP_FILE)
	
	printf("") > TEMP_FILE
	for (es in all_es_seq_len)
	   print es " " all_es_seq_len[es] >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -g < " TEMP_FILE)
	
	print "Statements following ES"
	printf("") > TEMP_FILE
	for (es in es_followed_by)
	   print es " " es_followed_by[es] >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -gr -k2 < " TEMP_FILE)
	
	print "Statement sequences"
	printf("") > TEMP_FILE
	for (es in all_stmt_seq)
	   print es " " all_stmt_seq[es] >> TEMP_FILE
	close(TEMP_FILE)
	system("sort -gr -k7 < " TEMP_FILE)
	
	system("rm " TEMP_FILE)
	}

