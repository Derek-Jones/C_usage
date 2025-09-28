//******************************************************************************
//
//  ActionFacade.h
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

#ifndef _ACTION_FACADE_H_
#define _ACTION_FACADE_H_

#include <string>
#include <vector>

#include "Access.h"
#include "LookupController.h"

class ContextManager;
class NameDeclaration;
class Scope;
class TokenInfo;

class ActionFacade
{
public:
  ActionFacade ( ContextManager * );

  // dynamic debugging
  void setDebug ( bool );

  NameDeclaration* lookupUnqualifiedName  ( NameOccurrence * ) const ;
  NameDeclaration* lookupQualifiedName    ( NameOccurrence * ) const ;
  NameDeclaration* lookupMemberName       ( NameDeclaration *, NameDeclaration * ) const ;
  NameDeclaration* lookupPseudoDestructor ( NameDeclaration *, NameDeclaration * ) const ;
  NameDeclaration* lookupFunctionCall     ( NameDeclaration *, std::vector<NameDeclaration *> ) const ;
  NameDeclaration* lookupUnaryOp          ( std::string *, NameDeclaration * );
  NameDeclaration* lookupBinOp            ( std::string *, NameDeclaration *, NameDeclaration * );

  // facilitate mem-init lists
  void relookupUnqualifiedName ( NameDeclaration *& ) const;

  void useNamespace   ( NameDeclaration * ); 
  void useDeclaration ( NameDeclaration * ); 

  NameDeclaration* moveIntoClassScope     ( NameDeclaration * );
  NameDeclaration* moveIntoNamespaceScope ( NameDeclaration * );
  NameDeclaration* moveIntoAnonNamespace  ( NameDeclaration * );
  NameDeclaration* moveIntoPrototypeScope ( NameDeclaration * ); 
  NameDeclaration* moveIntoFunctionScope  ( NameDeclaration * );

  NameDeclaration* makeAnonIdent     ( int, int ) const;
  NameDeclaration* makeAnonNSIdent   ( int, int ) const;
  NameDeclaration* makeAnonParmIdent ( int, int, int ) const;
  NameDeclaration* makeOperator      ( std::string *, int ) const;

  // add attributes to a decl
  void makeFunctionVirtual ( NameDeclaration * ) const;
  void makeFunctionPure    ( NameDeclaration * ) const;
  void makeFriend          ( NameDeclaration * ) const;
  void makeConst           ( NameDeclaration * ) const;
  void makeStatic          ( NameDeclaration * ) const;
  void makeTypedef         ( NameDeclaration * ) const;
  void makeInstance        ( NameDeclaration * ) const;

  NameDeclaration* insertLocal ( NameDeclaration *, Type *, bool = false ) ;

  void undoRecentInsertLocal ( NameDeclaration * );
  
  // support local (block) scopes
  void moveIntoLocalScope             ( void );
  void moveIntoTemplateParameterScope ( void );

  Scope* getCurrentScope         ( void ) const;
  Scope* getPreviousScope        ( void ) const;
  Scope* getCurrentTemplateScope ( bool ) const;
  // support this->x
  Scope* getCurrentClassScope ( void ) const;
  Scope* inCurrentClassScope  ( void ) const;

  void setAdditionalLookupScope ( Scope * );

  void leaveCurrentScope ( void );

  void installBaseClass ( NameDeclaration *, Access::AccessType );

  // for destructor name change
  void nextIsDestructor ( void );

  // record access
  void setAccess         ( NameDeclaration *, const Access::AccessType & ) const;
  void setAccessForClass ( const Access::AccessType & );

  bool inClassScope ( void );

  // remember pointer decls
  void makeIndirect ( NameDeclaration *, std::string ) const;
   
  NameDeclaration* getGlobalNamespace ( void ) const;

  void printClassesAndNamespaces ( void ) const;

private:
  ContextManager   *contextMan;
  LookupController  lookupMan;
  bool              debug_on;

  NameDeclaration* lookup_report ( std::string, TokenInfo *, NameDeclaration * ) const;
};

#endif
