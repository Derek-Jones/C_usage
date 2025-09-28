//******************************************************************************
//
//  TokenInfo.cpp
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

#include <sstream>

#include "TokenInfo.h"

using std::ostream;
using std::string;
using std::stringstream;

//------------------------------------------------------------------------------
// Constructors
//------------------------------------------------------------------------------

TokenPosn::TokenPosn ( const string &f, int l, int c )
          : fileName ( f ),
            line_num ( l ),
            col_num  ( c )
{ }

//------------------------------------------------------------------------------

TokenInfo::TokenInfo ( const string &n, const string &f, int l, int c)
          : TokenPosn ( f, l, c ),
            name      ( n ),
            arity     ( -1 )
{ }

//------------------------------------------------------------------------------

TokenInfo::TokenInfo ( const string &n, int l, int c)
          : TokenPosn ( "unknown", l, c ),
            name      ( n ),
            arity     ( -1 )
{ }

//------------------------------------------------------------------------------

TokenInfo::TokenInfo ( const string &n, TokenPosn *tp)
          : TokenPosn ( *tp ),
            name      ( n ),
            arity     ( -1 )
{ }

//------------------------------------------------------------------------------
// Output
//------------------------------------------------------------------------------

ostream& TokenInfo::Print ( ostream &out ) const
{
  out << name;

  if ( arity != -1 )
    out << ":" << arity;

  out << " ";
  TokenPosn::Print( out );

  return ( out );
}

//------------------------------------------------------------------------------

string TokenPosn::toString ( void ) const
{
  stringstream sstr;

  sstr << "(" << fileName << ": " << line_num << "," << col_num << ")";

  return sstr.str();
}

//------------------------------------------------------------------------------

string TokenInfo::toString ( void ) const
{
  stringstream sstr;

  sstr << name;

  if ( arity != -1 )
  {
    sstr << ":" << arity;
  }

  sstr << " ";

  sstr << TokenPosn::toString();

  return sstr.str();
}

//------------------------------------------------------------------------------
