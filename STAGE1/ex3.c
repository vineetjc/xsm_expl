int reg = -1;

struct tnode* makeLeafNode(int n)
{
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->op = NULL;
	temp->val = n;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
	
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->op = malloc(sizeof(char));
	*(temp->op) = c;
	temp->left = l;
	temp->right = r;
	return temp;
}
	
int evaluate(struct tnode *t){
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
}

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

int codeGen(struct tnode *t, FILE *target_file)
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
}
