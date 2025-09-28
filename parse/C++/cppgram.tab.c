/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison GLR parsers in C

   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0






/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _BOOL = 258,
     _COMPLEX = 259,
     _IMAGINARY = 260,
     AUTO = 261,
     STATIC = 262,
     EXTERN = 263,
     REGISTER = 264,
     TYPEDEF = 265,
     CHAR = 266,
     FLOAT = 267,
     DOUBLE = 268,
     INT = 269,
     SHORT = 270,
     LONG = 271,
     UNSIGNED = 272,
     SIGNED = 273,
     VOID = 274,
     CONST = 275,
     VOLATILE = 276,
     STRUCT = 277,
     UNION = 278,
     ENUM = 279,
     IF = 280,
     ELSE = 281,
     WHILE = 282,
     FOR = 283,
     DO = 284,
     SWITCH = 285,
     CASE = 286,
     DEFAULT = 287,
     BREAK = 288,
     CONTINUE = 289,
     RETURN = 290,
     GOTO = 291,
     SIZEOF = 292,
     OPEN_RND = 293,
     CLOSE_RND = 294,
     LEFTSHIFT = 295,
     RIGHTSHIFT = 296,
     PLUS = 297,
     ADD = 298,
     NEGATE = 299,
     MINUS = 300,
     STAR = 301,
     TIMES = 302,
     REMAINDER = 303,
     DIVIDE = 304,
     XOR = 305,
     AND = 306,
     BITAND = 307,
     OR = 308,
     BITNEGATE = 309,
     NOT = 310,
     LT = 311,
     LE = 312,
     GE = 313,
     GT = 314,
     EQUAL = 315,
     NOTEQUAL = 316,
     ANDTEST = 317,
     ORTEST = 318,
     QUESTION = 319,
     DUMMY1 = 320,
     DOT = 321,
     DEREF = 322,
     PLUSPLUS = 323,
     MINUSMINUS = 324,
     POSTPLUSPLUS = 325,
     POSTMINUSMINUS = 326,
     COMMA = 327,
     SEMICOLON = 328,
     ELLIPSIS = 329,
     OPEN_CURL = 330,
     CLOSE_CURL = 331,
     OPEN_SQUARE = 332,
     CLOSE_SQUARE = 333,
     ASSIGN = 334,
     PLUSASSIGN = 335,
     MINUSASSIGN = 336,
     TIMESASSIGN = 337,
     LSASSIGN = 338,
     RSASSIGN = 339,
     ANDASSIGN = 340,
     DIVASSIGN = 341,
     REMASSIGN = 342,
     ORASSIGN = 343,
     XORASSIGN = 344,
     COLON = 345,
     DUMMY2 = 346,
     CONSTANT = 347,
     IDENTIFIER = 348,
     STRING_LITERAL = 349,
     TYPEDEFNAME = 350,
     INLINE = 351,
     RESTRICT = 352,
     ASM = 353,
     CATCH = 354,
     CLASS = 355,
     COLONCOLON = 356,
     CONST_CAST = 357,
     DELETE = 358,
     DEREFSTAR = 359,
     DOTSTAR = 360,
     DYNAMIC_CAST = 361,
     EXPLICIT = 362,
     EXPORT = 363,
     FRIEND = 364,
     MUTABLE = 365,
     NAMESPACE = 366,
     NEW = 367,
     OPERATOR = 368,
     PRIVATE = 369,
     PROTECTED = 370,
     PUBLIC = 371,
     REINTERPRET_CAST = 372,
     STATIC_CAST = 373,
     TEMPLATE = 374,
     THIS = 375,
     THROW = 376,
     TRY = 377,
     TYPEID = 378,
     TYPENAME = 379,
     USING = 380,
     VIRTUAL = 381,
     WCHAR_T = 382,
     UNDEFINED = 383
   };
#endif


/* Copy the first part of user declarations.  */


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{

  char yydummy;

} YYLTYPE;
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template,
   here we set the default value of $$ to a zeroed-out value.
   Since the default value is undefined, this behavior is
   technically correct.  */
static YYSTYPE yyval_default;

/* Copy the second part of user declarations.  */


/* Line 234 of glr.c.  */
#line 244 "cppgram.tab.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#define YYSIZEMAX ((size_t) -1)

#ifdef __cplusplus
   typedef bool yybool;
#else
   typedef unsigned char yybool;
#endif
#define yytrue 1
#define yyfalse 0

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(env) setjmp (env)
# define YYLONGJMP(env, val) longjmp (env, val)
#endif

/*-----------------.
| GCC extensions.  |
`-----------------*/

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5) || __STRICT_ANSI__)
#  define __attribute__(Spec) /* empty */
# endif
#endif


#ifdef __cplusplus
# define YYOPTIONAL_LOC(Name) /* empty */
#else
# define YYOPTIONAL_LOC(Name) Name __attribute__ ((__unused__))
#endif

#ifndef YYASSERT
# define YYASSERT(condition) ((void) ((condition) || (abort (), 0)))
#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  236
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4094

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  129
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  164
/* YYNRULES -- Number of rules.  */
#define YYNRULES  428
/* YYNRULES -- Number of states.  */
#define YYNSTATES  706
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 7
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   383

