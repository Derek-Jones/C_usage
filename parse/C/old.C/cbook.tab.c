/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for GLR parsing with Bison,
   Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

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

/* This is the parser code for GLR (Generalized LR) parser. */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

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
     UNDEFINED = 353
   };
#endif
/* Tokens.  */
#define _BOOL 258
#define _COMPLEX 259
#define _IMAGINARY 260
#define AUTO 261
#define STATIC 262
#define EXTERN 263
#define REGISTER 264
#define TYPEDEF 265
#define CHAR 266
#define FLOAT 267
#define DOUBLE 268
#define INT 269
#define SHORT 270
#define LONG 271
#define UNSIGNED 272
#define SIGNED 273
#define VOID 274
#define CONST 275
#define VOLATILE 276
#define STRUCT 277
#define UNION 278
#define ENUM 279
#define IF 280
#define ELSE 281
#define WHILE 282
#define FOR 283
#define DO 284
#define SWITCH 285
#define CASE 286
#define DEFAULT 287
#define BREAK 288
#define CONTINUE 289
#define RETURN 290
#define GOTO 291
#define SIZEOF 292
#define OPEN_RND 293
#define CLOSE_RND 294
#define LEFTSHIFT 295
#define RIGHTSHIFT 296
#define PLUS 297
#define ADD 298
#define NEGATE 299
#define MINUS 300
#define STAR 301
#define TIMES 302
#define REMAINDER 303
#define DIVIDE 304
#define XOR 305
#define AND 306
#define BITAND 307
#define OR 308
#define BITNEGATE 309
#define NOT 310
#define LT 311
#define LE 312
#define GE 313
#define GT 314
#define EQUAL 315
#define NOTEQUAL 316
#define ANDTEST 317
#define ORTEST 318
#define QUESTION 319
#define DUMMY1 320
#define DOT 321
#define DEREF 322
#define PLUSPLUS 323
#define MINUSMINUS 324
#define POSTPLUSPLUS 325
#define POSTMINUSMINUS 326
#define COMMA 327
#define SEMICOLON 328
#define ELLIPSIS 329
#define OPEN_CURL 330
#define CLOSE_CURL 331
#define OPEN_SQUARE 332
#define CLOSE_SQUARE 333
#define ASSIGN 334
#define PLUSASSIGN 335
#define MINUSASSIGN 336
#define TIMESASSIGN 337
#define LSASSIGN 338
#define RSASSIGN 339
#define ANDASSIGN 340
#define DIVASSIGN 341
#define REMASSIGN 342
#define ORASSIGN 343
#define XORASSIGN 344
#define COLON 345
#define DUMMY2 346
#define CONSTANT 347
#define IDENTIFIER 348
#define STRING_LITERAL 349
#define TYPEDEFNAME 350
#define INLINE 351
#define RESTRICT 352
#define UNDEFINED 353




/* Copy the first part of user declarations.  */


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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
typedef struct YYLTYPE
{

  char yydummy;

} YYLTYPE;
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template,
   here we set the default value of $$ to a zeroed-out value.
   Since the default value is undefined, this behavior is
   technically correct. */
static YYSTYPE yyval_default;

/* Copy the second part of user declarations.  */


