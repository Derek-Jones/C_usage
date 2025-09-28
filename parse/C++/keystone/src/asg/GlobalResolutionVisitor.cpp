//******************************************************************************
//
//  GlobalResolutionVisitor.cpp
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

///\file
/// A visitor which resolves built-in types and literals to the global scope.
/// During AST construction several instances of built-in types and literals
/// are created.  This visitor moves the first found instance of each built-in
/// type, pointer to built-in, reference to built-in, array of built-in, and
/// literal to the global scope.  Pointers to subsequent instances of these
/// are then made to point to the new global instance.
/// This visitor also builds full names for cIndirectTypes.


#include <algorithm>
#include <functional>
#include <iostream>

#include "Ast.h"
#include "VisitorHelp.h"
#include "GlobalResolutionVisitor.h"

//-----------------------------------------------------------------------------

GlobalResolutionVisitor::GlobalResolver::GlobalResolver
  ( GlobalResolutionVisitor* aParent, cGlobalScope* aGlobal )
  : mParent( aParent )
  , mGlobal( aGlobal )
{
}

//-----------------------------------------------------------------------------

void
GlobalResolutionVisitor::GlobalResolver::operator() ( cType** aType )
{
  if ( *aType )
  {
    if ( (*aType)->isA( cBuiltInType_kind ) )
    {
      *aType = makeGlobal( *aType, &cType::equalToType );
    }

    // Clean this up once array equalToType is working
    if ( (*aType)->isA( cPointerType_kind ) || (*aType)->isA( cReferenceType_kind ) )
    {
      if ( (*aType)->isBuiltIn() )
      {
        *aType = makeGlobal( *aType, &cType::equalToType );
      }
    }

    (*aType)->accept( mParent );
  }
}

//-----------------------------------------------------------------------------

void
GlobalResolutionVisitor::GlobalResolver::operator() ( cExpressionBase** aExpression )
{
  if ( *aExpression )
  {
    if ( (*aExpression)->isA( cLiteral_kind ) )
    {
      (*aExpression) = makeGlobal( static_cast<cLiteral*>( *aExpression ), &cLiteral::equalToLiteral );
    }

    (*aExpression)->accept( mParent );
  }
}

//-----------------------------------------------------------------------------

void
GlobalResolutionVisitor::GlobalResolver::operator() ( cExpression** aExpression )
{
  if ( *aExpression )
  {
    if ( (*aExpression)->isA( cLiteral_kind ) )
    {
      *aExpression = makeGlobal( static_cast<cLiteral*>( *aExpression ), &cLiteral::equalToLiteral );
    }

    (*aExpression)->accept( mParent );
  }
}

//-----------------------------------------------------------------------------

template < class NodeType >
NodeType*
GlobalResolutionVisitor::GlobalResolver::makeGlobal
  ( NodeType* aNode, bool (NodeType::*aEqualTo)( NodeType* ) )
{
  NodeType* rVal = 0;

  bool fStop = false;
  for ( AsgNodeList_t::iterator ptr = mGlobal->mContents.begin();
        ptr != mGlobal->mContents.end() && !fStop;
        ++ptr
      )
  {
    if ( NodeType* n = dynamic_cast<NodeType*>( *ptr ) )
    {
      fStop = (n->*aEqualTo)( aNode );

      if ( fStop )
      {
        rVal = n;
      }
    }
  }

  if ( ! rVal )
  {
    aNode->mFilename  = "";
    aNode->mStartLine = 0;
    aNode->mEndLine   = 0;

    mGlobal->mContents.insert( mGlobal->mContents.begin(), aNode );

    rVal = static_cast<NodeType*>( mGlobal->mContents.front() );
  }

  return rVal;
}

//-----------------------------------------------------------------------------

GlobalResolutionVisitor::GlobalResolutionVisitor
  ( cGlobalScope* aGlobal )
  : mGlobal  ( aGlobal ) 
  , mResolver( this, mGlobal )
{
}

//-----------------------------------------------------------------------------
/// S.B
void
GlobalResolutionVisitor::visit ( cAsgNode* aNode ) // abstract
{
  // String   mFilename
  // int      mStartLine
  // int      mEndLine
  // unsigned mNodeNumber

  // NO OP
}

