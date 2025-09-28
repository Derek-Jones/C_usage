//******************************************************************************
//
//  CommandLineOptions.h
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

#ifndef _COMMAND_LINE_OPTIONS_
#define _COMMAND_LINE_OPTIONS_

#include <list>
#include <string>
#include <vector>

class CommandLineOptions
{
public:
  enum
  {
    OPT_VERBOSE,
    OPT_NO_CPP,
    OPT_CONTEXTS,
    OPT_LOOKUPS,
    OPT_STATS,
    OPT_EDGE_LABELS,
    OPT_AST2DOT,
    OPT_ASG2DOT,
    OPT_ASG2SRC,
    NUM_OPTIONS
  };

  static CommandLineOptions* Instance ( void );

  void parse ( int, char *[] );

  const std::vector<bool>&      getOptions      ( void ) const { return options;      }
  const std::list<std::string>& getHeaderSearch ( void ) const { return headerSearch; }
  //const std::string&       getAsg2Dot ( void ) const { return asg2Dot; }

  const std::vector<std::string>& getFilenames ( void ) const { return filenames; }

private:
  void usage   ( const char*, int ) const;
  void version ( void ) const;

private:
  static CommandLineOptions* instance;

  std::vector<bool>      options;
  std::list<std::string> headerSearch;
  //std::string       asg2Dot;

  std::vector<std::string> filenames;

  CommandLineOptions ( );
};

#endif
