
include $(top_srcdir)/keystone.am

dist_pkgdata_DATA = \
  Ast.tc

noinst_LTLIBRARIES = \
  libAst.la

nodist_libAst_la_SOURCES = Ast.cpp Ast.h

Ast.cpp Ast.h: Ast.tc ParserOperations.tc TypeOperations.tc ExpressionOperations.tc ApplyPreorder.tc
	$(TREECC) Ast.tc

BUILT_SOURCES = Ast.cpp Ast.h

CLEANFILES = $(BUILT_SOURCES)

EXTRA_DIST = Ast.tc ParserOperations.tc TypeOperations.tc ExpressionOperations.tc ApplyPreorder.tc

