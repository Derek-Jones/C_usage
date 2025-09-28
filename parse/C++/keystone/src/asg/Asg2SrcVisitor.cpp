//******************************************************************************
//
//  Asg2SrcVisitor.cpp
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
///\author Edward J. Duffy
///\author Nicholas A. Kraft

#include <algorithm>
#include <functional>
#include <iostream>

#include "Ast.h"

#include "VisitorHelp.h"
#include "Asg2SrcVisitor.h"

//-----------------------------------------------------------------------------

#define STANDARD_LIBRARY_CHECK(n) \
  if ( true ) \
  { \
    if ( StandardLibrary::inStandardLibrary( n->mFilename ) ) \
    { \
      if ( mInclude.insert( aNode->mFilename ).second ) \
      { \
        std::cout << "#include <" << StandardLibrary::abs2rel( aNode->mFilename ) << ">" << std::endl; \
      } \
      return; \
    } \
  } \
  else \
    (void)0

const unsigned INDENT_WIDTH = 3;

//-----------------------------------------------------------------------------
/// Functors and convenience functions

namespace key
{
  struct StartCommas
  {
    StartCommas ( )
      : mFirst ( true )
    { }

    template < typename Pointer >
    void operator() ( Pointer )
    {
      if ( !mFirst )
      {
        std::cout << ", ";
      }
      mFirst = false;
    }
  private:
     bool mFirst;
  };

  template < class VisitorType>
  VisitFunctor<VisitorType,StartCommas>
  VisitCommas ( VisitorType* aVisitor )
  {
    return VisitFunctor<VisitorType,StartCommas>
           ( aVisitor );
  }

  struct StartCsv
  {
    StartCsv ( Asg2SrcVisitor::Indent i )
      : mFirst ( true )
      , mIndent( i )
    { }

    template < typename Pointer >
    void operator() ( Pointer )
    {
      if ( !mFirst )
      {
        std::cout << ",";
        std::cout << std::endl << mIndent;
      }
      mFirst = false;
    }
  private:
     bool                   mFirst;
     Asg2SrcVisitor::Indent mIndent;
  };

  template < class VisitorType>
  VisitFunctor<VisitorType,StartCsv>
  VisitCsv ( VisitorType* aVisitor, Asg2SrcVisitor::Indent aIndent )
  {
    return VisitFunctor<VisitorType,StartCsv>
           ( aVisitor, StartCsv( aIndent ) );
  }

  struct StartStatement
  {
    StartStatement ( Asg2SrcVisitor::Indent i ) : mIndent( i ) { }

    template < typename Pointer >
    void operator() ( Pointer ) { std::cout << mIndent; }

  private:
    Asg2SrcVisitor::Indent mIndent;
  };

  struct EndStatement
  {
    template < typename Pointer >
    void operator() ( Pointer ) { std::cout << ";" << std::endl; }
  };

  template < class VisitorType >
  VisitFunctor< VisitorType, StartStatement, EndStatement >
  VisitStatements ( VisitorType* aVisitor, Asg2SrcVisitor::Indent aIndent )
  {
    return VisitFunctor<VisitorType, StartStatement, EndStatement>
           ( aVisitor, StartStatement( aIndent ) );
  }
}

//-----------------------------------------------------------------------------

Asg2SrcVisitor::Asg2SrcVisitor ( )
{ }

//-----------------------------------------------------------------------------
/// S.B
void
Asg2SrcVisitor::visit ( const cAsgNode* aNode ) // abstract
{
  // String   mFilename
  // int      mStartLine
  // int      mEndLine
  // unsigned mNodeNumber

  /// NOTHING - abstract
}

//-----------------------------------------------------------------------------
/// S.B.1
void
Asg2SrcVisitor::visit ( const cLinkage* aNode ) // : cAsgNode
{
  // String        mLinkType
  // bool          mIsBlock
  // AsgNodeList_t mContents

  std::cout << "extern " << aNode->mLinkType;
  if ( aNode->mIsBlock ) { std::cout << "\n{\n"; }
  std::for_each( aNode->mContents.begin(), aNode->mContents.end(),
                 key::VisitStatements( this, mIndent ) );
  if ( aNode->mIsBlock ) { std::cout << "\n}\n"; }
}

//-----------------------------------------------------------------------------
/// S.B.2
void
Asg2SrcVisitor::visit ( const cUsing* aNode ) // : cAsgNode
{
  // bool            mIsNamespace
  // cNameReference* mNameReference

  std::cout << "using ";
  if ( aNode->mIsNamespace ) { std::cout << "namespace "; }
  if ( aNode->mNameReference ) { aNode->mNameReference->accept( this ); }
}

//-----------------------------------------------------------------------------
/// S.B.3
void
Asg2SrcVisitor::visit ( const cAsmDefinition* aNode ) // : cAsgNode
{
  // String mAsm
}

//-----------------------------------------------------------------------------
/// S.TA.L
void
Asg2SrcVisitor::visit ( const cTemplateArgumentList* aNode ) // : cAsgNode
{
  // TemplateArgumentList_t mArguments
}

//-----------------------------------------------------------------------------
/// S.I
void
Asg2SrcVisitor::visit ( const cIdentifier* aNode ) // abstract : cAsgNode
{
  // String           mName
  // eAccessSpecifier mAccessSpecifier
  // cIdentifier*     mDefinedIn
}

