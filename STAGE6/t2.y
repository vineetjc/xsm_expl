%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#include "t2.h"
	#include "t2.c"
	int yylex(void);
	int yyerror(char const *);
	struct Gsymbol *Groot = NULL;
	struct Lsymbol *Lroot = NULL;
	struct Typetable *Troot = NULL;
	struct Typetable *returnType = NULL;
	int bindval = 0;
	int lbindval = 0;
	int startCount = 0;
	int fIndex = 0;
%}

%union
{
	struct tnode* treeNode;
	struct Gsymbol* GTableNode;
	struct Lsymbol* LTableNode;
	struct Paramstruct* paramlist;
	struct Typetable* typeNode;
	struct Fieldlist* fieldNode;
	int number;
}

%token BEG READ WRITE DO WHILE IF THEN ELSE ENDIF ENDWHILE ID
%token DECL ENDDECL BREAK CONTINUE REPEAT UNTIL STRING MAIN
%token NUM PLUS MINUS MUL DIV END NTEQ CONDEQ INT STR RETURN
%token AND TYPE ENDTYPE NULLTYPE INITIALISE ALLOC FREE
%type <treeNode> ID NULLTYPE INITIALISE ALLOC FREE
%type <treeNode> NUM PLUS MINUS MUL DIV END NTEQ CONDEQ MOD AND
%type <number> INT STR
%type <fieldNode> FIELD
%right EQ
%left PLUS MINUS LT GT LE GE NTEQ CONDEQ
%left MUL DIV MOD

