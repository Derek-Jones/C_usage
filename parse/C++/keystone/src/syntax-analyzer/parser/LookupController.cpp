//******************************************************************************
//
//  LookupController.cpp
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

#include <set>
#include <vector>

#include "Assertion.h"
#include "Sentry.h"

#include "ContextManager.h"
#include "NameOccurrence.h"

#include "NameDeclaration.h"
#include "Scope.h"
#include "ClassScope.h"
#include "TemplateParameterScope.h"
#include "Type.h"
#include "FunctionType.h"

#include "LookupController.h"

using std::vector;
using std::set;
using std::string;

//------------------------------------------------------------------------------

LookupController::LookupController ( ContextManager *contextMan )
                 : contextManager   ( contextMan ),
                   additional_scope ( 0 )
{ }

//------------------------------------------------------------------------------

NameDeclaration* LookupController::lookupUnqualifiedName ( NameOccurrence *occur ) const
{
  P_SENTRY;

  Scope::scope_searched_set.clear();

  NameDeclaration *decl = contextManager->getCurrentScope()->lookup( occur );

  if ( !decl && contextManager->getCurrentTemplateScope( false ) )
  {
    decl = contextManager->getCurrentTemplateScope( false )->lookup( occur );
  }
  if( !decl && additional_scope )
  {
    decl = additional_scope->lookup( occur );
  }

  return ( decl );
}
//------------------------------------------------------------------------------

//#include "Parser.h"
//#include "ActionFacade.h"
NameDeclaration* LookupController::lookupQualifiedName ( NameOccurrence *occur ) const
{
  P_SENTRY;

  Scope::scope_searched_set.clear();
  NameDeclaration *qual = occur->getQualifier();

  MAKE_ASSERTION( qual != 0, "lookupQualifiedName called with a NULL qualifier." );

  if ( qual->getType() &&
       ( qual->getType()->checkType( Type::DT_TEMPLATE_PARM ) ||
         qual->getType()->checkType( Type::DT_TEMPLATE_TEMPLATE_PARM )
       )
     )
  {
    return ( 0 );
  }
  Scope *scope = qual->getCorrespondingScope();

  // NAK
  // This is close, but the getCurrentTemplateScope call cannot come until after the
  // end of the statement/block.
  // For now, searching scopes backwards in ContextManager - this works because the
  //  current template scope is not exited properly on all paths
  #if 0
  if ( scope )
  {
    if ( ClassScope *cscope = dynamic_cast<ClassScope*>(scope) )
    {
      if ( cscope->isTemplate() )
      {
        contextManager->getCurrentTemplateScope();
      }
    }
  }
  #endif
  // END

  if ( scope == 0 )
  {
  //Parser::Instance()->facade()->printClassesAndNamespaces();
    if ( qual->getType() && qual->getType()->getDecl() )
    {
      scope = qual->getType()->getDecl()->getCorrespondingScope();
    }
  }

  MAKE_ASSERTION( scope != 0, "lookupQualifiedName called with a decl without a scope." );
  //if ( scope )
  //{
  /// KLUDGE: easy going here to slide the following through:
     // typedef typename __STD::iterator_traits<_Iter>::value_type value_type;
  NameDeclaration *decl = scope->lookup( occur );
  return ( decl );

  //}
  //else
  //{
    //return 0;
  //}
}

//------------------------------------------------------------------------------

ClassScope* LookupController::getClassScope ( NameDeclaration *aggr ) const
{
  // Get the class corresponding to aggr
  P_SENTRY;

  ClassScope *c_scope = 0;
  Type *a_type = aggr->getType();

  if ( a_type == 0 )
    return ( 0 );
  
  NameDeclaration *the_class = ( a_type->getDecl() ? a_type->getDecl() : aggr );

  // THG - If the expression was a function, use the return type as the lookup type
  if ( a_type->checkType (Type::DT_FUNCTION ) )
  {
    FunctionType *ft = dynamic_cast<FunctionType *>(a_type);
    a_type = ft->getReturnType();
    the_class = a_type->getDecl();
  }
   
  // THG - changed to find class scope in chained member calls (i.e. x.y().z())
  if ( the_class != 0 )
  {
    Scope *scope = the_class->getCorrespondingScope();
    while ( ( c_scope = dynamic_cast<ClassScope *>( scope ) ) == 0 )
    {
      if ( scope == 0 )
        break;
      scope = scope->getContainingScope();
    }
  }

  return ( c_scope );
}

//------------------------------------------------------------------------------

