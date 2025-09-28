/*
 *  IsoCpp.btyacc
 *
 *  Copyright (C) 2000-2004 by
 *
 *    Department of Computer Science, Clemson University,
 *    Department of Computer Science, National University of Ireland, Maynooth.
 * 
 *  http://keystone.sourceforge.net
 *
 *  <keystone@cs.clemson.edu>
 *
 *  Keystone is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  Keystone is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

%{
  #include "config.h"

  #define TRUE 1
  #define YYDELETEVAL(v,n) 
  #define YYERROR_DETAILED 1

  #include "BtYaccPosn.h"

  #ifdef KEY_YACC_DEBUG
    #define YYDEBUG 1
    #define KEY_YYERROR_DEBUG 1
  #endif

  #include <iostream>
  #include <string>

  #include "NameDeclaration.h"
  #include "Type.h"
  #include "Scope.h"
  #include "NamespaceScope.h"
  #include "PrototypeScope.h"
  #include "TemplateParameterScope.h"

  #include "NameOccurrence.h"
  #include "Parser.h"

  #include "ActionFacade.h"
  #include "ArgumentStack.h"
  #include "ContextManager.h"
  #include "DeclarationStack.h"
  #include "KeywordManager.h"
  #include "LocationTracker.h"
  #include "Actions.h"
  #include "TokenDecorator.h"

  #include "ParserUtility.h"

  extern char *yytext;

  namespace btyacc
  {
    Actions*        actions;
    TokenDecorator* decorator;
    ActionFacade*   facade;
    ContextManager* contextManager;

    void resetBtYacc ( void )
    {
      actions        = Parser::Instance()->actions();
      decorator      = Parser::Instance()->decorator();
      facade         = Parser::Instance()->facade();
      contextManager = Parser::Instance()->contextManager();
    }
  }
%}

%union {  
  int tcount;

  std::string *name;

  struct TokenInfo       *id_sym;
  class  NameDeclaration *decl;

  DeclSpecifier_t     *dspec;
  DeclSpecifierList_t *dscont;

  eOperator optype;

  ArrayDimensionList_t *arrdims;
  BaseClassPair_t      *bclass;
  ClassPair_t          *memdecl;
  ClassPairList_t      *memdecls;
  EnumeratorList_t     *enumcont;
  ExpressionList_t     *expcont;
  HandlerList_t        *handcont;
  BaseClassList_t      *inhcont;
  NewDeclarationPair_t *newdecl;
  AsgNodeList_t        *asgcont;
  ThrowList_t          *typcont;

  class cAsgNode                *stmt;
  class cIdentifier             *ident;
  class cType                   *ctype;
  class cClassTypeInterface     *cti;
  class cTemplateParameter      *tparm;
  class cBlock                  *block;
  class cHandler                *cblock;
  class cObject                 *obj;
  class cFunctionParameter      *parm;
  class cExceptionDeclaration   *cfcp;
  class cEnumerator             *endef;
  class cExpressionBase         *exprbase;
  class cExpression             *expr;
  class cNameReference          *nameref;
  class cInitializerList        *init;
  class cFunctionArgumentList   *paramlist;
  class cExceptionSpecification *tspec;
  class cFunctionParameterList  *argcont;
  class cTemplateParameterList  *tparmlist;
}

%include Terminals.y
%include Nonterminals.y

%start translation_unit

%%

// ********** K.1  Keystone Modifications **********

              any_identifier
/* K.1.001 */   : ID_typedef_name
                    { $$ = $1; }
/* K.1.002 */   | ID_original_namespace_name
                    { $$ = $1; }
/* K.1.003 */   | ID_namespace_alias
                    { $$ = $1; }
/* K.1.004 */   | ID_enum_name
                    { $$ = $1; }
/* K.1.005 */   | ID_class_name
                    { $$ = $1; }
/* K.1.006 */   | ID_template_name
                    { $$ = $1; }
/* K.1.007 */   | IDENTIFIER
                    { $$ = $1; }
                ;

              any_identifier_or_template
/* K.1.008 */   : any_identifier
                    { $$ = btyacc::actions->class_name( $1 ); }
/* K.1.009 */   | template_id
                    { $$ = $1; }
                ;


// ********** A.1  Keywords  [gram.key] **********

              typedef_name
/* A.1.001 */   : ID_typedef_name
                    { $$ = $1; }
                ;

              namespace_name
/* A.1.002 */   : original_namespace_name
                    { $$ = $1; }
/* A.1.003 */   | namespace_alias
                    { $$ = $1; }
                ;

              original_namespace_name
/* A.1.004 */   : ID_original_namespace_name
                    { $$ = $1; }
                ;

              namespace_alias
/* A.1.005 */   : ID_namespace_alias
                    { $$ = $1; }
                ;

              class_name
/* A.1.006 */   : ID_class_name
                    { $$ = btyacc::actions->class_name( $1 ); }
/* A.1.007 */   | template_id
                    { $$ = $1; }
                ;

              enum_name
/* A.1.008 */   : ID_enum_name
                    { $$ = $1; }
                ;

              template_name
/* A.1.009 */   : ID_template_name
                    { $$ = $1; }
                ;


// ********** A.2  Lexical conventions  [gram.lex] **********

   // Flex lexer defined in IsoCpp.flex

              boolean_literal
/* A.2.001 */   : KW_true
                    { $$ = new std::string( "true" );  }
/* A.2.002 */   | KW_false
                    { $$ = new std::string( "false" ); }
                ;


// ********** A.3  Basic concepts  [gram.basic] **********

              translation_unit
/* A.3.001 */   :   { btyacc::actions->translation_unit_1();     }
                  declaration_seq_opt
                    { btyacc::actions->translation_unit_2( $2 ); }
                ;


// ********** A.4  Expressions  [gram.expr] **********

              primary_expression
/* A.4.001a */  : INTEGER_LITERAL
                    { $$ = btyacc::actions->primary_expression_literal( LT_INT, $1->getName() );  }
/* A.4.001b */  | CHARACTER_LITERAL
                    { $$ = btyacc::actions->primary_expression_literal( LT_CHAR, $1->getName() ); }
/* A.4.001c */  | FLOATING_LITERAL
                    { $$ = btyacc::actions->primary_expression_literal( LT_REAL, $1->getName() ); }
/* A.4.001d */  | STRING_LITERAL
                    { $$ = btyacc::actions->primary_expression_literal( LT_STR, $1->getName() );  }
/* A.4.001e */  | boolean_literal
                    { $$ = btyacc::actions->primary_expression_literal( LT_BOOL, (*$1) ); }
/* A.4.002 */   | KW_this
                    { $$ = btyacc::actions->primary_expression_this();       }
/* A.4.003 */   | LEFTPAREN expression RIGHTPAREN
                    { $$ = btyacc::actions->primary_expression_parens( $2 ); }
/* A.4.004 */   | id_expression
                    { $$ = $1; }
                ;

              id_expression
/* A.4.005 */   : unqualified_id
                    { $$ = $1; }
/* A.4.006 */   | qualified_id
                    { $$ = $1; }
                ;

              unqualified_id
                  // not any_identifier, cannot have ::
/* A.4.007 */   : IDENTIFIER
                    { $$ = btyacc::actions->unqualified_id( $1 ); }
/* A.4.008 */   | operator_function_id
                    { $$ = btyacc::actions->unqualified_id( $1 ); }
/* A.4.009 */   | conversion_function_id
                    { $$ = $1; }
/* A.4.010 */   | COMPLEMENT class_name
                    { $$ = btyacc::actions->unqualified_id_destructor( $2 ); }
/* A.4.011 */   | template_id
                    { $$ = $1; }
                ;

              qualified_id
/* A.4.012 */   : colcol_opt nested_name_specifier template_opt unqualified_id
                    { $$ = btyacc::actions->qualified_id_nns( $1, $2, $3, $4 ); }
                  // not any_identifier, must have ::
/* A.4.013 */   | COLCOL IDENTIFIER
                    { $$ = btyacc::actions->qualified_id( $2 ); }
/* A.4.014 */   | COLCOL operator_function_id
                    { $$ = btyacc::actions->qualified_id( $2 ); }
/* A.4.015 */   | COLCOL template_id
                    { $$ = btyacc::actions->qualified_id_template( $2 ); }
                ;

              nested_name_specifier
/* A.4.016 */   : class_or_namespace_name COLCOL nested_name_specifier_opt
                    { $$ = btyacc::actions->nested_name_specifier( $1, false, $3 ); }
/* A.4.017 */   | class_or_namespace_name COLCOL KW_template nested_name_specifier
                    { $$ = btyacc::actions->nested_name_specifier( $1, false, $4 ); }
                ;

              class_or_namespace_name
/* A.4.018 */   : class_name
                    { $$ = $1; }
/* A.4.019 */   | namespace_name
                    { $$ = btyacc::actions->class_or_namespace_name( $1 ); }
                ;

              postfix_expression
/* A.4.020 */   : primary_expression
                    { $$ = $1; }
/* A.4.021 */   | postfix_expression LEFTARRAY expression RIGHTARRAY
                    { $$ = btyacc::actions->postfix_expression_array( $1, $3 ); }
/* A.4.022 */   | postfix_expression
                    { btyacc::actions->postfix_expression_start_function(); }
                  LEFTPAREN expression_list_opt RIGHTPAREN
                    { $$ = btyacc::actions->postfix_expression_end_function($1, $4); }
/* A.4.023 */   | simple_type_specifier LEFTPAREN
                    [
                      if ( btyacc::decorator->getLastIdentifier() )
                      {
                        if ( btyacc::decorator->getLastIdentifier()->markedTemplate() )
                        {
                          #ifdef KEY_YYERROR_DEBUG
                            std::cerr << "YYERROR 1a" << std::endl;
                          #endif
                          YYERROR;
                        }
                      }
                    ]
                  expression_list_opt RIGHTPAREN
                    { $$ = btyacc::actions->postfix_expression_cast($1, $4); }
/* A.4.024 */   | KW_typename colcol_opt nested_name_specifier any_identifier_or_template LEFTPAREN expression_list_opt RIGHTPAREN
                    { $$ = btyacc::actions->postfix_expression_cast_typename( $2, $3, $4, $6 ); }
/* A.4.025 */   | KW_typename colcol_opt nested_name_specifier template_opt template_id LEFTPAREN expression_list_opt RIGHTPAREN
                    { $$ = btyacc::actions->postfix_expression_cast_template( $2, $3, $4, $5, $7 ); }
