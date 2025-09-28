//******************************************************************************
//
//  SchemaClasses.h
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

#ifndef _SCHEMA_CLASSES_H_
#define _SCHEMA_CLASSES_H_

/* S.B       */ class cAsgNode;
/* S.B.1     */ class cLinkage;
/* S.B.2     */ class cUsing;
/* S.B.3     */ class cAsmDefinition;
/* S.TA.L    */ class cTemplateArgumentList;
/* S.I       */ class cIdentifier;
/* S.I.1     */ class cEnumerator;
/* S.OBJ     */ class cObject;
/* S.OBJ.L   */ class cObjectList;
/* S.FP.B    */ class cFunctionParameterBase;
/* S.FP      */ class cFunctionParameter;
/* S.FP.L    */ class cFunctionParameterList;
/* S.T       */ class cType;
/* S.T.1     */ class cBuiltInType;
/* S.T.2     */ class cAliasType;
/* S.T.3     */ class cFunctionType;
/* S.T.4     */ class cEnumerationType;
/* S.IT      */ class cIndirectType;
/* S.IT.1    */ class cArrayType;
/* S.IT.2    */ class cPointerType;
/* S.IT.3    */ class cReferenceType;
/* I.CTI     */ class cClassTypeInterface;
/* S.CTI.1   */ class cTemplateClassType;
/* S.CTI.2   */ class cSpecializedClassType;
/* S.CTI.3   */ class cClassType;
/* S.CTI.4   */ class cInstantiatedClassType;
/* I.FTI     */ class cForwardTypeInterface;
/* S.FTI.1   */ class cTemplateForwardType;
/* S.FTI.2   */ class cSpecializedForwardType;
/* S.FTI.3   */ class cForwardType;
/* S.FTI.4   */ class cInstantiatedForwardType;
/* S.L       */ class cLabel;
/* S.L.1     */ class cCaseLabel;
/* S.L.2     */ class cDefaultLabel;
/* S.FI      */ class cFunctionInterface;
/* S.FI.1    */ class cTemplateFunction;
/* S.FI.2    */ class cSpecializedFunction;
/* S.FI.3    */ class cFunction;
/* S.FI.4    */ class cInstantiatedFunction;
/* S.S       */ class cScope;
/* S.S.1     */ class cGlobalScope;
/* S.S.2     */ class cCompilationScope;
/* S.S.3     */ class cNamespace;
/* S.BLK     */ class cBlock;
/* S.BLK.1   */ class cCtorInitializerBlock;
/* S.TP.B    */ class cTemplateParameterBase;
/* S.TP      */ class cTemplateParameter;
/* S.TP.1    */ class cTypeTemplateParameter;
/* S.TP.2    */ class cTemplateTemplateParameter;
/* S.TP.3    */ class cNonTypeTemplateParameter;
/* S.TP.L    */ class cTemplateParameterList;
/* S.EXP.B   */ class cExpressionBase;
/* S.EXP     */ class cExpression;
/* S.EXP.1   */ class cNameReference;
/* S.EXP.2   */ class cLiteral;
/* S.EXP.3   */ class cNewExpression;
/* S.EXP.4   */ class cDeleteExpression;
/* S.EXP.5   */ class cConditionDeclarator;
/* S.EXP.6   */ class cEmptyExpression;
/* S.EXP.L   */ class cExpressionList;
/* S.EXP.L.1 */ class cFunctionArgumentList;
/* S.EXP.L.2 */ class cInitializerList;
/* S.O       */ class cOperator;
/* S.O.1     */ class cUnaryOperator;
/* S.O.2     */ class cBinaryOperator;
/* S.O.2     */ class cTernaryOperator;
/* S.CS      */ class cControlStatement;
/* S.SS      */ class cSelectionStatement;
/* S.SS.1    */ class cIfStatement;
/* S.SS.2    */ class cSwitchStatement;
/* S.IS      */ class cIterationStatement;
/* S.IS.1    */ class cWhileLoop;
/* S.IS.2    */ class cDoWhileLoop;
/* S.IS.3    */ class cForLoop;
/* S.JS      */ class cJumpStatement;
/* S.JS.1    */ class cBreak;
/* S.JS.2    */ class cContinue;
/* S.JS.3    */ class cReturn;
/* S.JS.4    */ class cGoto;
/* S.EXC.1   */ class cTryBlock;
/* S.EXC.2   */ class cFunctionTryBlock;
/* S.EXC.3   */ class cHandler;
/* S.EXC.4   */ class cExceptionDeclaration;
/* S.EXC.5   */ class cThrowExpression;
/* S.EXC.6   */ class cExceptionSpecification;

#endif
