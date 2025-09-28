                    /* calclev.c, 10 Dec 03 */

#include <stdio.h>
#include <stdlib.h>

/*
 * #define LEV_DIST 1
 * #define KEY_DIST 1
 * #define LEVKEY_DIST 1
 */
#define MAX_STR_LEN         100
#define MAX_ALL_ID_LEN 10000000
#define MAX_NUM_IDS      500000

char *all_id_str,
     *str_1,
     *str_2;
char **id_str_index;
int len_str_1;
int num_ids = 0;

#ifdef LEV_DIST
#include "levdist.c"
#endif
#ifdef KEY_DIST
#include "keydist.c"
#endif
#ifdef LEVKEY_DIST
#include "levkeydist.c"
#endif

void read_id_strings(void)
{
char * cur_id_start;

all_id_str=(char *)malloc(MAX_ALL_ID_LEN);
if (all_id_str == NULL)
   {
   printf("Failed to allocate %d bytes\n", MAX_ALL_ID_LEN);
   exit(1);
   }
cur_id_start=all_id_str;
*all_id_str='\0';
id_str_index=(char **)malloc(MAX_NUM_IDS*sizeof(char *));
if (id_str_index == NULL)
   {
   printf("Failed to allocate %d bytes\n", MAX_NUM_IDS);
   exit(1);
   }

while (!feof(stdin))
   {
   if (num_ids == MAX_NUM_IDS)
      {
      printf("Reached maximum number, %d, of identifiers\n", MAX_NUM_IDS);
      return;
      }
   if ((cur_id_start + MAX_STR_LEN+1) > (all_id_str+MAX_ALL_ID_LEN))
      {
      printf("Filled identifier string buffer, %d\n", MAX_ALL_ID_LEN);
      return;
      }
   if (gets(cur_id_start) != NULL)
      {
      num_ids++;
      id_str_index[num_ids]=cur_id_start;
      cur_id_start+=(strlen(id_str_index[num_ids])+1);
      }
   }
/*
printf("read %d ids\n", num_ids);
*/
}


int main(void)
{
int id_1_cnt = 0,
    id_2_cnt;

read_id_strings();

init_distance();

while (id_1_cnt < num_ids)
   {
   id_1_cnt++;
   str_1=id_str_index[id_1_cnt];
#if LEV_DIST || LEVKEY_DIST
   len_str_1=strlen(str_1);
#endif
   id_2_cnt=id_1_cnt;
   while (id_2_cnt < num_ids)
      {
      id_2_cnt++;
      str_2=id_str_index[id_2_cnt];
#ifdef LEV_DIST
      printf("%d\n", lev_dist());
#else
#ifdef KEY_DIST
      printf("%f\n", key_dist());
#else
#ifdef LEVKEY_DIST
      printf("%d\n", levkey_dist());
#else
#error "Must -Define either LEV_DIST, KEY_DIST, or LEVKEY_DIST"
#endif
#endif
#endif
      }
   }
}