/* A.4.026 */   | postfix_expression DOT template_opt id_expression
                    { $$ = btyacc::actions->postfix_expression_access( $1, OT_FIELD_ACCESS, $3, $4 ); }
/* A.4.027 */   | postfix_expression ARROW template_opt id_expression
                    { $$ = btyacc::actions->postfix_expression_access( $1, OT_POINTSAT, $3, $4 ); }
/* A.4.028 */   | postfix_expression DOT pseudo_destructor_name
                    { $$ = btyacc::actions->postfix_expression_access( $1, OT_FIELD_ACCESS, false, $3 ); }
/* A.4.029 */   | postfix_expression ARROW pseudo_destructor_name
                    { $$ = btyacc::actions->postfix_expression_access( $1, OT_POINTSAT, false, $3 ); }
/* A.4.030 */   | postfix_expression PLUSPLUS
                    { $$ = btyacc::actions->postfix_expression_unary( $1, OT_POST_INC ); }
/* A.4.031 */   | postfix_expression MINUSMINUS
                    { $$ = btyacc::actions->postfix_expression_unary( $1, OT_POST_DEC ); }
/* A.4.032 */   | KW_dynamic_cast LESS type_id GREATER LEFTPAREN expression RIGHTPAREN
                    { $$ = btyacc::actions->postfix_expression_cpp_cast( OT_DYNAM_CAST, $3, $6 ); }
/* A.4.033 */   | KW_static_cast LESS type_id GREATER LEFTPAREN expression RIGHTPAREN
                    { $$ = btyacc::actions->postfix_expression_cpp_cast( OT_STATIC_CAST, $3, $6 ); }
/* A.4.034 */   | KW_reinterpret_cast LESS type_id GREATER LEFTPAREN expression RIGHTPAREN
                    { $$ = btyacc::actions->postfix_expression_cpp_cast( OT_REINT_CAST, $3, $6 ); }
/* A.4.035 */   | KW_const_cast LESS type_id GREATER LEFTPAREN expression RIGHTPAREN
                    { $$ = btyacc::actions->postfix_expression_cpp_cast( OT_CONST_CAST, $3, $6 ); }
/* A.4.036 */   | KW_typeid LEFTPAREN expression RIGHTPAREN
                    { $$ = btyacc::actions->postfix_expression_unary( $3, OT_TYPE_ID ); }
/* A.4.037 */   | KW_typeid LEFTPAREN type_id RIGHTPAREN
                    { $$ = btyacc::actions->postfix_expression_unary_typeid( $3, OT_TYPE_ID ); }
                ;
          
              expression_list
/* A.4.038 */   : assignment_expression
                    { $$ = btyacc::actions->expression_list_start( $1 ); }
/* A.4.039 */   | expression_list COMMA assignment_expression
                    { $$ = btyacc::actions->expression_list_continue( $1, $3 ); }
                ;

              pseudo_destructor_name
/* A.4.040 */   : colcol_opt nested_name_specifier_opt type_name COLCOL COMPLEMENT type_name
                    { $$ = btyacc::actions->pseudo_destructor_name( $1, $2, $3 ); }
/* A.4.041 */   | colcol_opt nested_name_specifier KW_template template_id COLCOL COMPLEMENT type_name
                    { $$ = btyacc::actions->pseudo_destructor_name_template( $1, $2, $4, $7 ); }
/* A.4.042 */   | colcol_opt nested_name_specifier_opt COMPLEMENT type_name
                    { $$ = btyacc::actions->pseudo_destructor_name( $1, $2, $4 ); }
                ;
          
              unary_expression
/* A.4.043 */   : postfix_expression
                    { $$ = $1; }
/* A.4.044 */   | PLUSPLUS cast_expression
                    { $$ = btyacc::actions->unary_expression( OT_PRE_INC, $2 ); }      
/* A.4.045 */   | MINUSMINUS cast_expression
                    { $$ = btyacc::actions->unary_expression( OT_PRE_DEC, $2 ); }
/* A.4.046 */   | unary_operator cast_expression
                    { $$ = btyacc::actions->unary_expression( $1, $2 ); }
/* A.4.047 */   | KW_sizeof unary_expression
                    { $$ = btyacc::actions->unary_expression( OT_SIZEOF, $2 ); }
/* A.4.048 */   | KW_sizeof LEFTPAREN type_id RIGHTPAREN
                    { $$ = btyacc::actions->unary_expression( OT_SIZEOF, $3 ); }
/* A.4.049 */   | new_expression
                    { $$ = $1; }
/* A.4.050 */   | delete_expression
                    { $$ = $1; }
                ;

              unary_operator
/* A.4.051 */   : STAR
                    { $$ = OT_DEREF;   }
/* A.4.052 */   | AND
                    { $$ = OT_ADDR;    }
/* A.4.053 */   | PLUS
                    { $$ = OT_UPLUS;   }
/* A.4.054 */   | MINUS
                    { $$ = OT_UMINUS;  }
/* A.4.055 */   | NOT
                    { $$ = OT_NOT;     }
/* A.4.056 */   | COMPLEMENT
                    { $$ = OT_BIT_NOT; }
                ;
                   
              new_expression
/* A.4.057 */   : colcol_opt KW_new new_placement_opt new_type_id new_initializer_opt
                    { $$ = btyacc::actions->new_expression( $1, $3, $4, $5 ); }
/* A.4.058 */   | colcol_opt KW_new new_placement_opt LEFTPAREN type_id RIGHTPAREN new_initializer_opt
                    { $$ = btyacc::actions->new_expression( $1, $3, $5, $7 ); }
                ;
          
              new_placement
/* A.4.059 */   : LEFTPAREN expression_list RIGHTPAREN
                    { $$ = $2; }
                ;

              new_type_id
/* A.4.060 */   : type_specifier_seq new_declarator_opt
                    { $$ = btyacc::actions->new_type_id( $1, $2 ); }
                ;
          
              new_declarator
/* A.4.061 */   : ptr_operator new_declarator_opt
                    { $$ = btyacc::actions->new_declarator_ptr( $1, $2 ); }
/* A.4.062 */   | direct_new_declarator
                    { $$ = btyacc::actions->new_declarator_direct( $1 ); }
                ;

              direct_new_declarator
/* A.4.063 */   : LEFTARRAY expression RIGHTARRAY
                    { $$ = btyacc::actions->direct_new_declarator_exp( $2 ); }
/* A.4.064 */   | direct_new_declarator LEFTARRAY constant_expression RIGHTARRAY
                    { $$ = btyacc::actions->direct_new_declarator_const_exp( $1, $3 ); }
                ;

              new_initializer
/* A.4.065 */   : LEFTPAREN expression_list_opt RIGHTPAREN
                    { $$ = $2; }
                ;

              delete_expression
/* A.4.066 */   : colcol_opt KW_delete cast_expression
                    { $$ = btyacc::actions->delete_expression( $1, $3, false ); }
/* A.4.067 */   | colcol_opt KW_delete LEFTARRAY RIGHTARRAY cast_expression
                    { $$ = btyacc::actions->delete_expression( $1, $5, true ); }
                ;
          
              cast_expression
/* A.4.068 */   : unary_expression
                    { $$ = $1; }
/* A.4.069 */   | LEFTPAREN type_id RIGHTPAREN cast_expression
                    { $$ = btyacc::actions->cast_expression( $2, $4 ); }
                ;
          
              pm_expressionression
/* A.4.070 */   : cast_expression
                    { $$ = $1; }
/* A.4.071 */   | pm_expressionression DOTSTAR cast_expression
                    { $$ = btyacc::actions->pm_expressionression( OT_FIELD_DEREF, $1, $3 ); }
/* A.4.072 */   | pm_expressionression ARROWSTAR cast_expression
                    { $$ = btyacc::actions->pm_expressionression( OT_POINTSAT_DEREF, $1, $3 ); }
                ;

              multiplicative_expression
/* A.4.073 */   : pm_expressionression
                    { $$ = $1; }
/* A.4.074 */   | multiplicative_expression STAR pm_expressionression
                    { $$ = btyacc::actions->multiplicative_expression( OT_MULT, $1, $3 ); }
/* A.4.075 */   | multiplicative_expression DIVIDE pm_expressionression
                    { $$ = btyacc::actions->multiplicative_expression( OT_DIV, $1, $3 ); }
/* A.4.076 */   | multiplicative_expression MOD pm_expressionression
                    { $$ = btyacc::actions->multiplicative_expression( OT_MODULO, $1, $3 ); }
                ;        

              additive_expression
/* A.4.077 */   : multiplicative_expression
                    { $$ = $1; }
/* A.4.078 */   | additive_expression PLUS multiplicative_expression
                    { $$ = btyacc::actions->additive_expression( OT_BPLUS, $1, $3 ); }
/* A.4.079 */   | additive_expression MINUS multiplicative_expression
                    { $$ = btyacc::actions->additive_expression( OT_BMINUS, $1, $3 ); }
                ;

              shift_expression
/* A.4.080 */   : additive_expression
                    { $$ = $1; }
/* A.4.081 */   | shift_expression LTLT additive_expression
                    { $$ = btyacc::actions->shift_expression( OT_LSHIFT, $1, $3 ); }
/* A.4.082 */   | shift_expression GTGT additive_expression
                    { $$ = btyacc::actions->shift_expression( OT_RSHIFT, $1, $3 ); }
                ;

              relational_expression
/* A.4.083 */   : shift_expression
                    { $$ = $1; }
/* A.4.084 */   | relational_expression LESS shift_expression
                    { $$ = btyacc::actions->relational_expression( OT_TST_LT, $1, $3 ); }
/* A.4.085 */   | relational_expression GREATER shift_expression
                    { $$ = btyacc::actions->relational_expression( OT_TST_GT, $1, $3 ); }
/* A.4.086 */   | relational_expression LEQ shift_expression
                    { $$ = btyacc::actions->relational_expression( OT_TST_LE, $1, $3 ); }
/* A.4.087 */   | relational_expression GEQ shift_expression
                    { $$ = btyacc::actions->relational_expression( OT_TST_GE, $1, $3 ); }
                ;

              equality_expression
/* A.4.088 */   : relational_expression
                    { $$ = $1; }
/* A.4.089 */   | equality_expression EQEQ relational_expression
                    { $$ = btyacc::actions->equality_expression( OT_TST_EQ, $1, $3 ); }
/* A.4.090 */   | equality_expression NOTEQ relational_expression
                    { $$ = btyacc::actions->equality_expression( OT_TST_NE, $1, $3 ); }
                ;

              and_expression
/* A.4.091 */   : equality_expression
                    { $$ = $1; }
