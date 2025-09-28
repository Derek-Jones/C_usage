
include $(top_srcdir)/keystone.am

dist_pkginclude_HEADERS = \
  SchemaClasses.h \
  SchemaEnums.h \
  SchemaAliases.h \
  SchemaEnum2String.h \
  SchemaConstVisitor.h \
  SchemaNonConstVisitor.h \
  StandardLibrary.h \
  Schema.h

noinst_LTLIBRARIES = \
  libSchemaEnum2String.la \
  libStandardLibrary.la

libSchemaEnum2String_la_SOURCES = SchemaEnum2String.cpp SchemaEnum2String.h
libStandardLibrary_la_SOURCES   = StandardLibrary.cpp StandardLibrary.h

