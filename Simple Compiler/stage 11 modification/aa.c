struct Tnode *TreeCreate(struct TypeTable* TYPE,int NODE,char* NAME,int VALUE,struct Tnode *ArgList,
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
	temp -> Ptr1 = Ptr1;
	temp -> Ptr2 = Ptr2;
	temp -> Ptr3 = Ptr3;
	return temp;
}


