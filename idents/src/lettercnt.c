                    /* lettercnt.c, 30 Jul 03 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ID_LEN         100

int main(void)
/*
 * Count all the alphabetic letters (converted to lower
 * case) read from stdin.
 */
{
char buff[MAX_ID_LEN];
char *cur_id_start;
int let_cnt[256] = {0};
int total_chars = 0,
    c;

while (!feof(stdin))
   {
   cur_id_start=buff;
   if (gets(cur_id_start) != NULL)
      {
      while (*cur_id_start != '\0')
         {
         total_chars++;
	 let_cnt[tolower(*cur_id_start)]++;
	 cur_id_start++;
	 }
      }
   }
/*
 * Tough luck for EBCDIC
 */
for (c='a'; c <= 'z'; c++)
   printf("%c %2.2f\n", c, 100*(let_cnt[c]/(double)total_chars));
}

