//******************************************************************************
//
//  Type.h
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

#ifndef _TYPE__H_
#define _TYPE__H_

#include <iosfwd>

#include "TypeInvariantFacilitator.h"

class NameDeclaration;

class Type : public TypeInvariantFacilitator
{
public:

  enum DynType
  {
    DT_NAMESPACE,
    DT_ENUM,
    DT_CLASS,
    DT_BASIC,
    DT_FUNCTION,
    DT_FUNCTION_PROTOTYPE,
    DT_FUNCTION_DEFINITION,
    DT_INDIRECT,
    DT_TEMPLATE_PARM,
    DT_TEMPLATE_TEMPLATE_PARM
  };

  virtual ~Type ( ) { }

  virtual NameDeclaration* getDecl   ( void )    const = 0;
  virtual Type*            Clone     ( void )    const = 0;
  virtual bool             checkType ( DynType ) const = 0;

  virtual bool isConst    ( void ) const;
  virtual bool isVolatile ( void ) const;

  virtual void makeConst    ( void );
  virtual void makeVolatile ( void );

   virtual std::ostream& Print ( std::ostream & ) const = 0;

protected:
  Type ( );

private:
  bool m_const;
  bool m_volatile;
};

std::ostream& operator<< ( std::ostream &, const Type & );

#endif
