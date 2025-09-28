//******************************************************************************
//
//  KeywordManager.cpp
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

#include <iostream>

#include "y.tab.h"

#include "KeywordManager.h"

using std::cout;
using std::endl;
using std::map;
using std::string;

//------------------------------------------------------------------------------

KeywordManager::KeywordManager( )
{
  struct kwMap
  {
    string name;
    int    token;
  };

  const kwMap keys [] =
  {
    { string( "and"              ), ANDAND              },
    { string( "and_eq"           ), ANDEQ               },
    { string( "asm"              ), KW_asm              },
    { string( "auto"             ), KW_auto             },
    { string( "bitand"           ), AND                 },
    { string( "bitor"            ), OR                  },
    { string( "bool"             ), KW_bool             },
    { string( "break"            ), KW_break            },
    { string( "case"             ), KW_case             },
    { string( "catch"            ), KW_catch            },
    { string( "char"             ), KW_char             },
    { string( "class"            ), KW_class            },
    { string( "compl"            ), COMPLEMENT          },
    { string( "const"            ), KW_const            },
    { string( "const_cast"       ), KW_const_cast       },
    { string( "continue"         ), KW_continue         },
    { string( "default"          ), KW_default          },
    { string( "delete"           ), KW_delete           },
    { string( "do"               ), KW_do               },
    { string( "double"           ), KW_double           },
    { string( "dynamic_cast"     ), KW_dynamic_cast     },
    { string( "else"             ), KW_else             },
    { string( "enum"             ), KW_enum             },
    { string( "explicit"         ), KW_explicit         },
    { string( "export"           ), KW_export           },
    { string( "extern"           ), KW_extern           },
    { string( "false"            ), KW_false            },
    { string( "float"            ), KW_float            },
    { string( "for"              ), KW_for              },
    { string( "friend"           ), KW_friend           },
    { string( "goto"             ), KW_goto             },
    { string( "if"               ), KW_if               },
    { string( "inline"           ), KW_inline           },
    { string( "int"              ), KW_int              },
    { string( "long"             ), KW_long             },
    { string( "mutable"          ), KW_mutable          },
    { string( "namespace"        ), KW_namespace        },
    { string( "new"              ), KW_new              },
    { string( "not"              ), NOT                 },
    { string( "not_eq"           ), NOTEQ               },
    { string( "operator"         ), KW_operator         },
    { string( "or"               ), OROR                },
    { string( "or_eq"            ), OREQ                },
    { string( "private"          ), KW_private          },
    { string( "protected"        ), KW_protected        },
    { string( "public"           ), KW_public           },
    { string( "register"         ), KW_register         },
    { string( "reinterpret_cast" ), KW_reinterpret_cast },
    { string( "return"           ), KW_return           },
    { string( "short"            ), KW_short            },
    { string( "signed"           ), KW_signed           },
    { string( "sizeof"           ), KW_sizeof           },
    { string( "static"           ), KW_static           },
    { string( "static_cast"      ), KW_static_cast      },
    { string( "struct"           ), KW_struct           },
    { string( "switch"           ), KW_switch           },
    { string( "template"         ), KW_template         },
    { string( "this"             ), KW_this             },
    { string( "throw"            ), KW_throw            },
    { string( "true"             ), KW_true             },
    { string( "try"              ), KW_try              },
    { string( "typedef"          ), KW_typedef          },
    { string( "typeid"           ), KW_typeid           },
    { string( "typename"         ), KW_typename         },
    { string( "union"            ), KW_union            },
    { string( "unsigned"         ), KW_unsigned         },
    { string( "using"            ), KW_using            },
    { string( "virtual"          ), KW_virtual          },
    { string( "void"             ), KW_void             },
    { string( "volatile"         ), KW_volatile         },
    { string( "wchar_t"          ), KW_wchar_t          },
    { string( "while"            ), KW_while            },
    { string( "xor"              ), XOR                 },
    { string( "xor_eq"           ), XOREQ               }
  };  

  const int size = sizeof( keys ) / sizeof( keys[0] );

  for ( int i = 0; i < size; ++i )
  {
    keywords[keys[i].name] = keys[i].token;
  }
}

//------------------------------------------------------------------------------

bool KeywordManager::isKeyword ( const string &name ) const
{
  return ( keywords.find( name ) != keywords.end() );
}

//------------------------------------------------------------------------------

string KeywordManager::getName ( int key ) const
{
  map<string,int>::const_iterator ptr = keywords.begin();

  while ( ptr != keywords.end() ) {
    if ( ptr->second == key )
      return ( ptr->first );
    ++ptr;
  }

  return ( "Not a keyword" );
}

//------------------------------------------------------------------------------

int KeywordManager::getToken ( const string &name ) const
{
  map<string,int>::const_iterator p = keywords.find(name);

  if ( p != keywords.end() )
    return ( p->second );
  else
    return ( IDENTIFIER );
}

//------------------------------------------------------------------------------

void KeywordManager::printKeywords ( void ) const
{
  for ( map<string,int>::const_iterator p = keywords.begin();
        p != keywords.end();
        ++p
      )
    cout << p->first << '\t' << p->second << endl;
}

//------------------------------------------------------------------------------