/* Line 217 of glr.c.  */
#line 295 "cbook.tab.c"

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
# if (!defined (__GNUC__) || __GNUC__ < 2 \
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

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  126
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1265

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  99
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  85
/* YYNRULES -- Number of rules. */
#define YYNRULES  232
/* YYNRULES -- Number of states. */
#define YYNSTATES  373
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule. */
#define YYMAXRHS 8
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule. */
#define YYMAXLEFT 0

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   353

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
      95,    96,    97,    98
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    19,
      21,    24,    25,    27,    29,    34,    39,    43,    47,    50,
      53,    60,    68,    70,    74,    76,    79,    82,    85,    88,
      93,    95,    97,    99,   101,   103,   105,   107,   112,   114,
     118,   122,   126,   128,   132,   136,   138,   142,   146,   148,
     152,   156,   160,   164,   166,   170,   174,   176,   180,   182,
     186,   188,   192,   194,   198,   200,   204,   206,   212,   214,
     218,   220,   222,   224,   226,   228,   230,   232,   234,   236,
     238,   240,   242,   246,   248,   251,   255,   257,   259,   261,
     263,   265,   268,   270,   274,   276,   280,   282,   284,   286,
     288,   290,   292,   294,   296,   298,   300,   302,   304,   306,
     308,   310,   312,   314,   316,   318,   320,   321,   323,   329,
     332,   334,   336,   338,   341,   345,   347,   349,   351,   354,
     356,   360,   362,   365,   371,   378,   381,   383,   387,   389,
     393,   395,   397,   399,   401,   402,   404,   407,   410,   411,
     413,   414,   416,   417,   419,   421,   425,   431,   438,   445,
     451,   453,   458,   465,   470,   473,   477,   479,   482,   484,
     488,   490,   494,   495,   497,   500,   502,   505,   507,   511,
     514,   516,   519,   520,   522,   523,   525,   529,   534,   539,
     544,   546,   548,   552,   557,   558,   560,   563,   568,   571,
     573,   576,   580,   583,   585,   587,   589,   591,   593,   595,
     599,   604,   608,   611,   616,   621,   622,   624,   629,   631,
     640,   648,   652,   655,   658,   662,   664,   666,   667,   669,
     674,   678,   680
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     100,     0,    -1,   101,    -1,   180,    -1,   173,    -1,    93,
      -1,    92,    -1,   103,    -1,    38,   123,    39,    -1,    94,
      -1,   103,    94,    -1,    -1,   106,    -1,   102,    -1,   105,
      77,   123,    78,    -1,   105,    38,   104,    39,    -1,   105,
      66,    93,    -1,   105,    67,    93,    -1,   105,    68,    -1,
     105,    69,    -1,    38,   161,    39,    75,   169,    76,    -1,
      38,   161,    39,    75,   169,    72,    76,    -1,   121,    -1,
     106,    72,   121,    -1,   105,    -1,    68,   107,    -1,    69,
     107,    -1,   108,   109,    -1,    37,   107,    -1,    37,    38,
     161,    39,    -1,    51,    -1,    47,    -1,    43,    -1,    45,
      -1,    54,    -1,    55,    -1,   107,    -1,    38,   161,    39,
     109,    -1,   109,    -1,   110,    47,   109,    -1,   110,    49,
     109,    -1,   110,    48,   109,    -1,   110,    -1,   111,    43,
     110,    -1,   111,    45,   110,    -1,   111,    -1,   112,    40,
     111,    -1,   112,    41,   111,    -1,   112,    -1,   113,    56,
     112,    -1,   113,    59,   112,    -1,   113,    57,   112,    -1,
     113,    58,   112,    -1,   113,    -1,   114,    60,   113,    -1,
     114,    61,   113,    -1,   114,    -1,   115,    51,   114,    -1,
     115,    -1,   116,    50,   115,    -1,   116,    -1,   117,    53,
     116,    -1,   117,    -1,   118,    62,   117,    -1,   118,    -1,
     119,    63,   118,    -1,   119,    -1,   119,    64,   123,    90,
     120,    -1,   120,    -1,   107,   122,   121,    -1,    79,    -1,
      82,    -1,    86,    -1,    87,    -1,    80,    -1,    81,    -1,
      83,    -1,    84,    -1,    85,    -1,    88,    -1,    89,    -1,
     121,    -1,   123,    72,   121,    -1,   120,    -1,   127,    73,
      -1,   127,   128,    73,    -1,   130,    -1,   131,    -1,   144,
      -1,   145,    -1,   126,    -1,   127,   126,    -1,   129,    -1,
     128,    72,   129,    -1,   147,    -1,   147,    79,   167,    -1,
      10,    -1,     8,    -1,     7,    -1,     6,    -1,     9,    -1,
      19,    -1,    11,    -1,    15,    -1,    14,    -1,    16,    -1,
      12,    -1,    13,    -1,    18,    -1,    17,    -1,     3,    -1,
       4,    -1,     5,    -1,   133,    -1,   141,    -1,   166,    -1,
      -1,    93,    -1,   134,   132,    75,   135,    76,    -1,   134,
      93,    -1,    22,    -1,    23,    -1,   136,    -1,   135,   136,
      -1,   138,   139,    73,    -1,   131,    -1,   144,    -1,   137,
      -1,   138,   137,    -1,   140,    -1,   139,    72,   140,    -1,
     147,    -1,    90,   124,    -1,    24,   132,    75,   142,    76,
      -1,    24,   132,    75,   142,    72,    76,    -1,    24,    93,
      -1,   143,    -1,   142,    72,   143,    -1,    93,    -1,    93,
      79,   124,    -1,    20,    -1,    97,    -1,    21,    -1,    96,
      -1,    -1,   154,    -1,   146,   152,    -1,   146,   153,    -1,
      -1,   155,    -1,    -1,   121,    -1,    -1,   160,    -1,    93,
      -1,    38,   147,    39,    -1,   152,    77,   149,   150,    78,
      -1,   152,    77,     7,   149,   121,    78,    -1,   152,    77,
     155,     7,   121,    78,    -1,   152,    77,   149,    47,    78,
      -1,   153,    -1,   152,    38,   156,    39,    -1,   152,    38,
      38,   156,    39,    39,    -1,   152,    38,   151,    39,    -1,
      47,   149,    -1,    47,   149,   154,    -1,   144,    -1,   155,
     144,    -1,   157,    -1,   157,    72,    74,    -1,   159,    -1,
     157,    72,   159,    -1,    -1,   162,    -1,   127,   147,    -1,
     127,    -1,   127,   162,    -1,    93,    -1,   160,    72,    93,
      -1,   138,   158,    -1,   154,    -1,   146,   165,    -1,    -1,
     165,    -1,    -1,   156,    -1,    38,   162,    39,    -1,   163,
      77,   150,    78,    -1,   163,    77,    47,    78,    -1,   163,
      38,   164,    39,    -1,    93,    -1,   121,    -1,    75,   169,
      76,    -1,    75,   169,    72,    76,    -1,    -1,   170,    -1,
     168,   167,    -1,   169,    72,   168,   167,    -1,   171,    79,
      -1,   172,    -1,   171,   172,    -1,    77,   124,    78,    -1,
      66,    93,    -1,   174,    -1,   175,    -1,   176,    -1,   178,
      -1,    75,    -1,   179,    -1,    93,    90,   173,    -1,    31,
     124,    90,   173,    -1,    32,    90,   173,    -1,   177,    73,
      -1,    25,    38,   123,    39,    -1,    30,    38,   123,    39,
      -1,    -1,   123,    -1,    27,    38,   123,    39,    -1,    29,
      -1,    28,    38,   177,    73,   177,    73,   177,    39,    -1,
      28,    38,   125,   177,    73,   177,    39,    -1,    36,    93,
      73,    -1,    34,    73,    -1,    33,    73,    -1,    35,   177,
      73,    -1,   182,    -1,   125,    -1,    -1,   183,    -1,   127,
     148,   181,    75,    -1,   148,   181,    75,    -1,   125,    -1,
     183,   125,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   292,   292,   309,   317,   330,   334,   338,   342,   351,
     355,   361,   364,   370,   374,   378,   382,   386,   390,   394,
     398,   402,   409,   413,   420,   424,   428,   432,   440,   444,
     451,   455,   459,   463,   467,   471,   486,   490,   505,   509,
     513,   517,   553,   557,   561,   605,   609,   613,   620,   624,
     628,   632,   636,   643,   647,   651,   666,   670,   688,   692,
     699,   703,   710,   714,   721,   725,   732,   736,   743,   747,
     754,   758,   762,   766,   770,   774,   778,   782,   786,   790,
     794,   801,   805,   812,   840,   844,   854,   858,   862,   866,
     872,   876,   883,   887,   894,   898,   905,   909,   913,   917,
     921,   928,   932,   936,   940,   944,   948,   952,   956,   960,
     964,   968,   972,   976,   980,   984,   990,   993,  1000,  1004,
    1011,  1015,  1022,  1026,  1033,  1040,  1044,  1050,  1054,  1061,
    1065,  1083,  1087,  1109,  1113,  1117,  1124,  1128,  1135,  1139,
    1146,  1150,  1154,  1161,  1167,  1170,  1176,  1182,  1188,  1191,
    1196,  1199,  1204,  1207,  1223,  1227,  1231,  1235,  1239,  1243,
    1247,  1253,  1271,  1275,  1282,  1286,  1293,  1297,  1304,  1308,
    1315,  1319,  1325,  1328,  1351,  1355,  1359,  1366,  1370,  1377,
    1384,  1388,  1394,  1397,  1402,  1405,  1411,  1415,  1419,  1423,
    1433,  1440,  1444,  1448,  1454,  1457,  1463,  1467,  1474,  1481,
    1485,  1492,  1496,  1508,  1512,  1516,  1520,  1527,  1532,  1539,
    1543,  1547,  1572,  1586,  1591,  1598,  1601,  1614,  1619,  1632,
    1637,  1645,  1650,  1655,  1660,  1670,  1674,  1681,  1684,  1694,
    1702,  1710,  1714
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
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
  "spec_qual_list", "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "function_specifier", "pointer_opt", "declarator",
  "fndef_declarator", "type_qualifier_list_opt", "assignment_expr_opt",
  "identifier_list_opt", "direct_declarator", "fndef_direct_declarator",
  "pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "abstract_declarator_opt", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator_opt", "parameter_type_list_opt",
  "direct_abstract_declarator", "typedef_name", "initializer",
  "designation_opt", "initializer_list", "designation", "designator_list",
  "designator", "statement", "labeled_statement", "expression_statement",
  "selection_header", "expr_opt", "iteration_header", "jump_statement",
  "external_declaration", "declaration_list_opt", "function_header",
  "declaration_list", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    99,   100,   101,   101,   102,   102,   102,   102,   103,
     103,   104,   104,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   106,   106,   107,   107,   107,   107,   107,   107,
     108,   108,   108,   108,   108,   108,   109,   109,   110,   110,
     110,   110,   111,   111,   111,   112,   112,   112,   113,   113,
     113,   113,   113,   114,   114,   114,   115,   115,   116,   116,
     117,   117,   118,   118,   119,   119,   120,   120,   121,   121,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   123,   123,   124,   125,   125,   126,   126,   126,   126,
     127,   127,   128,   128,   129,   129,   130,   130,   130,   130,
     130,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   132,   132,   133,   133,
     134,   134,   135,   135,   136,   137,   137,   138,   138,   139,
     139,   140,   140,   141,   141,   141,   142,   142,   143,   143,
     144,   144,   144,   145,   146,   146,   147,   148,   149,   149,
     150,   150,   151,   151,   152,   152,   152,   152,   152,   152,
     152,   153,   153,   153,   154,   154,   155,   155,   156,   156,
     157,   157,   158,   158,   159,   159,   159,   160,   160,   161,
     162,   162,   163,   163,   164,   164,   165,   165,   165,   165,
     166,   167,   167,   167,   168,   168,   169,   169,   170,   171,
     171,   172,   172,   173,   173,   173,   173,   173,   173,   174,
     174,   174,   175,   176,   176,   177,   177,   178,   178,   178,
     178,   179,   179,   179,   179,   180,   180,   181,   181,   182,
     182,   183,   183
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     0,     1,     1,     4,     4,     3,     3,     2,     2,
       6,     7,     1,     3,     1,     2,     2,     2,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     3,     1,     1,     1,     1,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     5,     2,
       1,     1,     1,     2,     3,     1,     1,     1,     2,     1,
       3,     1,     2,     5,     6,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     0,     1,     2,     2,     0,     1,
       0,     1,     0,     1,     1,     3,     5,     6,     6,     5,
       1,     4,     6,     4,     2,     3,     1,     2,     1,     3,
       1,     3,     0,     1,     2,     1,     2,     1,     3,     2,
       1,     2,     0,     1,     0,     1,     3,     4,     4,     4,
       1,     1,     3,     4,     0,     1,     2,     4,     2,     1,
       2,     3,     2,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     4,     4,     0,     1,     4,     1,     8,
       7,     3,     2,     2,     3,     1,     1,     0,     1,     4,
       3,     1,     2
};

