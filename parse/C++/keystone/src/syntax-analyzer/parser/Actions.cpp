//******************************************************************************
//
//  Actions.cpp
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

#include <algorithm>

#include "CommandLineOptions.h"

#include "Assertion.h"

#include "ActionFacade.h"
#include "ArgumentStack.h"
#include "DeclarationStack.h"
#include "LocationTracker.h"
#include "NameOccurrence.h"
#include "TokenDecorator.h"

#include "NameDeclaration.h"
#include "Scope.h"
#include "ClassScope.h"
#include "NamespaceScope.h"
#include "Type.h"
#include "BasicType.h"
#include "ClassType.h"
#include "EnumType.h"
#include "FunctionType.h"
#include "IndirectType.h"
#include "NamespaceType.h"
#include "TemplateParameterType.h"
#include "TemplateTemplateParameterType.h"

#include "ActionsHelp.h"
#include "ParserUtility.h"

#include "Actions.h"

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

namespace key
{
  extern NodeState *gNodeState;
  extern void getNewTC( void );

  template < typename T >
  T safe_deref ( T *arg )
  {
    if ( arg )
      return ( *arg );

    return T();
  }
}

//------------------------------------------------------------------------------
// Public Methods
//------------------------------------------------------------------------------

Actions::Actions ( LocationTracker  *lt, TokenDecorator *td,
                   ActionFacade     *af, ArgumentStack  *as,
                   DeclarationStack *ds
                 )
                : location              ( lt ),
                  decorator             ( td ),
                  facade                ( af ),
                  argStack              ( as ),
                  declStack             ( ds ),
                  current_enum          ( 0 ),
                  global_scope          ( 0 ),
                  compile               ( 0 ),
                  lastAddressOperator   ( 0 ),
                  line_num_for_abs_decl ( 0 ),
                  saw_member_ptr        ( false ),
                  saw_function_def      ( false ),
                  seen_const            ( false ),
                  seen_volatile         ( false ),
                  seen_friend           ( false ),
                  seen_friend_tree      ( false ),
                  seen_virtual          ( false ),
                  seen_pure             ( false ),
                  seen_static           ( false ),
                  //signature
                  current_access        ( Access::None )
                  //next_access
{
  key::getNewTC();

  compile      = STATE->cCompilationScopeCreate( "", 1, 0, "", VB_UNKNOWN, 0, AsgNodeList_t() );
  global_scope = STATE->cGlobalScopeCreate( "", 0, 0, "", VB_UNKNOWN, 0, AsgNodeList_t() );
}

//------------------------------------------------------------------------------

eAccessSpecifier Actions::geteAccessSpecifier ( Access::AccessType at ) {

  eAccessSpecifier retval;

  switch ( at )
  {
    case Access::Private:   retval = VB_PRIVATE;   break;
    case Access::Protected: retval = VB_PROTECTED; break;
    case Access::Public:    retval = VB_PUBLIC;    break;
    case Access::None:
    default:                retval = VB_UNKNOWN;
  }

  return ( retval );
}

//------------------------------------------------------------------------------

/// K.1.008 | A.1.006
cNameReference* Actions::class_name ( NameDeclaration *decl )
{
  return STATE->cNameReferenceCreate( getCurrentFilename(),
                                getCurrentLine(),
                                getCurrentLine(),
                                decl->getName(),
                                decl,
                                0,
                                0
                              );
}

/// A.3.001
void Actions::translation_unit_1 ( void )
{
}

/// A.3.001
void Actions::translation_unit_2 ( AsgNodeList_t *node_list )
{
  PDEBUG;

  #ifdef KEY_PROCESSOR_ACTION_DEBUG
    std::cerr << "syntactially correct program" << endl;
  #endif

  if ( !declStack->empty() )
  {
    cout << "*** Missed a pop of declStack stack! ***" << endl;
    declStack->printAndEmpty();
  }

  AsgNodeList_t *newNodeList = key::collapseContainedObjectLists( node_list );

  //cSourceFile *sf = STATE->cSourceFileCreate( "", 0, 0, "filename", AsgNodeList_t() );

  if ( newNodeList )
  {
    //sf->mContents.insert( sf->mContents.begin(), newNodeList->begin(), newNodeList->end() );
    compile->mContents.insert( compile->mContents.begin(), newNodeList->begin(), newNodeList->end() );
  }

  //compile->mContents.push_back( sf );

  CommandLineOptions *cmd = CommandLineOptions::Instance();

  compile->mName = cmd->getFilenames().front();

  delete node_list;
  delete newNodeList;

  global_scope->mContents.push_back( compile );
}

/// A.4.001[a,b,c,d,e]
cLiteral* Actions::primary_expression_literal ( eLiteralType op, const string &str )
{
  PDEBUG;

  cLiteral *literal = STATE->cLiteralCreate( getCurrentFilename(),
                                             getCurrentLine(),
				                                     getCurrentLine(),
                                             str
                                           );

  literal->mType = createLiteralType( op );

  return literal;
}

/// A.4.002
cNameReference* Actions::primary_expression_this ( void )
{
  PDEBUG;

  Scope *tmp = facade->getCurrentClassScope();

  return STATE->cNameReferenceCreate( getCurrentFilename(), 
                                getCurrentLine(),
                                getCurrentLine(),
                                "this",
                                tmp->getDecl(),
                                0,
                                0
                              );
}

/// A.4.003
cUnaryOperator* Actions::primary_expression_parens ( cExpression *expr )
{
  PDEBUG;

  int fline = std::min( getStartLine( expr ), getCurrentLine() );
  int lline = std::max( getEndLine( expr ), getCurrentLine() );

  return STATE->cUnaryOperatorCreate( getCurrentFilename(), 
                                      fline,
                                      lline,
                                      OT_UPAREN,
                                      expr
                                    );
}

/// A.4.007 | A.4.008
cNameReference* Actions::unqualified_id ( NameDeclaration *decl )
{
  PDEBUG;

  return STATE->cNameReferenceCreate( getCurrentFilename(), 
                                getCurrentLine(),
                                getCurrentLine(),
                                decl->getName(),
                                decl,
                                0,
                                0
                              );
}

/// A.4.010
cNameReference* Actions::unqualified_id_destructor ( cNameReference *decl )
{
  PDEBUG;

  // THG - Added for destructor name change
  facade->nextIsDestructor();

  return STATE->cNameReferenceCreate( getCurrentFilename(), 
                                getStartLine( decl ),
                                getEndLine( decl ),
                                string("~") + decl->mNameDeclaration->getName(),
                                decl->mNameDeclaration,
                                decl->mTemplateArguments,
                                decl->mNamedNamespace
                              );
}

/// A.4.012
cNameReference* Actions::qualified_id_nns ( bool colcol_opt, cNameReference *ref, bool template_opt, cNameReference *decl )
{
  PDEBUG;

  if( !decl->mNameDeclaration->getOccurQual() )
  {
    decl->mNameDeclaration->setOccurQual( ref->mNameDeclaration );
  }

  if ( colcol_opt && ref )
  {
    ref->mNamedNamespace = STATE->cNameReferenceCreate( getCurrentFilename(),
                                                          getCurrentLine(),
                                                          getCurrentLine(),
                                                          "::",
                                                          0,
                                                          0,
                                                          0
                                                        );
  }

  decl->mNamedNamespace = ref;

  return decl;
}

/// A.4.013
cNameReference* Actions::qualified_id ( NameDeclaration *decl )
{
  PDEBUG;

  return STATE->cNameReferenceCreate( getCurrentFilename(), 
                                getCurrentLine(),
                                getCurrentLine(),
                                decl->getName(),
                                decl,
                                0,
                                STATE->cNameReferenceCreate( getCurrentFilename(),
                                                             getCurrentLine(),
                                                             getCurrentLine(),
                                                             "::",
                                                             0,
                                                             0,
                                                             0
                                                           )
                              );
}

/// A.4.015
cNameReference* Actions::qualified_id_template ( cNameReference *nameref )
{
  nameref->mName = "::" + nameref->mName;

  return nameref;
}

/// A.4.016 | A.4.017
cNameReference* Actions::nested_name_specifier ( cNameReference *decl, bool template_opt, cNameReference *rest )
{
  PDEBUG;

  if ( rest )
  {
    cNameReference *first = rest;
    while( first->mNamedNamespace )
      first = first->mNamedNamespace;

    first->mNamedNamespace = decl;
    return rest;
  }

  return decl;
}

/// A.4.019
cNameReference* Actions::class_or_namespace_name ( NameDeclaration *decl )
{
  return STATE->cNameReferenceCreate( getCurrentFilename(), 
                                getCurrentLine(),
                                getCurrentLine(),
                                decl->getName(),
                                decl,
                                0,
                                0
                              );
}

/// A.4.021
cExpression* Actions::postfix_expression_array ( cExpression *lhs, cExpression *rhs )
{
  PDEBUG;

  // if need decl -> checkBinOp( LEFTARRAY, getDecl(lhs), getDecl(rhs) )

  int fline = std::min( getStartLine( lhs ), getCurrentLine() );
  int lline = std::max( getEndLine( rhs ), getCurrentLine() );

  return STATE->cBinaryOperatorCreate( getCurrentFilename(), 
                                       fline,
                                       lline,
                                       OT_ARRAY_REF,
                                       lhs,
                                       rhs
                                     );
}

/// A.4.022
void Actions::postfix_expression_start_function ( void )
{
  PDEBUG;

  argStack->startArgumentList();
}

/// A.4.022
cExpression* Actions::postfix_expression_end_function ( cExpression *funname, cFunctionArgumentList *parms )
{
  PDEBUG;

  argStack->endArgumentList();

  return STATE->cBinaryOperatorCreate( getCurrentFilename(), 
                                       getStartLine( funname ),
                                       getCurrentLine(),
                                       OT_FCT_CALL,
                                       funname,
                                       parms
                                     );
}

/// A.4.023
cExpression* Actions::postfix_expression_cast ( cType *casttype, cFunctionArgumentList *parms )
{
  PDEBUG;

  return STATE->cBinaryOperatorCreate( getCurrentFilename(), 
                                       getStartLine(casttype),
                                       getCurrentLine(),
                                       OT_CPP_CAST_CALL,
                                       casttype,
                                       parms
                                     );
}

/// A.4.024
cExpression* Actions::postfix_expression_cast_typename ( bool colcol_opt, cNameReference *nns, cNameReference *id, cFunctionArgumentList *parms )
{
  PDEBUG;

  int fline = ( nns ? getStartLine( nns ) : getStartLine( id ) );

  return STATE->cBinaryOperatorCreate( getCurrentFilename(),
                                       fline,
                                       getCurrentLine(),
                                       OT_CPP_CAST_CALL,
                                       STATE->cNameReferenceCreate( getCurrentFilename(),
                                                              getStartLine( id ),
                                                              getEndLine( id ),
                                                              id->mName,
                                                              id->mNameDeclaration,
                                                              id->mTemplateArguments,
                                                              nns
                                                            ),
                                       parms
                                     );
}

/// A.4.025
cExpression* Actions::postfix_expression_cast_template ( bool colcol_opt, cNameReference *nns, bool template_opt, cNameReference *id, cFunctionArgumentList *parms )
{
  PDEBUG;

  int fline = ( nns ? getStartLine( nns ) : getStartLine( id ) );

  return STATE->cBinaryOperatorCreate( getCurrentFilename(), 
                                       fline,
                                       getCurrentLine(),
                                       OT_CPP_CAST_CALL,
                                       STATE->cNameReferenceCreate( getCurrentFilename(),
                                                              fline,
                                                              getEndLine(id),
                                                              id->mName,
                                                              id->mNameDeclaration,
                                                              0,
                                                              nns
                                                                  ),
                                       parms
                                     );
}

/// A.4.026 | A.4.027 | A.4.028 | A.4.029
cExpression* Actions::postfix_expression_access ( cExpression *lhs, eOperator op, bool template_opt, cExpression *rhs )
{
  // if decl is needed, do facade->lookupMemberName( getDecl( lhs ), getDecl( rhs ) )
  //                    or facade->lookupPseudoDestructor (...)

  PDEBUG;

  return STATE->cBinaryOperatorCreate( getCurrentFilename(), 
                                       getStartLine( lhs ),
                                       getCurrentLine(),
                                       op,
                                       lhs,
                                       rhs
                                     );
}

/// A.4.030 | A.4.031 | A.4.036
cExpression* Actions::postfix_expression_unary ( cExpression *operand, eOperator op )
{
  PDEBUG;

  // if decl is needed, do checkUnaryOp( PLUSPLUS/MINUSMINUS,
  //                                      getDecl( operand ) )

  return STATE->cUnaryOperatorCreate( getCurrentFilename(), 
                                      getStartLine( operand ),
                                      getCurrentLine(),
                                      op,
                                      operand
                                    );
}

/// A.4.032 | A.4.033 | A.4.034 | A.4.035
cExpression* Actions::postfix_expression_cpp_cast ( eOperator op, cType *type, cExpression *exp )
{
  PDEBUG;

  // if decl is needed, use type's decl

  return STATE->cBinaryOperatorCreate( getCurrentFilename(), 
                                       getStartLine( exp ),
                                       getCurrentLine(),
                                       op,
                                       type,
                                       exp
                                     );
}

/// A.4.037
cExpression* Actions::postfix_expression_unary_typeid ( cType *type, eOperator op )
{
  PDEBUG;

  string name = type->mName;
  NameDeclaration *decl = type->mNameDeclaration;

  return postfix_expression_unary( STATE->cNameReferenceCreate( getCurrentFilename(),
                                                          getStartLine( type ),
                                                          getEndLine( type ),
                                                          name,
                                                          decl,
                                                          0,
                                                          0
                                                        ),
                                   op
                                 );
}

/// A.4.038
cFunctionArgumentList* Actions::expression_list_start ( cExpression *expr )
{
  PDEBUG;

  argStack->addIfArgument( getDecl( expr ) );
  ArgumentList_t alist;
  alist.push_back( expr );

  return STATE->cFunctionArgumentListCreate( getCurrentFilename(), 
                                           getStartLine( expr ),
                                           getEndLine( expr ),
                                           alist
                                         );
}

/// A.4.039
cFunctionArgumentList* Actions::expression_list_continue ( cFunctionArgumentList *alist, cExpression *expr )
{
  PDEBUG;

  argStack->addIfArgument( getDecl( expr ) );
  alist->mArguments.push_back( expr );

  return alist;
}

/// A.4.040 | A.4.042
cNameReference* Actions::pseudo_destructor_name ( bool colcol_opt, cNameReference *nns_opt, cNameReference *decl )
{
  PDEBUG;

  int fline = ( nns_opt ? getStartLine( nns_opt ) : getStartLine( decl ) );
  cNameReference *to_return = STATE->cNameReferenceCreate( getCurrentFilename(), 
                                               fline,
                                               getCurrentLine(),
                                               decl->mName,
                                               decl->mNameDeclaration,
                                               decl->mTemplateArguments,
                                               nns_opt
                                             );
  to_return->mIsPseudoDestructor = true;

  return to_return;
}

/// A.4.041
cNameReference* Actions::pseudo_destructor_name_template ( bool colcol_opt, cNameReference *nns, cNameReference *decl, cNameReference *tname )
{
  PDEBUG;

  string name;
  name += "template " + decl->mName + "~" + tname->mName;

  int fline = ( nns ? getStartLine( nns ) : getStartLine( decl ) );

  return STATE->cNameReferenceCreate( getCurrentFilename(), 
                                fline,
                                getCurrentLine(),
                                name,
                                decl->mNameDeclaration,
                                decl->mTemplateArguments,
                                nns
                              );
}

/// A.4.044 | A.4.045 | A.4.046 | A.4.047
cExpression* Actions::unary_expression ( eOperator op, cExpression *expr )
{
  PDEBUG;

  // To get decl -> checkUnaryOp( OP, getDecl( expr ) )

  return STATE->cUnaryOperatorCreate( getCurrentFilename(), 
                                      getStartLine( expr ),
                                      getCurrentLine(),
                                      op,
                                      expr
                                    );
}

/// A.4.048
cExpression* Actions::unary_expression ( eOperator op, cType *type )
{
  PDEBUG;

  return STATE->cUnaryOperatorCreate( getCurrentFilename(), 
                                      getStartLine( type ),
                                      getCurrentLine(),
                                      op,
                                      STATE->cUnaryOperatorCreate( getCurrentFilename(), 
                                                                   getCurrentLine(),
                                                                   getCurrentLine(),
                                                                   OT_UPAREN,
                                                                   type
                                                                 )
                                    );
}

/// A.4.057 | A.4.058
cExpression* Actions::new_expression( bool colcol_opt, cFunctionArgumentList *placement, cType *type, cFunctionArgumentList *init )
{
  PDEBUG;

  // To get decl -> getDecl( type )

  cNewExpression *ce = STATE->cNewExpressionCreate( getCurrentFilename(), 
                                                  getStartLine( type ),
                                                  getCurrentLine(),
                                                  init,
                                                  placement
                                                );
  ce->mType = type;

  return ce;
}

/// A.4.066 | A.4.067
cExpression* Actions::delete_expression( bool colcol_opt, cExpression *what, bool is_array )
{
  PDEBUG;

  return STATE->cDeleteExpressionCreate( getCurrentFilename(), 
                                         getStartLine( what ),
                                         getCurrentLine(),
                                         what,
                                         is_array
                                       );
}

