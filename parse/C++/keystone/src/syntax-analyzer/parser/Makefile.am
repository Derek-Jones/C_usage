
include $(top_srcdir)/keystone.am

AM_YFLAGS = -dv
AM_LFLAGS =

noinst_LTLIBRARIES = \
  libIsoCpp.la \
  libActionFacade.la \
  libActions.la \
  libActionsHelp.la \
  libArgumentStack.la \
  libContextManager.la \
  libDeclarationStack.la \
  libKeywordManager.la \
  libLocationTracker.la \
  libLookupController.la \
  libNameOccurrence.la \
  libParser.la \
  libTokenBuffer.la \
  libTokenDecorator.la \
  libTokenInfo.la


libActionFacade_la_SOURCES     = ActionFacade.cpp ActionFacade.h
libActions_la_SOURCES          = Actions.cpp Actions.h
libActionsHelp_la_SOURCES      = ActionsHelp.cpp ActionsHelp.h
libArgumentStack_la_SOURCES    = ArgumentStack.cpp ArgumentStack.h
libContextManager_la_SOURCES   = ContextManager.cpp ContextManager.h
libDeclarationStack_la_SOURCES = DeclarationStack.cpp DeclarationStack.h
libKeywordManager_la_SOURCES   = KeywordManager.cpp KeywordManager.h
libLocationTracker_la_SOURCES  = LocationTracker.cpp LocationTracker.h
libLookupController_la_SOURCES = LookupController.cpp LookupController.h
libNameOccurrence_la_SOURCES   = NameOccurrence.cpp NameOccurrence.h
libParser_la_SOURCES           = Parser.cpp Parser.h
libTokenBuffer_la_SOURCES      = TokenBuffer.cpp TokenBuffer.h
libTokenDecorator_la_SOURCES   = TokenDecorator.cpp TokenDecorator.h
libTokenInfo_la_SOURCES        = TokenInfo.cpp TokenInfo.h

nodist_libIsoCpp_la_SOURCES = y.tab.cpp y.tab.h lex.yy.cpp

y.tab.cpp y.tab.h: IsoC++.y Nonterminals.y Terminals.y
	$(YACC) $(AM_YFLAGS) IsoC++.y
	@(echo "#include \"Ast.h\""; echo "#include \"ParserUtility.h\""; cat y_tab.h) > y.tab.h
	@sed -e 's/yylex()/Parser::Instance()->decorator()->getNextToken()/g' y_tab.c > y.tab.cpp
	$(RM) y_tab.[ch]

lex.yy.cpp: IsoC++.l y.tab.h
	$(LEX) $(AM_LFLAGS) IsoC++.l
	mv lex.yy.c lex.yy.cpp

BUILT_SOURCES = y.tab.cpp y.tab.h lex.yy.cpp

CLEANFILES = $(BUILT_SOURCES) y.output

EXTRA_DIST = IsoC++.l IsoC++.y BtYaccPosn.h Nonterminals.y Terminals.y ParserUtility.h