/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none). */
static const unsigned char yydprec[] =
{
       0,     0,     0,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     1,
       0,     0,     0,     0,     0,     0,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     0,     0,
       0,     2,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     1,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM. */
static const unsigned char yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     1,
       0,     0,     2,     2,     2,     0,     0,     0,     0,     0,
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
       0,     0,     0
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error.  */
static const unsigned char yydefact[] =
{
     215,   110,   111,   112,    99,    98,    97,   100,    96,   102,
     106,   107,   104,   103,   105,   109,   108,   101,   140,   142,
     120,   121,   116,     0,     0,     0,   218,     0,     0,     0,
       0,     0,   215,     0,     0,     0,    32,    33,    31,    30,
      34,    35,     0,     0,   207,     6,     5,     9,   143,   141,
       0,     2,    13,     7,    24,    36,     0,    38,    42,    45,
      48,    53,    56,    58,    60,    62,    64,    66,    68,    81,
     216,   226,    90,   144,    86,    87,   113,   116,   114,    88,
      89,     0,   227,   145,   115,     4,   203,   204,   205,     0,
     206,   208,     3,   225,   135,     0,     0,     0,   215,     0,
      31,     5,    36,    83,     0,   215,   223,   222,     0,     0,
       0,    28,     5,     0,   125,   127,   144,   126,     0,   166,
     164,   149,     0,    25,    26,   215,     1,    10,    11,     0,
       0,    18,    19,     0,    70,    74,    75,    71,    76,    77,
      78,    72,    73,    79,    80,     0,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,    84,   190,
      91,     0,    92,     0,    94,   227,   119,     0,   144,   154,
       0,   147,   231,   144,     0,   228,   212,     0,     0,     0,
     215,     0,     0,   215,     5,   211,   224,   221,     0,     8,
     128,   182,   145,   179,   173,     0,   165,   167,     0,   209,
       0,    12,    22,    16,    17,     0,    69,    39,    41,    40,
      43,    44,    46,    47,    49,    51,    52,    50,    54,    55,
      57,    59,    61,    63,    65,     0,    82,   144,    85,   146,
       0,     0,     0,     0,     0,   152,   148,   230,   232,   138,
       0,   136,   213,   217,     0,   215,   214,   210,    29,   144,
       0,   181,   194,    37,     0,    15,     0,    14,     0,    93,
     194,   191,    95,   229,     0,   122,   144,   160,   155,     0,
     190,   144,     0,     0,   168,   170,   153,   148,   150,   149,
       0,     0,   133,   215,     0,     0,   184,   150,     0,     0,
       0,     0,   195,     0,   199,    23,    67,     0,   118,   123,
       0,     0,   129,   131,     0,   182,   174,   176,   163,   161,
       0,     0,     0,    31,   151,     0,     0,   139,   134,   137,
       0,   215,   186,   185,     0,    31,     0,   202,     0,   196,
     194,    20,   198,   200,   194,   192,   132,   144,   124,     0,
     144,   169,   171,   178,     0,   159,   156,     0,   220,     0,
     189,   188,   187,   201,    21,     0,   193,   130,   162,   157,
     158,   219,   197
};

/* YYPDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,    50,    51,    52,    53,   210,    54,   211,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,   145,    70,   104,   182,    72,   183,   171,
     172,    74,    75,    95,    76,    77,   274,   275,   115,   116,
     311,   312,    78,   250,   251,    79,    80,   243,   174,    82,
     120,   325,   282,   239,   181,    83,   121,   283,   284,   203,
     285,   286,   118,   295,   260,   334,   261,    84,   272,   300,
     301,   302,   303,   304,    85,    86,    87,    88,    89,    90,
      91,    92,   184,    93,   185
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -278
static const short int yypact[] =
{
     324,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,   -11,    83,   103,   113,  -278,   141,   839,    54,
     136,   145,   839,   112,  1086,   480,  -278,  -278,     6,  -278,
    -278,  -278,  1119,  1119,  -278,  -278,   592,  -278,  -278,  -278,
     223,  -278,  -278,   130,    -2,   321,   839,  -278,   146,    13,
      57,   132,    46,   175,   179,   178,   170,   122,  -278,  -278,
     161,  -278,  -278,   732,  -278,  -278,  -278,   142,  -278,  -278,
    -278,    -9,   966,  -278,  -278,  -278,  -278,  -278,  -278,   168,
    -278,  -278,  -278,  -278,   173,   180,   839,   839,   419,   839,
    -278,  -278,  -278,  -278,   160,  1059,  -278,  -278,   184,   185,
     480,  -278,   547,     8,  -278,  -278,   988,  -278,   222,  -278,
     217,     4,   480,  -278,  -278,  1059,  -278,  -278,   839,   174,
     176,  -278,  -278,   839,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,   839,  -278,   839,   839,   839,
     839,   839,   839,   839,   839,   839,   839,   839,   839,   839,
     839,   839,   839,   839,   839,   839,   839,     4,  -278,  -278,
    -278,   128,  -278,    -9,   189,   966,   173,   195,   217,  -278,
      10,    -3,  -278,   827,   196,   966,  -278,   183,    20,    32,
     839,   199,    39,  1059,   187,  -278,  -278,  -278,   234,  -278,
    -278,   240,    80,  -278,  -278,   159,  -278,  -278,   243,  -278,
     244,   207,  -278,  -278,  -278,    70,  -278,  -278,  -278,  -278,
     146,   146,    13,    13,    57,    57,    57,    57,   132,   132,
      46,   175,   179,   178,   170,   -33,  -278,   217,  -278,    10,
     580,   209,   291,    -9,   248,   849,    12,  -278,  -278,   210,
     -21,  -278,  -278,  -278,   215,   839,  -278,  -278,   216,   217,
      14,    16,   -16,  -278,   216,  -278,   839,  -278,   839,  -278,
     -16,  -278,  -278,  -278,   799,  -278,  1053,  -278,  -278,   966,
      81,   687,   251,   253,   221,  -278,   226,     4,  1138,    21,
     839,   -31,  -278,   839,   227,   260,   966,  1171,   224,   839,
     580,    78,  -278,    79,  -278,  -278,  -278,    87,  -278,  -278,
     839,   135,  -278,  -278,   277,    -8,  -278,  -278,  -278,  -278,
     944,   225,   839,   241,  -278,   242,   839,  -278,  -278,  -278,
     283,   839,  -278,  -278,   284,   246,   247,  -278,   285,  -278,
      91,  -278,  -278,  -278,   106,  -278,  -278,   -13,  -278,   287,
     217,  -278,  -278,  -278,   286,  -278,  -278,   288,  -278,   326,
    -278,  -278,  -278,  -278,  -278,   580,  -278,  -278,  -278,  -278,
    -278,  -278,  -278
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,   -25,  -278,
     -35,    61,    64,    82,    62,   208,   211,   212,   213,   206,
    -278,   -24,  -123,  -278,    65,  -144,     7,   -36,     1,  -278,
     140,  -278,   -20,   296,  -278,  -278,  -278,   107,  -100,  -193,
    -278,    33,  -278,  -278,    92,   -27,  -278,     0,  -166,   309,
    -208,    88,  -278,   305,  -229,  -110,   143,  -233,  -278,  -278,
      67,  -278,   -50,  -103,  -278,  -278,  -278,  -278,  -277,  -171,
     120,  -278,  -278,    93,   -85,  -278,  -278,  -278,   -30,  -278,
    -278,  -278,   219,  -278,  -278
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -191
static const short int yytable[] =
{
      81,    73,   108,   102,   103,   212,   202,    71,   117,   111,
     206,   119,   244,   204,   277,   114,   200,   123,   124,   287,
     195,   146,   216,   339,    18,    19,    18,    19,   326,   178,
     350,   102,    18,    19,   167,  -160,   128,   170,   288,   166,
     209,    18,    19,   236,   -31,   328,   314,   199,   245,   276,
     298,   291,   296,   -31,  -183,   292,   150,   268,   151,   252,
     198,   299,   249,   333,   129,   130,   131,   132,   191,  -160,
    -160,   253,   208,   173,  -160,   133,  -160,   310,   256,   322,
     166,   276,    94,   117,   179,   179,   277,   246,   372,   117,
     114,   297,   166,  -183,   207,   117,   114,   152,   153,   -31,
     113,    49,   114,    49,   166,   190,   158,   159,   257,    49,
     313,   166,   217,   218,   219,   316,   201,   271,    49,  -180,
    -177,    96,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     119,    97,   166,   305,   105,   298,   327,   170,   267,   202,
     340,    98,  -180,  -177,   341,   338,   299,   298,   342,   344,
     254,   188,   189,   345,   192,   324,   346,   364,   299,   365,
     263,   202,   298,   365,   324,   113,   200,   271,   317,    99,
     102,   313,   366,   299,   244,   164,   165,   113,   154,   155,
     156,   157,   248,   147,   148,   149,    34,    35,   215,   354,
     237,   238,    36,   357,    37,   109,   100,   347,   348,   106,
      39,   220,   221,    40,    41,   117,   222,   223,   107,   119,
     228,   229,   114,   126,   127,   294,   160,    42,    43,   161,
     235,   162,   163,   166,   262,   176,   224,   225,   226,   227,
     202,   186,   271,   102,   306,   170,   281,   117,  -117,   117,
     193,    45,   101,    47,   114,   187,   114,   196,   197,   201,
     119,   205,   207,   330,   167,   102,   103,   213,   240,   214,
     242,   247,   255,   258,   102,   103,   249,   125,   259,   266,
     281,   315,   264,   265,   273,   102,   103,   278,   293,   290,
     318,   262,   319,   320,     1,     2,     3,   281,   321,   332,
     331,   359,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,   349,   337,   353,   355,
     356,   281,   358,   360,   361,   362,   368,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     315,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,   363,   369,   371,   370,    36,   230,    37,
     234,    38,   231,   177,   232,    39,   233,   269,    40,    41,
     367,   309,   175,   329,   169,   336,   180,   352,    49,   289,
     307,     0,    42,    43,   241,     0,   343,     0,     0,    44,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,     0,     0,     0,     0,     0,    45,    46,    47,     0,
      48,    49,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,    35,     0,     0,
       0,     0,    36,     0,    37,     0,   100,     0,     0,     0,
      39,     0,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     0,    42,    43,     0,
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     0,     0,     0,     0,     0,
       0,    45,   112,    47,     0,    48,    49,    34,    35,     0,
       0,     0,     0,    36,     0,    37,     0,   100,     0,     0,
       0,    39,     0,     0,    40,    41,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    42,    43,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,    45,   112,    47,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,    -5,    -5,     0,     0,     0,
       0,     0,     0,     0,    -5,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,    34,    35,     0,
      -5,     0,     0,    36,    -5,    37,     0,   100,     0,     0,
      -5,    39,     0,     0,    40,    41,     0,     0,     0,    -5,
    -190,     0,     0,  -190,  -190,     0,     0,     0,    42,    43,
       0,     0,     0,     0,     0,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    -5,     0,     0,     0,     0,
       0,     0,    45,   101,    47,     0,     0,     0,     0,     0,
       0,     0,   125,     0,     0,  -190,     0,     0,  -190,  -190,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -175,     0,     0,     0,
       0,     0,     0,     0,   167,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,     0,     0,  -175,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     169,     0,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,   168,     0,     0,     0,     0,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     0,   169,     0,     0,    48,    49,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   167,   308,    34,    35,     0,     0,
       0,     0,    36,     0,    37,     0,   100,   279,     0,     0,
      39,     0,   169,    40,    41,     0,    49,     0,     0,     0,
     168,     0,     0,     0,     0,     0,     0,    42,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     169,     0,     0,    48,    49,     0,     0,     0,     0,     0,
       0,    45,   101,    47,     0,     0,     0,     0,     0,     0,
       0,     0,   280,     0,     0,    48,    49,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     1,     2,     3,     0,     0,     0,     0,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     0,     0,     0,     0,     0,   351,     0,
       0,     0,     0,     0,     0,     0,     0,  -172,     0,     0,
       0,     0,     0,     0,     0,   167,     0,   169,     0,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     3,   169,
       0,     0,    48,    49,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,     0,     0,
       0,   169,     0,     0,    23,    49,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
     167,     0,    36,     0,    37,     0,   100,     0,     0,     0,
      39,     0,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    34,   110,     0,     0,    42,    43,    36,
       0,    37,     0,   100,    44,     0,     0,    39,     0,     0,
      40,    41,     0,   310,     0,     0,   169,     0,     0,     0,
      49,    45,   194,    47,    42,    43,    34,   122,     0,     0,
       0,     0,    36,     0,    37,     0,   100,     0,     0,     0,
      39,     0,     0,    40,    41,    34,    35,     0,    45,   101,
      47,    36,     0,    37,     0,   323,     0,    42,    43,    39,
       0,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    42,    43,    34,    35,
       0,    45,   101,    47,    36,     0,    37,     0,   335,     0,
       0,     0,    39,     0,     0,    40,    41,     0,     0,     0,
      45,   101,    47,     0,     0,     0,     0,     0,     0,    42,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,   101,    47
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const unsigned char yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,    33,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] =
{
       0,   144,     0,   144,     0,   148,     0,   148,     0,   148,
       0,   190,     0,   190,     0,   190,     0,   144,     0,   190,
       0,   190,     0,   190,     0,   190,     0,   190,     0,   144,
       0,   182,     0,   144,     0,   190,     0,   190,     0,   144,
       0,   182,     0
};

static const short int yycheck[] =
{
       0,     0,    32,    28,    28,   128,   116,     0,    35,    34,
     120,    38,   178,   116,   243,    35,   116,    42,    43,     7,
     105,    56,   145,   300,    20,    21,    20,    21,     7,    38,
      38,    56,    20,    21,    47,    38,    38,    73,   246,    72,
     125,    20,    21,   166,    38,    76,   279,    39,    38,   242,
      66,    72,    38,    47,    38,    76,    43,    90,    45,    39,
     110,    77,    93,   296,    66,    67,    68,    69,    98,    72,
      73,    39,   122,    73,    77,    77,    79,    90,    39,   287,
      72,   274,    93,   110,    93,    93,   315,    77,   365,   116,
     110,    77,    72,    77,   121,   122,   116,    40,    41,    93,
      35,    97,   122,    97,    72,    98,    60,    61,   193,    97,
     276,    72,   147,   148,   149,   281,   116,   240,    97,    39,
      39,    38,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     167,    38,    72,   266,    90,    66,   290,   183,    78,   259,
      72,    38,    72,    72,    76,   299,    77,    66,    79,    72,
     190,    96,    97,    76,    99,   288,   310,    76,    77,   340,
     205,   281,    66,   344,   297,   110,   276,   300,   281,    38,
     205,   347,    76,    77,   350,    63,    64,   122,    56,    57,
      58,    59,   185,    47,    48,    49,    37,    38,   133,   322,
      72,    73,    43,   326,    45,    93,    47,    72,    73,    73,
      51,   150,   151,    54,    55,   242,   152,   153,    73,   246,
     158,   159,   242,     0,    94,   255,    51,    68,    69,    50,
     165,    53,    62,    72,    75,    93,   154,   155,   156,   157,
     350,    73,   365,   268,   268,   281,   245,   274,    75,   276,
      90,    92,    93,    94,   274,    75,   276,    73,    73,   259,
     287,    39,   289,   293,    47,   290,   290,    93,    79,    93,
      75,    75,    73,    39,   299,   299,    93,    90,    38,    72,
     279,   281,    39,    39,    75,   310,   310,    39,    73,    79,
      39,    75,    39,    72,     3,     4,     5,   296,    72,    39,
      73,   331,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    39,    93,    93,    78,
      78,   320,    39,    39,    78,    78,    39,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     350,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    78,    78,    39,    78,    43,   160,    45,
     164,    47,   161,    77,   162,    51,   163,   237,    54,    55,
     347,   274,    73,   291,    93,   297,    81,   320,    97,   246,
     270,    -1,    68,    69,   175,    -1,   303,    -1,    -1,    75,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    -1,
      96,    97,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    43,    -1,    45,    -1,    47,    -1,    -1,    -1,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,    68,    69,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    -1,    96,    97,    37,    38,    -1,
      -1,    -1,    -1,    43,    -1,    45,    -1,    47,    -1,    -1,
      -1,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    92,    93,    94,    -1,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    37,    38,    -1,
      73,    -1,    -1,    43,    77,    45,    -1,    47,    -1,    -1,
      38,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,    47,
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
      21,    22,    23,    24,    47,    76,    37,    38,    -1,    -1,
      -1,    -1,    43,    -1,    45,    -1,    47,    38,    -1,    -1,
      51,    -1,    93,    54,    55,    -1,    97,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    -1,    -1,    96,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    96,    97,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    93,    -1,    -1,
      96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    93,
      -1,    -1,    96,    97,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    93,    -1,    -1,    25,    97,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      47,    -1,    43,    -1,    45,    -1,    47,    -1,    -1,    -1,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    -1,    68,    69,    43,
      -1,    45,    -1,    47,    75,    -1,    -1,    51,    -1,    -1,
      54,    55,    -1,    90,    -1,    -1,    93,    -1,    -1,    -1,
      97,    92,    93,    94,    68,    69,    37,    38,    -1,    -1,
      -1,    -1,    43,    -1,    45,    -1,    47,    -1,    -1,    -1,
      51,    -1,    -1,    54,    55,    37,    38,    -1,    92,    93,
      94,    43,    -1,    45,    -1,    47,    -1,    68,    69,    51,
      -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    37,    38,
      -1,    92,    93,    94,    43,    -1,    45,    -1,    47,    -1,
      -1,    -1,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      92,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    43,    45,    47,    51,
      54,    55,    68,    69,    75,    92,    93,    94,    96,    97,
     100,   101,   102,   103,   105,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     123,   125,   126,   127,   130,   131,   133,   134,   141,   144,
     145,   146,   148,   154,   166,   173,   174,   175,   176,   177,
     178,   179,   180,   182,    93,   132,    38,    38,    38,    38,
      47,    93,   107,   120,   124,    90,    73,    73,   177,    93,
      38,   107,    93,   123,   131,   137,   138,   144,   161,   144,
     149,   155,    38,   107,   107,    90,     0,    94,    38,    66,
      67,    68,    69,    77,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,   122,   109,    47,    48,    49,
      43,    45,    40,    41,    56,    57,    58,    59,    60,    61,
      51,    50,    53,    62,    63,    64,    72,    47,    73,    93,
     126,   128,   129,   146,   147,   148,    93,   132,    38,    93,
     152,   153,   125,   127,   181,   183,    73,    75,   123,   123,
     125,   177,   123,    90,    93,   173,    73,    73,   161,    39,
     137,   146,   154,   158,   162,    39,   154,   144,   161,   173,
     104,   106,   121,    93,    93,   123,   121,   109,   109,   109,
     110,   110,   111,   111,   112,   112,   112,   112,   113,   113,
     114,   115,   116,   117,   118,   123,   121,    72,    73,   152,
      79,   181,    75,   146,   147,    38,    77,    75,   125,    93,
     142,   143,    39,    39,   177,    73,    39,   173,    39,    38,
     163,   165,    75,   109,    39,    39,    72,    78,    90,   129,
      75,   121,   167,    75,   135,   136,   138,   153,    39,    38,
      93,   127,   151,   156,   157,   159,   160,     7,   149,   155,
      79,    72,    76,    73,   177,   162,    38,    77,    66,    77,
     168,   169,   170,   171,   172,   121,   120,   169,    76,   136,
      90,   139,   140,   147,   156,   146,   147,   162,    39,    39,
      72,    72,   149,    47,   121,   150,     7,   124,    76,   143,
     177,    73,    39,   156,   164,    47,   150,    93,   124,   167,
      72,    76,    79,   172,    72,    76,   124,    72,    73,    39,
      38,    74,   159,    93,   121,    78,    78,   121,    39,   177,
      39,    78,    78,    78,    76,   168,    76,   140,    39,    78,
      78,    39,   167
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
   while (0)

#if YYDEBUG

#if ! defined (YYFPRINTF)
#  define YYFPRINTF fprintf
#endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

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
   properly redirected to new data. */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
# if (! defined (__cplusplus) \
      || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL))
