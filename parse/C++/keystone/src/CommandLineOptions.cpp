//******************************************************************************
//
//  CommandLineOptions.cpp
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

#include <getopt.h>
#include <cstdlib>
#include <iostream>

#include "CommandLineOptions.h"
#include "config.h"

//------------------------------------------------------------------------------

CommandLineOptions *CommandLineOptions::instance = 0;

//------------------------------------------------------------------------------

CommandLineOptions*
CommandLineOptions::Instance ( void )
{
  if ( ! instance )
  {
    instance = new CommandLineOptions;
  }

  return instance;
}

//------------------------------------------------------------------------------

CommandLineOptions::CommandLineOptions ( )
  : options ( CommandLineOptions::NUM_OPTIONS, false )
  //, ast2Dot ( "ast.dot" )
  //, asg2Dot ( "asg.dot" )
{
}

//------------------------------------------------------------------------------

void
CommandLineOptions::parse ( int argc, char* argv[] )
{
  // follow letter with ":" for required arg
  // follow letter with "::" for optional arg
  const char* short_options = "hVvPclsetgSI:";

  static struct option long_options[] =
    {
      // Operation Modes
      { "help"   , no_argument, 0, 'h' },
      { "version", no_argument, 0, 'V' },

      // Parser
      { "verbose", no_argument, 0, 'v' },
      { "no-cpp" , no_argument, 0, 'P' },

      // no args
      { "fcontexts",   no_argument, 0, 'c' },
      { "flookups" ,   no_argument, 0, 'l' },
      { "fstats"   ,   no_argument, 0, 's' },
      { "fedgelabels", no_argument, 0, 'e' },

      { "fast2dot", no_argument, 0, 't' },
      { "fasg2dot", no_argument, 0, 'g' },
      { "fasg2src", no_argument, 0, 'S' },

      // optional args
      //{ "fasg2dot", optional_argument, 0, 'g' },

      // required args
      { "include", required_argument, 0, 'I' },

      { 0, 0, 0, 0 }
    };

  int c;
  while ( ( c = getopt_long( argc, argv, short_options, long_options, 0 ) ) != -1 )
  {
    switch ( c )
    {
      case 0:
      break;

      case 'h':
        usage( argv[0], 0 );
      break;

      case 'V':
        version();
      break;

      case 'v':
        options[OPT_VERBOSE] = true;
      break;

      case 'P':
        options[OPT_NO_CPP] = true;
      break;

      case 'c':
        options[OPT_CONTEXTS] = true;
      break;

      case 'l':
        options[OPT_LOOKUPS] = true;
      break;

      case 's':
        options[OPT_STATS] = true;
      break;

      case 'e':
        options[OPT_EDGE_LABELS] = true;
      break;

      case 't':
        options[OPT_AST2DOT] = true;
        //if ( optarg )
        //{
          //ast2Dot = optarg;
        //}
      break;

      case 'g':
        options[OPT_ASG2DOT] = true;
      break;

      case 'S':
        options[OPT_ASG2SRC] = true;
      break;

      case 'I':
        headerSearch.push_back( optarg );
      break;

      default:
        usage( argv[0], 1 );
    }
  }

  if ( optind < argc )
  {
    while ( optind < argc )
    {
      filenames.push_back( argv[optind++] );
    }
  }

  if ( ! filenames.size() )
  {
    usage( argv[0], 1 );
  }
}

//------------------------------------------------------------------------------

void
CommandLineOptions::usage ( const char* name, int status ) const
{
  if ( status != 0 )
  {
    std::cerr << "Try `" << name << " --help' for more information." << std::endl;
  }
  else
  {
    std::cout << "Keystone analyzes ISO C++ code and generates and ASG.\n" << std::endl;
    std::cout << "Usage: " << name << " [OPTION]... FILE1 FILE2...\n" << std::endl;

    std::cout << "\
Operation modes:\n\
  -h, --help           display this help and exit\n\
  -V, --version        output version information and exit\
" << std::endl;

    std::cout << "\n\
Parser:\n\
  -v,     --verbose        output exit status\n\
  -I dir, --include dir    add directory \'dir\' to header search path\n\
  -P,     --no-cpp         do not run GNU cpp\
" << std::endl;

    std::cout << "\n\
Output:\n\
  -c, --fcontexts      output debug information for scopes\n\
  -l, --flookups       output debug information for name lookups\n\
  -s, --fstats         output token decorator statistics\n\
  -t, --fast2dot       output dot description of the AST\n\
  -g, --fasg2dot       output dot description of the ASG\n\
  -S, --fasg2src       output src regeneration of the ASG\n\
  -e, --fedgelabels    output edge labels in dot graphs\
" << std::endl;

    std::cout << "\nReport bugs to " << PACKAGE_BUGREPORT << std::endl;
  }

  exit( status );
}

//------------------------------------------------------------------------------

void
CommandLineOptions::version ( void ) const
{
  std::cout << "key (Keystone) " << VERSION << std::endl;
  std::cout << "\n\
Copyright (C) 2000-2004 by\n\
  Department of Computer Science, Clemson University,\n\
  Department of Computer Science, National University of Ireland, Maynooth.\n\
This is free software; see the source for copying conditions.  There is NO\n\
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\
" << std::endl;

  exit( 1 );
}

//------------------------------------------------------------------------------

