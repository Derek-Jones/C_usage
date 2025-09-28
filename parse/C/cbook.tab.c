
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison GLR parsers in C
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0




/* Copy the first part of user declarations.  */


/* Line 172 of glr.c  */
#line 59 "cbook.tab.c"




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
     UNDEFINED = 353
   };
#endif


#ifndef YYSTYPE
typedef int YYSTYPE;
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


/* Line 243 of glr.c  */
#line 217 "cbook.tab.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
#define YYFINAL  128
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1239

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  99
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  85
/* YYNRULES -- Number of rules.  */
#define YYNRULES  237
/* YYNRULES -- Number of states.  */
#define YYNSTATES  385
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 8
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   353

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      95,    96,    97,    98
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    19,
      21,    24,    27,    33,    34,    36,    38,    43,    48,    52,
      56,    59,    62,    69,    77,    79,    83,    85,    88,    91,
      94,    97,   102,   104,   106,   108,   110,   112,   114,   116,
     121,   123,   127,   131,   135,   137,   141,   145,   147,   151,
     155,   157,   161,   165,   169,   173,   175,   179,   183,   185,
     189,   191,   195,   197,   201,   203,   207,   209,   213,   215,
     221,   223,   227,   229,   231,   233,   235,   237,   239,   241,
     243,   245,   247,   249,   251,   255,   257,   260,   264,   266,
     268,   270,   272,   274,   277,   279,   283,   285,   289,   291,
     293,   295,   297,   299,   301,   303,   305,   307,   309,   311,
     313,   315,   317,   319,   321,   323,   325,   327,   329,   330,
     332,   338,   341,   343,   345,   347,   350,   354,   356,   358,
     360,   363,   365,   369,   371,   374,   380,   387,   390,   392,
     396,   398,   402,   404,   406,   408,   410,   411,   413,   416,
     419,   420,   422,   423,   425,   427,   431,   438,   445,   451,
     453,   459,   464,   471,   475,   478,   482,   484,   487,   489,
     493,   495,   499,   500,   502,   505,   507,   510,   513,   515,
     518,   519,   521,   522,   524,   528,   534,   541,   548,   553,
     558,   560,   562,   566,   571,   572,   574,   577,   582,   583,
     586,   588,   591,   595,   598,   600,   602,   604,   606,   608,
     610,   612,   614,   618,   619,   625,   626,   631,   634,   639,
     644,   645,   647,   652,   654,   663,   671,   675,   678,   681,
     685,   687,   689,   690,   692,   697,   701,   703
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const short int yyrhs[] =
{
     100,     0,    -1,   101,    -1,   180,    -1,   171,    -1,    93,
      -1,    92,    -1,   103,    -1,    38,   123,    39,    -1,    94,
      -1,   103,    94,    -1,   103,    93,    -1,   103,    93,    38,
     124,    39,    -1,    -1,   106,    -1,   102,    -1,   105,    77,
     123,    78,    -1,   105,    38,   104,    39,    -1,   105,    66,
      93,    -1,   105,    67,    93,    -1,   105,    68,    -1,   105,
      69,    -1,    38,   159,    39,    75,   167,    76,    -1,    38,
     159,    39,    75,   167,    72,    76,    -1,   121,    -1,   106,
      72,   121,    -1,   105,    -1,    68,   107,    -1,    69,   107,
      -1,   108,   109,    -1,    37,   107,    -1,    37,    38,   159,
      39,    -1,    52,    -1,    47,    -1,    43,    -1,    45,    -1,
      54,    -1,    55,    -1,   107,    -1,    38,   159,    39,   109,
      -1,   109,    -1,   110,    47,   109,    -1,   110,    49,   109,
      -1,   110,    48,   109,    -1,   110,    -1,   111,    43,   110,
      -1,   111,    45,   110,    -1,   111,    -1,   112,    40,   111,
      -1,   112,    41,   111,    -1,   112,    -1,   113,    56,   112,
      -1,   113,    59,   112,    -1,   113,    57,   112,    -1,   113,
      58,   112,    -1,   113,    -1,   114,    60,   113,    -1,   114,
      61,   113,    -1,   114,    -1,   115,    52,   114,    -1,   115,
      -1,   116,    50,   115,    -1,   116,    -1,   117,    53,   116,
      -1,   117,    -1,   118,    62,   117,    -1,   118,    -1,   119,
      63,   118,    -1,   119,    -1,   119,    64,   123,    90,   120,
      -1,   120,    -1,   107,   122,   121,    -1,    79,    -1,    82,
      -1,    86,    -1,    87,    -1,    80,    -1,    81,    -1,    83,
      -1,    84,    -1,    85,    -1,    88,    -1,    89,    -1,   121,
      -1,   123,    72,   121,    -1,   120,    -1,   127,    73,    -1,
     127,   128,    73,    -1,   130,    -1,   131,    -1,   144,    -1,
     145,    -1,   126,    -1,   127,   126,    -1,   129,    -1,   128,
      72,   129,    -1,   147,    -1,   147,    79,   165,    -1,    10,
      -1,     8,    -1,     7,    -1,     6,    -1,     9,    -1,    19,
      -1,    11,    -1,    15,    -1,    14,    -1,    16,    -1,    12,
      -1,    13,    -1,    18,    -1,    17,    -1,     3,    -1,     4,
      -1,     5,    -1,   133,    -1,   141,    -1,   164,    -1,    -1,
      93,    -1,   134,   132,    75,   135,    76,    -1,   134,    93,
      -1,    22,    -1,    23,    -1,   136,    -1,   135,   136,    -1,
     138,   139,    73,    -1,   131,    -1,   144,    -1,   137,    -1,
     138,   137,    -1,   140,    -1,   139,    72,   140,    -1,   147,
      -1,    90,   124,    -1,    24,   132,    75,   142,    76,    -1,
      24,   132,    75,   142,    72,    76,    -1,    24,    93,    -1,
     143,    -1,   142,    72,   143,    -1,    93,    -1,    93,    79,
     124,    -1,    20,    -1,    97,    -1,    21,    -1,    96,    -1,
      -1,   153,    -1,   146,   151,    -1,   146,   152,    -1,    -1,
     154,    -1,    -1,   121,    -1,    93,    -1,    38,   147,    39,
      -1,   151,    77,     7,   149,   121,    78,    -1,   151,    77,
     154,     7,   121,    78,    -1,   151,    77,   149,    47,    78,
      -1,   152,    -1,   151,    77,   149,   150,    78,    -1,   151,
      38,   155,    39,    -1,   151,    38,    38,   155,    39,    39,
      -1,   151,    38,    39,    -1,    47,   149,    -1,    47,   149,
     153,    -1,   144,    -1,   154,   144,    -1,   156,    -1,   156,
      72,    74,    -1,   158,    -1,   156,    72,   158,    -1,    -1,
     160,    -1,   127,   147,    -1,   127,    -1,   127,   160,    -1,
     138,   157,    -1,   153,    -1,   146,   163,    -1,    -1,   163,
      -1,    -1,   155,    -1,    38,   160,    39,    -1,   161,    77,
     149,   150,    78,    -1,   161,    77,     7,   149,   121,    78,
      -1,   161,    77,   154,     7,   121,    78,    -1,   161,    77,
      47,    78,    -1,   161,    38,   162,    39,    -1,    93,    -1,
     121,    -1,    75,   167,    76,    -1,    75,   167,    72,    76,
      -1,    -1,   168,    -1,   166,   165,    -1,   167,    72,   166,
     165,    -1,    -1,   169,    79,    -1,   170,    -1,   169,   170,
      -1,    77,   124,    78,    -1,    66,    93,    -1,   172,    -1,
     175,    -1,   176,    -1,   178,    -1,    75,    -1,    76,    -1,
      26,    -1,   179,    -1,    93,    90,   171,    -1,    -1,    31,
     124,    90,   173,   171,    -1,    -1,    32,    90,   174,   171,
      -1,   177,    73,    -1,    25,    38,   123,    39,    -1,    30,
      38,   123,    39,    -1,    -1,   123,    -1,    27,    38,   123,
      39,    -1,    29,    -1,    28,    38,   177,    73,   177,    73,
     177,    39,    -1,    28,    38,   125,   177,    73,   177,    39,
      -1,    36,    93,    73,    -1,    34,    73,    -1,    33,    73,
      -1,    35,   177,    73,    -1,   182,    -1,   125,    -1,    -1,
     183,    -1,   127,   148,   181,    75,    -1,   148,   181,    75,
      -1,   125,    -1,   183,   125,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   280,   280,   305,   313,   326,   331,   336,   341,   351,
     356,   367,   373,   381,   385,   392,   397,   402,   407,   413,
     419,   424,   429,   434,   442,   447,   455,   460,   465,   470,
     479,   484,   492,   497,   502,   507,   512,   517,   533,   538,
     554,   559,   564,   569,   598,   603,   608,   647,   652,   657,
     665,   670,   675,   680,   685,   693,   698,   703,   719,   724,
     739,   744,   752,   757,   765,   770,   778,   783,   791,   796,
     805,   810,   818,   823,   828,   833,   838,   843,   848,   853,
     858,   863,   868,   876,   881,   889,   921,   925,   935,   939,
     943,   947,   953,   957,   964,   968,   975,   979,   987,   992,
     997,  1002,  1007,  1015,  1020,  1025,  1030,  1035,  1040,  1045,
    1050,  1055,  1060,  1065,  1070,  1075,  1079,  1083,  1089,  1092,
    1100,  1105,  1113,  1117,  1124,  1128,  1135,  1142,  1146,  1155,
    1159,  1167,  1171,  1189,  1193,  1215,  1220,  1225,  1239,  1243,
    1250,  1255,  1264,  1269,  1274,  1282,  1288,  1291,  1297,  1302,
    1307,  1310,  1315,  1318,  1345,  1350,  1357,  1362,  1367,  1371,
    1377,  1382,  1403,  1407,  1424,  1428,  1435,  1439,  1446,  1450,
    1457,  1461,  1467,  1470,  1493,  1497,  1501,  1523,  1531,  1535,
    1541,  1544,  1549,  1552,  1558,  1562,  1568,  1574,  1580,  1585,
    1595,  1603,  1607,  1611,  1617,  1620,  1626,  1630,  1639,  1645,
    1652,  1656,  1663,  1668,  1681,  1685,  1689,  1693,  1702,  1707,
    1712,  1717,  1724,  1729,  1729,  1734,  1734,  1759,  1774,  1780,
    1788,  1792,  1805,  1811,  1824,  1832,  1842,  1848,  1853,  1858,
    1869,  1873,  1880,  1883,  1905,  1913,  1921,  1925
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
  "UNDEFINED", "$accept", "TU", "translation_unit", "primary_expr",
  "string_seq", "argument_expr_list_opt", "postfix_expr",
  "argument_expr_list", "unary_expr", "unary_operator", "cast_expr",
  "multiplicative_expr", "additive_expr", "shift_expr", "relational_expr",
  "equality_expr", "AND_expr", "exclusive_OR_expr", "inclusive_OR_expr",
  "logical_AND_expr", "logical_OR_expr", "conditional_expr",
  "assignment_expr", "assignment_operator", "expression", "constant_expr",
  "declaration", "decl_specifier", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "identifier_opt", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "spec_qual", "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "function_specifier", "pointer_opt", "declarator",
  "fndef_declarator", "type_qualifier_list_opt", "assignment_expr_opt",
  "direct_declarator", "fndef_direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "abstract_declarator_opt", "parameter_declaration", "type_name",
  "abstract_declarator", "direct_abstract_declarator_opt",
  "parameter_type_list_opt", "direct_abstract_declarator", "typedef_name",
  "initializer", "designation_opt", "initializer_list", "designation",
  "designator_list", "designator", "statement", "labeled_statement", "$@1",
  "$@2", "expression_statement", "selection_header", "expr_opt",
  "iteration_header", "jump_statement", "external_declaration",
  "declaration_list_opt", "function_header", "declaration_list", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    99,   100,   101,   101,   102,   102,   102,   102,   103,
     103,   103,   103,   104,   104,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   106,   106,   107,   107,   107,   107,
     107,   107,   108,   108,   108,   108,   108,   108,   109,   109,
     110,   110,   110,   110,   111,   111,   111,   112,   112,   112,
     113,   113,   113,   113,   113,   114,   114,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   119,   119,   120,   120,
     121,   121,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   123,   123,   124,   125,   125,   126,   126,
     126,   126,   127,   127,   128,   128,   129,   129,   130,   130,
     130,   130,   130,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   132,   132,
     133,   133,   134,   134,   135,   135,   136,   137,   137,   138,
     138,   139,   139,   140,   140,   141,   141,   141,   142,   142,
     143,   143,   144,   144,   144,   145,   146,   146,   147,   148,
     149,   149,   150,   150,   151,   151,   151,   151,   151,   151,
     152,   152,   152,   152,   153,   153,   154,   154,   155,   155,
     156,   156,   157,   157,   158,   158,   158,   159,   160,   160,
     161,   161,   162,   162,   163,   163,   163,   163,   163,   163,
     164,   165,   165,   165,   166,   166,   167,   167,   167,   168,
     169,   169,   170,   170,   171,   171,   171,   171,   171,   171,
     171,   171,   172,   173,   172,   174,   172,   175,   176,   176,
     177,   177,   178,   178,   178,   178,   179,   179,   179,   179,
     180,   180,   181,   181,   182,   182,   183,   183
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     2,     5,     0,     1,     1,     4,     4,     3,     3,
       2,     2,     6,     7,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       5,     2,     1,     1,     1,     2,     3,     1,     1,     1,
       2,     1,     3,     1,     2,     5,     6,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     0,     1,     2,     2,
       0,     1,     0,     1,     1,     3,     6,     6,     5,     1,
       5,     4,     6,     3,     2,     3,     1,     2,     1,     3,
       1,     3,     0,     1,     2,     1,     2,     2,     1,     2,
       0,     1,     0,     1,     3,     5,     6,     6,     4,     4,
       1,     1,     3,     4,     0,     1,     2,     4,     0,     2,
       1,     2,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     0,     5,     0,     4,     2,     4,     4,
       0,     1,     4,     1,     8,     7,     3,     2,     2,     3,
       1,     1,     0,     1,     4,     3,     1,     2
};

