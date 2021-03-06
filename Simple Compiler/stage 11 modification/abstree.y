%{ 
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "abstree.h"
    #include "symboltable.h"
    #include "symboltable.c"
    #include "aa.c"
    #include "codegen.c"
    #include "userdtype.c"

    int yylex();
    void yyerror(char const *s);
    struct Tnode *head1,*head;
    int result;
    FILE * fp;
    extern FILE *yyin;
    extern int yylineno;
    struct FieldList *ftemp;
    struct TypeTable *declarationType ,*FdeclarationType,*functype,*temp1,*temp2;
    struct Gsymbol *Gtemp;
    struct Lsymbol *Ltemp;
    struct ArgStruct *Argtemp1, *Argtemp2;
    int indicator = 0; //for no.of arguments passed
    int declcount = 0,defcount = 0,exprcount = 0;
    char* id_name;
%}

%union
{
    struct Tnode * nptr;
};

%token NUM ID PLUS MUL DIV MOD ASGN READ WRITE MINUS NEWLINE LT GT DEQ NEQ ELSE IF THEN ENDIF ENDWHILE WHILE DO DARRAY
%token START END DECL ENDDECL T INT F BOOL LE GE NOT AND OR AMP MAIN RETURN ALLOC FREE TYPEDEF TYPE1 ENDTYPE NILL
%token DEQNILL NEQNILL
%left PLUS MINUS AND OR 
%left MUL DIV MOD 
%right ASGN 
%nonassoc LT  GT LE GE NOT
%right DEQ
%right NEQ
%type <nptr> T
%type <nptr> F
%type <nptr> NUM  
%type <nptr> ID
%type <nptr> PLUS
%type <nptr> MUL
%type <nptr> DIV
%type <nptr> MOD
%type <nptr> READ
%type <nptr> WRITE
%type <nptr> MINUS
%type <nptr> LT
%type <nptr> GT
%type <nptr> LE
%type <nptr> GE
%type <nptr> AND
%type <nptr> OR
%type <nptr> NOT
%type <nptr> ELSE
%type <nptr> IF
%type <nptr> THEN
%type <nptr> ENDIF
%type <nptr> WHILE
%type <nptr> DO
%type <nptr> ENDWHILE
%type <nptr> expr
%type <nptr> slist
%type <nptr> stmt
%type <nptr> AMP
%type <nptr> MAIN
%type <nptr> RETURN
%type <nptr> body
%type <nptr> mainblock
%type <nptr> retstmt
%type <nptr> fdef
%type <nptr> exprlist
%type <nptr> FIELD
%type <nptr> NILL
%type <nptr> DEQNILL
%type <nptr> NEQNILL

%%
program : TypeDefBlock gdeclaration fdeflist mainblock {
                                            // printf("SYMBOL TABLE:\n");
                                            // printSymbolTable();
                                            // printf("---------------\n");

                                            fclose(intermediate);
                                            exit(1);
                        }
        | TypeDefBlock gdeclaration mainblock    {

                                            // printf("SYMBOL TABLE:\n");
                                            // printSymbolTable();
                                            // printf("---------------\n");
                                            fclose(intermediate);
                                            exit(1);
                                    }
        ;


TypeDefBlock  : TYPE1 TypeDefList ENDTYPE
              |                                               
              ;

TypeDefList   : TypeDefList TypeDef
              | TypeDef 
              ;
TypeDef :   TypeDefhead TypeDefBody 
	        ;

TypeDefhead       : TYPEDEF ID { 
                                    id_name = $2 -> NAME; 
                                    TypeInstall($2 -> NAME,NULL); //fieldlist is initialized to null
                               }
              ;
TypeDefBody   : '{' FieldDeclList '}' { 
                                            temp1 = TypeLookup(id_name);
                                            temp1 -> fields = FieldHead;
                           					ftemp = FieldHead;
                           					// while(ftemp != NULL)
                           					// {
                           					// 	printf("%s : %s\n",ftemp -> NAME,ftemp -> type -> NAME );
                           					// 	ftemp = ftemp -> NEXT;
                           					// }                 
                                            FieldHead = NULL;
                                            FieldTail = NULL;
                                      }  
              ;

FieldDeclList : FieldDeclList FieldDecl
              | FieldDecl
              ;

FieldDecl    : TypeName ID ';' {
									// printf("%s\n",temp1 -> NAME );
									FieldInstall(temp1,$2 -> NAME);
								}

TypeName     : INT          {temp1 = TypeLookup("integer");}
             | BOOL         {temp1 = TypeLookup("boolean");}
             | ID           {
                                temp1 = TypeLookup($1 -> NAME);
                                if(temp1 == NULL)
                                {
                                    yyerror("Un-declared udt\n");
                                    exit(1);
                                }
                            }
             ;

gdeclaration : DECL gdlist ENDDECL    {
                                        intermediate = fopen("assemblycode.asm","w+");
                                        if(intermediate == NULL)
                                        {
                                            printf("Unable to locate file\n");
                                            exit(1);
                                        }
                                        // alloc();
                                        // freeheap();
                                        fprintf(intermediate, "START\n");
                                        // initialize();
                                        fprintf(intermediate, "MOV SP,%d\n",totalCount - 1);
                                        fprintf(intermediate, "MOV BP,%d\n",totalCount);
                                        fprintf(intermediate, "PUSH R0\n");
                                        fprintf(intermediate, "CALL MAIN\n");
                                        fprintf(intermediate, "HALT\n");
                    
                                        }
            |                       {
                                        intermediate = fopen("assemblycode.asm","w+");
                                        if(intermediate == NULL)
                                        {
                                            printf("Unable to locate file\n");
                                            exit(1);
                                        }
                                        // alloc();
                                        // freeheap();
                                        fprintf(intermediate, "START\n");
                                        initialize();
                                        fprintf(intermediate, "MOV SP,%d\n",totalCount - 1);
                                        fprintf(intermediate, "MOV BP,%d\n",totalCount);
                                        fprintf(intermediate, "PUSH R0\n");
                                        fprintf(intermediate, "CALL MAIN\n");
                                        fprintf(intermediate, "HALT\n");

                                     }        
            ;
gdlist : gdec             {}
        | gdlist gdec     {}
        ;
gdec : Type vlist ';'    {}
     ;
