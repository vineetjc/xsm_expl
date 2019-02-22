%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "t1.h"
	#include "y.tab.h"
	int number;
%}
	
%%
	
[0-9]+ {printf("%s\n", yytext); number = atoi(yytext); yylval = createTree(number,inttype,NULL,NODE_CONSTANT,NULL,NULL,NULL); return NUM;}
"endif" {printf("%s\n", yytext);return ENDIF;}
"endwhile" {printf("%s\n", yytext);return ENDWHILE;}
"end" {printf("%s\n", yytext);return END;}
"begin" {printf("%s\n", yytext);return BEG;}
"read" {printf("%s\n", yytext);return READ;}
"write" {printf("%s\n", yytext);return WRITE;}
"if" {printf("%s\n", yytext);return IF;}
"then" {printf("%s\n", yytext);return THEN;}
"else" {printf("%s\n", yytext);return ELSE;}
"do" {printf("%s\n", yytext);return DO;}
"while" {printf("%s\n", yytext);return WHILE;}
[a-z] {printf("%s\n", yytext);yylval = createTree(0,inttype,yytext,NODE_VAR,NULL,NULL,NULL); return ID;}
">=" {printf("%s\n", yytext);return GE;}
"<=" {printf("%s\n", yytext);return LE;}
"==" {printf("%s\n", yytext);return CONDEQ;}
"!=" {printf("%s\n", yytext);return NTEQ;}
">" {printf("%s\n", yytext);return GT;}
"<" {printf("%s\n", yytext);return LT;}
"+" {printf("%s\n", yytext);return PLUS;}
"-" {printf("%s\n", yytext);return MINUS;}
"*" {printf("%s\n", yytext);return MUL;}
"/" {printf("%s\n", yytext);return DIV;}
"=" {printf("%s\n", yytext);return EQ;}
";" {printf("%s\n", yytext);return *yytext;}
[ \t] {}
[\n] {}
[()] {return *yytext;}
. {yyerror("unknown character\n"); exit(1);}
	
%%
	
int yywrap(void) 
{
	return 1;
}
