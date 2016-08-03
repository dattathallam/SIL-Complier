/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
    NUM = 258,
    ID = 259,
    PLUS = 260,
    MUL = 261,
    ASGN = 262,
    READ = 263,
    WRITE = 264,
    MINUS = 265,
    NEWLINE = 266,
    LT = 267,
    GT = 268,
    DEQ = 269,
    ELSE = 270,
    IF = 271,
    THEN = 272,
    ENDIF = 273,
    ENDWHILE = 274,
    WHILE = 275,
    DO = 276,
    START = 277,
    END = 278,
    DECL = 279,
    ENDDECL = 280,
    T = 281,
    INT = 282,
    F = 283,
    BOOL = 284,
    LE = 285,
    GE = 286
  };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define PLUS 260
#define MUL 261
#define ASGN 262
#define READ 263
#define WRITE 264
#define MINUS 265
#define NEWLINE 266
#define LT 267
#define GT 268
#define DEQ 269
#define ELSE 270
#define IF 271
#define THEN 272
#define ENDIF 273
#define ENDWHILE 274
#define WHILE 275
#define DO 276
#define START 277
#define END 278
#define DECL 279
#define ENDDECL 280
#define T 281
#define INT 282
#define F 283
#define BOOL 284
#define LE 285
#define GE 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 22 "abstree.y" /* yacc.c:1909  */

    struct Tnode * nptr;

#line 120 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
