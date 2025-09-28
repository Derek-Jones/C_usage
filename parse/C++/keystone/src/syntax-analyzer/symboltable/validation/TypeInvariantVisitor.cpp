//******************************************************************************
//
//  TypeInvariantVisitor.cpp
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

#include <cassert>

#include "NameDeclaration.h"
#include "TypeInvariantVisitor.h"
#include "Type.h"
#include "BasicType.h"
#include "ClassType.h"
#include "EnumType.h"
#include "FunctionType.h"
#include "IndirectType.h"
#include "NamespaceType.h"

//------------------------------------------------------------------------------

void TypeInvariantVisitor::Visit ( const Type * ) { }

//------------------------------------------------------------------------------

void TypeInvariantVisitor::Visit ( const BasicType *self ) {
  assert( self->getDecl() == 0 );
}

//------------------------------------------------------------------------------

void TypeInvariantVisitor::Visit ( const FunctionType *self ) {
  assert( self->getDecl() );
  assert( self->getDecl()->getType() );
  assert( self->getReturnType() );
  assert( !self->getDecl()->getType()->checkType( Type::DT_NAMESPACE ) );
  assert( !self->getReturnType()->checkType( Type::DT_NAMESPACE ) );
}

//------------------------------------------------------------------------------

void TypeInvariantVisitor::Visit ( const IndirectType *self ) {
  assert( self->getReferencedType() );
  //  self->getReferencedType()->CheckInvariants();
}

//------------------------------------------------------------------------------

void TypeInvariantVisitor::Visit ( const ClassType *self ) {
  assert( self->getDecl()->getType()->checkType( Type::DT_CLASS ) );
}

//------------------------------------------------------------------------------

void TypeInvariantVisitor::Visit ( const EnumType *self ) {
  assert( self->getDecl()->getType()->checkType( Type::DT_ENUM ) );
}

//------------------------------------------------------------------------------

void TypeInvariantVisitor::Visit ( const NamespaceType *self ) {
  assert( self->getDecl()->getType()->checkType( Type::DT_NAMESPACE ) );
}

//------------------------------------------------------------------------------
