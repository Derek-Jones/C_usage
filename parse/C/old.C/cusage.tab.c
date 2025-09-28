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
     LEFTSHIFT = 291,
     RIGHTSHIFT = 292,
     PLUS = 293,
     ADD = 294,
     NEGATE = 295,
     MINUS = 296,
     STAR = 297,
     TIMES = 298,
     REMAINDER = 299,
     DIVIDE = 300,
     XOR = 301,
     AND = 302,
     BITAND = 303,
     OR = 304,
     BITNEGATE = 305,
     NOT = 306,
     LT = 307,
     LE = 308,
     GE = 309,
     GT = 310,
     EQUAL = 311,
     NOTEQUAL = 312,
     ANDTEST = 313,
     ORTEST = 314,
     QUESTION = 315,
     COLON = 316,
     CLOSE_RND = 317,
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
     LITERAL = 340,
     IDENTIFIER = 341,
     TYPEDEFNAME = 342,
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
     EMBED_SQL_HERMAPH = 355,
     EMBED_SQL_DECL = 356,
     EMBED_SQL_STMT = 357,
     UNDEFINED = 358
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
#define LEFTSHIFT 291
#define RIGHTSHIFT 292
#define PLUS 293
#define ADD 294
#define NEGATE 295
#define MINUS 296
#define STAR 297
#define TIMES 298
#define REMAINDER 299
#define DIVIDE 300
#define XOR 301
#define AND 302
#define BITAND 303
#define OR 304
#define BITNEGATE 305
#define NOT 306
#define LT 307
#define LE 308
#define GE 309
#define GT 310
#define EQUAL 311
#define NOTEQUAL 312
#define ANDTEST 313
#define ORTEST 314
#define QUESTION 315
#define COLON 316
#define CLOSE_RND 317
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
#define LITERAL 340
#define IDENTIFIER 341
#define TYPEDEFNAME 342
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
#define EMBED_SQL_HERMAPH 355
#define EMBED_SQL_DECL 356
#define EMBED_SQL_STMT 357
#define UNDEFINED 358




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
#line 293 "cusage.tab.c"

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
#define YYFINAL  131
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1106

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  104
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  127
/* YYNRULES -- Number of rules. */
#define YYNRULES  290
/* YYNRULES -- Number of states. */
#define YYNSTATES  438

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   358

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
      95,    96,    97,    98,    99,   100,   101,   102,   103
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    14,    18,    19,
      22,    25,    29,    32,    35,    39,    42,    43,    46,    48,
      50,    52,    54,    57,    59,    62,    64,    68,    70,    72,
      76,    78,    81,    84,    85,    87,    89,    91,    94,    96,
      98,   100,   102,   104,   106,   108,   110,   112,   115,   117,
     122,   127,   129,   131,   133,   135,   137,   139,   141,   143,
     145,   147,   149,   151,   153,   155,   157,   159,   161,   163,
     166,   168,   170,   173,   176,   179,   181,   185,   189,   193,
     196,   198,   201,   204,   206,   209,   213,   215,   217,   220,
     222,   225,   228,   230,   235,   239,   242,   244,   247,   249,
     253,   255,   258,   261,   265,   269,   273,   275,   277,   281,
     286,   289,   293,   295,   298,   300,   303,   306,   308,   311,
     313,   316,   318,   322,   324,   327,   329,   332,   334,   337,
     341,   344,   346,   348,   351,   355,   359,   362,   366,   371,
     375,   380,   382,   385,   388,   389,   391,   393,   395,   399,
     401,   405,   407,   411,   412,   417,   419,   424,   431,   440,
     451,   454,   458,   459,   461,   463,   467,   472,   474,   478,
     480,   483,   485,   487,   490,   493,   497,   499,   501,   503,
     506,   508,   510,   512,   514,   516,   518,   523,   527,   529,
     534,   536,   539,   543,   545,   550,   556,   562,   569,   571,
     576,   579,   583,   586,   590,   593,   597,   599,   601,   603,
     605,   610,   614,   619,   623,   627,   630,   634,   637,   639,
     641,   643,   648,   651,   656,   659,   662,   665,   668,   671,
     674,   676,   678,   680,   682,   684,   686,   690,   692,   695,
     697,   701,   703,   705,   707,   709,   713,   715,   717,   719,
     723,   725,   727,   729,   733,   735,   737,   739,   741,   743,
     747,   749,   751,   753,   757,   759,   763,   765,   769,   771,
     775,   777,   781,   783,   789,   791,   795,   797,   799,   801,
     803,   805,   807,   809,   811,   813,   815,   817,   819,   821,
     825
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     105,     0,    -1,   106,    -1,   186,    -1,   110,    -1,   107,
      -1,   122,    68,    -1,   122,   173,    68,    -1,    -1,   108,
      69,    -1,   108,   111,    -1,   122,   155,   108,    -1,   109,
      70,    -1,   123,    68,    -1,   123,   175,    68,    -1,   123,
     172,    -1,    -1,   113,   137,    -1,   113,    -1,    42,    -1,
      47,    -1,   115,    -1,   115,   127,    -1,   116,    -1,   117,
     116,    -1,   119,    -1,   119,    67,    69,    -1,    69,    -1,
     121,    -1,   119,    67,   121,    -1,   118,    -1,   123,   154,
      -1,   123,   172,    -1,    -1,   123,    -1,   124,    -1,   125,
      -1,   124,   125,    -1,   126,    -1,   128,    -1,     3,    -1,
       4,    -1,     5,    -1,     6,    -1,     7,    -1,    94,    -1,
     130,    -1,   127,   130,    -1,    87,    -1,    92,    35,   228,
      62,    -1,    92,    35,   112,    62,    -1,   130,    -1,   129,
      -1,   136,    -1,   146,    -1,     8,    -1,     9,    -1,    10,
      -1,    11,    -1,    12,    -1,    13,    -1,    14,    -1,    15,
      -1,    16,    -1,    88,    -1,    89,    -1,   131,    -1,    17,
      -1,    18,    -1,    99,    86,    -1,    19,    -1,    20,    -1,
     132,    86,    -1,   133,    70,    -1,   132,    70,    -1,   133,
      -1,   135,   114,    71,    -1,   134,   114,    71,    -1,   123,
     174,    68,    -1,   154,    61,    -1,   154,    -1,    61,   228,
      -1,   138,   228,    -1,   148,    -1,   140,   148,    -1,   140,
      67,   148,    -1,   142,    -1,   140,    -1,   140,    67,    -1,
      21,    -1,   143,    86,    -1,   144,    70,    -1,   144,    -1,
     143,    70,   141,    71,    -1,   145,   141,    71,    -1,    86,
      74,    -1,    86,    -1,   147,   228,    -1,    86,    -1,   149,
      67,    86,    -1,    86,    -1,   153,    35,    -1,   151,    62,
      -1,    35,   154,    62,    -1,   151,   149,    62,    -1,   151,
     120,    62,    -1,   150,    -1,   152,    -1,   153,    72,    73,
      -1,   153,    72,   225,    73,    -1,   153,   176,    -1,   117,
     153,   176,    -1,   152,    -1,   117,   152,    -1,   154,    -1,
     154,    74,    -1,    99,   225,    -1,   160,    -1,   160,   158,
      -1,   156,    -1,   157,   164,    -1,   164,    -1,   161,    67,
     164,    -1,    70,    -1,   165,    71,    -1,   228,    -1,   162,
     163,    -1,   161,    -1,   161,    67,    -1,    35,   170,    62,
      -1,   169,    35,    -1,    35,    -1,   166,    -1,   167,    62,
      -1,   167,   118,    62,    -1,   168,   118,    62,    -1,   168,
      62,    -1,   169,    72,    73,    -1,   169,    72,   225,    73,
      -1,   171,    72,    73,    -1,   171,    72,   225,    73,    -1,
     169,    -1,   117,   169,    -1,   117,   171,    -1,    -1,   170,
      -1,   171,    -1,   159,    -1,   173,    67,   159,    -1,   139,
      -1,   174,    67,   139,    -1,   154,    -1,   175,    67,   154,
      -1,    -1,    90,    35,    85,    62,    -1,   178,    -1,   179,
     228,    62,    68,    -1,   179,   228,    61,   180,    62,    68,
      -1,   179,   228,    61,   180,    61,   180,    62,    68,    -1,
     179,   228,    61,   180,    61,   180,    61,   183,    62,    68,
      -1,    90,    35,    -1,    90,   131,    35,    -1,    -1,   181,
      -1,   182,    -1,   181,    67,   182,    -1,    85,    35,   228,
      62,    -1,    85,    -1,   183,    67,    85,    -1,   200,    -1,
     184,   200,    -1,   190,    -1,   193,    -1,    30,    68,    -1,
      31,    68,    -1,    33,    86,    68,    -1,   199,    -1,   177,
      -1,   187,    -1,   184,   187,    -1,   185,    -1,   192,    -1,
     196,    -1,   189,    -1,   198,    -1,    22,    -1,   188,    35,
     230,    62,    -1,   103,   230,    68,    -1,    24,    -1,   191,
      35,   230,    62,    -1,    26,    -1,    68,    62,    -1,    68,
     230,    62,    -1,    25,    -1,   195,    35,    68,   194,    -1,
     195,    35,    68,   230,   194,    -1,   195,    35,   230,    68,
     194,    -1,   195,    35,   230,    68,   230,   194,    -1,    27,
      -1,   197,    35,   230,    62,    -1,    32,    68,    -1,    32,
     230,    68,    -1,    86,    61,    -1,    28,   228,    61,    -1,
      29,    61,    -1,    35,   230,    62,    -1,    86,    -1,    85,
      -1,   201,    -1,   202,    -1,   203,    72,   230,    73,    -1,
     203,    35,    62,    -1,   203,    35,   229,    62,    -1,   203,
      63,    86,    -1,   203,    64,    86,    -1,   203,   204,    -1,
     203,    63,    85,    -1,   203,    85,    -1,    65,    -1,    66,
      -1,   203,    -1,    34,    35,   112,    62,    -1,    34,   205,
      -1,    93,    35,   112,    62,    -1,    93,   205,    -1,   206,
     205,    -1,    42,   209,    -1,    47,   209,    -1,   207,   209,
      -1,    58,    86,    -1,    65,    -1,    66,    -1,    38,    -1,
      40,    -1,    51,    -1,    50,    -1,    35,   112,    62,    -1,
     205,    -1,   208,   209,    -1,   209,    -1,   210,   211,   209,
      -1,    42,    -1,    45,    -1,    44,    -1,   210,    -1,   212,
     213,   210,    -1,    38,    -1,    40,    -1,   212,    -1,   214,
     215,   212,    -1,    36,    -1,    37,    -1,   214,    -1,   216,
     217,   214,    -1,    52,    -1,    53,    -1,    54,    -1,    55,
      -1,   216,    -1,   218,   219,   216,    -1,    56,    -1,    57,
      -1,   218,    -1,   220,    47,   218,    -1,   220,    -1,   221,
      46,   220,    -1,   221,    -1,   222,    49,   221,    -1,   222,
      -1,   223,    58,   222,    -1,   223,    -1,   224,    59,   223,
      -1,   224,    -1,   224,    60,   230,    61,   225,    -1,   225,
      -1,   209,   227,   226,    -1,    74,    -1,    75,    -1,    76,
      -1,    77,    -1,    81,    -1,    82,    -1,    79,    -1,    78,
      -1,    80,    -1,    83,    -1,    84,    -1,   226,    -1,   228,
      -1,   229,    67,   228,    -1,   229,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,    57,    57,    61,    65,    70,    73,    77,    83,    90,
      96,   105,   110,   115,   119,   123,   133,   137,   145,   149,
     154,   162,   167,   174,   176,   184,   185,   191,   198,   205,
     212,   217,   229,   242,   247,   250,   257,   265,   277,   278,
     281,   287,   293,   299,   305,   311,   318,   330,   339,   344,
     349,   354,   355,   357,   362,   368,   374,   380,   386,   392,
     398,   404,   410,   416,   422,   428,   434,   437,   442,   447,
     454,   459,   465,   476,   488,   495,   500,   515,   526,   531,
     537,   547,   564,   584,   590,   598,   605,   615,   616,   622,
     630,   636,   646,   651,   658,   669,   675,   692,   706,   713,
     720,   728,   742,   756,   761,   775,   789,   790,   792,   801,
     821,   823,   831,   833,   841,   855,   872,   878,   879,   881,
     883,   888,   890,   895,   901,   907,   913,   918,   920,   925,
     931,   940,   948,   950,   962,   976,   988,   998,  1006,  1023,
    1028,  1046,  1048,  1053,  1059,  1062,  1068,  1074,  1081,  1090,
    1095,  1104,  1115,  1127,  1128,  1132,  1139,  1140,  1141,  1143,
    1146,  1147,  1149,  1150,  1152,  1153,  1159,  1165,  1166,  1168,
    1173,  1178,  1179,  1181,  1185,  1189,  1193,  1194,  1199,  1200,
    1203,  1204,  1205,  1206,  1207,  1210,  1215,  1220,  1225,  1230,
    1235,  1241,  1245,  1250,  1255,  1259,  1263,  1267,  1272,  1277,
    1282,  1286,  1292,  1296,  1300,  1305,  1313,  1322,  1326,  1329,
    1331,  1342,  1351,  1362,  1372,  1381,  1390,  1400,  1412,  1417,
    1422,  1424,  1433,  1441,  1445,  1449,  1458,  1467,  1476,  1486,
    1495,  1500,  1506,  1511,  1512,  1513,  1516,  1522,  1524,  1534,
    1536,  1545,  1549,  1550,  1553,  1555,  1564,  1569,  1575,  1577,
    1586,  1587,  1590,  1592,  1601,  1602,  1603,  1604,  1607,  1609,
    1619,  1620,  1623,  1625,  1635,  1637,  1647,  1649,  1659,  1661,
    1671,  1673,  1683,  1685,  1699,  1707,  1725,  1726,  1727,  1728,
    1729,  1730,  1731,  1732,  1733,  1734,  1735,  1738,  1740,  1744,
    1749
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
  "LEFTSHIFT", "RIGHTSHIFT", "PLUS", "ADD", "NEGATE", "MINUS", "STAR", 
  "TIMES", "REMAINDER", "DIVIDE", "XOR", "AND", "BITAND", "OR", 
  "BITNEGATE", "NOT", "LT", "LE", "GE", "GT", "EQUAL", "NOTEQUAL", 
  "ANDTEST", "ORTEST", "QUESTION", "COLON", "CLOSE_RND", "DOT", "DEREF", 
  "PLUSPLUS", "MINUSMINUS", "COMMA", "SEMICOLON", "ELLIPSIS", "OPEN_CURL", 
  "CLOSE_CURL", "OPEN_SQUARE", "CLOSE_SQUARE", "ASSIGN", "PLUSASSIGN", 
  "MINUSASSIGN", "TIMESASSIGN", "LSASSIGN", "RSASSIGN", "ANDASSIGN", 
  "DIVASSIGN", "REMASSIGN", "ORASSIGN", "NOTASSIGN", "LITERAL", 
  "IDENTIFIER", "TYPEDEFNAME", "PASCAL", "FORTRAN", "ASM", "ATTRIBUTE", 
  "TYPEOF", "ALIGNOF", "INLINE", "RESTRICT", "_BOOL", "_COMPLEX", 
  "_IMAGINARY", "AT_ADDR", "EMBED_SQL_HERMAPH", "EMBED_SQL_DECL", 
  "EMBED_SQL_STMT", "UNDEFINED", "$accept", "program", 
  "external_declaration", "top_level_data_declaration", 
  "old_param_decl_list", "function_header", "function_def_start", 
  "parameter_declaration", "typename_declaration", "NT_0003", 
  "list_struct_declaration", "ptr_star", "star_type", "pointer", 
  "parameter_type_list", "parameter_list", "formals_declaration", 
  "formal_declaration", "opt_decl_specifier", "decl_specifier", "NT_0005", 
  "tc_specifier", "std_class", "type_specifier_list", "type_specifier", 
  "struct_enum_spec", "std_type", "type_qual", "struct_or_union", 
  "struct_tag", "struct_def", "struct_curl", "struct_specifier", 
  "struct_declaration", "bitfield_dcltr", "struct_dcltr", "NT_0006", 
  "enumerator_list", "NT_0007", "an_enum", "enum_tag", "enum_def", 
  "enum_specifier", "enum_set_val", "enumerator", "identifier_list", 
  "p1_dcltr", "p2_fndcl", "p2_fn_dcltr", "p2_dcltr", "p3_dcltr", 
  "p3_fn_dcltr", "dcltr", "i_dcltr", "at_location", "init_dcltr", 
  "init_1_dcltr", "NT_0009", "start_init", "end_init", "init_exp", 
  "NT_0010", "p1_abs_dcltr", "p2_abs_fndcl", "e_open_rnd", "p2_abs_dcltr", 
  "p3_abs_dcltr", "e_abs_dcltr", "abs_dcltr", "list_init_dcltr", 
  "list_struct_dcltr", "list_dcltr", "maybe_asm", "asm_stmt", 
  "asm_gnu_stmt", "asm_hdr", "asm_operands", "nonnull_asm_operands", 
  "asm_operand", "asm_clobbers", "label_list", "basic_stmt", "stmt", 
  "bal_statement", "if_tok", "if_header", "e_stmt", "while_tok", 
  "while_header", "do_header", "NT_0014", "for_tok", "for_header", 
  "switch_tok", "switch_header", "return_stmt", "label", "paren_exp", 
  "primary_exp", "postfix_exp", "postfix_op", "unary_exp", "prefix_op", 
  "negate_op", "type_cast", "cast_exp", "mult_oper_exp", "mult_op", 
  "add_oper_exp", "add_op", "shift_oper_exp", "shift_op", "rel_oper_exp", 
  "rel_op", "equ_oper_exp", "equ_op", "bitand_oper_exp", 
  "bitxor_oper_exp", "bitor_oper_exp", "and_oper_exp", "or_oper_exp", 
  "cond_exp", "assign_exp", "asgn_op", "exp", "comma_exp", "list_exp", 0
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
     355,   356,   357,   358
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   104,   105,   105,   105,   106,   107,   107,   108,   108,
     108,   109,   110,   111,   111,   112,   113,   113,   114,   115,
     115,   116,   116,   117,   117,   118,   118,   118,   119,   119,
     120,   121,   121,   122,   122,   123,   124,   124,   125,   125,
     126,   126,   126,   126,   126,   126,   127,   127,   128,   128,
     128,   128,   128,   129,   129,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   131,   131,   131,
     132,   132,   133,   134,   135,   136,   136,   136,   137,   138,
     139,   139,   139,   140,   140,   140,   141,   142,   142,   143,
     144,   145,   146,   146,   146,   147,   148,   148,   149,   149,
     150,   151,   152,   152,   152,   152,   153,   153,   153,   153,
     154,   154,   155,   155,   156,   157,   158,   159,   159,   160,
     160,   161,   161,   162,   163,   164,   164,   165,   165,   166,
     167,   168,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   170,   170,   170,   171,   172,   172,   173,   173,   174,
     174,   175,   175,   176,   176,   177,   178,   178,   178,   178,
     179,   179,   180,   180,   181,   181,   182,   183,   183,   184,
     184,   185,   185,   185,   185,   185,   185,   185,   186,   186,
     187,   187,   187,   187,   187,   188,   189,   190,   191,   192,
     193,   194,   194,   195,   196,   196,   196,   196,   197,   198,
     199,   199,   200,   200,   200,   201,   202,   202,   202,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   204,   204,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     206,   206,   207,   207,   207,   207,   208,   209,   209,   210,
     210,   211,   211,   211,   212,   212,   213,   213,   214,   214,
     215,   215,   216,   216,   217,   217,   217,   217,   218,   218,
     219,   219,   220,   220,   221,   221,   222,   222,   223,   223,
     224,   224,   225,   225,   226,   226,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   228,   229,   229,
     230
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     3,     0,     2,
       2,     3,     2,     2,     3,     2,     0,     2,     1,     1,
       1,     1,     2,     1,     2,     1,     3,     1,     1,     3,
       1,     2,     2,     0,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     4,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     2,     2,     2,     1,     3,     3,     3,     2,
       1,     2,     2,     1,     2,     3,     1,     1,     2,     1,
       2,     2,     1,     4,     3,     2,     1,     2,     1,     3,
       1,     2,     2,     3,     3,     3,     1,     1,     3,     4,
       2,     3,     1,     2,     1,     2,     2,     1,     2,     1,
       2,     1,     3,     1,     2,     1,     2,     1,     2,     3,
       2,     1,     1,     2,     3,     3,     2,     3,     4,     3,
       4,     1,     2,     2,     0,     1,     1,     1,     3,     1,
       3,     1,     3,     0,     4,     1,     4,     6,     8,    10,
       2,     3,     0,     1,     1,     3,     4,     1,     3,     1,
       2,     1,     1,     2,     2,     3,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     4,     3,     1,     4,
       1,     2,     3,     1,     4,     5,     5,     6,     1,     4,
       2,     3,     2,     3,     2,     3,     1,     1,     1,     1,
       4,     3,     4,     3,     3,     2,     3,     2,     1,     1,
       1,     4,     2,     4,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     1,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
      33,    40,    41,    42,    43,    44,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    67,    68,    70,    71,    89,
     185,   188,   193,   190,   198,     0,     0,     0,     0,     0,
       0,     0,    48,    64,    65,     0,     0,    45,     0,     0,
       0,     2,     5,     0,     4,     0,    34,    35,    36,    38,
      39,    52,    51,    66,     0,    75,    16,    16,    53,     0,
      92,     0,    54,   177,   155,     0,     0,   180,     3,   178,
       0,   183,   171,     0,   181,   172,     0,   182,     0,   184,
     176,   169,     0,     0,   232,   233,     0,     0,   235,   234,
       0,   230,   231,   207,   206,     0,   208,   209,   220,   237,
       0,     0,     0,   239,   244,   248,   252,   258,   262,   264,
     266,   268,   270,   272,   274,   287,     0,   204,   173,   174,
     200,   288,   290,     0,     0,   202,   160,     0,     0,    69,
       0,     1,    12,     0,    19,    20,     6,   100,    21,    23,
       0,   106,     0,   112,   153,   114,     8,   119,     0,   147,
     117,     0,    37,    74,    72,    73,    18,     0,     0,     0,
      90,    91,    96,    87,     0,    86,     0,    83,     0,   179,
     170,     0,     0,     0,     0,     0,   222,     0,   144,     0,
     226,   227,   229,     0,   224,     0,     0,     0,   218,   219,
       0,   217,   215,     0,   225,   228,   238,   276,   277,   278,
     279,   283,   282,   284,   280,   281,   285,   286,     0,   241,
     243,   242,     0,   246,   247,     0,   250,   251,     0,   254,
     255,   256,   257,     0,   260,   261,     0,     0,     0,     0,
       0,     0,     0,   203,     0,   201,   175,   161,     0,     0,
     187,     0,   107,     0,    22,    46,    24,   113,   153,   102,
      27,    98,    30,    25,     0,    28,   144,     0,   101,     0,
       0,   110,   115,    11,   123,     0,   120,   125,     0,   118,
       0,     7,     0,    17,    77,    76,     0,    95,    88,    84,
      94,    97,   162,     0,     0,     0,     0,     0,     0,     0,
     236,   131,   144,   132,     0,     0,   141,   145,   146,    15,
     205,     0,   211,     0,   216,   213,   214,     0,   275,   240,
     239,   245,   249,   253,   259,   263,   265,   267,   269,   271,
       0,   289,    50,    49,   103,    47,   111,     0,   105,   131,
     144,    31,    32,   104,     0,   108,     0,     0,     9,    10,
       0,   127,   126,   121,     0,   116,   148,     0,     0,   149,
      80,     0,    93,    85,     0,     0,   163,   164,   156,   186,
     189,     0,   194,     0,     0,   199,   221,     0,     0,   142,
     143,   133,     0,   136,     0,   130,     0,     0,   223,   212,
     210,     0,    26,    29,    99,   109,     0,    13,   151,     0,
     128,   124,    81,    82,    79,     0,    78,     0,   162,     0,
       0,   191,     0,   195,   196,     0,   129,   134,   135,   137,
       0,   139,     0,   273,   154,     0,    14,   122,   150,     0,
       0,   157,   165,   192,   197,   138,   140,   152,   166,     0,
       0,   167,     0,   158,     0,     0,   159,   168
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,    40,    41,    42,   263,    43,    44,   339,   177,   156,
     157,   138,   139,   241,   252,   253,   254,   255,    45,   178,
      47,    48,    49,   244,    50,    51,    52,    53,    54,    55,
      56,    57,    58,   273,   348,   349,   163,   164,   165,    59,
      60,    61,    62,   166,   167,   257,   141,   142,   242,   144,
     145,   146,   147,   148,   269,   149,   150,   341,   265,   342,
     266,   344,   293,   294,   295,   296,   297,   298,   299,   151,
     351,   389,   261,    63,    64,    65,   355,   356,   357,   432,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
     362,    76,    77,    78,    79,    80,    81,    96,    97,    98,
     192,    99,   100,   101,   102,   103,   104,   212,   105,   215,
     106,   218,   107,   223,   108,   226,   109,   110,   111,   112,
     113,   114,   115,   208,   121,   122,   179
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -348
static const short yypact[] =
{
     370,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,   922,   -39,   -26,   -22,   177,
     -61,     3,  -348,  -348,  -348,    26,    35,  -348,    11,   922,
     100,  -348,  -348,    46,  -348,    15,  -348,   666,  -348,  -348,
    -348,  -348,  -348,  -348,   -49,    49,  -348,  -348,  -348,    25,
      51,    44,  -348,  -348,  -348,   922,    47,  -348,  -348,  -348,
     101,  -348,  -348,   104,  -348,  -348,   113,  -348,   116,  -348,
    -348,  -348,   951,   432,  -348,  -348,   922,   922,  -348,  -348,
      68,  -348,  -348,  -348,  -348,   984,  -348,  -348,   209,  -348,
    1013,   922,   922,   227,   148,    74,   164,   168,   175,   110,
     123,   140,   150,   174,  -348,  -348,   145,  -348,  -348,  -348,
    -348,  -348,   147,   158,   171,  -348,  -348,   181,   432,  -348,
     173,  -348,  -348,   160,  -348,  -348,  -348,  -348,    18,  -348,
     160,  -348,   167,    14,   -27,   186,  -348,  -348,   539,  -348,
     165,   170,  -348,  -348,  -348,  -348,   666,   176,   196,    44,
    -348,  -348,   197,    -1,   205,  -348,   922,  -348,   188,  -348,
    -348,   922,   922,   657,   922,   432,  -348,   195,   156,   222,
    -348,  -348,  -348,   432,  -348,   728,   166,   206,  -348,  -348,
     922,  -348,  -348,   922,  -348,  -348,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,   922,  -348,
    -348,  -348,   922,  -348,  -348,   922,  -348,  -348,   922,  -348,
    -348,  -348,  -348,   922,  -348,  -348,   922,   922,   922,   922,
     922,   922,   922,  -348,   922,  -348,  -348,  -348,   229,   231,
    -348,   160,  -348,   233,    18,  -348,  -348,    14,   -27,  -348,
    -348,  -348,  -348,   230,   234,  -348,   183,   -47,  -348,   757,
     263,  -348,  -348,   335,  -348,   539,  -348,  -348,   922,  -348,
     160,  -348,     6,  -348,  -348,  -348,   241,  -348,    44,  -348,
    -348,  -348,   232,   247,   254,   257,   794,   252,   259,   262,
    -348,    87,   156,  -348,   529,   550,    30,  -348,   253,  -348,
    -348,   264,  -348,    29,  -348,  -348,  -348,   255,  -348,  -348,
    -348,   148,    74,   164,   168,   175,   110,   123,   140,   150,
     266,  -348,  -348,  -348,  -348,  -348,  -348,   647,  -348,    12,
     183,  -348,  -348,  -348,   243,  -348,   258,   245,  -348,  -348,
      52,   267,  -348,  -348,   286,  -348,  -348,   922,   922,  -348,
     274,   210,  -348,  -348,   302,   218,   291,  -348,  -348,  -348,
    -348,   823,  -348,   292,   794,  -348,  -348,   297,   253,    30,
     253,  -348,   299,  -348,   300,  -348,   856,   885,  -348,  -348,
    -348,   922,  -348,  -348,  -348,  -348,   301,  -348,  -348,   215,
     539,  -348,  -348,  -348,  -348,     6,  -348,   922,   232,   296,
     232,  -348,   304,  -348,  -348,   292,  -348,  -348,  -348,  -348,
     294,  -348,   295,  -348,  -348,   160,  -348,  -348,  -348,   307,
     226,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,   285,
     303,  -348,    48,  -348,   325,   320,  -348,  -348
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -115,  -348,
     349,  -348,  -136,   -43,    -5,  -348,  -348,    80,  -348,     5,
    -348,   361,  -348,  -348,  -348,  -348,  -126,   374,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,    16,  -348,   251,  -348,  -348,
    -348,  -348,  -348,  -348,  -154,  -348,  -348,  -348,   -31,  -133,
    -130,  -348,  -348,  -348,  -348,   142,  -348,  -348,  -348,  -348,
    -259,  -348,  -348,  -348,  -348,  -274,  -236,  -240,   157,  -348,
    -348,  -348,   169,  -348,  -348,  -348,    17,  -348,    19,  -348,
    -348,  -348,  -348,   348,  -348,  -348,  -348,  -348,  -348,  -348,
    -347,  -348,  -348,  -348,  -348,  -348,   350,  -348,  -348,  -348,
    -348,    58,  -348,  -348,  -348,   -63,   203,  -348,   202,  -348,
     198,  -348,   199,  -348,   201,  -348,   204,   225,   200,   224,
    -348,  -249,   223,  -348,   -25,   248,   -28
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -145
static const short yytable[] =
{
     116,   123,   140,   243,   246,    46,   343,   248,   258,   279,
     336,   130,   245,   238,   143,   333,   403,   404,   369,   345,
     334,   153,   117,   180,   181,   124,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   154,   195,   196,
     168,   133,   118,    15,    16,   259,   119,   329,   134,  -107,
     133,   368,   370,   135,   134,   367,   369,   134,   424,   135,
     289,   126,   135,   260,   125,   375,   278,   347,   301,    20,
     128,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,  -107,  -107,   136,  -144,   162,  -107,   133,  -107,   368,
     370,   379,   137,   367,   134,   159,   234,   129,   137,   135,
     131,   137,   376,   239,  -107,   246,    33,    34,   248,   247,
     434,   160,   213,  -107,   214,   435,   132,    38,   325,   155,
     387,   161,   291,   267,   353,    38,   331,   410,   412,   134,
     162,   417,   413,    31,   135,   292,   171,    35,   137,   172,
     176,   281,   350,   284,   285,   287,   288,   256,   173,   309,
      39,   174,   310,   184,   182,   310,   246,   227,   194,  -144,
     310,   272,   307,   310,   310,   310,   310,   310,   310,   228,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   229,
     209,   291,   210,   211,   246,   133,   310,   248,   134,   243,
     216,   217,   134,   135,   320,   310,   233,   135,   230,   321,
     388,    82,    83,   330,   234,    84,   237,    85,   329,    86,
     219,   220,   221,   222,    87,   134,   235,    88,    89,   249,
     135,   224,   225,   231,   232,    90,   250,   270,   271,   236,
     267,   240,    91,    92,   185,   120,   137,   274,   292,   282,
     283,   304,   305,   251,    32,    33,    34,   290,   363,    36,
     262,    37,    93,    94,   268,   350,    38,   275,   340,   137,
      95,   277,   186,   187,   188,   189,   280,   395,   396,   398,
     399,   190,   415,   416,   300,   427,   330,   429,   430,   372,
     374,   322,   306,   323,   191,   324,   328,   327,   337,   256,
     256,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   352,   310,   310,   358,   359,   354,   310,   360,
     364,   365,   392,   393,   366,   377,   378,   381,   380,   384,
     386,   385,   256,   402,   390,   394,   405,   397,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   391,   400,   406,
     361,   407,   408,   414,   421,   267,   423,   425,   426,   428,
     431,   433,   419,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   436,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,   338,   437,   158,   383,   152,   127,
     276,   418,   346,   332,   169,   420,   170,   326,   311,   422,
     312,   313,    32,    33,    34,   314,     0,    36,   315,    37,
     318,   308,   316,   303,    38,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   317,   319,    31,    32,    33,    34,
      35,     0,    36,     0,    37,     0,    82,    83,     0,    38,
      84,     0,    85,    39,    86,     0,     0,     0,     0,    87,
       0,     0,    88,    89,     0,     0,     0,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,    94,    32,
      33,    34,     0,     0,    36,    95,    37,     0,     0,     0,
       0,    38,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    82,    83,     0,     0,    84,     0,    85,
       0,    86,     0,     0,     0,     0,    87,     0,     0,    88,
      89,   371,     0,     0,     0,     0,     0,    90,   250,     0,
       0,     0,     0,     0,    91,    92,     0,     0,     0,   264,
       0,     0,   373,     0,     0,     0,    32,    33,    34,   250,
       0,    36,     0,    37,    93,    94,     0,     0,    38,     0,
       0,     0,    95,     0,     0,     0,     0,    32,    33,    34,
       0,     0,    36,     0,    37,     0,     0,     0,     0,    38,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,    82,    83,     0,     0,    84,     0,    85,     0,    86,
       0,     0,     0,     0,    87,     0,     0,    88,    89,     0,
       0,     0,     0,     0,     0,    90,   382,     0,     0,     0,
       0,     0,    91,    92,     0,   286,     0,     0,     0,     0,
       0,     0,     0,     0,    32,    33,    34,     0,     0,    36,
       0,    37,    93,    94,     0,     0,    38,     0,     0,     0,
      95,     0,     0,    32,    33,    34,     0,     0,    36,     0,
      37,     0,    82,    83,     0,    38,    84,     0,    85,     0,
      86,     0,     0,     0,     0,    87,     0,     0,    88,    89,
       0,     0,     0,     0,     0,     0,    90,     0,     0,     0,
     302,    82,    83,    91,    92,    84,     0,    85,     0,    86,
       0,     0,     0,     0,    87,     0,     0,    88,    89,     0,
       0,     0,     0,    93,    94,    90,     0,     0,     0,     0,
       0,    95,    91,    92,     0,     0,     0,     0,    82,    83,
     335,     0,    84,     0,    85,     0,    86,     0,     0,     0,
       0,    87,    93,    94,    88,    89,     0,     0,     0,     0,
      95,     0,    90,     0,     0,     0,     0,    82,    83,    91,
      92,    84,   361,    85,     0,    86,     0,     0,     0,     0,
      87,     0,     0,    88,    89,     0,     0,     0,     0,    93,
      94,    90,     0,     0,     0,   401,     0,    95,    91,    92,
      82,    83,     0,     0,    84,     0,    85,     0,    86,     0,
       0,     0,     0,    87,     0,     0,    88,    89,    93,    94,
       0,     0,     0,     0,    90,     0,    95,     0,     0,    82,
      83,    91,    92,    84,     0,    85,     0,    86,     0,   409,
       0,     0,    87,     0,     0,    88,    89,     0,     0,     0,
       0,    93,    94,    90,     0,     0,     0,     0,     0,    95,
      91,    92,     0,     0,     0,     0,    82,    83,   411,     0,
      84,     0,    85,     0,    86,     0,     0,     0,     0,    87,
      93,    94,    88,    89,     0,     0,     0,     0,    95,     0,
      90,     0,     0,     0,     0,    82,   175,    91,    92,    84,
       0,    85,     0,    86,     0,     0,     0,     0,    87,     0,
       0,    88,    89,     0,     0,     0,     0,    93,    94,    90,
       0,     0,     0,     0,     0,    95,    91,    92,    82,   183,
       0,     0,    84,     0,    85,     0,    86,     0,     0,     0,
       0,    87,     0,     0,    88,    89,    93,    94,     0,     0,
       0,     0,    90,     0,    95,     0,     0,    82,   193,    91,
      92,    84,     0,    85,     0,    86,     0,     0,     0,     0,
      87,     0,     0,    88,    89,     0,     0,     0,     0,    93,
      94,    90,     0,     0,     0,     0,     0,    95,    91,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,    94,
       0,     0,     0,     0,     0,     0,    95
};

static const short yycheck[] =
{
      25,    29,    45,   133,   140,     0,   265,   140,    35,   163,
     259,    39,   138,   128,    45,    62,   363,   364,   292,   268,
      67,    70,    61,    86,    87,    86,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    86,   101,   102,
      65,    35,    68,    17,    18,    72,    68,    35,    42,    35,
      35,   291,   292,    47,    42,   291,   330,    42,   405,    47,
     175,    35,    47,    90,    61,    35,    67,    61,   183,    22,
      35,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    67,    68,    68,    72,    86,    72,    35,    74,   329,
     330,    62,    86,   329,    42,    70,    67,    86,    86,    47,
       0,    86,    72,   128,    90,   241,    88,    89,   241,   140,
      62,    86,    38,    99,    40,    67,    70,    99,   244,    70,
      68,    70,    35,   148,   278,    99,   256,   376,   377,    42,
      86,   390,   381,    86,    47,   178,    35,    90,    86,    35,
      82,   166,   272,   171,   172,   173,   174,   142,    35,   212,
     103,    35,   215,    95,    86,   218,   292,    47,   100,    72,
     223,   156,   190,   226,   227,   228,   229,   230,   231,    46,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    49,
      42,    35,    44,    45,   330,    35,   259,   330,    42,   329,
      36,    37,    42,    47,   232,   268,    61,    47,    58,   234,
     340,    34,    35,   256,    67,    38,    35,    40,    35,    42,
      52,    53,    54,    55,    47,    42,    68,    50,    51,    62,
      47,    56,    57,    59,    60,    58,    69,    67,    68,    68,
     265,    68,    65,    66,    35,    68,    86,    71,   291,    61,
      62,    85,    86,    86,    87,    88,    89,    62,   286,    92,
      74,    94,    85,    86,    99,   395,    99,    71,   263,    86,
      93,    74,    63,    64,    65,    66,    71,    67,    68,    61,
      62,    72,    67,    68,    62,   415,   329,    61,    62,   294,
     295,    62,    86,    62,    85,    62,    62,    67,    35,   294,
     295,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    71,   376,   377,    68,    62,    85,   381,    62,
      68,    62,   347,   348,    62,    72,    62,    61,    73,    86,
      85,    73,   327,   361,    67,    61,   364,    35,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    71,    67,    62,
      68,    62,    62,    62,    68,   390,    62,    73,    73,    62,
      85,    68,   397,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    68,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    69,    85,    57,   327,    47,    35,
     159,   395,   270,   256,    66,   398,    66,   248,   215,   400,
     218,   223,    87,    88,    89,   226,    -1,    92,   227,    94,
     230,   208,   228,   185,    99,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,   229,   231,    86,    87,    88,    89,
      90,    -1,    92,    -1,    94,    -1,    34,    35,    -1,    99,
      38,    -1,    40,   103,    42,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,
      -1,    99,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    34,    35,    -1,    -1,    38,    -1,    40,
      -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,
      51,    62,    -1,    -1,    -1,    -1,    -1,    58,    69,    -1,
      -1,    -1,    -1,    -1,    65,    66,    -1,    -1,    -1,    70,
      -1,    -1,    62,    -1,    -1,    -1,    87,    88,    89,    69,
      -1,    92,    -1,    94,    85,    86,    -1,    -1,    99,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    -1,    87,    88,    89,
      -1,    -1,    92,    -1,    94,    -1,    -1,    -1,    -1,    99,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    34,    35,    -1,    -1,    38,    -1,    40,    -1,    42,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    69,    -1,    -1,    -1,
      -1,    -1,    65,    66,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    -1,    -1,    92,
      -1,    94,    85,    86,    -1,    -1,    99,    -1,    -1,    -1,
      93,    -1,    -1,    87,    88,    89,    -1,    -1,    92,    -1,
      94,    -1,    34,    35,    -1,    99,    38,    -1,    40,    -1,
      42,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      62,    34,    35,    65,    66,    38,    -1,    40,    -1,    42,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    51,    -1,
      -1,    -1,    -1,    85,    86,    58,    -1,    -1,    -1,    -1,
      -1,    93,    65,    66,    -1,    -1,    -1,    -1,    34,    35,
      73,    -1,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,
      -1,    47,    85,    86,    50,    51,    -1,    -1,    -1,    -1,
      93,    -1,    58,    -1,    -1,    -1,    -1,    34,    35,    65,
      66,    38,    68,    40,    -1,    42,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    85,
      86,    58,    -1,    -1,    -1,    62,    -1,    93,    65,    66,
      34,    35,    -1,    -1,    38,    -1,    40,    -1,    42,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    50,    51,    85,    86,
      -1,    -1,    -1,    -1,    58,    -1,    93,    -1,    -1,    34,
      35,    65,    66,    38,    -1,    40,    -1,    42,    -1,    73,
      -1,    -1,    47,    -1,    -1,    50,    51,    -1,    -1,    -1,
      -1,    85,    86,    58,    -1,    -1,    -1,    -1,    -1,    93,
      65,    66,    -1,    -1,    -1,    -1,    34,    35,    73,    -1,
      38,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,
      85,    86,    50,    51,    -1,    -1,    -1,    -1,    93,    -1,
      58,    -1,    -1,    -1,    -1,    34,    35,    65,    66,    38,
      -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    50,    51,    -1,    -1,    -1,    -1,    85,    86,    58,
      -1,    -1,    -1,    -1,    -1,    93,    65,    66,    34,    35,
      -1,    -1,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    50,    51,    85,    86,    -1,    -1,
      -1,    -1,    58,    -1,    93,    -1,    -1,    34,    35,    65,
      66,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    85,
      86,    58,    -1,    -1,    -1,    -1,    -1,    93,    65,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    93
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    86,    87,    88,    89,    90,    92,    94,    99,   103,
     105,   106,   107,   109,   110,   122,   123,   124,   125,   126,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   143,
     144,   145,   146,   177,   178,   179,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   195,   196,   197,   198,
     199,   200,    34,    35,    38,    40,    42,    47,    50,    51,
      58,    65,    66,    85,    86,    93,   201,   202,   203,   205,
     206,   207,   208,   209,   210,   212,   214,   216,   218,   220,
     221,   222,   223,   224,   225,   226,   228,    61,    68,    68,
      68,   228,   229,   230,    86,    61,    35,   131,    35,    86,
     230,     0,    70,    35,    42,    47,    68,    86,   115,   116,
     117,   150,   151,   152,   153,   154,   155,   156,   157,   159,
     160,   173,   125,    70,    86,    70,   113,   114,   114,    70,
      86,    70,    86,   140,   141,   142,   147,   148,   228,   187,
     200,    35,    35,    35,    35,    35,   205,   112,   123,   230,
     209,   209,    86,    35,   205,    35,    63,    64,    65,    66,
      72,    85,   204,    35,   205,   209,   209,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,   227,    42,
      44,    45,   211,    38,    40,   213,    36,    37,   215,    52,
      53,    54,    55,   217,    56,    57,   219,    47,    46,    49,
      58,    59,    60,    61,    67,    68,    68,    35,   112,   228,
      68,   117,   152,   154,   127,   130,   116,   152,   153,    62,
      69,    86,   118,   119,   120,   121,   123,   149,    35,    72,
      90,   176,    74,   108,    70,   162,   164,   228,    99,   158,
      67,    68,   123,   137,    71,    71,   141,    74,    67,   148,
      71,   228,    61,    62,   230,   230,    68,   230,   230,   112,
      62,    35,   117,   166,   167,   168,   169,   170,   171,   172,
      62,   112,    62,   229,    85,    86,    86,   230,   226,   209,
     209,   210,   212,   214,   216,   218,   220,   221,   222,   223,
     230,   228,    62,    62,    62,   130,   176,    67,    62,    35,
     117,   154,   172,    62,    67,    73,   225,    35,    69,   111,
     123,   161,   163,   164,   165,   225,   159,    61,   138,   139,
     154,   174,    71,   148,    85,   180,   181,   182,    68,    62,
      62,    68,   194,   230,    68,    62,    62,   170,   171,   169,
     171,    62,   118,    62,   118,    35,    72,    72,    62,    62,
      73,    61,    69,   121,    86,    73,    85,    68,   154,   175,
      67,    71,   228,   228,    61,    67,    68,    35,    61,    62,
      67,    62,   230,   194,   194,   230,    62,    62,    62,    73,
     225,    73,   225,   225,    62,    67,    68,   164,   139,   228,
     180,    68,   182,    62,   194,    73,    73,   154,    62,    61,
      62,    85,   183,    68,    62,    67,    68,    85
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
        case 2:
#line 58 "cusage.y"
    {
	  ;}
    break;

  case 3:
#line 62 "cusage.y"
    {
	  ;}
    break;

  case 4:
#line 66 "cusage.y"
    {
	  ;}
    break;

  case 6:
#line 74 "cusage.y"
    {
			     ;}
    break;

  case 7:
#line 78 "cusage.y"
    {
			     ;}
    break;

  case 8:
#line 83 "cusage.y"
    {
           yyval.this_token  (TOKEN_LIST)NULL;
           yyval.u_ptr_c_type.ptr_c_vlist  (VLIST_PTR)NULL;
           decl_is_empty  TRUE;	/* ready for param decls */
           tdef_valid  TRUE;
	   ;}
    break;

  case 9:
#line 91 "cusage.y"
    {
           if (!cc_extensions[GCC_Extension])
	      LANG_ERROR(E_GCC_ELLIPSIS);
	   ;}
    break;

  case 10:
#line 97 "cusage.y"
    {
           yyval.this_token  yyvsp[0].this_token;
           yyval.u_ptr_c_type.ptr_c_vlist  app_var_list(yyvsp[0].u_ptr_c_type.ptr_c_vlist,
                                                      yyvsp[-1].u_ptr_c_type.ptr_c_vlist);
	   ;}
    break;

  case 11:
#line 106 "cusage.y"
    {
		  ;}
    break;

  case 12:
#line 111 "cusage.y"
    {
                        ;}
    break;

  case 13:
#line 116 "cusage.y"
    {
			;}
    break;

  case 14:
#line 120 "cusage.y"
    {
			;}
    break;

  case 15:
#line 124 "cusage.y"
    {
      		       pop_decl_spec();
      		       current_tok_p  yyvsp[0].this_token;
      		       yyval.u_ptr_c_type.ptr_c_type  build_type(yyvsp[0].u_ptr_c_type.ptr_c_type,
                                                  yyvsp[-1].u_ptr_c_type.ptr_c_type);
		       ;}
    break;

  case 16:
#line 133 "cusage.y"
    {
	  yyval.u_ptr_c_type.ptr_fld_list  (FIELD_PTR)NULL;
	  ;}
    break;

  case 17:
#line 138 "cusage.y"
    {
      current_tok_p  yyvsp[0].this_token;
      yyval.u_ptr_c_type.ptr_fld_list  append_fields(yyvsp[-1].u_ptr_c_type.ptr_fld_list,
      	                                          yyvsp[0].u_ptr_c_type.ptr_fld_list);
	  ;}
    break;

  case 18:
#line 146 "cusage.y"
    {
		;}
    break;

  case 19:
#line 150 "cusage.y"
    {
	   tdef_valid  FALSE;
	   ;}
    break;

  case 20:
#line 155 "cusage.y"
    {
	   /* Better error recover by supporting C++ ref
	    * operator in the grammar.
	    */
	   tdef_valid  FALSE;
	   ;}
    break;

  case 21:
#line 163 "cusage.y"
    {
            yyval.u_ptr_c_type.ptr_c_type  mk_ptr((C_TYPE_PTR)NULL);
	    ;}
    break;

  case 22:
#line 168 "cusage.y"
    {
      yyval.u_ptr_c_type.ptr_c_type  build_type(yyvsp[0].u_ptr_c_type.ptr_c_type,
                                              mk_ptr((C_TYPE_PTR)NULL));
	    ;}
    break;

  case 24:
#line 177 "cusage.y"
    {
         yyval.u_ptr_c_type.ptr_c_type  build_type(
                                   yyvsp[0].u_ptr_c_type.ptr_c_type,
                                   yyvsp[-1].u_ptr_c_type.ptr_c_type);
          ;}
    break;

  case 26:
#line 186 "cusage.y"
    {
      yyval.u_ptr_c_type.ptr_c_plist  mk_plist(yyvsp[-2].u_ptr_c_type.ptr_c_plist,
                                                anon_ellip_var);
		      ;}
    break;

  case 27:
#line 192 "cusage.y"
    {
      LANG_ERROR(E_ELLIPSIS_IS_CPP);
      yyval.u_ptr_c_type.ptr_c_plist  (PARAM_LIST_PTR)NULL;
		      ;}
    break;

  case 28:
#line 199 "cusage.y"
    {
      yyval.u_ptr_c_type.ptr_c_plist  mk_plist((PARAM_LIST_PTR)NULL,
      					     yyvsp[0].u_ptr_c_type.ptr_c_var);
		  ;}
    break;

  case 29:
#line 206 "cusage.y"
    {
      yyval.u_ptr_c_type.ptr_c_plist  mk_plist(yyvsp[-2].u_ptr_c_type.ptr_c_plist,
                                             yyvsp[0].u_ptr_c_type.ptr_c_var);
		  ;}
    break;

  case 30:
#line 213 "cusage.y"
    {
		chk_void_params(yyval.u_ptr_c_type.ptr_c_plist);
		;}
    break;

  case 31:
#line 218 "cusage.y"
    {
         current_tok_p  yyvsp[0].this_token;
	 yyvsp[0].u_ptr_c_type.ptr_c_var->vtype 
	 		build_type(yyvsp[0].u_ptr_c_type.ptr_c_var->vtype,
                                    rebuild_type(cur_decl_spec));
         chk_formal(yyvsp[0].u_ptr_c_type.ptr_c_var);
         pop_decl_spec();
         yyval  yyvsp[0];
         tdef_valid  TRUE;
		     ;}
    break;

  case 32:
#line 230 "cusage.y"
    {
         current_tok_p  yyvsp[0].this_token;
         pop_decl_spec();
         yyval.u_ptr_c_type.ptr_c_var  new_var((STR_PTR)NULL,
					      nest_scope_depth);
         yyval.u_ptr_c_type.ptr_c_var->vtype  yyvsp[0].u_ptr_c_type.ptr_c_type;
         chk_formal(yyval.u_ptr_c_type.ptr_c_var);
         tdef_valid  TRUE;
		     ;}
    break;

  case 33:
#line 242 "cusage.y"
    {
		     yyval.u_ptr_c_type.ptr_c_type  (C_TYPE_PTR)NULL;
		     push_decl_spec((C_TYPE_PTR)NULL);
		     ;}
    break;

  case 35:
#line 251 "cusage.y"
    {
                 mk_empty_set(types_seen);
                 push_decl_spec(yyvsp[0].u_ptr_c_type.ptr_c_type);
		 ;}
    break;

  case 36:
#line 258 "cusage.y"
    {
          mk_empty_set(types_seen);
          if (yyvsp[0].optok ! TOK_AT_LOCATION)
	     combine_std_types(types_seen, yyvsp[0].optok);
	  ;}
    break;

  case 37:
#line 266 "cusage.y"
    {
          current_tok_p  yyvsp[0].this_token;
          if (yyvsp[0].optok ! TOK_AT_LOCATION)
             {
	     combine_std_types(types_seen, yyvsp[0].optok);
             yyval.u_ptr_c_type.ptr_c_type  mk_tc_spec(yyvsp[-1].u_ptr_c_type.ptr_c_type,
                                                   yyvsp[0].u_ptr_c_type.ptr_c_type);
             }
	  ;}
    break;

  case 40:
#line 282 "cusage.y"
    {
            yyval.u_ptr_c_type.ptr_c_type  mk_class(CAUTO,
					      (C_TYPE_PTR)NULL);
	    ;}
    break;

  case 41:
#line 288 "cusage.y"
    {
            yyval.u_ptr_c_type.ptr_c_type  mk_class(CSTATIC,
					      (C_TYPE_PTR)NULL);
	    ;}
    break;

  case 42:
#line 294 "cusage.y"
    {
            yyval.u_ptr_c_type.ptr_c_type  mk_class(EXT,
					      (C_TYPE_PTR)NULL);
	    ;}
    break;

  case 43:
#line 300 "cusage.y"
    {
            yyval.u_ptr_c_type.ptr_c_type  mk_class(REG,
					      (C_TYPE_PTR)NULL);
	    ;}
    break;

  case 44:
#line 306 "cusage.y"
    {
            yyval.u_ptr_c_type.ptr_c_type  mk_class(CTYPEDEF,
					      (C_TYPE_PTR)NULL);
	    ;}
    break;

  case 45:
#line 312 "cusage.y"
    {
            yyval.u_ptr_c_type.ptr_c_type  mk_class(CINLINE,
					      (C_TYPE_PTR)NULL);
	    ;}
    break;

  case 46:
#line 319 "cusage.y"
    {
			/*
			 * The only types allowed are const
			 * and volatile
			 */
      current_tok_p  yyvsp[0].this_token;
      mk_empty_set(types_seen);	
      if (yyvsp[0].optok ! TOK_AT_LOCATION)
	    combine_std_types(types_seen, yyvsp[0].optok);
		      ;}
    break;

  case 47:
#line 331 "cusage.y"
    {
	 current_tok_p  yyvsp[0].this_token;	
	       combine_std_types(types_seen, yyvsp[0].optok);
	       yyval.u_ptr_c_type.ptr_c_type  mk_tc_spec(yyvsp[-1].u_ptr_c_type.ptr_c_type,
   	                                            yyvsp[0].u_ptr_c_type.ptr_c_type);
		      ;}
    break;

  case 48:
#line 340 "cusage.y"
    {
                 tdef_valid  FALSE;
		 ;}
    break;

  case 49:
#line 345 "cusage.y"
    {
		 yyval.u_ptr_c_type.ptr_c_type  yyvsp[-1].u_ptr_c_type.ptr_tree->exptype;
		 ;}
    break;

  case 50:
#line 350 "cusage.y"
    {
	         yyval.u_ptr_c_type.ptr_c_type  yyvsp[-1].u_ptr_c_type.ptr_c_type;
		 ;}
    break;

  case 53:
#line 358 "cusage.y"
    {
                   tdef_valid  FALSE;
		   ;}
    break;

  case 54:
#line 363 "cusage.y"
    {
                   tdef_valid  FALSE;
		   ;}
    break;

  case 55:
#line 369 "cusage.y"
    {
           yyval.u_ptr_c_type.ptr_c_type  ct_char;
           tdef_valid  FALSE;
	   ;}
    break;

  case 56:
#line 375 "cusage.y"
    {
           yyval.u_ptr_c_type.ptr_c_type  ct_float;
           tdef_valid  FALSE;
	   ;}
    break;

  case 57:
#line 381 "cusage.y"
    {
           yyval.u_ptr_c_type.ptr_c_type  ct_double;
           tdef_valid  FALSE;
	   ;}
    break;

  case 58:
#line 387 "cusage.y"
    {
           yyval.u_ptr_c_type.ptr_c_type  ct_int;
           tdef_valid  FALSE;
	   ;}
    break;

  case 59:
#line 393 "cusage.y"
    {
           yyval.u_ptr_c_type.ptr_c_type  ct_short;
           tdef_valid  FALSE;
	   ;}
    break;

  case 60:
#line 399 "cusage.y"
    {
           yyval.u_ptr_c_type.ptr_c_type  ct_long;
           tdef_valid  FALSE;
	   ;}
    break;

  case 61:
#line 405 "cusage.y"
    {
           yyval.u_ptr_c_type.ptr_c_type  ct_uint;
           tdef_valid  FALSE;
	   ;}
    break;

  case 62:
#line 411 "cusage.y"
    {
           yyval.u_ptr_c_type.ptr_c_type  ct_sint;
           tdef_valid  FALSE;
	   ;}
    break;

  case 63:
#line 417 "cusage.y"
    {
           yyval.u_ptr_c_type.ptr_c_type  ct_void;
           tdef_valid  FALSE;
	   ;}
    break;

  case 64:
#line 423 "cusage.y"
    {
           yyval.u_ptr_c_type.ptr_c_type  mk_class(CPASCAL,
					       (C_TYPE_PTR)NULL);
	   ;}
    break;

  case 65:
#line 429 "cusage.y"
    {
           yyval.u_ptr_c_type.ptr_c_type  mk_class(CFORTRAN,
					       (C_TYPE_PTR)NULL);
	   ;}
    break;

  case 67:
#line 438 "cusage.y"
    {
            yyval.u_ptr_c_type.ptr_c_type  add_qualifier(CCONSTANT, (C_TYPE_PTR)NULL);
	    ;}
    break;

  case 68:
#line 443 "cusage.y"
    {
            yyval.u_ptr_c_type.ptr_c_type  add_qualifier(CVOLATILE, (C_TYPE_PTR)NULL);
	    ;}
    break;

  case 69:
#line 448 "cusage.y"
    {
	    yyval.u_ptr_c_type.ptr_c_type  add_qualifier(CEXTENSION, (C_TYPE_PTR)NULL);
	    LANG_ERROR(E_AT_IDENTIFIER);
	    ;}
    break;

  case 70:
#line 455 "cusage.y"
    {
        tdef_valid  FALSE;
	;}
    break;

  case 71:
#line 460 "cusage.y"
    {
        tdef_valid  FALSE;
	;}
    break;

  case 72:
#line 466 "cusage.y"
    {
      if (yyvsp[-1].optok = TOK_STRUCT)
	 yyval.u_ptr_c_type.ptr_c_var  tagged_type(yyvsp[0].u_ptr_c_type.ptr_ident,
                                                                      CSTRUCT);
      else
	 yyval.u_ptr_c_type.ptr_c_var  tagged_type(yyvsp[0].u_ptr_c_type.ptr_ident,
                                                                      CUNION);
	     ;}
    break;

  case 73:
#line 477 "cusage.y"
    {
      tdef_valid  TRUE;
      decl_is_empty  FALSE;	
      if (yyval.u_ptr_c_type.ptr_c_var->v_scope_level ! nest_scope_depth)	
	 yyval.u_ptr_c_type.ptr_c_var  decl_tag(yyval.u_ptr_c_type.ptr_c_var->cvname,
                                        yyval.u_ptr_c_type.ptr_c_var->vtype->base,
					struct_nesting);
      struct_nesting++;
	     ;}
    break;

  case 74:
#line 489 "cusage.y"
    {
	struct_nesting++;
	tdef_valid  TRUE;
	;}
    break;

  case 75:
#line 496 "cusage.y"
    {
         yyval.u_ptr_c_type.ptr_c_type  yyval.u_ptr_c_type.ptr_c_var->vtype;
		   ;}
    break;

  case 76:
#line 501 "cusage.y"
    {
      just_defined_typeTRUE;
      struct_nesting--;
      current_tok_p  yyvsp[-1].this_token;	
      if (yyvsp[-2].optok = TOK_STRUCT)
	 yyval.u_ptr_c_type.ptr_c_type  mk_new_su((STR_PTR)NULL, CSTRUCT,
                                                  yyvsp[-1].u_ptr_c_type.ptr_fld_list,
						  struct_nesting);
      else
	 yyval.u_ptr_c_type.ptr_c_type  mk_new_su((STR_PTR)NULL, CUNION,
                                                  yyvsp[-1].u_ptr_c_type.ptr_fld_list,
						  struct_nesting);
		   ;}
    break;

  case 77:
#line 516 "cusage.y"
    {
      just_defined_typeTRUE;
      struct_nesting--;
      current_tok_p  yyvsp[-1].this_token;
      yyval.u_ptr_c_type.ptr_c_type  fin_su_tagged_decl(yyvsp[-2].u_ptr_c_type.ptr_c_var,
      		                                  yyvsp[-1].u_ptr_c_type.ptr_fld_list);
      decl_is_empty  FALSE;
		   ;}
    break;

  case 78:
#line 527 "cusage.y"
    {
		     ;}
    break;

  case 79:
#line 532 "cusage.y"
    {
		  if (is_open_proto_scope(yyval.u_ptr_c_type.ptr_c_var->vtype))	
		     scope_exit(FALSE);	/* close this prototype scope */
		 ;}
    break;

  case 80:
#line 538 "cusage.y"
    {
         current_tok_p  yyval.this_token;
	 if (is_open_proto_scope(yyval.u_ptr_c_type.ptr_c_var->vtype))	
	    scope_exit(FALSE);	/* close this prototype scope */
	 yyval.u_ptr_c_type.ptr_fld_list  mk_field(yyval.u_ptr_c_type.ptr_c_var->cvname,
                                    build_type(yyval.u_ptr_c_type.ptr_c_var->vtype,
                                                  rebuild_type(cur_decl_spec)));
	       ;}
    break;

  case 81:
#line 548 "cusage.y"
    {
	 current_tok_p  yyvsp[0].this_token;	
	 if (is_integral_const(yyvsp[0].u_ptr_c_type.ptr_tree))
	    {
	    temp_long  get_val(yyvsp[0].u_ptr_c_type.ptr_tree, (INTEGER32)0);
	    }
	 else
	    {
	    LANG_ERROR(E_BITS_INT_CONST);
	    temp_long  0;
	    }
	 yyval.u_ptr_c_type.ptr_fld_list  mk_field((STR_PTR)NULL,
                                            mk_bits(rebuild_type(cur_decl_spec),
                                                               temp_long, FALSE));
	       ;}
    break;

  case 82:
#line 565 "cusage.y"
    {
	 current_tok_p  yyvsp[0].this_token;	
	 if (is_integral_const(yyvsp[0].u_ptr_c_type.ptr_tree))
	    {
	    temp_long  get_val(yyvsp[0].u_ptr_c_type.ptr_tree,
                                       bits_in_type[INT_ALIGN]);
	    }
	 else
	 {
	    LANG_ERROR(E_BITS_INT_CONST);
	    temp_long  bits_in_type[INT_ALIGN];
	 }
      yyval.u_ptr_c_type.ptr_fld_list  mk_field(yyvsp[-1].u_ptr_c_type.ptr_c_var->cvname,
                            mk_bits(build_type(yyvsp[-1].u_ptr_c_type.ptr_c_var->vtype,
                                      rebuild_type(cur_decl_spec)),
							temp_long, TRUE));
	       ;}
    break;

  case 83:
#line 585 "cusage.y"
    {
          yyval.u_ptr_c_type.ptr_c_vlist  mk_vlist((VLIST_PTR)NULL,
	  					 yyvsp[0].u_ptr_c_type.ptr_c_var);
	  ;}
    break;

  case 84:
#line 591 "cusage.y"
    {
      current_tok_p  yyvsp[0].this_token;	
      LANG_ERROR(E_MISS_COMMA);
      yyval.u_ptr_c_type.ptr_c_vlist  mk_vlist(yyvsp[-1].u_ptr_c_type.ptr_c_vlist,
                                                     yyvsp[0].u_ptr_c_type.ptr_c_var);
	  ;}
    break;

  case 85:
#line 599 "cusage.y"
    {
      yyval.u_ptr_c_type.ptr_c_vlist  mk_vlist(yyvsp[-2].u_ptr_c_type.ptr_c_vlist,
                                                     yyvsp[0].u_ptr_c_type.ptr_c_var);
	  ;}
    break;

  case 86:
#line 606 "cusage.y"
    {
          set_num(-1, ct_int, &cur_enum_val);
          if (enum_member_count(yyval.u_ptr_c_type.ptr_c_vlist) > MAX_NUM_ENUMS)
	     LANG_ERROR(E_NUM_ENUM_CONSTS_EXCEEDS_CSTAN);
          if (enum_member_count(yyval.u_ptr_c_type.ptr_c_vlist) > max_enum_const)
	     LANG_ERROR(E_NUM_ENUM_CONSTS_EXCEEDS_LIMIT);
	  ;}
    break;

  case 88:
#line 617 "cusage.y"
    {
	  LANG_ERROR(E_ENUM_TRAIL_COMMA);
	  ;}
    break;

  case 89:
#line 623 "cusage.y"
    {
        KandR_Warn(yyval.this_token->tok.name, KR_ENUM);
        yyval.u_ptr_c_type.ptr_c_type  (C_TYPE_PTR)NULL;
        tdef_valid  FALSE;
	;}
    break;

  case 90:
#line 631 "cusage.y"
    {
      yyval.u_ptr_c_type.ptr_c_var  tagged_type(yyvsp[0].u_ptr_c_type.ptr_ident, CENUM);
	;}
    break;

  case 91:
#line 637 "cusage.y"
    {
      decl_is_empty  FALSE;	
      if (yyval.u_ptr_c_type.ptr_c_var->v_scope_level ! nest_scope_depth)
	 yyval.u_ptr_c_type.ptr_c_var  decl_tag(yyval.u_ptr_c_type.ptr_c_var->cvname,
                                              CENUM,
					      struct_nesting);
	;}
    break;

  case 92:
#line 647 "cusage.y"
    {
      yyval.u_ptr_c_type.ptr_c_type  yyval.u_ptr_c_type.ptr_c_var->vtype;
		;}
    break;

  case 93:
#line 652 "cusage.y"
    {
      		 mk_enum(&(yyval.u_ptr_c_type.ptr_c_type), yyvsp[-1].u_ptr_c_type.ptr_c_vlist);
      		 just_defined_typeTRUE;
      		 decl_is_empty  FALSE;
		 ;}
    break;

  case 94:
#line 659 "cusage.y"
    {
	 	 current_tok_p  yyvsp[0].this_token;
	 	 mk_enum(&(yyval.u_ptr_c_type.ptr_c_var->vtype),
                                                   yyvsp[-1].u_ptr_c_type.ptr_c_vlist);
	 	 yyval.u_ptr_c_type.ptr_c_type  yyval.u_ptr_c_type.ptr_c_var->vtype;
         	 just_defined_typeTRUE;
         	 decl_is_empty  FALSE;
		 ;}
    break;

  case 95:
#line 670 "cusage.y"
    {
	       tdef_valid  TRUE;	/* to allow casts in ensuing exp */
	       ;}
    break;

  case 96:
#line 676 "cusage.y"
    {
             current_tok_p  yyvsp[0].this_token;	
             if (signed_compare(&cur_enum_val,
				&int_info->val[IS_SIGNED].max_val) = COMP_EQ)
	        LANG_ERROR(E_ENUM_CONS_TOO_LARG);
             else
                {
                if (signed_compare(&cur_enum_val,
			   &int_info->val[IS_SIGNED].max_port_val) ! COMP_LT)
	           LANG_ERROR(E_ENUM_VALU_EXCEED_MIN_VAL);
                inc_number(&cur_enum_val, IS_SIGNED);	
                }
             yyval.u_ptr_c_type.ptr_c_var  mk_efield(yyvsp[0].u_ptr_c_type.ptr_ident,
                                                   &cur_enum_val);
	     ;}
    break;

  case 97:
#line 693 "cusage.y"
    {
	 current_tok_p  yyvsp[0].this_token;	
	 if (is_integral_const(yyvsp[0].u_ptr_c_type.ptr_tree))
	    {
	    get_folded_num(&cur_enum_val, yyvsp[0].u_ptr_c_type.ptr_tree);
	    }
	 else
	    LANG_ERROR(E_ENUM_INT_CONST);
      yyval.u_ptr_c_type.ptr_c_var  mk_efield(yyvsp[-1].u_ptr_c_type.ptr_ident,
                                                  &cur_enum_val);
	     ;}
    break;

  case 98:
#line 707 "cusage.y"
    {
                  yyval.u_ptr_c_type.ptr_c_plist  mk_plist((PARAM_LIST_PTR)NULL,
                                             new_var(yyvsp[0].u_ptr_c_type.ptr_ident,
                                                    nest_scope_depth));
		  ;}
    break;

  case 99:
#line 714 "cusage.y"
    {
             yyval.u_ptr_c_type.ptr_c_plist  mk_plist(yyvsp[-2].u_ptr_c_type.ptr_c_plist,
                                      new_var(yyvsp[0].u_ptr_c_type.ptr_ident,
                                               nest_scope_depth));
		  ;}
    break;

  case 100:
#line 721 "cusage.y"
    {
           yyval.u_ptr_c_type.ptr_c_var  new_var(yyvsp[0].u_ptr_c_type.ptr_ident,
                                               nest_scope_depth);
           decl_is_empty  FALSE;
	   ;}
    break;

  case 101:
#line 729 "cusage.y"
    {
           current_tok_p  yyvsp[-1].this_token;
	   if (cc_extensions[CPP_Extension] &&
	       just_defined_type)
	      {
	      just_defined_typeFALSE;
	      LANG_ERROR(E_CPP_DEF_TYPE_RET);
	      }
           tdef_valid  TRUE;
           nested_params++;		
           scope_entry();	/* open prototype scope */
	   ;}
    break;

  case 102:
#line 743 "cusage.y"
    {
      current_tok_p  yyvsp[0].this_token;
      if (is_open_proto_scope(yyval.u_ptr_c_type.ptr_c_var->vtype))	
         scope_exit(FALSE);	/* close this prototype scope */
      yyval.u_ptr_c_type.ptr_c_var->vtype 
                                 build_type(yyval.u_ptr_c_type.ptr_c_var->vtype,
                                            mk_func((C_TYPE_PTR)NULL,
					            OLD_FUNC_DECL,
						    (PARAM_LIST_PTR)NULL));
      tdef_valid  TRUE;
      nested_params--;
	   ;}
    break;

  case 103:
#line 757 "cusage.y"
    {
	   yyval  yyvsp[-1];
	   ;}
    break;

  case 104:
#line 762 "cusage.y"
    {
	 current_tok_p  yyvsp[-1].this_token;
	 if (is_open_proto_scope(yyval.u_ptr_c_type.ptr_c_var->vtype))	
	    scope_exit(FALSE);	/* close this prototype scope */
	 yyval.u_ptr_c_type.ptr_c_var->vtype 
				 build_type(yyval.u_ptr_c_type.ptr_c_var->vtype,
                                             mk_func((C_TYPE_PTR)NULL,
					     	     OLD_FUNC_DECL,
                                               	     yyvsp[-1].u_ptr_c_type.ptr_c_plist));
         tdef_valid  TRUE;
         nested_params--;
	   ;}
    break;

  case 105:
#line 776 "cusage.y"
    {
	 current_tok_p  yyvsp[-1].this_token;
	 if (is_open_proto_scope(yyval.u_ptr_c_type.ptr_c_var->vtype))	
	    scope_exit(FALSE);	/* close this prototype scope */
	 yyval.u_ptr_c_type.ptr_c_var->vtype 
				build_type(yyval.u_ptr_c_type.ptr_c_var->vtype,
                                              mk_func((C_TYPE_PTR)NULL,
					      	      PROTOTYPE_FUNC,
                                               	      yyvsp[-1].u_ptr_c_type.ptr_c_plist));
         tdef_valid  TRUE;
         nested_params--;
	   ;}
    break;

  case 108:
#line 793 "cusage.y"
    {
      current_tok_p  yyvsp[-1].this_token;
      yyval.u_ptr_c_type.ptr_c_var->vtype 
				 build_type(yyval.u_ptr_c_type.ptr_c_var->vtype,
                                          mk_array((C_TYPE_PTR)NULL,
					  	   (TYPE_SIZE_TYPE)0));
	   ;}
    break;

  case 109:
#line 802 "cusage.y"
    {
	 current_tok_p  yyvsp[-1].this_token;	
	 if (is_integral_const(yyvsp[-1].u_ptr_c_type.ptr_tree))
	    {
	    temp_long  get_val(yyvsp[-1].u_ptr_c_type.ptr_tree,
						(INTEGER32)0);
	    }
	 else
	    {
	    LANG_ERROR(E_ARRAY_BOUND_INT_CONST);
	    temp_long  0;
	    }
         yyval.u_ptr_c_type.ptr_c_var->vtype 
				 build_type(yyval.u_ptr_c_type.ptr_c_var->vtype,
                                                  mk_array((C_TYPE_PTR)NULL,
						  	    temp_long));
	   ;}
    break;

  case 111:
#line 824 "cusage.y"
    {
         yyvsp[-1].u_ptr_c_type.ptr_c_var->vtype 
				build_type(yyvsp[-1].u_ptr_c_type.ptr_c_var->vtype,
                                                 yyvsp[-2].u_ptr_c_type.ptr_c_type);
         yyval  yyvsp[-1];
	   ;}
    break;

  case 113:
#line 834 "cusage.y"
    {
      yyvsp[0].u_ptr_c_type.ptr_c_var->vtype 
				 build_type(yyvsp[0].u_ptr_c_type.ptr_c_var->vtype,
                                                 yyvsp[-1].u_ptr_c_type.ptr_c_type);
      yyval  yyvsp[0];
		;}
    break;

  case 114:
#line 842 "cusage.y"
    {
      if (is_open_proto_scope(yyval.u_ptr_c_type.ptr_c_var->vtype))	
         {
	 scope_exit(FALSE);	/* close prototype scope */
	 /* and transform fn params
          * add in the current decl specifier
	  */
	 strip_idents_from_formals(yyval.u_ptr_c_type.ptr_c_var->vtype);
         }
      
	;}
    break;

  case 115:
#line 856 "cusage.y"
    {
      tdef_valid  TRUE;	/* allow casts in ensuing initializer */
      if (is_open_proto_scope(yyval.u_ptr_c_type.ptr_c_var->vtype))	
         {
	 scope_exit(FALSE);	/* close prototype scope */
	 /*
	  * and transform fn params
	  */
	 strip_idents_from_formals(yyval.u_ptr_c_type.ptr_c_var->vtype);
         }
      current_tok_p  yyvsp[-1].this_token;	
      init_declare(&(yyval.u_ptr_c_type.ptr_c_var));
      cur_scope->has_init  TRUE;	
      start_initializer(yyval.u_ptr_c_type.ptr_c_var);
	  ;}
    break;

  case 116:
#line 873 "cusage.y"
    {
	      current_tok_p  yyvsp[-1].this_token;	
	      LANG_ERROR(E_AT_LOCATION);
	      ;}
    break;

  case 120:
#line 884 "cusage.y"
    {
	     ;}
    break;

  case 122:
#line 891 "cusage.y"
    {
	  ;}
    break;

  case 123:
#line 896 "cusage.y"
    {
	     open_curly();
	     ;}
    break;

  case 124:
#line 902 "cusage.y"
    {
	   cl_curly(TRUE);
	   ;}
    break;

  case 125:
#line 908 "cusage.y"
    {
           chk_lvalue_conversions(yyval.u_ptr_c_type.ptr_tree, TRUE);
           process_init(yyval.u_ptr_c_type.ptr_tree, TRUE);
	   ;}
    break;

  case 126:
#line 914 "cusage.y"
    {
	   yyvalyyvsp[0];
	   ;}
    break;

  case 128:
#line 921 "cusage.y"
    {
	   ;}
    break;

  case 129:
#line 926 "cusage.y"
    {
	       yyval  yyvsp[-1];
	       ;}
    break;

  case 130:
#line 932 "cusage.y"
    {
               current_tok_p  yyvsp[-1].this_token;
               tdef_valid  TRUE;
               nested_params++;		
               scope_entry();	/* open prototype scope */
	       ;}
    break;

  case 131:
#line 941 "cusage.y"
    {
             tdef_valid  TRUE;
             nested_params++;		
             scope_entry();	/* open prototype scope */
	     ;}
    break;

  case 133:
#line 951 "cusage.y"
    {
      current_tok_p  yyvsp[0].this_token;
      scope_exit(TRUE);		/* close prototype scope */
      yyval.u_ptr_c_type.ptr_c_type  build_type(yyvsp[-1].u_ptr_c_type.ptr_c_type,
                                              mk_func((C_TYPE_PTR)NULL,
					      	      OLD_FUNC_DECL,
						      (PARAM_LIST_PTR)NULL));
      tdef_valid  TRUE;
      nested_params--;
	       ;}
    break;

  case 134:
#line 963 "cusage.y"
    {
      scope_exit(TRUE);		/* close prototype scope */
      current_tok_p  yyvsp[-2].this_token;	/* we do not want a
					 * variable list here! */
      yyval.u_ptr_c_type.ptr_c_type  mk_func((C_TYPE_PTR)NULL, PROTOTYPE_FUNC,
                                            yyvsp[-1].u_ptr_c_type.ptr_c_plist);
      strip_idents_from_formals(yyval.u_ptr_c_type.ptr_c_type);
      yyval.u_ptr_c_type.ptr_c_type  build_type(yyvsp[-2].u_ptr_c_type.ptr_c_type,
                                                 yyval.u_ptr_c_type.ptr_c_type);
      tdef_valid  TRUE;
      nested_params--;
	       ;}
    break;

  case 135:
#line 977 "cusage.y"
    {
      scope_exit(TRUE);		/* close prototype scope */
      current_tok_p  yyvsp[-2].this_token;	/* we do not want a
					 * variable list here! */
      yyval.u_ptr_c_type.ptr_c_type  mk_func((C_TYPE_PTR)NULL, PROTOTYPE_FUNC,
                                               yyvsp[-1].u_ptr_c_type.ptr_c_plist);
      strip_idents_from_formals(yyval.u_ptr_c_type.ptr_c_type);
      tdef_valid  TRUE;
      nested_params--;
	       ;}
    break;

  case 136:
#line 989 "cusage.y"
    {
      current_tok_p  yyvsp[0].this_token;
      scope_exit(TRUE);		/* close prototype scope */
      yyval.u_ptr_c_type.ptr_c_type  mk_func((C_TYPE_PTR)NULL, OLD_FUNC_DECL,
      						(PARAM_LIST_PTR)NULL);
      tdef_valid  TRUE;
      nested_params--;
	       ;}
    break;

  case 137:
#line 999 "cusage.y"
    {
      current_tok_p  yyvsp[-1].this_token;
      yyval.u_ptr_c_type.ptr_c_type  build_type(yyvsp[-2].u_ptr_c_type.ptr_c_type,
                                              mk_array((C_TYPE_PTR)NULL,
					      	       (TYPE_SIZE_TYPE)0));
	       ;}
    break;

  case 138:
#line 1007 "cusage.y"
    {
	 current_tok_p  yyvsp[-1].this_token;	
	 if (is_integral_const(yyvsp[-1].u_ptr_c_type.ptr_tree))
	    {
	    temp_long  get_val(yyvsp[-1].u_ptr_c_type.ptr_tree, (INTEGER32)0);
	    }
	 else
	    {
	    LANG_ERROR(E_ARRAY_BOUND_INT_CONST);
	    temp_long  0;
	    }
         yyval.u_ptr_c_type.ptr_c_type  build_type(yyvsp[-3].u_ptr_c_type.ptr_c_type,
                                                 mk_array((C_TYPE_PTR)NULL,
						 	  temp_long));
	       ;}
    break;

  case 139:
#line 1024 "cusage.y"
    {
            yyval.u_ptr_c_type.ptr_c_type  mk_array((C_TYPE_PTR)NULL, (TYPE_SIZE_TYPE)0);
	       ;}
    break;

  case 140:
#line 1029 "cusage.y"
    {
	 current_tok_p  yyvsp[-1].this_token;	
	 if (is_integral_const(yyvsp[-1].u_ptr_c_type.ptr_tree))
	    {
	    temp_long  get_val(yyvsp[-1].u_ptr_c_type.ptr_tree,
						(INTEGER32)0);
	    }
	 else
	    {
	    LANG_ERROR(E_ARRAY_BOUND_INT_CONST);
	    temp_long  0;
	    }
         yyval.u_ptr_c_type.ptr_c_type  mk_array((C_TYPE_PTR)NULL,
						      temp_long);
	       ;}
    break;

  case 142:
#line 1049 "cusage.y"
    {
      yyval.u_ptr_c_type.ptr_c_type  build_type(yyvsp[0].u_ptr_c_type.ptr_c_type,
                                                yyvsp[-1].u_ptr_c_type.ptr_c_type);
	       ;}
    break;

  case 143:
#line 1054 "cusage.y"
    {
      yyval.u_ptr_c_type.ptr_c_type  yyvsp[-1].u_ptr_c_type.ptr_c_type ;
	       ;}
    break;

  case 145:
#line 1063 "cusage.y"
    {
      yyval.u_ptr_c_type.ptr_c_type  build_type(yyval.u_ptr_c_type.ptr_c_type,
                                                rebuild_type(cur_decl_spec));
	    ;}
    break;

  case 146:
#line 1069 "cusage.y"
    {
      yyval.u_ptr_c_type.ptr_c_type  rebuild_type(cur_decl_spec);
	    ;}
    break;

  case 147:
#line 1075 "cusage.y"
    {
      yyval.u_ptr_c_type.ptr_c_vlist  mk_vlist((VLIST_PTR)NULL,
      					     yyvsp[0].u_ptr_c_type.ptr_c_var);
      tdef_valid  FALSE;
		  ;}
    break;

  case 148:
#line 1082 "cusage.y"
    {
			/* NOTE: we build var list back to front!!!! */
      yyval.u_ptr_c_type.ptr_c_vlist  mk_vlist(yyvsp[-2].u_ptr_c_type.ptr_c_vlist,
                                                   yyvsp[0].u_ptr_c_type.ptr_c_var);
      tdef_valid  FALSE;
		  ;}
    break;

  case 149:
#line 1091 "cusage.y"
    {
		    tdef_valid  FALSE;
		    ;}
    break;

  case 150:
#line 1096 "cusage.y"
    {
      current_tok_p  yyvsp[0].this_token;
      yyval.u_ptr_c_type.ptr_fld_list  append_fields(yyvsp[-2].u_ptr_c_type.ptr_fld_list,
                                                 yyvsp[0].u_ptr_c_type.ptr_fld_list);
      tdef_valid  FALSE;
		    ;}
    break;

  case 151:
#line 1105 "cusage.y"
    {
	 if (is_open_proto_scope(yyval.u_ptr_c_type.ptr_c_var->vtype))	
	    scope_exit(FALSE);	/* close this prototype scope */
	 yyval.u_ptr_c_type.ptr_c_var->vtype  build_type(yyval.u_ptr_c_type.ptr_c_var->vtype,
                                                  rebuild_type(cur_decl_spec));
	 yyval.u_ptr_c_type.ptr_c_vlist  mk_vlist((VLIST_PTR)NULL,
	 					yyval.u_ptr_c_type.ptr_c_var);
         tdef_valid  FALSE;
	     ;}
    break;

  case 152:
#line 1116 "cusage.y"
    {
	 if (is_open_proto_scope(yyvsp[0].u_ptr_c_type.ptr_c_var->vtype))	
	    scope_exit(FALSE);	/* close this prototype scope */
	 yyvsp[0].u_ptr_c_type.ptr_c_var->vtype  build_type(yyvsp[0].u_ptr_c_type.ptr_c_var->vtype,
                                              rebuild_type(cur_decl_spec));
	 yyval.u_ptr_c_type.ptr_c_vlist  mk_vlist(yyvsp[-2].u_ptr_c_type.ptr_c_vlist,
                                                    yyvsp[0].u_ptr_c_type.ptr_c_var);
         tdef_valid  FALSE;
	     ;}
    break;

  case 154:
#line 1129 "cusage.y"
    {
	    ;}
    break;

  case 155:
#line 1133 "cusage.y"
    {
	   ;}
    break;

  case 169:
#line 1169 "cusage.y"
    {
	      not_labelledFALSE;
	      ;}
    break;

  case 173:
#line 1182 "cusage.y"
    {
	     ;}
    break;

  case 174:
#line 1186 "cusage.y"
    {
	     ;}
    break;

  case 175:
#line 1190 "cusage.y"
    {
	     ;}
    break;

  case 177:
#line 1195 "cusage.y"
    {
	     ;}
    break;

  case 185:
#line 1211 "cusage.y"
    {
	  ;}
    break;

  case 186:
#line 1216 "cusage.y"
    {
	     ;}
    break;

  case 187:
#line 1221 "cusage.y"
    {
	 ;}
    break;

  case 188:
#line 1226 "cusage.y"
    {
	    ;}
    break;

  case 189:
#line 1231 "cusage.y"
    {
		;}
    break;

  case 190:
#line 1236 "cusage.y"
    {
	    ;}
    break;

  case 191:
#line 1242 "cusage.y"
    {
	  ;}
    break;

  case 192:
#line 1246 "cusage.y"
    {
	  ;}
    break;

  case 193:
#line 1251 "cusage.y"
    {
	  ;}
    break;

  case 194:
#line 1256 "cusage.y"
    {
		 ;}
    break;

  case 195:
#line 1260 "cusage.y"
    {
		 ;}
    break;

  case 196:
#line 1264 "cusage.y"
    {
		 ;}
    break;

  case 197:
#line 1268 "cusage.y"
    {
		 ;}
    break;

  case 198:
#line 1273 "cusage.y"
    {
	     ;}
    break;

  case 199:
#line 1278 "cusage.y"
    {
		  ;}
    break;

  case 200:
#line 1283 "cusage.y"
    {
	      ;}
    break;

  case 201:
#line 1287 "cusage.y"
    {
	      ;}
    break;

  case 202:
#line 1293 "cusage.y"
    {
	;}
    break;

  case 203:
#line 1297 "cusage.y"
    {
	;}
    break;

  case 204:
#line 1301 "cusage.y"
    {
	;}
    break;

  case 205:
#line 1306 "cusage.y"
    {
      yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[-1].u_ptr_c_type.ptr_tree, (TPTR_TYPE)NULL,
                                         TOK_OPEN_RND,
					 yyvsp[-2].this_token->tok.parent_macro);
	    ;}
    break;

  case 206:
#line 1314 "cusage.y"
    {
              current_tok_p  yyvsp[0].this_token;	
	      id_nameyyvsp[0].u_ptr_c_type.ptr_ident;
              yyvsp[0].u_ptr_c_type.ptr_c_var  lookup_var(id_name,
					       yyvsp[0].this_token->tok.parent_macro);
              yyval.u_ptr_c_type.ptr_tree  mk_leaf(&(yyvsp[0]), TOK_IDENTIFIER);
	      ;}
    break;

  case 207:
#line 1323 "cusage.y"
    {
		 ;}
    break;

  case 210:
#line 1332 "cusage.y"
    {
              array_bnd_chk(yyvsp[-3].u_ptr_c_type.ptr_tree, yyvsp[-1].u_ptr_c_type.ptr_tree);
              current_tok_p  yyvsp[-2].this_token;
              yyval.u_ptr_c_type.ptr_tree 
		        mk_tree(yyvsp[-3].u_ptr_c_type.ptr_tree,
                                yyvsp[-1].u_ptr_c_type.ptr_tree,
				TOK_ARRAY_REF,
		                yyvsp[-2].this_token->tok.parent_macro);
	      ;}
    break;

  case 211:
#line 1343 "cusage.y"
    {
              current_tok_p  yyvsp[-2].this_token;
              yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[-2].u_ptr_c_type.ptr_tree,
					    (TPTR_TYPE)NULL,
                                            TOK_FNC_CALL,
				            current_tok_p->tok.parent_macro);
	       ;}
    break;

  case 212:
