//******************************************************************************
//
//  Scope.h
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

#ifndef _SCOPE_H_
#define _SCOPE_H_

#include <iosfwd>
#include <list>
#include <set>
#include <string>

#include "ScopeInvariantFacilitator.h"

class NameDeclaration;
class NameOccurrence;

class Scope : public ScopeInvariantFacilitator {
public:
  static std::set<Scope *> scope_searched_set;

  static bool             occurAsClass ( NameDeclaration *, NameOccurrence * );
  static NameDeclaration* pickBest     ( std::list<NameDeclaration *> &, NameOccurrence * );

  Scope ( NameDeclaration *, Scope *ptr = 0 );

  virtual ~Scope ( ) { }

  virtual bool canContain(NameOccurrence *) const = 0;

  Scope*                              getContainingScope ( void )       { return ( containedIn ); }
  NameDeclaration*                    getDecl            ( void ) const { return ( name );        }   
  const std::list<NameDeclaration *>* getLocals          ( void ) const { return ( &locals );     }
  std::string                         getName            ( void ) const;

  virtual void             insertLocal ( NameDeclaration * );
  virtual NameDeclaration* lookup      ( NameOccurrence  * );

  void removeDeclaration     ( NameDeclaration * );
  void removeNFFromClass     ( NameOccurrence  * );
  void undoRecentInsertLocal ( NameDeclaration * );

  std::list<NameDeclaration *> getAnonNamespaces ( void ) const;

  virtual std::ostream& Print ( std::ostream & ) const;

  // Java/SWIG doesn't overload on const-ness
  //const Scope* getContainingScope() const { return containedIn; }

protected:
  NameDeclaration *name;
  Scope           *containedIn;

  std::list<NameDeclaration *> locals;

  virtual NameDeclaration* findHere ( NameOccurrence * );
};

std::ostream& operator<< ( std::ostream &, const Scope & );

#endif