#  define YYSTACKEXPANDABLE 1
# else
#  define YYSTACKEXPANDABLE 0
# endif
#endif

#if YYERROR_VERBOSE

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
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
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;
typedef struct yyGLRStateSet yyGLRStateSet;

struct yyGLRState {
  /** Type tag: always true. */
  yybool yyisState;
  /** Type tag for yysemantics. If true, yysval applies, otherwise
   *  yyfirstVal applies. */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state. */
  yyStateNum yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the first token produced by my symbol */
  size_t yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  non-terminal corresponding to this state, threaded through
     *  yynext. */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state. */
    YYSTYPE yysval;
  } yysemantics;
  /** Source location for this state. */
  YYLTYPE yyloc;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  size_t yysize, yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false. */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced. */
  yyGLRState* yystate;
  /** Next sibling in chain of options. To facilitate merging,
   *  options are chained in decreasing order by address. */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack. The yyisState field
 *  indicates which item of the union is valid. */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  yySymbol* yytokenp;
  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  size_t yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

static void yyexpandGLRStack (yyGLRStack* yystack);

static void yyFail (yyGLRStack* yystack, const char* yymsg)
  __attribute__ ((__noreturn__));
static void
yyFail (yyGLRStack* yystack, const char* yymsg)
{
  if (yymsg != NULL)
    yyerror (yymsg);
  YYLONGJMP (yystack->yyexception_buffer, 1);
}

