                      /* keydist.c, 10 Dec 03 */

/*
 * Modified from ###
 */

#include <stdlib.h>
#include <math.h>
#include <string.h>


/* sqrt( 13**2 + 3**2 ) */
#define MAX_KBD_DISTANCE 13.34166406412633371248

/* character map for fast lookups... */
#define X_POS 0
#define Y_POS 1
#define GRID_WIDTH 15
#define GRID_HEIGHT 4

double qwertyMap[0xFF][2];

char qwertyGrid[GRID_HEIGHT][GRID_WIDTH] = {
  "`1234567890-= ",
  "\tqwertyuiop[]",
  " asdfghjkl;'# ",
  "\\zxcvbnm,./   ",
};

char qwertyShiftedGrid[GRID_HEIGHT][GRID_WIDTH] = {
  "~!\"#$%^&*()_+ ",
  "\tQWERTYUIOP{} ",
  " ASDFGHJKL:@~ ",
  "|ZXCVBNM<>?   ",
};

/*
The formula used in the original
#define GRID_DISTANCE(x1,y1,x2,y2) ((x1 == x2 && y1 == y2) ? \
                                      0 :		     \
				      (1 == abs(x1-x2) && 1 == abs(y1-y2)) ? 1 : sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)))
*/

#define GRID_DISTANCE(x1,y1,x2,y2) sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))

#define qwerty_char_distance(c1, c2) \
	GRID_DISTANCE(qwertyMap[c1][X_POS], qwertyMap[c1][Y_POS], \
                      qwertyMap[c2][X_POS], qwertyMap[c2][Y_POS])

/*
 * double key_dist(char* str_1, char * str_2)
 *
 * The function modifies both str_1 and str_2.
 */
double key_dist(void)
{
double distance = 0.0;
char *s_1 = str_1;

while ((*str_1 != 0) && (*str_2 != 0))
   {
   distance += qwerty_char_distance(*s_1, *str_2);
   /*
   printf("dist(%c,%c) = %f\n", *s_1, *str_2, dist);
    */
   s_1++;
   str_2++;
   }

while (*s_1 != 0)
   {
   s_1++; 
   distance += MAX_KBD_DISTANCE;
   }

while (*str_2 != 0)
   {
   str_2++; 
   distance += MAX_KBD_DISTANCE;
   }

return distance;
}

void init_qwerty_map(void)
{
int x,
    y;
char ch;

/*
 * The y*0.5 is an approximation to the staggering between
 * keys on adjacent rows.
 */
for (x = 0; x < GRID_WIDTH; x++)
   {
   for (y = 0; y < GRID_HEIGHT; y++)
      {
      ch = qwertyGrid[y][x];
      qwertyMap[ch][X_POS] = x+y*0.5;
      qwertyMap[ch][Y_POS] = y;

      ch = qwertyShiftedGrid[y][x];
      qwertyMap[ch][X_POS] = x+y*0.5;
      qwertyMap[ch][Y_POS] = y;
      }
   }
}

#if LEVKEY_DIST == 0
void init_distance(void)
{
init_qwerty_map();
}
#endif

