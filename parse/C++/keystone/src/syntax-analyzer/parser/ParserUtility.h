//******************************************************************************
//
//  ParserUtility.h
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

#ifndef _PARSER_UTILITY_H_
#define _PARSER_UTILITY_H_

#include <utility>
#include <vector>

class cAsgNode;
class cExpressionBase;
class cType;

enum eDeclSpecifier
{
  // storage-class-specifier
  DS_AUTO, DS_REGISTER, DS_STATIC, DS_EXTERN, DS_MUTABLE,

  // type-specifier
  DS_TYPE_SPECIFIER,
  DS_CONST, DS_VOLATILE,

  // function-specifier
  DS_INLINE, DS_VIRTUAL, DS_EXPLICIT,

  DS_FRIEND, DS_TYPEDEF
};

enum eLiteralType
{
  LT_INT, LT_REAL, LT_STR, LT_CHAR, LT_BOOL, LT_MEM
};

typedef std::pair<eDeclSpecifier, cType*> DeclSpecifier_t;
typedef std::vector<DeclSpecifier_t*>     DeclSpecifierList_t;

typedef std::vector<cExpressionBase*> ArrayDimensionList_t;
typedef std::vector<int>              PointerCalculationList_t;

typedef std::pair<PointerCalculationList_t*, ArrayDimensionList_t*> NewDeclarationPair_t;

typedef std::pair<cAsgNode*, bool> ClassPair_t;
typedef std::vector<ClassPair_t*>  ClassPairList_t;

#endif