/* A.4.092 */   | and_expression AND equality_expression
                    { $$ = btyacc::actions->and_expression( OT_BIT_AND, $1, $3 ); }
                ;

              exclusive_or_expression
/* A.4.093 */   : and_expression
                    { $$ = $1; }
/* A.4.094 */   | exclusive_or_expression XOR and_expression
                    { $$ = btyacc::actions->exclusive_or_expression( OT_BIT_XOR, $1, $3 ); }
                ;

              inclusive_or_expression
/* A.4.095 */   : exclusive_or_expression
                    { $$ = $1; }
/* A.4.096 */   | inclusive_or_expression OR exclusive_or_expression
                    { $$ = btyacc::actions->inclusive_or_expression( OT_BIT_OR, $1, $3 ); }
                ;

              logical_and_expression
/* A.4.097 */   : inclusive_or_expression
                    { $$ = $1; }
/* A.4.098 */   | logical_and_expression ANDAND inclusive_or_expression
                    { $$ = btyacc::actions->logical_and_expression( OT_AND, $1, $3 ); }
                ;

              logical_or_expression
/* A.4.099 */   : logical_and_expression
                    { $$ = $1; }
/* A.4.100 */   | logical_or_expression OROR logical_and_expression
                    { $$ = btyacc::actions->logical_or_expression( OT_OR, $1, $3 ); }
                ;

              conditional_expression
/* A.4.101 */   : logical_or_expression
                    { $$ = $1; }
/* A.4.102 */   | logical_or_expression QUESTION expression COLON assignment_expression
                    { $$ = btyacc::actions->conditional_expression( $1, $3, $5 ); }
                ;

              assignment_expression
/* A.4.103 */   : conditional_expression
                    { $$ = $1; }
/* A.4.104 */   | logical_or_expression assignment_operator assignment_expression
                    { $$ = btyacc::actions->assignment_expression( eOperator( $2 ), $1, $3 ); }
/* A.4.105 */   | throw_expression
                    { $$ = $1; }
                ;

              assignment_operator
/* A.4.106 */   : EQUAL
                    { $$ = OT_ASGN_EQ;      }
/* A.4.107 */   | STAREQ
                    { $$ = OT_ASGN_MULT;    }
/* A.4.108 */   | DIVEQ
                    { $$ = OT_ASGN_DIV;     }
/* A.4.109 */   | MODEQ
                    { $$ = OT_ASGN_MOD;     }
/* A.4.110 */   | PLUSEQ
                    { $$ = OT_ASGN_PLUS;    }
/* A.4.111 */   | MINUSEQ
                    { $$ = OT_ASGN_MINUS;   }  
/* A.4.112 */   | GTGTEQ
                    { $$ = OT_ASGN_RSHIFT;  }
/* A.4.113 */   | LTLTEQ
                    { $$ = OT_ASGN_LSHIFT;  }
/* A.4.114 */   | ANDEQ
                    { $$ = OT_ASGN_BIT_AND; }
/* A.4.115 */   | XOREQ
                    { $$ = OT_ASGN_BIT_XOR; }
/* A.4.116 */   | OREQ
                    { $$ = OT_ASGN_BIT_OR;  }
                ;
          
              expression
/* A.4.117 */   : assignment_expression
                    { $$ = $1; }
/* A.4.118 */   | expression COMMA assignment_expression
                    { $$ = btyacc::actions->expression( OT_COMMA, $1, $3 ); }
                ;

              constant_expression
/* A.4.119 */   : conditional_expression
                    { $$ = $1; }
                ;


// ********** A.5  Statements  [gram.stmt.stmt] **********

              statement
/* A.5.001 */   : labeled_statement
                    { $$ = $1; }
/* A.5.002 */   | expression_statement
                    { $$ = $1; }
/* A.5.003 */   | compound_statement
                    { $$ = $1; }
/* A.5.004 */   | selection_statement
                    { $$ = $1; }
/* A.5.005 */   | iteration_statement
                    { $$ = $1; }
/* A.5.006 */   | jump_statement
                    { $$ = $1; }
/* A.5.007 */   | declaration_statement
                    { $$ = $1; }
/* A.5.008 */   | try_block
                    { $$ = $1; }
                ;
          
              labeled_statement
/* A.5.009 */   : any_identifier COLON statement
                    { $$ = btyacc::actions->labeled_statement_generic( $1, $3 ); }
/* A.5.010 */   | KW_case constant_expression COLON statement
                    { $$ = btyacc::actions->labeled_statement_case( $2, $4 );    }
/* A.5.011 */   | KW_default COLON statement
                    { $$ = btyacc::actions->labeled_statement_default( $3 );     }
                ;

              expression_statement
/* A.5.012 */   : expression_opt SEMI
                    [ YYVALID; ]
                    { $$ = $1; }
                ;

              compound_statement
/* A.5.013 */   : LEFTBRACK
                    [ YYVALID; ]
                    { btyacc::actions->compound_statement_1(); }
                  statement_seq_opt RIGHTBRACK
                    [ YYVALID; ]
                    { $$ = btyacc::actions->compound_statement_2( $3 ); }
                ;

              statement_seq
/* A.5.014 */   : statement
                    { $$ = new AsgNodeList_t;
                      $$->push_back( $1 );
                    }
/* A.5.015 */   | statement_seq statement
                    { $$ = $1;
                      $$->push_back( $2 );
                    }
                ;

              selection_statement
/* A.5.016 */   : KW_if LEFTPAREN condition RIGHTPAREN statement
                    { $$ = btyacc::actions->selection_statement_if( $3, $5, 0 ); }
/* A.5.017 */   | KW_if LEFTPAREN condition RIGHTPAREN statement KW_else statement
                    { $$ = btyacc::actions->selection_statement_if( $3, $5, $7 ); }
/* A.5.018 */   | KW_switch LEFTPAREN condition RIGHTPAREN statement
                    { $$ = btyacc::actions->selection_statement_switch( $3, $5 ); }
                ;

              condition
/* A.5.019 */   : expression
                    { $$ = $1; }
/* A.5.020 */   | type_specifier_seq
                    { btyacc::actions->push_type_specifier( $1 ); }
                  declarator EQUAL assignment_expression
                    { $$ = btyacc::actions->condition( $1, $3, $5 ); }
                ;

              iteration_statement
/* A.5.021 */   : KW_while LEFTPAREN condition RIGHTPAREN statement
                    { $$ = btyacc::actions->iteration_statement_while( $3, $5 ); }
/* A.5.022 */   | KW_do statement KW_while LEFTPAREN expression RIGHTPAREN SEMI
                    [ YYVALID; ]
                    { $$ = btyacc::actions->iteration_statement_do( $5, $2 ); }
/* A.5.023 */   | KW_for LEFTPAREN for_init_statement condition_opt SEMI
                    [ YYVALID; ] 
	                expression_opt RIGHTPAREN statement
                    { $$ = btyacc::actions->iteration_statement_for( $3, $4, $7, $9 ); }
                ;

              for_init_statement
/* A.5.024 */   : expression_statement
                    { $$ = $1; }
/* A.5.025 */   | simple_declaration
                    { $$ = $1; }
                ;

              jump_statement
/* A.5.026 */   : KW_break SEMI
                    [ YYVALID; ]
                    { $$ = btyacc::actions->jump_statement_break(); }
/* A.5.027 */   | KW_continue SEMI
                    [ YYVALID; ]
                    { $$ = btyacc::actions->jump_statement_continue(); }
/* A.5.028 */   | KW_return expression_opt SEMI
                    [ YYVALID; ]
                    { $$ = btyacc::actions->jump_statement_return( $2 ); }
/* A.5.029 */   | KW_goto any_identifier SEMI
                    [ YYVALID; ]
                    { $$ = btyacc::actions->jump_statement_goto( $2 ); }
                ;

              declaration_statement
/* A.5.030 */   : block_declaration
                    { $$ = $1; }
                ;


// ********** A.6  Declarations  [gram.dcl.dcl] **********

              declaration_seq
/* A.6.001 */   : declaration
                    { $$ = btyacc::actions->declaration_seq_1( $1 ); }
/* A.6.002 */   | declaration_seq declaration
                    { $$ = btyacc::actions->declaration_seq_2( $2, $1 ); }  
                ;

              declaration
/* A.6.003 */   : block_declaration
                    { $$ = $1; }
/* A.6.004 */   | function_definition
                    { $$ = $1; }
/* A.6.005 */   | template_declaration
                    { $$ = $1; }
/* A.6.006 */   | explicit_instantiation
                    { $$ = $1; }
/* A.6.007 */   | explicit_specialization
                    { $$ = $1; }
/* A.6.008 */   | linkage_specification
                    { $$ = $1; }
/* A.6.009 */   | namespace_definition
                    {
                      btyacc::actions->declaration_namespace_definition( $1 );
                      $$ = $1;
                    }
                ;

              block_declaration
/* A.6.010 */   : simple_declaration
                    { $$ = $1; }
/* A.6.011 */   | asm_definition
                    { $$ = $1; }
/* A.6.012 */   | namespace_alias_definition
                    { $$ = $1; }
/* A.6.013 */   | using_declaration
                    { $$ = $1; }
/* A.6.014 */   | using_directive
                    { $$ = $1; }
                ;

              simple_declaration
/* A.6.015 */   : decl_specifier_seq_opt
                    [
                      btyacc::actions->setSawMemberPtr( false );
                      btyacc::actions->setSawFunctionDef( false );
                    ]
                  init_declarator_list_opt SEMI
                    [ YYVALID; ]
                    { $$ = btyacc::actions->simple_declaration( $1, $3 ); }
                ;

              decl_specifier
/* A.6.016 */   : storage_class_specifier
                    { $$ = $1; }
/* A.6.017 */   | type_specifier
                    { $$ = btyacc::actions->decl_specifier_type( $1 ); }
/* A.6.018 */   | function_specifier
                    { $$ = $1; }  
/* A.6.019 */   | KW_friend
                    { $$ = btyacc::actions->decl_specifier_friend(); }
/* A.6.020 */   | KW_typedef
                    { $$ = btyacc::actions->decl_specifier_typedef(); }
                ;

              decl_specifier_seq
/* A.6.021 */   : decl_specifier_seq_opt decl_specifier
                    { $$ = btyacc::actions->decl_specifier_seq( $2, $1 ); }
                ;

              storage_class_specifier
/* A.6.022 */   : KW_auto
                    { $$ = btyacc::actions->storage_class_specifier( DS_AUTO );   }
/* A.6.023 */   | KW_register
                    { $$ = btyacc::actions->storage_class_specifier( DS_REGISTER ); }
