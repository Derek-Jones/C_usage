//******************************************************************************
//
//  StandardLibrary.cpp
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

#include <iostream>

#include "StandardLibrary.h"

///-----------------------------------------------------------------------------
/// Static Member Initialization
///-----------------------------------------------------------------------------
std::set<std::string> StandardLibrary::sLibraryHeaders;
std::set<std::string> StandardLibrary::sLibrarySubdirectories;

bool StandardLibrary::sInitialized = false;

///-----------------------------------------------------------------------------
///
bool StandardLibrary::inStandardLibrary ( const std::string& aFilename )
{
  if ( ! sInitialized )
  {
    initialize();
  }

  std::string rel = abs2rel( aFilename );

  return sLibraryHeaders.find( rel ) != sLibraryHeaders.end();
}

///-----------------------------------------------------------------------------
///
std::string StandardLibrary::abs2rel ( const std::string& aFilename )
{
  std::string rVal;

  std::string::size_type lastSlash = aFilename.rfind( '/' );
  if ( lastSlash == std::string::npos )
  {
    rVal = aFilename;
  }
  else
  {
    std::string::size_type secondLastSlash = aFilename.rfind( '/', lastSlash-1 );
    if ( secondLastSlash == std::string::npos )
    {
      if ( sLibrarySubdirectories.find( aFilename.substr( 0, lastSlash ) ) !=
           sLibrarySubdirectories.end()
         )
      {
        rVal = aFilename;
      }
      else
      {
        rVal = aFilename.substr( lastSlash+1 );
      }
    }
    else
    {
      std::string subdirectory = aFilename.substr( secondLastSlash+1 );
      subdirectory = subdirectory.substr( 0, subdirectory.find( '/' ) );
      if ( sLibrarySubdirectories.find( subdirectory ) !=
           sLibrarySubdirectories.end()
         )
      {
        rVal = aFilename.substr( aFilename.find( subdirectory ) );
      }
      else
      {
        rVal = aFilename.substr( lastSlash+1 );
      }
    }
  }

  return rVal;
}

///-----------------------------------------------------------------------------
///
void StandardLibrary::initialize ( void )
{
  sInitialized = true;

  sLibraryHeaders.insert( "algorithm" );
  sLibraryHeaders.insert( "allocator.h" );
  sLibraryHeaders.insert( "assert.h" );
  sLibraryHeaders.insert( "bitset" );
  sLibraryHeaders.insert( "cassert" );
  sLibraryHeaders.insert( "cctype" );
  sLibraryHeaders.insert( "cerrno" );
  sLibraryHeaders.insert( "char_traits.h" );
  sLibraryHeaders.insert( "clocale" );
  sLibraryHeaders.insert( "cmath" );
  sLibraryHeaders.insert( "complex" );
  sLibraryHeaders.insert( "csetjmp" );
  sLibraryHeaders.insert( "csignal" );
  sLibraryHeaders.insert( "cstdarg" );
  sLibraryHeaders.insert( "cstddef" );
  sLibraryHeaders.insert( "cstdio" );
  sLibraryHeaders.insert( "cstdlib" );
  sLibraryHeaders.insert( "cstring" );
  sLibraryHeaders.insert( "ctype.h" );
  sLibraryHeaders.insert( "cwchar" );
  sLibraryHeaders.insert( "cwctype" );
  sLibraryHeaders.insert( "deque" );
  sLibraryHeaders.insert( "dirent.h" );
  sLibraryHeaders.insert( "errno.h" );
  sLibraryHeaders.insert( "exception" );
  sLibraryHeaders.insert( "fcntl.h" );
  sLibraryHeaders.insert( "fpos.h" );
  sLibraryHeaders.insert( "fstream" );
  sLibraryHeaders.insert( "functional" );
  sLibraryHeaders.insert( "grp.h" );
  sLibraryHeaders.insert( "iomanip" );
  sLibraryHeaders.insert( "ios" );
  sLibraryHeaders.insert( "ios_types.h" );
  sLibraryHeaders.insert( "iosfwd" );
  sLibraryHeaders.insert( "iostream" );
  sLibraryHeaders.insert( "istream" );
  sLibraryHeaders.insert( "iterator" );
  sLibraryHeaders.insert( "limits" );
  sLibraryHeaders.insert( "list" );
  sLibraryHeaders.insert( "locale" );
  sLibraryHeaders.insert( "locale.h" );
  sLibraryHeaders.insert( "map" );
  sLibraryHeaders.insert( "math.h" );
  sLibraryHeaders.insert( "mbstate.h" );
  sLibraryHeaders.insert( "memory" );
  sLibraryHeaders.insert( "new" );
  sLibraryHeaders.insert( "new.h" );
  sLibraryHeaders.insert( "numeric" );
  sLibraryHeaders.insert( "ostream" );
  sLibraryHeaders.insert( "priority_queue" );
  sLibraryHeaders.insert( "pwd.h" );
  sLibraryHeaders.insert( "queue" );
  sLibraryHeaders.insert( "set" );
  sLibraryHeaders.insert( "setjmp.h" );
  sLibraryHeaders.insert( "signal.h" );
  sLibraryHeaders.insert( "sstream" );
  sLibraryHeaders.insert( "stack" );
  sLibraryHeaders.insert( "stdarg.h" );
  sLibraryHeaders.insert( "stddef.h" );
  sLibraryHeaders.insert( "stdexcept" );
  sLibraryHeaders.insert( "stdio.h" );
  sLibraryHeaders.insert( "stdlib.h" );
  sLibraryHeaders.insert( "streambuf" );
  sLibraryHeaders.insert( "string" );
  sLibraryHeaders.insert( "string.h" );
  sLibraryHeaders.insert( "strstream" );
  sLibraryHeaders.insert( "strstream.h" );
  sLibraryHeaders.insert( "time.h" );
  sLibraryHeaders.insert( "typeinfo" );
  sLibraryHeaders.insert( "unistd.h" );
  sLibraryHeaders.insert( "utility" );
  sLibraryHeaders.insert( "utime.h" );
  sLibraryHeaders.insert( "vector" );
  sLibraryHeaders.insert( "wchar.h" );
  sLibraryHeaders.insert( "wctype.h" );
  sLibraryHeaders.insert( "sys/file.h" );
  sLibraryHeaders.insert( "sys/stat.h" );
  sLibraryHeaders.insert( "sys/types.h" );

  sLibrarySubdirectories.insert( "sys" );
}

///-----------------------------------------------------------------------------

