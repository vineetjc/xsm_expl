%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#include "t2.h"
	#include "t2.c"
	int yylex(void);
	int yyerror(char const *);
	struct Gsymbol *root = NULL;
%}

%union
{
	struct tnode* treeNode;
	struct Gsymbol* tableNode;
	int number;
}

%token BEG READ WRITE DO WHILE IF THEN ELSE ENDIF ENDWHILE ID
%token DECL ENDDECL BREAK CONTINUE REPEAT UNTIL STRING
%token NUM PLUS MINUS MUL DIV END NTEQ CONDEQ INT STR
%type <treeNode> ID
%type <treeNode> NUM PLUS MINUS MUL DIV END NTEQ CONDEQ MOD
%type <number> INT STR
%right EQ
%left PLUS MINUS LT GT LE GE NTEQ CONDEQ
%left MUL DIV MOD

%%
	Program : Declarations BEG Slist END {$<treeNode>$ = $<treeNode>3;
				printSymbolTable(&root);
				int p = codeGen($<treeNode>3);
				//evaluate($<treeNode>3);
				inorder($<treeNode>3);
				printf("Complete.\n");
				}
			| Declarations BEG END {$<treeNode>$ = NULL;}
			;

	Declarations : DECL DeclList ENDDECL
			| DECL ENDDECL
			;

	DeclList : 	DeclList Decl
			| Decl
			;

	Decl : Type Varlist';' {assignType(&root, $<number>1);}
			;

	Type : INT {$<number>$ = $<number>1;}
			| STR {$<number>$ = $<number>1;}
			;

	Varlist : Varlist','ID {struct Gsymbol *temp = NULL;
							temp = Lookup(&root, $<treeNode>3->varname);
							if(temp == NULL)
							{

								//printf("%s\n", $<treeNode>3->varname);
								install(&root, $<treeNode>3->varname, 0, 1);

								temp = Lookup(&root, $<treeNode>3->varname);
								$<tableNode>$ = temp;
							}
							else
							{
								printf("Error. Variable declared twice.\n");
								exit(1);
							}
							}
			| ID {	struct Gsymbol *temp = NULL;
					temp = Lookup(&root, $<treeNode>1->varname);
					if(temp == NULL)
					{

						//printf("%s\n", $<treeNode>1->varname);
						install(&root, $<treeNode>1->varname, 0, 1);

						temp = Lookup(&root, $<treeNode>1->varname);
						$<tableNode>$ = temp;
					}
					else
					{
						printf("Error. Variable declared twice.\n");
						exit(1);
					}
				}
			| Varlist','ID'['NUM']' { struct Gsymbol *temp = NULL;
									temp = Lookup(&root, $<treeNode>3->varname);
									if(temp == NULL)
									{

										//printf("%s\n", $<treeNode>3->varname);
										install(&root, $<treeNode>3->varname, 0, $<treeNode>5->val);

										//temp = Lookup(&root, $<treeNode>1->varname);
										//$<tableNode>$ = temp;
									}
									else
									{
										printf("Error. Variable declared twice.\n");
										exit(1);
									}
									}
			| ID'['NUM']'	{struct Gsymbol *temp = NULL;
							temp = Lookup(&root, $<treeNode>1->varname);
							if(temp == NULL)
							{

								//printf("%s\n", $<treeNode>1->varname);
								install(&root, $<treeNode>1->varname, 0, $<treeNode>3->val);

								//temp = Lookup(&root, $<treeNode>1->varname);
								//$<tableNode>$ = temp;
							}
							else
							{
								printf("Error. Variable declared twice.\n");
								exit(1);
							}
							}
			;

	Slist : Slist Stmt {$<treeNode>$ = createTree(0,0,NULL,NODE_CONN,NULL,$<treeNode>1,NULL,$<treeNode>2);}
			| Stmt {$<treeNode>$ = $<treeNode>1;}
			;

	Stmt : InputStmt {$<treeNode>$ = $<treeNode>1;}
			| OutputStmt {$<treeNode>$ = $<treeNode>1;}
			| AsgStmt {$<treeNode>$ = $<treeNode>1;}
			| IfStmt {$<treeNode>$ = $<treeNode>1;}
			| WhileStmt {$<treeNode>$ = $<treeNode>1;}
			| BreakStmt {$<treeNode>$ = $<treeNode>1;}
			| ContinueStmt {$<treeNode>$ = $<treeNode>1;}
			| RepeatUntilStmt {$<treeNode>$ = $<treeNode>1;}
			| DoWhileStmt {$<treeNode>$ = $<treeNode>1;}
			;

	InputStmt : READ'('ID')'';' {struct Gsymbol *temp = Lookup(&root, $<treeNode>3->varname);
								$<treeNode>3->Gentry = temp;
								$<treeNode>3->type = temp->type;
								$<treeNode>$ = createTree(0,0,NULL,NODE_READ,NULL,$<treeNode>3,NULL,NULL);
								}

				| READ'('ID'['ID']'')'';' {struct Gsymbol *temp1 = Lookup(&root, $<treeNode>3->varname);
										$<treeNode>3->Gentry = temp1;
										$<treeNode>3->type = temp1->type;
										struct Gsymbol *temp2 = Lookup(&root, $<treeNode>5->varname);
										$<treeNode>5->Gentry = temp2;
										$<treeNode>5->type = temp2->type;
										struct tnode *arrNode = createTree(0,temp1->type,NULL,NODE_ARR,NULL,$<treeNode>3,NULL,$<treeNode>5);
										$<treeNode>$ = createTree(0,0,NULL,NODE_READ,NULL,arrNode,NULL,NULL);
										}
			;

	OutputStmt : WRITE'('expr')'';' {$<treeNode>$ = createTree(0,0,NULL,NODE_WRITE,NULL,$<treeNode>3,NULL,NULL);}
			| WRITE'('STRING')'';' {$<treeNode>$ = createTree(0,0,NULL,NODE_WRITE,NULL,$<treeNode>3,NULL,NULL);}
			;

	AsgStmt : ID EQ expr';' {struct Gsymbol *tempNode = Lookup(&root, $<treeNode>1->varname);
							$<treeNode>1->Gentry = tempNode;
							$<treeNode>1->type = tempNode->type;
							char *temp = (char *)malloc(sizeof(char));
							strcpy(temp, "=");
							$<treeNode>$ = createTree(0,0,temp,NODE_ASSGN,NULL,$<treeNode>1,NULL,$<treeNode>3);}

			| ID'['expr']' EQ expr';' {struct Gsymbol *temp1 = Lookup(&root, $<treeNode>1->varname);
									$<treeNode>1->Gentry = temp1;
									$<treeNode>1->type = temp1->type;
									struct Gsymbol *temp2 = Lookup(&root, $<treeNode>3->varname);
									$<treeNode>3->Gentry = temp2;
									$<treeNode>3->type = temp2->type;
									char *temp = (char *)malloc(sizeof(char));
									strcpy(temp, "=");
									struct tnode *arrNode = createTree(0,temp1->type,NULL,NODE_ARR,NULL,$<treeNode>1,NULL,$<treeNode>3);
									$<treeNode>$ = createTree(0,0,temp,NODE_ASSGN,NULL,arrNode,NULL,$<treeNode>6);
									}
			;

	IfStmt : IF'('expr')' THEN Slist ELSE Slist ENDIF';' {$<treeNode>$ = createTree(0,0,NULL,NODE_IF,NULL,$<treeNode>3,$<treeNode>6,$<treeNode>8);}
			| 	IF'('expr')' THEN Slist ENDIF';' {$<treeNode>$ = createTree(0,0,NULL,NODE_IF,NULL,$<treeNode>3,$<treeNode>6,NULL);}
			;

	WhileStmt : WHILE'('expr')' DO Slist ENDWHILE';' {$<treeNode>$ = createTree(0,0,NULL,NODE_WHILE,NULL,$<treeNode>3,NULL,$<treeNode>6);}
			;

	BreakStmt : BREAK';' {$<treeNode>$ = createTree(0,0,NULL,NODE_BREAK,NULL,NULL,NULL,NULL);}
			;

	ContinueStmt : CONTINUE';' {$<treeNode>$ = createTree(0,0,NULL,NODE_CONTINUE,NULL,NULL,NULL,NULL);}
			;

	RepeatUntilStmt : REPEAT Slist UNTIL expr';' {$<treeNode>$ = createTree(0,0,NULL,NODE_REPUNTIL,NULL,$<treeNode>2,NULL,$<treeNode>4);}
			;

	DoWhileStmt : DO Slist WHILE'('expr')'';' {$<treeNode>$ = createTree(0,0,NULL,NODE_DOWHILE,NULL,$<treeNode>2,NULL,$<treeNode>5);}
			;

	expr : expr PLUS expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "+");
				$<treeNode>$ = createTree(0,inttype,temp,NODE_EX,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr MINUS expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "-");
				$<treeNode>$ = createTree(0,inttype,temp,NODE_EX,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr MUL expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "*");
				$<treeNode>$ = createTree(0,inttype,temp,NODE_EX,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr DIV expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "/");
				$<treeNode>$ = createTree(0,inttype,temp,NODE_EX,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr MOD expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "%");
				$<treeNode>$ = createTree(0,inttype,temp,NODE_EX,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr LT expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "<");
				$<treeNode>$ = createTree(0,booltype,temp,NODE_EX,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr GT expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, ">");
				$<treeNode>$ = createTree(0,booltype,temp,NODE_EX,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr LE expr {char *temp = (char *)malloc(2*sizeof(char));
				strcpy(temp, "<=");
				$<treeNode>$ = createTree(0,booltype,temp,NODE_EX,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr GE expr {char *temp = (char *)malloc(2*sizeof(char));
				strcpy(temp, ">=");
				$<treeNode>$ = createTree(0,booltype,temp,NODE_EX,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr NTEQ expr {char *temp = (char *)malloc(2*sizeof(char));
				strcpy(temp, "!=");
				printf("Node Type: %d\n", booltype);
				$<treeNode>$ = createTree(0,booltype,temp,NODE_EX,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr CONDEQ expr {char *temp = (char *)malloc(2*sizeof(char));
				strcpy(temp, "==");
				$<treeNode>$ = createTree(0,booltype,temp,NODE_EX,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| '(' expr ')' {$<treeNode>$ = $<treeNode>2;}
		| NUM {$<treeNode>$ = $<treeNode>1;}
		| ID'['ID']' { struct Gsymbol *temp1 = Lookup(&root, $<treeNode>1->varname);
					struct Gsymbol *temp2 = Lookup(&root, $<treeNode>3->varname);
					$<treeNode>1->Gentry = temp1;
					$<treeNode>1->type = temp1->type;
					$<treeNode>3->Gentry = temp2;
					$<treeNode>3->type = temp2->type;
					$<treeNode>$ = createTree(0,temp1->type,NULL,NODE_ARR,NULL,$<treeNode>1,NULL,$<treeNode>3);
					}
		| ID {	struct Gsymbol *temp = Lookup(&root, $<treeNode>1->varname);
				if(temp)
					printf("Not Null!\n");
				else
					printf("Null!\n");
				$<treeNode>1->Gentry = temp;
				$<treeNode>1->type = temp->type;
				$<treeNode>$ = $<treeNode>1;}
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
