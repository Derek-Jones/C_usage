//******************************************************************************
//
//  SchemaEnum2String.h
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
///\author Nicholas A. Kraft

#ifndef _SCHEMA_ENUM_2_STRING_H_
#define _SCHEMA_ENUM_2_STRING_H_

#include "SchemaEnums.h"

struct SchemaEnum2String
{
  std::string operator() ( eClassKey        );
  std::string operator() ( eAccessSpecifier );
  std::string operator() ( eOperator        );
  std::string operator() ( eFunctionKey     );
};

inline std::ostream& operator<< ( std::ostream& o, eClassKey aKey )
{
  SchemaEnum2String e2s;
  o << e2s( aKey );
  return o;
}

inline std::ostream& operator<< ( std::ostream& o, eAccessSpecifier aSpec )
{
  SchemaEnum2String e2s;
  o << e2s( aSpec );
  return o;
}

inline std::ostream& operator<< ( std::ostream& o, eOperator aOp )
{
  SchemaEnum2String e2s;
  o << e2s( aOp );
  return o;
}

inline std::ostream& operator<< ( std::ostream& o, eFunctionKey aKey )
{
  SchemaEnum2String e2s;
  o << e2s( aKey );
  return o;
}

#endif

