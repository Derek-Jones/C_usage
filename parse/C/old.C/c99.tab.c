/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

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

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

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
     PASCAL = 343,
     FORTRAN = 344,
     ASM = 345,
     ATTRIBUTE = 346,
     TYPEOF = 347,
     ALIGNOF = 348,
     INLINE = 349,
     RESTRICT = 350,
     _BOOL = 351,
     _COMPLEX = 352,
     _IMAGINARY = 353,
     AT_ADDR = 354,
     UNDEFINED = 355
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
#define PASCAL 343
#define FORTRAN 344
#define ASM 345
#define ATTRIBUTE 346
#define TYPEOF 347
#define ALIGNOF 348
#define INLINE 349
#define RESTRICT 350
#define _BOOL 351
#define _COMPLEX 352
#define _IMAGINARY 353
#define AT_ADDR 354
#define UNDEFINED 355




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
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 287 "c99.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1125

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  87
/* YYNRULES -- Number of rules. */
#define YYNRULES  235
/* YYNRULES -- Number of states. */
#define YYNSTATES  383

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   355

#define YYTRANSLATE(YYX) 						\
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
      95,    96,    97,    98,    99,   100
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    18,    19,
      21,    23,    28,    33,    37,    41,    44,    47,    54,    62,
      64,    68,    70,    73,    76,    79,    82,    87,    89,    91,
      93,    95,    97,    99,   101,   106,   108,   112,   116,   120,
     122,   126,   130,   132,   136,   140,   142,   146,   150,   154,
     158,   160,   164,   168,   170,   174,   176,   180,   182,   186,
     188,   192,   194,   198,   200,   206,   208,   212,   214,   216,
     218,   220,   222,   224,   226,   228,   230,   232,   234,   236,
     240,   242,   243,   245,   249,   250,   252,   255,   258,   261,
     264,   266,   270,   272,   276,   278,   280,   282,   284,   286,
     288,   290,   292,   294,   296,   298,   300,   302,   304,   306,
     308,   310,   312,   314,   316,   317,   319,   325,   328,   330,
     332,   334,   337,   341,   342,   344,   347,   350,   352,   356,
     357,   359,   361,   365,   371,   378,   381,   383,   387,   389,
     393,   395,   397,   399,   401,   402,   404,   407,   408,   410,
     411,   413,   414,   416,   418,   422,   428,   435,   442,   448,
     453,   458,   461,   465,   467,   470,   472,   476,   478,   482,
     483,   485,   488,   491,   493,   497,   500,   502,   505,   506,
     508,   509,   511,   515,   520,   525,   530,   532,   534,   538,
     543,   544,   546,   549,   554,   557,   559,   562,   566,   569,
     571,   573,   575,   577,   579,   581,   585,   590,   594,   595,
     597,   601,   603,   606,   608,   610,   613,   619,   627,   633,
     634,   636,   642,   650,   660,   669,   673,   676,   679,   683,
     685,   687,   688,   690,   695,   697
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     102,     0,    -1,   184,    -1,   102,   184,    -1,    86,    -1,
      85,    -1,    87,    -1,    35,   123,    36,    -1,    -1,   106,
      -1,   103,    -1,   105,    72,   123,    73,    -1,   105,    35,
     104,    36,    -1,   105,    63,    86,    -1,   105,    64,    86,
      -1,   105,    65,    -1,   105,    66,    -1,    35,   161,    36,
      70,   169,    71,    -1,    35,   161,    36,    70,   169,    67,
      71,    -1,   121,    -1,   106,    67,   121,    -1,   105,    -1,
      65,   107,    -1,    66,   107,    -1,   108,   109,    -1,    34,
     107,    -1,    34,    35,   161,    36,    -1,    48,    -1,    43,
      -1,    39,    -1,    42,    -1,    51,    -1,    52,    -1,   107,
      -1,    35,   161,    36,   109,    -1,   109,    -1,   110,    43,
     109,    -1,   110,    46,   109,    -1,   110,    45,   109,    -1,
     110,    -1,   111,    39,   110,    -1,   111,    42,   110,    -1,
     111,    -1,   112,    37,   111,    -1,   112,    38,   111,    -1,
     112,    -1,   113,    53,   112,    -1,   113,    56,   112,    -1,
     113,    54,   112,    -1,   113,    55,   112,    -1,   113,    -1,
     114,    57,   113,    -1,   114,    58,   113,    -1,   114,    -1,
     115,    48,   114,    -1,   115,    -1,   116,    47,   115,    -1,
     116,    -1,   117,    50,   116,    -1,   117,    -1,   118,    59,
     117,    -1,   118,    -1,   119,    60,   118,    -1,   119,    -1,
     119,    61,   123,    62,   120,    -1,   120,    -1,   107,   122,
     121,    -1,    74,    -1,    77,    -1,    81,    -1,    82,    -1,
      75,    -1,    76,    -1,    78,    -1,    79,    -1,    80,    -1,
      83,    -1,    84,    -1,   121,    -1,   123,    67,   121,    -1,
     120,    -1,    -1,   129,    -1,   128,   125,    68,    -1,    -1,
     128,    -1,   131,   127,    -1,   132,   127,    -1,   146,   127,
      -1,   147,   127,    -1,   130,    -1,   129,    67,   130,    -1,
     149,    -1,   149,    74,   167,    -1,     7,    -1,     5,    -1,
       4,    -1,     3,    -1,     6,    -1,    16,    -1,     8,    -1,
      12,    -1,    11,    -1,    13,    -1,     9,    -1,    10,    -1,
      15,    -1,    14,    -1,    96,    -1,    97,    -1,    98,    -1,
     134,    -1,   143,    -1,   166,    -1,    -1,    86,    -1,   135,
     133,    70,   136,    71,    -1,   135,    86,    -1,    19,    -1,
      20,    -1,   137,    -1,   136,   137,    -1,   139,   140,    68,
      -1,    -1,   139,    -1,   132,   138,    -1,   146,   138,    -1,
     142,    -1,   140,    67,   142,    -1,    -1,   149,    -1,   149,
      -1,   141,    62,   124,    -1,    21,   133,    70,   144,    71,
      -1,    21,   133,    70,   144,    67,    71,    -1,    21,    86,
      -1,   145,    -1,   144,    67,   145,    -1,    86,    -1,    86,
      74,   124,    -1,    17,    -1,    95,    -1,    18,    -1,    94,
      -1,    -1,   154,    -1,   148,   153,    -1,    -1,   155,    -1,
      -1,   121,    -1,    -1,   160,    -1,    86,    -1,    35,   149,
      36,    -1,   153,    72,   150,   151,    73,    -1,   153,    72,
       4,   150,   121,    73,    -1,   153,    72,   155,     4,   121,
      73,    -1,   153,    72,   150,    43,    73,    -1,   153,    35,
     156,    36,    -1,   153,    35,   152,    36,    -1,    43,   150,
      -1,    43,   150,   154,    -1,   146,    -1,   155,   146,    -1,
     157,    -1,   157,    67,    69,    -1,   159,    -1,   157,    67,
     159,    -1,    -1,   162,    -1,   128,   149,    -1,   128,   158,
      -1,    86,    -1,   160,    67,    86,    -1,   139,   158,    -1,
     154,    -1,   148,   165,    -1,    -1,   165,    -1,    -1,   156,
      -1,    35,   162,    36,    -1,   163,    72,   151,    73,    -1,
     163,    72,    43,    73,    -1,   163,    35,   164,    36,    -1,
      86,    -1,   121,    -1,    70,   169,    71,    -1,    70,   169,
      67,    71,    -1,    -1,   170,    -1,   168,   167,    -1,   169,
      67,   168,   167,    -1,   171,    74,    -1,   172,    -1,   171,
     172,    -1,    72,   124,    73,    -1,    63,    86,    -1,   174,
      -1,   176,    -1,   179,    -1,   180,    -1,   182,    -1,   183,
      -1,    86,    62,   173,    -1,    28,   124,    62,   173,    -1,
      29,    62,   173,    -1,    -1,   177,    -1,    70,   175,    71,
      -1,   178,    -1,   177,   178,    -1,   126,    -1,   173,    -1,
     181,    68,    -1,    22,    35,   123,    36,   173,    -1,    22,
      35,   123,    36,   173,    23,   173,    -1,    27,    35,   123,
      36,   173,    -1,    -1,   123,    -1,    24,    35,   123,    36,
     173,    -1,    26,   173,    24,    35,   123,    36,    68,    -1,
      25,    35,   181,    68,   181,    68,   181,    36,   173,    -1,
      25,    35,   126,   181,    68,   181,    36,   173,    -1,    33,
      86,    68,    -1,    31,    68,    -1,    30,    68,    -1,    32,
     181,    68,    -1,   186,    -1,   126,    -1,    -1,   187,    -1,
     128,   149,   185,   176,    -1,   126,    -1,   187,   126,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   278,   278,   279,   285,   286,   287,   288,   290,   291,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   306,
     307,   311,   312,   313,   314,   315,   316,   320,   321,   322,
     323,   324,   325,   329,   330,   334,   335,   336,   337,   341,
     342,   343,   347,   348,   349,   353,   354,   355,   356,   357,
     361,   362,   363,   367,   368,   372,   373,   377,   378,   382,
     383,   387,   388,   392,   393,   397,   398,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   416,   417,
     421,   425,   426,   429,   431,   432,   435,   436,   437,   438,
     442,   443,   447,   448,   452,   453,   454,   455,   456,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   476,   477,   481,   482,   486,   487,
     491,   492,   496,   498,   499,   502,   503,   507,   508,   510,
     511,   514,   515,   519,   520,   521,   525,   526,   530,   531,
     535,   536,   537,   541,   543,   544,   547,   549,   550,   551,
     552,   553,   554,   557,   558,   559,   560,   561,   562,   563,
     564,   568,   569,   573,   574,   578,   579,   583,   584,   586,
     587,   590,   591,   595,   596,   600,   604,   605,   607,   608,
     609,   610,   613,   614,   615,   616,   620,   624,   625,   626,
     628,   629,   632,   633,   637,   641,   642,   646,   647,   653,
     654,   655,   656,   657,   658,   662,   663,   664,   666,   667,
     670,   674,   675,   679,   680,   684,   688,   689,   690,   692,
     693,   697,   698,   699,   700,   704,   705,   706,   707,   713,
     714,   716,   717,   720,   724,   725
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "STATIC", "EXTERN", "REGISTER", 
  "TYPEDEF", "CHAR", "FLOAT", "DOUBLE", "INT", "SHORT", "LONG", 
  "UNSIGNED", "SIGNED", "VOID", "CONST", "VOLATILE", "STRUCT", "UNION", 
  "ENUM", "IF", "ELSE", "WHILE", "FOR", "DO", "SWITCH", "CASE", "DEFAULT", 
  "BREAK", "CONTINUE", "RETURN", "GOTO", "SIZEOF", "OPEN_RND", 
  "CLOSE_RND", "LEFTSHIFT", "RIGHTSHIFT", "PLUS", "ADD", "NEGATE", 
  "MINUS", "STAR", "TIMES", "REMAINDER", "DIVIDE", "XOR", "AND", "BITAND", 
  "OR", "BITNEGATE", "NOT", "LT", "LE", "GE", "GT", "EQUAL", "NOTEQUAL", 
  "ANDTEST", "ORTEST", "QUESTION", "COLON", "DOT", "DEREF", "PLUSPLUS", 
  "MINUSMINUS", "COMMA", "SEMICOLON", "ELLIPSIS", "OPEN_CURL", 
  "CLOSE_CURL", "OPEN_SQUARE", "CLOSE_SQUARE", "ASSIGN", "PLUSASSIGN", 
  "MINUSASSIGN", "TIMESASSIGN", "LSASSIGN", "RSASSIGN", "ANDASSIGN", 
  "DIVASSIGN", "REMASSIGN", "ORASSIGN", "NOTASSIGN", "CONSTANT", 
  "IDENTIFIER", "STRING_LITERAL", "PASCAL", "FORTRAN", "ASM", "ATTRIBUTE", 
  "TYPEOF", "ALIGNOF", "INLINE", "RESTRICT", "_BOOL", "_COMPLEX", 
  "_IMAGINARY", "AT_ADDR", "UNDEFINED", "$accept", "translation_unit", 
  "primary_expr", "argument_expr_list_opt", "postfix_expr", 
  "argument_expr_list", "unary_expr", "unary_operator", "cast_expr", 
  "multiplicative_expr", "additive_expr", "shift_expr", "relational_expr", 
  "equality_expr", "AND_expr", "exclusive_OR_expr", "inclusive_OR_expr", 
  "logical_AND_expr", "logical_OR_expr", "conditional_expr", 
  "assignment_expr", "assignment_operator", "expression", "constant_expr", 
  "init_declarator_list_opt", "declaration", "declaration_specifiers_opt", 
  "declaration_specifiers", "init_declarator_list", "init_declarator", 
  "storage_class_specifier", "type_specifier", "identifier_opt", 
  "struct_or_union_specifier", "struct_or_union", 
  "struct_declaration_list", "struct_declaration", 
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
  "block_item_list_opt", "compound_statement", "block_item_list", 
  "block_item", "expression_statement", "selection_statement", "expr_opt", 
  "iteration_statement", "jump_statement", "external_declaration", 
  "declaration_list_opt", "function_definition", "declaration_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   101,   102,   102,   103,   103,   103,   103,   104,   104,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   106,
     106,   107,   107,   107,   107,   107,   107,   108,   108,   108,
     108,   108,   108,   109,   109,   110,   110,   110,   110,   111,
     111,   111,   112,   112,   112,   113,   113,   113,   113,   113,
     114,   114,   114,   115,   115,   116,   116,   117,   117,   118,
     118,   119,   119,   120,   120,   121,   121,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   123,   123,
     124,   125,   125,   126,   127,   127,   128,   128,   128,   128,
     129,   129,   130,   130,   131,   131,   131,   131,   131,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   133,   133,   134,   134,   135,   135,
     136,   136,   137,   138,   138,   139,   139,   140,   140,   141,
     141,   142,   142,   143,   143,   143,   144,   144,   145,   145,
     146,   146,   146,   147,   148,   148,   149,   150,   150,   151,
     151,   152,   152,   153,   153,   153,   153,   153,   153,   153,
     153,   154,   154,   155,   155,   156,   156,   157,   157,   158,
     158,   159,   159,   160,   160,   161,   162,   162,   163,   163,
     164,   164,   165,   165,   165,   165,   166,   167,   167,   167,
     168,   168,   169,   169,   170,   171,   171,   172,   172,   173,
     173,   173,   173,   173,   173,   174,   174,   174,   175,   175,
     176,   177,   177,   178,   178,   179,   180,   180,   180,   181,
     181,   182,   182,   182,   182,   183,   183,   183,   183,   184,
     184,   185,   185,   186,   187,   187
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     0,     1,
       1,     4,     4,     3,     3,     2,     2,     6,     7,     1,
       3,     1,     2,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     0,     1,     3,     0,     1,     2,     2,     2,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     5,     2,     1,     1,
       1,     2,     3,     0,     1,     2,     2,     1,     3,     0,
       1,     1,     3,     5,     6,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     0,     1,     2,     0,     1,     0,
       1,     0,     1,     1,     3,     5,     6,     6,     5,     4,
       4,     2,     3,     1,     2,     1,     3,     1,     3,     0,
       1,     2,     2,     1,     3,     2,     1,     2,     0,     1,
       0,     1,     3,     4,     4,     4,     1,     1,     3,     4,
       0,     1,     2,     4,     2,     1,     2,     3,     2,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     0,     1,
       3,     1,     2,     1,     1,     2,     5,     7,     5,     0,
       1,     5,     7,     9,     8,     3,     2,     2,     3,     1,
       1,     0,     1,     4,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,    97,    96,    95,    98,    94,   100,   104,   105,   102,
     101,   103,   107,   106,    99,   140,   142,   118,   119,   114,
     186,   143,   141,   108,   109,   110,     0,   230,   144,    84,
      84,   111,   114,   112,    84,    84,   113,     2,   229,   135,
       0,     1,     3,   147,     0,    82,    90,     0,    92,   145,
      86,    85,    87,   117,     0,    88,    89,     0,   163,   161,
     148,    83,   144,   144,   153,   146,     0,   234,   144,     0,
     232,     0,   138,     0,   136,   162,   164,    91,    92,     0,
     151,   147,     0,     0,    29,    30,    28,    27,    31,    32,
       0,     0,   190,     5,     4,     6,    10,    21,    33,     0,
      35,    39,    42,    45,    50,    53,    55,    57,    59,    61,
      63,    65,   187,    93,   208,   233,   235,   123,     0,   120,
     144,   123,     0,     0,   133,   154,   186,   144,     0,     0,
     165,   167,   152,   147,   149,   148,     0,    25,     4,    78,
       0,   144,     0,     0,    22,    23,     0,     0,     0,     0,
     191,     0,   195,     8,     0,     0,    15,    16,     0,    67,
      71,    72,    68,    73,    74,    75,    69,    70,    76,    77,
       0,    33,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,     0,     0,     0,     0,
       0,   219,     0,     4,   220,   213,   214,   199,     0,   200,
     209,   211,   201,   202,     0,   203,   204,   125,   124,   116,
     121,     0,     0,   127,   131,   126,    80,   139,   134,   137,
     178,   171,   145,   172,   170,   160,   159,     0,     0,     0,
      28,   150,     0,     0,     0,     7,     0,   178,   175,     0,
       0,   198,     0,   192,   190,   188,   194,   196,     0,     9,
      19,    13,    14,     0,    66,    36,    38,    37,    40,    41,
      43,    44,    46,    48,    49,    47,    51,    52,    54,    56,
      58,    60,    62,     0,     0,     0,   219,     4,     0,     0,
       0,   219,   227,   226,     0,     0,   219,   210,   212,   215,
     144,   122,     0,   144,     0,   177,   166,   168,   174,     0,
     158,   155,     0,    26,    79,   144,   190,    34,     0,   197,
     189,     0,    12,     0,    11,     0,     0,     0,   219,     0,
       0,     0,   219,   207,   228,   225,   205,   128,   132,     0,
     180,   149,   156,   157,     0,   193,    20,    64,   219,   219,
       0,   219,     0,   219,   206,   182,   181,     0,    28,     0,
     190,    17,   216,   221,   219,     0,     0,   218,   185,   184,
     183,    18,   219,     0,   219,     0,   217,   219,     0,   222,
     224,   219,   223
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,    26,    96,   258,    97,   259,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     139,   170,   204,   227,    44,    27,    50,    68,    45,    46,
      29,    30,    40,    31,    32,   118,   119,   217,   141,   221,
     222,   223,    33,    73,    74,    34,    35,    47,    78,    59,
     242,   128,    65,    49,    60,   129,   130,   233,   131,   132,
     142,   234,   304,   357,   305,    36,   113,   148,   149,   150,
     151,   152,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    37,    69,    38,    70
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -285
static const short yypact[] =
{
     667,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,   -61,
    -285,  -285,  -285,  -285,  -285,  -285,   305,  -285,     9,   667,
     667,  -285,   -42,  -285,   667,   667,  -285,  -285,  -285,    -2,
      15,  -285,  -285,    48,   104,    43,  -285,   -24,   533,  -285,
    -285,  -285,  -285,    -2,    66,  -285,  -285,   102,  -285,   149,
      48,  -285,   149,   149,  -285,   -23,   426,  -285,     9,   133,
     667,   887,   132,   -28,  -285,  -285,  -285,  -285,   134,   165,
     686,     5,   926,   796,  -285,  -285,  -285,  -285,  -285,  -285,
     954,   954,    70,  -285,  -285,  -285,  -285,    10,   212,   982,
    -285,   130,   114,   131,   172,   122,   166,   174,   173,   175,
     125,  -285,  -285,  -285,   341,  -285,  -285,   887,   855,  -285,
      -5,   887,   982,   -35,  -285,  -285,    17,    12,   197,   200,
     179,  -285,   182,    48,  1010,    42,   796,  -285,   705,  -285,
      25,    55,   204,   796,  -285,  -285,   155,   982,   426,    80,
    -285,    83,  -285,   982,   156,   167,  -285,  -285,   982,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
     982,  -285,  -285,   982,   982,   982,   982,   982,   982,   982,
     982,   982,   982,   982,   982,   982,   982,   982,   982,   982,
     982,   982,   215,   216,   217,   708,   219,   982,   193,   189,
     191,   982,   176,   552,   194,  -285,  -285,  -285,   192,  -285,
     341,  -285,  -285,  -285,   196,  -285,  -285,  -285,  -285,  -285,
    -285,   145,   203,  -285,   206,  -285,  -285,  -285,  -285,  -285,
     -19,  -285,    45,  -285,  -285,  -285,  -285,   571,   180,   982,
     198,  -285,   202,   982,   233,  -285,   982,   235,  -285,   877,
     237,  -285,   205,  -285,   127,  -285,  -285,  -285,   243,   213,
    -285,  -285,  -285,    20,  -285,  -285,  -285,  -285,   130,   130,
     114,   114,   131,   131,   131,   131,   172,   172,   122,   166,
     174,   173,   175,   -20,   982,   982,   437,   221,   260,   982,
     236,   708,  -285,  -285,   234,   238,   708,  -285,  -285,  -285,
      -5,  -285,   982,   149,   -22,   -18,  -285,  -285,  -285,   228,
    -285,  -285,   230,   257,  -285,   149,    70,  -285,   257,  -285,
    -285,   426,  -285,   982,  -285,   982,    68,    71,   982,   261,
     269,    73,   708,  -285,  -285,  -285,  -285,  -285,  -285,   292,
     667,  1038,  -285,  -285,    99,  -285,  -285,  -285,   708,   708,
     262,   982,   982,   708,  -285,  -285,  -285,   295,   259,   263,
     139,  -285,   310,  -285,   982,   266,    78,  -285,  -285,  -285,
    -285,  -285,   708,   299,   982,   270,  -285,   708,   301,  -285,
    -285,   708,  -285
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -285,  -285,  -285,  -285,  -285,  -285,   -58,  -285,   -78,    40,
      41,    49,    54,   153,   154,   190,   188,   152,  -285,  -107,
     -65,  -285,   -80,  -139,  -285,   -43,   124,     0,  -285,   281,
    -285,    79,   332,  -285,  -285,  -285,   264,   258,    31,  -285,
    -285,    81,  -285,  -285,   265,   164,  -285,  -121,   -26,   -63,
      44,  -285,  -285,   -55,   306,    46,  -285,   249,   157,  -285,
     -30,  -284,  -285,  -285,  -285,  -285,  -138,  -226,    82,  -285,
    -285,   244,  -188,  -285,  -285,   327,  -285,   187,  -285,  -285,
    -187,  -285,  -285,   378,  -285,  -285,  -285
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -232
static const short yytable[] =
{
      28,   112,    48,   140,    75,    67,   230,   288,   252,   133,
     253,    63,    80,   340,   294,   226,   303,  -179,   134,   339,
     247,   172,    15,    16,   137,    39,    28,   116,   321,    51,
      51,   339,   144,   145,    51,    51,   228,    79,    43,   123,
     226,   171,   325,   124,    53,   153,   243,   246,  -169,    81,
     341,    72,    43,  -173,  -179,    43,   140,  -129,   290,    15,
      16,   245,    64,   140,   171,    15,    16,    64,  -115,   241,
     239,   205,   232,   154,   155,   156,   157,   -81,   263,  -169,
     127,  -176,   158,   112,  -173,    57,   232,   246,   260,   171,
     226,  -169,   246,   324,   224,   265,   266,   267,    43,   329,
      22,   231,   120,   333,   348,   264,   244,   349,   336,   353,
      62,   283,  -176,   250,   375,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   146,   321,   246,    71,    22,   246,   171,
     246,   350,   147,    22,   354,   246,   146,   254,   218,   120,
     117,   255,   218,   176,    52,   147,   177,   256,    55,    56,
     362,   363,   117,   338,   365,   367,   360,   205,   178,   179,
     361,   317,    61,   173,   309,   174,   175,   373,   312,   184,
     185,   314,   230,   345,   376,   190,   191,   378,    72,   380,
     146,   171,    43,   382,   247,   226,   117,   117,   320,   147,
     117,   125,   146,   114,   326,   327,   122,    58,    66,   331,
     371,   147,   300,   301,   186,   117,   268,   269,   347,   270,
     271,   187,   117,   188,    76,   180,   181,   182,   183,   272,
     273,   274,   275,   235,   189,   121,   236,   127,   276,   277,
     249,   251,   261,   328,   171,    58,   237,   121,   232,   238,
     284,   285,   286,   262,   289,   291,   112,   292,   346,   293,
     232,   246,   295,   297,   299,   302,   308,   171,  -130,   313,
     315,   310,   366,   318,   224,   311,   241,    79,   319,   322,
     323,   121,   121,   296,   330,   121,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    58,   332,    76,
     121,   342,   334,   343,   352,    41,   335,   121,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   316,   355,   351,
     364,   368,   369,   372,   374,   377,   370,   381,   379,   278,
     127,   279,   282,    77,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   192,    54,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,    82,    83,   281,   280,   225,
      84,   337,   220,    85,    86,   359,   356,   135,   229,    87,
     248,    20,    88,    89,   307,   257,   115,   298,   344,    21,
      22,    23,    24,    25,    42,     0,    90,    91,     0,  -219,
       0,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,   203,    95,     0,
       0,     0,     0,     0,     0,    21,    22,    23,    24,    25,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      82,    83,     0,     0,     0,    84,     0,     0,    85,    86,
       0,    82,    83,     0,    87,     0,    84,    88,    89,    85,
      86,     0,     0,     0,     0,    87,     0,     0,    88,    89,
       0,    90,    91,     0,     0,     0,    92,     0,     0,     0,
       0,     0,    90,    91,     0,     0,     0,     0,     0,     0,
       0,    93,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,    93,   138,    95,     0,     0,     0,     0,     0,
       0,    21,    22,    23,    24,    25,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -231,     0,     0,     0,    66,     0,     0,
       0,     0,     0,     0,   296,     0,     0,     0,     0,    20,
       0,     0,     0,     0,     0,     0,     0,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,  -186,     0,
     306,     0,     0,     0,     0,     0,  -186,  -186,  -186,  -186,
    -186,     0,     0,     0,     0,     0,     0,    20,     0,     0,
       0,     0,     0,     0,     0,    21,    22,    23,    24,    25,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,     0,     0,     0,
     192,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,    82,    83,     0,     0,     0,    84,     0,     0,
      85,    86,     0,    20,     0,     0,    87,     0,     0,    88,
      89,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,   126,    90,    91,     0,     0,     0,   114,     0,
      21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
       0,  -186,     0,    93,   287,    95,     0,     0,     0,  -186,
    -186,  -186,  -186,  -186,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,    83,     0,     0,     0,    84,     0,     0,    85,    86,
       0,     0,     0,     0,    87,     0,     0,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     0,     0,     0,
       0,    93,   138,    95,     0,     0,     0,     0,     0,     0,
       0,    22,    23,    24,    25,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
       0,    82,    83,     0,     0,     0,    84,     0,     0,    85,
      86,     0,     0,     0,     0,    87,   219,     0,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    90,    91,     0,     0,     0,   316,     0,     0,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
      82,   136,    93,    94,    95,    84,     0,     0,    85,    86,
       0,     0,     0,    20,    87,     0,     0,    88,    89,     0,
       0,     0,    22,    23,    24,    25,     0,     0,    82,   143,
       0,    90,    91,    84,     0,     0,    85,    86,     0,     0,
       0,     0,    87,     0,     0,    88,    89,     0,     0,     0,
       0,    93,    94,    95,     0,     0,    82,    83,     0,    90,
      91,    84,     0,     0,    85,    86,     0,     0,     0,     0,
      87,     0,     0,    88,    89,     0,     0,     0,     0,    93,
      94,    95,     0,     0,    82,    83,     0,    90,    91,    84,
       0,     0,    85,   240,     0,     0,     0,     0,    87,     0,
       0,    88,    89,     0,     0,     0,     0,    93,    94,    95,
       0,     0,    82,    83,     0,    90,    91,    84,     0,     0,
      85,   358,     0,     0,     0,     0,    87,     0,     0,    88,
      89,     0,     0,     0,     0,    93,    94,    95,     0,     0,
       0,     0,     0,    90,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,    94,    95
};

static const short yycheck[] =
{
       0,    66,    28,    83,    59,    48,   127,   195,   147,     4,
     148,    35,    35,    35,   201,   122,    35,    35,    81,   303,
     141,    99,    17,    18,    82,    86,    26,    70,   254,    29,
      30,   315,    90,    91,    34,    35,    71,    63,    43,    67,
     147,    99,    62,    71,    86,    35,     4,    67,    36,    72,
      72,    86,    43,    36,    72,    43,   136,    62,   197,    17,
      18,    36,    86,   143,   122,    17,    18,    86,    70,   134,
     133,   114,   127,    63,    64,    65,    66,    68,   158,    67,
      80,    36,    72,   148,    67,    70,   141,    67,   153,   147,
     197,    36,    67,    73,   120,   173,   174,   175,    43,   286,
      95,   127,    71,   291,    36,   170,   136,    36,   296,    36,
      67,   191,    67,   143,    36,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    63,   360,    67,    70,    95,    67,   197,
      67,   328,    72,    95,   332,    67,    63,    67,   117,   118,
      71,    71,   121,    39,    30,    72,    42,    74,    34,    35,
     348,   349,    83,   302,   351,   353,    67,   210,    37,    38,
      71,   249,    68,    43,   239,    45,    46,   364,   243,    57,
      58,   246,   303,   321,   372,    60,    61,   374,    86,   377,
      63,   249,    43,   381,   315,   302,   117,   118,    71,    72,
     121,    36,    63,    70,   284,   285,    74,    43,    74,   289,
      71,    72,    67,    68,    48,   136,   176,   177,   325,   178,
     179,    47,   143,    50,    60,    53,    54,    55,    56,   180,
     181,   182,   183,    36,    59,    71,    36,   237,   184,   185,
      36,    86,    86,   286,   302,    81,    67,    83,   303,    67,
      35,    35,    35,    86,    35,    62,   321,    68,   323,    68,
     315,    67,    86,    71,    68,    62,    86,   325,    62,    36,
      35,    73,   352,    36,   300,    73,   341,   303,    73,    36,
      67,   117,   118,    62,    24,   121,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,   133,    62,   135,
     136,    73,    68,    73,    35,     0,    68,   143,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    70,    36,    68,
      68,    36,    73,    23,    68,    36,    73,    36,    68,   186,
     340,   187,   190,    62,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    32,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   189,   188,   121,
      39,   300,   118,    42,    43,   341,   340,    81,   123,    48,
     141,    86,    51,    52,   237,   151,    69,   210,   316,    94,
      95,    96,    97,    98,    26,    -1,    65,    66,    -1,    68,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      34,    35,    -1,    -1,    -1,    39,    -1,    -1,    42,    43,
      -1,    34,    35,    -1,    48,    -1,    39,    51,    52,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      -1,    65,    66,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      22,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,
      42,    43,    -1,    86,    -1,    -1,    48,    -1,    -1,    51,
      52,    94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    65,    66,    -1,    -1,    -1,    70,    -1,
      94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    85,    86,    87,    -1,    -1,    -1,    94,
      95,    96,    97,    98,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    -1,    -1,    39,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    98,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    71,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    65,    66,    -1,    -1,    -1,    70,    -1,    -1,
      95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    85,    86,    87,    39,    -1,    -1,    42,    43,
      -1,    -1,    -1,    86,    48,    -1,    -1,    51,    52,    -1,
      -1,    -1,    95,    96,    97,    98,    -1,    -1,    34,    35,
      -1,    65,    66,    39,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    85,    86,    87,    -1,    -1,    34,    35,    -1,    65,
      66,    39,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    85,
      86,    87,    -1,    -1,    34,    35,    -1,    65,    66,    39,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    51,    52,    -1,    -1,    -1,    -1,    85,    86,    87,
      -1,    -1,    34,    35,    -1,    65,    66,    39,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    87
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      86,    94,    95,    96,    97,    98,   102,   126,   128,   131,
     132,   134,   135,   143,   146,   147,   166,   184,   186,    86,
     133,     0,   184,    43,   125,   129,   130,   148,   149,   154,
     127,   128,   127,    86,   133,   127,   127,    70,   146,   150,
     155,    68,    67,    35,    86,   153,    74,   126,   128,   185,
     187,    70,    86,   144,   145,   154,   146,   130,   149,   149,
      35,    72,    34,    35,    39,    42,    43,    48,    51,    52,
      65,    66,    70,    85,    86,    87,   103,   105,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   167,    70,   176,   126,   132,   136,   137,
     139,   146,    74,    67,    71,    36,    86,   128,   152,   156,
     157,   159,   160,     4,   150,   155,    35,   107,    86,   121,
     123,   139,   161,    35,   107,   107,    63,    72,   168,   169,
     170,   171,   172,    35,    63,    64,    65,    66,    72,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
     122,   107,   109,    43,    45,    46,    39,    42,    37,    38,
      53,    54,    55,    56,    57,    58,    48,    47,    50,    59,
      60,    61,    22,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    86,   123,   126,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   138,   139,    71,
     137,   140,   141,   142,   149,   138,   120,   124,    71,   145,
     148,   149,   154,   158,   162,    36,    36,    67,    67,   150,
      43,   121,   151,     4,   161,    36,    67,   148,   158,    36,
     161,    86,   124,   167,    67,    71,    74,   172,   104,   106,
     121,    86,    86,   123,   121,   109,   109,   109,   110,   110,
     111,   111,   112,   112,   112,   112,   113,   113,   114,   115,
     116,   117,   118,   123,    35,    35,    35,    86,   173,    35,
     124,    62,    68,    68,   181,    86,    62,    71,   178,    68,
      67,    68,    62,    35,   163,   165,    69,   159,    86,   121,
      73,    73,   121,    36,   121,    35,    70,   109,    36,    73,
      71,   168,    36,    67,    73,    62,   123,   123,   126,   181,
      24,   123,    62,   173,    68,    68,   173,   142,   124,   162,
      35,    72,    73,    73,   169,   167,   121,   120,    36,    36,
     181,    68,    35,    36,   173,    36,   156,   164,    43,   151,
      67,    71,   173,   173,    68,   181,   123,   173,    36,    73,
      73,    71,    23,   181,    68,    36,   173,    36,   181,    68,
     173,    36,   173
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1

/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
      
    }

/* Line 991 of yacc.c.  */
#line 1723 "c99.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab2;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:

  /* Suppress GCC warning that yyerrlab1 is unused when no action
     invokes YYERROR.  */
#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
  __attribute__ ((__unused__))
#endif


  goto yyerrlab2;


/*---------------------------------------------------------------.
| yyerrlab2 -- pop states until the error token can be shifted.  |
`---------------------------------------------------------------*/
yyerrlab2:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 783 "c99.y"




