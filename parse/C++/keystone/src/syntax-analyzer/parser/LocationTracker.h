//******************************************************************************
//
//  LocationTracker.h
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

#ifndef _LOCATION_TRACKER_H_
#define _LOCATION_TRACKER_H_

#include <string>

class LocationTracker
{
public:
  LocationTracker ( );

  const std::string& fileName   ( void ) const { return fileName_;   }
  const unsigned int lineNumber ( void ) const { return lineNumber_; }

  void setFileName   ( const std::string &fn ) { fileName_   = fn; }
  void setLineNumber ( const unsigned int ln ) { lineNumber_ = ln; }

  void incrementLineNumber ( void ) { ++lineNumber_; }

private:
  std::string  fileName_;
  unsigned int lineNumber_;
};

#endif
