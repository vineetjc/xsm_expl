#define NODE_EX 1
#define NODE_ASSGN 2
#define NODE_CONN 3
#define NODE_CONSTANT 4
#define NODE_READ 5
#define NODE_VAR 6
#define NODE_WRITE 7
#define NODE_IF 8
#define NODE_WHILE 9
#define NODE_BREAK 10
#define NODE_CONTINUE 11
#define NODE_REPUNTIL 12
#define NODE_DOWHILE 13
#define NODE_ARR 14
#define NODE_STRCONSTANT 15
#define reg_index int
#define inttype 1
#define booltype 2
#define stringtype 3

typedef struct tnode { 
	int val;	//value of a number for NUM nodes.
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  //information about non-leaf nodes - read/write/connector/+/* etc.  
	struct Gsymbol *Gentry;	//pointer to GST entry for global variables and functions
	struct tnode *left,*middle,*right;	//left and right branches   
}tnode;

typedef struct Gsymbol {
	char* name;	// name of the variable
	int type;	// type of the variable
	int size;	// size of the type of the variable
	int binding;	// stores the static memory address allocated to the variable
	struct Gsymbol *next;
}Gsymbol;

FILE *yyin;
FILE *xsm_file;
FILE *infile;
FILE *outfile;

struct tnode* createTree(int val,int type,char* varname,int nodetype,struct Gsymbol *Gentry,struct tnode *l,struct tnode *m,struct tnode *r);

int getReg();

void freeReg();

void backup_reg(int num);

void restore_reg(int num);

void xos_call(char *func, int arg1, int arg2, int tempreg, int flag);

reg_index codeGen(struct tnode *t);

void print_header();

void store_answer();

struct Gsymbol* Lookup(struct Gsymbol **headref, char *name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.

void install(struct Gsymbol **headref, char *name, int type, int size); // Creates a symbol table entry.

void printSymbolTable(struct Gsymbol **headref); // Prints out the symbol table 

void assignType(struct Gsymbol **headref, int type); // Assigns the types to all the remaining variables in a declaration.

/*Create a node tnode*/
//struct tnode* createTree(int val, int type, char* c, struct tnode *l, struct tnode *r);
	
	/*Make a leaf tnode and set the value of val field*/
//struct tnode* makeLeafNode(int n);
	
	/*Make a tnode with opertor, left and right branches set*/
//struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);
	
	/*To evaluate an expression tree*/
//int evaluate(struct tnode *t);