/// A.4.060
cType* Actions::new_type_id ( cType *type, NewDeclarationPair_t *typemods )
{
  PDEBUG;

  cType *to_return = type;

  if ( typemods )
  {
    if ( typemods->first )
    {
      for ( vector<int>::iterator it = typemods->first->begin();
            it != typemods->first->end();
            ++it )
      {
        if ( isPtr( *it ) )
        {
          to_return = STATE->cPointerTypeCreate( getCurrentFilename(), 
                                                 getStartLine( to_return ),
                                                 getEndLine( to_return ),
                                                 "",
                                                 VB_UNKNOWN,
                                                 0,
                                                 0,
                                                 to_return
                                               );
        }
        else
        {
          to_return = STATE->cReferenceTypeCreate( getCurrentFilename(),
                                                   getStartLine( to_return ),
                                                   getEndLine( to_return ),
                                                   "",
                                                   VB_UNKNOWN,
                                                   0,
                                                   0,
                                                   to_return
                                                );
        }
        makeCV( to_return, *it );
      }//for
    }

    if ( typemods->second )
    {
      // NAK - Use Array Types
      while ( typemods->second->size() )
      {
        to_return = STATE->cArrayTypeCreate( getCurrentFilename(), 
                                             getStartLine( to_return ),
                                             getEndLine( to_return ),
                                             "",
                                             VB_UNKNOWN,
                                             0,
                                             0,
                                             to_return,
                                             typemods->second->front()
                                           );
        typemods->second->erase( typemods->second->begin() );
      }
    }

    delete typemods->first;
    delete typemods->second;

  }//if

  return to_return;
}

/// A.4.061
NewDeclarationPair_t* Actions::new_declarator_ptr ( int ptrop, NewDeclarationPair_t *nd )
{
  PDEBUG;

  NewDeclarationPair_t *to_return = 0;

  if ( nd )
  {
    nd->first->insert( nd->first->begin(), ptrop );
    to_return = nd;
  }
  else
  {
    PointerCalculationList_t *plist = new PointerCalculationList_t;
    plist->push_back( ptrop );
    to_return = new NewDeclarationPair_t( plist, 0 );
  }

  return to_return;
}

/// A.4.062
NewDeclarationPair_t* Actions::new_declarator_direct ( ArrayDimensionList_t *dims )
{
  PDEBUG;

  return new NewDeclarationPair_t( new PointerCalculationList_t, dims );
}

/// A.4.063
ArrayDimensionList_t* Actions::direct_new_declarator_exp ( cExpression *expr )
{
  PDEBUG;

  return new ArrayDimensionList_t( 1, expr );
}

/// A.4.064
ArrayDimensionList_t* Actions::direct_new_declarator_const_exp ( ArrayDimensionList_t *prev, cExpression *expr )
{
  PDEBUG;

  prev->push_back( expr );
  return prev;
}

/// A.4.069
cExpression* Actions::cast_expression ( cType *type, cExpression *expr )
{
  PDEBUG;

  // to get decl -> getDecl( type )

  return STATE->cBinaryOperatorCreate( getCurrentFilename(), 
                                       getStartLine( type ),
                                       getEndLine( expr ),
                                       OT_C_CAST_CALL,
                                       STATE->cUnaryOperatorCreate( getCurrentFilename(), 
                                                                    getCurrentLine(),
                                                                    getCurrentLine(),
                                                                    OT_UPAREN,
                                                                    type
                                                                  ),
                                       expr
                                     );
}

/// A.4.071 | A.4.072
cExpression* Actions::pm_expressionression ( eOperator op, cExpression *lhs, cExpression *rhs )
{
  PDEBUG;

  // to get decl -> checkBinOp( op, lhs, rhs )

  return STATE->cBinaryOperatorCreate( getCurrentFilename(),
                                       getStartLine( lhs ),
                                       getEndLine( rhs ),
                                       op,
                                       lhs,
                                       rhs
                                     );
}

/// A.4.074 | A.4.075 | A.4.076
cExpression* Actions::multiplicative_expression ( eOperator op, cExpression *lhs, cExpression *rhs )
{
  PDEBUG;

  // to get decl -> checkBinOp( oh, lhs, rhs )

  return STATE->cBinaryOperatorCreate( getCurrentFilename(), 
                                       getStartLine( lhs ),
                                       getEndLine( rhs ),
                                       op,
                                       lhs,
                                       rhs
                                     );
}

/// A.4.078 | A.4.079
cExpression* Actions::additive_expression ( eOperator op, cExpression *lhs, cExpression *rhs )
{
  PDEBUG;

  // to get decl -> checkBinOp( oh, lhs, rhs )

  return STATE->cBinaryOperatorCreate( getCurrentFilename(),
                                       getStartLine( lhs ),
                                       getEndLine( rhs ),
                                       op,
                                       lhs,
                                       rhs
                                     );
}

/// A.4.081 | A.4.082
cExpression* Actions::shift_expression ( eOperator op, cExpression *lhs, cExpression *rhs )
{
  PDEBUG;

  // to get decl -> checkBinOp( oh, lhs, rhs )

  return STATE->cBinaryOperatorCreate( getCurrentFilename(),
                                       getStartLine( lhs ),
                                       getEndLine( rhs ),
                                       op,
                                       lhs,
                                       rhs
                                     );
}

/// A.4.084 | A.4.085 | A.4.086 | A.4.087
cExpression* Actions::relational_expression ( eOperator op, cExpression *lhs, cExpression *rhs )
{
  PDEBUG;

  // to get decl -> checkBinOp( oh, lhs, rhs )

  return STATE->cBinaryOperatorCreate( getCurrentFilename(),
                                       getStartLine( lhs ),
                                       getEndLine( rhs ),
                                       op,
                                       lhs,
                                       rhs
                                     );
}

/// A.4.089 | A.4.090
cExpression* Actions::equality_expression ( eOperator op, cExpression *lhs, cExpression *rhs )
{
  PDEBUG;

  // to get decl -> checkBinOp( oh, lhs, rhs )

  return STATE->cBinaryOperatorCreate( getCurrentFilename(),
                                       getStartLine( lhs ),
                                       getEndLine( rhs ),
                                       op,
                                       lhs,
                                       rhs
                                     );
}

/// A.4.092
cExpression* Actions::and_expression ( eOperator op, cExpression *lhs, cExpression *rhs )
{
  PDEBUG;

  // to get decl -> checkBinOp( oh, lhs, rhs )

  return STATE->cBinaryOperatorCreate( getCurrentFilename(),
                                       getStartLine( lhs ),
                                       getEndLine( rhs ),
                                       op,
                                       lhs,
                                       rhs
                                     );
}

/// A.4.094
cExpression* Actions::exclusive_or_expression ( eOperator op, cExpression *lhs, cExpression *rhs )
{
  PDEBUG;

  // to get decl -> checkBinOp( oh, lhs, rhs )

  return STATE->cBinaryOperatorCreate( getCurrentFilename(),
                                       getStartLine( lhs ),
                                       getEndLine( rhs ),
                                       op,
                                       lhs,
                                       rhs
                                     );
}

/// A.4.096
cExpression* Actions::inclusive_or_expression ( eOperator op, cExpression *lhs, cExpression *rhs )
{
  PDEBUG;

  // to get decl -> checkBinOp( oh, lhs, rhs )

  return STATE->cBinaryOperatorCreate( getCurrentFilename(),
                                       getStartLine( lhs ),
                                       getEndLine( rhs ),
                                       op,
                                       lhs,
                                       rhs
                                     );
}

/// A.4.098
cExpression* Actions::logical_and_expression ( eOperator op, cExpression* lhs, cExpression *rhs )
{
  PDEBUG;

  // to get decl -> checkBinOp( oh, lhs, rhs )

  return STATE->cBinaryOperatorCreate( getCurrentFilename(),
                                       getStartLine( lhs ),
                                       getEndLine( rhs ),
                                       op,
                                       lhs,
                                       rhs
                                     );
}

/// A.4.100
cExpression* Actions::logical_or_expression ( eOperator op, cExpression *lhs, cExpression *rhs )
{
  PDEBUG;

  // to get decl -> checkBinOp( oh, lhs, rhs )

  return STATE->cBinaryOperatorCreate( getCurrentFilename(),
                                       getStartLine( lhs ),
                                       getEndLine( rhs ),
                                       op,
                                       lhs,
                                       rhs
                                     );
}

/// A.4.102
cExpression* Actions::conditional_expression ( cExpression *cond, cExpression *tstmt, cExpression *fstmt )
{
  PDEBUG;

  // to get decl -> tstmt ? getDecl( tstmt ) : getDecl( fstmt )

  return STATE->cTernaryOperatorCreate( getCurrentFilename(), 
                                         getStartLine( cond ),
                                         getEndLine( fstmt ),
                                         OT_QUESTION,
                                         cond,
                                         tstmt,
                                         fstmt
                                       );
}

/// A.4.104
cExpression* Actions::assignment_expression ( eOperator op, cExpression *lhs, cExpression *rhs )
{
  PDEBUG;

  // to get decl -> getDecl( lhs )

  return STATE->cBinaryOperatorCreate( getCurrentFilename(), 
                                       getStartLine(lhs),
                                       getEndLine(rhs),
                                       op,
                                       lhs,
                                       rhs
                                     );
}

/// A.4.118
cExpression* Actions::expression( eOperator op, cExpression *lhs, cExpression *rhs )
{
  PDEBUG;

  // to get decl -> getDecl( rhs )

  return STATE->cBinaryOperatorCreate( getCurrentFilename(), 
                                       getStartLine( lhs ),
                                       getEndLine( rhs ),
                                       op,
                                       lhs,
                                       rhs
                                     );
}

//##############################################################################
// A.5
//##############################################################################

/// A.5.009
cLabel* Actions::labeled_statement_generic ( NameDeclaration *decl, cAsgNode *stmt )
{
  PDEBUG;

  return STATE->cLabelCreate( getCurrentFilename(), 
                              getStartLine(stmt),
                              getCurrentLine(),
                              decl->getName(),
                              VB_UNKNOWN,
                              decl,
                              stmt
                            );
}

/// A.5.010
cLabel* Actions::labeled_statement_case ( cExpression *expr, cAsgNode *stmt )
{
  PDEBUG;

  return STATE->cCaseLabelCreate( getCurrentFilename(), 
                                  getStartLine( stmt ),
                                  getCurrentLine(),
                                  "",
                                  VB_UNKNOWN,
                                  0,
                                  stmt, 
                                  expr
                                );
}

/// A.5.011
cLabel* Actions::labeled_statement_default ( cAsgNode *stmt )
{
  PDEBUG;

  return STATE->cDefaultLabelCreate( getCurrentFilename(), 
                                     getStartLine( stmt ),
                                     getCurrentLine(),
                                     "",
                                     VB_UNKNOWN,
                                     0,
                                     stmt
                                   );
}

/// A.5.013
void Actions::compound_statement_1 ( void )
{
  PDEBUG;

  facade->moveIntoLocalScope();
}

/// A.5.013
/// \param statments the statement(s) in this block
cBlock* Actions::compound_statement_2 ( AsgNodeList_t *statements )
{
  PDEBUG;

  facade->leaveCurrentScope();

  AsgNodeList_t *statList = key::collapseContainedObjectLists( statements );

  cBlock *block = STATE->cBlockCreate( getCurrentFilename(), 
                                       getCurrentLine(),
                                       getCurrentLine(),
                                       "",
                                       VB_UNKNOWN,
                                       0, 
                                       key::safe_deref( statList )
                                     );
  delete statements;

  for ( std::vector<cAsgNode*>::iterator ptr = block->mContents.begin();
        ptr != block->mContents.end();
        ++ptr
      )
  {
    if ( cObject *obj = dynamic_cast<cObject*>( (*ptr) ) )
    {
      obj->mDefinedIn = block;
    }
  }

  return block;
}

/// A.5.016 | A.5.017
/// \param cond the condition
/// \param tstat the if true statement(s)
/// \param fstat the if false statement(s)
cSelectionStatement* Actions::selection_statement_if ( cExpression *cond, cAsgNode *tstat, cAsgNode *fstat )
{
  PDEBUG;

  int end_line = ( fstat ? getEndLine( fstat ) : getEndLine( tstat ) );

  return STATE->cIfStatementCreate( getCurrentFilename(), 
                                    getStartLine( cond ),
                                    end_line,
                                    cond,
                                    key::ensureIsBlock( tstat ),
                                    key::ensureIsBlock( fstat )
                                  );
}

/// A.5.018
/// \param cond the condition
/// \param cases the case statement(s)
cSelectionStatement* Actions::selection_statement_switch ( cExpression *cond, cAsgNode *cases )
{
  PDEBUG;

  return STATE->cSwitchStatementCreate( getCurrentFilename(), 
                               getStartLine(cond),
                               getCurrentLine(),
                               cond,
                               key::ensureIsBlock( cases )
                             );
}

/// A.5.020
cConditionDeclarator* Actions::condition ( cType *type, cAsgNode *id, cExpression *expr )
{
  PDEBUG;

  while ( ! declStack->empty() )
  {
    declStack->pop();
  }

  cObject *obj = dynamic_cast<cObject*>( id );

  MAKE_ASSERTION( obj, "condition was not passed an object!" );

  obj->mType = type;
  obj->mInitialValue = expr;

  return STATE->cConditionDeclaratorCreate( getCurrentFilename(), 
                                            getStartLine(type),
                                            getCurrentLine(),
                                            obj
                                          );
}

/// A.5.021
cIterationStatement* Actions::iteration_statement_while ( cExpression *cond, cAsgNode *stat )
{
  PDEBUG;

  return STATE->cWhileLoopCreate( getCurrentFilename(),
                                    getStartLine( cond ),
                                    getCurrentLine(),
                                    cond,
                                    key::ensureIsBlock( stat )
                                  );
}

/// A.5.022
cIterationStatement* Actions::iteration_statement_do ( cExpression *cond, cAsgNode *stat )
{
  PDEBUG;

  return STATE->cDoWhileLoopCreate( getCurrentFilename(), 
                                    getStartLine( cond ),
                                    getCurrentLine(),
                                    cond,
                                    key::ensureIsBlock( stat )
                                  );
}

/// A.5.023
cIterationStatement* Actions::iteration_statement_for( cAsgNode *init, cExpression *cond, cExpression *inc, cAsgNode *stat )
{
  PDEBUG;

  return STATE->cForLoopCreate( getCurrentFilename(), 
                                getStartLine( init ),
                                getCurrentLine(),
                                cond,
                                key::ensureIsBlock( stat ),
                                key::safe_deref( key::collapseIfObjectList( init ) ),
                                inc
                              );
}

/// A.5.026
cJumpStatement* Actions::jump_statement_break ( void )
{
  PDEBUG;

  return STATE->cBreakCreate( getCurrentFilename(),
                              getCurrentLine(),
                              getCurrentLine(),
                              0
                            );
}

/// A.5.027
cJumpStatement* Actions::jump_statement_continue ( void )
{
  PDEBUG;

  return STATE->cContinueCreate( getCurrentFilename(),
                                 getCurrentLine(),
                                 getCurrentLine(),
                                 0
                               );
}

/// A.5.028
cJumpStatement* Actions::jump_statement_return ( cExpression *expr )
{
  PDEBUG;

  return STATE->cReturnCreate( getCurrentFilename(), 
                               getStartLine(expr),
                               getCurrentLine(),
                               0,
                               expr
                             );
}

/// A.5.029
cJumpStatement* Actions::jump_statement_goto ( NameDeclaration *decl )
{
  PDEBUG;

  return STATE->cGotoCreate( getCurrentFilename(),
                             getCurrentLine(),
                             getCurrentLine(),
                             STATE->cNameReferenceCreate( getCurrentFilename(),
                                                    getCurrentLine(),
                                                    getCurrentLine(),
                                                    decl->getName(),
                                                    decl,
                                                    0,
                                                    0
                                                  )
                           );
}

//##############################################################################
// A.6
//##############################################################################

/// A.6.001
AsgNodeList_t* Actions::declaration_seq_1 ( cAsgNode *object )
{
  PDEBUG;

  seen_static = false;
  seen_const  = false;

  return new AsgNodeList_t( 1, object );
}

/// A.6.002
AsgNodeList_t* Actions::declaration_seq_2 ( cAsgNode *object, AsgNodeList_t *objects )
{
  PDEBUG;

  objects->push_back( object );

  return objects;
}

/// A.6.009
void Actions::declaration_namespace_definition ( cAsgNode *node )
{
  if ( cNamespace *cns = dynamic_cast<cNamespace*>( node ) )
  {
    /// Add parent scope pointers to namespace members
    for ( std::vector<cAsgNode*>::iterator ptr = cns->mContents.begin();
          ptr != cns->mContents.end();
          ++ptr
        )
    {
      if ( cIdentifier *ci = dynamic_cast<cIdentifier*>( (*ptr) ) )
      {
        ci->mDefinedIn = cns;
      }
      else if ( cObjectList *ol = dynamic_cast<cObjectList*>( (*ptr) ) )
      {
        if ( ol->mObjects.size() )
        {
          for ( std::vector<cAsgNode*>::iterator ptr = ol->mObjects.begin();
                ptr != ol->mObjects.end();
                ++ptr
              )
          {
            if ( cIdentifier *ci = dynamic_cast<cIdentifier*>( *ptr ) )
            {
              ci->mDefinedIn = cns;
            }
          }
        }
      }
    }
  }
}

