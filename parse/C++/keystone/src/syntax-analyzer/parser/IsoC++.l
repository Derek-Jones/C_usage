/*
 *  IsoCpp.flex
 *
 *  Copyright (C) 2000-2004 by
 *
 *    Department of Computer Science, Clemson University,
 *    Department of Computer Science, National University of Ireland, Maynooth.
 * 
 *  http://keystone.sourceforge.net
 *
 *  <keystone@cs.clemson.edu>
 *
 *  Keystone is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  Keystone is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

%{
  #include <sstream>
  #include <string>
 
  #include "Parser.h"
  #include "KeywordManager.h"
  #include "LocationTracker.h"
  #include "TokenInfo.h"

  #include "BtYaccPosn.h"
  #include "y.tab.h"

  void yyerror_detailed ( char *, int, YYSTYPE &, YYPOSN & );

  namespace flex
  {
    static int check_keyword ( const std::string & );

    void do_newline      ( void );
    void do_preprocessor ( void );

    std::string text;
  }
%}

/* Start states for comments */
%x COMMENT
%x PREPROCESSOR

/*------------------------------------------------------------------------------
 * DEFINITIONS
 *------------------------------------------------------------------------------
 */

/* Whitespace */
NEWLINE [\n]
WHITEC  ([ \t\f\r])

/* Integer Literals */
DEC_LIT    [1-9][0-9]*
OCT_LIT    0[0-7]*
HEX_DIGIT  [0-9A-Fa-f]
HEX_LIT    0[xX]{HEX_DIGIT}+
INT_SUFFIX ([uU][lL]?)|([lL][uU]?)
INT_LIT    ({DEC_LIT}|{OCT_LIT}|{HEX_LIT}){INT_SUFFIX}?


/* Float Literals */
DIGIT_SEQ    [0-9]+
FRACT_CONST  ({DIGIT_SEQ}?\.{DIGIT_SEQ})|({DIGIT_SEQ}\.)
EXPONENT     [eE][+-]?{DIGIT_SEQ}
FLOAT_SUFFIX [fFlL]
FLOAT_LIT    ({FRACT_CONST}{EXPONENT}?{FLOAT_SUFFIX}?)|({DIGIT_SEQ}{EXPONENT}{FLOAT_SUFFIX}?)

