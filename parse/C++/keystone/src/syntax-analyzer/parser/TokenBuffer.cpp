//******************************************************************************
//
//  TokenBuffer.cpp
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

#include "Assertion.h"
#include "Sentry.h"

#include "BtYaccPosn.h"
#include "ActionFacade.h"
#include "LocationTracker.h"
#include "NameOccurrence.h"

#include "NameDeclaration.h"
#include "Type.h"

#include "TokenBuffer.h"

using std::cout;
using std::endl;
using std::string;

//------------------------------------------------------------------------------

extern int yylex();

extern char   *yytext;
extern YYPOSN  yyposn;

//------------------------------------------------------------------------------

namespace key
{
  inline bool one_of ( int a, int x, int y )
  {
    if ( a == x || a == y )
      return ( true );
    return ( false );
  }

  inline bool one_of ( int a, int x, int y, int z )
  {
    if ( a == x || a == y || a == z )
      return ( true );
    return ( false );
  }

  inline bool none_equal( int x, int y )
  {
    if ( x != y )
      return ( true );
    return ( false );
  }

  inline bool none_equal ( int x, int y, int z )
  {
    if ( x != y && y != z && x != z )
      return ( true );
    return ( false );
  }

  inline bool does_match_multi( int tok1, int tok2, int kw1, int kw2 )
  {
    if ( none_equal( tok1, tok2 ) && 
         one_of( tok1, kw1, kw2 ) &&
         one_of( tok2, kw1, kw2 )
       )
    {
      return ( true );
    }
    return ( false );
  }

  inline bool does_match_multi( int tok1, int tok2, int tok3, int kw1, int kw2, int kw3 )
  {
    if ( none_equal( tok1, tok2, tok3 ) &&
         one_of( tok1, kw1, kw2, kw3 )  &&
         one_of( tok2, kw1, kw2, kw3 )  &&
         one_of( tok3, kw1, kw2, kw3 )
       )
    {
      return ( true );
    }
    return ( false );
  }

}

//------------------------------------------------------------------------------

TokenBuffer::TokenBuffer ( LocationTracker *lt, ActionFacade *af )
            : location            ( lt ),
              facade              ( af ),
              currentToken        ( -1 ),
              tokenCounter        ( -1 ),
              lastLine            ( -1 ),
              lastToken           ( 0 ),
              parenLevel          ( 0 ),
              inBaseSpecifierList ( false ),
              inMemberAccess      ( false ),
              inTemplateArgList   ( false ),
              lastWasF            ( false ),
              seenEOF             ( false ), 
              last_identifier     ( 0 ),
              before_equal        ( 0 ),
              before_paren        ( 0 ),
              set_spec            ( 0 ),
              set_qual            ( 0 )
{ }

//------------------------------------------------------------------------------

void TokenBuffer::dump ( void ) const
{
   cout << "Token Buffer: " << endl;
   for ( int i = 0; i < MAX_BUF; ++i )
   {
      cout << "\t" << i << ". " << buf[i].filename << ":" << buf[i].lineNumber << ": " << buf[i].text << endl;
   }

   cout << endl;
   cout << "\tcurrent: " << currentToken << endl;
   cout << "\tlast:    " << lastToken << endl;

   cout << endl;
}

//------------------------------------------------------------------------------

void TokenBuffer::readToken ( int index )
{
  P_SENTRY;

  buf[index].token = ::yylex();

  int line = location->lineNumber();

  buf[index].lineNumber = line;
  buf[index].text       = ::yytext;
  buf[index].filename   = location->fileName();
  buf[index].lastDecl   = 0;

  if ( lastLine != line )
  {
    lastLine = line;
    tokenCounter = 1;
  }
  else
  {
    ++tokenCounter;
  }

  if ( buf[index].token == IDENTIFIER        ||
       buf[index].token == INTEGER_LITERAL   ||
       buf[index].token == CHARACTER_LITERAL ||
       buf[index].token == FLOATING_LITERAL  ||
       buf[index].token == STRING_LITERAL
     )
  {
    buf[index].attrib.id_sym = new TokenInfo( ::yytext, location->fileName(), line, tokenCounter );
  }
  else
  {
    buf[index].attrib.tcount = line;
  }

  seenEOF = ( buf[index].token == 0 );
}

//------------------------------------------------------------------------------

void TokenBuffer::init ( void )
{
  P_SENTRY;

   for ( int i = 0; i < MAX_BUF && !seenEOF; ++i )
   {
      readToken( i );
      lastToken = i;
   }
}

//------------------------------------------------------------------------------