//-----------------------------------------------------------------------------
/// S.B.1
void
GlobalResolutionVisitor::visit ( cLinkage* aNode ) // : cAsgNode
{
  // String        mLinkType
  // bool          mIsBlock
  // AsgNodeList_t mContents

  std::for_each( aNode->mContents.begin(), aNode->mContents.end(),
                 key::Visit( this ) );
}

//-----------------------------------------------------------------------------
/// S.B.2
void
GlobalResolutionVisitor::visit ( cUsing* aNode ) // : cAsgNode
{
  // bool            mIsNamespace
  // cNameReference* mNameReference

  // NO OP
}

//-----------------------------------------------------------------------------
/// S.B.3
void
GlobalResolutionVisitor::visit ( cAsmDefinition* aNode ) // : cAsgNode
{
  // String mAsm

  // NO OP
}

//-----------------------------------------------------------------------------
/// S.TA.L
void
GlobalResolutionVisitor::visit ( cTemplateArgumentList* aNode ) // : cAsgNode
{
  // TemplateArgumentList_t mArguments

  for ( TemplateArgumentList_t::iterator ptr = aNode->mArguments.begin();
        ptr != aNode->mArguments.end();
        ++ptr
      )
  {
    if ( (*ptr)->isA( cType_kind ) )
    {
      if ( cType* t = dynamic_cast<cType*>( *ptr ) )
      {
        mResolver( &t );
        *ptr = t;
      }
    }
    else if ( (*ptr)->isA( cExpression_kind ) )
    {
      if ( cExpression* e = dynamic_cast<cExpression*>( *ptr ) )
      {
        mResolver( &e );
        *ptr = e;
      }
    }
    else if ( (*ptr)->isA( cExpressionBase_kind ) )
    {
      if ( cExpressionBase* eb = dynamic_cast<cExpressionBase*>( *ptr ) )
      {
        mResolver( &eb );
        *ptr = eb;
      }
    }
    else
    {
      (*ptr)->accept( this );
    }
  }
}

//-----------------------------------------------------------------------------
/// S.I
void
GlobalResolutionVisitor::visit ( cIdentifier* aNode ) // abstract : cAsgNode
{
  // String           mName
  // eAccessSpecifier mAccessSpecifier
  // cIdentifier*     mDefinedIn

  // NO OP
}

//-----------------------------------------------------------------------------
/// S.I.1
void
GlobalResolutionVisitor::visit ( cEnumerator* aNode ) // : cIdentifier
{
  // cExpression* mValue

  mResolver( &aNode->mValue );
}

//-----------------------------------------------------------------------------
/// S.OBJ
void
GlobalResolutionVisitor::visit ( cObject* aNode ) // : cIdentifier
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

  key::VisitAttribute( this, aNode->mTemplateArguments );

  mResolver( &aNode->mBits );
  mResolver( &aNode->mInitialValue );
  mResolver( &aNode->mType );
}

//-----------------------------------------------------------------------------
/// S.OBJ.L
void
GlobalResolutionVisitor::visit ( cObjectList* aNode ) // : cIdentifier
{
  // AsgNodeList_t mObjects

  std::for_each( aNode->mObjects.begin(), aNode->mObjects.end(),
                 key::Visit( this ) );
}

//-----------------------------------------------------------------------------
/// S.FP
void
GlobalResolutionVisitor::visit ( cFunctionParameter* aNode ) // : cFunctionParameterBase
{
  // bool                   mIsAuto
  // bool                   mIsRegister
  // cType*                 mType
  // cTemplateArgumentList* mTemplateArguments
  // cNameReference*        mNamedNamespace
  // cExpressionBase*       mDefault

  key::VisitAttribute( this, aNode->mTemplateArguments );

  mResolver( &aNode->mType );
  mResolver( &aNode->mDefault );
}

