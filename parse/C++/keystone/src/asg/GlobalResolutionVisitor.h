//******************************************************************************
//
//  GlobalResolutionVisitor.h
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

#ifndef _GLOBAL_RESOLUTION_VISITOR_H_
#define _GLOBAL_RESOLUTION_VISITOR_H_

#include "SchemaNonConstVisitor.h"

class GlobalResolutionVisitor : public SchemaNonConstVisitor
{
public:
  GlobalResolutionVisitor ( cGlobalScope* );

  void visit ( cAsgNode* );
  void visit ( cLinkage* );
  void visit ( cUsing* );
  void visit ( cAsmDefinition* );
  void visit ( cTemplateArgumentList* );
  void visit ( cIdentifier* );
  void visit ( cEnumerator* );
  void visit ( cObject* );
  void visit ( cObjectList* );
  void visit ( cFunctionParameter* );
  void visit ( cFunctionParameterList* );
  void visit ( cType* );
  void visit ( cBuiltInType* );
  void visit ( cAliasType* );
  void visit ( cFunctionType* );
  void visit ( cEnumerationType* );
  void visit ( cIndirectType* );
  void visit ( cArrayType* );
  void visit ( cPointerType* );
  void visit ( cReferenceType* );
  void visit ( cClassTypeInterface* );
  void visit ( cTemplateClassType* );
  void visit ( cSpecializedClassType* );
  void visit ( cClassType* );
  void visit ( cInstantiatedClassType* );
  void visit ( cForwardTypeInterface* );
  void visit ( cTemplateForwardType* );
  void visit ( cSpecializedForwardType* );
  void visit ( cForwardType* );
  void visit ( cInstantiatedForwardType* );
  void visit ( cLabel* );
  void visit ( cCaseLabel* );
  void visit ( cDefaultLabel* );
  void visit ( cFunctionInterface* );
  void visit ( cTemplateFunction* );
  void visit ( cSpecializedFunction* );
  void visit ( cFunction* );
  void visit ( cInstantiatedFunction* );
  void visit ( cScope* );
  void visit ( cGlobalScope* );
  void visit ( cCompilationScope* );
  void visit ( cNamespace* );
  void visit ( cBlock* );
  void visit ( cCtorInitializerBlock* );
  void visit ( cTemplateParameter* );
  void visit ( cTypeTemplateParameter* );
  void visit ( cTemplateTemplateParameter* );
  void visit ( cNonTypeTemplateParameter* );
  void visit ( cTemplateParameterList* );
  void visit ( cExpression* );
  void visit ( cNameReference* );
  void visit ( cLiteral* );
  void visit ( cNewExpression* );
  void visit ( cDeleteExpression* );
  void visit ( cConditionDeclarator* );
  void visit ( cEmptyExpression* );
  void visit ( cExpressionList* );
  void visit ( cFunctionArgumentList* );
  void visit ( cInitializerList* );
  void visit ( cOperator* );
  void visit ( cUnaryOperator* );
  void visit ( cBinaryOperator* );
  void visit ( cTernaryOperator* );
  void visit ( cControlStatement* );
  void visit ( cSelectionStatement* );
  void visit ( cIfStatement* );
  void visit ( cSwitchStatement* );
  void visit ( cIterationStatement* );
  void visit ( cWhileLoop* );
  void visit ( cDoWhileLoop* );
  void visit ( cForLoop* );
  void visit ( cJumpStatement* );
  void visit ( cBreak* );
  void visit ( cContinue* );
  void visit ( cReturn* );
  void visit ( cGoto* );
  void visit ( cTryBlock* );
  void visit ( cFunctionTryBlock* );
  void visit ( cHandler* );
  void visit ( cExceptionDeclaration* );
  void visit ( cThrowExpression* );
  void visit ( cExceptionSpecification* );

private:

  struct GlobalResolver
  {
    GlobalResolver ( GlobalResolutionVisitor*, cGlobalScope* );

    void operator() ( cType**           );
    void operator() ( cExpressionBase** );
    void operator() ( cExpression**     );

  private:
    template < class NodeType >
    NodeType* makeGlobal ( NodeType*, bool (NodeType::*)( NodeType* ) );

  private:
    GlobalResolutionVisitor* mParent;
    cGlobalScope*            mGlobal;
  };

private:
  cGlobalScope*  mGlobal;
  GlobalResolver mResolver;
};

#endif
