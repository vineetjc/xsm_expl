int reg = -1;
int labelCount = -1;
int regarr[26];
int whileStack[50];
int top = -1;

void push(int whileStack[], int num)
{
	top++;
	whileStack[top] = num;
	return;
}

void pop(int whileStack[])
{
	top--;
	return;
}

struct tnode* createTree(int val,int type,char* varname,int nodetype,struct tnode *l,struct tnode *m,struct tnode *r){
    //creating tnode.....
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    //assigning val,type,nodetype
    temp->val=val;
    temp->type=type;
    temp->nodetype=nodetype;
    //mallocing for varname
    if(varname != NULL)
    {
    	temp->varname=(char*)malloc(2*sizeof(char));
    	strcpy(temp->varname, varname);
		if((strcmp(varname, "+") == 0) || (strcmp(varname, "-") == 0) || (strcmp(varname, "/") == 0) || (strcmp(varname, "*") == 0))
		{
			if((l->type != inttype) || (r->type != inttype))
			{
				fprintf(stderr, "Error : Arithmetic expression type mismatch\n");
				exit(0);
			}
			else
			{
				temp->type = inttype;
			}
		}
	}
    else
    {
    	temp->varname=NULL;
    }
	//assigning left, middle and right nodes....
    temp->left = l;
	temp->middle = m;
    temp->right = r;
	if((temp->nodetype == NODE_IF) || (temp->nodetype == NODE_WHILE))
	{
		if(temp->left->type != booltype)
		{
			fprintf(stderr, "Error : Non-Boolean guard for If or While Statement.\n");
			exit(0);
		}
	}
    return temp;
}
	
/*int evaluate(struct tnode *t){
	if(t->op == NULL)
	{
		return t->val;
	}
	else
	{
		switch(*(t->op))
		{
			case '+' : return evaluate(t->left) + evaluate(t->right);
			break;
			case '-' : return evaluate(t->left) - evaluate(t->right);
			break;
			case '*' : return evaluate(t->left) * evaluate(t->right);
			break;
			case '/' : return evaluate(t->left) / evaluate(t->right);
			break;
		}
	}
}

void printPrefix(struct tnode *t)
{
	if(t != NULL)
	{
		if(t->op == NULL)
		{
			printf("%d ", t->val);
		}
		else
		{
			printf("%c ", *(t->op));
		}
		printPrefix(t->left);
		printPrefix(t->right);
	}
	return;
}

void printPostfix(struct tnode *t)
{
	if(t != NULL)
	{
		printPostfix(t->left);
		printPostfix(t->right);
		if(t->op == NULL)
		{
			printf("%d ", t->val);
		}
		else
		{
			printf("%c ", *(t->op));
		}
	}
	return;
}*/

int getReg()
{
	reg++;
	return reg;
}

void freeReg()
{
	reg--;
	return;
}

int getLabel()
{
	labelCount++;
	return labelCount;
}

void backup_reg(int num)
{
	int p = 0;
	while(p <= num)
	{
		fprintf(xsm_file, "PUSH R%d\n", p);
		p++;
	}
	return;
}

void restore_reg(int num)
{
	int p = num;
	while(p >= 0)
	{
		fprintf(xsm_file, "POP R%d\n", p);
		p--;
	}
	return;
}

void xos_call(char *func, int arg1, int arg2, int p)
{
	fprintf(xsm_file, "MOV R%d, \"%s\"\n", p, func);
	fprintf(xsm_file, "PUSH R%d\n", p);
	fprintf(xsm_file, "MOV R%d, %d\n", p, arg1);
	fprintf(xsm_file, "PUSH R%d\n", p);
	if(func[0] == 'W')
	{
		fprintf(xsm_file, "MOV R%d, R%d\n", p, arg2);
	}
	else
	{
		fprintf(xsm_file, "MOV R%d, %d\n", p, arg2);
	}
	fprintf(xsm_file, "PUSH R%d\n", p);
	fprintf(xsm_file, "PUSH R0\n");
	fprintf(xsm_file, "PUSH R0\n");
	fprintf(xsm_file, "CALL 0\n");
	fprintf(xsm_file, "POP R%d\n", p);
	fprintf(xsm_file, "POP R0\n");
	fprintf(xsm_file, "POP R0\n");
	fprintf(xsm_file, "POP R0\n");
	fprintf(xsm_file, "POP R0\n");
	return;
}

