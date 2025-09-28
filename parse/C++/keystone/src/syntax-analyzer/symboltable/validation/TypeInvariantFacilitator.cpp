//******************************************************************************
//
//  TypeInvariantFacilitator.cpp
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

#include "TypeInvariantFacilitator.h"
#include "Type.h"
#include "BasicType.h"
#include "ClassType.h"
#include "EnumType.h"
#include "FunctionType.h"
#include "IndirectType.h"
#include "NamespaceType.h"
#include "TypeInvariantVisitor.h"

using std::cout;
using std::endl;
using std::vector;

//------------------------------------------------------------------------------

vector<TypeInvariantFacilitator *> TypeInvariantFacilitator::s_ptrs;

//------------------------------------------------------------------------------

TypeInvariantFacilitator::TypeInvariantFacilitator ( ) {
  m_idx = s_ptrs.size();
  s_ptrs.push_back( this );
}

//------------------------------------------------------------------------------

TypeInvariantFacilitator::~TypeInvariantFacilitator ( ) {
  s_ptrs[m_idx] = 0;
}

//------------------------------------------------------------------------------

void TypeInvariantFacilitator::CheckInvariants ( void ) const {
  TypeInvariantVisitor v;
  Accept( &v );
}

//------------------------------------------------------------------------------

void TypeInvariantFacilitator::CheckStoredClassesInvariants ( void ) {

  for ( vector<TypeInvariantFacilitator *>::iterator it = s_ptrs.begin();
        it != s_ptrs.end();
        ++it
      ) {
    if ( *it )
      (*it)->CheckInvariants();
  }
  cout << "TypeInvariants: " << s_ptrs.size() << endl;
}

//------------------------------------------------------------------------------

void TypeInvariantFacilitator::Accept ( Visitor *v ) const {

  if ( const FunctionType *self = dynamic_cast<const FunctionType *>( this ) )
    v->Visit( self );
  else if ( const ClassType *self = dynamic_cast<const ClassType *>( this ) )
    v->Visit( self );
  else if ( const EnumType *self = dynamic_cast<const EnumType *>( this ) )
    v->Visit( self );
  else if ( const NamespaceType *self = dynamic_cast<const NamespaceType *>( this ) )
    v->Visit( self );
  else if ( const IndirectType *self = dynamic_cast<const IndirectType *>( this ) )
    v->Visit( self );
  else if ( const BasicType *self = dynamic_cast<const BasicType *>( this ) )
    v->Visit( self );
  else if ( const Type *self = dynamic_cast<const Type *>( this ) )
    v->Visit( self );
}

//------------------------------------------------------------------------------
