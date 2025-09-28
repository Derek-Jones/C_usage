                         /* 242.c, 18 Sep 07 */
#include <stdio.h>

int main(int argc, char *argv[])
{
if (argc > 1)
   printf("%c%s%c", 242, argv[1], 242);
else
   printf("%c%c", 242, 242);
}

