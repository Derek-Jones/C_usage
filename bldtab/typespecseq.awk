# typspecseq.awk, 16 Jul 03
#
# type specifier sequences

function print_table()
{
for (i=1; i <= num_seqs; i++) {
   if (type_seq_freq[i]/total_sequences > 0.001)
      printf(" %s ,, %2.1f\n", type_seq_str[i], 100*(type_seq_freq[i]/total_sequences))
   }
exit
}


BEGIN {
	num_seqs=0
	}

$2 ~ /num_type_specs.d/ {
	in_data_freq=1
	next
	}

$1 ~ /End/ {
	if (in_data_freq == 1)
	   print_table()
	next
	}

	{
	if (in_data_freq == 1) {
	   num_seqs++
	   total_sequences+=$NF
	   for (i=1; i < NF; i++)
	      type_seq_str[num_seqs]=type_seq_str[num_seqs] " " $i
	   type_seq_freq[num_seqs]=$NF
	   }
	next
	}

END {
    }