/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const unsigned char yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     1,     0,     0,     0,     0,     0,     0,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     1,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const unsigned char yymerger[] =
{
       0,     0,     0,     1,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     2,     0,     0,     3,     3,     3,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error.  */
static const unsigned char yydefact[] =
{
     220,   112,   113,   114,   101,   100,    99,   102,    98,   104,
     108,   109,   106,   105,   107,   111,   110,   103,   142,   144,
     122,   123,   118,     0,   210,     0,     0,   223,     0,     0,
       0,     0,     0,   220,     0,     0,     0,    34,    35,    33,
      32,    36,    37,     0,     0,   208,   209,     6,     5,     9,
     145,   143,     0,     2,    15,     7,    26,    38,     0,    40,
      44,    47,    50,    55,    58,    60,    62,    64,    66,    68,
      70,    83,   221,   231,    92,   146,    88,    89,   115,   118,
     116,    90,    91,     0,   232,   147,   117,     4,   204,   205,
     206,     0,   207,   211,     3,   230,   137,     0,     0,     0,
     220,     0,    33,     5,    38,    85,     0,   215,   228,   227,
       0,     0,     0,    30,     5,     0,   127,   129,   146,   128,
       0,   166,   164,   151,     0,    27,    28,   220,     1,    11,
      10,    13,     0,     0,    20,    21,     0,    72,    76,    77,
      73,    78,    79,    80,    74,    75,    81,    82,     0,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,    86,   190,    93,     0,    94,     0,    96,   232,   121,
       0,   146,   154,     0,   149,   236,   146,     0,   233,   217,
       0,     0,     0,   220,     0,     0,   213,   220,   229,   226,
       0,     8,   130,   180,   147,   177,   173,     0,   165,   167,
       0,     5,   212,     0,     0,    14,    24,    18,    19,     0,
      71,    41,    43,    42,    45,    46,    48,    49,    51,    53,
      54,    52,    56,    57,    59,    61,    63,    65,    67,     0,
      84,   146,    87,   148,     0,     0,     0,     0,     0,     0,
     150,   235,   237,   140,     0,   138,   218,   222,     0,   220,
     219,   220,   216,    31,   146,     0,   179,   194,    39,     0,
       0,    17,     0,    16,     0,    95,   194,   191,    97,   234,
       0,   124,   146,   159,   155,     0,   163,   146,     0,   168,
     170,   150,   152,   151,     0,     0,   135,   220,     0,   214,
       0,   182,   150,     0,     0,     0,     0,   195,     0,   200,
      12,    25,    69,     0,   120,   125,     0,     0,   131,   133,
       0,   180,   174,   176,   161,     0,     0,    33,   153,     0,
       0,   141,   136,   139,     0,   220,   184,   183,     0,   150,
       0,   152,   151,   203,     0,   196,   194,    22,   199,   201,
     194,   192,   134,   146,   126,     0,   146,   169,   171,     0,
     158,   160,     0,   225,     0,   189,     0,   188,     0,     0,
     202,    23,     0,   193,   132,   162,   156,   157,   224,     0,
     185,     0,   197,   186,   187
};

/* YYPDEFGOTO[NTERM-NUM].  */
static const short int yydefgoto[] =
{
      -1,    52,    53,    54,    55,   214,    56,   215,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,   148,    72,   106,   185,    74,   186,   174,
     175,    76,    77,    97,    78,    79,   280,   281,   117,   118,
     317,   318,    80,   254,   255,    81,    82,   247,   177,    84,
     122,   329,   243,   184,    85,   123,   288,   289,   205,   290,
     120,   300,   265,   338,   266,    86,   278,   305,   306,   307,
     308,   309,    87,    88,   261,   197,    89,    90,    91,    92,
      93,    94,   187,    95,   188
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -274
static const short int yypact[] =
{
     354,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,   -52,   134,  -274,   139,   142,  -274,   149,  1074,
      44,    97,   129,  1074,   143,  1093,   510,  -274,  -274,   148,
    -274,  -274,  -274,  1126,  1126,  -274,  -274,  -274,   622,  -274,
    -274,  -274,   225,  -274,  -274,    62,   122,   231,  1074,  -274,
     218,    19,   168,    68,   162,   180,   192,   187,   182,   165,
    -274,  -274,   186,  -274,  -274,   762,  -274,  -274,  -274,   159,
    -274,  -274,  -274,   -23,   974,  -274,  -274,  -274,  -274,  -274,
    -274,   199,  -274,  -274,  -274,  -274,   185,   203,  1074,  1074,
     449,  1074,  -274,  -274,  -274,  -274,   194,  -274,  -274,  -274,
     207,   217,   510,  -274,   577,    28,  -274,  -274,   920,  -274,
     255,  -274,   249,     5,   510,  -274,  -274,  1014,  -274,   259,
    -274,  1074,   205,   206,  -274,  -274,  1074,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  1074,  -274,
    1074,  1074,  1074,  1074,  1074,  1074,  1074,  1074,  1074,  1074,
    1074,  1074,  1074,  1074,  1074,  1074,  1074,  1074,  1074,  1074,
       5,  -274,  -274,  -274,   183,  -274,   -23,   221,   974,   185,
     226,   249,  -274,   -11,   124,  -274,   857,   229,   974,  -274,
     213,    42,    58,  1074,   234,   132,  -274,  1014,  -274,  -274,
     282,  -274,  -274,   284,   135,  -274,  -274,   610,  -274,  -274,
     285,   233,  -274,  1074,   286,   277,  -274,  -274,  -274,    57,
    -274,  -274,  -274,  -274,   218,   218,    19,    19,   168,   168,
     168,   168,    68,    68,   162,   180,   192,   187,   182,    94,
    -274,   249,  -274,   -11,  1041,   275,    35,   -23,   312,   879,
      22,  -274,  -274,   273,    -7,  -274,  -274,  -274,   280,  1074,
    -274,  1014,  -274,   279,   249,    45,    54,   154,  -274,   279,
     316,  -274,  1074,  -274,  1074,  -274,   154,  -274,  -274,  -274,
     829,  -274,  1007,  -274,  -274,   974,  -274,   717,   355,   321,
    -274,     5,  1145,    66,  1074,   -58,  -274,  1074,   322,  -274,
     357,   974,    16,   307,  1074,  1041,   107,  -274,   140,  -274,
    -274,  -274,  -274,   138,  -274,  -274,  1074,   190,  -274,  -274,
     363,   -17,  -274,  -274,  -274,   324,  1074,   325,  -274,   326,
    1074,  -274,  -274,  -274,   366,  1074,  -274,  -274,   368,     5,
     332,  1074,    96,  -274,   333,  -274,   158,  -274,  -274,  -274,
     161,  -274,  -274,    25,  -274,   373,   249,  -274,  -274,   335,
    -274,  -274,   336,  -274,   376,  -274,  1074,  -274,   338,  1074,
    -274,  -274,  1041,  -274,  -274,  -274,  -274,  -274,  -274,   340,
    -274,   341,  -274,  -274,  -274
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,   -13,  -274,
     -46,   116,   133,   117,   131,   261,   262,   260,   265,   266,
    -274,   -21,   -87,  -274,    -3,  -193,    10,   -66,     1,  -274,
     191,  -274,   -33,   348,  -274,  -274,  -274,   155,  -107,  -212,
    -274,    75,  -274,  -274,   141,   -34,  -274,     0,  -175,   359,
    -231,    98,   358,  -233,  -105,  -222,  -208,  -274,  -274,   112,
      52,  -114,  -274,  -274,  -274,  -274,  -273,  -135,   164,  -274,
    -274,   130,  -103,  -274,  -274,  -274,  -274,  -274,   -26,  -274,
    -274,  -274,   264,  -274,  -274
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -199
static const short int yytable[] =
{
      83,    75,   119,   116,   206,   121,   248,   110,   105,   173,
      73,   202,   149,   204,   283,   181,   104,   208,   332,   292,
     270,   356,   113,   339,   212,    18,    19,   249,   293,   291,
     125,   126,   345,   115,   282,   253,    18,    19,     1,     2,
       3,    96,    18,    19,   216,   104,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     326,   220,   153,   340,   154,   295,   250,   201,   282,   296,
     182,   341,   170,   330,   194,   176,   182,   320,   119,   116,
     342,   256,   240,   301,   119,   116,    18,    19,   283,   209,
     119,   116,  -181,   337,   262,   191,   192,   257,   195,   382,
     169,   331,    51,   369,   221,   222,   223,   319,   366,   115,
     193,   344,   322,    51,   169,   316,    18,    19,   203,    51,
     173,   115,   302,   352,   157,   158,   159,   160,   172,   169,
     169,  -181,    51,   219,   107,   273,   121,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   129,   130,   277,   299,   204,
     131,   268,  -159,    51,   200,   239,   169,   258,    18,    19,
     108,   260,    98,   323,  -178,   202,   210,    99,   319,   346,
     100,   248,   204,   347,   274,   311,   -33,   101,   132,   133,
     134,   135,   105,    51,   104,   -33,  -159,  -159,   252,   136,
     104,  -159,   109,  -159,   169,   328,   303,  -178,   155,   156,
     350,   372,   119,   116,   351,   372,   121,   304,   277,   348,
     303,   173,   161,   162,   303,   128,  -198,   303,   167,   168,
    -198,   304,   163,   298,   371,   304,   111,   373,   304,   359,
     165,   -33,   164,   362,   166,    51,   119,   116,   119,   116,
     287,   204,   179,   312,   328,   241,   242,   121,   169,   209,
    -119,   104,   353,   354,   203,   150,   151,   152,   121,   224,
     225,   334,   189,   105,   228,   229,   230,   231,   190,   379,
     198,   104,   381,   105,   196,   277,   287,   321,   226,   227,
     199,   104,   232,   233,   207,   105,   170,   213,   217,   218,
     244,   246,   287,   104,   251,   121,   253,   259,   209,   364,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   263,   264,   127,   269,   271,   287,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,   272,
     279,   284,   294,   297,   267,   310,   321,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,   325,   324,   335,   336,    37,   357,    38,
     343,    39,   355,   360,   361,   363,    40,   365,    41,    42,
     367,   370,   375,   376,   377,   378,   380,   172,   383,   384,
      50,    51,    43,    44,   234,   236,   235,   180,   374,    45,
      46,   237,   275,   238,   178,   315,   333,   358,   349,   368,
     313,   183,   245,     0,     0,     0,    47,    48,    49,     0,
      50,    51,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,    36,     0,     0,
       0,     0,    37,     0,    38,     0,   102,     0,     0,     0,
       0,    40,     0,    41,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     0,    43,    44,     0,
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     0,     0,     0,     0,     0,
       0,    47,   114,    49,     0,    50,    51,    35,    36,     0,
       0,     0,     0,    37,     0,    38,     0,   102,     0,     0,
       0,     0,    40,     0,    41,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43,    44,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,    47,   114,    49,     0,     0,    51,     0,     0,
       0,     0,     0,     0,     0,    -5,    -5,     0,     0,     0,
       0,     0,     0,     0,    -5,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,    35,    36,     0,
      -5,     0,     0,    37,    -5,    38,     0,   102,     0,     0,
      -5,     0,    40,     0,    41,    42,     0,     0,     0,    -5,
    -190,     0,     0,  -190,  -190,     0,     0,     0,    43,    44,
       0,     0,     0,     0,     0,   267,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    -5,     0,     0,     0,     0,
       0,     0,    47,   103,    49,     0,     0,     0,     0,     0,
       0,     0,   127,     0,     0,  -190,     0,     0,  -190,  -190,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -175,     0,     0,     0,
       0,     0,     0,     0,   170,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,     0,     0,  -175,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   170,
     172,     0,     0,    50,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,   171,     0,     0,     0,     0,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     0,   172,     0,     0,    50,    51,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   170,   314,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   285,   286,     0,
       0,     0,   172,     1,     2,     3,    51,     0,     0,     0,
     171,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     0,     0,     0,     0,     0,
     172,     0,     0,    50,    51,     0,     0,     0,     0,  -172,
       0,     0,     0,     0,     0,     0,     0,   170,     0,     0,
       0,     0,   172,     0,     0,    50,    51,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     3,   172,     0,     0,     0,    51,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,     0,     0,     0,     0,     0,     0,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,   170,     0,     0,    37,     0,    38,
       0,   102,     0,     0,     0,     0,    40,   172,    41,    42,
      50,    51,     0,     0,     0,     0,     0,     0,    35,    36,
       0,     0,    43,    44,    37,     0,    38,     0,   102,    45,
      46,     0,     0,    40,     0,    41,    42,   316,     0,     0,
     172,     0,     0,     0,    51,     0,    47,   211,    49,    43,
      44,    35,    36,     0,     0,     0,   276,    37,     0,    38,
       0,   102,     0,     0,     0,     0,    40,     0,    41,    42,
      35,   112,     0,    47,   103,    49,    37,     0,    38,     0,
     102,     0,    43,    44,     0,    40,     0,    41,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,    44,    35,   124,     0,    47,   103,    49,    37,
       0,    38,     0,   102,     0,     0,     0,     0,    40,     0,
      41,    42,    35,    36,     0,    47,   103,    49,    37,     0,
      38,     0,   327,     0,    43,    44,     0,    40,     0,    41,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    43,    44,     0,     0,     0,    47,   103,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,   103,    49
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const unsigned char yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,     0,     0,
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
       0,     0,     0,     0,     0,    19,    21,     0,     0,     0,
       0,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,     0,     0,     0,    27,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,     0,     0,     0,     0,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
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
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] =
{
       0,   146,     0,   146,     0,   150,     0,   150,     0,   150,
       0,   190,     0,   190,     0,   190,     0,   146,     0,   190,
       0,   190,     0,   190,     0,   190,     0,   190,     0,    11,
       0,   146,     0,   180,     0,   146,     0,   146,     0,   150,
       0,   180,     0
};

static const short int yycheck[] =
{
       0,     0,    36,    36,   118,    39,   181,    33,    29,    75,
       0,   118,    58,   118,   247,    38,    29,   122,    76,   250,
     213,    38,    35,     7,   127,    20,    21,    38,   250,     7,
      43,    44,   305,    36,   246,    93,    20,    21,     3,     4,
       5,    93,    20,    21,   131,    58,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     291,   148,    43,    47,    45,    72,    77,    39,   280,    76,
      93,   302,    47,     7,   100,    75,    93,   285,   112,   112,
     302,    39,   169,    38,   118,   118,    20,    21,   321,   123,
     124,   124,    38,   301,   197,    98,    99,    39,   101,   372,
      72,   294,    97,     7,   150,   151,   152,   282,   339,   112,
     100,   304,   287,    97,    72,    90,    20,    21,   118,    97,
     186,   124,    77,   316,    56,    57,    58,    59,    93,    72,
      72,    77,    97,   136,    90,    78,   170,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    93,    94,   244,   261,   264,
      38,   207,    38,    97,   112,   168,    72,   193,    20,    21,
      73,    39,    38,   287,    39,   282,   124,    38,   353,    72,
      38,   356,   287,    76,    90,   272,    38,    38,    66,    67,
      68,    69,   213,    97,   207,    47,    72,    73,   188,    77,
     213,    77,    73,    79,    72,   292,    66,    72,    40,    41,
      72,   346,   246,   246,    76,   350,   250,    77,   305,    79,
      66,   287,    60,    61,    66,     0,    72,    66,    63,    64,
      76,    77,    52,   259,    76,    77,    93,    76,    77,   326,
      53,    93,    50,   330,    62,    97,   280,   280,   282,   282,
     249,   356,    93,   274,   341,    72,    73,   291,    72,   293,
      75,   274,    72,    73,   264,    47,    48,    49,   302,   153,
     154,   297,    73,   294,   157,   158,   159,   160,    75,   366,
      73,   294,   369,   304,    90,   372,   285,   287,   155,   156,
      73,   304,   161,   162,    39,   316,    47,    38,    93,    93,
      79,    75,   301,   316,    75,   339,    93,    73,   342,   335,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    39,    38,    90,    39,    39,   325,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    72,
      75,    39,    79,    73,    75,    39,   356,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    72,    39,    73,    39,    43,    74,    45,
      93,    47,    39,    78,    78,    39,    52,    39,    54,    55,
      78,    78,    39,    78,    78,    39,    78,    93,    78,    78,
      96,    97,    68,    69,   163,   165,   164,    79,   353,    75,
      76,   166,   241,   167,    75,   280,   295,   325,   308,   341,
     276,    83,   178,    -1,    -1,    -1,    92,    93,    94,    -1,
      96,    97,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    43,    -1,    45,    -1,    47,    -1,    -1,    -1,
      -1,    52,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,    68,    69,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    -1,    96,    97,    37,    38,    -1,
      -1,    -1,    -1,    43,    -1,    45,    -1,    47,    -1,    -1,
      -1,    -1,    52,    -1,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    92,    93,    94,    -1,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    37,    38,    -1,
      73,    -1,    -1,    43,    77,    45,    -1,    47,    -1,    -1,
      38,    -1,    52,    -1,    54,    55,    -1,    -1,    -1,    47,
      93,    -1,    -1,    96,    97,    -1,    -1,    -1,    68,    69,
      -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    96,    97,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      93,    -1,    -1,    96,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    73,    -1,    -1,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    93,    -1,    -1,    96,    97,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    47,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,
      -1,    -1,    93,     3,     4,     5,    97,    -1,    -1,    -1,
      73,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      93,    -1,    -1,    96,    97,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    96,    97,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    93,    -1,    -1,    -1,    97,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    47,    -1,    -1,    43,    -1,    45,
      -1,    47,    -1,    -1,    -1,    -1,    52,    93,    54,    55,
      96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    -1,    68,    69,    43,    -1,    45,    -1,    47,    75,
      76,    -1,    -1,    52,    -1,    54,    55,    90,    -1,    -1,
      93,    -1,    -1,    -1,    97,    -1,    92,    93,    94,    68,
      69,    37,    38,    -1,    -1,    -1,    75,    43,    -1,    45,
      -1,    47,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,
      37,    38,    -1,    92,    93,    94,    43,    -1,    45,    -1,
      47,    -1,    68,    69,    -1,    52,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    37,    38,    -1,    92,    93,    94,    43,
      -1,    45,    -1,    47,    -1,    -1,    -1,    -1,    52,    -1,
      54,    55,    37,    38,    -1,    92,    93,    94,    43,    -1,
      45,    -1,    47,    -1,    68,    69,    -1,    52,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    -1,    -1,    -1,    92,    93,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    43,    45,    47,
      52,    54,    55,    68,    69,    75,    76,    92,    93,    94,
      96,    97,   100,   101,   102,   103,   105,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   123,   125,   126,   127,   130,   131,   133,   134,
     141,   144,   145,   146,   148,   153,   164,   171,   172,   175,
     176,   177,   178,   179,   180,   182,    93,   132,    38,    38,
      38,    38,    47,    93,   107,   120,   124,    90,    73,    73,
     177,    93,    38,   107,    93,   123,   131,   137,   138,   144,
     159,   144,   149,   154,    38,   107,   107,    90,     0,    93,
      94,    38,    66,    67,    68,    69,    77,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,   122,   109,
      47,    48,    49,    43,    45,    40,    41,    56,    57,    58,
      59,    60,    61,    52,    50,    53,    62,    63,    64,    72,
      47,    73,    93,   126,   128,   129,   146,   147,   148,    93,
     132,    38,    93,   151,   152,   125,   127,   181,   183,    73,
      75,   123,   123,   125,   177,   123,    90,   174,    73,    73,
     159,    39,   137,   146,   153,   157,   160,    39,   153,   144,
     159,    93,   171,    38,   104,   106,   121,    93,    93,   123,
     121,   109,   109,   109,   110,   110,   111,   111,   112,   112,
     112,   112,   113,   113,   114,   115,   116,   117,   118,   123,
     121,    72,    73,   151,    79,   181,    75,   146,   147,    38,
      77,    75,   125,    93,   142,   143,    39,    39,   177,    73,
      39,   173,   171,    39,    38,   161,   163,    75,   109,    39,
     124,    39,    72,    78,    90,   129,    75,   121,   165,    75,
     135,   136,   138,   152,    39,    38,    39,   127,   155,   156,
     158,     7,   149,   154,    79,    72,    76,    73,   177,   171,
     160,    38,    77,    66,    77,   166,   167,   168,   169,   170,
      39,   121,   120,   167,    76,   136,    90,   139,   140,   147,
     155,   146,   147,   160,    39,    72,   149,    47,   121,   150,
       7,   124,    76,   143,   177,    73,    39,   155,   162,     7,
      47,   149,   154,    93,   124,   165,    72,    76,    79,   170,
      72,    76,   124,    72,    73,    39,    38,    74,   158,   121,
      78,    78,   121,    39,   177,    39,   149,    78,   150,     7,
      78,    76,   166,    76,   140,    39,    78,    78,    39,   121,
      78,   121,   165,    78,    78
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

/* Line 936 of glr.c  */
#line 281 "cbook.y"
    {
        if (seen_ES)
	   {
	   TRACE_LOG("ES");
	   }
        else if (seen_DC)
	   {
	   TRACE_LOG("DC");
	   }
	;}
    break;

  case 3:

/* Line 936 of glr.c  */
#line 306 "cbook.y"
    {
#if STMT_DEBUG
              printf("declaration\n");
#endif
              seen_term_tok=TRUE;
	      cnt_rule(yyn);
              ;}
    break;

  case 4:

/* Line 936 of glr.c  */
#line 314 "cbook.y"
    {
#if STMT_DEBUG
              printf("statement\n");
#endif
	      seen_term_tok=TRUE;
	      cnt_rule(yyn);
              ;}
    break;

  case 5:

/* Line 936 of glr.c  */
#line 327 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              cnt_rule(yyn);
              ;}
    break;

  case 6:

/* Line 936 of glr.c  */
#line 332 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(INTEGER_CONST);
              cnt_rule(yyn);
              ;}
    break;

  case 7:

/* Line 936 of glr.c  */
#line 337 "cbook.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 8:

/* Line 936 of glr.c  */
#line 342 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_unary_node(TOK_OPEN_RND, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 9:

/* Line 936 of glr.c  */
#line 352 "cbook.y"
    {
            ((*yyvalp)).node_ptr=mk_leaf_node(STRING_CONST);
            cnt_rule(yyn);
            ;}
    break;

  case 10:

/* Line 936 of glr.c  */
#line 357 "cbook.y"
    {
            ((*yyvalp)).node_ptr=mk_binary_node(TOK_STRING_CONCAT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval).node_ptr,
					mk_leaf_node(STRING_CONST));
            cnt_rule(yyn);
            ;}
    break;

  case 11:

/* Line 936 of glr.c  */
#line 368 "cbook.y"
    {
            ((*yyvalp)).node_ptr=mk_leaf_node(TOK_IDENTIFIER);
            ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval);
            cnt_rule(yyn);
            ;}
    break;

  case 12:

