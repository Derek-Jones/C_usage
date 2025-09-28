                        /* global.h, 25 Feb 12 */

#include "../config.h"

#if __MINGW32__
#define MS_DOS 1
#undef HAVE_FNMATCH_H
#endif

#include <limits.h>

#if HAVE_GMP 
    #include <gmp.h>
    typedef mpf_t fp_t;    
    #define FP_ARITHMETIC  "multiple-precision arithmetic"
#elif HAVE_LONG_DOUBLE
    typedef long double fp_t;
    #define FP_ARITHMETIC  "long double-precision arithmetic"
#else
    typedef double fp_t;   
    #define FP_ARITHMETIC  "double-precision arithmetic"
#endif

#if HAVE_ARCHIVE_H
  #define ARCHIVE_STR "with archive support"
#else
  #define ARCHIVE_STR "no archive support"
#endif

#if defined(FULL_POSIX)
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/* check file is:
        a regular file (not a directory etc)
        accessible for execution
*/
#define ISEXECUTABLE(file)      (stat(file,&ISexec),                    \
                                        (S_ISREG(ISexec.st_mode)) &&    \
                                        (access(file, X_OK) == 0))
#endif

#define GETVAR(var)      getenv(var)

#define MAX_WORD_LEN 80

// We want this to be no more than the maximum number of
// digits usually stored in the interesting number database.
#define MAX_NUM_DIGITS 40
#define MAX_MSG_LEN 120
#define DFLT_NEED_SIZE 15

#define FALSE 0
#define TRUE 1

#ifndef MAX_PATHNAME_LEN
#define MAX_PATHNAME_LEN 256      /* Maximum length of a path */
#endif

#ifdef NAME_MAX /* chars in the base filename */
   #define MAX_BASE_FILE_LEN (NAME_MAX)
#elif defined _POSIX_NAME_MAX
   #define MAX_BASE_FILE_LEN (_POSIX_NAME_MAX)
#else
   #define MAX_BASE_FILE_LEN 64
#endif

#define MAX_FILENAME_LEN (MAX_PATHNAME_LEN+MAX_BASE_FILE_LEN)

#define path_separator      ";"  /* string to separate several paths */

#if MS_DOS
#define directory_separator "\\"  /* string to separate directories */
#define Cur_Dir_Str         ".\\"
#else
#define directory_separator "/"  /* string to separate directories */
#define Cur_Dir_Str         "./"
#endif

#define DSEP_LEN 1
#define extension_separator "."  /* obvious ! */
#define device_separator    ":"  /* separate device from path */

/* environment variable used to find path information (prior to reading cfg) */
#ifndef PATHVAR
#define PATHVAR         "PATH"
#endif

#define NULL_CHAR '\0'
#define DP_CHAR '.'

#define DB_DIR "ndb/"
#define DEFAULT_DB "default.txt"


/*
 * A variety of maximum values for various quantities
 */
#define FILE_SEP_CHAR 242
#define FILENAME_SEP_CHAR 243

#define IDENT_SAVE_LEN 200
#define MIN_DEFINC_LINES 100
#define MAX_BIT_WIDTH (sizeof(LONGEST_UINT)*CHAR_BIT+1)
#define MAX_CCONST_LEN 17
#define MAX_FLT_WIDTH 60
#define MAX_HEX_DIGITS 32
#define MAX_IDENT_LEN 50
#define MAX_INDENT_LEN 250
#define MAX_KEY_LEN (13+1)
#define MAX_LINE_LEN 5000
#define MAX_LIT_LEN 1050
#define MAX_OP_LIT 257
#define MAX_STR_LEN 256
#define MAX_VISIBLE_LINE_LEN 100
#define NCHAR_MAX 255
#define MAX_WHITESPACE 256
#define MAX_CUR_FILE_LEN 257

#define SPACES_IN_TAB 8
#define FALSE 0
#define TRUE 1


/*
 * C type specifiers
 */
#define TS_CHAR         2
#define TS_FLOAT        3
#define TS_DOUBLE       4
#define TS_INT          5
#define TS_LONG         7
#define TS_BOOL        10
#define TS_COMPLEX     12
#define TS_IMAGINARY   13

/*
 * Kinds of tokens
 */
#define TK_KEYWORD     0
#define TK_IDENTIFIER  1
#define TK_CONSTANT    2
#define TK_STRING_LIT  3
#define TK_PUNCTUATOR  4
#define TK_HEADER_NAME 5
#define TK_COMMENT     6
#define TK_PP_DIRECT   7
#define MAX_TOK_KINDS  8

