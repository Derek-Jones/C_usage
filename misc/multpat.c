                        /* multpat.c, 15 Dec 08 */

/*
 * Count the number of values that occur from all combinations
 * of multiplication values possible using X bits.
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_OPRAND 65535u

#define MAX_IND (((MAX_OPRAND*MAX_OPRAND) >> 3) + 1)

unsigned char mult_result[MAX_IND];

unsigned char bit_count[] = {
                             0, 1, 1, 2, 1, 2, 2, 3,
                             1, 2, 2, 3, 2, 3, 3, 4};

unsigned int results_from(int max_bits)
{
unsigned int i, j;
unsigned int num_seen = 0;
unsigned int max_oprand = ((0x01 << max_bits)-1);
unsigned int max_index = (max_oprand*max_oprand) >> 3;

for (i=0; i <= max_oprand; i++)
   {
   for (j=i; j <= max_oprand; j++)
      mult_result[(i*j) >> 3] |= 0x01 << ((i*j) & 0x07);
   }

for (i=0; i <= max_index; i++)
   if (mult_result[i] != 0xff)
      num_seen += bit_count[mult_result[i] >> 4] +
                  bit_count[mult_result[i] & 0x0f];
   else
      num_seen += 8;

return num_seen;
}

int main(void)
{
unsigned i;

for (i=1; i <= 16; i++)
   printf("Results from %2d: %10d\n", i, results_from(i));

}

