//******************************************************************************
//
//  ScopeInvariantFacilitator.cpp
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

#include "ScopeInvariantFacilitator.h"
#include "ScopeInvariantVisitor.h"

#include "Scope.h"
#include "ClassScope.h"
#include "FunctionScope.h"
#include "LocalScope.h"
#include "NamespaceScope.h"
#include "PrototypeScope.h"
#include "TemplateParameterScope.h"

using std::cout;
using std::endl;
using std::vector;

//------------------------------------------------------------------------------

vector<ScopeInvariantFacilitator *> ScopeInvariantFacilitator::s_ptrs;

//------------------------------------------------------------------------------

void ScopeInvariantFacilitator::CheckStoredClassesInvariants ( void ) {

  for ( vector<ScopeInvariantFacilitator*>::iterator it = s_ptrs.begin();
        it != s_ptrs.end();
        ++it
      ) {

    if ( *it )
      (*it)->CheckInvariants();
  }

  cout << "ScopeInvariants: " << s_ptrs.size() << endl;
}

//------------------------------------------------------------------------------

ScopeInvariantFacilitator::ScopeInvariantFacilitator ( ) {
  m_idx = s_ptrs.size();
  s_ptrs.push_back( this );
}

//------------------------------------------------------------------------------

ScopeInvariantFacilitator::~ScopeInvariantFacilitator ( ) {
  s_ptrs[m_idx] = 0;
}

//------------------------------------------------------------------------------

void ScopeInvariantFacilitator::CheckInvariants ( void ) const {
  ScopeInvariantVisitor v;
  Accept( &v );
}

//------------------------------------------------------------------------------

void ScopeInvariantFacilitator::Accept ( Visitor *v ) const {

  if ( const TemplateParameterScope *self = dynamic_cast<const TemplateParameterScope *>( this ) )
    v->Visit( self );

  else if ( const ClassScope *self = dynamic_cast<const ClassScope *>( this ) )
    v->Visit( self );

  else if ( const NamespaceScope *self = dynamic_cast<const NamespaceScope *>( this ) )
    v->Visit( self );

  else if ( const LocalScope *self = dynamic_cast<const LocalScope *>( this ) )
    v->Visit( self );

  else if ( const PrototypeScope *self = dynamic_cast<const PrototypeScope *>( this ) )
    v->Visit( self );

  else if ( const FunctionScope *self = dynamic_cast<const FunctionScope *>( this ) )
    v->Visit( self );

  else if ( const Scope *self = dynamic_cast<const Scope *>( this ) )
    v->Visit( self );

}

//------------------------------------------------------------------------------