//-----------------------------------------------------------------------------
/// S.I.1
void
Asg2SrcVisitor::visit ( const cEnumerator* aNode ) // : cIdentifier
{
  // cExpression* mValue

  std::cout << aNode->mName;
  if ( aNode->mValue )
  {
    std::cout << " = ";
    aNode->mValue->accept( this );
  }
}

//-----------------------------------------------------------------------------
/// S.OBJ
void
Asg2SrcVisitor::visit ( const cObject* aNode ) // : cIdentifier
{
  // cTemplateArgumentList* mTemplateArguments
  // cExpression*           mBits
  // cExpressionBase*       mInitialValue
  // cType*                 mType
  // cNameReference*        mNamedNamespace
  // bool                   mIsAuto
  // bool                   mIsRegister
  // bool                   mIsStatic
  // bool                   mIsExtern
  // bool                   mIsMutable

  STANDARD_LIBRARY_CHECK(aNode);

  if ( aNode->mIsStatic  ) { std::cout << "static ";  }
  if ( aNode->mIsExtern  ) { std::cout << "extern ";  }
  if ( aNode->mIsMutable ) { std::cout << "mutable "; }

  if ( aNode->mType )
  {
    aNode->mType->accept( this );
  }

  if ( aNode->mNamedNamespace )
  {
    aNode->mNamedNamespace->accept( this );
    std::cout << "::";
  }

  if ( aNode->mType && !aNode->mType->isA( cArrayType_kind ) )
  {
    std::cout << " ";
    std::cout << aNode->mName;
  }

  if ( aNode->mInitialValue )
  {
    if ( !dynamic_cast<cFunctionArgumentList*>( aNode->mInitialValue ) )
    {
      std::cout << " = ";
    }
    if ( aNode->mInitialValue->isA( cInitializerList_kind ) )
    {
      std::cout << std::endl;
    }
    aNode->mInitialValue->accept( this );
  }

  if ( aNode->mBits )
  {
    std::cout << " : ";
    aNode->mBits->accept( this );
  }
}

//-----------------------------------------------------------------------------
/// S.OBJ.L
void
Asg2SrcVisitor::visit ( const cObjectList* aNode ) // : cIdentifier
{
  // AsgNodeList_t mObjects

  std::for_each( aNode->mObjects.begin(), aNode->mObjects.end(),
                 key::VisitCommas( this ) );
}

//-----------------------------------------------------------------------------
/// S.FP
void
Asg2SrcVisitor::visit ( const cFunctionParameter* aNode ) // : cFunctionParameterBase
{
  // bool                   mIsAuto
  // bool                   mIsRegister
  // cType*                 mType
  // cTemplateArgumentList* mTemplateArguments
  // cNameReference*        mNamedNamespace
  // cExpressionBase*       mDefault

  if ( aNode->mIsAuto     ) std::cout << "auto ";
  if ( aNode->mIsRegister ) std::cout << "register ";

  if ( aNode->mType )
  {
    aNode->mType->accept( this );
  }

  /// TODO: template args
  /// TODO: named namespaces

  if ( aNode->mType )//&& !aNode->mType->isA( cArrayType_kind ) )
  {
    if ( ! aNode->mType->isA( cArrayType_kind ) )
    {
      std::cout << " ";
      std::cout << aNode->mName;
    }
  }

  if ( aNode->mDefault )
  {
    std::cout << " = ";
    aNode->mDefault->accept( this );
  }
}

//-----------------------------------------------------------------------------
/// S.FP.L
void
Asg2SrcVisitor::visit ( const cFunctionParameterList* aNode ) // : cFunctionParameterBase
{
  // FunctionParameterList_t mParameters

  std::cout << "( ";
  std::for_each( aNode->mParameters.begin(), aNode->mParameters.end(),
                 key::VisitCommas( this ) );
  std::cout << " ) ";
}

//-----------------------------------------------------------------------------
/// S.T
void
Asg2SrcVisitor::visit ( const cType* aNode ) // abstract : cIdentifier
{
  // bool mIsConst
  // bool mIsVolatile

  /// NOTHING - abstract
}

//-----------------------------------------------------------------------------
/// S.T.1
void
Asg2SrcVisitor::visit ( const cBuiltInType* aNode ) // : cType
{
  if ( aNode->mIsConst )
  {
    std::cout << "const ";
  }
  if ( aNode->mIsVolatile )
  {
    std::cout << "volatile ";
  }
  std::cout << aNode->mName;
}

//-----------------------------------------------------------------------------
/// S.T.2
void
Asg2SrcVisitor::visit ( const cAliasType* aNode ) // : cType
{
  // cType* mAliasedType

}

//-----------------------------------------------------------------------------
/// S.T.3
void
Asg2SrcVisitor::visit ( const cFunctionType* aNode ) // : cType
{
  // cFunctionParameterList* mParameters
  // cType*                  mReturnType

  /// NOTHING - HANDLED FROM cFunction
}

//-----------------------------------------------------------------------------
/// S.T.4
void
Asg2SrcVisitor::visit ( const cEnumerationType* aNode ) // : cType
{
  // EnumeratorList_t mEnumerators

  std::cout << mIndent << "enum " << aNode->mName << std::endl;
  std::cout << mIndent << "{" << std::endl;
  mIndent += INDENT_WIDTH;
  std::cout << mIndent;
  for_each( aNode->mEnumerators.begin(), aNode->mEnumerators.end(),
            key::VisitCsv( this, mIndent ) );
  mIndent -= INDENT_WIDTH;
  std::cout << std::endl << mIndent << "};" << std::endl;
}

