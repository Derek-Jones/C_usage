//******************************************************************************
//
//  Actions.h
// 
//  Copyright (C) 2000-2004 by
// 
//    Department of Computer Science, Clemson University,
//    Department of Computer Science, National University of Ireland, Maynooth.
//  
//  http://keystone.sourceforge.net
// 
//  <keystone@cs.clemson.edu>
// 
//  Keystone is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
// 
//  Keystone is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
// 
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
// 
//******************************************************************************

#ifndef _ACTIONS_H_
#define _ACTIONS_H_

#include <list>
#include <stack>
#include <string>

#include "config.h"

#include "Ast.h"
#include "ParserUtility.h"

#if defined (__GNUG__) && (KEY_ACTION_DEBUG)
  #define PDEBUG std::cerr << "CALL: " << __PRETTY_FUNCTION__ << std::endl
#else
  #define PDEBUG
#endif

class Parser;
class ActionFacade;
class ArgumentStack;
class DeclarationStack;
class LocationTracker;
class TokenDecorator;
class Type;

class Actions
{
public:

  Actions ( LocationTracker *, TokenDecorator *, ActionFacade *, ArgumentStack *, DeclarationStack * );

  cGlobalScope* globalScope ( void ) { return global_scope; }

  const ActionFacade* getActionFacade ( void ) const { return facade; }

  //////////////////////////////////////////////////////////
  /// \section Accessors
  //////////////////////////////////////////////////////////

  /* A.7.036 */ bool sawMemberPtr   ( void ) const { return saw_member_ptr;   }
  /* A.7.037 */ bool sawFunctionDef ( void ) const { return saw_function_def; }

  //////////////////////////////////////////////////////////
  /// \section Parser to AST conversion
  //////////////////////////////////////////////////////////

  /* A.9.004 */
  /* A.9.005 */
  /* A.9.006 */
  eAccessSpecifier geteAccessSpecifier ( Access::AccessType );

  //////////////////////////////////////////////////////////
  /// \section Mutators
  //////////////////////////////////////////////////////////

  /* A.9.007 */
  /* A.9.008 */
  /* A.9.009 */ void setCurrentAccess ( Access::AccessType at ) { current_access = at; }
  
  /* A.8.005 */
  /* A.8.006 */ void setNextAccess    ( Access::AccessType at ) { next_access    = at; }

  /* A.7.007 */
  /* A.7.022 */ void setLineNumForAbsDecl ( int l  ) { line_num_for_abs_decl = l; }

  /* A.6.015 */
  /* A.7.012 */ void setSawMemberPtr   ( bool s ) { saw_member_ptr   = s; }

  /* A.6.015 */ 
  /* A.7.007 */ void setSawFunctionDef ( bool s ) { saw_function_def = s; }

  /* A.7.014 */ void setSeenConst    ( bool s ) { seen_const    = s; }
  /* A.7.015 */ void setSeenVolatile ( bool s ) { seen_volatile = s; }

  /* K.2.026 */ void clearTypedefList ( void ) { typedef_list.clear(); }

  //////////////////////////////////////////////////////////
  /// \section Semantic Actions
  //////////////////////////////////////////////////////////

  /* K.1.008 */
  /* A.1.006 */  cNameReference* class_name ( NameDeclaration * );

  /* A.3.001 */  void translation_unit_1 ( void );
  /* A.3.001 */  void translation_unit_2 ( AsgNodeList_t * );

  /* A.4.001a */
  /* A.4.001b */
  /* A.4.001c */
  /* A.4.001d */
  /* A.4.001e */ cLiteral*       primary_expression_literal ( eLiteralType, const std::string & );

  /* A.4.002 */  cNameReference*       primary_expression_this    ( void );
  /* A.4.003 */  cUnaryOperator* primary_expression_parens  ( cExpression * );

  /* A.4.007 */
  /* A.4.008 */  cNameReference* unqualified_id            ( NameDeclaration * );

  /* A.4.010 */  cNameReference* unqualified_id_destructor ( cNameReference * );
  /* A.4.012 */  cNameReference* qualified_id_nns      ( bool, cNameReference *, bool, cNameReference * );
  /* A.4.013 */  cNameReference* qualified_id          ( NameDeclaration * );
  /* A.4.015 */  cNameReference* qualified_id_template ( cNameReference * );

