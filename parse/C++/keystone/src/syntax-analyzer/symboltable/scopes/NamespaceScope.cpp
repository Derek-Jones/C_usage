//******************************************************************************
//
//  NamespaceScope.cpp
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

#include "Assertion.h"
#include "Sentry.h"

#include "NameDeclaration.h"
#include "NameOccurrence.h"

#include "NamespaceScope.h"

using std::endl;
using std::list;
using std::ostream;
using std::set;

//------------------------------------------------------------------------------

NameDeclaration* NamespaceScope::searchUsedNamespaces ( NameOccurrence *occur ) {

  ST_SENTRY("NamespaceScope::searchUsedNamespaces");

  list<NamespaceScope *>::const_iterator ptr = uses.begin();
  list<NameDeclaration *> choices;

  while ( ptr != uses.end() ) {
    choices.push_back( (*ptr)->lookup( occur ) );
    ++ptr;
  }

  return ( Scope::pickBest( choices, occur ) );
}

//------------------------------------------------------------------------------

bool NamespaceScope::canContain ( NameOccurrence *occur ) const {

  ST_SENTRY("LocalScope::canContain");

  switch ( occur->getSpec() ) {
    case NameOccurrence::ElabEnum        :
    case NameOccurrence::ElabClass       :
    case NameOccurrence::Member          :
    case NameOccurrence::Namespace       :
    case NameOccurrence::PseudoDestructor:
    case NameOccurrence::Destructor      :
    case NameOccurrence::Qualifier       :
    case NameOccurrence::nothing         : return ( true );
    default                              : return ( false );
  }
}

//------------------------------------------------------------------------------

NameDeclaration* NamespaceScope::lookup ( NameOccurrence *occur ) {

  ST_SENTRY("NamespaceScope::lookup");

  if ( Scope::scope_searched_set.find( this ) != Scope::scope_searched_set.end() )
    return ( 0 );

  Scope::scope_searched_set.insert( this );
  list<NameDeclaration *> choices;

  if ( canContain( occur ) )
    choices.push_back( findHere( occur ) );

  choices.push_back( searchUsedNamespaces( occur ) );

  if ( containedIn && !occur->hasQualifier() ) {
    choices.push_back( containedIn->lookup( occur ) );

    // THG - Added for anon namespaces to work
    list<NameDeclaration *> anon = containedIn->getAnonNamespaces();

    for ( list<NameDeclaration *>::iterator it = anon.begin();
          it != anon.end();
          ++it
        ) {
      if ( (*it)->getCorrespondingScope() &&
           (*it)->getCorrespondingScope() != this
         ) {
        choices.push_back( (*it)->getCorrespondingScope()->lookup( occur ) );
      }
    }
  }

  return ( Scope::pickBest( choices, occur ) );
}

//------------------------------------------------------------------------------

ostream& NamespaceScope::Print ( ostream &out ) const {

  ST_SENTRY("NamespaceScope::Print");

  out << "NAMESPACE: " ;
  Scope::Print( out );

  if ( uses.size() > 0 )  {
    out << "This namespace uses: ";
    for ( list<NamespaceScope *>::const_iterator ptr = uses.begin();
          ptr != uses.end();
          ++ptr
        ) {
      out << (*ptr)->getName() << '\t';
    }
  }
  out << "END OF NAMESPACE SCOPE: " << getName() << endl;

  return ( out );
}

//------------------------------------------------------------------------------
