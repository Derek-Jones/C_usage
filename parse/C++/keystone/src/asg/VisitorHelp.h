//******************************************************************************
//
//  VisitorHelp.h
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
///\author Nicholas A. Kraft
///\author Edward J. Duffy

#ifndef _VISITOR_HELP_H_
#define _VISITOR_HELP_H_

#include <algorithm>

namespace key
{

  struct NullFunctor
  {
    template < typename T >
    void operator() ( T )
    { /* Empty */ }
  };

  template
  <
    class VisitorType,
    class PreVisitPolicy  = NullFunctor,
    class PostVisitPolicy = NullFunctor
  >
  struct VisitFunctor
  {
    VisitFunctor ( VisitorType* v,
                   PreVisitPolicy pre = PreVisitPolicy(),
                   PostVisitPolicy post = PostVisitPolicy() )
      : mVisitor  ( v )
      , mPrePolicy( pre )
      , mPostPolicy( post )
    { }

    template < typename Pointer >
    void operator() ( Pointer& aPointer )
    {
      if ( aPointer )
      {
        mPrePolicy( aPointer );
        aPointer->accept( mVisitor );
        mPostPolicy( aPointer );
      }
    }

  private:
    VisitorType*    mVisitor;
    PreVisitPolicy  mPrePolicy;
    PostVisitPolicy mPostPolicy;
  };

  template < class VisitorType >
  inline
  VisitFunctor<VisitorType>
  Visit ( VisitorType* aVisitor )
  {
    return VisitFunctor<VisitorType>( aVisitor );
  }

  template < class BaseType, class VisitorType, class NodeType >
  inline
  void
  VisitAsBaseType ( VisitorType* aVisitor, NodeType* aNode )
  {
    aVisitor->visit( static_cast<BaseType*>( aNode ) );
  }

  template < class VisitorType, class NodeType >
  inline
  void
  VisitAttribute ( VisitorType* aVisitor, NodeType* aNode )
  {
    VisitFunctor<VisitorType> vf( aVisitor );
    vf( aNode );
  }
}

#endif

