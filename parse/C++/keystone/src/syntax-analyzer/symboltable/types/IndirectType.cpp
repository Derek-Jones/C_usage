//******************************************************************************
//
//  IndirectType.cpp
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
#include "IndirectType.h"
#include "NameDeclaration.h"

using std::endl;
using std::ostream;

//------------------------------------------------------------------------------

IndirectType::IndirectType ( NameDeclaration *decl, Type *pointed_to, IType ind_type )
             : m_decl  ( decl ),
               m_type  ( pointed_to ),
               m_itype ( ind_type )
{ }

//------------------------------------------------------------------------------

bool IndirectType::checkType ( Type::DynType type ) const
{
  return ( type == DT_INDIRECT );
}

//------------------------------------------------------------------------------

ostream& IndirectType::Print ( ostream &out ) const {

  //  MAKE_ASSERTION( m_type, "Referenced Type is NULL" );

  if ( getReferencedType() )
    out << *getReferencedType();
  else
    out << "NO REFERENCED TYPE!" << endl;

  switch( getIndirectionType() )
  {
    case IT_ARRAY:     out << "[]"; break;
    case IT_POINTER:   out << "*";  break;
    case IT_REFERENCE: out << "&";  break;
    default:           MAKE_ASSERTION( 0, "Invalid Indirection Type" );
  }

  return out;
}

//------------------------------------------------------------------------------