  /* A.4.016 */
  /* A.4.017 */  cNameReference* nested_name_specifier   ( cNameReference *, bool, cNameReference * );

  /* A.4.019 */  cNameReference* class_or_namespace_name ( NameDeclaration * );

  /* A.4.021 */  cExpression* postfix_expression_array          ( cExpression *, cExpression * );
  /* A.4.022 */  void         postfix_expression_start_function ( void );
  /* A.4.022 */  cExpression* postfix_expression_end_function   ( cExpression *, cFunctionArgumentList * );
  /* A.4.023 */  cExpression* postfix_expression_cast           ( cType *, cFunctionArgumentList * );
  /* A.4.024 */  cExpression* postfix_expression_cast_typename  ( bool, cNameReference *, cNameReference *, cFunctionArgumentList * );
  /* A.4.025 */  cExpression* postfix_expression_cast_template  ( bool, cNameReference *, bool, cNameReference *, cFunctionArgumentList * );

  /* A.4.026 */
  /* A.4.027 */
  /* A.4.028 */
  /* A.4.029 */  cExpression* postfix_expression_access         ( cExpression *, eOperator, bool, cExpression * );

  /* A.4.030 */
  /* A.4.031 */
  /* A.4.036 */  cExpression* postfix_expression_unary          ( cExpression *, eOperator );

  /* A.4.032 */
  /* A.4.033 */
  /* A.4.034 */
  /* A.4.035 */  cExpression* postfix_expression_cpp_cast       ( eOperator, cType *, cExpression * );

  /* A.4.037 */  cExpression* postfix_expression_unary_typeid   ( cType *, eOperator );

  /* A.4.038 */  cFunctionArgumentList* expression_list_start    ( cExpression * );
  /* A.4.039 */  cFunctionArgumentList* expression_list_continue ( cFunctionArgumentList *, cExpression * );

  /* A.4.040 */
  /* A.4.042 */  cNameReference* pseudo_destructor_name          ( bool, cNameReference *, cNameReference * );

  /* A.4.041 */  cNameReference* pseudo_destructor_name_template ( bool, cNameReference *, cNameReference *, cNameReference * );

  /* A.4.044 */
  /* A.4.045 */
  /* A.4.046 */
  /* A.4.047 */  cExpression* unary_expression ( eOperator, cExpression * );

  /* A.4.048 */  cExpression* unary_expression ( eOperator, cType * );

  /* A.4.057 */
  /* A.4.058 */  cExpression* new_expression    ( bool, cFunctionArgumentList *, cType *, cFunctionArgumentList * );

  /* A.4.066 */
  /* A.4.067 */  cExpression* delete_expression ( bool, cExpression *, bool );

  /* A.4.060 */  cType*     new_type_id                     ( cType *, NewDeclarationPair_t * );
  /* A.4.061 */  NewDeclarationPair_t* new_declarator_ptr              ( int, NewDeclarationPair_t * );
  /* A.4.062 */  NewDeclarationPair_t* new_declarator_direct           ( ArrayDimensionList_t * );
  /* A.4.063 */  ArrayDimensionList_t*  direct_new_declarator_exp       ( cExpression * );
  /* A.4.064 */  ArrayDimensionList_t*  direct_new_declarator_const_exp ( ArrayDimensionList_t *, cExpression * );

  /* A.4.069 */  cExpression* cast_expression           ( cType *, cExpression * );

  /* A.4.071 */
  /* A.4.072 */  cExpression* pm_expressionression             ( eOperator, cExpression *, cExpression * );

  /* A.4.074 */
  /* A.4.075 */
  /* A.4.076 */  cExpression* multiplicative_expression ( eOperator, cExpression *, cExpression * );

  /* A.4.078 */
  /* A.4.079 */  cExpression* additive_expression       ( eOperator, cExpression *, cExpression * );

  /* A.4.081 */
  /* A.4.082 */  cExpression* shift_expression          ( eOperator, cExpression *, cExpression * );

  /* A.4.084 */
  /* A.4.085 */
  /* A.4.086 */
  /* A.4.087 */  cExpression* relational_expression     ( eOperator, cExpression *, cExpression * );

