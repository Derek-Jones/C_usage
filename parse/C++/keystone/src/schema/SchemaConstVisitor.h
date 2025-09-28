//******************************************************************************
//
//  SchemaConstVisitor.h
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

#ifndef _SCHEMA_CONST_VISITOR_H_
#define _SCHEMA_CONST_VISITOR_H_

class SchemaConstVisitor
{
public:
  virtual ~SchemaConstVisitor ( ) { }

  /* S.B       */ virtual void visit ( const cAsgNode*                   ) = 0;
  /* S.B.1     */ virtual void visit ( const cLinkage*                   ) = 0;
  /* S.B.2     */ virtual void visit ( const cUsing*                     ) = 0;
  /* S.B.3     */ virtual void visit ( const cAsmDefinition*             ) = 0;
  /* S.TA.L    */ virtual void visit ( const cTemplateArgumentList*      ) = 0;
  /* S.I       */ virtual void visit ( const cIdentifier*                ) = 0;
  /* S.I.1     */ virtual void visit ( const cEnumerator*                ) = 0;
  /* S.OBJ     */ virtual void visit ( const cObject*                    ) = 0;
  /* S.OBJ.L   */ virtual void visit ( const cObjectList*                ) = 0;
  /* S.FP      */ virtual void visit ( const cFunctionParameter*         ) = 0;
  /* S.FP.L    */ virtual void visit ( const cFunctionParameterList*     ) = 0;
  /* S.T       */ virtual void visit ( const cType*                      ) = 0;
  /* S.T.1     */ virtual void visit ( const cBuiltInType*               ) = 0;
  /* S.T.2     */ virtual void visit ( const cAliasType*                 ) = 0;
  /* S.T.3     */ virtual void visit ( const cFunctionType*              ) = 0;
  /* S.T.4     */ virtual void visit ( const cEnumerationType*           ) = 0;
  /* S.IT      */ virtual void visit ( const cIndirectType*              ) = 0;
  /* S.IT.1    */ virtual void visit ( const cArrayType*                 ) = 0;
  /* S.IT.2    */ virtual void visit ( const cPointerType*               ) = 0;
  /* S.IT.3    */ virtual void visit ( const cReferenceType*             ) = 0;
  /* I.CTI     */ virtual void visit ( const cClassTypeInterface*        ) = 0;
  /* S.CTI.1   */ virtual void visit ( const cTemplateClassType*         ) = 0;
  /* S.CTI.2   */ virtual void visit ( const cSpecializedClassType*      ) = 0;
  /* S.CTI.3   */ virtual void visit ( const cClassType*                 ) = 0;
  /* S.CTI.4   */ virtual void visit ( const cInstantiatedClassType*     ) = 0;
  /* I.FTI     */ virtual void visit ( const cForwardTypeInterface*      ) = 0;
  /* S.FTI.1   */ virtual void visit ( const cTemplateForwardType*       ) = 0;
  /* S.FTI.2   */ virtual void visit ( const cSpecializedForwardType*    ) = 0;
  /* S.FTI.3   */ virtual void visit ( const cForwardType*               ) = 0;
  /* S.FTI.4   */ virtual void visit ( const cInstantiatedForwardType*   ) = 0;
  /* S.L       */ virtual void visit ( const cLabel*                     ) = 0;
  /* S.L.1     */ virtual void visit ( const cCaseLabel*                 ) = 0;
  /* S.L.2     */ virtual void visit ( const cDefaultLabel*              ) = 0;
  /* S.FI      */ virtual void visit ( const cFunctionInterface*         ) = 0;
  /* S.FI.1    */ virtual void visit ( const cTemplateFunction*          ) = 0;
  /* S.FI.2    */ virtual void visit ( const cSpecializedFunction*       ) = 0;
  /* S.FI.3    */ virtual void visit ( const cFunction*                  ) = 0;
  /* S.FI.4    */ virtual void visit ( const cInstantiatedFunction*      ) = 0;
  /* S.S       */ virtual void visit ( const cScope*                     ) = 0;
  /* S.S.1     */ virtual void visit ( const cGlobalScope*               ) = 0;
  /* S.S.2     */ virtual void visit ( const cCompilationScope*          ) = 0;
  /* S.S.3     */ virtual void visit ( const cNamespace*                 ) = 0;
  /* S.BLK     */ virtual void visit ( const cBlock*                     ) = 0;
  /* S.BLK.1   */ virtual void visit ( const cCtorInitializerBlock*      ) = 0;
  /* S.TP      */ virtual void visit ( const cTemplateParameter*         ) = 0;
  /* S.TP.1    */ virtual void visit ( const cTypeTemplateParameter*     ) = 0;
  /* S.TP.2    */ virtual void visit ( const cTemplateTemplateParameter* ) = 0;
  /* S.TP.3    */ virtual void visit ( const cNonTypeTemplateParameter*  ) = 0;
  /* S.TP.L    */ virtual void visit ( const cTemplateParameterList*     ) = 0;
  /* S.EXP     */ virtual void visit ( const cExpression*                ) = 0;
  /* S.EXP.1   */ virtual void visit ( const cNameReference*             ) = 0;
  /* S.EXP.2   */ virtual void visit ( const cLiteral*                   ) = 0;
  /* S.EXP.3   */ virtual void visit ( const cNewExpression*             ) = 0;
  /* S.EXP.4   */ virtual void visit ( const cDeleteExpression*          ) = 0;
  /* S.EXP.5   */ virtual void visit ( const cConditionDeclarator*       ) = 0;
  /* S.EXP.6   */ virtual void visit ( const cEmptyExpression*           ) = 0;
  /* S.EXP.L   */ virtual void visit ( const cExpressionList*            ) = 0;
  /* S.EXP.L.1 */ virtual void visit ( const cFunctionArgumentList*      ) = 0;
  /* S.EXP.L.2 */ virtual void visit ( const cInitializerList*           ) = 0;
  /* S.O       */ virtual void visit ( const cOperator*                  ) = 0;
  /* S.O.1     */ virtual void visit ( const cUnaryOperator*             ) = 0;
  /* S.O.2     */ virtual void visit ( const cBinaryOperator*            ) = 0;
  /* S.O.2     */ virtual void visit ( const cTernaryOperator*           ) = 0;
  /* S.CS      */ virtual void visit ( const cControlStatement*          ) = 0;
  /* S.SS      */ virtual void visit ( const cSelectionStatement*        ) = 0;
  /* S.SS.1    */ virtual void visit ( const cIfStatement*               ) = 0;
  /* S.SS.2    */ virtual void visit ( const cSwitchStatement*           ) = 0;
  /* S.IS      */ virtual void visit ( const cIterationStatement*        ) = 0;
  /* S.IS.1    */ virtual void visit ( const cWhileLoop*                 ) = 0;
  /* S.IS.2    */ virtual void visit ( const cDoWhileLoop*               ) = 0;
  /* S.IS.3    */ virtual void visit ( const cForLoop*                   ) = 0;
  /* S.JS      */ virtual void visit ( const cJumpStatement*             ) = 0;
  /* S.JS.1    */ virtual void visit ( const cBreak*                     ) = 0;
  /* S.JS.2    */ virtual void visit ( const cContinue*                  ) = 0;
  /* S.JS.3    */ virtual void visit ( const cReturn*                    ) = 0;
  /* S.JS.4    */ virtual void visit ( const cGoto*                      ) = 0;
  /* S.EXC.1   */ virtual void visit ( const cTryBlock*                  ) = 0;
  /* S.EXC.2   */ virtual void visit ( const cFunctionTryBlock*          ) = 0;
  /* S.EXC.3   */ virtual void visit ( const cHandler*                   ) = 0;
  /* S.EXC.4   */ virtual void visit ( const cExceptionDeclaration*      ) = 0;
  /* S.EXC.5   */ virtual void visit ( const cThrowExpression*           ) = 0;
  /* S.EXC.6   */ virtual void visit ( const cExceptionSpecification*    ) = 0;
};

#endif
