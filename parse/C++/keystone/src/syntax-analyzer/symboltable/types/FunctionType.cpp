//******************************************************************************
//
//  FunctionType.cpp
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

#include "Assertion.h"
#include "FunctionType.h"
#include "NameDeclaration.h"

#include "Scope.h"
#include "FunctionScope.h"
#include "PrototypeScope.h"

using std::ostream;

//------------------------------------------------------------------------------

FunctionType::FunctionType ( NameDeclaration *d, Type *t, Qual q ) 
             : m_decl ( d ),
               m_ty   ( t ),
               m_qual ( q ) 
{
  MAKE_ASSERTION( d, "Function Type given a NULL declaration" );
}

//------------------------------------------------------------------------------

bool FunctionType::checkType ( Type::DynType type ) const
{
  bool retval = false;

  if ( type == DT_FUNCTION )
    retval = true;

  if ( type == DT_FUNCTION_PROTOTYPE )
    retval = ( m_qual == Q_PROTOTYPE );

  if ( type == DT_FUNCTION_DEFINITION )
    retval = ( m_qual == Q_FUNCTION );

  return retval;
}

//------------------------------------------------------------------------------

void FunctionType::makeFunction ( void )
{
  m_qual = Q_FUNCTION;
}

//------------------------------------------------------------------------------

NameDeclaration* FunctionType::getDecl ( void ) const
{
  return m_decl;
}

//------------------------------------------------------------------------------

void FunctionType::setDecl ( NameDeclaration *d )
{
  m_decl = d;
}

//------------------------------------------------------------------------------

ostream& FunctionType::Print ( ostream &out ) const
{
  MAKE_ASSERTION( m_decl, "Declaration is NULL" );

  out << "function( ";
  Scope *proto = 0;

  if ( FunctionScope *fs = dynamic_cast<FunctionScope *>( getDecl()->getCorrespondingScope() ) )
  {
    proto = fs->getPrototypeScope();
  }
  else if( PrototypeScope *ps = dynamic_cast<PrototypeScope *>(getDecl()->getCorrespondingScope() ) )
  {
    proto = ps;
  }

  if ( proto )
  {
    for ( std::list<NameDeclaration*>::const_iterator ci = proto->getLocals()->begin();
          ci != proto->getLocals()->end();
          ++ci
        )
    {
      out << *((*ci)->getType());
      std::list<NameDeclaration *>::const_iterator ci2 = ci;
      if( ++ci2 != proto->getLocals()->end() )
        out << ",";
    }
  }  
  out << " ) : ";

  if ( m_ty )
    out << *m_ty;
  else
    out << "NO RETURN TYPE!";

  return out;
}

//------------------------------------------------------------------------------

Type* FunctionType::getReturnType ( void ) const
{
  return m_ty;
}

//------------------------------------------------------------------------------