/*
 * C type specifiers
 */
#define TS_VOID         1
#define TS_CHAR         2
#define TS_FLOAT        3
#define TS_DOUBLE       4
#define TS_INT          5
#define TS_SHORT        6
#define TS_LONG         7
#define TS_UNSIGNED     8
#define TS_SIGNED       9
#define TS_BOOL        10
#define TS_COMPLEX     12
#define TS_IMAGINARY   13
#define MAX_TYPE_SPECS  65000

/*
 * C tokens, with values suitable for use by the
 * output of bison (not that this tool contains such
 * a grammar, but the tool the lexer was lifted from
 * does).  Note that addtional 'tokens' have been added
 * to simplify the information extraction process.
 */
#define TOK_EOF         0
#define _AT_           50
#define TOK_SPACE      51
#define TOK_NEW_LINE   52
#define TOK_LINE_START 53
#define CHAR_CONST     54
#define COMMENT        55
#define INTEGER_CONST  56
#define FLOAT_CONST    57
#define HASH_HASH      58
#define HASH           59
#define COMMENT_NL     60
#define CPP_COMMENT    61
#define STRING_CONST   62
#define HEADER_NAME    63

#define TOK_BIT_WIDTH    70

#define TOK_COLONCOLON   72 /* The C++ :: operator */
#define TOK_CLASS        73 /* The C++ keyword */
#define TOK_TEMPLATE     74 /* The C++ keyword */

#define TOK__BOOL	 97
#define TOK__COMPLEX	 98
#define TOK__IMAGINARY	 99
#define TOK_AUTO	100
#define TOK_STATIC	101
#define TOK_EXTERN	102
#define TOK_REGISTER	103
#define TOK_TYPEDEF	104
#define TOK_CHAR	105
#define TOK_FLOAT	106
#define TOK_DOUBLE	107
#define TOK_INT		108
#define TOK_SHORT	109
#define TOK_LONG	110
#define TOK_UNSIGNED	111
#define TOK_SIGNED	112
#define TOK_VOID	113
#define TOK_CONST	114
#define TOK_VOLATILE	115
#define TOK_STRUCT	116
#define TOK_UNION	117
#define TOK_ENUM	118
#define TOK_IF		119
#define TOK_ELSE	120
#define TOK_WHILE	121
#define TOK_FOR		122
#define TOK_DO		123
#define TOK_SWITCH	124
#define TOK_CASE	125
#define TOK_DEFAULT	126
#define TOK_BREAK	127
#define TOK_CONTINUE	128
#define TOK_RETURN	129
#define TOK_GOTO	130
#define TOK_SIZEOF	131
#define TOK_OPEN_RND	132
#define TOK_CL_RND	133
#define TOK_LSHIFT	134
#define TOK_RSHIFT	135
#define TOK_PLUS	136   /* +v */
#define TOK_ADD		137
#define TOK_ARITH_NEG	138   /* -v */
#define TOK_MINUS	139
#define TOK_STAR	140   /* *v */
#define TOK_TIMES	141
#define TOK_REMAINDER	142
#define TOK_DIVIDE	143
#define TOK_BIT_XOR	144
#define TOK_ADDR	145   /* &v */
#define TOK_BIT_AND	146
#define TOK_BIT_OR	147
#define TOK_BIT_NOT	148
#define TOK_LOG_NOT	149
#define TOK_LESS_THAN	150
#define TOK_LESS_EQUAL	151
#define TOK_GR_EQUAL	152
#define TOK_GREATER_THAN 153
#define TOK_EQ_EQUAL	154
#define TOK_EXC_EQUAL	155
#define TOK_LOG_AND	156
#define TOK_LOG_OR	157
#define TOK_QUESTION	158
#define TOK_QCOLON	159
#define TOK_DIR_SELECT	160
#define TOK_INDIR_SELECT 161
#define TOK_PRE_PLUS	162
#define TOK_PRE_MINUS	163
#define TOK_POST_PLUS   164
#define TOK_POST_MINUS  165
#define TOK_COMMA       166
#define TOK_SEMICOLON   167
#define TOK_ELLIPSIS    168
#define TOK_OPEN_CURL   169
#define TOK_CL_CURL     170
#define TOK_OPEN_SQUARE 171
#define TOK_CL_SQUARE   172
#define TOK_EQUAL       173
#define TOK_PLUS_EQUAL  174
#define TOK_MIN_EQUAL   175
#define TOK_MULT_EQUAL  176
#define TOK_LSH_ASSIGN  177
#define TOK_RSH_ASSIGN  178
#define TOK_AND_ASSIGN  179
#define TOK_DIV_EQUAL   180
#define TOK_REM_EQUAL   181
#define TOK_BOR_ASSIGN  182
#define TOK_BXOR_ASSIGN 183
#define TOK_COLON	184
#define TOK_PTR		185
#define LAST_PUNCT_TOK	185
#define TOK_LITERAL     186
#define TOK_IDENTIFIER  187
#define TOK_STRING_LIT  188
#define TOK_PASCAL      189
#define TOK_FORTRAN     190
#define TOK_PPASM       191
#define TOK_ATTRIBUTE   192
#define TOK_TYPEOF      193
#define TOK_ALIGNOF     194