//-----------------------------------------------------------------------------
/// S.FP.L
void
GlobalResolutionVisitor::visit ( cFunctionParameterList* aNode ) // : cFunctionParameterBase
{
  // FunctionParameterList_t mParameters

  std::for_each( aNode->mParameters.begin(), aNode->mParameters.end(),
                 key::Visit( this ) );
}

//-----------------------------------------------------------------------------
/// S.T
void
GlobalResolutionVisitor::visit ( cType* aNode ) // abstract : cIdentifier
{
  // bool mIsConst
  // bool mIsVolatile

  // NO OP
}

//-----------------------------------------------------------------------------
/// S.T.1
void
GlobalResolutionVisitor::visit ( cBuiltInType* aNode ) // : cType
{
  // NO OP
}

//-----------------------------------------------------------------------------
/// S.T.2
void
GlobalResolutionVisitor::visit ( cAliasType* aNode ) // : cType
{
  // cType* mAliasedType

  mResolver( &aNode->mAliasedType );
}

//-----------------------------------------------------------------------------
/// S.T.3
void
GlobalResolutionVisitor::visit ( cFunctionType* aNode ) // : cType
{
  // cParameterList* mParameters
  // cType*          mReturnType

  key::VisitAttribute( this, aNode->mParameters );

  mResolver( &aNode->mReturnType );
}

//-----------------------------------------------------------------------------
/// S.T.4
void
GlobalResolutionVisitor::visit ( cEnumerationType* aNode ) // : cType
{
  // EnumeratorList_t mEnumerators

  std::for_each( aNode->mEnumerators.begin(), aNode->mEnumerators.end(),
                 key::Visit( this ) );
}

//-----------------------------------------------------------------------------
/// S.IT
void
GlobalResolutionVisitor::visit ( cIndirectType* aNode ) // abstract : cType
{
  // cType* mBaseType

  mResolver( &aNode->mBaseType );
}

//-----------------------------------------------------------------------------
/// S.IT.1
void
GlobalResolutionVisitor::visit ( cArrayType* aNode ) // : cIndirectType
{
  // cExpressionBase* mDimension

  visit( static_cast<cIndirectType*>( aNode ) );

  mResolver( &aNode->mDimension );
}

//-----------------------------------------------------------------------------
/// S.IT.2
void
GlobalResolutionVisitor::visit ( cPointerType* aNode ) // : cIndirectType
{
  key::VisitAsBaseType<cIndirectType>( this, aNode );

  if ( aNode->mName == "" )
  {
    if ( aNode->mBaseType->mIsConst )
    {
      aNode->mName += "const ";
    }
    aNode->mName += aNode->mBaseType->mName;
    aNode->mName += "*";
    if ( aNode->mIsConst )
    {
      aNode->mName += " const";
    }
  }
}

//-----------------------------------------------------------------------------
/// S.IT.3
void
GlobalResolutionVisitor::visit ( cReferenceType* aNode ) // : cIndirectType
{
  key::VisitAsBaseType<cIndirectType>( this, aNode );

  if ( aNode->mName == "" )
  {
    if ( aNode->mBaseType->mIsConst )
    {
      aNode->mName += "const ";
    }
    aNode->mName += aNode->mBaseType->mName;
    aNode->mName += "&";
  }
}

//-----------------------------------------------------------------------------
/// I.CTI
void
GlobalResolutionVisitor::visit ( cClassTypeInterface* aNode ) // abstract : cType
{
  // BaseClassList_t    mBaseClasses
  // FriendList_t       mFriends
  // MemberList_t       mMembers
  // eClassKey          mClassKey
  // DerivedClassList_t mDerivedClasses

  std::for_each( aNode->mMembers.begin(), aNode->mMembers.end(),
                 key::Visit( this ) );
}

//-----------------------------------------------------------------------------
/// S.CTI.1
void
GlobalResolutionVisitor::visit ( cTemplateClassType* aNode ) // : cClassTypeInterface
{
  // cTemplateParameterList* mTemplateParameters

  visit( static_cast<cClassTypeInterface*>( aNode ) );

  key::VisitAttribute( this, aNode->mTemplateParameters );
}

