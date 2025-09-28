//******************************************************************************
//
//  Parser.h
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

#ifndef _PARSER_H_
#define _PARSER_H_

#include <string>

class ActionFacade;
class ArgumentStack;
class ContextManager;
class DeclarationStack;
class KeywordManager;
class LocationTracker;
class Actions;
class TokenDecorator;

// Singleton
class Parser
{
public:
  static Parser* Instance ( void );

  void recycle ( void );

  const KeywordManager * const keywordManager ( void ) const { return keywordManager_; }

  LocationTracker*  const location       ( void ) { return locationTracker_; }
  ContextManager*   const contextManager ( void ) { return contextManager_;  }
  ActionFacade*     const facade         ( void ) { return facade_;          }
  TokenDecorator*   const decorator      ( void ) { return decorator_;       }
  ArgumentStack*    const argStack       ( void ) { return argStack_;        }
  DeclarationStack* const declStack      ( void ) { return declStack_;       }
  Actions*          const actions        ( void ) { return actions_;         }

private:
  static Parser *instance_;

  // Ordering here is critical
  KeywordManager*   keywordManager_;
  LocationTracker*  locationTracker_;
  ContextManager*   contextManager_;
  ActionFacade*     facade_;
  TokenDecorator*   decorator_;
  ArgumentStack*    argStack_;
  DeclarationStack* declStack_;
  Actions*          actions_;

  Parser ( );
};

#endif
