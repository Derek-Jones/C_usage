
include $(top_srcdir)/keystone.am

SUBDIRS = scopes types validation

noinst_LTLIBRARIES = \
  libAttribute.la \
  libKind.la \
  libNameDeclaration.la


libAttribute_la_SOURCES = Attribute.cpp Attribute.h
libKind_la_SOURCES = Kind.cpp Kind.h
libNameDeclaration_la_SOURCES = NameDeclaration.cpp NameDeclaration.h


EXTRA_DIST = Access.h