//-----------------------------------------------------------------------------
/// S.CTI.2
void
GlobalResolutionVisitor::visit ( cSpecializedClassType* aNode ) // : cClassTypeInterface
{
  // cTemplateParameterList* mTemplateParameters
  // cTemplateArgumentList*  mTemplateArguments

  visit( static_cast<cClassTypeInterface*>( aNode ) );

  key::VisitAttribute( this, aNode->mTemplateParameters );
  key::VisitAttribute( this, aNode->mTemplateArguments );
}

//-----------------------------------------------------------------------------
/// S.CTI.3
void
GlobalResolutionVisitor::visit ( cClassType* aNode ) // : cClassTypeInterface
{
  visit( static_cast<cClassTypeInterface*>( aNode ) );
}

//-----------------------------------------------------------------------------
/// S.CTI.4
void
GlobalResolutionVisitor::visit ( cInstantiatedClassType* aNode ) // : cClassTypeInterface
{
  // cTemplateArgumentList* mTemplateArguments

  visit( static_cast<cClassTypeInterface*>( aNode ) );

  key::VisitAttribute( this, aNode->mTemplateArguments );
}

//-----------------------------------------------------------------------------
/// I.FTI
void
GlobalResolutionVisitor::visit ( cForwardTypeInterface* aNode ) // abstract : cType
{
  // cNameReference* mNamedNamespace
  // cType*          mTypeDeclaration

  mResolver( &aNode->mTypeDeclaration );
}

//-----------------------------------------------------------------------------
/// S.FTI.1
void
GlobalResolutionVisitor::visit ( cTemplateForwardType* aNode ) // : cForwardTypeInterface
{
  // cTemplateParameterList* mTemplateParameters

  visit( static_cast<cForwardTypeInterface*>( aNode ) );

  key::VisitAttribute( this, aNode->mTemplateParameters );
}

//-----------------------------------------------------------------------------
/// S.FTI.2
void
GlobalResolutionVisitor::visit ( cSpecializedForwardType* aNode ) // : cForwardTypeInterface
{
  // cTemplateParameterList* mTemplateParameters
  // cTemplateArgumentList*  mTemplateArguments

  visit( static_cast<cForwardTypeInterface*>( aNode ) );

  key::VisitAttribute( this, aNode->mTemplateParameters );
  key::VisitAttribute( this, aNode->mTemplateArguments );
}

//-----------------------------------------------------------------------------
/// S.FTI.3
void
GlobalResolutionVisitor::visit ( cForwardType* aNode ) // : cForwardTypeInterface
{
  visit( static_cast<cForwardTypeInterface*>( aNode ) );
}

//-----------------------------------------------------------------------------
/// S.FTI.4
void
GlobalResolutionVisitor::visit ( cInstantiatedForwardType* aNode ) // : cForwardTypeInterface
{
  // cTemplateArgumentList* mTemplateArguments

  visit( static_cast<cForwardTypeInterface*>( aNode ) );

  key::VisitAttribute( this, aNode->mTemplateArguments );
}

//-----------------------------------------------------------------------------
/// S.L
void
GlobalResolutionVisitor::visit ( cLabel* aNode ) // : cIdentifier
{
  // cAsgNode* mLabeledStatement

  key::VisitAttribute( this, aNode->mLabeledStatement );
}

//-----------------------------------------------------------------------------
/// S.L.1
void
GlobalResolutionVisitor::visit ( cCaseLabel* aNode ) // : cLabel
{
  // cExpression* mConstantExpression

  mResolver( &aNode->mConstantExpression );
}

//-----------------------------------------------------------------------------
/// S.L.2
void
GlobalResolutionVisitor::visit ( cDefaultLabel* aNode ) // : cLabel
{
  // NO OP
}

//-----------------------------------------------------------------------------
/// S.FI
void
GlobalResolutionVisitor::visit ( cFunctionInterface* aNode ) // abstract : cIdentifier
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

  key::VisitAttribute( this, aNode->mType );
  key::VisitAttribute( this, aNode->mThrows );
  key::VisitAttribute( this, aNode->mInit );
  key::VisitAttribute( this, aNode->mBlock );
}

