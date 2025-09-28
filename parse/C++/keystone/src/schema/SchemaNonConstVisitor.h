//******************************************************************************
//
//  SchemaNonConstVisitor.h
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

#ifndef _SCHEMA_NON_CONST_VISITOR_H_
#define _SCHEMA_NON_CONST_VISITOR_H_

class SchemaNonConstVisitor
{
public:
  virtual ~SchemaNonConstVisitor ( ) { }

  /* S.B       */ virtual void visit ( cAsgNode*                   ) = 0;
  /* S.B.1     */ virtual void visit ( cLinkage*                   ) = 0;
  /* S.B.2     */ virtual void visit ( cUsing*                     ) = 0;
  /* S.B.3     */ virtual void visit ( cAsmDefinition*             ) = 0;
  /* S.TA.L    */ virtual void visit ( cTemplateArgumentList*      ) = 0;
  /* S.I       */ virtual void visit ( cIdentifier*                ) = 0;
  /* S.I.1     */ virtual void visit ( cEnumerator*                ) = 0;
  /* S.OBJ     */ virtual void visit ( cObject*                    ) = 0;
  /* S.OBJ.L   */ virtual void visit ( cObjectList*                ) = 0;
  /* S.FP      */ virtual void visit ( cFunctionParameter*         ) = 0;
  /* S.FP.L    */ virtual void visit ( cFunctionParameterList*     ) = 0;
  /* S.T       */ virtual void visit ( cType*                      ) = 0;
  /* S.T.1     */ virtual void visit ( cBuiltInType*               ) = 0;
  /* S.T.2     */ virtual void visit ( cAliasType*                 ) = 0;
  /* S.T.3     */ virtual void visit ( cFunctionType*              ) = 0;
  /* S.T.4     */ virtual void visit ( cEnumerationType*           ) = 0;
  /* S.IT      */ virtual void visit ( cIndirectType*              ) = 0;
  /* S.IT.1    */ virtual void visit ( cArrayType*                 ) = 0;
  /* S.IT.2    */ virtual void visit ( cPointerType*               ) = 0;
  /* S.IT.3    */ virtual void visit ( cReferenceType*             ) = 0;
  /* I.CTI     */ virtual void visit ( cClassTypeInterface*        ) = 0;
  /* S.CTI.1   */ virtual void visit ( cTemplateClassType*         ) = 0;
  /* S.CTI.2   */ virtual void visit ( cSpecializedClassType*      ) = 0;
  /* S.CTI.3   */ virtual void visit ( cClassType*                 ) = 0;
  /* S.CTI.4   */ virtual void visit ( cInstantiatedClassType*     ) = 0;
  /* I.FTI     */ virtual void visit ( cForwardTypeInterface*      ) = 0;
  /* S.FTI.1   */ virtual void visit ( cTemplateForwardType*       ) = 0;
  /* S.FTI.2   */ virtual void visit ( cSpecializedForwardType*    ) = 0;
  /* S.FTI.3   */ virtual void visit ( cForwardType*               ) = 0;
  /* S.FTI.4   */ virtual void visit ( cInstantiatedForwardType*   ) = 0;
  /* S.L       */ virtual void visit ( cLabel*                     ) = 0;
  /* S.L.1     */ virtual void visit ( cCaseLabel*                 ) = 0;
  /* S.L.2     */ virtual void visit ( cDefaultLabel*              ) = 0;
  /* S.FI      */ virtual void visit ( cFunctionInterface*         ) = 0;
  /* S.FI.1    */ virtual void visit ( cTemplateFunction*          ) = 0;
  /* S.FI.2    */ virtual void visit ( cSpecializedFunction*       ) = 0;
  /* S.FI.3    */ virtual void visit ( cFunction*                  ) = 0;
  /* S.FI.4    */ virtual void visit ( cInstantiatedFunction*      ) = 0;
  /* S.S       */ virtual void visit ( cScope*                     ) = 0;
  /* S.S.1     */ virtual void visit ( cGlobalScope*               ) = 0;
  /* S.S.2     */ virtual void visit ( cCompilationScope*          ) = 0;
  /* S.S.3     */ virtual void visit ( cNamespace*                 ) = 0;
  /* S.BLK     */ virtual void visit ( cBlock*                     ) = 0;
  /* S.BLK.1   */ virtual void visit ( cCtorInitializerBlock*      ) = 0;
  /* S.TP      */ virtual void visit ( cTemplateParameter*         ) = 0;
  /* S.TP.1    */ virtual void visit ( cTypeTemplateParameter*     ) = 0;
  /* S.TP.2    */ virtual void visit ( cTemplateTemplateParameter* ) = 0;
  /* S.TP.3    */ virtual void visit ( cNonTypeTemplateParameter*  ) = 0;
  /* S.TP.L    */ virtual void visit ( cTemplateParameterList*     ) = 0;
  /* S.EXP     */ virtual void visit ( cExpression*                ) = 0;
  /* S.EXP.1   */ virtual void visit ( cNameReference*             ) = 0;
  /* S.EXP.2   */ virtual void visit ( cLiteral*                   ) = 0;
  /* S.EXP.3   */ virtual void visit ( cNewExpression*             ) = 0;
  /* S.EXP.4   */ virtual void visit ( cDeleteExpression*          ) = 0;
  /* S.EXP.5   */ virtual void visit ( cConditionDeclarator*       ) = 0;
  /* S.EXP.6   */ virtual void visit ( cEmptyExpression*           ) = 0;
  /* S.EXP.L   */ virtual void visit ( cExpressionList*            ) = 0;
  /* S.EXP.L.1 */ virtual void visit ( cFunctionArgumentList*      ) = 0;
  /* S.EXP.L.2 */ virtual void visit ( cInitializerList*           ) = 0;
  /* S.O       */ virtual void visit ( cOperator*                  ) = 0;
  /* S.O.1     */ virtual void visit ( cUnaryOperator*             ) = 0;
  /* S.O.2     */ virtual void visit ( cBinaryOperator*            ) = 0;
  /* S.O.2     */ virtual void visit ( cTernaryOperator*           ) = 0;
  /* S.CS      */ virtual void visit ( cControlStatement*          ) = 0;
  /* S.SS      */ virtual void visit ( cSelectionStatement*        ) = 0;
  /* S.SS.1    */ virtual void visit ( cIfStatement*               ) = 0;
  /* S.SS.2    */ virtual void visit ( cSwitchStatement*           ) = 0;
  /* S.IS      */ virtual void visit ( cIterationStatement*        ) = 0;
  /* S.IS.1    */ virtual void visit ( cWhileLoop*                 ) = 0;
  /* S.IS.2    */ virtual void visit ( cDoWhileLoop*               ) = 0;
  /* S.IS.3    */ virtual void visit ( cForLoop*                   ) = 0;
  /* S.JS      */ virtual void visit ( cJumpStatement*             ) = 0;
  /* S.JS.1    */ virtual void visit ( cBreak*                     ) = 0;
  /* S.JS.2    */ virtual void visit ( cContinue*                  ) = 0;
  /* S.JS.3    */ virtual void visit ( cReturn*                    ) = 0;
  /* S.JS.4    */ virtual void visit ( cGoto*                      ) = 0;
  /* S.EXC.1   */ virtual void visit ( cTryBlock*                  ) = 0;
  /* S.EXC.2   */ virtual void visit ( cFunctionTryBlock*          ) = 0;
  /* S.EXC.3   */ virtual void visit ( cHandler*                   ) = 0;
  /* S.EXC.4   */ virtual void visit ( cExceptionDeclaration*      ) = 0;
  /* S.EXC.5   */ virtual void visit ( cThrowExpression*           ) = 0;
  /* S.EXC.6   */ virtual void visit ( cExceptionSpecification*    ) = 0;

};

#endif
