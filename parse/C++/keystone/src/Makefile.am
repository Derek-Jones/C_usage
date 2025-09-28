
include $(top_srcdir)/keystone.am

SUBDIRS = schema syntax-analyzer asg

bin_PROGRAMS = key

key_SOURCES = \
  CommandLineOptions.cpp \
  asg.cpp \
  main.cpp

#lib_LTLIBRARIES = \
  #libkey.la

#libkey_a_LDFLAGS = -static

#libkey_la_SOURCES = \
  #libkey.cpp

#libkey_so_SOURCES = \
  #libkey.cpp

key_LDADD = \
  syntax-analyzer/ast/Ast.o \
  syntax-analyzer/parser/y.tab.o \
  syntax-analyzer/parser/lex.yy.o \
  syntax-analyzer/SyntaxAnalyzer.o \
  syntax-analyzer/parser/ContextManager.o \
  syntax-analyzer/parser/ActionFacade.o \
  syntax-analyzer/parser/TokenDecorator.o \
  syntax-analyzer/parser/DeclarationStack.o \
  syntax-analyzer/parser/Actions.o \
  syntax-analyzer/parser/LookupController.o \
  syntax-analyzer/parser/NameOccurrence.o \
  syntax-analyzer/parser/ActionsHelp.o \
  syntax-analyzer/parser/LocationTracker.o \
  syntax-analyzer/parser/TokenInfo.o \
  syntax-analyzer/parser/TokenBuffer.o \
  syntax-analyzer/parser/KeywordManager.o \
  syntax-analyzer/parser/ArgumentStack.o \
  syntax-analyzer/parser/Parser.o \
  syntax-analyzer/utility/Assertion.o \
  syntax-analyzer/symboltable/Kind.o \
  syntax-analyzer/symboltable/types/Type.o \
  syntax-analyzer/symboltable/types/EnumType.o \
  syntax-analyzer/symboltable/types/ClassType.o \
  syntax-analyzer/symboltable/types/IndirectType.o \
  syntax-analyzer/symboltable/types/NamespaceType.o \
  syntax-analyzer/symboltable/types/TemplateTemplateParameterType.o \
  syntax-analyzer/symboltable/types/FunctionType.o \
  syntax-analyzer/symboltable/types/TemplateParameterType.o \
  syntax-analyzer/symboltable/types/BasicType.o \
  syntax-analyzer/symboltable/validation/ScopeInvariantVisitor.o \
  syntax-analyzer/symboltable/validation/NameDeclarationInvariantVisitor.o \
  syntax-analyzer/symboltable/validation/NameDeclarationInvariantFacilitator.o \
  syntax-analyzer/symboltable/validation/TypeInvariantFacilitator.o \
  syntax-analyzer/symboltable/validation/ScopeInvariantFacilitator.o \
  syntax-analyzer/symboltable/validation/TypeInvariantVisitor.o \
  syntax-analyzer/symboltable/NameDeclaration.o \
  syntax-analyzer/symboltable/scopes/TemplateParameterScope.o \
  syntax-analyzer/symboltable/scopes/NamespaceScope.o \
  syntax-analyzer/symboltable/scopes/PrototypeScope.o \
  syntax-analyzer/symboltable/scopes/Scope.o \
  syntax-analyzer/symboltable/scopes/ClassScope.o \
  syntax-analyzer/symboltable/scopes/LocalScope.o \
  syntax-analyzer/symboltable/scopes/FunctionScope.o \
  syntax-analyzer/symboltable/Attribute.o \
  schema/SchemaEnum2String.o \
  schema/StandardLibrary.o \
  asg/Asg2DotVisitor.o \
  asg/Asg2SrcVisitor.o \
  asg/GlobalResolutionVisitor.o

