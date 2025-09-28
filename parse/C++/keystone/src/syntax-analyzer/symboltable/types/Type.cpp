//******************************************************************************
//
//  Type.cpp
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

#include "Type.h"

using std::ostream;

//------------------------------------------------------------------------------

Type::Type ( )
     : m_const    ( false ),
       m_volatile ( false )
{ }

//------------------------------------------------------------------------------

bool Type::isConst ( void ) const
{
  return ( m_const );
}

//------------------------------------------------------------------------------

void Type::makeConst ( void )
{
  m_const = true;
}

//------------------------------------------------------------------------------

bool Type::isVolatile ( void ) const
{
  return ( m_volatile );
}

//------------------------------------------------------------------------------

void Type::makeVolatile ( void )
{
  m_volatile = true;
}

//------------------------------------------------------------------------------

ostream& operator<< ( ostream &out, const Type &t )
{
  return ( t.Print( out ) );
}

//------------------------------------------------------------------------------
