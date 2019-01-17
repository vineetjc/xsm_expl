/*Declarations section starts here*/

/*Declarations section 1: Auxiliary Declarations start here*/
%{
    #include <stdio.h>
    #include <string.h>
	  #include "y.tab.h"
%}

/*Auxiliary declarations end & Declarations section 2: Regular definitions start here*/

/*Declarations section ends here and Rules below*/

%%


[a-zA-Z]+ {
          yylval = *yytext; return DIGIT;
}
"+"	  return *yytext;
"-"	  return *yytext;
[()]	  return *yytext;
[\n]      return NEWLINE;

%%

//Auxiliary Functions here


yywrap()
{
	return 1;
}