#define YYTRANSLATE(YYX)						\
  ((YYX <= 0) ? YYEOF :							\
   (unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    19,
      21,    24,    25,    27,    29,    31,    33,    35,    37,    39,
      42,    46,    48,    51,    54,    57,    59,    61,    62,    64,
      66,    70,    75,    76,    78,    80,    85,    90,    93,    96,
     103,   111,   116,   121,   126,   131,   135,   139,   147,   155,
     163,   171,   176,   181,   183,   187,   191,   197,   200,   202,
     205,   208,   211,   214,   219,   221,   223,   225,   227,   229,
     231,   233,   235,   241,   249,   253,   254,   256,   259,   262,
     264,   265,   267,   271,   276,   280,   281,   283,   287,   293,
     295,   300,   302,   306,   310,   312,   316,   320,   324,   326,
     330,   334,   336,   340,   344,   346,   350,   354,   358,   362,
     364,   368,   372,   374,   378,   380,   384,   386,   390,   392,
     396,   398,   402,   404,   410,   412,   416,   418,   420,   422,
     424,   426,   428,   430,   432,   434,   436,   438,   440,   442,
     446,   448,   449,   451,   453,   455,   457,   459,   461,   463,
     465,   467,   469,   471,   475,   480,   484,   487,   492,   497,
     498,   500,   502,   507,   508,   510,   515,   517,   525,   527,
     529,   533,   536,   539,   543,   545,   547,   549,   551,   553,
     555,   557,   559,   561,   563,   565,   567,   569,   573,   575,
     577,   579,   581,   583,   585,   588,   589,   591,   593,   595,
     597,   599,   601,   603,   605,   607,   609,   611,   613,   615,
     617,   620,   622,   626,   628,   630,   632,   634,   636,   638,
     640,   642,   644,   646,   648,   649,   651,   655,   660,   664,
     666,   670,   675,   681,   682,   684,   686,   690,   692,   696,
     698,   700,   702,   704,   706,   710,   713,   715,   721,   724,
     730,   735,   736,   738,   744,   750,   754,   758,   759,   761,
     763,   767,   770,   772,   775,   777,   784,   789,   793,   796,
     798,   802,   803,   805,   807,   810,   812,   814,   816,   818,
     821,   823,   826,   829,   831,   832,   834,   835,   837,   844,
     849,   853,   856,   860,   861,   863,   864,   866,   868,   872,
     875,   880,   883,   888,   893,   897,   900,   902,   903,   905,
     907,   912,   916,   919,   921,   925,   927,   929,   934,   938,
     943,   948,   950,   952,   954,   955,   957,   959,   962,   964,
     967,   971,   974,   976,   978,   980,   984,   985,   987,   990,
     994,   995,   998,   999,  1001,  1003,  1007,  1009,  1013,  1017,
    1019,  1021,  1023,  1024,  1026,  1027,  1029,  1032,  1035,  1036,
    1038,  1040,  1043,  1044,  1047,  1049,  1053,  1058,  1061,  1067,
    1069,  1071,  1073,  1075,  1077,  1079,  1081,  1083,  1085,  1087,
    1089,  1091,  1093,  1095,  1097,  1099,  1101,  1103,  1105,  1107,
    1111,  1114,  1119,  1121,  1125,  1127,  1129,  1132,  1137,  1140,
    1145,  1149,  1155,  1160,  1161,  1163,  1165,  1169,  1171,  1173,
    1176,  1181,  1184,  1187,  1191,  1194,  1196,  1199,  1205,  1208,
    1211,  1213,  1215,  1217,  1220,  1221,  1225,  1230,  1232
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const short int yyrhs[] =
{
     130,     0,    -1,   189,    -1,   178,    -1,   134,    -1,    92,
      -1,   132,    -1,   120,    -1,    38,   175,    39,    -1,    94,
      -1,   132,    94,    -1,    -1,   146,    -1,   135,    -1,   138,
      -1,   247,    -1,   272,    -1,   265,    -1,   136,    -1,    54,
     247,    -1,   139,   141,   135,    -1,   137,    -1,   101,   272,
      -1,   101,   247,    -1,   142,   143,    -1,   139,    -1,   142,
      -1,    -1,   119,    -1,   101,    -1,   247,   101,   144,    -1,
     247,   101,   119,   143,    -1,    -1,   143,    -1,   131,    -1,
     145,    77,   175,    78,    -1,   145,    38,   133,    39,    -1,
     145,    68,    -1,   145,    69,    -1,    38,   247,    39,    75,
     246,    76,    -1,    38,   247,    39,    75,   246,    72,    76,
      -1,   199,    38,   133,    39,    -1,   202,    38,   133,    39,
      -1,   145,    66,   141,   134,    -1,   145,    67,   141,   134,
      -1,   145,    66,   147,    -1,   145,    67,   147,    -1,   106,
      56,   231,    59,    38,   175,    39,    -1,   118,    56,   231,
      59,    38,   175,    39,    -1,   117,    56,   231,    59,    38,
     175,    39,    -1,   102,    56,   231,    59,    38,   175,    39,
      -1,   123,    38,   175,    39,    -1,   123,    38,   231,    39,
      -1,   173,    -1,   146,    72,   173,    -1,   198,   101,   136,
      -1,   139,   119,   279,   101,   136,    -1,   140,   136,    -1,
     145,    -1,    68,   148,    -1,    69,   148,    -1,   149,   160,
      -1,    37,   148,    -1,    37,    38,   231,    39,    -1,   150,
      -1,   159,    -1,    52,    -1,    47,    -1,    43,    -1,    45,
      -1,    54,    -1,    55,    -1,   142,   112,   152,   153,   158,
      -1,   142,   112,   152,    38,   231,    39,   158,    -1,    38,
     146,    39,    -1,    -1,   151,    -1,   232,   155,    -1,   226,
     155,    -1,   156,    -1,    -1,   154,    -1,    77,   175,    78,
      -1,   156,    77,   176,    78,    -1,    38,   133,    39,    -1,
      -1,   157,    -1,   142,   103,   160,    -1,   142,   103,    77,
      78,   160,    -1,   148,    -1,    38,   231,    39,   160,    -1,
     160,    -1,   161,   105,   160,    -1,   161,   104,   160,    -1,
     161,    -1,   162,    47,   161,    -1,   162,    49,   161,    -1,
     162,    48,   161,    -1,   162,    -1,   163,    43,   162,    -1,
     163,    45,   162,    -1,   163,    -1,   164,    40,   163,    -1,
     164,    41,   163,    -1,   164,    -1,   165,    56,   164,    -1,
     165,    59,   164,    -1,   165,    57,   164,    -1,   165,    58,
     164,    -1,   165,    -1,   166,    60,   165,    -1,   166,    61,
     165,    -1,   166,    -1,   167,    52,   166,    -1,   167,    -1,
     168,    50,   167,    -1,   168,    -1,   169,    53,   168,    -1,
     169,    -1,   170,    62,   169,    -1,   170,    -1,   171,    63,
     170,    -1,   171,    -1,   171,    64,   175,    90,   172,    -1,
     172,    -1,   171,   174,   173,    -1,   290,    -1,    79,    -1,
      82,    -1,    86,    -1,    87,    -1,    80,    -1,    81,    -1,
      83,    -1,    84,    -1,    85,    -1,    88,    -1,    89,    -1,
     173,    -1,   175,    72,   173,    -1,   172,    -1,    -1,   176,
      -1,   179,    -1,   180,    -1,   181,    -1,   185,    -1,    75,
      -1,    76,    -1,    26,    -1,   187,    -1,   188,    -1,   285,
      -1,    93,    90,   178,    -1,    31,   176,    90,   178,    -1,
      32,    90,   178,    -1,   175,    73,    -1,    25,    38,   183,
      39,    -1,    30,    38,   183,    39,    -1,    -1,   175,    -1,
     175,    -1,   232,   224,    79,   173,    -1,    -1,   183,    -1,
      27,    38,   183,    39,    -1,    29,    -1,    28,    38,   186,
     184,    73,   184,    39,    -1,   180,    -1,   191,    -1,    36,
      93,    73,    -1,    34,    73,    -1,    33,    73,    -1,    35,
     182,    73,    -1,   190,    -1,   190,    -1,   242,    -1,   274,
      -1,   283,    -1,   284,    -1,   220,    -1,   209,    -1,   191,
      -1,   219,    -1,   214,    -1,   216,    -1,   218,    -1,   194,
     221,    73,    -1,   195,    -1,   197,    -1,   196,    -1,   109,
      -1,    10,    -1,   192,    -1,   193,   192,    -1,    -1,   193,
      -1,   110,    -1,     8,    -1,     7,    -1,     6,    -1,     9,
      -1,    96,    -1,   126,    -1,   107,    -1,   199,    -1,   248,
      -1,   203,    -1,   201,    -1,   229,    -1,   140,   247,    -1,
     198,    -1,   139,   119,   279,    -1,   127,    -1,    19,    -1,
      11,    -1,    15,    -1,    14,    -1,    16,    -1,    12,    -1,
      13,    -1,    18,    -1,    17,    -1,     3,    -1,    -1,    93,
      -1,   250,   140,    93,    -1,   250,   140,   141,   279,    -1,
      24,   140,    93,    -1,   202,    -1,   124,   139,    93,    -1,
     124,   139,   141,   279,    -1,    24,   200,    75,   204,    76,
      -1,    -1,   205,    -1,   206,    -1,   205,    72,   206,    -1,
     207,    -1,   207,    79,   176,    -1,    93,    -1,   213,    -1,
     210,    -1,   212,    -1,   211,    -1,   111,    93,    75,    -1,
     111,    75,    -1,    93,    -1,   111,    93,    79,   215,    73,
      -1,   140,   208,    -1,   125,   217,   139,   135,    73,    -1,
     125,   101,   135,    73,    -1,    -1,   124,    -1,   125,   111,
     140,   208,    73,    -1,    98,    38,   132,    39,    73,    -1,
       8,   132,    75,    -1,     8,   132,   189,    -1,    -1,   222,
      -1,   223,    -1,   222,    72,   223,    -1,   224,   244,    -1,
     225,    -1,   226,   224,    -1,   230,    -1,   225,    38,   237,
      39,   227,   291,    -1,   225,    77,   177,    78,    -1,    38,
     224,    39,    -1,    47,   227,    -1,    52,    -1,   139,    47,
     227,    -1,    -1,   228,    -1,   229,    -1,   228,   229,    -1,
      20,    -1,    21,    -1,   134,    -1,   198,    -1,   232,   234,
      -1,   197,    -1,   232,   197,    -1,   226,   234,    -1,   236,
      -1,    -1,   233,    -1,    -1,   236,    -1,   235,    38,   237,
      39,   227,   291,    -1,   235,    77,   177,    78,    -1,    38,
     233,    39,    -1,   239,   238,    -1,   240,    72,    74,    -1,
      -1,    74,    -1,    -1,   240,    -1,   241,    -1,   240,    72,
     241,    -1,   193,   224,    -1,   193,   224,    79,   173,    -1,
     193,   234,    -1,   193,   234,    79,   173,    -1,   194,   224,
     269,    75,    -1,   194,   224,   286,    -1,    79,   245,    -1,
     151,    -1,    -1,   243,    -1,   173,    -1,    75,   246,    72,
      76,    -1,    75,   246,    76,    -1,    75,    76,    -1,   245,
      -1,   246,    72,   245,    -1,    93,    -1,   279,    -1,   249,
      75,   251,    76,    -1,   250,   200,   259,    -1,   250,   143,
      93,   259,    -1,   250,   144,   279,   259,    -1,   100,    -1,
      22,    -1,    23,    -1,    -1,   252,    -1,   253,    -1,   252,
     253,    -1,   254,    -1,   262,    90,    -1,   194,   256,    73,
      -1,   137,    73,    -1,   216,    -1,   274,    -1,   257,    -1,
     255,    72,   257,    -1,    -1,   255,    -1,   224,   258,    -1,
     200,    90,   176,    -1,    -1,    79,   176,    -1,    -1,   260,
      -1,   261,    -1,   260,    72,   261,    -1,   198,    -1,   126,
     263,   198,    -1,   262,   264,   198,    -1,   114,    -1,   115,
      -1,   116,    -1,    -1,   262,    -1,    -1,   126,    -1,   113,
     266,    -1,   232,   267,    -1,    -1,   268,    -1,   226,    -1,
     268,   226,    -1,    -1,    90,   270,    -1,   271,    -1,   270,
      72,   271,    -1,   198,    38,   133,    39,    -1,   113,   273,
      -1,   113,   273,    56,   280,    59,    -1,    43,    -1,    45,
      -1,    47,    -1,    49,    -1,    50,    -1,    51,    -1,    52,
      -1,    53,    -1,    54,    -1,    55,    -1,    56,    -1,    57,
      -1,    58,    -1,    59,    -1,    60,    -1,    61,    -1,    62,
      -1,    63,    -1,    40,    -1,    41,    -1,   108,   275,   189,
      -1,   275,   189,    -1,   119,    56,   276,    59,    -1,   277,
      -1,   276,    72,   277,    -1,   278,    -1,   241,    -1,   100,
     200,    -1,   100,   200,    79,   231,    -1,   124,   200,    -1,
     124,   200,    79,   231,    -1,   275,   100,   200,    -1,   275,
     100,   200,    79,   134,    -1,    93,    56,   280,    59,    -1,
      -1,   281,    -1,   282,    -1,   281,    72,   282,    -1,   173,
      -1,   231,    -1,   119,   189,    -1,   119,    56,    59,   189,
      -1,   122,    75,    -1,    76,   287,    -1,   122,   269,    75,
      -1,    76,   287,    -1,   288,    -1,   287,   288,    -1,    99,
      38,   289,    39,    75,    -1,   232,   224,    -1,   232,   233,
      -1,   232,    -1,    74,    -1,   121,    -1,   121,   173,    -1,
      -1,   121,    38,    39,    -1,   121,    38,   292,    39,    -1,
     231,    -1,   292,    72,   231,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   297,   297,   305,   317,   322,   327,   332,   337,   347,
     352,   360,   364,   371,   372,   380,   381,   382,   383,   389,
     392,   395,   396,   397,   405,   408,   409,   411,   412,   415,
     418,   419,   421,   422,   431,   436,   441,   465,   470,   475,
     480,   485,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   503,   508,   520,   521,   522,   525,   530,
     535,   540,   549,   554,   559,   560,   563,   568,   573,   578,
     583,   588,   595,   596,   599,   601,   602,   605,   608,   609,
     611,   612,   615,   616,   619,   621,   622,   625,   626,   637,
     642,   649,   650,   651,   662,   667,   672,   677,   694,   699,
     704,   711,   716,   721,   728,   733,   738,   743,   748,   755,
     760,   765,   780,   785,   792,   797,   804,   809,   816,   821,
     828,   833,   840,   845,   853,   858,   863,   870,   875,   880,
     885,   890,   895,   900,   905,   910,   915,   920,   927,   932,
     939,   945,   946,   953,   957,   961,   965,   974,   979,   984,
     989,   993,   994,   997,  1001,  1007,  1017,  1040,  1047,  1056,
    1060,  1066,  1067,  1069,  1070,  1084,  1091,  1104,  1117,  1118,
    1121,  1126,  1131,  1136,  1145,  1158,  1159,  1160,  1161,  1162,
    1163,  1164,  1167,  1168,  1169,  1170,  1171,  1174,  1177,  1178,
    1179,  1180,  1181,  1184,  1185,  1187,  1188,  1194,  1198,  1202,
    1206,  1210,  1216,  1217,  1218,  1226,  1227,  1228,  1229,  1230,
    1236,  1239,  1240,  1241,  1242,  1246,  1250,  1254,  1258,  1262,
    1266,  1270,  1274,  1278,  1284,  1287,  1301,  1302,  1303,  1304,
    1307,  1308,  1316,  1318,  1319,  1322,  1323,  1326,  1327,  1330,
    1336,  1344,  1345,  1351,  1362,  1368,  1376,  1379,  1386,  1389,
    1390,  1392,  1393,  1396,  1399,  1405,  1406,  1412,  1413,  1416,
    1417,  1420,  1423,  1424,  1427,  1428,  1429,  1430,  1433,  1434,
    1435,  1437,  1438,  1441,  1442,  1445,  1446,  1449,  1450,  1453,
    1456,  1457,  1460,  1461,  1464,  1467,  1472,  1473,  1476,  1477,
    1478,  1481,  1482,  1484,  1485,  1487,  1488,  1491,  1492,  1495,
    1496,  1497,  1498,  1506,  1507,  1515,  1519,  1521,  1522,  1525,
    1526,  1527,  1528,  1531,  1532,  1539,  1544,  1547,  1550,  1551,
    1552,  1555,  1556,  1557,  1559,  1560,  1568,  1569,  1572,  1573,
    1576,  1580,  1581,  1582,  1588,  1589,  1591,  1592,  1598,  1599,
    1607,  1608,  1614,  1615,  1618,  1619,  1622,  1623,  1624,  1627,
    1628,  1629,  1631,  1632,  1634,  1635,  1642,  1648,  1650,  1651,
    1654,  1655,  1657,  1658,  1661,  1662,  1665,  1681,  1682,  1685,
    1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,  1694,  1695,
    1696,  1697,  1698,  1699,  1700,  1701,  1702,  1703,  1704,  1719,
    1720,  1723,  1726,  1727,  1730,  1731,  1734,  1735,  1736,  1737,
    1738,  1739,  1742,  1749,  1750,  1753,  1754,  1760,  1761,  1764,
    1767,  1778,  1779,  1786,  1787,  1790,  1791,  1798,  1801,  1802,
    1803,  1804,  1807,  1808,  1810,  1811,  1812,  1815,  1816
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_BOOL", "_COMPLEX", "_IMAGINARY",
  "AUTO", "STATIC", "EXTERN", "REGISTER", "TYPEDEF", "CHAR", "FLOAT",
  "DOUBLE", "INT", "SHORT", "LONG", "UNSIGNED", "SIGNED", "VOID", "CONST",
  "VOLATILE", "STRUCT", "UNION", "ENUM", "IF", "ELSE", "WHILE", "FOR",
  "DO", "SWITCH", "CASE", "DEFAULT", "BREAK", "CONTINUE", "RETURN", "GOTO",
  "SIZEOF", "OPEN_RND", "CLOSE_RND", "LEFTSHIFT", "RIGHTSHIFT", "PLUS",
  "ADD", "NEGATE", "MINUS", "STAR", "TIMES", "REMAINDER", "DIVIDE", "XOR",
  "AND", "BITAND", "OR", "BITNEGATE", "NOT", "LT", "LE", "GE", "GT",
  "EQUAL", "NOTEQUAL", "ANDTEST", "ORTEST", "QUESTION", "DUMMY1", "DOT",
  "DEREF", "PLUSPLUS", "MINUSMINUS", "POSTPLUSPLUS", "POSTMINUSMINUS",
  "COMMA", "SEMICOLON", "ELLIPSIS", "OPEN_CURL", "CLOSE_CURL",
  "OPEN_SQUARE", "CLOSE_SQUARE", "ASSIGN", "PLUSASSIGN", "MINUSASSIGN",
  "TIMESASSIGN", "LSASSIGN", "RSASSIGN", "ANDASSIGN", "DIVASSIGN",
  "REMASSIGN", "ORASSIGN", "XORASSIGN", "COLON", "DUMMY2", "CONSTANT",
  "IDENTIFIER", "STRING_LITERAL", "TYPEDEFNAME", "INLINE", "RESTRICT",
  "ASM", "CATCH", "CLASS", "COLONCOLON", "CONST_CAST", "DELETE",
  "DEREFSTAR", "DOTSTAR", "DYNAMIC_CAST", "EXPLICIT", "EXPORT", "FRIEND",
  "MUTABLE", "NAMESPACE", "NEW", "OPERATOR", "PRIVATE", "PROTECTED",
  "PUBLIC", "REINTERPRET_CAST", "STATIC_CAST", "TEMPLATE", "THIS", "THROW",
  "TRY", "TYPEID", "TYPENAME", "USING", "VIRTUAL", "WCHAR_T", "UNDEFINED",
  "$accept", "translation_unit", "primary_expr", "string_seq",
  "argument_expr_list_opt", "id_expression", "unqualified_id",
  "bitneg_type_name", "cconns_temp_unqual_id", "qualified_id",
  "cc_opt_nested_n_spec", "cc_opt_nested_n_specopt", "template_opt",
  "coloncolon_opt", "nested_name_specifier", "nested_name_specifier_opt",
  "postfix_expr", "argument_expr_list", "pseudo_destructor_name",
  "unary_expr", "unary_operator", "new_expression", "new_placement",
  "new_placement_opt", "new_type_id", "new_declarator",
  "new_declarator_opt", "direct_new_declarator", "new_initializer",
  "new_initializer_opt", "delete_expression", "cast_expr", "pm_expr",
  "multiplicative_expr", "additive_expr", "shift_expr", "relational_expr",
  "equality_expr", "AND_expr", "exclusive_OR_expr", "inclusive_OR_expr",
  "logical_AND_expr", "logical_OR_expr", "conditional_expr",
  "assignment_expr", "assignment_operator", "expression", "constant_expr",
  "constant_expr_opt", "statement", "labeled_statement",
  "expression_statement", "selection_header", "expr_opt", "condition",
  "condition_opt", "iteration_header", "for_init_statement",
  "jump_statement", "declaration_statement", "declaration",
  "block_declaration", "simple_declaration", "decl_specifier",
  "decl_specifier_seq", "decl_specifier_seq_opt",
  "storage_class_specifier", "function_specifier", "type_specifier",
  "stp_decl_id", "simple_type_specifier", "identifier_opt",
  "elaborated_type_specifier", "TN_cc_nested_ID_temp", "enum_specifier",
  "enumerator_list_opt", "enumerator_list", "enumerator_definition",
  "enumerator", "namespace_name", "namespace_definition",
  "named_namespace_definition", "extension_namespace_definition",
  "unnamed_namespace_definition", "namespace_alias",
  "namespace_alias_definition", "qualified_namespace_specifier",
  "using_declaration", "typename_opt", "using_directive", "asm_definition",
  "linkage_specification", "init_declarator_list_opt",
  "init_declarator_list", "init_declarator", "declarator",
  "direct_declarator", "ptr_operator", "cv_qualifier_seq_opt",
  "cv_qualifier_seq", "cv_qualifier", "declarator_id", "type_id",
  "type_specifier_seq", "abstract_declarator", "abstract_declarator_opt",
  "direct_abstract_declarator_opt", "direct_abstract_declarator",
  "parameter_declaration_clause", "ellipsis_opt",
  "parameter_declaration_list_opt", "parameter_declaration_list",
  "parameter_declaration", "function_header", "initializer",
  "initializer_opt", "initializer_clause", "initializer_list", "type_name",
  "class_specifier", "class_head", "class_key", "member_specification_opt",
  "member_specification", "mem_decl_or_acc_spec", "member_declaration",
  "member_declarator_list", "member_declarator_list_opt",
  "member_declarator", "constant_initializer_opt", "base_clause_opt",
  "base_specifier_list", "base_specifier", "access_specifier",
  "access_specifier_opt", "virtual_opt", "conversion_function_id",
  "conversion_type_id", "ptr_operator_list_opt", "ptr_operator_list",
  "ctor_initializer_opt", "mem_initializer_list", "mem_initializer",
  "operator_function_id", "operator", "template_declaration",
  "template_lt_gt", "template_parameter_list", "template_parameter",
  "type_parameter", "template_id", "template_argument_list_opt",
  "template_argument_list", "template_argument", "explicit_instantiation",
  "explicit_specialization", "try_block", "function_try_header",
  "handler_seq", "handler", "exception_declaration", "throw_expression",
  "exception_specification_opt", "type_id_list", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] =
{
       0,   129,   130,   130,   131,   131,   131,   131,   131,   132,
     132,   133,   133,   134,   134,   135,   135,   135,   135,   136,
     137,   138,   138,   138,   139,   140,   140,   141,   141,   142,
     143,   143,   144,   144,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   146,   146,   147,   147,   147,   148,   148,
     148,   148,   148,   148,   148,   148,   149,   149,   149,   149,
     149,   149,   150,   150,   151,   152,   152,   153,   154,   154,
     155,   155,   156,   156,   157,   158,   158,   159,   159,   160,
     160,   161,   161,   161,   162,   162,   162,   162,   163,   163,
     163,   164,   164,   164,   165,   165,   165,   165,   165,   166,
     166,   166,   167,   167,   168,   168,   169,   169,   170,   170,
     171,   171,   172,   172,   173,   173,   173,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   175,   175,
     176,   177,   177,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   179,   179,   179,   180,   181,   181,   182,
     182,   183,   183,   184,   184,   185,   185,   185,   186,   186,
     187,   187,   187,   187,   188,   189,   189,   189,   189,   189,
     189,   189,   190,   190,   190,   190,   190,   191,   192,   192,
     192,   192,   192,   193,   193,   194,   194,   195,   195,   195,
     195,   195,   196,   196,   196,   197,   197,   197,   197,   197,
     198,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   200,   200,   201,   201,   201,   201,
     202,   202,   203,   204,   204,   205,   205,   206,   206,   207,
     208,   209,   209,   210,   211,   212,   213,   214,   215,   216,
     216,   217,   217,   218,   219,   220,   220,   221,   221,   222,
     222,   223,   224,   224,   225,   225,   225,   225,   226,   226,
     226,   227,   227,   228,   228,   229,   229,   230,   230,   231,
     232,   232,   233,   233,   234,   234,   235,   235,   236,   236,
     236,   237,   237,   238,   238,   239,   239,   240,   240,   241,
     241,   241,   241,   242,   242,   243,   243,   244,   244,   245,
     245,   245,   245,   246,   246,   247,   247,   248,   249,   249,
     249,   250,   250,   250,   251,   251,   252,   252,   253,   253,
     254,   254,   254,   254,   255,   255,   256,   256,   257,   257,
     258,   258,   259,   259,   260,   260,   261,   261,   261,   262,
     262,   262,   263,   263,   264,   264,   265,   266,   267,   267,
     268,   268,   269,   269,   270,   270,   271,   272,   272,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   274,
     274,   275,   276,   276,   277,   277,   278,   278,   278,   278,
     278,   278,   279,   280,   280,   281,   281,   282,   282,   283,
     284,   285,   285,   286,   286,   287,   287,   288,   289,   289,
     289,   289,   290,   290,   291,   291,   291,   292,   292
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     2,     2,     2,     1,     1,     0,     1,     1,
       3,     4,     0,     1,     1,     4,     4,     2,     2,     6,
       7,     4,     4,     4,     4,     3,     3,     7,     7,     7,
       7,     4,     4,     1,     3,     3,     5,     2,     1,     2,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     7,     3,     0,     1,     2,     2,     1,
       0,     1,     3,     4,     3,     0,     1,     3,     5,     1,
       4,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     4,     4,     0,
       1,     1,     4,     0,     1,     4,     1,     7,     1,     1,
       3,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     3,     4,     3,     1,
       3,     4,     5,     0,     1,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     3,     2,     1,     5,     2,     5,
       4,     0,     1,     5,     5,     3,     3,     0,     1,     1,
       3,     2,     1,     2,     1,     6,     4,     3,     2,     1,
       3,     0,     1,     1,     2,     1,     1,     1,     1,     2,
       1,     2,     2,     1,     0,     1,     0,     1,     6,     4,
       3,     2,     3,     0,     1,     0,     1,     1,     3,     2,
       4,     2,     4,     4,     3,     2,     1,     0,     1,     1,
       4,     3,     2,     1,     3,     1,     1,     4,     3,     4,
       4,     1,     1,     1,     0,     1,     1,     2,     1,     2,
       3,     2,     1,     1,     1,     3,     0,     1,     2,     3,
       0,     2,     0,     1,     1,     3,     1,     3,     3,     1,
       1,     1,     0,     1,     0,     1,     2,     2,     0,     1,
       1,     2,     0,     2,     1,     3,     4,     2,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     4,     1,     3,     1,     1,     2,     4,     2,     4,
       3,     5,     4,     0,     1,     1,     3,     1,     1,     2,
       4,     2,     2,     3,     2,     1,     2,     5,     2,     2,
       1,     1,     1,     2,     0,     3,     4,     1,     3
};

/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const unsigned char yydprec[] =
{
       0,     0,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const unsigned char yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     1,     0,     0,     2,     2,
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error.  */
static const unsigned short int yydefact[] =
{
     195,   223,   200,   199,   198,   201,   192,   215,   219,   220,
     217,   216,   218,   222,   221,   214,   275,   276,   322,   323,
     224,     0,   149,     0,     0,   166,     0,     0,     0,     0,
       0,   159,     0,     0,     0,    68,    69,    67,    66,    70,
      71,     0,     0,   147,   148,     5,   315,     9,   202,     0,
     321,    29,     0,     0,   204,     0,   191,   197,     0,     0,
       0,     0,   195,     7,   422,     0,     0,     0,     0,   203,
     213,     0,    34,     6,     4,    13,    18,    21,    14,    27,
       0,     0,    58,    89,     0,    64,    65,    91,    94,    98,
     101,   104,   109,   112,   114,   116,   118,   120,   122,   124,
     138,     0,     3,   143,   144,   145,   146,   150,   151,     2,
     174,   182,   193,   196,   257,   188,   190,   189,   211,   205,
     208,   229,   207,   181,   241,   243,   242,   184,   185,   186,
     183,   180,   209,   176,    15,   206,     0,   224,    17,    16,
     177,   195,   316,   178,   179,   152,   126,   195,   225,    29,
      25,     0,    26,     0,     0,     0,   195,     0,   315,   122,
     140,     0,     0,     0,   195,   172,   171,   160,     0,     0,
       0,    62,     0,   280,     0,   284,    15,    19,     0,    59,
      60,     0,   412,   415,   403,   195,     0,     0,    23,    22,
       0,     0,     0,   195,   245,     0,   387,   388,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,    25,   205,   229,   358,
     356,   367,     0,     0,     0,   409,   175,   423,   411,     0,
       0,     0,     0,     0,   252,     0,     1,    10,    28,     0,
     210,     0,    75,    24,     0,    11,    27,    27,    37,    38,
       0,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,   131,   132,   128,   133,   134,   135,
     129,   130,   136,   137,     0,     0,   156,   198,   194,     0,
     271,   269,     0,   277,    27,   278,     0,   258,   259,   307,
     262,     0,   264,    11,    11,   195,   225,     0,     0,     0,
     342,   390,   255,   256,   228,   233,   161,     0,     0,     0,
     168,   163,   169,   257,     0,   195,     0,   155,   174,   173,
     170,     0,     8,     0,   286,    25,   281,   284,   285,   279,
       0,   283,     0,     0,   416,   407,   408,     0,   404,   405,
     153,     0,     0,     0,     0,   389,   244,     0,     0,   360,
     357,   359,   403,     0,     0,   195,   321,   224,   284,   395,
       0,     0,   392,   394,     0,     0,   230,    28,     0,     0,
       0,     0,     0,   212,    20,     0,    87,     0,    76,     0,
      32,     0,    12,    53,    25,     0,     0,    45,     0,     0,
      46,     0,    93,    92,    95,    97,    96,    99,   100,   102,
     103,   105,   107,   108,   106,   110,   111,   113,   115,   117,
     119,   121,     0,   125,   139,     0,   268,   272,   273,   271,
     187,     0,     0,     0,     0,   362,   306,   308,   261,     0,
     304,   295,   141,   263,     0,     0,   349,   350,   351,     0,
       0,   224,   332,     0,   195,   326,   328,     0,   333,   226,
       0,   342,   342,   352,   346,   318,   343,   344,   354,   239,
       0,   234,   235,   237,   157,    27,   211,     0,   165,   164,
       0,   307,   158,   154,     0,    63,    90,     0,     0,   282,
     295,   141,     0,   421,   286,     0,   402,     0,     0,     0,
       0,     0,     0,   361,     0,     0,     0,   410,   396,   398,
     286,   299,   284,   301,   224,   391,     0,    51,    52,   231,
     250,   246,     0,   240,     0,     0,     0,     0,    85,    80,
       0,    33,    30,    36,     0,     0,    57,    43,    27,     0,
      44,    35,     0,   267,   274,   270,   260,   414,     0,   309,
     305,     0,   363,   364,     0,   303,     0,   293,   296,   297,
     142,     0,    41,    42,   331,     0,   340,   337,     0,   334,
     317,   327,   329,   227,   319,   320,   353,     0,     0,   355,
       0,   232,     0,     0,     0,   163,   290,     0,     0,   313,
       0,   418,   419,     0,   406,   254,     0,     0,   248,   247,
     368,     0,     0,     0,     0,     0,     0,   400,   393,   253,
     249,    88,    74,     0,    11,    86,    72,     0,    81,    77,
      79,    80,    31,    54,     0,    55,   123,   312,     0,    11,
       0,   413,   271,   294,   291,     0,   266,     0,     0,   338,
     224,   330,   347,   345,   348,   236,   238,   162,     0,   271,
     289,     0,    39,   417,     0,     0,     0,     0,   397,   399,
     300,   302,     0,    85,     0,     0,     0,    78,     0,     0,
     311,     0,   365,   424,   292,   298,   339,   341,   335,   167,
     424,    40,   314,    50,    47,    49,    48,   401,    73,    84,
      82,     0,    56,   310,   366,     0,   265,   288,    83,     0,
     425,   427,     0,   426,     0,   428
};

/* YYPDEFGOTO[NTERM-NUM].  */
static const short int yydefgoto[] =
{
      -1,    71,    72,    73,   391,    74,    75,    76,    77,    78,
      79,    80,   239,    81,   243,   309,    82,   392,   397,    83,
      84,    85,   436,   389,   528,   618,   619,   620,   615,   616,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   284,   101,   560,   561,   102,
     103,   104,   105,   168,   479,   480,   106,   321,   107,   108,
     109,   226,   111,   112,   113,   114,   115,   116,   173,   118,
     162,   565,   120,   163,   122,   470,   471,   472,   473,   522,
     123,   124,   125,   126,   523,   127,   502,   128,   235,   129,
     130,   131,   296,   297,   298,   425,   300,   301,   426,   427,
     132,   302,   346,   175,   338,   489,   340,   341,   556,   634,
     557,   558,   369,   133,   437,   438,   589,   590,   134,   135,
     136,   137,   453,   454,   455,   456,   567,   568,   569,   639,
     465,   466,   467,   468,   577,   580,   138,   220,   360,   361,
     439,   552,   553,   139,   221,   140,   141,   371,   372,   373,
     142,   347,   348,   349,   143,   144,   145,   440,   182,   183,
     495,   146,   696,   702
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -427
static const short int yypact[] =
{
    1304,  -427,  -427,  -427,   -61,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
     124,     5,  -427,    27,    99,  -427,   114,  3428,   -40,    98,
     135,  3031,   122,  3546,  1923,  -427,  -427,  -427,  -427,   125,
    -427,  3606,  3606,  -427,   143,  -427,    37,  -427,  -427,   219,
    -427,   -56,   189,   215,  -427,   197,  -427,  -427,    25,  2042,
     243,   272,  2795,  -427,  3031,   261,   309,   270,   203,  -427,
    -427,   382,  -427,   290,  -427,  -427,  -427,  -427,  -427,   -63,
     303,    28,   378,  -427,  3428,  -427,  -427,  -427,   344,   339,
      54,   402,   349,   396,   341,   360,   376,   329,   794,  -427,
    -427,   390,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
     433,  -427,  -427,  3798,   268,  -427,  -427,  -427,  -427,   400,
    -427,   414,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,   384,   192,  -427,  -427,
    -427,  3095,  -427,  -427,  -427,  -427,  -427,  2103,  -427,  -427,
    -427,   380,   388,   425,  1923,  1923,  1804,  1923,   421,   408,
    -427,   420,   477,   479,  1429,  -427,  -427,   451,   453,   458,
    1923,  -427,    14,  -427,   494,  1871,   501,  -427,  3031,  -427,
    -427,   507,   143,  -427,  1923,  1554,   -61,  2780,  -427,  -427,
    1268,  1268,   491,  3153,  -427,   260,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,   435,  -427,  -427,  3967,
    -427,   500,  1268,  1268,  2851,  -427,  -427,  -427,  -427,  1923,
      24,   303,    15,   270,  -427,   270,  -427,  -427,   464,    15,
    -427,  3270,   520,  -427,   459,  3031,   179,   191,  -427,  -427,
    3031,  -427,  3428,  3428,  3428,  3428,  3428,  3428,  3428,  3428,
    3428,  3428,  3428,  3428,  3428,  3428,  3428,  3428,  3428,  3428,
    3428,  3428,  3031,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  3031,  3031,  -427,  -427,  -427,   268,
     448,  -427,   303,  -427,   -23,  -427,   508,   495,  -427,     2,
       6,   268,  -427,  3031,  3031,  2141,   476,    41,   480,   481,
     298,  -427,  -427,  -427,  -427,   487,   451,   543,  3337,   544,
    -427,  1923,  -427,   268,   545,  1679,   493,  -427,  -427,  -427,
    -427,   548,  -427,  3428,    35,   -21,  -427,    38,  -427,  -427,
      17,    68,   513,  2170,  -427,  -427,  -427,   530,   519,  -427,
    -427,    -3,   533,   534,  3673,  -427,  -427,   270,   481,  -427,
    -427,   174,  1923,   536,   539,  3392,   180,   124,  2266,  -427,
     502,    57,  -427,  -427,   194,   561,  -427,  -427,   481,   528,
     512,    15,   552,  -427,  -427,   531,  -427,  3031,  -427,  1006,
      42,   571,   546,  -427,   492,    65,     9,  -427,   516,     9,
    -427,   266,  -427,  -427,   344,   344,   344,   339,   339,    54,
      54,   402,   402,   402,   402,   429,   506,   396,   341,   360,
     376,   329,   252,  -427,  -427,   580,  -427,   448,  -427,   448,
    -427,   268,   143,  2912,   270,   537,  -427,  -427,  -427,   549,
    -427,  3850,  3428,  -427,   589,   591,  -427,  -427,  -427,   -73,
     558,   218,  -427,   560,  2318,  -427,  -427,   547,  -427,  -427,
     481,   298,   298,   405,  -427,  -427,   566,  -427,   514,  -427,
     563,   569,  -427,   565,  -427,   -18,   209,   572,  -427,  -427,
     575,    16,  -427,  -427,   573,  -427,  -427,   598,   614,  -427,
    3850,  3428,  2912,  -427,  1066,   616,  -427,  1923,   586,   623,
     625,   512,   587,  -427,   606,   628,   630,  -427,   594,   600,
     357,   602,   338,   603,   584,  -427,  3673,  -427,  -427,  -427,
    -427,  -427,   610,  -427,   613,  3428,   205,  1268,   649,  3915,
     303,  -427,  -427,  -427,  3031,   481,  -427,  -427,   570,   639,
    -427,  -427,  3428,  -427,  -427,  -427,  -427,   143,  2435,  -427,
    -427,   657,   624,  -427,   626,  -427,   658,   629,   633,  -427,
    -427,   620,  -427,  -427,  -427,   612,   621,   634,   635,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,   270,   298,  -427,
     270,  -427,   487,  3428,  3031,  1923,  -427,   668,   637,  -427,
     225,  -427,  -427,   638,  -427,  -427,  3031,  3031,  -427,  -427,
    -427,  3031,  3031,  1268,  1268,  3031,  3031,   642,  -427,  -427,
    -427,  -427,  -427,   678,  3031,  -427,  -427,  3031,  -427,  -427,
     645,    32,  -427,  -427,   631,  -427,  -427,  -427,   307,  3031,
     270,  -427,   448,  -427,  -427,  3728,  -427,  3428,  3428,  -427,
     437,  -427,  -427,  -427,  -427,  -427,  -427,  -427,   685,   448,
    -427,  2554,  -427,  -427,   207,   210,   222,   223,  -427,  -427,
    -427,  -427,     9,   649,   686,   300,  3428,  -427,   639,  2673,
    -427,   687,  -427,   607,  -427,  -427,  -427,  -427,  -427,  -427,
     607,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,   653,  -427,  -427,  -427,   689,  -427,  -427,  -427,  2385,
    -427,  -427,   224,  -427,  1268,  -427
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -427,  -427,  -427,    18,  -262,   391,  -171,  -360,  -273,  -427,
     605,     7,  -158,   289,  -132,   343,  -427,   347,   489,   299,
    -427,  -427,   496,  -427,  -427,  -427,   116,  -427,  -427,    76,
    -427,   -64,   167,   235,   236,   308,   238,   474,   485,   475,
     478,   483,   -24,   -17,   627,  -427,    73,    -4,   254,  -119,
    -427,   593,  -427,  -427,   280,   162,  -427,  -427,  -427,  -427,
     -15,     1,   599,  -104,  -203,  -125,  -427,  -427,   622,   -34,
       0,    -7,  -427,    12,  -427,  -427,  -427,   175,  -427,   255,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -247,  -427,  -427,
    -427,  -427,  -427,  -427,   327,   -11,  -427,   200,  -412,  -427,
    -279,  -427,   -28,   -43,  -296,  -157,  -427,  -427,   271,  -427,
    -427,  -427,  -426,  -427,  -427,  -427,  -419,   212,   -32,  -427,
    -427,  -427,  -427,  -427,   310,  -427,  -427,  -427,   126,  -427,
      90,  -427,   184,  -280,  -427,  -427,  -427,  -427,  -427,  -427,
     330,  -427,   137,   717,  -427,  -238,   -51,  -427,   256,  -427,
    -186,   409,  -427,   273,  -427,  -427,  -427,  -427,   342,  -174,
    -427,  -427,    93,  -427
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -421
static const short int yytable[] =
{
     119,   110,   176,   159,   193,   308,   174,   177,   344,   288,
     160,   428,   121,   153,   550,   559,   219,   545,   339,   188,
     251,   368,   147,   161,   429,   457,   429,   151,   232,   429,
     -25,   323,   450,    47,   119,   536,   498,   158,   488,   323,
     387,   444,   445,   154,   441,   327,   121,   225,   240,   244,
     164,   234,   383,   332,   387,   490,   238,   187,   452,   217,
     323,   379,   217,   292,   559,   155,   350,   458,   384,   292,
     -25,   218,   378,   334,   218,   -25,   334,  -362,   432,   290,
     295,   433,   290,   442,   291,   290,   285,   291,   396,   399,
     291,   237,   434,   184,   491,   433,   377,   257,   358,   258,
     194,   238,   158,   299,   167,   244,  -287,   172,   158,   617,
      51,   318,   318,   217,   318,  -286,   515,   376,   195,   292,
     244,   158,    59,   462,   435,   218,   311,   185,    59,   516,
     310,   241,   313,   149,   459,   158,   149,   156,   176,   149,
     242,   217,   331,   377,   307,  -287,   176,   217,   544,   460,
     428,   368,   157,   218,   119,   119,   119,   119,   158,   218,
     377,   530,   352,   353,   119,   328,   121,   121,   121,   121,
     119,   165,   383,   370,   457,   217,   121,   386,   355,   625,
     451,   450,   121,   576,   119,   119,   328,   218,   402,   403,
     217,   217,   519,   217,   363,   364,   121,   121,   592,   244,
     323,   375,   218,   218,   351,   218,   483,   452,   166,   675,
     524,   513,   398,   398,   488,   169,   458,   148,   158,   217,
     673,   290,   217,   217,   217,   149,   291,   316,   316,   119,
     316,   218,   682,   517,   218,   218,   218,   680,   368,  -224,
     380,   121,   181,   172,   612,   190,   683,  -211,  -211,   684,
     682,   172,  -224,   395,   395,   295,   289,   186,   531,  -224,
     177,   685,   686,   703,   288,   290,   285,   295,  -211,   486,
     291,   191,   292,   148,   573,   149,   464,   534,   318,   285,
     149,  -211,   285,  -211,   476,   306,  -211,   368,  -211,   295,
     443,  -336,   149,   149,   285,   285,   704,   651,   377,   222,
     494,   652,   374,   370,   232,   217,   289,   477,   692,   152,
     377,   306,   481,   368,   233,   290,   192,   218,   217,    51,
     291,   119,   292,   401,   285,   119,   328,   234,   223,   451,
     218,    59,   171,   121,   476,   356,   228,   121,   285,   357,
     179,   180,   542,   217,   541,   422,   529,   229,   152,   624,
     507,   152,   664,   428,   217,   218,   231,   511,   244,   508,
     509,   158,   119,   240,   501,   217,   218,   671,   217,    51,
     428,   149,   285,   344,   121,   337,   510,   218,   690,   669,
     218,    59,   236,   670,   237,   290,   254,   255,   256,   217,
     291,   270,   292,   267,   316,   510,   158,   295,   622,   149,
     551,   218,   152,   152,   290,   261,   262,   263,   264,   291,
     268,   292,   446,   447,   448,  -286,   245,   295,   159,   359,
     481,   404,   405,   406,   463,   160,   152,   464,   464,   269,
     152,   158,   368,  -174,   317,   319,   152,   324,   303,    51,
     566,   217,   259,   260,   246,   247,   248,   249,   252,   253,
     158,    59,   304,   218,   217,   250,   265,   266,    51,   305,
     476,   611,   285,   286,   152,   370,   218,   159,    16,    17,
      59,   271,   272,   314,   160,   289,   295,   184,   295,   152,
     152,   158,   152,   591,   290,   261,   262,   263,   264,   291,
     217,   292,   407,   408,   217,   409,   410,   119,   244,   613,
     315,   443,   218,   415,   416,   293,   218,   607,   152,   121,
     325,   152,   152,   152,  -315,   303,   217,   304,   159,   446,
     447,   448,   152,   285,   231,   626,   329,   217,   218,   217,
     306,   330,   184,   333,   337,   152,   152,   337,    51,   218,
     342,   218,   318,   642,   464,   343,   644,   354,  -315,  -315,
      59,   574,   575,  -315,   358,  -315,   362,   382,   387,   159,
     390,   503,   261,   262,   263,   264,   160,   431,   512,   411,
     412,   413,   414,   461,   382,   658,   659,  -225,   152,   646,
     469,   430,   474,   478,   482,   119,   484,   485,   492,   496,
     152,   497,   499,   500,   152,   505,   551,   121,   506,   152,
     518,   520,   514,   217,   217,   521,   295,   152,   184,   525,
     533,   535,   152,   159,   159,   218,   218,   539,   534,   543,
     160,   160,   117,   231,   555,   150,   231,   434,   562,   566,
     563,   564,   152,   676,   677,   217,   570,   572,   578,   581,
     579,   582,   159,   152,   583,   429,   152,   218,   585,   160,
     231,   584,   357,   586,   152,   593,   231,   152,   316,   595,
     599,   596,   691,   597,   216,   600,   601,   216,   602,   654,
     655,   701,   230,   603,   656,   657,   705,   148,   152,   604,
     293,   605,   606,   609,   117,   231,   610,   614,   231,   377,
     665,   227,   293,   292,   512,   629,   630,   632,   636,   217,
     638,   631,   637,   633,   217,   635,   640,   649,   641,   293,
     512,   218,   512,   653,   293,   650,   218,   663,   216,   294,
     152,   662,   666,   152,   679,   689,   694,   699,   695,   621,
     152,   698,   668,   532,   526,   117,   400,   667,   388,   688,
     152,   417,   150,   152,   419,   588,   216,   648,   420,   320,
     152,   152,   216,   418,   421,   322,   598,   645,   546,   293,
     628,   587,   643,   117,   571,   554,   678,   672,   189,   117,
     594,   504,   608,   697,   547,     0,     0,     0,   117,   152,
     335,     0,     0,   152,     0,     0,   117,   537,     0,     0,
     540,     0,     0,     0,     0,   216,   216,   336,   216,   152,
       0,   152,     0,     0,     0,   152,     0,   117,     0,     0,
       0,   345,     0,     0,     0,   117,   152,     0,   152,     0,
       0,   621,   293,     0,   335,     0,     0,   216,   216,   216,
       0,     0,     0,     0,     0,     0,     0,     0,   150,     0,
     381,   336,   293,     0,     0,     0,   117,     0,     0,     0,
       0,   394,   394,     0,     0,     0,     0,   271,   272,     0,
       0,     0,     0,     0,     0,     0,   152,   152,     0,   152,
       0,     0,   393,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,     0,   293,     0,     0,     0,     0,
       0,     0,   152,   152,   294,     0,     0,     0,     0,     0,
       0,   293,     0,   293,     0,     0,   294,     0,     0,     0,
     231,   423,   424,     0,     0,   150,     0,     0,     0,   152,
       0,     0,     0,   475,   152,     0,     0,   117,   294,   152,
     393,   393,     0,     0,     0,     0,     0,     0,     0,   487,
     336,     0,   487,     0,     0,     0,     0,   117,   216,     0,
       0,   231,     0,     0,     0,     0,     0,     0,     0,   216,
       0,     0,   150,     0,     0,     0,   487,     0,     0,     0,
     216,     0,   230,   475,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,   152,   345,
     117,     0,     0,   152,   216,     0,     0,     0,     0,     0,
       0,   538,     0,     0,   538,     0,     0,     0,     0,     1,
       0,     0,     0,     0,   393,     0,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   293,     0,     0,     0,     0,   294,     0,     0,   150,
       0,     0,     0,     0,   527,     0,   216,     0,     0,     0,
       0,     0,     0,   687,     0,     0,   294,     0,     0,     0,
     549,     0,     0,   117,     0,     0,   150,   150,     0,     1,
       0,     0,     0,     0,     0,     0,   117,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,     0,     0,   216,     0,     0,     0,   475,
       0,     0,     0,     0,   510,  -420,    50,   149,     0,     0,
       0,     0,   117,   290,     0,   294,   336,   294,   291,   549,
     292,   216,     0,     0,   345,     0,     0,     0,     0,     0,
      67,     0,   216,    70,   335,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   336,     0,     0,     0,     0,     0,     0,     0,   158,
       0,   623,     0,     0,     0,     0,    50,    51,     0,     0,
       0,     0,     0,     0,     0,   549,     0,     0,     0,    59,
       0,     0,   150,   150,     0,   150,     0,     0,     0,     0,
      67,     0,     0,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   216,   216,
       0,   647,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   487,     0,     0,     0,
       0,     0,   660,   661,     0,   150,     0,     0,     0,     0,
     216,   393,     0,     0,     0,   294,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   393,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   538,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     0,   549,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     0,   549,     0,     0,     0,
       0,     0,     0,     0,   216,     0,     0,     1,     0,   216,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,     0,     0,     0,    35,     0,    36,
       0,    37,     0,     0,     0,     0,    38,     0,    39,    40,
       0,     0,     0,     0,     0,     0,     0,     0,    50,   149,
       0,     0,    41,    42,     0,     0,     0,     0,     0,    43,
      44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,     0,     0,    70,    45,    46,    47,     0,
      48,     0,    49,     0,    50,    51,    52,     0,     0,     0,
      53,    54,    55,    56,    57,    58,     0,    59,     0,     0,
       0,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     1,     0,     0,     2,     3,   287,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     0,     0,
       0,     0,    35,     0,    36,     0,    37,     0,     0,     0,
       0,    38,     0,    39,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,    42,     0,
       0,     0,     0,     0,    43,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    45,    46,    47,     0,    48,     0,    49,     0,    50,
      51,    52,     0,     0,     0,    53,    54,     0,    56,    57,
     326,     0,    59,     0,     0,     0,    60,    61,     0,    63,
      64,    65,    66,    67,    68,    69,    70,     1,     0,     0,
       2,     3,   287,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,     0,     0,     0,    35,     0,    36,
       0,    37,     0,     0,     0,     0,    38,     0,    39,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,    42,     0,     0,     0,     0,     0,    43,
      44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,    46,    47,     0,
      48,     0,    49,     0,    50,    51,    52,     0,     0,     0,
      53,    54,     0,    56,    57,   326,     0,    59,     0,     0,
       0,    60,    61,     0,    63,    64,    65,    66,    67,    68,
      69,    70,     1,     0,     0,     2,     3,   287,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     0,     0,
       0,     0,    35,     0,    36,     0,    37,     0,     0,     0,
       0,    38,     0,    39,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,    42,     0,
       0,     0,     0,     0,    43,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    45,    46,    47,     0,    48,     0,    49,     0,    50,
      51,    52,     0,     0,     0,    53,    54,     0,    56,    57,
     326,     0,    59,     0,     0,     0,    60,    61,     0,    63,
      64,    65,    66,    67,    68,    69,    70,     1,     0,     0,
       2,     3,   287,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,     0,     0,     0,     0,    35,     0,    36,
       0,    37,     0,     0,     0,     0,    38,     0,    39,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,    42,     1,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    45,   158,    47,     0,
      48,     0,     0,     0,    50,    51,    52,     0,     0,   334,
      53,    54,     0,    56,    57,     0,     0,    59,   290,     0,
       0,    60,    61,   291,    63,    64,     1,    66,    67,     0,
      69,    70,     0,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,  -286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    34,     0,     0,     0,     0,    35,     0,    36,     0,
      37,    50,   149,     0,     0,    38,     0,    39,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,    42,     0,     0,    67,     0,     0,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    45,   158,    47,     0,     0,
       0,     0,     0,    50,    51,    52,     0,     0,     0,    53,
       0,     0,     0,     0,     0,     0,    59,     0,     0,     0,
      60,    61,     0,    63,    64,     1,    66,    67,     0,     0,
      70,     0,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   196,   197,     0,   198,     0,   199,     0,   200,
       0,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,     1,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,   149,     1,     0,     0,     2,     3,   287,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    67,     0,     0,    70,
       0,     0,     0,     1,     0,     0,     0,     0,   312,     0,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,   237,     0,    48,
       0,    49,     0,    50,   149,     0,     0,     0,     0,     0,
      54,    55,    56,    57,    58,     0,     0,  -324,     0,     0,
       0,     0,    62,     0,     0,     0,     0,    67,    68,    69,
      70,     0,     0,     0,     0,     0,     0,    48,     0,     0,
       0,    50,   149,     0,   493,     0,     0,     0,    54,    55,
      56,    57,     0,     0,     0,   446,   447,   448,     0,     0,
     192,     0,     0,     0,     0,    67,   449,    69,    70,     1,
      50,   149,     2,     3,   287,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,     0,    67,     0,     0,    70,     0,     0,
       0,     0,     0,     0,   510,     0,     0,     0,     0,     0,
       0,     0,     0,   290,     0,     0,     0,     0,   291,     0,
     292,     1,     0,     0,     2,     3,   287,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,  -286,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   158,
       0,     0,    48,     0,     0,     0,    50,    51,     0,     0,
       0,     0,     0,    54,     0,    56,    57,     0,     0,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
      67,     0,    69,    70,  -325,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,    48,     0,     0,     0,    50,   149,
       0,     0,     0,     0,   700,    54,    55,    56,    57,     0,
       0,     0,   446,   447,   448,     0,     0,   192,     1,     0,
       0,     0,    67,   449,    69,    70,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    34,     0,     0,     0,     0,    35,     0,
      36,     0,    37,     0,     0,    50,   149,    38,     0,    39,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,    42,     0,     0,     0,     0,    67,
     548,   627,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,   158,    47,
       0,     0,     0,     0,     0,     0,    51,    52,     0,     0,
       0,    53,     0,     0,     0,     0,     0,     0,    59,     0,
       0,     0,    60,    61,     0,    63,    64,     1,    66,    67,
       0,     0,    70,     0,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,     0,     0,     0,     0,    35,     0,    36,
       0,    37,     0,     0,     0,     0,    38,     0,    39,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,    42,     0,     0,     0,     0,     0,   548,
     681,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,   158,    47,     0,
       0,     0,     0,     0,     0,    51,    52,     0,     0,     0,
      53,     0,     0,     0,     0,     0,     0,    59,     0,     0,
       0,    60,    61,     0,    63,    64,     1,    66,    67,     0,
       0,    70,     0,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    34,     0,     0,     0,     0,    35,     0,    36,     0,
      37,     0,     0,     0,     0,    38,     0,    39,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,    42,     0,     0,     0,     0,     0,   548,   693,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    45,   158,    47,     0,     0,
       0,     0,     0,     0,    51,    52,     0,     0,     0,    53,
       0,     0,     0,     0,     0,     0,    59,     0,     0,     0,
      60,    61,     0,    63,    64,     0,    66,    67,     1,     0,
      70,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
     196,   197,     0,   198,     0,   199,     0,   200,     0,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,     0,     0,     0,     0,     0,     0,
       0,   224,     0,     0,     1,     0,     0,     2,     3,   287,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,    49,     0,    50,   149,     0,     0,     0,
       0,     0,    54,    55,    56,    57,    58,     0,     0,     0,
     365,     0,     0,     0,    62,     1,     0,     0,     0,    67,
      68,    69,    70,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,     0,    33,
      34,   366,   149,     0,     0,    35,     0,    36,    54,    37,
      56,    57,     0,     0,    38,     0,    39,    40,     0,     0,
     192,     0,     0,     0,     0,   367,     0,    69,    70,     0,
      41,    42,     0,     0,     0,     0,     0,   548,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,   158,    47,     0,     0,     0,
       0,     0,     0,    51,    52,     0,     0,     0,    53,     0,
       0,     0,     0,     0,     0,    59,     0,     0,     0,    60,
      61,     0,    63,    64,     1,    66,    67,     0,     0,    70,
       0,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,    34,
       0,     0,     0,     0,    35,     0,    36,     0,    37,     0,
       0,     0,     0,    38,     0,    39,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,    41,
      42,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,    45,   158,    47,     0,     0,     0,     0,
       0,     0,    51,    52,     0,     0,     0,    53,     0,     0,
       0,     0,     0,     0,    59,     0,     0,     0,    60,    61,
       0,    63,    64,     0,    66,    67,     1,     0,    70,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,    49,     0,    50,   149,     0,     0,     0,
       0,     0,    54,    55,    56,    57,    58,     0,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,     0,    67,
      68,    69,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,    49,     0,    50,   149,     0,     0,     0,     0,     0,
      54,    55,    56,    57,    58,     0,     0,     0,     0,     0,
       0,     0,    62,     1,     0,     0,     0,    67,    68,    69,
      70,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,     0,
       0,     0,     0,    35,     0,    36,     0,    37,     0,     0,
       0,     0,    38,     0,    39,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,    42,
       1,     0,     0,     0,     0,     0,     0,   385,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    45,   158,    47,     0,     0,     0,     0,     0,
       0,    51,    52,     0,     0,   289,    53,     0,     0,     0,
       0,     0,     0,    59,   290,     0,     0,    60,    61,   291,
      63,   292,     0,    66,    67,     1,     0,    70,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     158,     1,     0,     0,     0,     0,     0,    50,    51,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,     0,     0,    70,    33,    34,     0,     0,     0,
       0,    35,     0,    36,     0,    37,     0,     0,     0,     0,
      38,     0,    39,    40,     0,     0,     0,     0,    48,     0,
      49,     0,    50,   149,     0,     0,    41,    42,     0,    54,
      55,    56,    57,    58,     0,     0,     0,     0,     0,     0,
       0,    62,     0,     0,     0,     0,    67,    68,    69,    70,
      45,   158,    47,     0,     0,     0,     0,     0,     0,    51,
      52,     0,     0,     0,    53,     0,     0,     0,     0,     0,
       0,    59,     0,     0,     0,    60,    61,     0,    63,     1,
       0,    66,    67,     0,     0,    70,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,   170,     0,     0,     0,     0,    35,
       0,    36,     0,    37,     0,     0,     0,     0,    38,     0,
      39,    40,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,     0,     0,    41,    42,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,   158,
      47,     0,     0,    33,   178,     0,     0,    51,    52,    35,
       0,    36,    53,    37,     0,     0,     0,     0,    38,    59,
      39,    40,     0,    60,    61,     0,    63,     0,     0,    66,
      67,     0,     0,    70,    41,    42,     1,     0,     0,     2,
       3,   287,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    45,   158,
      47,     0,     0,     0,     0,     0,     0,    51,    52,     0,
       0,     0,    53,     0,     0,     0,     0,     0,     0,    59,
       0,     0,     0,    60,    61,     0,    63,     0,     0,    66,
      67,     1,     0,    70,     2,     3,   287,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,     0,   366,   149,     0,     0,     0,     0,     0,
      54,     0,    56,    57,     0,     0,     0,     0,     0,     0,
       0,     0,   192,     0,     0,     0,     0,   367,     0,    69,
      70,     1,   674,     0,     2,     3,   287,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,    48,     0,     0,     0,    50,   149,
       0,     0,     0,     0,     0,    54,     0,    56,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,     1,    69,    70,     2,     3,   287,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,     0,    50,   149,
       0,     0,     0,     0,     0,    54,     0,    56,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,    67,     0,    69,    70,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,    48,     0,     0,     0,
      50,   149,     0,     0,     0,     0,     0,    54,     0,    56,
      57,     0,   290,     0,     0,     0,     0,   291,     0,     0,
       1,     0,     0,     0,    67,     0,    69,    70,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   617,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   290,    50,   149,     0,     0,   291,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
       0,     0,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,   149,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,     0,     0,    70
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const unsigned char yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,     0,
      25,     0,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,     0,     0,   141,     0,   167,   143,     0,     0,   193,
       0,     0,     0,     0,   195,     0,     0,     0,     0,     0,
       0,     0,     0,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   105,     0,     0,
       0,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,   155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   157,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,   145,     0,     0,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   173,     0,
       0,     0,     0,   151,     0,     0,     0,     0,     0,     0,
     111,   175,     0,   177,     0,    39,   179,     0,   181,     0,
       0,     0,   113,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   185,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,     0,     0,
       0,    47,     0,     0,     0,     0,     0,     0,   159,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   107,   109,     0,
       0,     0,     0,     0,     0,   161,     0,     0,     0,     0,
       0,     0,     0,   125,     0,     0,     0,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   183,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     0,     0,     0,     5,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,     0,     0,
       0,     0,     0,     0,     0,     0,    67,     0,     0,     0,
       0,    69,     0,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    73,     0,     0,     0,     0,     0,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,    87,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,     0,     0,
       0,     0,     0,     0,     0,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
       0,     0,     0,     0,     0,     0,   129,     0,     0,     0,
       0,   131,     0,   133,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,     0,     0,     0,     0,     0,     0,     0,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   139,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
       0,    51,     0,     0,     0,     0,    53,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    57,     0,     0,
       0,     0,     0,     0,     0,    59,     0,     0,     0,    79,
       0,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   149,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   189,     0,     0,     0,     0,   191,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,   101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] =
{
       0,   195,     0,   195,     0,   195,     0,   195,     0,   195,
       0,   195,     0,   195,     0,    70,     0,   315,     0,    29,
       0,   195,     0,   251,     0,    27,     0,    26,     0,   109,
       0,   175,     0,   196,     0,   205,     0,   229,     0,    32,
       0,   224,     0,   195,     0,   195,     0,    26,     0,   195,
       0,   195,     0,   195,     0,   195,     0,   195,     0,   195,
       0,   195,     0,   315,     0,   195,     0,   195,     0,   195,
       0,   195,     0,   195,     0,   195,     0,   195,     0,   286,
       0,    15,     0,   195,     0,   195,     0,   195,     0,   195,
       0,   195,     0,   195,     0,   195,     0,   195,     0,   358,
       0,   358,     0,   367,     0,    27,     0,    28,     0,    75,
       0,    27,     0,    27,     0,    27,     0,   262,     0,   195,
       0,   315,     0,    27,     0,    33,     0,   195,     0,   195,
       0,   195,     0,   195,     0,   195,     0,   195,     0,   195,
       0,   286,     0,   286,     0,   359,     0,   359,     0,   195,
       0,   321,     0,   286,     0,    32,     0,    32,     0,   110,
       0,   111,     0,   251,     0,   195,     0,    27,     0,   278,
       0,   278,     0,   278,     0,   278,     0,   278,     0,   278,
       0,   278,     0,   286,     0,   286,     0,   286,     0,    80,
       0,    80,     0,    80,     0,    80,     0
};

static const short int yycheck[] =
{
       0,     0,    34,    27,    55,   137,    34,    39,   182,   113,
      27,   290,     0,    20,   433,   441,    59,   429,   175,    51,
      84,   224,     4,    27,    47,   305,    47,    20,   101,    47,
      93,   156,   305,    94,    34,   395,    39,    93,   334,   164,
      38,   303,   304,    38,    38,   164,    34,    62,    80,    81,
      90,   124,   238,    39,    38,    38,   119,   113,   305,    59,
     185,   232,    62,    54,   490,    38,   185,   305,   239,    54,
      93,    59,   230,    38,    62,    93,    38,    75,    76,    47,
     114,    79,    47,    77,    52,    47,    72,    52,   246,   247,
      52,    94,    90,    56,    77,    79,   119,    43,   119,    45,
      75,   119,    93,   114,    31,   137,    38,    34,    93,    77,
     101,   154,   155,   113,   157,    77,    59,    93,    93,    54,
     152,    93,   113,   309,   122,   113,   141,    90,   113,    72,
     137,   103,   147,   101,    93,    93,   101,    38,   170,   101,
     112,   141,   170,   119,   137,    77,   178,   147,   427,   307,
     429,   354,    38,   141,   154,   155,   156,   157,    93,   147,
     119,   119,   190,   191,   164,   164,   154,   155,   156,   157,
     170,    73,   358,   224,   454,   175,   164,   241,   193,   539,
     305,   454,   170,   463,   184,   185,   185,   175,   252,   253,
     190,   191,   378,   193,   222,   223,   184,   185,   494,   231,
     325,   229,   190,   191,   186,   193,   325,   454,    73,   635,
     381,   368,   246,   247,   510,    93,   454,    93,    93,   219,
     632,    47,   222,   223,   224,   101,    52,   154,   155,   229,
     157,   219,   651,    39,   222,   223,   224,   649,   441,    59,
     233,   229,    99,   170,    39,    56,    39,    38,    39,    39,
     669,   178,    72,   246,   247,   289,    38,    38,   390,    79,
     292,    39,    39,    39,   368,    47,    72,   301,    59,   333,
      52,    56,    54,    93,   460,   101,   310,    72,   321,    72,
     101,    72,    72,    74,   318,    93,    77,   490,    79,   323,
     301,    73,   101,   101,    72,    72,    72,    72,   119,    56,
     343,    76,   229,   354,   101,   305,    38,   318,   668,    20,
     119,    93,   323,   516,   111,    47,   119,   305,   318,   101,
      52,   321,    54,   250,    72,   325,   325,   124,    56,   454,
     318,   113,    33,   321,   368,    75,    75,   325,    72,    79,
      41,    42,    90,   343,    78,   272,   389,    38,    59,   535,
     365,    62,   614,   632,   354,   343,    67,   368,   390,   366,
     367,    93,   362,   395,   357,   365,   354,   629,   368,   101,
     649,   101,    72,   547,   362,   175,    38,   365,    78,    72,
     368,   113,     0,    76,    94,    47,    47,    48,    49,   389,
      52,    62,    54,    52,   321,    38,    93,   431,   530,   101,
     434,   389,   113,   114,    47,    56,    57,    58,    59,    52,
      50,    54,   114,   115,   116,    77,    38,   451,   442,   219,
     431,   254,   255,   256,   126,   442,   137,   461,   462,    53,
     141,    93,   635,     0,   154,   155,   147,   157,    38,   101,
     451,   441,    40,    41,    66,    67,    68,    69,   104,   105,
      93,   113,    38,   441,   454,    77,    60,    61,   101,    75,
     494,   525,    72,    73,   175,   516,   454,   491,    20,    21,
     113,    63,    64,    93,   491,    38,   510,    56,   512,   190,
     191,    93,   193,   494,    47,    56,    57,    58,    59,    52,
     490,    54,   257,   258,   494,   259,   260,   497,   530,   527,
      75,   512,   490,   265,   266,   114,   494,   514,   219,   497,
      90,   222,   223,   224,    38,    38,   516,    38,   542,   114,
     115,   116,   233,    72,   235,   542,    73,   527,   516,   529,
      93,    73,    56,    39,   334,   246,   247,   337,   101,   527,
      39,   529,   585,   577,   578,    38,   580,    56,    72,    73,
     113,   461,   462,    77,   119,    79,    56,    93,    38,   583,
     101,   361,    56,    57,    58,    59,   583,    72,   368,   261,
     262,   263,   264,    93,    93,   603,   604,   101,   289,   583,
      93,    73,    39,    39,    39,   585,    93,    39,    75,    59,
     301,    72,    59,    59,   305,    59,   630,   585,    59,   310,
      39,    73,   100,   603,   604,    93,   640,   318,    56,    78,
      39,   119,   323,   637,   638,   603,   604,   101,    72,    39,
     637,   638,     0,   334,    75,    20,   337,    90,    39,   640,
      39,    73,   343,   637,   638,   635,    76,    90,    72,    76,
     126,    72,   666,   354,    79,    47,   357,   635,    73,   666,
     361,    79,    79,    39,   365,    39,   367,   368,   585,    73,
      73,    38,   666,    38,    59,    59,    38,    62,    38,   596,
     597,   699,    67,    79,   601,   602,   704,    93,   389,    79,
     289,    79,    79,    73,    62,   396,    73,    38,   399,   119,
     617,    64,   301,    54,   494,    38,    72,    39,    78,   699,
      79,    75,    90,    74,   704,    72,    72,    39,    73,   318,
     510,   699,   512,    75,   323,    78,   704,    39,   113,   114,
     431,    79,    77,   434,    39,    39,    39,    38,   121,   529,
     441,    78,   101,   390,   387,   113,   247,   621,   242,   663,
     451,   267,   137,   454,   269,   491,   141,   585,   270,   156,
     461,   462,   147,   268,   271,   156,   501,   582,   431,   368,
     548,   490,   578,   141,   454,   435,   640,   630,    51,   147,
     497,   362,   516,   680,   432,    -1,    -1,    -1,   156,   490,
     175,    -1,    -1,   494,    -1,    -1,   164,   396,    -1,    -1,
     399,    -1,    -1,    -1,    -1,   190,   191,   175,   193,   510,
      -1,   512,    -1,    -1,    -1,   516,    -1,   185,    -1,    -1,
      -1,   184,    -1,    -1,    -1,   193,   527,    -1,   529,    -1,
      -1,   621,   431,    -1,   219,    -1,    -1,   222,   223,   224,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   233,    -1,
     235,   219,   451,    -1,    -1,    -1,   224,    -1,    -1,    -1,
      -1,   246,   247,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   577,   578,    -1,   580,
      -1,    -1,   245,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,   494,    -1,    -1,    -1,    -1,
      -1,    -1,   603,   604,   289,    -1,    -1,    -1,    -1,    -1,
      -1,   510,    -1,   512,    -1,    -1,   301,    -1,    -1,    -1,
     621,   284,   285,    -1,    -1,   310,    -1,    -1,    -1,   630,
      -1,    -1,    -1,   318,   635,    -1,    -1,   305,   323,   640,
     303,   304,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   334,
     318,    -1,   337,    -1,    -1,    -1,    -1,   325,   343,    -1,
      -1,   662,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   354,
      -1,    -1,   357,    -1,    -1,    -1,   361,    -1,    -1,    -1,
     365,    -1,   367,   368,    -1,    -1,   354,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   365,   699,   362,
     368,    -1,    -1,   704,   389,    -1,    -1,    -1,    -1,    -1,
      -1,   396,    -1,    -1,   399,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    -1,   387,    -1,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   640,    -1,    -1,    -1,    -1,   431,    -1,    -1,   434,
      -1,    -1,    -1,    -1,    38,    -1,   441,    -1,    -1,    -1,
      -1,    -1,    -1,   662,    -1,    -1,   451,    -1,    -1,    -1,
     433,    -1,    -1,   441,    -1,    -1,   461,   462,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    -1,   454,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,   494,
      -1,    -1,    -1,    -1,    38,    39,   100,   101,    -1,    -1,
      -1,    -1,   490,    47,    -1,   510,   494,   512,    52,   492,
      54,   516,    -1,    -1,   497,    -1,    -1,    -1,    -1,    -1,
     124,    -1,   527,   127,   529,    -1,    -1,    -1,   516,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   529,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,   534,    -1,    -1,    -1,    -1,   100,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   548,    -1,    -1,    -1,   113,
      -1,    -1,   577,   578,    -1,   580,    -1,    -1,    -1,    -1,
     124,    -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   603,   604,
      -1,   584,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   621,    -1,    -1,    -1,
      -1,    -1,   605,   606,    -1,   630,    -1,    -1,    -1,    -1,
     635,   614,    -1,    -1,    -1,   640,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   629,   635,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   662,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,   651,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,   669,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   699,    -1,    -1,     3,    -1,   704,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,    45,
      -1,    47,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
      -1,    -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,    -1,    -1,   127,    92,    93,    94,    -1,
      96,    -1,    98,    -1,   100,   101,   102,    -1,    -1,    -1,
     106,   107,   108,   109,   110,   111,    -1,   113,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,     3,    -1,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    43,    -1,    45,    -1,    47,    -1,    -1,    -1,
      -1,    52,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    -1,
      -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    -1,    96,    -1,    98,    -1,   100,
     101,   102,    -1,    -1,    -1,   106,   107,    -1,   109,   110,
     111,    -1,   113,    -1,    -1,    -1,   117,   118,    -1,   120,
     121,   122,   123,   124,   125,   126,   127,     3,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,    45,
      -1,    47,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    -1,
      96,    -1,    98,    -1,   100,   101,   102,    -1,    -1,    -1,
     106,   107,    -1,   109,   110,   111,    -1,   113,    -1,    -1,
      -1,   117,   118,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,     3,    -1,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    43,    -1,    45,    -1,    47,    -1,    -1,    -1,
      -1,    52,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    -1,
      -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    -1,    96,    -1,    98,    -1,   100,
     101,   102,    -1,    -1,    -1,   106,   107,    -1,   109,   110,
     111,    -1,   113,    -1,    -1,    -1,   117,   118,    -1,   120,
     121,   122,   123,   124,   125,   126,   127,     3,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,    45,
      -1,    47,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    92,    93,    94,    -1,
      96,    -1,    -1,    -1,   100,   101,   102,    -1,    -1,    38,
     106,   107,    -1,   109,   110,    -1,    -1,   113,    47,    -1,
      -1,   117,   118,    52,   120,   121,     3,   123,   124,    -1,
     126,   127,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    -1,    -1,    -1,    43,    -1,    45,    -1,
      47,   100,   101,    -1,    -1,    52,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    -1,    -1,   124,    -1,    -1,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    -1,    -1,
      -1,    -1,    -1,   100,   101,   102,    -1,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
     117,   118,    -1,   120,   121,     3,   123,   124,    -1,    -1,
     127,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    43,    -1,    45,    -1,    47,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,     3,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   100,   101,     3,    -1,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   124,    -1,    -1,   127,
      -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    94,    -1,    96,
      -1,    98,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,
     107,   108,   109,   110,   111,    -1,    -1,    76,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      -1,   100,   101,    -1,    74,    -1,    -1,    -1,   107,   108,
     109,   110,    -1,    -1,    -1,   114,   115,   116,    -1,    -1,
     119,    -1,    -1,    -1,    -1,   124,   125,   126,   127,     3,
     100,   101,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,   124,    -1,    -1,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,    -1,
      54,     3,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    -1,    96,    -1,    -1,    -1,   100,   101,    -1,    -1,
      -1,    -1,    -1,   107,    -1,   109,   110,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
     124,    -1,   126,   127,    76,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,   100,   101,
      -1,    -1,    -1,    -1,    39,   107,   108,   109,   110,    -1,
      -1,    -1,   114,   115,   116,    -1,    -1,   119,     3,    -1,
      -1,    -1,   124,   125,   126,   127,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,
      45,    -1,    47,    -1,    -1,   100,   101,    52,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    -1,    -1,    -1,    -1,   124,
      75,    76,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,    -1,   117,   118,    -1,   120,   121,     3,   123,   124,
      -1,    -1,   127,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,    45,
      -1,    47,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,
      -1,   117,   118,    -1,   120,   121,     3,   123,   124,    -1,
      -1,   127,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    -1,    -1,    -1,    43,    -1,    45,    -1,
      47,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,   101,   102,    -1,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
     117,   118,    -1,   120,   121,    -1,   123,   124,     3,    -1,
     127,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      40,    41,    -1,    43,    -1,    45,    -1,    47,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,     3,    -1,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    98,    -1,   100,   101,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,   110,   111,    -1,    -1,    -1,
      59,    -1,    -1,    -1,   119,     3,    -1,    -1,    -1,   124,
     125,   126,   127,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    37,
      38,   100,   101,    -1,    -1,    43,    -1,    45,   107,    47,
     109,   110,    -1,    -1,    52,    -1,    54,    55,    -1,    -1,
     119,    -1,    -1,    -1,    -1,   124,    -1,   126,   127,    -1,
      68,    69,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,   101,   102,    -1,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,   117,
     118,    -1,   120,   121,     3,   123,   124,    -1,    -1,   127,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,    43,    -1,    45,    -1,    47,    -1,
      -1,    -1,    -1,    52,    -1,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    68,
      69,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,   101,   102,    -1,    -1,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,   117,   118,
      -1,   120,   121,    -1,   123,   124,     3,    -1,   127,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    98,    -1,   100,   101,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    98,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,
     107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,     3,    -1,    -1,    -1,   124,   125,   126,
     127,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      -1,    -1,    -1,    43,    -1,    45,    -1,    47,    -1,    -1,
      -1,    -1,    52,    -1,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    77,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,
      -1,   101,   102,    -1,    -1,    38,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    47,    -1,    -1,   117,   118,    52,
     120,    54,    -1,   123,   124,     3,    -1,   127,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,     3,    -1,    -1,    -1,    -1,    -1,   100,   101,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,    -1,    -1,   127,    37,    38,    -1,    -1,    -1,
      -1,    43,    -1,    45,    -1,    47,    -1,    -1,    -1,    -1,
      52,    -1,    54,    55,    -1,    -1,    -1,    -1,    96,    -1,
      98,    -1,   100,   101,    -1,    -1,    68,    69,    -1,   107,
     108,   109,   110,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,    -1,    -1,    -1,   124,   125,   126,   127,
      92,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,
     102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,    -1,   117,   118,    -1,   120,     3,
      -1,   123,   124,    -1,    -1,   127,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    43,
      -1,    45,    -1,    47,    -1,    -1,    -1,    -1,    52,    -1,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    -1,    68,    69,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    -1,    -1,    37,    38,    -1,    -1,   101,   102,    43,
      -1,    45,   106,    47,    -1,    -1,    -1,    -1,    52,   113,
      54,    55,    -1,   117,   118,    -1,   120,    -1,    -1,   123,
     124,    -1,    -1,   127,    68,    69,     3,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    92,    93,
      94,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,
      -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,   117,   118,    -1,   120,    -1,    -1,   123,
     124,     3,    -1,   127,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,
     107,    -1,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,    -1,   124,    -1,   126,
     127,     3,    74,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    96,    -1,    -1,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,   107,    -1,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,     3,   126,   127,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,   107,    -1,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,   124,    -1,   126,   127,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,
     100,   101,    -1,    -1,    -1,    -1,    -1,   107,    -1,   109,
     110,    -1,    47,    -1,    -1,    -1,    -1,    52,    -1,    -1,
       3,    -1,    -1,    -1,   124,    -1,   126,   127,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,   100,   101,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
      -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,    -1,    -1,   127
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,     3,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    43,    45,    47,    52,    54,
      55,    68,    69,    75,    76,    92,    93,    94,    96,    98,
     100,   101,   102,   106,   107,   108,   109,   110,   111,   113,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   130,   131,   132,   134,   135,   136,   137,   138,   139,
     140,   142,   145,   148,   149,   150,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   175,   178,   179,   180,   181,   185,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     201,   202,   203,   209,   210,   211,   212,   214,   216,   218,
     219,   220,   229,   242,   247,   248,   249,   250,   265,   272,
     274,   275,   279,   283,   284,   285,   290,   132,    93,   101,
     139,   140,   142,   200,    38,    38,    38,    38,    93,   171,
     172,   176,   199,   202,    90,    73,    73,   175,   182,    93,
      38,   148,   175,   197,   231,   232,   247,   247,    38,   148,
     148,    99,   287,   288,    56,    90,    38,   113,   247,   272,
      56,    56,   119,   275,    75,    93,    40,    41,    43,    45,
      47,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,   139,   199,   202,   232,
     266,   273,    56,    56,    56,   189,   190,   173,    75,    38,
     139,   142,   101,   111,   124,   217,     0,    94,   119,   141,
     247,   103,   112,   143,   247,    38,    66,    67,    68,    69,
      77,   160,   104,   105,    47,    48,    49,    43,    45,    40,
      41,    56,    57,    58,    59,    60,    61,    52,    50,    53,
      62,    63,    64,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,   174,    72,    73,     8,   192,    38,
      47,    52,    54,   134,   139,   198,   221,   222,   223,   224,
     225,   226,   230,    38,    38,    75,    93,   140,   143,   144,
     200,   189,    75,   189,    93,    75,   175,   183,   232,   183,
     180,   186,   191,   194,   183,    90,   111,   178,   190,    73,
      73,   231,    39,    39,    38,   139,   197,   226,   233,   234,
     235,   236,    39,    38,   288,   173,   231,   280,   281,   282,
     178,   132,   231,   231,    56,   189,    75,    79,   119,   226,
     267,   268,    56,   231,   231,    59,   100,   124,   193,   241,
     275,   276,   277,   278,   175,   231,    93,   119,   141,   135,
     140,   139,    93,   279,   135,    77,   160,    38,   151,   152,
     101,   133,   146,   173,   139,   140,   141,   147,   198,   141,
     147,   175,   160,   160,   161,   161,   161,   162,   162,   163,
     163,   164,   164,   164,   164,   165,   165,   166,   167,   168,
     169,   170,   175,   173,   173,   224,   227,   228,   229,    47,
      73,    72,    76,    79,    90,   122,   151,   243,   244,   269,
     286,    38,    77,   224,   133,   133,   114,   115,   116,   125,
     137,   194,   216,   251,   252,   253,   254,   262,   274,    93,
     141,    93,   279,   126,   198,   259,   260,   261,   262,    93,
     204,   205,   206,   207,    39,   139,   198,   224,    39,   183,
     184,   224,    39,   178,    93,    39,   160,   139,   233,   234,
      38,    77,    75,    74,   232,   289,    59,    72,    39,    59,
      59,   140,   215,   226,   280,    59,    59,   189,   200,   200,
      38,   224,   226,   234,   100,    59,    72,    39,    39,   279,
      73,    93,   208,   213,   135,    78,   146,    38,   153,   232,
     119,   143,   144,    39,    72,   119,   136,   134,   139,   101,
     134,    78,    90,    39,   229,   227,   223,   287,    75,   173,
     245,   198,   270,   271,   269,    75,   237,   239,   240,   241,
     176,   177,    39,    39,    73,   200,   224,   255,   256,   257,
      76,   253,    90,   279,   259,   259,   262,   263,    72,   126,
     264,    76,    72,    79,    79,    73,    39,   237,   177,   245,
     246,   224,   233,    39,   282,    73,    38,    38,   208,    73,
      59,    38,    38,    79,    79,    79,    79,   200,   277,    73,
      73,   160,    39,   231,    38,   157,   158,    77,   154,   155,
     156,   226,   143,   173,   279,   136,   172,    76,   246,    38,
      72,    75,    39,    74,   238,    72,    78,    90,    79,   258,
      72,    73,   198,   261,   198,   206,   176,   173,   184,    39,
      78,    72,    76,    75,   175,   175,   175,   175,   231,   231,
     173,   173,    79,    39,   133,   175,    77,   155,   101,    72,
      76,   133,   271,   227,    74,   241,   176,   176,   257,    39,
     227,    76,   245,    39,    39,    39,    39,   134,   158,    39,
      78,   176,   136,    76,    39,   121,   291,   291,    78,    38,
      39,   231,   292,    39,    72,   231
};


/* Prevent warning if -Wmissing-prototypes.  */
int yyparse (void);

/* Error token number */
#define YYTERROR 1

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */


#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N) ((void) 0)
#endif


#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#define YYLEX yylex ()

YYSTYPE yylval;

YYLTYPE yylloc;

int yynerrs;
int yychar;

static const int YYEOF = 0;
static const int YYEMPTY = -2;

typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;

#define YYCHK(YYE)							     \
   do { YYRESULTTAG yyflag = YYE; if (yyflag != yyok) return yyflag; }	     \
   while (YYID (0))

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			    \
do {									    \
  if (yydebug)								    \
    {									    \
      YYFPRINTF (stderr, "%s ", Title);					    \
      yy_symbol_print (stderr, Type,					    \
		       Value);  \
      YYFPRINTF (stderr, "\n");						    \
    }									    \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

#else /* !YYDEBUG */

# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)

#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
# if (! defined __cplusplus \
      || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL))
#  define YYSTACKEXPANDABLE 1
# else
#  define YYSTACKEXPANDABLE 0
# endif
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)			\
  do {							\
    if (Yystack->yyspaceLeft < YYHEADROOM)		\
      yyexpandGLRStack (Yystack);			\
  } while (YYID (0))
#else
# define YY_RESERVE_GLRSTACK(Yystack)			\
  do {							\
    if (Yystack->yyspaceLeft < YYHEADROOM)		\
      yyMemoryExhausted (Yystack);			\
  } while (YYID (0))
#endif


#if YYERROR_VERBOSE

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static size_t
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return strlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* !YYERROR_VERBOSE */

/** State numbers, as in LALR(1) machine */
typedef int yyStateNum;

/** Rule numbers, as in LALR(1) machine */
typedef int yyRuleNum;

/** Grammar symbol */
typedef short int yySymbol;

/** Item references, as in LALR(1) machine */
typedef short int yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState {
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yysval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yyStateNum yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the first token produced by my symbol */
  size_t yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  non-terminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yysval;
  } yysemantics;
  /** Source location for this state.  */
  YYLTYPE yyloc;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  size_t yysize, yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  size_t yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

static void yyFail (yyGLRStack* yystackp, const char* yymsg)
  __attribute__ ((__noreturn__));
static void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != NULL)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

static void yyMemoryExhausted (yyGLRStack* yystackp)
  __attribute__ ((__noreturn__));
static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

#if YYDEBUG || YYERROR_VERBOSE
/** A printable representation of TOKEN.  */
static inline const char*
yytokenName (yySymbol yytoken)
{
  if (yytoken == YYEMPTY)
    return "";

  return yytname[yytoken];
}
#endif

/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) __attribute__ ((__unused__));
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  yyGLRState* s;
  int i;
  s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
      YYASSERT (s->yyresolved);
      yyvsp[i].yystate.yyresolved = yytrue;
      yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
      yyvsp[i].yystate.yyloc = s->yyloc;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     __attribute__ ((__unused__));
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT.  */
/*ARGSUSED*/ static YYRESULTTAG
yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
	      YYSTYPE* yyvalp,
	      YYLTYPE* YYOPTIONAL_LOC (yylocp),
	      yyGLRStack* yystackp
	      )
{
  yybool yynormal __attribute__ ((__unused__)) =
    (yystackp->yysplitPoint == NULL);
  int yylow;
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, N, yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)						     \
  return yyerror (YY_("syntax error: cannot back up")),     \
	 yyerrok, yyerr

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
  YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);

  switch (yyn)
    {
        case 2:
#line 298 "cppgram.y"
    {
#if STMT_DEBUG
              printf("declaration\n");
#endif
              seen_term_tok=TRUE;
	      cnt_rule(yyn);
              ;}
    break;

  case 3:
#line 306 "cppgram.y"
    {
#if STMT_DEBUG
              printf("statement\n");
#endif
	      seen_term_tok=TRUE;
	      cnt_rule(yyn);
              ;}
    break;

  case 4:
#line 318 "cppgram.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 5:
#line 323 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(INTEGER_CONST);
              cnt_rule(yyn);
              ;}
    break;

  case 6:
#line 328 "cppgram.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 7:
#line 333 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_THIS);
              cnt_rule(yyn);
              ;}
    break;

  case 8:
#line 338 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_unary_node(TOK_OPEN_RND, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 9:
#line 348 "cppgram.y"
    {
            ((*yyvalp)).node_ptr=mk_leaf_node(STRING_CONST);
            cnt_rule(yyn);
            ;}
    break;

  case 10:
#line 353 "cppgram.y"
    {
            ((*yyvalp)).node_ptr=mk_binary_node(TOK_STRING_CONCAT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval).node_ptr,
					mk_leaf_node(STRING_CONST));
            cnt_rule(yyn);
            ;}
    break;

  case 11:
#line 360 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=NULL;
	      cnt_rule(yyn);
              ;}
    break;

  case 12:
#line 365 "cppgram.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 34:
#line 432 "cppgram.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 35:
#line 437 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_OPEN_SQUARE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 36:
#line 442 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_FUNC_CALL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 37:
#line 466 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_unary_node(TOK_POST_PLUS, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 38:
#line 471 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_unary_node(TOK_POST_MINUS, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 39:
#line 476 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_CMPD_INIT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 40:
#line 481 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_CMPD_INIT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (7))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 53:
#line 504 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_ARG, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval).node_ptr, NULL);
              cnt_rule(yyn);
              ;}
    break;

  case 54:
#line 509 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_ARG, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 58:
#line 526 "cppgram.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 59:
#line 531 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_unary_node(TOK_PRE_PLUS, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 60:
#line 536 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_unary_node(TOK_PRE_MINUS, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 61:
#line 541 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_unary_node((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval).tok, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 62:
#line 550 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_unary_node(TOK_SIZEOF, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 63:
#line 555 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_unary_node(TOK_SIZEOF, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 66:
#line 564 "cppgram.y"
    {
	      ((*yyvalp)).tok=TOK_ADDR;
              cnt_rule(yyn);
              ;}
    break;

  case 67:
#line 569 "cppgram.y"
    {
              ((*yyvalp)).tok=TOK_STAR;
              cnt_rule(yyn);
              ;}
    break;

  case 68:
#line 574 "cppgram.y"
    {
              ((*yyvalp)).tok=TOK_PLUS;
              cnt_rule(yyn);
              ;}
    break;

  case 69:
#line 579 "cppgram.y"
    {
              ((*yyvalp)).tok=TOK_ARITH_NEG;
              cnt_rule(yyn);
              ;}
    break;

  case 70:
#line 584 "cppgram.y"
    {
              ((*yyvalp)).tok=TOK_BIT_NOT;
              cnt_rule(yyn);
              ;}
    break;

  case 71:
#line 589 "cppgram.y"
    {
              ((*yyvalp)).tok=TOK_LOG_NOT;
              cnt_rule(yyn);
              ;}
    break;

  case 89:
#line 638 "cppgram.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 90:
#line 643 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_CAST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 94:
#line 663 "cppgram.y"
    {
	      ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 95:
#line 668 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_TIMES, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 96:
#line 673 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_DIVIDE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 97:
#line 678 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_REMAINDER, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 98:
#line 695 "cppgram.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 99:
#line 700 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_ADD, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 100:
#line 705 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_MINUS, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 101:
#line 712 "cppgram.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 102:
#line 717 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_LSHIFT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 103:
#line 722 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_RSHIFT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 104:
#line 729 "cppgram.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 105:
#line 734 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_LESS_THAN, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 106:
#line 739 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_GREATER_THAN, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 107:
#line 744 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_LESS_EQUAL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 108:
#line 749 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_GR_EQUAL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 109:
#line 756 "cppgram.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 110:
#line 761 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_EQ_EQUAL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 111:
#line 766 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_EXC_EQUAL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 112:
#line 781 "cppgram.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 113:
#line 786 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_BIT_AND, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 114:
#line 793 "cppgram.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 115:
#line 798 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_BIT_XOR, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 116:
#line 805 "cppgram.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 117:
#line 810 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_BIT_OR, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 118:
#line 817 "cppgram.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 119:
#line 822 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_LOG_AND, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 120:
#line 829 "cppgram.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 121:
#line 834 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_LOG_OR, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 122:
#line 841 "cppgram.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 123:
#line 846 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_QUESTION, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval).node_ptr,
				mk_binary_node(TOK_COLON, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval).node_ptr));
              cnt_rule(yyn);
              ;}
    break;

  case 124:
#line 854 "cppgram.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 125:
#line 859 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).tok, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 126:
#line 864 "cppgram.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 127:
#line 871 "cppgram.y"
    {
              ((*yyvalp)).tok=TOK_EQUAL;
              cnt_rule(yyn);
              ;}
    break;

  case 128:
#line 876 "cppgram.y"
    {
              ((*yyvalp)).tok=TOK_MULT_EQUAL;
              cnt_rule(yyn);
              ;}
    break;

  case 129:
#line 881 "cppgram.y"
    {
              ((*yyvalp)).tok=TOK_DIV_EQUAL;
              cnt_rule(yyn);
              ;}
    break;

  case 130:
#line 886 "cppgram.y"
    {
              ((*yyvalp)).tok=TOK_REM_EQUAL;
              cnt_rule(yyn);
              ;}
    break;

  case 131:
#line 891 "cppgram.y"
    {
              ((*yyvalp)).tok=TOK_PLUS_EQUAL;
              cnt_rule(yyn);
              ;}
    break;

  case 132:
#line 896 "cppgram.y"
    {
              ((*yyvalp)).tok=TOK_MIN_EQUAL;
              cnt_rule(yyn);
              ;}
    break;

  case 133:
#line 901 "cppgram.y"
    {
              ((*yyvalp)).tok=TOK_LSH_ASSIGN;
              cnt_rule(yyn);
              ;}
    break;

  case 134:
#line 906 "cppgram.y"
    {
              ((*yyvalp)).tok=TOK_RSH_ASSIGN;
              cnt_rule(yyn);
              ;}
    break;

  case 135:
#line 911 "cppgram.y"
    {
              ((*yyvalp)).tok=TOK_AND_ASSIGN;
              cnt_rule(yyn);
              ;}
    break;

  case 136:
#line 916 "cppgram.y"
    {
              ((*yyvalp)).tok=TOK_BOR_ASSIGN;
              cnt_rule(yyn);
              ;}
    break;

  case 137:
#line 921 "cppgram.y"
    {
              ((*yyvalp)).tok=TOK_BXOR_ASSIGN;
              cnt_rule(yyn);
              ;}
    break;

  case 138:
#line 928 "cppgram.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 139:
#line 933 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_COMMA, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
	      cnt_rule(yyn);
              ;}
    break;

  case 140:
#line 940 "cppgram.y"
    {
	      ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
	      ;}
    break;

  case 143:
#line 954 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 144:
#line 958 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 145:
#line 962 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 146:
#line 966 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 147:
#line 975 "cppgram.y"
    {
              print_stmt("OC");
              cnt_rule(yyn);
              ;}
    break;

  case 148:
#line 980 "cppgram.y"
    {
              print_stmt("CC");
              cnt_rule(yyn);
              ;}
    break;

  case 149:
#line 985 "cppgram.y"
    {
              print_stmt("EL");
              cnt_rule(yyn);
              ;}
    break;

  case 150:
#line 990 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 153:
#line 998 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 154:
#line 1002 "cppgram.y"
    {
              got_expression(CASE_LAB_CE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval).node_ptr);
              free_tree((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 155:
#line 1008 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 156:
#line 1018 "cppgram.y"
    {
              print_stmt("ES");
              got_expression(EXPR_STMT_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval).node_ptr);
              free_tree((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval).node_ptr);
	          cnt_rule(yyn);
              ;}
    break;

  case 157:
#line 1041 "cppgram.y"
    {
              print_stmt("IF");
              got_expression(IF_EXPR_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval).node_ptr);
              free_tree((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval).node_ptr);
	      cnt_rule(yyn);
              ;}
    break;

  case 158:
#line 1048 "cppgram.y"
    {
              print_stmt("SW");
              got_expression(SWITCH_EXPR_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval).node_ptr);
              free_tree((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval).node_ptr);
	      cnt_rule(yyn);
              ;}
    break;

  case 159:
#line 1056 "cppgram.y"
    {
              ((*yyvalp)).node_ptr=NULL;
              cnt_rule(yyn);
              ;}
    break;

  case 160:
#line 1061 "cppgram.y"
    {
	      cnt_rule(yyn);
              ;}
    break;

  case 165:
#line 1085 "cppgram.y"
    {
              print_stmt("WH");
              got_expression(WHILE_EXPR_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval).node_ptr);
              free_tree((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval).node_ptr);
	      cnt_rule(yyn);
              ;}
    break;

  case 166:
#line 1092 "cppgram.y"
    {
              print_stmt("DO");
              cnt_rule(yyn);
              ;}
    break;

  case 167:
#line 1105 "cppgram.y"
    {
              print_stmt("FO");
              got_expression(FOR_INIT_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (7))].yystate.yysemantics.yysval).node_ptr);
              free_tree((((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (7))].yystate.yysemantics.yysval).node_ptr);
              got_expression(FOR_CNTRL_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (7))].yystate.yysemantics.yysval).node_ptr);
              free_tree((((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval).node_ptr);
              got_expression(FOR_INC_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (7))].yystate.yysemantics.yysval).node_ptr);
              free_tree((((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 170:
#line 1122 "cppgram.y"
    {
              print_stmt("GO");
              cnt_rule(yyn);
              ;}
    break;

  case 171:
#line 1127 "cppgram.y"
    {
              print_stmt("CO");
              cnt_rule(yyn);
              ;}
    break;

  case 172:
#line 1132 "cppgram.y"
    {
              print_stmt("BR");
              cnt_rule(yyn);
              ;}
    break;

  case 173:
#line 1137 "cppgram.y"
    {
              print_stmt("RE");
              got_expression(RETURN_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).node_ptr);
              free_tree((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 197:
#line 1195 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 198:
#line 1199 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 199:
#line 1203 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 200:
#line 1207 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 201:
#line 1211 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 214:
#line 1243 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 215:
#line 1247 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 216:
#line 1251 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 217:
#line 1255 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 218:
#line 1259 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 219:
#line 1263 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 220:
#line 1267 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 221:
#line 1271 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 222:
#line 1275 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 223:
#line 1279 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 224:
#line 1284 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 225:
#line 1288 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 284:
#line 1464 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 285:
#line 1468 "cppgram.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 315:
#line 1540 "cppgram.y"
    {
          ((*yyvalp)).node_ptr=mk_leaf_node(TOK_IDENTIFIER);
          cnt_rule(yyn);
          ;}
    break;


/* Line 930 of glr.c.  */
#line 3893 "cppgram.tab.c"
      default: break;
    }

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


/*ARGSUSED*/ static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YYUSE (yy0);
  YYUSE (yy1);

  switch (yyn)
    {
        case 1: *yy0 = multiplicative_merge (*yy0, *yy1); break;
  case 2: *yy0 = additive_merge (*yy0, *yy1); break;

      default: break;
    }
}

			      /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yystos[yys->yylrState],
		&yys->yysemantics.yysval);
  else
    {
#if YYDEBUG
      if (yydebug)
	{
	  if (yys->yysemantics.yyfirstVal)
	    YYFPRINTF (stderr, "%s unresolved ", yymsg);
	  else
	    YYFPRINTF (stderr, "%s incomplete ", yymsg);
	  yy_symbol_print (stderr, yystos[yys->yylrState],
			   NULL);
	  YYFPRINTF (stderr, "\n");
	}
#endif

      if (yys->yysemantics.yyfirstVal)
	{
	  yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
	  yyGLRState *yyrh;
	  int yyn;
	  for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
	       yyn > 0;
	       yyrh = yyrh->yypred, yyn -= 1)
	    yydestroyGLRState (yymsg, yyrh);
	}
    }
}

/** Left-hand-side symbol for rule #RULE.  */
static inline yySymbol
yylhsNonterm (yyRuleNum yyrule)
{
  return yyr1[yyrule];
}

#define yyis_pact_ninf(yystate) \
  ((yystate) == YYPACT_NINF)

/** True iff LR state STATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yyStateNum yystate)
{
  return yyis_pact_ninf (yypact[yystate]);
}

/** The default reduction for STATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yyStateNum yystate)
{
  return yydefact[yystate];
}

#define yyis_table_ninf(yytable_value) \
  YYID (0)

/** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *CONFLICTS to a pointer into yyconfl to 0-terminated list of
 *  conflicting reductions.
 */
static inline void
yygetLRActions (yyStateNum yystate, int yytoken,
		int* yyaction, const short int** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyaction = -yydefact[yystate];
      *yyconflicts = yyconfl;
    }
  else if (! yyis_table_ninf (yytable[yyindex]))
    {
      *yyaction = yytable[yyindex];
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
  else
    {
      *yyaction = 0;
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
}

static inline yyStateNum
yyLRgotoState (yyStateNum yystate, yySymbol yylhs)
{
  int yyr;
  yyr = yypgoto[yylhs - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yylhs - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

				/* GLRStates */

/** Return a fresh GLRStackItem.  Callers should call
 * YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 * headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  RULENUM on the semantic values in RHS to the list of
 *  alternative actions for STATE.  Assumes that RHS comes from
 *  stack #K of *STACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
		     yyGLRState* rhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  yynewOption->yystate = rhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
      yynewOption->yyloc = yylloc;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

				/* GLRStacks */

/** Initialize SET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates = (yyGLRState**) YYMALLOC (16 * sizeof yyset->yystates[0]);
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = NULL;
  yyset->yylookaheadNeeds =
    (yybool*) YYMALLOC (16 * sizeof yyset->yylookaheadNeeds[0]);
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize STACK to a single empty stack, with total maximum
 *  capacity for all stacks of SIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems =
    (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystackp->yynextFree[0]);
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = NULL;
  yystackp->yylastDeleted = NULL;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS,YYTOITEMS,YYX,YYTYPE) \
  &((YYTOITEMS) - ((YYFROMITEMS) - (yyGLRStackItem*) (YYX)))->YYTYPE

/** If STACK is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  size_t yysize, yynewSize;
  size_t yyn;
  yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems = (yyGLRStackItem*) YYMALLOC (yynewSize * sizeof yynewItems[0]);
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*(yybool *) yyp0)
	{
	  yyGLRState* yys0 = &yyp0->yystate;
	  yyGLRState* yys1 = &yyp1->yystate;
	  if (yys0->yypred != NULL)
	    yys1->yypred =
	      YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
	  if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != NULL)
	    yys1->yysemantics.yyfirstVal =
	      YYRELOC(yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
	}
      else
	{
	  yySemanticOption* yyv0 = &yyp0->yyoption;
	  yySemanticOption* yyv1 = &yyp1->yyoption;
	  if (yyv0->yystate != NULL)
	    yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
	  if (yyv0->yynext != NULL)
	    yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
	}
    }
  if (yystackp->yysplitPoint != NULL)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
				 yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != NULL)
      yystackp->yytops.yystates[yyn] =
	YYRELOC (yystackp->yyitems, yynewItems,
		 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that S is a GLRState somewhere on STACK, update the
 *  splitpoint of STACK, if needed, so that it is at least as deep as
 *  S.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != NULL && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #K in STACK.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yytops.yystates[yyk] != NULL)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = NULL;
}

/** Undelete the last stack that was marked as deleted.  Can only be
    done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == NULL || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = NULL;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  size_t yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == NULL)
	{
	  if (yyi == yyj)
	    {
	      YYDPRINTF ((stderr, "Removing dead stacks.\n"));
	    }
	  yystackp->yytops.yysize -= 1;
	}
      else
	{
	  yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
	  /* In the current implementation, it's unnecessary to copy
	     yystackp->yytops.yylookaheadNeeds[yyi] since, after
	     yyremoveDeletes returns, the parser immediately either enters
	     deterministic operation or shifts a token.  However, it doesn't
	     hurt, and the code might evolve to need it.  */
	  yystackp->yytops.yylookaheadNeeds[yyj] =
	    yystackp->yytops.yylookaheadNeeds[yyi];
	  if (yyj != yyi)
	    {
	      YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
			  (unsigned long int) yyi, (unsigned long int) yyj));
	    }
	  yyj += 1;
	}
      yyi += 1;
    }
}

/** Shift to a new state on stack #K of STACK, corresponding to LR state
 * LRSTATE, at input position POSN, with (resolved) semantic value SVAL.  */
static inline void
yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
	    size_t yyposn,
	    YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yysval = *yyvalp;
  yynewState->yyloc = *yylocp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #K of YYSTACK, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
		 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = NULL;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, rhs, yyrule);
}

/** Pop the symbols consumed by reduction #RULE from the top of stack
 *  #K of STACK, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *VALP to the resulting value,
 *  and *LOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
	    YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == NULL)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* rhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
      YYASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, rhs,
			   yyvalp, yylocp, yystackp);
    }
  else
    {
      /* At present, doAction is never called in nondeterministic
       * mode, so this branch is never taken.  It is here in
       * anticipation of a future feature that will allow immediate
       * evaluation of selected actions in nondeterministic mode.  */
      int yyi;
      yyGLRState* yys;
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
	= yystackp->yytops.yystates[yyk];
      for (yyi = 0; yyi < yynrhs; yyi += 1)
	{
	  yys = yys->yypred;
	  YYASSERT (yys);
	}
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
			   yyvalp, yylocp, yystackp);
    }
}

#if !YYDEBUG
# define YY_REDUCE_PRINT(Args)
#else
# define YY_REDUCE_PRINT(Args)		\
do {					\
  if (yydebug)				\
    yy_reduce_print Args;		\
} while (YYID (0))

/*----------------------------------------------------------.
| Report that the RULE is going to be reduced on stack #K.  |
`----------------------------------------------------------*/

/*ARGSUSED*/ static inline void
yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
		 YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  int yynrhs = yyrhsLength (yyrule);
  yybool yynormal __attribute__ ((__unused__)) =
    (yystackp->yysplitPoint == NULL);
  yyGLRStackItem* yyvsp = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
  int yylow = 1;
  int yyi;
  YYUSE (yyvalp);
  YYUSE (yylocp);
  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
	     (unsigned long int) yyk, yyrule - 1,
	     (unsigned long int) yyrline[yyrule]);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(((yyGLRStackItem const *)yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yysemantics.yysval)
		       		       );
      fprintf (stderr, "\n");
    }
}
#endif

/** Pop items off stack #K of STACK according to grammar rule RULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with RULE and store its value with the
 *  newly pushed state, if FORCEEVAL or if STACK is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #K from
 *  the STACK.  In this case, the (necessarily deferred) semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
	     yybool yyforceEval)
{
  size_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == NULL)
    {
      YYSTYPE yysval;
      YYLTYPE yyloc;

      YY_REDUCE_PRINT ((yystackp, yyk, yyrule, &yysval, &yyloc));
      YYCHK (yydoAction (yystackp, yyk, yyrule, &yysval,
			 &yyloc));
      YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
      yyglrShift (yystackp, yyk,
		  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
				 yylhsNonterm (yyrule)),
		  yyposn, &yysval, &yyloc);
    }
  else
    {
      size_t yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yyStateNum yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
	   0 < yyn; yyn -= 1)
	{
	  yys = yys->yypred;
	  YYASSERT (yys);
	}
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YYDPRINTF ((stderr,
		  "Reduced stack %lu by rule #%d; action deferred.  Now in state %d.\n",
		  (unsigned long int) yyk, yyrule - 1, yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
	if (yyi != yyk && yystackp->yytops.yystates[yyi] != NULL)
	  {
	    yyGLRState* yyp, *yysplit = yystackp->yysplitPoint;
	    yyp = yystackp->yytops.yystates[yyi];
	    while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
	      {
		if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
		  {
		    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
		    yymarkStackDeleted (yystackp, yyk);
		    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
				(unsigned long int) yyk,
				(unsigned long int) yyi));
		    return yyok;
		  }
		yyp = yyp->yypred;
	      }
	  }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static size_t
yysplitStack (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yysplitPoint == NULL)
    {
      YYASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yysize >= yystackp->yytops.yycapacity)
    {
      yyGLRState** yynewStates;
      yybool* yynewLookaheadNeeds;

      yynewStates = NULL;

      if (yystackp->yytops.yycapacity
	  > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
	yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      yynewStates =
	(yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
				  (yystackp->yytops.yycapacity
				   * sizeof yynewStates[0]));
      if (yynewStates == NULL)
	yyMemoryExhausted (yystackp);
      yystackp->yytops.yystates = yynewStates;

      yynewLookaheadNeeds =
	(yybool*) YYREALLOC (yystackp->yytops.yylookaheadNeeds,
			     (yystackp->yytops.yycapacity
			      * sizeof yynewLookaheadNeeds[0]));
      if (yynewLookaheadNeeds == NULL)
	yyMemoryExhausted (yystackp);
      yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize-1;
}

/** True iff Y0 and Y1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
	   yyn = yyrhsLength (yyy0->yyrule);
	   yyn > 0;
	   yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
	if (yys0->yyposn != yys1->yyposn)
	  return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (Y0,Y1), destructively merge the
 *  alternative semantic values for the RHS-symbols of Y1 and Y0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       yyn > 0;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
	break;
      else if (yys0->yyresolved)
	{
	  yys1->yyresolved = yytrue;
	  yys1->yysemantics.yysval = yys0->yysemantics.yysval;
	}
      else if (yys1->yyresolved)
	{
	  yys0->yyresolved = yytrue;
	  yys0->yysemantics.yysval = yys1->yysemantics.yysval;
	}
      else
	{
	  yySemanticOption** yyz0p;
	  yySemanticOption* yyz1;
	  yyz0p = &yys0->yysemantics.yyfirstVal;
	  yyz1 = yys1->yysemantics.yyfirstVal;
	  while (YYID (yytrue))
	    {
	      if (yyz1 == *yyz0p || yyz1 == NULL)
		break;
	      else if (*yyz0p == NULL)
		{
		  *yyz0p = yyz1;
		  break;
		}
	      else if (*yyz0p < yyz1)
		{
		  yySemanticOption* yyz = *yyz0p;
		  *yyz0p = yyz1;
		  yyz1 = yyz1->yynext;
		  (*yyz0p)->yynext = yyz;
		}
	      yyz0p = &(*yyz0p)->yynext;
	    }
	  yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
	}
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
	return 0;
      else
	return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG yyresolveValue (yyGLRState* yys,
				   yyGLRStack* yystackp);


/** Resolve the previous N states starting at and including state S.  If result
 *  != yyok, some states may have been left unresolved possibly with empty
 *  semantic option chains.  Regardless of whether result = yyok, each state
 *  has been left with consistent data so that yydestroyGLRState can be invoked
 *  if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
		 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YYASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
	YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of OPT, perform its user action, and return
 *  the semantic value and location.  Regardless of whether result = yyok, all
 *  RHS states have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
		 YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs;
  int yychar_current;
  YYSTYPE yylval_current;
  YYLTYPE yylloc_current;
  YYRESULTTAG yyflag;

  yynrhs = yyrhsLength (yyopt->yyrule);
  yyflag = yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
	yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  yychar_current = yychar;
  yylval_current = yylval;
  yylloc_current = yylloc;
  yychar = yyopt->yyrawchar;
  yylval = yyopt->yyval;
  yylloc = yyopt->yyloc;
  yyflag = yyuserAction (yyopt->yyrule, yynrhs,
			   yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
			   yyvalp, yylocp, yystackp);
  yychar = yychar_current;
  yylval = yylval_current;
  yylloc = yylloc_current;
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == NULL)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, empty>\n",
	       yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
	       yyx->yyrule - 1);
  else
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %lu .. %lu>\n",
	       yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
	       yyx->yyrule - 1, (unsigned long int) (yys->yyposn + 1),
	       (unsigned long int) yyx->yystate->yyposn);
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
	{
	  if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
	    YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
		       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]));
	  else
	    YYFPRINTF (stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent+2, "",
		       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]),
		       (unsigned long int) (yystates[yyi - 1]->yyposn + 1),
		       (unsigned long int) yystates[yyi]->yyposn);
	}
      else
	yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

/*ARGSUSED*/ static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
		   yySemanticOption* yyx1)
{
  YYUSE (yyx0);
  YYUSE (yyx1);

#if YYDEBUG
  YYFPRINTF (stderr, "Ambiguity detected.\n");
  YYFPRINTF (stderr, "Option 1,\n");
  yyreportTree (yyx0, 2);
  YYFPRINTF (stderr, "\nOption 2,\n");
  yyreportTree (yyx1, 2);
  YYFPRINTF (stderr, "\n");
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Starting at and including state S1, resolve the location for each of the
 *  previous N1 states that is unresolved.  The first semantic option of a state
 *  is always chosen.  */
static void
yyresolveLocations (yyGLRState* yys1, int yyn1,
		    yyGLRStack *yystackp)
{
  if (0 < yyn1)
    {
      yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp);
      if (!yys1->yyresolved)
	{
	  yySemanticOption *yyoption;
	  yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
	  int yynrhs;
	  int yychar_current;
	  YYSTYPE yylval_current;
	  YYLTYPE yylloc_current;
	  yyoption = yys1->yysemantics.yyfirstVal;
	  YYASSERT (yyoption != NULL);
	  yynrhs = yyrhsLength (yyoption->yyrule);
	  if (yynrhs > 0)
	    {
	      yyGLRState *yys;
	      int yyn;
	      yyresolveLocations (yyoption->yystate, yynrhs,
				  yystackp);
	      for (yys = yyoption->yystate, yyn = yynrhs;
		   yyn > 0;
		   yys = yys->yypred, yyn -= 1)
		yyrhsloc[yyn].yystate.yyloc = yys->yyloc;
	    }
	  else
	    {
	      /* Both yyresolveAction and yyresolveLocations traverse the GSS
		 in reverse rightmost order.  It is only necessary to invoke
		 yyresolveLocations on a subforest for which yyresolveAction
		 would have been invoked next had an ambiguity not been
		 detected.  Thus the location of the previous state (but not
		 necessarily the previous state itself) is guaranteed to be
		 resolved already.  */
	      yyGLRState *yyprevious = yyoption->yystate;
	      yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
	    }
	  yychar_current = yychar;
	  yylval_current = yylval;
	  yylloc_current = yylloc;
	  yychar = yyoption->yyrawchar;
	  yylval = yyoption->yyval;
	  yylloc = yyoption->yyloc;
	  YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
	  yychar = yychar_current;
	  yylval = yylval_current;
	  yylloc = yylloc_current;
	}
    }
}

