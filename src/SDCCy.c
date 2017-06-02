/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 24 "SDCC.y"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "SDCCglobl.h"
#include "SDCCsymt.h"
#include "SDCChasht.h"
#include "SDCCval.h"
#include "SDCCmem.h"
#include "SDCCast.h"
#include "port.h"
#include "newalloc.h"
#include "SDCCerr.h"
#include "SDCCutil.h"

extern int yyerror (char *);
extern FILE     *yyin;
int NestLevel = 0;      /* current NestLevel       */
int stackPtr  = 1;      /* stack pointer           */
int xstackPtr = 0;      /* xstack pointer          */
int reentrant = 0;
int blockNo   = 0;      /* sequential block number  */
int currBlockno=0;
int inCritical= 0;
int seqPointNo= 1;      /* sequence point number */
int ignoreTypedefType=0;
extern int yylex();
int yyparse(void);
extern int noLineno;
char lbuff[1024];       /* local buffer */

/* break & continue stacks */
STACK_DCL(continueStack  ,symbol *,MAX_NEST_LEVEL)
STACK_DCL(breakStack  ,symbol *,MAX_NEST_LEVEL)
STACK_DCL(forStack  ,symbol *,MAX_NEST_LEVEL)
STACK_DCL(swStk   ,ast   *,MAX_NEST_LEVEL)
STACK_DCL(blockNum,int,MAX_NEST_LEVEL*3)

value *cenum = NULL;        /* current enumeration  type chain*/
bool uselessDecl = TRUE;

#define YYDEBUG 1



/* Line 189 of yacc.c  */
#line 118 "SDCCy.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     TYPE_NAME = 259,
     ADDRSPACE_NAME = 260,
     CONSTANT = 261,
     SIZEOF = 262,
     TYPEOF = 263,
     OFFSETOF = 264,
     PTR_OP = 265,
     INC_OP = 266,
     DEC_OP = 267,
     LEFT_OP = 268,
     RIGHT_OP = 269,
     LE_OP = 270,
     GE_OP = 271,
     EQ_OP = 272,
     NE_OP = 273,
     AND_OP = 274,
     OR_OP = 275,
     MUL_ASSIGN = 276,
     DIV_ASSIGN = 277,
     MOD_ASSIGN = 278,
     ADD_ASSIGN = 279,
     SUB_ASSIGN = 280,
     LEFT_ASSIGN = 281,
     RIGHT_ASSIGN = 282,
     AND_ASSIGN = 283,
     XOR_ASSIGN = 284,
     OR_ASSIGN = 285,
     TYPEDEF = 286,
     EXTERN = 287,
     STATIC = 288,
     AUTO = 289,
     REGISTER = 290,
     CODE = 291,
     EEPROM = 292,
     INTERRUPT = 293,
     SFR = 294,
     SFR16 = 295,
     SFR32 = 296,
     ADDRESSMOD = 297,
     AT = 298,
     SBIT = 299,
     REENTRANT = 300,
     USING = 301,
     XDATA = 302,
     DATA = 303,
     IDATA = 304,
     PDATA = 305,
     VAR_ARGS = 306,
     CRITICAL = 307,
     NONBANKED = 308,
     BANKED = 309,
     SHADOWREGS = 310,
     SD_WPARAM = 311,
     SD_BOOL = 312,
     SD_CHAR = 313,
     SD_SHORT = 314,
     SD_INT = 315,
     SD_LONG = 316,
     SIGNED = 317,
     UNSIGNED = 318,
     SD_FLOAT = 319,
     DOUBLE = 320,
     FIXED16X16 = 321,
     SD_CONST = 322,
     VOLATILE = 323,
     SD_VOID = 324,
     BIT = 325,
     STRUCT = 326,
     UNION = 327,
     ENUM = 328,
     RANGE = 329,
     SD_FAR = 330,
     CASE = 331,
     DEFAULT = 332,
     IF = 333,
     ELSE = 334,
     SWITCH = 335,
     WHILE = 336,
     DO = 337,
     FOR = 338,
     GOTO = 339,
     CONTINUE = 340,
     BREAK = 341,
     RETURN = 342,
     NAKED = 343,
     JAVANATIVE = 344,
     OVERLAY = 345,
     STRING_LITERAL = 346,
     INLINEASM = 347,
     IFX = 348,
     ADDRESS_OF = 349,
     GET_VALUE_AT_ADDRESS = 350,
     SPIL = 351,
     UNSPIL = 352,
     GETHBIT = 353,
     GETABIT = 354,
     GETBYTE = 355,
     GETWORD = 356,
     BITWISEAND = 357,
     UNARYMINUS = 358,
     IPUSH = 359,
     IPOP = 360,
     PCALL = 361,
     ENDFUNCTION = 362,
     JUMPTABLE = 363,
     RRC = 364,
     RLC = 365,
     CAST = 366,
     CALL = 367,
     PARAM = 368,
     NULLOP = 369,
     BLOCK = 370,
     LABEL = 371,
     RECEIVE = 372,
     SEND = 373,
     ARRAYINIT = 374,
     DUMMY_READ_VOLATILE = 375,
     ENDCRITICAL = 376,
     SWAP = 377,
     INLINE = 378,
     NORETURN = 379,
     RESTRICT = 380,
     SMALLC = 381,
     ASM = 382
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define TYPE_NAME 259
#define ADDRSPACE_NAME 260
#define CONSTANT 261
#define SIZEOF 262
#define TYPEOF 263
#define OFFSETOF 264
#define PTR_OP 265
#define INC_OP 266
#define DEC_OP 267
#define LEFT_OP 268
#define RIGHT_OP 269
#define LE_OP 270
#define GE_OP 271
#define EQ_OP 272
#define NE_OP 273
#define AND_OP 274
#define OR_OP 275
#define MUL_ASSIGN 276
#define DIV_ASSIGN 277
#define MOD_ASSIGN 278
#define ADD_ASSIGN 279
#define SUB_ASSIGN 280
#define LEFT_ASSIGN 281
#define RIGHT_ASSIGN 282
#define AND_ASSIGN 283
#define XOR_ASSIGN 284
#define OR_ASSIGN 285
#define TYPEDEF 286
#define EXTERN 287
#define STATIC 288
#define AUTO 289
#define REGISTER 290
#define CODE 291
#define EEPROM 292
#define INTERRUPT 293
#define SFR 294
#define SFR16 295
#define SFR32 296
#define ADDRESSMOD 297
#define AT 298
#define SBIT 299
#define REENTRANT 300
#define USING 301
#define XDATA 302
#define DATA 303
#define IDATA 304
#define PDATA 305
#define VAR_ARGS 306
#define CRITICAL 307
#define NONBANKED 308
#define BANKED 309
#define SHADOWREGS 310
#define SD_WPARAM 311
#define SD_BOOL 312
#define SD_CHAR 313
#define SD_SHORT 314
#define SD_INT 315
#define SD_LONG 316
#define SIGNED 317
#define UNSIGNED 318
#define SD_FLOAT 319
#define DOUBLE 320
#define FIXED16X16 321
#define SD_CONST 322
#define VOLATILE 323
#define SD_VOID 324
#define BIT 325
#define STRUCT 326
#define UNION 327
#define ENUM 328
#define RANGE 329
#define SD_FAR 330
#define CASE 331
#define DEFAULT 332
#define IF 333
#define ELSE 334
#define SWITCH 335
#define WHILE 336
#define DO 337
#define FOR 338
#define GOTO 339
#define CONTINUE 340
#define BREAK 341
#define RETURN 342
#define NAKED 343
#define JAVANATIVE 344
#define OVERLAY 345
#define STRING_LITERAL 346
#define INLINEASM 347
#define IFX 348
#define ADDRESS_OF 349
#define GET_VALUE_AT_ADDRESS 350
#define SPIL 351
#define UNSPIL 352
#define GETHBIT 353
#define GETABIT 354
#define GETBYTE 355
#define GETWORD 356
#define BITWISEAND 357
#define UNARYMINUS 358
#define IPUSH 359
#define IPOP 360
#define PCALL 361
#define ENDFUNCTION 362
#define JUMPTABLE 363
#define RRC 364
#define RLC 365
#define CAST 366
#define CALL 367
#define PARAM 368
#define NULLOP 369
#define BLOCK 370
#define LABEL 371
#define RECEIVE 372
#define SEND 373
#define ARRAYINIT 374
#define DUMMY_READ_VOLATILE 375
#define ENDCRITICAL 376
#define SWAP 377
#define INLINE 378
#define NORETURN 379
#define RESTRICT 380
#define SMALLC 381
#define ASM 382




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 70 "SDCC.y"

    symbol     *sym;        /* symbol table pointer                   */
    structdef  *sdef;       /* structure definition                   */
    char       yychar[SDCC_NAME_MAX+1];
    sym_link   *lnk;        /* declarator  or specifier               */
    int        yyint;       /* integer value returned                 */
    value      *val;        /* for integer constant                   */
    initList   *ilist;      /* initial list                           */
    designation*dsgn;       /* designator                             */
    const char *yystr;      /* pointer to dynamicaly allocated string */
    ast        *asts;       /* expression tree                        */



