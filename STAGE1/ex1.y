%{
	#include <stdio.h>
	#include <stdlib.h>

	#include "ex1.h"
	#include "ex1.c"

	#define YYSTYPE tnode *

	int yylex(void);
	int yyerror(const char *s);
%}

%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

	program : expr END {
							printf("Prefix Expression : ");
							printPrefix($1);
							printf("\n");
							printf("Postfix Expression : ");
							printPostfix($1);
							printf("\n");
							exit(1);
						}
	;

	expr : expr PLUS expr {$$ = makeOperatorNode('+',$1,$3);}
		| expr MINUS expr {$$ = makeOperatorNode('-',$1,$3);}
		| expr MUL expr {$$ = makeOperatorNode('*',$1,$3);}
		| expr DIV expr {$$ = makeOperatorNode('/',$1,$3);}
		| '(' expr ')' {$$ = $2;}
		| NUM {$$ = $1;}
	;

%%

	int main()
	{
		yyparse();
		return 0;
	}
