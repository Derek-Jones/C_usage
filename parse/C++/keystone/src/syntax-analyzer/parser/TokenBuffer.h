//******************************************************************************
//
//  TokenBuffer.h
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

#ifndef _TOKEN_BUFFER_H_
#define _TOKEN_BUFFER_H_

#include <stack>
#include <string>

#include "y.tab.h"

class ActionFacade;
class LocationTracker;
class NameOccurrence;

class TokenBuffer
{
public:
  TokenBuffer ( LocationTracker *, ActionFacade * );

  void init ( void );
  void dump ( void ) const;

  bool nextIsLESS     ( void ) const;
  bool nextIsLPAREN   ( void ) const;
  bool nextIsColCol   ( void ) const;
  bool lastWasFun     ( void ) const { return ( lastWasF );                              }
  bool nextIsClass    ( void ) const { return ( buf[currentToken+1].token == KW_class ); }
  bool prevIsEqual    ( void ) const { return ( buf[currentToken-1].token == EQUAL );    }
  bool prevIsType     ( void ) const;
  bool nextIsSemi     ( void ) const { return ( buf[currentToken+1].token == SEMI );     }
  bool isMemberAccess ( void ) const { return ( inMemberAccess );                        }

  int  getNextToken     ( void );
  int  getTokenNumber   ( void );
  int  getTokenCount    ( void ) const;
  int  getCurrentToken  ( void ) const { return ( buf[currentToken].token ); }
  int  getCurrentLine   ( void ) const { return ( lastLine );                }
  void getMultiWordType ( int & );

  std::string getTokenText       ( void );
  std::string getCurrentFilename ( void ) const { return ( buf[currentToken].filename ); }
  std::string getCurrentText     ( void ) const { return ( buf[currentToken].text     ); }

  NameDeclaration* getLastIdentifier ( void ) const { return ( last_identifier ); }
  NameDeclaration* getBeforeEqual    ( void ) const { return ( before_equal );    }
  NameDeclaration* getBeforeParen    ( void ) const { return ( before_paren );    }
  NameOccurrence * getNameOccurrence ( void );

  void setNameDeclaration ( NameDeclaration * );

  void saveId    ( void );
  void restoreId ( void );

  // THG - Statistics
  int getSpecStat ( void ) const { return ( set_spec ); }
  int getQualStat ( void ) const { return ( set_qual ); }

private:
  void readToken    ( int );
  void setOccurSpec ( NameOccurrence * );

private:
  LocationTracker *location;
  ActionFacade    *facade;

  enum { MAX_BUF = 5 };
  struct
  {
    int              token;
    int              lineNumber;
    std::string      text;
    std::string      filename;
    YYSTYPE          attrib;
    NameDeclaration *lastDecl;
  } buf[MAX_BUF];

  int currentToken;
  int tokenCounter;
  int lastLine;
  int lastToken;
  int parenLevel;

  bool inBaseSpecifierList;
  bool inMemberAccess;
  bool inTemplateArgList;
  bool lastWasF;
  bool seenEOF;

  NameDeclaration *last_identifier;
  NameDeclaration *before_equal;
  NameDeclaration *before_paren;

  int set_spec;
  int set_qual;

  // THG - for templates
  std::stack<NameDeclaration *> idStack;
};

#endif
