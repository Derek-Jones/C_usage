
include $(top_srcdir)/keystone.am

nodist_pkginclude_HEADERS =

noinst_LTLIBRARIES = \
  libAsg2DotVisitor.la \
  libAsg2SrcVisitor.la \
  libGlobalResolutionVisitor.la

libAsg2DotVisitor_la_SOURCES = Asg2DotVisitor.cpp Asg2DotVisitor.h
libAsg2SrcVisitor_la_SOURCES = Asg2SrcVisitor.cpp Asg2SrcVisitor.h
libGlobalResolutionVisitor_la_SOURCES = GlobalResolutionVisitor.cpp GlobalResolutionVisitor.h

EXTRA_DIST = VisitorHelp.h

