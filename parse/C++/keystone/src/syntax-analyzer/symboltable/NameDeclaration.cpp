//******************************************************************************
//
//  NameDeclaration.cpp
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

#include <sstream>
#include <string>

#include "Assertion.h"
#include "Sentry.h"

#include "ActionFacade.h"
#include "NameOccurrence.h"
#include "Parser.h"

#include "Scope.h"
#include "ClassScope.h"
#include "Type.h"
#include "BasicType.h"
#include "ClassType.h"
#include "EnumType.h"
#include "FunctionType.h"
#include "IndirectType.h"
#include "NamespaceType.h"
#include "TemplateParameterType.h"
#include "TemplateTemplateParameterType.h"

#include "NameDeclaration.h"

using std::list;
using std::ostream;
using std::string;
using std::stringstream;

//------------------------------------------------------------------------------

NameDeclaration::NameDeclaration ( TokenInfo *ti, Scope *c, Type *t, bool isDestructor ) 
                : TokenInfo          ( *ti ),
                  hasTemplate        ( false ),
                  inSymbolTable      ( false ),
                  isConst            ( false ),
                  isFriend           ( false ),
                  isInst             ( false ),
                  isPure             ( false ),
                  isStatic           ( false ),
                  isTemplate         ( false ),
                  isVirtual          ( false ),
                  acc                ( Access::None ),
                  definedIn          ( c ),
                  correspondingScope ( 0 ),
                  theType            ( t ), 
                  occurQualifier     ( 0 )
{
  ST_SENTRY("NameDeclaration::NameDeclaration");

  // THG - constructor/destructor fix
  if ( definedIn &&
       dynamic_cast<ClassScope*>( definedIn ) &&
       getName() == definedIn->getName()
     )
  {

    if ( isDestructor )
      setName( definedIn->getName() + "::~" + definedIn->getName() );
    else
      setName( definedIn->getName() + "::" + definedIn->getName() );      
  }
}

//------------------------------------------------------------------------------

NameDeclaration::~NameDeclaration ( )
{
  ST_SENTRY("NameDeclaration::~NameDeclaration");

  for ( list<TokenPosn *>::iterator ptr = refList.begin();
        ptr != refList.end();
        ++ptr
      ) {
    delete ( *ptr );
  }
}

//------------------------------------------------------------------------------
// Query Methods
//------------------------------------------------------------------------------

// THG - Added to lookup/create a destructor.
bool NameDeclaration::hasDestructor ( void )
{
  ST_SENTRY("NameDeclaration::hasDestructor");

  if ( !theType ||
       !theType->checkType( Type::DT_CLASS )
     )
  {
    return ( false );
  }

  Scope *s = getCorrespondingScope();

  if ( !s )
    return ( false );

  // try to find a destructor entry
  TokenInfo tok( getName() + "::~" + getName(), -1, -1 ); 
  NameOccurrence no( &tok );

  NameDeclaration *nd = s->lookup( &no );
  if ( nd )
  {
    nd->takeReference();
  }

  return ( nd );
}

//------------------------------------------------------------------------------

bool NameDeclaration::isAlias ( void ) const
{
  ST_SENTRY("NameDeclaration::isAlias");

  return ( theType != 0 &&
           theType->checkType( Type::DT_NAMESPACE ) &&
           isInstance()
         );
}

//------------------------------------------------------------------------------

bool NameDeclaration::isAttributeSet ( const Attribute::AType &attr ) const
{
  ST_SENTRY("NameDeclaration::isAttributeSet");

  bool retval;
  switch ( attr )
  {
    case Attribute::Virtual: retval = isVirtual; break;
    case Attribute::Pure   : retval = isPure;    break;
    case Attribute::Friend : retval = isFriend;  break;
    case Attribute::Const  : retval = isConst;   break;
    case Attribute::Static : retval = isStatic;  break;
    default                : throw string( "Invalid Attribute" );
  }

  return ( retval );
}

//------------------------------------------------------------------------------

