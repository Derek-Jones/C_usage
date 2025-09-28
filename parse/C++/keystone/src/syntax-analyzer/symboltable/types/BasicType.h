//******************************************************************************
//
//  BasicType.h
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

#ifndef _BASIC_TYPE_H_
#define _BASIC_TYPE_H_

#include "Type.h"

class BasicType : public Type
{
public:

  enum BType
  {
    BT_CHAR,
    BT_UCHAR,
    BT_WCHAR,
    BT_BOOL,
    BT_SHORT,
    BT_USHORT,
    BT_INT,
    BT_LONG,
    BT_ULONG,
    BT_SIGNED,
    BT_UNSIGNED,
    BT_FLOAT,
    BT_DOUBLE,
    BT_LDOUBLE,
    BT_VOID,
    NUM_BT
  };

  BasicType ( BType );
  
  Type* Clone ( void ) const { return ( new BasicType( m_type ) ); }

  NameDeclaration* getDecl ( void ) const { return ( 0 ); }

  bool checkType      ( DynType    ) const;
  bool checkBasicType ( BType type ) { return type == m_type; }
  BType getBType ( void ) const { return m_type; }

  std::ostream& Print ( std::ostream & ) const;

private:
  BType m_type;
};

#endif
