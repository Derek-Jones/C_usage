#include <stdio.h>

extern int glob;
struct T {
          int mem;
         };

int main(void)
{
int i = 0;

START_LOOP:
if (i == 10)
   goto END_LOOP;

i++;
   int      loc_1 = glob;
   struct T loc_2 = { 1 },             loc_3 = { glob },
           *ploc_a = &(struct T){ 1 }, *ploc_b = &(struct T){ glob };

            loc_1++;
            loc_2.mem++;               loc_3.mem++;
            ploc_a->mem++;             ploc_b->mem++;

goto START_LOOP;
END_LOOP:;

if (       (loc_1 != (glob+1))  ||
           (loc_2.mem != 1+1)   ||    (loc_3.mem != (glob+1)) ||
           (ploc_a->mem != 1+1) ||    (ploc_b->mem != (glob+1)))
   printf("This is not a conforming implementation\n");
}