bool NameDeclaration::isaMatch ( NameOccurrence *occur ) const
{
  ST_SENTRY("NameDeclaration::isaMatch");

  if ( !TokenInfo::isaMatch( occur ) )
    return ( false );

  bool retval = true;
  NameOccurrence::OccurSpecifier spec = occur->getSpec();
  switch ( spec )
  {
    case NameOccurrence::ElabEnum : retval = theType &&
                                             ( theType->checkType( Type::DT_ENUM ) ||
                                               theType->checkType( Type::DT_TEMPLATE_PARM )
                                             );

    case NameOccurrence::ElabClass: retval = theType &&
                                             ( theType->checkType( Type::DT_CLASS ) ||
                                               theType->checkType( Type::DT_TEMPLATE_PARM ) ||
                                               theType->checkType( Type::DT_TEMPLATE_TEMPLATE_PARM )
                                             );

    case NameOccurrence::Member   : retval = !theType ||
                                             !( ( theType->checkType( Type::DT_ENUM ) ||
                                                  theType->checkType( Type::DT_CLASS )
                                                ) &&
                                                isInstance()
                                              ) &&
                                             !theType->checkType( Type::DT_NAMESPACE );

    case NameOccurrence::Namespace: retval = theType && theType->checkType( Type::DT_NAMESPACE );

    case NameOccurrence::Qualifier: retval = theType &&
                                             ( ( theType->checkType( Type::DT_CLASS ) &&
                                                 !isInstance()
                                               ) ||
                                               theType->checkType( Type::DT_NAMESPACE ) ||
                                               ( theType->checkType( Type::DT_BASIC ) &&
                                                 !isInstance()
                                               ) ||
                                               ( theType->checkType( Type::DT_TEMPLATE_PARM ) &&
                                                 !isInstance()
                                               ) ||
                                               ( theType->checkType( Type::DT_TEMPLATE_TEMPLATE_PARM ) &&
                                                 !isInstance()
                                               )
                                             );
  }

  return ( retval );
}

//------------------------------------------------------------------------------
// Accessor Methods
//------------------------------------------------------------------------------

Access::AccessType NameDeclaration::getAccess ( void ) const
{
  ST_SENTRY("NameDeclaration::getAccess");

  return ( acc );
}

//------------------------------------------------------------------------------

NameDeclaration* NameDeclaration::getDestructor ( void )
{
  ST_SENTRY("NameDeclaration::getDestructor");

  if ( !theType->checkType( Type::DT_CLASS ) &&
       !theType->checkType( Type::DT_NAMESPACE )
     )
  {

    TokenInfo tok( "__basic_destructor", -1, -1 );
    NameOccurrence no( &tok );
    Scope *gs = Parser::Instance()->facade()->getGlobalNamespace()->getCorrespondingScope();
    NameDeclaration *nd = gs->lookup( &no );

    if ( nd )
    {
      return ( nd );
    }

    // create a destructor declaration if one is not found
    NameDeclaration *decl = new NameDeclaration( &tok, gs, 0 );
    FunctionType    *ft   = new FunctionType( decl, new BasicType( BasicType::BT_VOID ), FunctionType::Q_FUNCTION );
    decl->setType( ft );
    gs->insertLocal( decl );

    return ( decl );
  }

  if ( !theType ||
       theType->checkType( Type::DT_NAMESPACE )
     )
  {
    return ( 0 );
  }

  Scope *s = theType->getDecl()->getCorrespondingScope();

  // try to find a destructor entry
  TokenInfo tok( theType->getDecl()->getName() + "::~" + theType->getDecl()->getName(), -1, -1 ); 
  NameOccurrence no( &tok );
  NameDeclaration *nd = s->lookup( &no );
  if ( nd )
  {
    return ( nd );
  }
  
  // create a destructor declaration if one is not found
  TokenInfo ti( getName(), "unknown", -1, -1 );
  NameDeclaration *decl = new NameDeclaration( &ti, s, 0, true );
  FunctionType    *ft   = new FunctionType( decl, new BasicType( BasicType::BT_VOID ), FunctionType::Q_FUNCTION );
  decl->setType( ft );
  s->insertLocal( decl );

  return ( decl );
}

//------------------------------------------------------------------------------

TokenPosn* NameDeclaration::getLastReference ( void ) const
{
  ST_SENTRY("NameDeclaration::getLastReference");

  TokenPosn *temp = 0;

  if ( refList.size() != 0 )
    temp = refList.front();

  return ( temp );
}

//------------------------------------------------------------------------------
// Mutator Methods
//------------------------------------------------------------------------------

// THG - Added code to get and set an attribute
// such as virtual, pure, friend, and const

