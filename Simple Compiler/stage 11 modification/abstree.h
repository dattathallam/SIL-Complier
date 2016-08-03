#define FALSE 		0
#define TRUE 		1
#define TYPE_INT 	2
#define TYPE_BOOL 	3
#define TYPE_VOID 	4
#define NODE_ASGN	5
#define NODE_READ 	6
#define NODE_WRITE	7
#define NODE_IF 	8 
#define NODE_IF_ELSE 9 
#define NODE_ID  	10
#define NODE_PLUS 	11 
#define NODE_MINUS 	12
#define NODE_MUL 	13
#define NODE_DIV    25
#define NODE_MOD    26
#define NODE_LT  	14
#define NODE_GT  	15
#define NODE_DEQ 	16
#define NODE_NEQ    27
#define NODE_NUM 	17
#define NODE_WHILE  18
#define NODE_T 		20
#define NODE_F 		21
#define NODE_LE     22
#define NODE_GE     23
#define NODE_ARRAY  24
#define NODE_ARRAY_ASGN 28
#define NODE_ARRAY_READ 29
#define NODE_AND    30
#define NODE_OR    31
#define NODE_NOT    32
#define NODE_FUNC	33
#define SYMBOL_FUNC_INT 34
#define SYMBOL_FUNC_BOOLEAN 35
#define NODE_RET 36
#define NODE_BODY 37
#define NODE_MAIN 38
#define NODE_EXPR 39
#define NODE_FIELD 40
#define NODE_ALLOC 41
#define NODE_FREE 42
#define NODE_NILL 43
#define NODE_ALLOC1 44
#define NODE_FREE1 45

#define DEFAULT     100
#define TYPE_DEFAULT 200

struct Tnode {

struct TypeTable* TYPE; 		// Integer, Boolean or Void (for statements)
				/* Must point to the type expression tree for user defined types */
int NODE;
				/* this field should carry following information:
				* a) operator : (+,*,/ etc.) for expressions
				* b) statement Type : (WHILE, READ etc.) for statements */
char* NAME; 	// For Identifiers/Functions
int VALUE; 		// for constants && incase of functions put -1
struct ArgStruct *ArgList; // List of arguments for functions
struct Tnode *Ptr1, *Ptr2, *Ptr3;	/* Maximum of three subtrees (3 required for IF THEN ELSE */
struct Gsymbol *Gentry; // For global identifiers/functions
struct Lsymbol *Lentry; // For Local variables
};	


struct Tnode *TreeCreate(struct TypeTable* TYPE,int NODE,char* NAME,int VALUE,struct Tnode *ArgList,
										struct Tnode *Ptr1,struct Tnode *Ptr2,struct Tnode *Ptr3);

int Evaluate(struct Tnode *root);
void intermediate_codegen(struct Tnode *abstree);
int codegen(struct Tnode* root);
