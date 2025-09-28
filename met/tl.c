struct {
        int l:3;
	char c;
       } x;

static int glob_1;
static int glob_2 = 3;

void f(void)
{
L:;

if (glob)
   goto L;
}

