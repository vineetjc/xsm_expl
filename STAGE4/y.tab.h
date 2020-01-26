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
    READ = 259,
    WRITE = 260,
    DO = 261,
    WHILE = 262,
    IF = 263,
    THEN = 264,
    ELSE = 265,
    ENDIF = 266,
    ENDWHILE = 267,
    ID = 268,
    DECL = 269,
    ENDDECL = 270,
    BREAK = 271,
    CONTINUE = 272,
    REPEAT = 273,
    UNTIL = 274,
    STRING = 275,
    NUM = 276,
    PLUS = 277,
    MINUS = 278,
    MUL = 279,
    DIV = 280,
    END = 281,
    NTEQ = 282,
    CONDEQ = 283,
    INT = 284,
    STR = 285,
    EQ = 286,
    LT = 287,
    GT = 288,
    LE = 289,
    GE = 290,
    MOD = 291
  };
#endif
/* Tokens.  */
#define BEG 258
#define READ 259
#define WRITE 260
#define DO 261
#define WHILE 262
#define IF 263
#define THEN 264
#define ELSE 265
#define ENDIF 266
#define ENDWHILE 267
#define ID 268
#define DECL 269
#define ENDDECL 270
#define BREAK 271
#define CONTINUE 272
#define REPEAT 273
#define UNTIL 274
#define STRING 275
#define NUM 276
#define PLUS 277
#define MINUS 278
#define MUL 279
#define DIV 280
#define END 281
#define NTEQ 282
#define CONDEQ 283
#define INT 284
#define STR 285
#define EQ 286
#define LT 287
#define GT 288
#define LE 289
#define GE 290
#define MOD 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "t2.y" /* yacc.c:1909  */

	struct tnode* treeNode;
	struct Gsymbol* tableNode;
	int number;

#line 132 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