  /* A.4.089 */
  /* A.4.090 */  cExpression* equality_expression       ( eOperator, cExpression *, cExpression * );
  /* A.4.092 */  cExpression* and_expression            ( eOperator, cExpression *, cExpression * );
  /* A.4.094 */  cExpression* exclusive_or_expression   ( eOperator, cExpression *, cExpression * );
  /* A.4.096 */  cExpression* inclusive_or_expression   ( eOperator, cExpression *, cExpression * );
  /* A.4.098 */  cExpression* logical_and_expression    ( eOperator, cExpression *, cExpression * );
  /* A.4.100 */  cExpression* logical_or_expression     ( eOperator, cExpression *, cExpression * );
  /* A.4.102 */  cExpression* conditional_expression    ( cExpression *, cExpression *, cExpression * );
  /* A.4.104 */  cExpression* assignment_expression     ( eOperator, cExpression *, cExpression * );
  /* A.4.118 */  cExpression* expression                ( eOperator, cExpression *, cExpression * );

  /* A.5.009 */  cLabel* labeled_statement_generic( NameDeclaration* decl, cAsgNode* stmt );
  /* A.5.010 */  cLabel* labeled_statement_case( cExpression* expr, cAsgNode* stmt );
  /* A.5.011 */  cLabel* labeled_statement_default( cAsgNode* stmt );

  /* A.5.013 */  void     compound_statement_1 ( void );
  /* A.5.013 */  cBlock*  compound_statement_2 ( AsgNodeList_t * );

  /* A.5.016 */
  /* A.5.017 */  cSelectionStatement* selection_statement_if     ( cExpression *, cAsgNode *, cAsgNode * );

  /* A.5.018 */  cSelectionStatement* selection_statement_switch ( cExpression *, cAsgNode * );

  /* A.5.020 */  cConditionDeclarator* condition ( cType *, cAsgNode *, cExpression * );

  /* A.5.021 */  cIterationStatement* iteration_statement_while ( cExpression *, cAsgNode * );
  /* A.5.022 */  cIterationStatement* iteration_statement_do    ( cExpression *, cAsgNode * );
  /* A.5.023 */  cIterationStatement* iteration_statement_for   ( cAsgNode *, cExpression *, cExpression *, cAsgNode * );

  /* A.5.026 */  cJumpStatement* jump_statement_break    ( void );
  /* A.5.027 */  cJumpStatement* jump_statement_continue ( void );
  /* A.5.028 */  cJumpStatement* jump_statement_return   ( cExpression * );
  /* A.5.029 */  cJumpStatement* jump_statement_goto     ( NameDeclaration * );

  /* A.6.001 */  AsgNodeList_t* declaration_seq_1 ( cAsgNode * );
  /* A.6.002 */  AsgNodeList_t* declaration_seq_2 ( cAsgNode *, AsgNodeList_t * );

  /* A.6.009 */  void declaration_namespace_definition ( cAsgNode * );

  /* A.6.015 */  cObjectList* simple_declaration ( DeclSpecifierList_t *, AsgNodeList_t * );

  /* A.6.017 */  DeclSpecifier_t*       decl_specifier_type     ( cType * );
  /* A.6.019 */  DeclSpecifier_t*       decl_specifier_friend   ( void );
  /* A.6.020 */  DeclSpecifier_t*       decl_specifier_typedef  ( void );
  /* A.6.021 */  DeclSpecifierList_t* decl_specifier_seq      ( DeclSpecifier_t *, DeclSpecifierList_t * );

  /* A.6.022 */
  /* A.6.023 */
  /* A.6.024 */
  /* A.6.025 */
  /* A.6.026 */  DeclSpecifier_t*       storage_class_specifier ( eDeclSpecifier );

  /* A.6.027 */
  /* A.6.028 */
  /* A.6.029 */  DeclSpecifier_t*       function_specifier      ( eDeclSpecifier );

  /* A.5.020  */
  /* A.13.005 */ void push_type_specifier( cType * );

  /* A.6.034 */  cType* cv_qualifier                    ( int );
  /* A.6.035 */  cType* simple_type_specifier_type_name ( bool, cNameReference *, cNameReference * );
  /* A.6.036 */  cType* simple_type_specifier_template  ( bool, cNameReference *, cNameReference * );