/* A.6.024 */   | KW_static
                    { $$ = btyacc::actions->storage_class_specifier( DS_STATIC );   }
/* A.6.025 */   | KW_extern
                    { $$ = btyacc::actions->storage_class_specifier( DS_EXTERN );   }
/* A.6.026 */   | KW_mutable
                    { $$ = btyacc::actions->storage_class_specifier( DS_MUTABLE );  }
                ;

              function_specifier
/* A.6.027 */   : KW_inline
                    { $$ = btyacc::actions->function_specifier( DS_INLINE );   }
/* A.6.028 */   | KW_virtual
                    { $$ = btyacc::actions->function_specifier( DS_VIRTUAL );  }
/* A.6.029 */   | KW_explicit
                    { $$ = btyacc::actions->function_specifier( DS_EXPLICIT ); }
                ;

              type_specifier
/* A.6.030 */   : simple_type_specifier
                    { $$ = $1; }
/* A.6.031 */   | class_specifier
                    { $$ = $1; }
/* A.6.032 */   | enum_specifier
                    { $$ = $1; }
/* A.6.033 */   | elaborated_type_specifier
                    { $$ = $1; }
/* A.6.034 */   | cv_qualifier
                    { $$ = btyacc::actions->cv_qualifier( $1 ); }
                ;

              simple_type_specifier
/* A.6.035 */   : colcol_opt nested_name_specifier_opt type_name
                    { $$ = btyacc::actions->simple_type_specifier_type_name( $1, $2, $3 ); }
/* A.6.036 */   | colcol_opt nested_name_specifier KW_template template_id
                    { $$ = btyacc::actions->simple_type_specifier_template( $1, $2, $4 ); }
/* A.6.037 */   | KW_char
                    { $$ = btyacc::actions->simple_type_specifier_basic_type( "char" ); }
/* A.6.037a */  | KW_unsigned_char
                    { $$ = btyacc::actions->simple_type_specifier_basic_type( "unsigned char" ); }
/* A.6.038 */   | KW_wchar_t
                    { $$ = btyacc::actions->simple_type_specifier_basic_type( "wchar_t" ); }
/* A.6.039 */   | KW_bool
                    { $$ = btyacc::actions->simple_type_specifier_basic_type( "bool" ); }
/* A.6.040 */   | KW_short
                    { $$ = btyacc::actions->simple_type_specifier_basic_type( "short" ); }
/* A.6.040a */  | KW_unsigned_short
                    { $$ = btyacc::actions->simple_type_specifier_basic_type( "unsigned short" ); }
/* A.6.041 */   | KW_int
                    { $$ = btyacc::actions->simple_type_specifier_basic_type( "int" ); }
/* A.6.042 */   | KW_long
                    { $$ = btyacc::actions->simple_type_specifier_basic_type( "long" ); }
/* A.6.042a */  | KW_unsigned_long
                    { $$ = btyacc::actions->simple_type_specifier_basic_type( "unsigned long" ); }
/* A.6.043 */   | KW_signed
                    { $$ = btyacc::actions->simple_type_specifier_basic_type( "signed" ); }
/* A.6.044 */   | KW_unsigned
                    { $$ = btyacc::actions->simple_type_specifier_basic_type( "unsigned" ); }
/* A.6.045 */   | KW_float
                    { $$ = btyacc::actions->simple_type_specifier_basic_type( "float" ); }
/* A.6.046 */   | KW_double
                    { $$ = btyacc::actions->simple_type_specifier_basic_type( "double" ); }
/* A.6.046a */  | KW_long_double
                    { $$ = btyacc::actions->simple_type_specifier_basic_type( "long double" ); }
/* A.6.047 */   | KW_void
                    {
                      //YYPOSN p = *(yyps->psp);
                      $$ = btyacc::actions->simple_type_specifier_basic_type( "void" );
                    }
                ;

              type_name
/* A.6.048 */   : class_name
                    { $$ = $1; }
/* A.6.049 */   | enum_name
                    { $$ = btyacc::actions->type_name( $1 ); }
/* A.6.050 */   | typedef_name
                    { $$ = btyacc::actions->type_name( $1 ); }
                ;

              elaborated_type_specifier
/* A.6.051 */   : class_key colcol_opt nested_name_specifier_opt any_identifier_or_template
                    { $$ = btyacc::actions->elaborated_type_specifier_class( $1, $2, $3, $4 ); }
/* A.6.052 */   | KW_enum colcol_opt nested_name_specifier_opt any_identifier
                    { $$ = btyacc::actions->elaborated_type_specifier_enum( $2, $3, $4 ); }
/* A.6.053 */   | KW_typename colcol_opt nested_name_specifier any_identifier
                    { $$ = btyacc::actions->elaborated_type_specifier_typename( $2, $3, $4 ); }
/* A.6.054 */   | KW_typename colcol_opt nested_name_specifier template_opt template_id
                    { $$ = btyacc::actions->elaborated_type_specifier_template( $2, $3, $4, $5 ); }
                ;

              enum_specifier
/* A.6.055 */   : KW_enum identifier_opt
                    { btyacc::actions->enum_specifier_1( $2, $1 ); }
                  LEFTBRACK
                    [ YYVALID; ]
                  enumerator_list_opt RIGHTBRACK
                    [ YYVALID; ]
                    { $$ = btyacc::actions->enum_specifier_2( $6 ); }
                ;

              enumerator_list
/* A.6.056 */   : enumerator_definition
                    { $$ = btyacc::actions->enumerator_list_1( $1 ); }
/* A.6.057 */   | enumerator_list COMMA enumerator_definition
                    { $$ = btyacc::actions->enumerator_list_2( $1, $3 ); }
                ;

              enumerator_definition
/* A.6.058 */   : enumerator
                    { $$ = btyacc::actions->enumerator_definition( $1, 0 ); }
/* A.6.059 */   | enumerator EQUAL constant_expression
                    { $$ = btyacc::actions->enumerator_definition( $1, $3 ); }
                ;

              enumerator
/* A.6.060 */   : any_identifier
                    { $$ = $1; }
                ;

              namespace_definition
/* A.6.061 */   : named_namespace_definition
                    { $$ = $1; }
/* A.6.062 */   | unnamed_namespace_definition
                    { $$ = $1; }
                ;

              named_namespace_definition
/* A.6.063 */   : original_namespace_definition
                    { $$ = $1; }
/* A.6.064 */   | extension_namespace_definition
                    { $$ = $1; }
                ;

              original_namespace_definition
/* A.6.065 */   : KW_namespace any_identifier
                    { btyacc::actions->original_namespace_definition_1( $2 ); }
                  LEFTBRACK
                    [ YYVALID; ]
                  namespace_body
                  RIGHTBRACK
                    [ YYVALID; ]
                    { $$ = btyacc::actions->original_namespace_definition_2( $2, $6 ); }
                ;

              extension_namespace_definition
/* A.6.066 */   : KW_namespace original_namespace_name
                    { btyacc::actions->extension_namespace_definition_1( $2 ); }
                  LEFTBRACK
                    [ YYVALID; ]
                  namespace_body RIGHTBRACK
                    [ YYVALID; ]
                    { $$ = btyacc::actions->extension_namespace_definition_2( $2, $6 ); }
                ;

              unnamed_namespace_definition
/* A.6.067 */   : KW_namespace
                    { $<decl>$ = btyacc::actions->unnamed_namespace_definition_1( $1 ); }
                  LEFTBRACK
                    [ YYVALID; ]
                  namespace_body RIGHTBRACK
                    [ YYVALID; ]
                    { $$ = btyacc::actions->unnamed_namespace_definition_2( $<decl>2, $5 ); }
                ;

              namespace_body
/* A.6.068 */   : declaration_seq_opt
                    { $$ = $1; }
                ;

              namespace_alias_definition
/* A.6.069 */   : KW_namespace any_identifier EQUAL qualified_namespace_specifier SEMI
                    [ YYVALID; ]
                    { $$ = btyacc::actions->namespace_alias_definition( $2, $4 ); }
                ;

              qualified_namespace_specifier
/* A.6.070 */   : colcol_opt nested_name_specifier_opt namespace_name
                    { $$ = $3; }
                ;

              using_declaration
/* A.6.071 */   : KW_using typename_opt colcol_opt nested_name_specifier any_unqualified_id SEMI
                    [ YYVALID; ]
                    { $$ = btyacc::actions->using_declaration($3, $4, $5); }
/* A.6.072 */   | KW_using COLCOL  any_unqualified_id SEMI
                    [ YYVALID; ]
                    { $$ = btyacc::actions->using_declaration(true, 0, $3); }
                ;

              using_directive
/* A.6.073 */   : KW_using KW_namespace colcol_opt nested_name_specifier_opt namespace_name SEMI
                    [ YYVALID; ]
                    { $$ = btyacc::actions->using_directive($3, $4, $5); }
                ;

              asm_definition
/* A.6.074 */   : KW_asm LEFTPAREN STRING_LITERAL RIGHTPAREN SEMI
                    [ YYVALID; ]
                    { $$ = btyacc::actions->asm_definition( $3->getName() ); }
                ;

              linkage_specification
/* A.6.075 */   : KW_extern STRING_LITERAL LEFTBRACK
                    [ YYVALID; ]
                  declaration_seq_opt RIGHTBRACK
                    [ YYVALID; ]
                    { $$ = btyacc::actions->linkage_specification_block( $2->getName(), $5 ); }
/* A.6.076 */   | KW_extern STRING_LITERAL declaration
                    { $$ = btyacc::actions->linkage_specification_decl( $2->getName(), $3 ); }
                ;


// ********** A.7  Declarators  [gram.dcl.decl] **********

              init_declarator_list
/* A.7.001 */   : init_declarator 
                    { $$ = btyacc::actions->init_declarator_list( $1, 0 ); }
/* A.7.002 */   | init_declarator_list COMMA init_declarator
                    { $$ = btyacc::actions->init_declarator_list( $3, $1 ); }
                ;

              init_declarator
/* A.7.003 */   : declarator initializer_opt
                    { $$ = btyacc::actions->init_declarator( $1, $2 ); }
                ;

              declarator
/* A.7.004 */   : direct_declarator
                    { $$ = btyacc::actions->declarator_direct( $1 ); }
/* A.7.005 */   | ptr_operator
                    { btyacc::actions->declarator_ptr_1( $1 ); }
                  declarator
                    { $$ = btyacc::actions->declarator_ptr_2( $1, $3 ); }
                ;

              direct_declarator