bool TokenBuffer::nextIsLESS ( void ) const
{
  P_SENTRY;

  return ( buf[currentToken+1].token == LESS );
}

//------------------------------------------------------------------------------

bool TokenBuffer::nextIsLPAREN ( void ) const
{
  P_SENTRY;

  return ( buf[currentToken+1].token == LEFTPAREN );
}

//------------------------------------------------------------------------------

bool TokenBuffer::nextIsColCol ( void ) const
{
  P_SENTRY;

  return ( buf[currentToken+1].token == COLCOL );
}

//------------------------------------------------------------------------------

bool TokenBuffer::prevIsType ( void ) const
{
  bool retval;

  switch ( buf[currentToken-1].token )
  {
    case ID_typedef_name:
    case ID_class_name:
    case ID_enum_name:
    case ID_template_name:
    case KW_char:
    case KW_unsigned_char:
    case KW_wchar_t:
    case KW_bool:
    case KW_short:
    case KW_unsigned_short:
    case KW_int:
    case KW_long:
    case KW_unsigned_long:
    case KW_signed:
    case KW_unsigned:
    case KW_float:
    case KW_double:
    case KW_long_double:
    case KW_void:
      retval = true;
      break;
    default:
      retval = false;
      break;
  }

  return retval;
}

//------------------------------------------------------------------------------

int TokenBuffer::getNextToken ( void )
{
  P_SENTRY;

  int token;
  if ( currentToken < MAX_BUF / 2 )
  { // initial phase
    if ( currentToken < lastToken )
      ++currentToken;
  }
  else if ( seenEOF )
  { // third & final phase
    if ( currentToken < lastToken )
      ++currentToken;
  }
  else if ( currentToken == MAX_BUF / 2 && lastToken == MAX_BUF - 1 )
  { // second phase, refresh buffer
    for ( int i = 0; i + 1 < MAX_BUF; ++i) {
      buf[i].token      = buf[i+1].token;
      buf[i].lineNumber = buf[i+1].lineNumber;
      buf[i].attrib     = buf[i+1].attrib;
      buf[i].lastDecl   = buf[i+1].lastDecl;
      buf[i].text       = buf[i+1].text;
      buf[i].filename   = buf[i+1].filename;
    } 
    readToken( MAX_BUF-1 );
  }
  else
  {
    throw string( "Error in TokenBuffer" );
  }

  token = buf[currentToken].token;
  ::yyposn.filename   = new string( buf[currentToken].filename );
  ::yyposn.lineNumber = buf[currentToken].lineNumber;

  if ( token == DOT || token == ARROW )
  {
    inMemberAccess = true;
  }
  else if ( ( token == KW_class || token == KW_struct ) &&
            ( currentToken+2 <= lastToken )             &&
              buf[currentToken+1].token == IDENTIFIER   &&
              buf[currentToken+2].token == COLON
          )
  {
    inBaseSpecifierList = true;
  }
  else if ( token == LEFTBRACK )
  {
    inBaseSpecifierList = false;
  }
  else if( inTemplateArgList && token == LEFTPAREN )
  {
    ++parenLevel;
  }
  else if( inTemplateArgList && token == RIGHTPAREN )
  {
    --parenLevel;
  }
  else if( token == GREATER && inTemplateArgList && !parenLevel )
  {
    restoreId();
  }

  getMultiWordType( token );

  return ( token );
}

//------------------------------------------------------------------------------

int TokenBuffer::getTokenNumber ( void )
{
  return ( currentToken );
}

//------------------------------------------------------------------------------

string TokenBuffer::getTokenText ( void )
{
  return ( ::yytext );
}

//------------------------------------------------------------------------------

