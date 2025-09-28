//******************************************************************************
//
//  ArgumentStack.cpp
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

#include "Assertion.h"

#include "NameDeclaration.h"

#include "ArgumentStack.h"

using std::vector;

//------------------------------------------------------------------------------

void ArgumentStack::startArgumentList ( void )
{
  P_SENTRY;

  vector<NameDeclaration *> args;
  argsLists.push( args );
}

//------------------------------------------------------------------------------

void ArgumentStack::endArgumentList ( void )
{
  P_SENTRY;

  MAKE_ASSERTION( !argsLists.empty(), "The argument list was empty." );

  if ( argsLists.size() > 1 )
  {
    vector<NameDeclaration *> args(argsLists.top());
    argsLists.pop();
    for ( unsigned int i = 0; i < args.size(); ++i )
      argsLists.top().push_back( args[i] );
  }
  else
  {
    argsLists.pop();
  }
}

//------------------------------------------------------------------------------

void ArgumentStack::addIfArgument ( NameDeclaration *decl )
{
  P_SENTRY;

  if ( decl != 0 && !argsLists.empty() )
    argsLists.top().push_back(decl);
}

//------------------------------------------------------------------------------

vector<NameDeclaration *>  ArgumentStack::getArgumentList ( void ) const
{
  P_SENTRY;

  MAKE_ASSERTION( !argsLists.empty(), "The argument list was empty." );

  return ( argsLists.top() );
}

//------------------------------------------------------------------------------
