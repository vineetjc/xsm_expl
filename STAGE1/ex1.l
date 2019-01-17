%{
	#include <stdio.h>
	#include "y.tab.h"
	#include <stdlib.h>

	int number;
	int yyerror(char const *s);
%}

%%

[0-9]+ {number = atoi(yytext);yylval = makeLeafNode(number); return NUM;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
[()] {return *yytext;}
[\n] {return END;}
. {yyerror("unknown character\n");exit(1);}

%%

int yywrap(void)
{
	return 0;
}

int yyerror(char const *s)
{
	printf("yyerror %s",s);
	return 1;
}