/// A.6.015
cObjectList* Actions::simple_declaration ( DeclSpecifierList_t *dlist, AsgNodeList_t *objects )
{
  PDEBUG;

  // THG - check for typedef
  if ( hasDeclSpec( dlist, DS_TYPEDEF ) )
  {
    for ( list<NameDeclaration*>::iterator it = typedef_list.begin();
          it != typedef_list.end();
          ++it )
    {
      facade->makeTypedef( *it );
    }
    if ( objects )
    {
      for ( AsgNodeList_t::iterator it = objects->begin();
            it != objects->end();
            ++it )
      {
        if ( cObject* co = dynamic_cast<cObject*>( *it ) )
        {
          cType* to_add = co->mType;

          if ( to_add )
            applyType( to_add, findType( dlist ) );
          else
            to_add = findType( dlist );

          *it = STATE->cAliasTypeCreate( getCurrentFilename(), 
                                         getStartLine(co),
                                         getCurrentLine(),
                                         co->mName,
                                         geteAccessSpecifier( current_access ),
                                         co->mNameDeclaration,
                                         to_add
                                        );
        }
      }
    }
  }

  while ( ! declStack->empty() )
  {
    declStack->pop();
  }

  if ( objects )
  {
    cType *type = findType( dlist );
    updateType( type, dlist );
    for ( AsgNodeList_t::iterator it = objects->begin();
          it != objects->end();
          ++it )
    {
      if ( cObject* obj = dynamic_cast<cObject*>( *it ) )
      {
        if ( obj->mType )
          applyType( obj->mType, type );
        else
          obj->mType = type;

        if ( hasDeclSpec( dlist, DS_AUTO ) )     obj->mIsAuto      = true;
        if ( hasDeclSpec( dlist, DS_REGISTER ) ) obj->mIsRegister  = true;
        if ( hasDeclSpec( dlist, DS_STATIC ) )   obj->mIsStatic  = true;
        if ( hasDeclSpec( dlist, DS_EXTERN ) )   obj->mIsExtern  = true;
        if ( hasDeclSpec( dlist, DS_MUTABLE ) )  obj->mIsMutable = true;
      }
      else if ( cFunctionInterface* fct = dynamic_cast<cFunctionInterface*>( *it ) )
      {
        if ( fct->mType && type )
        {
          if ( fct->mType->mReturnType )
            applyType( fct->mType->mReturnType, type );
          else
            fct->mType->mReturnType = type;
        }
        if ( hasDeclSpec( dlist, DS_INLINE ) )   fct->mIsInline   = true;
        if ( hasDeclSpec( dlist, DS_STATIC ) )   fct->mIsStatic   = true;
        if ( hasDeclSpec( dlist, DS_EXTERN ) )   fct->mIsExtern   = true;
        if ( hasDeclSpec( dlist, DS_VIRTUAL ) )  fct->mIsVirtual  = true;
        if ( hasDeclSpec( dlist, DS_EXPLICIT ) ) fct->mIsExplicit = true;
      }
    }
  }

  if ( cType *t = declaredType( findType( dlist ), objects ) )
  {
     // throwaway template parameter scope...??
     facade->getCurrentTemplateScope( true );
    if ( objects )
      objects->insert( objects->begin(), t );
    else
    {
      objects = new AsgNodeList_t( 1, t );
      // check for anonymous unions!
      if ( cClassType* at = dynamic_cast<cClassType*>( t ) )
      {
        if ( at->mName.substr( 0, 6 ) == "__anon" &&
             at->mClassKey == AT_UNION
           )
        {
          for ( MemberList_t::iterator it = at->mMembers.begin();
               it != at->mMembers.end();
               ++it )
          {
            if ( cObjectList* olist = dynamic_cast<cObjectList*>( *it ) )
            {
              for ( AsgNodeList_t::iterator it = olist->mObjects.begin();
                   it != olist->mObjects.end();
                   ++it )
              {
                if( cIdentifier *id = dynamic_cast<cIdentifier*>( *it ) )
                {
                  facade->getCurrentScope()->insertLocal( id->mNameDeclaration );
                }
              }
            }

            /// Tanton depended on this being an object list, but we've eliminated some of them
            if( cIdentifier *id = dynamic_cast<cIdentifier*>( *it ) )
            {
              facade->getCurrentScope()->insertLocal( id->mNameDeclaration );
            }

          }
        }
		}
		// end check for anonymous union
    }
  }

  return STATE->cObjectListCreate( getCurrentFilename(), 
                                   getCurrentLine(),
                                   getCurrentLine(),
                                   "",
                                   geteAccessSpecifier( current_access ),
                                   0,
                                   key::safe_deref( objects )
                                 );
}

/// A.6.017
DeclSpecifier_t* Actions::decl_specifier_type( cType *type )
{
  PDEBUG;

  if ( type && getKeyType( type ) )
  {
    declStack->push( getKeyType( type ) );
  }

  DeclSpecifier_t *to_return = new DeclSpecifier_t;

  // NAK - added cQualifierType to pass cv_qualifier sums up the tree
  if ( cQualifierType *qt = dynamic_cast<cQualifierType *>( type ) )
  {
    if ( qt->mCvSum == 1 )
    {
      to_return->first = DS_CONST;
    }
    else if ( qt->mCvSum == 2 )
    {
      to_return->first = DS_VOLATILE;
    }
  }
  else if ( type )
  {
    to_return->first = DS_TYPE_SPECIFIER;
    to_return->second = type;
  }

  return to_return;
}

/// A.6.019
DeclSpecifier_t* Actions::decl_specifier_friend ( void )
{
  PDEBUG;

  seen_friend = true;
  seen_friend_tree = true;

  DeclSpecifier_t *to_return = new DeclSpecifier_t;
  to_return->first = DS_FRIEND;

  return to_return;
}

/// A.6.020
DeclSpecifier_t* Actions::decl_specifier_typedef ( void )
{
  PDEBUG;

  DeclSpecifier_t *to_return = new DeclSpecifier_t;
  to_return->first = DS_TYPEDEF;

  return to_return;
}

/// A.6.021
DeclSpecifierList_t* Actions::decl_specifier_seq ( DeclSpecifier_t *ds, DeclSpecifierList_t *objects )
{
  PDEBUG;

  DeclSpecifierList_t *to_return = ( objects ? objects : new DeclSpecifierList_t );
  to_return->insert( to_return->begin(), ds );

  return to_return;
}

/// A.6.022 | A.6.023 | A.6.024 | A.6.025 | A.6.026
DeclSpecifier_t* Actions::storage_class_specifier ( eDeclSpecifier dstype )
{
  PDEBUG;

  DeclSpecifier_t *to_return = new DeclSpecifier_t;
  to_return->first = dstype;

  if ( dstype == DS_STATIC )
  {
    seen_static = true;
  }

  return to_return;
}

/// A.6.027 | A.6.028 | A.6.029
DeclSpecifier_t* Actions::function_specifier( eDeclSpecifier dstype )
{
  PDEBUG;

  DeclSpecifier_t *to_return = new DeclSpecifier_t;
  to_return->first = dstype;

  if( dstype == DS_VIRTUAL )
  {
    seen_virtual = true;
  }

  return to_return;
}

/// A.5.020 | A.13.005
void Actions::push_type_specifier ( cType *type )
{
  PDEBUG;

  if ( type && getKeyType( type ) )
  {
    declStack->push( getKeyType( type ) );
  }
}

/// A.6.034
cType* Actions::cv_qualifier ( int sum )
{
  // NAK - need cQualifierType for compatibility between cType and Tanton's horrible system for qualifiers
  return STATE->cQualifierTypeCreate( "", 0, 0, "", VB_UNKNOWN, 0, sum );
}

/// A.6.035
cType* Actions::simple_type_specifier_type_name ( bool colcol_opt, cNameReference *nns, cNameReference *decl )
{
  PDEBUG;

  if ( colcol_opt && !nns )
  {
    nns = STATE->cNameReferenceCreate( getCurrentFilename(),
                                       getCurrentLine(),
                                       getCurrentLine(),
                                       "::",
                                       0,
                                       0,
                                       0
                                     );
  }

  cForwardTypeInterface *fti = 0;

  if ( decl->mTemplateArguments && decl->mTemplateArguments->mArguments.size() )
  {
    // e.g. ctEntry<int> object;
    fti = STATE->cInstantiatedForwardTypeCreate( getCurrentFilename(), 
                                                 ( nns ? getStartLine( nns ) : getStartLine( decl ) ),
                                                 getEndLine( decl ),
                                                 decl->mName,
                                                 VB_UNKNOWN,
                                                 decl->mNameDeclaration,
                                                 nns,
                                                 decl->mTemplateArguments
                                               );
  }
  else
  {
    fti = STATE->cForwardTypeCreate( getCurrentFilename(), 
                                     ( nns ? getStartLine( nns ) : getStartLine( decl ) ),
                                     getEndLine( decl ),
                                     decl->mName,
                                     VB_UNKNOWN,
                                     decl->mNameDeclaration,
                                     nns
                                   );
  }
  return fti;
}

/// A.6.036
cType* Actions::simple_type_specifier_template ( bool colcol_opt, cNameReference *nns, cNameReference *decl )
{
  PDEBUG;

  //string name( "template " + decl->mName );

  // e.g. std::template Class<int> a;
  return STATE->cInstantiatedForwardTypeCreate( getCurrentFilename(), 
                                                ( nns ? getStartLine( nns ) : getStartLine( decl ) ),
                                                getEndLine(decl),
                                                decl->mName,
                                                VB_UNKNOWN,
                                                decl->mNameDeclaration, 
                                                nns,
                                                decl->mTemplateArguments
                                              );
}

/// A.6.037 | A.6.037a | A.6.038 | A.6.039 | A.6.040 | A.6.040a | A.6.041  |
/// A.6.042 | A.6.042a | A.6.043 | A.6.044 | A.6.045  | A.6.046 | A.6.046a | A.6.047
cType* Actions::simple_type_specifier_basic_type ( const string &tname )
{
  PDEBUG;

  BasicType::BType bType = key::convertStringToBType( tname );
  if ( bType != BasicType::NUM_BT )
  {
    return STATE->cBuiltInTypeCreate( "", 0, 0, tname, VB_UNKNOWN, 0, new BasicType( bType ) );
  }

  return ( 0 );
}

/// A.6.049 | A.6.050
cNameReference* Actions::type_name ( NameDeclaration* decl )
{
  return STATE->cNameReferenceCreate( getCurrentFilename(), 
                                getCurrentLine(),
                                getCurrentLine(),
                                decl->getName(),
                                decl, 
                                0,
                                0
                              );
}

/// A.6.051
cForwardTypeInterface* Actions::elaborated_type_specifier_class ( int class_key, bool colcol_opt, cNameReference *nns, cNameReference *decl )
{
  PDEBUG;

  NameDeclaration *to_return = facade->insertLocal( decl->mNameDeclaration, new ClassType( decl->mNameDeclaration ) );

  cForwardTypeInterface *fti = 0;

  if ( decl->mTemplateArguments && decl->mTemplateArguments->mArguments.size() )
  {
    // e.g. template class ctEntry<int>; (i.e. template instantiation)
    // e.g. class ctEntry<unsigned>;     (i.e. forward decl of template specialization)
      fti = STATE->cInstantiatedForwardTypeCreate( getCurrentFilename(), 
                                                   ( nns ? getStartLine( nns ) : getStartLine( decl ) ),
                                                   getEndLine( decl ),
                                                   decl->mName,
                                                   VB_UNKNOWN,
                                                   decl->mNameDeclaration,
                                                   nns,
                                                   decl->mTemplateArguments
                                                 );
  }
  else
  { 
    fti = STATE->cForwardTypeCreate( getCurrentFilename(),
                                           ( nns ? getStartLine( nns ) : getStartLine( decl ) ),
                                           getEndLine( decl ),
                                           decl->mName,
                                           VB_UNKNOWN,
                                           to_return,
                                           nns
                                         );
  }
  return fti;
}

/// A.6.052
cForwardTypeInterface* Actions::elaborated_type_specifier_enum ( bool colcol_opt, cNameReference *nns, NameDeclaration *decl )
{
  PDEBUG;

  // e.g.  enum EnumType; (after EnumType has already been defined)
  return STATE->cForwardTypeCreate( getCurrentFilename(),
                                    getStartLine( nns ),
                                    getCurrentLine(),
                                    decl->getName(),
                                    VB_UNKNOWN,
                                    facade->insertLocal( decl, new EnumType( decl ) ),
                                    nns
                                  );
}

/// A.6.053
cForwardTypeInterface* Actions::elaborated_type_specifier_typename ( bool colcol_opt, cNameReference *nns, NameDeclaration *decl )
{
  PDEBUG;

  if ( !decl->getType() || decl->isInstance() )
    decl->setType( new ClassType( decl ) );

  // e.g. typename Class<int>::iterator ptr; (the iterator part)
  // e.g. typename Class::iterator ptr; (illegal, but the parser accepts it)
  return STATE->cForwardTypeCreate( getCurrentFilename(),
                                    getStartLine(nns),
                                    getCurrentLine(),
                                    decl->getName(),
                                    VB_UNKNOWN,
                                    decl,
                                    nns
                                  );
}

/// A.6.054
cForwardTypeInterface* Actions::elaborated_type_specifier_template ( bool colcol_opt, cNameReference *nns, bool template_opt, cNameReference *decl )
{
  PDEBUG;

  decl->mNameDeclaration->setType( new ClassType( decl->mNameDeclaration ) );

  if ( decl->mTemplateArguments && decl->mTemplateArguments->mArguments.size() )
  {
    // e.g. typename Class<int>::Iterator<int> ptr; (the Iterator part)
    return STATE->cInstantiatedForwardTypeCreate( getCurrentFilename(),
                                                  getStartLine( nns ),
                                                  getCurrentLine(),
                                                  decl->mName,
                                                  VB_UNKNOWN,
                                                  decl->mNameDeclaration,
                                                  nns,
                                                  decl->mTemplateArguments
                                                );
  }
  else
  {
    return STATE->cForwardTypeCreate( getCurrentFilename(),
                                      getStartLine( nns ),
                                      getCurrentLine(),
                                      decl->mName,
                                      VB_UNKNOWN,
                                      decl->mNameDeclaration,
                                      nns
                                    );
  }
}

/// A.6.055
void Actions::enum_specifier_1 ( NameDeclaration *decl, int line )
{
  PDEBUG;

  NameDeclaration *tmp = checkAnon( decl, line ); 
  current_enum = facade->insertLocal( tmp, new EnumType( tmp ));  
}

/// A.6.055
cType* Actions::enum_specifier_2 ( EnumeratorList_t *enums )
{
  PDEBUG;

  std::string name = current_enum->getName();
  if ( name.find( "__anon" ) != std::string::npos )
  {
    name = "";
  }

  cEnumerationType *to_return = STATE->cEnumerationTypeCreate( getCurrentFilename(), 
                                                 getCurrentLine(),
                                                 getCurrentLine(),
                                                 name,
                                                 geteAccessSpecifier( current_access ),
                                                 current_enum,
                                                 new EnumType( current_enum ),
                                                 key::safe_deref( enums ) 
                                               );
  delete enums;
  current_enum = 0;

  return to_return;
}

/// A.6.056
EnumeratorList_t* Actions::enumerator_list_1 ( cEnumerator *en )
{
  PDEBUG;

  return new EnumeratorList_t( 1, en );
}

/// A.6.057
EnumeratorList_t* Actions::enumerator_list_2 ( EnumeratorList_t *objects, cEnumerator *en )
{
  PDEBUG;

  objects->push_back( en );

  return objects;
}

/// A.6.058 | A.6.059
cEnumerator* Actions::enumerator_definition ( NameDeclaration *enumdecl, cExpression *expr )
{
  PDEBUG;

  Type *tmp = new BasicType( BasicType::BT_INT );
  NameDeclaration *decl = facade->insertLocal( enumdecl, tmp, true );
  decl->setInstance( true );

  return STATE->cEnumeratorCreate( getCurrentFilename(), 
                                   getStartLine(expr),
                                   getEndLine(expr),
                                   decl->getName(),
                                   geteAccessSpecifier( current_access ),
                                   decl,
                                   expr
                                 );
}

/// A.6.065
void Actions::original_namespace_definition_1 ( NameDeclaration *decl )
{
  PDEBUG;

  facade->moveIntoNamespaceScope( decl );
}

/// A.6.065
cScope* Actions::original_namespace_definition_2 ( NameDeclaration *decl, AsgNodeList_t *contents )
{
  PDEBUG;

  AsgNodeList_t *newContents = key::collapseContainedObjectLists( contents );

  cNamespace *to_return = STATE->cNamespaceCreate( getCurrentFilename(), 
                                                   getCurrentLine(),
                                                   getCurrentLine(),
                                                   decl->getName(),
                                                   VB_UNKNOWN,
                                                   decl,
                                                   key::safe_deref( newContents )
                                                 );
  facade->leaveCurrentScope();

  delete contents;
  delete newContents;

  return to_return;
}

/// A.6.066
void Actions::extension_namespace_definition_1 ( NameDeclaration *decl )
{
  PDEBUG;

  facade->moveIntoNamespaceScope( decl );
}

/// A.6.066
cScope* Actions::extension_namespace_definition_2 ( NameDeclaration *decl, AsgNodeList_t *contents )
{
  PDEBUG;

  AsgNodeList_t *newContents = key::collapseContainedObjectLists( contents );

  cNamespace *to_return = STATE->cNamespaceCreate( getCurrentFilename(), 
                                                   getCurrentLine(),
                                                   getCurrentLine(),
                                                   decl->getName(),
                                                   VB_UNKNOWN,
                                                   decl,
                                                   key::safe_deref( newContents )
                                                 );
  facade->leaveCurrentScope();
  delete contents;
  delete newContents;

  return to_return;
}

/// A.6.067
NameDeclaration* Actions::unnamed_namespace_definition_1 ( int line )
{
  PDEBUG;

  NameDeclaration *tmp = checkAnonNS( 0, line );
  facade->moveIntoAnonNamespace( tmp );

  return tmp;
}