reg_index codeGen(struct tnode *t)
{
	int p, q, add;
	int l1, l2, l3;
	//printf("Initial\n");
	switch(t->nodetype)
	{
		case NODE_CONN : 	//printf("Switchconn\n");
					if(t->left)
					{
						p = codeGen(t->left);
					}
					if(t->right)
					{
						p = codeGen(t->right);
					}
					freeReg();
					return p;
					break;
					
		case NODE_CONSTANT : 	//printf("Switchconst\n");
					p = getReg();
					fprintf(xsm_file, "MOV R%d, %d\n", p, t->val);
					return p;
					break;
		
		case NODE_VAR :		//printf("Switchvariable\n");
					p = getReg();
					add = 4096 + (*(t->varname)) - 'a';
					fprintf(xsm_file, "MOV R%d, [%d]\n", p, add);
					return p;
					break;			
		
		case NODE_WRITE : 	//printf("Switchwrite\n");
					p = getReg();
					q = codeGen(t->left);
					backup_reg(p);
					xos_call("Write", -2, q, p);
					restore_reg(p);
					freeReg();
					return p;
					break;
		
		case NODE_READ : 	//printf("Switchread\n");
					p = getReg();
					add = 4096 + *(t->left->varname) - 'a';
					backup_reg(p);
					xos_call("Read", -1, add, p);
					restore_reg(p);
					return p;
					break;
		
		case NODE_ASSGN :	//printf("Switchassgn\n");
					add = 4096 + *(t->left->varname) - 'a';
					q = codeGen(t->right);
					fprintf(xsm_file, "MOV [%d], R%d\n", add, q);
					return q;
					break;
		
		case NODE_EX :	//printf("Switchexpr\n");
					p = codeGen(t->left);
					q = codeGen(t->right);
					if(strcmp(t->varname, "!=") == 0)
					{
						fprintf(xsm_file, "NE R%d, R%d\n", p, q);
					}
					else if(strcmp(t->varname, "==") == 0)
					{
						fprintf(xsm_file, "EQ R%d, R%d\n", p, q);
					}
					else if(strcmp(t->varname, ">=") == 0)
					{
						fprintf(xsm_file, "GE R%d, R%d\n", p, q);
					}
					else if(strcmp(t->varname, "<=") == 0)
					{
						fprintf(xsm_file, "LE R%d, R%d\n", p, q);
					}
					else
					{
						switch(*(t->varname))
						{
							case '+' : 	fprintf(xsm_file, "ADD R%d, R%d\n", p, q);
									break;
							case '-' : 	fprintf(xsm_file, "SUB R%d, R%d\n", p, q);
									break;
							case '*' : 	fprintf(xsm_file, "MUL R%d, R%d\n", p, q);
									break;
							case '/' : 	fprintf(xsm_file, "DIV R%d, R%d\n", p, q);
									break;
							case '>' : 	fprintf(xsm_file, "GT R%d, R%d\n", p, q);
									break;
							case '<' : 	fprintf(xsm_file, "LT R%d, R%d\n", p, q);
									break;					 		 		 	
						}
					}	
					freeReg();
					return p;
					break;
		
		case NODE_WHILE : l1 = getLabel();
					l2 = getLabel();
					push(whileStack, l1);
					push(whileStack, l2);
					fprintf(xsm_file, "L%d:\n", l1);
					p = codeGen(t->left);
					fprintf(xsm_file, "JZ R%d, L%d\n", p, l2);
					q = codeGen(t->right);
					fprintf(xsm_file, "JMP L%d\n", l1);
					fprintf(xsm_file, "L%d:\n", l2);
					pop(whileStack);
					pop(whileStack);
					return q; 
					break;
		
		case NODE_IF : l1 = getLabel();
					p = codeGen(t->left);
					fprintf(xsm_file, "JZ R%d, L%d\n", p, l1);
					q = codeGen(t->middle);
					if(t->right)
					{
						l2 = getLabel();
						fprintf(xsm_file, "JMP L%d\n", l2);
					}	
					fprintf(xsm_file, "L%d:\n", l1);
					if(t->right)
					{
						q = codeGen(t->right);
						fprintf(xsm_file, "L%d:\n", l2);
					}
					return q;		
					break;

		case NODE_BREAK : 
					if(top != -1)
					{
						l1 = whileStack[top];
						fprintf(xsm_file, "JMP L%d\n", l1);
					}	
					return 1;
					break;

		case NODE_CONTINUE : 
					if(top != -1)
					{
						l2 = whileStack[top-1];
						fprintf(xsm_file, "JMP L%d\n", l2);
					}	
					return 1;
					break;

		case NODE_REPUNTIL :
					l1 = getLabel();
					l2 = getLabel();
					l3 = getLabel();
					push(whileStack, l2);
					push(whileStack, l3);
					fprintf(xsm_file, "L%d:\n", l1);
					p = codeGen(t->left);
					fprintf(xsm_file, "L%d:\n", l2);
					q = codeGen(t->right);
					fprintf(xsm_file, "JZ R%d, L%d\n", q, l1);
					fprintf(xsm_file, "L%d:\n", l3);
					break;

		case NODE_DOWHILE : 
					l1 = getLabel();
					l2 = getLabel();
					l3 = getLabel();
					push(whileStack, l2);
					push(whileStack, l3);
					fprintf(xsm_file, "L%d:\n", l1);
					p = codeGen(t->left);
					fprintf(xsm_file, "L%d:\n", l2);
					q = codeGen(t->right);
					fprintf(xsm_file, "JNZ R%d, L%d\n", q, l1);
					fprintf(xsm_file, "L%d:\n", l3);
					break;												
	}				
}

