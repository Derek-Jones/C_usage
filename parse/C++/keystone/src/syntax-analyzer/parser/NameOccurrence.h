//******************************************************************************
//
//  NameOccurrence.h
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

#ifndef _NAME_OCCURRENCE_H_
#define _NAME_OCCURRENCE_H_

#include <iostream>

#include "TokenInfo.h"

class Scope; 
class ClassScope;
class FunctionScope;
class LocalScope; 
class NamespaceScope; 
class PrototypeScope;

class NameDeclaration;

class NameOccurrence : public TokenInfo
{
public:

  enum OccurSpecifier
  {
    ConvFunction,
    Destructor,
    DestructorQualifier,
    ElabEnum,
    ElabClass,
    Member,
    Namespace,
    PseudoDestructor,
    Qualifier, 
    nothing
  };

  NameOccurrence ( TokenInfo *ti ) : TokenInfo    ( *ti ),
                                     qualifier    ( 0 ),
                                     spec         ( nothing ),
                                     ignoreUsings ( false ),
                                     sawTemplate  ( false )
  { }

  NameOccurrence ( const NameDeclaration * );

  NameDeclaration* getQualifier    ( void ) const { return ( qualifier    ); }
  OccurSpecifier   getSpec         ( void ) const { return ( spec         ); }
  bool             getIgnoreUsings ( void ) const { return ( ignoreUsings ); }

  void setQualifier    ( NameDeclaration *decl ) { qualifier = decl; }
  void setSpec         ( OccurSpecifier oc )     { spec = oc;        }
  void setIgnoreUsings ( bool i = true )         { ignoreUsings = i; }
  void setTemplate     ( bool b )                { sawTemplate = b;  }

  bool hasQualifier ( void ) const { return ( qualifier != 0 ); }
  bool isTemplate   ( void )       { return ( sawTemplate    ); }

  virtual std::ostream& Print ( std::ostream & ) const;

private:
  NameDeclaration *qualifier;
  OccurSpecifier	 spec;
  bool             ignoreUsings;
  bool             sawTemplate;
};

std::ostream& operator<< ( std::ostream &, const NameOccurrence & );
std::ostream& operator<< ( std::ostream &, const NameOccurrence::OccurSpecifier & );

#endif
