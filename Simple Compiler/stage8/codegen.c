FILE *intermediate;
int counter = -1,label = -1;
void intermediate_codegen(struct Tnode *abstree)
{
	intermediate = fopen("assemblycode","w+");
	if(intermediate == NULL)
	{
		printf("Unable to locate file\n");
		exit(1);
	}
	fprintf(intermediate, "START\n");
	fprintf(intermediate, "MOV SP 1000\n");	
	codegen(abstree);
	fprintf(intermediate, "HALT\n");
	fclose(intermediate);
}
int getlabel()
{
	return ++label;
}
void freereg()
{
	if(counter >= 0)
		counter--;
}
int getreg()
{
	if(counter < 8)
		return ++counter;
	else
	{
		printf("Running out of registers\n");
		exit(1);
	}
}
int codegen(struct Tnode* root)
{
		// printf("Evaluate %d\n",root -> NODE);
	int number,a,offset,r1,r2,l1,l2;
	struct  Tnode *temp ;
	if(intermediate == NULL)
	{
		printf("Error while generating assemblycode\n");
		exit(1);
	}
	if(root -> NODE == DEFAULT)
	{
		codegen(root -> Ptr1);
		codegen(root -> Ptr2);
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
										r1 = getreg();
										fprintf(intermediate, "MOV R%d , %d\n",r1,temp -> VALUE);
										// return temp -> VALUE;
										return r1;
										break;
					case NODE_F 		  :
										/*printf("---F---");*/
										r1 = getreg();
										fprintf(intermediate, "MOV R%d , %d\n",r1,temp -> VALUE);
										// return temp -> VALUE;
										return r1;
										break;					
					case NODE_LE  :
										/*printf("---LE---");*/
										r1 = codegen(temp -> Ptr1);
										r2 = codegen(temp -> Ptr2);
										fprintf(intermediate, "LE R%d , R%d\n",r1,r2);
										freereg();
										return r1;		
										break;
					case NODE_GE  :
										/*printf("---GE---");*/
										r1 = codegen(temp -> Ptr1);
										r2 = codegen(temp -> Ptr2);
										fprintf(intermediate, "GE R%d , R%d\n",r1,r2);
										freereg();
										return r1;
										break;
					case NODE_LT  :
										// printf("---LT---");
										r1 = codegen(temp -> Ptr1);
										r2 = codegen(temp -> Ptr2);
										fprintf(intermediate, "LT R%d , R%d\n",r1,r2);
										freereg();
										return r1;
										break;
					case NODE_GT  :
										/*printf("---GT---");*/
										r1 = codegen(temp -> Ptr1);
										r2 = codegen(temp -> Ptr2);
										fprintf(intermediate, "GT R%d , R%d\n",r1,r2);
										freereg();
										return r1;
										break;
					case NODE_DEQ  :
										/*printf("---DEQ---");*/
										r1 = codegen(temp -> Ptr1);
										r2 = codegen(temp -> Ptr2);
										fprintf(intermediate, "EQ R%d , R%d\n",r1,r2);
										freereg();
										return r1;
										break;
					case NODE_ID   :
										// printf("---ID---\n");
										// return *(temp -> Gentry -> BINDING);
										r1 = getreg();
										fprintf(intermediate, "MOV R%d , [%d]\n",r1,(temp -> Gentry -> BINDING));
										return r1;
										break;
					case NODE_ARRAY :
											//printf("---ID ARR---/n");
											offset = codegen(temp -> Ptr2);
											r1 = getreg();
											fprintf(intermediate, "MOV R%d , %d\n",r1,(temp -> Ptr1 -> Gentry -> BINDING));
											fprintf(intermediate, "ADD R%d , R%d\n",r1,offset);
											fprintf(intermediate, "MOV R%d , [R%d]\n",offset,r1);
											freereg();
											return offset;
											break;
				}
			break;
				
			case TYPE_INT:
				switch(temp -> NODE)
				{
					case NODE_NUM :
											// printf("NODE_NUM is %d\n",(root -> VALUE));
											// return (root -> VALUE); 
											r1 = getreg();
											fprintf(intermediate, "MOV R%d , %d\n",r1,(root -> VALUE));
											return r1;
											break;
					case NODE_PLUS :
											// printf("---PLUS---");
						 					// return (Evaluate(temp -> Ptr1) + Evaluate(temp -> Ptr2));
											r1 = codegen(temp -> Ptr1);
											r2 = codegen(temp -> Ptr2);
											fprintf(intermediate, "ADD R%d ,R%d\n",r1,r2);
											freereg();
											return r1;
											break;
		 			case NODE_MINUS :
		 									/*printf("---MINUS---");*/
											// return (Evaluate(temp -> Ptr1) - Evaluate(temp -> Ptr2));
		 									r1 = codegen(temp -> Ptr1);
											r2 = codegen(temp -> Ptr2);
											fprintf(intermediate, "SUB R%d ,R%d\n",r1,r2);
											freereg();
											return r1;
											break;
		 			case NODE_MUL :
		 									/*printf("---MUL---");*/
											// return (Evaluate(temp -> Ptr1) * Evaluate(temp -> Ptr2));
											r1 = codegen(temp -> Ptr1);
											r2 = codegen(temp -> Ptr2);
											fprintf(intermediate, "MUL R%d ,R%d\n",r1,r2);
											freereg();
											return r1;
											break;
					case NODE_ID  :
											
											// printf("NODE_ID\n");
											// return *(temp -> Gentry -> BINDING);
											r1 = getreg();
											fprintf(intermediate, "MOV R%d , [%d]\n",r1,(temp -> Gentry -> BINDING));
											return r1;
											break;
					case NODE_ARRAY :
											//printf("---ID ARR---/n");
											offset = codegen(temp -> Ptr2);
											r1 = getreg();
											fprintf(intermediate, "MOV R%d , %d\n",r1,(temp -> Ptr1 -> Gentry -> BINDING));
											fprintf(intermediate, "ADD R%d , R%d\n",r1,offset);
											fprintf(intermediate, "MOV R%d , [R%d]\n",offset,r1);
											freereg();
											return offset;
											break;
					
				}
			break;

			case TYPE_VOID:
				switch(temp -> NODE)
				{
					case NODE_ASGN :
											// printf("---ASGN---");
											number = codegen(temp -> Ptr2);
											// *(temp -> Ptr1 -> Gentry -> BINDING) = number;
											fprintf(intermediate, "MOV [%d], R%d\n",(temp -> Ptr1 -> Gentry -> BINDING),number);
											freereg();
											break;
					case NODE_ARRAY_ASGN :
												offset = codegen(temp -> Ptr2);
												r1 = getreg();
												fprintf(intermediate, "MOV R%d , %d\n",r1,(temp -> Ptr1 -> Gentry -> BINDING));
												fprintf(intermediate, "ADD R%d , R%d\n",offset,r1);
												freereg();
												r1 = codegen(temp -> Ptr3);
												fprintf(intermediate, "MOV [R%d] , R%d\n",offset,r1);
												freereg();
												freereg();
												break;
					case NODE_READ :
											/*printf("---READ---");*/
											r1 = getreg();
											fprintf(intermediate, "IN R%d\n",r1);
											fprintf(intermediate, "MOV [%d] , R%d \n",(temp -> Ptr2 -> Gentry -> BINDING),r1);
											freereg();
											break;
					case NODE_ARRAY_READ :
											offset = codegen(temp -> Ptr3);
				    						r1 = getreg();
											fprintf(intermediate, "MOV R%d , %d\n",r1,(temp -> Ptr2 -> Gentry -> BINDING));
											fprintf(intermediate, "ADD R%d , R%d\n",offset,r1);
											freereg();
				    						r1 = getreg();
											fprintf(intermediate, "IN R%d\n",r1);
											fprintf(intermediate, "MOV [R%d] R%d\n",offset,r1);
											freereg();
											freereg();
											break;
					case NODE_WRITE :
											// printf("---WRITE---");
											number = codegen(temp -> Ptr2);
											fprintf(intermediate, "OUT R%d\n",number);
											freereg();
											break;
					case NODE_IF  :
											/*printf("---IF---");*/
											l1 = getlabel();
											number = codegen(temp -> Ptr1);
											fprintf(intermediate, "JZ R%d , L%d\n",number,l1);
											number = codegen(temp -> Ptr2);
											fprintf(intermediate, "L%d:\n",l1);
											freereg();
											break;
					case NODE_IF_ELSE:
											/*printf("---IF_ELSE---");*/
											number = codegen(temp -> Ptr1);
											l1 = getlabel();
											l2 = getlabel();
											fprintf(intermediate, "JZ R%d , L%d\n",number,l1);
											number = codegen(temp -> Ptr2);
											fprintf(intermediate, "JMP L%d:\n",l2);
											fprintf(intermediate, "L%d:\n",l1);
											number = codegen(temp -> Ptr3);
											fprintf(intermediate, "L%d:\n",l2);
											freereg();
											break;
				 	case NODE_WHILE :
				 							// printf("---WHILE----");
				 							l1 = getlabel();
				 							l2 = getlabel();
				 							fprintf(intermediate, "L%d:\n",l1);
				 							number = codegen(temp -> Ptr1);
				 							fprintf(intermediate, "JZ R%d , L%d\n",number,l2);
				 							freereg();
											number = codegen(temp -> Ptr2);
				 							fprintf(intermediate, "JMP L%d\n",l1);
				 							fprintf(intermediate, "L%d:\n",l2);
				 							freereg();
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
