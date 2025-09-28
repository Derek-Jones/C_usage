//******************************************************************************
//
//  Asg2DotVisitor.h
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

#ifndef _ASG_2_DOT_VISITOR_H_
#define _ASG_2_DOT_VISITOR_H_

#include <set>

#include "SchemaConstVisitor.h"
#include "SchemaEnum2String.h"

class Asg2DotVisitor : public SchemaConstVisitor
{
public:
  Asg2DotVisitor ( std::ofstream&, bool );

  void visit ( const cAsgNode* );
  void visit ( const cLinkage* );
  void visit ( const cUsing* );
  void visit ( const cAsmDefinition* );
  void visit ( const cTemplateArgumentList* );
  void visit ( const cIdentifier* );
  void visit ( const cEnumerator* );
  void visit ( const cObject* );
  void visit ( const cObjectList* );
  void visit ( const cFunctionParameter* );
  void visit ( const cFunctionParameterList* );
  void visit ( const cType* );
  void visit ( const cBuiltInType* );
  void visit ( const cAliasType* );
  void visit ( const cFunctionType* );
  void visit ( const cEnumerationType* );
  void visit ( const cIndirectType* );
  void visit ( const cArrayType* );
  void visit ( const cPointerType* );
  void visit ( const cReferenceType* );
  void visit ( const cClassTypeInterface* );
  void visit ( const cTemplateClassType* );
  void visit ( const cSpecializedClassType* );
  void visit ( const cClassType* );
  void visit ( const cInstantiatedClassType* );
  void visit ( const cForwardTypeInterface* );
  void visit ( const cTemplateForwardType* );
  void visit ( const cSpecializedForwardType* );
  void visit ( const cForwardType* );
  void visit ( const cInstantiatedForwardType* );
  void visit ( const cLabel* );
  void visit ( const cCaseLabel* );
  void visit ( const cDefaultLabel* );
  void visit ( const cFunctionInterface* );
  void visit ( const cTemplateFunction* );
  void visit ( const cSpecializedFunction* );
  void visit ( const cFunction* );
  void visit ( const cInstantiatedFunction* );
  void visit ( const cScope* );
  void visit ( const cGlobalScope* );
  void visit ( const cCompilationScope* );
  void visit ( const cNamespace* );
  void visit ( const cBlock* );
  void visit ( const cCtorInitializerBlock* );
  void visit ( const cTemplateParameter* );
  void visit ( const cTypeTemplateParameter* );
  void visit ( const cTemplateTemplateParameter* );
  void visit ( const cNonTypeTemplateParameter* );
  void visit ( const cTemplateParameterList* );
  void visit ( const cExpression* );
  void visit ( const cNameReference* );
  void visit ( const cLiteral* );
  void visit ( const cNewExpression* );
  void visit ( const cDeleteExpression* );
  void visit ( const cConditionDeclarator* );
  void visit ( const cEmptyExpression* );
  void visit ( const cExpressionList* );
  void visit ( const cFunctionArgumentList* );
  void visit ( const cInitializerList* );
  void visit ( const cOperator* );
  void visit ( const cUnaryOperator* );
  void visit ( const cBinaryOperator* );
  void visit ( const cTernaryOperator* );
  void visit ( const cControlStatement* );
  void visit ( const cSelectionStatement* );
  void visit ( const cIfStatement* );
  void visit ( const cSwitchStatement* );
  void visit ( const cIterationStatement* );
  void visit ( const cWhileLoop* );
  void visit ( const cDoWhileLoop* );
  void visit ( const cForLoop* );
  void visit ( const cJumpStatement* );
  void visit ( const cBreak* );
  void visit ( const cContinue* );
  void visit ( const cReturn* );
  void visit ( const cGoto* );
  void visit ( const cTryBlock* );
  void visit ( const cFunctionTryBlock* );
  void visit ( const cHandler* );
  void visit ( const cExceptionDeclaration* );
  void visit ( const cThrowExpression* );
  void visit ( const cExceptionSpecification* );

private:
  inline std::string bool2String ( bool b ) { return ( b ? "true" : "false" ); }

  std::string dotNodePrologue ( const char*, unsigned );
  std::string dotNodeEpilogue ( void );

  std::string dotBool ( const std::string&, bool );

  inline std::string dotIsArray          ( bool b ) { return dotBool( "array",       b ); }
  inline std::string dotIsBlock          ( bool b ) { return dotBool( "block",       b ); }
  inline std::string dotIsNamespace      ( bool b ) { return dotBool( "namespace",   b ); }
  inline std::string dotPseudoDestructor ( bool b ) { return dotBool( "pseudo dtor", b ); }

  std::string dotUnquotedString ( const std::string &, const std::string & );

  inline std::string dotName            ( const std::string& u ) { return dotUnquotedString( "name",   u ); }
  inline std::string dotAccessSpecifier ( const std::string& u ) { return dotUnquotedString( "access", u ); }
  inline std::string dotClassKey        ( const std::string& u ) { return dotUnquotedString( "key",    u ); }
  inline std::string dotFunctionKey     ( const std::string& u ) { return dotUnquotedString( "key",    u ); }
  inline std::string dotOperator        ( const std::string& u ) { return dotUnquotedString( "op",     u ); }

  std::string dotQuotedString ( const std::string&, std::string );

  inline std::string dotAsm     ( std::string s ) { return dotQuotedString( "asm",     s ); }
  inline std::string dotLinkage ( std::string s ) { return dotQuotedString( "linkage", s ); }
  inline std::string dotLiteral ( std::string s ) { return dotQuotedString( "value",   s ); }

  std::string dotNodeNumber ( const std::string&, const cAsgNode* );

  inline std::string dotDefinedIn    ( const cAsgNode* n ) { return dotNodeNumber( "defined in",    n ); }
  inline std::string dotOperatorType ( const cAsgNode* n ) { return dotNodeNumber( "operator type", n ); }

  std::string dotNameDeclaration ( const NameDeclaration* );

  std::string dotQualifier             ( bool, bool );
  std::string dotFunctionSpecifier     ( bool, bool, bool );
  std::string dotStorageClassSpecifier ( bool, bool, bool, bool, bool );

  void dotBaseClasses ( const cClassTypeInterface*, const BaseClassList_t& );

  template < class T >
  void dotAttribute ( const cAsgNode*, const T*, const std::string& aLabel = "" );

  template < class T >
  void dotAttributeVector ( const cAsgNode*, const std::vector<T*>&,
                            const std::string& aLabel = "" );

private:
  std::ofstream&    mFile;
  bool              mEdgeLabels;
  SchemaEnum2String mE2S;

  std::set<int> mSeen;
};

#endif
