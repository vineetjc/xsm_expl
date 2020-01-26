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
    BEG = 258,
    ID = 259,
    READ = 260,
    WRITE = 261,
    DO = 262,
    WHILE = 263,
    IF = 264,
    THEN = 265,
    ELSE = 266,
    ENDIF = 267,
    ENDWHILE = 268,
    NUM = 269,
    PLUS = 270,
    MINUS = 271,
    MUL = 272,
    DIV = 273,
    END = 274,
    NTEQ = 275,
    CONDEQ = 276,
    BREAK = 277,
    CONTINUE = 278,
    REPEAT = 279,
    UNTIL = 280,
    EQ = 281,
    LT = 282,
    GT = 283,
    LE = 284,
    GE = 285
  };
#endif
/* Tokens.  */
#define BEG 258
#define ID 259
#define READ 260
#define WRITE 261
#define DO 262
#define WHILE 263
#define IF 264
#define THEN 265
#define ELSE 266
#define ENDIF 267
#define ENDWHILE 268
#define NUM 269
#define PLUS 270
#define MINUS 271
#define MUL 272
#define DIV 273
#define END 274
#define NTEQ 275
#define CONDEQ 276
#define BREAK 277
#define CONTINUE 278
#define REPEAT 279
#define UNTIL 280
#define EQ 281
#define LT 282
#define GT 283
#define LE 284
#define GE 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
