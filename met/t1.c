
#if BLAH
#endif

void f_proto(int);
void f_old();

struct s_tag { int mem;};

struct s_tag f_struct(void);

static void f_int1(void);
static void f_int1(void);

extern int ext_int;
static int glob_int;

typedef int glob_type;
struct glob_tag { int mem;};


int a3[2][3][4];

int g_proto(long p)
{
int init_loc = ext_int;
char a[] = { 1, 2, 3};
int *ptr = &ext_int;

typedef int I;
struct s_tag  sv;
struct s_tag *svp;
struct s_tag  sva[2];

goto Label;

svp=(struct s_tag *)0;
a[3]=4;
a[2]++;
*(ptr+1)=2;
f_old(ext_int, 1, glob_int++);
if (a[2] == 1)
  a[a[ext_int]]--;

Label:;

goto Label;

glob_int=1;
ext_int++;
sv.mem=1;
svp->mem=2;
sva[2].mem=3;
glob_int=f_struct().mem;

   {
   enum et {E1, E2} ev;
   ev=E1;
   goto Label;
   }
}

void g_old(a)
int a;
{
}