/* A.7.006 */   : declarator_id
                    { $$ = btyacc::actions->direct_declarator_id( $1 ); }
/* A.7.007 */   | direct_declarator
                    { btyacc::actions->direct_declarator_fun_1( $1 ); }
                  LEFTPAREN
                    [
                      if ( btyacc::decorator->lastWasFun() )
                      {
                        /// Tanton 3rd condition: btyacc::decorator->getBeforeParen()->getName().find( "::" )
                        /// NAK believes he meant != npos (i.e. found)
                        if ( btyacc::decorator->getBeforeParen() &&
                             btyacc::decorator->getBeforeParen()->getOccurQual() &&
                             ( btyacc::decorator->getBeforeParen()->getName().find( "::" ) != std::string::npos )
                           )
                        {
                          btyacc::facade->setAdditionalLookupScope(
                                        btyacc::decorator->getBeforeParen()->getOccurQual()->getCorrespondingScope() );
                        }
                        btyacc::actions->setSawFunctionDef( true );
                        YYVALID_NESTED;
                      }
                      if ( btyacc::decorator->getBeforeParen() )
                      {
                        if ( btyacc::decorator->getBeforeParen()->markedTemplate() )
                        {
                          // constructor check!
                          if ( !btyacc::facade->inCurrentClassScope() ||
                               !( btyacc::facade->inCurrentClassScope()->getName() ==
                                  btyacc::decorator->getBeforeParen()->getName()) )
                          {
                            #ifdef KEY_YYERROR_DEBUG
                              std::cerr << "YYERROR 2" << std::endl;
                            #endif
                            YYERROR;
                          }
                        }
                      }                     
                    ]
                    { btyacc::actions->setLineNumForAbsDecl( $3 ); }
                  parameter_declaration_clause
                    [ btyacc::facade->setAdditionalLookupScope( 0 ); ]
                  RIGHTPAREN cv_qualifier_seq_opt exception_specification_opt
                    [ YYVALID_NESTED; ]
                    {
                      btyacc::actions->setSawFunctionDef( false );
                      $$ = btyacc::actions->direct_declarator_fun_2( $1, $5, $8, $9 );
                    }
/* A.7.008 */   | direct_declarator LEFTARRAY constant_expression_opt RIGHTARRAY
                    { $$ = btyacc::actions->direct_declarator_arr( $1, $3 ); }
/* A.7.009 */   | LEFTPAREN declarator RIGHTPAREN
                    { $$ = $2; }
                ;

              ptr_operator
/* A.7.010 */   : STAR cv_qualifier_seq_opt
                    { $$ = btyacc::actions->ptr_operator( STAR, $2 ); }
/* A.7.011 */   | AND
                    { $$ = btyacc::actions->ptr_operator( AND, 0 );   }
/* A.7.012 */   | colcol_opt nested_name_specifier STAR cv_qualifier_seq_opt
                    [
                      btyacc::actions->setSawMemberPtr( true );
                    ]
                    { $$ = btyacc::actions->ptr_operator( STAR, $4 ); }
                ;

              cv_qualifier_seq
/* A.7.013 */   : cv_qualifier cv_qualifier_seq_opt
                    { $$ = $1 + $2; }
                ;

              cv_qualifier
/* A.7.014 */   : KW_const
                    {
                      btyacc::actions->setSeenConst( true );
                      $$ = 1;
                    }
/* A.7.015 */   | KW_volatile
                    {
                      btyacc::actions->setSeenVolatile( true );
                      $$ = 2;
                    }
                ;

              declarator_id
/* A.7.016 */   : id_expression
                    { $$ = $1; }
/* A.7.017 */   | colcol_opt nested_name_specifier_opt type_name
                    { $$ = $3; }
                ;

              type_id
/* A.7.018 */   : type_specifier_seq abstract_declarator_opt
                    { $$ = btyacc::actions->type_id( $1, $2 ); }
                ;

              type_specifier_seq
/* A.7.019 */   : type_specifier type_specifier_seq_opt
                    {
                      // This no longer works now that cQualifierType is in the mix
                      // Plus, it was wrong anyway.
                      //$$ = ($1 != 0 ? $1 : $2);
                      $$ = btyacc::actions->type_specifier_seq( $1, $2 );
                    }
                ;

              abstract_declarator
/* A.7.020 */   : ptr_operator abstract_declarator_opt
                    { $$ = btyacc::actions->abstract_declarator( $1, $2 ); }
/* A.7.021 */   | direct_abstract_declarator
                    { $$ = $1; }
                ;

              direct_abstract_declarator
/* A.7.022 */   : direct_abstract_declarator_opt LEFTPAREN
                    { btyacc::actions->setLineNumForAbsDecl( $2 ); }
                  parameter_declaration_clause RIGHTPAREN cv_qualifier_seq_opt exception_specification_opt
                    { $$ = btyacc::actions->direct_abstract_declarator_fun( $1, $4, $6, $7 ); }
/* A.7.023 */   | direct_abstract_declarator_opt LEFTARRAY constant_expression_opt RIGHTARRAY
                    { $$ = btyacc::actions->direct_abstract_declarator_arr( $1, $3 ); }
/* A.7.024 */   | LEFTPAREN abstract_declarator RIGHTPAREN
                    { $$ = $2; }
                ;

              parameter_declaration_clause
/* A.7.025 */   : parameter_declaration_list_opt ellipses_opt
                    { $$ = btyacc::actions->parameter_declaration_clause( $1, $2 ); }
/* A.7.026 */   | parameter_declaration_list COMMA ELLIPSES
                    { $$ = btyacc::actions->parameter_declaration_clause( $1, 1 ); }
                ;

              parameter_declaration_list
/* A.7.027 */   : parameter_declaration
                    { $$ = btyacc::actions->parameter_declaration_list( $1, 0 ); }
/* A.7.028 */   | parameter_declaration_list COMMA parameter_declaration
                    { $$ = btyacc::actions->parameter_declaration_list($3, $1);	}
                ;

              parameter_declaration
/* A.7.029 */   : decl_specifier_seq declarator
                    { $$ = btyacc::actions->parameter_declaration_named( $1, $2, 0 ); }
/* A.7.030 */   | decl_specifier_seq declarator EQUAL assignment_expression
                    { $$ = btyacc::actions->parameter_declaration_named( $1, $2, $4 ); }
/* A.7.031 */   | decl_specifier_seq abstract_declarator_opt
                    { $$ = btyacc::actions->parameter_declaration_unnamed( $1, $2, 0 ); }
/* A.7.032 */   | decl_specifier_seq abstract_declarator_opt EQUAL assignment_expression
                    { $$ = btyacc::actions->parameter_declaration_unnamed( $1, $2, $4 ); }
                ;

              function_definition
/* A.7.033 */   : decl_specifier_seq_opt declarator
                    { btyacc::actions->function_definition_1( $2 ); }
                  ctor_initializer_opt function_body
                    { $$ = btyacc::actions->function_definition_2( $1, $2, $4, $5 ); }
/* A.7.034 */   | decl_specifier_seq_opt declarator
                    {  btyacc::actions->function_definition_1( $2 ); }
                  function_try_block
                    { $$ = btyacc::actions->function_definition_2( $1, $2, 0, $4 ); }
                ;

              function_body
/* A.7.035 */   : compound_statement
                    { $$ = $1; }
                ;

              initializer
/* A.7.036 */   : EQUAL
                    [
                      if ( !btyacc::actions->sawMemberPtr() && btyacc::decorator->getBeforeEqual() &&
                           btyacc::decorator->getBeforeEqual()->getOccurQual()    &&
                           btyacc::facade->getCurrentScope() != btyacc::facade->getGlobalNamespace()->getCorrespondingScope() )
                      {
                        #ifdef KEY_YYERROR_DEBUG
                          std::cerr << "YYERROR 3" << std::endl;
                        #endif
                        YYERROR;
                      }
                    ]
                  initializer_clause
                    { $$ = $3; }
/* A.7.037 */   | LEFTPAREN
                    [
                      NameDeclaration *decl = btyacc::decorator->getBeforeParen();
                      if ( btyacc::facade->getCurrentTemplateScope(false) )
                      {
                        #ifdef KEY_YYERROR_DEBUG
                          std::cerr << "YYERROR 4" << std::endl;
                        #endif
                        YYERROR;
                      }
                      else if ( dynamic_cast<TemplateParameterScope*>( btyacc::facade->getPreviousScope() ) )
                      {
                        #ifdef KEY_YYERROR_DEBUG
                          std::cerr << "YYERROR 5" << std::endl;
                        #endif
                        YYERROR;
                      }
                      else if( btyacc::actions->sawFunctionDef() ||
                               decl && decl->getType() &&
                               !decl->isInstance() &&
                               decl->isInSymbolTable() &&
                               ( decl->getType()->checkType( Type::DT_CLASS ) ||
                                 decl->getType()->checkType( Type::DT_ENUM ) ||
                                 decl->getType()->checkType( Type::DT_BASIC ) ||
                                 decl->getType()->checkType( Type::DT_INDIRECT ) ||
                                 decl->getType()->checkType( Type::DT_TEMPLATE_PARM ) ||
                                 decl->getType()->checkType( Type::DT_TEMPLATE_TEMPLATE_PARM ) ) )
                      {
                        #ifdef KEY_YYERROR_DEBUG
                          std::cerr << "YYERROR 6" << std::endl;
                        #endif
                        YYERROR;
                      }
                    ]
                  expression_list RIGHTPAREN
                    { $$ = $3; }
                ;

              initializer_clause
/* A.7.038 */   : assignment_expression
                    { $$ = $1; }
/* A.7.039 */   | LEFTBRACK
                    [ YYVALID; ]
                  initializer_list comma_opt RIGHTBRACK
                    [ YYVALID; ]
                    { $$ = $3; }
/* A.7.040 */   | LEFTBRACK RIGHTBRACK
                    [ YYVALID; ]
                    { /* XXX - cEmptyExpression */ $$ = 0;  }
                ;

              initializer_list
/* A.7.041 */   : initializer_clause
                    { $$ = btyacc::actions->initializer_list( $1, 0 );  }
/* A.7.042 */   | initializer_list COMMA initializer_clause
                    { $$ = btyacc::actions->initializer_list( $3, $1 ); }
                ;


//********* A.8  Classes  [gram.class] **********

              class_specifier
/* A.8.001 */   : class_head LEFTBRACK
                    [ YYVALID; ]
                  member_specification_opt RIGHTBRACK
                    [ YYVALID; ]
                    { $$ = btyacc::actions->class_specifier( $1, $4 ); }
                ;

              class_head