/* Line 936 of glr.c  */
#line 374 "cbook.y"
    {
            ((*yyvalp)).node_ptr=mk_leaf_node(TOK_IDENTIFIER);
            ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval);
            cnt_rule(yyn);
            ;}
    break;

  case 13:

/* Line 936 of glr.c  */
#line 381 "cbook.y"
    {
              ((*yyvalp)).node_ptr=NULL;
	      cnt_rule(yyn);
              ;}
    break;

  case 14:

/* Line 936 of glr.c  */
#line 386 "cbook.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 15:

/* Line 936 of glr.c  */
#line 393 "cbook.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 16:

/* Line 936 of glr.c  */
#line 398 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_OPEN_SQUARE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 17:

/* Line 936 of glr.c  */
#line 403 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_FUNC_CALL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 18:

/* Line 936 of glr.c  */
#line 408 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_DIR_SELECT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr,
					         mk_leaf_node(TOK_IDENTIFIER));
              cnt_rule(yyn);
              ;}
    break;

  case 19:

/* Line 936 of glr.c  */
#line 414 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_INDIR_SELECT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr,
					         mk_leaf_node(TOK_IDENTIFIER));
              cnt_rule(yyn);
              ;}
    break;

  case 20:

/* Line 936 of glr.c  */
#line 420 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_unary_node(TOK_POST_PLUS, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 21:

