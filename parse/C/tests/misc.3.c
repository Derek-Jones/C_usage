
typedef int foo, bar, lose;
void g(void)
{
static foo (bar);        /* redeclare `bar' as static variable */
static int foo (lose);   /* redeclare `foo' as function */
}