%%
	Program : TypeDefBlock GDeclBlock FDefBlock MainBlock
			| TypeDefBlock GDeclBlock MainBlock
			| TypeDefBlock FDefBlock MainBlock
			| GDeclBlock FDefBlock MainBlock
			| TypeDefBlock MainBlock
			| GDeclBlock MainBlock
			| FDefBlock MainBlock
			| MainBlock
			;

	TypeDefBlock	: TYPE TypeDefList ENDTYPE	{printTypeTable(&Troot);}
              		|
              		;

	TypeDefList	: TypeDefList TypeDef	{fIndex = 0;}
				| TypeDef				{fIndex = 0;}
				;

	TypeDef		: ID {TInstall(&Troot, $<treeNode>1->varname, 0, NULL);} '{'FieldDeclList'}'   	{
																									struct Typetable *tempType = TLookup(&Troot, $<treeNode>1->varname);
																									addFields(&tempType, $<fieldNode>4);
																								}
				;

	FieldDeclList	: FieldDeclList FieldDecl	{
													FAppendNode(&($<fieldNode>1), $<fieldNode>2);
													$<fieldNode>$ = $<fieldNode>1;
												}
					| FieldDecl		{
										$<fieldNode>$ = $<fieldNode>1;
									}
					;

	FieldDecl	: Type ID';'	{
										fIndex++;
										$<fieldNode>$ = createFieldNode($<treeNode>2->varname, fIndex, $<typeNode>1);
									}

	Type		: INT	{$<typeNode>$ = TLookup(&Troot, "int");}
				| STR	{$<typeNode>$ = TLookup(&Troot, "str");}
				| ID	{
							struct Typetable *temp = NULL;
							temp = TLookup(&Troot, $<treeNode>1->varname);
							if(temp == NULL)
							{
								printf("User-defined type not yet defined.\n");
								exit(1);
							}
							$<typeNode>$ = temp;
						}
				;

	GDeclBlock : DECL GDeclList ENDDECL		{printGSymbolTable(&Groot);}
			|
			;

	GDeclList : GDeclList GDecl
			| GDecl
			;

	GDecl : Type GidList';' 	{GAssignType(&Groot, $<typeNode>1);}
			;

	GidList : GidList','Gid
			| Gid
			;

	Gid : ID					{
									struct Gsymbol *temp = NULL;
									temp = GLookup(&Groot, $<treeNode>1->varname);
									if(temp == NULL)
									{
										//
										//printf("%s\n", $<treeNode>1->varname);
										GInstall(&Groot, $<treeNode>1->varname, NULL, 1, NULL);
										//
									}
									else
									{
										printf("Error. Variable declared twice.\n");
										exit(1);
									}
								}
		| ID'['NUM']'			{
									struct Gsymbol *temp = NULL;
									temp = GLookup(&Groot, $<treeNode>1->varname);
									struct Typetable *tempType = TLookup(&Troot, "int");
									$<treeNode>3->type = tempType;
									if(temp == NULL)
									{
										//
										//printf("%s\n", $<treeNode>1->varname);
										GInstall(&Groot, $<treeNode>1->varname, NULL, $<treeNode>3->val, NULL);
										//
									}
									else
									{
										printf("Error. Array name declared twice.\n");
										exit(1);
									}
								}
		| ID'('ParamList')'		{
									struct Gsymbol *temp = NULL;
									temp = GLookup(&Groot, $<treeNode>1->varname);
									if(temp == NULL)
									{
										//
										//printf("%s\n", $<treeNode>1->varname);
										GInstall(&Groot, $<treeNode>1->varname, NULL, -1, $<paramlist>3);
										//
									}
									else
									{
										printf("Error. Function name declared twice.\n");
										exit(1);
									}
								}
		;

	ParamList : ParamList','Param	{
										//lbindval = 0;
										struct Paramstruct *temp = NULL;
										if($<paramlist>1 == NULL)
											printf("Null parameter\n");
										else
											printf("Not Null parameter\n");
										printf("%s\t%s\n",$<paramlist>1->name, $<paramlist>3->name);
										temp = ParamLookup(&($<paramlist>1), $<paramlist>3->name);
										printf("Lookup over\n");
										if(temp == NULL)
										{
											printf("temp is null\n");
											appendParamNode(&($<paramlist>1),$<paramlist>3);
											bindval--;
											LAppendNode(&Lroot, LInstall($<paramlist>3->name, $<paramlist>3->type, bindval));
											printf("Appending done.\n");
											$<paramlist>$ = $<paramlist>1;
										}
										else
										{
											printf("Error. Parameter name already used in function.\n");
											exit(1);
										}
									}
				| Param				{
										//lbindval = 0;
										Lroot = NULL;
										bindval = -3;
										LAppendNode(&Lroot, LInstall($<paramlist>1->name, $<paramlist>1->type, bindval));
										$<paramlist>$ = $<paramlist>1;
									}
				|					{
										//lbindval = 0;
										$<paramlist>$ = NULL;
									}
				;

	Param : Type ID {$<paramlist>$ = createParamNode($<treeNode>2->varname, $<typeNode>1);}
			;

	FDefBlock : FDefBlock FDef
				| FDef
				;

	FDef : Type ID '('ParamList')' '{'LDeclBlock Body'}'	{
																printf("Function Definition of %s.\n", $<treeNode>2->varname);
																if(returnType != $<typeNode>1)
																{
																	printf("return type : %s \t def return type : %s \n", returnType->name, $<typeNode>1->name);
																	printf("Error. Return type mismatch.\n");
																	exit(1);
																}
																returnType = NULL;
																struct Gsymbol *temp = NULL;
																temp = GLookup(&Groot, $<treeNode>2->varname);
																//1.\n");
																if(temp == NULL)
																{
																	printf("Function not globally declared.\n");
																	exit(1);
																}
																printf("Label No : %d\n", temp->fLabel);
																checkNameEqv(&temp, &($<paramlist>4));
																//2.\n");
																//addParametersToLST(&Lroot, &($<paramlist>4));
																//printLSymbolTable(&Lroot);
																if(startCount == 0)
																{
																	print_header();
																	store_answer();
																	startCount = 1;
																}
																initFuncCode(temp->fLabel, &Lroot);
																//3.\n");
																int p = codeGen($<treeNode>8);
																//4.\n");
																endFuncCode(&Lroot);
																//evaluate($<treeNode>8);
																inorder($<treeNode>8);
																printf("Complete.\n");
																free(Lroot);
																free($<treeNode>8);
																Lroot = NULL;
															}
			;

	MainBlock : INT MAIN'('')' '{'LDeclBlock Body'}'	{
															printf("Main Definition.\n");
															struct Typetable *tempType = TLookup(&Troot, "int");
															if(returnType != tempType)
															{
																printf("Error. Return type mismatch.\n");
																exit(1);
															}
															returnType = NULL;
															//printGSymbolTable(&Groot);
															if(startCount == 0)
															{
																print_header();
																store_answer();
																startCount = 1;
															}
															initFuncCode(-1, &Lroot);
															int p = codeGen($<treeNode>7);
															endFuncCode(&Lroot);
															//evaluate($<treeNode>7);
															inorder($<treeNode>7);
															printf("Complete.\n");
															free(Lroot);
															free($<treeNode>7);
															Lroot = NULL;
														}
			;

	LDeclBlock : DECL LDeclList ENDDECL	{
											lbindval = 0;
											printLSymbolTable(&Lroot);
										}
				|						{
											lbindval = 0;
											printLSymbolTable(&Lroot);
										}
				;

	LDeclList : LDeclList LDecl
				| LDecl
				;

	LDecl : Type IdList';'		{
									LAssignType(&Lroot, $<typeNode>1);
								}
			;

	IdList : IdList','ID		{
									struct Lsymbol *temp = NULL;
									temp = LLookup(&Lroot, $<treeNode>3->varname);
									if(temp == NULL)
									{
										//
										//printf("%s\n", $<treeNode>1->varname);
										lbindval++;
										struct Lsymbol *temp2 = LInstall($<treeNode>3->varname, NULL, lbindval);
										LAppendNode(&Lroot, temp2);
										//
									}
									else
									{
										printf("Error. Variable declared twice.\n");
										exit(1);
									}
								}
			| ID				{
									lbindval++;
									LAppendNode(&Lroot, LInstall($<treeNode>1->varname, NULL, lbindval));
								}
			;

	Body : BEG Slist RetStmt END 	{
										$<treeNode>$ = createTree(0,NULL,NULL,NODE_CONN,NULL,NULL,NULL,$<treeNode>2,NULL,$<treeNode>3);
										returnType = $<treeNode>3->type;
									}
			| BEG RetStmt END		{
										$<treeNode>$ = $<treeNode>2;
										returnType = $<treeNode>2->type;
									}
			;

	Slist : Slist Stmt {$<treeNode>$ = createTree(0,NULL,NULL,NODE_CONN,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>2);}
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
			| RetStmt {$<treeNode>$ = $<treeNode>1;}
			;

	InputStmt : READ'('ID')'';' {
									int flag = 0;
									struct Lsymbol *temp = LLookup(&Lroot, $<treeNode>3->varname);
									struct Gsymbol *temp2 = NULL;
									if(temp == NULL)
									{
										flag++;
										printf("Not in LST.\n");
										temp2 = GLookup(&Groot, $<treeNode>3->varname);
										if(temp2 == NULL)
										{
											printf("Variable not declared.\n");
											exit(1);
										}
									}
									if(flag == 0)
									{
										$<treeNode>3->Lentry = temp;
										$<treeNode>3->type = temp->type;
									}
									else
									{
										$<treeNode>3->Gentry = temp2;
										$<treeNode>3->type = temp2->type;
									}
									$<treeNode>$ = createTree(0,NULL,NULL,NODE_READ,NULL,NULL,NULL,$<treeNode>3,NULL,NULL);
								}

				| READ'('ID'['expr']'')'';' {
											//i again.\n");
											struct Gsymbol *temp1 = GLookup(&Groot, $<treeNode>3->varname);
											if(temp1 == NULL)
											{
												printf("Array not declared.\n");
												exit(1);
											}
											$<treeNode>3->Gentry = temp1;
											$<treeNode>3->type = temp1->type;
											struct tnode *arrNode = createTree(0,$<treeNode>3->type,NULL,NODE_ARR,NULL,NULL,NULL,$<treeNode>3,NULL,$<treeNode>5);
											$<treeNode>$ = createTree(0,NULL,NULL,NODE_READ,NULL,NULL,NULL,arrNode,NULL,NULL);
											}

				| READ'('FIELD')'';'	{
											$<treeNode>$ = createTree(0,NULL,NULL,NODE_READ,NULL,NULL,NULL,$<treeNode>3,NULL,NULL);
										}
				;

	OutputStmt : WRITE'('expr')'';' {$<treeNode>$ = createTree(0,NULL,NULL,NODE_WRITE,NULL,NULL,NULL,$<treeNode>3,NULL,NULL);}
			| WRITE'('STRING')'';' 	{
										struct Typetable *tempType = TLookup(&Troot, "str");
										$<treeNode>3->type = tempType;
										$<treeNode>$ = createTree(0,NULL,NULL,NODE_WRITE,NULL,NULL,NULL,$<treeNode>3,NULL,NULL);
									}
			;

	AsgStmt : ID EQ expr';' {
								int flag = 0;
								struct Lsymbol *tempNode = LLookup(&Lroot, $<treeNode>1->varname);
								struct Gsymbol *tempNode2 = NULL;
								if(tempNode == NULL)
								{
									flag++;
									printf("Not in LST.\n");
									printf("%s\n", $<treeNode>1->varname);
									tempNode2 = GLookup(&Groot, $<treeNode>1->varname);
									if(tempNode2 == NULL)
									{
										printf("Variable not declared.\n");
										exit(1);
									}
									printf("There in GST.\n");
								}
								if(flag == 0)
								{
									$<treeNode>1->Lentry = tempNode;
									$<treeNode>1->type = tempNode->type;
								}
								else
								{
									//printf("There in GST2.\n");
									$<treeNode>1->Gentry = tempNode2;
									//printf("%s\n", tempNode2->name);
									//printf("There in GST3.\n");
									$<treeNode>1->type = tempNode2->type;
									//printf("There in GST4.\n");
								}
								char *temp = (char *)malloc(sizeof(char));
								strcpy(temp, "=");
								$<treeNode>$ = createTree(0,NULL,temp,NODE_ASSGN,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>3);
							}

			| ID'['expr']' EQ expr';' {
										struct Gsymbol *temp1 = GLookup(&Groot, $<treeNode>1->varname);
										if(temp1 == NULL)
										{
											printf("Array not declared.\n");
											exit(1);
										}
										$<treeNode>1->Gentry = temp1;
										$<treeNode>1->type = temp1->type;
										char *temp = (char *)malloc(sizeof(char));
										strcpy(temp, "=");
										struct tnode *arrNode = createTree(0,$<treeNode>1->type,NULL,NODE_ARR,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>3);
										$<treeNode>$ = createTree(0,NULL,temp,NODE_ASSGN,NULL,NULL,NULL,arrNode,NULL,$<treeNode>6);
									}

			| FIELD EQ expr';'	{
									char *temp = (char *)malloc(sizeof(char));
									strcpy(temp, "=");
									$<treeNode>$ = createTree(0,NULL,temp,NODE_ASSGN,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>3);
								}

			| ID EQ INITIALISE '('')'';'	{
												int flag = 0;
												struct Lsymbol *tempNode = LLookup(&Lroot, $<treeNode>1->varname);
												struct Gsymbol *tempNode2 = NULL;
												if(tempNode == NULL)
												{
													flag++;
													printf("Not in LST.\n");
													printf("%s\n", $<treeNode>1->varname);
													tempNode2 = GLookup(&Groot, $<treeNode>1->varname);
													if(tempNode2 == NULL)
													{
														printf("Variable not declared.\n");
														exit(1);
													}
													printf("There in GST.\n");
												}
												if(flag == 0)
												{
													$<treeNode>1->Lentry = tempNode;
													$<treeNode>1->type = tempNode->type;
												}
												else
												{
													//printf("There in GST2.\n");
													$<treeNode>1->Gentry = tempNode2;
													//printf("%s\n", tempNode2->name);
													//printf("There in GST3.\n");
													$<treeNode>1->type = tempNode2->type;
													//printf("There in GST4.\n");
												}
												$<treeNode>3->type = $<treeNode>1->type;
												char *temp = (char *)malloc(sizeof(char));
												strcpy(temp, "=");
												$<treeNode>$ = createTree(0,NULL,temp,NODE_ASSGN,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>3);
											}
			| ID EQ ALLOC'('')'';'	{
										int flag = 0;
										struct Lsymbol *tempNode = LLookup(&Lroot, $<treeNode>1->varname);
										struct Gsymbol *tempNode2 = NULL;
										if(tempNode == NULL)
										{
											flag++;
											printf("Not in LST.\n");
											printf("%s\n", $<treeNode>1->varname);
											tempNode2 = GLookup(&Groot, $<treeNode>1->varname);
											if(tempNode2 == NULL)
											{
												printf("Variable not declared.\n");
												exit(1);
											}
											printf("There in GST.\n");
										}
										if(flag == 0)
										{
											$<treeNode>1->Lentry = tempNode;
											$<treeNode>1->type = tempNode->type;
										}
										else
										{
											//printf("There in GST2.\n");
											$<treeNode>1->Gentry = tempNode2;
											//printf("%s\n", tempNode2->name);
											//printf("There in GST3.\n");
											$<treeNode>1->type = tempNode2->type;
											//printf("There in GST4.\n");
										}
										$<treeNode>3->type = $<treeNode>1->type;
										char *temp = (char *)malloc(sizeof(char));
										strcpy(temp, "=");
										$<treeNode>$ = createTree(0,NULL,temp,NODE_ASSGN,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>3);
									}
			| FIELD EQ ALLOC'('')'';'	{
											$<treeNode>3->type = getFieldType(&($<treeNode>1));
											char *temp = (char *)malloc(sizeof(char));
											strcpy(temp, "=");
											$<treeNode>$ = createTree(0,NULL,temp,NODE_ASSGN,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>3);
										}
			| FREE'('ID')'';'			{
											int flag = 0;
											struct Lsymbol *tempNode = LLookup(&Lroot, $<treeNode>3->varname);
											struct Gsymbol *tempNode2 = NULL;
											if(tempNode == NULL)
											{
												flag++;
												printf("Not in LST.\n");
												printf("%s\n", $<treeNode>3->varname);
												tempNode2 = GLookup(&Groot, $<treeNode>3->varname);
												if(tempNode2 == NULL)
												{
													printf("Variable not declared.\n");
													exit(1);
												}
												printf("There in GST.\n");
											}
											if(flag == 0)
											{
												$<treeNode>3->Lentry = tempNode;
												$<treeNode>3->type = tempNode->type;
											}
											else
											{
												//printf("There in GST2.\n");
												$<treeNode>3->Gentry = tempNode2;
												//printf("%s\n", tempNode2->name);
												//printf("There in GST3.\n");
												$<treeNode>3->type = tempNode2->type;
												//printf("There in GST4.\n");
											}
											$<treeNode>1->left = $<treeNode>3;
											$<treeNode>$ = $<treeNode>1;
										}
			| FREE'('FIELD')'';'		{
											$<treeNode>1->left = $<treeNode>3;
											$<treeNode>$ = $<treeNode>1;
										}
			;

	IfStmt : IF'('expr')' THEN Slist ELSE Slist ENDIF';' {$<treeNode>$ = createTree(0,NULL,NULL,NODE_IF,NULL,NULL,NULL,$<treeNode>3,$<treeNode>6,$<treeNode>8);}
			| 	IF'('expr')' THEN Slist ENDIF';' {$<treeNode>$ = createTree(0,NULL,NULL,NODE_IF,NULL,NULL,NULL,$<treeNode>3,$<treeNode>6,NULL);}
			;

	WhileStmt : WHILE'('expr')' DO Slist ENDWHILE';' {$<treeNode>$ = createTree(0,NULL,NULL,NODE_WHILE,NULL,NULL,NULL,$<treeNode>3,NULL,$<treeNode>6);}
			;

	BreakStmt : BREAK';' {$<treeNode>$ = createTree(0,NULL,NULL,NODE_BREAK,NULL,NULL,NULL,NULL,NULL,NULL);}
			;

	ContinueStmt : CONTINUE';' {$<treeNode>$ = createTree(0,NULL,NULL,NODE_CONTINUE,NULL,NULL,NULL,NULL,NULL,NULL);}
			;

	RepeatUntilStmt : REPEAT Slist UNTIL expr';' {$<treeNode>$ = createTree(0,NULL,NULL,NODE_REPUNTIL,NULL,NULL,NULL,$<treeNode>2,NULL,$<treeNode>4);}
			;

	DoWhileStmt : DO Slist WHILE'('expr')'';' {$<treeNode>$ = createTree(0,NULL,NULL,NODE_DOWHILE,NULL,NULL,NULL,$<treeNode>2,NULL,$<treeNode>5);}
			;

	RetStmt : RETURN expr';' {
								//lbindval = 0;
								$<treeNode>$ = createTree(0,$<treeNode>2->type,NULL,NODE_RETURN,NULL,NULL,NULL,$<treeNode>2,NULL,NULL);
							}
			;

	FIELD	: ID'.'ID		{
								int flag = 0;
								struct Lsymbol *tempNode = LLookup(&Lroot, $<treeNode>1->varname);
								struct Gsymbol *tempNode2 = NULL;
								if(tempNode == NULL)
								{
									flag++;
									printf("Not in LST.\n");
									tempNode2 = GLookup(&Groot, $<treeNode>1->varname);
									if(tempNode2 == NULL)
									{
										printf("Variable not declared.\n");
										exit(1);
									}
									printf("There in GST.\n");
								}
								if(flag == 0)
								{
									$<treeNode>1->Lentry = tempNode;
									$<treeNode>1->type = tempNode->type;
								}
								else
								{
									//printf("There in GST2.\n");
									$<treeNode>1->Gentry = tempNode2;
									//printf("%s\n", tempNode2->name);
									//printf("There in GST3.\n");
									$<treeNode>1->type = tempNode2->type;
									//printf("There in GST4.\n");
								}
								struct Fieldlist *tempNode3 = FLookup(&($<treeNode>1->type), $<treeNode>3->varname);
								if(tempNode3 == NULL)
								{
									printf("Invalid member of user-defined type accessed.\n");
									exit(0);
								}
								$<treeNode>3->type = tempNode3->type;
								$<treeNode>3->nodetype = NODE_FIELD;
								$<treeNode>1->nodetype = NODE_FIELD;
								//struct tnode *memberNode = createTree(0,tempNode3->type,tempNode3->name,NODE_FIELD,NULL,NULL,NULL,NULL,NULL,NULL);
								$<treeNode>1->left = $<treeNode>3;
								$<treeNode>$ = $<treeNode>1;
							}
          	| FIELD'.'ID  {
				  				struct tnode *tempNode = $<treeNode>1;
								while(tempNode->left)
								{
									tempNode = tempNode->left;
								}
				  				struct Fieldlist *tempNode3 = FLookup(&(tempNode->type), $<treeNode>3->varname);
								if(tempNode3 == NULL)
								{
									printf("Invalid member of user-defined type accessed.\n");
									exit(0);
								}
				  				$<treeNode>3->type = tempNode3->type;
								$<treeNode>3->nodetype = NODE_FIELD;
								tempNode->left = $<treeNode>3;
								$<treeNode>$ = $<treeNode>1;
			  				}
			;

	expr : expr PLUS expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "+");
				struct Typetable *tempType = TLookup(&Troot, "int");
				$<treeNode>$ = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr MINUS expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "-");
				struct Typetable *tempType = TLookup(&Troot, "int");
				$<treeNode>$ = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr MUL expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "*");
				struct Typetable *tempType = TLookup(&Troot, "int");
				$<treeNode>$ = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr DIV expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "/");
				struct Typetable *tempType = TLookup(&Troot, "int");
				$<treeNode>$ = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr MOD expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "%");
				struct Typetable *tempType = TLookup(&Troot, "int");
				$<treeNode>$ = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr LT expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "<");
				struct Typetable *tempType = TLookup(&Troot, "bool");
				$<treeNode>$ = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr GT expr {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, ">");
				struct Typetable *tempType = TLookup(&Troot, "bool");
				$<treeNode>$ = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr LE expr {char *temp = (char *)malloc(2*sizeof(char));
				strcpy(temp, "<=");
				struct Typetable *tempType = TLookup(&Troot, "bool");
				$<treeNode>$ = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr GE expr {char *temp = (char *)malloc(2*sizeof(char));
				strcpy(temp, ">=");
				struct Typetable *tempType = TLookup(&Troot, "bool");
				$<treeNode>$ = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr NTEQ expr {char *temp = (char *)malloc(2*sizeof(char));
				strcpy(temp, "!=");
				struct Typetable *tempType = TLookup(&Troot, "bool");
				//printf("Node Type: %d\n", booltype);
				$<treeNode>$ = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr CONDEQ expr {char *temp = (char *)malloc(2*sizeof(char));
				strcpy(temp, "==");
				struct Typetable *tempType = TLookup(&Troot, "bool");
				$<treeNode>$ = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| expr AND expr {char *temp = (char *)malloc(2*sizeof(char));
				strcpy(temp, "&&");
				struct Typetable *tempType = TLookup(&Troot, "bool");
				$<treeNode>$ = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>3);}

		| '(' expr ')' {$<treeNode>$ = $<treeNode>2;}
		| NUM	{
					struct Typetable *tempType = TLookup(&Troot, "int");
					$<treeNode>1->type = tempType;
					$<treeNode>$ = $<treeNode>1;
				}
		| STRING	{
						struct Typetable *tempType = TLookup(&Troot, "str");
						$<treeNode>1->type = tempType;
						$<treeNode>$ = $<treeNode>1;
					}
		| NULLTYPE	{
					struct Typetable *tempType = TLookup(&Troot, "null");
					$<treeNode>1->type = tempType;
					$<treeNode>$ = $<treeNode>1;
				}
		| ID'['expr']' {
						struct Gsymbol *temp1 = GLookup(&Groot, $<treeNode>1->varname);
						if(temp1 == NULL)
						{
							printf("Array not declared.\n");
							exit(1);
						}
						$<treeNode>1->Gentry = temp1;
						$<treeNode>1->type = temp1->type;
						$<treeNode>$ = createTree(0,temp1->type,NULL,NODE_ARR,NULL,NULL,NULL,$<treeNode>1,NULL,$<treeNode>3);
					}
		| ID 	{
					int flag = 0;
					struct Lsymbol *temp = LLookup(&Lroot, $<treeNode>1->varname);
					struct Gsymbol *temp2 = NULL;
					if(temp == NULL)
					{
						flag++;
						printf("Not in LST.\n");
						temp2 = GLookup(&Groot, $<treeNode>1->varname);
						if(temp2 == NULL)
						{
							printf("Variable not declared.\n");
							exit(1);
						}
					}
					printf("There in GST.\n");
					if(flag == 0)
					{
						$<treeNode>1->Lentry = temp;
						$<treeNode>1->type = temp->type;
					}
					else
					{
						$<treeNode>1->Gentry = temp2;
						$<treeNode>1->type = temp2->type;
					}
					$<treeNode>$ = $<treeNode>1;
				}
		| ID'('')' 			{
								struct Gsymbol *temp = GLookup(&Groot, $<treeNode>1->varname);
								if(temp == NULL)
								{
									printf("Function not declared.\n");
									exit(1);
								}
								$<treeNode>1->Gentry = temp;
								$<treeNode>1->type = temp->type;
								$<treeNode>$ = createTree(0,$<treeNode>1->type,$<treeNode>1->varname,NODE_FUNCTION,$<treeNode>1->Gentry,NULL,NULL,NULL,NULL,NULL);
							}
		| ID'('ArgList')'	{
								struct Gsymbol *temp = GLookup(&Groot, $<treeNode>1->varname);
								if(temp == NULL)
								{
									printf("Function not declared.\n");
									exit(1);
								}
								$<treeNode>1->Gentry = temp;
								$<treeNode>1->type = temp->type;
								$<treeNode>$ = createTree(0,$<treeNode>1->type,$<treeNode>1->varname,NODE_FUNCTION,$<treeNode>1->Gentry,NULL,NULL,$<treeNode>3,NULL,NULL);
							}
		| FIELD		{$<treeNode>$ = $<treeNode>1;}
		;

	ArgList : ArgList','expr	{
									appendArg(&($<treeNode>1),$<treeNode>3);
									$<treeNode>$ = $<treeNode>1;
								}
			| expr				{
									$<treeNode>$ = $<treeNode>1;
								}
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
	TypeTableCreate(&Troot);
	printf("Initial Type Table.\n");
	printTypeTable(&Troot);
	yyparse();
	if(fptr)
		fclose(fptr);
	fclose(xsm_file);
	fclose(infile);
	fclose(outfile);
	return 0;
}
