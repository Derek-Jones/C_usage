//******************************************************************************
//
//  ContextManager.cpp
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

#include "Assertion.h"
#include "Sentry.h"

#include "NameOccurrence.h"

#include "NameDeclaration.h"
#include "Scope.h"
#include "ClassScope.h"
#include "FunctionScope.h"
#include "LocalScope.h"
#include "NamespaceScope.h"
#include "PrototypeScope.h"
#include "TemplateParameterScope.h"
#include "Type.h"
#include "ClassType.h"
#include "FunctionType.h"
#include "NamespaceType.h"

#include "ContextManager.h"

using std::cout;
using std::endl;
using std::list;
using std::ostream;

//------------------------------------------------------------------------------
// Constructor/Destructor
//------------------------------------------------------------------------------

ContextManager::ContextManager ( )
               : inTemplate       ( false ),
                 mem_init         ( false ),
                 nextIsDestructor ( false )
{
  P_SENTRY;

  globalNamespace = new NameDeclaration( new TokenInfo( "_GlobalNamespace", 0, 0 ), 0, 0 );

  //can't use moveIntoNewScope because it will insertLocal into NOTHING!
  globalNamespace->setType( new NamespaceType( globalNamespace ) );
  NamespaceScope *globScope = new NamespaceScope( globalNamespace, 0 );
  listOfScopes.push_back( globScope );
  enterScope( globScope );
}

//------------------------------------------------------------------------------

ContextManager::~ContextManager ( )
{
  P_SENTRY;

  list<Scope *>::iterator ptr = listOfScopes.begin();
  ++ptr; // skip the globalNamespace
  while ( ptr != listOfScopes.end() )
  {
    delete ( *ptr );
    ++ptr;
  }
  listOfScopes.clear();
  delete ( globalNamespace );
}

//------------------------------------------------------------------------------
// Public Methods
//------------------------------------------------------------------------------

Scope* ContextManager::getCurrentScope ( void ) const
{
  P_SENTRY;

  if ( nestedScopes.empty() )
    throw "stack empty in getCurrentScope()";

  return ( nestedScopes.top() );
}

//------------------------------------------------------------------------------

Scope* ContextManager::getPreviousScope ( void )
{
  P_SENTRY;

  Scope *top = getCurrentScope();
  nestedScopes.pop();
  Scope* second = 0;
  if( !nestedScopes.empty() )
    second = getCurrentScope();
  nestedScopes.push(top);

  return ( second );
}

//------------------------------------------------------------------------------

void ContextManager::enterScope ( Scope *scope )
{
  P_SENTRY;

  nestedScopes.push( scope );
}

//------------------------------------------------------------------------------

void ContextManager::leaveCurrentScope ( void )
{
  P_SENTRY;

  nestedScopes.pop();
}

//------------------------------------------------------------------------------

NameDeclaration* ContextManager::getGlobalNamespace ( void ) const
{
  P_SENTRY;

  return ( globalNamespace );
}

//------------------------------------------------------------------------------

bool ContextManager::inClassScope ( void )
{
  P_SENTRY;

  return ( dynamic_cast<ClassScope*>( getCurrentScope() ) != 0 );
}

//------------------------------------------------------------------------------

void ContextManager::setAccessForClass ( const Access::AccessType &ca )
{
  P_SENTRY;

  getCurrentScope()->getDecl()->setAccess( ca );
}

//------------------------------------------------------------------------------