//-----------------------------------------------------------------------------
/// S.IT
void
Asg2SrcVisitor::visit ( const cIndirectType* aNode ) // abstract : cType
{
  // cType* mBaseType

  //std::cout << aNode->mName;
}

//-----------------------------------------------------------------------------
/// S.IT.1
void
Asg2SrcVisitor::visit ( const cArrayType* aNode ) // : cIndirectType
{
  // cExpressionBase* mDimension

  if ( aNode->mIsConst )
  {
    std::cout << "const ";
  }
  if ( aNode->mIsVolatile )
  {
    std::cout << "volatile ";
  }
  if ( aNode->mBaseType )
  {
    aNode->mBaseType->accept( this );
  }
  std::cout << " ";
  std::cout << aNode->mName;
  std::cout << "[";
  if ( aNode->mDimension )
  {
    aNode->mDimension->accept( this );
  }
  std::cout << "]";
}

//-----------------------------------------------------------------------------
/// S.IT.2
void
Asg2SrcVisitor::visit ( const cPointerType* aNode ) // : cIndirectType
{
  //key::VisitAsBaseType<const cIndirectType>( this, aNode );
  if ( ! aNode->mBaseType->isA( cFunctionType_kind ) )
  {
    aNode->mBaseType->accept( this );
    std::cout << "*"; 
  }
  if ( aNode->mIsConst )
  {
    std::cout << " const";
  }
  if ( aNode->mIsVolatile )
  {
    std::cout << " volatile";
  }
}

//-----------------------------------------------------------------------------
/// S.IT.3
void
Asg2SrcVisitor::visit ( const cReferenceType* aNode ) // : cIndirectType
{
  //key::VisitAsBaseType<const cIndirectType>( this, aNode );
/*
  if ( aNode->mIsConst )
  {
    std::cout << "const ";
  }
  if ( aNode->mIsVolatile )
  {
    std::cout << "volatile ";
  }
*/

  if ( ! aNode->mBaseType->isA( cFunctionType_kind ) )
  {
    aNode->mBaseType->accept( this );
    std::cout << "&"; 
  }
}

//-----------------------------------------------------------------------------
/// I.CTI
void
Asg2SrcVisitor::visit ( const cClassTypeInterface* aNode ) // abstract : cType
{
  // BaseClassList_t    mBaseClasses
  // FriendList_t       mFriends
  // MemberList_t       mMembers
  // eClassKey          mClassKey
  // DerivedClassList_t mDerivedClasses

  // NOTHING - abstract
}

//-----------------------------------------------------------------------------
/// S.CTI.1
void
Asg2SrcVisitor::visit ( const cTemplateClassType* aNode ) // : cClassTypeInterface
{
  // cTemplateParameterList* mTemplateParameters

}

//-----------------------------------------------------------------------------
/// S.CTI.2
void
Asg2SrcVisitor::visit ( const cSpecializedClassType* aNode ) // : cClassTypeInterface
{
  // cTemplateParameterList* mTemplateParameters
  // cTemplateArgumentList*  mTemplateArguments

}

//-----------------------------------------------------------------------------
/// S.CTI.3
void
Asg2SrcVisitor::visit ( const cClassType* aNode ) // : cClassTypeInterface
{
  STANDARD_LIBRARY_CHECK(aNode);
 
  // Print name 
  std::cout << mIndent << aNode->mClassKey << " " << aNode->mName << std::endl;

  // Print base classes
  if ( ! aNode->mBaseClasses.empty() )
  {
    mIndent += INDENT_WIDTH;
    std::cout << mIndent << ": ";
    for ( BaseClassList_t::const_iterator ptr = aNode->mBaseClasses.begin();
          ptr != aNode->mBaseClasses.end();
          ++ptr
        )
    {       
      if ( ptr != aNode->mBaseClasses.begin() ) { std::cout << mIndent << ", "; }       
      std::cout << ptr->second.first << " ";
      if ( ptr->second.second ) { std::cout << "virtual "; }       
      std::cout << ptr->first->mName;
      std::cout << std::endl;
    }       
    mIndent -= INDENT_WIDTH;
  }

  // Open body
  std::cout << mIndent << "{" << std::endl;
  mIndent += INDENT_WIDTH;

  /// TODO: friends

  // Print Members
  //std::for_each( aNode->mMembers.begin(), aNode->mMembers.end(),
                 //key::Visit( this ) );
  for ( std::vector<cAsgNode*>::const_iterator ptr = aNode->mMembers.begin();
        ptr != aNode->mMembers.end();
        ++ptr
      )
  {
    if (
         (*ptr)->isA( cFunctionInterface_kind )
       )
    {
      (*ptr)->accept( this );
    }
    else
    {
      key::VisitStatements( this, mIndent )( *ptr );
    }
  }

  // Close body
  mIndent -= INDENT_WIDTH;
  std::cout << mIndent << "};" << std::endl;
}

//-----------------------------------------------------------------------------
/// S.CTI.4
void
Asg2SrcVisitor::visit ( const cInstantiatedClassType* aNode ) // : cClassTypeInterface
{
  // cTemplateArgumentList* mTemplateArguments
}

