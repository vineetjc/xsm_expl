%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#define YYSTYPE tnode*

	#include "t1.h"
	#include "t1.c"
	int yylex(void);
	int yyerror(char const *);
%}

%token BEG ID READ WRITE DO WHILE IF THEN ELSE ENDIF ENDWHILE
%token NUM PLUS MINUS MUL DIV END NTEQ CONDEQ
%right EQ
%left PLUS MINUS LT GT LE GE NTEQ CONDEQ
%left MUL DIV

%%
	Program : BEG Slist END {$$ = $2;
				codeGen($2);
				evaluate($2);
				inorder($2);
				printf("Complete.\n");
				exit(1);}
			| BEG END {$$ = NULL;}
			;

	Slist : Slist Stmt {$$ = createTree(0,0,NULL,NODE_CONN,$1,NULL,$2);}
			| Stmt {$$ = $1;}
			;

	Stmt : InputStmt {$$ = $1;}
			| OutputStmt {$$ = $1;}
			| AsgStmt {$$ = $1;}
			| IfStmt {$$ = $1;}
			| WhileStmt {$$ = $1;}
			;

	InputStmt : READ'('ID')'';' {$$ = createTree(0,0,NULL,NODE_READ,$3,NULL,NULL);}
			;

	OutputStmt : WRITE'('expr')'';' {$$ = createTree(0,0,NULL,NODE_WRITE,$3,NULL,NULL);}
			;

	AsgStmt : ID EQ expr';' {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "=");
				$$ = createTree(0,0,temp,NODE_ASSGN,$1,NULL,$3);}
			;

	IfStmt : IF'('expr')' THEN Slist ELSE Slist ENDIF';' {$$ = createTree(0,0,NULL,NODE_IF,$3,$6,$8);}
			| 	IF'('expr')' THEN Slist ENDIF';' {$$ = createTree(0,0,NULL,NODE_IF,$3,$6,NULL);}
			;

	WhileStmt : WHILE'('expr')' DO Slist ENDWHILE';' {$$ = createTree(0,0,NULL,NODE_WHILE,$3,NULL,$6);}
			;

	expr : expr PLUS expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "+");
				$$ = createTree(0,inttype,temp,NODE_EX,$1,NULL,$3);}

		| expr MINUS expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "-");
				$$ = createTree(0,inttype,temp,NODE_EX,$1,NULL,$3);}

		| expr MUL expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "*");
				$$ = createTree(0,inttype,temp,NODE_EX,$1,NULL,$3);}

		| expr DIV expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "/");
				$$ = createTree(0,inttype,temp,NODE_EX,$1,NULL,$3);}

		| expr LT expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "<");
				$$ = createTree(0,booltype,temp,NODE_EX,$1,NULL,$3);}

		| expr GT expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, ">");
				$$ = createTree(0,booltype,temp,NODE_EX,$1,NULL,$3);}

		| expr LE expr {char *temp = (char *)malloc(2*sizeof(char));
				strcpy(temp, "<=");
				$$ = createTree(0,booltype,temp,NODE_EX,$1,NULL,$3);}

		| expr GE expr {char *temp = (char *)malloc(2*sizeof(char));
				strcpy(temp, ">=");
				$$ = createTree(0,booltype,temp,NODE_EX,$1,NULL,$3);}

		| expr NTEQ expr {char *temp = (char *)malloc(2*sizeof(char));
				strcpy(temp, "!=");
				$$ = createTree(0,booltype,temp,NODE_EX,$1,NULL,$3);}

		| expr CONDEQ expr {char *temp = (char *)malloc(2*sizeof(char));
				strcpy(temp, "==");
				$$ = createTree(0,booltype,temp,NODE_EX,$1,NULL,$3);}
		| '(' expr ')' {$$ = $2;}
		| NUM {$$ = $1;}
		| ID {$$ = $1;}
		;

%%

int yyerror(char const *s)
{
    printf("yyerror %s",s);
}

int main(int argc, char *argv[])
{
	FILE *fptr;
	if(argc > 1)
	{
		fptr = fopen(argv[1], "r");
		if(fptr)
		{
			yyin = fptr;
		}
	}
	xsm_file = fopen("code.xsm", "w");
	infile = fopen("input.txt", "r");
	outfile = fopen("output.txt", "w");
	print_header();
	yyparse();
	store_answer();
	if(fptr)
		fclose(fptr);
	fclose(xsm_file);
	fclose(infile);
	fclose(outfile);
	return 0;
}
