#
# Boilerplate
#
AC_INIT([keystone], [0.2.3], keystone@cs.clemson.edu)
AC_PREREQ([2.57])
AC_CONFIG_AUX_DIR(config)

AM_INIT_AUTOMAKE(dist-bzip2)
AM_CONFIG_HEADER(config.h)


#
# Programs
#

# Turn off shared libraries during beta-testing, since they
# make the build process take too long.
AC_DISABLE_SHARED
AC_DISABLE_STATIC
AC_PROG_LIBTOOL

AC_PROG_CXX
AC_PROG_CXXCPP
AC_CHECK_HEADERS([getopt.h])
AC_CHECK_FUNCS([getopt_long],,[AC_MSG_ERROR([getopt_long is required])])

AC_LANG_CPLUSPLUS

if test "x$GXX" = "xyes"; then
  KEY_CXXFLAGS="-pipe -W -Wall -Wno-long-long -Wno-switch -Wno-unused-parameter -Wno-unused-variable"
  #KEY_CXXFLAGS="-O0 -c -fdump-translation-unit-all"
else
  AC_MSG_ERROR([gcc is required.])
fi
AC_SUBST(KEY_CXXFLAGS)

AM_PROG_LEX

AC_PATH_PROG(YACC, btyacc)
if test "x$YACC" = "x"; then
  AC_MSG_ERROR([Please make sure that 'btyacc' is in your path.])
fi

AC_PATH_PROG(TREECC, treecc)
if test "x$TREECC" = "x"; then
  AC_MSG_ERROR([Please make sure that 'treecc' is in your path.])
fi

#
# Documentation
#
DX_HTML_FEATURE(OFF)
DX_CHM_FEATURE(OFF)
DX_CHI_FEATURE(OFF)
DX_MAN_FEATURE(OFF)
DX_RTF_FEATURE(OFF)
DX_XML_FEATURE(OFF)
DX_PDF_FEATURE(OFF)
DX_PS_FEATURE(OFF)
DX_INIT_DOXYGEN(keystone, src/Doxyfile, doc)


#
# Keystone Options
#
AC_ARG_ENABLE([debug],
              [AC_HELP_STRING([--disable-debug], [compile without debugging])],
              [enable_debug=$enableval], [enable_debug=yes])

AC_ARG_ENABLE([optimization],
              [AC_HELP_STRING([--disable-optimization], [compile without optimization])],
              [enable_optimization=$enableval], [enable_optimization=yes])

AC_ARG_ENABLE([coverage],
              [AC_HELP_STRING([--enable-coverage], [compile for use with gcov])],
              [enable_coverage=$enableval], [enable_coverage=no])

AC_ARG_ENABLE([profiling],
              [AC_HELP_STRING([--enable-profiling], [compile with profiling])],
              [enable_profiling=$enableval], [enable_profiling=no])

# shouldn't do this, but...
CXXFLAGS=""

if test "x$enable_debug" = "xyes"; then
  CXXFLAGS="$CXXFLAGS -g"
fi

if test "x$enable_optimization" = "xyes"; then
  CXXFLAGS="$CXXFLAGS -O2"
fi

if test "x$enable_coverage" = "xyes"; then
  CXXFLAGS="-ftest-coverage -fprofile-arcs"
fi

if test "x$enable_profiling" = "xyes"; then
  CXXFLAGS="$CXXFLAGS -pg"
fi

AC_DEFUN([KEY_ARG_ENABLE],
         [ AC_MSG_CHECKING(whether to enable $4)
           AC_ARG_ENABLE([$1],
                          [AC_HELP_STRING([--enable-$1], [turn on $4 (default=$2)])],
                          [
                            if test "x$enableval" = "xyes"; then
                              AC_MSG_RESULT(yes)
                              AC_DEFINE([$3], [1], [$4])
                            else
                              AC_MSG_RESULT(no)
                            fi
                          ],
                          [ AC_MSG_RESULT(no) ])])

# Preprocessor defines
KEY_ARG_ENABLE(yacc-debug,          no, KEY_YACC_DEBUG,          btyacc debugging output)
KEY_ARG_ENABLE(action-debug,        no, KEY_ACTION_DEBUG,        action debugging output)
KEY_ARG_ENABLE(parser-sentry,       no, KEY_P_SENTRY,            parser sentry output)
KEY_ARG_ENABLE(symbol-table-sentry, no, KEY_ST_SENTRY,           symbol table sentry output)
KEY_ARG_ENABLE(class-based-testing, no, KEY_CLASS_BASED_TESTING, ClassBasedTest.cpp)


#
# Output
#
AC_OUTPUT(\
  Makefile \
  files/Makefile \
  files/scripts/Makefile \
  files/include/Makefile \
  src/Makefile \
  src/schema/Makefile \
  src/syntax-analyzer/Makefile \
  src/syntax-analyzer/ast/Makefile \
  src/syntax-analyzer/parser/Makefile \
  src/syntax-analyzer/symboltable/Makefile \
  src/syntax-analyzer/symboltable/scopes/Makefile \
  src/syntax-analyzer/symboltable/types/Makefile \
  src/syntax-analyzer/symboltable/validation/Makefile \
  src/syntax-analyzer/utility/Makefile \
  src/asg/Makefile)


#
# User Messages
#