void TokenBuffer::getMultiWordType ( int &token )
{
  P_SENTRY;

  bool found = false;

  if( currentToken + 2 <= lastToken )
  {
    // assume we are going to find it.
    found = true;

    int ct  = buf[currentToken].token;
    int ct2 = buf[currentToken+1].token;
    int ct3 = buf[currentToken+2].token;

    // check for 3 word type
    if ( key::does_match_multi( ct, ct2, ct3, KW_unsigned, KW_short, KW_int ) )
    {
      token = KW_unsigned_short;
      getNextToken(); // THIS ACTUALLY GETS 2 TOKENS!!!! short int is a MULTI-TOKEN!!!!
    }
    else if ( key::does_match_multi( ct, ct2, ct3, KW_signed, KW_short, KW_int ) )
    {
      token = KW_short;
      getNextToken(); // SEE ABOVE
    }
    else if ( key::does_match_multi( ct, ct2, ct3, KW_unsigned, KW_long, KW_int ) )
    {
      token = KW_unsigned_long;
      getNextToken(); // SEE ABOVE
    }
    else if ( key::does_match_multi( ct, ct2, ct3, KW_signed, KW_long, KW_int ) )
    {
      token = KW_long;
      getNextToken(); // SEE ABOVE
    }
    else
    {
      // nope...didn't find it
      found = false;
    }
  }

  if ( !found && currentToken + 1 <= lastToken )
  {
    int ct  = buf[currentToken].token;
    int ct2 = buf[currentToken+1].token;

    // check 2 word types
    if ( key::does_match_multi( ct, ct2, KW_unsigned, KW_short ) )
    {
      token = KW_unsigned_short;
      getNextToken();
    }			
    else if ( key::does_match_multi( ct, ct2, KW_signed, KW_short ) )
    {
      token = KW_short;
      getNextToken();
    }			
    else if ( key::does_match_multi( ct, ct2, KW_unsigned, KW_int ) )
    {
      token = KW_unsigned;
      getNextToken();
    }			
    else if ( key::does_match_multi( ct, ct2, KW_signed, KW_int ) )
    {
      token = KW_int;
      getNextToken();
    }			
    else if ( key::does_match_multi( ct, ct2, KW_unsigned, KW_long ) )
    {
      token = KW_unsigned_long;
      getNextToken();
    }			
    else if ( key::does_match_multi( ct, ct2, KW_signed, KW_long ) )
    {
      token = KW_long;
      getNextToken();
    }			
    else if ( key::does_match_multi( ct, ct2, KW_long, KW_int ) )
    {
      token = KW_long;
      getNextToken();
    }			
    else if ( key::does_match_multi( ct, ct2, KW_short, KW_int ) )
    {
      token = KW_short;
      getNextToken();
    }			
    else if ( key::does_match_multi( ct, ct2, KW_unsigned, KW_char ) )
    {
      token = KW_unsigned_char;
      getNextToken();
    }			
    else if ( key::does_match_multi( ct, ct2, KW_signed, KW_char ) )
    {
      token = KW_char;
      getNextToken();
    }
    else if ( key::does_match_multi( ct, ct2, KW_long, KW_double ) )
    {
      token = KW_long_double;
      getNextToken();
    }
  }
}

//------------------------------------------------------------------------------
// THG - Added set_spec for statistics.

void TokenBuffer::setOccurSpec ( NameOccurrence *occur )
{
  P_SENTRY;

  // Check left context
  if ( currentToken >= 1 )
  {
    int lc1 = buf[currentToken-1].token; 
    if ( lc1 == KW_enum )
    {
      occur->setSpec( NameOccurrence::ElabEnum );
      ++set_spec;
    }
    else if ( lc1 == KW_class || lc1 == KW_union || lc1 == KW_struct )
    {
      occur->setSpec( NameOccurrence::ElabClass );
      ++set_spec;
    }
    else if ( lc1 == KW_namespace )
    {
      occur->setSpec( NameOccurrence::Namespace );
      ++set_spec;
    }
    else if ( lc1 == COMPLEMENT )
    {
      occur->setSpec( NameOccurrence::Destructor );
      ++set_spec;
    }
  }

  // Check right context
  if ( currentToken+1 <= lastToken && buf[currentToken+1].token == COLCOL)
  {
    occur->setSpec( NameOccurrence::Qualifier );
    ++set_spec;
  }

  // Check other local flags...
  if ( inMemberAccess && occur->getSpec() == NameOccurrence::nothing )
  {
    occur->setSpec( NameOccurrence::Member );
    inMemberAccess = false;
    ++set_spec;
  }
  else if ( inBaseSpecifierList && occur->getSpec() != NameOccurrence::Qualifier )
  {
    occur->setSpec( NameOccurrence::ElabClass );
    ++set_spec;
  }
}

