//******************************************************************************
//
//  PrototypeScope.h
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

#ifndef _PROTOTYPE_SCOPE_H_
#define _PROTOTYPE_SCOPE_H_

#include "Scope.h"

class TemplateParameterScope;

class PrototypeScope : public Scope {
public:
  PrototypeScope(NameDeclaration * n, Scope * ptr);

  virtual bool canContain ( NameOccurrence * ) const;

  TemplateParameterScope* getTemplateParameterScope ( void ) { return m_tps; }

  NameDeclaration* lookup ( NameOccurrence * );

  void setTemplateParameterScope ( TemplateParameterScope *tps ) { m_tps = tps; }

  virtual std::ostream& Print( std::ostream & ) const;

private:
  TemplateParameterScope *m_tps;
};

#endif
