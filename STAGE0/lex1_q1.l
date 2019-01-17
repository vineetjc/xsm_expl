/*Declarations section starts here*/

/*Indicate absence of yywrap*/
%option noyywrap

/*Declarations section 1: Auxiliary Declarations start here*/
%{
	#include <stdlib.h>
	#include <stdio.h>

	int num=0, words=0, lines=0;
%}


/*Auxiliary declarations end & Declarations section 2: Regular definitions start here*/

/*Declarations section ends here and Rules below*/

%%

["\n"] {lines++; words++;}
["\t"|" "]+ {words++;}
. {num++;}

%%

//Auxiliary Functions here


int main()
{
	yyin = fopen("input_file1.l","r");
	yylex();
	printf("Number of words: %d\n", words);
	printf("Number of characters: %d\n", num);
	printf("Number of lines: %d\n", lines);
	return 1;
}