#line 1352 "cusage.y"
    {
      current_tok_p  yyvsp[-1].this_token;
      temp_tree_ptr  tilt_args(yyvsp[-1].u_ptr_c_type.ptr_tree);
      current_tok_p  yyvsp[-3].this_token;
      yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[-3].u_ptr_c_type.ptr_tree,
                                         temp_tree_ptr,
					 TOK_FNC_CALL,
				         yyvsp[-2].this_token->tok.parent_macro);
		 ;}
    break;

  case 213:
#line 1363 "cusage.y"
    {
      current_tok_p  yyvsp[-1].this_token;
      yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[-2].u_ptr_c_type.ptr_tree,
                                         (TPTR_TYPE)yyvsp[0].u_ptr_c_type.ptr_ident,
                                         TOK_DIR_SELECT,
				         yyvsp[-1].this_token->tok.parent_macro);
	/* note type punning of Ptr_Ident with Ptr_Tree */
		 ;}
    break;

  case 214:
#line 1373 "cusage.y"
    {
      current_tok_p  yyvsp[-1].this_token;
      yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[-2].u_ptr_c_type.ptr_tree,
                                         (TPTR_TYPE)yyvsp[0].u_ptr_c_type.ptr_ident,
                                         TOK_INDIR_SELECT,
				         yyvsp[-1].this_token->tok.parent_macro);
		 ;}
    break;

  case 215:
