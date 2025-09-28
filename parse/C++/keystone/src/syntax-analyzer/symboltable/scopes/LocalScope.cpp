//******************************************************************************
//
//  LocalScope.cpp
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

#include "NameDeclaration.h"
#include "NameOccurrence.h"

#include "FunctionScope.h"
#include "LocalScope.h"
#include "NamespaceScope.h"
#include "PrototypeScope.h"

using std::endl;
using std::list;
using std::ostream;

//------------------------------------------------------------------------------
// THG - Added to move function prototype variables into local scope.

LocalScope::LocalScope ( Scope *ptr )
           : Scope ( 0, ptr )
{
  ST_SENTRY("LocalScope::LocalScope");

  // if the enclosing scope is FunctionScope,
  // move the function prototype declarations
  // into this scope
  if ( FunctionScope *fs = dynamic_cast<FunctionScope *>( ptr ) ) {
    Scope *s = fs->getPrototypeScope();

    for ( list<NameDeclaration *>::const_iterator it = s->getLocals()->begin();
          it != s->getLocals()->end();
          ++it
        ) {
      insertLocal( *it );
    }
  }
}

//------------------------------------------------------------------------------

bool LocalScope::canContain ( NameOccurrence *occur ) const {

  ST_SENTRY("LocalScope::canContain");

  switch ( occur->getSpec() ) {
    case NameOccurrence::ElabEnum :
    case NameOccurrence::ElabClass:
    case NameOccurrence::nothing  : return ( true );
    default                       : return ( false );
  }
}

//------------------------------------------------------------------------------
// THG - Added for block using namespace

NameDeclaration* LocalScope::lookup ( NameOccurrence *occur ) {

  ST_SENTRY("LocalScope::lookup");

  MAKE_ASSERTION( !occur->hasQualifier(),
                  "Cannot lookup an occurrence with a qualifier in local scope." );

  list<NameDeclaration *> choices;

  if ( canContain( occur ) )
    choices.push_back( findHere( occur ) );

  choices.push_back( searchUsedNamespaces( occur ) );

  if ( containedIn ) {
    choices.push_back( containedIn->lookup( occur ) );

    // THG - Added for anon namespaces to work
    list<NameDeclaration*> anon = containedIn->getAnonNamespaces();

    for ( list<NameDeclaration*>::iterator it = anon.begin();
          it != anon.end();
          ++it
        ) {
      if ( (*it)->getCorrespondingScope() ) {
        choices.push_back( (*it)->getCorrespondingScope()->lookup( occur ) );
      }
    }
  }

  return ( Scope::pickBest( choices, occur ) );
}

//------------------------------------------------------------------------------
// THG - Added for block using namespace

NameDeclaration* LocalScope::searchUsedNamespaces ( NameOccurrence *occur ) {

  ST_SENTRY("LocalScope::searchUsedNamespaces");

  list<NamespaceScope *>::const_iterator ptr = uses.begin();
  list<NameDeclaration *> choices;

  while ( ptr != uses.end() ) {
    choices.push_back( (*ptr)->lookup( occur ) );
    ++ptr;
  }

  return ( Scope::pickBest( choices, occur ) );
}
//------------------------------------------------------------------------------

ostream& LocalScope::Print ( ostream &out ) const {

  ST_SENTRY("LocalScope::Print");

  out << "LOCAL SCOPE: " ;
  Scope::Print( out );
  out << "END OF LOCAL SCOPE: " << endl;

  return ( out );
}

//------------------------------------------------------------------------------