/*int codeGen(struct tnode *t, FILE *target_file)
{
	if((t->left == NULL) && (t->right == NULL))
	{
		int p = getReg();
		fprintf(target_file, "MOV R%d, %d\n", p, t->val);
		return p;
	}
	else
	{
		int i = codeGen(t->left, target_file);
		int j = codeGen(t->right, target_file);
		if(*(t->op) == '+')
		{
			fprintf(target_file, "ADD R%d, R%d\n", i, j);
			freeReg();
			return i;
		}
		if(*(t->op) == '-')
		{
			fprintf(target_file, "SUB R%d, R%d\n", i, j);
			freeReg();
			return i;
		}
		if(*(t->op) == '/')
		{
			fprintf(target_file, "DIV R%d, R%d\n", i, j);
			freeReg();
			return i;
		}
		if(*(t->op) == '*')
		{
			fprintf(target_file, "MUL R%d, R%d\n", i, j);
			freeReg();
			return i;
		}
	}	
}*/

void tnode_print(struct tnode *t)
{  
	printf("\n[");
	printf("val %d\n",t->val);
	printf("type %d\n",t->type);
	printf("nodetype %d\n",t->nodetype);
	switch(t->nodetype)
	{
		case 1:
	    		printf("EXPR\n");
	    		break;
	    	case 2:
	    		printf("ASSGN\n");
	    		break;
	    	case 3:
			printf("CONN\n");
			break;
	    	case 4:
	    		printf("CONSTANT\n");
	    		break;
	    	case 5:
	    		printf("READ\n");
	    		break;
	    	case 6:
	   		printf("VAR\n");
	    		break;
	    	case 7:
	    		printf("WRITE\n");
	    		break;
			case 8 : 
				printf("IF\n");
				break;
			case 9 : 
				printf("WHILE\n");
				break;
			case 10 :
				printf("BREAK\n");
				break;
			case 11 :
				printf("CONTINUE\n");
				break;
			case 12 :
				printf("REPEAT-UNTIL\n");
				break;
			case 13 :
				printf("DO-WHILE\n");
				break;									
	}
  
  	if(t->varname!=NULL)
  		printf("varname %c\n",*(t->varname));
 	printf("]\n");
}
// 
void inorder(struct tnode *t)
{ //printf("inside inorder");
	if(t==NULL)
		return;
	inorder(t->left);
	tnode_print(t);
	inorder(t->middle);
	inorder(t->right);
}

void print_header()
{
	fprintf(xsm_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0); 
	fprintf(xsm_file, "BRKP\n");
	fprintf(xsm_file, "MOV SP, 4121\n");
	return;
}

