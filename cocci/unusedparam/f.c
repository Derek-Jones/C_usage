
int g;

void f1(int x1)
{
g++;
if (g)
   {
   x1++;
   }
}

void f2(int x2)
{
g++;
--g;
}

void f_p2_1(char c1, char c2)
{
c2++;
}

void f_p2_2(char c1, char c2)
{
c1++;
}

void f_p2_all(char c1, char c2)
{
g++;
}