/// A.6.067
cScope* Actions::unnamed_namespace_definition_2 ( NameDeclaration  *decl, AsgNodeList_t *contents )
{
  PDEBUG;

  AsgNodeList_t *newContents = key::collapseContainedObjectLists( contents );

  cNamespace *to_return = STATE->cNamespaceCreate( getCurrentFilename(), 
                                                   getCurrentLine(),
                                                   getCurrentLine(),
                                                   decl->getName(),
                                                   VB_UNKNOWN,
                                                   decl,
                                                   key::safe_deref( newContents )
                                                 );
  facade->leaveCurrentScope();

  delete contents;
  delete newContents;

  return to_return;
}

/// A.6.069
cScope* Actions::namespace_alias_definition( NameDeclaration *lhs, NameDeclaration *rhs )
{
  PDEBUG;

  Type *tmp = rhs->getType()->Clone();

  // this is an alias type
  NameDeclaration *decl = facade->insertLocal( lhs, tmp, true );
  lhs->setCorrespondingScope( rhs->getCorrespondingScope() );
  decl->setInstance( true );
  cNamespace* to_return = STATE->cNamespaceCreate( getCurrentFilename(), 
                                                   getCurrentLine(),
                                                   getCurrentLine(),
                                                   lhs->getName(), 
                                                   VB_UNKNOWN,
                                                   lhs, 
                                                   AsgNodeList_t()
                                                 );
  to_return->mAliases = STATE->cNameReferenceCreate( getCurrentFilename(), 
                                                getCurrentLine(),
                                                getCurrentLine(),
                                                rhs->getName(),
                                                rhs, 
                                                0,
                                                0
                                              );

  return to_return;
}

/// A.6.071 | A.6.072
cUsing* Actions::using_declaration ( bool colcol_opt, cNameReference *nns, NameDeclaration *decl )
{
  PDEBUG;

  facade->useDeclaration( decl );

  return STATE->cUsingCreate( getCurrentFilename(), 
                              getCurrentLine(),
                              getCurrentLine(),
                              false,
                              STATE->cNameReferenceCreate( getCurrentFilename(), 
                                                     getCurrentLine(),
                                                     getCurrentLine(),
                                                     decl->getName(),
                                                     decl, 
                                                     0,
                                                     nns
                                                   )
                            );
}

/// A.6.073
cUsing* Actions::using_directive ( bool colcol_opt, cNameReference *nns, NameDeclaration *decl )
{
  PDEBUG;

  facade->useNamespace( decl );

  return STATE->cUsingCreate( getCurrentFilename(), 
                              getCurrentLine(),
                              getCurrentLine(),
                              true,
                              STATE->cNameReferenceCreate( getCurrentFilename(), 
                                                     getCurrentLine(),
                                                     getCurrentLine(),
                                                     decl->getName(),
                                                     decl, 
                                                     0,
                                                     nns
                                                   )
                            );
}

/// A.6.074
cAsmDefinition* Actions::asm_definition ( const std::string &asmLiteral )
{
  return STATE->cAsmDefinitionCreate( getCurrentFilename(),
                                      getCurrentLine(),
                                      getCurrentLine(),
                                      asmLiteral
                                    );
}


/// A.6.075
cLinkage* Actions::linkage_specification_block ( const string &name, AsgNodeList_t *decls )
{
  AsgNodeList_t *declsList = key::collapseContainedObjectLists( decls );

  return STATE->cLinkageCreate( getCurrentFilename(), 
                               getCurrentLine(),
                               getCurrentLine(),
                               name,
                               true,
                               key::safe_deref( declsList )
                             );
}

/// A.6.076
cLinkage* Actions::linkage_specification_decl ( const string &name, cAsgNode *declaration )
{
  return STATE->cLinkageCreate( getCurrentFilename(), 
                               getCurrentLine(),
                               getCurrentLine(),
                               name,
                               false, 
                               key::safe_deref( key::collapseIfObjectList( declaration ) )
                             );
}

//##############################################################################
// A.7
//##############################################################################

/// A.7.001 | A.7.002
AsgNodeList_t* Actions::init_declarator_list( cAsgNode *ident, AsgNodeList_t *objects )
{
  PDEBUG;

  if ( !objects )
    typedef_list.clear();

  if ( cIdentifier *i = dynamic_cast<cIdentifier*>( ident ) )
  {
    typedef_list.push_back( i->mNameDeclaration );
  }

  if ( objects )
  {
    objects->push_back( ident );
    return ( objects );
  }

  return new AsgNodeList_t( 1, ident );
}

/// A.7.003
cAsgNode* Actions::init_declarator( cAsgNode *node, cExpressionBase* init )
{
  PDEBUG;

  cIdentifier *var = dynamic_cast<cIdentifier *>( node );

  if ( init )
  {
    cAsgNode *retVal = 0;

    // NAK - "fix" problem with "A::B::foo( 1, 2 );" being seen as an object decl when foo is a function
    NameOccurrence *occur = new NameOccurrence( var->mNameDeclaration );
    if ( occur->getQualifier() )
    {
      NameDeclaration *func = facade->lookupQualifiedName( occur );
      if ( func )
      {
        Type *ft = func->getType();
        if ( ft->checkType( Type::DT_FUNCTION ) ||
             ft->checkType( Type::DT_FUNCTION_PROTOTYPE ) ||
             ft->checkType( Type::DT_FUNCTION_DEFINITION )
           )
        {
          // function
          retVal = STATE->cBinaryOperatorCreate( getCurrentFilename(), 
                                                 getStartLine( var ),
                                                 getEndLine( init ),
                                                 OT_FCT_CALL,
                                                 STATE->cNameReferenceCreate( var->mFilename,
                                                                              var->mStartLine,
                                                                              var->mEndLine,
                                                                              var->mName,
                                                                              var->mNameDeclaration,
                                                                              0,
                                                                              getNamedNamespace( var )
                                                                            ),
                                                 init
                                               );
          return retVal;
        }
      }
    }
    // END

    retVal = STATE->cObjectCreate( getCurrentFilename(), 
                                   getStartLine( var ),
                                   getEndLine( init ),
                                   var->mName,
                                   geteAccessSpecifier( current_access ),
                                   var->mNameDeclaration,
                                   0,
                                   0,
                                   init,
                                   getType( var ),
                                   getNamedNamespace( var )
                                 );

    return retVal;
  }

  return ( var ? var : node );
}

/// A.7.004
cAsgNode* Actions::declarator_direct ( cAsgNode *node )
{
  PDEBUG;

  if ( cIdentifier *var = dynamic_cast<cIdentifier *>( node ) )
  {
    facade->makeIndirect( var->mNameDeclaration, signature );
    signature = "";

    return var;
  }
  else
  {
    return node;
  }
}

/// A.7.005
void Actions::declarator_ptr_1 ( int ptrop )
{
  PDEBUG;

  if ( isPtr( ptrop ) )
  {
    if ( declStack->size() )
    {
      Type *type = declStack->top();
      declStack->pop();
      type = new IndirectType( type->getDecl(), type, IndirectType::IT_POINTER );
      declStack->push( type );
    }
    else
    {
      signature += "*";
    }
  }
  else if ( isRef( ptrop ) )
  {
    if ( declStack->size() )
    {
      Type *type = declStack->top();
      declStack->pop();
      type = new IndirectType( type->getDecl(), type, IndirectType::IT_REFERENCE );
      declStack->push( type );
    }
    else
    {
      signature += "&";
    }
  }
  lastAddressOperator = 0;  
}

/// A.7.005
cIdentifier* Actions::declarator_ptr_2 ( int ptrop, cAsgNode *node )
{
  PDEBUG;

  cIdentifier *var = dynamic_cast<cIdentifier*>( node );

  if( isPtr( ptrop ) )
  {
    cType *to_apply = STATE->cPointerTypeCreate( getCurrentFilename(),
                                             getStartLine( var ),
                                             getEndLine( var ),
                                             "",
                                             VB_UNKNOWN,
                                             0,
                                             dynamic_cast<IndirectType *>( declStack->top() ),
                                             0
                                           );
    makeCV( to_apply, ptrop );

    if ( cType *ctype = maskType( getReturnType( var ) ) )
    {
      applyType( ctype, to_apply );
    }

    else if ( cObject *obj = dynamic_cast<cObject*>( var ) )
    {
      applyType( to_apply, obj->mType );
      obj->mType = to_apply;
    }

    else
    {
      setType( var, to_apply );
    }
  }
  else
  {
    cType* to_apply = STATE->cReferenceTypeCreate( getCurrentFilename(), 
                                             getCurrentLine(),
                                             getCurrentLine(),
                                             "",
                                             VB_UNKNOWN,
                                             0,
                                             dynamic_cast<IndirectType *>( declStack->top() ),
                                             0
                                           );
    if ( cType *ctype = maskType( getReturnType( var ) ) )
    {
      applyType( ctype, to_apply );
    }
    else
    {
      setType( var, to_apply );
    }
  }

  return var;
}

/// A.7.006
cIdentifier* Actions::direct_declarator_id ( cNameReference *name )
{
  PDEBUG;

  NameDeclaration *decl = name->mNameDeclaration;
  Type *ty = ( declStack->empty() ? new BasicType(BasicType::BT_INT ) : declStack->top() );

  if ( seen_const )
  {
    seen_const = false;
  }
  decl = facade->insertLocal( decl, ty, true );

  cObject *obj = STATE->cObjectCreate( getCurrentFilename(), 
                                       getStartLine( name ),
                                       getEndLine( name ),
                                       decl->getName(),
                                       geteAccessSpecifier( current_access ),
                                       decl,
                                       name->mTemplateArguments,
                                       0,
                                       0,
                                       0,
                                       name->mNamedNamespace
                                     );
  obj->mOperatorType = name->mOperatorType;

  return obj;
}

/// A.7.007
void Actions::direct_declarator_fun_1 ( cAsgNode *node )
{
  PDEBUG;

  cIdentifier *var = dynamic_cast<cIdentifier*>( node );

  var->mNameDeclaration = facade->moveIntoPrototypeScope( var->mNameDeclaration );
}

/// A.7.007
cAsgNode* Actions::direct_declarator_fun_2 ( cAsgNode *node,
                                             cFunctionParameterList *parms,
                                             int cvseq,
                                             cExceptionSpecification *tspec
                                           )
{
  PDEBUG;

  cIdentifier *var = dynamic_cast<cIdentifier*>( node );

// NAK - The "fix"
if ( !parms )
{
  NameOccurrence *occur = new NameOccurrence( var->mNameDeclaration );
  if ( occur->getQualifier() )
  {
    bool containingScopeIsTemplate = false;
    Scope *s  = occur->getQualifier()->getCorrespondingScope();
    if ( dynamic_cast<NamespaceScope*>( s ) || dynamic_cast<ClassScope*>( s ) )
    {
      NameDeclaration *func = facade->lookupQualifiedName( occur );

      Scope *cs = func->getContainingScope();
      if ( cs )
      {
        NameDeclaration *csDecl = cs->getDecl();
        if ( csDecl && csDecl->getIsTemplate() )
        {
          containingScopeIsTemplate = true;
        }
      }

      if ( func && !containingScopeIsTemplate )
      {
        Type *ft = func->getType();
        if ( ft->checkType( Type::DT_FUNCTION ) )
        {
          if ( decorator->getCurrentToken() == SEMI )
          {
            return STATE->cBinaryOperatorCreate( getCurrentFilename(), 
                                                 getStartLine( var ),
                                                 getEndLine( var ),
                                                 OT_FCT_CALL,
                                                 STATE->cNameReferenceCreate( var->mFilename,
                                                                              var->mStartLine,
                                                                              var->mEndLine,
                                                                              var->mName,
                                                                              var->mNameDeclaration,
                                                                              0,
                                                                              getNamedNamespace( var )
                                                                            ),
                                                 0
                                               );
          }
        }
      }
    }
  }
}//end fix

  cFunctionType *ftype = STATE->cFunctionTypeCreate( getCurrentFilename(), 
                                                     getStartLine(var),
                                                     getEndLine(var),
                                                     "",
                                                     VB_UNKNOWN,
                                                     0,
                                                     0,
                                                     parms,
                                                     0
                                                   );
  
  if ( seen_const )
  {
    facade->makeConst( var->mNameDeclaration );
    seen_const = false;
  }

  facade->leaveCurrentScope();
  TemplateArgumentList_t arglist;
  cNameReference *nns = 0;

  if ( cNameReference *nr = dynamic_cast<cNameReference *>( var ) )
  {
    arglist = ( nr->mTemplateArguments ? nr->mTemplateArguments->mArguments : TemplateArgumentList_t() );
    if ( nr->mOperatorType )
    {
      if ( ftype->mReturnType )
      {
        applyType( ftype->mReturnType, nr->mOperatorType );
      }
      else
      {
        ftype->mReturnType = nr->mOperatorType;
      }
    }
    nns = nr->mNamedNamespace;
  }
  else if ( cObject *obj = dynamic_cast<cObject *>( var ) )
  {
    arglist = ( obj->mTemplateArguments ? obj->mTemplateArguments->mArguments : TemplateArgumentList_t() );
    if ( obj->mOperatorType )
    {
      if ( ftype->mReturnType )
      {
        applyType( ftype->mReturnType, obj->mOperatorType );
      }
      else
      {
        ftype->mReturnType = obj->mOperatorType;
      }
    }
    nns = obj->mNamedNamespace;
  }
  else if ( cSpecializedFunction *func = dynamic_cast<cSpecializedFunction *>( var ) )
  {
    arglist = ( func->mTemplateArguments ? func->mTemplateArguments->mArguments : TemplateArgumentList_t() );
    nns = func->mNamedNamespace;
  }

  if ( !getType( var ) )
  {
    makeCV( ftype, cvseq );

    cFunctionInterface *func = 0;
    if ( arglist.size() )
    {
      func = STATE->cSpecializedFunctionCreate( getCurrentFilename(), 
                                                   getStartLine( var ),
                                                   getEndLine( var ),
                                                   var->mName,
                                                   geteAccessSpecifier( current_access ),
                                                   var->mNameDeclaration,
                                                   FK_FREE,
                                                   false,
                                                   nns,
                                                   ftype,
                                                   tspec,
                                                   0,
                                                   0,
                                                   STATE->cTemplateArgumentListCreate( getCurrentFilename(),
                                                                                             getCurrentLine(),
                                                                                             getCurrentLine(),
                                                                                             arglist
                                                                                           )
                                                 );
    }
    else
    {
      func = STATE->cFunctionCreate( getCurrentFilename(), 
                                     getStartLine( var ),
                                     getEndLine( var ),
                                     var->mName,
                                     geteAccessSpecifier( current_access ),
                                     var->mNameDeclaration,
                                     FK_FREE,
                                     false,
                                     nns,
                                     ftype,
                                     tspec,
                                     0,
                                     0
                                   );
    }

    return func;
  }
  else
  {
	// FUNCTION POINTER
    return STATE->cObjectCreate( getCurrentFilename(), 
                                 getStartLine( var ),
                                 getEndLine( var ),
                                 var->mName,
                                 geteAccessSpecifier( current_access ),
                                 var->mNameDeclaration,
                                 ( arglist.size()
                                    ? STATE->cTemplateArgumentListCreate( getCurrentFilename(),
                                                                                 getCurrentLine(),
                                                                                 getCurrentLine(),
                                                                                 arglist
                                                                               )
                                    : 0 ),
                                 0,
                                 0,
                                 applyType( getType( var ), ftype ),
                                 nns
                               );
  }
}

/// A.7.008
cIdentifier* Actions::direct_declarator_arr ( cAsgNode *node, cExpression *expr )
{
  PDEBUG;

  cIdentifier *var = dynamic_cast<cIdentifier*>( node );

  signature += "[";
  if ( !expr )
    expr = STATE->cEmptyExpressionCreate( getCurrentFilename(), getStartLine( var ), getEndLine( var ) );

  cObject *obj = dynamic_cast<cObject *>( var );

  MAKE_ASSERTION( obj, "direct_declarator_arr called without object!" );

  if ( !obj->mType )
  {
    obj->mType = STATE->cArrayTypeCreate( getCurrentFilename(), 
                                           getStartLine( var ),
                                           getEndLine( var ),
                                           var->mName,
                                           VB_UNKNOWN,
                                           obj->mNameDeclaration,
                                           new IndirectType( obj->mNameDeclaration, obj->mNameDeclaration->getType(), IndirectType::IT_POINTER ),
                                           0,
                                           expr
                                         );
  }
  else
  {
    // NAK - Use Array Types
    obj->mType = STATE->cArrayTypeCreate( getCurrentFilename(), 
                                           getStartLine( obj ),
                                           getEndLine( obj ),
                                           var->mName,
                                           VB_UNKNOWN,
                                           obj->mNameDeclaration,
                                           new IndirectType( obj->mNameDeclaration, obj->mNameDeclaration->getType(), IndirectType::IT_POINTER ),
                                           obj->mType,
                                           expr
                                         );
  }

  return obj;
}

/// A.7.010 | A.7.011 | A.7.012
int Actions::ptr_operator ( int last, int cvSequenceValue )
{
  lastAddressOperator = last;

  int toReturn = cvSequenceValue;

  if ( last == STAR )
  {
    toReturn += 10;
  }
  else
  {
    toReturn += 20;
  }

  return toReturn;
}

/// A.7.018
cType* Actions::type_id ( cType *lhs, cType *rhs )
{
  PDEBUG;

  if ( rhs )
  {
    applyType( rhs, lhs );
    applyKeyType( getKeyType( rhs ), getKeyType( lhs ) );

    return rhs;
  }

  return lhs;
}

