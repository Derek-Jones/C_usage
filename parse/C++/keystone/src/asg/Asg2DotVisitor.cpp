//******************************************************************************
//
//  Asg2DotVisitor.cpp
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
/// A visitor which outputs the ASG in dot format.
/// Nodes which represent entities from the standard library are excluded.
/// Only nodes which can be direct children of the compilation scope must be
/// protected with STANDARD_LIBRARY_CHECK


#include <fstream>
#include <sstream>

#include "Ast.h"

#include "VisitorHelp.h"

#include "Asg2DotVisitor.h"

//-----------------------------------------------------------------------------

#define STANDARD_LIBRARY_CHECK(n) \
  if ( true ) \
  { \
    if ( StandardLibrary::inStandardLibrary( n->mFilename ) ) \
    { \
      return; \
    } \
  } \
  else \
    (void)0

//-----------------------------------------------------------------------------

Asg2DotVisitor::Asg2DotVisitor ( std::ofstream& aFile, bool aEdgeLabels )
  : mFile      ( aFile )
  , mEdgeLabels( aEdgeLabels )
{
}

//-----------------------------------------------------------------------------
/// S.B
void
Asg2DotVisitor::visit ( const cAsgNode* aNode ) // abstract
{
  // String   mFilename
  // int      mStartLine
  // int      mEndLine
  // unsigned mNodeNumber

  STANDARD_LIBRARY_CHECK(aNode);

  mFile << dotNodePrologue( aNode->getKindName(), aNode->mNodeNumber );
  mFile << dotNodeEpilogue();
}

//-----------------------------------------------------------------------------
/// S.B.1
void
Asg2DotVisitor::visit ( const cLinkage* aNode ) // : cAsgNode
{
  // String        mLinkType
  // bool          mIsBlock
  // AsgNodeList_t mContents

  STANDARD_LIBRARY_CHECK(aNode);

  mFile << dotNodePrologue( aNode->getKindName(), aNode->mNodeNumber );
  mFile << dotLinkage( aNode->mLinkType );
  mFile << dotIsBlock( aNode->mIsBlock );
  mFile << dotNodeEpilogue();

  dotAttributeVector( aNode, aNode->mContents, "cOwnershipEdge" );
}

//-----------------------------------------------------------------------------
/// S.B.2
void
Asg2DotVisitor::visit ( const cUsing* aNode ) // : cAsgNode
{
  // bool            mIsNamespace
  // cNameReference* mNameReference

  STANDARD_LIBRARY_CHECK(aNode);

  mFile << dotNodePrologue( aNode->getKindName(), aNode->mNodeNumber );
  mFile << dotIsNamespace( aNode->mIsNamespace );
  mFile << dotNodeEpilogue();

  dotAttribute( aNode, aNode->mNameReference, "cReferenceEdge" );
}

//-----------------------------------------------------------------------------
/// S.B.3
void
Asg2DotVisitor::visit ( const cAsmDefinition* aNode ) // : cAsgNode
{
  // String mAsm

  STANDARD_LIBRARY_CHECK(aNode);

  mFile << dotNodePrologue( aNode->getKindName(), aNode->mNodeNumber );
  mFile << dotAsm( aNode->mAsm );
  mFile << dotNodeEpilogue();
}

//-----------------------------------------------------------------------------
/// S.TA.L
void
Asg2DotVisitor::visit ( const cTemplateArgumentList* aNode ) // : cAsgNode
{
  // TemplateArgumentList_t mArguments

  STANDARD_LIBRARY_CHECK(aNode);

  mFile << dotNodePrologue( aNode->getKindName(), aNode->mNodeNumber );
  mFile << dotNodeEpilogue();

  dotAttributeVector( aNode, aNode->mArguments, "cOwnershipEdge" );
}

//-----------------------------------------------------------------------------
/// S.I
void
Asg2DotVisitor::visit ( const cIdentifier* aNode ) // abstract : cAsgNode
{
  // String            mName
  // eAccessSpecifier  mAccessSpecifier
  // cIdentifier*      mDefinedIn

  STANDARD_LIBRARY_CHECK(aNode);

  mFile << dotNodePrologue( aNode->getKindName(), aNode->mNodeNumber );
//mFile << dotNameDeclaration( aNode->mNameDeclaration );
  mFile << dotName( aNode->mName );
  mFile << dotAccessSpecifier( mE2S( aNode->mAccessSpecifier ) );
  mFile << dotDefinedIn( aNode->mDefinedIn );
  mFile << dotNodeEpilogue();
}

//-----------------------------------------------------------------------------
/// S.I.1
void
Asg2DotVisitor::visit ( const cEnumerator* aNode ) // : cIdentifier
{
  // cExpression* mValue

  key::VisitAsBaseType<const cIdentifier>( this, aNode );

  dotAttribute( aNode, aNode->mValue, "cValueEdge" );
}

//-----------------------------------------------------------------------------
/// S.OBJ
void
Asg2DotVisitor::visit ( const cObject* aNode ) // : cIdentifier
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

  mFile << dotNodePrologue( aNode->getKindName(), aNode->mNodeNumber );
//mFile << dotNameDeclaration( aNode->mNameDeclaration );
  mFile << dotName( aNode->mName );
  mFile << dotStorageClassSpecifier( aNode->mIsAuto, aNode->mIsRegister,
                                     aNode->mIsStatic, aNode->mIsExtern,
                                     aNode->mIsMutable );
  mFile << dotAccessSpecifier( mE2S( aNode->mAccessSpecifier ) );
  mFile << dotDefinedIn( aNode->mDefinedIn );
  mFile << dotNodeEpilogue();

  dotAttribute( aNode, aNode->mType, "cInstanceEdge" );
  dotAttribute( aNode, aNode->mTemplateArguments, "cTemplateArgumentListEdge" );
  dotAttribute( aNode, aNode->mNamedNamespace, "cScopeResolutionEdge" );
  dotAttribute( aNode, aNode->mInitialValue, "cInitialValueEdge" );
  dotAttribute( aNode, aNode->mBits, "cBitDimensionEdge" );
}

