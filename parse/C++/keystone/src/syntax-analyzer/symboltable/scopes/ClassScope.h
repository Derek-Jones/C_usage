//******************************************************************************
//
//  ClassScope.h
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

#ifndef _CLASS_SCOPE_H_
#define _CLASS_SCOPE_H_

#include "Scope.h"
#include "Access.h"

class TemplateParameterScope;

class ClassScope : public Scope {
public:
  ClassScope ( NameDeclaration *, Scope * );

  bool isTemplate() const { return m_tps || is_template; }


  virtual bool             canContain  ( NameOccurrence  * ) const;
  virtual void             insertLocal ( NameDeclaration * );
  virtual NameDeclaration* lookup      ( NameOccurrence  * );

  Access::AccessType getAccessTypeForBase ( const ClassScope * ) const;

  // THG - Added to support API parents call
  const std::list<ClassScope *>& getBaseClasses ( void ) const { return ( baseClasses ); }
  const std::list<std::string>&  getFriends     ( void ) const { return ( friends );     }

  TemplateParameterScope* getTemplateParameterScope ( void ) { return ( m_tps ); }

  void setTemplateParameterScope ( TemplateParameterScope *tps ) { m_tps = tps; }

  // THG - Added to support friends
  void addFriend ( NameDeclaration *decl, const std::string &friend_name ) {
    removeDeclaration(decl);
    friends.push_back( friend_name );
  }

  void installBaseClass ( ClassScope *ptr, Access::AccessType acc ) {
    baseClasses.push_back( ptr );
    baseClassAccess.push_back( acc );
  }

  // THG - Added to support backpatching
  void removeNotFound ( NameOccurrence * );

  virtual std::ostream& Print ( std::ostream & ) const;

private:
  TemplateParameterScope        *m_tps;
  std::list<ClassScope *>        baseClasses;
  std::list<Access::AccessType>  baseClassAccess;
  std::list<NameOccurrence>      notFound;
  std::list<std::string>         friends;
  bool                           is_template;

  static bool hasValidChoice ( std::list<NameDeclaration *> & );
  NameDeclaration* searchBaseClasses ( NameOccurrence * );
};

#endif
