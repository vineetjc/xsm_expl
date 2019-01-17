/*Declarations section starts here*/

/*Indicate absence of yywrap*/
%option noyywrap

/*Declarations section 1: Auxiliary Declarations start here*/
%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>

	int comments=0;
%}


/*Auxiliary declarations end & Declarations section 2: Regular definitions start here*/

chars [a-z|A-Z|0-9|"\t"|" "|"#"|"$"]+
Lchars {chars}|[/]|[*]|[/]
BCchars {Lchars}|[\n]
linecomment [/][/]{Lchars}+
blockcomment [/][*]{BCchars}+[*][/]
comment {blockcomment}|{linecomment}

/*Declarations section ends here and Rules below*/

%%

{comment} {printf("Found comment: (start) %s (end)\n", yytext); comments++;}

%%

//Auxiliary Functions here


int main()
{
	yyin = fopen("input_file4.l","r");
	yylex();
	printf("Number of comments: %d\n", comments);
	return 1;
}
