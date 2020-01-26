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
    MAIN = 276,
    TYPE = 277,
    ENDTYPE = 278,
    NUM = 279,
    PLUS = 280,
    MINUS = 281,
    MUL = 282,
    DIV = 283,
    END = 284,
    NTEQ = 285,
    CONDEQ = 286,
    INT = 287,
    STR = 288,
    RETURN = 289,
    AND = 290,
    EQ = 291,
    LT = 292,
    GT = 293,
    LE = 294,
    GE = 295,
    MOD = 296
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
#define MAIN 276
#define TYPE 277
#define ENDTYPE 278
#define NUM 279
#define PLUS 280
#define MINUS 281
#define MUL 282
#define DIV 283
#define END 284
#define NTEQ 285
#define CONDEQ 286
#define INT 287
#define STR 288
#define RETURN 289
#define AND 290
#define EQ 291
#define LT 292
#define GT 293
#define LE 294
#define GE 295
#define MOD 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "t2.y" /* yacc.c:1909  */

	struct tnode* treeNode;
	struct Gsymbol* GTableNode;
	struct Lsymbol* LTableNode;
	struct Paramstruct* paramlist;
	//struct Typetable* typeNode;
	// struct Fieldlist* fieldNode;
	int number;

#line 146 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
