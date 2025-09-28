// Levenstein Distance Algorithms Module
//
// Contains functions to do "Inexact Alphanumeric Comparisons".  The original
// concept for this code came from "The C Users Journal", May 1991, starting
// on page 127.  The author was Hans Z. Zwakenberg.
//
// These routines have been modified so they do not need to use double
// subscripted arrays in the CUJ code.  An additional function was created to
// "look up" a word from a list, returning the most likely matches.
//
// Written initailly by R. Bruce Roberts, MCI Systems Engineering, 1/7/93
// Compiled with Borland C++, V3.1
//
//---------------------------------------------------------------------------
// Revision History:
//
// Date     Ini   Comments
// -------- ---   ---------------
// 10/12/03 DMJ   Modified to use CHANGE_DIST
// 30/07/03 DMJ   Made stand alone and tidied up a few things
// 01/08/93 RBR   Module initially created and tested.
//
//---------------------------------------------------------------------------
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "keydist.c"

#define MAX_LDIST_LEN      75 // max word len to compair

#define ADDITION           2  // penality for needing to add a character
#define CHANGE             2  // penality for needing to modify a character
#define DELETION           2  // penality for needing to delete a character

#define MIN(x, y) ((x < y) ? x : y)
#define SMALLEST_OF(x, y, z) ((x<y) ? MIN(x, z) : MIN(y, z))
#define CHANGE_DIST(ch1, ch2) change_dist[ch1][ch2]

unsigned char change_dist[128][128];

/*
 * Optimized for repeatedly calling with the same first string
 *
 * int lev_dist(char *str_1, int len_str_1, char *str_2)
 */
int levkey_dist(void)
{
const int len2= strlen(str_2);
int i,
    j;
unsigned int dist_im1[MAX_LDIST_LEN+1];
unsigned int dist_i_j,
	     dist_i_jm1,
	     dist_j0;
char *p1,
     *p2;

dist_im1[0]=0;
for (i=1; i<=MAX_LDIST_LEN; i++)
   dist_im1[i] = dist_im1[i-1] + ADDITION;
   
dist_j0 = 0;
for (i=1, p1=str_1; i<=len_str_1; i++, p1++)
   {
   dist_i_jm1 = dist_j0 += DELETION;
   for (j=1, p2=str_2; j<=len2; j++, p2++)
      {
      dist_i_j = SMALLEST_OF(dist_im1[j-1] + CHANGE_DIST(*p1, *p2),
                             dist_i_jm1    + ADDITION,
                             dist_im1[j]   + DELETION );
      dist_im1[j-1] = dist_i_jm1;
      dist_i_jm1 = dist_i_j;
      }
   dist_im1[j] = dist_i_j;
   }

return dist_i_j;
}

void init_distance(void)
{
int x, y,
    v, w;
double ch_dist;
char ch1,
     ch2;

init_qwerty_map();

/*
 * Give all character pairs the default change distance.
 */
for (x=0; x < 128; x++)
   for (y=0; y < 128; y++)
      change_dist[x][y]=CHANGE;

/*
 * Loop over all characters on the keyboard (the implementation
 * of qwerty_char_distance does not handle arbitrary characters)
 * calculating the distance to all other characters on the
 * keyboard.
 *
 *   1) Adjacent keys (ie distance less than 2) are given
 *      a reduced change distance.
 *   2) A character has a change distance of 1 to any
 *      corresponding upper case character.
 *   3) 'boundary' characters...
 */
for (v=0; v < GRID_WIDTH; v++)
   for (w=0; w < GRID_HEIGHT; w++)
      {
      ch1=qwertyGrid[w][v];
      if (islower(ch1))
         {
         change_dist[toupper(ch1)][toupper(ch1)]=0;
         change_dist[ch1][toupper(ch1)]=1;
         change_dist[toupper(ch1)][ch1]=1;
	 }
      for (x=0; x < GRID_WIDTH; x++)
         for (y=0; y < GRID_HEIGHT; y++)
	    {
            ch2=qwertyGrid[y][x];
            ch_dist=qwerty_char_distance(ch1, ch2);
	    if (ch_dist < 1.5) /* adjacent characters */
	       if (ch_dist < 1)
	          change_dist[ch1][ch2]=0; /* the same character */
	       else
	          change_dist[ch1][ch2]=1;
	    }
      }

/*
printf("g %f,%f\n", qwertyMap['g'][0], qwertyMap['g'][1]);
printf("c %f,%f\n", qwertyMap['c'][0], qwertyMap['c'][1]);
printf("v %f,%f\n", qwertyMap['v'][0], qwertyMap['v'][1]);
printf("b %f,%f\n", qwertyMap['b'][0], qwertyMap['b'][1]);
printf("n %f,%f\n", qwertyMap['n'][0], qwertyMap['n'][1]);
printf("g c %f\n", qwerty_char_distance('g', 'c'));
printf("g v %f\n", qwerty_char_distance('g', 'v'));
printf("g b %f\n", qwerty_char_distance('g', 'b'));
printf("g n %f\n", qwerty_char_distance('g', 'n'));

printf("g g %d\n", change_dist['g']['g']);
printf("g h %d\n", change_dist['g']['h']);
printf("h g %d\n", change_dist['h']['g']);
*/
}

