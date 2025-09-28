                       /* sizeof.y,  1 May 06 */

%glr-parser

%token
ID


%{
#include <ctype.h>
#include <stdio.h>

static const char *input = "(x)*S(y);";

#define YYSTYPE char *

static void yyerror (const char *s)
{
  printf ("%s\n", s);
}

static YYSTYPE multiplicative_merge(YYSTYPE a, YYSTYPE b)
{
char *s;
asprintf (&s, "\n{ %s %s }\n\t", a, b);
  
printf("multiplicative_merge\n");
return s;
}

static YYSTYPE sizeof_merge(YYSTYPE a, YYSTYPE b)
{
char *s;
asprintf (&s, "\n{ %s %s }\n\t", a, b);
  
printf("sizeof_merge\n");
return s;
}

static int yylex (void);
%}

%%


TU:
	translation_unit
	{
	}                   ;

translation_unit:
              statement
              { }        ;

primary_expr:
              ID
              { }                      |
              '(' expression ')'
              { }                      ;

postfix_expr:
              primary_expr
              { }                      ;

unary_expr:
              postfix_expr
              { }                 |
              '*' cast_expr
              { }                 |
              'S' unary_expr                   %merge <sizeof_merge>
              {
	       printf("S unary_expr\n");
	       }                 |
	      'S' '(' type_specifier ')'       %merge <sizeof_merge>
              {
	       printf("S ( type_specifier )\n");
	       }                 ;

cast_expr:
              unary_expr                         %dprec 1
              { }                             |
              '(' type_specifier ')' cast_expr   %dprec 2
              { }                             ;

multiplicative_expr:
              cast_expr                         %merge <multiplicative_merge>
              { }                         |
              multiplicative_expr '*' cast_expr %merge <multiplicative_merge>
              { }                         ;

expression:
              multiplicative_expr
              { }                     ;

type_specifier:
              typedef_name
              {
              }           ;

typedef_name:
              ID  %dprec 1
              { } ;

statement:
              expression ';'
              {
              printf("%s\n", "statement\n");
              } ;

%%


static int yylex (void)
{
  char c = *input ? *input++ : 0;
  asprintf (&yylval, "%c", c);
  return (isalpha(c) && (c != 'S')) ? ID : c;
}

int main (void)
{
yydebug=1;
printf ("%i\n", yyparse ());
}