//-----------------------------------------------------------------------------
/// S.OBJ.L
void
Asg2DotVisitor::visit ( const cObjectList* aNode ) // : cIdentifier
{
  // AsgNodeList_t mObjects

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cIdentifier>( this, aNode );

  dotAttributeVector( aNode, aNode->mObjects, "cOwnershipEdge" );
}

//-----------------------------------------------------------------------------
/// S.FP
void
Asg2DotVisitor::visit ( const cFunctionParameter* aNode ) // : cFunctionParameterBase
{
  // bool                   mIsAuto
  // bool                   mIsRegister
  // cType*                 mType
  // cTemplateArgumentList* mTemplateArguments
  // cNameReference*        mNamedNamespace
  // cExpressionBase*       mDefault

  mFile << dotNodePrologue( aNode->getKindName(), aNode->mNodeNumber );
//mFile << dotNameDeclaration( aNode->mNameDeclaration );
  mFile << dotName( aNode->mName );
  mFile << dotStorageClassSpecifier( aNode->mIsAuto, aNode->mIsRegister,
                                     false, false,
                                     false );
  mFile << dotAccessSpecifier( mE2S( aNode->mAccessSpecifier ) );
  mFile << dotDefinedIn( aNode->mDefinedIn );
  mFile << dotNodeEpilogue();

  dotAttribute( aNode, aNode->mType, "cInstanceEdge" );
  dotAttribute( aNode, aNode->mTemplateArguments, "cTemplateArgumentListEdge" );
  dotAttribute( aNode, aNode->mNamedNamespace, "cScopeResolutionEdge" );
  dotAttribute( aNode, aNode->mDefault, "cDefaultValueEdge" );
}

//-----------------------------------------------------------------------------
/// S.FP.L
void
Asg2DotVisitor::visit ( const cFunctionParameterList* aNode ) // : cFunctionParameterBase
{
  // FunctionParameterList_t mParameters

  key::VisitAsBaseType<const cIdentifier>( this, aNode );

  dotAttributeVector( aNode, aNode->mParameters, "cOwnershipEdge" );
}

//-----------------------------------------------------------------------------
/// S.T
void
Asg2DotVisitor::visit ( const cType* aNode ) // abstract : cIdentifier
{
  // bool mIsConst
  // bool mIsVolatile

  STANDARD_LIBRARY_CHECK(aNode);

  mFile << dotNodePrologue( aNode->getKindName(), aNode->mNodeNumber );
//mFile << dotNameDeclaration( aNode->mNameDeclaration );
  mFile << dotName( aNode->mName );
  mFile << dotAccessSpecifier( mE2S( aNode->mAccessSpecifier ) );
  mFile << dotQualifier( aNode->mIsConst, aNode->mIsVolatile );
  mFile << dotDefinedIn( aNode->mDefinedIn );
  mFile << dotNodeEpilogue();
}

//-----------------------------------------------------------------------------
/// S.T.1
void
Asg2DotVisitor::visit ( const cBuiltInType* aNode ) // : cType
{
  STANDARD_LIBRARY_CHECK(aNode);

  if ( mSeen.insert( aNode->mNodeNumber ).second )
  {
    key::VisitAsBaseType<const cType>( this, aNode );
  }
}

//-----------------------------------------------------------------------------
/// S.T.2
void
Asg2DotVisitor::visit ( const cAliasType* aNode ) // : cType
{
  // cType* mAliasedType

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cType>( this, aNode );

  dotAttribute( aNode, aNode->mAliasedType, "cTypeEdge" );
}

//-----------------------------------------------------------------------------
/// S.T.3
void
Asg2DotVisitor::visit ( const cFunctionType* aNode ) // : cType
{
  // cParameterList* mParameters
  // cType*          mReturnType

  key::VisitAsBaseType<const cType>( this, aNode );

  dotAttribute( aNode, aNode->mReturnType, "cTypeEdge" );
  dotAttribute( aNode, aNode->mParameters, "cFunctionParameterListEdge" );
}

//-----------------------------------------------------------------------------
/// S.T.4
void
Asg2DotVisitor::visit ( const cEnumerationType* aNode ) // : cType
{
  // EnumeratorList_t mEnumerators

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cType>( this, aNode );

  dotAttributeVector( aNode, aNode->mEnumerators, "cOwnershipEdge" );
}

//-----------------------------------------------------------------------------
/// S.IT
void
Asg2DotVisitor::visit ( const cIndirectType* aNode ) // abstract : cType
{
  // cType* mBaseType

  STANDARD_LIBRARY_CHECK(aNode);

  if ( mSeen.insert( aNode->mNodeNumber ).second )
  {
    key::VisitAsBaseType<const cType>( this, aNode );

    dotAttribute( aNode, aNode->mBaseType, "cTypeEdge" );
  }
}

//-----------------------------------------------------------------------------
/// S.IT.1
void
Asg2DotVisitor::visit ( const cArrayType* aNode ) // : cIndirectType
{
  // cExpressionBase* mDimension

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cIndirectType>( this, aNode );

  dotAttribute( aNode, aNode->mDimension, "cArrayDimensionEdge" );
}

//-----------------------------------------------------------------------------
/// S.IT.2
void
Asg2DotVisitor::visit ( const cPointerType* aNode ) // : cIndirectType
{
  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cIndirectType>( this, aNode );
}

//-----------------------------------------------------------------------------
/// S.IT.3
void
Asg2DotVisitor::visit ( const cReferenceType* aNode ) // : cIndirectType
{
  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cIndirectType>( this, aNode );
}

