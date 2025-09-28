//******************************************************************************
//
//  main.cpp
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
///\author Nicholas A. Kraft

#include "config.h"

#ifdef KEY_CLASS_BASED_TESTING

#include "ClassBasedTest.cpp"

#else

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "CommandLineOptions.h"
#include "SyntaxAnalyzer.h"

#include "Ast.h"

extern void asgTricks ( cGlobalScope*, const std::string& );

int main ( int argc, char* argv[] )
{
  CommandLineOptions* cmd = CommandLineOptions::Instance();
  cmd->parse( argc, argv );

  std::vector<bool>               options = cmd->getOptions();
  const std::vector<std::string>& files   = cmd->getFilenames();

  for ( std::vector<std::string>::const_iterator ptr = files.begin();
        ptr != files.end();
        ++ptr
      )
  {
    cGlobalScope* root = SyntaxAnalyzer::analyze( *ptr );
    asgTricks( root, *ptr );
  }
}

#endif

