
#include <errno.h>
#include <math.h>
#include <stdio.h>

double gf;
FILE *io;

int f(void)
{
errno=0;
gf=tan(1.0);

if (gf < 0.5)
   gf++;

errno=3;

gf=log(1.0);

errno=0;
io=fopen("abc", "r");

if (io == 0)
   gf++;

errno=2;
}