//-----------------------------------------------------------------------------
/// I.CTI
void
Asg2DotVisitor::visit ( const cClassTypeInterface* aNode ) // abstract : cType
{
  // BaseClassList_t    mBaseClasses
  // FriendList_t       mFriends
  // MemberList_t       mMembers
  // eClassKey          mClassKey
  // DerivedClassList_t mDerivedClasses

  STANDARD_LIBRARY_CHECK(aNode);

  mFile << dotNodePrologue( aNode->getKindName(), aNode->mNodeNumber );
//mFile << dotNameDeclaration( aNode->mNameDeclaration );
  mFile << dotClassKey( mE2S( aNode->mClassKey ) );
  mFile << dotName( aNode->mName );
  mFile << dotAccessSpecifier( mE2S( aNode->mAccessSpecifier ) );
  mFile << dotQualifier( aNode->mIsConst, aNode->mIsVolatile );
  mFile << dotDefinedIn( aNode->mDefinedIn );
  mFile << dotNodeEpilogue();

  dotBaseClasses( aNode, aNode->mBaseClasses );
}

//-----------------------------------------------------------------------------
/// S.CTI.1
void
Asg2DotVisitor::visit ( const cTemplateClassType* aNode ) // : cClassTypeInterface
{
  // cTemplateParameterList* mTemplateParameters

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cClassTypeInterface>( this, aNode );

  dotAttribute( aNode, aNode->mTemplateParameters, "cTemplateParameterListEdge" );
  dotAttributeVector( aNode, aNode->mMembers, "cOwnershipEdge" );
  dotAttributeVector( aNode, aNode->mFriends, "cFriendEdge" );
}

//-----------------------------------------------------------------------------
/// S.CTI.2
void
Asg2DotVisitor::visit ( const cSpecializedClassType* aNode ) // : cClassTypeInterface
{
  // cTemplateParameterList* mTemplateParameters
  // cTemplateArgumentList*  mTemplateArguments

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cClassTypeInterface>( this, aNode );

  dotAttribute( aNode, aNode->mTemplateParameters, "cTemplateParameterListEdge" );
  dotAttribute( aNode, aNode->mTemplateArguments, "cTemplateArgumentListEdge" );
  dotAttributeVector( aNode, aNode->mMembers, "cOwnershipEdge" );
  dotAttributeVector( aNode, aNode->mFriends, "cFriendEdge" );
}

//-----------------------------------------------------------------------------
/// S.CTI.3
void
Asg2DotVisitor::visit ( const cClassType* aNode ) // : cClassTypeInterface
{
  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cClassTypeInterface>( this, aNode );

  dotAttributeVector( aNode, aNode->mMembers, "cOwnershipEdge" );
  dotAttributeVector( aNode, aNode->mFriends, "cFriendEdge" );
}

//-----------------------------------------------------------------------------
/// S.CTI.4
void
Asg2DotVisitor::visit ( const cInstantiatedClassType* aNode ) // : cClassTypeInterface
{
  // cTemplateArgumentList* mTemplateArguments

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cClassTypeInterface>( this, aNode );

  dotAttribute( aNode, aNode->mTemplateArguments, "cTemplateArgumentListEdge" );
  dotAttributeVector( aNode, aNode->mMembers, "cOwnershipEdge" );
  dotAttributeVector( aNode, aNode->mFriends, "cFriendEdge" );
}

//-----------------------------------------------------------------------------
/// I.FTI
void
Asg2DotVisitor::visit ( const cForwardTypeInterface* aNode ) // abstract : cType
{
  // cNameReference* mNamedNamespace
  // cType*          mTypeDeclaration

  STANDARD_LIBRARY_CHECK(aNode);

#if 0
  if ( aNode->mNameDeclaration )
  {
    std::cout << "NODE: " << aNode->mNodeNumber << std::endl;
    std::cout << "ND:   " << aNode->mNameDeclaration << std::endl;
    aNode->mNameDeclaration->Print( std::cout );
    std::cout << std::endl;
  }
#endif

  key::VisitAsBaseType<const cType>( this, aNode );

  dotAttribute( aNode, aNode->mNamedNamespace, "cScopeResolutionEdge" );
}

//-----------------------------------------------------------------------------
/// S.FTI.1
void
Asg2DotVisitor::visit ( const cTemplateForwardType* aNode ) // : cForwardTypeInterface
{
  // cTemplateParameterList* mTemplateParameters

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cForwardTypeInterface>( this, aNode );

  dotAttribute( aNode, aNode->mTemplateParameters, "cTemplateParameterListEdge" );
}

//-----------------------------------------------------------------------------
/// S.FTI.2
void
Asg2DotVisitor::visit ( const cSpecializedForwardType* aNode ) // : cForwardTypeInterface
{
  // cTemplateParameterList* mTemplateParameters
  // cTemplateArgumentList*  mTemplateArguments

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cForwardTypeInterface>( this, aNode );

  dotAttribute( aNode, aNode->mTemplateParameters, "cTemplateParameterListEdge" );
  dotAttribute( aNode, aNode->mTemplateArguments, "cTemplateArgumentListEdge" );
}

//-----------------------------------------------------------------------------
/// S.FTI.3
void
Asg2DotVisitor::visit ( const cForwardType* aNode ) // : cForwardTypeInterface
{
  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cForwardTypeInterface>( this, aNode );
}

//-----------------------------------------------------------------------------
/// S.FTI.4
void
Asg2DotVisitor::visit ( const cInstantiatedForwardType* aNode ) // : cForwardTypeInterface
{
  // cTemplateArgumentList* mTemplateArguments

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cForwardTypeInterface>( this, aNode );

  dotAttribute( aNode, aNode->mTemplateArguments, "cTemplateArgumentListEdge" );
}