  /* A.6.037  */
  /* A.6.037a */
  /* A.6.038  */
  /* A.6.039  */
  /* A.6.040  */
  /* A.6.040a */
  /* A.6.041  */
  /* A.6.042  */
  /* A.6.042a */
  /* A.6.043  */
  /* A.6.044  */
  /* A.6.045  */
  /* A.6.046  */
  /* A.6.046a */
  /* A.6.047  */ cType* simple_type_specifier_basic_type ( const std::string & );

  /* A.6.049 */
  /* A.6.050 */  cNameReference* type_name ( NameDeclaration * );

  /* A.6.051 */  cForwardTypeInterface* elaborated_type_specifier_class    ( int, bool, cNameReference *, cNameReference * );
  /* A.6.052 */  cForwardTypeInterface* elaborated_type_specifier_enum     ( bool, cNameReference *, NameDeclaration * );
  /* A.6.053 */  cForwardTypeInterface* elaborated_type_specifier_typename ( bool, cNameReference *, NameDeclaration * );
  /* A.6.054 */  cForwardTypeInterface* elaborated_type_specifier_template ( bool, cNameReference *, bool, cNameReference * );

  /* A.6.055 */  void           enum_specifier_1      ( NameDeclaration *, int );
  /* A.6.055 */  cType*         enum_specifier_2      ( EnumeratorList_t * );
  /* A.6.056 */  EnumeratorList_t* enumerator_list_1     ( cEnumerator * );
  /* A.6.057 */  EnumeratorList_t* enumerator_list_2     ( EnumeratorList_t *, cEnumerator * );

  /* A.6.058 */
  /* A.6.059 */  cEnumerator*   enumerator_definition ( NameDeclaration *, cExpression * );

  /* A.6.065 */  void             original_namespace_definition_1  ( NameDeclaration * );
  /* A.6.065 */  cScope*          original_namespace_definition_2  ( NameDeclaration *, AsgNodeList_t * );
  /* A.6.066 */  void             extension_namespace_definition_1 ( NameDeclaration * );
  /* A.6.066 */  cScope*          extension_namespace_definition_2 ( NameDeclaration *, AsgNodeList_t * );
  /* A.6.067 */  NameDeclaration* unnamed_namespace_definition_1   ( int );
  /* A.6.067 */  cScope*          unnamed_namespace_definition_2   ( NameDeclaration *, AsgNodeList_t * );
  /* A.6.069 */  cScope*          namespace_alias_definition       ( NameDeclaration *, NameDeclaration * );

  /* A.6.071 */
  /* A.6.072 */  cUsing* using_declaration ( bool, cNameReference *, NameDeclaration * );
  /* A.6.073 */  cUsing* using_directive   ( bool, cNameReference *, NameDeclaration * );

  /* A.6.074 */  cAsmDefinition* asm_definition ( const std::string & );

  /* A.6.075 */  cLinkage* linkage_specification_block ( const std::string &, AsgNodeList_t * );
  /* A.6.076 */  cLinkage* linkage_specification_decl  ( const std::string &, cAsgNode * );

  /* A.7.001 */
  /* A.7.002 */  AsgNodeList_t*  init_declarator_list    ( cAsgNode *, AsgNodeList_t * );
  /* A.7.003 */  cAsgNode* init_declarator         ( cAsgNode *, cExpressionBase * );
  /* A.7.004 */  cAsgNode* declarator_direct       ( cAsgNode * );
  /* A.7.005 */  void         declarator_ptr_1        ( int );
  /* A.7.005 */  cIdentifier* declarator_ptr_2        ( int, cAsgNode * );
  /* A.7.006 */  cIdentifier* direct_declarator_id    ( cNameReference * );
  /* A.7.007 */  void         direct_declarator_fun_1 ( cAsgNode * );
  /* A.7.007 */  cAsgNode*    direct_declarator_fun_2 ( cAsgNode *, cFunctionParameterList *, int, cExceptionSpecification * );
  /* A.7.008 */  cIdentifier* direct_declarator_arr   ( cAsgNode *, cExpression * );

  /* A.7.010 */
  /* A.7.011 */
  /* A.7.012 */  int    ptr_operator       ( int, int );
  /* A.7.018 */  cType* type_id            ( cType *, cType * );
  /* A.7.019 */  cType* type_specifier_seq ( cType *, cType * );

  /* A.7.020 */  cType* abstract_declarator            ( int, cType * );
  /* A.7.022 */  cType* direct_abstract_declarator_fun ( cType *, cFunctionParameterList *, int, cExceptionSpecification * );
  /* A.7.023 */  cType* direct_abstract_declarator_arr ( cType *, cExpression * );

