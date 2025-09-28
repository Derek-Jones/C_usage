//******************************************************************************
//
//  TokenDecorator.cpp
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

#include <iostream>

#include "Assertion.h"

#include "ActionFacade.h"
#include "LocationTracker.h"
#include "NameOccurrence.h"

#include "NameDeclaration.h"
#include "Scope.h"
#include "ClassScope.h"
#include "FunctionScope.h"
#include "PrototypeScope.h"
#include "TemplateParameterScope.h"
#include "Type.h"

#include "NameDeclarationInvariantFacilitator.h"
#include "ScopeInvariantFacilitator.h"
#include "TypeInvariantFacilitator.h"

#include "TokenDecorator.h"

using std::cout;
using std::endl;

bool TokenDecorator::first_time = true;

void TokenDecorator::recycle ( void )
{
  first_time = true;
}

//------------------------------------------------------------------------------
// Constructors
//------------------------------------------------------------------------------

TokenDecorator::TokenDecorator ( LocationTracker *lt, ActionFacade *af )
               : location       ( lt ),
                 facade         ( af ),
                 buf            ( lt, af ),
                 currentToken   ( 1 ),
                 decorated      ( 0 ),
                 non_decorated  ( 0 ),
                 non_identifier ( 0 )
{ }

//------------------------------------------------------------------------------

void TokenDecorator::printStatistics ( void ) const
{
  cout << "STATISTICS: " << endl;
  cout << "Decorated Identifiers: "     << decorated << endl;
  cout << "Non Decorated Identifiers: " << non_decorated << endl;
  cout << "Non Identifier Tokens: "     << non_identifier << endl;
  cout << "Specifiers set by buffer: "  << buf.getSpecStat() << endl;
  cout << "Qualifiers set by buffer: "  << buf.getQualStat() << endl;

  // check invariants
  TypeInvariantFacilitator::CheckStoredClassesInvariants();
  ScopeInvariantFacilitator::CheckStoredClassesInvariants();
  NameDeclarationInvariantFacilitator::CheckStoredClassesInvariants();

  cout << "END STATISTICS: " << endl;
}

//------------------------------------------------------------------------------

bool isTemplate ( NameDeclaration *decl )
{
  if( ClassScope *scope = dynamic_cast<ClassScope *>( decl->getCorrespondingScope() ) )
    return  ( scope->isTemplate() );

  if ( FunctionScope *scope = dynamic_cast<FunctionScope *>( decl->getCorrespondingScope() ) )
    return ( scope->getPrototypeScope()->getTemplateParameterScope() );

  if ( PrototypeScope *scope = dynamic_cast<PrototypeScope *>( decl->getCorrespondingScope() ) )
    return ( scope->getTemplateParameterScope() );

  if ( decl->getType()->checkType( Type::DT_TEMPLATE_TEMPLATE_PARM ) )
    return ( true );

  return ( decl->getIsTemplate() );
}

//------------------------------------------------------------------------------

int TokenDecorator::getNextToken ( void )
{
  P_SENTRY;

  // cannot initialize in constructor because
  // this is a GLOBAL object and the lexer
  // won't be ready!
  if ( first_time )
  {
    buf.init();
    first_time = false;
  }

  currentToken = buf.getNextToken();
  if ( currentToken == IDENTIFIER )
  {
    NameOccurrence *occur = buf.getNameOccurrence();
    NameDeclaration *decl = doLookup( occur );
    if ( decl == 0 )
    {  // Not found
      decl = new NameDeclaration( occur, facade->getCurrentScope(), 0 );
      if ( occur->isTemplate() )
      {
        decl->markTemplate();        
      }
    }
    else
    {
      decl->addReference( occur );
      if ( occur->isTemplate() )
      {
        decl->setIsTemplate( true );
      }
    }//else

    // next line needed if ( occur->getSpec()==NameOccurrence::Member ) 
    decl->setOccurQual( occur->getQualifier() );
    yylval.decl = decl;
    buf.setNameDeclaration( decl );
    currentToken = getCSIdent( decl, occur->isTemplate() );
    delete ( occur );
  }
  else
  { // Not an identifier
    // THG - added statistics
    ++non_identifier;
    yylval.tcount = buf.getTokenCount();
  }

  return ( currentToken );
}

//------------------------------------------------------------------------------

NameDeclaration* TokenDecorator::doLookup ( NameOccurrence *id ) const
{
  P_SENTRY;

  NameDeclaration *decl = 0;

  if ( id->hasQualifier() )
  {
    decl = facade->lookupQualifiedName( id );
  } 
  else
  {
    decl = facade->lookupUnqualifiedName( id );
  }

  if ( decl == 0 && buf.lastWasFun() &&
       buf.getLastIdentifier()->getCorrespondingScope()
     )
  {
    decl = buf.getLastIdentifier()->getCorrespondingScope()->lookup( id );
  }

  return ( decl );
}

//------------------------------------------------------------------------------

int TokenDecorator::getCSIdent ( NameDeclaration *decl, bool isTem )
{
  P_SENTRY;

  // THG - added statistics
  MAKE_ASSERTION( decl != 0, "getCSIdent was given a NULL declaration." );

  if( !decl->getType() && !isTem )
  {
    ++non_decorated;
    return ( IDENTIFIER );
  }
  else if ( //(decl->getType() && decl->getType()->checkType(Type::DT_CLASS) && buf.nextIsLPAREN()) ||
            isTem || ( buf.nextIsLESS() && isTemplate( decl ) )
          )
  {
    buf.saveId();
    ++decorated;
    return ( ID_template_name );
  }
  else if ( decl->getType()->checkType(Type::DT_CLASS) &&
            !decl->isInstance()                        &&
            decl->getType()->getDecl() == decl
            // NAK - don't decorate certain parameters in prototype scope
            && ( !buf.prevIsType() || ( buf.prevIsType() && buf.nextIsColCol() ) )
            // END
          )
  {
    ++decorated;
    return ( ID_class_name );
  }
  else if ( decl->getType()->checkType( Type::DT_ENUM ) &&
            !decl->isInstance()
          )
  {
    ++decorated;
    return ( ID_enum_name );
  }
  else if ( decl->getType()->checkType( Type::DT_NAMESPACE ) )
  {
    ++decorated;
    return ( decl->isInstance() ? ID_namespace_alias : ID_original_namespace_name );
  }
  else if ( !decl->isInstance()                                    &&
            ( decl->getType()->checkType( Type::DT_TEMPLATE_PARM ) ||
              decl->getType()->checkType( Type::DT_TEMPLATE_TEMPLATE_PARM )
            )
          )
  {
    ++decorated;
    return ( ID_class_name );
  }
  else if ( !decl->isInstance() &&
            ( decl->getType()->getDecl() != decl ||
              decl->getType()->checkType( Type::DT_INDIRECT ) ||
              decl->getType()->checkType( Type::DT_FUNCTION )
            )
          )
  {
    ++decorated;
    if ( decl->getType()->checkType( Type::DT_CLASS ) )
    {
       return ( ID_class_name );
    }

    return ( ID_typedef_name );
  }
  ++non_decorated;

  return ( IDENTIFIER );
}

//------------------------------------------------------------------------------