//-----------------------------------------------------------------------------
/// S.L
void
Asg2DotVisitor::visit ( const cLabel* aNode ) // : cIdentifier
{
  // cAsgNode* mLabeledStatement

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cIdentifier>( this, aNode );

  dotAttribute( aNode, aNode->mLabeledStatement, "cOwnershipEdge" );
}

//-----------------------------------------------------------------------------
/// S.L.1
void
Asg2DotVisitor::visit ( const cCaseLabel* aNode ) // : cLabel
{
  // cExpression* mConstantExpression

  key::VisitAsBaseType<const cLabel>( this, aNode );

  dotAttribute( aNode, aNode->mConstantExpression, "cValueEdge" );
}

//-----------------------------------------------------------------------------
/// S.L.2
void
Asg2DotVisitor::visit ( const cDefaultLabel* aNode ) // : cLabel
{
  key::VisitAsBaseType<const cLabel>( this, aNode );
}

//-----------------------------------------------------------------------------
/// S.FI
void
Asg2DotVisitor::visit ( const cFunctionInterface* aNode ) // abstract : cIdentifier
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

  STANDARD_LIBRARY_CHECK(aNode);

  mFile << dotNodePrologue( aNode->getKindName(), aNode->mNodeNumber );
//mFile << dotNameDeclaration( aNode->mNameDeclaration );
  mFile << dotName( aNode->mName );
  mFile << dotFunctionKey( mE2S( aNode->mFunctionKey ) );
  mFile << dotFunctionSpecifier( aNode->mIsExplicit, aNode->mIsVirtual,
                                 aNode->mIsInline );
  mFile << dotStorageClassSpecifier( false, false,
                                     aNode->mIsStatic, aNode->mIsExtern,
                                     false );
  mFile << dotAccessSpecifier( mE2S( aNode->mAccessSpecifier ) );
  mFile << dotDefinedIn( aNode->mDefinedIn );
  mFile << dotNodeEpilogue();

  dotAttribute( aNode, aNode->mNamedNamespace, "cScopeResolutionEdge" );
  dotAttribute( aNode, aNode->mType, "cTypeEdge" );
  dotAttribute( aNode, aNode->mThrows, "cThrowsEdge" );
  dotAttribute( aNode, aNode->mInit, "cCtorInitializerEdge" );
  dotAttribute( aNode, aNode->mBlock, "cOwnershipEdge" );
}

//-----------------------------------------------------------------------------
/// S.FI.1
void
Asg2DotVisitor::visit ( const cTemplateFunction* aNode ) // : cFunctionInterface
{
  // cTemplateParameterList* mTemplateParameters

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cFunctionInterface>( this, aNode );

  dotAttribute( aNode, aNode->mTemplateParameters, "cTemplateParameterListEdge" );
}

//-----------------------------------------------------------------------------
/// S.FI.2
void
Asg2DotVisitor::visit ( const cSpecializedFunction* aNode ) // : cFunctionInterface
{
  // cTemplateParameterList* mTemplateParameters
  // cTemplateArgumentList*  mTemplateArguments

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cFunctionInterface>( this, aNode );

  dotAttribute( aNode, aNode->mTemplateParameters, "cTemplateParameterListEdge" );
  dotAttribute( aNode, aNode->mTemplateArguments, "cTemplateArgumentListEdge" );
}

//-----------------------------------------------------------------------------
/// S.FI.3
void
Asg2DotVisitor::visit ( const cFunction* aNode ) // : cFunctionInterface
{
  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cFunctionInterface>( this, aNode );
}

//-----------------------------------------------------------------------------
/// S.FI.4
void
Asg2DotVisitor::visit ( const cInstantiatedFunction* aNode ) // : cFunctionInterface
{
  // cTemplateArgumentList* mTemplateArguments

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cFunctionInterface>( this, aNode );

  dotAttribute( aNode, aNode->mTemplateArguments, "cTemplateArgumentListEdge" );
}

//-----------------------------------------------------------------------------
/// S.S
void
Asg2DotVisitor::visit ( const cScope* aNode ) // abstract : cIdentifier
{
  // AsgNodeList_t mContents

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cIdentifier>( this, aNode );

  dotAttributeVector( aNode, aNode->mContents, "cOwnershipEdge" );
}

//-----------------------------------------------------------------------------
/// S.S.1
void
Asg2DotVisitor::visit ( const cGlobalScope* aNode ) // : cScope
{
  key::VisitAsBaseType<const cScope>( this, aNode );
}

//-----------------------------------------------------------------------------
/// S.S.2
void
Asg2DotVisitor::visit ( const cCompilationScope* aNode ) // : cScope
{
  key::VisitAsBaseType<const cScope>( this, aNode );
}

//-----------------------------------------------------------------------------
/// S.S.3
void
Asg2DotVisitor::visit ( const cNamespace* aNode ) // : cScope
{
  // cNameReference* mAliases

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cScope>( this, aNode );

  dotAttribute( aNode, aNode->mAliases, "cReferenceEdge" );
}

//-----------------------------------------------------------------------------
/// S.BLK
void
Asg2DotVisitor::visit ( const cBlock* aNode ) // : cScope
{
  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cScope>( this, aNode );
}

//-----------------------------------------------------------------------------
/// S.BLK.1
void
Asg2DotVisitor::visit ( const cCtorInitializerBlock* aNode ) // : cBlock
{
  key::VisitAsBaseType<const cScope>( this, aNode );
}

//-----------------------------------------------------------------------------
/// S.TP
void
Asg2DotVisitor::visit ( const cTemplateParameter* aNode ) // abstract : cTemplateParameterBase
{
  key::VisitAsBaseType<const cIdentifier>( this, aNode );

#if 0
  if ( aNode->mNameDeclaration )
  {
    std::cout << "NODE: " << aNode->mNodeNumber << std::endl;
    std::cout << "ND:   " << aNode->mNameDeclaration << std::endl;
    aNode->mNameDeclaration->Print( std::cout );
    std::cout << std::endl;
  }
#endif
}