  /* A.7.025 */
  /* A.7.026 */  cFunctionParameterList*          parameter_declaration_clause  ( cFunctionParameterList *, bool );

  /* A.7.027 */
  /* A.7.028 */  cFunctionParameterList*          parameter_declaration_list    ( cFunctionParameter *, cFunctionParameterList * );

  /* A.7.029 */
  /* A.7.030 */  cFunctionParameter* parameter_declaration_named   ( DeclSpecifierList_t *, cAsgNode *, cExpression * );

  /* A.7.031 */
  /* A.7.032 */  cFunctionParameter* parameter_declaration_unnamed ( DeclSpecifierList_t *, cType *, cExpression * );

  /* A.7.033 */
  /* A.7.034 */  void       function_definition_1 ( cAsgNode * );

  /* A.7.033 */
  /* A.7.034 */  cFunctionInterface* function_definition_2 ( DeclSpecifierList_t *, cAsgNode *, cBlock *, cBlock * );

  /* A.7.041 */
  /* A.7.042 */  cInitializerList* initializer_list ( cExpressionBase *, cInitializerList * );

  /* A.8.001 */  cClassTypeInterface* class_specifier ( cClassTypeInterface *, ClassPairList_t * );
  /* A.8.002 */  NameDeclaration* class_head_opt         ( NameDeclaration * );
  /* A.8.003 */  NameDeclaration* class_head_nns         ( NameDeclaration * );

  /* A.8.002 */ 
  /* A.8.003 */  cClassTypeInterface* class_head             ( int, cNameReference *, NameDeclaration *, BaseClassList_t * );

  /* A.8.004 */  cNameReference*            class_head_template    ( cNameReference * );
  /* A.8.004 */  cClassTypeInterface* class_head_template_bc ( int, cNameReference *, cNameReference *, BaseClassList_t * );

  /* A.8.008 */  ClassPairList_t* member_specification             ( ClassPair_t *, ClassPairList_t * );
  /* A.8.010 */  ClassPair_t*  member_declaration               ( DeclSpecifierList_t *, MemberList_t * );
  /* A.8.011 */  ClassPair_t*  member_declaration_fundef        ( cAsgNode * );
  /* A.8.012 */  ClassPair_t*  member_declaration_disambiguated ( cNameReference *, cNameReference * );
  /* A.8.013 */  ClassPair_t*  member_declaration_using         ( cAsgNode * );
  /* A.8.014 */  ClassPair_t*  member_declaration_template      ( cAsgNode * );

  /* A.8.015 */
  /* A.8.016 */  MemberList_t*      member_declarator_list      ( cIdentifier *, MemberList_t * );

  /* K.2.048 */  MemberList_t*      member_declarator_list_opt  ( void );

  /* A.8.017 */ 
  /* A.8.018 */  cIdentifier*    member_declarator           ( cAsgNode *, cExpression * );
  /* A.8.019 */  cIdentifier*    member_declarator_bitfield  ( NameDeclaration *, int, cExpression * );

  /* A.8.020 */  cExpression*    pure_specifier       ( const std::string & );
  /* A.8.021 */  cExpression*    constant_initializer ( cExpression * );

  /* A.9.002 */
  /* A.9.003 */  BaseClassList_t* base_specifier_list  ( BaseClassPair_t *, BaseClassList_t * );

  /* A.9.004 */ 
  /* A.9.005 */ 
  /* A.9.006 */  BaseClassPair_t*    base_specifier       ( cNameReference *, cNameReference *, eAccessSpecifier, bool );

  /* A.10.001 */ cNameReference* conversion_function_id ( int, cType * );
  /* A.10.002 */ cType*    conversion_type_id     ( cType *, cType * );
  /* A.10.003 */ cType*    conversion_declarator  ( int, cType * );

  /* A.10.004 */ cBlock*      ctor_initializer     ( AsgNodeList_t * );

  /* A.10.005 */
  /* A.10.006 */ AsgNodeList_t*  mem_initializer_list ( cAsgNode *, AsgNodeList_t * );
  /* A.10.007 */ cExpression* mem_initializer      ( cNameReference *, cFunctionArgumentList * );
  /* A.10.009 */ cNameReference*    mem_initializer_id   ( NameDeclaration * );

