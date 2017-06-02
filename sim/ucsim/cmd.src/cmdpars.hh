/* A Bison parser, made by GNU Bison 1.875c.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PTOK_PLUS = 258,
     PTOK_MINUS = 259,
     PTOK_ASTERIX = 260,
     PTOK_SLASH = 261,
     PTOK_EQUAL = 262,
     PTOK_LEFT_PAREN = 263,
     PTOK_RIGHT_PAREN = 264,
     PTOK_LEFT_BRACKET = 265,
     PTOK_RIGHT_BRACKET = 266,
     PTOK_DOT = 267,
     PTOK_AMPERSAND = 268,
     PTOK_MEMORY_OBJECT = 269,
     PTOK_MEMORY = 270,
     PTOK_NUMBER = 271,
     PTOK_BIT = 272,
     UNARYMINUS = 273
   };
#endif
#define PTOK_PLUS 258
#define PTOK_MINUS 259
#define PTOK_ASTERIX 260
#define PTOK_SLASH 261
#define PTOK_EQUAL 262
#define PTOK_LEFT_PAREN 263
#define PTOK_RIGHT_PAREN 264
#define PTOK_LEFT_BRACKET 265
#define PTOK_RIGHT_BRACKET 266
#define PTOK_DOT 267
#define PTOK_AMPERSAND 268
#define PTOK_MEMORY_OBJECT 269
#define PTOK_MEMORY 270
#define PTOK_NUMBER 271
#define PTOK_BIT 272
#define UNARYMINUS 273




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 31 "cmdpars.y"
typedef union YYSTYPE {
  long number;
  class cl_memory *memory_object;
  struct {
    class cl_memory *memory;
    long address;
  } memory;
  struct {
    class cl_memory *memory;
    long mem_address, bit_address;
    long mask;
  } bit;
} YYSTYPE;
/* Line 1275 of yacc.c.  */
#line 87 "y.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



