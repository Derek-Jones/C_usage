//******************************************************************************
//
//  PrototypeScope.cpp
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

#include "PrototypeScope.h"
#include "ClassScope.h"
#include "TemplateParameterScope.h"

using std::endl;
using std::list;
using std::ostream;

//------------------------------------------------------------------------------

PrototypeScope::PrototypeScope ( NameDeclaration *n, Scope *ptr )
               : Scope ( n,
                         ( dynamic_cast<TemplateParameterScope*>(ptr)
                           ? ptr->getContainingScope()
                           : ptr
                         )
                       ),
                 m_tps ( 0 )
{ }

//------------------------------------------------------------------------------

bool PrototypeScope::canContain ( NameOccurrence *occur ) const {

  ST_SENTRY("PrototypeScope::canContain");

  switch ( occur->getSpec() ) {
    case NameOccurrence::nothing: return ( true );
    default                     : return ( false );
  }
}

//------------------------------------------------------------------------------

NameDeclaration* PrototypeScope::lookup ( NameOccurrence *occur ) {

  ST_SENTRY( "PrototypeScope::lookup" );

  list<NameDeclaration *> choices;

  if ( m_tps )
    choices.push_back( m_tps->lookup( occur ) );

  choices.push_back( Scope::lookup( occur ) );
  choices.push_back( getContainingScope()->lookup( occur ) );

  if ( getDecl()->getOccurQual() &&
       dynamic_cast<ClassScope *>( getDecl()->getOccurQual()->getCorrespondingScope() )
     ) {
    choices.push_back( getDecl()->getOccurQual()->getCorrespondingScope()->lookup( occur ) );
  }

  return ( Scope::pickBest( choices, occur ) );
}

//------------------------------------------------------------------------------

ostream& PrototypeScope::Print ( ostream &out ) const {

  ST_SENTRY("PrototypeScope::Print");

  out << "FN PROTOTYPE: ";
  Scope::Print( out );
  if ( m_tps ) {
    out << "\tTemplate Parameters: ";
    m_tps->Print( out );
  }
  out << "END OF PROTOTYPE SCOPE: " << getName() << endl;

  return ( out );
}

//------------------------------------------------------------------------------
