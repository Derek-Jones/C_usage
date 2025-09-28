//******************************************************************************
//
//  TokenInfo.h
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

#ifndef _TOKEN_INFO_H_
#define _TOKEN_INFO_H_

#include <iostream>
#include <string>

class TokenPosn
{
public:
  TokenPosn ( const std::string &, int, int );
  virtual ~TokenPosn ( ) { }

  std::string getFileName ( void ) const { return fileName; }

  int getColnum  ( void ) const { return col_num;  }
  int getLinenum ( void ) const { return line_num; }

  virtual std::ostream& Print( std::ostream & ) const;

  std::string toString ( void ) const;

protected:
  std::string fileName;
  int         line_num;
  int         col_num;
};

inline std::ostream& TokenPosn::Print ( std::ostream &out ) const
{
  return ( out << "(" << fileName << ": " << line_num << "," << col_num << ")" );
}

inline std::ostream& operator<< ( std::ostream &out, const TokenPosn &tp )
{
  return ( tp.Print( out ) );
}

//------------------------------------------------------------------------------

class TokenInfo : public TokenPosn
{
public:
  TokenInfo ( const std::string &, const std::string &, int , int );
  TokenInfo ( const std::string &, int , int );
  TokenInfo ( const std::string &, TokenPosn * );
  virtual ~TokenInfo ( ) { }

  std::string getName  ( void )                const { return ( name ); }
  void        setName  ( const std::string &n )      { name = n; }
  int         getArity ( void )                const { return ( arity ); }
  void        setArity ( int a )                     { arity = a; }

  bool        isaMatch ( TokenInfo * ) const;

  virtual std::ostream& Print ( std::ostream & ) const;

  std::string toString ( void ) const;

protected:
  std::string name;
  int         arity;
};

inline bool TokenInfo::isaMatch ( TokenInfo *ti ) const
{
  return ( name == ti->getName() && arity == ti->getArity() );
}

//------------------------------------------------------------------------------

#endif