  /* A.12.001 */ void                template_declaration_1           ( void );
  /* A.12.001 */ void                template_declaration_leave_scope ( void );
  /* A.12.001 */ cAsgNode*            template_declaration_2           ( int, cTemplateParameterList *, cAsgNode * );

  /* A.12.002 */
  /* A.12.003 */ cTemplateParameterList* template_parameter_list          ( cTemplateParameter *, cTemplateParameterList * );
  /* A.12.005 */ cTemplateParameter*      template_parameter               ( cFunctionParameter * );

  /* A.12.006 */
  /* A.12.007 */
  /* A.12.008 */
  /* A.12.009 */ cTemplateParameter*      type_parameter                   ( int, NameDeclaration *, cType * );

  /* A.12.010 */ 
  /* A.12.011 */ cTemplateParameter*      type_parameter_template          ( int, NameDeclaration *, cTemplateParameterList *, cNameReference * );
  /* A.12.012 */ cNameReference*           template_id                      ( NameDeclaration *, TemplateArgumentList_t * );

  /* A.12.013 */ 
  /* A.12.014 */ TemplateArgumentList_t*  template_argument_list           ( cAsgNode *, TemplateArgumentList_t * );

  /* A.12.019 */ cAsgNode* explicit_specialization ( cAsgNode * );

  /* A.13.001 */ cAsgNode*           try_block                     ( cAsgNode *, HandlerList_t * );
  /* A.13.002 */ cBlock*            function_try_block            ( cBlock *, cAsgNode *, HandlerList_t * );
  /* A.13.003 */ HandlerList_t*        handler_seq                   ( cHandler *, HandlerList_t * );
  /* A.13.004 */ cHandler*       handler                       ( cExceptionDeclaration *, cAsgNode * );
  /* A.13.005 */ cExceptionDeclaration* exception_declaration_named   ( cType *, cAsgNode * );

  /* A.13.006 */ 
  /* A.13.007 */ cExceptionDeclaration* exception_declaration_unnamed  ( cType *, cType * );
  /* A.13.008 */ cExceptionDeclaration* exception_declaration_ellipses ( void );
  /* A.13.009 */ cThrowExpression*            throw_expression              ( cExpression * );
  /* A.13.010 */ cExceptionSpecification*        exception_specification       ( ThrowList_t * );

  /* A.13.011 */ 
  /* A.13.012 */ ThrowList_t*          type_id_list                  ( cType *, ThrowList_t * );

  /* K.3.001 */ 
  /* K.3.002 */  cNameReference* any_id_expression ( NameDeclaration * );

private:

  cType* createLiteralType ( eLiteralType );

  //////////////////////////////////////////////////////////
  /// \section Parser
  //////////////////////////////////////////////////////////

  NameDeclaration* checkUnaryOp  ( int, NameDeclaration * );
  NameDeclaration* checkBinOp    ( int, NameDeclaration *, NameDeclaration * );
  NameDeclaration* checkAnon     ( NameDeclaration *, int );
  NameDeclaration* checkAnonNS   ( NameDeclaration *, int );
  NameDeclaration* checkAnonParm ( NameDeclaration *, int, int );

  static std::string makeOperatorName ( int );

  std::string getCurrentFilename ( void );
  int         getCurrentLine     ( void );

  /// apply a Keystone Type as the referenced or returned Type of another.
  /// rhs will be applied as:
  ///   - the referenced Type if lhs is an IndirectType.
  ///   - the return Type if lhs is a FunctionType.
  /// @param lhs the target Type.
  /// @param rhs the Type to be applied.
  void applyKeyType ( Type *lhs, Type *rhs );


  //////////////////////////////////////////////////////////
  /// \section AST
  //////////////////////////////////////////////////////////

  static bool isPtr ( int );
  static bool isRef ( int );

  static cType* declaredType ( cType *, bool );
  static bool hasDeclSpec ( DeclSpecifierList_t *, eDeclSpecifier );
  static cType* findType ( DeclSpecifierList_t * );

  /// get a pointer to a cNameReference node for the owning Named Namespace of the cIdentifier node.
  /// @return a pointer to the cNameReference node for the owning Named Namespace.
  /// @param n a pointer to a cIdentifier node.
  static cNameReference* getNamedNamespace ( cIdentifier *n );

