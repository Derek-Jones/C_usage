//******************************************************************************
//
//  FunctionType.h
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

#ifndef _FUNCTION_TYPE_H_
#define _FUNCTION_TYPE_H_

#include "Type.h"

class FunctionType : public Type
{
public:

  enum Qual
  {
    Q_PROTOTYPE,
    Q_FUNCTION
  };

  FunctionType ( NameDeclaration *, Type *, Qual );

  Type* Clone ( void ) const { return ( new FunctionType( m_decl, m_ty, m_qual ) ); }

  bool checkType ( Type::DynType ) const;

  NameDeclaration* getDecl       ( void ) const;
  virtual Type*    getReturnType ( void ) const;

  virtual void makeFunction  ( void );
  virtual void setDecl       ( NameDeclaration * );

  virtual void setReturnType ( Type *type ) { m_ty = type; }

  std::ostream& Print ( std::ostream & ) const;

private:
  NameDeclaration *m_decl;
  Type            *m_ty;
  Qual             m_qual;
};

#endif
