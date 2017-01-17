/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TEXSCI_BEGIN = 258,
    TEXSCI_END = 259,
    BLANKLINE = 260,
    MBOX = 261,
    IF = 262,
    PRINTTEXT = 263,
    PRINTINT = 264,
    LEFTARROW = 265,
    LOCAL = 266,
    MINUX = 267,
    PLUS = 268,
    MINUS = 269,
    MULT = 270,
    ASSIGN = 271,
    CARACFIN = 272,
    DIV = 273,
    IN = 274,
    GLOBAL = 275,
    INPUT = 276,
    OUTPUT = 277,
    EMPTY = 278,
    TYPEREAL = 279,
    OPAR = 280,
    CPAR = 281,
    TYPEINT = 282,
    EGAL = 283,
    PRINTREAL = 284,
    ID = 285,
    PHRASE = 286,
    UMINUS = 287,
    REAL = 288,
    INTEGER = 289
  };
#endif
/* Tokens.  */
#define TEXSCI_BEGIN 258
#define TEXSCI_END 259
#define BLANKLINE 260
#define MBOX 261
#define IF 262
#define PRINTTEXT 263
#define PRINTINT 264
#define LEFTARROW 265
#define LOCAL 266
#define MINUX 267
#define PLUS 268
#define MINUS 269
#define MULT 270
#define ASSIGN 271
#define CARACFIN 272
#define DIV 273
#define IN 274
#define GLOBAL 275
#define INPUT 276
#define OUTPUT 277
#define EMPTY 278
#define TYPEREAL 279
#define OPAR 280
#define CPAR 281
#define TYPEINT 282
#define EGAL 283
#define PRINTREAL 284
#define ID 285
#define PHRASE 286
#define UMINUS 287
#define REAL 288
#define INTEGER 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "texcc.y" /* yacc.c:1909  */

    long int value;
    char *name;
    float valuefloat;
    struct {
        struct symbol * ptr;
    } exprval;

#line 131 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