/* Line 936 of glr.c  */
#line 425 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_unary_node(TOK_POST_MINUS, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 22:

/* Line 936 of glr.c  */
#line 430 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_CMPD_INIT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 23:

/* Line 936 of glr.c  */
#line 435 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_CMPD_INIT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (7))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 24:

/* Line 936 of glr.c  */
#line 443 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_ARG, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval).node_ptr, NULL);
              cnt_rule(yyn);
              ;}
    break;

  case 25:

/* Line 936 of glr.c  */
#line 448 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_ARG, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 26:

/* Line 936 of glr.c  */
#line 456 "cbook.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 27:

/* Line 936 of glr.c  */
#line 461 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_unary_node(TOK_PRE_PLUS, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 28:

/* Line 936 of glr.c  */
#line 466 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_unary_node(TOK_PRE_MINUS, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 29:

/* Line 936 of glr.c  */
#line 471 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_unary_node((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval).tok, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 30:

/* Line 936 of glr.c  */
#line 480 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_unary_node(TOK_SIZEOF, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 31:

/* Line 936 of glr.c  */
#line 485 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_unary_node(TOK_SIZEOF, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 32:

/* Line 936 of glr.c  */
#line 493 "cbook.y"
    {
	      ((*yyvalp)).tok=TOK_ADDR;
              cnt_rule(yyn);
              ;}
    break;

  case 33:

/* Line 936 of glr.c  */
#line 498 "cbook.y"
    {
              ((*yyvalp)).tok=TOK_STAR;
              cnt_rule(yyn);
              ;}
    break;

  case 34:

/* Line 936 of glr.c  */
#line 503 "cbook.y"
    {
              ((*yyvalp)).tok=TOK_PLUS;
              cnt_rule(yyn);
              ;}
    break;

  case 35:

/* Line 936 of glr.c  */
#line 508 "cbook.y"
    {
              ((*yyvalp)).tok=TOK_ARITH_NEG;
              cnt_rule(yyn);
              ;}
    break;

  case 36:

/* Line 936 of glr.c  */
#line 513 "cbook.y"
    {
              ((*yyvalp)).tok=TOK_BIT_NOT;
              cnt_rule(yyn);
              ;}
    break;

  case 37:

/* Line 936 of glr.c  */
#line 518 "cbook.y"
    {
              ((*yyvalp)).tok=TOK_LOG_NOT;
              cnt_rule(yyn);
              ;}
    break;

  case 38:

/* Line 936 of glr.c  */
#line 534 "cbook.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 39:

/* Line 936 of glr.c  */
#line 539 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_CAST, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 40:

/* Line 936 of glr.c  */
#line 555 "cbook.y"
    {
	      ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 41:

/* Line 936 of glr.c  */
#line 560 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_TIMES, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 42:

/* Line 936 of glr.c  */
#line 565 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_DIVIDE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 43:

/* Line 936 of glr.c  */
#line 570 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_REMAINDER, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 44:

/* Line 936 of glr.c  */
#line 599 "cbook.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 45:

/* Line 936 of glr.c  */
#line 604 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_ADD, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 46:

/* Line 936 of glr.c  */
#line 609 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_MINUS, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 47:

/* Line 936 of glr.c  */
#line 648 "cbook.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 48:

/* Line 936 of glr.c  */
#line 653 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_LSHIFT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 49:

/* Line 936 of glr.c  */
#line 658 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_RSHIFT, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 50:

/* Line 936 of glr.c  */
#line 666 "cbook.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 51:

/* Line 936 of glr.c  */
#line 671 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_LESS_THAN, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 52:

/* Line 936 of glr.c  */
#line 676 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_GREATER_THAN, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 53:

/* Line 936 of glr.c  */
#line 681 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_LESS_EQUAL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 54:

/* Line 936 of glr.c  */
#line 686 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_GR_EQUAL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 55:

/* Line 936 of glr.c  */
#line 694 "cbook.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 56:

/* Line 936 of glr.c  */
#line 699 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_EQ_EQUAL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 57:

/* Line 936 of glr.c  */
#line 704 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_EXC_EQUAL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 58:

/* Line 936 of glr.c  */
#line 720 "cbook.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 59:

/* Line 936 of glr.c  */
#line 725 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_BIT_AND, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 60:

/* Line 936 of glr.c  */
#line 740 "cbook.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 61:

/* Line 936 of glr.c  */
#line 745 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_BIT_XOR, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 62:

/* Line 936 of glr.c  */
#line 753 "cbook.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 63:

/* Line 936 of glr.c  */
#line 758 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_BIT_OR, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 64:

/* Line 936 of glr.c  */
#line 766 "cbook.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 65:

/* Line 936 of glr.c  */
#line 771 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_LOG_AND, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 66:

/* Line 936 of glr.c  */
#line 779 "cbook.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 67:

/* Line 936 of glr.c  */
#line 784 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_LOG_OR, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 68:

/* Line 936 of glr.c  */
#line 792 "cbook.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 69:

/* Line 936 of glr.c  */
#line 797 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_QUESTION, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval).node_ptr,
				mk_binary_node(TOK_COLON, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval).node_ptr));
              cnt_rule(yyn);
              ;}
    break;

  case 70:

