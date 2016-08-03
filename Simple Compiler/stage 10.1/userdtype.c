
void initialize()
{
	int i,j;
	i = 0;
	j = 16;
	while(j <= 255)
	{
		fprintf(intermediate, "MOV [%d], %d\n",i,j);
		i = j;
		j = j + 16;
	}
	fprintf(intermediate, "MOV [%d], %d\n",256,0);
	return;
}
void alloc() // put the value in BP - 2
{
	int r1,r2,r3;

	fprintf(intermediate, "ALLOC:\n");
	fprintf(intermediate, "PUSH BP\n");
	fprintf(intermediate, "MOV BP, SP\n");
	// r1 = getreg();
	fprintf(intermediate, "MOV R%d, [256]\n",0);
	// r2 = getreg();
	fprintf(intermediate, "MOV R%d, [R%d]\n",1,0);
	fprintf(intermediate, "MOV [%d], R%d\n",256,1);
	// r3 = getreg();
	fprintf(intermediate, "MOV R%d, BP\n",1);
	fprintf(intermediate, "MOV R%d, 2\n",2);
	fprintf(intermediate, "SUB R%d, R%d\n",1,2);
	fprintf(intermediate, "MOV [R%d], R%d\n",1,0);
	// freereg();
	// freereg();
	// freereg();
	fprintf(intermediate, "MOV BP, [SP]\n");
	fprintf(intermediate, "POP R0\n");
	fprintf(intermediate, "RET\n");
	return;
}
void freeheap() // get the argument from BP -3 
{
	int r1,r2;
	// r1 = getreg();
	// r2 = getreg();
	fprintf(intermediate, "FREE:\n");
	fprintf(intermediate, "PUSH BP\n");
	fprintf(intermediate, "MOV BP, SP\n");
	fprintf(intermediate, "MOV R%d, 2\n",0);
	fprintf(intermediate, "MOV R%d, BP\n",1);
	fprintf(intermediate, "SUB R%d, R%d\n",1,0 );
	fprintf(intermediate, "MOV R%d, [R%d]\n",0,1 );
	fprintf(intermediate, "MOV R%d, [256]\n",1);
	fprintf(intermediate, "MOV [%d], R%d\n",256,0);
	fprintf(intermediate, "MOV [R%d], R%d\n",0,1 );
	// freereg();
	// freereg();
	fprintf(intermediate, "MOV BP, [SP]\n");
	fprintf(intermediate, "POP R0\n");
	fprintf(intermediate, "RET\n");
	return;
}