char c;
short s;
int i;
volatile long l;
float f;
double a[3];
char *p;

void func(void)
{
c=i+l;
f=c << l;
l=s % 2;
c=a[2] ? 'w' : 2;
l=!s;
p++;
(*p)--;
}