vlist : ID              {
                            Gtemp = Glookup($1 -> NAME);
                            if(Gtemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            if(declarationType == TypeLookup("darray"))
                            {
                                Ginstall($1 -> NAME,declarationType,1,NULL);                                
                            }
                        }
        |ID '['NUM']'  {
                            Gtemp = Glookup($1 -> NAME);
                            if(Gtemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            if ( declarationType == TypeLookup("integer") )
                                Ginstall($1 -> NAME,TypeLookup("array_integer"),$3 -> VALUE,NULL);
                            else if ( declarationType == TypeLookup("boolean") )
                                Ginstall($1 -> NAME,TypeLookup("array_boolean"),$3 -> VALUE,NULL);
                            else
                            {
                            	yyerror("arrays of udt is not allowed\n");
                            	exit(1);
                            }
                        }
                        
        | ID '(' arglist ')'{
                                declcount++; //  to keep track of number of functions declared
                                Gtemp = Glookup($1 -> NAME);
                                if(Gtemp != NULL)
                                {
                                    printf("Re initialization of identifier\n");
                                    exit(1);
                                }
                                Ginstall($1 -> NAME,declarationType,-1, Arghead);
                                Arghead = NULL;
                                Argtail = NULL;
                            }
        |vlist ',' ID   {
                            Gtemp = Glookup($3 -> NAME);
                            if(Gtemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            Ginstall($3 -> NAME,declarationType,1,NULL);
                        }
        |vlist ',' ID '['NUM']' {
                                    Gtemp = Glookup($3 -> NAME);
                                    if(Gtemp != NULL)
                                    {
                                        printf("Re initialization of variable\n");
                                        exit(1);
                                    }

                                    if ( declarationType == TypeLookup("integer") )
                                        Ginstall($3 -> NAME,TypeLookup("array_integer"),$5 -> VALUE,NULL);
                                    else if ( declarationType == TypeLookup("boolean") )
                                        Ginstall($3 -> NAME,TypeLookup("array_boolean"),$5 -> VALUE,NULL);
        							else
		                            {
		                            	yyerror("arrays of udt is not allowed\n");
		                            	exit(1);
		                            }

                                }
                                
        |vlist ',' ID '(' arglist ')'{
                                        declcount++; //  to keep track of number of functions declared

                                        Gtemp = Glookup($3 -> NAME);
                                        if(Gtemp != NULL)
                                        {
                                            printf("Re initialization of identifier\n");
                                            exit(1);
                                        }
                                        Ginstall($3 -> NAME,declarationType,-1, Arghead);
                                        Arghead = NULL;
                                        Argtail = NULL;
                                    }
        ;
        
Type :     INT  {
                    declarationType = TypeLookup("integer");
                }

        |  BOOL {
                    declarationType = TypeLookup("boolean");
                }
        | DARRAY {
                    declarationType = TypeLookup("darray");
                    }
        |   ID {
                    temp1 = TypeLookup($1 -> NAME);
                    if(temp1 != NULL)
                        declarationType = TypeLookup($1 -> NAME);
                    else
                    {
                        yyerror("Unknown user-defined type\n");
                        exit(1);
                    }
                }
        ;

FType :     INT  {FdeclarationType = TypeLookup("integer");}
        |   BOOL {FdeclarationType = TypeLookup("boolean");}
        |   DARRAY {FdeclarationType = TypeLookup("darray");}
        |   ID {
                   temp1 = TypeLookup($1 -> NAME);
                    if(temp1 != NULL)
                        FdeclarationType = TypeLookup($1 -> NAME);
                    else
                    {
                        yyerror("Unknown user-defined type\n");
                        exit(1);
                    }
                }
        ;

arglist :   arg               {}
        |   arglist ';' arg   {}
        |
        ;

arg     :   FType fvlist         {} 
        ;
        
fvlist  :   ID                     {
                                        // printf("%s\n", $1 -> NAME);
                                        // printf("%s\n", FdeclarationType -> NAME);
                                        Argtemp = Arglookup($1 -> NAME);
                                        if(Argtemp != NULL)
                                        {
                                            printf("Re initialization of variable in Arglist\n");
                                            exit(1);
                                        }

                                        ArgInstall($1 -> NAME,FdeclarationType,0); 
                                    }
        |    AMP ID                {        
                                            Argtemp = Arglookup($2 -> NAME);

                                            if(Argtemp != NULL)
                                            {
                                                printf("Re initialization of variable in Arglist\n");
                                                exit(1);
                                            }
                                            
                                            if ( FdeclarationType == TypeLookup("integer") )
                                            	ArgInstall($2 -> NAME,TypeLookup("amp_integer"),1);
	                                        else if ( FdeclarationType == TypeLookup("boolean") )
                                            	ArgInstall($2 -> NAME,TypeLookup("amp_boolean"),1);
    	                                    else
                                            {
												ArgInstall($2 -> NAME,FdeclarationType,1);
		                                    }
		                            }
        |   fvlist ',' ID          {
                                        Argtemp = Arglookup($3 -> NAME);

                                        if(Argtemp != NULL)
                                        {
                                            printf("Re initialization of variable in Arglist\n");
                                            exit(1);
                                        }

                                        ArgInstall($3 -> NAME,FdeclarationType,0); 
                                    }

        |   fvlist ',' AMP ID      {
                                        Argtemp = Arglookup($4 -> NAME);

                                        if(Argtemp != NULL)
                                        {
                                            printf("Re initialization of variable in Arglist\n");
                                            exit(1);
                                        }
                                        if ( FdeclarationType == TypeLookup("integer") )
                                            ArgInstall($4 -> NAME,TypeLookup("amp_integer"),1);

                                        else if ( FdeclarationType == TypeLookup("boolean") )
                                            ArgInstall($4 -> NAME,TypeLookup("amp_boolean"),1);
	                                    else
                                        {
											ArgInstall($4 -> NAME,FdeclarationType,1);
	                                    }
                                    }
        ;



fdeflist : fdef                 {}
            | fdeflist fdef     {}
            ;

fdef : Type ID '(' arglist ')' '{' ldeclaration body '}'    {  
                                                                // printf("IN fdef\n");
                                                                defcount++; //  to keep track of number of functions defined

                                                                Gtemp = Glookup($2 -> NAME);

                                                                if(Gtemp == NULL)
                                                                {
                                                                    printf("Function not declared in GST\n");
                                                                    exit(1);
                                                                }

                                                                //storing arguments in LST

                                                                Argtemp1 = Arghead;
                                                                Argtemp2 = Gtemp -> Arglist;

                                                                while((Argtemp1 != NULL)&&(Argtemp2 != NULL))
                                                                {
                                                                    if (strcmp(Argtemp1 -> NAME,Argtemp2 -> NAME) == 0)
                                                                    {
                                                                        if (Argtemp1 -> TYPE != Argtemp2 -> TYPE)
                                                                        {
                                                                            printf("Conflict in argument types \n");
                                                                            exit(1);
                                                                        }
                                                                    }
                                                                    else
                                                                    {
                                                                        printf("Conflict in argument names \n");
                                                                        exit(1);
                                                                    }

                                                                    Argtemp1 = Argtemp1 -> NEXT;
                                                                    Argtemp2 = Argtemp2 -> NEXT;
                                                                }

                                                                if((Argtemp1 != NULL)||(Argtemp2 != NULL))
                                                                {
                                                                    printf("Unequal number of arguments \n");
                                                                    exit(1);
                                                                }

                                                                $2 -> Lentry = Lhead;

                                                                fprintf(intermediate, "F%d:\n",Gtemp -> BINDING);
                                                                fprintf(intermediate, "PUSH BP\n");
                                                                fprintf(intermediate, "MOV BP,SP\n");

                                                                Ltemp = Lhead;

                                                                while(Ltemp != NULL)
                                                                {                                                               
                                                                    fprintf(intermediate, "PUSH R0\n");
                                                                    Ltemp = Ltemp -> NEXT;
                                                                }                                                               

                                                                // printf("entering..\n");
                                                                codegen($8);
                                                                // printf("entering..\n");

                                                                Arghead = NULL;
                                                                Argtail = NULL;
                                                                Lhead = NULL;
                                                                Ltail = NULL;
                                                            }
     ;

ldeclaration : DECL ldlist ENDDECL    {
                                            // $$ = $2;

                                        }
              |                       { 
                                        //$$ = NULL;
                                     }
            ;
ldlist : ldec             {
                                // $$ = Lhead;
                            }

         | ldlist ldec     {
                                // $$ = Lhead;
                            }
        ;
ldec : FType lvlist ';'    {
                                // $$ = Lhead;
                           }
    ;
lvlist : ID              {
                            // printf("%s\n",$1 -> NAME );
                            // printf("%s\n", FdeclarationType -> NAME);
                            Ltemp = Llookup($1 -> NAME);
                            if(Ltemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            Linstall($1 -> NAME,FdeclarationType);
                            // $$ = Lhead;
                        }

        |lvlist ',' ID   {
                            Ltemp = Llookup($3 -> NAME);
                            if(Ltemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            Linstall($3 -> NAME,FdeclarationType);

                            // $$ = Lhead;
                        }
        ;   

mainblock : Type MAIN '(' ')' '{' ldeclaration body '}'  
                            {
                                if(declcount != defcount)
                                {
                                    yyerror("All functions declared need to be defined\n");
                                    exit(1);
                                }
                                //$2 -> Lentry = Lhead;
                                if(declarationType != TypeLookup("integer"))
                                {
                                    yyerror("Main return type should be of integer type\n");
                                    exit(1);
                                }
                                fprintf(intermediate, "MAIN:\n");
                                fprintf(intermediate, "PUSH BP\n");
                                fprintf(intermediate, "MOV BP,SP\n");

                                Ltemp = Lhead;

                                while(Ltemp != NULL)
                                {                                                                
                                    fprintf(intermediate, "PUSH R0\n");
                                    Ltemp = Ltemp -> NEXT;
                                }
                                
                                //printf("entering\n");
                                codegen($7);
                                // printf("entering\n");                              
                                Lhead = NULL;
                                Ltail = NULL;
                            }
          ; 

body : START slist retstmt END  {
                                    //printf("created\n");
                                    $$ = TreeCreate(TypeLookup("void"), DEFAULT, NULL,0,NULL,$2,$3,NULL);
                                }
        | START retstmt END  {
                                    //printf("created\n");
                                    $$ = TreeCreate(TypeLookup("void"), DEFAULT, NULL,0,NULL,NULL,$2,NULL);
                                }
    ;


retstmt : RETURN expr ';'   {   
                                if(declarationType == $2 -> TYPE)                              
                                    $$ = TreeCreate($2->TYPE, NODE_RET,NULL,0,NULL,NULL,$2,NULL);
                                else
                                {
                                    // printf("functype : %d\n",functype );
                                    // printf("exprtype : %d\n",$2 -> TYPE );
                                    yyerror("return type do not match with the function return type\n");
                                    exit(1);
                                }
                            }
        ;

slist : slist stmt   {
                            head = (struct Tnode *)malloc(sizeof(struct Tnode ));
                            head -> NODE = DEFAULT;
                            head -> Ptr1 = $1;
                            //printf("----------------------\n");
                            //printf("%d\n",head->Ptr1->NODE);
                            head -> Ptr2 = $2;
                            //printf("%d\n",head->Ptr2->NODE);
                            // printf("----------------------\n");
                            $$ = head;
                        }   
        | stmt          {
                            $$ = $1;
                            //printf("-----%d----\n",$1->NODE);
                                                        
                        }
        
        ;

stmt : ID ASGN expr ';'         {
                                    /*printf(" in ASGN \n");*/

                                    Ltemp = Llookup($1 -> NAME);

                                    if(Ltemp != NULL)
                                    {
                                        $1 -> TYPE = Ltemp -> TYPE;
                                    }

                                    else
                                    {
                                        Argtemp = Arglookup($1 -> NAME);
                                        if(Argtemp != NULL)
                                        {
                                            if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                            {
                                                $1 -> TYPE = TypeLookup("integer");
                                            }
                                            else if((Argtemp -> TYPE == TypeLookup("boolean")) || (Argtemp -> TYPE == TypeLookup("amp_boolean")))
                                            {
                                                $1 -> TYPE = TypeLookup("boolean"); 
                                            }
                                            else
                                            {
                                            	$1 -> TYPE = Argtemp -> TYPE;	
                                            }           
                                        }

                                        else
                                        {

                                            Gtemp = Glookup($1 -> NAME);
                                            if(Gtemp == NULL)
                                            {
                                                yyerror("Un-declared variable\n");
                                                printf("%s\n",$1 -> NAME);
                                                exit(1);
                                            }
                                            else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                            {
                                                yyerror("conflict in ID NodeType : Expected Variable . Found Array\n");
                                                printf("%s\n",$1 -> NAME);
                                                exit(1);
                                            }
                                            else
                                            {   
                                                $1 -> Gentry = Gtemp;
                                                $1 -> TYPE = Gtemp -> TYPE;
                                            }
                                        }
                                    }
                                    if($1-> TYPE != $3 -> TYPE)
                                    {
                                        printf("%s\n",$1 -> TYPE -> NAME );
                                        printf("%s\n",$3 -> NAME);

                                        yyerror("conflict in types in assignment 1\n");
                                        printf("%s\n",$1 -> NAME);
                                        exit(1);
                                    } 
                                    $$ = TreeCreate(TypeLookup("void"), NODE_ASGN,NULL,0,NULL,$1,$3,NULL);  
                                }

        | ID '[' expr ']' ASGN expr ';'   {
                                                /*printf(" in ASGN ARRAY\n");*/
                                                Gtemp = Glookup($1 -> NAME);
                                                if(Gtemp == NULL)
                                                {
                                                    printf("Un-declared array\n");
                                                    exit(1);
                                                }
                                                else if(Gtemp -> TYPE == TypeLookup("boolean") ||Gtemp -> TYPE == TypeLookup("integer") )
                                                {
                                                    yyerror("conflict in ID NodeType : Expected Variable , Found Array\n");
                                                    printf("%s\n",$1 -> NAME);
                                                    exit(1);
                                                }
                                                else if($3 -> TYPE != TypeLookup("integer"))
                                                {
                                                    yyerror("Expected value \n");
                                                    printf("%s\n",$1 -> NAME);
                                                    exit(1);
                                                }
                                                else
                                                {   
                                                    $1 -> Gentry = Gtemp;
                                                    if(Gtemp -> TYPE == TypeLookup("array_integer"))
                                                    {
                                                        $1 -> TYPE = TypeLookup("integer");
                                                    }
                                                    else if(Gtemp -> TYPE == TypeLookup("array_boolean"))
                                                    {
                                                        $1 -> TYPE = TypeLookup("boolean"); 
                                                    }
                                                } 
                                                if($1-> TYPE != $6 -> TYPE)
                                                {
                                                    yyerror("conflict in types in assignment 2\n");
                                                    printf("%s\n",$1 -> NAME);
                                                    exit(1);
                                                } 
                                                $$ = TreeCreate(TypeLookup("void"), NODE_ARRAY_ASGN,NULL,0,NULL,$1,$3,$6); 
                                          }
        | READ '(' ID ')' ';'   {
                                    /*printf(" in READ \n");*/ 
                                    Ltemp = Llookup($3 -> NAME);

                                    if(Ltemp != NULL)
                                    {
                                        if(Ltemp -> TYPE == TypeLookup("integer"))
                                        {
                                            $3 -> TYPE = TypeLookup("integer");
                                        }
                                        else 
                                        {
                                            //$3 -> TYPE = TYPE_BOOL;
                                            yyerror("variables other than integer can not be read\n");
                                            printf("%s\n",$3 -> NAME);
                                            exit(1);
                                        }
                                        
                                    }

                                    else
                                    {
                                        Argtemp = Arglookup($3 -> NAME);
                                        // printf("%d\n",Argtemp -> TYPE );
                                        if(Argtemp != NULL)
                                        {
                                            if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                            {
                                                $3 -> TYPE = TypeLookup("integer");
                                            }
                                            else
                                            {
                                            	yyerror("variables other than integer can not be read\n");
                                                printf("%s\n",$3 -> NAME);
                                                exit(1);
                                            }
                                        }

                                        else
                                        {
                                            Gtemp = Glookup($3 -> NAME);
                                            if(Gtemp == NULL)
                                            {
                                                printf("Un-declared variable\n");
                                                exit(1);
                                            }
                                            else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                            {
                                                yyerror("conflict in ID NodeType : Expected Variable . Found Array\n");
                                                printf("%s\n",$3 -> NAME);
                                                exit(1);
                                            }
                                            else
                                            {   
                                                $3 -> Gentry = Gtemp;
                                                if(Gtemp -> TYPE == TypeLookup("integer"))
                                                {
                                                    $3 -> TYPE = TypeLookup("integer");
                                                }
                                                else
                                                {
                                                    //$3 -> TYPE = TYPE_BOOL;
                                            		yyerror("variables other than integer can not be read\n");
                                                    printf("%s\n",$3 -> NAME);
                                                    exit(1);
                                                }
                                            }
                                        }
                                    }
                                    $$ = TreeCreate(TypeLookup("void"), NODE_READ,NULL,0,NULL,NULL,$3,NULL); 
                                } 

        | READ '(' ID '[' expr ']' ')' ';'   {
                                                /*printf(" in READ ARR\n");*/  
                                                Gtemp = Glookup($3 -> NAME);
                                                if(Gtemp == NULL)
                                                {
                                                    yyerror("Un-declared array\n");
                                                    exit(1);
                                                }
                                                else if(Gtemp -> TYPE == TypeLookup("boolean") ||Gtemp -> TYPE == TypeLookup("integer") )
                                                {
                                                    yyerror("conflict in ID NodeType : Expected Variable , Found Array\n");
                                                    printf("%s\n",$3 -> NAME);
                                                    exit(1);
                                                }          
                                                else if($5 -> TYPE != TypeLookup("integer"))
                                                {
                                                    yyerror("Expected value\n");
                                                    printf("%s\n",$3 -> NAME);
                                                    exit(1);
                                                }                                          
                                                else
                                                {   
                                                    $3 -> Gentry = Gtemp;
                                                    if(Gtemp -> TYPE == TypeLookup("array_integer"))
                                                    {
                                                        $3 -> TYPE = TypeLookup("integer");
                                                    }
                                                    else
                                                    {
                                                        //$3 -> TYPE = TYPE_BOOL;
                                                        yyerror("array variables other than integer cannot be read\n");
                                                        printf("%s\n",$3 -> NAME);
                                                        exit(1);
                                                    }
                                                }
                                                $$ = TreeCreate(TypeLookup("void"), NODE_ARRAY_READ,NULL,0,NULL,NULL,$3,$5); 
                                            }
        | WRITE '(' expr ')' ';'  {
                                    /*  printf(" in WRITE \n"); */
                                     // printf("%d\n",$3 -> TYPE );
                                    if( $3 -> TYPE != TypeLookup("boolean") || $3 -> TYPE != TypeLookup("amp_boolean"))
                                    {
                                        $$ = TreeCreate(TypeLookup("void"), NODE_WRITE,NULL,0,NULL,NULL,$3,NULL);
                                    }
                                    else
                                    {
                                        yyerror("Boolean variable can not be written\n");
                                        if($3 -> Ptr1 != NULL)
                                        {
                                            printf("%s\n",$3 -> Ptr1 -> NAME);
                                        }
                                        else
                                        {
                                            printf("%s\n",$3 -> NAME);
                                        }
                                        exit(1);
                                    }   
                                }
        |IF '(' expr ')' THEN slist ENDIF ';' 
                               { 
                                    /*printf(" in IF_THEN \n");*/
                                    if($3 -> TYPE != TypeLookup("boolean"))
                                    {
                                        yyerror("Expected boolean , Found value in if\n");
                                        exit(1);
                                    }
                                    $$ = TreeCreate(TypeLookup("void"), NODE_IF,NULL,0,NULL,$3,$6,NULL); 
                               }
        |IF '(' expr ')' THEN slist ELSE slist ENDIF ';' 
                                { 
                                    // printf(" in IF_THEN_ELSE \n");
                                    if($3 -> TYPE != TypeLookup("boolean"))
                                    {
                                        yyerror("Expected boolean , Found value in if else\n");
                                        exit(1);
                                    }
                                    $$ = TreeCreate(TypeLookup("void"), NODE_IF_ELSE,NULL,0,NULL,$3,$6,$8); 
                                }
        |WHILE '(' expr ')' DO slist ENDWHILE ';'
                                { 
                                    // printf(" in WHILE \n"); 
                                    if($3 -> TYPE != TypeLookup("boolean"))
                                    {
                                        yyerror("Expected boolean , Found value in while\n");
                                        exit(1);
                                    }
                                    $$ = TreeCreate(TypeLookup("void"), NODE_WHILE,NULL,0,NULL,$3,$6,NULL); 
                                }
        | ID ASGN ALLOC'('expr')' ';'
                                        {
                                          Ltemp = Llookup($1 -> NAME);

                                        if(Ltemp != NULL)
                                        {
                                             if(Ltemp -> TYPE != TypeLookup("darray"))
                                                {
                                                    //$1 -> TYPE = TypeLookup("integer");
                                                    yyerror("Cannot ALLOC expr to non darray variable\n");
                                                    exit(1);
                                                }
                                                else 
                                                {
                                                    $1 -> TYPE = TypeLookup(Ltemp -> TYPE);
                                                }
                                        }
                                        else
                                        {
                                            Argtemp = Arglookup($1 -> NAME);
                                            if(Argtemp != NULL)
                                            {
                                                if(Argtemp -> TYPE != TypeLookup("darray") )
                                                {
                                                    //$1 -> TYPE = TypeLookup("integer");
                                                    yyerror("Cannot ALLOC to integer variable\n");
                                                    exit(1);
                                                }
                                                else
                                                {
                                                    $1 -> TYPE = TypeLookup(Argtemp -> TYPE);
                                                }       
                                            }

                                            else
                                            {
                                                Gtemp = Glookup($1 -> NAME);
                                                if(Gtemp == NULL)
                                                {
                                                    yyerror("Un-declared variable\n");
                                                    printf("%s\n",$1 -> NAME);
                                                    exit(1);
                                                }
                                                else if(Gtemp -> TYPE != TypeLookup("darray") )
                                                {
                                                    yyerror("alloc expr can not be assigned to non darray variables\n");
                                                    printf("%s\n",$1 -> NAME);
                                                    exit(1);
                                                }
                                                else
                                                {   
                                                    $1 -> Gentry = Gtemp;
                                                    $1 -> TYPE = Gtemp -> TYPE;
                                                }
                                            }
                                        }
                                            head = TreeCreate(TypeLookup("integer"),NODE_ALLOC1,NULL,0,NULL,NULL,$5,NULL);
                                            $$ = TreeCreate(TypeLookup("void"), NODE_ASGN,NULL,0,NULL,$1,head,NULL);           
                                        }
        | ID ASGN ALLOC'(' ')' ';'  {
                                        /*printf(" in ALLOC ASGN \n");*/

                                        Ltemp = Llookup($1 -> NAME);

                                        if(Ltemp != NULL)
                                        {
                                             if(Ltemp -> TYPE == TypeLookup("integer"))
                                                {
                                                    //$1 -> TYPE = TypeLookup("integer");
                                                    yyerror("Cannot ALLOC to integer variable\n");
                                                    exit(1);
                                                }
                                                else if(Ltemp -> TYPE == TypeLookup("boolean"))
                                                {
                                                    // $1 -> TYPE = TypeLookup("boolean"); 
                                                    yyerror("Cannot ALLOC to boolean variable\n");
                                                    exit(1);

                                                }
                                                else if(Ltemp -> TYPE == TypeLookup("darray"))
                                                {

                                                    yyerror("Cannot ALLOC to darray variable\n");
                                                    exit(1);
                                                }
                                                else
                                                    $1 -> TYPE = TypeLookup(Ltemp -> TYPE);
                                        }
                                        else
                                        {
                                            Argtemp = Arglookup($1 -> NAME);
                                            if(Argtemp != NULL)
                                            {
                                                if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                                {
                                                    //$1 -> TYPE = TypeLookup("integer");
                                                    yyerror("Cannot ALLOC to integer variable\n");
                                                    exit(1);
                                                }
                                                else if((Argtemp -> TYPE == TypeLookup("boolean")) || (Argtemp -> TYPE == TypeLookup("amp_boolean")))
                                                {
                                                    // $1 -> TYPE = TypeLookup("boolean"); 
                                                    yyerror("Cannot ALLOC to boolean variable\n");
                                                    exit(1);

                                                }
                                                else if(Argtemp -> TYPE == TypeLookup("darray"))
                                                 {
                                                    // $1 -> TYPE = TypeLookup("boolean"); 
                                                    yyerror("Cannot ALLOC to darray variable\n");
                                                    exit(1);

                                                }   
                                                else    
                                                    $1 -> TYPE = TypeLookup(Argtemp -> TYPE);
                                            }

                                            else
                                            {
                                                Gtemp = Glookup($1 -> NAME);
                                                if(Gtemp == NULL)
                                                {
                                                    yyerror("Un-declared variable\n");
                                                    printf("%s\n",$1 -> NAME);
                                                    exit(1);
                                                }
                                                else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                                {
                                                    yyerror("conflict in ID NodeType : Expected udt Variable . Found Array\n");
                                                    printf("%s\n",$1 -> NAME);
                                                    exit(1);
                                                }
                                                else if(Gtemp -> TYPE == TypeLookup("boolean") ||Gtemp -> TYPE == TypeLookup("integer"))
                                                {
                                                    yyerror("Cannot ALLOC to boolean or integer variable\n");
                                                    exit(1);
                                                }
                                                else if(Gtemp -> TYPE == TypeLookup("boolean") ||Gtemp -> TYPE == TypeLookup("integer"))
                                                {
                                                    yyerror("Cannot ALLOC to boolean or integer variable\n");
                                                    exit(1);
                                                }
                                                else if(Gtemp -> TYPE == TypeLookup("darray"))
                                                {
                                                    yyerror("Cannot ALLOC to darray variable\n");
                                                    exit(1);
                                                }
                                                else
                                                {   
                                                    $1 -> Gentry = Gtemp;
                                                    $1 -> TYPE = Gtemp -> TYPE;
                                                }
                                            }
                                        }
                                            head = TreeCreate(TypeLookup("integer"),NODE_ALLOC,NULL,0,NULL,NULL,NULL,NULL);
                                            $$ = TreeCreate(TypeLookup("void"), NODE_ASGN,NULL,0,NULL,$1,head,NULL); 
                                    }    
        | FIELD ASGN ALLOC'(' ')' ';'  {
											// printf("FIELDASGN\n");
                                            head = $1;
                                            while(head -> Ptr2 != NULL)
                                            {
                                                head = head -> Ptr2;
                                            }
                                            if(head -> TYPE == TypeLookup("integer") || head -> TYPE == TypeLookup("boolean") )
                                            {
                                               yyerror("Cannot ALLOC to boolean or integer variable\n");
                                                    exit(1);
                                            }
                                            // else if(head -> TYPE == TypeLookup("array_integer") || head -> TYPE == TypeLookup("array_boolean") )
                                            // {
                                            //         yyerror("Cannot ALLOC to array type variable\n");
                                            //         exit(1);
                                            // }
                                            else
                                            {
                                                head = TreeCreate(TypeLookup("integer"),NODE_ALLOC,NULL,0,NULL,NULL,NULL,NULL);
                                                $$ = TreeCreate(TypeLookup("void"), NODE_ASGN,NULL,0,NULL,$1,head,NULL);        
                                            }
											

                                        }

		| FIELD ASGN expr ';'			{
											// printf("FASGN\n");
                                            head  = $1;
                                            while(head -> Ptr2 != NULL)
                                            {
                                                head = head -> Ptr2;
                                            }
                                            head1 = $3;
                                            while(head1 -> Ptr2 != NULL)
                                            {
                                                head1 = head1 -> Ptr2;
                                            }
                                            if(head1 -> TYPE == head -> TYPE)
                                                $$ = TreeCreate(TypeLookup("void"), NODE_ASGN,NULL,0,NULL,$1,$3,NULL);        
                                            else
                                            {
                                                yyerror("conflicting assignment types in field\n");
                                                exit(1);
                                            }
                                        }

        | ID ASGN FREE '(' ')'    ';'             {
                                                  Ltemp = Llookup($1 -> NAME);
                                            if(Ltemp != NULL)
                                            {
                                                if(Ltemp -> TYPE != TypeLookup("darray") )
                                                {
                                                    yyerror("can not free a non darray\n");
                                                    exit(1);
                                                }
                                                $1 -> TYPE = Ltemp -> TYPE;

                                            }
                                            else
                                            {
                                                Argtemp = Arglookup($1 -> NAME);
                                                if(Argtemp != NULL)
                                                {
                                                    if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                                    {
                                                        //$1 -> TYPE = TypeLookup("integer");
                                                        yyerror("Cannot free integer variable\n");
                                                        exit(1);
                                                    }
                                                    else if((Argtemp -> TYPE == TypeLookup("boolean")) || (Argtemp -> TYPE == TypeLookup("amp_boolean")))
                                                    {
                                                        // $1 -> TYPE = TypeLookup("boolean"); 
                                                        yyerror("Cannot free  boolean variable\n");
                                                        exit(1);

                                                    }
                                                    if(Argtemp -> TYPE == TypeLookup("darray"))
                                                        $1 -> TYPE = Argtemp -> TYPE;
                                                    else
                                                    {
                                                        yyerror("error\n");
                                                        exit(1);
                                                    }
                                                }

                                                else
                                                {
                                                    Gtemp = Glookup($1 -> NAME);
                                                    if(Gtemp == NULL)
                                                    {
                                                        yyerror("Un-declared variable\n");
                                                        printf("%s\n",$1 -> NAME);
                                                        exit(1);
                                                    }
                                                    else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                                    {
                                                        yyerror("can not free array\n");
                                                        printf("%s\n",$1 -> NAME);
                                                        exit(1);
                                                    }
                                                    else if(Gtemp -> TYPE == TypeLookup("boolean") ||Gtemp -> TYPE == TypeLookup("integer"))
                                                    {
                                                        yyerror("Cannot free boolean or integer variable\n");
                                                        exit(1);
                                                    }
                                                    if(Argtemp -> TYPE == TypeLookup("darray"))
                                                        $1 -> TYPE = Gtemp -> TYPE;
                                                    else
                                                    {
                                                        yyerror("error");
                                                        exit(1);
                                                    }
                                                }
                                            }  
                                            $$ = TreeCreate(TypeLookup("void"),NODE_FREE1,NULL,0,NULL,NULL,$1,NULL);
                                        }       
        | FREE '(' ID ')' ';'          {
                                            Ltemp = Llookup($3 -> NAME);
                                            if(Ltemp != NULL)
                                            {
                                                if(Ltemp -> TYPE == TypeLookup("integer") || Ltemp -> TYPE == TypeLookup("boolean"))
                                                {
                                                    yyerror("can not free a non udt\n");
                                                    exit(1);
                                                }
                                                $3 -> TYPE = Ltemp -> TYPE;

                                            }
                                            else
                                            {
                                                Argtemp = Arglookup($3 -> NAME);
                                                if(Argtemp != NULL)
                                                {
                                                    if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                                    {
                                                        //$1 -> TYPE = TypeLookup("integer");
                                                        yyerror("Cannot free integer variable\n");
                                                        exit(1);
                                                    }
                                                    else if((Argtemp -> TYPE == TypeLookup("boolean")) || (Argtemp -> TYPE == TypeLookup("amp_boolean")))
                                                    {
                                                        // $1 -> TYPE = TypeLookup("boolean"); 
                                                        yyerror("Cannot free  boolean variable\n");
                                                        exit(1);

                                                    }
                                                	$3 -> TYPE = Argtemp -> TYPE;
                                                }

                                                else
                                                {
                                                    Gtemp = Glookup($3 -> NAME);
                                                    if(Gtemp == NULL)
                                                    {
                                                        yyerror("Un-declared variable\n");
                                                        printf("%s\n",$3 -> NAME);
                                                        exit(1);
                                                    }
                                                    else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                                    {
                                                        yyerror("can not free array\n");
                                                        printf("%s\n",$3 -> NAME);
                                                        exit(1);
                                                    }
                                                    else if(Gtemp -> TYPE == TypeLookup("boolean") ||Gtemp -> TYPE == TypeLookup("integer"))
                                                    {
                                                        yyerror("Cannot free boolean or integer variable\n");
                                                        exit(1);
                                                    }
                                                	$3 -> TYPE = Gtemp -> TYPE;

                                                }
                                            }  
                                            $$ = TreeCreate(TypeLookup("void"),NODE_FREE,NULL,0,NULL,NULL,$3,NULL); 
                                        }
        | FREE '(' FIELD ')' ';'    {
                                            head  = $3;
                                            while(head -> Ptr2 != NULL)
                                            {
                                                head = head -> Ptr2;
                                            }
                                            
                                            if(head -> TYPE == TypeLookup("integer") || head -> TYPE == TypeLookup("boolean"))
                                            {
                                                yyerror("cannot FREE non-udt\n");
                                                exit(1);
                                            }
                                            $$ = TreeCreate(TypeLookup("void"),NODE_FREE,NULL,0,NULL,NULL,$3,NULL); 
                                    }
        | READ '(' FIELD ')' ';'    {
                                            head  = $3;
                                            while(head -> Ptr2 != NULL)
                                            {
                                                head = head -> Ptr2;
                                            }
                                            
                                            if(head -> TYPE != TypeLookup("integer"))
                                            {
                                                yyerror("cannot READ a udt or boolean type\n");
                                                exit(1);
                                            }
                                            $$ = TreeCreate(TypeLookup("void"),NODE_READ,NULL,0,NULL,NULL,$3,NULL); 
                                    }
        | ID ASGN NILL ';' {
                                Ltemp = Llookup($1 -> NAME);

                                if(Ltemp != NULL)
                                {
                                    if(Ltemp -> TYPE == TypeLookup("integer") || Ltemp -> TYPE == TypeLookup("boolean"))
                                    {
                                        yyerror("integers and booleans can not be assigned null\n");
                                        exit(1); 
                                    }
                                    $1 -> TYPE = Ltemp -> TYPE;
                                }
                                else
                                {
                                    Argtemp = Arglookup($1 -> NAME);
                                    if(Argtemp != NULL)
                                    {
                                        if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                        {
                                            yyerror("integers can not be assigned null\n");
                                            exit(1);
                                        }
                                        else if((Argtemp -> TYPE == TypeLookup("boolean")) || (Argtemp -> TYPE == TypeLookup("amp_boolean")))
                                        {
                                            yyerror("boolean can not be assigned null\n");
                                            exit(1); 
                                        }
                                        else
                                        {
                                        	$1 -> TYPE = Argtemp -> TYPE;	
                                        }
                                    }

                                    else
                                    {

                                        Gtemp = Glookup($1 -> NAME);
                                        if(Gtemp == NULL)
                                        {
                                            yyerror("Un-declared variable\n");
                                            printf("%s\n",$1 -> NAME);
                                            exit(1);
                                        }
                                        else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                        {
                                            yyerror("conflict in ID NodeType : Expected Variable . Found Array\n");
                                            printf("%s\n",$1 -> NAME);
                                            exit(1);
                                        }
                                        else
                                        {   
                                            if(Gtemp -> TYPE == TypeLookup("integer") || Gtemp -> TYPE == TypeLookup("boolean"))
                                            {
                                                yyerror("integers and booleans can not be assigned null\n");
                                                exit(1); 
                                            }
                                            $1 -> Gentry = Gtemp;
                                            $1 -> TYPE = Gtemp -> TYPE;  
                                        }
                                    }
                                }
                                $$ = TreeCreate(TypeLookup("void"), NODE_ASGN,NULL,0,NULL,$1,$3,NULL);
        					}
      	| FIELD ASGN NILL ';'{
                                head  = $1;
                                while(head -> Ptr2 != NULL)
                                {
                                    head = head -> Ptr2;
                                }
                                
                                if(head -> TYPE == TypeLookup("integer") || head -> TYPE == TypeLookup("boolean"))
                                {
                                    yyerror("cannot assign null to a non-udt\n");
                                    exit(1);
                                }
								$$ = TreeCreate(TypeLookup("void"), NODE_ASGN,NULL,0,NULL,$1,$3,NULL); 
						    }
        ;
FIELD     : ID '.' ID   {
                            $1 -> NODE = NODE_FIELD;
                            Ltemp = Llookup($1 -> NAME);
                            if(Ltemp != NULL)
                            {
                                $1 -> TYPE = Ltemp -> TYPE;

                                ftemp = FieldLookup($3 -> NAME,$1 -> TYPE -> fields);
                                if(ftemp != NULL)
                                {
                                    $3 -> TYPE = ftemp -> type;
                                    $1 -> Ptr2 = $3;                        
                                    $$ = $1;
                                }
                                else
                                {
                                    yyerror("Un-declared field variable\n");
                                    exit(1);
                                }
                            }

                            else
                            {
                                Argtemp = Arglookup($1 -> NAME);
                                if(Argtemp != NULL)
                                {
                                    if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                    {
                                        yyerror(" . opearation over integer type is not allowed\n");
                                        exit(1);
                                    }
                                    else if((Argtemp -> TYPE == TypeLookup("boolean")) || (Argtemp -> TYPE == TypeLookup("amp_boolean")))
                                    {
                                        yyerror(" . opearation over boolean type is not allowed\n");
                                        exit(1);
                                    }
                                    $1 -> TYPE = Argtemp -> TYPE;                                        
                                    ftemp = FieldLookup($3 -> NAME,$1 -> TYPE -> fields);
                                    if(ftemp != NULL)
                                    {
                                        $3 -> TYPE = ftemp -> type;
                                        $1 -> Ptr2 = $3;                        
                                        $$ = $1;
                                    }
                                    else
                                    {
                                        yyerror("Un-declared field variable\n");
                                        exit(1);
                                    }

                                }

                                else
                                {
                                    Gtemp = Glookup($1 -> NAME);
                                    if(Gtemp == NULL)
                                    {
                                        yyerror("Un-declared variable\n");
                                        printf("%s\n",$1 -> NAME);
                                        exit(1);
                                    }
                                    else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                    {
                                        yyerror(" . opearation over arrays found\n");
                                        printf("%s\n",$1 -> NAME);
                                        exit(1);
                                    }
                                    else if(Gtemp -> TYPE == TypeLookup("boolean") ||Gtemp -> TYPE == TypeLookup("integer") )
                                    {
                                        yyerror(" . opearation over integer or boolean found\n");
                                        printf("%s\n",$1 -> NAME);
                                        exit(1);
                                    }
                                    else
                                    {   
                                        $1 -> Gentry = Gtemp;   
                                        $1 -> TYPE = Gtemp -> TYPE;
                            			// printf("%s\n",Gtemp -> TYPE -> NAME);
                                        // printf("%s\n",$3 -> NAME );
                                        ftemp = FieldLookup($3 -> NAME,$1 -> TYPE -> fields);
                                        if(ftemp != NULL)
                                        {
                                            $3 -> TYPE = ftemp -> type;
                            			// 	printf("%s\n",ftemp -> type -> NAME);
                                            $1 -> Ptr2 = $3;                        
                                        }
                                        else
                                        {
                                            yyerror("Un-declared field variable\n");
                                            exit(1);
                                        }

                                        $$ = $1;
                                    }
                                }
                            }
                        }
          | FIELD '.' ID {
                            head1 = head = $1;
                            while(head -> Ptr2 != NULL)
                            {
                                head = head -> Ptr2;
                            }
                            temp1 = head -> TYPE;
                            	// printf("%s\n",temp1 -> NAME);
                            if(temp1 != TypeLookup("boolean") && temp1 != TypeLookup("integer"))
                            {
                                ftemp = FieldLookup($3 -> NAME,temp1 -> fields);
          						// printf("IN FIELD\n");
                                if(ftemp != NULL)
                                {
                                    $3 -> TYPE = ftemp -> type;
                                    head -> Ptr2 = $3;
                                    $$ = head1;
                                }
                                else
                                {
                                    yyerror("Un-declared field variable\n");
                                    exit(1);
                                }
                            }
                            else
                            {
                                yyerror("Illegal access of identifier\n");
                                exit(1);
                            }
                        } 
          ;

exprlist : expr                 {
                                    // printf("FIRST : %d\n",$1 -> NODE);
                                    exprcount = 1;
                                    $$ = $1;
                                }
        |   exprlist ',' expr     {
                                        // printf("SECOND : %d\n",$3 -> NODE);         
                                        indicator = 1;
                                        exprcount++;
                                        head = (struct Tnode *)malloc(sizeof(struct Tnode ));
                                        head -> NODE = NODE_EXPR;
                                        head -> Ptr1 = $3;
                                        // $3 -> VALUE = ++tree_iter;
                                        //printf("----------------------\n");
                                        //printf("%d\n",head->Ptr1->NODE);
                                        head -> Ptr2 = $1;
                                        //printf("%d\n",head->Ptr2->NODE);
                                       // printf("----------------------\n");
                                        $$ = head;
                                    }

        ;

expr : expr PLUS expr       {
                                /*printf("PLUS\n");*/
                                // printf("%s\n",$1 -> TYPE -> NAME );
                                // printf("%d\n",$1 ->  NODE );
                                // printf("%s\n",$3 -> TYPE -> NAME );
                                // printf("%s\n",$3 -> VALUE );
                                if($1 -> TYPE == TypeLookup("integer") && $3 -> TYPE == TypeLookup("integer"))
                                {
                                    $$ = TreeCreate(TypeLookup("integer"), NODE_PLUS , NULL,0, NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in PLUS\n");
                                    exit(1);
                                }
                            }
        |expr MINUS expr    {
                                /*printf("MINUS\n");*/
                                if($1 -> TYPE != TypeLookup("boolean") && $3 -> TYPE != TypeLookup("boolean"))
                                {
                                    $$ = TreeCreate(TypeLookup("integer"), NODE_MINUS , NULL,0 , NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MINUS\n");
                                    exit(1);
                                }
                            }
        |expr MUL expr      {
                                /*printf("MUL\n");*/
                                if($1 -> TYPE != TypeLookup("boolean") && $3 -> TYPE != TypeLookup("boolean"))
                                {
                                    $$ = TreeCreate(TypeLookup("integer"), NODE_MUL , NULL,0 , NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MUL\n");
                                    exit(1);
                                }
                            }
        |expr DIV expr      {
                                /*printf("DIV\n");*/
                                if($1 -> TYPE != TypeLookup("boolean") && $3 -> TYPE != TypeLookup("boolean"))
                                {
                                    $$ = TreeCreate(TypeLookup("integer"), NODE_DIV , NULL,0 , NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MUL\n");
                                    exit(1);
                                }
                            }
        |expr MOD expr      {
                                /*printf("MOD\n");*/
                                if($1 -> TYPE != TypeLookup("boolean") && $3 -> TYPE != TypeLookup("boolean"))
                               	{
                                    $$ = TreeCreate(TypeLookup("integer"), NODE_MOD , NULL,0 , NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MUL\n");
                                    exit(1);
                                }
                            }
        |expr LT expr       {
                                /*printf("LT\n");*/
                                if($1 -> TYPE != TypeLookup("boolean") && $3 -> TYPE != TypeLookup("boolean"))
                                {
                                    $$ = TreeCreate(TypeLookup("boolean"), NODE_LT , NULL, 0, NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in LT\n");
                                    exit(1);
                                }
                            }
        |expr LE expr       {
                                /*printf("LT\n");*/
                                if($1 -> TYPE != TypeLookup("boolean") && $3 -> TYPE != TypeLookup("boolean"))
                                {
                                    $$ = TreeCreate(TypeLookup("boolean"), NODE_LE , NULL, 0, NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in LE\n");
                                    exit(1);
                                }
                            }
        |expr GT expr       {
                                /*printf("GT\n");*/
                                if($1 -> TYPE != TypeLookup("boolean") && $3 -> TYPE != TypeLookup("boolean"))
                                {
                                    $$ = TreeCreate(TypeLookup("boolean"), NODE_GT , NULL, 0, NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in GT\n");
                                    exit(1);
                                }
                            }
        |expr GE expr       {
                                /*printf("GT\n");*/
                                if($1 -> TYPE != TypeLookup("boolean") && $3 -> TYPE !=  TypeLookup("boolean"))
                                {
                                    $$ = TreeCreate(TypeLookup("boolean"), NODE_GE , NULL, 0, NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in GE\n");
                                    exit(1);
                                }
                            }        
        |expr DEQ expr      {
                                /*printf("DEQ\n");*/
                                if($1 -> TYPE != TypeLookup("boolean") && $3 -> TYPE != TypeLookup("boolean"))
                                {
                                    $$ = TreeCreate(TypeLookup("boolean"), NODE_DEQ, NULL, 0, NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in DEQ\n");
                                    exit(1);
                                }
                            }
        |expr NEQ expr      {
                                /*printf("NEQ\n");*/
                                if($1 -> TYPE != TypeLookup("boolean") && $3 -> TYPE != TypeLookup("boolean"))
                                {
                                    $$ = TreeCreate(TypeLookup("boolean"), NODE_NEQ, NULL, 0, NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in NEQ\n");
                                    exit(1);
                                }
                            }
        |expr AND expr      {
                                if($1 -> TYPE == TypeLookup("boolean") && $3 -> TYPE == TypeLookup("boolean"))
                                {
                                    $$ = TreeCreate($1 -> TYPE, NODE_AND, NULL, 0, NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in AND\n");
                                    exit(1);
                                }   
                            }
        |expr OR expr       {
                                if($1 -> TYPE == TypeLookup("boolean") && $3 -> TYPE == TypeLookup("boolean"))
                                {
                                    $$ = TreeCreate($1 -> TYPE, NODE_OR, NULL, 0, NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in OR\n");
                                    exit(1);
                                }   
                            }
        |NOT expr           {

                                if($2 -> TYPE == TypeLookup("boolean"))
                                {
                                    $$ = TreeCreate($2 -> TYPE, NODE_NOT, NULL, 0, NULL, NULL, $2, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand type in NOT\n");
                                    exit(1);
                                }   
                            }
        | '(' expr ')'      {
                                $$ = $2;
                            }
        | FIELD             {
                                $$ = $1;
                            }
        
        | NUM               {
                                /*printf("NUM\n");*/
                                $$ = $1;
                            }
        | ID                {
                                // printf("ID\n");
                                Ltemp = Llookup($1 -> NAME);

                                if(Ltemp != NULL)
                                {
                                    $1 -> TYPE = Ltemp -> TYPE;
                                    $$ = $1;
                                }

                                else
                                {
                                    Argtemp = Arglookup($1 -> NAME);
                                    if(Argtemp != NULL)
                                    {
                                        if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                        {
                                            $1 -> TYPE = TypeLookup("integer");
                                        }
                                        else if((Argtemp -> TYPE == TypeLookup("boolean")) || (Argtemp -> TYPE == TypeLookup("amp_boolean")))
                                        {
                                            $1 -> TYPE = TypeLookup("boolean"); 
                                        }
                                        else
                                        {
                                            $1 -> TYPE = Argtemp -> TYPE;
                                        }

                                        $$ = $1;
                                    }

                                    else
                                    {

                                        Gtemp = Glookup($1 -> NAME);
                                        if(Gtemp == NULL)
                                        {
                                            yyerror("Un-declared variable\n");
                                            printf("%s\n",$1 -> NAME);
                                            exit(1);
                                        }
                                        else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                        {
                                            yyerror("conflict in ID NodeType : Expected Variable . Found Array\n");
                                            printf("%s\n",$1 -> NAME);
                                            exit(1);
                                        }
                                        else
                                        {   
                                            $1 -> Gentry = Gtemp;
                                            $1 -> TYPE = Gtemp -> TYPE;
                                            $$ = $1;
                                        }
                                    }
                                 }
                            }

        | ID '[' expr ']'   {
                                /*printf("ID[expr]\n");*/
                                Gtemp = Glookup($1 -> NAME);
                                temp1 = TypeLookup("integer");
                                temp2 = TypeLookup("boolean");

                                if(Gtemp == NULL)
                                {
                                    yyerror("Un-declared array\n");
                                    printf("%s\n",$1 -> NAME);
                                    exit(1);
                                }
                                else if(Gtemp -> TYPE == temp2 ||Gtemp -> TYPE == temp1 )
                                {
                                    yyerror("conflict in ID NodeType : Expected Array , Found Variable\n");
                                    printf("%s\n",$1 -> NAME);
                                    exit(1);
                                }
                                else if($3 -> TYPE == temp2)
                                {
                                    yyerror("Expected value , Found boolean\n");
                                    printf("%s\n",$1 -> NAME);
                                    exit(1);
                                }
                                else
                                {   
                                    temp1 = TypeLookup("array_integer");
                                    temp2 = TypeLookup("array_boolean");
                                    $1 -> Gentry = Gtemp;
                                    if(Gtemp -> TYPE == temp1)
                                    {
                                        $1 -> TYPE = TypeLookup("integer");
                                    }
                                    else if(Gtemp -> TYPE == temp2)
                                    {
                                        $1 -> TYPE = TypeLookup("boolean");
                                    }
                                    $$ = TreeCreate($1 -> TYPE,NODE_ARRAY,NULL,0,NULL,$1,$3,NULL);
                                }
                            }
        | T                 {
                                $$ = $1;
                            }
        | F                 {
                                $$ = $1;
                            }

        |ID '(' exprlist ')' {
                                Gtemp = Glookup($1 -> NAME);

                                if(Gtemp == NULL)
                                {
                                    yyerror("Un-declared function \n");
                                    exit(1);
                                }

                                if(Gtemp -> SIZE != -1)
                                {
                                    yyerror("conflict in ID NodeType : Expected Function \n");
                                    printf("%s\n",$1 -> NAME);
                                    exit(1);
                                }
                                else
                                {   
                                    $1 -> Gentry = Gtemp;
                                    $1 -> TYPE = Gtemp -> TYPE;
                                }

                                $3 -> Ptr3 = Gtemp -> Arglist;
                                Arg_callee = Gtemp -> Arglist;
                                while(Arg_callee != NULL)
                                {
                                    exprcount--;
                                    Arg_callee = Arg_callee -> NEXT;
                                }
                                if(exprcount)
                                {
                                    yyerror("Unequal number of arguments\n");
                                    exit(1);
                                }
                                //differentiating b/w one and more than one arguments
                                if(indicator == 1)
                                {
                                    $$ = TreeCreate($1 -> TYPE,NODE_FUNC,$1 -> NAME,0,Gtemp -> Arglist,NULL,$3,NULL);
                                    indicator = 0;
                                }

                                else
                                    $$ = TreeCreate($1 -> TYPE,NODE_FUNC,$1 -> NAME,0,Gtemp -> Arglist,NULL,NULL,$3);
                                }

        |ID '(' ')' {
                                    Gtemp = Glookup($1 -> NAME);

                                    if(Gtemp == NULL)
                                    {
                                        yyerror("Un-declared function \n");
                                        exit(1);
                                    }

                                    if(Gtemp -> SIZE != -1)
                                    {
                                        yyerror("conflict in ID NodeType : Expected Function \n");
                                        printf("%s\n",$1 -> NAME);
                                        exit(1);
                                    }
                                    else
                                    {   
                                        $1 -> Gentry = Gtemp;
                                        $1 -> TYPE = Gtemp -> TYPE;
                                    }
                                        $$ = TreeCreate($1 -> TYPE,NODE_FUNC,$1 -> NAME,0,Gtemp -> Arglist,NULL,NULL,NULL);
                                }

       | ID DEQNILL {
   						    Ltemp = Llookup($1 -> NAME);
                            if(Ltemp != NULL)
                            {
                            	    if(Ltemp -> TYPE == TypeLookup("integer"))
                                    {
                                        yyerror("can not assign null to integer\n");
                                        exit(1);
                                    }
                                    else if(Ltemp -> TYPE == TypeLookup("boolean"))
                                    {
                                        yyerror("can not assign null to boolean\n");
                                        exit(1);
                                    }
                                    else
                                    {
	                                    $1 -> TYPE = Ltemp -> TYPE;
	                                }
                            }
                            else
                            {
                                Argtemp = Arglookup($1 -> NAME);
                                if(Argtemp != NULL)
                                {
                                    if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                    {
                                        yyerror("can not assign null to integer\n");
                                        exit(1);
                                    }
                                    else if((Argtemp -> TYPE == TypeLookup("boolean")) || (Argtemp -> TYPE == TypeLookup("amp_boolean")))
                                    {
                                        yyerror("can not assign null to boolean\n");
                                        exit(1);
                                    }
                                    else
                                    {
                                    	$1 -> TYPE = Argtemp -> TYPE;
                                    }
                                }

                                else
                                {

                                    Gtemp = Glookup($1 -> NAME);
                                    if(Gtemp == NULL)
                                    {
                                        yyerror("Un-declared variable\n");
                                        printf("%s\n",$1 -> NAME);
                                        exit(1);
                                    }
                                    else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                    {
                                        yyerror("conflict in ID NodeType : Expected Variable . Found Array\n");
                                        printf("%s\n",$1 -> NAME);
                                        exit(1);
                                    }
                                    if(Gtemp -> TYPE == TypeLookup("integer"))
                                    {
                                        yyerror("can not assign null to integer\n");
                                        exit(1);
                                    }
                                    else if(Gtemp -> TYPE == TypeLookup("boolean"))
                                    {
                                        yyerror("can not assign null to boolean\n");
                                        exit(1);
                                    }
                                    else
                                    {   
                                        $1 -> Gentry = Gtemp;
                                        $1 -> TYPE = Gtemp -> TYPE;
                                       
                                    }
                                }
                            }
	                    	$$ = TreeCreate(TypeLookup("boolean"), NODE_DEQ, NULL, 0, NULL, $1, $2, NULL);
		    		}
        | ID NEQNILL {
    					Ltemp = Llookup($1 -> NAME);
                        if(Ltemp != NULL)
                        {
                        	    if(Ltemp -> TYPE == TypeLookup("integer"))
                                {
                                    yyerror("can not assign null to integer in NEQ\n");
                                    exit(1);
                                }
                                else if(Ltemp -> TYPE == TypeLookup("boolean"))
                                {
                                    yyerror("can not assign null to boolean in NEQ\n");
                                    exit(1);
                                }
                                else
                                {
                                    $1 -> TYPE = Ltemp -> TYPE;
                                }
                        }
                        else
                        {
                            Argtemp = Arglookup($1 -> NAME);
                            if(Argtemp != NULL)
                            {
                                if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                {
                                    yyerror("can not assign null to integer in NEQ\n");
                                    exit(1);
                                }
                                else if((Argtemp -> TYPE == TypeLookup("boolean")) || (Argtemp -> TYPE == TypeLookup("amp_boolean")))
                                {
                                    yyerror("can not assign null to boolean in NEQ\n");
                                    exit(1);
                                }
                                else
                                {
                                	$1 -> TYPE = Argtemp -> TYPE;
                                }
                            }

                            else
                            {

                                Gtemp = Glookup($1 -> NAME);
                                if(Gtemp == NULL)
                                {
                                    yyerror("Un-declared variable\n");
                                    printf("%s\n",$1 -> NAME);
                                    exit(1);
                                }
                                else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                {
                                    yyerror("conflict in ID NodeType : Expected Variable . Found Array in NEQ\n");
                                    printf("%s\n",$1 -> NAME);
                                    exit(1);
                                }
                                if(Gtemp -> TYPE == TypeLookup("integer"))
                                {
                                    yyerror("can not assign null to integer in NEQ\n");
                                    exit(1);
                                }
                                else if(Gtemp -> TYPE == TypeLookup("boolean"))
                                {
                                    yyerror("can not assign null to boolean in NEQ\n");
                                    exit(1);
                                }
                                else
                                {   
                                    $1 -> Gentry = Gtemp;
                                    $1 -> TYPE = Gtemp -> TYPE;
                                   
                                }
                            }
                        }
                        	$$ = TreeCreate(TypeLookup("boolean"), NODE_NEQ, NULL, 0, NULL, $1, $2, NULL);
        				}
        | FIELD DEQNILL {
        					if($1 -> TYPE != TypeLookup("boolean") && $1 -> TYPE != TypeLookup("integer"))
                            {
                                $$ = TreeCreate(TypeLookup("boolean"), NODE_DEQ, NULL, 0, NULL, $1, $2, NULL);
                            }
                            else
                            {
                                yyerror("conflict in operand types in DEQ\n");
                                exit(1);
                            }
        				}
        | FIELD NEQNILL {
                            
                            if($1 -> TYPE != TypeLookup("boolean") && $1 -> TYPE != TypeLookup("integer"))
                            {
                                $$ = TreeCreate(TypeLookup("boolean"), NODE_NEQ, NULL, 0, NULL, $1, $2, NULL);
                            }
                            else
                            {
                                yyerror("conflict in operand types in NEQ\n");
                                exit(1);
                            }
                            
        				}
        ;

%%

void yyerror(char const *s) 
{ 
    printf("yyerror  %s\n",s); 
    return ;
} 

int main(int argc,char* argv[]) 
{ 
    TypeInstall("integer",NULL);
    TypeInstall("boolean",NULL);
    TypeInstall("array_integer",NULL);
    TypeInstall("array_boolean",NULL);
    TypeInstall("amp_integer",NULL);
    TypeInstall("amp_boolean",NULL);
    TypeInstall("void",NULL);
    TypeInstall("darray",NULL);
    // printf("installation of TypeTable\n");
    
    if(argc > 1)
    {
        fp = fopen(argv[1],"r");
        if(fp)
            yyin = fp;
    }    
    yyparse(); 
    // printf("installation of TypeTable\n");
    return 1; 
}