#line 1382 "cusage.y"
    {
      current_tok_p  yyvsp[0].this_token;
      yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[-1].u_ptr_c_type.ptr_tree,
					 (TPTR_TYPE)NULL,
                                         yyvsp[0].optok,
				         yyvsp[0].this_token->tok.parent_macro);
	         ;}
    break;

  case 216:
#line 1391 "cusage.y"
    {
      /*
       * S. 9 is tokenised as IDENTIFIER DOT LITERAL
       */
      current_tok_p  yyvsp[-1].this_token;
      yyvalyyvsp[-2];
      LANG_ERROR(E_EXT_BIT_SELECT);
		 ;}
    break;

  case 217:
#line 1401 "cusage.y"
    {
      /*
       * S.9 is tokenised as IDENTIFIER LITERAL, not
       * IDENTIFIER DOT LITERAL
       * where the literal will be a floating point value
       */
      current_tok_p  yyvsp[0].this_token;
      yyvalyyvsp[-1];
		 ;}
    break;

  case 218:
#line 1413 "cusage.y"
    {
	     yyval.optokTOK_POST_PLUS;
	     ;}
    break;

  case 219:
#line 1418 "cusage.y"
    {
	     yyval.optokTOK_POST_MINUS;
	     ;}
    break;

  case 221:
#line 1425 "cusage.y"
    {
	    current_tok_p  yyvsp[-1].this_token;
	    yyval.u_ptr_c_type.ptr_tree  mk_sizeof(yyvsp[-1].u_ptr_c_type.ptr_c_type,
                                                  FALSE,
				                  yyvsp[-1].this_token->tok.parent_macro);
            tdef_valid  TRUE;
	    ;}
    break;

  case 222:
#line 1434 "cusage.y"
    {
	    current_tok_p  yyvsp[0].this_token;
	    yyval.u_ptr_c_type.ptr_tree  mk_sizeof(yyvsp[0].u_ptr_c_type.ptr_tree->exptype,
                                              yyvsp[0].u_ptr_c_type.ptr_tree->is_l_value,
				              yyvsp[0].this_token->tok.parent_macro);
	     ;}
    break;

  case 223:
#line 1442 "cusage.y"
    {
	     ;}
    break;

  case 224:
#line 1446 "cusage.y"
    {
	     ;}
    break;

  case 225:
#line 1450 "cusage.y"
    {
             current_tok_p  yyvsp[0].this_token;
             yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[0].u_ptr_c_type.ptr_tree,
	     					(TPTR_TYPE)NULL,
                                                yyvsp[-1].optok,
				                yyvsp[-1].this_token->tok.parent_macro);
	     ;}
    break;

  case 226:
