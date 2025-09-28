//******************************************************************************
//
//  Visitor.h
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

#ifndef _VISITOR_H_
#define _VISITOR_H_

class Visitor {
public:
  virtual ~Visitor() {}

  virtual void Visit ( const class NameDeclaration * ) { }

  virtual void Visit ( const class Type          * ) { }
  virtual void Visit ( const class BasicType     * ) { }
  virtual void Visit ( const class ClassType     * ) { }
  virtual void Visit ( const class EnumType      * ) { }
  virtual void Visit ( const class FunctionType  * ) { }
  virtual void Visit ( const class IndirectType  * ) { }
  virtual void Visit ( const class NamespaceType * ) { }

  virtual void Visit ( const class Scope                  * ) { }
  virtual void Visit ( const class ClassScope             * ) { }
  virtual void Visit ( const class FunctionScope          * ) { }
  virtual void Visit ( const class LocalScope             * ) { }
  virtual void Visit ( const class NamespaceScope         * ) { }
  virtual void Visit ( const class PrototypeScope         * ) { }
  virtual void Visit ( const class TemplateParameterScope * ) { }
};

#endif