/*
 * New in C99
 */
#define TOK_INLINE	195
#define TOK_RESTRICT	196

#define TOK_START_PP_DIRECT 200     
#define TOK_H_IF        200     
#define TOK_H_ELSE      201
#define TOK_ELIF        202
#define TOK_LINE        203
#define TOK_ENDIF       204
#define TOK_ERROR       205
#define TOK_IFDEF       206
#define TOK_PRAGMA      207
#define TOK_DEFINED     208
#define TOK_INCLUDE     209
#define TOK_DEFINE      210
#define TOK_IFNDEF      211
#define TOK_UNDEF       212

#define TOK_EXPR_STMT	215

#define TOK_STRING_CONCAT 216
#define TOK_FUNC_CALL     217
#define TOK_ARG           218
#define TOK_CAST          219
#define TOK_CMPD_INIT     220

#define MAX_TOK		221

#define is_a_f(ch) ((ch >= 'a') && (ch <= 'f'))
#define is_A_F(ch) ((ch >= 'A') && (ch <= 'F'))
#define is_hex_digit(ch)   (isdigit(ch) || is_a_f(ch) || is_A_F(ch))
#define is_comment_tok(tok) ((tok == COMMENT_NL) || \
			     (tok == CPP_COMMENT) || \
			     (tok == COMMENT))
/*
 * Is ch in the basic execution character set?
 */
#define in_bec_set(ch) ((((ch >= 'a') && (ch <= 'z')) || \
			 ((ch >= 'A') && (ch <= 'Z')) || \
			 ((ch >= '0') && (ch <= '9')) || \
			 (strrchr("!\"#%&'()*+,-./:;<=>?[\\]^_{|}~ \a\b\f\\nr\t\v", ch) != NULL)) ? 1 : 0)

/*
 * Is tok a binary operator?
 */
#define IS_USER_BIN_OP(tok)                   \
		((TOK_LSHIFT == tok) ||       \
		 (TOK_RSHIFT == tok) ||       \
		 (TOK_ADD == tok) ||          \
		 (TOK_MINUS == tok) ||        \
		 (TOK_TIMES == tok) ||        \
		 (TOK_REMAINDER == tok) ||    \
		 (TOK_DIVIDE == tok) ||       \
		 (TOK_BIT_XOR == tok) ||      \
		 (TOK_BIT_AND == tok) ||      \
		 (TOK_BIT_OR == tok) ||       \
		 (TOK_BIT_NOT == tok) ||      \
		 (TOK_LESS_THAN == tok) ||    \
		 (TOK_LESS_EQUAL == tok) ||   \
		 (TOK_GR_EQUAL == tok) ||     \
		 (TOK_GREATER_THAN == tok) || \
		 (TOK_EQ_EQUAL == tok) ||     \
		 (TOK_EXC_EQUAL == tok) ||    \
		 (TOK_LOG_AND == tok) ||      \
		 (TOK_LOG_OR == tok) ||       \
		 (TOK_COMMA == tok))

// We don't want the token definitions created by Bison to be seen
#define YYTOKENTYPE

typedef unsigned long long LONGEST_UINT;
typedef unsigned char BYTE;

#if HAVE__BOOL
typedef _Bool BOOL;
#else
typedef unsigned char BOOL;
#endif

typedef char DIGIT_CHAR;
typedef char CHAR;
typedef char * (*get_buff_func_type)(void);


#define enum_eq(numeric_val, enum_val)  (((numeric_val) & enum_val) == enum_val)
#define enum_ne(numeric_val, enum_val)  (((numeric_val) & enum_val) != enum_val)


extern BOOL do_trace_input;
extern BOOL do_trace_progress;

