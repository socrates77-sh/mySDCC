/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1685 of yacc.c  */
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



/* Line 1685 of yacc.c  */
#line 320 "SDCCy.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


