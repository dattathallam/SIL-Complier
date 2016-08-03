struct Tnode *TreeCreate(int TYPE,int NODE,char* NAME,int VALUE,struct Tnode *ArgList,
										struct Tnode *Ptr1,struct Tnode *Ptr2,struct Tnode *Ptr3)
{
	struct Tnode * temp;
	temp = (struct Tnode *) malloc(sizeof(struct Tnode));
	temp -> TYPE = TYPE;
	temp -> NODE = NODE;
	if(NAME != NULL)
	{
   	 	temp -> NAME = (char *)malloc(sizeof(NAME));
   	 	strcpy(temp -> NAME,NAME);
    }
    else
    {
   	 	temp -> NAME = NULL;     
    }
	temp -> VALUE =  VALUE;
	temp -> ArgList = ArgList;

	if(temp -> TYPE == NODE_FUNC)
	{
		
	}
	temp -> Ptr1 = Ptr1;
	temp -> Ptr2 = Ptr2;
	temp -> Ptr3 = Ptr3;
	return temp;
}
void printtree(struct Tnode* root)
{
	int tree_iter = 0;
	struct ArgStruct *Argtemp,*Arg_callee = root -> Ptr3;
	Argtemp = Arg_callee;
	struct Tnode *Ttemp;
	while(Argtemp != NULL)
	{
		++tree_iter;
		printf("%d : %s\n",tree_iter,Argtemp -> NAME );
		Argtemp = Argtemp -> NEXT;
	}
	Ttemp = root;
	while( tree_iter != 0 )
	{
		printf("%s\n",Ttemp -> Ptr1 -> NAME );
		Ttemp =  Ttemp -> Ptr2;
		tree_iter--;
	}
}