//-----------------------------------------------------------------------------
/// S.FI.1
void
GlobalResolutionVisitor::visit ( cTemplateFunction* aNode ) // : cFunctionInterface
{
  // cTemplateParameterList* mTemplateParameters

  visit( static_cast<cFunctionInterface*>( aNode ) );

  key::VisitAttribute( this, aNode->mTemplateParameters );
}

//-----------------------------------------------------------------------------
/// S.FI.2
void
GlobalResolutionVisitor::visit ( cSpecializedFunction* aNode ) // : cFunctionInterface
{
  // cTemplateParameterList* mTemplateParameters
  // cTemplateArgumentList*  mTemplateArguments

  visit( static_cast<cFunctionInterface*>( aNode ) );

  key::VisitAttribute( this, aNode->mTemplateParameters );
  key::VisitAttribute( this, aNode->mTemplateArguments );
}

//-----------------------------------------------------------------------------
/// S.FI.3
void
GlobalResolutionVisitor::visit ( cFunction* aNode ) // : cFunctionInterface
{
  visit( static_cast<cFunctionInterface*>( aNode ) );
}

//-----------------------------------------------------------------------------
/// S.FI.4
void
GlobalResolutionVisitor::visit ( cInstantiatedFunction* aNode ) // : cFunctionInterface
{
  // cTemplateArgumentList* mTemplateArguments

  visit( static_cast<cFunctionInterface*>( aNode ) );

  key::VisitAttribute( this, aNode->mTemplateArguments );
}

//-----------------------------------------------------------------------------
/// S.S
void
GlobalResolutionVisitor::visit ( cScope* aNode ) // abstract : cIdentifier
{
  // AsgNodeList_t mContents

  std::for_each( aNode->mContents.begin(), aNode->mContents.end(),
                 key::Visit( this ) );
}

//-----------------------------------------------------------------------------
/// S.S.1
void
GlobalResolutionVisitor::visit ( cGlobalScope* aNode ) // : cScope
{
  visit( static_cast<cScope*>( aNode ) );
}

//-----------------------------------------------------------------------------
/// S.S.2
void
GlobalResolutionVisitor::visit ( cCompilationScope* aNode ) // : cScope
{
  visit( static_cast<cScope*>( aNode ) );
}

//-----------------------------------------------------------------------------
/// S.S.3
void
GlobalResolutionVisitor::visit ( cNamespace* aNode ) // : cScope
{
  // cNameReference* mAliases

  visit( static_cast<cScope*>( aNode ) );
}

//-----------------------------------------------------------------------------
/// S.BLK
void
GlobalResolutionVisitor::visit ( cBlock* aNode ) // : cScope
{
  visit( static_cast<cScope*>( aNode ) );
}

//-----------------------------------------------------------------------------
/// S.BLK.1
void
GlobalResolutionVisitor::visit ( cCtorInitializerBlock* aNode ) // : cBlock
{
  visit( static_cast<cScope*>( aNode ) );
}

//-----------------------------------------------------------------------------
/// S.TP
void
GlobalResolutionVisitor::visit ( cTemplateParameter* aNode ) // abstract : cTemplateParameterBase
{
  // NO OP
}

//-----------------------------------------------------------------------------
/// S.TP.1
void
GlobalResolutionVisitor::visit ( cTypeTemplateParameter* aNode ) // : cTemplateParameter
{
  // cType* mDefault

  mResolver( &aNode->mDefault );
}

//-----------------------------------------------------------------------------
/// S.TP.2
void
GlobalResolutionVisitor::visit ( cTemplateTemplateParameter* aNode ) // : cTemplateParameter
{
  // cTemplateParameterList* mTemplateParameters
  // cNameReference*         mDefault

  key::VisitAttribute( this, aNode->mTemplateParameters );
}

//-----------------------------------------------------------------------------
/// S.TP.3
void
GlobalResolutionVisitor::visit ( cNonTypeTemplateParameter* aNode ) // : cTemplateParameter
{
  // bool                   mIsAuto
  // bool                   mIsRegister
  // cType*                 mType
  // cTemplateArgumentList* mTemplateArguments
  // cNameReference*        mNamedNamespace
  // cExpressionBase*       mDefault

  mResolver( &aNode->mType );

  key::VisitAttribute( this, aNode->mTemplateArguments );

  mResolver( &aNode->mDefault );
}

