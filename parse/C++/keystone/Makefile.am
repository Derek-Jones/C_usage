
SUBDIRS = src files

EXTRA_DIST = \
  AUTHORS \
  COPYING \
  ChangeLog \
  INSTALL \
  Makefile.cvs \
  NEWS \
  README \
  acinclude.m4 \
  aminclude.am \
  doxygen.am \
  keystone.am

CLEANFILES = $(shell find . -regex ".*\.gcno" -o -regex ".*\.gcda" -o -regex ".*\.gcov")

include $(top_srcdir)/doxygen.am

