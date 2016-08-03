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
	temp -> Ptr1 = Ptr1;
	temp -> Ptr2 = Ptr2;
	temp -> Ptr3 = Ptr3;
	return temp;
}

int Evaluate(struct Tnode *root)
{
	// printf("Evaluate %d\n",root -> NODE);
	int number,a;
	struct  Tnode *temp ;
	if(root -> NODE == DEFAULT)
	{
		Evaluate(root -> Ptr1);
		Evaluate(root -> Ptr2);
	}
	else
	{
	    temp=root;
		switch(temp -> TYPE)
		{
			case TYPE_BOOL:
					switch(temp -> NODE)
					{
						case NODE_T 		  :
											/*printf("---T---");*/
											return temp -> VALUE;
											break;
						case NODE_F 		  :
											/*printf("---F---");*/
											return temp -> VALUE;
											break;					
						case NODE_LE  :
											/*printf("---LE---");*/
											if(Evaluate(temp -> Ptr1) <= Evaluate(temp -> Ptr2))
											{
												return TRUE;
											}
											else
												return FALSE;
											break;
						case NODE_GE  :
											/*printf("---GE---");*/
											if(Evaluate(temp -> Ptr1) >= Evaluate(temp -> Ptr2))
											{
												return TRUE;
											}
											else
												return FALSE;
											break;
						case NODE_LT  :
											// printf("---LT---");
											if(Evaluate(temp -> Ptr1) < Evaluate(temp -> Ptr2))
											{
												return TRUE;
											}
											else
												return FALSE;
											break;
						case NODE_GT  :
											/*printf("---GT---");*/
											if(Evaluate(temp -> Ptr1) > Evaluate(temp -> Ptr2))
											{
												return TRUE;
											}
											else
												return FALSE;
											break;
						case NODE_DEQ  :
											/*printf("---DEQ---");*/
											if(Evaluate(temp -> Ptr1) == Evaluate(temp -> Ptr2))
											{
												return TRUE;
											}
											else
												return FALSE;
											break;
						case NODE_ID   :
											// printf("---ID---\n");
											return *(temp -> Gentry -> BINDING);
											break;
					}
					break;
				
			case TYPE_INT:
					switch(temp -> NODE)
					{
						case NODE_NUM :
												// printf("NODE_NUM is %d\n",(root -> VALUE));
												return (root -> VALUE); 
												break;
						case NODE_PLUS :
												// printf("---PLUS---");
							 					return (Evaluate(temp -> Ptr1) + Evaluate(temp -> Ptr2));
												break;
			 			case NODE_MINUS :
			 									/*printf("---MINUS---");*/
												return (Evaluate(temp -> Ptr1) - Evaluate(temp -> Ptr2));
												break;
			 			case NODE_MUL :
			 									/*printf("---MUL---");*/
												return (Evaluate(temp -> Ptr1) * Evaluate(temp -> Ptr2));
												break;
						case NODE_ID  :
												
												// printf("NODE_ID\n");
												return *(temp -> Gentry -> BINDING);
												// if(value[*(root -> NAME)- 'a'] == NULL)
												// {
												// 	printf("un initialized variable\n");
												// 	exit(1);
												// }
												// return *value[*(root -> NAME)- 'a'];
												break;
						
					}
					break;

			case TYPE_VOID:
					switch(temp -> NODE)
					{
						case NODE_ASGN :
												// printf("---ASGN---");
												number = Evaluate(temp -> Ptr2);
												*(temp -> Ptr1 -> Gentry -> BINDING) = number;
											 	//if(value[*(temp -> Ptr1 -> NAME) -'a'] == NULL)
												// {
												// 	value[*(temp -> Ptr1 -> NAME) - 'a'] = malloc(sizeof(int));
												// }
												// *value[*(temp -> Ptr1 -> NAME)- 'a'] = number;
												/*printf("%c is %d\n",*(temp -> Ptr1 -> NAME),*value[*(temp -> Ptr1 -> NAME)- 'a']);*/
												
												break;
						case NODE_READ :
												/*printf("---READ---");*/
												printf("Enter a number : ");
												scanf("%d",(temp -> Ptr2 -> Gentry -> BINDING));
												// if(value[*(temp -> Ptr2 -> NAME)-'a'] == NULL)
												// {
												// 	value[*(temp -> Ptr2 -> NAME) - 'a'] = malloc(sizeof(int));
												// }
												/*printf("%c is %d\n",*(temp -> Ptr2 -> NAME),*value[*(temp -> Ptr2 -> NAME)- 'a']);*/
												break;
						case NODE_WRITE :
												// printf("---WRITE---");
												number = Evaluate(temp -> Ptr2);
												printf("%d\n",number);
												break;
						case NODE_IF  :
												/*printf("---IF---");*/
												number = Evaluate(temp -> Ptr1);
												if(number == TRUE)
												{
													number = Evaluate(temp -> Ptr2);
												}
												break;
						case NODE_IF_ELSE:
												/*printf("---IF_ELSE---");*/
												number = Evaluate(temp -> Ptr1);
												if(number == TRUE)
												{
													number = Evaluate(temp -> Ptr2);
												}
												else
													number = Evaluate(temp -> Ptr3);
												break;
					 	case NODE_WHILE :
					 							// printf("---WHILE----");
					 							number = Evaluate(temp -> Ptr1);
					 							printf("%d\n",number);
					 							while(number == TRUE)
					 							{
					 								number = Evaluate(temp -> Ptr2);
					 								number = Evaluate(temp -> Ptr1);
					 							}
					 							break;
					}
					break;
				
				default:
						printf("NODETYPE is %d\n",temp -> NODE);
						printf("Error : Unknown Node Type\n");
						exit(1);	
		}														
	}
		
	return 0;
}