/* Line 936 of glr.c  */
#line 806 "cbook.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 71:

/* Line 936 of glr.c  */
#line 811 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).tok, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 72:

/* Line 936 of glr.c  */
#line 819 "cbook.y"
    {
              ((*yyvalp)).tok=TOK_EQUAL;
              cnt_rule(yyn);
              ;}
    break;

  case 73:

/* Line 936 of glr.c  */
#line 824 "cbook.y"
    {
              ((*yyvalp)).tok=TOK_MULT_EQUAL;
              cnt_rule(yyn);
              ;}
    break;

  case 74:

/* Line 936 of glr.c  */
#line 829 "cbook.y"
    {
              ((*yyvalp)).tok=TOK_DIV_EQUAL;
              cnt_rule(yyn);
              ;}
    break;

  case 75:

/* Line 936 of glr.c  */
#line 834 "cbook.y"
    {
              ((*yyvalp)).tok=TOK_REM_EQUAL;
              cnt_rule(yyn);
              ;}
    break;

  case 76:

/* Line 936 of glr.c  */
#line 839 "cbook.y"
    {
              ((*yyvalp)).tok=TOK_PLUS_EQUAL;
              cnt_rule(yyn);
              ;}
    break;

  case 77:

/* Line 936 of glr.c  */
#line 844 "cbook.y"
    {
              ((*yyvalp)).tok=TOK_MIN_EQUAL;
              cnt_rule(yyn);
              ;}
    break;

  case 78:

/* Line 936 of glr.c  */
#line 849 "cbook.y"
    {
              ((*yyvalp)).tok=TOK_LSH_ASSIGN;
              cnt_rule(yyn);
              ;}
    break;

  case 79:

/* Line 936 of glr.c  */
#line 854 "cbook.y"
    {
              ((*yyvalp)).tok=TOK_RSH_ASSIGN;
              cnt_rule(yyn);
              ;}
    break;

  case 80:

/* Line 936 of glr.c  */
#line 859 "cbook.y"
    {
              ((*yyvalp)).tok=TOK_AND_ASSIGN;
              cnt_rule(yyn);
              ;}
    break;

  case 81:

/* Line 936 of glr.c  */
#line 864 "cbook.y"
    {
              ((*yyvalp)).tok=TOK_BOR_ASSIGN;
              cnt_rule(yyn);
              ;}
    break;

  case 82:

/* Line 936 of glr.c  */
#line 869 "cbook.y"
    {
              ((*yyvalp)).tok=TOK_BXOR_ASSIGN;
              cnt_rule(yyn);
              ;}
    break;

  case 83:

/* Line 936 of glr.c  */
#line 877 "cbook.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
              ;}
    break;

  case 84:

/* Line 936 of glr.c  */
#line 882 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_COMMA, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
	      cnt_rule(yyn);
              ;}
    break;

  case 85:

/* Line 936 of glr.c  */
#line 890 "cbook.y"
    {
	      ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              cnt_rule(yyn);
	      ;}
    break;

  case 86:

/* Line 936 of glr.c  */
#line 922 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 87:

/* Line 936 of glr.c  */
#line 926 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 88:

/* Line 936 of glr.c  */
#line 936 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 89:

/* Line 936 of glr.c  */
#line 940 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 90:

/* Line 936 of glr.c  */
#line 944 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 91:

/* Line 936 of glr.c  */
#line 948 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 92:

/* Line 936 of glr.c  */
#line 954 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 93:

/* Line 936 of glr.c  */
#line 958 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 94:

/* Line 936 of glr.c  */
#line 965 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 95:

/* Line 936 of glr.c  */
#line 969 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 96:

/* Line 936 of glr.c  */
#line 976 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 97:

/* Line 936 of glr.c  */
#line 980 "cbook.y"
    {
              got_expression(INIT_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 98:

/* Line 936 of glr.c  */
#line 988 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_TYPEDEF);
              cnt_rule(yyn);
              ;}
    break;

  case 99:

/* Line 936 of glr.c  */
#line 993 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_EXTERN);
              cnt_rule(yyn);
              ;}
    break;

  case 100:

/* Line 936 of glr.c  */
#line 998 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_STATIC);
              cnt_rule(yyn);
              ;}
    break;

  case 101:

/* Line 936 of glr.c  */
#line 1003 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_AUTO);
              cnt_rule(yyn);
              ;}
    break;

  case 102:

/* Line 936 of glr.c  */
#line 1008 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_REGISTER);
              cnt_rule(yyn);
              ;}
    break;

  case 103:

/* Line 936 of glr.c  */
#line 1016 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_VOID);
              cnt_rule(yyn);
              ;}
    break;

  case 104:

/* Line 936 of glr.c  */
#line 1021 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_CHAR);
              cnt_rule(yyn);
              ;}
    break;

  case 105:

/* Line 936 of glr.c  */
#line 1026 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_SHORT);
              cnt_rule(yyn);
              ;}
    break;

  case 106:

/* Line 936 of glr.c  */
#line 1031 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_INT);
              cnt_rule(yyn);
              ;}
    break;

  case 107:

/* Line 936 of glr.c  */
#line 1036 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_LONG);
              cnt_rule(yyn);
              ;}
    break;

  case 108:

/* Line 936 of glr.c  */
#line 1041 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_FLOAT);
              cnt_rule(yyn);
              ;}
    break;

  case 109:

/* Line 936 of glr.c  */
#line 1046 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_DOUBLE);
              cnt_rule(yyn);
              ;}
    break;

  case 110:

/* Line 936 of glr.c  */
#line 1051 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_SIGNED);
              cnt_rule(yyn);
              ;}
    break;

  case 111:

/* Line 936 of glr.c  */
#line 1056 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_UNSIGNED);
              cnt_rule(yyn);
              ;}
    break;

  case 112:

/* Line 936 of glr.c  */
#line 1061 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK__BOOL);
              cnt_rule(yyn);
              ;}
    break;

  case 113:

/* Line 936 of glr.c  */
#line 1066 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK__COMPLEX);
              cnt_rule(yyn);
              ;}
    break;

  case 114:

/* Line 936 of glr.c  */
#line 1071 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK__IMAGINARY);
              cnt_rule(yyn);
              ;}
    break;

  case 115:

/* Line 936 of glr.c  */
#line 1076 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 116:

/* Line 936 of glr.c  */
#line 1080 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 117:

/* Line 936 of glr.c  */
#line 1084 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 118:

/* Line 936 of glr.c  */
#line 1089 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 119:

/* Line 936 of glr.c  */
#line 1093 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              cnt_rule(yyn);
              ;}
    break;

  case 120:

/* Line 936 of glr.c  */
#line 1101 "cbook.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval);
	      cnt_rule(yyn);
              ;}
    break;

  case 121:

