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
    DIV = 262,
    MOD = 263,
    ASGN = 264,
    READ = 265,
    WRITE = 266,
    MINUS = 267,
    NEWLINE = 268,
    LT = 269,
    GT = 270,
    DEQ = 271,
    NEQ = 272,
    ELSE = 273,
    IF = 274,
    THEN = 275,
    ENDIF = 276,
    ENDWHILE = 277,
    WHILE = 278,
    DO = 279,
    DARRAY = 280,
    START = 281,
    END = 282,
    DECL = 283,
    ENDDECL = 284,
    T = 285,
    INT = 286,
    F = 287,
    BOOL = 288,
    LE = 289,
    GE = 290,
    NOT = 291,
    AND = 292,
    OR = 293,
    AMP = 294,
    MAIN = 295,
    RETURN = 296,
    ALLOC = 297,
    FREE = 298,
    TYPEDEF = 299,
    TYPE1 = 300,
    ENDTYPE = 301,
    NILL = 302,
    DEQNILL = 303,
    NEQNILL = 304
  };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define PLUS 260
#define MUL 261
#define DIV 262
#define MOD 263
#define ASGN 264
#define READ 265
#define WRITE 266
#define MINUS 267
#define NEWLINE 268
#define LT 269
#define GT 270
#define DEQ 271
#define NEQ 272
#define ELSE 273
#define IF 274
#define THEN 275
#define ENDIF 276
#define ENDWHILE 277
#define WHILE 278
#define DO 279
#define DARRAY 280
#define START 281
#define END 282
#define DECL 283
#define ENDDECL 284
#define T 285
#define INT 286
#define F 287
#define BOOL 288
#define LE 289
#define GE 290
#define NOT 291
#define AND 292
#define OR 293
#define AMP 294
#define MAIN 295
#define RETURN 296
#define ALLOC 297
#define FREE 298
#define TYPEDEF 299
#define TYPE1 300
#define ENDTYPE 301
#define NILL 302
#define DEQNILL 303
#define NEQNILL 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 30 "abstree.y" /* yacc.c:1909  */

    struct Tnode * nptr;

#line 156 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
