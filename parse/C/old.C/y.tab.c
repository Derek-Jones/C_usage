/* A Bison parser, made by GNU Bison 2.0.  */

/* Skeleton parser for GLR parsing with Bison,
   Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* This is the parser code for GLR (Generalized LR) parser. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <setjmp.h>

/* Identify Bison output.  */
#define YYBISON 1

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
     AUTO = 258,
     STATIC = 259,
     EXTERN = 260,
     REGISTER = 261,
     TYPEDEF = 262,
     CHAR = 263,
     FLOAT = 264,
     DOUBLE = 265,
     INT = 266,
     SHORT = 267,
     LONG = 268,
     UNSIGNED = 269,
     SIGNED = 270,
     VOID = 271,
     CONST = 272,
     VOLATILE = 273,
     STRUCT = 274,
     UNION = 275,
     ENUM = 276,
     IF = 277,
     ELSE = 278,
     WHILE = 279,
     FOR = 280,
     DO = 281,
     SWITCH = 282,
     CASE = 283,
     DEFAULT = 284,
     BREAK = 285,
     CONTINUE = 286,
     RETURN = 287,
     GOTO = 288,
     SIZEOF = 289,
     OPEN_RND = 290,
     CLOSE_RND = 291,
     LEFTSHIFT = 292,
     RIGHTSHIFT = 293,
     PLUS = 294,
     ADD = 295,
     NEGATE = 296,
     MINUS = 297,
     STAR = 298,
     TIMES = 299,
     REMAINDER = 300,
     DIVIDE = 301,
     XOR = 302,
     AND = 303,
     BITAND = 304,
     OR = 305,
     BITNEGATE = 306,
     NOT = 307,
     LT = 308,
     LE = 309,
     GE = 310,
     GT = 311,
     EQUAL = 312,
     NOTEQUAL = 313,
     ANDTEST = 314,
     ORTEST = 315,
     QUESTION = 316,
     COLON = 317,
     DOT = 318,
     DEREF = 319,
     PLUSPLUS = 320,
     MINUSMINUS = 321,
     COMMA = 322,
     SEMICOLON = 323,
     ELLIPSIS = 324,
     OPEN_CURL = 325,
     CLOSE_CURL = 326,
     OPEN_SQUARE = 327,
     CLOSE_SQUARE = 328,
     ASSIGN = 329,
     PLUSASSIGN = 330,
     MINUSASSIGN = 331,
     TIMESASSIGN = 332,
     LSASSIGN = 333,
     RSASSIGN = 334,
     ANDASSIGN = 335,
     DIVASSIGN = 336,
     REMASSIGN = 337,
     ORASSIGN = 338,
     NOTASSIGN = 339,
     CONSTANT = 340,
     IDENTIFIER = 341,
     STRING_LITERAL = 342,
     TYPEDEFNAME = 343,
     INLINE = 344,
     RESTRICT = 345,
     _BOOL = 346,
     _COMPLEX = 347,
     _IMAGINARY = 348,
     UNDEFINED = 349
   };
#endif
#define AUTO 258
#define STATIC 259
#define EXTERN 260
#define REGISTER 261
#define TYPEDEF 262
#define CHAR 263
#define FLOAT 264
#define DOUBLE 265
#define INT 266
#define SHORT 267
#define LONG 268
#define UNSIGNED 269
#define SIGNED 270
#define VOID 271
#define CONST 272
#define VOLATILE 273
#define STRUCT 274
#define UNION 275
#define ENUM 276
#define IF 277
#define ELSE 278
#define WHILE 279
#define FOR 280
#define DO 281
#define SWITCH 282
#define CASE 283
#define DEFAULT 284
#define BREAK 285
#define CONTINUE 286
#define RETURN 287
#define GOTO 288
#define SIZEOF 289
#define OPEN_RND 290
#define CLOSE_RND 291
#define LEFTSHIFT 292
#define RIGHTSHIFT 293
#define PLUS 294
#define ADD 295
#define NEGATE 296
#define MINUS 297
#define STAR 298
#define TIMES 299
#define REMAINDER 300
#define DIVIDE 301
#define XOR 302
#define AND 303
#define BITAND 304
#define OR 305
#define BITNEGATE 306
#define NOT 307
#define LT 308
#define LE 309
#define GE 310
#define GT 311
#define EQUAL 312
#define NOTEQUAL 313
#define ANDTEST 314
#define ORTEST 315
#define QUESTION 316
#define COLON 317
#define DOT 318
#define DEREF 319
#define PLUSPLUS 320
#define MINUSMINUS 321
#define COMMA 322
#define SEMICOLON 323
#define ELLIPSIS 324
#define OPEN_CURL 325
#define CLOSE_CURL 326
#define OPEN_SQUARE 327
#define CLOSE_SQUARE 328
#define ASSIGN 329
#define PLUSASSIGN 330
#define MINUSASSIGN 331
#define TIMESASSIGN 332
#define LSASSIGN 333
#define RSASSIGN 334
#define ANDASSIGN 335
#define DIVASSIGN 336
#define REMASSIGN 337
#define ORASSIGN 338
#define NOTASSIGN 339
#define CONSTANT 340
#define IDENTIFIER 341
#define STRING_LITERAL 342
#define TYPEDEFNAME 343
#define INLINE 344
#define RESTRICT 345
#define _BOOL 346
#define _COMPLEX 347
#define _IMAGINARY 348
#define UNDEFINED 349




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
#line 284 "y.tab.c"

#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#ifdef __cplusplus
   typedef bool yybool;
#else
   typedef unsigned char yybool;
#endif
#define yytrue 1
#define yyfalse 0

/*-----------------.
| GCC extensions.  |
`-----------------*/

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if !defined (__GNUC__) || __GNUC__ < 2 || \
(__GNUC__ == 2 && __GNUC_MINOR__ < 5) || __STRICT_ANSI__
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YYASSERT
# define YYASSERT(condition) ((void) ((condition) || (abort (), 0)))
#endif