/// A.7.019
cType* Actions::type_specifier_seq ( cType *spec, cType *opt )
{
  cType *retVal = 0;

  cQualifierType *qt = 0;
  if ( ( qt = dynamic_cast<cQualifierType *>( spec ) ) )
  {
    if ( opt )
    {
      if ( qt->mCvSum == 1 )
      {
        opt->mIsConst = true;
      }
      else if ( qt->mCvSum == 2 )
      {
        opt->mIsVolatile = true;
      }
      else if ( qt->mCvSum == 3 )
      {
        opt->mIsConst = true;
        opt->mIsVolatile = true;
      }
    }
  }
  if ( !spec || qt )
  {
    retVal = opt;
  }
  else
  {
    retVal = spec;
  }

  return retVal;
}

/// A.7.020
cType* Actions::abstract_declarator ( int ptrop, cType *adopt )
{
  PDEBUG;

  NameDeclaration *to_use = ( adopt ? adopt->mNameDeclaration : facade->makeAnonIdent( line_num_for_abs_decl, 0 ) );
  IndirectType *it;

  if ( isPtr( ptrop ) )
  {
    if ( adopt )
    {
      it = new IndirectType( to_use, 0, IndirectType::IT_POINTER );
      applyKeyType( to_use->getType(), it );
      cPointerType *ptr = STATE->cPointerTypeCreate( getCurrentFilename(),
                                             getCurrentLine(),
                                             getCurrentLine(),
                                             "",
                                             VB_UNKNOWN,
                                             to_use,
                                             it,
                                             0
                                           );
      makeCV( ptr, ptrop );

      return applyType( adopt, ptr );
    }
    else
    {
      it = new IndirectType( to_use, to_use->getType(), IndirectType::IT_POINTER );
      to_use->setType( it );
      cPointerType *ptr = STATE->cPointerTypeCreate( getCurrentFilename(), 
                                             getCurrentLine(),
                                             getCurrentLine(),
                                             "",
                                             VB_UNKNOWN,
                                             to_use,
                                             it,
                                             0
                                           );
      makeCV( ptr, ptrop );

      return ptr;
    }
  }
  else
  {
    if ( adopt )
    {
      it = new IndirectType( to_use, 0, IndirectType::IT_REFERENCE );
      applyKeyType( to_use->getType(), it );
      cReferenceType *ref = STATE->cReferenceTypeCreate( getCurrentFilename(), 
                                             getCurrentLine(),
                                             getCurrentLine(),
                                             "",
                                             VB_UNKNOWN,
                                             to_use,
                                             it,
                                             0
                                           );

      return applyType( adopt, ref );
    }
    else
    {
      it = new IndirectType( to_use, to_use->getType(), IndirectType::IT_REFERENCE );
      to_use->setType( it );
      cReferenceType *ref = STATE->cReferenceTypeCreate( getCurrentFilename(), 
                                             getCurrentLine(),
                                             getCurrentLine(),
                                             "",
                                             VB_UNKNOWN,
                                             to_use,
                                             it,
                                             0
                                           );

      return ref;
    }
  }
}

/// A.7.022
cType* Actions::direct_abstract_declarator_fun ( cType* unk, cFunctionParameterList *parms, int ptrop, cExceptionSpecification *tspec )
{
  PDEBUG;

  NameDeclaration *to_use;
  FunctionType *fct;

  if ( unk && unk->mNameDeclaration )
  {
    to_use = unk->mNameDeclaration;    
    applyKeyType( to_use->getType(), fct = new FunctionType( to_use, 0, FunctionType::Q_PROTOTYPE ) );
  }
  else
  {
    to_use = facade->makeAnonIdent( line_num_for_abs_decl, 0 );
    to_use->setType( fct = new FunctionType( to_use, to_use->getType(), FunctionType::Q_PROTOTYPE ) );
  }

  cType *to_return = STATE->cFunctionTypeInformationCreate( getCurrentFilename(), 
                                                         getCurrentLine(),
                                                         getCurrentLine(),
                                                         "",
                                                         VB_UNKNOWN,
                                                         to_use,             
                                                         fct,
                                                         parms,
                                                         tspec,
                                                         0
                                                       );
  makeCV( to_return, ptrop );

  return applyType( unk, to_return );
}

/// A.7.023
cType* Actions::direct_abstract_declarator_arr ( cType *base, cExpression *expr )
{
  PDEBUG;

  if ( !expr )
    expr = STATE->cEmptyExpressionCreate( getCurrentFilename(),
                                    getCurrentLine(),
                                    getCurrentLine()
                                  );
  NameDeclaration *to_use;
  IndirectType *it;

  if ( base && base->mNameDeclaration )
  {
    to_use = base->mNameDeclaration;
    base->mNameDeclaration->setType( it = new IndirectType( base->mNameDeclaration, base->mNameDeclaration->getType(), IndirectType::IT_ARRAY ) );
  }
  else
  {
    to_use = facade->makeAnonIdent( line_num_for_abs_decl, 0 );
    to_use->setType( it = new IndirectType( to_use, 0, IndirectType::IT_ARRAY ) );
  }

  // NAK - Use Array Types
  return STATE->cArrayTypeCreate( getCurrentFilename(), 
                                  getCurrentLine(),
                                  getCurrentLine(),
                                  "",
                                  VB_UNKNOWN,
                                  to_use,
                                  it,
                                  base,
                                  expr
                                );
}

/// A.7.025 | A.7.026
cFunctionParameterList* Actions::parameter_declaration_clause ( cFunctionParameterList *parms, bool ellipses )
{
  if ( ellipses )
  {
    // NAK - represent ellipses
    cFunctionParameter *ep = STATE->cFunctionParameterCreate( getCurrentFilename(), 
                                                                          getCurrentLine(),
                                                                          getCurrentLine(),
                                                                          "...",
                                                                          VB_UNKNOWN,
                                                                          0,
                                                                          false,
                                                                          false,
                                                                          0,
                                                                          0,
                                                                          0,
                                                                          0
                                                                        );

    if ( parms )
    {
      parms->mParameters.push_back( ep );
    }
    else
    {
      //return new ParameterList_t( 1, ep );
      return STATE->cFunctionParameterListCreate( getCurrentFilename(),
                                                  getCurrentLine(),
                                                  getCurrentLine(),
                                                  "",
                                                  VB_UNKNOWN,
                                                  0,
                                                  FunctionParameterList_t( 1, ep )
                                                );
    }
  }

  return parms;
}

/// A.7.027 | A.7.028
cFunctionParameterList* Actions::parameter_declaration_list ( cFunctionParameter *parm, cFunctionParameterList *parms )
{
  PDEBUG;

  declStack->pop();

  if ( !parm )
  {
    return parms;
  }

  if ( parms )
  {
    parms->mParameters.push_back( parm );
    return parms;
  }

  //return new ParameterList_t( 1, parm );
      return STATE->cFunctionParameterListCreate( getCurrentFilename(),
                                                  getCurrentLine(),
                                                  getCurrentLine(),
                                                  "",
                                                  VB_UNKNOWN,
                                                  0,
                                                  FunctionParameterList_t( 1, parm )
                                                );
}

/// A.7.029 | A.7.030
cFunctionParameter* Actions::parameter_declaration_named ( DeclSpecifierList_t *dsl, cAsgNode *id, cExpression *exp )
{
  PDEBUG;

  cObject *to_return = dynamic_cast<cObject *>( id );

  if ( to_return->mType )
  {
    setType( to_return, applyType( to_return->mType, findType( dsl ) ) );
  }
  else
  {
    setType( to_return, findType( dsl ) );
  }

  // NAK - cv correctness for function parameters
  if ( cPointerType *pt = dynamic_cast<cPointerType*>( to_return->mType ) )
  {
    updateType( pt->mBaseType, dsl );
  }
  else if ( cReferenceType *rt = dynamic_cast<cReferenceType*>( to_return->mType ) )
  {
    updateType( rt->mBaseType, dsl );
  }
  else if ( cArrayType *at = dynamic_cast<cArrayType*>( to_return->mType ) )
  {
    if ( cPointerType *pt = dynamic_cast<cPointerType*>( at->mBaseType ) )
    {
      updateType( pt->mBaseType, dsl );
    }
    else if ( cReferenceType *rt = dynamic_cast<cReferenceType*>( at->mBaseType ) )
    {
      updateType( rt->mBaseType, dsl );
    }
    else
    {
      updateType( at->mBaseType, dsl );
    }
  }
  else
  {
    updateType( to_return->mType, dsl );
  }
  // END

  if ( exp )
  {
    to_return->mInitialValue = exp;
  }

  if ( hasDeclSpec( dsl, DS_STATIC ) ||
       hasDeclSpec( dsl, DS_EXTERN ) ||
       hasDeclSpec( dsl, DS_MUTABLE )
     )
  {
    std::cerr << getCurrentFilename() << ":" << getCurrentLine() << " :error: "
              << "Invalid storage class specifier in parameter declaration" << std::endl;
  }

  return STATE->cFunctionParameterCreate( getCurrentFilename(), 
                                                getStartLine( to_return ),
                                                getEndLine( to_return ),
                                                to_return->mName,
                                                VB_UNKNOWN,
                                                to_return->mNameDeclaration,
                                                hasDeclSpec( dsl, DS_AUTO ),
                                                hasDeclSpec( dsl, DS_REGISTER ),
                                                to_return->mType,
                                                to_return->mTemplateArguments,
                                                to_return->mNamedNamespace,
                                                to_return->mInitialValue
                                              );
}

/// A.7.031 | A.7.032
cFunctionParameter* Actions::parameter_declaration_unnamed ( DeclSpecifierList_t *dsl, cType *type, cExpression *exp )
{
  PDEBUG;

  // check for void!
  NameDeclaration *tmp = 0;

  if ( !seen_friend )
  {
    tmp = checkAnonParm( 0, line_num_for_abs_decl, declStack->size() );
    if ( seen_const )
    {
      facade->makeConst( tmp );
      seen_const = false;
    }
    tmp = facade->insertLocal( tmp, declStack->top()->Clone(), true );
    tmp->setInstance( true );
  }
  cType *new_type = findType( dsl );

  if ( type )
  {
    applyKeyType( getKeyType( type ), getKeyType( new_type ) );
    new_type = applyType( type, new_type );
  }

  // NAK - cv correctness for function parameters
  if ( cPointerType *pt = dynamic_cast<cPointerType*>( new_type ) )
  {
    updateType( pt->mBaseType, dsl );
  }
  else if ( cReferenceType *rt = dynamic_cast<cReferenceType*>( new_type ) )
  {
    updateType( rt->mBaseType, dsl );
  }
  else if ( cArrayType *at = dynamic_cast<cArrayType*>( new_type ) )
  {
    if ( cPointerType *pt = dynamic_cast<cPointerType*>( at->mBaseType ) )
    {
      updateType( pt->mBaseType, dsl );
    }
    else if ( cReferenceType *rt = dynamic_cast<cReferenceType*>( at->mBaseType ) )
    {
      updateType( rt->mBaseType, dsl );
    }
    else
    {
      updateType( at->mBaseType, dsl );
    }
  }
  else
  {
    updateType( new_type, dsl );
  }
  // END


  if ( cBuiltInType *bt = dynamic_cast<cBuiltInType *>( new_type ) )
  {
    if ( bt->mBasicType->checkBasicType( BasicType::BT_VOID ) )
    {
      return 0;
    }
  }

  return STATE->cFunctionParameterCreate( getCurrentFilename(), 
                                                getCurrentLine(),
                                                getCurrentLine(),
                                                "",
                                                VB_UNKNOWN,
                                                tmp,
                                                hasDeclSpec( dsl, DS_AUTO ),
                                                hasDeclSpec( dsl, DS_REGISTER ),
                                                new_type,
                                                0,
                                                0,
                                                exp
                                              );
}

/// A.7.033 | A.7.034
void Actions::function_definition_1 ( cAsgNode *node )
{
  PDEBUG;

  if ( cIdentifier *id = dynamic_cast<cIdentifier*>( node ) )
  {
    facade->moveIntoFunctionScope( id->mNameDeclaration );
  }

  if ( ! declStack->empty() )
  {
    declStack->pop();
  }
}

/// A.7.033 | A.7.034
cFunctionInterface* Actions::function_definition_2 ( DeclSpecifierList_t *dsl, cAsgNode *node, cBlock *ctor, cBlock *body )
{
  PDEBUG;

  // Parameter "node" is either a cFunctionType or a cFunctionInterface.
  // Unfortunately, there is lots of cut and pasted code and lost info in the process.  I've patched this, but there is 
  // plenty of useless code here.

  cIdentifier *id = dynamic_cast<cIdentifier*>( node );

  if ( seen_pure )
  {
    facade->makeFunctionPure( id->mNameDeclaration );
    seen_pure = false;
  }

  if ( seen_const )
  {
    facade->makeConst( id->mNameDeclaration );
    seen_const = false;
  }

  if ( seen_static )
  {
    facade->makeStatic( id->mNameDeclaration );
    seen_static = false;
  }

  if ( seen_virtual )
  {
    facade->makeFunctionVirtual( id->mNameDeclaration );
    seen_virtual = false;
  }

  if ( seen_friend )
  {
    facade->makeFriend( id->mNameDeclaration );
    seen_friend = false;
  }
  else
  {
    facade->setAccess( id->mNameDeclaration, current_access );
  }  
        
  facade->leaveCurrentScope();

  /// Could have either a cFunctionType or a cFunctionTypeInformation
  cExceptionSpecification *exceptions = 0;
  cFunctionType *ftype = 0;
  cFunctionTypeInformation *fti = dynamic_cast<cFunctionTypeInformation *>( getType( id ) );
  if ( fti )
  {
    exceptions = fti->mExceptionSpec;

    ftype = STATE->cFunctionTypeCreate( fti->mFilename,
                                        fti->mStartLine,
                                        fti->mEndLine,
                                        fti->mName,
                                        VB_UNKNOWN,
                                        fti->mNameDeclaration,
                                        fti->mFunctionType,
                                        fti->mParameters,
                                        fti->mReturnType
                                      );
  }
  else
  {
    ftype = dynamic_cast<cFunctionType *>( getType( id ) );
  }

  if ( cType *rtype = findType( dsl ) )
  {
    if ( ftype->mReturnType )
    {
      applyType( ftype->mReturnType, rtype );
    }
    else
    {
      ftype->mReturnType = rtype;
    }
  }

  updateType( ftype->mReturnType, dsl );
  TemplateArgumentList_t arglist;
  cNameReference *nns = 0;
  if ( cNameReference *nr = dynamic_cast<cNameReference *>( id ) )
  {
    arglist = ( nr->mTemplateArguments ? nr->mTemplateArguments->mArguments : TemplateArgumentList_t() );
    if ( nr->mOperatorType )
    {
      if ( ftype->mReturnType )
      {
        applyType( ftype->mReturnType, nr->mOperatorType );
      }
      else
      {
        ftype->mReturnType = nr->mOperatorType;
      }
    }
    nns = nr->mNamedNamespace;
  }
  else if ( cObject *obj = dynamic_cast<cObject *>( id ) )
  {
    arglist = ( obj->mTemplateArguments ? obj->mTemplateArguments->mArguments : TemplateArgumentList_t() );
    nns = obj->mNamedNamespace;
  }
  else if ( cSpecializedFunction *func = dynamic_cast<cSpecializedFunction *>( id ) )
  {
    arglist = ( func->mTemplateArguments ? func->mTemplateArguments->mArguments : TemplateArgumentList_t() );
    nns = func->mNamedNamespace;
  }

  cFunctionInterface *fctn = 0;

  if ( cSpecializedFunction *sfct = dynamic_cast<cSpecializedFunction*>( node ) )
  {
    sfct->mInit = static_cast<cCtorInitializerBlock*>( ctor );
    sfct->mBlock = body;
    sfct->mTemplateArguments = STATE->cTemplateArgumentListCreate( getCurrentFilename(),
                                                                   getCurrentLine(),
                                                                   getCurrentLine(),
                                                                   arglist
                                                                 );
    fctn = sfct;
  }
  else if ( cFunction *fct = dynamic_cast<cFunction*>( node ) )
  {
    fct->mInit = static_cast<cCtorInitializerBlock*>( ctor );
    fct->mBlock = body;
    fctn = fct;
  }
  else
  {
    if ( arglist.size() )
    {
      fctn = STATE->cSpecializedFunctionCreate( getCurrentFilename(), 
                                                   getStartLine( id ),
                                                   getEndLine( id ),
                                                   id->mNameDeclaration->getName(),
                                                   geteAccessSpecifier( current_access ),
                                                   id->mNameDeclaration,
                                                   FK_FREE,
                                                   false,
                                                   nns,
                                                   ftype,
                                                   exceptions,
                                                   static_cast<cCtorInitializerBlock*>( ctor ),
                                                   body,
                                                   STATE->cTemplateArgumentListCreate( getCurrentFilename(),
                                                                                              getCurrentLine(),
                                                                                              getCurrentLine(),
                                                                                              arglist
                                                                                            )
                                                 );
    }
    else
    {
      fctn = STATE->cFunctionCreate( getCurrentFilename(), 
                                     getStartLine( id ),
                                     getEndLine( id ),
                                     id->mNameDeclaration->getName(),
                                     geteAccessSpecifier( current_access ),
                                     id->mNameDeclaration,
                                     FK_FREE,
                                     false,
                                     nns,
                                     ftype,
                                     exceptions,
                                     static_cast<cCtorInitializerBlock*>( ctor ),
                                     body
                                   );
    }
  }

  if ( hasDeclSpec( dsl, DS_INLINE ) )   fctn->mIsInline   = true;
  if ( hasDeclSpec( dsl, DS_STATIC ) )   fctn->mIsStatic   = true;
  if ( hasDeclSpec( dsl, DS_EXTERN ) )   fctn->mIsExtern   = true;
  if ( hasDeclSpec( dsl, DS_VIRTUAL ) )  fctn->mIsVirtual  = true;
  if ( hasDeclSpec( dsl, DS_EXPLICIT ) ) fctn->mIsExplicit = true;  

  return fctn;
}