//-----------------------------------------------------------------------------
/// S.TP.1
void
Asg2DotVisitor::visit ( const cTypeTemplateParameter* aNode ) // : cTemplateParameter
{
  // cType* mDefault

  key::VisitAsBaseType<const cTemplateParameter>( this, aNode );

  dotAttribute( aNode, aNode->mDefault, "cDefaultTypeEdge" );
}

//-----------------------------------------------------------------------------
/// S.TP.2
void
Asg2DotVisitor::visit ( const cTemplateTemplateParameter* aNode ) // : cTemplateParameter
{
  // cTemplateParameterList* mTemplateParameters
  // cNameReference*         mDefault

  key::VisitAsBaseType<const cTemplateParameter>( this, aNode );

  dotAttribute( aNode, aNode->mTemplateParameters, "cTemplateParameterListEdge" );
  dotAttribute( aNode, aNode->mDefault, "cDefaultTypeEdge" );
}

//-----------------------------------------------------------------------------
/// S.TP.3
void
Asg2DotVisitor::visit ( const cNonTypeTemplateParameter* aNode ) // : cTemplateParameter
{
  // bool                   mIsAuto
  // bool                   mIsRegister
  // cType*                 mType
  // cTemplateArgumentList* mTemplateArguments
  // cNameReference*        mNamedNamespace
  // cExpressionBase*       mDefault

  mFile << dotNodePrologue( aNode->getKindName(), aNode->mNodeNumber );
  mFile << dotName( aNode->mName );
  mFile << dotStorageClassSpecifier( aNode->mIsAuto, aNode->mIsRegister,
                                     false, false,
                                     false );
  mFile << dotAccessSpecifier( mE2S( aNode->mAccessSpecifier ) );
  mFile << dotDefinedIn( aNode->mDefinedIn );
  mFile << dotNodeEpilogue();

  dotAttribute( aNode, aNode->mType, "cInstanceEdge" );
  dotAttribute( aNode, aNode->mTemplateArguments, "cTemplateArgumentListEdge" );
  dotAttribute( aNode, aNode->mNamedNamespace, "cScopeResolutionEdge" );
  dotAttribute( aNode, aNode->mDefault, "cDefaultValueEdge" );
}

//-----------------------------------------------------------------------------
/// S.TP.L
void
Asg2DotVisitor::visit ( const cTemplateParameterList* aNode ) // : cTemplateParameterBase
{
  // TemplateParameterList_t mParameters

  key::VisitAsBaseType<const cAsgNode>( this, aNode );

  dotAttributeVector( aNode, aNode->mParameters, "cOwnershipEdge" );
}

//-----------------------------------------------------------------------------
/// S.EXP
void
Asg2DotVisitor::visit ( const cExpression* aNode ) // abstract : cExpressionBase
{
  // cType* mType

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cAsgNode>( this, aNode );

  dotAttribute( aNode, aNode->mType, "cTypeEdge" );
}

//-----------------------------------------------------------------------------
/// S.EXP.1
void
Asg2DotVisitor::visit ( const cNameReference* aNode ) // : cExpression
{
  // String                 mName
  // cTemplateArgumentList* mTemplateArguments
  // cNameReference*        mNamedNamespace
  // bool                   mIsPseudoDestructor
  // cIdentifier*           mObjectDeclaration

  STANDARD_LIBRARY_CHECK(aNode);

  mFile << dotNodePrologue( aNode->getKindName(), aNode->mNodeNumber );
//mFile << dotNameDeclaration( aNode->mNameDeclaration );
  mFile << dotName( aNode->mName );
  mFile << dotPseudoDestructor( aNode->mIsPseudoDestructor );
  mFile << dotNodeEpilogue();

  dotAttribute( aNode, aNode->mNamedNamespace, "cScopeResolutionEdge" );
  dotAttribute( aNode, aNode->mTemplateArguments, "cTemplateArgumentListEdge" );
  dotAttribute( aNode, aNode->mObjectDeclaration, "cInstanceEdge" );
}

//-----------------------------------------------------------------------------
/// S.EXP.2
void
Asg2DotVisitor::visit ( const cLiteral* aNode ) // : cExpression
{
  // String mValue

  STANDARD_LIBRARY_CHECK(aNode);

  if ( mSeen.insert( aNode->mNodeNumber ).second )
  {
    mFile << dotNodePrologue( aNode->getKindName(), aNode->mNodeNumber );
    mFile << dotLiteral( aNode->mValue );
    mFile << dotNodeEpilogue();

    dotAttribute( aNode, aNode->mType, "cTypeEdge" );
  }
}

//-----------------------------------------------------------------------------
/// S.EXP.3
void
Asg2DotVisitor::visit ( const cNewExpression* aNode ) // : cExpression
{
  // cExpressionBase*       mInitializer
  // cFunctionArgumentList* mPlacement

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cExpression>( this, aNode );

  dotAttribute( aNode, aNode->mPlacement, "cPlacementEdge" );
  dotAttribute( aNode, aNode->mInitializer, "cInitialValueEdge" );
}

//-----------------------------------------------------------------------------
/// S.EXP.4
void
Asg2DotVisitor::visit ( const cDeleteExpression* aNode ) // : cExpression
{
  // cExpression* mToDelete
  // bool         mIsArray

  STANDARD_LIBRARY_CHECK(aNode);

  mFile << dotNodePrologue( aNode->getKindName(), aNode->mNodeNumber );
  mFile << dotIsArray( aNode->mIsArray );
  mFile << dotNodeEpilogue();

  dotAttribute( aNode, aNode->mType, "cTypeEdge" );
  dotAttribute( aNode, aNode->mToDelete, "cOwnershipEdge" );
}