/* A.8.002 */   : class_key identifier_opt
                    { $<decl>$ = btyacc::actions->class_head_opt( $2 ); }
                  base_clause_opt
                    { $$ = btyacc::actions->class_head( $1, 0, $<decl>3, $4 ); }
/* A.8.003 */   | class_key nested_name_specifier any_identifier
                    { $<decl>$ = btyacc::actions->class_head_nns( $3 ); }
                  base_clause_opt
                    { $$ = btyacc::actions->class_head( $1, $2, $<decl>4, $5 ); }
/* A.8.004 */   | class_key nested_name_specifier_opt template_id
                    { $<nameref>$ = btyacc::actions->class_head_template( $3 ); }
                  base_clause_opt
                    { $$ = btyacc::actions->class_head_template_bc( $1, $2, $<nameref>4, $5 ); }
                ;

              class_key
/* A.8.005 */   : KW_class
                    {
                      btyacc::actions->pushEntryAccess( btyacc::actions->getCurrentAccess() );
                      btyacc::actions->setNextAccess( Access::Private );
                      $$ = AT_CLASS;
                    }
/* A.8.006 */   | KW_struct
                    {
                      btyacc::actions->pushEntryAccess( btyacc::actions->getCurrentAccess() );
                      btyacc::actions->setNextAccess( Access::Public );
                      $$ = AT_STRUCT;
                    }
/* A.8.007 */   | KW_union
                    {
                      $$ = AT_UNION;
                      btyacc::actions->pushEntryAccess( btyacc::actions->getCurrentAccess() );
                      btyacc::actions->setNextAccess( Access::Public );
                    }
                ;

              member_specification
/* A.8.008 */   : member_declaration member_specification_opt
                    { $$ = btyacc::actions->member_specification( $1, $2 ); }
/* A.8.009 */   | access_specifier COLON member_specification_opt
                    { $$ = $3; }
                ;

              member_declaration
/* A.8.010 */   : decl_specifier_seq_opt member_declarator_list_opt SEMI
                    [ YYVALID; ]
                    { $$ = btyacc::actions->member_declaration( $1, $2 ); }
/* A.8.011 */   | function_definition semi_opt
                    { $$ = btyacc::actions->member_declaration_fundef( $1 ); }
/* A.8.012 */   | colcol_opt nested_name_specifier template_opt unqualified_id SEMI
                    [ YYVALID; ]
                    { $$ = btyacc::actions->member_declaration_disambiguated( $2, $4 ); }
/* A.8.013 */   | using_declaration
                    { $$ = btyacc::actions->member_declaration_using( $1 ); }
/* A.8.014 */   | template_declaration
                    { $$ = btyacc::actions->member_declaration_template( $1 ); }
                ;

              member_declarator_list
/* A.8.015 */   : member_declarator
                    { $$ = btyacc::actions->member_declarator_list( $1, 0 ); }
/* A.8.016 */   | member_declarator_list COMMA member_declarator
                    { $$ = btyacc::actions->member_declarator_list( $3, $1 ); }
                ;

              member_declarator
/* A.8.017 */   : declarator pure_specifier_opt
                    { $$ = btyacc::actions->member_declarator( $1, $2 ); }
/* A.8.018 */   | declarator constant_initializer_opt
                    { $$ = btyacc::actions->member_declarator( $1, $2 ); }
/* A.8.019 */   | identifier_opt COLON constant_expression
                    { $$ = btyacc::actions->member_declarator_bitfield( $1, $2, $3 ); }
                ;

              pure_specifier
                 // Must equal "0"
/* A.8.020 */   : EQUAL INTEGER_LITERAL
                    {
                      std::string zero = $2->getName();
                      if ( zero != "0" )
                      {
                        YYSTYPE pureVal;
                        pureVal.id_sym = $2;

                        YYPOSN  purePosn;
                        purePosn.filename   = new std::string( $2->getFileName() );
                        purePosn.lineNumber = $2->getLinenum();

                        yyerror_detailed( "syntax error", PS_LITERAL, pureVal, purePosn );
                        YYERROR;
                      }
                      $$ = btyacc::actions->pure_specifier( zero );
                    }
                ;

              constant_initializer
/* A.8.021 */   : EQUAL constant_expression
                    [
                      NameDeclaration *decl = btyacc::decorator->getBeforeEqual();

                      if ( ! decl )
                      {
                        #ifdef KEY_YYERROR_DEBUG
                          std::cout << "YYERROR A.8.021" << std::endl;
                        #endif
                        YYERROR;
                      }
                    ]
                    { $$ = btyacc::actions->constant_initializer( $2 ); }
                ;


/********** A.9  Derived classes  [gram.class.derived] **********/

              base_clause
/* A.9.001 */   : COLON base_specifier_list
                    { $$ = $2; }
                ;

              base_specifier_list
/* A.9.002 */   : base_specifier
                    { $$ = btyacc::actions->base_specifier_list( $1, 0 ); }
/* A.9.003 */   | base_specifier_list COMMA base_specifier
                    { $$ = btyacc::actions->base_specifier_list( $3, $1 ); }
                ;

              base_specifier
/* A.9.004 */   : colcol_opt nested_name_specifier_opt class_name
                    { $$ = btyacc::actions->base_specifier( $2, $3, btyacc::actions->geteAccessSpecifier( btyacc::actions->getCurrentAccess() ), false ); }
/* A.9.005 */   | KW_virtual access_specifier_opt colcol_opt nested_name_specifier_opt class_name
                    { $$ = btyacc::actions->base_specifier( $4, $5, btyacc::actions->geteAccessSpecifier( btyacc::actions->getCurrentAccess() ), true ); }
/* A.9.006 */   | access_specifier virtual_opt colcol_opt nested_name_specifier_opt class_name
                    { $$ = btyacc::actions->base_specifier( $4, $5, btyacc::actions->geteAccessSpecifier( btyacc::actions->getCurrentAccess() ), $2 ); }
                ;

              access_specifier
/* A.9.007 */   : KW_private
                    { btyacc::actions->setCurrentAccess( Access::Private );   }
/* A.9.008 */   | KW_protected
                    { btyacc::actions->setCurrentAccess( Access::Protected ); }
/* A.9.009 */   | KW_public
                    { btyacc::actions->setCurrentAccess( Access::Public );    }
                ;


//********* A.10  Special member functions  [gram.special] **********

               conversion_function_id
/* A.10.001 */   : KW_operator conversion_type_id
                     { $$ = btyacc::actions->conversion_function_id( $1, $2 ); }
                 ;

              conversion_type_id
/* A.10.002 */   : type_specifier_seq conversion_declarator_opt
                     { $$ = btyacc::actions->conversion_type_id( $1, $2 ); }
                 ;

               conversion_declarator
/* A.10.003 */   : ptr_operator conversion_declarator_opt
                     { $$ = btyacc::actions->conversion_declarator( $1, $2 ); }
                 ;

               ctor_initializer
/* A.10.004 */   : COLON mem_initializer_list
                     { $$ = btyacc::actions->ctor_initializer( $2 ); }
                 ;

               mem_initializer_list
/* A.10.005 */   : mem_initializer
                     { $$ = btyacc::actions->mem_initializer_list( $1, 0 ); }
/* A.10.006 */   | mem_initializer COMMA mem_initializer_list
                     { $$ = btyacc::actions->mem_initializer_list( $1, $3 ); }
                 ;

               mem_initializer
/* A.10.007 */   : mem_initializer_id LEFTPAREN expression_list_opt RIGHTPAREN
                     { $$ = btyacc::actions->mem_initializer( $1, $3 ); }
                 ;

               mem_initializer_id
/* A.10.008 */   : colcol_opt nested_name_specifier_opt class_name
                     { $$ = $3; }
/* A.10.009 */   | any_identifier
                     { $$ = btyacc::actions->mem_initializer_id( $1 ); }
                 ;


// ********** A.11  Overloading  [gram.over] **********

               operator_function_id
/* A.11.001 */   : KW_operator an_operator
                     { $$ = btyacc::facade->makeOperator($2,$1); }
                 ;

               an_operator
/* A.11.002 */   : KW_new
                     { $$ = new std::string( "new" );      }
/* A.11.003 */   | KW_delete
                     { $$ = new std::string( "delete" );   }
/* A.11.004 */   | KW_new LEFTARRAY RIGHTARRAY
                     { $$ = new std::string( "new[]" );    }
/* A.11.005 */   | KW_delete LEFTARRAY RIGHTARRAY
                     { $$ = new std::string( "delete[]" ); }
/* A.11.006 */   | PLUS
                     { $$ = new std::string( "+" );   }
/* A.11.007 */   | MINUS
                     { $$ = new std::string( "-" );   }
/* A.11.008 */   | STAR
                     { $$ = new std::string( "*" );   }
/* A.11.009 */   | DIVIDE
                     { $$ = new std::string( "/" );   }
/* A.11.010 */   | MOD
                     { $$ = new std::string( "%" );   }
/* A.11.011 */   | XOR
                     { $$ = new std::string( "^" );   }
/* A.11.012 */   | AND
                     { $$ = new std::string( "&" );   }
/* A.11.013 */   | OR
                     { $$ = new std::string( "|" );   }
/* A.11.014 */   | COMPLEMENT
                     { $$ = new std::string( "~" );   }
/* A.11.015 */   | NOT
                     { $$ = new std::string( "!" );   }
/* A.11.016 */   | EQUAL
                     { $$ = new std::string( "=" );   }
/* A.11.017 */   | LESS
                     { $$ = new std::string( "<" );   }
/* A.11.018 */   | GREATER
                     { $$ = new std::string( ">" );   }
/* A.11.019 */   | PLUSEQ
                     { $$ = new std::string( "+=" );  }
/* A.11.020 */   | MINUSEQ
                     { $$ = new std::string( "-=" );  }
/* A.11.021 */   | STAREQ
                     { $$ = new std::string( "*=" );  }
/* A.11.022 */   | DIVEQ
                     { $$ = new std::string( "/=" );  }
/* A.11.023 */   | MODEQ
                     { $$ = new std::string( "%=" );  }
/* A.11.024 */   | XOREQ
                     { $$ = new std::string( "^=" );  }
/* A.11.025 */   | ANDEQ
                     { $$ = new std::string( "&=" );  }
/* A.11.026 */   | OREQ
                     { $$ = new std::string( "|=" );  }
/* A.11.027 */   | LTLT
                     { $$ = new std::string( "<<" );  }
/* A.11.028 */   | GTGT
                     { $$ = new std::string( ">>" );  }