//-----------------------------------------------------------------------------
/// S.TP.L
void
GlobalResolutionVisitor::visit ( cTemplateParameterList* aNode ) // : cTemplateParameterBase
{
  // TemplateParameterList_t mParameters

  std::for_each( aNode->mParameters.begin(), aNode->mParameters.end(),
                 key::Visit( this ) );
}

//-----------------------------------------------------------------------------
/// S.EXP
void
GlobalResolutionVisitor::visit ( cExpression* aNode ) // abstract : cExpressionBase
{
  // cType* mType

  mResolver( &aNode->mType );
}

//-----------------------------------------------------------------------------
/// S.EXP.1
void
GlobalResolutionVisitor::visit ( cNameReference* aNode ) // : cExpression
{
  // String                 mName
  // cTemplateArgumentList* mTemplateArguments
  // cNameReference*        mNamedNamespace
  // bool                   mIsPseudoDestructor
  // cIdentifier*           mObjectDeclaration

  key::VisitAttribute( this, aNode->mTemplateArguments );
}

//-----------------------------------------------------------------------------
/// S.EXP.2
void
GlobalResolutionVisitor::visit ( cLiteral* aNode ) // : cExpression
{
  // String mValue

  visit( static_cast<cExpression*>( aNode ) );
}

//-----------------------------------------------------------------------------
/// S.EXP.3
void
GlobalResolutionVisitor::visit ( cNewExpression* aNode ) // : cExpression
{
  // cExpressionBase*       mInitializer
  // cFunctionArgumentList* mPlacement

  mResolver( &aNode->mInitializer );
  key::VisitAttribute( this, aNode->mPlacement );
}

//-----------------------------------------------------------------------------
/// S.EXP.4
void
GlobalResolutionVisitor::visit ( cDeleteExpression* aNode ) // : cExpression
{
  // cExpression* mToDelete
  // bool         mIsArray

  mResolver( &aNode->mToDelete );
}

//-----------------------------------------------------------------------------
/// S.EXP.5
void
GlobalResolutionVisitor::visit ( cConditionDeclarator* aNode ) // : cExpression
{
  // cObject* mObject

  key::VisitAttribute( this, aNode->mObject );
}

//-----------------------------------------------------------------------------
/// S.EXP.6
void
GlobalResolutionVisitor::visit ( cEmptyExpression* aNode ) // : cExpression
{
  // NO OP
}

//-----------------------------------------------------------------------------
/// S.EXP.L
void
GlobalResolutionVisitor::visit ( cExpressionList* aNode ) // : cExpressionBase
{
  // cType* mType

  mResolver( &aNode->mType );
}

//-----------------------------------------------------------------------------
/// S.EXP.L.1
void
GlobalResolutionVisitor::visit ( cFunctionArgumentList* aNode ) // : cExpressionList
{
  // ArgumentList_t mArguments

  for ( ArgumentList_t::iterator ptr = aNode->mArguments.begin();
        ptr != aNode->mArguments.end();
        ++ptr
      )
  { mResolver( &( *ptr ) ); }
}

//-----------------------------------------------------------------------------
/// S.EXP.L.2
void
GlobalResolutionVisitor::visit ( cInitializerList* aNode ) // : cExpressionList
{
  // ArgumentList_t mInitializers

  //std::for_each( aNode->mInitializers.begin(), aNode->mInitializers.end(),
                 //key::Visit( this ) );
  for ( ArgumentList_t::iterator ptr = aNode->mInitializers.begin();
        ptr != aNode->mInitializers.end();
        ++ptr
      )
  { mResolver( &( *ptr ) ); }
}

//-----------------------------------------------------------------------------
/// S.O
void
GlobalResolutionVisitor::visit ( cOperator* aNode ) // abstract : cExpression
{
  // eOperator mOperator

  // NO OP
}

