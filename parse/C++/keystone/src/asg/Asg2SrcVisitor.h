//******************************************************************************
//
//  Asg2SrcVisitor.h
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

#ifndef _ASG_2_SRC_VISITOR_H_
#define _ASG_2_SRC_VISITOR_H_

#include <set>
#include <stack>

enum eAccessSpecifier;

class Asg2SrcVisitor : public SchemaConstVisitor
{
public:
  Asg2SrcVisitor ( );

  void visit ( const cAsgNode * );
  void visit ( const cLinkage * );
  void visit ( const cUsing * );
  void visit ( const cAsmDefinition * );
  void visit ( const cTemplateArgumentList * );
  void visit ( const cIdentifier * );
  void visit ( const cEnumerator * );
  void visit ( const cObject * );
  void visit ( const cObjectList * );
  void visit ( const cFunctionParameter * );
  void visit ( const cFunctionParameterList * );
  void visit ( const cType * );
  void visit ( const cBuiltInType * );
  void visit ( const cAliasType * );
  void visit ( const cFunctionType * );
  void visit ( const cEnumerationType * );
  void visit ( const cIndirectType * );
  void visit ( const cArrayType * );
  void visit ( const cPointerType * );
  void visit ( const cReferenceType * );
  void visit ( const cClassTypeInterface * );
  void visit ( const cTemplateClassType * );
  void visit ( const cSpecializedClassType * );
  void visit ( const cClassType * );
  void visit ( const cInstantiatedClassType * );
  void visit ( const cForwardTypeInterface * );
  void visit ( const cTemplateForwardType * );
  void visit ( const cSpecializedForwardType * );
  void visit ( const cForwardType * );
  void visit ( const cInstantiatedForwardType * );
  void visit ( const cLabel * );
  void visit ( const cCaseLabel * );
  void visit ( const cDefaultLabel * );
  void visit ( const cFunctionInterface * );
  void visit ( const cTemplateFunction * );
  void visit ( const cSpecializedFunction * );
  void visit ( const cFunction * );
  void visit ( const cInstantiatedFunction * );
  void visit ( const cScope * );
  void visit ( const cGlobalScope * );
  void visit ( const cCompilationScope * );
  void visit ( const cNamespace * );
  void visit ( const cBlock * );
  void visit ( const cCtorInitializerBlock * );
  void visit ( const cTemplateParameter * );
  void visit ( const cTypeTemplateParameter * );
  void visit ( const cTemplateTemplateParameter * );
  void visit ( const cNonTypeTemplateParameter * );
  void visit ( const cTemplateParameterList * );
  void visit ( const cExpression * );
  void visit ( const cNameReference * );
  void visit ( const cLiteral * );
  void visit ( const cNewExpression * );
  void visit ( const cDeleteExpression * );
  void visit ( const cConditionDeclarator * );
  void visit ( const cEmptyExpression * );
  void visit ( const cExpressionList * );
  void visit ( const cFunctionArgumentList * );
  void visit ( const cInitializerList * );
  void visit ( const cOperator * );
  void visit ( const cUnaryOperator * );
  void visit ( const cBinaryOperator * );
  void visit ( const cTernaryOperator * );
  void visit ( const cControlStatement * );
  void visit ( const cSelectionStatement * );
  void visit ( const cIfStatement * );
  void visit ( const cSwitchStatement * );
  void visit ( const cIterationStatement * );
  void visit ( const cWhileLoop * );
  void visit ( const cDoWhileLoop * );
  void visit ( const cForLoop * );
  void visit ( const cJumpStatement * );
  void visit ( const cBreak * );
  void visit ( const cContinue * );
  void visit ( const cReturn * );
  void visit ( const cGoto * );
  void visit ( const cTryBlock * );
  void visit ( const cFunctionTryBlock * );
  void visit ( const cHandler * );
  void visit ( const cExceptionDeclaration * );
  void visit ( const cThrowExpression * );
  void visit ( const cExceptionSpecification * );

public:
  struct Indent
  {
    Indent ( ) : mI( 0 ) { }
    operator unsigned& ( ) { return mI; }

  private:
    unsigned mI;
  };

private:
  // method

private:
  Indent mIndent;

  std::set<std::string>        mInclude;
  std::stack<eAccessSpecifier> mAccess;
};

inline
std::ostream&
operator<< ( std::ostream& o, Asg2SrcVisitor::Indent aIndent )
{
  for ( unsigned i = 0; i < aIndent; ++i ) { o << ' '; }
  return o;
}

#endif

