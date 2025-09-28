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
// 01/08/93 RBR   Module initially created and tested.
//
//---------------------------------------------------------------------------
#include "stdlib.h"
#include "string.h"

#include "ldist.h"


static int l_dist_raw(char *str1, char *str2, int len1, int len2);


//---------------------------------------------------------------------------
// is_alike()
//---------------------------------------------------------------------------
int is_alike(char *str1, char *str2, int *threshold, int *ldist)
{
   int len1, len2;

   len1 = strlen(str1);
   len2 = strlen(str2);

   *threshold = 1 + ((len1 + 2) / 4);
   *ldist = LENGTH_MISMATCH;

   if (abs(len1-len2) <= *threshold)
   {
      len1 = min(len1, MAX_LDIST_LEN);
      len2 = min(len2, MAX_LDIST_LEN);
   
      if ((*ldist = l_dist_raw(str1, str2, len1, len2)) <= *threshold)
         return(ALIKE);
   }
   return(NOT_ALIKE);
}



//---------------------------------------------------------------------------
// l_dist_list()
//---------------------------------------------------------------------------
int l_dist_list(char *key,
                char **list,
                char **match,
                int dist[],
                int match_limit,
                int *threshold)
{
   int i, j, k, key_len, l_dist, len, num;
   
   key_len = strlen(key);
   key_len = min(key_len, MAX_LDIST_LEN);
   *threshold = 1 + ((key_len + 2) / 4);

   num = 0;
   for (k=0; list[k][0]; k++)
   {
      len = strlen(list[k]);
      len = min(len, MAX_LDIST_LEN);

      if (abs(key_len-len) <= *threshold)
      {
         // calculate the distance
         l_dist = l_dist_raw(key, list[k], key_len, len);

         // is this acceptable?
         if (l_dist <= *threshold)        // is it in range to consider
         {
            // search the list to see where we should insert this result
            for (i=j=0; i<num && !j; )
               if (l_dist < dist[i])
                  j = 1;
               else
                  i++;        // do not increment when we find a match

            // i points to the next higher valued result if j=1, otherwise
            // i points to the end of the list, insert at i if in range

            // found a higher valued (worse) result or list not full
            if (j || i < match_limit-1)
            {                             // insert in front of higher results

               for (j=min(match_limit-2,num-1); j>=i; j--)
               {
                  match[j+1] = match[j];
                  dist[j+1]  = dist[j];
               }
               match[i] = list[k];
               dist[i]  = l_dist;
               if (num < match_limit) num++;
            }

         }  // if l_dist <= threshold

      }  // if len diff <= threshold

   }  // for k

   return(num);
}



//---------------------------------------------------------------------------
// l_dist_raw()
//    static/local function !!!
//
// Purpose: Calculates the L Distance for the two strings (words).
//
// Inputs:  char *str1, *str2 - input strings (words) to compair
//          int len1,len2     - the shorter of the length of str1 amd str2
//                              respectively or MAX_LDIST_LEN.
//                              NOTE! No error checking is done.
//                                    Array overflow on the stack will result
//                                    if either is out of range.
// Outputs: none
//
// Returns: L Distance value is returned
//
// Note, there are two defines immediately after this comment header that
// are only used by this function.
//
// (values in all CAPS are defined in the LDIST.H header file)
//
//---------------------------------------------------------------------------
#define SMALLEST_OF(x,y,z)       ( (x<y) ? min(x,z) : min(y,z) )
#define ZERO_IF_EQUAL(ch1,ch2)   ( (ch1==ch2) ? 0 : CHANGE )

static int l_dist_raw(char *str1, char *str2, int len1, int len2)
{
   register int i, j;
   unsigned int dist_im1[MAX_LDIST_LEN+1];
   unsigned int dist_i_j, dist_i_jm1, dist_j0;
   char *p1, *p2;

   for (i=1, dist_im1[0]=0; i<=MAX_LDIST_LEN; i++)
      dist_im1[i] = dist_im1[i-1] + ADDITION;
   dist_j0 = 0;

   for (i=1, p1=str1; i<=len1; i++, p1++)
   {
      dist_i_jm1 = dist_j0 += DELETION;
      for (j=1, p2=str2; j<=len2; j++, p2++)
      {
         dist_i_j = SMALLEST_OF(dist_im1[j-1] + ZERO_IF_EQUAL(*p1, *p2),
                                dist_i_jm1    + ADDITION,
                                dist_im1[j]   + DELETION );
         dist_im1[j-1] = dist_i_jm1;
         dist_i_jm1 = dist_i_j;
      }
      dist_im1[j] = dist_i_j;
   }

   return(dist_i_j);
}