#ifndef ATTRIBUTE_UNUSED
# define ATTRIBUTE_UNUSED __attribute__ ((__unused__))
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  115
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1348

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  84
/* YYNRULES -- Number of rules. */
#define YYNRULES  230
/* YYNRULES -- Number of states. */
#define YYNSTATES  364
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule. */
#define YYMAXRHS 8
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule. */
#define YYMAXLEFT 0

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   349

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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      22,    23,    25,    27,    32,    37,    41,    45,    48,    51,
      58,    66,    68,    72,    74,    77,    80,    83,    86,    91,
      93,    95,    97,    99,   101,   103,   105,   110,   112,   116,
     120,   124,   126,   130,   134,   136,   140,   144,   146,   150,
     154,   158,   162,   164,   168,   172,   174,   178,   180,   184,
     186,   190,   192,   196,   198,   202,   204,   210,   212,   216,
     218,   220,   222,   224,   226,   228,   230,   232,   234,   236,
     238,   240,   244,   246,   247,   249,   253,   256,   257,   259,
     262,   265,   268,   271,   273,   277,   279,   283,   285,   287,
     289,   291,   293,   295,   297,   299,   301,   303,   305,   307,
     309,   311,   313,   315,   317,   319,   321,   323,   324,   326,
     332,   335,   337,   339,   341,   344,   348,   349,   351,   354,
     357,   359,   363,   364,   366,   368,   372,   378,   385,   388,
     390,   394,   396,   400,   402,   404,   406,   408,   409,   411,
     414,   415,   417,   418,   420,   421,   423,   425,   429,   435,
     442,   449,   455,   460,   465,   468,   472,   474,   477,   479,
     483,   485,   489,   490,   492,   495,   498,   500,   502,   506,
     509,   511,   514,   515,   517,   518,   520,   524,   529,   534,
     539,   541,   543,   547,   552,   553,   555,   558,   563,   566,
     568,   571,   575,   578,   580,   582,   584,   586,   588,   592,
     597,   601,   604,   609,   614,   615,   617,   622,   624,   633,
     641,   645,   648,   651,   655,   657,   659,   660,   662,   667,
     669
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
      96,     0,    -1,    97,    -1,    96,    97,    -1,   175,    -1,
     168,    -1,    86,    -1,    85,    -1,    87,    -1,    35,   118,
      36,    -1,    -1,   101,    -1,    98,    -1,   100,    72,   118,
      73,    -1,   100,    35,    99,    36,    -1,   100,    63,    86,
      -1,   100,    64,    86,    -1,   100,    65,    -1,   100,    66,
      -1,    35,   156,    36,    70,   164,    71,    -1,    35,   156,
      36,    70,   164,    67,    71,    -1,   116,    -1,   101,    67,
     116,    -1,   100,    -1,    65,   102,    -1,    66,   102,    -1,
     103,   104,    -1,    34,   102,    -1,    34,    35,   156,    36,
      -1,    48,    -1,    44,    -1,    40,    -1,    42,    -1,    51,
      -1,    52,    -1,   102,    -1,    35,   156,    36,   104,    -1,
     104,    -1,   105,    44,   104,    -1,   105,    46,   104,    -1,
     105,    45,   104,    -1,   105,    -1,   106,    40,   105,    -1,
     106,    42,   105,    -1,   106,    -1,   107,    37,   106,    -1,
     107,    38,   106,    -1,   107,    -1,   108,    53,   107,    -1,
     108,    56,   107,    -1,   108,    54,   107,    -1,   108,    55,
     107,    -1,   108,    -1,   109,    57,   108,    -1,   109,    58,
     108,    -1,   109,    -1,   110,    48,   109,    -1,   110,    -1,
     111,    47,   110,    -1,   111,    -1,   112,    50,   111,    -1,
     112,    -1,   113,    59,   112,    -1,   113,    -1,   114,    60,
     113,    -1,   114,    -1,   114,    61,   118,    62,   115,    -1,
     115,    -1,   102,   117,   116,    -1,    74,    -1,    77,    -1,
      81,    -1,    82,    -1,    75,    -1,    76,    -1,    78,    -1,
      79,    -1,    80,    -1,    83,    -1,    84,    -1,   116,    -1,
     118,    67,   116,    -1,   115,    -1,    -1,   124,    -1,   123,
     120,    68,    -1,   123,    68,    -1,    -1,   123,    -1,   126,
     122,    -1,   127,   122,    -1,   141,   122,    -1,   142,   122,
      -1,   125,    -1,   124,    67,   125,    -1,   144,    -1,   144,
      74,   162,    -1,     7,    -1,     5,    -1,     4,    -1,     3,
      -1,     6,    -1,    16,    -1,     8,    -1,    12,    -1,    11,
      -1,    13,    -1,     9,    -1,    10,    -1,    15,    -1,    14,
      -1,    91,    -1,    92,    -1,    93,    -1,   129,    -1,   138,
      -1,   161,    -1,    -1,    86,    -1,   130,   128,    70,   131,
      71,    -1,   130,    86,    -1,    19,    -1,    20,    -1,   132,
      -1,   131,   132,    -1,   134,   135,    68,    -1,    -1,   134,
      -1,   127,   133,    -1,   141,   133,    -1,   137,    -1,   135,
      67,   137,    -1,    -1,   144,    -1,   144,    -1,   136,    62,
     119,    -1,    21,   128,    70,   139,    71,    -1,    21,   128,
      70,   139,    67,    71,    -1,    21,    86,    -1,   140,    -1,
     139,    67,   140,    -1,    86,    -1,    86,    74,   119,    -1,
      17,    -1,    90,    -1,    18,    -1,    89,    -1,    -1,   149,
      -1,   143,   148,    -1,    -1,   150,    -1,    -1,   116,    -1,
      -1,   155,    -1,    86,    -1,    35,   144,    36,    -1,   148,
      72,   145,   146,    73,    -1,   148,    72,     4,   145,   116,
      73,    -1,   148,    72,   150,     4,   116,    73,    -1,   148,
      72,   145,    44,    73,    -1,   148,    35,   151,    36,    -1,
     148,    35,   147,    36,    -1,    44,   145,    -1,    44,   145,
     149,    -1,   141,    -1,   150,   141,    -1,   152,    -1,   152,
      67,    69,    -1,   154,    -1,   152,    67,   154,    -1,    -1,
     157,    -1,   123,   144,    -1,   123,   157,    -1,   123,    -1,
      86,    -1,   155,    67,    86,    -1,   134,   153,    -1,   149,
      -1,   143,   160,    -1,    -1,   160,    -1,    -1,   151,    -1,
      35,   157,    36,    -1,   158,    72,   146,    73,    -1,   158,
      72,    44,    73,    -1,   158,    35,   159,    36,    -1,    86,
      -1,   116,    -1,    70,   164,    71,    -1,    70,   164,    67,
      71,    -1,    -1,   165,    -1,   163,   162,    -1,   164,    67,
     163,   162,    -1,   166,    74,    -1,   167,    -1,   166,   167,
      -1,    72,   119,    73,    -1,    63,    86,    -1,   169,    -1,
     170,    -1,   171,    -1,   173,    -1,   174,    -1,    86,    62,
     168,    -1,    28,   119,    62,   168,    -1,    29,    62,   168,
      -1,   172,    68,    -1,    22,    35,   118,    36,    -1,    27,
      35,   118,    36,    -1,    -1,   118,    -1,    24,    35,   118,
      36,    -1,    26,    -1,    25,    35,   172,    68,   172,    68,
     172,    36,    -1,    25,    35,   121,   172,    68,   172,    36,
      -1,    33,    86,    68,    -1,    31,    68,    -1,    30,    68,
      -1,    32,   172,    68,    -1,   177,    -1,   121,    -1,    -1,
     178,    -1,   123,   144,   176,    70,    -1,   121,    -1,   178,
     121,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   275,   275,   279,   282,   286,   295,   299,   303,   307,
     313,   316,   322,   326,   330,   334,   338,   342,   346,   350,
     354,   361,   365,   372,   376,   380,   384,   388,   392,   399,
     403,   407,   411,   415,   419,   426,   430,   437,   441,   445,
     449,   456,   460,   464,   471,   475,   479,   486,   490,   494,
     498,   502,   509,   513,   517,   524,   528,   535,   539,   546,
     550,   557,   561,   568,   572,   579,   583,   590,   594,   601,
     605,   609,   613,   617,   621,   625,   629,   633,   637,   641,
     648,   652,   659,   664,   667,   673,   677,   683,   686,   692,
     696,   700,   704,   711,   715,   722,   726,   733,   737,   741,
     745,   749,   756,   760,   764,   768,   772,   776,   780,   784,
     788,   792,   796,   800,   804,   808,   812,   818,   821,   828,
     832,   839,   843,   850,   854,   861,   864,   867,   873,   877,
     884,   888,   894,   897,   903,   907,   923,   927,   931,   938,
     942,   949,   953,   960,   964,   968,   975,   981,   984,   990,
     996,   999,  1004,  1007,  1012,  1015,  1021,  1025,  1029,  1033,
    1037,  1041,  1045,  1049,  1056,  1060,  1067,  1071,  1078,  1082,
    1089,  1093,  1099,  1102,  1108,  1112,  1116,  1123,  1127,  1134,
    1141,  1145,  1151,  1154,  1159,  1162,  1168,  1172,  1176,  1180,
    1187,  1194,  1198,  1202,  1208,  1211,  1217,  1221,  1228,  1235,
    1239,  1246,  1250,  1262,  1266,  1270,  1274,  1278,  1285,  1289,
    1293,  1318,  1331,  1335,  1341,  1344,  1357,  1361,  1365,  1369,
    1376,  1380,  1384,  1388,  1397,  1401,  1407,  1410,  1420,  1427,
    1431
};
#endif

