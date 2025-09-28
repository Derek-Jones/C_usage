
int a[10];

void f(int *);

int main(void)
{
f(a[1]);
f(&a[1]);

&a[2]=2;
}

