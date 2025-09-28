//******************************************************************************
//
//  ScopeInvariantVisitor.cpp
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
#include "ScopeInvariantVisitor.h"
#include "Type.h"
#include "Visitor.h"

#include "Scope.h"
#include "ClassScope.h"
#include "FunctionScope.h"
#include "LocalScope.h"
#include "NamespaceScope.h"
#include "PrototypeScope.h"
#include "TemplateParameterScope.h"

using std::list;

//------------------------------------------------------------------------------

void ScopeInvariantVisitor::Visit ( Scope *self ) {
  assert( !( self->getDecl() != 0 ) ||
             self->getDecl()->getCorrespondingScope() == self
        );
  assert( self->getContainingScope() != 0 ^ (self->getName() == "_GlobalNamespace") );
  assert( priv_forall_0( self ) );
}

//------------------------------------------------------------------------------

void ScopeInvariantVisitor::Visit ( ClassScope *self ) {
  assert( priv_forall_3( self ) );
  assert( dynamic_cast<const NamespaceScope *>( self->getContainingScope() ) != 0 ||
          ( dynamic_cast<const ClassScope *>( self->getContainingScope() ) != 0 ) ||
          ( dynamic_cast<const LocalScope *>( self->getContainingScope() ) != 0 )
        );
}

//------------------------------------------------------------------------------

void ScopeInvariantVisitor::Visit ( FunctionScope *self ) {
  assert( self->getPrototypeScope()->getName() == self->getName() );
  assert( dynamic_cast<const NamespaceScope *>( self->getContainingScope() ) != 0 ||
          ( dynamic_cast<const ClassScope *>( self->getContainingScope() ) != 0 )
        );
}

//------------------------------------------------------------------------------

void ScopeInvariantVisitor::Visit ( LocalScope *self ) {
  assert( self->getDecl() == 0 );
  assert( priv_forall_2( self ) );
  assert( dynamic_cast<const FunctionScope *>( self->getContainingScope() ) != 0 ||
          ( dynamic_cast<const LocalScope *>( self->getContainingScope() ) != 0 )
        );
}

//------------------------------------------------------------------------------

void ScopeInvariantVisitor::Visit ( NamespaceScope *self ) {
  assert( dynamic_cast<const NamespaceScope *>( self->getContainingScope() ) != 0 ^
          ( self->getName() == "_GlobalNamespace" )
        );
}

//------------------------------------------------------------------------------

void ScopeInvariantVisitor::Visit ( PrototypeScope *self ) {
  assert( priv_forall_1( self ) );
  assert( dynamic_cast<const NamespaceScope *>( self->getContainingScope() ) != 0 ||
          ( dynamic_cast<const ClassScope *>( self->getContainingScope() ) != 0 ) ||
          ( dynamic_cast<const PrototypeScope *>( self->getContainingScope() ) != 0 ) ||
          ( dynamic_cast<const LocalScope *>( self->getContainingScope() ) != 0 )
        );
}

//------------------------------------------------------------------------------

void ScopeInvariantVisitor::Visit ( TemplateParameterScope *self ) { }

//------------------------------------------------------------------------------

bool ScopeInvariantVisitor::priv_forall_0 ( Scope *self ) const {

  for ( list<NameDeclaration *>::const_iterator priv_forall_temp = self->getLocals()->begin();
        priv_forall_temp != self->getLocals()->end();
        ++priv_forall_temp
      ) {
    NameDeclaration *n = *priv_forall_temp;

    if ( !( n->getContainingScope() == self ) )
      return ( false );
  }

  return ( true );
}

//------------------------------------------------------------------------------

bool ScopeInvariantVisitor::priv_forall_1 ( PrototypeScope *self) const {

  for ( list<NameDeclaration *>::const_iterator priv_forall_temp = self->getLocals()->begin();
        priv_forall_temp != self->getLocals()->end();\
        ++priv_forall_temp
      ) {
    NameDeclaration *n = *priv_forall_temp;

    if ( n->getType()->checkType( Type::DT_NAMESPACE ) )
      return ( false );
  }

  return ( true );
}

//------------------------------------------------------------------------------

bool ScopeInvariantVisitor::priv_forall_2 ( LocalScope *self ) const {

  for ( list<NameDeclaration *>::const_iterator priv_forall_temp = self->getLocals()->begin();
        priv_forall_temp != self->getLocals()->end();
        ++priv_forall_temp
      ) {
    NameDeclaration *n = *priv_forall_temp;

    if ( n->getType()->checkType( Type::DT_NAMESPACE ) )
      return ( false );
  }

  return ( true );
}

//------------------------------------------------------------------------------

bool ScopeInvariantVisitor::priv_forall_3(ClassScope* self) const {

  for ( list<NameDeclaration *>::const_iterator priv_forall_temp = self->getLocals()->begin();
        priv_forall_temp != self->getLocals()->end();
        ++priv_forall_temp
      ) {
    NameDeclaration *n = *priv_forall_temp;

    if ( n->getType()->checkType( Type::DT_NAMESPACE ) )
      return ( false );
  }

  return ( true );
}

//------------------------------------------------------------------------------
