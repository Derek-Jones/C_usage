                       /* decl.y, 28 Apr 06 */

%glr-parser

%token
INT
IDENT

%{
#include <ctype.h>
#include <stdio.h>

static const char *input = "I j; I k;";

#define YYSTYPE char *
#define YYDEBUG 1

int seen_decl = 0;

static void yyerror (const char *s)
{
  printf ("%s\n", s);
}

static int yylex (void);
%}

%%

TU:
	translation_unit
	{
	puts($1);
	}                 ;

translation_unit:
              declaration
              {
	      printf("seen declaration\n");
	      seen_decl=1;
	      }         ;

declaration:
              declaration_specifiers            ';' %dprec 1
              { }         |
              declaration_specifiers declarator ';' %dprec 2
              { }         ;

declaration_specifiers:
              type_specifier
              { }         |
              declaration_specifiers type_specifier
              { }         ;

type_specifier:
              INT
              { }         |
              typedef_name
              { }         ;

declarator:
              IDENT  %dprec 2
              { }         ;

typedef_name:
              IDENT  %dprec 1
              { }         ;

%%

static int yylex (void)
{
char c;

if (seen_decl)
   return 0; /* return 'EOF' if seen a declaration */

c = (*input ? *input++ : 0);
  
while (isspace(c))
   c = *input++;

asprintf (&yylval, "%c", c);
printf("> %c\n",  c);
return (c == 'I') ? INT : (isalpha(c) ? IDENT : c);
}

int main (void)
{
yydebug=1;

printf ("%i\n", yyparse ());
}

