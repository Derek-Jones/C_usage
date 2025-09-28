//******************************************************************************
//
//  ActionFacade.cpp
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

#include <sstream>

#include "Assertion.h"
#include "Sentry.h"

#include "ContextManager.h"
#include "NameOccurrence.h"

#include "NameDeclaration.h"
#include "Scope.h"
#include "ClassScope.h"
#include "TemplateParameterScope.h"
#include "Type.h"
#include "IndirectType.h"

#include "ActionFacade.h"

using std::cout;
using std::endl;
using std::ends;
using std::flush;
using std::string;
using std::stringstream;
using std::vector;

//------------------------------------------------------------------------------

void ActionFacade::setDebug ( bool val )
{
  debug_on = val;
}

//------------------------------------------------------------------------------
// Constructor
//------------------------------------------------------------------------------

ActionFacade::ActionFacade ( ContextManager *contextManager )
             : contextMan ( contextManager ),
               lookupMan  ( contextManager ),
               debug_on   ( true )
{
}

//------------------------------------------------------------------------------
// Public Methods
//------------------------------------------------------------------------------

NameDeclaration* ActionFacade::lookup_report ( string msg,
                                               TokenInfo *id,
                                               NameDeclaration *decl
                                             ) const
{
  P_SENTRY;

  if ( debug_on )
  {
    if ( decl == 0 )
      cout << msg << ": did not find decl: " << *id << endl;
    else
      cout << msg << ": resolved " << *id << flush << " as " << *decl << endl;
  }

  return ( decl );
}

//------------------------------------------------------------------------------

NameDeclaration* ActionFacade::lookupUnqualifiedName ( NameOccurrence *occur ) const
{
  P_SENTRY;

  MAKE_ASSERTION( occur != 0, "NameOccurrence is NULL while looking up an unqualified Name." );

  return ( lookup_report( "UNL", occur, lookupMan.lookupUnqualifiedName( occur ) ) );
}
//------------------------------------------------------------------------------

NameDeclaration* ActionFacade::lookupQualifiedName ( NameOccurrence* occur ) const
{
  P_SENTRY;

  MAKE_ASSERTION( occur != 0, "NameOccurrence is NULL while looking up a qualified Name." );

  return ( lookup_report( "QNL", occur,lookupMan.lookupQualifiedName( occur ) ) );
}

//------------------------------------------------------------------------------

NameDeclaration* ActionFacade::lookupMemberName ( NameDeclaration *aggr,
                                                  NameDeclaration *memb
                                                ) const
{
  P_SENTRY;

  MAKE_ASSERTION( aggr != 0, "Aggregate is NULL in member name lookup" );
  MAKE_ASSERTION( memb != 0, "Member is NULL in member name lookup." );

  return ( lookup_report( "MNL", memb,lookupMan.lookupMemberName( aggr, memb ) ) );
}

//------------------------------------------------------------------------------

NameDeclaration* ActionFacade::lookupPseudoDestructor ( NameDeclaration *aggr, 
                                                        NameDeclaration *pdest
                                                      ) const
{
  P_SENTRY;

  MAKE_ASSERTION( aggr != 0, "Aggregate is NULL in pseudoDestructor lookup." );
  MAKE_ASSERTION( pdest != 0, "Pseudo Destructor decl is NULL in pseudoDestructor lookup." );

  return ( lookup_report( "DNL",pdest, lookupMan.lookupPseudoDestructor( aggr, pdest ) ) );
}

//------------------------------------------------------------------------------

NameDeclaration* ActionFacade::lookupFunctionCall ( NameDeclaration *decl,
                                                    vector<NameDeclaration *> args
                                                  ) const
{
  P_SENTRY;

  MAKE_ASSERTION( decl != 0, "Declaration is null when looking up a function call." );

  return ( lookup_report( "FCL", decl, lookupMan.lookupFunctionCall( decl, args ) ) );
}

//------------------------------------------------------------------------------

NameDeclaration* ActionFacade::lookupBinOp ( string *op,
                                             NameDeclaration *lhs,
                                             NameDeclaration *rhs
                                           )
{
  P_SENTRY;

  MAKE_ASSERTION( op != 0, "operator name is null in Binary Op lookup." );

  if ( ( lhs == 0 ) && ( rhs == 0 ) )
    return ( 0 );

  string file = ( lhs != 0 ? lhs->getFileName() : rhs->getFileName() );
  int line    = ( lhs != 0 ? lhs->getLinenum() : rhs->getLinenum() );
  int col     = ( lhs != 0 ? lhs->getColnum()  : rhs->getColnum() );
  TokenInfo ti( *op, file, line, col + 1 );

  return ( lookup_report( "BOP", &ti, lookupMan.lookupBinOp( op, lhs, rhs ) ) );
}

