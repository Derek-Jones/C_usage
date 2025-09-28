
include $(top_srcdir)/keystone.am

SUBDIRS = ast parser symboltable utility

noinst_LTLIBRARIES = \
  libSyntaxAnalyzer.la

libSyntaxAnalyzer_la_SOURCES = SyntaxAnalyzer.cpp SyntaxAnalyzer.h

AM_CPPFLAGS += \
  -DKEY_CPP="\"$(CXXCPP) -w -undef -D__KEY__ -D'__attribute__(...)=' -D'__builtin_va_list=void' -D'__const=const' -D'__extension__=' -D'__restrict=' -I$(pkgincludedir)/stubs\""


#-DKEY_CPP="\"$(CXXCPP) -w -undef -D__KEY__ -D'__attribute__(...)=' -D'__builtin_va_list=void' -D'__const=const' -D'__extension__=' -D'__restrict=' -I/home/nkraft/sgi\""

#-DKEY_CPP="\"$(CXXCPP) -w -I$(pkgincludedir)/stubs\""
