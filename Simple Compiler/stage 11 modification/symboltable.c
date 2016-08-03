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

void Ginstall(char *NAME,struct TypeTable* TYPE,int SIZE,struct ArgStruct *Arglist)
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

void Linstall(char *NAME,struct TypeTable* TYPE)
{
	struct Lsymbol *temp;
    temp = (struct Lsymbol *) malloc(sizeof(struct Lsymbol));
    temp -> NAME = (char *) malloc(sizeof(NAME));
    strcpy(temp -> NAME , NAME);
    temp -> TYPE = TYPE;
    temp -> NEXT = NULL;
   
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

void ArgInstall(char* NAME,struct TypeTable* TYPE,int amp)
{
    struct ArgStruct *temp;
    temp = (struct ArgStruct *) malloc(sizeof(struct ArgStruct));
    temp -> NAME = (char *) malloc(sizeof(NAME));
    strcpy(temp -> NAME , NAME);
    temp -> TYPE = TYPE;
    temp -> amp = amp;
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

struct TypeTable* TypeLookup(char* NAME)
{
   struct TypeTable *temp;
    temp  = Typehead;
    // printf("REACHED WITH : %s \n",NAME);

    while(temp != NULL && (strcmp(temp -> NAME,NAME) != 0))
    {
        // printf("REACHED : %s \n",temp -> NAME);
        temp = temp -> NEXT;
    }

    return temp;
}

void TypeInstall(char* NAME,struct FieldList *fields)
{
    struct TypeTable *temp;
    temp = (struct TypeTable *) malloc(sizeof(struct TypeTable));
    temp -> NAME = (char *) malloc(sizeof(NAME));
    strcpy(temp -> NAME , NAME);
    temp -> fields = fields;
    temp -> NEXT = NULL;

    if(Typehead == NULL)
    {
        Typehead = temp;
        Typetail = temp;
    }
    else
    {
        Typetail -> NEXT = temp;
        Typetail = Typetail -> NEXT;
    }
    

    return;
}


struct FieldList* FieldLookup(char* NAME,struct FieldList *list)
{
   struct FieldList *temp;
    temp  = list;
    while(temp != NULL && (strcmp(temp -> NAME,NAME) != 0))
    {
        temp = temp -> NEXT;
    }
    // printf("%s\n",temp -> type -> NAME );
    return temp;
}

void FieldInstall(struct TypeTable *type,char* NAME)
{
    struct FieldList *temp;
    struct TypeTable *temp1;
    temp = (struct FieldList *) malloc(sizeof(struct FieldList));
    temp -> NAME = (char *) malloc(sizeof(NAME));
    strcpy(temp -> NAME , NAME);
	temp -> type = type;
    temp -> NEXT = NULL;

    if(FieldHead == NULL)
    {
        FieldHead = temp;
        FieldTail = temp;
    }
    else
    {
        FieldTail -> NEXT = temp;
        FieldTail = FieldTail -> NEXT;
    }
    return;
}


void printSymbolTable()
{
    struct Gsymbol *temp;
    temp = Ghead;
    while(temp != NULL)
    {
        printf("%s----%s-----%d\n",temp -> NAME,temp -> TYPE -> NAME,temp -> BINDING);
        temp = temp -> NEXT;
    }
}