  /// get a pointer to the cType node associated with the cIdentifier node.
  /// @return a pointer to the cType node.
  /// @param n a pointer to a cIdentifier node.
  //! \pre n is not null
  static cType* getType ( cIdentifier *n ) { return n->getType(); }

  /// get a pointer to the cType node associated with the cIdentifier node.
  /// The returned pointer may represent:
  ///   - the return type of a cFunction.
  ///   - the type of a non-cFunction.
  /// @return a pointer to the cType node.
  /// @param n a pointer to a cIdentifier node.
  //! \pre n is not null
  static cType* getReturnType ( cIdentifier *n );

  static inline void makeConst    ( cType *n ) { if ( n ) {  n->mIsConst    = true; } }
  static inline void makeVolatile ( cType *n ) { if ( n ) {  n->mIsVolatile = true; } }

  static void makeCV ( cType *, int );

  /// just a wrapper?
  static void setType ( cIdentifier *, cType * );

  /// apply a cType as an attribute cType of another.
  /// rhs will be applied as:
  ///   - the base type if lhs is a cPointerType or cReferenceType.
  ///   - the basic type if lhs is a cArrayType.
  ///   - the return type if lhs is a cFunctionType.
  ///   - the aliased type if lhs is a cAliasType.
  /// @return lhs with rhs applied
  /// @param lhs the target cType.
  /// @param rhs the cType to be applied.
  cType* applyType ( cType *lhs, cType *rhs );

  /// mask type
  /// returns
  ///   - lhs if:
  ///     - lhs is of one of these kinds
  ///       - cPointerType
  ///       - cReferenceType
  ///       - cArrayType
  ///       - cFunctionType
  ///       - cAliasType
  ///   - 0 else:
  /// @return lhs or 0
  /// @param lhs a pointer to a cType node.  
  cType* maskType ( cType *lhs );

  /// apply list of collected DeclSpecifier_t to a cType node.
  /// @param n a pointer to a cType node.
  /// @param l a list of collected DeclSpecifier_t
  void updateType ( cType *n, DeclSpecifierList_t *l );

  //////////////////////////////////////////////////////////
  /// \section Parser to AST conversion
  //////////////////////////////////////////////////////////

  int         getStartLine       ( const cAsgNode * );
  int         getEndLine         ( const cAsgNode * );

  /// get the Keystone AccessType corresponding to the eAccessSpecifier parameter.
  /// @return the Keystone AccessType corresponding to v
  /// @param v an AST eAccessSpecifier value
  static Access::AccessType getAccess ( eAccessSpecifier v );

  /// get a pointer to the Keystone NameDeclaration of the cExpression node.
  /// @return a pointer to the Keystone NameDeclaration.
  /// @param n a pointer to a cExpression node.
  //! \pre n is not null
  static NameDeclaration* getDecl ( cExpression *n ) { return n->getKeyDecl(); }

  /// get a pointer to the Keystone Type of the cType node.
  /// @return a pointer to the Keystone Type.
  /// @param n a pointer to a cType node.
  //! \pre n is not null
  static Type* getKeyType ( cType *n ) { return n->getKeyType(); }

public:
  void pushEntryAccess ( Access::AccessType at ) { entryAccessStack.push( at ); }
  void popEntryAccess  ( void )                  { entryAccessStack.pop( ); }

  Access::AccessType getEntryAccess   ( void ) const { return entryAccessStack.top(); }
  Access::AccessType getCurrentAccess ( void ) const { return current_access; }

private:
  LocationTracker  *location;
  TokenDecorator   *decorator;
  ActionFacade     *facade;
  ArgumentStack    *argStack;
  DeclarationStack *declStack;

  NameDeclaration *current_enum;

  cGlobalScope     *global_scope;
  cCompilationScope *compile;

  int lastAddressOperator;

  int line_num_for_abs_decl;

  bool saw_member_ptr;
  bool saw_function_def;

  bool seen_const;
  bool seen_volatile;
  bool seen_friend;
  bool seen_friend_tree;
  bool seen_virtual;
  bool seen_pure;
  bool seen_static;

  std::string signature;

  // save the access found upon entering the most recent class/struct
  std::stack<Access::AccessType> entryAccessStack;

  Access::AccessType current_access;
  Access::AccessType next_access;

  std::list<NameDeclaration *> typedef_list;
};

#endif