/// A.7.041 | A.7.042
cInitializerList *Actions::initializer_list ( cExpressionBase *expr, cInitializerList *objects )
{
  PDEBUG;

  if ( objects )
  {
    objects->mInitializers.push_back( expr );

    return objects;
  }
  else
  {
    ArgumentList_t args( 1, expr );

    return STATE->cInitializerListCreate( getCurrentFilename(), 
                                   getCurrentLine(),
                                   getCurrentLine(),
                                   args
                                 );
  }
}

/// A.8.001
cClassTypeInterface* Actions::class_specifier ( cClassTypeInterface *type, ClassPairList_t *members )
{
  PDEBUG;

  facade->leaveCurrentScope();

  // NAK - reset current upon leaving class
  current_access = getEntryAccess();
  popEntryAccess();

  if ( !members )
  {
    return type;
  }

  for ( ClassPairList_t::iterator it = members->begin();
        it != members->end();
        ++it
      )
  {
    if ( (*it)->second )
    {
      type->mFriends.push_back( (*it)->first );
    }
    else
    {
      if ( cIdentifier *ci = dynamic_cast<cIdentifier*>( (*it)->first ) )
      {
        /// Add parent pointers for class members
        /// cClassType and cSpecializedClassTYpe only
        ci->mDefinedIn = type;
      }

      if ( cFunctionInterface *fi = dynamic_cast<cFunctionInterface*>( (*it)->first ) )
      {
        if ( fi->mName.find( "::" ) != std::string::npos )
        {
          if ( fi->mName.find( "~" ) != std::string::npos )
          {
            fi->mFunctionKey = FK_DESTRUCTOR;
          }
          else
          {
            fi->mFunctionKey = FK_CONSTRUCTOR;
          }
        }
        /// Note the " " that differentiates between an overloaded operator
        else if ( fi->mName.find( "operator " ) != std::string::npos )
        {
          fi->mFunctionKey = FK_CONVERSION;
        }
        else if ( fi->mName.find( "operator" ) != std::string::npos )
        {
          fi->mFunctionKey = FK_OPERATOR;
        }
        else
        {
          fi->mFunctionKey = FK_MEMBER;
        }
      }

      /// Add class members to the list
      type->mMembers.push_back( (*it)->first );
    }
  }
  delete members;

  return type;
}

/// A.8.002
NameDeclaration* Actions::class_head_opt ( NameDeclaration *decl )
{
  PDEBUG;

  bool inClass = facade->inClassScope();
  NameDeclaration *tmp = checkAnon( decl, location->lineNumber() );
  tmp = facade->moveIntoClassScope( tmp );

  if ( inClass )
  {
    facade->setAccessForClass( current_access );
  }
  current_access = next_access;

  return ( tmp );
}

/// A.8.003
NameDeclaration* Actions::class_head_nns ( NameDeclaration *decl )
{
  PDEBUG;

  bool inClass = facade->inClassScope();
  NameDeclaration *tmp = facade->moveIntoClassScope( decl );
  if ( inClass )
  {
    facade->setAccessForClass( current_access );
  }
  current_access = next_access;

  return tmp;
}

/// A.8.002 | A>8.003
cClassTypeInterface* Actions::class_head ( int key, cNameReference *nns, NameDeclaration *decl, BaseClassList_t *parents )
{
  PDEBUG;

  cClassType *at = STATE->cClassTypeCreate( getCurrentFilename(), 
                                          decl->getLinenum(),
                                          getCurrentLine(),
                                          decl->getName(),
                                          geteAccessSpecifier( getEntryAccess() ),
                                          decl,
                                          key::safe_deref( parents ),
                                          FriendList_t(),
                                          MemberList_t(),
                                          eClassKey( key )
                                        );
  delete parents;

  current_access = next_access;

  return at;
}

/// A.8.004
cNameReference* Actions::class_head_template ( cNameReference *decl )
{
  PDEBUG;

  bool inClass = facade->inClassScope();
  decl->mNameDeclaration = facade->moveIntoClassScope(decl->mNameDeclaration);

  if ( inClass )
  {
    facade->setAccessForClass( current_access );
  }
  current_access = next_access;

  return decl;
}

/// A.8.004
/// pre: decl != NULL
cClassTypeInterface* Actions::class_head_template_bc( int key, cNameReference *nns, cNameReference *decl, BaseClassList_t *parents )
{
  PDEBUG;

  cClassTypeInterface *ct = 0;
  if ( decl->mTemplateArguments && decl->mTemplateArguments->mArguments.size() )
  {
    ct = STATE->cSpecializedClassTypeCreate( getCurrentFilename(), 
                                 getStartLine(decl),
                                 getEndLine(decl),
                                 decl->mName,
                                 geteAccessSpecifier( getEntryAccess() ),
                                 decl->mNameDeclaration,
                                 key::safe_deref( parents ),
                                 FriendList_t(),
                                 MemberList_t(),
                                 eClassKey( key ),
                                 decl->mTemplateArguments
                               );
  }
  else
  {
    ct = STATE->cClassTypeCreate( getCurrentFilename(), 
                                 getStartLine(decl),
                                 getEndLine(decl),
                                 decl->mName,
                                 geteAccessSpecifier( getEntryAccess() ),
                                 decl->mNameDeclaration,
                                 key::safe_deref( parents ),
                                 FriendList_t(),
                                 MemberList_t(),
                                 eClassKey( key )
                               );
  }

  delete parents;

  current_access = next_access;

  return ct;
}

/// A.8.008
ClassPairList_t* Actions::member_specification ( ClassPair_t *mem, ClassPairList_t *objects )
{
  PDEBUG;

  if ( ! objects )
  {
    objects = new ClassPairList_t;
  }

  //
  // This should be worked into collapseIfObjectList
  //
  /// if we received an object list of size 1, then make its children the children of param objects
  if ( cObjectList *lst = dynamic_cast<cObjectList*>( mem->first ) )
  {
    if ( lst->mObjects.size() == 1 )
    {
      register unsigned int size = lst->mObjects.size();
      ClassPairList_t *newObjects = new ClassPairList_t;
      for ( std::vector<cAsgNode*>::const_iterator ptr = lst->mObjects.begin();
            ptr != lst->mObjects.end();
            ++ptr
          )
      {
        ClassPair_t *cm = new std::pair<cAsgNode*,bool>( (*ptr), mem->second );
        newObjects->push_back( cm );
      }
      objects->insert( objects->begin(), newObjects->begin(), newObjects->end() );
      delete newObjects;
    }
    else
    {
      objects->insert( objects->begin(), mem );
    }
  }
  else
  {
    objects->insert( objects->begin(), mem );
  }

  return objects;
}

/// A.8.010
ClassPair_t* Actions::member_declaration ( DeclSpecifierList_t *dsl, MemberList_t *objects )
{
  PDEBUG;

  if ( hasDeclSpec( dsl, DS_TYPEDEF ) )
  {
    for ( list<NameDeclaration*>::iterator it = typedef_list.begin();
          it != typedef_list.end();
          ++it
        )
    {
      facade->makeTypedef( *it );
    }

    if ( objects )
    {
      for ( AsgNodeList_t::iterator it = objects->begin();
            it != objects->end();
            ++it
          )
      {
        if ( cObject *co = dynamic_cast<cObject *>( *it ) )
        {
          cType* to_add = co->mType;

          if ( to_add )
          {
            applyType( to_add, findType( dsl ) );
          }
          else
            to_add = findType( dsl );

          *it = STATE->cAliasTypeCreate( getCurrentFilename(), 
                                         getStartLine(co),
                                         getEndLine(co),
                                         co->mName,
                                         geteAccessSpecifier( current_access ),
                                         co->mNameDeclaration,
                                         to_add
                                       );
        }
      }
    }
  }

  if ( !declStack->empty() ) 
    declStack->pop();

  if ( objects && findType( dsl ) )
  {
    cType *type = findType( dsl );    
    updateType( type, dsl );

    for ( MemberList_t::iterator it = objects->begin();
          it != objects->end();
          ++it )
    {
      if ( cObject *obj = dynamic_cast<cObject *>( *it ) )
      {
        if ( obj->mType )
          applyType( obj->mType, type );
        else
          obj->mType = type;

        if ( hasDeclSpec( dsl, DS_AUTO ) )     obj->mIsAuto      = true;
        if ( hasDeclSpec( dsl, DS_REGISTER ) ) obj->mIsRegister  = true;
        if ( hasDeclSpec( dsl, DS_STATIC ) )   obj->mIsStatic = true;
        if ( hasDeclSpec( dsl, DS_EXTERN ) )   obj->mIsExtern = true;
        if ( hasDeclSpec( dsl, DS_MUTABLE ) )  obj->mIsMutable = true;        
      }
      else if ( cFunction *fct = dynamic_cast<cFunction *>( *it ) )
      {
        if ( fct->mType )
        {
          if ( fct->mType->mReturnType )
          {
            applyType( fct->mType->mReturnType, type );
          }
          else
          {
            fct->mType->mReturnType = type;
          }
        }

        if ( hasDeclSpec( dsl, DS_INLINE ) )   fct->mIsInline  = true;
        if ( hasDeclSpec( dsl, DS_STATIC ) )   fct->mIsStatic   = true;
        if ( hasDeclSpec( dsl, DS_EXTERN ) )   fct->mIsExtern   = true;
        if ( hasDeclSpec( dsl, DS_VIRTUAL ) )  fct->mIsVirtual  = true;
        if ( hasDeclSpec( dsl, DS_EXPLICIT ) ) fct->mIsExplicit = true;
      }      
    }
  }
  else if ( objects )
  {
    for ( MemberList_t::iterator it = objects->begin();
          it != objects->end();
          ++it
        )
    {
      if ( cFunction *fct = dynamic_cast<cFunction *>( *it ) )
      {
        if ( fct->mType )
          updateType( fct->mType->mReturnType, dsl );

        if ( hasDeclSpec( dsl, DS_INLINE ) )   fct->mIsInline   = true;
        if ( hasDeclSpec( dsl, DS_STATIC ) )   fct->mIsStatic   = true;
        if ( hasDeclSpec( dsl, DS_EXTERN ) )   fct->mIsExtern   = true;
        if ( hasDeclSpec( dsl, DS_VIRTUAL ) )  fct->mIsVirtual  = true;
        if ( hasDeclSpec( dsl, DS_EXPLICIT ) ) fct->mIsExplicit = true;        
      }
    }
  }

  if ( cType *t = declaredType( findType( dsl ), objects ) )
  {
    if ( objects )
      objects->insert( objects->begin(), t );
    else {      
      objects = new AsgNodeList_t( 1, t );

      // check for anonymous unions!
      if ( cClassType *at = dynamic_cast<cClassType *>(t) )
      {
        if ( at->mName.substr( 0, 6 ) == "__anon" && at->mClassKey == AT_UNION )
        {
          for ( MemberList_t::iterator it = at->mMembers.begin();
                it != at->mMembers.end();
                ++it
              )
          {
            if ( cObjectList *olist = dynamic_cast<cObjectList *>( *it ) )
            {
              for ( AsgNodeList_t::iterator it = olist->mObjects.begin();
                    it != olist->mObjects.end();
                    ++it
                  )
              {
                if ( cIdentifier *id = dynamic_cast<cIdentifier *>( *it ) )
                {
                  facade->getCurrentScope()->insertLocal( id->mNameDeclaration );
                }
              }
            }

            /// Tanton depended on this being an object list, but we've eliminated some of them
            else if ( cIdentifier *id = dynamic_cast<cIdentifier *>( *it ) )
            {
              facade->getCurrentScope()->insertLocal( id->mNameDeclaration );
            }

          }
        }
      }
    }
  }

  bool sf = seen_friend_tree;
  seen_friend_tree = false;

  return new ClassPair_t( STATE->cObjectListCreate( getCurrentFilename(), 
                                                      getCurrentLine(),
                                                      getCurrentLine(),
                                                      "",
                                                      geteAccessSpecifier( current_access ),
                                                      0,
                                                      key::safe_deref( objects )
                                                    ),
                            sf
                          );
}

/// A.8.011
ClassPair_t* Actions::member_declaration_fundef ( cAsgNode *fun )
{
  PDEBUG;

  bool sf = seen_friend_tree;
  seen_friend_tree = false;

  return new ClassPair_t( fun, sf );
}

/// A.8.012
ClassPair_t* Actions::member_declaration_disambiguated ( cNameReference *namedNamespace, cNameReference *unqualifiedId )
{
  PDEBUG;

  bool sf = seen_friend_tree;
  seen_friend_tree = false;

  unqualifiedId->mNamedNamespace = namedNamespace;

  return new ClassPair_t( unqualifiedId, sf );
}

/// A.8.013
ClassPair_t* Actions::member_declaration_using ( cAsgNode *usingDeclaration )
{
  PDEBUG;

  return new ClassPair_t( usingDeclaration, false );
}

/// A.8.014
ClassPair_t* Actions::member_declaration_template ( cAsgNode *tem )
{
  PDEBUG;

  bool sf = seen_friend_tree;
  seen_friend_tree = false;

  return new ClassPair_t( tem, sf );
}

/// A.8.015 | A.8.016
MemberList_t* Actions::member_declarator_list ( cIdentifier *decl, MemberList_t *objects )
{
  PDEBUG;

  MemberList_t *to_return = objects;

  if ( !objects )
  {
    typedef_list.clear();
    to_return = new MemberList_t;
  }

  typedef_list.push_back( decl->mNameDeclaration );
  to_return->push_back( decl );

  return to_return;
}

/// K.2.048
MemberList_t* Actions::member_declarator_list_opt ( void )
{
  PDEBUG;

  typedef_list.clear();

  return 0;
}

/// A.8.017 | A.8.018
cIdentifier* Actions::member_declarator ( cAsgNode *node, cExpression *exp )
{
  PDEBUG;

  cIdentifier *id = dynamic_cast<cIdentifier*>( node );

  if ( seen_pure )
  {
    facade->makeFunctionPure( id->mNameDeclaration );
    seen_pure = false;
  }
  if ( seen_const )
  {
    facade->makeConst( id->mNameDeclaration );
    seen_const = false;
  }
  if ( seen_static )
  {
    facade->makeStatic( id->mNameDeclaration );
    seen_static = false;
  }
  if ( seen_virtual )
  {
    facade->makeFunctionVirtual( id->mNameDeclaration );
    seen_virtual = false;
  }  
  if ( seen_friend )
  {
    facade->makeFriend( id->mNameDeclaration );
    seen_friend = false;
  }
  else
  {
    facade->setAccess( id->mNameDeclaration, current_access );
  }

  if ( cObject *obj = dynamic_cast<cObject *>( id ) )
  {
    if ( exp )
      obj->mInitialValue = exp;
  }
  else if( cFunction *fct = dynamic_cast<cFunction *>( id ) )
  {
    if ( exp )
      fct->mIsPureVirtual = true;
  }

  return id;
}

/// A.8.019
cIdentifier* Actions::member_declarator_bitfield ( NameDeclaration *decl, int line, cExpression *bits )
{
  PDEBUG;

  decl = checkAnon( decl, line );

  return STATE->cObjectCreate( getCurrentFilename(), 
                               getCurrentLine(),
                               getCurrentLine(),
                               decl->getName(),
                               geteAccessSpecifier( current_access ),
                               decl,
                               0,
                               bits,
                               0,
                               STATE->cBuiltInTypeCreate( "", 
                                                          getCurrentLine(),
                                                          getCurrentLine(),
                                                          "int",
                                                          VB_UNKNOWN,
                                                          0,
                                                          new BasicType( BasicType::BT_INT )
                                                        ), 
                               NULL
                             );
}

/// A.8.020
cExpression* Actions::pure_specifier( const string &str )
{
  PDEBUG;

  seen_pure = true;

  cLiteral *literal = STATE->cLiteralCreate( getCurrentFilename(), 
                                             getCurrentLine(),
                                             getCurrentLine(),
                                             str
                                           );

  literal->mType = STATE->cBuiltInTypeCreate( "", 
                                               getCurrentLine(),
                                               getCurrentLine(),
                                               "int",
                                               VB_UNKNOWN,
                                               0,
                                               new BasicType( BasicType::BT_INT )
                                             );

  return literal; 
}

/// A.8.021
cExpression* Actions::constant_initializer ( cExpression *ce )
{
  PDEBUG;

  // NAK
  // Need to save this value, could be just a literal, or a literal with a unary-op
  string name = "";
  if ( cLiteral *cl = dynamic_cast<cLiteral*>( ce ) )
  {
    name = cl->mValue;
  }
  else if ( cUnaryOperator *uo = dynamic_cast<cUnaryOperator*>( ce ) )
  {
    switch ( uo->mOperator )
    {
      case OT_DEREF   : name = "*"; break;
      case OT_ADDR    : name = "&"; break;
      case OT_UPLUS   : name = "+"; break;
      case OT_UMINUS  : name = "-"; break;
      case OT_NOT     : name = "!"; break;
      case OT_BIT_NOT : name = "~"; break;
    }

    if ( uo->mOperand )
    {
      if ( cLiteral *cl = dynamic_cast<cLiteral*>( uo->mOperand ) )
      {
        name += cl->mValue;
      }
    }
  }
  //END

  cLiteral *literal = STATE->cLiteralCreate( getCurrentFilename(), 
                                             getCurrentLine(),
                                             getCurrentLine(),
                                             name
                                           );

  literal->mType = STATE->cBuiltInTypeCreate( "", 
                                               getCurrentLine(),
                                               getCurrentLine(),
                                               "int",
                                               VB_UNKNOWN,
                                               0,
                                               new BasicType( BasicType::BT_INT )
                                             );

  return literal;
}