/* Characters and Strings */
HEX_QUAD   {HEX_DIGIT}{4}
UNI_CHAR   (\\[u]{HEX_QUAD})|(\\[U]{HEX_QUAD}{HEX_QUAD})
SIMPLE_ESC \\['"?\\abfnrtv]
OCTAL_ESC  \\[0-7]{1,3}
HEX_ESC    \\x{HEX_DIGIT}+
ESC_SEQ    {SIMPLE_ESC}|{OCTAL_ESC}|{HEX_ESC}
C_CHAR     [^'\\\n]|{ESC_SEQ}|{UNI_CHAR}
CHAR_LIT   [L]?'{C_CHAR}+'
S_CHAR     [^"\\\n]|{ESC_SEQ}|{UNI_CHAR}
STRING_LIT [L]?\"{S_CHAR}*\"


/* Identifiers */
NONDIGIT {UNI_CHAR}|[_a-zA-Z]
IDENT    {NONDIGIT}({NONDIGIT}|[0-9])*

/*------------------------------------------------------------------------------
 * LEXICAL RULES
 *------------------------------------------------------------------------------
 */

%%

"/*"          { BEGIN(COMMENT); }
<COMMENT>"*/" { BEGIN(0);       }
<COMMENT>\n   { flex::do_newline();   }
<COMMENT>.    { ; }

"//".*        { ; }
 
"#"                { BEGIN(PREPROCESSOR); }
<PREPROCESSOR>\\\n { flex::do_preprocessor();  }
<PREPROCESSOR>\n   { flex::do_preprocessor(); BEGIN(0); }
<PREPROCESSOR>.    { flex::text.append( yytext ); }

"("   { return LEFTPAREN;  }
")"   { return RIGHTPAREN; }
"{"   { return LEFTBRACK;  }
"}"   { return RIGHTBRACK; }
"["   { return LEFTARRAY;  }
"]"   { return RIGHTARRAY; }
"+"   { return PLUS;       }
"-"   { return MINUS;      }
"*"   { return STAR;       }
"/"   { return DIVIDE;     }
"%"   { return MOD;        }
">"   { return GREATER;    }
"<"   { return LESS;       }
"="   { return EQUAL;      }
"&"   { return AND;        }
"|"   { return OR;         }
"!"   { return NOT;        }
"^"   { return XOR;        }
","   { return COMMA;      }
";"   { return SEMI;       }
":"   { return COLON;      }
"~"   { return COMPLEMENT; }
"."   { return DOT;        }
"?"   { return QUESTION;   }
"*="  { return STAREQ;     }
"/="  { return DIVEQ;      }
"%="  { return MODEQ;      }
"+="  { return PLUSEQ;     }
"-="  { return MINUSEQ;    }
"<<=" { return LTLTEQ;     }
">>=" { return GTGTEQ;     }
"&="  { return ANDEQ;      }
"^="  { return XOREQ;      }
"|="  { return OREQ;       }
"||"  { return OROR;       }
"&&"  { return ANDAND;     }
"=="  { return EQEQ;       }
"!="  { return NOTEQ;      }
"<="  { return LEQ;        }
">="  { return GEQ;        }
"<<"  { return LTLT;       } 
">>"  { return GTGT;       }
".*"  { return DOTSTAR;    }
"->*" { return ARROWSTAR;  }
"++"  { return PLUSPLUS;   }
"--"  { return MINUSMINUS; }
"->"  { return ARROW;      }
"::"  { return COLCOL;     }
"..." { return ELLIPSES;   }

{INT_LIT}    { return INTEGER_LITERAL; }
{FLOAT_LIT}  { return FLOATING_LITERAL; }
{CHAR_LIT}   { return CHARACTER_LITERAL; }
{STRING_LIT} { return STRING_LITERAL; }
{IDENT}      { return flex::check_keyword( yytext ); }
{WHITEC}     { ; }
{NEWLINE}    { flex::do_newline(); }

.            {
               LocationTracker *location = Parser::Instance()->location();
               unsigned int line = location->lineNumber();
               YYSTYPE lval;
               lval.id_sym = new TokenInfo( yytext, location->fileName(), line, 0 );

               YYPOSN  lexPosn;
               lexPosn.filename   = new std::string( location->fileName() );
               lexPosn.lineNumber = line;

               yyerror_detailed( "lexical error", IDENTIFIER, lval, lexPosn );
             }

%%

/*------------------------------------------------------------------------------
 * Overloaded BtYacc Functions
 *------------------------------------------------------------------------------
 */

int yywrap ( void )
{
  return ( 1 );
}

/*------------------------------------------------------------------------------
 * Helper Functions
 *------------------------------------------------------------------------------
 */

namespace flex
{
  /*------------------------------------------------------------------------------ */

  static int check_keyword ( const std::string &name )
  {
    int tok = Parser::Instance()->keywordManager()->getToken( name );
    return ( tok );
  }

  /*------------------------------------------------------------------------------ */

  void do_newline ( void )
  {
    Parser::Instance()->location()->incrementLineNumber();
  }

  /*------------------------------------------------------------------------------ */

  void do_preprocessor ( void )
  {
    std::istringstream temp( flex::text.c_str() );
    int num;
    std::string strtemp;
    temp >> num >> strtemp;
    if ( temp && strtemp[0] == '"')
    {
      LocationTracker *location = Parser::Instance()->location();
      location->setLineNumber( num );
      location->setFileName( strtemp.substr( 1, strtemp.size() - 2 ) );
    }
    flex::text = "";
  }

  /*------------------------------------------------------------------------------ */
}


