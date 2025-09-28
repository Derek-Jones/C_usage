//******************************************************************************
//
//  SchemaAliases.h
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

#ifndef _SCHEMA_ALIASES_H_
#define _SCHEMA_ALIASES_H_

#include <string>
#include <utility>
#include <vector>

typedef std::string String;

typedef std::vector<cAsgNode*>        AsgNodeList_t;
typedef std::vector<cExpressionBase*> ExpressionList_t;

typedef std::vector<cEnumerator*> EnumeratorList_t;
typedef std::vector<cObject*>     ObjectList_t;

typedef std::vector<cFunctionParameter*> FunctionParameterList_t;
typedef ExpressionList_t                 ArgumentList_t;

/// < access, isVirtual >
typedef std::pair<eAccessSpecifier, bool> InheritanceSpecifierPair_t;
typedef std::pair<cNameReference*, InheritanceSpecifierPair_t> BaseClassPair_t;

typedef std::vector<BaseClassPair_t>      BaseClassList_t;
typedef AsgNodeList_t                     MemberList_t;
typedef std::vector<cClassTypeInterface*> DerivedClassList_t;
typedef AsgNodeList_t                     FriendList_t;

/// Templates
typedef std::vector<cTemplateParameter*> TemplateParameterList_t;
typedef AsgNodeList_t                    TemplateArgumentList_t;

/// Exceptions
typedef std::vector<cType*>    ThrowList_t;
typedef std::vector<cHandler*> HandlerList_t;

#endif