/* Line 214 of yacc.c  */
#line 423 "SDCCy.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 435 "SDCCy.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  107
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1630

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  152
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  304
/* YYNRULES -- Number of states.  */
#define YYNSTATES  462

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   382

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   139,     2,     2,     2,   141,   134,     2,
     131,   132,   135,   136,   133,   137,   128,   140,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   147,   149,
     142,   148,   143,   146,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   129,     2,   130,   144,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   150,   145,   151,   138,     2,     2,     2,
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
     125,   126,   127
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    13,    15,    17,
      20,    24,    26,    29,    32,    34,    36,    38,    40,    42,
      44,    46,    48,    50,    52,    54,    56,    59,    61,    62,
      67,    72,    74,    76,    78,    82,    84,    86,    91,    95,
     100,   101,   106,   107,   112,   115,   118,   120,   124,   126,
     129,   132,   135,   138,   143,   146,   153,   155,   157,   159,
     161,   163,   165,   167,   172,   174,   178,   182,   186,   188,
     192,   196,   198,   202,   206,   208,   212,   216,   220,   224,
     226,   230,   234,   236,   240,   242,   246,   248,   252,   254,
     255,   260,   262,   263,   268,   270,   271,   278,   280,   284,
     286,   288,   290,   292,   294,   296,   298,   300,   302,   304,
     306,   308,   309,   314,   316,   319,   323,   325,   327,   330,
     332,   335,   337,   340,   342,   346,   348,   352,   353,   355,
     358,   360,   363,   367,   370,   372,   374,   376,   378,   380,
     382,   384,   386,   389,   391,   393,   395,   397,   399,   401,
     403,   405,   407,   409,   411,   413,   415,   417,   419,   421,
     423,   425,   427,   429,   431,   434,   436,   438,   440,   442,
     444,   446,   448,   451,   453,   455,   456,   463,   466,   468,
     470,   472,   473,   475,   477,   480,   484,   486,   490,   492,
     495,   499,   500,   505,   511,   514,   516,   519,   523,   526,
     529,   530,   532,   535,   537,   539,   541,   544,   546,   549,
     551,   555,   559,   564,   568,   569,   575,   580,   582,   585,
     588,   592,   594,   596,   598,   601,   603,   607,   609,   613,
     615,   619,   622,   624,   626,   629,   631,   633,   636,   640,
     643,   647,   651,   656,   659,   663,   667,   668,   674,   676,
     680,   685,   688,   693,   695,   697,   699,   701,   703,   705,
     707,   709,   711,   714,   717,   721,   722,   726,   728,   730,
     733,   737,   741,   746,   749,   751,   754,   756,   759,   761,
     764,   767,   768,   769,   777,   778,   785,   787,   789,   791,
     792,   799,   807,   817,   818,   820,   824,   827,   830,   833,
     837,   839,   845,   848,   853
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     153,     0,    -1,    -1,   154,    -1,   155,    -1,   154,   155,
      -1,   156,    -1,   190,    -1,   263,    -1,   220,   159,    -1,
     191,   220,   159,    -1,   158,    -1,   158,   157,    -1,    46,
     189,    -1,    45,    -1,    52,    -1,    88,    -1,    89,    -1,
      90,    -1,    53,    -1,    55,    -1,    56,    -1,    54,    -1,
     201,    -1,   126,    -1,   246,    -1,   247,   246,    -1,   264,
      -1,    -1,   160,   128,   161,   264,    -1,   160,   129,   187,
     130,    -1,   264,    -1,     6,    -1,   163,    -1,   131,   187,
     132,    -1,    91,    -1,   162,    -1,   164,   129,   187,   130,
      -1,   164,   131,   132,    -1,   164,   131,   167,   132,    -1,
      -1,   164,   128,   165,   264,    -1,    -1,   164,    10,   166,
     264,    -1,   164,    11,    -1,   164,    12,    -1,   185,    -1,
     185,   133,   167,    -1,   164,    -1,    11,   168,    -1,    12,
     168,    -1,   169,   170,    -1,     7,   168,    -1,     7,   131,
     233,   132,    -1,     8,   168,    -1,     9,   131,   233,   133,
     160,   132,    -1,   134,    -1,   135,    -1,   136,    -1,   137,
      -1,   138,    -1,   139,    -1,   168,    -1,   131,   233,   132,
     170,    -1,   170,    -1,   171,   135,   170,    -1,   171,   140,
     170,    -1,   171,   141,   170,    -1,   171,    -1,   172,   136,
     171,    -1,   172,   137,   171,    -1,   172,    -1,   173,    13,
     172,    -1,   173,    14,   172,    -1,   173,    -1,   174,   142,
     173,    -1,   174,   143,   173,    -1,   174,    15,   173,    -1,
     174,    16,   173,    -1,   174,    -1,   175,    17,   174,    -1,
     175,    18,   174,    -1,   175,    -1,   176,   134,   175,    -1,
     176,    -1,   177,   144,   176,    -1,   177,    -1,   178,   145,
     177,    -1,   178,    -1,    -1,   179,    19,   180,   178,    -1,
     179,    -1,    -1,   181,    20,   182,   179,    -1,   181,    -1,
      -1,   181,   146,   184,   181,   147,   183,    -1,   183,    -1,
     170,   186,   185,    -1,   148,    -1,    21,    -1,    22,    -1,
      23,    -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,
      28,    -1,    29,    -1,    30,    -1,   185,    -1,    -1,   187,
     133,   188,   185,    -1,   183,    -1,   191,   149,    -1,   191,
     193,   149,    -1,   192,    -1,   199,    -1,   199,   192,    -1,
     202,    -1,   202,   192,    -1,   200,    -1,   200,   192,    -1,
     194,    -1,   193,   133,   194,    -1,   218,    -1,   218,   148,
     237,    -1,    -1,   196,    -1,   197,   148,    -1,   198,    -1,
     197,   198,    -1,   129,   189,   130,    -1,   128,   264,    -1,
      31,    -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,
     123,    -1,   124,    -1,    38,    -1,    38,   189,    -1,    57,
      -1,    58,    -1,    59,    -1,    60,    -1,    61,    -1,    62,
      -1,    63,    -1,    69,    -1,    67,    -1,    68,    -1,   125,
      -1,     5,    -1,    64,    -1,    66,    -1,    47,    -1,    36,
      -1,    37,    -1,    48,    -1,    49,    -1,    50,    -1,    70,
      -1,    43,   189,    -1,   205,    -1,   214,    -1,     4,    -1,
     203,    -1,    44,    -1,   204,    -1,    39,    -1,    39,    54,
      -1,    40,    -1,    41,    -1,    -1,   207,   208,   206,   150,
     210,   151,    -1,   207,   209,    -1,    71,    -1,    72,    -1,
     209,    -1,    -1,   264,    -1,   211,    -1,   210,   211,    -1,
     227,   212,   149,    -1,   213,    -1,   212,   133,   213,    -1,
     218,    -1,   147,   189,    -1,   218,   147,   189,    -1,    -1,
      73,   150,   215,   151,    -1,    73,   264,   150,   215,   151,
      -1,    73,   264,    -1,   216,    -1,   215,   133,    -1,   215,
     133,   216,    -1,   264,   217,    -1,   148,   189,    -1,    -1,
     219,    -1,   225,   219,    -1,   221,    -1,   222,    -1,   221,
      -1,   225,   221,    -1,   223,    -1,   223,   157,    -1,   264,
      -1,   131,   218,   132,    -1,   219,   129,   130,    -1,   219,
     129,   189,   130,    -1,   222,   131,   132,    -1,    -1,   222,
     131,   224,   230,   132,    -1,   222,   131,   229,   132,    -1,
     226,    -1,   226,   227,    -1,   226,   225,    -1,   226,   227,
     225,    -1,   135,    -1,   228,    -1,   202,    -1,   228,   202,
      -1,   264,    -1,   229,   133,   264,    -1,   231,    -1,   231,
     133,    51,    -1,   232,    -1,   231,   133,   232,    -1,   191,
     218,    -1,   233,    -1,   191,    -1,   191,   234,    -1,   225,
      -1,   235,    -1,   225,   235,    -1,   131,   234,   132,    -1,
     129,   130,    -1,   129,   189,   130,    -1,   235,   129,   130,
      -1,   235,   129,   189,   130,    -1,   131,   132,    -1,   131,
     230,   132,    -1,   235,   131,   132,    -1,    -1,   235,   131,
     236,   230,   132,    -1,   185,    -1,   150,   238,   151,    -1,
     150,   238,   133,   151,    -1,   195,   237,    -1,   238,   133,
     195,   237,    -1,   242,    -1,   246,    -1,   249,    -1,   251,
      -1,   257,    -1,   260,    -1,   241,    -1,   262,    -1,    52,
      -1,   240,   239,    -1,   264,   147,    -1,    76,   189,   147,
      -1,    -1,    77,   243,   147,    -1,   150,    -1,   151,    -1,
     244,   245,    -1,   244,   248,   245,    -1,   244,   247,   245,
      -1,   244,   247,   248,   245,    -1,     1,   149,    -1,   190,
      -1,   247,   190,    -1,   239,    -1,   248,   239,    -1,   149,
      -1,   187,   149,    -1,    79,   239,    -1,    -1,    -1,    78,
     131,   187,   132,   252,   239,   250,    -1,    -1,    80,   131,
     187,   132,   253,   239,    -1,    81,    -1,    82,    -1,    83,
      -1,    -1,   254,   131,   187,   132,   258,   239,    -1,   255,
     239,    81,   131,   187,   132,   149,    -1,   256,   131,   259,
     149,   259,   149,   259,   132,   239,    -1,    -1,   187,    -1,
      84,   264,   149,    -1,    85,   149,    -1,    86,   149,    -1,
      87,   149,    -1,    87,   187,   149,    -1,    91,    -1,   127,
     131,   261,   132,   149,    -1,    92,   149,    -1,    42,   264,
     264,   149,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   142,   142,   145,   149,   150,   154,   158,   179,   183,
     188,   197,   198,   202,   206,   209,   212,   215,   218,   221,
     227,   230,   233,   239,   245,   251,   252,   260,   261,   261,
     268,   275,   276,   277,   278,   282,   286,   287,   288,   290,
     294,   294,   301,   301,   308,   310,   315,   316,   320,   321,
     322,   323,   324,   325,   326,   327,   331,   332,   333,   334,
     335,   336,   340,   341,   345,   346,   347,   348,   352,   353,
     354,   358,   359,   360,   364,   365,   366,   367,   368,   372,
     373,   374,   378,   379,   383,   384,   388,   389,   393,   394,
     394,   399,   400,   400,   405,   406,   406,   414,   415,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     474,   475,   475,   479,   483,   507,   524,   527,   528,   533,
     534,   539,   540,   548,   549,   553,   554,   558,   559,   563,
     567,   568,   572,   594,   598,   602,   606,   610,   614,   621,
     625,   632,   633,   646,   651,   656,   661,   666,   671,   676,
     681,   686,   690,   694,   698,   702,   707,   712,   716,   720,
     724,   728,   732,   736,   744,   751,   756,   762,   771,   775,
     783,   787,   795,   806,   817,   830,   829,   922,   951,   952,
     956,   957,   968,   987,   988,  1001,  1026,  1027,  1035,  1036,
    1051,  1069,  1073,  1078,  1099,  1115,  1116,  1117,  1125,  1145,
    1158,  1172,  1173,  1181,  1182,  1186,  1187,  1195,  1196,  1228,
    1229,  1230,  1239,  1271,  1276,  1275,  1306,  1316,  1317,  1330,
    1336,  1376,  1383,  1386,  1388,  1396,  1397,  1405,  1406,  1410,
    1411,  1419,  1435,  1445,  1453,  1479,  1480,  1481,  1488,  1489,
    1494,  1500,  1506,  1514,  1515,  1516,  1529,  1528,  1561,  1562,
    1563,  1567,  1568,  1577,  1578,  1579,  1580,  1581,  1582,  1583,
    1584,  1588,  1597,  1607,  1609,  1616,  1616,  1626,  1636,  1644,
    1645,  1646,  1651,  1658,  1662,  1675,  1701,  1702,  1706,  1707,
    1711,  1712,  1717,  1717,  1725,  1725,  1750,  1764,  1779,  1798,
    1798,  1807,  1817,  1845,  1846,  1850,  1855,  1868,  1878,  1887,
    1899,  1903,  1913,  1926,  1940
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "TYPE_NAME",
  "ADDRSPACE_NAME", "CONSTANT", "SIZEOF", "TYPEOF", "OFFSETOF", "PTR_OP",
  "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP",
  "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "CODE", "EEPROM", "INTERRUPT", "SFR", "SFR16", "SFR32",
  "ADDRESSMOD", "AT", "SBIT", "REENTRANT", "USING", "XDATA", "DATA",
  "IDATA", "PDATA", "VAR_ARGS", "CRITICAL", "NONBANKED", "BANKED",
  "SHADOWREGS", "SD_WPARAM", "SD_BOOL", "SD_CHAR", "SD_SHORT", "SD_INT",
  "SD_LONG", "SIGNED", "UNSIGNED", "SD_FLOAT", "DOUBLE", "FIXED16X16",
  "SD_CONST", "VOLATILE", "SD_VOID", "BIT", "STRUCT", "UNION", "ENUM",
  "RANGE", "SD_FAR", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "NAKED",
  "JAVANATIVE", "OVERLAY", "STRING_LITERAL", "INLINEASM", "IFX",
  "ADDRESS_OF", "GET_VALUE_AT_ADDRESS", "SPIL", "UNSPIL", "GETHBIT",
  "GETABIT", "GETBYTE", "GETWORD", "BITWISEAND", "UNARYMINUS", "IPUSH",
  "IPOP", "PCALL", "ENDFUNCTION", "JUMPTABLE", "RRC", "RLC", "CAST",
  "CALL", "PARAM", "NULLOP", "BLOCK", "LABEL", "RECEIVE", "SEND",
  "ARRAYINIT", "DUMMY_READ_VOLATILE", "ENDCRITICAL", "SWAP", "INLINE",
  "NORETURN", "RESTRICT", "SMALLC", "ASM", "'.'", "'['", "']'", "'('",
  "')'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'",
  "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'",
  "$accept", "file", "program", "external_definition",
  "function_definition", "function_attribute", "function_attributes",
  "function_body", "offsetof_member_designator", "$@1", "primary_expr",
  "string_literal_val", "postfix_expr", "$@2", "$@3", "argument_expr_list",
  "unary_expr", "unary_operator", "cast_expr", "multiplicative_expr",
  "additive_expr", "shift_expr", "relational_expr", "equality_expr",
  "and_expr", "exclusive_or_expr", "inclusive_or_expr", "logical_and_expr",
  "$@4", "logical_or_expr", "$@5", "conditional_expr", "$@6",
  "assignment_expr", "assignment_operator", "expr", "$@7", "constant_expr",
  "declaration", "declaration_specifiers", "declaration_specifiers_",
  "init_declarator_list", "init_declarator", "designation_opt",
  "designation", "designator_list", "designator",
  "storage_class_specifier", "function_specifier", "Interrupt_storage",
  "type_specifier", "sfr_reg_bit", "sfr_attributes",
  "struct_or_union_specifier", "$@8", "struct_or_union", "opt_stag",
  "stag", "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "opt_assign_expr", "declarator",
  "declarator3", "function_declarator", "declarator2_function_attributes",
  "declarator2", "function_declarator2", "$@9", "pointer",
  "unqualified_pointer", "type_specifier_list", "type_specifier_list_",
  "identifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "type_name", "abstract_declarator",
  "abstract_declarator2", "$@10", "initializer", "initializer_list",
  "statement", "critical", "critical_statement", "labeled_statement",
  "@11", "start_block", "end_block", "compound_statement",
  "declaration_list", "statement_list", "expression_statement",
  "else_statement", "selection_statement", "$@12", "@13", "while", "do",
  "for", "iteration_statement", "$@14", "expr_opt", "jump_statement",
  "asm_string_literal", "asm_statement", "addressmod", "identifier", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
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
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,    46,    91,
      93,    40,    41,    44,    38,    42,    43,    45,   126,    33,
      47,    37,    60,    62,    94,   124,    63,    58,    61,    59,
     123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   152,   153,   153,   154,   154,   155,   155,   155,   156,
     156,   157,   157,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   159,   159,   160,   161,   160,
     160,   162,   162,   162,   162,   163,   164,   164,   164,   164,
     165,   164,   166,   164,   164,   164,   167,   167,   168,   168,
     168,   168,   168,   168,   168,   168,   169,   169,   169,   169,
     169,   169,   170,   170,   171,   171,   171,   171,   172,   172,
     172,   173,   173,   173,   174,   174,   174,   174,   174,   175,
     175,   175,   176,   176,   177,   177,   178,   178,   179,   180,
     179,   181,   182,   181,   183,   184,   183,   185,   185,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     187,   188,   187,   189,   190,   190,   191,   192,   192,   192,
     192,   192,   192,   193,   193,   194,   194,   195,   195,   196,
     197,   197,   198,   198,   199,   199,   199,   199,   199,   200,
     200,   201,   201,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   203,
     203,   204,   204,   204,   204,   206,   205,   205,   207,   207,
     208,   208,   209,   210,   210,   211,   212,   212,   213,   213,
     213,   213,   214,   214,   214,   215,   215,   215,   216,   217,
     217,   218,   218,   219,   219,   220,   220,   221,   221,   222,
     222,   222,   222,   223,   224,   223,   223,   225,   225,   225,
     225,   226,   227,   228,   228,   229,   229,   230,   230,   231,
     231,   232,   232,   233,   233,   234,   234,   234,   235,   235,
     235,   235,   235,   235,   235,   235,   236,   235,   237,   237,
     237,   238,   238,   239,   239,   239,   239,   239,   239,   239,
     239,   240,   241,   242,   242,   243,   242,   244,   245,   246,
     246,   246,   246,   246,   247,   247,   248,   248,   249,   249,
     250,   250,   252,   251,   253,   251,   254,   255,   256,   258,
     257,   257,   257,   259,   259,   260,   260,   260,   260,   260,
     261,   262,   262,   263,   264
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     1,     2,
       3,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     0,     4,
       4,     1,     1,     1,     3,     1,     1,     4,     3,     4,
       0,     4,     0,     4,     2,     2,     1,     3,     1,     2,
       2,     2,     2,     4,     2,     6,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     0,
       4,     1,     0,     4,     1,     0,     6,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     1,     2,     3,     1,     1,     2,     1,
       2,     1,     2,     1,     3,     1,     3,     0,     1,     2,
       1,     2,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     0,     6,     2,     1,     1,
       1,     0,     1,     1,     2,     3,     1,     3,     1,     2,
       3,     0,     4,     5,     2,     1,     2,     3,     2,     2,
       0,     1,     2,     1,     1,     1,     2,     1,     2,     1,
       3,     3,     4,     3,     0,     5,     4,     1,     2,     2,
       3,     1,     1,     1,     2,     1,     3,     1,     3,     1,
       3,     2,     1,     1,     2,     1,     1,     2,     3,     2,
       3,     3,     4,     2,     3,     3,     0,     5,     1,     3,
       4,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     0,     3,     1,     1,     2,
       3,     3,     4,     2,     1,     2,     1,     2,     1,     2,
       2,     0,     0,     7,     0,     6,     1,     1,     1,     0,
       6,     7,     9,     0,     1,     3,     2,     2,     2,     3,
       1,     5,     2,     4,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,   304,   167,   154,   134,   135,   136,   137,   138,   158,
     159,   171,   173,   174,     0,     0,   169,   157,   160,   161,
     162,   143,   144,   145,   146,   147,   148,   149,   155,   156,
     151,   152,   150,   163,   178,   179,     0,   139,   140,   153,
       0,   221,     0,     3,     4,     6,     7,     0,   116,   117,
     121,   119,   168,   170,   165,   181,   166,     0,     0,   205,
     204,   207,     0,   217,     8,   209,   172,     0,    32,     0,
       0,     0,     0,     0,    35,     0,    56,    57,    58,    59,
      60,    61,    36,    33,    48,    62,     0,    64,    68,    71,
      74,    79,    82,    84,    86,    88,    91,    94,   113,   164,
      31,     0,   194,     0,   201,   203,     0,     1,     5,   114,
       0,   123,   125,     0,     0,   118,   122,   120,   175,   177,
     182,     0,     0,   267,     9,   274,     0,     0,    25,     0,
     214,   141,    14,     0,    15,    19,    22,    20,    21,    16,
      17,    18,    24,   208,    11,    23,   206,   223,   219,   218,
     222,     0,     0,    52,     0,    54,     0,    49,    50,    64,
      97,   110,     0,   233,     0,    42,    44,    45,    40,     0,
       0,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    92,
      95,     0,   195,   200,     0,   210,   202,     0,   115,     0,
      10,     0,   211,     0,   273,   261,     0,   265,     0,     0,
     286,   287,   288,     0,     0,     0,     0,     0,     0,   278,
     268,     0,   276,     0,   259,   253,   269,   254,     0,     0,
     255,   256,     0,     0,     0,   257,   258,   260,    31,   275,
      26,   213,     0,     0,   225,   142,    13,    12,   220,   224,
     303,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,    99,     0,    34,   111,     0,     0,   235,
     234,   236,     0,     0,     0,     0,    38,     0,    46,    65,
      66,    67,    69,    70,    72,    73,    77,    78,    75,    76,
      80,    81,    83,    85,    87,     0,     0,     0,   196,   192,
       0,   198,     0,   124,   127,   248,   126,     0,   212,     0,
       0,     0,     0,     0,   296,   297,   298,     0,   302,     0,
     279,   262,   271,     0,   277,   270,     0,     0,   293,   263,
     233,     0,   227,   229,   232,   216,     0,    53,     0,    98,
       0,   239,     0,   243,     0,     0,   237,     0,   246,    63,
      43,    41,    37,    39,     0,    90,    93,     0,   197,   199,
     193,     0,     0,     0,   128,     0,   130,     0,     0,   183,
     191,   264,   266,     0,     0,   295,   299,   300,     0,   272,
       0,     0,   294,     0,     0,   231,   235,   215,     0,   226,
       0,    27,   112,   240,   244,   238,   241,     0,   245,     0,
      47,     0,   133,     0,   251,   129,   131,   127,   249,   176,
     184,     0,     0,   186,   188,   282,   284,     0,   289,     0,
     293,   228,   230,    28,     0,    55,   242,     0,    96,   132,
     250,     0,   189,   191,   185,     0,     0,     0,   301,     0,
       0,     0,     0,     0,   247,   252,   187,   190,   281,   285,
     290,     0,   293,    29,    30,     0,   283,   291,     0,   280,
       0,   292
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    42,    43,    44,    45,   143,   144,   124,   390,   442,
      82,    83,    84,   274,   273,   277,    85,    86,   159,    88,
      89,    90,    91,    92,    93,    94,    95,    96,   295,    97,
     296,   160,   297,   161,   264,   221,   340,    99,   125,   126,
      48,   110,   111,   363,   364,   365,   366,    49,    50,   145,
      51,    52,    53,    54,   201,    55,   118,   119,   368,   369,
     412,   413,    56,   191,   192,   301,   112,   104,    58,   105,
      60,    61,   242,   106,    63,   370,   150,   243,   344,   332,
     333,   334,   270,   271,   399,   306,   367,   222,   223,   224,
     225,   310,   127,   226,   227,   129,   229,   230,   456,   231,
     436,   437,   232,   233,   234,   235,   439,   383,   236,   378,
     237,    64,   100
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -390
static const yytype_int16 yypact[] =
{
    1194,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,   -22,  -390,  -390,    41,   989,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,     7,  -390,  -390,  -390,
      10,  -390,    61,  1194,  -390,  -390,  -390,    56,  -390,  1458,
    1458,  1458,  -390,  -390,  -390,    41,  -390,   -78,   653,   -83,
     -61,   700,    21,  1340,  -390,  -390,  -390,    41,  -390,   999,
    1009,   -35,  1009,  1009,  -390,   903,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,    67,  -390,   989,  -390,    86,    17,
     211,    59,   225,   -51,   -39,   -20,   128,   -17,  -390,  -390,
    -390,    41,   -12,     4,   -78,  -390,    21,  -390,  -390,  -390,
     -96,  -390,    31,   653,    21,  -390,  -390,  -390,  -390,    24,
    -390,   423,    39,  -390,  -390,  -390,    56,   440,  -390,   653,
      16,   989,  -390,   989,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,   700,  -390,   -83,  -390,  -390,    50,
    1505,    55,   903,  -390,   989,  -390,  1458,  -390,  -390,   619,
    -390,  -390,   117,   -37,    58,  -390,  -390,  -390,  -390,   989,
     627,  -390,   989,   989,   989,   989,   989,   989,   989,   989,
     989,   989,   989,   989,   989,   989,   989,   989,  -390,  -390,
    -390,  -110,  -390,    74,    41,  -390,   -78,    10,  -390,   208,
    -390,    80,  -390,   130,  -390,  -390,   989,  -390,   108,   116,
    -390,  -390,  -390,    41,   115,   131,   229,   142,   126,  -390,
    -390,   -69,  -390,   728,  -390,  -390,  -390,  -390,   440,   532,
    -390,  -390,   165,   728,   171,  -390,  -390,  -390,   141,  -390,
    -390,  -390,  1458,   119,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,   173,   174,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,   989,  -390,  -390,   913,  1299,    11,
    -390,    81,   989,    41,    41,   -49,  -390,   178,   179,  -390,
    -390,  -390,    86,    86,    17,    17,   211,   211,   211,   211,
      59,    59,   225,   -51,   -39,   989,   989,   989,    41,  -390,
     989,  -390,  -103,  -390,   127,  -390,  -390,  1505,  -390,   159,
     164,   989,   989,   166,  -390,  -390,  -390,   -40,  -390,   223,
    -390,  -390,  -390,   532,  -390,  -390,   989,   235,   989,  -390,
      15,   185,   188,  -390,  -390,  -390,    41,  -390,    41,  -390,
     989,  -390,   192,  -390,   186,   194,    81,   978,   195,  -390,
    -390,  -390,  -390,  -390,   989,   -20,   128,    36,  -390,  -390,
    -390,    41,   989,   208,  -390,   -90,  -390,   -91,   832,  -390,
       8,  -390,  -390,   136,   139,  -390,  -390,  -390,   196,  -390,
     143,   198,   191,   176,  1146,  -390,    51,  -390,  1410,  -390,
     -16,  -390,  -390,  -390,  -390,  -390,  -390,   201,  -390,  1458,
    -390,   989,  -390,   202,  -390,  -390,  -390,   -94,  -390,  -390,
    -390,   989,   -38,  -390,   203,  -390,  -390,   205,  -390,   989,
     989,  -390,  -390,  -390,   989,  -390,  -390,   209,  -390,  -390,
    -390,   208,  -390,     8,  -390,   989,   728,   728,  -390,   728,
     146,   206,    41,    -9,  -390,  -390,  -390,  -390,   256,  -390,
    -390,   210,   989,  -390,  -390,   728,  -390,  -390,   230,  -390,
     728,  -390
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -390,  -390,  -390,   297,  -390,   227,  -390,   259,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,    19,   193,  -390,   -14,   109,
     123,   -48,   120,   184,   189,   187,    82,    83,  -390,    79,
    -390,   -13,  -390,  -154,  -390,   -67,  -390,  -116,     6,    25,
     157,  -390,   183,   -26,  -390,  -390,    18,  -390,  -390,  -390,
     -59,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,    14,
    -390,   -44,  -390,   197,    92,  -390,   -33,     9,   345,   156,
    -390,  -390,  -390,    26,  -390,   330,  -390,  -390,  -221,  -390,
      13,   -53,  -256,  -249,  -390,  -334,  -390,  -147,  -390,  -390,
    -390,  -390,  -390,  -201,   -25,   267,   168,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -389,  -390,  -390,
    -390,  -390,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -204
static const yytype_int16 yytable[] =
{
      65,    87,    98,   189,   147,   203,    46,   103,   162,    57,
       1,     1,   345,     1,    67,   245,   278,   246,     1,     1,
     346,   331,   164,   298,     1,    47,    62,   322,   325,   404,
     298,   441,    66,   128,   361,   362,   102,   197,   361,   362,
      65,   299,   407,    65,     1,   305,  -203,    65,   360,    46,
    -203,   121,    57,   198,     1,   120,   189,   430,   405,     1,
     408,   107,    65,   458,   266,  -203,  -203,   151,    47,    62,
     130,    57,   171,   114,   179,   180,   321,   165,   166,   167,
     320,   352,   324,   185,   266,   162,   327,   162,   128,   148,
     309,   249,   267,   266,   268,   433,   156,   445,    41,   251,
     163,   193,   275,   252,   240,   186,    65,    87,    98,   376,
     339,   434,   423,   424,    65,   196,   425,    87,    98,    87,
      98,   454,   379,   196,   266,   187,    65,   238,   345,   190,
     244,   286,   287,   288,   289,   239,   195,   346,   194,    40,
     267,    40,   268,    41,   267,    41,   384,   188,   241,   317,
      41,   342,    40,   175,   176,   411,    59,   101,   279,   280,
     281,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,  -180,   248,   324,   163,   427,   199,
     267,   163,   384,   401,   359,    41,   392,    40,   204,   269,
     272,    41,    87,    98,   193,   168,   169,    65,   170,    59,
     278,   181,   182,    59,   250,   109,   115,   116,   117,   305,
     347,     1,   348,   313,    68,    69,    70,    71,   146,    72,
      73,   172,   300,   238,   177,   178,   173,   174,   238,   238,
     307,   397,     1,   238,   239,    68,    69,    70,    71,   311,
      72,    73,   183,   184,   373,   374,   403,   312,   147,   265,
     266,   335,   336,    87,    98,   361,   362,   319,   349,   380,
     308,   382,   153,   155,   314,   157,   158,   330,   415,   266,
     146,   416,   266,   350,   351,   418,   266,   305,   451,   266,
     315,    87,    87,    87,   282,   283,    87,    98,   329,   448,
     449,   318,   450,   330,   269,   432,   326,   385,   193,    74,
     284,   285,   328,   290,   291,   337,   371,   338,   459,   147,
     353,   372,   354,   461,   377,   375,   381,   387,   394,   447,
      74,   388,   393,   238,   266,   420,   395,   398,   417,   419,
      65,   426,   429,    87,    98,   455,   389,   414,   391,    75,
     108,   444,    76,    77,    78,    79,    80,    81,    87,    98,
     435,   103,   440,   382,   438,   452,   386,   443,   304,   457,
      75,   402,   460,    76,    77,    78,    79,    80,    81,   292,
      65,   247,   200,   400,   294,   293,   357,   355,   316,   356,
     303,   431,   410,   406,    65,   382,    65,    87,   428,   446,
     358,   302,   113,   149,   228,   196,   323,    87,    98,     0,
     414,   422,     0,     0,     0,     0,     0,     0,     0,   330,
     386,     0,     0,   330,     0,     0,     0,     0,     0,     0,
       0,    87,    98,     0,   330,     0,     1,     0,     0,    68,
      69,    70,    71,    65,    72,    73,   238,   238,     0,   238,
       0,   122,   453,     1,     2,     3,    68,    69,    70,    71,
       0,    72,    73,     0,     0,   238,     0,     0,     0,     0,
     238,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,     0,    15,    16,     0,     0,    17,    18,    19,
      20,     0,   205,     0,     0,     0,     0,    21,    22,    23,
      24,    25,    26,    27,    28,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    74,     0,   206,   207,   208,     0,
     209,   210,   211,   212,   213,   214,   215,   216,     0,     0,
       0,    74,   217,   122,     0,     1,     0,     0,    68,    69,
      70,    71,     0,    72,    73,     0,     0,     0,     0,     0,
       0,     0,     0,   202,    75,     0,     0,    76,    77,    78,
      79,    80,    81,    37,    38,    39,     0,   218,     0,     0,
       0,    75,     0,     0,    76,    77,    78,    79,    80,    81,
       0,     0,     0,     0,   205,     0,     0,     0,     0,   219,
     123,   220,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   206,   207,
     208,     0,   209,   210,   211,   212,   213,   214,   215,   216,
       0,     0,     0,    74,   217,     0,     0,     0,     0,     0,
       1,     0,     0,    68,    69,    70,    71,     0,    72,    73,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
       0,     0,     0,     0,   122,     0,     0,     2,     3,   218,
       0,     0,     0,    75,     0,     0,    76,    77,    78,    79,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   219,   123,   220,     4,     5,     6,     7,     8,     9,
      10,     0,    11,    12,    13,     0,    15,    16,     0,     0,
      17,    18,    19,    20,     0,     0,     0,     0,     0,     0,
      21,    22,    23,    24,    25,    26,    27,    28,    74,    29,
      30,    31,    32,    33,    34,    35,    36,     0,     0,   122,
       0,     1,     0,     0,    68,    69,    70,    71,   131,    72,
      73,     0,     0,     0,     0,   132,   133,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,     0,    75,   276,
       0,    76,    77,    78,    79,    80,    81,   263,     0,     0,
       0,     0,     0,     0,     0,     0,    37,    38,    39,     0,
     205,     0,     0,     0,     0,     0,     0,     0,   139,   140,
     141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,   206,   207,   208,     0,   209,   210,
     211,   212,   213,   214,   215,   216,     0,     0,     0,    74,
     217,     0,     0,     0,     0,     0,   142,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   218,     0,     0,     0,    75,
       0,     0,    76,    77,    78,    79,    80,    81,     9,    10,
       0,    11,    12,    13,     0,    15,    16,   219,   123,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,    21,
      22,    23,    24,    25,    26,    27,    28,     0,    29,    30,
      31,    32,    33,    34,    35,    36,     1,     2,     3,    68,
      69,    70,    71,     0,    72,    73,     1,     0,     0,    68,
      69,    70,    71,     0,    72,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,    11,    12,    13,     0,    15,    16,     0,     0,
      17,    18,    19,    20,     0,     0,     0,    39,     0,     0,
      21,    22,    23,    24,    25,    26,    27,    28,     0,    29,
      30,    31,    32,    33,    34,    35,    36,     0,     0,     0,
       0,     1,     0,   409,    68,    69,    70,    71,     0,    72,
      73,     0,     1,     0,    74,    68,    69,    70,    71,     0,
      72,    73,     1,     0,    74,    68,    69,    70,    71,     0,
      72,    73,     1,     0,     0,    68,    69,    70,    71,     0,
      72,    73,     0,     0,     0,     0,    37,    38,    39,     0,
       0,     0,     0,     0,    75,     0,     0,    76,    77,    78,
      79,    80,    81,   341,    75,     0,     0,    76,    77,    78,
      79,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,     0,     0,     0,     0,     0,     0,     0,   396,    75,
       0,     0,    76,    77,    78,    79,    80,    81,     0,     0,
      75,     0,     0,    76,    77,    78,    79,    80,    81,     0,
     152,     0,     0,    76,    77,    78,    79,    80,    81,     0,
     154,     0,     0,    76,    77,    78,    79,    80,    81,     1,
       2,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,     0,    15,
      16,     0,     0,    17,    18,    19,    20,     1,     2,     3,
       0,     0,     0,    21,    22,    23,    24,    25,    26,    27,
      28,     0,    29,    30,    31,    32,    33,    34,    35,    36,
       0,     0,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,     0,
       0,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,    21,    22,    23,    24,    25,    26,    27,    28,     0,
      29,    30,    31,    32,    33,    34,    35,    36,     0,    37,
      38,    39,     0,     0,     0,   267,     0,   384,   343,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,    38,    39,
       0,     0,     0,     0,     0,    40,     0,     0,     0,    41,
       4,     5,     6,     7,     8,     9,    10,     0,    11,    12,
      13,     0,    15,    16,     2,     3,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,    21,    22,    23,    24,
      25,    26,    27,    28,     0,    29,    30,    31,    32,    33,
      34,    35,    36,     0,     0,     0,     9,    10,     0,    11,
      12,    13,     0,    15,    16,     0,     0,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,    21,    22,    23,
      24,    25,    26,    27,    28,     0,    29,    30,    31,    32,
      33,    34,    35,    36,     2,     3,     0,     0,     0,     0,
       0,     0,    37,    38,    39,     0,     0,     0,   267,     0,
     268,   343,     0,     0,    41,     0,     0,     0,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,     0,    15,    16,     0,     0,    17,    18,    19,
      20,   421,     2,     3,     0,    39,     0,    21,    22,    23,
      24,    25,    26,    27,    28,    41,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     0,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
       0,    15,    16,     0,     0,    17,    18,    19,    20,     2,
       3,     0,     0,     0,     0,    21,    22,    23,    24,    25,
      26,    27,    28,     0,    29,    30,    31,    32,    33,    34,
      35,    36,     0,    37,    38,    39,     0,     0,     0,     0,
       0,     9,    10,     0,    11,    12,    13,     0,    15,    16,
       0,     0,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     0,    21,    22,    23,    24,    25,    26,    27,    28,
       0,    29,    30,    31,    32,    33,    34,    35,    36,     0,
       0,    37,    38,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39
};

static const yytype_int16 yycheck[] =
{
       0,    15,    15,    20,    63,   121,     0,    40,    75,     0,
       3,     3,   268,     3,    14,   131,   170,   133,     3,     3,
     269,   242,    75,   133,     3,     0,     0,   228,   229,   363,
     133,   420,    54,    58,   128,   129,    36,   133,   128,   129,
      40,   151,   133,    43,     3,   199,   129,    47,   151,    43,
     133,   129,    43,   149,     3,    55,    20,   151,   148,     3,
     151,     0,    62,   452,   133,   148,   149,    67,    43,    43,
     131,    62,    86,    47,    15,    16,   223,    10,    11,    12,
     149,   130,   229,   134,   133,   152,   233,   154,   113,    63,
     206,   150,   129,   133,   131,   133,   131,   431,   135,   152,
      75,   101,   169,   156,   129,   144,   106,   121,   121,   149,
     264,   149,   128,   129,   114,   106,   132,   131,   131,   133,
     133,   130,   323,   114,   133,   145,   126,   127,   384,   146,
     130,   179,   180,   181,   182,   129,   132,   386,   150,   131,
     129,   131,   131,   135,   129,   135,   131,    19,   132,   216,
     135,   267,   131,   136,   137,   147,     0,   150,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   150,   149,   323,   152,   399,   148,
     129,   156,   131,   147,   300,   135,   340,   131,   149,   163,
     132,   135,   206,   206,   194,   128,   129,   197,   131,    43,
     354,   142,   143,    47,   149,   149,    49,    50,    51,   363,
     129,     3,   131,   213,     6,     7,     8,     9,    62,    11,
      12,   135,   148,   223,    13,    14,   140,   141,   228,   229,
     150,   347,     3,   233,   228,     6,     7,     8,     9,   131,
      11,    12,    17,    18,   311,   312,   362,   131,   307,   132,
     133,   132,   133,   267,   267,   128,   129,   131,   272,   326,
     130,   328,    69,    70,   149,    72,    73,   242,   132,   133,
     114,   132,   133,   273,   274,   132,   133,   431,   132,   133,
     149,   295,   296,   297,   175,   176,   300,   300,   147,   436,
     437,   149,   439,   268,   268,   411,   131,   330,   298,    91,
     177,   178,   131,   183,   184,   132,   147,   133,   455,   368,
     132,   147,   133,   460,    91,   149,    81,   132,   132,   435,
      91,   133,   130,   323,   133,   149,   132,   132,   132,   131,
     330,   130,   130,   347,   347,    79,   336,   370,   338,   131,
      43,   132,   134,   135,   136,   137,   138,   139,   362,   362,
     147,   384,   419,   420,   149,   149,   330,   424,   150,   149,
     131,   361,   132,   134,   135,   136,   137,   138,   139,   185,
     370,   144,   113,   354,   187,   186,   297,   295,   149,   296,
     197,   407,   368,   365,   384,   452,   386,   401,   401,   433,
     298,   194,    47,    63,   127,   386,   228,   411,   411,    -1,
     433,   388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,
     384,    -1,    -1,   388,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   435,   435,    -1,   399,    -1,     3,    -1,    -1,     6,
       7,     8,     9,   433,    11,    12,   436,   437,    -1,   439,
      -1,     1,   442,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,   455,    -1,    -1,    -1,    -1,
     460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      40,    41,    -1,    43,    44,    -1,    -1,    47,    48,    49,
      50,    -1,    52,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    91,    -1,    76,    77,    78,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    -1,
      -1,    91,    92,     1,    -1,     3,    -1,    -1,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,    -1,    -1,   134,   135,   136,
     137,   138,   139,   123,   124,   125,    -1,   127,    -1,    -1,
      -1,   131,    -1,    -1,   134,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,   149,
     150,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      78,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    -1,    -1,    91,    92,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    -1,     6,     7,     8,     9,    -1,    11,    12,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,     1,    -1,    -1,     4,     5,   127,
      -1,    -1,    -1,   131,    -1,    -1,   134,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    91,    66,
      67,    68,    69,    70,    71,    72,    73,    -1,    -1,     1,
      -1,     3,    -1,    -1,     6,     7,     8,     9,    38,    11,
      12,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    -1,   131,   132,
      -1,   134,   135,   136,   137,   138,   139,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   150,    76,    77,    78,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    -1,    -1,    91,
      92,    -1,    -1,    -1,    -1,    -1,   126,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,   131,
      -1,    -1,   134,   135,   136,   137,   138,   139,    36,    37,
      -1,    39,    40,    41,    -1,    43,    44,   149,   150,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,     3,    -1,    -1,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      47,    48,    49,    50,    -1,    -1,    -1,   125,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,     3,    -1,   151,     6,     7,     8,     9,    -1,    11,
      12,    -1,     3,    -1,    91,     6,     7,     8,     9,    -1,
      11,    12,     3,    -1,    91,     6,     7,     8,     9,    -1,
      11,    12,     3,    -1,    -1,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    -1,    -1,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,   134,   135,   136,
     137,   138,   139,   130,   131,    -1,    -1,   134,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
      -1,    -1,   134,   135,   136,   137,   138,   139,    -1,    -1,
     131,    -1,    -1,   134,   135,   136,   137,   138,   139,    -1,
     131,    -1,    -1,   134,   135,   136,   137,   138,   139,    -1,
     131,    -1,    -1,   134,   135,   136,   137,   138,   139,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    40,    41,    -1,    43,
      44,    -1,    -1,    47,    48,    49,    50,     3,     4,     5,
      -1,    -1,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    -1,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,   123,
     124,   125,    -1,    -1,    -1,   129,    -1,   131,   132,    -1,
      -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,   135,
      31,    32,    33,    34,    35,    36,    37,    -1,    39,    40,
      41,    -1,    43,    44,     4,     5,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    36,    37,    -1,    39,
      40,    41,    -1,    43,    44,    -1,    -1,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,    -1,    -1,    -1,   129,    -1,
     131,   132,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      40,    41,    -1,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,     4,     5,    -1,   125,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,   135,    66,    67,    68,    69,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    40,    41,
      -1,    43,    44,    -1,    -1,    47,    48,    49,    50,     4,
       5,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    -1,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,    36,    37,    -1,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    47,    48,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    -1,
      -1,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     3,     4,     5,    31,    32,    33,    34,    35,    36,
      37,    39,    40,    41,    42,    43,    44,    47,    48,    49,
      50,    57,    58,    59,    60,    61,    62,    63,    64,    66,
      67,    68,    69,    70,    71,    72,    73,   123,   124,   125,
     131,   135,   153,   154,   155,   156,   190,   191,   192,   199,
     200,   202,   203,   204,   205,   207,   214,   219,   220,   221,
     222,   223,   225,   226,   263,   264,    54,   264,     6,     7,
       8,     9,    11,    12,    91,   131,   134,   135,   136,   137,
     138,   139,   162,   163,   164,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   181,   183,   189,
     264,   150,   264,   218,   219,   221,   225,     0,   155,   149,
     193,   194,   218,   220,   225,   192,   192,   192,   208,   209,
     264,   129,     1,   150,   159,   190,   191,   244,   246,   247,
     131,    38,    45,    46,    52,    53,    54,    55,    56,    88,
      89,    90,   126,   157,   158,   201,   221,   202,   225,   227,
     228,   264,   131,   168,   131,   168,   131,   168,   168,   170,
     183,   185,   187,   191,   233,    10,    11,    12,   128,   129,
     131,   170,   135,   140,   141,   136,   137,    13,    14,    15,
      16,   142,   143,    17,    18,   134,   144,   145,    19,    20,
     146,   215,   216,   264,   150,   132,   219,   133,   149,   148,
     159,   206,   130,   189,   149,    52,    76,    77,    78,    80,
      81,    82,    83,    84,    85,    86,    87,    92,   127,   149,
     151,   187,   239,   240,   241,   242,   245,   246,   247,   248,
     249,   251,   254,   255,   256,   257,   260,   262,   264,   190,
     246,   132,   224,   229,   264,   189,   189,   157,   225,   202,
     149,   233,   233,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,   148,   186,   132,   133,   129,   131,   225,
     234,   235,   132,   166,   165,   187,   132,   167,   185,   170,
     170,   170,   171,   171,   172,   172,   173,   173,   173,   173,
     174,   174,   175,   176,   177,   180,   182,   184,   133,   151,
     148,   217,   215,   194,   150,   185,   237,   150,   130,   189,
     243,   131,   131,   264,   149,   149,   149,   187,   149,   131,
     149,   239,   245,   248,   239,   245,   131,   239,   131,   147,
     191,   230,   231,   232,   233,   132,   133,   132,   133,   185,
     188,   130,   189,   132,   230,   234,   235,   129,   131,   170,
     264,   264,   130,   132,   133,   178,   179,   181,   216,   189,
     151,   128,   129,   195,   196,   197,   198,   238,   210,   211,
     227,   147,   147,   187,   187,   149,   149,    91,   261,   245,
     187,    81,   187,   259,   131,   218,   225,   132,   133,   264,
     160,   264,   185,   130,   132,   132,   130,   189,   132,   236,
     167,   147,   264,   189,   237,   148,   198,   133,   151,   151,
     211,   147,   212,   213,   218,   132,   132,   132,   132,   131,
     149,    51,   232,   128,   129,   132,   130,   230,   183,   130,
     151,   195,   189,   133,   149,   147,   252,   253,   149,   258,
     187,   259,   161,   187,   132,   237,   213,   189,   239,   239,
     239,   132,   149,   264,   130,    79,   250,   149,   259,   239,
     132,   239
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
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

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
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

      yyarg[0] = yytname[yytype];
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
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
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
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
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

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
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



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

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
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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

/* Line 1464 of yacc.c  */
#line 142 "SDCC.y"
    {
          werror(W_EMPTY_SOURCE_FILE);
        }
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 155 "SDCC.y"
    {
          // blockNo = 0;
        }
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 159 "SDCC.y"
    {
          ignoreTypedefType = 0;
          if ((yyvsp[(1) - (1)].sym) && (yyvsp[(1) - (1)].sym)->type && IS_FUNC((yyvsp[(1) - (1)].sym)->type))
            {
              /* The only legal storage classes for
               * a function prototype (declaration)
               * are extern and static. extern is the
               * default. Thus, if this function isn't
               * explicitly marked static, mark it
               * extern.
               */
              if ((yyvsp[(1) - (1)].sym)->etype && IS_SPEC((yyvsp[(1) - (1)].sym)->etype) && !SPEC_STAT((yyvsp[(1) - (1)].sym)->etype))
                {
                  SPEC_EXTR((yyvsp[(1) - (1)].sym)->etype) = 1;
                }
            }
          addSymChain (&(yyvsp[(1) - (1)].sym));
          allocVariables ((yyvsp[(1) - (1)].sym));
          cleanUpLevel (SymbolTab, 1);
        }
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 183 "SDCC.y"
    {   /* function type not specified */
                                   /* assume it to be 'int'       */
                                   addDecl((yyvsp[(1) - (2)].sym),0,newIntLink());
                                   (yyval.asts) = createFunction((yyvsp[(1) - (2)].sym),(yyvsp[(2) - (2)].asts));
                               }
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 189 "SDCC.y"
    {
                                    pointerTypes((yyvsp[(2) - (3)].sym)->type,copyLinkChain((yyvsp[(1) - (3)].lnk)));
                                    addDecl((yyvsp[(2) - (3)].sym),0,(yyvsp[(1) - (3)].lnk));
                                    (yyval.asts) = createFunction((yyvsp[(2) - (3)].sym),(yyvsp[(3) - (3)].asts));
                                }
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 198 "SDCC.y"
    { (yyval.lnk) = mergeSpec((yyvsp[(1) - (2)].lnk),(yyvsp[(2) - (2)].lnk),"function_attribute"); }
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 202 "SDCC.y"
    {
                        (yyval.lnk) = newLink(SPECIFIER);
                        FUNC_REGBANK((yyval.lnk)) = (int) ulFromVal(constExprValue((yyvsp[(2) - (2)].asts),TRUE));
                     }
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 206 "SDCC.y"
    {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISREENT((yyval.lnk))=1;
                     }
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 209 "SDCC.y"
    {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISCRITICAL((yyval.lnk)) = 1;
                     }
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 212 "SDCC.y"
    {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISNAKED((yyval.lnk))=1;
                     }
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 215 "SDCC.y"
    {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISJAVANATIVE((yyval.lnk))=1;
                     }
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 218 "SDCC.y"
    {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISOVERLAY((yyval.lnk))=1;
                     }
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 221 "SDCC.y"
    {(yyval.lnk) = newLink (SPECIFIER);
                        FUNC_NONBANKED((yyval.lnk)) = 1;
                        if (FUNC_BANKED((yyval.lnk))) {
                            werror(W_BANKED_WITH_NONBANKED);
                        }
                     }
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 227 "SDCC.y"
    {(yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISSHADOWREGS((yyval.lnk)) = 1;
                     }
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 230 "SDCC.y"
    {(yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISWPARAM((yyval.lnk)) = 1;
                     }
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 233 "SDCC.y"
    {(yyval.lnk) = newLink (SPECIFIER);
                        FUNC_BANKED((yyval.lnk)) = 1;
                        if (FUNC_NONBANKED((yyval.lnk))) {
                            werror(W_BANKED_WITH_NONBANKED);
                        }
                     }
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 240 "SDCC.y"
    {
                        (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_INTNO((yyval.lnk)) = (yyvsp[(1) - (1)].yyint);
                        FUNC_ISISR((yyval.lnk)) = 1;
                     }
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 245 "SDCC.y"
    {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISSMALLC((yyval.lnk))=1;
                     }
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 253 "SDCC.y"
    {
                       werror (E_OLD_STYLE, ((yyvsp[(1) - (2)].sym) ? (yyvsp[(1) - (2)].sym)->name: ""));
                       exit (1);
                     }
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 260 "SDCC.y"
    { (yyval.asts) = newAst_VALUE (symbolVal ((yyvsp[(1) - (1)].sym))); }
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 261 "SDCC.y"
    { ignoreTypedefType = 1; }
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 262 "SDCC.y"
    {
                       ignoreTypedefType = 0;
                       (yyvsp[(4) - (4)].sym) = newSymbol ((yyvsp[(4) - (4)].sym)->name, NestLevel);
                       (yyvsp[(4) - (4)].sym)->implicit = 1;
                       (yyval.asts) = newNode ('.', (yyvsp[(1) - (4)].asts), newAst_VALUE (symbolVal ((yyvsp[(4) - (4)].sym))));
                     }
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 269 "SDCC.y"
    {
                       (yyval.asts) = newNode ('[', (yyvsp[(1) - (4)].asts), (yyvsp[(3) - (4)].asts));
                     }
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 275 "SDCC.y"
    { (yyval.asts) = newAst_VALUE (symbolVal ((yyvsp[(1) - (1)].sym))); }
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 276 "SDCC.y"
    { (yyval.asts) = newAst_VALUE ((yyvsp[(1) - (1)].val)); }
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 278 "SDCC.y"
    { (yyval.asts) = (yyvsp[(2) - (3)].asts); }
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 282 "SDCC.y"
    { (yyval.asts) = newAst_VALUE (strVal ((yyvsp[(1) - (1)].yystr))); }
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 287 "SDCC.y"
    { (yyval.asts) = newNode  ('[', (yyvsp[(1) - (4)].asts), (yyvsp[(3) - (4)].asts)); }
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 288 "SDCC.y"
    { (yyval.asts) = newNode  (CALL,(yyvsp[(1) - (3)].asts),NULL);
                                          (yyval.asts)->left->funcName = 1;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 291 "SDCC.y"
    {
            (yyval.asts) = newNode  (CALL,(yyvsp[(1) - (4)].asts),(yyvsp[(3) - (4)].asts)); (yyval.asts)->left->funcName = 1;
          }
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 294 "SDCC.y"
    { ignoreTypedefType = 1; }
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 295 "SDCC.y"
    {
                        ignoreTypedefType = 0;
                        (yyvsp[(4) - (4)].sym) = newSymbol((yyvsp[(4) - (4)].sym)->name,NestLevel);
                        (yyvsp[(4) - (4)].sym)->implicit = 1;
                        (yyval.asts) = newNode(PTR_OP,newNode('&',(yyvsp[(1) - (4)].asts),NULL),newAst_VALUE(symbolVal((yyvsp[(4) - (4)].sym))));
                      }
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 301 "SDCC.y"
    { ignoreTypedefType = 1; }
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 302 "SDCC.y"
    {
                        ignoreTypedefType = 0;
                        (yyvsp[(4) - (4)].sym) = newSymbol((yyvsp[(4) - (4)].sym)->name,NestLevel);
                        (yyvsp[(4) - (4)].sym)->implicit = 1;
                        (yyval.asts) = newNode(PTR_OP,(yyvsp[(1) - (4)].asts),newAst_VALUE(symbolVal((yyvsp[(4) - (4)].sym))));
                      }
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 309 "SDCC.y"
    { (yyval.asts) = newNode(INC_OP,(yyvsp[(1) - (2)].asts),NULL);}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 311 "SDCC.y"
    { (yyval.asts) = newNode(DEC_OP,(yyvsp[(1) - (2)].asts),NULL); }
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 316 "SDCC.y"
    { (yyval.asts) = newNode(PARAM,(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts)); }
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 321 "SDCC.y"
    { (yyval.asts) = newNode (INC_OP, NULL, (yyvsp[(2) - (2)].asts)); }
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 322 "SDCC.y"
    { (yyval.asts) = newNode (DEC_OP, NULL, (yyvsp[(2) - (2)].asts)); }
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 323 "SDCC.y"
    { (yyval.asts) = newNode ((yyvsp[(1) - (2)].yyint), (yyvsp[(2) - (2)].asts), NULL); }
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 324 "SDCC.y"
    { (yyval.asts) = newNode (SIZEOF, NULL, (yyvsp[(2) - (2)].asts)); }
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 325 "SDCC.y"
    { (yyval.asts) = newAst_VALUE (sizeofOp ((yyvsp[(3) - (4)].lnk))); }
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 326 "SDCC.y"
    { (yyval.asts) = newNode (TYPEOF, NULL, (yyvsp[(2) - (2)].asts)); }
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 327 "SDCC.y"
    { (yyval.asts) = offsetofOp((yyvsp[(3) - (6)].lnk), (yyvsp[(5) - (6)].asts)); }
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 331 "SDCC.y"
    { (yyval.yyint) = '&';}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 332 "SDCC.y"
    { (yyval.yyint) = '*';}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 333 "SDCC.y"
    { (yyval.yyint) = '+';}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 334 "SDCC.y"
    { (yyval.yyint) = '-';}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 335 "SDCC.y"
    { (yyval.yyint) = '~';}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 336 "SDCC.y"
    { (yyval.yyint) = '!';}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 341 "SDCC.y"
    { (yyval.asts) = newNode(CAST,newAst_LINK((yyvsp[(2) - (4)].lnk)),(yyvsp[(4) - (4)].asts)); }
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 346 "SDCC.y"
    { (yyval.asts) = newNode('*',(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 347 "SDCC.y"
    { (yyval.asts) = newNode('/',(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 348 "SDCC.y"
    { (yyval.asts) = newNode('%',(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 353 "SDCC.y"
    { (yyval.asts)=newNode('+',(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 354 "SDCC.y"
    { (yyval.asts)=newNode('-',(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 359 "SDCC.y"
    { (yyval.asts) = newNode(LEFT_OP,(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts)); }
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 360 "SDCC.y"
    { (yyval.asts) = newNode(RIGHT_OP,(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts)); }
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 365 "SDCC.y"
    { (yyval.asts) = newNode('<',  (yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 366 "SDCC.y"
    { (yyval.asts) = newNode('>',  (yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 367 "SDCC.y"
    { (yyval.asts) = newNode(LE_OP,(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 368 "SDCC.y"
    { (yyval.asts) = newNode(GE_OP,(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 373 "SDCC.y"
    { (yyval.asts) = newNode(EQ_OP,(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 374 "SDCC.y"
    { (yyval.asts) = newNode(NE_OP,(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 379 "SDCC.y"
    { (yyval.asts) = newNode('&',(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 384 "SDCC.y"
    { (yyval.asts) = newNode('^',(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 389 "SDCC.y"
    { (yyval.asts) = newNode('|',(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 394 "SDCC.y"
    { seqPointNo++;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 395 "SDCC.y"
    { (yyval.asts) = newNode(AND_OP,(yyvsp[(1) - (4)].asts),(yyvsp[(4) - (4)].asts));}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 400 "SDCC.y"
    { seqPointNo++;}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 401 "SDCC.y"
    { (yyval.asts) = newNode(OR_OP,(yyvsp[(1) - (4)].asts),(yyvsp[(4) - (4)].asts)); }
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 406 "SDCC.y"
    { seqPointNo++;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 407 "SDCC.y"
    {
                        (yyval.asts) = newNode(':',(yyvsp[(4) - (6)].asts),(yyvsp[(6) - (6)].asts));
                        (yyval.asts) = newNode('?',(yyvsp[(1) - (6)].asts),(yyval.asts));
                     }
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 416 "SDCC.y"
    {

                             switch ((yyvsp[(2) - (3)].yyint)) {
                             case '=':
                                     (yyval.asts) = newNode((yyvsp[(2) - (3)].yyint),(yyvsp[(1) - (3)].asts),(yyvsp[(3) - (3)].asts));
                                     break;
                             case MUL_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), '*', (yyvsp[(3) - (3)].asts));
                                     break;
                             case DIV_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), '/', (yyvsp[(3) - (3)].asts));
                                     break;
                             case MOD_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), '%', (yyvsp[(3) - (3)].asts));
                                     break;
                             case ADD_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), '+', (yyvsp[(3) - (3)].asts));
                                     break;
                             case SUB_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), '-', (yyvsp[(3) - (3)].asts));
                                     break;
                             case LEFT_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), LEFT_OP, (yyvsp[(3) - (3)].asts));
                                     break;
                             case RIGHT_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), RIGHT_OP, (yyvsp[(3) - (3)].asts));
                                     break;
                             case AND_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), '&', (yyvsp[(3) - (3)].asts));
                                     break;
                             case XOR_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), '^', (yyvsp[(3) - (3)].asts));
                                     break;
                             case OR_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[(1) - (3)].asts), '|', (yyvsp[(3) - (3)].asts));
                                     break;
                             default :
                                     (yyval.asts) = NULL;
                             }

                     }
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 460 "SDCC.y"
    { (yyval.yyint) = '=';}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 475 "SDCC.y"
    { seqPointNo++;}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 475 "SDCC.y"
    { (yyval.asts) = newNode(',',(yyvsp[(1) - (4)].asts),(yyvsp[(4) - (4)].asts));}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 484 "SDCC.y"
    {
         /* Special case: if incomplete struct/union declared without name, */
         /* make sure an incomplete type for it exists in the current scope */
         if (IS_STRUCT((yyvsp[(1) - (2)].lnk)))
           {
             structdef *sdef = SPEC_STRUCT((yyvsp[(1) - (2)].lnk));
             structdef *osdef;
             osdef = findSymWithBlock (StructTab, sdef->tagsym, currBlockno);
             if (osdef && osdef->block != currBlockno)
               {
                 sdef = newStruct(osdef->tagsym->name);
                 sdef->level = NestLevel;
                 sdef->block = currBlockno;
                 sdef->tagsym = newSymbol (osdef->tagsym->name, NestLevel);
                 addSym (StructTab, sdef, sdef->tag, sdef->level, currBlockno, 0);
                 uselessDecl = FALSE;
               }
           }
         if (uselessDecl)
           werror(W_USELESS_DECL);
         uselessDecl = TRUE;
         (yyval.sym) = NULL;
      }
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 508 "SDCC.y"
    {
         /* add the specifier list to the id */
         symbol *sym , *sym1;

         for (sym1 = sym = reverseSyms((yyvsp[(2) - (3)].sym));sym != NULL;sym = sym->next) {
             sym_link *lnk = copyLinkChain((yyvsp[(1) - (3)].lnk));
             /* do the pointer stuff */
             pointerTypes(sym->type,lnk);
             addDecl (sym,0,lnk);
         }

         uselessDecl = TRUE;
         (yyval.sym) = sym1;
      }
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 524 "SDCC.y"
    { (yyval.lnk) = finalizeSpec((yyvsp[(1) - (1)].lnk)); }
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 527 "SDCC.y"
    { (yyval.lnk) = (yyvsp[(1) - (1)].lnk); }
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 528 "SDCC.y"
    {
     /* if the decl $2 is not a specifier */
     /* find the spec and replace it      */
     (yyval.lnk) = mergeDeclSpec((yyvsp[(1) - (2)].lnk), (yyvsp[(2) - (2)].lnk), "storage_class_specifier declaration_specifiers - skipped");
   }
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 533 "SDCC.y"
    { (yyval.lnk) = (yyvsp[(1) - (1)].lnk); }
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 534 "SDCC.y"
    {
     /* if the decl $2 is not a specifier */
     /* find the spec and replace it      */
     (yyval.lnk) = mergeDeclSpec((yyvsp[(1) - (2)].lnk), (yyvsp[(2) - (2)].lnk), "type_specifier declaration_specifiers - skipped");
   }
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 539 "SDCC.y"
    { (yyval.lnk) = (yyvsp[(1) - (1)].lnk); }
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 540 "SDCC.y"
    {
     /* if the decl $2 is not a specifier */
     /* find the spec and replace it      */
     (yyval.lnk) = mergeDeclSpec((yyvsp[(1) - (2)].lnk), (yyvsp[(2) - (2)].lnk), "function_specifier declaration_specifiers - skipped");
   }
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 549 "SDCC.y"
    { (yyvsp[(3) - (3)].sym)->next = (yyvsp[(1) - (3)].sym); (yyval.sym) = (yyvsp[(3) - (3)].sym);}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 553 "SDCC.y"
    { (yyvsp[(1) - (1)].sym)->ival = NULL; }
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 554 "SDCC.y"
    { (yyvsp[(1) - (3)].sym)->ival = (yyvsp[(3) - (3)].ilist); }
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 558 "SDCC.y"
    { (yyval.dsgn) = NULL; }
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 563 "SDCC.y"
    { (yyval.dsgn) = revDesignation((yyvsp[(1) - (2)].dsgn)); }
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 568 "SDCC.y"
    { (yyvsp[(2) - (2)].dsgn)->next = (yyvsp[(1) - (2)].dsgn); (yyval.dsgn) = (yyvsp[(2) - (2)].dsgn); }
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 573 "SDCC.y"
    {
            value *tval;
            int elemno;

            tval = constExprValue((yyvsp[(2) - (3)].asts), TRUE);
            /* if it is not a constant then Error  */
            if (!tval || (SPEC_SCLS(tval->etype) != S_LITERAL))
              {
                werror (E_CONST_EXPECTED);
                elemno = 0; /* arbitrary fixup */
              }
            else
              {
                if ((elemno = (int) ulFromVal(tval)) < 0)
                  {
                    werror (E_BAD_DESIGNATOR);
                    elemno = 0; /* arbitrary fixup */
                  }
              }
            (yyval.dsgn) = newDesignation(DESIGNATOR_ARRAY, &elemno);
         }
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 594 "SDCC.y"
    { (yyval.dsgn) = newDesignation(DESIGNATOR_STRUCT,(yyvsp[(2) - (2)].sym)); }
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 598 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_TYPEDEF((yyval.lnk)) = 1;
               }
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 602 "SDCC.y"
    {
                  (yyval.lnk) = newLink(SPECIFIER);
                  SPEC_EXTR((yyval.lnk)) = 1;
               }
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 606 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_STAT((yyval.lnk)) = 1;
               }
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 610 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_AUTO;
               }
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 614 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_REGISTER;
               }
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 621 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_INLINE((yyval.lnk)) = 1;
               }
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 625 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_NORETURN((yyval.lnk)) = 1;
               }
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 632 "SDCC.y"
    { (yyval.yyint) = INTNO_UNSPEC; }
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 634 "SDCC.y"
    { int intno = (int) ulFromVal(constExprValue((yyvsp[(2) - (2)].asts),TRUE));
          if ((intno >= 0) && (intno <= INTNO_MAX))
            (yyval.yyint) = intno;
          else
            {
              werror(E_INT_BAD_INTNO, intno);
              (yyval.yyint) = INTNO_UNSPEC;
            }
        }
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 646 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_BOOL;
                  ignoreTypedefType = 1;
               }
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 651 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_CHAR;
                  ignoreTypedefType = 1;
               }
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 656 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_SHORT((yyval.lnk)) = 1;
                  ignoreTypedefType = 1;
               }
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 661 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_INT;
                  ignoreTypedefType = 1;
               }
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 666 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_LONG((yyval.lnk)) = 1;
                  ignoreTypedefType = 1;
               }
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 671 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  (yyval.lnk)->select.s.b_signed = 1;
                  ignoreTypedefType = 1;
               }
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 676 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_USIGN((yyval.lnk)) = 1;
                  ignoreTypedefType = 1;
               }
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 681 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_VOID;
                  ignoreTypedefType = 1;
               }
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 686 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_CONST((yyval.lnk)) = 1;
               }
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 690 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_VOLATILE((yyval.lnk)) = 1;
               }
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 694 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_RESTRICT((yyval.lnk)) = 1;
               }
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 698 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_ADDRSPACE((yyval.lnk)) = findSym (AddrspaceTab, 0, (yyvsp[(1) - (1)].yychar));
               }
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 702 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_FLOAT;
                  ignoreTypedefType = 1;
               }
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 707 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_FIXED16X16;
                  ignoreTypedefType = 1;
               }
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 712 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_XDATA;
               }
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 716 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_CODE;
               }
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 720 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_EEPROM;
               }
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 724 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_DATA;
               }
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 728 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_IDATA;
               }
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 732 "SDCC.y"
    {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_PDATA;
               }
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 736 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_BIT;
                  SPEC_SCLS((yyval.lnk)) = S_BIT;
                  SPEC_BLEN((yyval.lnk)) = 1;
                  SPEC_BSTR((yyval.lnk)) = 0;
                  ignoreTypedefType = 1;
               }
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 744 "SDCC.y"
    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  /* add this to the storage class specifier  */
                  SPEC_ABSA((yyval.lnk)) = 1;   /* set the absolute addr flag */
                  /* now get the abs addr from value */
                  SPEC_ADDR((yyval.lnk)) = (unsigned int) ulFromVal(constExprValue((yyvsp[(2) - (2)].asts),TRUE));
               }
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 751 "SDCC.y"
    {
                                   uselessDecl = FALSE;
                                   (yyval.lnk) = (yyvsp[(1) - (1)].lnk);
                                   ignoreTypedefType = 1;
                                }
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 756 "SDCC.y"
    {
                           cenum = NULL;
                           uselessDecl = FALSE;
                           ignoreTypedefType = 1;
                           (yyval.lnk) = (yyvsp[(1) - (1)].lnk);
                        }
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 763 "SDCC.y"
    {
            symbol *sym;
            sym_link *p;
            sym = findSym(TypedefTab,NULL,(yyvsp[(1) - (1)].yychar));
            (yyval.lnk) = p = copyLinkChain(sym ? sym->type : NULL);
            SPEC_TYPEDEF(getSpec(p)) = 0;
            ignoreTypedefType = 1;
         }
    break;

  case 169:

/* Line 1464 of yacc.c  */
#line 775 "SDCC.y"
    {
               (yyval.lnk) = newLink(SPECIFIER);
               SPEC_NOUN((yyval.lnk)) = V_SBIT;
               SPEC_SCLS((yyval.lnk)) = S_SBIT;
               SPEC_BLEN((yyval.lnk)) = 1;
               SPEC_BSTR((yyval.lnk)) = 0;
               ignoreTypedefType = 1;
            }
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 787 "SDCC.y"
    {
               (yyval.lnk) = newLink(SPECIFIER);
               FUNC_REGBANK((yyval.lnk)) = 0;
               SPEC_NOUN((yyval.lnk))    = V_CHAR;
               SPEC_SCLS((yyval.lnk))    = S_SFR;
               SPEC_USIGN((yyval.lnk))   = 1;
               ignoreTypedefType = 1;
            }
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 795 "SDCC.y"
    {
               (yyval.lnk) = newLink(SPECIFIER);
               FUNC_REGBANK((yyval.lnk)) = 1;
               SPEC_NOUN((yyval.lnk))    = V_CHAR;
               SPEC_SCLS((yyval.lnk))    = S_SFR;
               SPEC_USIGN((yyval.lnk))   = 1;
               ignoreTypedefType = 1;
            }
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 806 "SDCC.y"
    {
               (yyval.lnk) = newLink(SPECIFIER);
               FUNC_REGBANK((yyval.lnk)) = 0;
               SPEC_NOUN((yyval.lnk))    = V_INT;
               SPEC_SCLS((yyval.lnk))    = S_SFR;
               SPEC_USIGN((yyval.lnk))   = 1;
               ignoreTypedefType = 1;
            }
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 817 "SDCC.y"
    {
               (yyval.lnk) = newLink(SPECIFIER);
               FUNC_REGBANK((yyval.lnk)) = 0;
               SPEC_NOUN((yyval.lnk))    = V_INT;
               SPEC_SCLS((yyval.lnk))    = S_SFR;
               SPEC_LONG((yyval.lnk))    = 1;
               SPEC_USIGN((yyval.lnk))   = 1;
               ignoreTypedefType = 1;
            }
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 830 "SDCC.y"
    {
          structdef *sdef;

          if (! (yyvsp[(2) - (2)].sdef)->tagsym)
            {
              /* no tag given, so new struct def for current scope */
              addSym (StructTab, (yyvsp[(2) - (2)].sdef), (yyvsp[(2) - (2)].sdef)->tag, (yyvsp[(2) - (2)].sdef)->level, currBlockno, 0);
            }
          else
            {
              sdef = findSymWithBlock (StructTab, (yyvsp[(2) - (2)].sdef)->tagsym, currBlockno);
              if (sdef)
                {
                  /* Error if a complete type already defined in this scope */
                  if (sdef->block == currBlockno)
                    {
                      if (sdef->fields)
                        {
                          werror(E_STRUCT_REDEF, (yyvsp[(2) - (2)].sdef)->tag);
                          werrorfl(sdef->tagsym->fileDef, sdef->tagsym->lineDef, E_PREVIOUS_DEF);
                        }
                      else
                        {
                          (yyvsp[(2) - (2)].sdef) = sdef; /* We are completing an incomplete type */
                        }
                    }
                  else
                    {
                      /* There is an existing struct def in an outer scope. */
                      /* Create new struct def for current scope */
                      addSym (StructTab, (yyvsp[(2) - (2)].sdef), (yyvsp[(2) - (2)].sdef)->tag, (yyvsp[(2) - (2)].sdef)->level, currBlockno, 0);
                    }
                }
              else
               {
                 /* There is no existing struct def at all. */
                 /* Create new struct def for current scope */
                 addSym (StructTab, (yyvsp[(2) - (2)].sdef), (yyvsp[(2) - (2)].sdef)->tag, (yyvsp[(2) - (2)].sdef)->level, currBlockno, 0);
               }
            }

          if (!(yyvsp[(2) - (2)].sdef)->type)
            {
              (yyvsp[(2) - (2)].sdef)->type = (yyvsp[(1) - (2)].yyint);
            }
          else
            {
              if ((yyvsp[(2) - (2)].sdef)->type != (yyvsp[(1) - (2)].yyint))
                  werror(E_BAD_TAG, (yyvsp[(2) - (2)].sdef)->tag, (yyvsp[(1) - (2)].yyint)==STRUCT ? "struct" : "union");
            }
        }
    break;

  case 176:

/* Line 1464 of yacc.c  */
#line 882 "SDCC.y"
    {
          structdef *sdef;
          symbol *sym, *dsym;

          // check for errors in structure members
          for (sym=(yyvsp[(5) - (6)].sym); sym; sym=sym->next)
            {
              if (IS_ABSOLUTE(sym->etype))
                {
                  werrorfl(sym->fileDef, sym->lineDef, E_NOT_ALLOWED, "'at'");
                  SPEC_ABSA(sym->etype) = 0;
                }
              if (IS_SPEC(sym->etype) && SPEC_SCLS(sym->etype))
                {
                  werrorfl(sym->fileDef, sym->lineDef, E_NOT_ALLOWED, "storage class");
                  printTypeChainRaw (sym->type, NULL);
                  SPEC_SCLS(sym->etype) = 0;
                }
              for (dsym=sym->next; dsym; dsym=dsym->next)
                {
                  if (*dsym->name && strcmp(sym->name, dsym->name)==0)
                    {
                      werrorfl(sym->fileDef, sym->lineDef, E_DUPLICATE_MEMBER,
                               (yyvsp[(1) - (6)].yyint)==STRUCT ? "struct" : "union", sym->name);
                      werrorfl(dsym->fileDef, dsym->lineDef, E_PREVIOUS_DEF);
                    }
                }
            }

          /* Create a structdef   */
          sdef = (yyvsp[(2) - (6)].sdef);
          sdef->fields = reverseSyms((yyvsp[(5) - (6)].sym));        /* link the fields */
          sdef->size = compStructSize((yyvsp[(1) - (6)].yyint), sdef); /* update size of  */
          promoteAnonStructs ((yyvsp[(1) - (6)].yyint), sdef);

          /* Create the specifier */
          (yyval.lnk) = newLink (SPECIFIER);
          SPEC_NOUN((yyval.lnk)) = V_STRUCT;
          SPEC_STRUCT((yyval.lnk))= sdef;
        }
    break;

  case 177:

/* Line 1464 of yacc.c  */
#line 923 "SDCC.y"
    {
          structdef *sdef;

          sdef = findSymWithBlock (StructTab, (yyvsp[(2) - (2)].sdef)->tagsym, currBlockno);
          if (sdef)
            (yyvsp[(2) - (2)].sdef) = sdef;
          else
            {
              /* new struct def for current scope */
              addSym (StructTab, (yyvsp[(2) - (2)].sdef), (yyvsp[(2) - (2)].sdef)->tag, (yyvsp[(2) - (2)].sdef)->level, currBlockno, 0);
            }
          (yyval.lnk) = newLink(SPECIFIER);
          SPEC_NOUN((yyval.lnk)) = V_STRUCT;
          SPEC_STRUCT((yyval.lnk)) = (yyvsp[(2) - (2)].sdef);

          if (!(yyvsp[(2) - (2)].sdef)->type)
            {
              (yyvsp[(2) - (2)].sdef)->type = (yyvsp[(1) - (2)].yyint);
            }
          else
            {
              if ((yyvsp[(2) - (2)].sdef)->type != (yyvsp[(1) - (2)].yyint))
                  werror(E_BAD_TAG, (yyvsp[(2) - (2)].sdef)->tag, (yyvsp[(1) - (2)].yyint)==STRUCT ? "struct" : "union");
            }
        }
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 951 "SDCC.y"
    { (yyval.yyint) = STRUCT; ignoreTypedefType = 1; }
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 952 "SDCC.y"
    { (yyval.yyint) = UNION; ignoreTypedefType = 1; }
    break;

  case 181:

/* Line 1464 of yacc.c  */
#line 957 "SDCC.y"
    {  /* synthesize a name add to structtable */
          ignoreTypedefType = 0;
          (yyval.sdef) = newStruct(genSymName(NestLevel));
          (yyval.sdef)->level = NestLevel;
          (yyval.sdef)->block = currBlockno;
          (yyval.sdef)->tagsym = NULL;
          //addSym (StructTab, $$, $$->tag, $$->level, currBlockno, 0);
        }
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 969 "SDCC.y"
    {  /* add name to structure table */
          ignoreTypedefType = 0;
          (yyval.sdef) = newStruct((yyvsp[(1) - (1)].sym)->name);
          (yyval.sdef)->level = NestLevel;
          (yyval.sdef)->block = currBlockno;
          (yyval.sdef)->tagsym = (yyvsp[(1) - (1)].sym);
          //$$ = findSymWithBlock (StructTab, $1, currBlockno);
          //if (! $$ )
          //  {
          //    $$ = newStruct($1->name);
          //    $$->level = NestLevel;
          //    $$->tagsym = $1;
          //    //addSym (StructTab, $$, $$->tag, $$->level, currBlockno, 0);
          //  }
        }
    break;

  case 184:

/* Line 1464 of yacc.c  */
#line 989 "SDCC.y"
    {
          symbol *sym = (yyvsp[(2) - (2)].sym);

          /* go to the end of the chain */
          while (sym->next) sym = sym->next;
          sym->next = (yyvsp[(1) - (2)].sym);

           (yyval.sym) = (yyvsp[(2) - (2)].sym);
        }
    break;

  case 185:

/* Line 1464 of yacc.c  */
#line 1002 "SDCC.y"
    {
          /* add this type to all the symbols */
          symbol *sym;
          for ( sym = (yyvsp[(2) - (3)].sym); sym != NULL; sym = sym->next )
            {
              sym_link *btype = copyLinkChain((yyvsp[(1) - (3)].lnk));

              pointerTypes(sym->type, btype);
              if (!sym->type)
                {
                  sym->type = btype;
                  sym->etype = getSpec(sym->type);
                }
              else
                  addDecl (sym, 0, btype);
              /* make sure the type is complete and sane */
              checkTypeSanity(sym->etype, sym->name);
            }
          ignoreTypedefType = 0;
          (yyval.sym) = (yyvsp[(2) - (3)].sym);
        }
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 1028 "SDCC.y"
    {
          (yyvsp[(3) - (3)].sym)->next  = (yyvsp[(1) - (3)].sym);
          (yyval.sym) = (yyvsp[(3) - (3)].sym);
        }
    break;

  case 189:

/* Line 1464 of yacc.c  */
#line 1037 "SDCC.y"
    {
          unsigned int bitsize;
          (yyval.sym) = newSymbol (genSymName(NestLevel), NestLevel);
          bitsize = (unsigned int) ulFromVal(constExprValue((yyvsp[(2) - (2)].asts), TRUE));
          if (bitsize > (port->s.int_size * 8))
            {
              bitsize = port->s.int_size * 8;
              werror(E_BITFLD_SIZE, bitsize);
            }
          if (!bitsize)
              bitsize = BITVAR_PAD;
          (yyval.sym)->bitVar = bitsize;
          (yyval.sym)->bitUnnamed = 1;
        }
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 1052 "SDCC.y"
    {
          unsigned int bitsize;
          bitsize = (unsigned int) ulFromVal(constExprValue((yyvsp[(3) - (3)].asts), TRUE));
          if (bitsize > (port->s.int_size * 8))
            {
              bitsize = port->s.int_size * 8;
              werror(E_BITFLD_SIZE, bitsize);
            }
          if (!bitsize)
            {
              (yyval.sym) = newSymbol (genSymName(NestLevel), NestLevel);
              (yyval.sym)->bitVar = BITVAR_PAD;
              werror(W_BITFLD_NAMED);
            }
          else
              (yyvsp[(1) - (3)].sym)->bitVar = bitsize;
        }
    break;

  case 191:

/* Line 1464 of yacc.c  */
#line 1069 "SDCC.y"
    { (yyval.sym) = newSymbol ("", NestLevel); }
    break;

  case 192:

/* Line 1464 of yacc.c  */
#line 1074 "SDCC.y"
    {
          (yyval.lnk) = newEnumType ((yyvsp[(3) - (4)].sym));
          SPEC_SCLS(getSpec((yyval.lnk))) = 0;
        }
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 1079 "SDCC.y"
    {
          symbol *csym;
          sym_link *enumtype;

          csym = findSymWithLevel(enumTab, (yyvsp[(2) - (5)].sym));
          if ((csym && csym->level == (yyvsp[(2) - (5)].sym)->level))
            {
              werrorfl((yyvsp[(2) - (5)].sym)->fileDef, (yyvsp[(2) - (5)].sym)->lineDef, E_DUPLICATE_TYPEDEF, csym->name);
              werrorfl(csym->fileDef, csym->lineDef, E_PREVIOUS_DEF);
            }

          enumtype = newEnumType ((yyvsp[(4) - (5)].sym));
          SPEC_SCLS(getSpec(enumtype)) = 0;
          (yyvsp[(2) - (5)].sym)->type = enumtype;

          /* add this to the enumerator table */
          if (!csym)
              addSym (enumTab, (yyvsp[(2) - (5)].sym), (yyvsp[(2) - (5)].sym)->name, (yyvsp[(2) - (5)].sym)->level, (yyvsp[(2) - (5)].sym)->block, 0);
          (yyval.lnk) = copyLinkChain(enumtype);
        }
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 1100 "SDCC.y"
    {
          symbol *csym;

          /* check the enumerator table */
          if ((csym = findSymWithLevel(enumTab, (yyvsp[(2) - (2)].sym))))
              (yyval.lnk) = copyLinkChain(csym->type);
          else
            {
              (yyval.lnk) = newLink(SPECIFIER);
              SPEC_NOUN((yyval.lnk)) = V_INT;
            }
        }
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 1118 "SDCC.y"
    {
          (yyvsp[(3) - (3)].sym)->next = (yyvsp[(1) - (3)].sym);
          (yyval.sym) = (yyvsp[(3) - (3)].sym);
        }
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 1126 "SDCC.y"
    {
          symbol *sym;

          // check if the symbol at the same level already exists
          if ((sym = findSymWithLevel (SymbolTab, (yyvsp[(1) - (2)].sym))) && sym->level == (yyvsp[(1) - (2)].sym)->level)
            {
              werrorfl ((yyvsp[(1) - (2)].sym)->fileDef, (yyvsp[(1) - (2)].sym)->lineDef, E_DUPLICATE_MEMBER, "enum", (yyvsp[(1) - (2)].sym)->name);
              werrorfl (sym->fileDef, sym->lineDef, E_PREVIOUS_DEF);
            }
          (yyvsp[(1) - (2)].sym)->type = copyLinkChain ((yyvsp[(2) - (2)].val)->type);
          (yyvsp[(1) - (2)].sym)->etype = getSpec ((yyvsp[(1) - (2)].sym)->type);
          SPEC_ENUM ((yyvsp[(1) - (2)].sym)->etype) = 1;
          (yyval.sym) = (yyvsp[(1) - (2)].sym);
          // do this now, so we can use it for the next enums in the list
          addSymChain (&(yyvsp[(1) - (2)].sym));
        }
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 1146 "SDCC.y"
    {
          value *val;

          val = constExprValue((yyvsp[(2) - (2)].asts), TRUE);
          if (!IS_INT(val->type) && !IS_CHAR(val->type) && !IS_BOOL(val->type))
            {
              werror(E_ENUM_NON_INTEGER);
              SNPRINTF(lbuff, sizeof(lbuff), "%d", (int) ulFromVal(val));
              val = constVal(lbuff);
            }
          (yyval.val) = cenum = val;
        }
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 1158 "SDCC.y"
    {
          if (cenum)
            {
              SNPRINTF(lbuff, sizeof(lbuff), "%d", (int) ulFromVal(cenum)+1);
              (yyval.val) = cenum = constVal(lbuff);
            }
          else
            {
              (yyval.val) = cenum = constCharVal(0);
            }
        }
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 1172 "SDCC.y"
    { (yyval.sym) = (yyvsp[(1) - (1)].sym); }
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 1174 "SDCC.y"
    {
             addDecl ((yyvsp[(2) - (2)].sym),0,reverseLink((yyvsp[(1) - (2)].lnk)));
             (yyval.sym) = (yyvsp[(2) - (2)].sym);
         }
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 1181 "SDCC.y"
    { (yyval.sym) = (yyvsp[(1) - (1)].sym); }
    break;

  case 204:

/* Line 1464 of yacc.c  */
#line 1182 "SDCC.y"
    { (yyval.sym) = (yyvsp[(1) - (1)].sym); }
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 1186 "SDCC.y"
    { (yyval.sym) = (yyvsp[(1) - (1)].sym); }
    break;

  case 206:

/* Line 1464 of yacc.c  */
#line 1188 "SDCC.y"
    {
             addDecl ((yyvsp[(2) - (2)].sym),0,reverseLink((yyvsp[(1) - (2)].lnk)));
             (yyval.sym) = (yyvsp[(2) - (2)].sym);
         }
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 1195 "SDCC.y"
    { (yyval.sym) = (yyvsp[(1) - (1)].sym); }
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 1196 "SDCC.y"
    {
           // copy the functionAttributes (not the args and hasVargs !!)
           struct value *args;
           unsigned hasVargs;
           sym_link *funcType=(yyvsp[(1) - (2)].sym)->type;

           while (funcType && !IS_FUNC(funcType))
             funcType = funcType->next;

           if (!funcType)
             werror (E_FUNC_ATTR);
           else
             {
               args=FUNC_ARGS(funcType);
               hasVargs=FUNC_HASVARARGS(funcType);

               memcpy (&funcType->funcAttrs, &(yyvsp[(2) - (2)].lnk)->funcAttrs,
                   sizeof((yyvsp[(2) - (2)].lnk)->funcAttrs));

               FUNC_ARGS(funcType)=args;
               FUNC_HASVARARGS(funcType)=hasVargs;

               // just to be sure
               memset (&(yyvsp[(2) - (2)].lnk)->funcAttrs, 0,
                   sizeof((yyvsp[(2) - (2)].lnk)->funcAttrs));

               addDecl ((yyvsp[(1) - (2)].sym),0,(yyvsp[(2) - (2)].lnk));
             }
   }
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 1229 "SDCC.y"
    { (yyval.sym) = (yyvsp[(2) - (3)].sym); }
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 1231 "SDCC.y"
    {
            sym_link   *p;

            p = newLink (DECLARATOR);
            DCL_TYPE(p) = ARRAY;
            DCL_ELEM(p) = 0;
            addDecl((yyvsp[(1) - (3)].sym),0,p);
         }
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 1240 "SDCC.y"
    {
            sym_link *p;
            value *tval;
            int size;

            tval = constExprValue((yyvsp[(3) - (4)].asts), TRUE);
            /* if it is not a constant then Error  */
            p = newLink (DECLARATOR);
            DCL_TYPE(p) = ARRAY;

            if (!tval || (SPEC_SCLS(tval->etype) != S_LITERAL))
              {
                werror(E_CONST_EXPECTED);
                /* Assume a single item array to limit the cascade */
                /* of additional errors. */
                size = 1;
              }
            else
              {
                if ((size = (int) ulFromVal(tval)) < 0)
                  {
                    werror(E_NEGATIVE_ARRAY_SIZE, (yyvsp[(1) - (4)].sym)->name);
                    size = 1;
                  }
              }
            DCL_ELEM(p) = size;
            addDecl((yyvsp[(1) - (4)].sym), 0, p);
         }
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 1272 "SDCC.y"
    {
          addDecl ((yyvsp[(1) - (3)].sym), FUNCTION, NULL);
        }
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 1276 "SDCC.y"
    {
          NestLevel++;
          STACK_PUSH(blockNum, currBlockno);
          currBlockno = ++blockNo;
        }
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 1282 "SDCC.y"
    {
          sym_link *funcType;

          addDecl ((yyvsp[(1) - (5)].sym), FUNCTION, NULL);

          funcType = (yyvsp[(1) - (5)].sym)->type;
          while (funcType && !IS_FUNC(funcType))
              funcType = funcType->next;

          assert (funcType);

          FUNC_HASVARARGS(funcType) = IS_VARG((yyvsp[(4) - (5)].val));
          FUNC_ARGS(funcType) = reverseVal((yyvsp[(4) - (5)].val));

          /* nest level was incremented to take care of the parms  */
          NestLevel--;
          currBlockno = STACK_POP(blockNum);

          // if this was a pointer (to a function)
          if (!IS_FUNC((yyvsp[(1) - (5)].sym)->type))
              cleanUpLevel(SymbolTab, NestLevel + 1);

          (yyval.sym) = (yyvsp[(1) - (5)].sym);
        }
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 1307 "SDCC.y"
    {
          werror(E_OLD_STYLE,(yyvsp[(1) - (4)].sym)->name);
          /* assume it returns an int */
          (yyvsp[(1) - (4)].sym)->type = (yyvsp[(1) - (4)].sym)->etype = newIntLink();
          (yyval.sym) = (yyvsp[(1) - (4)].sym);
        }
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 1316 "SDCC.y"
    { (yyval.lnk) = (yyvsp[(1) - (1)].lnk);}
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 1318 "SDCC.y"
    {
             (yyval.lnk) = (yyvsp[(1) - (2)].lnk);
             if (IS_SPEC((yyvsp[(2) - (2)].lnk))) {
                 DCL_TSPEC((yyvsp[(1) - (2)].lnk)) = (yyvsp[(2) - (2)].lnk);
                 DCL_PTR_CONST((yyvsp[(1) - (2)].lnk)) = SPEC_CONST((yyvsp[(2) - (2)].lnk));
                 DCL_PTR_VOLATILE((yyvsp[(1) - (2)].lnk)) = SPEC_VOLATILE((yyvsp[(2) - (2)].lnk));
                 DCL_PTR_RESTRICT((yyvsp[(1) - (2)].lnk)) = SPEC_RESTRICT((yyvsp[(2) - (2)].lnk));
                 DCL_PTR_ADDRSPACE((yyvsp[(1) - (2)].lnk)) = SPEC_ADDRSPACE((yyvsp[(2) - (2)].lnk));
             }
             else
                 werror (W_PTR_TYPE_INVALID);
         }
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 1331 "SDCC.y"
    {
             (yyval.lnk) = (yyvsp[(1) - (2)].lnk);
             (yyval.lnk)->next = (yyvsp[(2) - (2)].lnk);
             DCL_TYPE((yyvsp[(2) - (2)].lnk))=port->unqualified_pointer;
         }
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 1337 "SDCC.y"
    {
             (yyval.lnk) = (yyvsp[(1) - (3)].lnk);
             if (IS_SPEC((yyvsp[(2) - (3)].lnk)) && DCL_TYPE((yyvsp[(3) - (3)].lnk)) == UPOINTER) {
                 DCL_PTR_CONST((yyvsp[(1) - (3)].lnk)) = SPEC_CONST((yyvsp[(2) - (3)].lnk));
                 DCL_PTR_VOLATILE((yyvsp[(1) - (3)].lnk)) = SPEC_VOLATILE((yyvsp[(2) - (3)].lnk));
                 DCL_PTR_RESTRICT((yyvsp[(1) - (3)].lnk)) = SPEC_RESTRICT((yyvsp[(2) - (3)].lnk));
                 DCL_PTR_ADDRSPACE((yyvsp[(1) - (3)].lnk)) = SPEC_ADDRSPACE((yyvsp[(2) - (3)].lnk));
                 switch (SPEC_SCLS((yyvsp[(2) - (3)].lnk))) {
                 case S_XDATA:
                     DCL_TYPE((yyvsp[(3) - (3)].lnk)) = FPOINTER;
                     break;
                 case S_IDATA:
                     DCL_TYPE((yyvsp[(3) - (3)].lnk)) = IPOINTER;
                     break;
                 case S_PDATA:
                     DCL_TYPE((yyvsp[(3) - (3)].lnk)) = PPOINTER;
                     break;
                 case S_DATA:
                     DCL_TYPE((yyvsp[(3) - (3)].lnk)) = POINTER;
                     break;
                 case S_CODE:
                     DCL_TYPE((yyvsp[(3) - (3)].lnk)) = CPOINTER;
                     break;
                 case S_EEPROM:
                     DCL_TYPE((yyvsp[(3) - (3)].lnk)) = EEPPOINTER;
                     break;
                 default:
                   // this could be just "constant"
                   // werror(W_PTR_TYPE_INVALID);
                     ;
                 }
             }
             else
                 werror (W_PTR_TYPE_INVALID);
             (yyval.lnk)->next = (yyvsp[(3) - (3)].lnk);
         }
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 1377 "SDCC.y"
    {
        (yyval.lnk) = newLink(DECLARATOR);
        DCL_TYPE((yyval.lnk))=UPOINTER;
      }
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 1383 "SDCC.y"
    { (yyval.lnk) = finalizeSpec((yyvsp[(1) - (1)].lnk)); }
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 1388 "SDCC.y"
    {
     /* if the decl $2 is not a specifier */
     /* find the spec and replace it      */
     (yyval.lnk) = mergeDeclSpec((yyvsp[(1) - (2)].lnk), (yyvsp[(2) - (2)].lnk), "type_specifier_list type_specifier skipped");
   }
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 1398 "SDCC.y"
    {
           (yyvsp[(3) - (3)].sym)->next = (yyvsp[(1) - (3)].sym);
           (yyval.sym) = (yyvsp[(3) - (3)].sym);
         }
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 1406 "SDCC.y"
    { (yyvsp[(1) - (3)].val)->vArgs = 1;}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 1412 "SDCC.y"
    {
            (yyvsp[(3) - (3)].val)->next = (yyvsp[(1) - (3)].val);
            (yyval.val) = (yyvsp[(3) - (3)].val);
         }
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 1420 "SDCC.y"
    {
          symbol *loop;

          if (IS_SPEC ((yyvsp[(1) - (2)].lnk)) && !IS_VALID_PARAMETER_STORAGE_CLASS_SPEC ((yyvsp[(1) - (2)].lnk)))
            {
              werror (E_STORAGE_CLASS_FOR_PARAMETER, (yyvsp[(2) - (2)].sym)->name);
            }
          pointerTypes ((yyvsp[(2) - (2)].sym)->type, (yyvsp[(1) - (2)].lnk));
          addDecl ((yyvsp[(2) - (2)].sym), 0, (yyvsp[(1) - (2)].lnk));
          for (loop = (yyvsp[(2) - (2)].sym); loop; loop->_isparm = 1, loop = loop->next)
            ;
          addSymChain (&(yyvsp[(2) - (2)].sym));
          (yyval.val) = symbolVal ((yyvsp[(2) - (2)].sym));
          ignoreTypedefType = 0;
        }
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 1436 "SDCC.y"
    {
          (yyval.val) = newValue ();
          (yyval.val)->type = (yyvsp[(1) - (1)].lnk);
          (yyval.val)->etype = getSpec ((yyval.val)->type);
          ignoreTypedefType = 0;
         }
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 1446 "SDCC.y"
    {
          if (IS_SPEC ((yyvsp[(1) - (1)].lnk)) && !IS_VALID_PARAMETER_STORAGE_CLASS_SPEC ((yyvsp[(1) - (1)].lnk)))
            {
              werror (E_STORAGE_CLASS_FOR_PARAMETER, "type name");
            }
          (yyval.lnk) = (yyvsp[(1) - (1)].lnk); ignoreTypedefType = 0;
        }
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 1454 "SDCC.y"
    {
          /* go to the end of the list */
          sym_link *p;

          if (IS_SPEC ((yyvsp[(1) - (2)].lnk)) && !IS_VALID_PARAMETER_STORAGE_CLASS_SPEC ((yyvsp[(1) - (2)].lnk)))
            {
              werror (E_STORAGE_CLASS_FOR_PARAMETER, "type name");
            }
          pointerTypes ((yyvsp[(2) - (2)].lnk),(yyvsp[(1) - (2)].lnk));
          for (p = (yyvsp[(2) - (2)].lnk); p && p->next; p = p->next)
            ;
          if (!p)
            {
              werror(E_SYNTAX_ERROR, yytext);
            }
          else
            {
              p->next = (yyvsp[(1) - (2)].lnk);
            }
          (yyval.lnk) = (yyvsp[(2) - (2)].lnk);
          ignoreTypedefType = 0;
        }
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 1479 "SDCC.y"
    { (yyval.lnk) = reverseLink((yyvsp[(1) - (1)].lnk)); }
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 1481 "SDCC.y"
    { (yyvsp[(1) - (2)].lnk) = reverseLink((yyvsp[(1) - (2)].lnk)); (yyvsp[(1) - (2)].lnk)->next = (yyvsp[(2) - (2)].lnk); (yyval.lnk) = (yyvsp[(1) - (2)].lnk);
          if (IS_PTR((yyvsp[(1) - (2)].lnk)) && IS_FUNC((yyvsp[(2) - (2)].lnk)))
            DCL_TYPE((yyvsp[(1) - (2)].lnk)) = CPOINTER;
        }
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 1488 "SDCC.y"
    { (yyval.lnk) = (yyvsp[(2) - (3)].lnk); }
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 1489 "SDCC.y"
    {
                                       (yyval.lnk) = newLink (DECLARATOR);
                                       DCL_TYPE((yyval.lnk)) = ARRAY;
                                       DCL_ELEM((yyval.lnk)) = 0;
                                    }
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 1494 "SDCC.y"
    {
                                       value *val;
                                       (yyval.lnk) = newLink (DECLARATOR);
                                       DCL_TYPE((yyval.lnk)) = ARRAY;
                                       DCL_ELEM((yyval.lnk)) = (int) ulFromVal(val = constExprValue((yyvsp[(2) - (3)].asts),TRUE));
                                    }
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 1500 "SDCC.y"
    {
                                       (yyval.lnk) = newLink (DECLARATOR);
                                       DCL_TYPE((yyval.lnk)) = ARRAY;
                                       DCL_ELEM((yyval.lnk)) = 0;
                                       (yyval.lnk)->next = (yyvsp[(1) - (3)].lnk);
                                    }
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 1507 "SDCC.y"
    {
                                       value *val;
                                       (yyval.lnk) = newLink (DECLARATOR);
                                       DCL_TYPE((yyval.lnk)) = ARRAY;
                                       DCL_ELEM((yyval.lnk)) = (int) ulFromVal(val = constExprValue((yyvsp[(3) - (4)].asts),TRUE));
                                       (yyval.lnk)->next = (yyvsp[(1) - (4)].lnk);
                                    }
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 1514 "SDCC.y"
    { (yyval.lnk) = NULL;}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 1515 "SDCC.y"
    { (yyval.lnk) = NULL;}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 1516 "SDCC.y"
    {
     // $1 must be a pointer to a function
     sym_link *p=newLink(DECLARATOR);
     DCL_TYPE(p) = FUNCTION;
     if (!(yyvsp[(1) - (3)].lnk)) {
       // ((void (code *) ()) 0) ()
       (yyvsp[(1) - (3)].lnk)=newLink(DECLARATOR);
       DCL_TYPE((yyvsp[(1) - (3)].lnk))=CPOINTER;
       (yyval.lnk) = (yyvsp[(1) - (3)].lnk);
     }
     (yyvsp[(1) - (3)].lnk)->next=p;
   }
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 1529 "SDCC.y"
    {
          NestLevel++;
          STACK_PUSH(blockNum, currBlockno);
          currBlockno = ++blockNo;
        }
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 1535 "SDCC.y"
    {
          sym_link *p = newLink(DECLARATOR);
          DCL_TYPE(p) = FUNCTION;

          FUNC_HASVARARGS(p) = IS_VARG((yyvsp[(4) - (5)].val));
          FUNC_ARGS(p) = reverseVal((yyvsp[(4) - (5)].val));

          /* nest level was incremented to take care of the parms  */
          NestLevel--;
          currBlockno = STACK_POP(blockNum);
          if (!(yyvsp[(1) - (5)].lnk))
            {
              /* ((void (code *) (void)) 0) () */
              (yyvsp[(1) - (5)].lnk) = newLink(DECLARATOR);
              DCL_TYPE((yyvsp[(1) - (5)].lnk)) = CPOINTER;
              (yyval.lnk) = (yyvsp[(1) - (5)].lnk);
            }
          (yyvsp[(1) - (5)].lnk)->next = p;

          // disabled to fix bug 3190029
//        // remove the symbol args (if any)
//        cleanUpLevel(SymbolTab, NestLevel + 1);
   }
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 1561 "SDCC.y"
    { (yyval.ilist) = newiList(INIT_NODE,(yyvsp[(1) - (1)].asts)); }
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 1562 "SDCC.y"
    { (yyval.ilist) = newiList(INIT_DEEP,revinit((yyvsp[(2) - (3)].ilist))); }
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 1563 "SDCC.y"
    { (yyval.ilist) = newiList(INIT_DEEP,revinit((yyvsp[(2) - (4)].ilist))); }
    break;

  case 251:

/* Line 1464 of yacc.c  */
#line 1567 "SDCC.y"
    { (yyvsp[(2) - (2)].ilist)->designation = (yyvsp[(1) - (2)].dsgn); (yyval.ilist) = (yyvsp[(2) - (2)].ilist); }
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 1569 "SDCC.y"
    {
                                       (yyvsp[(4) - (4)].ilist)->designation = (yyvsp[(3) - (4)].dsgn);
                                       (yyvsp[(4) - (4)].ilist)->next = (yyvsp[(1) - (4)].ilist);
                                       (yyval.ilist) = (yyvsp[(4) - (4)].ilist);
                                    }
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 1588 "SDCC.y"
    {
                   inCritical++;
                   STACK_PUSH(continueStack,NULL);
                   STACK_PUSH(breakStack,NULL);
                   (yyval.sym) = NULL;
                }
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 1597 "SDCC.y"
    {
                   STACK_POP(breakStack);
                   STACK_POP(continueStack);
                   inCritical--;
                   (yyval.asts) = newNode(CRITICAL,(yyvsp[(2) - (2)].asts),NULL);
                }
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 1607 "SDCC.y"
    {  (yyval.asts) = createLabel((yyvsp[(1) - (2)].sym),NULL);
                                          (yyvsp[(1) - (2)].sym)->isitmp = 0;  }
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 1610 "SDCC.y"
    {
       if (STACK_EMPTY(swStk))
         (yyval.asts) = createCase(NULL,(yyvsp[(2) - (3)].asts),NULL);
       else
         (yyval.asts) = createCase(STACK_PEEK(swStk),(yyvsp[(2) - (3)].asts),NULL);
     }
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 1616 "SDCC.y"
    { (yyval.asts) = newNode(DEFAULT,NULL,NULL); }
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 1617 "SDCC.y"
    {
       if (STACK_EMPTY(swStk))
         (yyval.asts) = createDefault(NULL,(yyvsp[(2) - (3)].asts),NULL);
       else
         (yyval.asts) = createDefault(STACK_PEEK(swStk),(yyvsp[(2) - (3)].asts),NULL);
     }
    break;

  case 267:

/* Line 1464 of yacc.c  */
#line 1627 "SDCC.y"
    {
          NestLevel++;
          STACK_PUSH(blockNum, currBlockno);
          currBlockno = ++blockNo;
          ignoreTypedefType = 0;
        }
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 1637 "SDCC.y"
    {
          NestLevel--;
          currBlockno = STACK_POP(blockNum);
        }
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 1644 "SDCC.y"
    { (yyval.asts) = createBlock(NULL, NULL); }
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 1645 "SDCC.y"
    { (yyval.asts) = createBlock(NULL, (yyvsp[(2) - (3)].asts)); }
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 1647 "SDCC.y"
    {
       (yyval.asts) = createBlock((yyvsp[(2) - (3)].sym), NULL); 
       cleanUpLevel(StructTab, NestLevel + 1);
     }
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 1654 "SDCC.y"
    {
       (yyval.asts) = createBlock((yyvsp[(2) - (4)].sym), (yyvsp[(3) - (4)].asts)); 
       cleanUpLevel(StructTab, NestLevel + 1);
     }
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 1658 "SDCC.y"
    { (yyval.asts) = NULL; }
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 1663 "SDCC.y"
    {
       /* if this is typedef declare it immediately */
       if ( (yyvsp[(1) - (1)].sym) && IS_TYPEDEF((yyvsp[(1) - (1)].sym)->etype)) {
         allocVariables ((yyvsp[(1) - (1)].sym));
         (yyval.sym) = NULL;
       }
       else
         (yyval.sym) = (yyvsp[(1) - (1)].sym);
       ignoreTypedefType = 0;
       addSymChain(&(yyvsp[(1) - (1)].sym));
     }
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 1676 "SDCC.y"
    {
       symbol   *sym;

       /* if this is a typedef */
       if ((yyvsp[(2) - (2)].sym) && IS_TYPEDEF((yyvsp[(2) - (2)].sym)->etype)) {
         allocVariables ((yyvsp[(2) - (2)].sym));
         (yyval.sym) = (yyvsp[(1) - (2)].sym);
       }
       else {
         /* get to the end of the previous decl */
         if ( (yyvsp[(1) - (2)].sym) ) {
           (yyval.sym) = sym = (yyvsp[(1) - (2)].sym);
           while (sym->next)
             sym = sym->next;
           sym->next = (yyvsp[(2) - (2)].sym);
         }
         else
           (yyval.sym) = (yyvsp[(2) - (2)].sym);
       }
       ignoreTypedefType = 0;
       addSymChain(&(yyvsp[(2) - (2)].sym));
     }
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 1702 "SDCC.y"
    {  (yyval.asts) = newNode(NULLOP,(yyvsp[(1) - (2)].asts),(yyvsp[(2) - (2)].asts));}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 1706 "SDCC.y"
    { (yyval.asts) = NULL;}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 1707 "SDCC.y"
    { (yyval.asts) = (yyvsp[(1) - (2)].asts); seqPointNo++;}
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 1711 "SDCC.y"
    { (yyval.asts) = (yyvsp[(2) - (2)].asts); }
    break;

  case 281:

/* Line 1464 of yacc.c  */
#line 1712 "SDCC.y"
    { (yyval.asts) = NULL; }
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 1717 "SDCC.y"
    { seqPointNo++;}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 1718 "SDCC.y"
    {
                              noLineno++;
                              (yyval.asts) = createIf ((yyvsp[(3) - (7)].asts), (yyvsp[(6) - (7)].asts), (yyvsp[(7) - (7)].asts) );
                              (yyval.asts)->lineno = (yyvsp[(3) - (7)].asts)->lineno;
                              (yyval.asts)->filename = (yyvsp[(3) - (7)].asts)->filename;
                              noLineno--;
                           }
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 1725 "SDCC.y"
    {
                              ast *ex;
                              static   int swLabel = 0;

                              seqPointNo++;
                              /* create a node for expression  */
                              ex = newNode(SWITCH,(yyvsp[(3) - (4)].asts),NULL);
                              STACK_PUSH(swStk,ex);   /* save it in the stack */
                              ex->values.switchVals.swNum = swLabel;

                              /* now create the label */
                              SNPRINTF(lbuff, sizeof(lbuff),
                                       "_swBrk_%d",swLabel++);
                              (yyval.sym)  =  newSymbol(lbuff,NestLevel);
                              /* put label in the break stack  */
                              STACK_PUSH(breakStack,(yyval.sym));
                           }
    break;

  case 285:

/* Line 1464 of yacc.c  */
#line 1742 "SDCC.y"
    {
                              /* get back the switch form the stack  */
                              (yyval.asts) = STACK_POP(swStk);
                              (yyval.asts)->right = newNode (NULLOP,(yyvsp[(6) - (6)].asts),createLabel((yyvsp[(5) - (6)].sym),NULL));
                              STACK_POP(breakStack);
                           }
    break;

  case 286:

/* Line 1464 of yacc.c  */
#line 1750 "SDCC.y"
    {  /* create and push the continue , break & body labels */
                  static int Lblnum = 0;
                  /* continue */
                  SNPRINTF (lbuff, sizeof(lbuff), "_whilecontinue_%d",Lblnum);
                  STACK_PUSH(continueStack,newSymbol(lbuff,NestLevel));
                  /* break */
                  SNPRINTF (lbuff, sizeof(lbuff), "_whilebreak_%d",Lblnum);
                  STACK_PUSH(breakStack,newSymbol(lbuff,NestLevel));
                  /* body */
                  SNPRINTF (lbuff, sizeof(lbuff), "_whilebody_%d",Lblnum++);
                  (yyval.sym) = newSymbol(lbuff,NestLevel);
               }
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 1764 "SDCC.y"
    {  /* create and push the continue , break & body Labels */
           static int Lblnum = 0;

           /* continue */
           SNPRINTF(lbuff, sizeof(lbuff), "_docontinue_%d",Lblnum);
           STACK_PUSH(continueStack,newSymbol(lbuff,NestLevel));
           /* break */
           SNPRINTF(lbuff, sizeof(lbuff), "_dobreak_%d",Lblnum);
           STACK_PUSH(breakStack,newSymbol(lbuff,NestLevel));
           /* do body */
           SNPRINTF(lbuff, sizeof(lbuff), "_dobody_%d",Lblnum++);
           (yyval.sym) = newSymbol (lbuff,NestLevel);
        }
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 1779 "SDCC.y"
    { /* create & push continue, break & body labels */
            static int Lblnum = 0;

            /* continue */
            SNPRINTF(lbuff, sizeof(lbuff), "_forcontinue_%d",Lblnum);
            STACK_PUSH(continueStack,newSymbol(lbuff,NestLevel));
            /* break    */
            SNPRINTF(lbuff, sizeof(lbuff), "_forbreak_%d",Lblnum);
            STACK_PUSH(breakStack,newSymbol(lbuff,NestLevel));
            /* body */
            SNPRINTF(lbuff, sizeof(lbuff), "_forbody_%d",Lblnum);
            (yyval.sym) = newSymbol(lbuff,NestLevel);
            /* condition */
            SNPRINTF(lbuff, sizeof(lbuff), "_forcond_%d",Lblnum++);
            STACK_PUSH(forStack,newSymbol(lbuff,NestLevel));
          }
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 1798 "SDCC.y"
    { seqPointNo++;}
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 1799 "SDCC.y"
    {
                           noLineno++;
                           (yyval.asts) = createWhile ( (yyvsp[(1) - (6)].sym), STACK_POP(continueStack),
                                              STACK_POP(breakStack), (yyvsp[(3) - (6)].asts), (yyvsp[(6) - (6)].asts) );
                           (yyval.asts)->lineno = (yyvsp[(1) - (6)].sym)->lineDef;
                           (yyval.asts)->filename = (yyvsp[(1) - (6)].sym)->fileDef;
                           noLineno--;
                         }
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 1808 "SDCC.y"
    {
                          seqPointNo++;
                          noLineno++;
                          (yyval.asts) = createDo ( (yyvsp[(1) - (7)].sym) , STACK_POP(continueStack),
                                          STACK_POP(breakStack), (yyvsp[(5) - (7)].asts), (yyvsp[(2) - (7)].asts));
                          (yyval.asts)->lineno = (yyvsp[(1) - (7)].sym)->lineDef;
                          (yyval.asts)->filename = (yyvsp[(1) - (7)].sym)->fileDef;
                          noLineno--;
                        }
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 1818 "SDCC.y"
    {
                          noLineno++;

                          /* if break or continue statement present
                             then create a general case loop */
                          if (STACK_PEEK(continueStack)->isref ||
                              STACK_PEEK(breakStack)->isref) {
                              (yyval.asts) = createFor ((yyvsp[(1) - (9)].sym), STACK_POP(continueStack),
                                              STACK_POP(breakStack) ,
                                              STACK_POP(forStack)   ,
                                              (yyvsp[(3) - (9)].asts) , (yyvsp[(5) - (9)].asts) , (yyvsp[(7) - (9)].asts), (yyvsp[(9) - (9)].asts) );
                          } else {
                              (yyval.asts) = newNode(FOR,(yyvsp[(9) - (9)].asts),NULL);
                              AST_FOR((yyval.asts),trueLabel) = (yyvsp[(1) - (9)].sym);
                              AST_FOR((yyval.asts),continueLabel) =  STACK_POP(continueStack);
                              AST_FOR((yyval.asts),falseLabel) = STACK_POP(breakStack);
                              AST_FOR((yyval.asts),condLabel)  = STACK_POP(forStack);
                              AST_FOR((yyval.asts),initExpr)   = (yyvsp[(3) - (9)].asts);
                              AST_FOR((yyval.asts),condExpr)   = (yyvsp[(5) - (9)].asts);
                              AST_FOR((yyval.asts),loopExpr)   = (yyvsp[(7) - (9)].asts);
                          }

                          noLineno--;
                        }
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 1845 "SDCC.y"
    { (yyval.asts) = NULL; seqPointNo++; }
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 1846 "SDCC.y"
    { (yyval.asts) = (yyvsp[(1) - (1)].asts); seqPointNo++; }
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 1850 "SDCC.y"
    {
                              (yyvsp[(2) - (3)].sym)->islbl = 1;
                              (yyval.asts) = newAst_VALUE(symbolVal((yyvsp[(2) - (3)].sym)));
                              (yyval.asts) = newNode(GOTO,(yyval.asts),NULL);
                           }
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 1855 "SDCC.y"
    {
       /* make sure continue is in context */
       if (STACK_EMPTY(continueStack) || STACK_PEEK(continueStack) == NULL) {
           werror(E_BREAK_CONTEXT);
           (yyval.asts) = NULL;
       }
       else {
           (yyval.asts) = newAst_VALUE(symbolVal(STACK_PEEK(continueStack)));
           (yyval.asts) = newNode(GOTO,(yyval.asts),NULL);
           /* mark the continue label as referenced */
           STACK_PEEK(continueStack)->isref = 1;
       }
   }
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 1868 "SDCC.y"
    {
       if (STACK_EMPTY(breakStack) || STACK_PEEK(breakStack) == NULL) {
           werror(E_BREAK_CONTEXT);
           (yyval.asts) = NULL;
       } else {
           (yyval.asts) = newAst_VALUE(symbolVal(STACK_PEEK(breakStack)));
           (yyval.asts) = newNode(GOTO,(yyval.asts),NULL);
           STACK_PEEK(breakStack)->isref = 1;
       }
   }
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 1878 "SDCC.y"
    {
       seqPointNo++;
       if (inCritical) {
           werror(E_INVALID_CRITICAL);
           (yyval.asts) = NULL;
       } else {
           (yyval.asts) = newNode(RETURN,NULL,NULL);
       }
   }
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 1887 "SDCC.y"
    {
       seqPointNo++;
       if (inCritical) {
           werror(E_INVALID_CRITICAL);
           (yyval.asts) = NULL;
       } else {
           (yyval.asts) = newNode(RETURN,NULL,(yyvsp[(2) - (3)].asts));
       }
   }
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 1904 "SDCC.y"
    {
        ast *ex;

        seqPointNo++;
        ex = newNode(INLINEASM, NULL, NULL);
        ex->values.inlineasm = copyStr ((yyvsp[(3) - (5)].yystr), NULL);
        seqPointNo++;
        (yyval.asts) = ex;
     }
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 1914 "SDCC.y"
    {
        ast *ex;

        seqPointNo++;
        ex = newNode(INLINEASM, NULL, NULL);
        ex->values.inlineasm = strdup((yyvsp[(1) - (2)].yystr));
        seqPointNo++;
        (yyval.asts) = ex;
      }
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 1926 "SDCC.y"
    {
     symbol *sym;
     if ((sym = findSymWithLevel (AddrspaceTab, (yyvsp[(3) - (4)].sym))) && sym->level == (yyvsp[(3) - (4)].sym)->level)
       werrorfl (sym->fileDef, sym->lineDef, E_PREVIOUS_DEF);
     if (!findSymWithLevel (SymbolTab, (yyvsp[(2) - (4)].sym)))
       werror (E_ID_UNDEF, (yyvsp[(2) - (4)].sym)->name);
     addSym (AddrspaceTab, (yyvsp[(3) - (4)].sym), (yyvsp[(3) - (4)].sym)->name, (yyvsp[(3) - (4)].sym)->level, (yyvsp[(3) - (4)].sym)->block, 0);
     sym = findSymWithLevel (AddrspaceTab, (yyvsp[(3) - (4)].sym));
     sym->addressmod[0] = findSymWithLevel (SymbolTab, (yyvsp[(2) - (4)].sym));
     sym->addressmod[1] = 0;
   }
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 1940 "SDCC.y"
    { (yyval.sym) = newSymbol ((yyvsp[(1) - (1)].yychar), NestLevel); }
    break;



/* Line 1464 of yacc.c  */
#line 5216 "SDCCy.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
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
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 1942 "SDCC.y"