TemplateParameterScope* ContextManager::getCurrentTemplateScope ( bool b )
{
  P_SENTRY;

#if 0
  list<Scope*>::iterator fit = listOfScopes.end();
  for ( list<Scope*>::reverse_iterator it( fit );
        it != listOfScopes.rend();
        ++it )
  {
    if ( TemplateParameterScope* tps = dynamic_cast<TemplateParameterScope*>( *it ) )
    {
      if( b )
      {
        list<Scope*>::iterator rit;
        rit = it.base();
        --rit;

        listOfScopes.erase( rit );
      }

#endif
  for ( list<Scope*>::reverse_iterator it = listOfScopes.rbegin();
        it != listOfScopes.rend();
        ++it )
  {
    if ( TemplateParameterScope* tps = dynamic_cast<TemplateParameterScope*>( *it ) )
    {
      if( b )
      {
        list<Scope*>::iterator fit;
        fit = it.base();
        --fit;

        listOfScopes.erase( fit );
      }

      return ( tps );
    }
  }
  return ( 0 );
}

//------------------------------------------------------------------------------

Scope* ContextManager::inCurrentClassScope ( void )
{
  P_SENTRY;

  MAKE_ASSERTION( !nestedScopes.empty(), "Stack is empty in getCurrentClassScope." );

  Scope      *tmp = nestedScopes.top();
  ClassScope *cs  = 0;

  while( ( cs = dynamic_cast<ClassScope*>( tmp ) ) == 0 )
  {
    if ( tmp->getDecl() && tmp->getDecl()->getOccurQual() )
      tmp = tmp->getDecl()->getOccurQual()->getCorrespondingScope();
    else
      tmp = tmp->getContainingScope();

    if ( tmp == 0 )
       return ( 0 );
  }

  return ( cs );
}

//------------------------------------------------------------------------------

Scope* ContextManager::getCurrentClassScope ( void )
{
  P_SENTRY;

  MAKE_ASSERTION( !nestedScopes.empty(), "Stack is empty in getCurrentClassScope." );

  Scope      *tmp = nestedScopes.top();
  ClassScope *cs  = 0;

  while ( ( cs = dynamic_cast<ClassScope*>( tmp ) ) == 0 )
  {
    if ( FunctionScope *fs = dynamic_cast<FunctionScope*>(tmp) )
      tmp = fs->getPrototypeScope();

    if( tmp->getDecl() && tmp->getDecl()->getOccurQual() )
      tmp = tmp->getDecl()->getOccurQual()->getCorrespondingScope();
    else
      tmp = tmp->getContainingScope();

    MAKE_ASSERTION( tmp != 0, "Declaration has a NULL containing scope." );
  }

  return ( cs );
}

//------------------------------------------------------------------------------

void ContextManager::installBaseInCurrentScope ( NameDeclaration *base,
                                                 Access::AccessType acc )
{
  P_SENTRY;

  Scope      *current_scope = getCurrentScope();
  ClassScope *c_scope       = dynamic_cast<ClassScope *>( current_scope );

  MAKE_ASSERTION( c_scope != 0, "current scope was not class scope in installBaseInCurrentScope." );

  Scope      *base_scope = base->getCorrespondingScope();
  ClassScope *b_scope    = dynamic_cast<ClassScope *>( base_scope );

  if ( b_scope )
  {
    c_scope->installBaseClass( b_scope, acc );
  }
  else
  {
    MAKE_ASSERTION( base->getType() &&
                    ( base->getType()->checkType( Type::DT_TEMPLATE_PARM ) ||
                      base->getType()->checkType( Type::DT_TEMPLATE_TEMPLATE_PARM )
                    ),
                    "base class scope was not of type ClassScope."
                  );
  }
}

//------------------------------------------------------------------------------

void ContextManager::useNamespace ( NameDeclaration *n )
{
  P_SENTRY;

  NamespaceScope *scope = dynamic_cast<NamespaceScope *>( n->getCorrespondingScope() );

  MAKE_ASSERTION( scope != 0, "useNamespace was not given a namespace scoped decl." );

  // THG - Changed below to allow using in local scope
  NamespaceScope *curr_scope = dynamic_cast<NamespaceScope *>( getCurrentScope() );

  if( curr_scope != 0 )
  {
    curr_scope->addUses(scope);
  }
  else
  {
    LocalScope *curr_scope = dynamic_cast<LocalScope *>( getCurrentScope() );

    MAKE_ASSERTION( curr_scope != 0, "current scope was not of type local scope in useNamespace." );

    curr_scope->addUses( scope );
  }
}

//------------------------------------------------------------------------------

NameDeclaration* ContextManager::moveIntoNamespaceScope ( NameDeclaration *decl )
{
  P_SENTRY;

  Scope *scope_ptr = decl->getCorrespondingScope();

  if ( scope_ptr == 0 )
  {
    scope_ptr = new NamespaceScope( decl, getCurrentScope() );
    decl = insertLocal( decl, new NamespaceType( decl ) );
    listOfScopes.push_back( scope_ptr );
  }
  enterScope( scope_ptr );

  return ( decl );
}

//------------------------------------------------------------------------------

NameDeclaration* ContextManager::moveIntoAnonNamespace ( NameDeclaration *decl )
{
  P_SENTRY;

  NamespaceScope *c_scope = dynamic_cast<NamespaceScope *>( getCurrentScope() );

  MAKE_ASSERTION( c_scope != 0, "moveIntoAnonNamespace was called when current scope was not of namespace scope." );

  decl = moveIntoNamespaceScope( decl );
  NamespaceScope *a_scope = dynamic_cast<NamespaceScope *>( decl->getCorrespondingScope() );

  MAKE_ASSERTION( a_scope != 0, "moveIntoAnonNamespace was given a decl that was not of namespace scope." );

  c_scope->addUses( a_scope );

  return ( decl );
}

//------------------------------------------------------------------------------


NameDeclaration* ContextManager::moveIntoPrototypeScope ( NameDeclaration *decl )
{
  P_SENTRY;

  if ( decl->getType() &&
       decl->getType()->checkType( Type::DT_FUNCTION_PROTOTYPE ) &&
       decl->getCorrespondingScope() != NULL )
  {
    PrototypeScope* scope_ptr = dynamic_cast<PrototypeScope*>(decl->getCorrespondingScope());
    TemplateParameterScope* tps = NULL;
    if ( scope_ptr && !inTemplate && ( tps = getCurrentTemplateScope() ) )
    {
      tps->setNameDeclaration( decl );    
      scope_ptr->setTemplateParameterScope( tps );
    }
    enterScope( decl->getCorrespondingScope() );

    return ( decl );
  }

  Type         *ret_type = decl->getType();
  FunctionType *ft       = new FunctionType( decl, ret_type, FunctionType::Q_PROTOTYPE );
  decl->setType( ft );
  ft->setDecl( decl );//new NameDeclaration( decl, decl->getContainingScope(), ft ) );
  PrototypeScope *scope_ptr = new PrototypeScope( decl, getCurrentScope() );
  TemplateParameterScope *tps = 0;

  if( !inTemplate && ( tps = getCurrentTemplateScope() ) )
  {
    tps->setNameDeclaration( decl );    
    scope_ptr->setTemplateParameterScope( tps );
  }
  listOfScopes.push_back( scope_ptr );
  enterScope( scope_ptr );

  return ( decl );
}

//------------------------------------------------------------------------------

NameDeclaration* ContextManager::moveIntoFunctionScope ( NameDeclaration *decl )
{
  P_SENTRY;

  if( mem_init )
  {
    mem_init = false;

    return ( nestedScopes.top()->getDecl() );
  }

  if( FunctionType *ft = dynamic_cast<FunctionType*>( decl->getType() ) )
    ft->makeFunction();

  Scope *proto = decl->getCorrespondingScope();

  if( !inTemplate )
  {
    decl->setContainingScope( dynamic_cast<TemplateParameterScope *>( decl->getContainingScope() )
                                ? getPreviousScope()
                                : decl->getContainingScope()
                            );
  }

  FunctionScope *new_scope = new FunctionScope( decl, getCurrentScope(), proto );
  TemplateParameterScope *tps = 0;

  if( !inTemplate && ( tps = getCurrentTemplateScope() ) )
  {
    tps->setNameDeclaration( decl );
    new_scope->getPrototypeScope()->setTemplateParameterScope( tps );
  }
  listOfScopes.push_back( new_scope );
  enterScope( new_scope );

  return ( decl );
}

//------------------------------------------------------------------------------

NameDeclaration* ContextManager::moveIntoClassScope ( NameDeclaration *decl )
{
  P_SENTRY;

  TemplateParameterScope *tps = 0;

  if( !inTemplate )
    tps = getCurrentTemplateScope();

  // could be an explicit specialization...do nothing if so
  if( decl &&
      decl->getType() &&
      decl->getType()->checkType( Type::DT_CLASS ) &&
      dynamic_cast<ClassScope*>( decl->getCorrespondingScope() ) &&
      dynamic_cast<ClassScope*>( decl->getCorrespondingScope() )->getTemplateParameterScope() )
  {
    listOfScopes.push_back( decl->getCorrespondingScope() );
    enterScope( listOfScopes.back() );
    if( tps )
    {
       tps->setNameDeclaration( decl );
       dynamic_cast<ClassScope*>(listOfScopes.back())->setTemplateParameterScope( tps );
    }

    return ( decl );
  }

  decl = insertLocal( decl, new ClassType( decl ) );
  ClassScope * new_scope = new ClassScope( decl, getCurrentScope() );
  if( tps )
  {
    tps->setNameDeclaration( decl );
    new_scope->setTemplateParameterScope( tps );
  }
  listOfScopes.push_back( new_scope );
  enterScope( new_scope );

  return ( decl );
}

//------------------------------------------------------------------------------
// THG - Added to support local (block) scopes

void ContextManager::moveIntoLocalScope ( void )
{
  P_SENTRY;

  Scope *new_scope = new LocalScope( getCurrentScope() );
  // try to find a function scope
  Scope *cur = getCurrentScope();
  while ( cur )
  {
    if ( FunctionScope *fs = dynamic_cast<FunctionScope *>( cur ) )
    {
      fs->addLocalScope( new_scope );
      break;
    }
    cur = cur->getContainingScope();
  }
  listOfScopes.push_back( new_scope );
  enterScope( new_scope );
}

//------------------------------------------------------------------------------

void ContextManager::moveIntoTemplateParameterScope ( void )
{
  P_SENTRY;

  Scope *new_scope = new TemplateParameterScope( getCurrentScope() );
  listOfScopes.push_back( new_scope );
  enterScope( new_scope );
}

//------------------------------------------------------------------------------

bool ContextManager::sameType ( const Type *t1, const Type *t2 ) const
{
  P_SENTRY;

  if( t1 == t2 )
    return ( true );
  if( !t1 || !t2 )
    return ( false );

  return ( t1->checkType( Type::DT_NAMESPACE )           && t2->checkType( Type::DT_NAMESPACE )           ||
           t1->checkType( Type::DT_FUNCTION_PROTOTYPE )  && t2->checkType( Type::DT_FUNCTION_PROTOTYPE )  ||
           ///\todo Fix next line!
           t2->checkType( Type::DT_FUNCTION_DEFINITION ) && t2->checkType( Type::DT_FUNCTION_DEFINITION ) ||
           t1->checkType( Type::DT_CLASS )               && t2->checkType( Type::DT_CLASS )               ||
           t1->checkType( Type::DT_ENUM )                && t2->checkType( Type::DT_ENUM )                ||
           t1->checkType( Type::DT_BASIC )               && t2->checkType( Type::DT_BASIC )               ||
           t1->checkType( Type::DT_INDIRECT )            && t2->checkType( Type::DT_INDIRECT )
         );
}

//------------------------------------------------------------------------------

NameDeclaration* ContextManager::insertLocal ( NameDeclaration *decl, Type *ty )
{
  P_SENTRY;

  MAKE_ASSERTION( !nestedScopes.empty(), "insertLocal was called when no local scope exists." );

  // Figure out the owning scope
  NameDeclaration *qual = decl->getOccurQual();
  Scope *owner_scope = 0;

  if ( qual != 0 )
    owner_scope = qual->getCorrespondingScope();

  if ( owner_scope == 0 )
    owner_scope = getCurrentScope();

  // Check for duplicates here:
  if ( decl->isInSymbolTable())
  {
    if ( decl->getContainingScope() == owner_scope &&
         sameType( decl->getType(),ty )            &&
         !decl->isInstance()
       )
    {
      // Redeclaration of class/namespace
      return ( decl );
    }
    else if ( decl->getType()                                           &&
              decl->getType()->checkType( Type::DT_FUNCTION_PROTOTYPE ) &&
              decl->getContainingScope() == owner_scope
            )
    {
      // remove the prototype and replace it with the full function
      return ( decl );
    }
    else
    { // Got the wrong decl!
      if ( nextIsDestructor                             &&
           decl->getType()                              &&
           decl->getType()->checkType( Type::DT_CLASS ) &&
           decl->hasDestructor()
         )
      {
        TokenInfo ti( decl->getName() + "::~" + decl->getName(), decl->takeReference() );
        NameOccurrence no( &ti );
        NameDeclaration *to_return = decl->getCorrespondingScope()->lookup( &no );
        to_return->addReference( &no );
        return ( to_return );
      }
      TokenInfo *ti = new TokenInfo( decl->getName(),decl->takeReference() );
      // THG - Added nextIsDestructor for destructor name change
      decl = new NameDeclaration( ti, owner_scope, ty, nextIsDestructor );
      decl->setOccurQual( qual );
      nextIsDestructor = false;
    }
  }
  else
  { // Not in symbol table
    decl->setType( ty );
  }
  owner_scope->insertLocal( decl );
  return ( decl );
}

//------------------------------------------------------------------------------

void ContextManager::undoRecentInsertLocal ( NameDeclaration *decl )
{
  P_SENTRY;

  Scope *owner_scope = 0;
  NameDeclaration *qual = decl->getOccurQual();
  if ( qual != 0 )
    owner_scope = qual->getCorrespondingScope();
  if ( owner_scope == 0 )
    owner_scope = getCurrentScope();
  owner_scope->undoRecentInsertLocal( decl );
}

//------------------------------------------------------------------------------

void  ContextManager::useDeclaration ( NameDeclaration *decl )
{
  P_SENTRY;

  MAKE_ASSERTION( decl->getType(), "decl->getType() is NULL in useDeclaration" );

  Type *ty = decl->getType()->Clone();
  NameDeclaration *nd = decl->getOccurQual();
  decl->setOccurQual( 0 ); // Forces creation of new decl
  NameDeclaration *user = insertLocal( decl,ty );

  if( decl->isInstance() )
    user->setInstance( true );
  if( decl->getIsTemplate() )
    user->setIsTemplate( true );

  decl->addReference( user );
  decl->setOccurQual( nd );
  user->setOccurQual( nd );
  user->setCorrespondingScope( decl->getCorrespondingScope() );
}

//------------------------------------------------------------------------------
// THG - Following two functions added for destructor name change.

bool ContextManager::setNextIsDestructor ( bool b )
{
  P_SENTRY;

  return ( nextIsDestructor = b );
}

//------------------------------------------------------------------------------

bool ContextManager::getNextIsDestructor ( void ) const
{
  P_SENTRY;

  return ( nextIsDestructor );
}

//------------------------------------------------------------------------------
// Output
//------------------------------------------------------------------------------

ostream& operator<< ( ostream &out, const ContextManager &man )
{
  out << "----- Listing the " << man.listOfScopes.size() << " scopes -----" << endl;

  list<Scope *>::const_iterator ptr = man.listOfScopes.begin();
  while ( ptr != man.listOfScopes.end() )
  {
    out << (**ptr);
    ++ptr;
  }

  return ( out );
}

//------------------------------------------------------------------------------
