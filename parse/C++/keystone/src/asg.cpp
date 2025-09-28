//******************************************************************************
//
//  asg.cpp
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

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "CommandLineOptions.h"

#include "Ast.h"
#include "Asg2DotVisitor.h"
#include "Asg2SrcVisitor.h"
#include "GlobalResolutionVisitor.h"

namespace key
{
  std::string baseFilename ( const std::string& );
}

void asgTricks ( cGlobalScope* root, const std::string& filename )
{
  CommandLineOptions* cmd     = CommandLineOptions::Instance();
  std::vector<bool>   options = cmd->getOptions();
  try
  {
    if ( !root )
    {
      return;
    }

    if ( options[CommandLineOptions::OPT_AST2DOT] )
    {
      std::string dotName = key::baseFilename( filename ) + ".ast.dot";
      std::ofstream ofile( dotName.c_str() );

      ofile << "digraph {\n";
      Asg2DotVisitor a2dv( ofile, options[CommandLineOptions::OPT_EDGE_LABELS] );
      root->accept( &a2dv );
      ofile << "\n}\n";
    }

    GlobalResolutionVisitor grv( root );
    root->accept( &grv );

    if ( options[CommandLineOptions::OPT_ASG2DOT] )
    {
      std::string dotName = key::baseFilename( filename ) + ".asg.dot";
      std::ofstream ofile( dotName.c_str() );

      ofile << "digraph {\n";
      Asg2DotVisitor a2dv( ofile, options[CommandLineOptions::OPT_EDGE_LABELS] );
      root->accept( &a2dv );
      ofile << "\n}\n";
    }

    if ( options[CommandLineOptions::OPT_ASG2SRC] )
    {
      std::cout << "!*****   Source Regeneration from the ASG   *****!" << std::endl;
      Asg2SrcVisitor a2sv;
      root->accept( &a2sv );
      std::cout << "!***** End Source Regeneration from the ASG *****!" << std::endl;
    }
  }
  catch ( const char* msg )
  {
    std::cerr << msg << std::endl;
  }
  catch ( const std::string& msg )
  {
    std::cerr << msg << std::endl;
  }
}

namespace key
{
  std::string baseFilename ( const std::string& filename )
  {
    std::string rVal;

    std::string::size_type lastSlash = filename.rfind( '/' );
    if ( lastSlash == std::string::npos )
    {
      rVal = filename;
    }
    else
    {
      rVal = filename.substr( lastSlash+1 );
    }

    return rVal;
  }
}