//-----------------------------------------------------------------------------
/// S.EXP.5
void
Asg2DotVisitor::visit ( const cConditionDeclarator* aNode ) // : cExpression
{
  // cObject* mObject

  key::VisitAsBaseType<const cExpression>( this, aNode );

  dotAttribute( aNode, aNode->mObject, "cOwnershipEdge" );
}

//-----------------------------------------------------------------------------
/// S.EXP.6
void
Asg2DotVisitor::visit ( const cEmptyExpression* aNode ) // : cExpression
{
  key::VisitAsBaseType<const cExpression>( this, aNode );
}

//-----------------------------------------------------------------------------
/// S.EXP.L
void
Asg2DotVisitor::visit ( const cExpressionList* aNode ) // : cExpressionBase
{
  // cType* mType

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cAsgNode>( this, aNode );

  dotAttribute( aNode, aNode->mType, "cTypeEdge" );
}

//-----------------------------------------------------------------------------
/// S.EXP.L.1
void
Asg2DotVisitor::visit ( const cFunctionArgumentList* aNode ) // : cExpressionList
{
  // ArgumentList_t mArguments

  key::VisitAsBaseType<const cExpressionList>( this, aNode );

  dotAttributeVector( aNode, aNode->mArguments, "cOwnershipEdge" );
}

//-----------------------------------------------------------------------------
/// S.EXP.L.2
void
Asg2DotVisitor::visit ( const cInitializerList* aNode ) // : cExpressionList
{
  // ArgumentList_t mInitializers

  key::VisitAsBaseType<const cExpressionList>( this, aNode );

  dotAttributeVector( aNode, aNode->mInitializers, "cOwnershipEdge" );
}

//-----------------------------------------------------------------------------
/// S.O
void
Asg2DotVisitor::visit ( const cOperator* aNode ) // abstract : cExpression
{
  // eOperator mOperator

  STANDARD_LIBRARY_CHECK(aNode);

  mFile << dotNodePrologue( aNode->getKindName(), aNode->mNodeNumber );
  mFile << dotOperator( mE2S( aNode->mOperator ) );
  mFile << dotNodeEpilogue();
}

//-----------------------------------------------------------------------------
/// S.O.1
void
Asg2DotVisitor::visit ( const cUnaryOperator* aNode ) // : cOperator
{
  // cAsgNode* mOperand

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cOperator>( this, aNode );

  dotAttribute( aNode, aNode->mOperand, "cOperand" );
}

//-----------------------------------------------------------------------------
/// S.O.2
void
Asg2DotVisitor::visit ( const cBinaryOperator* aNode ) // : cOperator
{
  // cAsgNode*        mLhs
  // cExpressionBase* mRhs

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cOperator>( this, aNode );

  dotAttribute( aNode, aNode->mLhs, "cOperand(1)" );
  dotAttribute( aNode, aNode->mRhs, "cOperand(2)" );
}

//-----------------------------------------------------------------------------
/// S.O.3
void
Asg2DotVisitor::visit ( const cTernaryOperator* aNode ) // : cOperator
{
  // cExpression* mCondition
  // cExpression* mTrueExpression
  // cExpression* mFalseExpression

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cOperator>( this, aNode );

  dotAttribute( aNode, aNode->mCondition, "cConditionEdge" );
  dotAttribute( aNode, aNode->mTrueExpression, "cTrueBranchEdge" );
  dotAttribute( aNode, aNode->mFalseExpression, "cFalseBranchEdge" );
}

//-----------------------------------------------------------------------------
/// S.CS
void
Asg2DotVisitor::visit ( const cControlStatement* aNode ) // abstract : cAsgNode
{
  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cAsgNode>( this, aNode );
}

//-----------------------------------------------------------------------------
/// S.SS
void
Asg2DotVisitor::visit ( const cSelectionStatement* aNode ) // abstract : cControlStatement
{
  // cExpression* mCondition

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cControlStatement>( this, aNode );

  dotAttribute( aNode, aNode->mCondition, "cConditionEdge" );
}

//-----------------------------------------------------------------------------
/// S.SS.1
void
Asg2DotVisitor::visit ( const cIfStatement* aNode ) // : cSelectionStatement
{
  // cBlock* mTrueBlock
  // cBlock* mFalseBlock

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cSelectionStatement>( this, aNode );

  dotAttribute( aNode, aNode->mTrueBlock, "cTrueBlockEdge" );
  dotAttribute( aNode, aNode->mFalseBlock, "cFalseBlockEdge" );
}

//-----------------------------------------------------------------------------
/// S.SS.2
void
Asg2DotVisitor::visit ( const cSwitchStatement* aNode ) // : cSelectionStatement
{
  // cBlock* mBlock

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cSelectionStatement>( this, aNode );

  dotAttribute( aNode, aNode->mBlock, "cOwnershipEdge" );
}

//-----------------------------------------------------------------------------
/// S.IS
void
Asg2DotVisitor::visit ( const cIterationStatement* aNode ) // abstract : cControlStatement
{
  // cExpression* mCondition
  // cBlock*      mBlock

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cControlStatement>( this, aNode );

  dotAttribute( aNode, aNode->mCondition, "cConditionEdge" );
  dotAttribute( aNode, aNode->mBlock, "cOwnershipEdge" );
}

//-----------------------------------------------------------------------------
/// S.IS.1
void
Asg2DotVisitor::visit ( const cWhileLoop* aNode ) // : cIterationStatement
{
  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cIterationStatement>( this, aNode );
}

//-----------------------------------------------------------------------------
/// S.IS.2
void
Asg2DotVisitor::visit ( const cDoWhileLoop* aNode ) // : cIterationStatement
{
  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cIterationStatement>( this, aNode );
}

