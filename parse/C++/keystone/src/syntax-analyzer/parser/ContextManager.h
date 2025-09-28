//******************************************************************************
//
//  ContextManager.h
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

#ifndef _CONTEXT_MANAGER_H_
#define _CONTEXT_MANAGER_H_

#include <list>
#include <stack>

#include "Access.h"

class NameDeclaration;
class Scope;
class TemplateParameterScope;
class Type;

class ContextManager
{
public:
  ContextManager ( );
 ~ContextManager ( );

  Scope* getCurrentScope  ( void ) const;
  Scope* getPreviousScope ( void ); // this should be const, but need to make nestedScopes mutable.
  // THG - Added to make this->x work
  Scope* getCurrentClassScope ( void );
  Scope* inCurrentClassScope  ( void );

  TemplateParameterScope* getCurrentTemplateScope ( bool = true );
  
  void enterScope        ( Scope * );
  void leaveCurrentScope ( void );
   
  NameDeclaration* moveIntoPrototypeScope ( NameDeclaration * );
  NameDeclaration* moveIntoNamespaceScope ( NameDeclaration * );
  NameDeclaration* moveIntoAnonNamespace  ( NameDeclaration * );
  NameDeclaration* moveIntoClassScope     ( NameDeclaration * );
  NameDeclaration* moveIntoFunctionScope  ( NameDeclaration * );
  // THG - Added to support local (block) scopes
  void moveIntoLocalScope             ( void );
  void moveIntoTemplateParameterScope ( void );

  void installBaseInCurrentScope ( NameDeclaration *, Access::AccessType );
  void useNamespace              ( NameDeclaration *) ;

  NameDeclaration* insertLocal ( NameDeclaration *, Type * );
  void undoRecentInsertLocal   ( NameDeclaration * );

  void useDeclaration ( NameDeclaration * ); 
  bool sameType ( const Type *, const Type * ) const;

  // THG - Added for destructor name change
  bool setNextIsDestructor ( bool );
  bool getNextIsDestructor ( void ) const;

  void setInTemplate ( bool b ) { inTemplate = b; }
  bool getInTemplate ( void ) const { return inTemplate; }
   
  NameDeclaration* getGlobalNamespace ( void ) const;

  // THG - Added to support recording access levels
  bool inClassScope ( void );

  void setAccessForClass ( const Access::AccessType & );
   
  friend std::ostream & operator<< ( std::ostream &, const ContextManager & );

private:
  NameDeclaration *globalNamespace;
  bool             inTemplate;
  bool             mem_init;
  bool             nextIsDestructor;

  std::stack<Scope *>    nestedScopes;
  std::list<Scope *>     listOfScopes;
};

#endif