//-----------------------------------------------------------------------------
/// I.FTI
void
Asg2SrcVisitor::visit ( const cForwardTypeInterface* aNode ) // abstract : cType
{
  // cNameReference* mNamedNamespace
  // cType*          mTypeDeclaration

  // NOTHING - abstract
}

//-----------------------------------------------------------------------------
/// S.FTI.1
void
Asg2SrcVisitor::visit ( const cTemplateForwardType* aNode ) // : cForwardTypeInterface
{
  // cTemplateParameterList* mTemplateParameters
}

//-----------------------------------------------------------------------------
/// S.FTI.2
void
Asg2SrcVisitor::visit ( const cSpecializedForwardType* aNode ) // : cForwardTypeInterface
{
  // cTemplateParameterList* mTemplateParameters
  // cTemplateArgumentList*  mTemplateArguments
}

//-----------------------------------------------------------------------------
/// S.FTI.3
void
Asg2SrcVisitor::visit ( const cForwardType* aNode ) // : cForwardTypeInterface
{
  if ( aNode->mNamedNamespace )
  {
    aNode->mNamedNamespace->accept( this );
    std::cout << "::";
  }
  std::cout << aNode->mName;
}

//-----------------------------------------------------------------------------
/// S.FTI.4
void
Asg2SrcVisitor::visit ( const cInstantiatedForwardType* aNode ) // : cForwardTypeInterface
{
  // cTemplateArgumentList* mTemplateArguments
}

//-----------------------------------------------------------------------------
/// S.L
void
Asg2SrcVisitor::visit ( const cLabel* aNode ) // : cIdentifier
{
  // cAsgNode* mLabeledStatement

  std::cout << mIndent << aNode->mName << ":" << std::endl;
  mIndent += INDENT_WIDTH;
  if ( aNode->mLabeledStatement )
  {
    aNode->mLabeledStatement->accept( this );
  }
  mIndent -= INDENT_WIDTH;
}

//-----------------------------------------------------------------------------
/// S.L.1
void
Asg2SrcVisitor::visit ( const cCaseLabel* aNode ) // : cLabel
{
  // cExpression* mConstantExpression

  std::cout << mIndent << "case ";
  aNode->mConstantExpression->accept( this );
  std::cout << ":" << std::endl;
  if ( aNode->mLabeledStatement )
  {
    if ( aNode->mLabeledStatement->isA( cBlock_kind ) )
    {
      aNode->mLabeledStatement->accept( this );
    }
    else
    {
      mIndent += INDENT_WIDTH;
      key::VisitStatements( this, mIndent )( aNode->mLabeledStatement );
      mIndent -= INDENT_WIDTH;
    }
    //aNode->mLabeledStatement->accept( this );
  }
}

//-----------------------------------------------------------------------------
/// S.L.2
void
Asg2SrcVisitor::visit ( const cDefaultLabel* aNode ) // : cLabel
{
  std::cout << mIndent << "default: " << std::endl;
  if ( aNode->mLabeledStatement )
  {
    if ( aNode->mLabeledStatement->isA( cBlock_kind ) )
    {
      aNode->mLabeledStatement->accept( this );
    }
    else
    {
      mIndent += INDENT_WIDTH;
      key::VisitStatements( this, mIndent )( aNode->mLabeledStatement );
      mIndent -= INDENT_WIDTH;
    }
  }
}

//-----------------------------------------------------------------------------
/// S.FI
void
Asg2SrcVisitor::visit ( const cFunctionInterface* aNode ) // abstract : cIdentifier
{
  // eFunctionKey             mFunctionKey
  // bool                     mIsPureVirtual
  // cNameReference*          mNamedNamespace
  // cFunctionType*           mType
  // cExceptionSpecification* mThrows
  // cCtorInitializerBlock*   mInit
  // cBlock*                  mBlock
  // bool                     mIsStatic
  // bool                     mIsExtern
  // bool                     mIsInline
  // bool                     mIsVirtual
  // bool                     mIsExplicit

  /// NOTHING - abstract
}

//-----------------------------------------------------------------------------
/// S.FI.1
void
Asg2SrcVisitor::visit ( const cTemplateFunction* aNode ) // : cFunctionInterface
{
  // cTemplateParameterList* mTemplateParameters

}

//-----------------------------------------------------------------------------
/// S.FI.2
void
Asg2SrcVisitor::visit ( const cSpecializedFunction* aNode ) // : cFunctionInterface
{
  // cTemplateParameterList* mTemplateParameters
  // cTemplateArgumentList*  mTemplateArguments

}