static void yyMemoryExhausted (yyGLRStack* yystack)
  __attribute__ ((__noreturn__));
static void
yyMemoryExhausted (yyGLRStack* yystack)
{
  YYLONGJMP (yystack->yyexception_buffer, 2);
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
 *  containing the pointer to the next state in the chain. Assumes
 *  YYLOW1 < YYLOW0.  */
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
   YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
   For convenience, always return YYLOW1.  */
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
 *  (@$). Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT. */
static YYRESULTTAG
yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
	      YYSTYPE* yyvalp,
	      YYLTYPE* YYOPTIONAL_LOC (yylocp),
	      yyGLRStack* yystack
              )
{
  yybool yynormal __attribute__ ((__unused__)) =
    (yystack->yysplitPoint == NULL);
  int yylow;

# undef yyerrok
# define yyerrok (yystack->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING (yystack->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = *(yystack->yytokenp) = YYEMPTY)
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
  YYLLOC_DEFAULT (*yylocp, yyvsp - yyrhslen, yyrhslen);

  switch (yyn)
    {
        case 2:
#line 293 "cbook.y"
    {
	;}
    break;

  case 3:
#line 310 "cbook.y"
    {
#if STMT_DEBUG
              printf("declaration\n");
#endif
              seen_term_tok=TRUE;
	      cnt_rule(yyn);
              ;}
    break;

  case 4:
#line 318 "cbook.y"
    {
#if STMT_DEBUG
              printf("statement\n");
#endif
	      seen_term_tok=TRUE;
	      cnt_rule(yyn);
              ;}
    break;

  case 5:
#line 331 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 6:
#line 335 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 7:
#line 339 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 8:
#line 343 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 9:
#line 352 "cbook.y"
    {
            cnt_rule(yyn);
            ;}
    break;

  case 10:
#line 356 "cbook.y"
    {
            cnt_rule(yyn);
            ;}
    break;

  case 11:
#line 361 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 12:
#line 365 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 13:
#line 371 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 14:
#line 375 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 15:
#line 379 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 16:
#line 383 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 17:
#line 387 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 18:
#line 391 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 19:
#line 395 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 20:
#line 399 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 21:
#line 403 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 22:
#line 410 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 23:
#line 414 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 24:
#line 421 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 25:
#line 425 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 26:
#line 429 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 27:
#line 433 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 28:
#line 441 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 29:
#line 445 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 30:
#line 452 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 31:
#line 456 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 32:
#line 460 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 33:
#line 464 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 34:
#line 468 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 35:
#line 472 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 36:
#line 487 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 37:
#line 491 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 38:
#line 506 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 39:
#line 510 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 40:
#line 514 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 41:
#line 518 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 42:
#line 554 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 43:
#line 558 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 44:
#line 562 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 45:
#line 606 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 46:
#line 610 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 47:
#line 614 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 48:
#line 621 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 49:
#line 625 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 50:
#line 629 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 51:
#line 633 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 52:
#line 637 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 53:
#line 644 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 54:
#line 648 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 55:
#line 652 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 56:
#line 667 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 57:
#line 671 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 58:
#line 689 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 59:
#line 693 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 60:
#line 700 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 61:
#line 704 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 62:
#line 711 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 63:
#line 715 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 64:
#line 722 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 65:
#line 726 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 66:
#line 733 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 67:
#line 737 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 68:
#line 744 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 69:
#line 748 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 70:
#line 755 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 71:
#line 759 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 72:
#line 763 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 73:
#line 767 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 74:
#line 771 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 75:
#line 775 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 76:
#line 779 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 77:
#line 783 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 78:
#line 787 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 79:
#line 791 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 80:
#line 795 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 81:
#line 802 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 82:
#line 806 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 84:
#line 841 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 85:
#line 845 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 86:
#line 855 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 87:
#line 859 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 88:
#line 863 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 89:
#line 867 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 90:
#line 873 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 91:
#line 877 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 92:
#line 884 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 93:
#line 888 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 94:
#line 895 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 95:
#line 899 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 96:
#line 906 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 97:
#line 910 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 98:
#line 914 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 99:
#line 918 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 100:
#line 922 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 101:
#line 929 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 102:
#line 933 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 103:
#line 937 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 104:
#line 941 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 105:
#line 945 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 106:
#line 949 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 107:
#line 953 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 108:
#line 957 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 109:
#line 961 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 110:
#line 965 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 111:
#line 969 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 112:
#line 973 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 113:
#line 977 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 114:
#line 981 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 115:
#line 985 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 116:
#line 990 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 117:
#line 994 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 118:
#line 1001 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 119:
#line 1005 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 120:
#line 1012 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 121:
#line 1016 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 122:
#line 1023 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 123:
#line 1027 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 125:
#line 1041 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 126:
#line 1045 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 127:
#line 1051 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 128:
#line 1055 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 129:
#line 1062 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 130:
#line 1066 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 131:
#line 1084 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 132:
#line 1088 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 133:
#line 1110 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 134:
#line 1114 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 135:
#line 1118 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 136:
#line 1125 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 137:
#line 1129 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 138:
#line 1136 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 139:
#line 1140 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 140:
#line 1147 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 141:
#line 1151 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 142:
#line 1155 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 143:
#line 1162 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 144:
#line 1167 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 145:
#line 1171 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 146:
#line 1177 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 147:
#line 1183 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 148:
#line 1188 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 149:
#line 1192 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 150:
#line 1196 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 151:
#line 1200 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 152:
#line 1204 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 153:
#line 1208 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 154:
#line 1224 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 155:
#line 1228 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 156:
#line 1232 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 157:
#line 1236 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 158:
#line 1240 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 159:
#line 1244 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 160:
#line 1248 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 161:
#line 1254 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 162:
#line 1272 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 163:
#line 1276 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 164:
#line 1283 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 165:
#line 1287 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 166:
#line 1294 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 167:
#line 1298 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 168:
#line 1305 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 169:
#line 1309 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 170:
#line 1316 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 171:
#line 1320 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 172:
#line 1325 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 173:
#line 1329 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 174:
#line 1352 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 175:
#line 1356 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 176:
#line 1360 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 177:
#line 1367 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 178:
#line 1371 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 179:
#line 1378 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 180:
#line 1385 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 181:
#line 1389 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 182:
#line 1394 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 183:
#line 1398 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 184:
#line 1402 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 185:
#line 1406 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 186:
#line 1412 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 187:
#line 1416 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 188:
#line 1420 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 189:
#line 1424 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 190:
#line 1434 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 191:
#line 1441 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 192:
#line 1445 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 193:
#line 1449 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 194:
#line 1454 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 195:
#line 1458 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 196:
#line 1464 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 197:
#line 1468 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 198:
#line 1475 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 199:
#line 1482 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 200:
#line 1486 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 201:
#line 1493 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 202:
#line 1497 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 203:
#line 1509 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 204:
#line 1513 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 205:
#line 1517 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 206:
#line 1521 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 207:
#line 1528 "cbook.y"
    {
	      printf("OC\n");
              cnt_rule(yyn);
              ;}
    break;

  case 208:
#line 1533 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 209:
#line 1540 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 210:
#line 1544 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 211:
#line 1548 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 212:
#line 1573 "cbook.y"
    {
              printf("ES\n");
	      cnt_rule(yyn);
              ;}
    break;

  case 213:
#line 1587 "cbook.y"
    {
              printf("IF\n");
	      cnt_rule(yyn);
              ;}
    break;

  case 214:
#line 1592 "cbook.y"
    {
              printf("SW\n");
              cnt_rule(yyn);
              ;}
    break;

  case 215:
#line 1598 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 216:
#line 1602 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 217:
#line 1615 "cbook.y"
    {
              printf("WH\n");
              cnt_rule(yyn);
              ;}
    break;

  case 218:
#line 1620 "cbook.y"
    {
              printf("DO\n");
              cnt_rule(yyn);
              ;}
    break;

  case 219:
#line 1633 "cbook.y"
    {
              printf("FO\n");
              cnt_rule(yyn);
              ;}
    break;

  case 220:
#line 1638 "cbook.y"
    {
              printf("FO\n");
              cnt_rule(yyn);
              ;}
    break;

  case 221:
#line 1646 "cbook.y"
    {
              printf("GO\n");
              cnt_rule(yyn);
              ;}
    break;

  case 222:
#line 1651 "cbook.y"
    {
              printf("CO\n");
              cnt_rule(yyn);
              ;}
    break;

  case 223:
#line 1656 "cbook.y"
    {
              printf("BR\n");
              cnt_rule(yyn);
              ;}
    break;

  case 224:
#line 1661 "cbook.y"
    {
              printf("RE\n");
              cnt_rule(yyn);
              ;}
    break;

  case 225:
#line 1671 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 226:
#line 1675 "cbook.y"
    {
              printf("DC\n");
              cnt_rule(yyn);
              ;}
    break;

  case 227:
#line 1681 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 228:
#line 1685 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 229:
#line 1695 "cbook.y"
    {
	      printf("FD\n");
              cnt_rule(yyn);
              ;}
    break;

  case 230:
#line 1703 "cbook.y"
    {
	      printf("FD\n");
              cnt_rule(yyn);
              ;}
    break;

  case 231:
#line 1711 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;

  case 232:
#line 1715 "cbook.y"
    {
              cnt_rule(yyn);
              ;}
    break;


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
/* Line 872 of glr.c.  */
#line 3346 "cbook.tab.c"
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  /* `Use' the arguments.  */
  (void) yy0;
  (void) yy1;

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

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
	  YYFPRINTF (stderr, "%s unresolved ", yymsg);
	  yysymprint (stderr, yystos[yys->yylrState],
		      &yys->yysemantics.yysval);
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

/** Left-hand-side symbol for rule #RULE. */
static inline yySymbol
yylhsNonterm (yyRuleNum yyrule)
{
  return yyr1[yyrule];
}

#define yyis_pact_ninf(yystate) \
  ((yystate) == YYPACT_NINF)

/** True iff LR state STATE has only a default reduction (regardless
 *  of token). */
static inline yybool
yyisDefaultedState (yyStateNum yystate)
{
  return yyis_pact_ninf (yypact[yystate]);
}

/** The default reduction for STATE, assuming it has one. */
static inline yyRuleNum
yydefaultAction (yyStateNum yystate)
{
  return yydefact[yystate];
}

#define yyis_table_ninf(yytable_value) \
  0

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

static void
yyaddDeferredAction (yyGLRStack* yystack, yyGLRState* yystate,
		     yyGLRState* rhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewItem;
  yynewItem = &yystack->yynextFree->yyoption;
  yystack->yyspaceLeft -= 1;
  yystack->yynextFree += 1;
  yynewItem->yyisState = yyfalse;
  yynewItem->yystate = rhs;
  yynewItem->yyrule = yyrule;
  yynewItem->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewItem;
  if (yystack->yyspaceLeft < YYHEADROOM)
    yyexpandGLRStack (yystack);
}

				/* GLRStacks */

/** Initialize SET to a singleton set containing an empty stack. */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates = (yyGLRState**) YYMALLOC (16 * sizeof yyset->yystates[0]);
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = NULL;
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
}

/** Initialize STACK to a single empty stack, with total maximum
 *  capacity for all stacks of SIZE. */
static yybool
yyinitGLRStack (yyGLRStack* yystack, size_t yysize)
{
  yystack->yyerrState = 0;
  yynerrs = 0;
  yystack->yyspaceLeft = yysize;
  yystack->yyitems =
    (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystack->yynextFree[0]);
  if (!yystack->yyitems)
    return yyfalse;
  yystack->yynextFree = yystack->yyitems;
  yystack->yysplitPoint = NULL;
  yystack->yylastDeleted = NULL;
  return yyinitStateSet (&yystack->yytops);
}

#define YYRELOC(YYFROMITEMS,YYTOITEMS,YYX,YYTYPE) \
  &((YYTOITEMS) - ((YYFROMITEMS) - (yyGLRStackItem*) (YYX)))->YYTYPE

/** If STACK is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation. */
static void
yyexpandGLRStack (yyGLRStack* yystack)
{
#if YYSTACKEXPANDABLE
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  size_t yysize, yynewSize;
  size_t yyn;
  yysize = yystack->yynextFree - yystack->yyitems;
  if (YYMAXDEPTH <= yysize)
    yyMemoryExhausted (yystack);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems = (yyGLRStackItem*) YYMALLOC (yynewSize * sizeof yynewItems[0]);
  if (! yynewItems)
    yyMemoryExhausted (yystack);
  for (yyp0 = yystack->yyitems, yyp1 = yynewItems, yyn = yysize;
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
  if (yystack->yysplitPoint != NULL)
    yystack->yysplitPoint = YYRELOC (yystack->yyitems, yynewItems,
				 yystack->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystack->yytops.yysize; yyn += 1)
    if (yystack->yytops.yystates[yyn] != NULL)
      yystack->yytops.yystates[yyn] =
	YYRELOC (yystack->yyitems, yynewItems,
		 yystack->yytops.yystates[yyn], yystate);
  YYFREE (yystack->yyitems);
  yystack->yyitems = yynewItems;
  yystack->yynextFree = yynewItems + yysize;
  yystack->yyspaceLeft = yynewSize - yysize;

#else
  yyMemoryExhausted (yystack);
#endif
}

static void
yyfreeGLRStack (yyGLRStack* yystack)
{
  YYFREE (yystack->yyitems);
  yyfreeStateSet (&yystack->yytops);
}

/** Assuming that S is a GLRState somewhere on STACK, update the
 *  splitpoint of STACK, if needed, so that it is at least as deep as
 *  S. */
static inline void
yyupdateSplit (yyGLRStack* yystack, yyGLRState* yys)
{
  if (yystack->yysplitPoint != NULL && yystack->yysplitPoint > yys)
    yystack->yysplitPoint = yys;
}

/** Invalidate stack #K in STACK. */
static inline void
yymarkStackDeleted (yyGLRStack* yystack, size_t yyk)
{
  if (yystack->yytops.yystates[yyk] != NULL)
    yystack->yylastDeleted = yystack->yytops.yystates[yyk];
  yystack->yytops.yystates[yyk] = NULL;
}

/** Undelete the last stack that was marked as deleted.  Can only be
    done once after a deletion, and only when all other stacks have
    been deleted. */
static void
yyundeleteLastStack (yyGLRStack* yystack)
{
  if (yystack->yylastDeleted == NULL || yystack->yytops.yysize != 0)
    return;
  yystack->yytops.yystates[0] = yystack->yylastDeleted;
  yystack->yytops.yysize = 1;
  YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystack->yylastDeleted = NULL;
}

static inline void
yyremoveDeletes (yyGLRStack* yystack)
{
  size_t yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystack->yytops.yysize)
    {
      if (yystack->yytops.yystates[yyi] == NULL)
	{
	  if (yyi == yyj)
	    {
	      YYDPRINTF ((stderr, "Removing dead stacks.\n"));
	    }
	  yystack->yytops.yysize -= 1;
	}
      else
	{
	  yystack->yytops.yystates[yyj] = yystack->yytops.yystates[yyi];
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
 * LRSTATE, at input position POSN, with (resolved) semantic value SVAL. */
static inline void
yyglrShift (yyGLRStack* yystack, size_t yyk, yyStateNum yylrState,
	    size_t yyposn,
	    YYSTYPE yysval, YYLTYPE* yylocp)
{
  yyGLRStackItem* yynewItem;

  yynewItem = yystack->yynextFree;
  yystack->yynextFree += 1;
  yystack->yyspaceLeft -= 1;
  yynewItem->yystate.yyisState = yytrue;
  yynewItem->yystate.yylrState = yylrState;
  yynewItem->yystate.yyposn = yyposn;
  yynewItem->yystate.yyresolved = yytrue;
  yynewItem->yystate.yypred = yystack->yytops.yystates[yyk];
  yystack->yytops.yystates[yyk] = &yynewItem->yystate;
  yynewItem->yystate.yysemantics.yysval = yysval;
  yynewItem->yystate.yyloc = *yylocp;
  if (yystack->yyspaceLeft < YYHEADROOM)
    yyexpandGLRStack (yystack);
}

/** Shift stack #K of YYSTACK, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE. */
static inline void
yyglrShiftDefer (yyGLRStack* yystack, size_t yyk, yyStateNum yylrState,
		 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule)
{
  yyGLRStackItem* yynewItem;

  yynewItem = yystack->yynextFree;
  yynewItem->yystate.yyisState = yytrue;
  yynewItem->yystate.yylrState = yylrState;
  yynewItem->yystate.yyposn = yyposn;
  yynewItem->yystate.yyresolved = yyfalse;
  yynewItem->yystate.yypred = yystack->yytops.yystates[yyk];
  yynewItem->yystate.yysemantics.yyfirstVal = NULL;
  yystack->yytops.yystates[yyk] = &yynewItem->yystate;
  yystack->yynextFree += 1;
  yystack->yyspaceLeft -= 1;
  yyaddDeferredAction (yystack, &yynewItem->yystate, rhs, yyrule);
}

/** Pop the symbols consumed by reduction #RULE from the top of stack
 *  #K of STACK, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved. Set *VALP to the resulting value,
 *  and *LOCP to the computed location (if any).  Return value is as
 *  for userAction. */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
	    YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystack->yysplitPoint == NULL)
    {
      /* Standard special case: single stack. */
      yyGLRStackItem* rhs = (yyGLRStackItem*) yystack->yytops.yystates[yyk];
      YYASSERT (yyk == 0);
      yystack->yynextFree -= yynrhs;
      yystack->yyspaceLeft += yynrhs;
      yystack->yytops.yystates[0] = & yystack->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, rhs,
			   yyvalp, yylocp, yystack);
    }
  else
    {
      int yyi;
      yyGLRState* yys;
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
	= yystack->yytops.yystates[yyk];
      for (yyi = 0; yyi < yynrhs; yyi += 1)
	{
	  yys = yys->yypred;
	  YYASSERT (yys);
	}
      yyupdateSplit (yystack, yys);
      yystack->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
			   yyvalp, yylocp, yystack);
    }
}