//-----------------------------------------------------------------------------
/// S.IS.3
void
Asg2DotVisitor::visit ( const cForLoop* aNode ) // : cIterationStatement
{
  // AsgNodeList_t mForInitStatement
  // cExpression*  mIncrement

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cControlStatement>( this, aNode );

  dotAttributeVector( aNode, aNode->mForInitStatement, "cForInitEdge" );
  dotAttribute( aNode, aNode->mCondition, "cConditionEdge" );
  dotAttribute( aNode, aNode->mIncrement, "cForIncrementEdge" );
  dotAttribute( aNode, aNode->mBlock, "cOwnershipEdge" );
}

//-----------------------------------------------------------------------------
/// S.JS
void
Asg2DotVisitor::visit ( const cJumpStatement* aNode ) // abstract : cControlStatement
{
  // cExpression* mDestination

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cControlStatement>( this, aNode );

  dotAttribute( aNode, aNode->mDestination, "cDestinationEdge" );
}

//-----------------------------------------------------------------------------
/// S.JS.1
void
Asg2DotVisitor::visit ( const cBreak* aNode ) // : cJumpStatement
{
  key::VisitAsBaseType<const cJumpStatement>( this, aNode );
}

//-----------------------------------------------------------------------------
/// S.JS.2
void
Asg2DotVisitor::visit ( const cContinue* aNode ) // : cJumpStatement
{
  key::VisitAsBaseType<const cJumpStatement>( this, aNode );
}

//-----------------------------------------------------------------------------
/// S.JS.3
void
Asg2DotVisitor::visit ( const cReturn* aNode ) // : cJumpStatement
{
  // cExpression* mValue

  key::VisitAsBaseType<const cJumpStatement>( this, aNode );

  dotAttribute( aNode, aNode->mValue, "cValueEdge" );
}

//-----------------------------------------------------------------------------
/// S.JS.4
void
Asg2DotVisitor::visit ( const cGoto* aNode ) // : cJumpStatement
{
  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cJumpStatement>( this, aNode );
}

//-----------------------------------------------------------------------------
/// S.EXC.1
void
Asg2DotVisitor::visit ( const cTryBlock* aNode ) // : cBlock
{
  // HandlerList_t mHandlers

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cBlock>( this, aNode );

  dotAttributeVector( aNode, aNode->mHandlers, "cHandlerEdge" );
}

//-----------------------------------------------------------------------------
/// S.EXC.2
void
Asg2DotVisitor::visit ( const cFunctionTryBlock* aNode ) // : cTryBlock
{
  // cCtorInitializerBlock* mInit

  key::VisitAsBaseType<const cIdentifier>( this, aNode );

  dotAttribute( aNode, aNode->mInit, "cCtorInitializerEdge" );
  dotAttributeVector( aNode, aNode->mContents, "cOwnershipEdge" );
  dotAttributeVector( aNode, aNode->mHandlers, "cHandlerEdge" );
}

//-----------------------------------------------------------------------------
/// S.EXC.3
void
Asg2DotVisitor::visit ( const cHandler* aNode ) // : cAsgNode
{
  // cExceptionDeclaration* mParameters
  // cBlock*                mStatements

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cAsgNode>( this, aNode );

  dotAttribute( aNode, aNode->mParameters, "cExceptionDeclarationEdge" );
  dotAttribute( aNode, aNode->mStatements, "cOwnershipEdge" );
}

//-----------------------------------------------------------------------------
/// S.EXC.4
void
Asg2DotVisitor::visit ( const cExceptionDeclaration* aNode ) // : cIdentifier
{
  // cType*                 mType
  // cNameReference*        mNamedNamespace
  // cTemplateArgumentList* mTemplateArguments

  mFile << dotNodePrologue( aNode->getKindName(), aNode->mNodeNumber );
//mFile << dotNameDeclaration( aNode->mNameDeclaration );
  mFile << dotName( aNode->mName );
  mFile << dotAccessSpecifier( mE2S( aNode->mAccessSpecifier ) );
  mFile << dotDefinedIn( aNode->mDefinedIn );
  mFile << dotNodeEpilogue();

  dotAttribute( aNode, aNode->mType, "cInstanceEdge" );
  dotAttribute( aNode, aNode->mNamedNamespace, "cScopeResolutionEdge" );
  dotAttribute( aNode, aNode->mTemplateArguments, "cTemplateArgumentListEdge" );
}

//-----------------------------------------------------------------------------
/// S.EXC.5
void
Asg2DotVisitor::visit ( const cThrowExpression* aNode ) // : cExpression
{
  // cExpression* mArgument

  STANDARD_LIBRARY_CHECK(aNode);

  key::VisitAsBaseType<const cExpression>( this, aNode );

  dotAttribute( aNode, aNode->mArgument, "cOwnershipEdge" );
}

//-----------------------------------------------------------------------------
/// S.EXC.6
void
Asg2DotVisitor::visit ( const cExceptionSpecification* aNode ) // : cAsgNode
{
  // ThrowList_t mException

  key::VisitAsBaseType<const cAsgNode>( this, aNode );

  dotAttributeVector( aNode, aNode->mException, "cOwnershipEdge" );
}

//-----------------------------------------------------------------------------
/// Private Methods
//-----------------------------------------------------------------------------

//---------------------------------------------------------------------------
///
std::string
Asg2DotVisitor::dotNodePrologue ( const char* aKind, unsigned aNodeNumber )
{
  std::stringstream sstr;

  //sstr << "\"" << aKind << aNodeNumber << "\""
       //<< "[\n\tlabel = \"{" << aNodeNumber << ": " << aKind;
  sstr << aKind << aNodeNumber
       << "[\n\tlabel = \"{" << aNodeNumber << ": " << aKind;

  return sstr.str();
}

//---------------------------------------------------------------------------
///
std::string
Asg2DotVisitor::dotNodeEpilogue ( void )
{
  return "}\"\n\tshape = \"record\"\n];\n";
}