//-----------------------------------------------------------------------------
/// S.FI.3
void
Asg2SrcVisitor::visit ( const cFunction* aNode ) // : cFunctionInterface
{
  std::cout << mIndent;

  if ( aNode->mIsStatic   ) { std::cout << "static ";   }
  if ( aNode->mIsExtern   ) { std::cout << "extern ";   }
  if ( aNode->mIsInline   ) { std::cout << "inline ";   }
  if ( aNode->mIsVirtual  ) { std::cout << "virtual ";  }
  if ( aNode->mIsExplicit ) { std::cout << "explicit "; }

  if ( aNode->mType )
  {
    if ( aNode->mType->mReturnType )
    {
      aNode->mType->mReturnType->accept( this );
      std::cout << ' ';
    }
    /// else a constructor
  }

  if ( aNode->mNamedNamespace )
  {
    /// TODO: loop for mNamedNamespace
    std::cout << aNode->mNamedNamespace->mName;
    /// TODO: handle template args
    std::cout << "::";
  }

  /// Check for constructor/destructor
  std::string n = aNode->mName;
  std::string::size_type i = n.find( "::" );
  if ( i != std::string::npos )
  {
    n = n.substr( i+2, n.size()-1 );
  }
  std::cout << n << " ";

  /// TODO: template specialization

  if ( aNode->mType )
  {
    if ( aNode->mType->mParameters )
    {
      aNode->mType->mParameters->accept( this );
    }
    else
    {
      std::cout << "( void ) ";
    }
    if ( aNode->mType->mIsConst ) { std::cout << " const"; }
  }
  else
  {
    std::cout << "( void ) ";
  }

  if ( aNode->mThrows )
  {
    aNode->mThrows->accept( this );
  }

  if ( aNode->mInit )
  {
    aNode->mInit->accept( this );
  }

  if ( aNode->mBlock )
  {
    std::cout << std::endl;
    aNode->mBlock->accept( this );
    //std::cout << std::endl;
  }
  else
  {
    if ( aNode->mIsPureVirtual )
    {
      std::cout << " = 0";
    }
    std::cout << ';' << std::endl;
  }
}

//-----------------------------------------------------------------------------
/// S.FI.4
void
Asg2SrcVisitor::visit ( const cInstantiatedFunction* aNode ) // : cFunctionInterface
{
  // cTemplateArgumentList* mTemplateArguments

}

//-----------------------------------------------------------------------------
/// S.S
void
Asg2SrcVisitor::visit ( const cScope* aNode ) // abstract : cIdentifier
{
  // AsgNodeList_t mContents

  // NOTHING
}

//-----------------------------------------------------------------------------
/// S.S.1
void
Asg2SrcVisitor::visit ( const cGlobalScope* aNode ) // : cScope
{
  /// Don't directly visit built-in, pointer, reference, array types

  for ( AsgNodeList_t::const_iterator ptr = aNode->mContents.begin();
        ptr != aNode->mContents.end();
        ++ptr
      )
  {
    if ( !( (*ptr)->isA( cBuiltInType_kind )        ||
            (*ptr)->isA( cIndirectType_kind )       ||
            (*ptr)->isA( cLiteral_kind )            ||
            (*ptr)->isA( cClassTypeInterface_kind ) ||
            (*ptr)->isA( cNamespace_kind )
       )  )
    {
      (*ptr)->accept( this );
    }
  }
}

//-----------------------------------------------------------------------------
/// S.S.2
void
Asg2SrcVisitor::visit ( const cCompilationScope* aNode ) // : cScope
{
  for ( std::vector<cAsgNode*>::const_iterator ptr = aNode->mContents.begin();
        ptr != aNode->mContents.end();
        ++ptr
      )
  {
    if (
         (*ptr)->isA( cBlock_kind )              ||
         (*ptr)->isA( cFunctionInterface_kind )  ||
         (*ptr)->isA( cClassTypeInterface_kind ) ||
         (*ptr)->isA( cNamespace_kind )
       )
    {
      (*ptr)->accept( this );
    }
    else
    {
      key::VisitStatements( this, mIndent )( *ptr );
    }
  }
}

//-----------------------------------------------------------------------------
/// S.S.3
void
Asg2SrcVisitor::visit ( const cNamespace* aNode ) // : cScope
{
  // cNameReference* mAliases

  STANDARD_LIBRARY_CHECK(aNode);

  std::cout << mIndent << "namespace " << aNode->mName;
  if ( aNode->mAliases )
  {
    /// TODO: loop on mAliases?
    std::cout << " = " << aNode->mAliases->mName << ";" << std::endl;
  }
  else
  {
    std::cout << std::endl << mIndent << "{" << std::endl;
    mIndent += INDENT_WIDTH;
    for ( std::vector<cAsgNode*>::const_iterator ptr = aNode->mContents.begin();
          ptr != aNode->mContents.end();
          ++ptr
        )
    {
      if (
           (*ptr)->isA( cLabel_kind )              ||
           (*ptr)->isA( cIterationStatement_kind ) ||
           (*ptr)->isA( cSelectionStatement_kind ) ||
           (*ptr)->isA( cTryBlock_kind )           ||
           (*ptr)->isA( cClassTypeInterface_kind ) ||
           (*ptr)->isA( cNamespace_kind )
         )
      {
        (*ptr)->accept( this );
      }
      else
      {
        key::VisitStatements( this, mIndent )( *ptr );
      }
    }
    mIndent -= INDENT_WIDTH;
    std::cout << mIndent << "}" << std::endl;
  }
}

//-----------------------------------------------------------------------------
/// S.BLK
void
Asg2SrcVisitor::visit ( const cBlock* aNode ) // : cScope
{
  std::cout << mIndent << "{" << std::endl;
  mIndent += INDENT_WIDTH;
  for ( std::vector<cAsgNode*>::const_iterator ptr = aNode->mContents.begin();
        ptr != aNode->mContents.end();
        ++ptr
      )
  {
    if (
         (*ptr)->isA( cLabel_kind )              ||
         (*ptr)->isA( cIterationStatement_kind ) ||
         (*ptr)->isA( cSelectionStatement_kind ) ||
         (*ptr)->isA( cTryBlock_kind )
       )
    {
      (*ptr)->accept( this );
    }
    else
    {
      key::VisitStatements( this, mIndent )( *ptr );
    }
  }
  mIndent -= INDENT_WIDTH;
  std::cout << mIndent << "}" << std::endl;
}