#if !YYDEBUG
# define YY_REDUCE_PRINT(K, Rule)
#else
# define YY_REDUCE_PRINT(K, Rule)	\
do {					\
  if (yydebug)				\
    yy_reduce_print (K, Rule);		\
} while (0)

/*----------------------------------------------------------.
| Report that the RULE is going to be reduced on stack #K.  |
`----------------------------------------------------------*/

static inline void
yy_reduce_print (size_t yyk, yyRuleNum yyrule)
{
  int yyi;
  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu), ",
	     (unsigned long int) yyk, yyrule - 1,
	     (unsigned long int) yyrline[yyrule]);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytokenName (yyrhs[yyi]));
  YYFPRINTF (stderr, "-> %s\n", yytokenName (yyr1[yyrule]));
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
 *  the STACK. In this case, the (necessarily deferred) semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
             yybool yyforceEval)
{
  size_t yyposn = yystack->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystack->yysplitPoint == NULL)
    {
      YYSTYPE yysval;
      YYLTYPE yyloc;

      YY_REDUCE_PRINT (yyk, yyrule);
      YYCHK (yydoAction (yystack, yyk, yyrule, &yysval, &yyloc));
      yyglrShift (yystack, yyk,
		  yyLRgotoState (yystack->yytops.yystates[yyk]->yylrState,
				 yylhsNonterm (yyrule)),
		  yyposn, yysval, &yyloc);
    }
  else
    {
      size_t yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystack->yytops.yystates[yyk];
      yyStateNum yynewLRState;

      for (yys = yystack->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
	   0 < yyn; yyn -= 1)
	{
	  yys = yys->yypred;
	  YYASSERT (yys);
	}
      yyupdateSplit (yystack, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YYDPRINTF ((stderr,
		  "Reduced stack %lu by rule #%d; action deferred. Now in state %d.\n",
		  (unsigned long int) yyk, yyrule - 1, yynewLRState));
      for (yyi = 0; yyi < yystack->yytops.yysize; yyi += 1)
	if (yyi != yyk && yystack->yytops.yystates[yyi] != NULL)
	  {
	    yyGLRState* yyp, *yysplit = yystack->yysplitPoint;
	    yyp = yystack->yytops.yystates[yyi];
	    while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
	      {
		if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
		  {
		    yyaddDeferredAction (yystack, yyp, yys0, yyrule);
		    yymarkStackDeleted (yystack, yyk);
		    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
				(unsigned long int) yyk,
				(unsigned long int) yyi));
		    return yyok;
		  }
		yyp = yyp->yypred;
	      }
	  }
      yystack->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystack, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static size_t
