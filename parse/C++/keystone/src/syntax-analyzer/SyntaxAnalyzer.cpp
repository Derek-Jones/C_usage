//******************************************************************************
//
//  SyntaxAnalyzer.cpp
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

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>

#include "CommandLineOptions.h"

#include "Assertion.h"

#include "ActionFacade.h"
#include "Actions.h"
#include "LocationTracker.h"
#include "Parser.h"
#include "TokenDecorator.h"

#include "Type.h"
#include "TypeInvariantVisitor.h"

#include "SyntaxAnalyzer.h"

using std::cout;
using std::cerr;
using std::endl;
using std::ends;
using std::string;
using std::stringstream;

extern FILE* yyin;
extern int   yylex     ( );
extern int   yyparse   ( );
extern void  yyrestart ( FILE* );
extern int   yydebug;

namespace btyacc
{
  extern void resetBtYacc ( void );
}

bool SyntaxAnalyzer::reset = false;

//------------------------------------------------------------------------------

cGlobalScope* SyntaxAnalyzer::analyze ( const string& filename )
{
  // Always turn this on, we'll control btyacc debugging with YYDEBUG
  yydebug = 1;

  CommandLineOptions*           cmd          = CommandLineOptions::Instance();
  const std::vector<bool>&      options      = cmd->getOptions();
  const std::list<std::string>& headerSearch = cmd->getHeaderSearch();

  Parser* processor = Parser::Instance();

  if ( reset )
  {
    processor->recycle();
  }
  reset = true;
  btyacc::resetBtYacc();

  FILE* file;

  if ( options[CommandLineOptions::OPT_NO_CPP] )
  {
    file = fopen( filename.c_str(), "r" );
  }
  else
  {
    stringstream str;
    str << KEY_CPP << " ";
    for ( std::list<std::string>::const_iterator ptr = headerSearch.begin();
          ptr != headerSearch.end();
          ++ptr
        )
    {
      str << "-I" << *ptr << "  ";
    }
    str << filename;
    str << ends;
    file = popen( str.str().c_str(), "r" );
  }

  if ( !file )
  {
    cout << "Could not open " << filename << endl;
    return 0;
  }

  yyin = file;
  processor->location()->setFileName( filename );

  try
  {
    ActionFacade* facade = processor->facade();

    if ( options[CommandLineOptions::OPT_LOOKUPS] )
    {
      facade->setDebug( true );
    }
    else
    {
      facade->setDebug( false );
    }

    int rc = yyparse();

    if ( options[CommandLineOptions::OPT_NO_CPP] )
    {
      fclose( file );
    }
    else
    {
      pclose( file );
    }

    if ( rc )
    {
      cout << "Parse Failed." << endl;
      if ( options[CommandLineOptions::OPT_VERBOSE] )
      {
        cout << "Syntax Analysis Failed." << endl;
      }
      return 0;
    }

    if ( options[CommandLineOptions::OPT_VERBOSE] )
    {
      cout << "Syntax Analysis Succeeded." << endl;
    }

    if ( options[CommandLineOptions::OPT_CONTEXTS] )
    {
      facade->printClassesAndNamespaces();
      cout << endl;
    }

    if ( options[CommandLineOptions::OPT_STATS] )
    {
      processor->decorator()->printStatistics();
      cout << endl;
    }

    Actions* actions = processor->actions();
    unsigned long counter = 0;
    actions->globalScope()->applyPreorder( counter );

    return actions->globalScope();
  }

  catch ( const char* msg )
  {
    cout << msg << endl;
  }
  catch ( const string& msg )
  {
    cout << msg << endl;
  }
  catch ( const Assertion& a )
  {
    cout << "Failed assertion: " << a.getDesc()     << endl
         << "\tfile: "           << a.getFileName() << endl
         << "\tline: "           << a.getLineNo()   << endl;
  }
  catch ( ... )
  {
    cout << "Unknown Exception." << endl;
  }

  return 0;
}