//-----------------------------------------------------------------------------
/// S.BLK.1
void
Asg2SrcVisitor::visit ( const cCtorInitializerBlock* aNode ) // : cBlock
{
  std::cout << mIndent << ": constructor" << std::endl;
}

//-----------------------------------------------------------------------------
/// S.TP
void
Asg2SrcVisitor::visit ( const cTemplateParameter* aNode ) // abstract : cTemplateParameterBase
{
}

//-----------------------------------------------------------------------------
/// S.TP.1
void
Asg2SrcVisitor::visit ( const cTypeTemplateParameter* aNode ) // : cTemplateParameter
{
  // cType* mDefault
}

//-----------------------------------------------------------------------------
/// S.TP.2
void
Asg2SrcVisitor::visit ( const cTemplateTemplateParameter* aNode ) // : cTemplateParameter
{
  // cTemplateParameterList* mTemplateParameters
  // cNameReference*         mDefault
}

//-----------------------------------------------------------------------------
/// S.TP.3
void
Asg2SrcVisitor::visit ( const cNonTypeTemplateParameter* aNode ) // : cTemplateParameter
{
  // bool                   mIsAuto
  // bool                   mIsRegister
  // cType*                 mType
  // cTemplateArgumentList* mTemplateArguments
  // cNameReference*        mNamedNamespace
  // cExpressionBase*       mDefault
}

//-----------------------------------------------------------------------------
/// S.TP.L
void
Asg2SrcVisitor::visit ( const cTemplateParameterList* aNode ) // : cTemplateParameterBase
{
  // TemplateParameterList_t mParameters
}

//-----------------------------------------------------------------------------
/// S.EXP
void
Asg2SrcVisitor::visit ( const cExpression* aNode ) // abstract : cExpressionBase
{
  // cType* mType

  /// NOTHING - abstract
}

//-----------------------------------------------------------------------------
/// S.EXP.1
void
Asg2SrcVisitor::visit ( const cNameReference* aNode ) // : cExpression
{
  // String                 mName
  // cTemplateArgumentList* mTemplateArguments
  // cNameReference*        mNamedNamespace
  // bool                   mIsPseudoDestructor
  // cIdentifier*           mObjectDeclaration

  /// TODO: named ns
  if ( aNode->mNamedNamespace )
  {
    aNode->mNamedNamespace->accept( this );
    std::cout << "::";
  }

  std::cout << aNode->mName;

  /// TODO: template args

  /// TODO: pseudo
}

//-----------------------------------------------------------------------------
/// S.EXP.2
void
Asg2SrcVisitor::visit ( const cLiteral* aNode ) // : cExpression
{
  // String mValue

  std::cout << aNode->mValue;
}

//-----------------------------------------------------------------------------
/// S.EXP.3
void
Asg2SrcVisitor::visit ( const cNewExpression* aNode ) // : cExpression
{
  // cExpressionBase*       mInitializer
  // cFunctionArgumentList* mPlacement

  std::cout << "new ";
  if ( aNode->mPlacement )
  {
    aNode->mPlacement->accept( this );
    std::cout << " ";
  }
  if ( aNode->mType )
  {
    aNode->mType->accept( this );
  }
  if ( aNode->mInitializer )
  {
    aNode->mInitializer->accept( this );
  }
}

//-----------------------------------------------------------------------------
/// S.EXP.4
void
Asg2SrcVisitor::visit ( const cDeleteExpression* aNode ) // : cExpression
{
  // cExpression* mToDelete
  // bool         mIsArray
}

//-----------------------------------------------------------------------------
/// S.EXP.5
void
Asg2SrcVisitor::visit ( const cConditionDeclarator* aNode ) // : cExpression
{
  // cObject* mObject
}

//-----------------------------------------------------------------------------
/// S.EXP.6
void
Asg2SrcVisitor::visit ( const cEmptyExpression* aNode ) // : cExpression
{
}

//-----------------------------------------------------------------------------
/// S.EXP.L
void
Asg2SrcVisitor::visit ( const cExpressionList* aNode ) // : cExpressionBase
{
  // cType* mType
}

//-----------------------------------------------------------------------------
/// S.EXP.L.1
void
Asg2SrcVisitor::visit ( const cFunctionArgumentList* aNode ) // : cExpressionList
{
  // ArgumentList_t mArguments

  std::cout << "( ";
  std::for_each( aNode->mArguments.begin(), aNode->mArguments.end(),
                 key::VisitCommas( this ) );
  std::cout << " )";
}

//-----------------------------------------------------------------------------
/// S.EXP.L.2
void
Asg2SrcVisitor::visit ( const cInitializerList* aNode ) // : cExpressionList
{
  // ArgumentList_t mInitializers

  std::cout << mIndent << "{" << std::endl;
  mIndent += INDENT_WIDTH;
  std::cout << mIndent;
  std::for_each( aNode->mInitializers.begin(), aNode->mInitializers.end(),
                 key::VisitCsv( this, mIndent ) );
  mIndent -= INDENT_WIDTH;
  std::cout << std::endl << mIndent << "}";
}