//-----------------------------------------------------------------------------
/// S.O.1
void
GlobalResolutionVisitor::visit ( cUnaryOperator* aNode ) // : cOperator
{
  // cAsgNode* mOperand

  //mResolver( &aNode->mOperand );
  if ( aNode->mOperand )
  {
    if ( aNode->mOperand->isA( cType_kind ) )
    {
      if ( cType* t = dynamic_cast<cType*>( aNode->mOperand ) )
      {
        mResolver( &t );
        aNode->mOperand = t;
      }
    }
    else if ( aNode->mOperand->isA( cExpression_kind ) )
    {
      if ( cExpression* e = dynamic_cast<cExpression*>( aNode->mOperand ) )
      {
        mResolver( &e );
        aNode->mOperand = e;
      }
    }
  }
}

//-----------------------------------------------------------------------------
/// S.O.2
void
GlobalResolutionVisitor::visit ( cBinaryOperator* aNode ) // : cOperator
{
  // cAsgNode*        mLhs
  // cExpressionBase* mRhs

  if ( aNode->mLhs )
  {
    if ( aNode->mLhs->isA( cType_kind ) )
    {
      if ( cType* t = dynamic_cast<cType*>( aNode->mLhs ) )
      {
        mResolver( &t );
        aNode->mLhs = t;
      }
    }
    else if ( aNode->mLhs->isA( cExpression_kind ) )
    {
      if ( cExpression* e = dynamic_cast<cExpression*>( aNode->mLhs ) )
      {
        mResolver( &e );
        aNode->mLhs = e;
      }
    }
  }
  //mResolver( &aNode->mRhs );
  if ( aNode->mRhs )
  {
    if ( aNode->mRhs->isA( cExpression_kind ) )
    {
      if ( cExpression* e = dynamic_cast<cExpression*>( aNode->mRhs ) )
      {
        mResolver( &e );
        aNode->mRhs = e;
      }
    }
  }
}

//-----------------------------------------------------------------------------
/// S.O.3
void
GlobalResolutionVisitor::visit ( cTernaryOperator* aNode ) // : cOperator
{
  // cExpression* mCondition
  // cExpression* mTrueExpression
  // cExpression* mFalseExpression

  mResolver( &aNode->mCondition );
  mResolver( &aNode->mTrueExpression );
  mResolver( &aNode->mFalseExpression );
}

//-----------------------------------------------------------------------------
/// S.CS
void
GlobalResolutionVisitor::visit ( cControlStatement* aNode ) // abstract : cAsgNode
{
  // NO OP
}

//-----------------------------------------------------------------------------
/// S.SS
void
GlobalResolutionVisitor::visit ( cSelectionStatement* aNode ) // abstract : cControlStatement
{
  // cExpression* mCondition

  mResolver( &aNode->mCondition );
}

//-----------------------------------------------------------------------------
/// S.SS.1
void
GlobalResolutionVisitor::visit ( cIfStatement* aNode ) // : cSelectionStatement
{
  // cBlock* mTrueBlock
  // cBlock* mFalseBlock

  mResolver( &aNode->mCondition );

  key::VisitAttribute( this, aNode->mTrueBlock );
  key::VisitAttribute( this, aNode->mFalseBlock );
}

//-----------------------------------------------------------------------------
/// S.SS.2
void
GlobalResolutionVisitor::visit ( cSwitchStatement* aNode ) // : cSelectionStatement
{
  // cBlock* mBlock

  mResolver( &aNode->mCondition );
  key::VisitAttribute( this, aNode->mBlock );
}

//-----------------------------------------------------------------------------
/// S.IS
void
GlobalResolutionVisitor::visit ( cIterationStatement* aNode ) // abstract : cControlStatement
{
  // cExpression* mCondition
  // cBlock*      mBlock

  mResolver( &aNode->mCondition );
  key::VisitAttribute( this, aNode->mBlock );
}

//-----------------------------------------------------------------------------
/// S.IS.1
void
GlobalResolutionVisitor::visit ( cWhileLoop* aNode ) // : cIterationStatement
{
  mResolver( &aNode->mCondition );
  key::VisitAttribute( this, aNode->mBlock );
}

