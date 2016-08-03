struct Gsymbol *Glookup(char * NAME)
{
    struct Gsymbol *temp;
    temp  = Ghead;

    while(temp != NULL && (strcmp(temp -> NAME,NAME) != 0))
    {
    	temp = temp -> NEXT;
    }
	return temp;
}

void Ginstall(char *NAME,int TYPE,int SIZE,struct ArgStruct *Arglist)
{
	struct Gsymbol *temp;

    temp = Glookup(NAME);

    if(temp != NULL)
    {
    	yyerror("Variable re-initialized");
    	printf("\"%s\"\n",NAME);
    	exit(1);
    }

    temp = (struct Gsymbol *) malloc(sizeof(struct Gsymbol));
    temp -> NAME = (char *) malloc(sizeof(NAME));
    strcpy(temp -> NAME , NAME);
    temp -> TYPE = TYPE;
    temp -> SIZE = SIZE;
    temp -> Arglist = Arglist;
    temp -> NEXT = NULL;
/*
    switch(temp -> TYPE)
    {
    	case SYMBOL_INTEGER:
    			temp -> BINDING = (int *) malloc(temp -> SIZE *sizeof(int));
    			break;
    	case SYMBOL_BOOLEAN:
    			temp -> BINDING = (int *) malloc(temp -> SIZE *sizeof(int));
    			break;
        case SYMBOL_ARRAY_BOOLEAN:
                temp -> BINDING = (int *) malloc(temp -> SIZE *sizeof(int));
                break;
        case SYMBOL_ARRAY_INT :
                temp -> BINDING = (int *) malloc(temp -> SIZE *sizeof(int));
                break;
    	default:
   				printf("Unknown datatype.\n");
    }
    memset(temp -> BINDING,0,temp -> SIZE );

*/
    if(temp -> SIZE == -1)
    {
        temp -> BINDING = fbind;
        fbind++;
    }

    else
    {
        temp -> BINDING = totalCount;
        totalCount = totalCount + temp -> SIZE;        
    }


    if(Ghead != NULL)
    {
    	Gtail -> NEXT = temp;
        Gtail = temp; 
    }
    else
    {
    	Ghead = temp;
    	Gtail = temp;
    }
    return;
}

struct Lsymbol *Llookup(char *NAME)
{
    struct Lsymbol *temp;
    temp  = Lhead;
    while(temp != NULL && (strcmp(temp -> NAME,NAME) != 0))
    {
    	temp = temp -> NEXT;
    }
	return temp;
}

void Linstall(char *NAME,int TYPE)
{
	struct Lsymbol *temp;
    temp = (struct Lsymbol *) malloc(sizeof(struct Lsymbol));
    temp -> NAME = (char *) malloc(sizeof(NAME));
    strcpy(temp -> NAME , NAME);
    temp -> TYPE = TYPE;
    temp -> NEXT = NULL;
   
   /* switch(temp -> TYPE)
    {
    	case SYMBOL_INTEGER:
    			temp -> BINDING = (int *) malloc(sizeof(int));
    			break;
    	case SYMBOL_BOOLEAN:
    			temp -> BINDING = (int *) malloc(sizeof(int));
    			break;
    	default:
   				printf("Unknown datatype.\n");
    }*/
   
    temp -> BINDING = totalCount;
    totalCount = totalCount + 1;        

    if(Lhead != NULL)
    {
    	Ltail -> NEXT = temp;
        Ltail = temp; 
    }
    else
    {
    	Lhead = temp;
    	Ltail = temp;
    }
    return;
}

struct ArgStruct* Arglookup(char* NAME)
{
   struct ArgStruct *temp;
    temp  = Arghead;
    while(temp != NULL && (strcmp(temp -> NAME,NAME) != 0))
    {
        temp = temp -> NEXT;
    }
    return temp;
}

void ArgInstall(char* NAME,int TYPE)
{
    struct ArgStruct *temp;
    temp = (struct ArgStruct *) malloc(sizeof(struct ArgStruct));
    temp -> NAME = (char *) malloc(sizeof(NAME));
    strcpy(temp -> NAME , NAME);
    temp -> TYPE = TYPE;
    temp -> NEXT = NULL;

    if(Arghead == NULL)
    {
        Arghead = temp;
        Argtail = temp;
    }

    else
    {
        Argtail -> NEXT = temp;
        Argtail = Argtail -> NEXT;
    }
    
     
    return;
}


void printSymbolTable()
{
    struct Gsymbol *temp;
    temp = Ghead;
    while(temp != NULL)
    {
        printf("%s----%d-----%d\n",temp -> NAME,temp -> TYPE,temp -> BINDING);
        temp = temp -> NEXT;
    }
}
