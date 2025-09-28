
#include <stdio.h>

 long l1 = 'abcd';  // note single quotes
 char * s = "dcba";

int main(void)
{
 long * lptr = ( long * )s;
 long l2 = *lptr;

printf("%d   %d\n", l1, l2);
}

