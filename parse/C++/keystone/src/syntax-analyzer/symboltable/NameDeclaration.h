//******************************************************************************
//
//  NameDeclaration.h
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

#ifndef _NAME_DECLARATION_H_
#define _NAME_DECLARATION_H_

#include <iostream>
#include <list>

#include "Access.h"
#include "Attribute.h"
#include "Sentry.h"
#include "TokenInfo.h"

//#include "NameDeclarationInvariantFacilitator.h"

class NameOccurrence;
class Scope;
class Type;

// Old declaration with multiple inheritance changed to work with SWIG
//class NameDeclaration : public TokenInfo, public NameDeclarationInvariantFacilitator {

class NameDeclaration : public TokenInfo
{
public:
  // THG - isDestructor for destructor name change
  NameDeclaration  ( TokenInfo *, Scope *, Type *, bool isDestructor = false );
  ~NameDeclaration ( );
   
  bool hasDestructor   ( void );
  bool isAlias         ( void )                     const;
  bool isAttributeSet  ( const Attribute::AType & ) const;
  bool isInSymbolTable ( void )                     const { return ( inSymbolTable ); }
  bool isInstance      ( void )                     const { return ( isInst );        }
  bool isaMatch        ( NameOccurrence * )         const;
  bool markedTemplate  ( void )                           { return ( hasTemplate );   }

  Access::AccessType getAccess             ( void ) const;
  Scope*             getContainingScope    ( void ) const { return ( definedIn );          }
  Scope*             getCorrespondingScope ( void ) const { return ( correspondingScope ); }
  NameDeclaration*   getDestructor         ( void );
  bool               getIsTemplate         ( void )       { return ( isTemplate );         }
  TokenPosn*         getLastReference      ( void ) const; 
  NameDeclaration*   getOccurQual          ( void ) const { return ( occurQualifier );     }
  Type*              getType               ( void ) const { return ( theType );            }

  void setAccess    ( const Access::AccessType & );
  void setAttribute ( const Attribute::AType &   );
  void setType      ( Type * );

  void setContainingScope    ( Scope *s   )            { definedIn          = s;   }
  void setCorrespondingScope ( Scope *ptr )            { correspondingScope = ptr; }
  void setInstance           ( bool b )                { isInst     = b; }
  void setIsTemplate         ( bool b )                { isTemplate = b; }
  void setOccurQual          ( NameDeclaration *qual ) { occurQualifier = qual; }

  void       addReference  ( TokenPosn * ); 
  TokenPosn* takeReference ( void );

  void makeInSymbolTable     ( void ) { inSymbolTable = true;  }
  void markTemplate          ( void ) { hasTemplate   = true;  }
  void removeFromSymbolTable ( void ) { inSymbolTable = false; }

          std::ostream& printRefs ( std::ostream & ) const;
  virtual std::ostream& Print     ( std::ostream & ) const;

  std::string toString ( void ) const;

private:
  bool hasTemplate;
  bool inSymbolTable;
  bool isConst;
  bool isFriend;
  bool isInst;
  bool isPure;
  bool isStatic;
  bool isTemplate;
  bool isVirtual;

  Access::AccessType acc;

  Scope           *definedIn;
  Scope           *correspondingScope;
  Type            *theType;

  NameDeclaration *occurQualifier; // Most recent qualifier only

  std::list<TokenPosn *> refList;
};

std::ostream& operator<< ( std::ostream &, const NameDeclaration & );

//--------------------
// Inline Definitions
//--------------------

inline void NameDeclaration::setAccess ( const Access::AccessType &atype )
{
  ST_SENTRY("NameDeclaration::setAccess");

  acc = atype;
}

//------------------------------------------------------------------------------

inline void NameDeclaration::setType ( Type *t )
{
  ST_SENTRY("NameDeclaration::setType");

  theType = t;
}

//------------------------------------------------------------------------------

#endif
