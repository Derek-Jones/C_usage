//******************************************************************************
//
//  IndirectType.h
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

#ifndef _INDIRECT_TYPE_H_
#define _INDIRECT_TYPE_H_

#include "Type.h"

class IndirectType : public Type
{
public:

  enum IType
  {
    IT_ARRAY,
    IT_POINTER,
    IT_REFERENCE
  };

  IndirectType ( NameDeclaration * , Type * , IType );

  Type* Clone ( void ) const { return ( new IndirectType( m_decl, m_type, m_itype ) ); }  

  bool checkType ( Type::DynType ) const;

  NameDeclaration* getDecl            ( void ) const { return ( m_decl );  }
  Type*            getReferencedType  ( void ) const { return ( m_type );  }
  IType            getIndirectionType ( void ) const { return ( m_itype ); }

  void setDecl           ( NameDeclaration *decl ) { m_decl = decl; }
  void setReferencedType ( Type *type )            { m_type = type; }

  std::ostream& Print ( std::ostream & ) const;

private:
  NameDeclaration *m_decl; // may not be necessary
  Type            *m_type;
  IType            m_itype;
};

#endif