#if (YYDEBUG) || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "STATIC", "EXTERN", "REGISTER",
  "TYPEDEF", "CHAR", "FLOAT", "DOUBLE", "INT", "SHORT", "LONG", "UNSIGNED",
  "SIGNED", "VOID", "CONST", "VOLATILE", "STRUCT", "UNION", "ENUM", "IF",
  "ELSE", "WHILE", "FOR", "DO", "SWITCH", "CASE", "DEFAULT", "BREAK",
  "CONTINUE", "RETURN", "GOTO", "SIZEOF", "OPEN_RND", "CLOSE_RND",
  "LEFTSHIFT", "RIGHTSHIFT", "PLUS", "ADD", "NEGATE", "MINUS", "STAR",
  "TIMES", "REMAINDER", "DIVIDE", "XOR", "AND", "BITAND", "OR",
  "BITNEGATE", "NOT", "LT", "LE", "GE", "GT", "EQUAL", "NOTEQUAL",
  "ANDTEST", "ORTEST", "QUESTION", "COLON", "DOT", "DEREF", "PLUSPLUS",
  "MINUSMINUS", "COMMA", "SEMICOLON", "ELLIPSIS", "OPEN_CURL",
  "CLOSE_CURL", "OPEN_SQUARE", "CLOSE_SQUARE", "ASSIGN", "PLUSASSIGN",
  "MINUSASSIGN", "TIMESASSIGN", "LSASSIGN", "RSASSIGN", "ANDASSIGN",
  "DIVASSIGN", "REMASSIGN", "ORASSIGN", "NOTASSIGN", "CONSTANT",
  "IDENTIFIER", "STRING_LITERAL", "TYPEDEFNAME", "INLINE", "RESTRICT",
  "_BOOL", "_COMPLEX", "_IMAGINARY", "UNDEFINED", "$accept", "TU",
  "translation_unit", "primary_expr", "argument_expr_list_opt",
  "postfix_expr", "argument_expr_list", "unary_expr", "unary_operator",
  "cast_expr", "multiplicative_expr", "additive_expr", "shift_expr",
  "relational_expr", "equality_expr", "AND_expr", "exclusive_OR_expr",
  "inclusive_OR_expr", "logical_AND_expr", "logical_OR_expr",
  "conditional_expr", "assignment_expr", "assignment_operator",
  "expression", "constant_expr", "init_declarator_list_opt", "declaration",
  "declaration_specifiers_opt", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "identifier_opt", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list_opt", "specifier_qualifier_list",
  "struct_declarator_list", "declarator_opt", "struct_declarator",
  "enum_specifier", "enumerator_list", "enumerator", "type_qualifier",
  "function_specifier", "pointer_opt", "declarator",
  "type_qualifier_list_opt", "assignment_expr_opt", "identifier_list_opt",
  "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "abstract_declarator_opt",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator_opt",
  "parameter_type_list_opt", "direct_abstract_declarator", "typedef_name",
  "initializer", "designation_opt", "initializer_list", "designation",
  "designator_list", "designator", "statement", "labeled_statement",
  "expression_statement", "selection_header", "expr_opt",
  "iteration_header", "jump_statement", "external_declaration",
  "declaration_list_opt", "function_header", "declaration_list", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    95,    96,    96,    97,    97,    98,    98,    98,    98,
      99,    99,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   101,   101,   102,   102,   102,   102,   102,   102,   103,
     103,   103,   103,   103,   103,   104,   104,   105,   105,   105,
     105,   106,   106,   106,   107,   107,   107,   108,   108,   108,
     108,   108,   109,   109,   109,   110,   110,   111,   111,   112,
     112,   113,   113,   114,   114,   115,   115,   116,   116,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     118,   118,   119,   120,   120,   121,   121,   122,   122,   123,
     123,   123,   123,   124,   124,   125,   125,   126,   126,   126,
     126,   126,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   128,   128,   129,
     129,   130,   130,   131,   131,   132,   133,   133,   134,   134,
     135,   135,   136,   136,   137,   137,   138,   138,   138,   139,
     139,   140,   140,   141,   141,   141,   142,   143,   143,   144,
     145,   145,   146,   146,   147,   147,   148,   148,   148,   148,
     148,   148,   148,   148,   149,   149,   150,   150,   151,   151,
     152,   152,   153,   153,   154,   154,   154,   155,   155,   156,
     157,   157,   158,   158,   159,   159,   160,   160,   160,   160,
     161,   162,   162,   162,   163,   163,   164,   164,   165,   166,
     166,   167,   167,   168,   168,   168,   168,   168,   169,   169,
     169,   170,   171,   171,   172,   172,   173,   173,   173,   173,
     174,   174,   174,   174,   175,   175,   176,   176,   177,   178,
     178
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       0,     1,     1,     4,     4,     3,     3,     2,     2,     6,
       7,     1,     3,     1,     2,     2,     2,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     0,     1,     3,     2,     0,     1,     2,
       2,     2,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     5,
       2,     1,     1,     1,     2,     3,     0,     1,     2,     2,
       1,     3,     0,     1,     1,     3,     5,     6,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     0,     1,     2,
       0,     1,     0,     1,     0,     1,     1,     3,     5,     6,
       6,     5,     4,     4,     2,     3,     1,     2,     1,     3,
       1,     3,     0,     1,     2,     2,     1,     1,     3,     2,
       1,     2,     0,     1,     0,     1,     3,     4,     4,     4,
       1,     1,     3,     4,     0,     1,     2,     4,     2,     1,
       2,     3,     2,     1,     1,     1,     1,     1,     3,     4,
       3,     2,     4,     4,     0,     1,     4,     1,     8,     7,
       3,     2,     2,     3,     1,     1,     0,     1,     4,     1,
       2
};

