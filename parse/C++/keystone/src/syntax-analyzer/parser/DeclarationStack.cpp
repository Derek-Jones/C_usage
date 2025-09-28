//******************************************************************************
//
//  DeclarationStack.cpp
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

#include <iostream>

#include "Assertion.h"

#include "LocationTracker.h"

#include "NameDeclaration.h"
#include "Type.h"

#include "DeclarationStack.h"

using std::cout;
using std::endl;
using std::stack;
using std::string;

//------------------------------------------------------------------------------

DeclarationStack::DeclarationStack ( LocationTracker *lt )
                 : location ( lt )
{ }

//------------------------------------------------------------------------------

Type* DeclarationStack::top ( void ) const
{
  P_SENTRY;

  MAKE_ASSERTION( !declStack.empty(), "top called when declStack is empty." );

  return ( declStack.top() );
}

//------------------------------------------------------------------------------

void DeclarationStack::push ( NameDeclaration *decl )
{
  P_SENTRY;

  MAKE_ASSERTION( decl != 0, "push given a NULL declaration." );

  push( decl->getType()->Clone() );
}

//------------------------------------------------------------------------------

void DeclarationStack::push( Type *t )
{
  P_SENTRY;

  MAKE_ASSERTION( t != 0, "push given a NULL type." );

  declStack.push( t );
  line_no_stack.push( location->lineNumber() );
}

//------------------------------------------------------------------------------

void DeclarationStack::pop ( void )
{
  P_SENTRY;

  if ( declStack.empty() )
    throw string("declStack is empty!");

  declStack.pop();
  line_no_stack.pop();

  // NEED TO OVERLOAD DELETE in TYPE
  //delete this_type;
}

//------------------------------------------------------------------------------

void DeclarationStack::printAndEmpty ( void )
{
  cout << "    declStack size is: " << size() << endl;
  cout << "line_no_stack size is: " << line_no_stack.size() << endl;

  while ( !empty() )
  {
    cout << line_no_stack.top() << ":" << *top() << endl;
    pop();
  }
}

//------------------------------------------------------------------------------