/// A.9.002 | A.9.003
BaseClassList_t* Actions::base_specifier_list ( BaseClassPair_t *bclass, BaseClassList_t *inh )
{
  PDEBUG;

  if ( inh )
  {
    inh->push_back( key::safe_deref( bclass ) );

    return inh;
  }

  return new BaseClassList_t( 1, key::safe_deref( bclass ) );
}

/// A.9.004 | A.9.005 | A.9.006
BaseClassPair_t* Actions::base_specifier ( cNameReference *nns_opt, cNameReference *decl, eAccessSpecifier vis, bool is_virt )
{
  PDEBUG;

  decl->mNamedNamespace = nns_opt;
  facade->installBaseClass( decl->mNameDeclaration, getAccess(vis) );

  return new BaseClassPair_t( decl, std::pair<eAccessSpecifier, bool>( vis, is_virt ) );
}

/// A.10.001
cNameReference* Actions::conversion_function_id ( int line, cType *type )
{
  PDEBUG;

  NameDeclaration *decl;
  string str( " " + type->mName );

  if ( cPointerType *pt = dynamic_cast<cPointerType*>( type ) )
  {
    str += "*";
  }
  else if ( cReferenceType *pt = dynamic_cast<cReferenceType*>( type ) )
  {
    str += "&";
  }

  decl = facade->makeOperator( &(str), line );

  cNameReference *to_return = STATE->cNameReferenceCreate( getCurrentFilename(), 
                                                           getStartLine( type ),
                                                           getCurrentLine(),
                                                           decl->getName(),
                                                           decl,
                                                           0,
                                                           0
                                                         );
  to_return->mOperatorType = type;

  return to_return;
}

/// A.10.002
cType* Actions::conversion_type_id ( cType *lhs, cType *rhs )
{
  PDEBUG;

  // Dammit Tanton.
  // 12.3.2.4 states:
  // conversion_type_id (the return value of this function aka lhs) shall not
  // represent a function type nor an array type

  if ( rhs )
  {
    if ( cPointerType *ptr = dynamic_cast<cPointerType *>( rhs ) )
    { // XXX
      lhs = STATE->cPointerTypeCreate( getCurrentFilename(), 
                                   getStartLine( lhs ),
                                   getCurrentLine(),
                                   lhs->mName,
                                   //lhs->mAccessSpecifier,
                                   VB_UNKNOWN,
                                   lhs->mNameDeclaration,
                                   new IndirectType( lhs->mNameDeclaration,
                                                     getKeyType( lhs ),
                                                     IndirectType::IT_POINTER
                                                   ),
                                   lhs
                                 );
    }

    if ( cReferenceType *ptr = dynamic_cast<cReferenceType *>( rhs ) )
    { // XXX
      lhs = STATE->cReferenceTypeCreate( getCurrentFilename(), 
                                   getStartLine( lhs ),
                                   getCurrentLine(),
                                   lhs->mName,
                                   //lhs->mAccessSpecifier,
                                   VB_UNKNOWN,
                                   lhs->mNameDeclaration,
                                   new IndirectType( lhs->mNameDeclaration,
                                                     getKeyType( lhs ),
                                                     IndirectType::IT_REFERENCE
                                                   ),
                                   lhs
                                 );
    }

    #if 0
    else if ( cFunctionType *ft = dynamic_cast<cFunctionType *>( rhs ) )
    {// This should be a fatal error.
    }
    else if ( cArrayType *at = dynamic_cast<cArrayType *>( rhs ) )
    {// This should be a fatal error.
    }
    #endif
  }

  return lhs; 
}

/// A.10.003
cType* Actions::conversion_declarator ( int ptrop, cType *cdopt )
{
  PDEBUG;

  if ( isPtr( ptrop ) )
  {
    cPointerType *ptr = STATE->cPointerTypeCreate( getCurrentFilename(), 
                                           getCurrentLine(),
                                           getCurrentLine(),
                                           "",
                                           VB_UNKNOWN,
                                           0,
                                           0,
                                           cdopt
                                         );
    makeCV( ptr, ptrop );

    return ptr;
  }
  else
  {
    return STATE->cReferenceTypeCreate( getCurrentFilename(), 
                                  getCurrentLine(),
                                  getCurrentLine(),
                                  "",
                                  VB_UNKNOWN,
                                  0,
                                  0,
                                  cdopt
                                );
  }
}

/// A.10.004
cBlock* Actions::ctor_initializer ( AsgNodeList_t *conts )
{
  PDEBUG;

  AsgNodeList_t *contsList = key::collapseContainedObjectLists( conts );

  for ( AsgNodeList_t::iterator ptr = contsList->begin();
        ptr != contsList->end();
        ++ptr
      )
  {
    if ( cOperator *op = dynamic_cast<cOperator*>( *ptr ) )
    {
      op->mOperator = OT_MEM_INIT;
    }
  }

  cBlock *block = STATE->cCtorInitializerBlockCreate( getCurrentFilename(), 
                                                      getCurrentLine(),
                                                      getCurrentLine(),
                                                      "",
                                                      VB_UNKNOWN,
                                                      0,
                                                      key::safe_deref( contsList )
                                                    );

  delete conts;

  return block;
}

/// A.10.005 | A.10.006
AsgNodeList_t* Actions::mem_initializer_list ( cAsgNode *node, AsgNodeList_t *conts )
{
  PDEBUG;

  if ( conts )
  {
    conts->insert( conts->begin(), node );

    return conts;
  }

  return new AsgNodeList_t( 1, node );
}

/// A.10.007
cExpression* Actions::mem_initializer ( cNameReference *decl, cFunctionArgumentList *exp )
{
  PDEBUG;

  return STATE->cBinaryOperatorCreate( getCurrentFilename(), 
                                       getCurrentLine(),
                                       getCurrentLine(),
                                       OT_FCT_CALL,
                                       decl,
                                       exp
                                     );
}

/// A.10.009
cNameReference* Actions::mem_initializer_id ( NameDeclaration *decl )
{
  return STATE->cNameReferenceCreate( getCurrentFilename(), 
                                      getCurrentLine(),
                                      getCurrentLine(),
                                      decl->getName(),
                                      decl,
                                      0,
                                      0
                                    );
}

/// A.12.001
void Actions::template_declaration_1 ( void )
{
  PDEBUG;

  facade->moveIntoTemplateParameterScope();
}

/// A.12.001
void Actions::template_declaration_leave_scope ( void )
{
  PDEBUG;

  facade->leaveCurrentScope();
}

/// A.12.001
cAsgNode* Actions::template_declaration_2 ( int export_opt, cTemplateParameterList *parms, cAsgNode *decl )
{
  PDEBUG;

  cAsgNode *to_change = decl;

  if ( cObjectList *obj = dynamic_cast<cObjectList *>( decl ) )
  {
    if ( obj->mObjects.size() )
    {
      to_change = obj->mObjects.front(); 
    }
  }

  if ( cIdentifier *id = dynamic_cast<cIdentifier *>( to_change ) )
  {
    id->mNameDeclaration->setIsTemplate( true );

	  // TEMPLATE PARMS
	  if ( cClassTypeInterface *cti = dynamic_cast<cClassTypeInterface *>( to_change ) )
	  {
		  if ( parms && parms->mParameters.size() )
		  {
        cSpecializedClassType *sct = dynamic_cast<cSpecializedClassType *>( cti );
        if ( ! sct )
        {
          cTemplateClassType *tct = STATE->cTemplateClassTypeCreate( cti->mFilename,
                                                                     cti->mStartLine,
                                                                     cti->mEndLine,
                                                                     cti->mName,
                                                                     cti->mAccessSpecifier,
                                                                     cti->mNameDeclaration,
                                                                     cti->mBaseClasses,
                                                                     cti->mFriends,
                                                                     cti->mMembers,
                                                                     cti->mClassKey,
                                                      STATE->cTemplateParameterListCreate( getCurrentFilename(),
                                                                                           getCurrentLine(),
                                                                                           getCurrentLine(),
                                                                                           "",
                                                                                           VB_UNKNOWN,
                                                                                           0,
                                                                                           parms->mParameters
                                                                                         )
                                                                  );
          
          for ( MemberList_t::iterator it = tct->mMembers.begin();
                it != tct->mMembers.end();
                ++it
              )
          {
            if ( cIdentifier *ci = dynamic_cast<cIdentifier*>( *it ) )
            {
              /// Add parent pointers to class members
              /// cTemplateClassType only
              ci->mDefinedIn = tct;
            }
          }

		      decl = tct;
        }
        else
        {
          sct->mTemplateParameters = parms; //->mTemplateParameters;
        }
      }
    }

    else if ( cForwardTypeInterface *fti = dynamic_cast<cForwardTypeInterface *>( to_change ) )
    {
		  if ( parms && parms->mParameters.size() )
		  {
        cSpecializedForwardType *sft = 0;

        if ( cInstantiatedForwardType *ift = dynamic_cast<cInstantiatedForwardType *>( fti ) )
        {
          sft = STATE->cSpecializedForwardTypeCreate( ift->mFilename,
                                                     ift->mStartLine,
                                                     ift->mEndLine,
                                                     ift->mName,
                                                     ift->mAccessSpecifier,
                                                     ift->mNameDeclaration,
                                                     ift->mNamedNamespace,
                                                     ift->mTemplateArguments
                                                   );
        }
        else
        {
          sft = dynamic_cast<cSpecializedForwardType *>( fti );
        }

        if ( ! sft )
        {
          cTemplateForwardType *tft = STATE->cTemplateForwardTypeCreate( fti->mFilename,
                                                                         fti->mStartLine,
                                                                         fti->mEndLine,
                                                                         fti->mName,
                                                                         fti->mAccessSpecifier,
                                                                         fti->mNameDeclaration,
                                                                         fti->mNamedNamespace,
                                                      STATE->cTemplateParameterListCreate( getCurrentFilename(),
                                                                                           getCurrentLine(),
                                                                                           getCurrentLine(),
                                                                                           "",
                                                                                           VB_UNKNOWN,
                                                                                           0,
                                                                                           parms->mParameters
                                                                                         )
                                                                       );
		      decl = tft;
        }
        else
        {
          sft->mTemplateParameters = parms; //->mTemplateParameters;
          decl = sft;
        } 
      }
    }

    else if ( cFunctionInterface *fun = dynamic_cast<cFunctionInterface *>( to_change ) )
    {
		  if ( parms && parms->mParameters.size() )
		  {
        fun->mNameDeclaration->setIsTemplate( true );
        cSpecializedFunction *sf = dynamic_cast<cSpecializedFunction *>( fun );

        if ( ! sf )
        {
          cTemplateFunction *tf = STATE->cTemplateFunctionCreate( fun->mFilename,
                                                      fun->mStartLine,
                                                      fun->mEndLine,
                                                      fun->mName,
                                                      fun->mAccessSpecifier,
                                                      fun->mNameDeclaration,
                                                      fun->mFunctionKey,
                                                      fun->mIsPureVirtual,
                                                      fun->mNamedNamespace,
                                                      fun->mType,
                                                      fun->mThrows,
                                                      fun->mInit,
                                                      fun->mBlock,
                                                      STATE->cTemplateParameterListCreate( getCurrentFilename(),
                                                                                           getCurrentLine(),
                                                                                           getCurrentLine(),
                                                                                           "",
                                                                                           VB_UNKNOWN,
                                                                                           0,
                                                                                           parms->mParameters
                                                                                         )
                                                    );
          tf->mIsStatic = fun->mIsStatic;
          tf->mIsExtern = fun->mIsExtern;
          tf->mIsInline = fun->mIsInline;
          tf->mIsVirtual = fun->mIsVirtual;
          tf->mIsExplicit = fun->mIsExplicit;

		      decl = tf;
        }
        else
        {
          sf->mTemplateParameters = parms; //->mTemplateParameters;
          decl = sf;
        } 
      }
    }
  }

  decorator->restoreId();

  return decl;
}

/// A.12.002 | A.12.003
cTemplateParameterList* Actions::template_parameter_list ( cTemplateParameter *parm, cTemplateParameterList *tlist )
{
  PDEBUG;

  if ( tlist )
  {
    tlist->mParameters.push_back( parm );

    return tlist;
  }

  return STATE->cTemplateParameterListCreate( getCurrentFilename(),
                                              getCurrentLine(),
                                              getCurrentLine(),
                                              "",
                                              VB_UNKNOWN,
                                              0,
                                              TemplateParameterList_t( 1, parm )
                                            );
}

/// A.12.005
cTemplateParameter* Actions::template_parameter ( cFunctionParameter *ffp )
{
  PDEBUG;

  declStack->pop();

  cNonTypeTemplateParameter *nttp = 0;
  nttp = STATE->cNonTypeTemplateParameterCreate( ffp->mFilename,
                                                 ffp->mStartLine,
                                                 ffp->mEndLine,
                                                 ffp->mName,
                                                 ffp->mAccessSpecifier,
                                                 ffp->mNameDeclaration,
                                                 ffp->mIsAuto,
                                                 ffp->mIsRegister,
                                                 ffp->mType,
                                                 ffp->mTemplateArguments,
                                                 ffp->mNamedNamespace,
                                                 ffp->mDefault
                                               );
  
  return nttp;
}

/// A.12.006 | A.12.007 | A.12.008 | A.12.009
cTemplateParameter* Actions::type_parameter ( int line, NameDeclaration *decl, cType *def )
{
  PDEBUG;

  decl = checkAnon( decl, line );
  Type *tmp = new TemplateParameterType( decl );
  decl = facade->insertLocal( decl, tmp );

  return STATE->cTypeTemplateParameterCreate( getCurrentFilename(), 
                                            decl->getLinenum(),
                                            decl->getLinenum(),
                                            decl->getName(),
                                            VB_UNKNOWN,
                                            decl,
                                            def
                                          );
}

/// A.12.010 | A.12.011 | A.12.012
cTemplateParameter* Actions::type_parameter_template ( int line, NameDeclaration *decl, cTemplateParameterList *parmlist, cNameReference *deftype )
{
  PDEBUG;

  decl = checkAnon( decl, line );
  Type *tmp = new TemplateTemplateParameterType( decl );
  decl = facade->insertLocal( decl, tmp );

  return STATE->cTemplateTemplateParameterCreate( getCurrentFilename(), 
                                             decl->getLinenum(),
                                             decl->getLinenum(),
                                             decl->getName(),
                                             VB_UNKNOWN,
                                             decl,
                                             parmlist,
                                             deftype
                                           );
}

/// A.12.012
cNameReference* Actions::template_id ( NameDeclaration *decl, TemplateArgumentList_t *args )
{
  // instantiate decl with args
  cNameReference *to_return = STATE->cNameReferenceCreate( getCurrentFilename(), 
                                               getCurrentLine(),
                                               getCurrentLine(),
                                               decl->getName(),
                                               decl,
                                               ( args && args->size()
                                                 ? STATE->cTemplateArgumentListCreate( getCurrentFilename(),
                                                                                              getCurrentLine(),
                                                                                              getCurrentLine(),
                                                                                              *args
                                                                                            )
                                                 : 0
                                               ),
                                               0
                                             );

  return to_return;
}

/// A.12.013 | A.12.014
TemplateArgumentList_t* Actions::template_argument_list( cAsgNode *arg, TemplateArgumentList_t *tlist )
{
  if ( tlist )
  {
    tlist->push_back( arg );

    return tlist;
  }

  return new TemplateArgumentList_t( 1, arg );
}

/// A.12.019
cAsgNode* Actions::explicit_specialization ( cAsgNode *node )
{
   if ( cObjectList *ol = dynamic_cast<cObjectList*>( node ) )
   {
     if ( cInstantiatedForwardType *ift = dynamic_cast<cInstantiatedForwardType*>( ol->mObjects.front() ) )
     {
       cSpecializedForwardType *sft = STATE->cSpecializedForwardTypeCreate( ift->mFilename,
                                                                                  ift->mStartLine,
                                                                                  ift->mEndLine,
                                                                                  ift->mName,
                                                                                  ift->mAccessSpecifier,
                                                                                  ift->mNameDeclaration,
                                                                                  ift->mNamedNamespace,
                                                                                  ift->mTemplateArguments
                                                                                );
       ol->mObjects.erase( ol->mObjects.begin() );
       ol->mObjects.insert( ol->mObjects.begin(), sft );
     }
   }

  return node;
}

/// A.13.001
/// \param stmt is guaranteed to be a cBlock*
cAsgNode* Actions::try_block ( cAsgNode *stmt, HandlerList_t *handlers )
{
  PDEBUG;

  cBlock *block = static_cast<cBlock *>( stmt );

  cTryBlock *tryBlock = STATE->cTryBlockCreate( block->mFilename,
                                                block->mStartLine,
                                                block->mEndLine,
                                                block->mName,
                                                block->mAccessSpecifier,
                                                block->mNameDeclaration,
                                                block->mContents,
                                                key::safe_deref( handlers )
                                              );

  return tryBlock;
}

/// A.13.002
/// \param stmt is guaranteed to be a cBlock*
cBlock* Actions::function_try_block ( cBlock *init, cAsgNode *stmt, HandlerList_t *handlers )
{
  PDEBUG;

  cBlock *block = static_cast<cBlock *>( stmt );

  cCtorInitializerBlock *ctor = static_cast<cCtorInitializerBlock*>( init );

  cFunctionTryBlock *ftb = STATE->cFunctionTryBlockCreate( block->mFilename,
                                                           block->mStartLine,
                                                           block->mEndLine,
                                                           block->mName,
                                                           block->mAccessSpecifier,
                                                           block->mNameDeclaration,
                                                           block->mContents,
                                                           key::safe_deref( handlers ),
                                                           ctor
                                                         );

  return ftb;
}

