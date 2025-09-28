int a[2][4];
struct st {
          int m0;
	  int m1[3];
	  struct {
	          int m21;
		 } m2;
	  } so1,
	    so2[3];

int glob,
    glob1,
    glob2,
    glob3,
    glob4,
    glob5;
int bolg,
    bolg1,
    bolg2,
    bolg3,
    bolg4,
    bolg5;

extern int g();

void f(void)
{
int loc=glob;
a[3][4]=2;
a[glob1][glob2]=2;
so1.m0=3;
so1.m1[glob3]=99;
so2[glob4].m1[glob5]=1;

so1.m0=g(bolg, bolg1, bolg2);
so1.m1[g(bolg3)]=8;
}

