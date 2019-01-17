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
	temp->op =(char*)malloc(sizeof(char));
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