NameDeclaration* LookupController::redoMemberLookup ( ClassScope *c_scope, NameDeclaration *memb ) const
{
  P_SENTRY;

  Scope::scope_searched_set.clear();

  // Assume memb has been looked up in the context of postfix expresion
  // Now look it up as a member of aggr
  MAKE_ASSERTION( memb->getOccurQual() != 0, "redoMemberLookup called with a member that is not qualified." );

  NameDeclaration *decl = memb;
  // First store the qualifers in a vector
  vector<NameDeclaration *> quals;
  for ( NameDeclaration *tmp = memb->getOccurQual();
        tmp != 0;
        tmp = tmp->getOccurQual()
      )
  {
    quals.push_back( tmp );
  }

  int first_qual = quals.size() - 1;  // They're backwards!

  // If the first wasn't found, redo all the others
  if ( ! quals[first_qual]->isInSymbolTable() )
  {
    Scope *tscope = c_scope;
    for ( int i = first_qual; i >= 0; i-- )
    {
      NameOccurrence occur( quals[i] );

      if ( i != first_qual )
        occur.setQualifier( decl );

      decl = tscope->lookup( &occur );

      if ( decl == 0 )
        return ( 0 );

      tscope = decl->getCorrespondingScope();

      if ( tscope == 0 )
        return ( 0 );
    }//for

    // now decl is the last qualifier (may be different from quals[0])
    // and tscope is its corresponding scope
    NameOccurrence occur( memb );
    occur.setQualifier( decl );
    decl = tscope->lookup( &occur );
  }

  return ( decl );
}

//------------------------------------------------------------------------------

NameDeclaration* LookupController::lookupMemberName ( NameDeclaration *aggr, NameDeclaration *memb ) const
{
  P_SENTRY;

  Scope::scope_searched_set.clear();
  NameDeclaration *decl = memb;
  ClassScope *c_scope = getClassScope( aggr );

  if ( c_scope != 0 )
  {
    if ( memb->getOccurQual() == 0 )
    {
      NameOccurrence occur( memb );
      decl = c_scope->lookup( &occur );
    }
    else
    { // Qualified member access
      decl = redoMemberLookup( c_scope, memb );
    }
  }

  // THG - Added to make x.y().z() work right.
  if ( decl != 0 )
  {
    NameOccurrence occur( memb );
    decl->addReference( &occur );
  }

  // THG - Added to ensure correct type is preserved
  if ( memb->getType() == 0 )
  {
    memb->setType( decl->getType() );
  }
  return ( decl );
}

//------------------------------------------------------------------------------
// THG - Added code to lookup/create a destructor for class aggr

NameDeclaration* LookupController::lookupPseudoDestructor ( NameDeclaration *aggr, NameDeclaration *pdest) const
{
  P_SENTRY;

  Scope::scope_searched_set.clear();

  MAKE_ASSERTION( aggr  != 0, "lookupPseudoDestructor called with a NULL aggregate." );
  MAKE_ASSERTION( pdest != 0, "lookupPseudoDestructor called with a NULL pseudo destructor decl." );

  return ( pdest->getDestructor() );
}

//------------------------------------------------------------------------------
// THG - added for infix operator overloading

NameDeclaration* LookupController::lookupUnaryOp ( string *op, NameDeclaration *decl ) const
{
  P_SENTRY;

  Scope::scope_searched_set.clear();

  MAKE_ASSERTION( op != 0, "lookupUnaryOp called with a NULL operator string." );

  if ( decl == 0 )
    return ( 0 );

  NameDeclaration *n = 0;
  TokenInfo ti( *op, decl->getFileName(), decl->getLinenum(), decl->getColnum() );
  NameOccurrence occur( &ti );
  Type *t = decl->getType();

  // if it is a function, use the return type
  if( FunctionType *ft = dynamic_cast<FunctionType *>( t ) )
    t = ft->getReturnType();

  // overloading is not possible on basic types or namespaces
  if ( !t->checkType( Type::DT_BASIC ) &&
       !t->checkType( Type::DT_NAMESPACE )
     )
  {
    // overloading is possible...try current scope first
    n = lookupUnqualifiedName( &occur );

    if ( n == 0 )
    {
      // not found...try class scope
      ClassScope *c_scope = getClassScope( decl );
      if ( c_scope != 0 )
        n = c_scope->lookup( &occur );
    }
  }
  if ( n != 0 )
    n->addReference(&occur);

  return ( n );
}

//------------------------------------------------------------------------------

