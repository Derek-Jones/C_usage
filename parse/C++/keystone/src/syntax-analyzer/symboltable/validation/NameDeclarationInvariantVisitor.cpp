//******************************************************************************
//
//  NameDeclarationInvariantVisitor.cpp
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
#include "NameDeclarationInvariantVisitor.h"
#include "NameOccurrence.h"
#include "Visitor.h"

#include "Type.h"

#include "Scope.h"
#include "ClassScope.h"
#include "FunctionScope.h"
#include "LocalScope.h"
#include "NamespaceScope.h"
#include "PrototypeScope.h"

void NameDeclarationInvariantVisitor::Visit ( const NameDeclaration *self ) {

  assert( !( self->getContainingScope() != 0 ) ||
           ( self->getContainingScope() != self->getCorrespondingScope() )
        );

  #if 0
  assert( self->getAccess() == Access::None &&
          self->isAttributeSet( Attribute::Friend ) ||
          self->getAccess() == Access::None ^
          ( dynamic_cast<const ClassScope *>( self->getContainingScope() ) != 0 )
        );
  #endif

  assert( !( dynamic_cast<const LocalScope *>( self->getCorrespondingScope() ) != 0 ) );

  // temporary hack
  if ( self->getType() ) {
    assert( !( self->getType()->checkType( Type::DT_CLASS ) && self->isInstance() ) ||
               self->getCorrespondingScope() == 0
          );

    assert( !( self->getType()->checkType( Type::DT_NAMESPACE ) ) ||
             dynamic_cast<const NamespaceScope *>( self->getCorrespondingScope() ) != 0
          );

    assert( !( self->getType()->checkType( Type::DT_FUNCTION ) ) ||
             ( dynamic_cast<const FunctionScope  *>( self->getCorrespondingScope() ) != 0 ) ||
             ( dynamic_cast<const PrototypeScope *>( self->getCorrespondingScope() ) != 0 ) ||
             ( self->getCorrespondingScope() == 0 )
          );

    assert( !( self->getType()->checkType( Type::DT_FUNCTION_PROTOTYPE ) ) ||
             ( dynamic_cast<const PrototypeScope *>( self->getCorrespondingScope() ) != 0 ) ||
             ( self->getCorrespondingScope() == 0 )
          );

    assert( !( self->getType()->checkType( Type::DT_FUNCTION_DEFINITION ) ) ||
             ( dynamic_cast<const FunctionScope *>( self->getCorrespondingScope() ) != 0 ) ||
             ( self->getCorrespondingScope() == 0 )
          );

    assert( !( self->isAttributeSet( Attribute::Virtual ) ) ||
             ( dynamic_cast<const ClassScope *>( self->getContainingScope() ) != 0  &&
             ( self->getType()->checkType( Type::DT_FUNCTION ) ) )
          ); // &&
           //(!(self->isAttributeSet( Attribute::Static )))));

    assert( !( self->isAttributeSet( Attribute::Pure) ) ||
               self->isAttributeSet( Attribute::Virtual )
          );

    assert( !( self->isAttributeSet( Attribute::Friend ) ) ||
             ( ( self->getType()->checkType( Type::DT_FUNCTION ) ) ||
               ( self->getType()->checkType( Type::DT_CLASS ) )
             )
          );

    assert( !( self->isAttributeSet( Attribute::Static ) ) ||
             ( !self->getType()->checkType( Type::DT_NAMESPACE ) )
          );
  }

  assert( !( self->isAttributeSet( Attribute::Const ) ) ||
           ( self->isInstance() ||
             self->getType()->checkType( Type::DT_FUNCTION )
           )
        );
}

//------------------------------------------------------------------------------