/* A.11.029 */   | GTGTEQ
                     { $$ = new std::string( ">>=" ); }
/* A.11.030 */   | LTLTEQ
                     { $$ = new std::string( "<<=" ); }
/* A.11.031 */   | EQEQ
                     { $$ = new std::string( "==" );  }
/* A.11.032 */   | NOTEQ
                     { $$ = new std::string( "!=" );  }
/* A.11.033 */   | LEQ
                     { $$ = new std::string( "<=" );  }
/* A.11.034 */   | GEQ
                     { $$ = new std::string( ">=" );  }
/* A.11.035 */   | ANDAND
                     { $$ = new std::string( "&&" );  }
/* A.11.036 */   | OROR
                     { $$ = new std::string( "||" );  }
/* A.11.037 */   | PLUSPLUS
                     { $$ = new std::string( "++" );  }
/* A.11.038 */   | MINUSMINUS
                     { $$ = new std::string( "--" );  }
/* A.11.039 */   | COMMA
                     { $$ = new std::string( "," );   }
/* A.11.040 */   | ARROWSTAR
                     { $$ = new std::string( "->*" ); }
/* A.11.041 */   | ARROW
                     { $$ = new std::string( "->" );  }
/* A.11.042 */   | LEFTPAREN RIGHTPAREN
                     { $$ = new std::string( "()" );  }
/* A.11.043 */   | LEFTARRAY RIGHTARRAY
                     { $$ = new std::string( "[]" );  }
                 ;


// ********** A.12  Templates  [gram.temp] **********

               template_declaration
/* A.12.001 */   : export_opt KW_template LESS
                     { btyacc::contextManager->setInTemplate( true );
                       btyacc::actions->template_declaration_1();
                     }
                   template_parameter_list GREATER
                     [ //if ( !btyacc::decorator()->nextIsClass() ) {
                       YYVALID;
                       //}
                     ]
                     { btyacc::contextManager->setInTemplate( false );
                       btyacc::actions->template_declaration_leave_scope();
                     }
                   declaration
                     [ YYVALID; ]
                     { $$ = btyacc::actions->template_declaration_2( $1, $5, $8 ); } 
                 ;

               template_parameter_list
/* A.12.002 */   : template_parameter
                     [ YYVALID; ]
                     { $$ = btyacc::actions->template_parameter_list( $1, 0 ); }
/* A.12.003 */   | template_parameter_list COMMA template_parameter
                     [ YYVALID; ]
                     { $$ = btyacc::actions->template_parameter_list( $3, $1 ); }
                 ;

               template_parameter
/* A.12.004 */   : type_parameter
                     { $$ = $1; }
/* A.12.005 */   | parameter_declaration
                     { $$ = btyacc::actions->template_parameter( $1 ); }
                 ;

               type_parameter
/* A.12.006 */   : KW_class identifier_opt
                     { $$= btyacc::actions->type_parameter( $1, $2, 0 ); }
/* A.12.007 */   | KW_class identifier_opt EQUAL type_id
                     { $$= btyacc::actions->type_parameter( $1, $2, $4 ); }
/* A.12.008 */   | KW_typename identifier_opt
                     { $$= btyacc::actions->type_parameter( $1, $2, 0 ); }
/* A.12.009 */   | KW_typename identifier_opt EQUAL type_id
                     { $$= btyacc::actions->type_parameter( $1, $2, $4 ); }
/* A.12.010 */   | KW_template LESS template_parameter_list GREATER KW_class identifier_opt
                     { $$ = btyacc::actions->type_parameter_template( $1, $6, $3, 0 ); }
/* A.12.011 */   | KW_template LESS template_parameter_list GREATER KW_class identifier_opt EQUAL any_id_expression
                     { $$ = btyacc::actions->type_parameter_template( $1, $6, $3, $8 ); }
                 ;

               template_id
/* A.12.012 */   : template_name LESS template_argument_list_opt GREATER
                     { $$ = btyacc::actions->template_id( $1, $3 ); }
                 ;

              template_argument_list
/* A.12.013 */   : template_argument
                     { $$ = btyacc::actions->template_argument_list( $1, 0 ); }
/* A.12.014 */   | template_argument_list COMMA template_argument
                     { $$ = btyacc::actions->template_argument_list( $3, $1 ); }
                 ;

               template_argument
/* A.12.015 */   : assignment_expression
                     { $$ = $1; }
/* A.12.016 */   | type_id
                     { $$ = $1; }
/* A.12.017 */   | id_expression
                     { $$ = $1; }
                 ;

               explicit_instantiation
/* A.12.018 */   : KW_template declaration
                     { $$ = $2; }
                 ;

               explicit_specialization
/* A.12.019 */   : KW_template LESS GREATER declaration
                     { $$ = btyacc::actions->explicit_specialization( $4 ); }
                 ;


// ********** A.13  Exception handling  [gram.except] **********

               try_block
/* A.13.001 */   : KW_try compound_statement handler_seq
                     { $$ = btyacc::actions->try_block( $2, $3 ); }
                 ;

               function_try_block
/* A.13.002 */   : KW_try ctor_initializer_opt function_body handler_seq
                     { $$ = btyacc::actions->function_try_block( $2, $3, $4 ); }
                 ;

               handler_seq
/* A.13.003 */   : handler handler_seq_opt
                     { $$ = btyacc::actions->handler_seq( $1, $2 ); }
                 ;

               handler
/* A.13.004 */   : KW_catch LEFTPAREN exception_declaration RIGHTPAREN compound_statement
                     { $$ = btyacc::actions->handler( $3, $5 ); }
                 ;

               exception_declaration
/* A.13.005 */   : type_specifier_seq
                     { btyacc::actions->push_type_specifier( $1 ); }
                   declarator
                     { $$ = btyacc::actions->exception_declaration_named( $1, $3 ); }
/* A.13.006 */   | type_specifier_seq
                     { btyacc::actions->push_type_specifier( $1 ); }
                   abstract_declarator
                     { $$ = btyacc::actions->exception_declaration_unnamed( $1, $3 ); }
/* A.13.007 */   | type_specifier_seq
                     {
                       btyacc::actions->push_type_specifier( $1 );
                       $$ = btyacc::actions->exception_declaration_unnamed( $1, 0 );
                     }
/* A.13.008 */   | ELLIPSES
                     { $$ = btyacc::actions->exception_declaration_ellipses(); }
                 ;

               throw_expression
/* A.13.009 */   : KW_throw assignment_expression_opt
                     { $$ = btyacc::actions->throw_expression( $2 ); }
                 ;

               exception_specification
/* A.13.010 */   : KW_throw LEFTPAREN type_id_list_opt RIGHTPAREN
                     { $$ = btyacc::actions->exception_specification( $3 ); }
                 ;

               type_id_list
/* A.13.011 */   : type_id
                     { $$ = btyacc::actions->type_id_list( $1, 0 ); }
/* A.13.012 */   | type_id_list COMMA type_id
                     { $$ = btyacc::actions->type_id_list( $3, $1 ); }
                 ;


// ********** A.14  Preprocessing directives  [gram.cpp] **********

   // Gnu cpp


// ********** K.2  Opt productions  [gram.cpp] **********

              nested_name_specifier_opt
/* K.2.001 */   : nested_name_specifier
                    { $$ = $1; }
/* K.2.002 */   | /* Empty */
                    { $$ = 0;  }
                ;

              expression_list_opt
/* K.2.003 */   : expression_list
                    { $$ = $1; }
/* K.2.004 */   | /* Empty */
                    { $$ = 0;  }
                ;

              new_placement_opt
/* K.2.005 */   : new_placement
                    { $$ = $1; }
/* K.2.006 */   | /* Empty */
                    { $$ = 0;  }
                ;

              new_declarator_opt
/* K.2.007 */   : new_declarator
                    { $$ = $1; }
/* K.2.008 */   | /* Empty */
                    { $$ = 0;  }
                ;

              new_initializer_opt
/* K.2.009 */   : new_initializer
                    { $$ = $1; }
/* K.2.010 */   | /* Empty */
                    { $$ = 0;  }
                ;

              expression_opt
/* K.2.011 */   : expression
                    { $$ = $1; }
/* K.2.012 */   | /* Empty */ 
                    { $$ = 0;  }
                ;

              constant_expression_opt
/* K.2.013 */   : constant_expression
                    { $$ = $1; }
/* K.2.014 */   | /* Empty */
                    { $$ = 0;  }
                ;

              statement_seq_opt
/* K.2.015 */   : statement_seq
                    { $$ = $1; }
/* K.2.016 */   | /* Empty */
                    { $$ = 0;  }
                ;

              condition_opt
/* K.2.017 */   : condition
                    { $$ = $1; }
/* K.2.018 */   | /* Empty */
                    { $$ = 0;  }
                ;

              declaration_seq_opt
/* K.2.019 */   : declaration_seq
                    { $$ = $1; }
/* K.2.020 */   | /* Empty */
                    { $$ = 0; }
                ;

              decl_specifier_seq_opt
/* K.2.021 */   : decl_specifier_seq
                    { $$ = $1; }
/* K.2.022 */   | /* Empty */
                    { $$ = 0;  }
                ;

              enumerator_list_opt
/* K.2.023 */   : enumerator_list /*comma_opt*/
                    { $$ = $1; }
/* K.2.024 */   | /* Empty */
                    { $$ = 0;  }
                ;

              init_declarator_list_opt
/* K.2.025 */   : init_declarator_list
                    { $$ = $1; }
/* K.2.026 */   | /* Empty */
                    {
                      btyacc::actions->clearTypedefList();
                      $$ = 0;
                    }
                ;

              cv_qualifier_seq_opt
/* K.2.027 */   : cv_qualifier_seq
                    { $$ = $1; }
/* K.2.028 */   | /* Empty */
                    { $$ = 0; }
                ;

              type_specifier_seq_opt
/* K.2.029 */   : type_specifier_seq
                    { $$ = $1; }
/* K.2.030 */   | /* Empty */
                    { $$ = 0;  }
                ;

              abstract_declarator_opt
/* K.2.031 */   : abstract_declarator
                    { $$ = $1; }
/* K.2.032 */   | /* Empty */
                    { $$ = 0;  }
                ;

              direct_abstract_declarator_opt
/* K.2.033 */   : direct_abstract_declarator
                    { $$ = $1; }
/* K.2.034 */   | /* Empty */
                    { $$ = 0;  }
                ;

              ellipses_opt
/* K.2.035 */   : ELLIPSES
                    { $$ = $1; }
/* K.2.036 */   | /* Empty */
                    { $$ = 0;  }
                ;

              parameter_declaration_list_opt
