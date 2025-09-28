//******************************************************************************
//
//  FunctionScope.cpp
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
#include "PrototypeScope.h"
#include "TemplateParameterScope.h"

using std::cout;
using std::endl;
using std::list;
using std::ostream;
using std::string;

//------------------------------------------------------------------------------

FunctionScope::FunctionScope ( NameDeclaration *n, Scope *ptr )
              : Scope ( n,
                        ( dynamic_cast<TemplateParameterScope *>( ptr )
                          ?  ptr->getContainingScope()
                          : ptr
                        )
                      ),
                thePrototype ( 0 )
{
  ST_SENTRY( "FunctionScope::FunctionScope" );

  cout << "The pointer to the prototype is unitialized." << endl;
}

//------------------------------------------------------------------------------

FunctionScope::FunctionScope ( NameDeclaration *n, Scope *ptr, Scope *scope )
              : Scope ( n,
                        ( dynamic_cast<TemplateParameterScope *>( ptr )
                          ? ptr->getContainingScope()
                          : ptr
                        )
                      ),
                thePrototype ( dynamic_cast<PrototypeScope *>( scope ) )
{ }

//------------------------------------------------------------------------------

bool FunctionScope::canContain ( NameOccurrence *occur ) const {

  ST_SENTRY("FunctionScope::canContain");

  switch ( occur->getSpec() ) {
    case NameOccurrence::nothing: return ( true );
    default                     : return ( false );
  }
}

//------------------------------------------------------------------------------

NameDeclaration* FunctionScope::lookup ( NameOccurrence *occur ) {

  ST_SENTRY("FunctionScope::lookup");

  MAKE_ASSERTION( !occur->hasQualifier(),
                  "Cannot lookup an occurrence with a qualifier in Function Scope." );

  list<NameDeclaration *> choices;

  if ( canContain( occur ) )
    choices.push_back( findHere( occur ) );

  if ( thePrototype )
    choices.push_back( thePrototype->lookup( occur ) ); // also looks in class scope

  if ( containedIn ) {
    choices.push_back( containedIn->lookup( occur ) );
    // THG - Added for anon namespaces to work
    list<NameDeclaration *> anon = containedIn->getAnonNamespaces();

    for ( list<NameDeclaration *>::iterator it = anon.begin();
          it != anon.end();
          ++it
        ) {
      choices.push_back( (*it)->getCorrespondingScope()->lookup( occur ) );
    }
  }

  return ( Scope::pickBest( choices, occur ) );
}

//------------------------------------------------------------------------------

ostream& FunctionScope::Print ( ostream &out ) const {

  ST_SENTRY("FunctionScope::Print");

  out << "FUNCTION: " ;
  Scope::Print( out );

  if ( thePrototype == 0 )
    throw string("No prototype");

  //out << thePrototype->getName();
  out << "END OF FUNCTION SCOPE: " << getName() << endl;

  return ( out );
}

//------------------------------------------------------------------------------
