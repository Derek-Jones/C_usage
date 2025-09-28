
%glr-parser

%token
INT
ID

%{
#include <ctype.h>
#include <stdio.h>

static const char *input = "a b c (( d ));";

#define YYSTYPE char *
#define YYDEBUG 1


static void yyerror (const char *s)
{
  printf ("%s\n", s);
}

static int yylex (void);
%}

%%


TU:
	translation_unit
	{ }                   ;

translation_unit:
              external_declaration  %dprec 1
              { }        ;

declaration:
              declaration_specifiers                      ';' %dprec 1
              { }                                           |
              declaration_specifiers init_declarator_list ';' %dprec 2
              { }                                           ;

decl_specifier:
              typedef_name
              { }            ;

declaration_specifiers:
              decl_specifier
              { }            |
              declaration_specifiers decl_specifier
              { }            ;

init_declarator_list:
              declarator
              { }                    ;

pointer_opt:
              { }          |
              '*'
              { } ;
declarator:
              pointer_opt direct_declarator
              { } ;

direct_declarator:
              ID       %dprec 2
              { }                |
              '(' declarator ')'
              { }                |
              direct_declarator '(' parameter_type_list ')' %dprec 2
              { }                |
              direct_declarator '(' '(' parameter_type_list ')' ')'
              { }                ;

parameter_type_list:
              declaration_specifiers declarator          %dprec 2
              { }              |
              declaration_specifiers                     %dprec 1
              { }              ;

typedef_name:
              ID
              { } ;

external_declaration:
              declaration
              { }     ;

%%

static int yylex (void)
{
char c;

c = (*input ? *input++ : 0);
  
while (isspace(c))
   c = *input++;

asprintf (&yylval, "%c", c);
printf("> %c\n",  c);
return (c == 'I') ? INT : (isalpha(c) ? ID : c);
}

int main (void)
{
yydebug=1;

printf ("%i\n", yyparse ());
}

