
struct foo {
       int f_1;
       char f_2;
       float f_3;
       } x;

void (*f(char *p[sizeof(struct foo {long l;})]))(struct foo);
void (*f(char (*p)[sizeof(struct foo {long l;})]))(struct foo)
{
}

int main(void)
{
void * pv;
f(pv);

}

