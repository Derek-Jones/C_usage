//******************************************************************************
//
//  NameOccurrence.cpp
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

#include "NameDeclaration.h"
#include "Type.h"

#include "NameOccurrence.h"

using std::ostream;

//------------------------------------------------------------------------------

NameOccurrence::NameOccurrence( const NameDeclaration *decl )
               : TokenInfo ( *decl )
{
   qualifier = decl->getOccurQual();
   spec = nothing;

        if( !decl->getType() ) ;                                //no-op
   else if(  decl->getType()->checkType( Type::DT_CLASS ) )     spec = ElabClass;
   else if(  decl->getType()->checkType( Type::DT_ENUM ) )      spec = ElabEnum;
   else if(  decl->getType()->checkType( Type::DT_NAMESPACE ) ) spec = Namespace;

  ignoreUsings = false;
}

//------------------------------------------------------------------------------

ostream& operator<< ( ostream &out, const NameOccurrence &occ )
{
  return ( occ.Print( out ) );
}

//------------------------------------------------------------------------------

ostream& NameOccurrence::Print ( ostream &out ) const
{
  out << "use of ";
  TokenInfo::Print( out );
  out << ' ' << getSpec();

  return ( out );
}

//------------------------------------------------------------------------------

ostream& operator<< ( ostream &out, const NameOccurrence::OccurSpecifier &occ )
{
  switch ( occ )
  {
    case NameOccurrence::ConvFunction:        out << "ConvFunction";        break;
    case NameOccurrence::Destructor:          out << "Destructor";          break;
    case NameOccurrence::DestructorQualifier: out << "DestructorQualifier"; break;
    case NameOccurrence::ElabEnum:            out << "ElabEnum";            break;
    case NameOccurrence::ElabClass:           out << "ElabClass";           break;
    case NameOccurrence::Member:              out << "Member";              break;
    case NameOccurrence::Namespace:           out << "Namespace";           break;
    case NameOccurrence::PseudoDestructor:    out << "PseudoDestructor";    break;
    case NameOccurrence::Qualifier:           out << "Qualifier";           break;
    case NameOccurrence::nothing:             out << "nothing";             break;
  }

  return ( out );
}

//------------------------------------------------------------------------------