#line 1459 "cusage.y"
    {
             current_tok_p  yyvsp[0].this_token;
             yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[0].u_ptr_c_type.ptr_tree,
	     					(TPTR_TYPE)NULL,
                                         	TOK_CONT_OF,
				         	yyvsp[-1].this_token->tok.parent_macro);
	     ;}
    break;

  case 227:
#line 1468 "cusage.y"
    {
             current_tok_p  yyvsp[0].this_token;
             yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[0].u_ptr_c_type.ptr_tree,
	     					(TPTR_TYPE)NULL,
                                         	TOK_ADDR_OF,
				         	yyvsp[-1].this_token->tok.parent_macro);
	     ;}
    break;

  case 228:
#line 1477 "cusage.y"
    {
             current_tok_p  yyvsp[0].this_token;
             yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[0].u_ptr_c_type.ptr_tree,
	     					(TPTR_TYPE)NULL,
                                         	yyvsp[-1].optok,
				         	yyvsp[-1].this_token->tok.parent_macro);
	     ;}
    break;

  case 229:
#line 1487 "cusage.y"
    {
             /*
	      * The NULL pointer constant, a 'safe' value
	      */
	     yyval.u_ptr_c_type.ptr_tree  mk_l_const(0,
				                   yyvsp[-1].this_token->tok.parent_macro);
	     ;}
    break;

  case 230:
#line 1496 "cusage.y"
    {
	    yyval.optokTOK_PRE_PLUS;
	    ;}
    break;

  case 231:
#line 1501 "cusage.y"
    {
	    yyval.optokTOK_PRE_MINUS;
	    ;}
    break;

  case 232:
#line 1507 "cusage.y"
    {
      	    KandR_UnPlus(yyval.this_token->tok.name);
	    ;}
    break;

  case 236:
#line 1517 "cusage.y"
    {
	    tdef_valid  TRUE;
	    yyval  yyvsp[-1];
	    ;}
    break;

  case 238:
#line 1525 "cusage.y"
    {
           current_tok_p  yyval.this_token;
           yyval.u_ptr_c_type.ptr_tree  mk_cast(yyvsp[0].u_ptr_c_type.ptr_tree,
                                                yyval.u_ptr_c_type.ptr_c_type,
				         	yyvsp[-1].this_token->tok.parent_macro);
	   ;}
    break;

  case 240:
#line 1537 "cusage.y"
    {
      current_tok_p  yyvsp[-1].this_token;
      yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[-2].u_ptr_c_type.ptr_tree,
                                         yyvsp[0].u_ptr_c_type.ptr_tree, yyvsp[-1].optok,
				         yyvsp[-1].this_token->tok.parent_macro);
		;}
    break;

  case 241:
#line 1546 "cusage.y"
    {
	  yyval.optok  TOK_TIMES;
	  ;}
    break;

  case 245:
#line 1556 "cusage.y"
    {
      current_tok_p  yyvsp[-1].this_token;
      yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[-2].u_ptr_c_type.ptr_tree,
                                        yyvsp[0].u_ptr_c_type.ptr_tree, yyvsp[-1].optok,
				        yyvsp[-1].this_token->tok.parent_macro);
	       ;}
    break;

  case 246:
#line 1565 "cusage.y"
    {
	 yyval.optok  TOK_ADD;
	 ;}
    break;

  case 247:
#line 1570 "cusage.y"
    {
	 yyval.optok  TOK_MINUS;
	 ;}
    break;

  case 249:
#line 1578 "cusage.y"
    {
                 current_tok_p  yyvsp[-1].this_token;
                 yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[-2].u_ptr_c_type.ptr_tree,
                                         yyvsp[0].u_ptr_c_type.ptr_tree, yyvsp[-1].optok,
				         yyvsp[-1].this_token->tok.parent_macro);
		 ;}
    break;

  case 253:
#line 1593 "cusage.y"
    {
               current_tok_p  yyvsp[-1].this_token;
               yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[-2].u_ptr_c_type.ptr_tree,
                                         yyvsp[0].u_ptr_c_type.ptr_tree,
                                         yyvsp[-1].optok,
				         yyvsp[-1].this_token->tok.parent_macro);
	       ;}
    break;

  case 259:
#line 1610 "cusage.y"
    {
               current_tok_p  yyvsp[-1].this_token;
               yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[-2].u_ptr_c_type.ptr_tree,
                                         yyvsp[0].u_ptr_c_type.ptr_tree,
                                         yyvsp[-1].optok,
				         yyvsp[-1].this_token->tok.parent_macro);
	       ;}
    break;

  case 263:
#line 1626 "cusage.y"
    {
                  current_tok_p  yyvsp[-1].this_token;
                  yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[-2].u_ptr_c_type.ptr_tree,
                                         yyvsp[0].u_ptr_c_type.ptr_tree,
                                         TOK_BIT_AND,
				         yyvsp[-1].this_token->tok.parent_macro);
		  ;}
    break;

  case 265:
#line 1638 "cusage.y"
    {
                  current_tok_p  yyvsp[-1].this_token;
                  yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[-2].u_ptr_c_type.ptr_tree,
                                         yyvsp[0].u_ptr_c_type.ptr_tree,
                                         TOK_BIT_XOR,
				         yyvsp[-1].this_token->tok.parent_macro);
		  ;}
    break;

  case 267:
#line 1650 "cusage.y"
    {
                 current_tok_p  yyvsp[-1].this_token;
                 yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[-2].u_ptr_c_type.ptr_tree,
                                         yyvsp[0].u_ptr_c_type.ptr_tree,
                                         TOK_BIT_OR,
				         yyvsp[-1].this_token->tok.parent_macro);
		 ;}
    break;

  case 269:
#line 1662 "cusage.y"
    {
               current_tok_p  yyvsp[-1].this_token;
               yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[-2].u_ptr_c_type.ptr_tree,
                                         yyvsp[0].u_ptr_c_type.ptr_tree,
                                         TOK_LOG_AND,
				         yyvsp[-1].this_token->tok.parent_macro);
	       ;}
    break;

  case 271:
#line 1674 "cusage.y"
    {
              current_tok_p  yyvsp[-1].this_token;
              yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[-2].u_ptr_c_type.ptr_tree,
                                         yyvsp[0].u_ptr_c_type.ptr_tree,
                                         TOK_LOG_OR,
				         yyvsp[-1].this_token->tok.parent_macro);
	      ;}
    break;

  case 273:
#line 1686 "cusage.y"
    {
           current_tok_p  yyvsp[-3].this_token;
           yyval.u_ptr_c_type.ptr_tree 
			mk_tree(yyvsp[-4].u_ptr_c_type.ptr_tree,
				mk_tree(yyvsp[-2].u_ptr_c_type.ptr_tree,
                                        yyvsp[0].u_ptr_c_type.ptr_tree,
                                        TOK_COLON,
				        yyvsp[-1].this_token->tok.parent_macro),
				TOK_QUESTION,
				yyvsp[-3].this_token->tok.parent_macro);
	   ;}
    break;

  case 275:
#line 1708 "cusage.y"
    {
             if (yyvsp[-2].u_ptr_c_type.ptr_tree->op = TOK_CAST)
	        {
                current_tok_p  yyvsp[-2].this_token;
	        LANG_ERROR(E_CAST_ON_LHS_ASSIGN);
                while (yyvsp[-2].u_ptr_c_type.ptr_tree->op = TOK_CAST)
                   yyvsp[-2].u_ptr_c_type.ptr_treeRHS_EXPR(yyvsp[-2].u_ptr_c_type.ptr_tree);
		}
/*STD1232*/
             current_tok_p  yyvsp[-1].this_token;
             yyval.u_ptr_c_type.ptr_tree  mk_tree(yyvsp[-2].u_ptr_c_type.ptr_tree,
                                         yyvsp[0].u_ptr_c_type.ptr_tree,
                                         yyvsp[-1].optok,
				         yyvsp[-1].this_token->tok.parent_macro);
	     ;}
    break;

  case 288:
#line 1741 "cusage.y"
    {
	    ;}
    break;

  case 289:
#line 1745 "cusage.y"
    {
	    ;}
    break;

  case 290:
#line 1750 "cusage.y"
    {
           current_tok_p  yyvsp[0].this_token;
           cvt_comma_expr(yyvsp[0].u_ptr_c_type.ptr_tree);
	   ;}
    break;


    }

/* Line 991 of yacc.c.  */
#line 3628 "cusage.tab.c"

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


#line 1755 "cusage.y"



