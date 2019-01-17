/*Declarations section starts here*/

/*Indicate absence of yywrap*/
%option noyywrap

/*Declarations section 1: Auxiliary Declarations start here*/
%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>

	int words=0;
	char name[] = "vineet";
%}


/*Auxiliary declarations end & Declarations section 2: Regular definitions start here*/

Astring ['A']..[" "|"\n"|"\t"]+

/*Declarations section ends here and Rules below*/

%%

{Astring} {printf("Found string: (%c%c%c)\n", yytext[0], yytext[1], yytext[2]); words++;}

%%

//Auxiliary Functions here


int main()
{
	yyin = fopen("input_file3.l","r");
	yylex();
	printf("Number of such words: %d\n", words);
	return 1;
}