/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none). */
static const unsigned char yydprec[] =
{
       0,     0,     0,     0,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM. */
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error.  */
static const unsigned char yydefact[] =
{
     214,   100,    99,    98,   101,    97,   103,   107,   108,   105,
     104,   106,   110,   109,   102,   143,   145,   121,   122,   117,
       0,     0,     0,   217,     0,     0,     0,     0,     0,   214,
       0,     0,     0,    31,    32,    30,    29,    33,    34,     0,
       0,     7,     6,     8,   146,   144,   111,   112,   113,   214,
       2,    12,    23,    35,     0,    37,    41,    44,    47,    52,
      55,    57,    59,    61,    63,    65,    67,    80,   215,   225,
     147,    87,    87,   114,   117,   115,    87,    87,   116,     5,
     203,   204,   205,     0,   206,   207,     4,   224,   138,     0,
       0,     0,   214,     0,     6,    35,    82,     0,   214,   222,
     221,     0,     0,     0,    27,     6,     0,   126,   147,   126,
       0,     0,    24,    25,   214,     1,     3,    10,     0,     0,
      17,    18,     0,    69,    73,    74,    70,    75,    76,    77,
      71,    72,    78,    79,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,    86,     0,    84,
      93,     0,    95,   148,   190,    89,    88,    90,   120,     0,
      91,    92,   211,     0,     0,     0,   214,   147,     0,     0,
     214,     6,   210,   223,   220,     0,     9,   128,   127,   182,
     148,   179,   173,   129,     0,     0,   208,     0,    11,    21,
      15,    16,     0,    68,    38,    40,    39,    42,    43,    45,
      46,    48,    50,    51,    49,    53,    54,    56,    58,    60,
      62,    64,     0,    81,   166,   164,   151,    85,   147,   147,
     156,   149,     0,   229,     0,   227,     0,   141,     0,   139,
     212,   216,     0,    95,   214,   213,   209,    28,   147,     0,
     181,   194,    36,     0,    14,     0,    13,     0,   165,   167,
      94,     0,   154,   150,   194,   191,    96,   228,   230,     0,
     123,   147,     0,     0,   136,   214,     0,     0,   184,   152,
       0,     0,     0,     0,   195,     0,   199,    22,    66,   157,
     190,   147,     0,     0,   168,   170,   155,   150,   152,   151,
       0,   119,   124,     0,     0,   130,   134,   142,   137,   140,
       0,   214,   186,   185,     0,    30,   153,     0,   202,     0,
     196,   194,    19,   198,   200,   182,   174,   175,   163,   162,
       0,     0,     0,    30,     0,     0,   194,   192,   147,   125,
       0,   219,     0,   189,   188,   187,   201,    20,     0,   147,
     169,   171,   178,     0,   161,   158,     0,   193,   131,   135,
     218,   197,   159,   160
};

/* YYPDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,    49,    50,    51,   197,    52,   198,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,   134,    68,    97,   158,    69,   165,   166,   159,
     160,    71,    72,    89,    73,    74,   269,   270,   187,   108,
     303,   304,   305,    75,   238,   239,    76,    77,   161,   243,
     225,   317,   292,   231,   163,   226,   293,   294,   191,   295,
     296,   110,   277,   249,   314,   250,    78,   266,   282,   283,
     284,   285,   286,    79,    80,    81,    82,    83,    84,    85,
      86,   234,    87,   235
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -271
static const short int yypact[] =
{
     419,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,   -16,
      51,   113,   150,  -271,   168,  1153,   101,    98,   137,  1153,
     121,  1180,  1007,  -271,  -271,  -271,  -271,  -271,  -271,  1207,
    1207,  -271,   644,  -271,  -271,  -271,  -271,  -271,  -271,   328,
    -271,  -271,    -8,   458,  1153,  -271,   128,     1,   131,   126,
     119,   160,   162,   161,   153,   123,  -271,  -271,   146,  -271,
       3,   292,   773,  -271,   129,  -271,   864,   883,  -271,  -271,
    -271,  -271,  -271,   148,  -271,  -271,  -271,  -271,   147,   151,
    1153,  1153,   510,  1153,  -271,  -271,  -271,   158,  1095,  -271,
    -271,   154,   156,  1007,  -271,   601,     6,   478,     9,  1066,
     189,  1007,  -271,  -271,  1095,  -271,  -271,  1153,   141,   142,
    -271,  -271,  1153,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,  1153,  -271,  1153,  1153,  1153,  1153,
    1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,
    1153,  1153,  1153,  1153,  1153,  1153,     7,  -271,   163,   165,
    -271,   -14,   735,  -271,  -271,  -271,  -271,  -271,   147,   159,
    -271,  -271,  -271,   144,    12,    15,  1153,    39,   169,    24,
    1095,   174,  -271,  -271,  -271,   202,  -271,  -271,  -271,   204,
      26,  -271,  -271,  -271,   632,   206,  -271,   207,   173,  -271,
    -271,  -271,    36,  -271,  -271,  -271,  -271,   128,   128,     1,
       1,   131,   131,   131,   131,   126,   126,   119,   160,   162,
     161,   153,    37,  -271,  -271,   201,     7,  -271,   201,   201,
    -271,    -7,   764,  -271,   176,   902,  1093,   177,    65,  -271,
    -271,  -271,   185,   186,  1153,  -271,  -271,   191,   201,    -6,
      -4,    72,  -271,   191,  -271,  1153,  -271,  1153,  -271,  -271,
    -271,   223,   921,    16,    72,  -271,  -271,  -271,  -271,   387,
    -271,   -12,  1153,   -27,  -271,  1153,   195,   228,   902,  1234,
     179,  1153,   764,    89,  -271,   -11,  -271,  -271,  -271,  -271,
      44,     2,   230,   231,   203,  -271,   205,     7,  1261,    18,
      94,  -271,  -271,   120,   209,  -271,   212,  -271,  -271,  -271,
     233,  1153,  -271,  -271,   240,   208,  -271,   210,  -271,   214,
    -271,    68,  -271,  -271,  -271,    -9,  -271,  -271,  -271,  -271,
     754,   193,  1153,   215,   216,  1153,    70,  -271,   -12,  -271,
    1153,  -271,   244,  -271,  -271,  -271,  -271,  -271,   764,   201,
    -271,  -271,  -271,   217,  -271,  -271,   218,  -271,  -271,  -271,
    -271,  -271,  -271,  -271
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -271,  -271,   236,  -271,  -271,  -271,  -271,   -24,  -271,   -36,
      55,    59,    47,    50,   133,   143,   164,   140,   166,  -271,
     -23,   -80,  -271,    56,  -264,  -271,   -78,    78,     0,  -271,
      66,  -271,   -13,   246,  -271,  -271,  -271,    45,   213,   -98,
    -271,  -271,   -20,  -271,  -271,    48,   -22,  -271,  -105,   -65,
    -223,    25,  -271,  -271,   -95,    61,    49,  -271,  -271,    -5,
    -271,    34,  -102,  -271,  -271,  -271,  -271,  -270,  -226,    62,
    -271,  -271,    79,   -75,  -271,  -271,  -271,   -25,  -271,  -271,
    -271,  -271,  -271,  -271
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -227
static const short int yytable[] =
{
      70,    95,    96,   189,   101,   162,   192,   104,   307,   188,
     109,   188,   320,   190,   176,   112,   113,   319,   135,   107,
     297,   229,   335,   182,    15,    16,   349,   117,   262,   278,
      95,  -183,   156,    15,    16,    15,    16,   199,  -176,   196,
     298,   139,   186,   140,   308,  -172,   156,   156,   240,    70,
    -132,   241,   280,   156,   203,   118,   119,   120,   121,   237,
     245,   281,  -180,   323,   122,   263,   279,   178,  -183,  -176,
      88,   157,   230,   155,   332,   223,   359,   230,   361,   155,
    -177,   109,   155,   156,   233,   109,    90,   109,   106,   109,
     107,   155,   177,  -180,   107,   348,   107,    45,   107,   257,
     204,   205,   206,   155,   155,   246,    45,   157,    45,   256,
     348,  -177,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
     258,   280,   273,   280,   224,   280,   274,   185,   271,   347,
     281,   357,   281,   189,   281,   195,   174,   175,    91,   179,
     167,   242,   265,   190,   170,   171,   321,   268,   252,   106,
     322,   336,   177,    98,   261,   337,    99,   106,   141,   142,
      95,   271,   136,   137,   138,   287,   147,   148,   202,   143,
     144,   145,   146,   153,   154,    92,   325,   338,   339,   327,
     211,   212,   213,   214,   207,   208,   190,   215,   216,   316,
     209,   210,   265,    93,   259,   100,   306,   102,   149,   150,
     222,   151,   152,   155,   109,   168,   172,  -118,   316,   276,
     180,   173,   183,   107,   184,   194,   326,   200,   201,   236,
     237,   227,   228,    95,   288,   177,   114,   244,   247,   248,
     255,   224,   253,   254,   325,   156,   267,   109,    95,    96,
     310,   272,   353,   275,   190,   356,   107,    95,    96,   289,
     232,   251,   291,   311,   312,   318,   328,   329,   265,   341,
     330,   340,   331,   306,  -133,   224,   343,   259,   291,   352,
     360,   344,   217,   345,   261,   116,   342,   346,   354,   355,
     362,   363,   220,   218,   260,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   302,   219,    95,    96,   358,   221,
     169,   309,   193,   334,   299,   351,   300,   313,   115,     0,
     291,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,   324,     0,     0,     0,    33,     0,
      34,     0,    35,     0,     0,     0,    36,     0,   164,    37,
      38,    44,    45,    46,    47,    48,     0,     0,     0,     0,
       0,     0,     0,    39,    40,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
       0,     0,     0,    41,    42,    43,     0,    44,    45,    46,
      47,    48,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     0,     0,     0,   301,    33,
       0,    34,     0,    35,     0,     0,     0,    36,     0,     0,
      37,    38,     0,   164,     0,     0,     0,    45,    46,    47,
      48,     0,     0,     0,    39,    40,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,     0,     0,     0,    41,    42,    43,     0,    44,    45,
      46,    47,    48,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,     0,    31,    32,     0,     0,     0,     0,
      33,     0,    34,     0,    35,     0,     0,     0,    36,     0,
       0,    37,    38,     0,   164,     0,     0,     0,    45,    46,
      47,    48,     0,     0,     0,    39,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,   105,    43,     0,    44,
      45,    46,    47,    48,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    -6,    -6,     0,     0,
       0,     0,     0,     0,     0,    -6,     0,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,    31,    32,     0,    -6,
       0,     0,    33,    -6,    34,     0,    35,     0,     0,    -6,
      36,     0,     0,    37,    38,     0,     0,  -190,    -6,     0,
    -190,  -190,  -190,  -190,  -190,     0,     0,    39,    40,     0,
       0,     0,   251,     0,     0,     0,   114,     0,     0,     0,
       0,     0,    -6,     0,     0,     0,     0,    41,    94,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -190,     0,     0,  -190,  -190,  -190,  -190,  -190,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     0,     0,     0,    31,    32,
       0,     0,     0,     0,    33,  -226,    34,     0,    35,   232,
       0,     0,    36,     0,     0,    37,    38,     0,     0,     0,
       0,   164,     0,   350,    44,    45,    46,    47,    48,    39,
      40,     0,     0,     0,   264,     0,     0,     0,     0,     0,
     164,     0,     0,    44,    45,    46,    47,    48,     0,    41,
      94,    43,     0,     0,     0,     0,     0,     0,     0,   164,
       0,     0,    44,    45,    46,    47,    48,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
     164,     0,     0,    44,    45,    46,    47,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   164,
       0,     0,    44,    45,    46,    47,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164,     0,
       0,    44,    45,    46,    47,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   290,     0,     0,
      44,    45,    46,    47,    48,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,    33,     0,    34,
       0,    35,     0,     0,     0,    36,     0,     0,    37,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    40,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,    41,   105,    43,     0,     0,    45,    46,    47,
      48,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     0,     0,    20,     0,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     0,     0,     0,     0,    33,     0,    34,     0,    35,
       0,     0,     0,    36,     0,     0,    37,    38,     0,     0,
       0,     0,   164,     0,     0,     0,    45,    46,    47,    48,
      39,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   164,
      41,   181,    43,    45,    46,    47,    48,    31,    32,     0,
       0,     0,     0,    33,     0,    34,     0,    35,     0,     0,
       0,    36,     0,     0,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,    31,   103,     0,     0,    39,    40,
      33,     0,    34,     0,    35,     0,     0,     0,    36,     0,
       0,    37,    38,     0,     0,     0,     0,     0,    41,    94,
      43,    31,   111,     0,     0,    39,    40,    33,     0,    34,
       0,    35,     0,     0,     0,    36,     0,     0,    37,    38,
       0,     0,     0,     0,     0,    41,    94,    43,    31,    32,
       0,     0,    39,    40,    33,     0,    34,     0,   315,     0,
       0,     0,    36,     0,     0,    37,    38,     0,     0,     0,
       0,     0,    41,    94,    43,    31,    32,     0,     0,    39,
      40,    33,     0,    34,     0,   333,     0,     0,     0,    36,
       0,     0,    37,    38,     0,     0,     0,     0,     0,    41,
      94,    43,     0,     0,     0,     0,    39,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,    94,    43
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const unsigned char yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     0,     0,     0,     0,     0,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,    19,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,    25,     0,     0,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] =
{
       0,   190,     0,   190,     0,   190,     0,    83,     0,    87,
       0,    87,     0,    87,     0,    87,     0,   190,     0,   190,
       0,   190,     0,   190,     0,   190,     0,   126,     0,   126,
       0,    83,     0,   182,     0,   190,     0,   190,     0,   182,
       0
};

static const short int yycheck[] =
{
       0,    25,    25,   108,    29,    70,   108,    31,   272,   107,
      32,   109,   282,   108,    92,    39,    40,   281,    54,    32,
       4,    35,     4,    98,    17,    18,    35,    35,    35,    35,
      54,    35,    44,    17,    18,    17,    18,   117,    36,   114,
     263,    40,    36,    42,    71,    36,    44,    44,    36,    49,
      62,    36,    63,    44,   134,    63,    64,    65,    66,    86,
      36,    72,    36,    74,    72,    72,    72,    92,    72,    67,
      86,    68,    86,    67,   297,   155,   340,    86,   348,    67,
      36,   103,    67,    44,   162,   107,    35,   109,    32,   111,
     103,    67,    92,    67,   107,   321,   109,    90,   111,    62,
     136,   137,   138,    67,    67,   180,    90,    68,    90,    73,
     336,    67,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     225,    63,    67,    63,   156,    63,    71,   103,   236,    71,
      72,    71,    72,   248,    72,   111,    90,    91,    35,    93,
      72,   176,   232,   248,    76,    77,    67,   235,   194,   103,
      71,    67,   162,    62,   229,    71,    68,   111,    37,    38,
     194,   269,    44,    45,    46,   255,    57,    58,   122,    53,
      54,    55,    56,    60,    61,    35,   291,    67,    68,   291,
     143,   144,   145,   146,   139,   140,   291,   147,   148,   279,
     141,   142,   282,    35,   226,    68,   271,    86,    48,    47,
     154,    50,    59,    67,   236,    86,    68,    70,   298,   244,
      62,    70,    68,   236,    68,    36,   291,    86,    86,    70,
      86,    68,    67,   257,   257,   235,    62,    68,    36,    35,
      67,   263,    36,    36,   349,    44,    70,   269,   272,   272,
     275,    74,   332,    68,   349,   335,   269,   281,   281,    36,
      74,    70,   262,    68,    36,    86,    36,    36,   348,    36,
      67,    62,    67,   338,    62,   297,    36,   299,   278,    86,
      36,    73,   149,    73,   349,    49,   311,    73,    73,    73,
      73,    73,   152,   150,   228,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,   269,   151,   340,   340,   338,   153,
      74,   273,   109,   298,   263,   330,   264,   278,     0,    -1,
     330,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,   285,    -1,    -1,    -1,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    48,    -1,    86,    51,
      52,    89,    90,    91,    92,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    85,    86,    87,    -1,    89,    90,    91,
      92,    93,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    71,    40,
      -1,    42,    -1,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,    -1,    86,    -1,    -1,    -1,    90,    91,    92,
      93,    -1,    -1,    -1,    65,    66,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    85,    86,    87,    -1,    89,    90,
      91,    92,    93,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    34,    35,    -1,    -1,    -1,    -1,
      40,    -1,    42,    -1,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    52,    -1,    86,    -1,    -1,    -1,    90,    91,
      92,    93,    -1,    -1,    -1,    65,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    -1,    89,
      90,    91,    92,    93,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    34,    35,    -1,    68,
      -1,    -1,    40,    72,    42,    -1,    44,    -1,    -1,    35,
      48,    -1,    -1,    51,    52,    -1,    -1,    86,    44,    -1,
      89,    90,    91,    92,    93,    -1,    -1,    65,    66,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    89,    90,    91,    92,    93,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    40,    70,    42,    -1,    44,    74,
      -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    86,    -1,    69,    89,    90,    91,    92,    93,    65,
      66,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    89,    90,    91,    92,    93,    -1,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    89,    90,    91,    92,    93,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    89,    90,    91,    92,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    89,    90,    91,    92,    93,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    89,    90,    91,    92,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      89,    90,    91,    92,    93,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,    42,
      -1,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    85,    86,    87,    -1,    -1,    90,    91,    92,
      93,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    22,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    40,    -1,    42,    -1,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    -1,    90,    91,    92,    93,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      85,    86,    87,    90,    91,    92,    93,    34,    35,    -1,
      -1,    -1,    -1,    40,    -1,    42,    -1,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    65,    66,
      40,    -1,    42,    -1,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    34,    35,    -1,    -1,    65,    66,    40,    -1,    42,
      -1,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    34,    35,
      -1,    -1,    65,    66,    40,    -1,    42,    -1,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    34,    35,    -1,    -1,    65,
      66,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    85,
      86,    87,    -1,    -1,    -1,    -1,    65,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    40,    42,    44,    48,    51,    52,    65,
      66,    85,    86,    87,    89,    90,    91,    92,    93,    96,
      97,    98,   100,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   118,   121,
     123,   126,   127,   129,   130,   138,   141,   142,   161,   168,
     169,   170,   171,   172,   173,   174,   175,   177,    86,   128,
      35,    35,    35,    35,    86,   102,   115,   119,    62,    68,
      68,   172,    86,    35,   102,    86,   118,   127,   134,   141,
     156,    35,   102,   102,    62,     0,    97,    35,    63,    64,
      65,    66,    72,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,   117,   104,    44,    45,    46,    40,
      42,    37,    38,    53,    54,    55,    56,    57,    58,    48,
      47,    50,    59,    60,    61,    67,    44,    68,   120,   124,
     125,   143,   144,   149,    86,   122,   123,   122,    86,   128,
     122,   122,    68,    70,   118,   118,   121,   123,   172,   118,
      62,    86,   168,    68,    68,   156,    36,   133,   134,   143,
     149,   153,   157,   133,    36,   156,   168,    99,   101,   116,
      86,    86,   118,   116,   104,   104,   104,   105,   105,   106,
     106,   107,   107,   107,   107,   108,   108,   109,   110,   111,
     112,   113,   118,   116,   141,   145,   150,    68,    67,    35,
      86,   148,    74,   121,   176,   178,    70,    86,   139,   140,
      36,    36,   172,   144,    68,    36,   168,    36,    35,   158,
     160,    70,   104,    36,    36,    67,    73,    62,   149,   141,
     125,   144,    35,    72,    70,   116,   162,    70,   121,   131,
     132,   134,    74,    67,    71,    68,   172,   157,    35,    72,
      63,    72,   163,   164,   165,   166,   167,   116,   115,    36,
      86,   123,   147,   151,   152,   154,   155,     4,   145,   150,
     164,    71,   132,   135,   136,   137,   144,   119,    71,   140,
     172,    68,    36,   151,   159,    44,   116,   146,    86,   119,
     162,    67,    71,    74,   167,   143,   144,   157,    36,    36,
      67,    67,   145,    44,   146,     4,    67,    71,    67,    68,
      62,    36,   172,    36,    73,    73,    73,    71,   163,    35,
      69,   154,    86,   116,    73,    73,   116,    71,   137,   119,
      36,   162,    73,    73
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
   to be completed by functions that call expandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data. */
#define YYHEADROOM 2

#if (! defined (YYSTACKEXPANDABLE) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))
#define YYSTACKEXPANDABLE 1
#else
#define YYSTACKEXPANDABLE 0
#endif

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
  yybool yyisState;
  yybool yyresolved;
  yyStateNum yylrState;
  yyGLRState* yypred;
  size_t yyposn;
  union {
    yySemanticOption* yyfirstVal;
    YYSTYPE yysval;
  } yysemantics;
  YYLTYPE yyloc;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  size_t yysize, yycapacity;
};

