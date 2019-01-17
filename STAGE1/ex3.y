%{
	#include <stdio.h>
	#include <stdlib.h>
	
	#define YYSTYPE tnode *
	
	#include "ex3.h"
	#include "ex3.c"
	
	int yylex(void);	
%}
	
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV
	
%%
	
	program : expr END {
							$$ = $2;
							FILE *fptr = fopen("../code.xsm", "w");
							fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
							int temp = codeGen($1, fptr);
							fprintf(fptr, "MOV [4096], R%d\n", temp);
							fprintf(fptr, "MOV R0, [4096]\n");
							fprintf(fptr, "MOV SP, 4096\n");
							fprintf(fptr, "MOV R2, \"Write\"\n");
							fprintf(fptr, "PUSH R2\n");
							fprintf(fptr, "MOV R2, -2\n");
							fprintf(fptr, "PUSH R2\n");
							fprintf(fptr, "PUSH R0\n");
							fprintf(fptr, "PUSH R2\n");
							fprintf(fptr, "PUSH R2\n");
							fprintf(fptr, "CALL 0\n");
							fprintf(fptr, "POP R0\n");
							fprintf(fptr, "POP R1\n");
							fprintf(fptr, "POP R1\n");
							fprintf(fptr, "POP R1\n");
							fprintf(fptr, "POP R1\n");
							fprintf(fptr, "MOV R2, \"Exit\"\n");
							fprintf(fptr, "PUSH R2\n");
							fprintf(fptr, "PUSH R2\n");
							fprintf(fptr, "PUSH R0\n");
							fprintf(fptr, "PUSH R2\n");
							fprintf(fptr, "PUSH R2\n");
							fprintf(fptr, "CALL 0\n");
							fprintf(fptr, "POP R0\n");
							fprintf(fptr, "POP R1\n");
							fprintf(fptr, "POP R1\n");
							fprintf(fptr, "POP R1\n");
							fprintf(fptr, "POP R1\n");
							fclose(fptr);
							exit(1);
						}
	;
	
	expr : PLUS expr expr {$$ = makeOperatorNode('+',$2,$3);}
		| MINUS expr expr {$$ = makeOperatorNode('-',$2,$3);}
		| MUL expr expr {$$ = makeOperatorNode('*',$2,$3);}
		| DIV expr expr {$$ = makeOperatorNode('/',$2,$3);}
		| '(' expr ')' {$$ = $2;}
		| NUM {$$ = $1;}
	;
	
%%
	
	yyerror(char const *s)
	{
		printf("yyerror %s",s);
	}
	
	
	int main(void) 
	{
		yyparse();
		return 0;
	}
