//******************************************************************************
//
//  Scope.cpp
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

#include "Access.h"
#include "NameDeclaration.h"
#include "NameOccurrence.h"
#include "Type.h"

#include "Scope.h"
#include "ClassScope.h"
#include "NamespaceScope.h"

using std::cout;
using std::endl;
using std::list;
using std::ostream;
using std::set;
using std::string;

//------------------------------------------------------------------------------
// Static Public Members
//------------------------------------------------------------------------------

set<Scope *> Scope::scope_searched_set;

//------------------------------------------------------------------------------
// Static Methods
//------------------------------------------------------------------------------

bool Scope::occurAsClass ( NameDeclaration *decl, NameOccurrence *occur )
{
  if ( ( decl->getType() && 
         ( decl->getType()->checkType( Type::DT_CLASS ) ||
           decl->getType()->checkType( Type::DT_ENUM ) )
       ) &&
       occur->getSpec()!= NameOccurrence::ElabClass &&
       occur->getSpec()!= NameOccurrence::ElabEnum &&
       occur->getSpec()!= NameOccurrence::Destructor
     )
  { 
    return ( true );
  }

  return ( false );
}

//------------------------------------------------------------------------------

NameDeclaration* Scope::pickBest( list<NameDeclaration *> &decls, NameOccurrence *occur )
{
  NameDeclaration *first = 0;

  for ( list<NameDeclaration *>::iterator it = decls.begin();
        it != decls.end();
        ++it
      )
  {
    if ( *it )
    {
      if ( !occurAsClass( *it, occur ) )
      {
        return ( *it );
      }
      if ( !first )
      {
        first = *it;
      }
    }
  }

  return ( first );
}

//------------------------------------------------------------------------------
// Constructor
//------------------------------------------------------------------------------

Scope::Scope ( NameDeclaration *n, Scope *ptr )
      : name        ( n   ),
        containedIn ( ptr )
{
  if ( n )
    n->setCorrespondingScope( this );
}

//------------------------------------------------------------------------------
// Accessor Methods
//------------------------------------------------------------------------------

// THG - Added to handle anonymous namespaces

list<NameDeclaration *> Scope::getAnonNamespaces ( void ) const {

  ST_SENTRY( "Scope::getAnonNamespaces" );

  list<NameDeclaration *> retval;

  for ( list<NameDeclaration *>::const_iterator it = locals.begin();
        it != locals.end();
        ++it
      ) {

    if ( (*it)->getName() == "anon" &&
         dynamic_cast<NamespaceScope *>( (*it)->getCorrespondingScope() )
       ) {
      retval.push_back( *it );
    }
  }

  return ( retval );
}

//------------------------------------------------------------------------------

string Scope::getName ( void ) const {

  if ( name == 0 )
    return ( "none" );
  else
    return ( name->getName() );
}   

//------------------------------------------------------------------------------
// Mutator Methods
//------------------------------------------------------------------------------

NameDeclaration* Scope::findHere ( NameOccurrence *occur ) {

  ST_SENTRY( "Scope::findHere" );

  NameDeclaration *occur_as_class = 0;  // name hiding 3.3.7/2

  list<NameDeclaration *>::const_iterator ptr = locals.begin();

  while ( ptr != locals.end() )
  {
    if ( (*ptr)->isaMatch( occur ) )
    {
      if ( occurAsClass( *ptr, occur ) )
      {
        occur_as_class = *ptr;
      }
      else
      {
        return ( *ptr );
      }
    }
    ++ptr;
  }

  return ( occur_as_class );
}

//------------------------------------------------------------------------------

void Scope::insertLocal ( NameDeclaration *decl ) {

  ST_SENTRY("Scope::insertLocal");

  MAKE_ASSERTION( decl != 0, "decl to insert was NULL." );

  locals.push_back( decl ); 
  decl->makeInSymbolTable();
  decl->setContainingScope( this );

  // THG - Added this for backpatching
  NameOccurrence occur( decl );
  removeNFFromClass( &occur );
}

//------------------------------------------------------------------------------

NameDeclaration* Scope::lookup ( NameOccurrence *occur ) {

  ST_SENTRY("Scope::lookup");

  MAKE_ASSERTION( !occur->hasQualifier(),
                  "Cannot lookup an occurrence with a qualifier." );

  list<NameDeclaration *> choices;

  if ( canContain( occur ) ) {
    choices.push_back( findHere( occur ) );
  }

  if ( containedIn ) {
    choices.push_back( containedIn->lookup(occur) );
    // THG - Added for anon namespaces to work
    list<NameDeclaration *> anon = containedIn->getAnonNamespaces();

    for( list<NameDeclaration *>::iterator it = anon.begin();
         it != anon.end();
         ++it
       ) {
      choices.push_back( (*it)->getCorrespondingScope()->lookup( occur ) );
    }
  }

  return ( Scope::pickBest( choices, occur ) );
}

//------------------------------------------------------------------------------

void Scope::removeDeclaration ( NameDeclaration *decl ) {

  ST_SENTRY( "Scope::removeDeclaration" );

  for ( list<NameDeclaration *>::iterator it = locals.begin();
        it != locals.end();
        ++it
      ) {
    if ( *it == decl ) {
      locals.erase( it );
      return;
    }
  }
}

//------------------------------------------------------------------------------
// THG - provide the ability to remove not found entries from classes
// THG - Added this for backpatching

void Scope::removeNFFromClass ( NameOccurrence *occur ) {

  ST_SENTRY("Scope::removeNFFromClass");

  Scope *s = this;

  while ( s != 0 ) {
    ClassScope *cs = dynamic_cast<ClassScope *>(s);

    if ( cs != 0 ) {
      cs->removeNotFound( occur );
    }

    s = s->getContainingScope();
  }  
}

//------------------------------------------------------------------------------

void Scope::undoRecentInsertLocal ( NameDeclaration *decl ) {

  ST_SENTRY( "Scope::undoRecentInsertLocal" );

  MAKE_ASSERTION( !locals.empty(),
                  "Cannot undoRecentInsertLocal because locals list is empty." );

  MAKE_ASSERTION( locals.back() == decl,
                  "undoRecentInsertLocal got a decl different from that expected." );

  locals.pop_back();
}

//------------------------------------------------------------------------------

ostream& Scope::Print( ostream &out ) const {

  ST_SENTRY("Scope::Print");

  if ( name )
    out << *name;

  if ( containedIn )
    out << " in " << containedIn->getName();

  if ( locals.size() == 0 ) 
    out << endl << "\t...no locals!";

  for ( list<NameDeclaration *>::const_iterator ptr = locals.begin();
        ptr != locals.end();
        ++ptr
      ) {
    out << endl << '\t' << (**ptr);
  }
  out << endl;

  return ( out );
}

//------------------------------------------------------------------------------

ostream& operator<< ( ostream &out, const Scope &scope ) {
  return ( scope.Print( out ) );
}

//------------------------------------------------------------------------------
