//******************************************************************************
//
//  SchemaEnums.h
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

#ifndef _SCHEMA_ENUMS_H_
#define _SCHEMA_ENUMS_H_

// A.8
enum eClassKey
{
  AT_CLASS, AT_STRUCT, AT_UNION
};

// A.9
enum eAccessSpecifier
{
  VB_PRIVATE, VB_PROTECTED, VB_PUBLIC, VB_UNKNOWN
};

// A.11
enum eOperator
{
  OT_UPLUS,        OT_UMINUS,         OT_PRE_INC,      OT_PRE_DEC,
  OT_POST_INC,     OT_POST_DEC,       OT_BPLUS,        OT_BMINUS,
  OT_MODULO,       OT_MULT,           OT_DIV,          OT_BIT_AND,
  OT_BIT_OR,       OT_BIT_XOR,        OT_RSHIFT,       OT_LSHIFT,
  OT_BIT_NOT,      OT_TST_EQ,         OT_TST_NE,       OT_TST_GE,
  OT_TST_LE,       OT_TST_GT,         OT_TST_LT,       OT_NOT,
  OT_AND,          OT_OR,             OT_ASGN_EQ,      OT_ASGN_PLUS,
  OT_ASGN_MINUS,   OT_ASGN_MULT,      OT_ASGN_DIV,     OT_ASGN_MOD,
  OT_ASGN_LSHIFT,  OT_ASGN_RSHIFT,    OT_ASGN_BIT_AND, OT_ASGN_BIT_OR,
  OT_ASGN_BIT_XOR, OT_QUESTION,       OT_ADDR,         OT_DEREF,
  OT_POINTSAT,     OT_POINTSAT_DEREF, OT_ARRAY_REF,    OT_FCT_CALL,
  OT_UPAREN,       OT_CPP_CAST_CALL,  OT_C_CAST_CALL,
  OT_FIELD_ACCESS, OT_FIELD_DEREF,    OT_MEM_INIT,
  OT_SIZEOF,       OT_COMMA,          OT_CONST_CAST,   OT_STATIC_CAST,
  OT_REINT_CAST,   OT_DYNAM_CAST,     OT_TYPE_ID,      OT_RANGE
};

enum eFunctionKey
{
  FK_MEMBER, FK_CONSTRUCTOR, FK_DESTRUCTOR, FK_CONVERSION, FK_OPERATOR, FK_FREE
};

#endif