struct yySemanticOption {
  yybool yyisState;
  yyRuleNum yyrule;
  yyGLRState* yystate;
  yySemanticOption* yynext;
};

union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrflag;
  int yyerrState;


  yySymbol* yytokenp;
  jmp_buf yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  int yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

static void yyinitGLRStack (yyGLRStack* yystack, size_t yysize);
static void yyexpandGLRStack (yyGLRStack* yystack);
static void yyfreeGLRStack (yyGLRStack* yystack);

static void
yyFail (yyGLRStack* yystack, const char* yyformat, ...)
{
  yystack->yyerrflag = 1;
  if (yyformat != NULL)
    {
      char yymsg[256];
      va_list yyap;
      va_start (yyap, yyformat);
      vsprintf (yymsg, yyformat, yyap);
      yyerror (yymsg);
    }
  longjmp (yystack->yyexception_buffer, 1);
}

#if YYDEBUG || YYERROR_VERBOSE
/** A printable representation of TOKEN.  Valid until next call to
 *  tokenName. */
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
static void yyfillin (yyGLRStackItem *, int, int) ATTRIBUTE_UNUSED;
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
     ATTRIBUTE_UNUSED;
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
	      YYLTYPE* yylocp ATTRIBUTE_UNUSED,
	      yyGLRStack* yystack
              )
{
  yybool yynormal ATTRIBUTE_UNUSED = (yystack->yysplitPoint == NULL);
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
  return yyerror ("syntax error: cannot back up"),	     \
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
#line 276 "cbook.y"
    {
	printf("TU reduce\n");
	}
    break;

  case 4:
#line 283 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 5:
#line 287 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 6:
#line 296 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 7:
#line 300 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 8:
#line 304 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 9:
#line 308 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 10:
#line 313 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 11:
#line 317 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 12:
#line 323 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 13:
#line 327 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 14:
#line 331 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 15:
#line 335 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 16:
#line 339 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 17:
#line 343 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 18:
#line 347 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 19:
#line 351 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 20:
#line 355 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 21:
#line 362 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 22:
#line 366 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 23:
#line 373 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 24:
#line 377 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 25:
#line 381 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 26:
#line 385 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 27:
#line 389 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 28:
#line 393 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 29:
#line 400 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 30:
#line 404 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 31:
#line 408 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 32:
#line 412 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 33:
#line 416 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 34:
#line 420 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 35:
#line 427 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 36:
#line 431 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 37:
#line 438 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 38:
#line 442 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 39:
#line 446 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 40:
#line 450 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 41:
#line 457 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 42:
#line 461 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 43:
#line 465 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 44:
#line 472 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 45:
#line 476 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 46:
#line 480 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 47:
#line 487 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 48:
#line 491 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 49:
#line 495 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 50:
#line 499 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 51:
#line 503 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 52:
#line 510 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 53:
#line 514 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 54:
#line 518 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 55:
#line 525 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 56:
#line 529 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 57:
#line 536 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 58:
#line 540 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 59:
#line 547 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 60:
#line 551 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 61:
#line 558 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 62:
#line 562 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 63:
#line 569 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 64:
#line 573 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 65:
#line 580 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 66:
#line 584 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 67:
#line 591 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 68:
#line 595 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 69:
#line 602 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 70:
#line 606 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 71:
#line 610 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 72:
#line 614 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 73:
#line 618 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 74:
#line 622 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 75:
#line 626 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 76:
#line 630 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 77:
#line 634 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 78:
#line 638 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 79:
#line 642 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 80:
#line 649 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 81:
#line 653 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 83:
#line 664 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 84:
#line 668 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 85:
#line 674 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 86:
#line 678 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 87:
#line 683 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 88:
#line 687 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 89:
#line 693 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 90:
#line 697 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 91:
#line 701 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 92:
#line 705 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 93:
#line 712 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 94:
#line 716 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 95:
#line 723 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 96:
#line 727 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 97:
#line 734 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 98:
#line 738 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 99:
#line 742 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 100:
#line 746 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 101:
#line 750 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 102:
#line 757 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 103:
#line 761 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 104:
#line 765 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 105:
#line 769 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 106:
#line 773 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 107:
#line 777 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 108:
#line 781 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 109:
#line 785 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 110:
#line 789 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 111:
#line 793 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 112:
#line 797 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 113:
#line 801 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 114:
#line 805 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 115:
#line 809 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 116:
#line 813 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 117:
#line 818 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 118:
#line 822 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 119:
#line 829 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 120:
#line 833 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 121:
#line 840 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 122:
#line 844 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 123:
#line 851 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 124:
#line 855 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 126:
#line 864 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 127:
#line 868 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 128:
#line 874 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 129:
#line 878 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 130:
#line 885 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 131:
#line 889 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 132:
#line 894 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 133:
#line 898 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 134:
#line 904 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 135:
#line 908 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 136:
#line 924 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 137:
#line 928 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 138:
#line 932 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 139:
#line 939 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 140:
#line 943 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 141:
#line 950 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 142:
#line 954 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 143:
#line 961 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 144:
#line 965 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 145:
#line 969 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 146:
#line 976 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 147:
#line 981 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 148:
#line 985 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 149:
#line 991 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 150:
#line 996 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 151:
#line 1000 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 152:
#line 1004 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 153:
#line 1008 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 154:
#line 1012 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 155:
#line 1016 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 156:
#line 1022 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 157:
#line 1026 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 158:
#line 1030 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 159:
#line 1034 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 160:
#line 1038 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 161:
#line 1042 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 162:
#line 1046 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 163:
#line 1050 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 164:
#line 1057 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 165:
#line 1061 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 166:
#line 1068 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 167:
#line 1072 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 168:
#line 1079 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 169:
#line 1083 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 170:
#line 1090 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 171:
#line 1094 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 172:
#line 1099 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 173:
#line 1103 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 174:
#line 1109 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 175:
#line 1113 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 176:
#line 1117 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 177:
#line 1124 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 178:
#line 1128 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 179:
#line 1135 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 180:
#line 1142 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 181:
#line 1146 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 182:
#line 1151 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 183:
#line 1155 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 184:
#line 1159 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 185:
#line 1163 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 186:
#line 1169 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 187:
#line 1173 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 188:
#line 1177 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 189:
#line 1181 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 190:
#line 1188 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 191:
#line 1195 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 192:
#line 1199 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 193:
#line 1203 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 194:
#line 1208 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 195:
#line 1212 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 196:
#line 1218 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 197:
#line 1222 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 198:
#line 1229 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 199:
#line 1236 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 200:
#line 1240 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 201:
#line 1247 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 202:
#line 1251 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 203:
#line 1263 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 204:
#line 1267 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 205:
#line 1271 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 206:
#line 1275 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 207:
#line 1279 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 208:
#line 1286 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 209:
#line 1290 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 210:
#line 1294 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 211:
#line 1319 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 212:
#line 1332 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 213:
#line 1336 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 214:
#line 1341 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 215:
#line 1345 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 216:
#line 1358 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 217:
#line 1362 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 218:
#line 1366 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 219:
#line 1370 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 220:
#line 1377 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 221:
#line 1381 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 222:
#line 1385 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 223:
#line 1389 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 224:
#line 1398 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 225:
#line 1402 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 226:
#line 1407 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 227:
#line 1411 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 228:
#line 1421 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 229:
#line 1428 "cbook.y"
    {
              cnt_rule();
              }
    break;

  case 230:
#line 1432 "cbook.y"
    {
              cnt_rule();
              }
    break;


    }

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
/* Line 750 of glr.c.  */
#line 3190 "y.tab.c"
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  /* `Use' the arguments.  */
  (void) yy0;
  (void) yy1;

  switch (yyn)
    {
      
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

/** Number of symbols composing the right hand side of rule #RULE. */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
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
static void
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates = (yyGLRState**) YYMALLOC (16 * sizeof yyset->yystates[0]);
  yyset->yystates[0] = NULL;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
}