yysplitStack (yyGLRStack* yystack, size_t yyk)
{
  if (yystack->yysplitPoint == NULL)
    {
      YYASSERT (yyk == 0);
      yystack->yysplitPoint = yystack->yytops.yystates[yyk];
    }
  if (yystack->yytops.yysize >= yystack->yytops.yycapacity)
    {
      yyGLRState** yynewStates;
      if (! ((yystack->yytops.yycapacity
	      <= (YYSIZEMAX / (2 * sizeof yynewStates[0])))
	     && (yynewStates =
		 (yyGLRState**) YYREALLOC (yystack->yytops.yystates,
					   ((yystack->yytops.yycapacity *= 2)
					    * sizeof yynewStates[0])))))
	yyMemoryExhausted (yystack);
      yystack->yytops.yystates = yynewStates;
    }
  yystack->yytops.yystates[yystack->yytops.yysize]
    = yystack->yytops.yystates[yyk];
  yystack->yytops.yysize += 1;
  return yystack->yytops.yysize-1;
}

/** True iff Y0 and Y1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols. */
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
 *  alternative semantic values for the RHS-symbols of Y1 and Y0. */
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
	  while (yytrue)
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
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred. */
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

static YYRESULTTAG yyresolveValue (yySemanticOption* yyoptionList,
				   yyGLRStack* yystack, YYSTYPE* yyvalp,
				   YYLTYPE* yylocp);

static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn, yyGLRStack* yystack)
{
  YYRESULTTAG yyflag;
  if (0 < yyn)
    {
      YYASSERT (yys->yypred);
      yyflag = yyresolveStates (yys->yypred, yyn-1, yystack);
      if (yyflag != yyok)
	return yyflag;
      if (! yys->yyresolved)
	{
	  yyflag = yyresolveValue (yys->yysemantics.yyfirstVal, yystack,
				   &yys->yysemantics.yysval, &yys->yyloc
				  );
	  if (yyflag != yyok)
	    return yyflag;
	  yys->yyresolved = yytrue;
	}
    }
  return yyok;
}

static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack,
	         YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs;

  yynrhs = yyrhsLength (yyopt->yyrule);
  YYCHK (yyresolveStates (yyopt->yystate, yynrhs, yystack));
  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  return yyuserAction (yyopt->yyrule, yynrhs,
		       yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
		       yyvalp, yylocp, yystack);
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[YYMAXRHS];
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
	       yyx->yyrule);
  else
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %lu .. %lu>\n",
	       yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
	       yyx->yyrule, (unsigned long int) (yys->yyposn + 1),
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

static void yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
			       yyGLRStack* yystack)
  __attribute__ ((__noreturn__));
static void
yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
		   yyGLRStack* yystack)
{
  /* `Unused' warnings.  */
  (void) yyx0;
  (void) yyx1;

#if YYDEBUG
  YYFPRINTF (stderr, "Ambiguity detected.\n");
  YYFPRINTF (stderr, "Option 1,\n");
  yyreportTree (yyx0, 2);
  YYFPRINTF (stderr, "\nOption 2,\n");
  yyreportTree (yyx1, 2);
  YYFPRINTF (stderr, "\n");
#endif
  yyFail (yystack, YY_("syntax is ambiguous"));
}


/** Resolve the ambiguity represented by OPTIONLIST, perform the indicated
 *  actions, and return the result. */
static YYRESULTTAG
yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
		YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yySemanticOption* yybest;
  yySemanticOption** yypp;
  yybool yymerge;

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
	      yyreportAmbiguity (yybest, yyp, yystack);
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
      YYCHK (yyresolveAction (yybest, yystack, yyvalp, yylocp));
      for (yyp = yybest->yynext; yyp != NULL; yyp = yyp->yynext)
	{
	  if (yyprec == yydprec[yyp->yyrule])
	    {
	      YYSTYPE yyval1;
	      YYLTYPE yydummy;
	      YYCHK (yyresolveAction (yyp, yystack, &yyval1, &yydummy));
	      yyuserMerge (yymerger[yyp->yyrule], yyvalp, &yyval1);
	    }
	}
      return yyok;
    }
  else
    return yyresolveAction (yybest, yystack, yyvalp, yylocp);
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystack)
{
  if (yystack->yysplitPoint != NULL)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystack->yytops.yystates[0];
	   yys != yystack->yysplitPoint;
	   yys = yys->yypred, yyn += 1)
	continue;
      YYCHK (yyresolveStates (yystack->yytops.yystates[0], yyn, yystack
			     ));
    }
  return yyok;
}

static void
yycompressStack (yyGLRStack* yystack)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystack->yytops.yysize != 1 || yystack->yysplitPoint == NULL)
    return;

  for (yyp = yystack->yytops.yystates[0], yyq = yyp->yypred, yyr = NULL;
       yyp != yystack->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystack->yyspaceLeft += yystack->yynextFree - yystack->yyitems;
  yystack->yynextFree = ((yyGLRStackItem*) yystack->yysplitPoint) + 1;
  yystack->yyspaceLeft -= yystack->yynextFree - yystack->yyitems;
  yystack->yysplitPoint = NULL;
  yystack->yylastDeleted = NULL;

  while (yyr != NULL)
    {
      yystack->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystack->yynextFree->yystate.yypred = & yystack->yynextFree[-1].yystate;
      yystack->yytops.yystates[0] = &yystack->yynextFree->yystate;
      yystack->yynextFree += 1;
      yystack->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystack, size_t yyk,
	           size_t yyposn, YYSTYPE* yylvalp, YYLTYPE* yyllocp
		  )
{
  int yyaction;
  const short int* yyconflicts;
  yyRuleNum yyrule;
  yySymbol* const yytokenp = yystack->yytokenp;

  while (yystack->yytops.yystates[yyk] != NULL)
    {
      yyStateNum yystate = yystack->yytops.yystates[yyk]->yylrState;
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
	      yymarkStackDeleted (yystack, yyk);
	      return yyok;
	    }
	  YYCHK (yyglrReduce (yystack, yyk, yyrule, yyfalse));
	}
      else
	{
	  if (*yytokenp == YYEMPTY)
	    {
	      YYDPRINTF ((stderr, "Reading a token: "));
	      yychar = YYLEX;
	      *yytokenp = YYTRANSLATE (yychar);
	      YY_SYMBOL_PRINT ("Next token is", *yytokenp, yylvalp, yyllocp);
	    }
	  yygetLRActions (yystate, *yytokenp, &yyaction, &yyconflicts);

	  while (*yyconflicts != 0)
	    {
	      size_t yynewStack = yysplitStack (yystack, yyk);
	      YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
			  (unsigned long int) yynewStack,
			  (unsigned long int) yyk));
	      YYCHK (yyglrReduce (yystack, yynewStack,
				  *yyconflicts, yyfalse));
	      YYCHK (yyprocessOneStack (yystack, yynewStack, yyposn,
					yylvalp, yyllocp));
	      yyconflicts += 1;
	    }

	  if (yyisShiftAction (yyaction))
	    {
	      YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yyk));
	      YY_SYMBOL_PRINT ("shifting", *yytokenp, yylvalp, yyllocp);
	      yyglrShift (yystack, yyk, yyaction, yyposn+1,
			  *yylvalp, yyllocp);
	      YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
			  (unsigned long int) yyk,
			  yystack->yytops.yystates[yyk]->yylrState));
	      break;
	    }
	  else if (yyisErrorAction (yyaction))
	    {
	      YYDPRINTF ((stderr, "Stack %lu dies.\n",
			  (unsigned long int) yyk));
	      yymarkStackDeleted (yystack, yyk);
	      break;
	    }
	  else
	    YYCHK (yyglrReduce (yystack, yyk, -yyaction, yyfalse));
	}
    }
  return yyok;
}