//-----------------------------------------------------------------------------
/// S.O
void
Asg2SrcVisitor::visit ( const cOperator* aNode ) // abstract : cExpression
{
  // eOperator mOperator

  // NOTHING - abstract
}

//-----------------------------------------------------------------------------
/// S.O.1
void
Asg2SrcVisitor::visit ( const cUnaryOperator* aNode ) // : cOperator
{
  // cAsgNode* mOperand

  switch ( aNode->mOperator )
  {
    case OT_UPAREN:
    {
      std::cout << "(";
      aNode->mOperand->accept( this );
      std::cout << ")";
    }
    break;

    case OT_POST_INC:
    case OT_POST_DEC:
    {
      aNode->mOperand->accept( this );
      std::cout << aNode->mOperator;
    }
    break;

    default:
    {
      std::cout << aNode->mOperator;
      aNode->mOperand->accept( this );
    }
  }
}

//-----------------------------------------------------------------------------
/// S.O.2
void
Asg2SrcVisitor::visit ( const cBinaryOperator* aNode ) // : cOperator
{
  // cAsgNode*        mLhs
  // cExpressionBase* mRhs

  if ( aNode->mOperator == OT_C_CAST_CALL ) { std::cout << "("; }
  aNode->mLhs->accept( this );
  if ( aNode->mOperator == OT_C_CAST_CALL ) { std::cout << ")"; }

  const char* space = ( ( aNode->mOperator == OT_FIELD_ACCESS   ) ||
                        ( aNode->mOperator == OT_FIELD_DEREF    ) ||
                        ( aNode->mOperator == OT_POINTSAT       ) ||
                        ( aNode->mOperator == OT_POINTSAT_DEREF ) ||
                        ( aNode->mOperator == OT_FCT_CALL       ) ||
                        ( aNode->mOperator == OT_C_CAST_CALL    ) ||
                        ( aNode->mOperator == OT_CPP_CAST_CALL  ) ? "" : " " );

  if ( ( aNode->mOperator != OT_FCT_CALL      ) &&
       ( aNode->mOperator != OT_C_CAST_CALL   ) &&
       ( aNode->mOperator != OT_CPP_CAST_CALL ) &&
       ( aNode->mOperator != OT_ARRAY_REF     ) )
  {
    std::cout << space << aNode->mOperator;
  }

  if ( aNode->mRhs )
  {
    if ( aNode->mOperator == OT_ARRAY_REF )
    {
      std::cout << "["; 
      aNode->mRhs->accept( this ); 
      std::cout << "]"; 
    }
    else    
    {
      std::cout << space;
      aNode->mRhs->accept(this);
    }
  }
  else
  {
    std::cout << "( )";
  }
}

//-----------------------------------------------------------------------------
/// S.O.3
void
Asg2SrcVisitor::visit ( const cTernaryOperator* aNode ) // : cOperator
{
  // cExpression* mCondition
  // cExpression* mTrueExpression
  // cExpression* mFalseExpression

  aNode->mCondition->accept( this );
  std::cout << " ? ";
  aNode->mTrueExpression->accept( this );
  std::cout << " : ";
  aNode->mFalseExpression->accept( this );
}

//-----------------------------------------------------------------------------
/// S.CS
void
Asg2SrcVisitor::visit ( const cControlStatement* aNode ) // abstract : cAsgNode
{
  /// NOTHING - abstract
}

//-----------------------------------------------------------------------------
/// S.SS
void
Asg2SrcVisitor::visit ( const cSelectionStatement* aNode ) // abstract : cControlStatement
{
  // cExpression* mCondition

  /// NOTHING - abstract
}

//-----------------------------------------------------------------------------
/// S.SS.1
void
Asg2SrcVisitor::visit ( const cIfStatement* aNode ) // : cSelectionStatement
{
  // cBlock* mTrueBlock
  // cBlock* mFalseBlock

  std::cout << mIndent << "if ( ";
  aNode->mCondition->accept(this);
  std::cout << " )" << std::endl;
  if ( aNode->mTrueBlock )
  {
    aNode->mTrueBlock->accept(this);
  }

  if ( aNode->mFalseBlock )
  {
    std::cout << mIndent <<  "else" << std::endl;
    aNode->mFalseBlock->accept( this );
  }
}

//-----------------------------------------------------------------------------
/// S.SS.2
void
Asg2SrcVisitor::visit ( const cSwitchStatement* aNode ) // : cSelectionStatement
{
  // cBlock* mBlock

  std::cout << mIndent << "switch ( ";
  aNode->mCondition->accept(this);
  std::cout << " )" << std::endl;
  aNode->mBlock->accept(this);
}

//-----------------------------------------------------------------------------
/// S.IS
void
Asg2SrcVisitor::visit ( const cIterationStatement* aNode ) // abstract : cControlStatement
{
  // cExpression* mCondition
  // cBlock*      mBlock

  /// NOTHING - abstract
}

//-----------------------------------------------------------------------------
/// S.IS.1
void
Asg2SrcVisitor::visit ( const cWhileLoop* aNode ) // : cIterationStatement
{
}

//-----------------------------------------------------------------------------
/// S.IS.2
void
Asg2SrcVisitor::visit ( const cDoWhileLoop* aNode ) // : cIterationStatement
{
}

