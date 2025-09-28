# charsqin.awk, 20 Nov 08
#
# Find distance between identical sequences of characters within identifiers,
# the underscore is treated as a separator.
#

function add_averages()
# Sum the number of occurrences of each distance for a
# random pair of fields in a struct with the given number
# of fields.
{
for (a=1; a < num_fields; a++)
   total_av_field_dist[a]+=(num_fields-a)
field_count[num_fields]++
}


function count_name(id_name)
{
total_distances++
if (length(id_name) < 3)
   return

if (def_seq_last_occur[id_name] == 0)
   def_seq_last_occur[id_name]=cur_field_num
else
   {
# Only count the same pair of fields once
   if (def_seq_seen[cur_field_num " "  def_seq_last_occur[id_name]] == 0)
      {
      def_seq_seen[cur_field_num " "  def_seq_last_occur[id_name]]=1
      def_seq_dist[cur_field_num - def_seq_last_occur[id_name]]++
      struct_field_dist[num_fields]+= \
				(cur_field_num - def_seq_last_occur[id_name])
      struct_field_total[num_fields]++
      def_seq_last_occur[id_name]=cur_field_num
      total_def_distances++
      add_averages()
      if (counted_this_field == 0)
	 {
	 counted_this_field=1
	 total_field_contrib++
	 }
      }
   }
}

function extract_name(id_name)
{
cur_word=tolower(substr(id_name, 1, RLENGTH))
count_name(cur_word)
return substr(id_name, 1+RLENGTH)
}

function camelcase_names(id_name)
{
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
}


BEGIN {
	total_fields=0
	total_field_contrib=0
	total_distances=0
	total_def_distances=0
	def_seq_last_occur["w"]=0  # dummy assignment
	def_seq_seen["w"]=0  # dummy assignment
	}

$1 == "|start_struct|" &&
$2 > 4	{
	delete def_seq_last_occur
	delete def_seq_seen
	num_fields=$2
	cur_field_num=0
	next
	}

	{
	total_fields++
	counted_this_field=0
	cur_field_num++
	   sub(/_+$/, "", $2)
	   if ($2 == "")
	      {
	      next
	      }
	   cur_splits=split(tolower($2), sub_ids, "_")
	   if (cur_splits == 1)
	      camelcase_names($2)
	   else
	      for (i=1; i<= cur_splits; i++)
		 count_name(sub_ids[i])
	next
	}

END {
    TEMP_FILE="t." systime()
    sum_total_av_dist=0
    for (a=1; a < 70; a++) 
      sum_total_av_dist+=total_av_field_dist[a]
    sum_total_real_dist=0
    for (a=1; a < 70; a++) 
      sum_total_real_dist+=def_seq_dist[a]
    printf("") > TEMP_FILE
    for (ind in def_seq_dist)
      printf("%2d  %6d  %6d\n", ind, def_seq_dist[ind], \
		(sum_total_real_dist*total_av_field_dist[ind])/sum_total_av_dist) >> TEMP_FILE
    close(TEMP_FILE)
    print "Total fields " total_fields " contributing fields " total_field_contrib
    print "Total distance counts " total_def_distances " everything " total_distances
    print "File: field_id_dist.d"
    system("sort -g < " TEMP_FILE)
    print "End File"

    print "File: av_field_id.d"
    for (a=1; a < 70; a++) 
      printf("%2d  %6d  %5.2f %6d\n", a, total_av_field_dist[a], \
			(100.0*total_av_field_dist[a])/sum_total_av_dist, \
                         field_count[a])
    print "End File"

    print "File: av_field_dist.d"
    for (f=5; f < 70; f++)
       printf("%2d %5.2f  %5.2f %5d\n", f, \
                  struct_field_dist[f]/(struct_field_total[f]+0.001), \
		  (f+1)/3.0, struct_field_total[f])
    print "End File"

    system("rm " TEMP_FILE)
    }

