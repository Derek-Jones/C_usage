                     /* wordambig.c, 27 May 02 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE (0)
#define TRUE (1)
#define MAX_ID_LEN 1000 /* a big number to be 'safe' */
#define MAX_ID_LEN_CNT 17

typedef int CH_PAT_TYPE;
typedef unsigned char ID_CHAR;

ID_CHAR ident_str[MAX_ID_LEN];
size_t ident_len;

int num_id_matches[2],
    num_word_matches[2],
    num_new_patterns,
    num_word_patterns;
int num_patterns[MAX_ID_LEN_CNT],
    num_words[MAX_ID_LEN_CNT];
struct pattern_list {
                    char is_ident_pat;
		    CH_PAT_TYPE ch_pattern;
		    struct pattern_list *next;
		    };

/*
 * Assumes a character is represented by a value in 0..255
 * 1st index is the identifier length (always greater than 4)
 * 2nd index is the value of the first character of the identifier
 * 3rd index is the offset, within the word, of the character pair
 *           first and last letters not included
 */
struct pattern_list *(pattern_info[MAX_ID_LEN_CNT-4][256][MAX_ID_LEN_CNT-2]);
int pattern_count[MAX_ID_LEN_CNT-4][MAX_ID_LEN_CNT-2];


void add_word_info(void)
/*
 * Add the each set of four character sequences in ident_str into
 * the list of known identifier character sequences
 */
{
char found_match;
ID_CHAR const first_ch=ident_str[0];
size_t id_ind;
CH_PAT_TYPE cur_ch_pat,
	    last_ch = ident_str[ident_len-1] << 16;
struct pattern_list *(* const start_pat_info)=pattern_info[ident_len-5][first_ch],
                    *cur_pat_info;

num_words[ident_len]++;

/*
 * For each interior letter position, count the number of three
 * (we are indexing on the first letter, which makes four) letter
 * patterns.
 */
for (id_ind=1; id_ind < ident_len-1; id_ind++)
   {
   /*
    * A simple encoding of three letters
    */
   cur_ch_pat=last_ch | (ident_str[id_ind] << 8) | ident_str[id_ind+1];
   cur_pat_info=start_pat_info[id_ind-1];
   found_match=FALSE;
   while (cur_pat_info != NULL)
      {
      if (cur_pat_info->ch_pattern == cur_ch_pat)
         {
	 found_match=TRUE;
	 break;
	 }
      cur_pat_info=cur_pat_info->next;
      }
   if (!found_match)
      {
      num_word_patterns++;
      num_patterns[ident_len]++;
      cur_pat_info=malloc(sizeof(struct pattern_list));
      cur_pat_info->is_ident_pat=FALSE;
      cur_pat_info->ch_pattern=cur_ch_pat;
      cur_pat_info->next=pattern_info[ident_len-5][first_ch][id_ind-1];
      pattern_info[ident_len-5][first_ch][id_ind-1]=cur_pat_info;
      pattern_count[ident_len-5][id_ind-1]++;
      }
   }
}

void chk_ident(void)
{
char found_match;
ID_CHAR const first_ch=ident_str[0];
size_t id_ind,
       center_id=(ident_len/2);
CH_PAT_TYPE cur_ch_pat,
	    last_ch = ident_str[ident_len-1] << 16;
struct pattern_list *(* const start_pat_info)=pattern_info[ident_len-5][first_ch],
                    *cur_pat_info;

num_words[ident_len]++;

/*
 * For each interior letter position, count the number of three
 * (we are indexing on the first letter, which makes four) letter
 * patterns.
 */
for (id_ind=1; id_ind < ident_len-1; id_ind++)
   {
   /*
    * A simple encoding of three letters
    */
   cur_ch_pat=last_ch | (ident_str[id_ind] << 8) | ident_str[id_ind+1];
   cur_pat_info=start_pat_info[id_ind-1];
   found_match=FALSE;
   while (cur_pat_info != NULL)
      {
      if (cur_pat_info->ch_pattern == cur_ch_pat)
         {
	 if (cur_pat_info->is_ident_pat)
	    {
	    num_id_matches[0]++;
	    if (id_ind == center_id)
	       num_id_matches[1]++;
	    }
	 else
	    {
	    num_word_matches[0]++;
	    if (id_ind == center_id)
	       num_word_matches[1]++;
	    }
	 found_match=TRUE;
	 break;
	 }
      cur_pat_info=cur_pat_info->next;
      }
   if (!found_match)
      {
      num_new_patterns++;
      num_patterns[ident_len]++;
      cur_pat_info=malloc(sizeof(struct pattern_list));
      cur_pat_info->is_ident_pat=TRUE;
      cur_pat_info->ch_pattern=cur_ch_pat;
      cur_pat_info->next=pattern_info[ident_len-5][first_ch][id_ind-1];
      pattern_info[ident_len-5][first_ch][id_ind-1]=cur_pat_info;
      pattern_count[ident_len-5][id_ind-1]++;
      }
   }
}

void print_ambig(void)
{
int id_len,
    l_pos;

for (id_len=0; id_len < MAX_ID_LEN_CNT-4; id_len++)
   {
   printf("Id length= %d num words= %d num patterns= %d\n",
		5+id_len, num_words[5+id_len], num_patterns[5+id_len]);
   for (l_pos=0; l_pos < id_len+5-2; l_pos++)
      {
      printf("center offset= %.1f num patterns= %d ambig= %f\n",
		l_pos+2-(5+id_len)/2.0, pattern_count[id_len][l_pos],
		num_words[5+id_len]/(double)pattern_count[id_len][l_pos]);
      }
   }
}

int main(void)
{
int seen_word_id_delimiter = FALSE;

/*
 * Calculate two kinds of information
 *
 *   1) If the input contains the character sequence $___$ then
 *      a list of known words will have preceeded it and it will be
 *      followed by a list of identifiers.  Calculate match information
 *      between these words and identifiers.
 *
 *   2) Otherwise, calculate ambiguity information based on the
 *      character sequences that have bee encountered.  That is,
 *      given four characters from a character sequence, what percentage
 *      of other character sequences have the same four characters in
 *      the same character positions.
 */
while (!feof(stdin))
   {
   gets(ident_str);
   if (strcmp(ident_str, "$___$") == 0)
      seen_word_id_delimiter = TRUE;
   else
      {
      ident_len=strlen(ident_str);
      if ((ident_len > 4) && (ident_len <= MAX_ID_LEN_CNT))
         if (seen_word_id_delimiter)
	    chk_ident();
	 else
	    add_word_info();
      }
   }

if (seen_word_id_delimiter)
   {
   printf("num word patterns=%d num id patterns=%d\n",
		num_word_patterns, num_new_patterns);
   printf("num word matches=%d num id matches=%d num center word=%d num center id=%d\n",
		num_word_matches[0], num_id_matches[0],
		num_word_matches[1], num_id_matches[1]);
   }
else
   print_ambig();

return 0;
}

