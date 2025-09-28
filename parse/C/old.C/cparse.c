
#include <stdio.h>

extern int yyparse(void);
extern int yydebug;

void cnt_rule(void)
{
}
     
void yyerror (const char *s)  /* Called by yyparse on error */
{
printf ("%s\n", s);
}


int main(void)
{

yydebug=0;
next_ch();

printf("parse result =%d\n", yyparse());
}