//---------------------------------------------------------------------------
///
std::string
Asg2DotVisitor::dotUnquotedString ( const std::string& aCaption, const std::string& aUnquoted )
{
  std::string rVal = "";

  if ( aUnquoted.size() )
  {
    rVal += " | " + aCaption + ": " + aUnquoted;
  }

  return rVal;
}

//---------------------------------------------------------------------------
///
std::string
Asg2DotVisitor::dotNodeNumber ( const std::string& aCaption, const cAsgNode* aNode )
{
  std::stringstream rVal;

  if ( aNode )
  {
    rVal << " | " + aCaption + ": " << aNode->mNodeNumber;
  }

  return rVal.str();
}

//---------------------------------------------------------------------------
///
std::string
Asg2DotVisitor::dotQuotedString ( const std::string& aCaption, std::string aQuoted )
{
  std::string rVal = "";

  if ( aQuoted.size() )
  {
    if ( aQuoted.find( "\"" ) != std::string::npos )
    {
      aQuoted.insert( aQuoted.begin(), '\\' );
      aQuoted.resize( aQuoted.size() - 1 );
      aQuoted.append( "\\\"" );
    }
    rVal += " | " + aCaption + ": " + aQuoted;
  }

  return rVal;
}

//---------------------------------------------------------------------------
///
std::string
Asg2DotVisitor::dotNameDeclaration ( const NameDeclaration* aDecl )
{
  std::stringstream rVal;

  rVal << " | " << "nd: " << aDecl;

  return rVal.str();
}

//---------------------------------------------------------------------------
///
std::string
Asg2DotVisitor::dotBool ( const std::string& aProperty, bool aValue )
{
  std::string rVal = "";

  if ( aValue )
  {
    rVal += " | " + aProperty + ": " + bool2String( aValue );
  }

  return rVal;
}

//---------------------------------------------------------------------------
///
std::string
Asg2DotVisitor::dotQualifier ( bool aIsConst, bool aIsVolatile )
{
  std::string rVal = "";

  if ( aIsConst || aIsVolatile )
  {
    rVal += " | qualifier: ";
    rVal += ( aIsConst ?
              ( aIsVolatile ?  "const volatile" : "const" ) :
              ( aIsVolatile ? "volatile" : "" ) );
  }

  return rVal;
}

//---------------------------------------------------------------------------
///
std::string
Asg2DotVisitor::dotFunctionSpecifier ( bool aIsExplicit,
                                       bool aIsVirtual,
                                       bool aIsInline
                                     )
{
  std::string rVal = "";

  if ( aIsExplicit || aIsVirtual || aIsInline )
  {
    rVal += " | function spec: ";

    if ( aIsExplicit ) rVal += "explicit ";
    if ( aIsVirtual  ) rVal += "virtual ";
    if ( aIsInline   ) rVal += "inline ";
  }

  return rVal;
}

//---------------------------------------------------------------------------
///
std::string
Asg2DotVisitor::dotStorageClassSpecifier ( bool aIsAuto,
                                           bool aIsRegister,
                                           bool aIsStatic,
                                           bool aIsExtern,
                                           bool aIsMutable
                                         )
{
  std::string rVal = "";

  if ( aIsAuto || aIsRegister || aIsStatic || aIsExtern || aIsMutable )
  {
    rVal += " | storage spec: ";

    if ( aIsAuto     ) rVal += "auto ";
    if ( aIsRegister ) rVal += "register ";
    if ( aIsStatic   ) rVal += "static ";
    if ( aIsExtern   ) rVal += "extern ";
    if ( aIsMutable  ) rVal += "mutable ";
  }

  return rVal;
}

//---------------------------------------------------------------------------
///
void
Asg2DotVisitor::dotBaseClasses ( const cClassTypeInterface* aCaller
                               , const BaseClassList_t&     aList
                               )
{
  for ( BaseClassList_t::const_iterator ptr = aList.begin();
        ptr != aList.end();
        ++ptr
      )
  {
    std::string accessStr  = mE2S( ptr->second.first );
    std::string virtualStr = ( ptr->second.second ? "virtual " : "" );

    if ( ptr->first )
    {
      ptr->first->accept( this );
      mFile << aCaller->getKindName() << aCaller->mNodeNumber
            << " -> " << ptr->first->getKindName() << ptr->first->mNodeNumber;
      if ( mEdgeLabels )
      {
        mFile << " [ labeldistance = \"2.00\", headlabel = \""
              << ( "cInheritanceEdge: " + virtualStr + accessStr ) << "\" ]";
      }
      mFile << ";\n";
    }
  }
}

//---------------------------------------------------------------------------
///
template < class T >
void
Asg2DotVisitor::dotAttribute ( const cAsgNode*     aCaller
                             , const T*            aChild
                             , const std::string&  aLabel
                             )
{
  if ( aChild )
  {
    STANDARD_LIBRARY_CHECK(aChild);

    aChild->accept( this );
    mFile << aCaller->getKindName() << aCaller->mNodeNumber
          << " -> " << aChild->getKindName() << aChild->mNodeNumber;
    if ( mEdgeLabels )
    {
      mFile << " [ labeldistance = \"2.00\", headlabel = \"" << aLabel << "\" ]";
    }
    mFile << ";\n";
  }
}

//---------------------------------------------------------------------------
///
template < class T >
void
Asg2DotVisitor::dotAttributeVector ( const cAsgNode*    aCaller,
                                     const std::vector<T*>& aVector,
                                     const std::string&     aLabel )
{
  for ( typename std::vector<T*>::const_iterator ptr = aVector.begin();
        ptr != aVector.end();
        ++ptr
      )
  {
    dotAttribute( aCaller, *ptr, aLabel );
  }
}

//-----------------------------------------------------------------------------

