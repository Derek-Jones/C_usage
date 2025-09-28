//******************************************************************************
//
//  SchemaEnum2String.cpp
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

#include <string>

#include "SchemaEnum2String.h"

//----------------------------------------------------------------------------

std::string SchemaEnum2String::operator() ( eClassKey eck )
{
  switch ( eck )
  {
    case AT_CLASS    : return "class";
    case AT_STRUCT   : return "struct";
    case AT_UNION    : return "union";
    default          : return "";
  }
}

//----------------------------------------------------------------------------

std::string SchemaEnum2String::operator() ( eAccessSpecifier eas )
{
  switch ( eas )
  {
    case VB_PUBLIC    : return "public";
    case VB_PROTECTED : return "protected";
    case VB_PRIVATE   : return "private";
    case VB_UNKNOWN   :
    default           : return "";
  }
}

//----------------------------------------------------------------------------

std::string SchemaEnum2String::operator() ( eOperator eo )
{
  std::string r;
  switch ( eo )
  {
    case OT_UPLUS:
    case OT_BPLUS:          r = "+";                break;
    case OT_UMINUS:
    case OT_BMINUS:         r = "-";                break;
    case OT_PRE_INC:
    case OT_POST_INC:       r = "++";               break;
    case OT_PRE_DEC:
    case OT_POST_DEC:       r = "--";               break;
    case OT_MODULO:         r = "%";                break;
    case OT_MULT:
    case OT_DEREF:          r = "*";                break;
    case OT_DIV:            r = "/";                break;
    case OT_BIT_AND:
    case OT_ADDR:           r = "&";                break;
    case OT_BIT_OR:         r = "|";                break;
    case OT_BIT_XOR:        r = "^";                break;
    case OT_RSHIFT:         r = ">>";               break;
    case OT_LSHIFT:         r = "<<";               break;
    case OT_BIT_NOT:        r = "~";                break;
    case OT_TST_EQ:         r = "==";               break;
    case OT_TST_NE:         r = "!=";               break;
    case OT_TST_GE:         r = ">=";               break;
    case OT_TST_LE:         r = "<=";               break;
    case OT_TST_GT:         r = ">";                break;
    case OT_TST_LT:         r = "<";                break;
    case OT_NOT:            r = "!";                break;
    case OT_AND:            r = "&&";               break;
    case OT_OR:             r = "||";               break;
    case OT_ASGN_EQ:        r = "=";                break;
    case OT_ASGN_PLUS:      r = "+=";               break;
    case OT_ASGN_MINUS:     r = "-=";               break;
    case OT_ASGN_MULT:      r = "*=";               break;
    case OT_ASGN_DIV:       r = "/=";               break;
    case OT_ASGN_MOD:       r = "%=";               break;
    case OT_ASGN_LSHIFT:    r = "<<=";              break;
    case OT_ASGN_RSHIFT:    r = ">>=";              break;
    case OT_ASGN_BIT_AND:   r = "&=";               break;
    case OT_ASGN_BIT_OR:    r = "|=";               break;
    case OT_ASGN_BIT_XOR:   r = "^=";               break;
    case OT_QUESTION:       r = "?:";               break;
    case OT_POINTSAT:       r = "->";               break;
    case OT_POINTSAT_DEREF: r = "->*";              break;
    case OT_ARRAY_REF:      r = "[]";               break;
    case OT_FCT_CALL:
    case OT_UPAREN:         r = "()";               break;
    case OT_C_CAST_CALL:    r = "(cast)";           break;
    case OT_CPP_CAST_CALL:  r = "cast()";           break;
    case OT_FIELD_ACCESS:   r = ".";                break;
    case OT_FIELD_DEREF:    r = ".*";               break;
    case OT_MEM_INIT:       r = "meminit()";        break;
    case OT_SIZEOF:         r = "sizeof";           break;
    case OT_COMMA:          r = ",";                break;
    case OT_CONST_CAST:     r = "const_cast";       break;
    case OT_STATIC_CAST:    r = "static_cast";      break;
    case OT_REINT_CAST:     r = "reinterpret_cast"; break;
    case OT_DYNAM_CAST:     r = "dynamic_cast";     break;
    case OT_TYPE_ID:        r = "typeid";           break;
    case OT_RANGE:          r = "...";              break;
  }
  return r;
}

//----------------------------------------------------------------------------

std::string SchemaEnum2String::operator() ( eFunctionKey efk )
{
  switch ( efk )
  {
    case FK_MEMBER     : return "member";
    case FK_CONSTRUCTOR: return "constructor";
    case FK_DESTRUCTOR : return "destructor";
    case FK_CONVERSION : return "conversion";
    case FK_OPERATOR   : return "operator";
    case FK_FREE       :
    default            : return "";
  }
}

//----------------------------------------------------------------------------