/** Resolve the ambiguity represented in state S, perform the indicated
 *  actions, and set the semantic value of S.  If result != yyok, the chain of
 *  semantic options in S has been cleared instead or it has been left
 *  unmodified except that redundant options may have been removed.  Regardless
 *  of whether result = yyok, S has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest;
  yySemanticOption** yypp;
  yybool yymerge;
  YYSTYPE yysval;
  YYRESULTTAG yyflag;
  YYLTYPE *yylocp = &yys->yyloc;

  yybest = yyoptionList;
  yymerge = yyfalse;
  for (yypp = &yyoptionList->yynext; *yypp != NULL; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
	{
	  yymergeOptionSets (yybest, yyp);
	  *yypp = yyp->yynext;
	}
      else
	{
	  switch (yypreference (yybest, yyp))
	    {
	    case 0:
	      yyresolveLocations (yys, 1, yystackp);
	      return yyreportAmbiguity (yybest, yyp);
	      break;
	    case 1:
	      yymerge = yytrue;
	      break;
	    case 2:
	      break;
	    case 3:
	      yybest = yyp;
	      yymerge = yyfalse;
	      break;
	    default:
	      /* This cannot happen so it is not worth a YYASSERT (yyfalse),
		 but some compilers complain if the default case is
		 omitted.  */
	      break;
	    }
	  yypp = &yyp->yynext;
	}
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yysval,
				yylocp);
      if (yyflag == yyok)
	for (yyp = yybest->yynext; yyp != NULL; yyp = yyp->yynext)
	  {
	    if (yyprec == yydprec[yyp->yyrule])
	      {
		YYSTYPE yysval_other;
		YYLTYPE yydummy;
		yyflag = yyresolveAction (yyp, yystackp, &yysval_other,
					  &yydummy);
		if (yyflag != yyok)
		  {
		    yydestruct ("Cleanup: discarding incompletely merged value for",
				yystos[yys->yylrState],
				&yysval);
		    break;
		  }
		yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
	      }
	  }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yysval = yysval;
    }
  else
    yys->yysemantics.yyfirstVal = NULL;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != NULL)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
	   yys != yystackp->yysplitPoint;
	   yys = yys->yypred, yyn += 1)
	continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
			     ));
    }
  return yyok;
}

static void
yycompressStack (yyGLRStack* yystackp)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == NULL)
    return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = NULL;
       yyp != yystackp->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = ((yyGLRStackItem*) yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = NULL;
  yystackp->yylastDeleted = NULL;

  while (yyr != NULL)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
		   size_t yyposn)
{
  int yyaction;
  const short int* yyconflicts;
  yyRuleNum yyrule;

  while (yystackp->yytops.yystates[yyk] != NULL)
    {
      yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YYDPRINTF ((stderr, "Stack %lu Entering state %d\n",
		  (unsigned long int) yyk, yystate));

      YYASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
	{
	  yyrule = yydefaultAction (yystate);
	  if (yyrule == 0)
	    {
	      YYDPRINTF ((stderr, "Stack %lu dies.\n",
			  (unsigned long int) yyk));
	      yymarkStackDeleted (yystackp, yyk);
	      return yyok;
	    }
	  YYCHK (yyglrReduce (yystackp, yyk, yyrule, yyfalse));
	}
      else
	{
	  yySymbol yytoken;
	  yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
	  if (yychar == YYEMPTY)
	    {
	      YYDPRINTF ((stderr, "Reading a token: "));
	      yychar = YYLEX;
	      yytoken = YYTRANSLATE (yychar);
	      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
	    }
	  else
	    yytoken = YYTRANSLATE (yychar);
	  yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);

	  while (*yyconflicts != 0)
	    {
	      size_t yynewStack = yysplitStack (yystackp, yyk);
	      YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
			  (unsigned long int) yynewStack,
			  (unsigned long int) yyk));
	      YYCHK (yyglrReduce (yystackp, yynewStack,
				  *yyconflicts, yyfalse));
	      YYCHK (yyprocessOneStack (yystackp, yynewStack,
					yyposn));
	      yyconflicts += 1;
	    }

	  if (yyisShiftAction (yyaction))
	    break;
	  else if (yyisErrorAction (yyaction))
	    {
	      YYDPRINTF ((stderr, "Stack %lu dies.\n",
			  (unsigned long int) yyk));
	      yymarkStackDeleted (yystackp, yyk);
	      break;
	    }
	  else
	    YYCHK (yyglrReduce (yystackp, yyk, -yyaction,
				yyfalse));
	}
    }
  return yyok;
}

/*ARGSUSED*/ static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState == 0)
    {
#if YYERROR_VERBOSE
      int yyn;
      yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
      if (YYPACT_NINF < yyn && yyn <= YYLAST)
	{
	  yySymbol yytoken = YYTRANSLATE (yychar);
	  size_t yysize0 = yytnamerr (NULL, yytokenName (yytoken));
	  size_t yysize = yysize0;
	  size_t yysize1;
	  yybool yysize_overflow = yyfalse;
	  char* yymsg = NULL;
	  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn + 1;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytokenName (yytoken);
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytokenName (yyx);
		yysize1 = yysize + yytnamerr (NULL, yytokenName (yyx));
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + strlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow)
	    yymsg = (char *) YYMALLOC (yysize);

	  if (yymsg)
	    {
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYFREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      yyMemoryExhausted (yystackp);
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
      yynerrs += 1;
    }
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the look-ahead.  */
/*ARGSUSED*/ static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  size_t yyk;
  int yyj;

  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (YYID (yytrue))
      {
	yySymbol yytoken;
	if (yychar == YYEOF)
	  yyFail (yystackp, NULL);
	if (yychar != YYEMPTY)
	  {
	    yytoken = YYTRANSLATE (yychar);
	    yydestruct ("Error: discarding",
			yytoken, &yylval);
	  }
	YYDPRINTF ((stderr, "Reading a token: "));
	yychar = YYLEX;
	yytoken = YYTRANSLATE (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
	yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
	if (yyis_pact_ninf (yyj))
	  return;
	yyj += yytoken;
	if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
	  {
	    if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
	      return;
	  }
	else if (yytable[yyj] != 0 && ! yyis_table_ninf (yytable[yyj]))
	  return;
      }

  /* Reduce to one stack.  */
  for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
    if (yystackp->yytops.yystates[yyk] != NULL)
      break;
  if (yyk >= yystackp->yytops.yysize)
    yyFail (yystackp, NULL);
  for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
    yymarkStackDeleted (yystackp, yyk);
  yyremoveDeletes (yystackp);
  yycompressStack (yystackp);

  /* Now pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != NULL)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      yyj = yypact[yys->yylrState];
      if (! yyis_pact_ninf (yyj))
	{
	  yyj += YYTERROR;
	  if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
	      && yyisShiftAction (yytable[yyj]))
	    {
	      /* Shift the error token having adjusted its location.  */
	      YYLTYPE yyerrloc;
	      YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
			       &yylval, &yyerrloc);
	      yyglrShift (yystackp, 0, yytable[yyj],
			  yys->yyposn, &yylval, &yyerrloc);
	      yys = yystackp->yytops.yystates[0];
	      break;
	    }
	}

      yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == NULL)
    yyFail (yystackp, NULL);
}

#define YYCHK1(YYE)							     \
  do {									     \
    switch (YYE) {							     \
    case yyok:								     \
      break;								     \
    case yyabort:							     \
      goto yyabortlab;							     \
    case yyaccept:							     \
      goto yyacceptlab;							     \
    case yyerr:								     \
      goto yyuser_error;						     \
    default:								     \
      goto yybuglab;							     \
    }									     \
  } while (YYID (0))


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  size_t yyposn;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;


  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval, &yylloc);
  yyposn = 0;

  while (YYID (yytrue))
    {
      /* For efficiency, we have two loops, the first of which is
	 specialized to deterministic operation (single stack, no
	 potential ambiguity).  */
      /* Standard mode */
      while (YYID (yytrue))
	{
	  yyRuleNum yyrule;
	  int yyaction;
	  const short int* yyconflicts;

	  yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
	  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
	  if (yystate == YYFINAL)
	    goto yyacceptlab;
	  if (yyisDefaultedState (yystate))
	    {
	      yyrule = yydefaultAction (yystate);
	      if (yyrule == 0)
		{

		  yyreportSyntaxError (&yystack);
		  goto yyuser_error;
		}
	      YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
	    }
	  else
	    {
	      yySymbol yytoken;
	      if (yychar == YYEMPTY)
		{
		  YYDPRINTF ((stderr, "Reading a token: "));
		  yychar = YYLEX;
		  yytoken = YYTRANSLATE (yychar);
		  YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
		}
	      else
		yytoken = YYTRANSLATE (yychar);
	      yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
	      if (*yyconflicts != 0)
		break;
	      if (yyisShiftAction (yyaction))
		{
		  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
		  if (yychar != YYEOF)
		    yychar = YYEMPTY;
		  yyposn += 1;
		  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
		  if (0 < yystack.yyerrState)
		    yystack.yyerrState -= 1;
		}
	      else if (yyisErrorAction (yyaction))
		{

		  yyreportSyntaxError (&yystack);
		  goto yyuser_error;
		}
	      else
		YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
	    }
	}

      while (YYID (yytrue))
	{
	  yySymbol yytoken_to_shift;
	  size_t yys;

	  for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
	    yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

	  /* yyprocessOneStack returns one of three things:

	      - An error flag.  If the caller is yyprocessOneStack, it
		immediately returns as well.  When the caller is finally
		yyparse, it jumps to an error label via YYCHK1.

	      - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
		(&yystack, yys), which sets the top state of yys to NULL.  Thus,
		yyparse's following invocation of yyremoveDeletes will remove
		the stack.

	      - yyok, when ready to shift a token.

	     Except in the first case, yyparse will invoke yyremoveDeletes and
	     then shift the next token onto all remaining stacks.  This
	     synchronization of the shift (that is, after all preceding
	     reductions on all stacks) helps prevent double destructor calls
	     on yylval in the event of memory exhaustion.  */

	  for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
	    YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
	  yyremoveDeletes (&yystack);
	  if (yystack.yytops.yysize == 0)
	    {
	      yyundeleteLastStack (&yystack);
	      if (yystack.yytops.yysize == 0)
		yyFail (&yystack, YY_("syntax error"));
	      YYCHK1 (yyresolveStack (&yystack));
	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));

	      yyreportSyntaxError (&yystack);
	      goto yyuser_error;
	    }

	  /* If any yyglrShift call fails, it will fail after shifting.  Thus,
	     a copy of yylval will already be on stack 0 in the event of a
	     failure in the following loop.  Thus, yychar is set to YYEMPTY
	     before the loop to make sure the user destructor for yylval isn't
	     called twice.  */
	  yytoken_to_shift = YYTRANSLATE (yychar);
	  yychar = YYEMPTY;
	  yyposn += 1;
	  for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
	    {
	      int yyaction;
	      const short int* yyconflicts;
	      yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
	      yygetLRActions (yystate, yytoken_to_shift, &yyaction,
			      &yyconflicts);
	      /* Note that yyconflicts were handled by yyprocessOneStack.  */
	      YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
	      YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
	      yyglrShift (&yystack, yys, yyaction, yyposn,
			  &yylval, &yylloc);
	      YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
			  (unsigned long int) yys,
			  yystack.yytops.yystates[yys]->yylrState));
	    }

	  if (yystack.yytops.yysize == 1)
	    {
	      YYCHK1 (yyresolveStack (&yystack));
	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
	      yycompressStack (&yystack);
	      break;
	    }
	}
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturn;

 yybuglab:
  YYASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
		YYTRANSLATE (yychar),
		&yylval);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
	{
	  size_t yysize = yystack.yytops.yysize;
	  size_t yyk;
	  for (yyk = 0; yyk < yysize; yyk += 1)
	    if (yystates[yyk])
	      {
		while (yystates[yyk])
		  {
		    yyGLRState *yys = yystates[yyk];
		    yydestroyGLRState ("Cleanup: popping", yys);
		    yystates[yyk] = yys->yypred;
		    yystack.yynextFree -= 1;
		    yystack.yyspaceLeft += 1;
		  }
		break;
	      }
	}
      yyfreeGLRStack (&yystack);
    }

  /* Make sure YYID is used.  */
  return YYID (yyresult);
}

/* DEBUGGING ONLY */
#ifdef YYDEBUG
static void yypstack (yyGLRStack* yystackp, size_t yyk)
  __attribute__ ((__unused__));
static void yypdumpstack (yyGLRStack* yystackp) __attribute__ ((__unused__));

static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      fprintf (stderr, " -> ");
    }
  fprintf (stderr, "%d@%lu", yys->yylrState, (unsigned long int) yys->yyposn);
}

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == NULL)
    fprintf (stderr, "<null>");
  else
    yy_yypstack (yyst);
  fprintf (stderr, "\n");
}

static void
yypstack (yyGLRStack* yystackp, size_t yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

#define YYINDEX(YYX)							     \
    ((YYX) == NULL ? -1 : (yyGLRStackItem*) (YYX) - yystackp->yyitems)


static void
yypdumpstack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yyp;
  size_t yyi;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      fprintf (stderr, "%3lu. ", (unsigned long int) (yyp - yystackp->yyitems));
      if (*(yybool *) yyp)
	{
	  fprintf (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
		   yyp->yystate.yyresolved, yyp->yystate.yylrState,
		   (unsigned long int) yyp->yystate.yyposn,
		   (long int) YYINDEX (yyp->yystate.yypred));
	  if (! yyp->yystate.yyresolved)
	    fprintf (stderr, ", firstVal: %ld",
		     (long int) YYINDEX (yyp->yystate.yysemantics.yyfirstVal));
	}
      else
	{
	  fprintf (stderr, "Option. rule: %d, state: %ld, next: %ld",
		   yyp->yyoption.yyrule - 1,
		   (long int) YYINDEX (yyp->yyoption.yystate),
		   (long int) YYINDEX (yyp->yyoption.yynext));
	}
      fprintf (stderr, "\n");
    }
  fprintf (stderr, "Tops:");
  for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
    fprintf (stderr, "%lu: %ld; ", (unsigned long int) yyi,
	     (long int) YYINDEX (yystackp->yytops.yystates[yyi]));
  fprintf (stderr, "\n");
}
#endif


#line 1878 "cppgram.y"