//-----------------------------------------------------------------------------
/// S.IS.3
void
Asg2SrcVisitor::visit ( const cForLoop* aNode ) // : cIterationStatement
{
  // AsgNodeList_t mForInitStatement
  // cExpression*  mIncrement
}

//-----------------------------------------------------------------------------
/// S.JS
void
Asg2SrcVisitor::visit ( const cJumpStatement* aNode ) // abstract : cControlStatement
{
  // cExpression* mDestination
}

//-----------------------------------------------------------------------------
/// S.JS.1
void
Asg2SrcVisitor::visit ( const cBreak* aNode ) // : cJumpStatement
{
  std::cout << "break";
}

//-----------------------------------------------------------------------------
/// S.JS.2
void
Asg2SrcVisitor::visit ( const cContinue* aNode ) // : cJumpStatement
{
  std::cout << "continue";
}

//-----------------------------------------------------------------------------
/// S.JS.3
void
Asg2SrcVisitor::visit ( const cReturn* aNode ) // : cJumpStatement
{
  // cExpression* mValue

  std::cout << "return ";
  if ( aNode->mValue )
  {
    aNode->mValue->accept( this );
  }
}

//-----------------------------------------------------------------------------
/// S.JS.4
void
Asg2SrcVisitor::visit ( const cGoto* aNode ) // : cJumpStatement
{
  std::cout << "goto ";
  if ( aNode->mDestination )
  {
    aNode->mDestination->accept( this );
  }
}

//-----------------------------------------------------------------------------
/// S.EXC.1
void
Asg2SrcVisitor::visit ( const cTryBlock* aNode ) // : cBlock
{
  // HandlerList_t mHandlers

  std::cout << mIndent << "try" << std::endl;
  std::cout << mIndent << "{" << std::endl;
  mIndent += INDENT_WIDTH;
  for ( std::vector<cAsgNode*>::const_iterator ptr = aNode->mContents.begin();
        ptr != aNode->mContents.end();
        ++ptr
      )
  {
    if (
         (*ptr)->isA( cLabel_kind )              ||
         (*ptr)->isA( cIterationStatement_kind ) ||
         (*ptr)->isA( cSelectionStatement_kind ) ||
         (*ptr)->isA( cTryBlock_kind )
       )
    {
      (*ptr)->accept( this );
    }
    else
    {
      key::VisitStatements( this, mIndent )( *ptr );
    }
  }
  mIndent -= INDENT_WIDTH;
  std::cout << mIndent << "}" << std::endl;
  std::for_each( aNode->mHandlers.begin(), aNode->mHandlers.end(),
                 key::Visit( this ) );
}

//-----------------------------------------------------------------------------
/// S.EXC.2
void
Asg2SrcVisitor::visit ( const cFunctionTryBlock* aNode ) // : cTryBlock
{
  // cCtorInitializerBlock* mInit

  std::cout << mIndent << "try" << std::endl;

  mIndent += INDENT_WIDTH;
  if ( aNode->mInit ) { aNode->mInit->accept( this ); }
  mIndent -= INDENT_WIDTH;

  std::cout << mIndent << "{" << std::endl;

  mIndent += INDENT_WIDTH;
  std::for_each( aNode->mContents.begin(), aNode->mContents.end(),
                 key::VisitStatements( this, mIndent ) );
  mIndent -= INDENT_WIDTH;

  std::cout << mIndent << "}" << std::endl;

  std::for_each( aNode->mHandlers.begin(), aNode->mHandlers.end(),
                 key::Visit( this ) );
}

//-----------------------------------------------------------------------------
/// S.EXC.3
void
Asg2SrcVisitor::visit ( const cHandler* aNode ) // : cAsgNode
{
  // cExceptionDeclaration* mParameters
  // cBlock*                mStatements

  std::cout << mIndent << "catch ";
  if ( aNode->mParameters )
  {
    aNode->mParameters->accept( this );
  }
  if ( aNode->mStatements )
  {
    aNode->mStatements->accept( this );
  }
}

//-----------------------------------------------------------------------------
/// S.EXC.4
void
Asg2SrcVisitor::visit ( const cExceptionDeclaration* aNode ) // : cIdentifier
{
  // cType*                 mType
  // cNameReference*        mNamedNamespace
  // cTemplateArgumentList* mTemplateArguments

  std::cout << "( ";
  if ( aNode->mType )
  {
    std::cout << aNode->mType->mName << ' ';
  }
  /// TODO: named ns
  std::cout << aNode->mName;
  /// TODO: templ args
  std::cout  << " )" << std::endl;
}

//-----------------------------------------------------------------------------
/// S.EXC.5
void
Asg2SrcVisitor::visit ( const cThrowExpression* aNode ) // : cExpression
{
  // cExpression* mArgument

  std::cout << "throw ";
  if ( aNode->mType )
  {
    aNode->mType->accept( this );
  }
  if ( aNode->mArgument )
  {
    aNode->mArgument->accept( this );
  }
}

//-----------------------------------------------------------------------------
/// S.EXC.6
void
Asg2SrcVisitor::visit ( const cExceptionSpecification* aNode ) // : cAsgNode
{
  // ThrowList_t mException

  std::cout << "throw ( ";
  std::for_each( aNode->mException.begin(), aNode->mException.end(),
                 key::VisitCommas( this ) );
  std::cout << " )";
}

//-----------------------------------------------------------------------------
