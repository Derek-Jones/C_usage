                    /* rdstrs.c, 27 Nov 02 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN 30
#define STR_CHUNK_SIZE 3000

struct char_info {
                  int num_allocated,
		      num_used;
		  char *strings;
		  struct char_info *next;
		 };

struct char_info *all_strings[MAX_STR_LEN+1];

static void new_str_chunk(struct char_info **chunk_base)
{
*chunk_base = (struct char_info *)malloc(sizeof(struct char_info));
(*chunk_base)->strings=(char *)malloc(STR_CHUNK_SIZE);
(*chunk_base)->num_allocated=STR_CHUNK_SIZE;
(*chunk_base)->num_used=0;
(*chunk_base)->next=NULL;
}

static void init_all_strings(void)
{
int ind;

for (ind=1; ind<=MAX_STR_LEN; ind++)
   {
   new_str_chunk(all_strings+ind);
   }
}


static void add_string(char *cur_str,
		       int cur_str_len)
{
/*
 * Create another chunk of storage if there is not enough room left.
 */
if (cur_str_len+all_strings[cur_str_len]->num_used >
				all_strings[cur_str_len]->num_allocated)
   {
   struct char_info *new_chunk;
   new_str_chunk(&new_chunk);
   new_chunk->next=all_strings[cur_str_len];
   all_strings[cur_str_len]=new_chunk;
   }

/*
 * Copy over the new string.
 */
strcpy(all_strings[cur_str_len]->strings+
       all_strings[cur_str_len]->num_allocated, cur_str);
all_strings[cur_str_len]->strings[
			all_strings[cur_str_len]->num_allocated +
							cur_str_len]=0;
all_strings[cur_str_len]->num_allocated+=(cur_str_len+1);
}


void read_strings(void)
{
char cur_str[MAX_STR_LEN+2];
int cur_str_len;

init_all_strings();

while (!feof(stdin))
   {
   fgets(cur_str, MAX_STR_LEN+2, stdin);
   cur_str_len=strlen(cur_str);
   if (cur_str_len > 0)
      add_string(cur_str, cur_str_len);
   }
}