static void
yyreportSyntaxError (yyGLRStack* yystack,
		     YYSTYPE* yylvalp, YYLTYPE* yyllocp)
{
  /* `Unused' warnings. */
  (void) yylvalp;
  (void) yyllocp;

  if (yystack->yyerrState == 0)
    {
#if YYERROR_VERBOSE
      yySymbol* const yytokenp = yystack->yytokenp;
      int yyn;
      yyn = yypact[yystack->yytops.yystates[0]->yylrState];
      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  size_t yysize0 = yytnamerr (NULL, yytokenName (*yytokenp));
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
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytokenName (*yytokenp);
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
	      yyMemoryExhausted (yystack);
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
      yynerrs += 1;
    }
}

/* Recover from a syntax error on YYSTACK, assuming that YYTOKENP,
   YYLVALP, and YYLLOCP point to the syntactic category, semantic
   value, and location of the look-ahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystack,
		      YYSTYPE* yylvalp,
		      YYLTYPE* YYOPTIONAL_LOC (yyllocp)
		      )
{
  yySymbol* const yytokenp = yystack->yytokenp;
  size_t yyk;
  int yyj;

  if (yystack->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
	if (*yytokenp == YYEOF)
	  yyFail (yystack, NULL);
	if (*yytokenp != YYEMPTY)
	  {
	    yydestruct ("Error: discarding",
			*yytokenp, yylvalp);
	  }
	YYDPRINTF ((stderr, "Reading a token: "));
	yychar = YYLEX;
	*yytokenp = YYTRANSLATE (yychar);
	YY_SYMBOL_PRINT ("Next token is", *yytokenp, yylvalp, yyllocp);
	yyj = yypact[yystack->yytops.yystates[0]->yylrState];
	if (yyis_pact_ninf (yyj))
	  return;
	yyj += *yytokenp;
	if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != *yytokenp)
	  {
	    if (yydefact[yystack->yytops.yystates[0]->yylrState] != 0)
	      return;
	  }
	else if (yytable[yyj] != 0 && ! yyis_table_ninf (yytable[yyj]))
	  return;
      }

  /* Reduce to one stack.  */
  for (yyk = 0; yyk < yystack->yytops.yysize; yyk += 1)
    if (yystack->yytops.yystates[yyk] != NULL)
      break;
  if (yyk >= yystack->yytops.yysize)
    yyFail (yystack, NULL);
  for (yyk += 1; yyk < yystack->yytops.yysize; yyk += 1)
    yymarkStackDeleted (yystack, yyk);
  yyremoveDeletes (yystack);
  yycompressStack (yystack);

  /* Now pop stack until we find a state that shifts the error token. */
  yystack->yyerrState = 3;
  while (yystack->yytops.yystates[0] != NULL)
    {
      yyGLRState *yys = yystack->yytops.yystates[0];
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
			       yylvalp, &yyerrloc);
	      yyglrShift (yystack, 0, yytable[yyj],
			  yys->yyposn, *yylvalp, &yyerrloc);
	      yys = yystack->yytops.yystates[0];
	      break;
	    }
	}

      yydestroyGLRState ("Error: popping", yys);
      yystack->yytops.yystates[0] = yys->yypred;
      yystack->yynextFree -= 1;
      yystack->yyspaceLeft += 1;
    }
  if (yystack->yytops.yystates[0] == NULL)
    yyFail (yystack, NULL);
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
  } while (0)


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yySymbol yytoken;
  yyGLRStack yystack;
  size_t yyposn;


  YYSTYPE* const yylvalp = &yylval;
  YYLTYPE* const yyllocp = &yylloc;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yytoken = YYEMPTY;
  yylval = yyval_default;


  if (! yyinitGLRStack (&yystack, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yystack.yytokenp = &yytoken;
  yyglrShift (&yystack, 0, 0, 0, yylval, &yylloc);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
	 specialized to deterministic operation (single stack, no
	 potential ambiguity).  */
      /* Standard mode */
      while (yytrue)
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

		  yyreportSyntaxError (&yystack, yylvalp, yyllocp);
		  goto yyuser_error;
		}
	      YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
	    }
	  else
	    {
	      if (yytoken == YYEMPTY)
		{
		  YYDPRINTF ((stderr, "Reading a token: "));
		  yychar = YYLEX;
		  yytoken = YYTRANSLATE (yychar);
                  YY_SYMBOL_PRINT ("Next token is", yytoken, yylvalp, yyllocp);
		}
	      yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
	      if (*yyconflicts != 0)
		break;
	      if (yyisShiftAction (yyaction))
		{
		  YY_SYMBOL_PRINT ("Shifting", yytoken, yylvalp, yyllocp);
		  if (yytoken != YYEOF)
		    yytoken = YYEMPTY;
		  yyposn += 1;
		  yyglrShift (&yystack, 0, yyaction, yyposn, yylval, yyllocp);
		  if (0 < yystack.yyerrState)
		    yystack.yyerrState -= 1;
		}
	      else if (yyisErrorAction (yyaction))
		{

		  yyreportSyntaxError (&yystack, yylvalp, yyllocp);
		  goto yyuser_error;
		}
	      else
		YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
	    }
	}

      while (yytrue)
	{
	  size_t yys;
	  size_t yyn = yystack.yytops.yysize;
	  for (yys = 0; yys < yyn; yys += 1)
	    YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn,
				       yylvalp, yyllocp));
	  yytoken = YYEMPTY;
	  yyposn += 1;
	  yyremoveDeletes (&yystack);
	  if (yystack.yytops.yysize == 0)
	    {
	      yyundeleteLastStack (&yystack);
	      if (yystack.yytops.yysize == 0)
		yyFail (&yystack, YY_("syntax error"));
	      YYCHK1 (yyresolveStack (&yystack));
	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));

	      yyreportSyntaxError (&yystack, yylvalp, yyllocp);
	      goto yyuser_error;
	    }
	  else if (yystack.yytops.yysize == 1)
	    {
	      YYCHK1 (yyresolveStack (&yystack));
	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
	      yycompressStack (&yystack);
	      break;
	    }
	}
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack, yylvalp, yyllocp);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturn;

 yybuglab:
  YYASSERT (yyfalse);
  /* Fall through.  */

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */

 yyreturn:
  if (yytoken != YYEOF && yytoken != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                yytoken, yylvalp);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
	while (yystates[0])
	  {
	    yyGLRState *yys = yystates[0];
	    yydestroyGLRState ("Cleanup: popping", yys);
	    yystates[0] = yys->yypred;
	    yystack.yynextFree -= 1;
	    yystack.yyspaceLeft += 1;
	  }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#ifdef YYDEBUG
static void yypstack (yyGLRStack* yystack, size_t yyk)
  __attribute__ ((__unused__));
static void yypdumpstack (yyGLRStack* yystack) __attribute__ ((__unused__));

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
yypstack (yyGLRStack* yystack, size_t yyk)
{
  yypstates (yystack->yytops.yystates[yyk]);
}

#define YYINDEX(YYX)							     \
    ((YYX) == NULL ? -1 : (yyGLRStackItem*) (YYX) - yystack->yyitems)


static void
yypdumpstack (yyGLRStack* yystack)
{
  yyGLRStackItem* yyp;
  size_t yyi;
  for (yyp = yystack->yyitems; yyp < yystack->yynextFree; yyp += 1)
    {
      fprintf (stderr, "%3lu. ", (unsigned long int) (yyp - yystack->yyitems));
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
		   yyp->yyoption.yyrule,
		   (long int) YYINDEX (yyp->yyoption.yystate),
		   (long int) YYINDEX (yyp->yyoption.yynext));
	}
      fprintf (stderr, "\n");
    }
  fprintf (stderr, "Tops:");
  for (yyi = 0; yyi < yystack->yytops.yysize; yyi += 1)
    fprintf (stderr, "%lu: %ld; ", (unsigned long int) yyi,
	     (long int) YYINDEX (yystack->yytops.yystates[yyi]));
  fprintf (stderr, "\n");
}
#endif


#line 1775 "cbook.y"




