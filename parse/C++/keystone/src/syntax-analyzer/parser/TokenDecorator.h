//******************************************************************************
//
//  TokenDecorator.h
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

#ifndef _TOKEN_DECORATOR_H_
#define _TOKEN_DECORATOR_H_

#include "TokenBuffer.h"

class ActionFacade;
class LocationTracker;
class NameDeclaration;

class TokenDecorator
{
public:
  TokenDecorator ( LocationTracker *, ActionFacade * );

  static void recycle ( void );

  int getNextToken    ( void );
  int getCurrentToken ( void ) const { return ( currentToken );         }
  int getCurrentLine  ( void ) const { return ( buf.getCurrentLine() ); }

  std::string getCurrentText     ( void ) const { return ( buf.getCurrentText() );     }
  std::string getCurrentFilename ( void ) const { return ( buf.getCurrentFilename() ); }

  NameDeclaration* getLastIdentifier ( void ) const { return ( buf.getLastIdentifier() ); }
  NameDeclaration* getBeforeEqual    ( void ) const { return ( buf.getBeforeEqual() );    }
  NameDeclaration* getBeforeParen    ( void ) const { return ( buf.getBeforeParen() );    }

  void saveId      ( void ) { buf.saveId();    }
  void restoreId   ( void ) { buf.restoreId(); }
  bool lastWasFun  ( void ) const { return ( buf.lastWasFun() );  }
  bool nextIsClass ( void ) const { return ( buf.nextIsClass() ); }

  int getTokenCount    ( void ) const { return ( buf.getTokenCount() ); }
  int getDecorated     ( void ) const { return ( decorated );           }
  int getNonDecorated  ( void ) const { return ( non_decorated );       }
  int getNonIdentifier ( void ) const { return ( non_identifier );      }

  void printStatistics ( void ) const;

  void dumpBuffer ( void ) const { buf.dump(); }

private:
  LocationTracker *location;
  ActionFacade    *facade;

  TokenBuffer buf;

  int currentToken;

  mutable int decorated;
  mutable int non_decorated;
  mutable int non_identifier;

  static bool first_time;

  NameDeclaration* doLookup ( NameOccurrence * ) const;

  int getCSIdent ( NameDeclaration *, bool );
};

#endif
