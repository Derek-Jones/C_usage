
    1 TU: translation_unit

    2 translation_unit: external_declaration
    3                 | statement

    4 primary_expr: IDENTIFIER
    5             | CONSTANT
    6             | string_seq
    7             | OPEN_RND expression CLOSE_RND

    8 string_seq: STRING_LITERAL
    9           | string_seq STRING_LITERAL

   10 argument_expr_list_opt: /* empty */
   11                       | argument_expr_list

   12 postfix_expr: primary_expr
   13             | postfix_expr OPEN_SQUARE expression CLOSE_SQUARE
   14             | postfix_expr OPEN_RND argument_expr_list_opt CLOSE_RND
   15             | postfix_expr DOT IDENTIFIER
   16             | postfix_expr DEREF IDENTIFIER
   17             | postfix_expr PLUSPLUS
   18             | postfix_expr MINUSMINUS
   19             | OPEN_RND type_name CLOSE_RND OPEN_CURL initializer_list CLOSE_CURL
   20             | OPEN_RND type_name CLOSE_RND OPEN_CURL initializer_list COMMA CLOSE_CURL

   21 argument_expr_list: assignment_expr
   22                   | argument_expr_list COMMA assignment_expr

   23 unary_expr: postfix_expr
   24           | PLUSPLUS unary_expr
   25           | MINUSMINUS unary_expr
   26           | unary_operator cast_expr
   27           | SIZEOF unary_expr
   28           | SIZEOF OPEN_RND type_name CLOSE_RND

   29 unary_operator: AND
   30               | TIMES
   31               | ADD
   32               | MINUS
   33               | BITNEGATE
   34               | NOT

   35 cast_expr: unary_expr
   36          | OPEN_RND type_name CLOSE_RND cast_expr

   37 multiplicative_expr: cast_expr
   38                    | multiplicative_expr TIMES cast_expr
   39                    | multiplicative_expr DIVIDE cast_expr
   40                    | multiplicative_expr REMAINDER cast_expr

   41 additive_expr: multiplicative_expr
   42              | additive_expr ADD multiplicative_expr
   43              | additive_expr MINUS multiplicative_expr

   44 shift_expr: additive_expr
   45           | shift_expr LEFTSHIFT additive_expr
   46           | shift_expr RIGHTSHIFT additive_expr

   47 relational_expr: shift_expr
   48                | relational_expr LT shift_expr
   49                | relational_expr GT shift_expr
   50                | relational_expr LE shift_expr
   51                | relational_expr GE shift_expr

   52 equality_expr: relational_expr
   53              | equality_expr EQUAL relational_expr
   54              | equality_expr NOTEQUAL relational_expr

   55 AND_expr: equality_expr
   56         | AND_expr AND equality_expr

   57 exclusive_OR_expr: AND_expr
   58                  | exclusive_OR_expr XOR AND_expr

   59 inclusive_OR_expr: exclusive_OR_expr
   60                  | inclusive_OR_expr OR exclusive_OR_expr

   61 logical_AND_expr: inclusive_OR_expr
   62                 | logical_AND_expr ANDTEST inclusive_OR_expr

   63 logical_OR_expr: logical_AND_expr
   64                | logical_OR_expr ORTEST logical_AND_expr

   65 conditional_expr: logical_OR_expr
   66                 | logical_OR_expr QUESTION expression COLON conditional_expr

   67 assignment_expr: conditional_expr
   68                | unary_expr assignment_operator assignment_expr

   69 assignment_operator: ASSIGN
   70                    | TIMESASSIGN
   71                    | DIVASSIGN
   72                    | REMASSIGN
   73                    | PLUSASSIGN
   74                    | MINUSASSIGN
   75                    | LSASSIGN
   76                    | RSASSIGN
   77                    | ANDASSIGN
   78                    | ORASSIGN
   79                    | XORASSIGN

   80 expression: assignment_expr
   81           | expression COMMA assignment_expr

   82 constant_expr: conditional_expr

   83 declaration: declaration_specifiers SEMICOLON
   84            | declaration_specifiers init_declarator_list SEMICOLON

   85 decl_specifier: storage_class_specifier
   86               | type_specifier
   87               | type_qualifier
   88               | function_specifier

   89 declaration_specifiers: decl_specifier
   90                       | declaration_specifiers decl_specifier

   91 init_declarator_list: init_declarator
   92                     | init_declarator_list COMMA init_declarator

   93 init_declarator: declarator
   94                | declarator ASSIGN initializer

   95 storage_class_specifier: TYPEDEF
   96                        | EXTERN
   97                        | STATIC
   98                        | AUTO
   99                        | REGISTER

  100 type_specifier: VOID
  101               | CHAR
  102               | SHORT
  103               | INT
  104               | LONG
  105               | FLOAT
  106               | DOUBLE
  107               | SIGNED
  108               | UNSIGNED
  109               | _BOOL
  110               | _COMPLEX
  111               | _IMAGINARY
  112               | struct_or_union_specifier
  113               | enum_specifier
  114               | typedef_name

  115 identifier_opt: /* empty */
  116               | IDENTIFIER

  117 struct_or_union_specifier: struct_or_union identifier_opt OPEN_CURL struct_declaration_list CLOSE_CURL
  118                          | struct_or_union IDENTIFIER

  119 struct_or_union: STRUCT
  120                | UNION

  121 struct_declaration_list: struct_declaration
  122                        | struct_declaration_list struct_declaration

  123 struct_declaration: specifier_qualifier_list struct_declarator_list SEMICOLON

  124 spec_qual_list: type_specifier
  125               | type_qualifier

  126 specifier_qualifier_list: spec_qual_list
  127                         | specifier_qualifier_list spec_qual_list

  128 struct_declarator_list: struct_declarator
  129                       | struct_declarator_list COMMA struct_declarator

  130 struct_declarator: declarator
  131                  | COLON constant_expr

  132 enum_specifier: ENUM identifier_opt OPEN_CURL enumerator_list CLOSE_CURL
  133               | ENUM identifier_opt OPEN_CURL enumerator_list COMMA CLOSE_CURL
  134               | ENUM IDENTIFIER

  135 enumerator_list: enumerator
  136                | enumerator_list COMMA enumerator

  137 enumerator: IDENTIFIER
  138           | IDENTIFIER ASSIGN constant_expr

  139 type_qualifier: CONST
  140               | RESTRICT
  141               | VOLATILE

  142 function_specifier: INLINE

  143 pointer_opt: /* empty */
  144            | pointer

  145 declarator: pointer_opt direct_declarator

  146 fndef_declarator: pointer_opt fndef_direct_declarator

  147 type_qualifier_list_opt: /* empty */
  148                        | type_qualifier_list

  149 assignment_expr_opt: /* empty */
  150                    | assignment_expr

  151 identifier_list_opt: /* empty */
  152                    | identifier_list

  153 direct_declarator: IDENTIFIER
  154                  | OPEN_RND declarator CLOSE_RND
  155                  | direct_declarator OPEN_SQUARE type_qualifier_list_opt assignment_expr_opt CLOSE_SQUARE
  156                  | direct_declarator OPEN_SQUARE STATIC type_qualifier_list_opt assignment_expr CLOSE_SQUARE
  157                  | direct_declarator OPEN_SQUARE type_qualifier_list STATIC assignment_expr CLOSE_SQUARE
  158                  | direct_declarator OPEN_SQUARE type_qualifier_list_opt TIMES CLOSE_SQUARE
  159                  | fndef_direct_declarator

  160 fndef_direct_declarator: direct_declarator OPEN_RND parameter_type_list CLOSE_RND
  161                        | direct_declarator OPEN_RND identifier_list_opt CLOSE_RND

  162 pointer: TIMES type_qualifier_list_opt
  163        | TIMES type_qualifier_list_opt pointer

  164 type_qualifier_list: type_qualifier
  165                    | type_qualifier_list type_qualifier

  166 parameter_type_list: parameter_list
  167                    | parameter_list COMMA ELLIPSIS

  168 parameter_list: parameter_declaration
  169               | parameter_list COMMA parameter_declaration

  170 abstract_declarator_opt: /* empty */
  171                        | abstract_declarator

  172 parameter_declaration: declaration_specifiers declarator
  173                      | declaration_specifiers
  174                      | declaration_specifiers abstract_declarator

  175 identifier_list: IDENTIFIER
  176                | identifier_list COMMA IDENTIFIER

  177 type_name: specifier_qualifier_list abstract_declarator_opt

  178 abstract_declarator: pointer
  179                    | pointer_opt direct_abstract_declarator

  180 direct_abstract_declarator_opt: /* empty */
  181                               | direct_abstract_declarator

  182 parameter_type_list_opt: /* empty */
  183                        | parameter_type_list

  184 direct_abstract_declarator: OPEN_RND abstract_declarator CLOSE_RND
  185                           | direct_abstract_declarator_opt OPEN_SQUARE assignment_expr_opt CLOSE_SQUARE
  186                           | direct_abstract_declarator_opt OPEN_SQUARE TIMES CLOSE_SQUARE
  187                           | direct_abstract_declarator_opt OPEN_RND parameter_type_list_opt CLOSE_RND

  188 typedef_name: IDENTIFIER

  189 initializer: assignment_expr
  190            | OPEN_CURL initializer_list CLOSE_CURL
  191            | OPEN_CURL initializer_list COMMA CLOSE_CURL

  192 designation_opt: /* empty */
  193                | designation

  194 initializer_list: designation_opt initializer
  195                 | initializer_list COMMA designation_opt initializer

  196 designation: designator_list ASSIGN

  197 designator_list: designator
  198                | designator_list designator

  199 designator: OPEN_SQUARE constant_expr CLOSE_SQUARE
  200           | DOT IDENTIFIER

  201 statement: labeled_statement
  202          | expression_statement
  203          | selection_header
  204          | iteration_header
  205          | OPEN_CURL
  206          | jump_statement

  207 labeled_statement: IDENTIFIER COLON statement
  208                  | CASE constant_expr COLON statement
  209                  | DEFAULT COLON statement

  210 expression_statement: expr_opt SEMICOLON

  211 selection_header: IF OPEN_RND expression CLOSE_RND
  212                 | SWITCH OPEN_RND expression CLOSE_RND

  213 expr_opt: /* empty */
  214         | expression

  215 iteration_header: WHILE OPEN_RND expression CLOSE_RND
  216                 | DO
  217                 | FOR OPEN_RND expr_opt SEMICOLON expr_opt SEMICOLON expr_opt CLOSE_RND
  218                 | FOR OPEN_RND declaration expr_opt SEMICOLON expr_opt CLOSE_RND

  219 jump_statement: GOTO IDENTIFIER SEMICOLON
  220               | CONTINUE SEMICOLON
  221               | BREAK SEMICOLON
  222               | RETURN expr_opt SEMICOLON

  223 external_declaration: function_header
  224                     | declaration

  225 declaration_list_opt: /* empty */
  226                     | declaration_list

  227 function_header: declaration_specifiers fndef_declarator declaration_list_opt OPEN_CURL

  228 declaration_list: declaration
  229                 | declaration_list declaration
***