/* K.2.037 */   : parameter_declaration_list
                    { $$ = $1; }
/* K.2.038 */   | /* Empty */
                    { $$ = 0;  }
                ;

              initializer_opt
/* K.2.039 */   : initializer
                    { $$ = $1; }
/* K.2.040 */   | /* Empty */ 
                    { $$ = 0;  }
                ;

              comma_opt
/* K.2.041 */   : COMMA
                    { $$ = 1; }
/* K.2.042 */   | /* Empty */
                    { $$ = 0; }
                ;

              member_specification_opt
/* K.2.043 */   : member_specification
                    { $$ = $1; }
/* K.2.044 */   | /* Empty */
                    { $$ = 0;  }
                ;

              semi_opt
/* K.2.045 */   : SEMI
                    [ YYVALID; ]
/* K.2.046 */   | /* Empty */
                    [ YYVALID; ]
                ;

              member_declarator_list_opt
/* K.2.047 */   : member_declarator_list
                    { $$ = $1; }
/* K.2.048 */   | /* Empty */
                    { $$ = btyacc::actions->member_declarator_list_opt(); }
                ;

              pure_specifier_opt
/* K.2.049 */   : pure_specifier
                    { $$ = $1; }
/* K.2.050 */   | /* Empty */
                    { $$ = 0;  }
                ;

              constant_initializer_opt
/* K.2.051 */   : constant_initializer
                    { $$ = $1; }
/* K.2.052 */   | /* Empty */
                    { $$ = 0;  }
                ;

              base_clause_opt
/* K.2.053 */   : base_clause
                    { $$ = $1; }
/* K.2.054 */   | /* Empty */
                    { $$ = 0;  }
                ;

              virtual_opt
/* K.2.055 */   : KW_virtual
                    { $$ = 1; }
/* K.2.056 */   | /* Empty */
                    { $$ = 0; }
                ;

              access_specifier_opt
/* K.2.057 */   : access_specifier
/* K.2.058 */   | /* Empty */
                ;

               conversion_declarator_opt
/* K.2.059 */   : conversion_declarator
                    { $$ = $1; }
/* K.2.060 */   | /* Empty */
                    { $$ = 0;  }
                ;

               ctor_initializer_opt
/* K.2.061 */   : ctor_initializer
                    { $$ = $1; }
/* K.2.062 */   | /* Empty */
                    { $$ = 0;  }
                ;

               colcol_opt
/* K.2.063 */   : COLCOL
                    { $$ = 1; }
/* K.2.064 */   | /* Empty */
                    { $$ = 0; }
                ;

               export_opt
/* K.2.065 */   : KW_export
                    { $$ = 1; }
/* K.2.066 */   | /* Empty */
                    { $$ = 0; }
                ;

               template_opt
/* K.2.067 */   : KW_template
                    { $$ = 1; }
/* K.2.068 */   | /* Empty */
                    { $$ = 0; }
                ;

               identifier_opt
/* K.2.069 */   : any_identifier
                    { $$ = $1; }
/* K.2.070 */   | /* Empty */
                    { $$ = 0;  }
                ;

               template_argument_list_opt
/* K.2.071 */   : template_argument_list
                    { $$ = $1; }
/* K.2.072 */   | /* Empty */
                    { $$ = 0;  }
                ;

               handler_seq_opt
/* K.2.073 */   : handler_seq
                    { $$ = $1; }
/* K.2.074 */   | /* Empty */
                    { $$ = 0;  }
                ;

               assignment_expression_opt
/* K.2.075 */   : assignment_expression
                    { $$ = $1; }
/* K.2.076 */   | /* Empty */
                    { $$ = 0;  }
                ;

               exception_specification_opt
/* K.2.077 */   : exception_specification
                    { $$ = $1; }
/* K.2.078 */   | /* Empty */
                    { $$ = 0;  }
                ;

               type_id_list_opt
/* K.2.079 */   : type_id_list
                    { $$ = $1; }
/* K.2.080 */   | /* Empty */
                    { $$ = 0;  }
                ;

              typename_opt
/* K.2.081 */   : KW_typename
                    { $$ = 1; }
/* K.2.082 */   | /* Empty */
                    { $$ = 0; }
                ;


// ********** K.3  Keystone Modifications **********

               any_id_expression
/* K.3.001 */    : any_unqualified_id
                     { $$ = btyacc::actions->any_id_expression( $1 ); }
/* K.3.002 */    | any_qualified_id
                     { $$ = btyacc::actions->any_id_expression( $1 ); }
                 ;

               any_unqualified_id
/* K.3.003 */    : any_identifier
                     { $$ = $1; }
/* K.3.004 */    | operator_function_id
                     { $$ = $1; }
/* K.3.005 */    | conversion_function_id
                     { $$ = $1->mNameDeclaration; }
/* K.3.006 */    | COMPLEMENT class_name
                     { // Added for destructor name change
                       btyacc::facade->nextIsDestructor();
                       $$ = $2->mNameDeclaration; 
                     }
/* K.3.007 */    | template_id
                     { $$ = $1->mNameDeclaration; }
                 ;

               any_qualified_id
/* K.3.008 */    : colcol_opt nested_name_specifier template_opt any_unqualified_id
                     { $$ = $4; }
/* K.3.009 */    | COLCOL any_identifier
                     { $$ = $2; }
/* K.3.010 */    | COLCOL operator_function_id
                     { $$ = $2; }
/* K.3.011 */    | COLCOL template_id
                     { $$ = $2->mNameDeclaration; }
                 ;

%%

//------------------------------------------------------------------------------

std::string getTokenText ( int token, const YYSTYPE &lval )
{
  // This seems rather nasty, but it saves us from tracking around a string
  // for each token while still providing nice error messages.

  // Also, it shows that the KeywordManager is NOT useless

  std::string retval;

  switch ( token )
  {
    case KW_asm:           case KW_do:             case KW_inline:
    case KW_short:         case KW_typeid:         case KW_auto:
    case KW_double:        case KW_int:            case KW_signed:
    case KW_typename:      case KW_bool:           case KW_dynamic_cast:
    case KW_long:          case KW_sizeof:         case KW_union:
    case KW_break:         case KW_else:           case KW_mutable:
    case KW_static:        case KW_unsigned:       case KW_case:
    case KW_enum:          case KW_namespace:      case KW_static_cast:
    case KW_using:         case KW_catch:          case KW_explicit:
    case KW_new:           case KW_struct:         case KW_virtual:
    case KW_char:          case KW_extern:         case KW_operator:
    case KW_switch:        case KW_void:           case KW_class:
    case KW_false:         case KW_private:        case KW_template:
    case KW_volatile:      case KW_const:          case KW_float:
    case KW_protected:     case KW_this:           case KW_wchar_t:
    case KW_const_cast:    case KW_for:            case KW_public:
    case KW_throw:         case KW_while:          case KW_continue:
    case KW_friend:        case KW_register:       case KW_true:
    case KW_default:       case KW_goto:           case KW_reinterpret_cast:
    case KW_try:           case KW_delete:         case KW_if:
    case KW_return:        case KW_typedef:        case KW_export:
    case KW_unsigned_char: case KW_unsigned_short: case KW_unsigned_long:
    case KW_long_double:
      retval = Parser::Instance()->keywordManager()->getName( token );
      break;

    case PS_LITERAL:
    case INTEGER_LITERAL:    case CHARACTER_LITERAL:
    case FLOATING_LITERAL:   case STRING_LITERAL:
    case IDENTIFIER:
    case ID_typedef_name:    case ID_original_namespace_name:
    case ID_namespace_alias: case ID_enum_name:
    case ID_class_name:      case ID_template_name:
      retval = lval.id_sym->getName();
      break;

    case LEFTPAREN:  retval = "(";   break;
    case RIGHTPAREN: retval = ")";   break;
    case LEFTBRACK:  retval = "{";   break;
    case RIGHTBRACK: retval = "}";   break;
    case LEFTARRAY:  retval = "[";   break;
    case RIGHTARRAY: retval = "]";   break;
    case PLUS:       retval = "+";   break;
    case MINUS:      retval = "-";   break;
    case STAR:       retval = "*";   break;
    case DIVIDE:     retval = "/";   break;
    case MOD:        retval = "%";   break;
    case GREATER:    retval = ">";   break;
    case LESS:       retval = "<";   break;
    case EQUAL:      retval = "=";   break;
    case AND:        retval = "&";   break;
    case OR:         retval = "|";   break;
    case NOT:        retval = "!";   break;
    case XOR:        retval = "^";   break;
    case COMMA:      retval = ",";   break;
    case SEMI:       retval = ";";   break;
    case COLON:      retval = ":";   break;
    case COMPLEMENT: retval = "~";   break;
    case DOT:        retval = ".";   break;
    case QUESTION:   retval = "?";   break;
    case COLCOL:     retval = "::";  break;
    case ELLIPSES:   retval = "..."; break;
    case PLUSEQ:     retval = "+=";  break;
    case MINUSEQ:    retval = "-=";  break;
    case STAREQ:     retval = "*=";  break;
    case DIVEQ:      retval = "/=";  break;
    case MODEQ:      retval = "%=";  break;
    case XOREQ:      retval = "^=";  break;
    case ANDEQ:      retval = "&=";  break;
    case OREQ:       retval = "|=";  break;
    case LTLT:       retval = "<<";  break;
    case GTGT:       retval = ">>";  break;
    case GTGTEQ:     retval = ">>="; break;
    case LTLTEQ:     retval = "<<="; break;
    case EQEQ:       retval = "==";  break;
    case NOTEQ:      retval = "!=";  break;
    case LEQ:        retval = "<=";  break;
    case GEQ:        retval = ">=";  break;
    case ANDAND:     retval = "&&";  break;
    case OROR:       retval = "||";  break;
    case PLUSPLUS:   retval = "++";  break;
    case MINUSMINUS: retval = "--";  break;
    case DOTSTAR:    retval = ".*";  break;
    case ARROWSTAR:  retval = "->*"; break;
    case ARROW:      retval = "->";  break;

    default:
      retval = "ICE - please contact keystone@cs.clemson.edu";
  }

  return retval;
}

//------------------------------------------------------------------------------

void yyerror_detailed ( char *text, int errt, YYSTYPE &errt_value, YYPOSN &errt_posn )
{
  std::cerr << (*errt_posn.filename) << ":"
            << errt_posn.lineNumber  << ": "
            << text                             << ": \'"
            << getTokenText( errt, errt_value ) << "\'"
            << std::endl;
}

//------------------------------------------------------------------------------
