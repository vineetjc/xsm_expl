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
    NUM = 277,
    PLUS = 278,
    MINUS = 279,
    MUL = 280,
    DIV = 281,
    END = 282,
    NTEQ = 283,
    CONDEQ = 284,
    INT = 285,
    STR = 286,
    RETURN = 287,
    AND = 288,
    TYPE = 289,
    ENDTYPE = 290,
    NULLTYPE = 291,
    INITIALISE = 292,
    ALLOC = 293,
    FREE = 294,
    EQ = 295,
    LT = 296,
    GT = 297,
    LE = 298,
    GE = 299,
    MOD = 300
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
#define NUM 277
#define PLUS 278
#define MINUS 279
#define MUL 280
#define DIV 281
#define END 282
#define NTEQ 283
#define CONDEQ 284
#define INT 285
#define STR 286
#define RETURN 287
#define AND 288
#define TYPE 289
#define ENDTYPE 290
#define NULLTYPE 291
#define INITIALISE 292
#define ALLOC 293
#define FREE 294
#define EQ 295
#define LT 296
#define GT 297
#define LE 298
#define GE 299
#define MOD 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "t2.y" /* yacc.c:1909  */

	struct tnode* treeNode;
	struct Gsymbol* GTableNode;
	struct Lsymbol* LTableNode;
	struct Paramstruct* paramlist;
	struct Typetable* typeNode;
	struct Fieldlist* fieldNode;
	int number;

#line 154 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
