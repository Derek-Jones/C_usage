//******************************************************************************
//
//  ClassScope.cpp
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

#include "ClassScope.h"
#include "TemplateParameterScope.h"

using std::endl;
using std::list;
using std::ostream;
using std::string;

//------------------------------------------------------------------------------
// Static Methods
//------------------------------------------------------------------------------

bool ClassScope::hasValidChoice ( list<NameDeclaration *> &decls )
{
  for ( std::list<NameDeclaration*>::iterator it = decls.begin();
        it != decls.end();
        ++it
      )
  {
    if ( *it )
    {
      return ( true );
    }
  }

  return ( false );
}

//------------------------------------------------------------------------------

ClassScope::ClassScope ( NameDeclaration *n, Scope *ptr )
           : Scope       ( n, ptr ),
             m_tps       ( 0 ),
             is_template ( n->getIsTemplate() )
{ }

//------------------------------------------------------------------------------
// Query Methods
//------------------------------------------------------------------------------

bool ClassScope::canContain ( NameOccurrence *occur ) const {

  ST_SENTRY("ClassScope::canContain");

  switch (occur->getSpec()) {
    case NameOccurrence::ConvFunction       :
    case NameOccurrence::Destructor         :
    case NameOccurrence::DestructorQualifier:
    case NameOccurrence::ElabEnum           :
    case NameOccurrence::ElabClass          :
    case NameOccurrence::Member             :
    case NameOccurrence::PseudoDestructor   :
    case NameOccurrence::Qualifier          :
    case NameOccurrence::nothing            : return ( true );
    default                                 : return ( false );
  }

}

//------------------------------------------------------------------------------
// Accessor Methods
//------------------------------------------------------------------------------

Access::AccessType ClassScope::getAccessTypeForBase ( const ClassScope *cs ) const {

  list<Access::AccessType>::const_iterator cait = baseClassAccess.begin();

  for ( list<ClassScope *>::const_iterator cit = baseClasses.begin();
        cit != baseClasses.end();
        ++cit, ++cait
      ) {

    if ( *cit == cs ) {
      return ( *cait );
    }
  }

  return ( Access::None );
}

//------------------------------------------------------------------------------
// Mutator Methods
//------------------------------------------------------------------------------

void ClassScope::insertLocal ( NameDeclaration *decl ) {

  ST_SENTRY("ClassScope::insertLocal");

  for ( list<NameOccurrence>::iterator it = notFound.begin();
        it != notFound.end();
        ++it ) {
    NameOccurrence &nc = *it;

    if ( decl->isaMatch( &nc ) &&
         ( nc.getLinenum() != decl->getLinenum() ||
           nc.getColnum() != decl->getColnum()
         )
       ) {
      decl->addReference( &nc );
    }
  }
  Scope::insertLocal( decl );

  // if there is an entry in the notFound list with the same
  // token info as decl, then remove it.
  list<NameOccurrence>::iterator it = notFound.begin();
  while ( it != notFound.end() ) {

    if ( it->getName() == decl->getName() ) {
      list<NameOccurrence>::iterator temp = it++;
      notFound.erase( temp );
      if ( getContainingScope() ) {
        getContainingScope()->removeNFFromClass( &( *temp ) );
      }
    }
    else {
      ++it;
    }
  }
}

//------------------------------------------------------------------------------

NameDeclaration* ClassScope::lookup ( NameOccurrence *occur ) {

  ST_SENTRY("ClassScope::lookup");

  list<NameDeclaration *> choices;

  if ( occur->getQualifier() &&
       occur->getName() == occur->getQualifier()->getName()
     ) {
    occur->setName( occur->getName() + "::" + occur->getName() );
  }

  if ( canContain( occur ) )
    choices.push_back( findHere( occur ) );

  // THG - Added fix for destructor.
  if ( occur->getName() == getName() )
    choices.push_back( getDecl() );

  if ( m_tps && !occur->hasQualifier() )
    choices.push_back( m_tps->lookup( occur ) );

  if( hasValidChoice( choices ) )
    return ( Scope::pickBest( choices, occur ) );

  choices.push_back( searchBaseClasses( occur ) );

  if ( hasValidChoice( choices ) )
    return ( Scope::pickBest( choices, occur ) );

  if ( containedIn && !occur->hasQualifier() ) {
    choices.push_back( containedIn->lookup( occur ) );

    // THG - Added for anon namespaces to work
    list<NameDeclaration *> anon = containedIn->getAnonNamespaces();

    for ( list<NameDeclaration *>::iterator it = anon.begin();
          it != anon.end();
          ++it
        ) {

      if ( (*it)->getCorrespondingScope() )
        choices.push_back( (*it)->getCorrespondingScope()->lookup( occur ) );
    }
  }

  return ( Scope::pickBest( choices, occur ) );
}

//------------------------------------------------------------------------------
// THG - Added to support backpatching

void ClassScope::removeNotFound ( NameOccurrence *occur ) {

  ST_SENTRY("ClassScope::removeNotFound");

  for ( list<NameOccurrence>::iterator it = notFound.begin();
        it != notFound.end();
        ++it
      ) {

    if ( it->getColnum() == occur->getColnum() &&
         it->getLinenum() == occur->getLinenum()
       ) {
      notFound.erase( it );
      return;
    }
  }
}

//------------------------------------------------------------------------------

NameDeclaration* ClassScope::searchBaseClasses ( NameOccurrence *occur ) {

  ST_SENTRY("ClassScope::searchBaseClasses");

  list<ClassScope *>::const_iterator ptr = baseClasses.begin();
  list<NameDeclaration *> choices;

  while ( ptr != baseClasses.end() ) {
    choices.push_back( (*ptr)->lookup( occur ) );
    ++ptr;
  }

  return ( Scope::pickBest( choices, occur ) );
}

//------------------------------------------------------------------------------

ostream& ClassScope::Print ( ostream &out ) const {

  ST_SENTRY("ClassScope::Print");

  out << "CLASS: " ;
  Scope::Print( out );

  if ( m_tps ) {
    out << "\tTemplate Parameters: ";
    m_tps->Print( out );
    out << endl;
  }

  if ( baseClasses.size() > 0 ) {
    out << "\tBase class(es): ";
    list<ClassScope *>::const_iterator ptr = baseClasses.begin();

    while ( ptr != baseClasses.end() ) {
      out << (*ptr)->getName() << '\t';
      ++ptr;
    }
    out << endl;
  }

  // THG - Print out friends
  if ( friends.size() > 0 ) {
    out << "\tFriend(s): ";
    list<string>::const_iterator ptr = friends.begin();

    while ( ptr != friends.end() ) {
      out << *ptr << '\t';
      ++ptr;
    }
    out << endl;
  }

  #if 0
  if( notFound.size() > 0 ) {
    out << "\tUnresolved: " << endl;
    list<NameOccurrence>::const_iterator ptr = notFound.begin();
    while( ptr != notFound.end() ) {
      out << "\t\t" << *ptr << endl;
      ++ptr;
    }
  }
  #endif

  out << "END OF CLASS SCOPE: " << getName() << endl;

  return ( out );
}

//------------------------------------------------------------------------------
