//******************************************************************************
//
//  BasicType.cpp
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
#include <string>

#include "BasicType.h"
#include "NameDeclaration.h"

using std::ostream;
using std::string;

//------------------------------------------------------------------------------

BasicType::BasicType ( BType type )
          : m_type ( type )
{ }

//------------------------------------------------------------------------------

bool BasicType::checkType ( Type::DynType type ) const
{
  return ( type == Type::DT_BASIC );
}

//------------------------------------------------------------------------------

ostream& BasicType::Print ( ostream &out ) const
{
  if( isConst() )
    out << "const ";

  string to_print;

  switch ( m_type )
  {
    case BT_VOID:     to_print = "void";           break;
    case BT_BOOL:     to_print = "bool";           break;
    case BT_CHAR:     to_print = "char";           break;
    case BT_UCHAR:    to_print = "unsigned char";  break;
    case BT_WCHAR:    to_print = "wchar_t";        break;
    case BT_SHORT:    to_print = "short";          break;
    case BT_USHORT:   to_print = "unsigned short"; break;
    case BT_INT:      to_print = "int";            break;
    case BT_SIGNED:   to_print = "int";            break;
    case BT_UNSIGNED: to_print = "unsigned int";   break;
    case BT_LONG:     to_print = "long";           break;
    case BT_ULONG:    to_print = "unsigned long";  break;
    case BT_FLOAT:    to_print = "float";          break;
    case BT_DOUBLE:   to_print = "double";         break;
    case BT_LDOUBLE:  to_print = "long double";    break;
    default:          to_print = "unknown basic type";
  }
  out << to_print;

  return out;
}

//------------------------------------------------------------------------------
