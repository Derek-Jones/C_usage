//******************************************************************************
//
//  LookupController.h
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

#ifndef _LOOKUP_CONTROLLER_H_
#define _LOOKUP_CONTROLLER_H_

#include <string>
#include <vector>

class ClassScope;
class ContextManager;
class NameDeclaration;
class NameOccurrence;
class Scope;
class Type;

class LookupController {
public:
  LookupController ( ContextManager * );

  NameDeclaration* lookupUnqualifiedName  ( NameOccurrence * ) const; 
  NameDeclaration* lookupQualifiedName    ( NameOccurrence * ) const; 
  NameDeclaration* lookupMemberName       ( NameDeclaration *, NameDeclaration * ) const ;
  NameDeclaration* lookupPseudoDestructor ( NameDeclaration *, NameDeclaration * ) const ;
  NameDeclaration* lookupFunctionCall     ( NameDeclaration *, std::vector<NameDeclaration *> ) const ;
  NameDeclaration* lookupUnaryOp          ( std::string *, NameDeclaration * ) const;
  NameDeclaration* lookupBinOp            ( std::string *, NameDeclaration *, NameDeclaration * ) const;
  void setAdditionalLookupScope           ( Scope * );

private:
  ContextManager *contextManager;
  Scope          *additional_scope;

  ClassScope*      getClassScope    ( NameDeclaration * ) const;
  NameDeclaration* redoMemberLookup ( ClassScope *, NameDeclaration * ) const; 
  Scope*           getScopeForArg   ( Type * ) const;

};

#endif
