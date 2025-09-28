
#include <stdio.h>

#include "stdio.h"

#include "_H_.h"

static int statc;
extern int statc;

const int ci;
const int * const cpci;
const int a[20];

struct s_tag {
             int member;
	     char arr_mem[4];
	     struct nest_tag {
	     		      int nest_mem;
			     } mem_3;
	     struct nest_tag *mem_4;
	     } s_obj;

volatile struct s_tag vs_obj;

const volatile cv;
volatile const vc;
const c;

int f(int p, ...)
{
static int stat;
int loc = 99;
struct s_tag *vs_loc;

vs_loc->member++;
vs_loc->mem_4->nest_mem++;
vs_obj.mem_4->nest_mem++;
(vs_obj).member++;
vs_obj.member++;
vs_obj.arr_mem[2]++;

loc--;

goto L;
f(1);

L:return 1;

goto L;
}

extern void h(void);

void g(void)
{
h();
if (cv) {cv;}
}

void h(void)
{
g();
}

extern int ext_func(void)
{
return 3;
}

static int int_func(void)
{
}

extern ext_func_decl(void);