#libkey_la_LIBADD = \
  #syntax-analyzer/ast/libAst.la \
  #syntax-analyzer/parser/libIsoCpp.la \
  #syntax-analyzer/libSyntaxAnalyzer.la \
  #syntax-analyzer/parser/libContextManager.la \
  #syntax-analyzer/parser/libActionFacade.la \
  #syntax-analyzer/parser/libTokenDecorator.la \
  #syntax-analyzer/parser/libDeclarationStack.la \
  #syntax-analyzer/parser/libActions.la \
  #syntax-analyzer/parser/libLookupController.la \
  #syntax-analyzer/parser/libNameOccurrence.la \
  #syntax-analyzer/parser/libActionsHelp.la \
  #syntax-analyzer/parser/libLocationTracker.la \
  #syntax-analyzer/parser/libTokenInfo.la \
  #syntax-analyzer/parser/libTokenBuffer.la \
  #syntax-analyzer/parser/libKeywordManager.la \
  #syntax-analyzer/parser/libArgumentStack.la \
  #syntax-analyzer/parser/libParser.la \
  #syntax-analyzer/utility/libAssertion.la \
  #syntax-analyzer/symboltable/libKind.la \
  #syntax-analyzer/symboltable/types/libType.la \
  #syntax-analyzer/symboltable/types/libEnumType.la \
  #syntax-analyzer/symboltable/types/libClassType.la \
  #syntax-analyzer/symboltable/types/libIndirectType.la \
  #syntax-analyzer/symboltable/types/libNamespaceType.la \
  #syntax-analyzer/symboltable/types/libTemplateTemplateParameterType.la \
  #syntax-analyzer/symboltable/types/libFunctionType.la \
  #syntax-analyzer/symboltable/types/libTemplateParameterType.la \
  #syntax-analyzer/symboltable/types/libBasicType.la \
  #syntax-analyzer/symboltable/validation/libScopeInvariantVisitor.la \
  #syntax-analyzer/symboltable/validation/libNameDeclarationInvariantVisitor.la \
  #syntax-analyzer/symboltable/validation/libNameDeclarationInvariantFacilitator.la \
  #syntax-analyzer/symboltable/validation/libTypeInvariantFacilitator.la \
  #syntax-analyzer/symboltable/validation/libScopeInvariantFacilitator.la \
  #syntax-analyzer/symboltable/validation/libTypeInvariantVisitor.la \
  #syntax-analyzer/symboltable/libNameDeclaration.la \
  #syntax-analyzer/symboltable/scopes/libTemplateParameterScope.la \
  #syntax-analyzer/symboltable/scopes/libNamespaceScope.la \
  #syntax-analyzer/symboltable/scopes/libPrototypeScope.la \
  #syntax-analyzer/symboltable/scopes/libScope.la \
  #syntax-analyzer/symboltable/scopes/libClassScope.la \
  #syntax-analyzer/symboltable/scopes/libLocalScope.la \
  #syntax-analyzer/symboltable/scopes/libFunctionScope.la \
  #syntax-analyzer/symboltable/libAttribute.la \
  #schema/libSchemaEnum2String.la \
  #schema/libStandardLibrary.la \
  #asg/libAsg2DotVisitor.la \
  #asg/libAsg2SrcVisitor.la \
  #asg/libGlobalResolutionVisitor.la

#libkey_so_LIBADD = \
  #syntax-analyzer/ast/Ast.lo \
  #syntax-analyzer/parser/y.tab.lo \
  #syntax-analyzer/parser/lex.yy.lo \
  #syntax-analyzer/SyntaxAnalyzer.lo \
  #syntax-analyzer/parser/ContextManager.lo \
  #syntax-analyzer/parser/ActionFacade.lo \
  #syntax-analyzer/parser/TokenDecorator.lo \
  #syntax-analyzer/parser/DeclarationStack.lo \
  #syntax-analyzer/parser/Actions.lo \
  #syntax-analyzer/parser/LookupController.lo \
  #syntax-analyzer/parser/NameOccurrence.lo \
  #syntax-analyzer/parser/ActionsHelp.lo \
  #syntax-analyzer/parser/LocationTracker.lo \
  #syntax-analyzer/parser/TokenInfo.lo \
  #syntax-analyzer/parser/TokenBuffer.lo \
  #syntax-analyzer/parser/KeywordManager.lo \
  #syntax-analyzer/parser/ArgumentStack.lo \
  #syntax-analyzer/parser/Parser.lo \
  #syntax-analyzer/utility/Assertion.lo \
  #syntax-analyzer/symboltable/Kind.lo \
  #syntax-analyzer/symboltable/types/Type.lo \
  #syntax-analyzer/symboltable/types/EnumType.lo \
  #syntax-analyzer/symboltable/types/ClassType.lo \
  #syntax-analyzer/symboltable/types/IndirectType.lo \
  #syntax-analyzer/symboltable/types/NamespaceType.lo \
  #syntax-analyzer/symboltable/types/TemplateTemplateParameterType.lo \
  #syntax-analyzer/symboltable/types/FunctionType.lo \
  #syntax-analyzer/symboltable/types/TemplateParameterType.lo \
  #syntax-analyzer/symboltable/types/BasicType.lo \
  #syntax-analyzer/symboltable/validation/ScopeInvariantVisitor.lo \
  #syntax-analyzer/symboltable/validation/NameDeclarationInvariantVisitor.lo \
  #syntax-analyzer/symboltable/validation/NameDeclarationInvariantFacilitator.lo \
  #syntax-analyzer/symboltable/validation/TypeInvariantFacilitator.lo \
  #syntax-analyzer/symboltable/validation/ScopeInvariantFacilitator.lo \
  #syntax-analyzer/symboltable/validation/TypeInvariantVisitor.lo \
  #syntax-analyzer/symboltable/NameDeclaration.lo \
  #syntax-analyzer/symboltable/scopes/TemplateParameterScope.lo \
  #syntax-analyzer/symboltable/scopes/NamespaceScope.lo \
  #syntax-analyzer/symboltable/scopes/PrototypeScope.lo \
  #syntax-analyzer/symboltable/scopes/Scope.lo \
  #syntax-analyzer/symboltable/scopes/ClassScope.lo \
  #syntax-analyzer/symboltable/scopes/LocalScope.lo \
  #syntax-analyzer/symboltable/scopes/FunctionScope.lo \
  #syntax-analyzer/symboltable/Attribute.lo \
  #schema/SchemaEnum2String.lo \
  #schema/StandardLibrary.lo \
  #asg/Asg2DotVisitor.lo \
  #asg/Asg2SrcVisitor.lo \
  #asg/GlobalResolutionVisitor.lo

EXTRA_DIST = CommandLineOptions.h Doxyfile