/** Initialize STACK to a single empty stack, with total maximum
 *  capacity for all stacks of SIZE. */
static void
yyinitGLRStack (yyGLRStack* yystack, size_t yysize)
{
  yystack->yyerrflag = 0;
  yystack->yyerrState = 0;
  yynerrs = 0;
  yystack->yyspaceLeft = yysize;
  yystack->yynextFree = yystack->yyitems =
    (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystack->yynextFree[0]);
  yystack->yysplitPoint = NULL;
  yystack->yylastDeleted = NULL;
  yyinitStateSet (&yystack->yytops);
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
  yyGLRStack yynewStack;
  yyGLRStackItem* yyp0, *yyp1;
  size_t yysize, yynewSize;
  size_t yyn;
  yysize = yystack->yynextFree - yystack->yyitems;
  if (YYMAXDEPTH <= yysize)
    yyFail (yystack, "parser stack overflow");
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yyinitGLRStack (&yynewStack, yynewSize);
  for (yyp0 = yystack->yyitems, yyp1 = yynewStack.yyitems, yyn = yysize;
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
    yystack->yysplitPoint = YYRELOC (yystack->yyitems, yynewStack.yyitems,
				 yystack->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystack->yytops.yysize; yyn += 1)
    if (yystack->yytops.yystates[yyn] != NULL)
      yystack->yytops.yystates[yyn] =
	YYRELOC (yystack->yyitems, yynewStack.yyitems,
		 yystack->yytops.yystates[yyn], yystate);
  YYFREE (yystack->yyitems);
  yystack->yyitems = yynewStack.yyitems;
  yystack->yynextFree = yynewStack.yynextFree + yysize;
  yystack->yyspaceLeft = yynewStack.yyspaceLeft - yysize;

#else

  yyFail (yystack, "parser stack overflow");
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
yymarkStackDeleted (yyGLRStack* yystack, int yyk)
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
yyglrShift (yyGLRStack* yystack, int yyk, yyStateNum yylrState, size_t yyposn,
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
yyglrShiftDefer (yyGLRStack* yystack, int yyk, yyStateNum yylrState,
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
yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
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

static int
yysplitStack (yyGLRStack* yystack, int yyk)
{
  if (yystack->yysplitPoint == NULL)
    {
      YYASSERT (yyk == 0);
      yystack->yysplitPoint = yystack->yytops.yystates[yyk];
    }
  if (yystack->yytops.yysize >= yystack->yytops.yycapacity)
    {
      yystack->yytops.yycapacity *= 2;
      yystack->yytops.yystates =
	(yyGLRState**) YYREALLOC (yystack->yytops.yystates,
				  (yystack->yytops.yycapacity
				   * sizeof yystack->yytops.yystates[0]));
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

/** Assuming identicalOptions (Y0,Y1), (destructively) merge the
 *  alternative semantic values for the RHS-symbols of Y1 into the
 *  corresponding semantic value sets of the symbols of Y0. */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       yyn > 0;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    if (yys0 == yys1)
      break;
    else if (! yys0->yyresolved && ! yys1->yyresolved)
      {
	yySemanticOption* yyz;
	for (yyz = yys0->yysemantics.yyfirstVal; yyz->yynext != NULL;
	     yyz = yyz->yynext)
	  continue;
	yyz->yynext = yys1->yysemantics.yyfirstVal;
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
  yyFail (yystack, "ambiguity detected");
}


/** Resolve the ambiguity represented by OPTIONLIST, perform the indicated
 *  actions, and return the result. */
static YYRESULTTAG
yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
		YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yySemanticOption* yybest;
  yySemanticOption* yyp;
  int yymerge;

  yybest = yyoptionList;
  yymerge = 0;
  for (yyp = yyoptionList->yynext; yyp != NULL; yyp = yyp->yynext)
    {
      if (yyidenticalOptions (yybest, yyp))
	yymergeOptionSets (yybest, yyp);
      else
	switch (yypreference (yybest, yyp))
	  {
	  case 0:
	    yyreportAmbiguity (yybest, yyp, yystack);
	    break;
	  case 1:
	    yymerge = 1;
	    break;
	  case 2:
	    break;
	  case 3:
	    yybest = yyp;
	    yymerge = 0;
	    break;
	  }
    }

  if (yymerge)
    {
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
yyprocessOneStack (yyGLRStack* yystack, int yyk,
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
      YYDPRINTF ((stderr, "Stack %d Entering state %d\n", yyk, yystate));

      YYASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
	{
	  yyrule = yydefaultAction (yystate);
	  if (yyrule == 0)
	    {
	      YYDPRINTF ((stderr, "Stack %d dies.\n", yyk));
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
	      int yynewStack = yysplitStack (yystack, yyk);
	      YYDPRINTF ((stderr, "Splitting off stack %d from %d.\n",
			  yynewStack, yyk));
	      YYCHK (yyglrReduce (yystack, yynewStack,
				  *yyconflicts, yyfalse));
	      YYCHK (yyprocessOneStack (yystack, yynewStack, yyposn,
					yylvalp, yyllocp));
	      yyconflicts += 1;
	    }

	  if (yyisShiftAction (yyaction))
	    {
	      YYDPRINTF ((stderr, "On stack %d, ", yyk));
	      YY_SYMBOL_PRINT ("shifting", *yytokenp, yylvalp, yyllocp);
	      yyglrShift (yystack, yyk, yyaction, yyposn+1,
			  *yylvalp, yyllocp);
	      YYDPRINTF ((stderr, ", now in state #%d\n",
			  yystack->yytops.yystates[yyk]->yylrState));
	      break;
	    }
	  else if (yyisErrorAction (yyaction))
	    {
	      YYDPRINTF ((stderr, "Stack %d dies.\n", yyk));
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
	  size_t yysize = 0;
	  const char* yyprefix;
	  char* yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += strlen (yyprefix) + strlen (yytokenName (yyx));
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
		yyprefix = " or ";
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + strlen (yytokenName (*yytokenp)));
	  yymsg = (char*) YYMALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char* yyp = yymsg;
	      sprintf (yyp, "syntax error%s%s",
		       (*yytokenp == YYEMPTY ? "" : ", unexpected "),
		       yytokenName (*yytokenp));
	      yyp += strlen (yyp);
	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			sprintf (yyp, "%s%s", yyprefix, yytokenName (yyx));
			yyp += strlen (yyp);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYFREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
      yynerrs += 1;
    }
}

/* Recover from a syntax error on YYSTACK, assuming that YYTOKENP,
   YYLVALP, and YYLLOCP point to the syntactic category, semantic
   value, and location of the look-ahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystack,
		      YYSTYPE* yylvalp,
		      YYLTYPE* yyllocp ATTRIBUTE_UNUSED
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
	  {
	    /* Now pop stack until empty and fail. */
	    while (yystack->yytops.yystates[0] != NULL)
	      {
		yyGLRState *yys = yystack->yytops.yystates[0];

		yydestruct ("Error: popping",
                            yystos[yys->yylrState],
			    &yys->yysemantics.yysval);
		yystack->yytops.yystates[0] = yys->yypred;
		yystack->yynextFree -= 1;
		yystack->yyspaceLeft += 1;
	      }
	    yyFail (yystack, NULL);
	  }
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

      yydestruct ("Error: popping",
		  yystos[yys->yylrState],
	          &yys->yysemantics.yysval);
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
    default:								     \
      break;								     \
    case yyabort:							     \
      yystack.yyerrflag = 1;						     \
      goto yyDone;							     \
    case yyaccept:							     \
      yystack.yyerrflag = 0;						     \
      goto yyDone;							     \
    case yyerr:								     \
      goto yyuser_error;						     \
    }									     \
  } while (0)


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  yySymbol yytoken;
  yyGLRStack yystack;
  size_t yyposn;


  YYSTYPE* const yylvalp = &yylval;
  YYLTYPE* const yyllocp = &yylloc;

  yyinitGLRStack (&yystack, YYINITDEPTH);
  yystack.yytokenp = &yytoken;

  YYDPRINTF ((stderr, "Starting parse\n"));

  if (setjmp (yystack.yyexception_buffer) != 0)
    goto yyDone;

  yylval = yyval_default;


  yyglrShift (&yystack, 0, 0, 0, yylval, &yylloc);
  yytoken = YYEMPTY;
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
	    goto yyDone;
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
		  yyglrShift (&yystack, 0, yyaction, yyposn,
		              yylval, yyllocp);
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
	  int yys;
	  int yyn = yystack.yytops.yysize;
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
		yyFail (&yystack, "syntax error");
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
 yyDone:
  /* On YYABORT, free the lookahead. */
  if (yystack.yyerrflag == 1 && yytoken != YYEMPTY)
    yydestruct ("Error: discarding lookahead",
                yytoken, yylvalp);

  yyfreeGLRStack (&yystack);
  return yystack.yyerrflag;
}

/* DEBUGGING ONLY */
#ifdef YYDEBUG
static void yypstack (yyGLRStack* yystack, int yyk) ATTRIBUTE_UNUSED;
static void yypdumpstack (yyGLRStack* yystack) ATTRIBUTE_UNUSED;

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
yypstack (yyGLRStack* yystack, int yyk)
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


#line 1492 "cbook.y"




