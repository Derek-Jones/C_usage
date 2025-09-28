//******************************************************************************
//
//  Kind.cpp
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

#include "Kind.h"

using std::ostream;

ostream& operator<< ( ostream &out, const Kind::KType &kind )
{
  switch ( kind )
  {
    case Kind::Class            : out << "Class";             break;
    case Kind::Enum             : out << "Enum";              break;
    case Kind::Function         : out << "Function";          break;
    case Kind::FunctionPrototype: out << "FunctionPrototype"; break;
    case Kind::Label            : out << "Label";             break;
    case Kind::Namespace        : out << "Namespace";         break;
    case Kind::Variable         : out << "Variable";          break;
    case Kind::Typedef          : out << "Typedef";           break;
    default                     : out << "No Such Kind";      break;
  }

  return ( out );
}