void NameDeclaration::setAttribute ( const Attribute::AType &attr )
{
  ST_SENTRY("NameDeclaration::setAttribute");

  switch ( attr )
  {
    case Attribute::Const  : isConst   = true; break;
    case Attribute::Friend : isFriend  = true; break;
    case Attribute::Pure   : isPure    = true; break;
    case Attribute::Static : isStatic  = true; break;
    case Attribute::Virtual: isVirtual = true; break;
    default                : throw string( "Invalid Attribute." );
  }
}

//------------------------------------------------------------------------------

void NameDeclaration::addReference ( TokenPosn *ref )
{
  ST_SENTRY("NameDeclaration::addReference");

  MAKE_ASSERTION( ref != 0, "Cannot add NULL reference." );

  TokenPosn *tp = new TokenPosn( *ref );
  refList.push_front( tp );
}

//------------------------------------------------------------------------------

TokenPosn* NameDeclaration::takeReference ( void )
{
  ST_SENTRY("NameDeclaration::takeReference");

  #if 0
  MAKE_ASSERTION( refList.size() != 0,
                  "cannot take reference for: " + getName() + " because there is not one to take." );
   TokenPosn * temp = refList.front();
   refList.pop_front();
   return ( temp );
  #endif

  if ( refList.size() )
  {
    TokenPosn *temp = refList.front();      
    refList.pop_front();

    return ( temp );
  }

  return ( new TokenPosn( "unknown", -1, -1 ) );
}

//------------------------------------------------------------------------------

ostream& NameDeclaration::printRefs ( ostream &out ) const
{
#if 0
  ST_SENTRY("NameDeclaration::printRefs");

  if ( refList.size() == 0 ) {
    out << " (no refs)";
  }
  else {
    out << " refs:";
    for ( list<TokenPosn *>::const_iterator ptr = refList.begin();
          ptr != refList.end();
          ++ptr
        ) {
      out << " " << **ptr ;
    }
  }
#endif
  return ( out );
}


//------------------------------------------------------------------------------

ostream& operator<< ( ostream &out, const NameDeclaration &entry )
{
  ST_SENTRY("NameDeclaration::operator<<");

  return ( entry.Print( out ) );
}

//------------------------------------------------------------------------------

ostream& NameDeclaration::Print ( ostream &out ) const
{
  ST_SENTRY("NameDeclaration::Print");

  TokenInfo::Print( out );

  if ( theType != 0 )
  {
    if( isInstance() )
      out << " instance of";
    out << ": " << *(theType);
  }

  if ( theType && (theType->checkType(Type::DT_NAMESPACE) ||
                    theType->checkType(Type::DT_CLASS) ||
                    theType->checkType(Type::DT_FUNCTION)) )
  {
    if ( !correspondingScope )
      out << ": No corresponding scope";
  }

  if ( isPure    ) out << " Pure";
  if ( isVirtual ) out << " Virtual";
  if ( isFriend  ) out << " Friend";
  if ( isConst   ) out << " Const";
  if ( isStatic  ) out << " Static";

       if ( acc == Access::Public    ) out << " Public";
  else if ( acc == Access::Protected ) out << " Protected";
  else if ( acc == Access::Private   ) out << " Private";

  printRefs( out );

  return ( out );
}

//------------------------------------------------------------------------------

string NameDeclaration::toString ( void ) const
{
  stringstream sstr;

  sstr << TokenInfo::toString();

  if ( theType != 0 )
  {
    if ( isInstance() )
    {
      sstr << " instance of";
    }
    sstr << ": " << *theType;
  }

  if ( theType &&
       ( theType->checkType( Type::DT_NAMESPACE ) ||
         theType->checkType( Type::DT_CLASS     ) ||
         theType->checkType( Type::DT_FUNCTION  )
       )
     )
  {
    if ( ! correspondingScope )
    {
      sstr << ": No corresponding scope";
    }
  }

  if ( isPure    ) sstr << " Pure";
  if ( isVirtual ) sstr << " Virtual";
  if ( isFriend  ) sstr << " Friend";
  if ( isConst   ) sstr << " Const";
  if ( isStatic  ) sstr << " Static";

       if ( acc == Access::Public    ) sstr << " Public";
  else if ( acc == Access::Protected ) sstr << " Protected";
  else if ( acc == Access::Private   ) sstr << " Private";

  return sstr.str();
}

//------------------------------------------------------------------------------
