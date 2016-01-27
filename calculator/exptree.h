typedef struct tnode
{
   char *op;      //indicates the opertor branch
   int value;      //value of for the expression tree
   struct tnode *left,*right;    //left and right branches
}tnode;

#define YYSTYPE tnode *

// Make a tnode with opertor, left and right branches set
struct tnode* makeOperatorNode(char c,struct tnode* l,struct tnode* r);

// Make a leaf tnode and set the value of val field
struct tnode* makeLeafNode(int n);

// To evaluate an expression tree
int evaluate(struct tnode *t);