//-----------------------------------------------------------------------------
/// S.IS.2
void
GlobalResolutionVisitor::visit ( cDoWhileLoop* aNode ) // : cIterationStatement
{
  mResolver( &aNode->mCondition );
  key::VisitAttribute( this, aNode->mBlock );
}

//-----------------------------------------------------------------------------
/// S.IS.3
void
GlobalResolutionVisitor::visit ( cForLoop* aNode ) // : cIterationStatement
{
  // AsgNodeList_t mForInitStatement
  // cExpression*  mIncrement

  std::for_each( aNode->mForInitStatement.begin(), aNode->mForInitStatement.end(),
                 key::Visit( this ) );

  mResolver( &aNode->mCondition );
  mResolver( &aNode->mIncrement );
  key::VisitAttribute( this, aNode->mBlock );
}

//-----------------------------------------------------------------------------
/// S.JS
void
GlobalResolutionVisitor::visit ( cJumpStatement* aNode ) // abstract : cControlStatement
{
  // cExpression* mDestination

  mResolver( &aNode->mDestination );
}

//-----------------------------------------------------------------------------
/// S.JS.1
void
GlobalResolutionVisitor::visit ( cBreak* aNode ) // : cJumpStatement
{
  // NO OP
}

//-----------------------------------------------------------------------------
/// S.JS.2
void
GlobalResolutionVisitor::visit ( cContinue* aNode ) // : cJumpStatement
{
  // NO OP
}

//-----------------------------------------------------------------------------
/// S.JS.3
void
GlobalResolutionVisitor::visit ( cReturn* aNode ) // : cJumpStatement
{
  // cExpression* mValue

  mResolver( &aNode->mValue );
}

//-----------------------------------------------------------------------------
/// S.JS.4
void
GlobalResolutionVisitor::visit ( cGoto* aNode ) // : cJumpStatement
{
  // NO OP
}

//-----------------------------------------------------------------------------
/// S.EXC.1
void
GlobalResolutionVisitor::visit ( cTryBlock* aNode ) // : cBlock
{
  // HandlerList_t mHandlers

  std::for_each( aNode->mHandlers.begin(), aNode->mHandlers.end(),
                 key::Visit( this ) );
}

//-----------------------------------------------------------------------------
/// S.EXC.2
void
GlobalResolutionVisitor::visit ( cFunctionTryBlock* aNode ) // : cTryBlock
{
  // cCtorInitializerBlock* mInit

  std::for_each( aNode->mHandlers.begin(), aNode->mHandlers.end(),
                 key::Visit( this ) );

  key::VisitAttribute( this, aNode->mInit );
}

//-----------------------------------------------------------------------------
/// S.EXC.3
void
GlobalResolutionVisitor::visit ( cHandler* aNode ) // : cAsgNode
{
  // cExceptionDeclaration* mParameters
  // cBlock*                mStatements

  key::VisitAttribute( this, aNode->mParameters );
  key::VisitAttribute( this, aNode->mStatements );
}

//-----------------------------------------------------------------------------
/// S.EXC.4
void
GlobalResolutionVisitor::visit ( cExceptionDeclaration* aNode ) // : cIdentifier
{
  // cType*                 mType
  // cNameReference*        mNamedNamespace
  // cTemplateArgumentList* mTemplateArguments

  mResolver( &aNode->mType );

  key::VisitAttribute( this, aNode->mTemplateArguments );
}

//-----------------------------------------------------------------------------
/// S.EXC.5
void
GlobalResolutionVisitor::visit ( cThrowExpression* aNode ) // : cExpression
{
  // cExpression* mArgument

  mResolver( &aNode->mArgument );
}

//-----------------------------------------------------------------------------
/// S.EXC.6
void
GlobalResolutionVisitor::visit ( cExceptionSpecification* aNode ) // : cAsgNode
{
  // ThrowList_t mException

  for ( ThrowList_t::iterator ptr = aNode->mException.begin();
        ptr != aNode->mException.end();
        ++ptr
      )
  { mResolver( &( *ptr ) ); }
}

//-----------------------------------------------------------------------------

