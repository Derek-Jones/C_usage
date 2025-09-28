//******************************************************************************
//
//  NameDeclarationInvariantFacilitator.cpp
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

#include "NameDeclaration.h"
#include "NameDeclarationInvariantFacilitator.h"
#include "NameDeclarationInvariantVisitor.h"

using std::cout;
using std::endl;
using std::vector;

//------------------------------------------------------------------------------
// Static Members/Methods
//------------------------------------------------------------------------------

vector<NameDeclarationInvariantFacilitator *> NameDeclarationInvariantFacilitator::s_ptrs;

//------------------------------------------------------------------------------

void NameDeclarationInvariantFacilitator::CheckStoredClassesInvariants ( void ) {

  for ( vector<NameDeclarationInvariantFacilitator*>::iterator it = s_ptrs.begin();
        it != s_ptrs.end();
        ++it
      ) {

    if ( *it )
      (*it)->CheckInvariants();
  }

  cout << "NameDeclarationInvariants: " << s_ptrs.size() << endl;
}

//------------------------------------------------------------------------------

NameDeclarationInvariantFacilitator::NameDeclarationInvariantFacilitator ( ) {
  m_idx = s_ptrs.size();
  s_ptrs.push_back( this );
}

//------------------------------------------------------------------------------

NameDeclarationInvariantFacilitator::~NameDeclarationInvariantFacilitator ( ) {
  s_ptrs[m_idx] = 0;
}

//------------------------------------------------------------------------------

void NameDeclarationInvariantFacilitator::CheckInvariants ( void ) const {
  NameDeclarationInvariantVisitor v;
  Accept( &v );
}

//------------------------------------------------------------------------------

void NameDeclarationInvariantFacilitator::Accept(Visitor* v) const {

  if ( const NameDeclaration *self = dynamic_cast<const NameDeclaration *>( this ) )
    v->Visit( self);
}

//------------------------------------------------------------------------------
