/*Declarations section starts here*/

/*Indicate absence of yywrap*/
%option noyywrap

/*Declarations section 1: Auxiliary Declarations start here*/
%{
	#include <stdlib.h>
	#include <stdio.h>

	int floats=0, integers=0;
%}


/*Auxiliary declarations end & Declarations section 2: Regular definitions start here*/

number [0-9]+
float {number}[.]{number}
string [a-zA-Z]+

/*Declarations section ends here and Rules below*/

%%

{number} {integers++;}
{float} {floats++;}

%%

//Auxiliary Functions here


int main()
{
	integers = 0, floats = 0;
	yyin = fopen("input_file2.l","r");
	yylex();
	printf("Number of integers: %d\n", integers);
  printf("Number of floats: %d\n", floats);
	return 1;
}
