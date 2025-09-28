%glr-parser
%token
INT
IDENT

%{
#include <ctype.h>
#include <stdio.h>

static const char *input = "I j(k);";   // int j(k);

#define YYSTYPE char *
#define YYDEBUG 1

static void yyerror (const char *s)
{
  printf ("%s\n", s);
}

static int yylex ();
%}

%%

TU:
	translation_unit
	{ }                   ;

translation_unit:
              declaration
              { }        ;

declaration:
              declaration_specifiers                 ';' %dprec 1
              { }                                           |
              declaration_specifiers init_declarator ';' %dprec 2
              { }                                           ;

decl_specifier:
              type_specifier
              { }            ;

declaration_specifiers:
              decl_specifier
              { }            |
              declaration_specifiers decl_specifier
              { }            ;

init_declarator:
              direct_declarator
              { }                    ;

type_specifier:
              INT
              { }           |
              typedef_name
              { }           ;

direct_declarator:
              IDENT                                         %dprec 2
              { }                |
              '(' direct_declarator ')'
              { }                |
              direct_declarator '(' identifier_list ')'
              { }                ;

identifier_list:
              IDENT
              { }                       |
              identifier_list ',' IDENT
              { } ;

typedef_name:
              IDENT                                         %dprec 1
              { } ;

%%

static int yylex (void)
{
char c;

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

