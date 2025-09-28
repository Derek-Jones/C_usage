# dups.awk,  8 Jan 04
#

function sum_duplicates()
{
# Count the number of times a given number of files have
# shared a duplicate
# and the total number of duplicate lines
dup_file_cnt[cur_diff_dup_files]++
dup_file_line_cnt[cur_diff_dup_files]+=cur_dup_cnt

if (cur_dup_cnt > 7)
   {
   big_dup_file_cnt[cur_diff_dup_files]++
   big_dup_file_line_cnt[cur_diff_dup_files]+=cur_dup_cnt
   }
}


BEGIN {
	}

$1 == "Between" {
	if (dup_files[$7] == 0)
	   {
	   dup_files[$7]=1
	   cur_diff_dup_files++
	   }
	next
	}

$1 == "Found" {
	if (cur_diff_dup_files != 0)
	   sum_duplicates()
	
	cur_diff_dup_files=0
	cur_dup_cnt=$2
	delete dup_files
	next
	}

# Started a new duplicate file
$1 == "Loading" {
	cur_dup_cnt=0
	cur_diff_dup_files=0
	dup_files["dummy"]=0
	next
	}

	{
	next
	}

END {
	if (cur_diff_dup_files != 0)
	   sum_duplicates()
	
	TEMP_FILE=systime() ".dp"
	printf("") > TEMP_FILE
	for (d in dup_file_cnt)
	   print d " " dup_file_cnt[d] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: dup_file_cnt.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	printf("") > TEMP_FILE
	for (d in dup_file_line_cnt)
	   print d " " dup_file_line_cnt[d] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: dup_file_line_cnt.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	printf("") > TEMP_FILE
	for (d in big_dup_file_cnt)
	   print d " " big_dup_file_cnt[d] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: big_dup_file_cnt.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	printf("") > TEMP_FILE
	for (d in big_dup_file_line_cnt)
	   print d " " big_dup_file_line_cnt[d] >> TEMP_FILE
	close(TEMP_FILE)
	print "File: big_dup_file_line_cnt.d"
	system("sort -g < " TEMP_FILE)
	print "End File"
	
	system("rm " TEMP_FILE)
	}