//------------------------------------------------------------------------------
// THG - Added set_qual for statistics
NameOccurrence* TokenBuffer::getNameOccurrence ( void )
{
  P_SENTRY;

  if ( buf[currentToken].token != IDENTIFIER )
  {
    throw string( "TokenBuffer: Not an id!" );
  }

  NameOccurrence *occur = new NameOccurrence( buf[currentToken].attrib.id_sym );
  
  if ( currentToken-2 >= 0 && buf[currentToken-1].token==COMPLEMENT &&
                              buf[currentToken-2].token==COLCOL
     )
  {
    if( last_identifier->getOccurQual() )
      occur->setQualifier( last_identifier->getOccurQual() );
    else
      occur->setQualifier( facade->getGlobalNamespace() );
    ++set_qual;
  }
  else if ( currentToken-2 >= 0 && buf[currentToken-1].token==COLCOL &&
                                   buf[currentToken-2].token==IDENTIFIER
          )
  {
    MAKE_ASSERTION( buf[currentToken-2].attrib.decl != 0,
                    "getNameOccurrence could not find a declaration of a qualifier."
                  );

    occur->setQualifier(buf[currentToken-2].attrib.decl);
    ++set_qual;
  }
  else if ( currentToken-2 >= 0 && buf[currentToken-1].token == COLCOL &&
                                   buf[currentToken-2].token == GREATER
          )
  {
    if ( buf[currentToken-2].lastDecl )
    {
      occur->setQualifier(buf[currentToken-2].lastDecl);
      ++set_qual;
    }
  }
  else if ( currentToken-2 >= 0 && buf[currentToken-1].token == KW_template &&
                                   buf[currentToken-2].token == COLCOL
          )
  {
    if ( buf[currentToken-2].lastDecl )
    {
      occur->setQualifier(buf[currentToken-2].lastDecl);
      ++set_qual;
    }
    else
    {
      occur->setQualifier(last_identifier);
    }
  }
  else if ( currentToken-1 >= 0 && buf[currentToken-1].token==COLCOL)
  { // Global
    occur->setQualifier(facade->getGlobalNamespace());
    ++set_qual;
  }

  if ( currentToken-2 >= 0                      &&
       buf[currentToken-1].token == KW_template &&
      ( buf[currentToken-2].token == COLCOL  ||
        buf[currentToken-2].token == ARROW   ||
        buf[currentToken-2].token == DOT )
     )
  {
    occur->setTemplate( true );
  }

  if ( currentToken-1 >= 0                        &&
       ( buf[currentToken-1].token == KW_class ||
         buf[currentToken-1].token == KW_struct ) &&
       currentToken-2 >= 0                        &&
       buf[currentToken-2].token == GREATER       &&
       currentToken+1 < MAX_BUF                   &&
       buf[currentToken+1].token == LESS
     )
  {
    occur->setTemplate( true );
  }
  setOccurSpec( occur );

  return ( occur ); // deleted by caller (TokenDecorator)
}

//------------------------------------------------------------------------------

void TokenBuffer::saveId ( void )
{
  P_SENTRY;

  inTemplateArgList = true;
  idStack.push( last_identifier );
}

//------------------------------------------------------------------------------

void TokenBuffer::restoreId ( void )
{
  P_SENTRY;

  if ( idStack.empty() )
    return;

  if ( buf[currentToken].token == GREATER )
    buf[currentToken].lastDecl = idStack.top();

  if ( currentToken+1 < MAX_BUF && buf[currentToken+1].token == COLCOL )
    buf[currentToken+1].lastDecl = idStack.top();

  idStack.pop();
  inTemplateArgList = false;
}
//------------------------------------------------------------------------------

void TokenBuffer::setNameDeclaration ( NameDeclaration *decl )
{
  P_SENTRY;

  if ( buf[currentToken].token != IDENTIFIER )
  {
    throw string( "TokenBuffer: Not an id!" );
  }

  if ( currentToken+1 < MAX_BUF && buf[currentToken+1].token == EQUAL )
    before_equal = decl;

  if ( currentToken+1 < MAX_BUF && buf[currentToken+1].token == LEFTPAREN )
    before_paren = decl;

  // buf[currentToken].attrib.id_sym belongs to NameDeclaration
  buf[currentToken].attrib.decl = decl;
  last_identifier = decl;

  if ( currentToken+1 < MAX_BUF && buf[currentToken+1].token == LEFTPAREN )
  {
    if ( currentToken -1 < 0 || buf[currentToken-1].token == KW_template )
    {
      lastWasF = false;
    }
    else
    {
      /// THG had: decl->getName().find( "::" )
      /// NAK believes he meant != npos (i.e. found)
      lastWasF = ( ( decl->getType() && decl->getType()->checkType( Type::DT_FUNCTION ) ) ||
                   ( decl->getOccurQual() && ( decl->getName().find( "::" ) != std::string::npos ) )
                 );
    }
  }   
}

//------------------------------------------------------------------------------

int TokenBuffer::getTokenCount ( void ) const
{
  P_SENTRY;

  if ( buf[currentToken].token == IDENTIFIER )
    return ( buf[currentToken].attrib.decl->getColnum() );
  else
    return ( buf[currentToken].attrib.tcount );
}

//------------------------------------------------------------------------------
