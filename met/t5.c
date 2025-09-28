
extern int ext_int;
void f_old();

int g_proto(long p)
{
char a[] = { 1, 2, 3};
int *ptr = &ext_int;

a[3]=4;
*(ptr+1)=2;
/*
a[2]++;
if (a[2] == 1)
  a[a[ext_int]]--;
*/
}

