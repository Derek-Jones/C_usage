
extern char glob_c;
extern unsigned short glob_us;
extern int glob_i;
extern long glob_l;

extern int *glob_pi;
extern int **glob_ppi;
extern int *glob_aapi[2][4];
extern const int glob_ci;
extern const int volatile glob_civ;
extern char glob_ac[10];

extern float glob_f;
extern double glob_d;
extern long double glob_ld;
extern int (*pf)(void);

struct {
	int mem1;
       } glob_s;

enum { e1, e2} glob_e;

void f(void)
{
static int si;
char c;
}