NameDeclaration* LookupController::lookupBinOp ( string          *op,
                                                 NameDeclaration *lhs,
                                                 NameDeclaration *rhs
                                               ) const
{
  P_SENTRY;

  Scope::scope_searched_set.clear();

  MAKE_ASSERTION( op != 0, "lookupBinOp called with a NULL operator string." );

  if ( lhs == 0 && rhs == 0 )
    return ( 0 );

  NameDeclaration *n = 0;
  string file = ( lhs ? lhs->getFileName() : rhs->getFileName() );
  int line = ( lhs ? lhs->getLinenum() : rhs->getLinenum() );
  int col  = ( lhs ? lhs->getColnum()  : rhs->getColnum() );
  TokenInfo ti( *op, file, line, col );
  NameOccurrence occur( &ti );

  if( lhs && lhs->getType() )
  {
    Type *t = lhs->getType();

    // If it is a function, use the return type
    if( FunctionType *ft = dynamic_cast<FunctionType *>( t ) ) 
      t = ft->getReturnType();

    // overloading is not possible on basic types or namespaces
    if ( !t->checkType( Type::DT_BASIC ) &&
         !t->checkType( Type::DT_NAMESPACE )
       )
    {
      // overloading is possible...try current scope first  
      n = lookupUnqualifiedName( &occur );
      if ( n == 0 )
      {
        // not found...try class scope
        ClassScope *c_scope = getClassScope( lhs );
        if ( c_scope != 0 )
          n = c_scope->lookup( &occur );
      }
    }
  }

  if ( rhs && rhs->getType() && !n )
  {
    Type *t = rhs->getType();

    // If it is a function, use the return type
    if( FunctionType *ft = dynamic_cast<FunctionType *>( t ) )
      t = ft->getReturnType();

    // overloading is not possible on basic types or namespaces
    if ( !t->checkType( Type::DT_BASIC ) &&
         !t->checkType( Type::DT_NAMESPACE )
       )
    {
      // overloading is possible...try global scope first  
      n = lookupUnqualifiedName( &occur );
      if ( n == 0 )
      {
        // not found...try class scope
        ClassScope *c_scope = getClassScope( rhs );
        if ( c_scope != 0 )
          n = c_scope->lookup( &occur );
      }
    }
  }

  if ( n != 0 )
    n->addReference( &occur );

  if ( !n )
    return lhs;

  return ( n );
}

//------------------------------------------------------------------------------

Scope* LookupController::getScopeForArg ( Type *argtype ) const
{
  P_SENTRY;

  NameDeclaration *tdecl = 0;
  while ( tdecl == 0 && argtype != 0 )
  {
    // Try for instance
    tdecl = argtype->getDecl();
    // Try for function return type
    if ( tdecl == 0 )
    {
      if ( FunctionType *ft = dynamic_cast<FunctionType *>( argtype ) )
      {
        argtype = ft->getReturnType();
      }
      else
      {
        break;
      }
    }
  }

  Scope *arg_scope = 0;
  if ( tdecl != 0 )
    arg_scope = tdecl->getCorrespondingScope();

  return ( arg_scope );
}

//------------------------------------------------------------------------------

NameDeclaration* LookupController::lookupFunctionCall ( NameDeclaration *decl, vector<NameDeclaration *> args) const
{
  P_SENTRY;

  Scope::scope_searched_set.clear();
  if ( decl->isInSymbolTable() &&
       decl->getType()         && 
       decl->getType()->checkType( Type::DT_FUNCTION )
     )
  {
    return ( decl );
  }  

  vector<Scope *> associated_scopes;
  // Collect the associated scopes
  unsigned int size = args.size();
  for ( unsigned int i = 0; i < size; i++)
  {
    Type *argtype = args[i]->getType();
    Scope *a_scope = getScopeForArg( argtype );
    if ( a_scope != 0 )
    {
      associated_scopes.push_back( a_scope );
    }
  }
   // Search the associated scopes
  NameDeclaration *fun = 0;
  NameOccurrence occur( decl );
  occur.setIgnoreUsings();

  size = associated_scopes.size();
  for ( unsigned int i = 0; i < size && fun == 0; ++i )
  {
    Scope *s = associated_scopes[i];
    fun = s->lookup( &occur );
  }
  if ( fun != 0 )
  {
    fun->addReference( &occur );

    // THG - be sure and propagate correct type information
    if ( decl->getType() == 0 )
      decl->setType( fun->getType() );
  }

  return ( fun );
}

//------------------------------------------------------------------------------

void LookupController::setAdditionalLookupScope ( Scope *s )
{
  additional_scope = s;
}

//------------------------------------------------------------------------------
