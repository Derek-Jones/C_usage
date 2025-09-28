#
# splitseq.awk,  4 Feb 08

function seq_match(ch_seq)
{
if (seen_word[ch_seq] == 1)
  return 1
if ((length(ch_seq) == 4) && (seen_4_pref[ch_seq] == 1))
  return 1
if ((length(ch_seq) == 3) && (seen_3_pref[ch_seq] == 1))
  return 1
if (seen_a_pref[ch_seq] == 1)
  return 1
}


function find_splits(ch_seq, depth, ch_len, i, left_match, left_split, right_split, pos_splits)
{
ch_len=length(ch_seq)
if (ch_len < 3)
   return ch_seq

if (seq_match(ch_seq))
   pos_splits=" " ch_seq
else
   pos_splits=""

for (i=1; i < ch_len; i++)
   {
left_match=0
left_split=substr(ch_seq, 1, i)
right_split=substr(ch_seq, 1+i)
if (seen_word[left_split] == 1)
   {
   left_match=1
   if (seq_match(right_split))
      pos_splits=pos_splits " " left_split "-" right_split
   else if (length(left_split) != 1)
      pos_splits=pos_splits " " left_split "." find_splits(right_split, depth+1)
   }
if ((i==4) && (seen_4_pref[left_split] == 1))
   {
   left_match=1
   if (seq_match(right_split))
      pos_splits=pos_splits " " left_split "-" right_split
   else if (length(left_split) != 1)
      pos_splits=pos_splits " " left_split "." find_splits(right_split, depth+1)
   }
if ((i==3) && (seen_3_pref[left_split] == 1))
   {
   left_match=1
   if (seq_match(right_split))
      pos_splits=pos_splits " " left_split "-" right_split
   else if (length(left_split) != 1)
      pos_splits=pos_splits " " left_split "." find_splits(right_split, depth+1)
   }
if (seen_a_pref[left_split] == 1)
   {
   left_match=1
   if (seq_match(right_split))
      pos_splits=pos_splits " " left_split "-" right_split
   else if (length(left_split) != 1)
      pos_splits=pos_splits " " left_split "." find_splits(right_split, depth+1)
   }
if ((left_match == 0) && (length(right_split) != 1) && seq_match(right_split))
   pos_splits=pos_splits " " find_splits(left_split, depth+1) "," right_split
   }

if (pos_splits == "")
   return ch_seq
else
   {
   pos_splits=substr(pos_splits, 2)
   if ((depth > 0) && (index(pos_splits, " ") != 0))
      return "(" pos_splits ")"
   else
      return pos_splits
   }
}


BEGIN {
	in_guessed=1
	last_seq=""
	}

$1 == "$___$" {
	in_guessed=0
	next
	}

in_guessed == 1 {
	if ($2 == "w")
	   seen_word[$3]=1
	else if ($2 == "4")
	   seen_4_pref[$3]=1
	else if ($2 == "3")
	   seen_3_pref[$3]=1
	else if ($2 == "a")
	   seen_a_pref[$3]=1
	next
	}

NF == 3 {
	print $3 " " find_splits($3, 0)
	last_seq=$3
	next
	}

END {
	}