//------------------------------------------------------------------------------

NameDeclaration* ActionFacade::lookupUnaryOp ( string *op, NameDeclaration *decl )
{
  P_SENTRY;

  MAKE_ASSERTION( op != 0, "operator name is null in unary op lookup." );

  if ( ( decl == 0 ) || ( decl->getCorrespondingScope() == 0 ) )
    return decl;

  TokenInfo ti( *op, decl->getFileName(), decl->getLinenum(), decl->getColnum() );

  return ( lookup_report( "UOP", &ti, lookupMan.lookupUnaryOp(op, decl ) ) );
}

//------------------------------------------------------------------------------

void ActionFacade::relookupUnqualifiedName ( NameDeclaration *&decl ) const
{
  P_SENTRY;

  NameOccurrence occur( decl );

  if( decl->getOccurQual() )
    decl = lookup_report( "RQN", &occur, lookupMan.lookupQualifiedName( &occur ) );
  else
    decl = lookup_report( "RUN", &occur, lookupMan.lookupUnqualifiedName( &occur ) );

  decl->addReference( &occur );
}

//------------------------------------------------------------------------------

void ActionFacade::useDeclaration ( NameDeclaration* n )
{
  P_SENTRY;

  MAKE_ASSERTION( n != 0, "using declaration decl is NULL." );
  MAKE_ASSERTION( n->isInSymbolTable(), "using declaration decl is NOT in the symbol table." );

  contextMan->useDeclaration( n );
}

//------------------------------------------------------------------------------

void ActionFacade::useNamespace ( NameDeclaration *n )
{
  P_SENTRY;

  MAKE_ASSERTION( n != 0, "using namespace decl is NULL." );
  MAKE_ASSERTION( n->getType() && n->getType()->checkType( Type::DT_NAMESPACE ),
                  "useNamespace was not given a Namespace type." );

  contextMan->useNamespace( n );
}

//------------------------------------------------------------------------------

NameDeclaration* ActionFacade::makeOperator ( string *name, int line ) const
{
  P_SENTRY;

  string n( "operator" + *name );

  if ( ( *name == "delete" )   ||
       ( *name == "delete[]" ) ||
       ( *name == "new" )      ||
       ( *name == "new[]" )
     ) {
    n = "operator " + *name;
  }
  TokenInfo       *ti   = new TokenInfo( n, line, 0 );
  NameDeclaration *decl = new NameDeclaration( ti, getCurrentScope(), 0 );

  return ( decl );
}

//------------------------------------------------------------------------------

NameDeclaration* ActionFacade::makeAnonIdent ( int line, int col ) const
{
  static int num = 1;

  P_SENTRY;

  stringstream str;
  str << "__anon" << num;

  TokenInfo       *ti   = new TokenInfo( str.str(), line, col );
  NameDeclaration *decl = new NameDeclaration( ti, getCurrentScope(), 0 );
  ++num;

  return ( decl );
}

//------------------------------------------------------------------------------

NameDeclaration* ActionFacade::makeAnonParmIdent ( int line,
                                                   int col,
                                                   int parm_num
                                                 ) const
{
  P_SENTRY;

  stringstream str;
  str << "__anon" << parm_num;

  TokenInfo       *ti   = new TokenInfo( str.str(), line, col );
  NameDeclaration *decl = new NameDeclaration( ti, getCurrentScope(), 0 );

  return ( decl );
}

//------------------------------------------------------------------------------

NameDeclaration* ActionFacade::makeAnonNSIdent ( int line, int col ) const
{
  P_SENTRY;

  TokenInfo       *ti   = new TokenInfo( "anon", line, col );
  NameDeclaration *decl = new NameDeclaration( ti, getCurrentScope(), 0 );

  return ( decl );
}

//------------------------------------------------------------------------------

NameDeclaration* ActionFacade::insertLocal ( NameDeclaration *decl,
                                             Type            *ty,
                                             bool             instance
                                           )
{
  P_SENTRY;

  MAKE_ASSERTION( decl != 0, "insertLocal passed a NULL declaration." );

  if ( instance )
  {
    NameDeclaration *oldDecl = decl;
    bool oldInstance = oldDecl->isInstance();
    decl->setInstance( true );
    decl = contextMan->insertLocal( decl, ty );

    if ( oldDecl != decl )
    {
      oldDecl->setInstance( oldInstance );
      decl->setInstance( true );
    }

    return ( decl );
  }

  return ( contextMan->insertLocal( decl, ty ) );
}

