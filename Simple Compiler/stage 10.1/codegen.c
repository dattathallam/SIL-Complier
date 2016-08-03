FILE *intermediate;
int res,counter = -1,label = -1,temporary = 0,offset= 0 ,offset1 = 0,Loffset = 0,isamp = 0,i,j;
struct Lsymbol* Ltemp;
int tree_iter = 0,flditer = 0;
struct Gsymbol *Gtemp;
struct ArgStruct *Argtemp,*Arg_callee;
struct FieldList *fldtemp1,*fldtemp2;

// void intermediate_codegen(struct Tnode *abstree)
// {
// 	intermediate = fopen("assemblycode.asm","w+");
// 	if(intermediate == NULL)
// 	{
// 		printf("Unable to locate file\n");
// 		exit(1);
// 	}
// 	fprintf(intermediate, "START\n");
// 	fprintf(intermediate, "MOV SP 1000\n");	
// 	res = codegen(abstree);
// 	fprintf(intermediate, "HALT\n");
// 	fclose(intermediate);
// }
int getlabel()
{
	return ++label;
}
void freereg()
{
	if(counter >= 0)
		counter--;
}
void freeallreg()
{
	counter = -1;
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
	int number,a,r1,r2,r3,l1,l2,i,status = 0;
	struct  Tnode *temp ;
	struct Tnode *Ttemp;
	if(intermediate == NULL)
	{
		printf("Error while generating assemblycode\n");
		exit(1);
	}

	
	if(root -> NODE == NODE_EXPR )
	{
		tree_iter = 0;
		Arg_callee = root -> Ptr3;
		Argtemp = Arg_callee;
		while(Argtemp != NULL)
		{
			++tree_iter;
			// printf("%d : %s\n",tree_iter,Argtemp -> NAME );
			Argtemp = Argtemp -> NEXT;
		}
		Ttemp = root;
		while( tree_iter != 1 )
		{
			// printf("executed\n");		
			if(Ttemp -> Ptr1 -> NODE == NODE_ID)
			{
				Argtemp = Arg_callee;
				for (i = 1 ; i < tree_iter; i++)
				{
					Argtemp = Argtemp -> NEXT;
				}
				if(Argtemp -> TYPE == TypeLookup("amp_integer") || Argtemp -> TYPE == TypeLookup("amp_boolean") )
					isamp = 1;
			}
			a = codegen(Ttemp -> Ptr1);
			// printf("IN HERE 1 : %s \n",Ttemp -> Ptr1 -> NAME );
			fprintf(intermediate, "PUSH R%d\n", a);
			freereg();	
			Ttemp =  Ttemp -> Ptr2;
			// printf("executed\n");		
			tree_iter--;
		}
			// printf("executed\n");		
			if(Ttemp -> NODE == NODE_ID)
			{
				Argtemp = Arg_callee;
				for (i = 1 ; i < tree_iter; i++)
				{
					Argtemp = Argtemp -> NEXT;
				}
				if(Argtemp -> TYPE == TypeLookup("amp_integer") || Argtemp -> TYPE == TypeLookup("amp_boolean") )
					isamp = 1;
			}
			a = codegen(Ttemp);
			// printf("IN HERE 1 : %s \n",Ttemp -> NAME );
			fprintf(intermediate, "PUSH R%d\n", a);
			freereg();	
			// printf("executed\n");		

	}
	else if(root -> NODE == DEFAULT)
	{
		codegen(root -> Ptr1);
		codegen(root -> Ptr2);
	}
	else
	{
	    temp = root;

		switch(temp -> NODE)
		{
			case NODE_T   :
								/*printf("---T---");*/
								r1 = getreg();
								fprintf(intermediate, "MOV R%d , %d\n",r1,temp -> VALUE);
								// return temp -> VALUE;
								return r1;
								break;
			case NODE_F   :
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
			case NODE_NEQ  :
								/*printf("---NEQ---");*/
								r1 = codegen(temp -> Ptr1);
								r2 = codegen(temp -> Ptr2);
								fprintf(intermediate, "NE R%d , R%d\n",r1,r2);
								freereg();
								return r1;
								break;
			case NODE_AND  :
								r1 = codegen(temp -> Ptr1);
								r2 = getreg();
								fprintf(intermediate,"MOV R%d, 1\n",r2);
								l1 = getlabel();
								fprintf(intermediate, "JZ R%d, L%d\n",r1,l1);
								r3 = codegen(temp -> Ptr2);
								fprintf(intermediate, "MOV R%d, R%d\n",r2,r3);
								freereg();
								fprintf(intermediate, "L%d:\n",l1);
								fprintf(intermediate, "MUL R%d, R%d\n",r1,r2);
								freereg();
								return r1;
								break;
            case NODE_OR  :
								r1 = codegen(temp -> Ptr1);
								r2 = getreg();
								fprintf(intermediate,"MOV R%d, 1\n",r2);
								l1 = getlabel();
								fprintf(intermediate, "JNZ R%d, L%d\n",r1,l1);
								r3 = codegen(temp -> Ptr2);
								fprintf(intermediate, "MOV R%d, R%d\n",r2,r3);
								freereg();
								fprintf(intermediate, "L%d:\n",l1);
								fprintf(intermediate, "ADD R%d, R%d\n",r1,r2);
								freereg();
								return r1;
								break;
			case NODE_NOT  :
								r1 = codegen(temp -> Ptr2);
								l1 = getlabel();
								fprintf(intermediate, "JNZ R%d, L%d\n",r1,l1);
								fprintf(intermediate, "MOV R%d, 1\n",r1);
								l2 = getlabel();
								fprintf(intermediate, "JMP L%d\n",l2);
								fprintf(intermediate, "L%d:\n",l1);
								fprintf(intermediate, "MOV R%d, 0\n",r1);										
								fprintf(intermediate, "L%d:\n",l2);
								return r1;
			case NODE_ID   :
								// printf("---ID---\n");
								// return *(temp -> Gentry -> BINDING);
								r1 = getreg();
								Ltemp = Llookup(temp -> NAME);
								if(Ltemp != NULL)
								{
									Ltemp = Lhead;
									Loffset = 0;
									while(strcmp(temp -> NAME , Ltemp -> NAME) != 0)
									{
										Loffset = Loffset + 1;
										Ltemp = Ltemp -> NEXT;
									}
									
									r2 = getreg();
									fprintf(intermediate, "MOV R%d,BP\n",r2);
									fprintf(intermediate, "MOV R%d,%d\n",r1,Loffset+1);
									fprintf(intermediate, "ADD R%d,R%d\n",r2,r1);
									if(isamp)
									{
										fprintf(intermediate, "MOV R%d,R%d\n",r1,r2);
										isamp = 0; 
									}
									else
										fprintf(intermediate, "MOV R%d,[R%d]\n",r1,r2);
									freereg();

									// fprintf(intermediate, "MOV R%d,[%d]\n",r1,(Ltemp -> BINDING));
								}
								else
								{
									Argtemp = Arglookup(temp -> NAME);
	// BRING THIGS FROM STACK
									if(Argtemp != NULL)
									{
										Argtemp = Arghead;
										offset = 0;

										while(strcmp(Argtemp -> NAME,temp -> NAME) != 0)
										{
											offset = offset + 1;
											Argtemp = Argtemp -> NEXT;
										}
									
										r2 = getreg();
										fprintf(intermediate, "MOV R%d,BP\n",r2);
			 							r3 = getreg();
			 							fprintf(intermediate, "MOV R%d,2\n",r3);
			 							fprintf(intermediate, "SUB R%d,R%d\n",r2,r3);
			 							fprintf(intermediate, "MOV R%d,%d\n",r3,(offset+1));
										fprintf(intermediate, "SUB R%d,R%d\n",r2,r3);
										freereg();
										if(isamp && (Argtemp -> TYPE == TypeLookup("amp_integer") ||Argtemp -> TYPE == TypeLookup("amp_boolean")))
										{
											fprintf(intermediate, "MOV R%d,[R%d]\n",r1,r2); //BP-2-(offset+1)
											isamp = 0;
										}
										else
										{
											fprintf(intermediate, "MOV R%d,[R%d]\n",r1,r2); //BP-2-(offset+1)
											if(Argtemp -> TYPE == TypeLookup("amp_integer") ||Argtemp -> TYPE == TypeLookup("amp_boolean") )
											{
												fprintf(intermediate, "MOV R%d,[R%d]\n",r1,r1); 
											}
										}
										
										freereg();
									}
									else
									{
										if(isamp)
										{
											fprintf(intermediate, "MOV R%d,%d\n",r1,(temp -> Gentry -> BINDING));
											isamp = 0;
										}
										else
											fprintf(intermediate, "MOV R%d,[%d]\n",r1,(temp -> Gentry -> BINDING));
									}
								}
								// fprintf(intermediate, "OUT R%d\n",r1 );
								return r1;
								break;

			case NODE_FIELD :		
								r1 = getreg();
								Ltemp = Llookup(temp -> NAME);
								if(Ltemp != NULL)
								{
									Ltemp = Lhead;
									Loffset = 0;
									while(strcmp(temp -> NAME , Ltemp -> NAME) != 0)
									{
										Loffset = Loffset + 1;
										Ltemp = Ltemp -> NEXT;
									}
									
									r2 = getreg();
									fprintf(intermediate, "MOV R%d,BP\n",r2);
									fprintf(intermediate, "MOV R%d,%d\n",r1,Loffset+1);
									fprintf(intermediate, "ADD R%d,R%d\n",r2,r1);
									fprintf(intermediate, "MOV R%d,[R%d]\n",r1,r2);
									freereg();

									fldtemp2 = fldtemp1 = Ltemp -> TYPE -> fields;
									flditer = 0;
									while(temp -> Ptr2 != NULL)
									{
										flditer = 1;
										fldtemp2 = fldtemp1;
										while(fldtemp2 != NULL)
										{
											if(strcmp(fldtemp2 -> NAME,temp -> Ptr2 -> NAME) == 0)
											{
												r2 = getreg();
												fprintf(intermediate, "MOV R%d, %d\n",r2,flditer);
												fprintf(intermediate, "ADD R%d, R%d\n",r1,r2);
												fprintf(intermediate, "MOV R%d, [R%d]\n",r1,r1);
												break;
											}
											flditer++;
											fldtemp2 = fldtemp2 -> NEXT;
										}
										temp = temp -> Ptr2;
									}
								}
								else
								{
									Argtemp = Arglookup(temp -> NAME);
	// BRING THIGS FROM STACK
									if(Argtemp != NULL)
									{
										Argtemp = Arghead;
										offset = 0;

										while(strcmp(Argtemp -> NAME,temp -> NAME) != 0)
										{
											offset = offset + 1;
											Argtemp = Argtemp -> NEXT;
										}
									
										r2 = getreg();
										fprintf(intermediate, "MOV R%d,BP\n",r2);
			 							r3 = getreg();
			 							fprintf(intermediate, "MOV R%d,2\n",r3);
			 							fprintf(intermediate, "SUB R%d,R%d\n",r2,r3);
			 							fprintf(intermediate, "MOV R%d,%d\n",r3,(offset+1));
										fprintf(intermediate, "SUB R%d,R%d\n",r2,r3);
										freereg();

										fprintf(intermediate, "MOV R%d,[R%d]\n",r1,r2); //BP-2-(offset+1)
										freereg();

										fldtemp2 = fldtemp1 = Argtemp -> TYPE -> fields;
										flditer = 0;
										while(temp -> Ptr2 != NULL)
										{
											flditer = 1;
											fldtemp2 = fldtemp1;
											while(fldtemp2 != NULL)
											{
												if(strcmp(fldtemp2 -> NAME,temp -> Ptr2 -> NAME) == 0)
												{
													r2 = getreg();
													fprintf(intermediate, "MOV R%d, %d\n",r2,flditer);
													fprintf(intermediate, "ADD R%d, R%d\n",r1,r2);
													fprintf(intermediate, "MOV R%d, [R%d]\n",r1,r1);
													break;
												}
												flditer++;
												fldtemp2 = fldtemp2 -> NEXT;
											}
											temp = temp -> Ptr2;
										}
									}
									else
									{
										fprintf(intermediate, "MOV R%d,[%d]\n",r1,(temp -> Gentry -> BINDING));

										fldtemp2 = fldtemp1 = temp -> Gentry -> TYPE -> fields;
										flditer = 0;
										while(temp -> Ptr2 != NULL)
										{
											flditer = 1;
											fldtemp2 = fldtemp1;
											while(fldtemp2 != NULL)
											{
												if(strcmp(fldtemp2 -> NAME,temp -> Ptr2 -> NAME) == 0)
												{
													r2 = getreg();
													fprintf(intermediate, "MOV R%d, %d\n",r2,flditer);
													fprintf(intermediate, "ADD R%d, R%d\n",r1,r2);
													fprintf(intermediate, "MOV R%d, [R%d]\n",r1,r1);
													break;
												}
												flditer++;
												fldtemp2 = fldtemp2 -> NEXT;
											}
											temp = temp -> Ptr2;
										}

									}
								}

	                            return r1;
								break;
			case NODE_ARRAY :
									//printf("---ID ARR---/n");
									offset = codegen(temp -> Ptr2);
									r1 = getreg();
									fprintf(intermediate, "MOV R%d , %d\n",r1,(temp -> Ptr1 -> Gentry -> BINDING));
									// printf("1234\n");
									// r2 = getreg();
									// fprintf(intermediate, "MOV R%d , %d\n",r2,(temp -> Ptr1 -> Gentry -> SIZE));
									// fprintf(intermediate, "GT R%d, R%d\n",r2,offset);
									// l1 = getlabel();
									// fprintf(intermediate, "JNZ R%d, L%d\n",r2,l1);
									// freereg();
									// fprintf(intermediate, "HALT\n");
									// fprintf(intermediate, "L%d:\n",l1);
									// printf("REACHED\n");
									fprintf(intermediate, "ADD R%d , R%d\n",r1,offset);
									fprintf(intermediate, "MOV R%d , [R%d]\n",offset,r1);
									freereg();
									// fprintf(intermediate,"OUT R%d\n",offset);
									return offset;
									break;

			case NODE_NUM :
									// printf("NODE_NUM is %d\n",(root -> VALUE));
									// return (root -> VALUE); 
									r1 = getreg();
									fprintf(intermediate, "MOV R%d , %d\n",r1,(root -> VALUE));
									// fprintf(intermediate, "OUT %d\n",(root -> VALUE) );
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
			case NODE_DIV :
 									/*printf("---DIV---");*/
									// return (Evaluate(temp -> Ptr1) / Evaluate(temp -> Ptr2));
									r1 = codegen(temp -> Ptr1);
									r2 = codegen(temp -> Ptr2);
									l1 = getlabel();
									fprintf(intermediate, "JZ R%d, L%d\n",r2,l1);
									fprintf(intermediate, "DIV R%d ,R%d\n",r1,r2);
									freereg();
									fprintf(intermediate, "JMP L%d\n",l2);
									fprintf(intermediate, "L%d:\n",l1);
									fprintf(intermediate, "HALT\n");
									fprintf(intermediate, "L%d:\n",l2);
									
									return r1;
									break;
			case NODE_MOD :
 									/*printf("---MOD---");*/
									// return (Evaluate(temp -> Ptr1) % Evaluate(temp -> Ptr2));
									r1 = codegen(temp -> Ptr1);
									r2 = codegen(temp -> Ptr2);
									fprintf(intermediate, "MOD R%d ,R%d\n",r1,r2);
									freereg();
									return r1;
									break;
			case NODE_ASGN :
									// printf("---ASGN---");
									number = codegen(temp -> Ptr2);
									// *(temp -> Ptr1 -> Gentry -> BINDING) = number; ///// brought from ID
									//r1 = getreg();
									Ltemp = Llookup(temp -> Ptr1 -> NAME);
									if(Ltemp != NULL)
									{
										Ltemp = Lhead;
										Loffset = 0;

										while(strcmp(temp -> Ptr1 -> NAME , Ltemp -> NAME) != 0)
										{
											Loffset = Loffset + 1;
											Ltemp = Ltemp -> NEXT;
										}
										r1 = getreg();
										r2 = getreg();
										fprintf(intermediate, "MOV R%d,BP\n",r2);
										fprintf(intermediate, "MOV R%d,%d\n",r1,Loffset+1);
										fprintf(intermediate, "ADD R%d,R%d\n",r2,r1);
										// fprintf(intermediate, "MOV R%d,[%d]\n",r1,r2);
										
										fprintf(intermediate, "MOV [R%d],R%d\n",r2,number);
										freereg();
										freereg();
									}
									else
									{
										Argtemp = Arglookup(temp -> Ptr1 -> NAME);
		// BRING THIGS FROM STACK
										if(Argtemp != NULL)
										{
											Argtemp = Arghead;
											offset = 0;

											while(strcmp(Argtemp -> NAME,temp -> Ptr1 -> NAME) != 0)
											{
												offset = offset + 1;
												Argtemp = Argtemp -> NEXT;
											}

											r1 = getreg();
											fprintf(intermediate, "MOV R%d,BP\n",r1);
				 							r2 = getreg();
				 							fprintf(intermediate, "MOV R%d,2\n",r2);
				 							fprintf(intermediate, "SUB R%d,R%d\n",r1,r2);
				 							
				 							fprintf(intermediate, "MOV R%d,%d\n",r2,(offset+1));
											fprintf(intermediate, "SUB R%d,R%d\n",r1,r2);
											freereg();

											if(Argtemp -> TYPE == TypeLookup("amp_integer") ||Argtemp -> TYPE == TypeLookup("amp_boolean") )
											{
												r2 = getreg();
												fprintf(intermediate, "MOV R%d,[R%d]\n",r2,r1); //BP-2-(offset+1)
												fprintf(intermediate, "MOV [R%d],R%d\n",r2,number); //BP-2-(offset+1)
												freereg();
											}
											else
											{
												fprintf(intermediate, "MOV [R%d],R%d\n",r1,number); //BP-2-(offset+1)
											}
											freereg();
										}
										else
										{
											fprintf(intermediate, "MOV [%d], R%d\n",(temp -> Ptr1 -> Gentry -> BINDING),number);
										}
									}
									
									freereg();
									break;
			case NODE_ARRAY_ASGN :
										offset1 = codegen(temp -> Ptr2);
										// fprintf(intermediate, "OUT R%d\n",offset1);
										// printf("QWER\n");
										// r2 = getreg();
										// fprintf(intermediate, "MOV R%d , %d\n",r2,(temp -> Ptr1 -> Gentry -> SIZE));
										// fprintf(intermediate, "GT R%d, R%d\n",r2,offset);
										// l1 = getlabel();
										// fprintf(intermediate, "JNZ R%d, L%d\n",r2,l1);
										// freereg();
										// fprintf(intermediate, "HALT\n");
										// fprintf(intermediate, "L%d:\n",l1);
										// // freereg();
										
										r1 = getreg();
										fprintf(intermediate, "MOV R%d , %d\n",r1,(temp -> Ptr1 -> Gentry -> BINDING));
										fprintf(intermediate, "ADD R%d , R%d\n",offset1,r1);
										freereg();
										r1 = codegen(temp -> Ptr3);

										// fprintf(intermediate, "OUT R%d\n",r1);
										 // printf("r1 : %d\n",r1 );
										 // printf("offset : %d\n",offset1 );
										fprintf(intermediate, "MOV [R%d] , R%d\n",offset1,r1);
										freereg();
										freereg();
										// printf("ALSO HERE\n");
										break;
			case NODE_READ :
									/*printf("---READ---");*/
									r1 = getreg();
									fprintf(intermediate, "IN R%d\n",r1);
									Ltemp = Llookup(temp -> Ptr2 -> NAME);
									if(Ltemp != NULL)
									{
										Ltemp = Lhead;
										Loffset = 0;

										while(strcmp(temp -> Ptr2 -> NAME , Ltemp -> NAME) != 0)
										{
											Loffset = Loffset + 1;
											Ltemp = Ltemp -> NEXT;
										}
										r2 = getreg();
										r3 = getreg();
										fprintf(intermediate, "MOV R%d,BP\n",r3);
										fprintf(intermediate, "MOV R%d,%d\n",r2,Loffset+1);
										fprintf(intermediate, "ADD R%d,R%d\n",r3,r2);
										fprintf(intermediate, "MOV [R%d],R%d\n",r3,r1);
										freereg();
										freereg();
									}
									
									else
									{
										Argtemp = Arglookup(temp -> Ptr2 -> NAME);

										if(Argtemp != NULL)
										{
											Argtemp = Arghead;
											offset = 0;

											while(strcmp(Argtemp -> NAME,temp -> Ptr2 -> NAME) != 0)
											{
												offset = offset + 1;
												Argtemp = Argtemp -> NEXT;
											}

											r2 = getreg();
											fprintf(intermediate, "MOV R%d,BP\n",r2);
				 							r3 = getreg();
				 							fprintf(intermediate, "MOV R%d,2\n",r3);
				 							fprintf(intermediate, "SUB R%d,R%d\n",r2,r3);
				 							fprintf(intermediate, "MOV R%d,%d\n",r3,(offset+1));
											fprintf(intermediate, "SUB R%d,R%d\n",r2,r3);
											freereg();

											if(Argtemp -> TYPE == TypeLookup("amp_integer") ||Argtemp -> TYPE == TypeLookup("amp_boolean") )
											{
												r3 = getreg();
												fprintf(intermediate, "MOV R%d,[R%d]\n",r3,r2); //BP-2-(offset+1)
												fprintf(intermediate, "MOV [R%d],R%d\n",r3,r1); //BP-2-(offset+1)
												freereg();
											}
											else
											{
												fprintf(intermediate, "MOV [R%d],R%d\n",r2,r1); //BP-2-(offset+1)
											}
											freereg();
										}
										else
										{
											fprintf(intermediate, "MOV [%d],R%d\n",(temp -> Ptr2 -> Gentry -> BINDING),r1);
										}
									}
									freereg();
									break;
			case NODE_ARRAY_READ :
									offset = codegen(temp -> Ptr3);
		    						r1 = getreg();
									fprintf(intermediate, "MOV R%d , %d\n",r1,(temp -> Ptr2 -> Gentry -> BINDING));
									
									r2 = getreg();
									fprintf(intermediate, "MOV R%d , %d\n",r2,(temp -> Ptr2 -> Gentry -> SIZE));
									fprintf(intermediate, "GT R%d, R%d\n",r2,offset);
									l1 = getlabel();
									fprintf(intermediate, "JNZ R%d, L%d\n",r2,l1);
									// freereg();
									fprintf(intermediate, "HALT\n");
									fprintf(intermediate, "L%d:\n",l1);
									
									freereg();
									fprintf(intermediate, "ADD R%d , R%d\n",offset,r1);
									freereg();
		    						r1 = getreg();
									fprintf(intermediate, "IN R%d\n",r1);
									fprintf(intermediate, "MOV [R%d], R%d\n",offset,r1);
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
									freereg();
									number = codegen(temp -> Ptr2);
									fprintf(intermediate, "JMP L%d\n",l2);
									fprintf(intermediate, "L%d:\n",l1);
									freereg();
									number = codegen(temp -> Ptr3);
									fprintf(intermediate, "L%d:\n",l2);
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

		 	case NODE_FUNC :
		 							// printf("counter : %d\n",counter);
		 							for(i = 0; i <= counter; i++)
		 								fprintf(intermediate, "PUSH R%d\n",i);
		 							status = counter;

		 							freeallreg();

		 							if(temp -> Ptr2 != NULL)
		 							{
		 								// fprintf(intermediate,"IN HERE\n");
		 								// printf("func name : %s \t tree_iter : %d\n",temp -> NAME,tree_iter);
		 								codegen(temp -> Ptr2); //more than 1 argument
		 							}
		 							else
		 							{
		 								
		 								if(temp -> Ptr3 -> NODE == NODE_ID)
										{
											// Argtemp = Arg_callee;
											Argtemp = temp -> Ptr3 -> Ptr3;
									
											if(Argtemp -> TYPE == TypeLookup("amp_integer") || Argtemp -> TYPE == TypeLookup("amp_boolean") )
												isamp = 1;
										}

		 								a = codegen(temp -> Ptr3);
		 								fprintf(intermediate, "PUSH R%d\n",a);
		 								freereg();
		 							}

		 							fprintf(intermediate, "PUSH R0\n"); //space for return value

		 							Gtemp = Glookup(temp -> NAME);
		 							fprintf(intermediate, "CALL F%d\n",Gtemp -> BINDING);

		 							r1 = getreg();
                                    fprintf(intermediate, "POP R%d\n",r1);	// for return value
                                    freereg();

                                    r2 = getreg();

                                    Argtemp = Gtemp -> Arglist;
                                    temporary = 0;

                                    while(Argtemp != NULL)
                                    {
                                    	temporary = temporary + 1;
		 								fprintf(intermediate, "POP R%d\n",r2);
		 								Argtemp = Argtemp -> NEXT;
                                    }

                                    freereg();

                                    for(i = status; i >= 0; i--)
                                    {
                                    	temporary = temporary + 1;
		 								fprintf(intermediate, "POP R%d\n",i);
                                    }
		 							counter = status;
		 							r1 = getreg();
		 							r2 = getreg();
		 							fprintf(intermediate, "MOV R%d, %d\n",r1,(temporary+1));
		 							fprintf(intermediate, "MOV R%d, SP\n",r2);
		 							
		 							fprintf(intermediate, "ADD R%d, R%d\n",r2,r1);
		 							fprintf(intermediate, "MOV R%d, [R%d]\n",r1,r2);
		 							freereg();

		 							return r1;

		 							break;



		 	case NODE_RET : 
	 								res = codegen(temp -> Ptr2);
		 							r1 = getreg();
		 							fprintf(intermediate, "MOV R%d,BP\n",r1);
		 							r2 = getreg();
		 							fprintf(intermediate, "MOV R%d,2\n",r2);
		 							fprintf(intermediate, "SUB R%d,R%d\n",r1,r2);
		 							freereg();
		 							fprintf(intermediate, "MOV [R%d],R%d\n",r1,res);
		 							freereg();
		 							freereg();
		 							Ltemp = Lhead;
		 							while(Ltemp != NULL)
		 							{                                                                
                                        fprintf(intermediate, "POP R0\n");
                                        Ltemp = Ltemp -> NEXT;
                                    }

		 							fprintf(intermediate, "MOV BP,[SP]\n");
		 							fprintf(intermediate, "POP R0\n");
                                    fprintf(intermediate, "RET\n");

                                    break;

            case NODE_ALLOC :	
            						for(i = 0; i <= counter; i++)
		 								fprintf(intermediate, "PUSH R%d\n",i);
		 							status = counter;

		 							freeallreg();
		 							fprintf(intermediate, "PUSH R0\n");
		 							
		 							fprintf(intermediate, "CALL ALLOC\n");
		 							
		 							fprintf(intermediate, "POP R0\n");
									
									temporary = 0;
									for(i = status; i >= 0; i--)
                                    {
                                    	temporary = temporary + 1;
		 								fprintf(intermediate, "POP R%d\n",i);
                                    }
		 							
		 							counter = status;
		 							
		 							r1 = getreg();
		 							r2 = getreg();
		 							fprintf(intermediate, "MOV R%d, %d\n",r1,(temporary+1));
		 							fprintf(intermediate, "MOV R%d, SP\n",r2);
		 							
		 							fprintf(intermediate, "ADD R%d, R%d\n",r2,r1);
		 							fprintf(intermediate, "MOV R%d, [R%d]\n",r1,r2);
		 							freereg();

		 							return r1;

		 	case NODE_FREE :
		 							r1 = getreg();
		 							r1 = codegen(temp -> Ptr2);
		 							for(i = 0; i <= counter; i++)
		 								fprintf(intermediate, "PUSH R%d\n",i);
		 							status = counter;

		 							freeallreg();
		 							fprintf(intermediate, "PUSH R%d\n",r1);

		 							fprintf(intermediate, "CALL FREE\n");
		 							
		 							fprintf(intermediate, "POP R0\n"); // for argument
									
									for(i = status; i >= 0; i--)
                                    {
		 								fprintf(intermediate, "POP R%d\n",i);
                                    }
		 							
		 							counter = status;

		 							return;
			default:
					printf("NODETYPE is %d\n",temp -> NODE);
					printf("Error : Unknown Node Type\n");
					exit(1);	
		}														
	}
	return 0;
}
