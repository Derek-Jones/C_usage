
extern int f1(int);
extern int f2();
extern int f3(char, ...);

extern int ar[99];

int glob;

void f(void)
{
char blaaa[22];

char c = '3';

glob=c+glob;
glob=(long)glob;
}