//------------------------------------------------------------------------------

void ActionFacade::undoRecentInsertLocal ( NameDeclaration *decl )
{
  P_SENTRY;

  contextMan->undoRecentInsertLocal( decl );
}

//------------------------------------------------------------------------------

NameDeclaration* ActionFacade::moveIntoClassScope ( NameDeclaration *decl )
{
  P_SENTRY;

  MAKE_ASSERTION( decl != 0, "moveIntoClassScope passed a NULL declaration." );

  return ( contextMan->moveIntoClassScope( decl ) );
}

//------------------------------------------------------------------------------

NameDeclaration* ActionFacade::moveIntoNamespaceScope ( NameDeclaration *decl )
{
  P_SENTRY;

  MAKE_ASSERTION( decl != 0, "moveIntoNamepspaceScope passed a NULL declaration." );

  return ( contextMan->moveIntoNamespaceScope( decl ) );
}

//------------------------------------------------------------------------------

NameDeclaration* ActionFacade::moveIntoAnonNamespace ( NameDeclaration *decl )
{
  P_SENTRY;

  MAKE_ASSERTION( decl != 0, "moveIntoAnonNamespace passed a NULL declaration." );

  return ( contextMan->moveIntoNamespaceScope( decl ) ); 
}

//------------------------------------------------------------------------------

NameDeclaration* ActionFacade::moveIntoPrototypeScope ( NameDeclaration *decl )
{
  // Assume decl has already been recognized as a variable
  P_SENTRY;

  MAKE_ASSERTION( decl != 0, "moveIntoPrototypeScope passed a NULL declaration." );

  return ( contextMan->moveIntoPrototypeScope( decl ) );
}

//------------------------------------------------------------------------------

NameDeclaration* ActionFacade::moveIntoFunctionScope ( NameDeclaration *decl )
{
   // Assume decl has already been recognised as a function prototype
  P_SENTRY;

  MAKE_ASSERTION( decl != 0, "moveIntoFunctionScope was passed a NULL declaration." );
  MAKE_ASSERTION( decl->isInSymbolTable(),
                  "moveIntoFunctionScope was passed a decl that was not in the symbol table." );
  MAKE_ASSERTION( decl->getType() && decl->getType()->checkType( Type::DT_FUNCTION_PROTOTYPE ),
                  "moveIntoFunctionScope was passed a decl that was did not have a FunctionPrototype type." );

   return ( contextMan->moveIntoFunctionScope( decl ) );
}

//------------------------------------------------------------------------------

void ActionFacade::moveIntoLocalScope ( void )
{
  P_SENTRY;

  contextMan->moveIntoLocalScope();
}

//------------------------------------------------------------------------------

void ActionFacade::moveIntoTemplateParameterScope ( void )
{
  P_SENTRY;

  contextMan->moveIntoTemplateParameterScope();
}

//------------------------------------------------------------------------------

Scope* ActionFacade::getCurrentScope ( void ) const
{
  P_SENTRY;

  return ( contextMan->getCurrentScope() );
}

//------------------------------------------------------------------------------

Scope* ActionFacade::getPreviousScope ( void ) const
{
  P_SENTRY;

  return ( contextMan->getPreviousScope() );
}

//------------------------------------------------------------------------------

Scope* ActionFacade::getCurrentTemplateScope ( bool b ) const
{
  P_SENTRY;

  return ( contextMan->getCurrentTemplateScope( b ) );
}

//------------------------------------------------------------------------------

Scope* ActionFacade::inCurrentClassScope ( void ) const
{
  P_SENTRY;

  return ( contextMan->inCurrentClassScope() );
}

//------------------------------------------------------------------------------

void ActionFacade::setAdditionalLookupScope (Scope *s )
{
  P_SENTRY;

  lookupMan.setAdditionalLookupScope( s );
}

//------------------------------------------------------------------------------

Scope* ActionFacade::getCurrentClassScope ( void ) const
{
  P_SENTRY;

  return ( contextMan->getCurrentClassScope() );
}

//------------------------------------------------------------------------------

void ActionFacade::leaveCurrentScope ( void )
{
  P_SENTRY;

  contextMan->leaveCurrentScope();
}

//------------------------------------------------------------------------------

void ActionFacade::installBaseClass ( NameDeclaration *base, Access::AccessType acc )
{
  P_SENTRY;

  MAKE_ASSERTION( base != 0, "Base class declaration was NULL." );
  MAKE_ASSERTION( base->getType() &&
                   ( base->getType()->checkType( Type::DT_CLASS)          ||
                     base->getType()->checkType( Type::DT_TEMPLATE_PARM ) ||
                     base->getType()->checkType( Type::DT_TEMPLATE_TEMPLATE_PARM )
                   ),
                   "Base class declaration was not of type class." );

  contextMan->installBaseInCurrentScope( base, acc );
}

