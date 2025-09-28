//******************************************************************************
//
//  Sentry.h
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

#ifndef _SENTRY_H_
#define _SENTRY_H_

#include <iostream>

#include "config.h"

class Sentry {
public:
  Sentry ( const char *c ) : m_c ( c ) {
    std::cerr << "Entering " << m_c << std::endl;
  }
  ~Sentry ( ) {
    std::cerr << "Exiting " << m_c << std::endl;
  }

private:
  const char *m_c;  
};

#if defined (__GNUG__) && (KEY_P_SENTRY)
  #define P_SENTRY Sentry sen(__PRETTY_FUNCTION__)
#else
  #define P_SENTRY
#endif

#ifdef KEY_ST_SENTRY
  #define ST_SENTRY(x) Sentry sen(x)
#else
  #define ST_SENTRY(x)
#endif

#endif
