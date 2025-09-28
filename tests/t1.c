
int f(void)
{
int i;
unsigned int ui;
signed int si;
switch (ui)
   {
   int nested_1;
   case 1: case 3: i--;
   
   case 0xffff: i++;
   
   default: break;
            {
	    int nested_2;
	    }
   }

switch (si)
   {
   case 2: case 3: i--;
   
   case -1: i++;
   
   case 99: break;
   }

return;
}

void f2(void)
{
enum LOC_E {q, w, r, t};
struct LOC_TAG {
               int mem_1;
	       };
typedef int LOC_INT;
}