//------------------------------------------------------------------------------

void ActionFacade::nextIsDestructor ( void )
{
  P_SENTRY;

  contextMan->setNextIsDestructor( true );
}

//------------------------------------------------------------------------------

void ActionFacade::makeFunctionPure ( NameDeclaration *decl ) const
{
  P_SENTRY;

  if ( decl->getType() && decl->getType()->checkType( Type::DT_FUNCTION ) )
    decl->setAttribute( Attribute::Pure );
}

//------------------------------------------------------------------------------

void ActionFacade::makeFunctionVirtual ( NameDeclaration *decl ) const
{
  P_SENTRY;

  if( decl->getType() && decl->getType()->checkType( Type::DT_FUNCTION ) )
    decl->setAttribute( Attribute::Virtual );
}

//------------------------------------------------------------------------------

void ActionFacade::makeFriend ( NameDeclaration *decl ) const
{
  P_SENTRY;

  Scope *theScope = contextMan->getCurrentScope();

  MAKE_ASSERTION( theScope, "Current scope does not exist" );
  MAKE_ASSERTION( decl->getType(), "decl does not have a type" );

  if( decl->getType()->checkType( Type::DT_FUNCTION_DEFINITION ) )
    theScope = theScope->getContainingScope();

  ClassScope *classScope = dynamic_cast<ClassScope*>( theScope );

  MAKE_ASSERTION( classScope, "Friend declared in non-class scope." );

  string name = decl->getName();
  NameDeclaration *origDecl = decl;

  while( ( decl = decl->getOccurQual() ) )
    name = decl->getName() + "::" + name;

  classScope->addFriend( origDecl, name );
}

//------------------------------------------------------------------------------

void ActionFacade::makeConst ( NameDeclaration *decl ) const
{
  P_SENTRY;

  decl->setAttribute( Attribute::Const );
}

//------------------------------------------------------------------------------

void ActionFacade::makeStatic ( NameDeclaration *decl ) const
{
  P_SENTRY;

  decl->setAttribute( Attribute::Static );
}

//------------------------------------------------------------------------------

void ActionFacade::makeTypedef ( NameDeclaration *decl ) const
{
  P_SENTRY;

  MAKE_ASSERTION( decl->getType(), "Name Declaration has a NULL type." );                    

  decl->setInstance( false );
}

//------------------------------------------------------------------------------

void ActionFacade::makeInstance ( NameDeclaration *decl ) const
{
  P_SENTRY;

  MAKE_ASSERTION( decl->getType(), "Name declaration has a NULL type in makeInstance." );

  decl->setInstance( true );
}

//------------------------------------------------------------------------------

void ActionFacade::setAccess ( NameDeclaration *decl,
                               const Access::AccessType &acc
                             ) const
{
  P_SENTRY;

  if ( dynamic_cast<ClassScope*>( decl->getContainingScope() ) )
    decl->setAccess( acc );
}
//------------------------------------------------------------------------------

bool ActionFacade::inClassScope ( void )
{
  P_SENTRY;

  return ( contextMan->inClassScope() );
}

//------------------------------------------------------------------------------

void ActionFacade::setAccessForClass ( const Access::AccessType &ca )
{
  P_SENTRY;

  contextMan->setAccessForClass( ca );
}
//------------------------------------------------------------------------------

void ActionFacade::makeIndirect ( NameDeclaration *decl, string signature ) const
{
  P_SENTRY;

  for ( unsigned int i = 0; i < signature.length(); ++i )
  {
    if ( signature[i] == '*' )
      decl->setType( new IndirectType( decl, decl->getType(), IndirectType::IT_POINTER ) );
    else if ( signature[i] == '&' )
      decl->setType( new IndirectType( decl, decl->getType(), IndirectType::IT_REFERENCE ) );
    else if ( signature[i] == '[' )
      decl->setType( new IndirectType( decl, decl->getType(), IndirectType::IT_ARRAY ) );
  }
}

//------------------------------------------------------------------------------

NameDeclaration* ActionFacade::getGlobalNamespace ( void ) const
{
  P_SENTRY;

  return ( contextMan->getGlobalNamespace() );
}
//------------------------------------------------------------------------------

void ActionFacade::printClassesAndNamespaces ( void ) const
{
  cout << *contextMan;
}

//------------------------------------------------------------------------------