/* Line 936 of glr.c  */
#line 1106 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              cnt_rule(yyn);
              ;}
    break;

  case 122:

/* Line 936 of glr.c  */
#line 1114 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 123:

/* Line 936 of glr.c  */
#line 1118 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 124:

/* Line 936 of glr.c  */
#line 1125 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 125:

/* Line 936 of glr.c  */
#line 1129 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 126:

/* Line 936 of glr.c  */
#line 1136 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 127:

/* Line 936 of glr.c  */
#line 1143 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 128:

/* Line 936 of glr.c  */
#line 1147 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 129:

/* Line 936 of glr.c  */
#line 1156 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 130:

/* Line 936 of glr.c  */
#line 1160 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_qualifier_list((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 131:

/* Line 936 of glr.c  */
#line 1168 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 132:

/* Line 936 of glr.c  */
#line 1172 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 133:

/* Line 936 of glr.c  */
#line 1190 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 134:

/* Line 936 of glr.c  */
#line 1194 "cbook.y"
    {
              got_expression(EMPT_COLON_CE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval).node_ptr);
	      cnt_rule(yyn);
              ;}
    break;

  case 135:

/* Line 936 of glr.c  */
#line 1216 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_ENUM);
              cnt_rule(yyn);
              ;}
    break;

  case 136:

/* Line 936 of glr.c  */
#line 1221 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_ENUM);
              cnt_rule(yyn);
              ;}
    break;

  case 137:

/* Line 936 of glr.c  */
#line 1226 "cbook.y"
    {
	      /*
	       * All instances of IDENTIFIER in the grammar need a mk_leaf_node
	       * so that previously pushed identifiers get popped in the
	       * correct order.
	       */
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_ENUM);
              cnt_rule(yyn);
              ;}
    break;

  case 138:

/* Line 936 of glr.c  */
#line 1240 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 139:

/* Line 936 of glr.c  */
#line 1244 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 140:

/* Line 936 of glr.c  */
#line 1251 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              cnt_rule(yyn);
              ;}
    break;

  case 141:

/* Line 936 of glr.c  */
#line 1256 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              got_expression(ENUM_INITIAL_CE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 142:

/* Line 936 of glr.c  */
#line 1265 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_CONST);
              cnt_rule(yyn);
              ;}
    break;

  case 143:

/* Line 936 of glr.c  */
#line 1270 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_RESTRICT);
              cnt_rule(yyn);
              ;}
    break;

  case 144:

/* Line 936 of glr.c  */
#line 1275 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_VOLATILE);
              cnt_rule(yyn);
              ;}
    break;

  case 145:

/* Line 936 of glr.c  */
#line 1283 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 146:

/* Line 936 of glr.c  */
#line 1288 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 147:

/* Line 936 of glr.c  */
#line 1292 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 148:

/* Line 936 of glr.c  */
#line 1298 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 149:

/* Line 936 of glr.c  */
#line 1303 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 150:

/* Line 936 of glr.c  */
#line 1307 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 151:

/* Line 936 of glr.c  */
#line 1311 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 152:

/* Line 936 of glr.c  */
#line 1315 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 153:

/* Line 936 of glr.c  */
#line 1319 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 154:

/* Line 936 of glr.c  */
#line 1346 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              cnt_rule(yyn);
              ;}
    break;

  case 155:

/* Line 936 of glr.c  */
#line 1351 "cbook.y"
    {
/*
   printf("( declarator )\n");
*/
              cnt_rule(yyn);
              ;}
    break;

  case 156:

/* Line 936 of glr.c  */
#line 1358 "cbook.y"
    {
              got_expression(DIR_DECL_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 157:

/* Line 936 of glr.c  */
#line 1363 "cbook.y"
    {
              got_expression(DIR_DECL_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 158:

/* Line 936 of glr.c  */
#line 1368 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 159:

/* Line 936 of glr.c  */
#line 1372 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 160:

/* Line 936 of glr.c  */
#line 1378 "cbook.y"
    {
              got_expression(DIR_DECL_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 161:

/* Line 936 of glr.c  */
#line 1383 "cbook.y"
    {
/*
	      printf("direct_decl ( param type list )\n");
*/
              cnt_rule(yyn);
              ;}
    break;

  case 162:

/* Line 936 of glr.c  */
#line 1404 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 163:

/* Line 936 of glr.c  */
#line 1408 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 164:

/* Line 936 of glr.c  */
#line 1425 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 165:

/* Line 936 of glr.c  */
#line 1429 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 166:

/* Line 936 of glr.c  */
#line 1436 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 167:

/* Line 936 of glr.c  */
#line 1440 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 168:

/* Line 936 of glr.c  */
#line 1447 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 169:

/* Line 936 of glr.c  */
#line 1451 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 170:

/* Line 936 of glr.c  */
#line 1458 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 171:

/* Line 936 of glr.c  */
#line 1462 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 172:

/* Line 936 of glr.c  */
#line 1467 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 173:

/* Line 936 of glr.c  */
#line 1471 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 174:

/* Line 936 of glr.c  */
#line 1494 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 175:

/* Line 936 of glr.c  */
#line 1498 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 176:

/* Line 936 of glr.c  */
#line 1502 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 177:

/* Line 936 of glr.c  */
#line 1524 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_TYPEOF);
              cnt_rule(yyn);
              ;}
    break;

  case 178:

/* Line 936 of glr.c  */
#line 1532 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 179:

/* Line 936 of glr.c  */
#line 1536 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 180:

/* Line 936 of glr.c  */
#line 1541 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 181:

/* Line 936 of glr.c  */
#line 1545 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 182:

/* Line 936 of glr.c  */
#line 1549 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 183:

/* Line 936 of glr.c  */
#line 1553 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 184:

/* Line 936 of glr.c  */
#line 1559 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 185:

/* Line 936 of glr.c  */
#line 1563 "cbook.y"
    {
              print_filename();
	      got_expression(DIR_ABSDECL_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 186:

/* Line 936 of glr.c  */
#line 1569 "cbook.y"
    {
              print_filename();
              got_expression(DIR_ABSDECL_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 187:

/* Line 936 of glr.c  */
#line 1575 "cbook.y"
    {
              print_filename();
              got_expression(DIR_ABSDECL_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 188:

/* Line 936 of glr.c  */
#line 1581 "cbook.y"
    {
              print_filename();
              cnt_rule(yyn);
              ;}
    break;

  case 189:

/* Line 936 of glr.c  */
#line 1586 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 190:

/* Line 936 of glr.c  */
#line 1596 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              cnt_rule(yyn);
              ;}
    break;

  case 191:

/* Line 936 of glr.c  */
#line 1604 "cbook.y"
    {
              ((*yyvalp))=(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);
              ;}
    break;

  case 192:

/* Line 936 of glr.c  */
#line 1608 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_unary_node(TOK_OPEN_CURL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).node_ptr);
              ;}
    break;

  case 193:

/* Line 936 of glr.c  */
#line 1612 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_unary_node(TOK_OPEN_CURL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval).node_ptr);
              ;}
    break;

  case 194:

/* Line 936 of glr.c  */
#line 1617 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 195:

/* Line 936 of glr.c  */
#line 1621 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 196:

/* Line 936 of glr.c  */
#line 1627 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_ARG, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval).node_ptr, NULL);
              ;}
    break;

  case 197:

/* Line 936 of glr.c  */
#line 1631 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_binary_node(TOK_ARG, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval).node_ptr, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval).node_ptr);
              ;}
    break;

  case 198:

/* Line 936 of glr.c  */
#line 1639 "cbook.y"
    {
              ((*yyvalp)).node_ptr=NULL;
              ;}
    break;

  case 199:

/* Line 936 of glr.c  */
#line 1646 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 200:

/* Line 936 of glr.c  */
#line 1653 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 201:

/* Line 936 of glr.c  */
#line 1657 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 202:

/* Line 936 of glr.c  */
#line 1664 "cbook.y"
    {
              got_expression(DESIGNATOR_CE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 203:

/* Line 936 of glr.c  */
#line 1669 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              cnt_rule(yyn);
              ;}
    break;

  case 204:

/* Line 936 of glr.c  */
#line 1682 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 205:

/* Line 936 of glr.c  */
#line 1686 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 206:

/* Line 936 of glr.c  */
#line 1690 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 207:

/* Line 936 of glr.c  */
#line 1694 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 208:

/* Line 936 of glr.c  */
#line 1703 "cbook.y"
    {
              TRACE_LOG("{_");
              cnt_rule(yyn);
              ;}
    break;

  case 209:

/* Line 936 of glr.c  */
#line 1708 "cbook.y"
    {
              TRACE_LOG("}_");
              cnt_rule(yyn);
              ;}
    break;

  case 210:

/* Line 936 of glr.c  */
#line 1713 "cbook.y"
    {
              TRACE_LOG("EL");
              cnt_rule(yyn);
              ;}
    break;

  case 211:

/* Line 936 of glr.c  */
#line 1718 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 212:

/* Line 936 of glr.c  */
#line 1725 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              cnt_rule(yyn);
              ;}
    break;

  case 213:

/* Line 936 of glr.c  */
#line 1729 "cbook.y"
    {TRACE_LOG("CA");;}
    break;

  case 214:

/* Line 936 of glr.c  */
#line 1730 "cbook.y"
    {
              got_expression(CASE_LAB_CE, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 215:

/* Line 936 of glr.c  */
#line 1734 "cbook.y"
    {TRACE_LOG("DE");;}
    break;

  case 216:

/* Line 936 of glr.c  */
#line 1735 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 217:

/* Line 936 of glr.c  */
#line 1760 "cbook.y"
    {
              seen_ES=TRUE;
              got_expression(EXPR_STMT_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval).node_ptr);
	      cnt_rule(yyn);
              ;}
    break;

  case 218:

/* Line 936 of glr.c  */
#line 1775 "cbook.y"
    {
	      TRACE_LOG("IF");
              got_expression(IF_EXPR_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval).node_ptr);
	      cnt_rule(yyn);
              ;}
    break;

  case 219:

/* Line 936 of glr.c  */
#line 1781 "cbook.y"
    {
              TRACE_LOG("SW");
              got_expression(SWITCH_EXPR_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval).node_ptr);
	      cnt_rule(yyn);
              ;}
    break;

  case 220:

/* Line 936 of glr.c  */
#line 1788 "cbook.y"
    {
              ((*yyvalp)).node_ptr=NULL;
              cnt_rule(yyn);
              ;}
    break;

  case 221:

/* Line 936 of glr.c  */
#line 1793 "cbook.y"
    {
	      cnt_rule(yyn);
              ;}
    break;

  case 222:

/* Line 936 of glr.c  */
#line 1806 "cbook.y"
    {
              TRACE_LOG("WH");
              got_expression(WHILE_EXPR_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval).node_ptr);
	      cnt_rule(yyn);
              ;}
    break;

  case 223:

/* Line 936 of glr.c  */
#line 1812 "cbook.y"
    {
              TRACE_LOG("DO");
              cnt_rule(yyn);
              ;}
    break;

  case 224:

/* Line 936 of glr.c  */
#line 1825 "cbook.y"
    {
              TRACE_LOG("FO");
              got_expression(FOR_INIT_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (8))].yystate.yysemantics.yysval).node_ptr);
              got_expression(FOR_CNTRL_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (8))].yystate.yysemantics.yysval).node_ptr);
              got_expression(FOR_INC_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (8))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 225:

/* Line 936 of glr.c  */
#line 1833 "cbook.y"
    {
              TRACE_LOG("FO");
              got_expression(FOR_CNTRL_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval).node_ptr);
              got_expression(FOR_INC_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 226:

/* Line 936 of glr.c  */
#line 1843 "cbook.y"
    {
              ((*yyvalp)).node_ptr=mk_leaf_node(TOK_IDENTIFIER);
              TRACE_LOG("GO");
              cnt_rule(yyn);
              ;}
    break;

  case 227:

/* Line 936 of glr.c  */
#line 1849 "cbook.y"
    {
              TRACE_LOG("CO");
              cnt_rule(yyn);
              ;}
    break;

  case 228:

/* Line 936 of glr.c  */
#line 1854 "cbook.y"
    {
              TRACE_LOG("BR");
              cnt_rule(yyn);
              ;}
    break;

  case 229:

/* Line 936 of glr.c  */
#line 1859 "cbook.y"
    {
              TRACE_LOG("RE");
              got_expression(RETURN_EX, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).node_ptr);
              cnt_rule(yyn);
              ;}
    break;

  case 230:

/* Line 936 of glr.c  */
#line 1870 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 231:

/* Line 936 of glr.c  */
#line 1874 "cbook.y"
    {
              seen_DC=TRUE;
              cnt_rule(yyn);
              ;}
    break;

  case 232:

/* Line 936 of glr.c  */
#line 1880 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 233:

/* Line 936 of glr.c  */
#line 1884 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 234:

/* Line 936 of glr.c  */
#line 1906 "cbook.y"
    {
	      TRACE_LOG("FD");
              cnt_rule(yyn);
              ;}
    break;

  case 235:

/* Line 936 of glr.c  */
#line 1914 "cbook.y"
    {
	      TRACE_LOG("FD");
              cnt_rule(yyn);
              ;}
    break;

  case 236:

/* Line 936 of glr.c  */
#line 1922 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 237:

/* Line 936 of glr.c  */
#line 1926 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;



/* Line 936 of glr.c  */
#line 3998 "cbook.tab.c"
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
        case 1: *yy0 = stmt_decl_merge (*yy0, *yy1); break;
  case 2: *yy0 = multiplicative_merge (*yy0, *yy1); break;
  case 3: *yy0 = additive_merge (*yy0, *yy1); break;

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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(((yyGLRStackItem const *)yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yysemantics.yysval)
		       		       );
      YYFPRINTF (stderr, "\n");
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
	    }

	  if (yychar <= YYEOF)
	    {
	      yychar = yytoken = YYEOF;
	      YYDPRINTF ((stderr, "Now at end of input.\n"));
	    }
	  else
	    {
	      yytoken = YYTRANSLATE (yychar);
	      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
	    }

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
   of the lookahead.  */
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
	if (yychar <= YYEOF)
	  {
	    yychar = yytoken = YYEOF;
	    YYDPRINTF ((stderr, "Now at end of input.\n"));
	  }
	else
	  {
	    yytoken = YYTRANSLATE (yychar);
	    YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
	  }
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

      if (yys->yypred != NULL)
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
		}

	      if (yychar <= YYEOF)
		{
		  yychar = yytoken = YYEOF;
		  YYDPRINTF ((stderr, "Now at end of input.\n"));
		}
	      else
		{
		  yytoken = YYTRANSLATE (yychar);
		  YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
		}

	      yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
	      if (*yyconflicts != 0)
		break;
	      if (yyisShiftAction (yyaction))
		{
		  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
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
  if (yychar != YYEMPTY)
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
		    if (yys->yypred != NULL)
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
#if YYDEBUG
static void yypstack (yyGLRStack* yystackp, size_t yyk)
  __attribute__ ((__unused__));
static void yypdumpstack (yyGLRStack* yystackp) __attribute__ ((__unused__));

static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YYFPRINTF (stderr, " -> ");
    }
  YYFPRINTF (stderr, "%d@%lu", yys->yylrState,
             (unsigned long int) yys->yyposn);
}

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == NULL)
    YYFPRINTF (stderr, "<null>");
  else
    yy_yypstack (yyst);
  YYFPRINTF (stderr, "\n");
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
      YYFPRINTF (stderr, "%3lu. ",
                 (unsigned long int) (yyp - yystackp->yyitems));
      if (*(yybool *) yyp)
	{
	  YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
		     yyp->yystate.yyresolved, yyp->yystate.yylrState,
		     (unsigned long int) yyp->yystate.yyposn,
		     (long int) YYINDEX (yyp->yystate.yypred));
	  if (! yyp->yystate.yyresolved)
	    YYFPRINTF (stderr, ", firstVal: %ld",
		       (long int) YYINDEX (yyp->yystate
                                             .yysemantics.yyfirstVal));
	}
      else
	{
	  YYFPRINTF (stderr, "Option. rule: %d, state: %ld, next: %ld",
		     yyp->yyoption.yyrule - 1,
		     (long int) YYINDEX (yyp->yyoption.yystate),
		     (long int) YYINDEX (yyp->yyoption.yynext));
	}
      YYFPRINTF (stderr, "\n");
    }
  YYFPRINTF (stderr, "Tops:");
  for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
    YYFPRINTF (stderr, "%lu: %ld; ", (unsigned long int) yyi,
	       (long int) YYINDEX (yystackp->yytops.yystates[yyi]));
  YYFPRINTF (stderr, "\n");
}
#endif



/* Line 2634 of glr.c  */
#line 1986 "cbook.y"