/// A.13.003
HandlerList_t* Actions::handler_seq ( cHandler *cblock, HandlerList_t *blocks )
{
  PDEBUG;

  if ( blocks )
  {
    blocks->insert( blocks->begin(), cblock );

    return blocks;
  }

  return new HandlerList_t( 1, cblock );
}

/// A.13.004
/// \param node is guaranteed to be a cBlock*
cHandler* Actions::handler ( cExceptionDeclaration *parm, cAsgNode *node )
{
  PDEBUG;

  return STATE->cHandlerCreate( getCurrentFilename(),
                                   getCurrentLine(),
                                   getCurrentLine(),
                                   parm,
                                   static_cast<cBlock *>( node )
                                 );
}

/// A.13.005
cExceptionDeclaration* Actions::exception_declaration_named ( cType *tss, cAsgNode *decl )
{
  PDEBUG;

  while ( ! declStack->empty() )
  {
    declStack->pop();
  }

  // NAK
  MAKE_ASSERTION( decl, "exception_declaration_named was passed a NULL declaration" );

  cObject *ed = static_cast<cObject *>( decl );

  // NAK - tss holds the type and its qualifier, decl would know about a pointer or reference
  if ( ed->mType )
  {
    setType( ed, applyType( ed->mType, tss ) );
  }
  else
  {
    setType( ed, tss );
  }
  // END

  cExceptionDeclaration *to_return = STATE->cExceptionDeclarationCreate( getCurrentFilename(), 
                                                                         getStartLine( tss ),
                                                                         getEndLine( decl ),
                                                                         ed->mName,
                                                                         VB_UNKNOWN,
                                                                         ed->mNameDeclaration,
                                                                         ed->mType,
                                                                         ed->mNamedNamespace,
                                                                         ed->mTemplateArguments
                                                                       );

  return to_return;
}

/// A.13.006 | A.13.007
cExceptionDeclaration* Actions::exception_declaration_unnamed ( cType *type, cType *ad )
{
  PDEBUG;

  NameDeclaration *tmp = 0;
  tmp = checkAnonParm( 0, line_num_for_abs_decl, declStack->size() );

  if ( seen_const )
  {
    facade->makeConst( tmp );
    seen_const = false;
  }

  tmp = facade->insertLocal( tmp, declStack->top(), true );

  while ( ! declStack->empty() )
  {
    declStack->pop();
  }
  tmp->setInstance( true );

  // Must apply type to ad to get ptr or ref
  return STATE->cExceptionDeclarationCreate( getCurrentFilename(), 
                                             getStartLine( type ),
                                             getEndLine( ad ),
                                             tmp->getName(),
                                             VB_UNKNOWN,
                                             tmp,
                                             applyType( ad, type ),
                                             0,
                                             0
                                           );
}

/// A.13.008
cExceptionDeclaration* Actions::exception_declaration_ellipses ( void )
{
  PDEBUG;

  return STATE->cExceptionDeclarationCreate( getCurrentFilename(),
                                             getCurrentLine(),
                                             getCurrentLine(),
                                             "...",
                                             VB_UNKNOWN,
                                             0,
                                             0,
                                             0,
                                             0
                                           );
}

/// A.13.009
cThrowExpression* Actions::throw_expression ( cExpression *what )
{
  PDEBUG;

  return STATE->cThrowExpressionCreate( getCurrentFilename(), 
                                        getStartLine( what ),
                                        getEndLine( what ),
                                        what
                                      );
}

/// A.13.010
cExceptionSpecification* Actions::exception_specification ( ThrowList_t *types )
{
  PDEBUG;

  cExceptionSpecification *to_return = STATE->cExceptionSpecificationCreate( getCurrentFilename(), 
                                                   getCurrentLine(),
                                                   getCurrentLine(),
                                                   key::safe_deref( types )
                                                 );
  delete types;

  return to_return;
}

/// A.13.011 | A.13.012
ThrowList_t* Actions::type_id_list ( cType *type, ThrowList_t *throws )
{
  PDEBUG;

  if ( throws )
  {
    throws->push_back( type );

    return throws;
  }

  return new ThrowList_t( 1, type );
}

/// K.2.001 | K.2.002
cNameReference* Actions::any_id_expression ( NameDeclaration *decl )
{
  PDEBUG;

  return STATE->cNameReferenceCreate( getCurrentFilename(), 
                                getCurrentLine(),
                                getCurrentLine(),
                                decl->getName(),
                                decl,
                                0,
                                0
                              );
}

//------------------------------------------------------------------------------
// Private Methods
//------------------------------------------------------------------------------

NameDeclaration* Actions::checkUnaryOp ( int op, NameDeclaration *d )
{
  string s = makeOperatorName( op );

  return ( facade->lookupUnaryOp( &s, d ) );
}

//------------------------------------------------------------------------------

NameDeclaration* Actions::checkBinOp ( int op, NameDeclaration *d1, NameDeclaration *d2 )
{
  string s = makeOperatorName( op );

  return ( facade->lookupBinOp( &s, d1, d2 ) );
}

//------------------------------------------------------------------------------

NameDeclaration* Actions::checkAnon ( NameDeclaration *decl, int line )
{
  if ( decl == 0 )
  {
    return ( facade->makeAnonIdent( line, 0 ) );
  }

  return decl;
}

//------------------------------------------------------------------------------

NameDeclaration* Actions::checkAnonParm ( NameDeclaration *decl, int line, int parm_num )
{
  if( decl == 0 )
  {
    return ( facade->makeAnonParmIdent( line, 0, parm_num ) );
  }

  return decl;
}

//------------------------------------------------------------------------------

NameDeclaration* Actions::checkAnonNS ( NameDeclaration *decl, int line )
{
  if ( decl == 0 )
  {
    return ( facade->makeAnonNSIdent( line, 0 ) ); 
  }

  return decl;
}

//------------------------------------------------------------------------------

cType* Actions::declaredType ( cType *type, bool others )
{
  if( !type )
  {
    return 0;
  }

  if ( type->isA( cClassTypeInterface_kind )  ||
       type->isA( cInstantiatedClassType_kind )  ||
       type->isA( cEnumerationType_kind )  ||
       type->isA( cAliasType_kind ) ||
       ( !others &&
          type->isA( cForwardTypeInterface_kind )
       )
     )
  {
    return type;
  }

  return 0;
}

//------------------------------------------------------------------------------

bool Actions::hasDeclSpec ( DeclSpecifierList_t *dsl, eDeclSpecifier dst )
{
  if ( !dsl )
  {
    return false;
  }

  for ( DeclSpecifierList_t::iterator it = dsl->begin();
        it != dsl->end();
        ++it
      )
  {
    if ( (*it)->first == dst )
    {
      return true;
    }
  }

  return false;
}

//------------------------------------------------------------------------------

bool Actions::isPtr ( int ptrop )
{
  if ( ( ptrop >= 10 ) && ( ptrop < 20 ) )
  {
    return true;
  }

  return false;
}

//------------------------------------------------------------------------------

bool Actions::isRef ( int ptrop )
{
  if ( ptrop >= 20 )
  {
    return true;
  }

  return false;
}

//------------------------------------------------------------------------------

cType* Actions::findType ( DeclSpecifierList_t *dsl )
{
  if( !dsl )
  {
    return 0;
  }

  for ( DeclSpecifierList_t::iterator it = dsl->begin();
        it != dsl->end();
        ++it
      )
  {
    if ( (*it)->first == DS_TYPE_SPECIFIER )
    {
      return (*it)->second;
    }
  }

  return 0;
}

//------------------------------------------------------------------------------

string Actions::getCurrentFilename ( void )
{
  return decorator->getCurrentFilename();
}

//------------------------------------------------------------------------------

int Actions::getCurrentLine ( void )
{
  return decorator->getCurrentLine();
}

//------------------------------------------------------------------------------

int Actions::getStartLine ( const cAsgNode *node )
{
  if ( node )
  {
    return node->mStartLine;
  }

  return getCurrentLine();
}

//------------------------------------------------------------------------------

int Actions::getEndLine ( const cAsgNode *node )
{
  if ( node )
  {
    return node->mEndLine;
  }

  return getCurrentLine();
}

//------------------------------------------------------------------------------

Access::AccessType Actions::getAccess ( eAccessSpecifier v )
{
  Access::AccessType toReturn;

  switch ( v )
  {
    case VB_PRIVATE   : toReturn = Access::Private;   break;
    case VB_PROTECTED : toReturn = Access::Protected; break;
    case VB_PUBLIC    : toReturn = Access::Public;    break;
    default           : toReturn = Access::None;      break;
  }

  return toReturn;
}

//------------------------------------------------------------------------------

cNameReference* Actions::getNamedNamespace ( cIdentifier *n )
{

  if ( cNameReference *nr = dynamic_cast<cNameReference *>( n ) )
  {
    return nr->mNamedNamespace;
  }
  if ( cObject *obj = dynamic_cast<cObject *>( n ) )
  {
    return obj->mNamedNamespace;
  }
  if ( cFunctionInterface *fun = dynamic_cast<cFunctionInterface *>( n ) )
  {
    return fun->mNamedNamespace;
  }

  return 0;
}
//------------------------------------------------------------------------------

cType* Actions::getReturnType ( cIdentifier *n )
{
  if ( cFunctionInterface *fct = dynamic_cast<cFunctionInterface *>( n ) )
  {
    if ( fct->mType )
    {
      return fct->mType->mReturnType;
    }
  }

  return getType( n );
}

//------------------------------------------------------------------------------

void Actions::makeCV ( cType *n, int ptrOp )
{
  if ( !n )
  {
    return;
  }

  ptrOp %= 10;
  if ( ( ptrOp == 1 ) || ( ptrOp == 3 ) )
  {
    makeConst( n );
  }
  if ( ( ptrOp == 2 ) || ( ptrOp == 3 ) )
  {
    makeVolatile( n );
  }
}

//------------------------------------------------------------------------------

std::string Actions::makeOperatorName ( int op )
{
  switch( op )
  {
    case PLUS:       return std::string( "operator+");
    case MINUS:      return std::string( "operator-");
    case STAR:       return std::string( "operator*");
    case DIVIDE:     return std::string( "operator/" );
    case MOD:        return std::string( "operator%" );
    case GREATER:    return std::string( "operator>" );
    case LESS:       return std::string( "operator<" );
    case EQUAL:      return std::string( "operator=" );
    case AND:        return std::string( "operator&" );
    case OR:         return std::string( "operator|" );
    case NOT:        return std::string( "operator!" );
    case XOR:        return std::string( "operator^" );
    case COMMA:      return std::string( "operator," );
    case COMPLEMENT: return std::string( "operator~" );
    case PLUSEQ:     return std::string( "operator+=" );
    case MINUSEQ:    return std::string( "operator-=" );
    case STAREQ:     return std::string( "operator*=" );
    case DIVEQ:      return std::string( "operator/=" );
    case MODEQ:      return std::string( "operator%=" );
    case XOREQ:      return std::string( "operator^=" );
    case ANDEQ:      return std::string( "operator&=" );
    case OREQ:       return std::string( "operator|=" );
    case LTLT:       return std::string( "operator<<" );
    case GTGT:       return std::string( "operator>>" );
    case GTGTEQ:     return std::string( "operator>>=" );
    case LTLTEQ:     return std::string( "operator<<=" );
    case EQEQ:       return std::string( "operator==" );
    case NOTEQ:      return std::string( "operator!=" );
    case LEQ:        return std::string( "operator>=" );
    case ANDAND:     return std::string( "operator||" );
    case PLUSPLUS:   return std::string( "operator++" );
    case MINUSMINUS: return std::string( "operator--" );
    case ARROW:      return std::string( "operator->" );
  }
  return std::string("");
}

//------------------------------------------------------------------------------

void Actions::setType ( cIdentifier *lhs, cType *rhs )
{
  lhs->setType( rhs );
}

//------------------------------------------------------------------------------

void Actions::applyKeyType ( Type *lhs, Type *rhs )
{
  if ( IndirectType *it = dynamic_cast<IndirectType *>( lhs ) )
  {
    if ( it->getReferencedType() )
    {
      applyKeyType( it->getReferencedType(), rhs );
    }
    else
    {
      it->setReferencedType( rhs );
    }
  }
  if ( FunctionType *ft = dynamic_cast<FunctionType *>( lhs ) )
  {
    if ( ft->getReturnType() )
    {
      applyKeyType( ft->getReturnType(), rhs );
    }
    else
    {
      ft->setReturnType( rhs );
    }
  }
}

//------------------------------------------------------------------------------

cType* Actions::applyType ( cType *lhs, cType *rhs )
{
  if ( cPointerType *pt = dynamic_cast<cPointerType *>( lhs ) )
  {
    if ( pt->mBaseType ) { applyType( pt->mBaseType, rhs ); }
    else                   { pt->mBaseType = rhs; }
  }
  else if ( cReferenceType *rt = dynamic_cast<cReferenceType *>( lhs ) )
  {
    if ( rt->mBaseType ) { applyType( rt->mBaseType, rhs ); }
    else                  { rt->mBaseType = rhs; }
  }
  else if ( cArrayType *at = dynamic_cast<cArrayType *>( lhs ) )
  {
    if ( at->mBaseType ) { applyType( at->mBaseType, rhs ); }
    else              { at->mBaseType = rhs; }
  }
  else if ( cFunctionType *ft = dynamic_cast<cFunctionType *>( lhs ) )
  {
    if ( ft->mReturnType ) { applyType( ft->mReturnType, rhs ); }
    else               { ft->mReturnType = rhs; }
  }
  else if ( cFunctionTypeInformation *ft = dynamic_cast<cFunctionTypeInformation *>( lhs ) )
  {
    if ( ft->mReturnType ) { applyType( ft->mReturnType, rhs ); }
    else                     { ft->mReturnType = rhs; }
  }
  else if ( cAliasType *at = dynamic_cast<cAliasType *>( lhs ) )
  {
    if ( at->mAliasedType ) { applyType( at->mAliasedType, rhs ); }
    else                      { at->mAliasedType = rhs; }
  }

  return lhs;
}

//------------------------------------------------------------------------------

cType* Actions::maskType ( cType *type )
{
  if ( !type )                            { return 0; }
  if ( type->isA( cPointerType_kind ) )   { return type; }
  if ( type->isA( cReferenceType_kind ) ) { return type; }
  if ( type->isA( cArrayType_kind ) )     { return type; }
  if ( type->isA( cFunctionType_kind ) )  { return type; }
  if ( type->isA( cFunctionTypeInformation_kind ) )  { return type; }
  if ( type->isA( cAliasType_kind ) )     { return type; }

  return 0;
}

//------------------------------------------------------------------------------

void Actions::updateType ( cType *n, DeclSpecifierList_t *l )
{
  if ( hasDeclSpec( l, DS_VOLATILE ) )
  {
    makeVolatile( n );
  }
  if ( hasDeclSpec( l, DS_CONST ) )
  {
    makeConst( n );
  }
}

//------------------------------------------------------------------------------

cType* Actions::createLiteralType ( eLiteralType lt )
{
  cType *type = 0;

  switch ( lt )
  {
    case LT_INT:
      type = STATE->cBuiltInTypeCreate( "",
                                        getCurrentLine(),
                                        getCurrentLine(),
                                        "int",
                                        VB_UNKNOWN,
                                        0,
                                        new BasicType( BasicType::BT_INT )
                                      ); 
    break;

    case LT_REAL:
      type = STATE->cBuiltInTypeCreate( "",
                                        getCurrentLine(),
                                        getCurrentLine(),
                                        "float",
                                        VB_UNKNOWN,
                                        0,
                                        new BasicType( BasicType::BT_FLOAT )
                                      ); 
    break;

    case LT_STR:
      type = STATE->cPointerTypeCreate( getCurrentFilename(), 
                                        getCurrentLine(),
                                        getCurrentLine(),
                                        "",
                                        VB_UNKNOWN,
                                        0,
                                        0,
                                        STATE->cBuiltInTypeCreate( "",
                                                                   getCurrentLine(),
                                                                   getCurrentLine(),
                                                                   "char",
                                                                   VB_UNKNOWN,
                                                                   0,
                                                                   new BasicType( BasicType::BT_CHAR )
                                                                 )
                                      );
    break;

    case LT_CHAR:
      type = STATE->cBuiltInTypeCreate( "",
                                        getCurrentLine(),
                                        getCurrentLine(),
                                        "char",
                                        VB_UNKNOWN,
                                        0,
                                        new BasicType( BasicType::BT_CHAR )
                                      ); 
    break;

    case LT_BOOL:
      type = STATE->cBuiltInTypeCreate( "",
                                        getCurrentLine(),
                                        getCurrentLine(),
                                        "bool",
                                        VB_UNKNOWN,
                                        0,
                                        new BasicType( BasicType::BT_BOOL )
                                      ); 
    break;

    case LT_MEM:
      type = STATE->cBuiltInTypeCreate( "",
                                        getCurrentLine(),
                                        getCurrentLine(),
                                        "unsigned long",
                                        VB_UNKNOWN,
                                        0,
                                        new BasicType( BasicType::BT_ULONG )
                                      ); 
    break;
  }

  // ???
  if ( lt != LT_STR )
  {
    type->mIsConst = true;
  }
  else
  {
    static_cast<cPointerType *>( type )->mBaseType->mIsConst = true;
  }
  // ???

  return type;
}

//------------------------------------------------------------------------------




