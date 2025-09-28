
char (*f(int x))[sizeof x];

int main(void)
{
printf("%d\n", sizeof(*f));
}