void store_answer()
{
	fprintf(xsm_file, "MOV SP, 4095\n");
	fprintf(xsm_file, "PUSH R%d\n",reg);
	int p = getReg();
	backup_reg(p);
	xos_call("Exit", 0, 0, p);
	restore_reg(p);
	freeReg();  
	return;
}

int evaluate(struct tnode *t)
{
	int temp, lval, mval, rval;
	switch(t->nodetype)
	{
		case NODE_CONSTANT : return t->val;
					break;
		case NODE_VAR : temp = *(t->varname) - 'a';
				printf("%c value is : %d\n", *(t->varname), regarr[temp]);
				return regarr[temp];
				break;
		case NODE_READ : temp = *(t->left->varname) - 'a'; 
				printf("Gonna read now.\n");
				fscanf(infile, "%d\n", &regarr[temp]);
				printf("Value Read ; %d\n", regarr[temp]);
				return regarr[temp];
				break;
		case NODE_WRITE : lval = evaluate(t->left);
				fprintf(outfile, "%d\n", lval);
				printf("Just printed.\n");
				printf("Value printed : %d\n", lval);
				return lval;
				break;
		case NODE_EX :
			if(strcmp(t->varname, "<=") == 0)
			{
				lval = evaluate(t->left);
				rval = evaluate(t->right);
				if(lval <= rval)
					return 1;
				else 
					return 0;	
			}
			else if(strcmp(t->varname, ">=") == 0)
			{
				lval = evaluate(t->left);
				rval = evaluate(t->right);
				if(lval >= rval)
					return 1;
				else 
					return 0;	
			}
			else if(strcmp(t->varname, "!=") == 0)
			{
				lval = evaluate(t->left);
				rval = evaluate(t->right);
				if(lval != rval)
					return 1;
				else 
					return 0;	
			}
			else if(strcmp(t->varname, "==") == 0)
			{
				lval = evaluate(t->left);
				rval = evaluate(t->right);
				if(lval == rval)
					return 1;
				else 
					return 0;	
			}  
			switch(*(t->varname))
			{
				case '+' : return evaluate(t->left) + evaluate(t->right);
						break;
				case '-' : return evaluate(t->left) - evaluate(t->right);
						break;
				case '*' : return evaluate(t->left) * evaluate(t->right);
						break;
				case '/' : return evaluate(t->left) / evaluate(t->right);
						break;
				case '<' : lval = evaluate(t->left);
						rval = evaluate(t->right);
						if(lval < rval)
							return 1;
						else
							return 0;	
						break;
				case '>' : lval = evaluate(t->left);
						rval = evaluate(t->right);
						if(lval > rval)
							return 1;
						else
							return 0;	
						break;										
			}
			break;
		case NODE_ASSGN : temp = *(t->left->varname) - 'a';
					rval = evaluate(t->right);
					regarr[temp] = rval;
					return regarr[temp];
					break;
		case NODE_CONN : if(t->left)
					lval = evaluate(t->left);
					if(t->middle)
						mval = evaluate(t->middle);
					if(t->right)
						rval = evaluate(t->right);
					return rval;
					break;
		case NODE_IF : lval = evaluate(t->left);
				if(lval == 1)
				{
					mval = evaluate(t->middle);
					return mval;
				}
				else
				{
					if(t->right)
					{
						rval = evaluate(t->right);
						return rval;
					}	
				}
				break;
		case NODE_WHILE :
				lval = evaluate(t->left);
				printf("lval = %d\n", lval); 
				while(lval == 1)
				{
					rval = evaluate(t->right);
					lval = evaluate(t->left);
					printf("lval = %d\n", lval);
				}
				return rval;
				break;
		case NODE_BREAK : 
				break;
		case NODE_CONTINUE : 
				break;
		case NODE_REPUNTIL :
				lval = evaluate(t->left);
				rval = evaluate(t->right);
				printf("rval = %d\n", rval);
				while(rval == 0)
				{
					lval = evaluate(t->left);
					rval = evaluate(t->right);
					printf("rval = %d\n", rval);
				}
				break;
		case NODE_DOWHILE :
				lval = evaluate(t->left);
				rval = evaluate(t->right);
				printf("rval = %d\n", rval);
				while(rval == 1)
				{
					lval = evaluate(t->left);
					rval = evaluate(t->right);
					printf("rval = %d\n", rval);
				}
				break;									
	}
}
