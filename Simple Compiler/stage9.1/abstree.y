%{ 
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "abstree.h"
    #include "symboltable.h"
    #include "symboltable.c"
    #include "aa.c"
    #include "codegen.c"
    int yylex();
    void yyerror(char const *s);
    struct Tnode *root,*head;
    int result;
    FILE * fp;
    extern FILE *yyin;
    extern int yylineno;
    int declarationType ,FdeclarationType;
    struct Gsymbol *Gtemp;
    struct Lsymbol *Ltemp;
    struct ArgStruct *Argtemp1, *Argtemp2;
    int indicator = 0; //for no.of arguments passed
    // int tree_iter = 0;
%}

%union
{
    struct Tnode * nptr;
};

%token NUM ID PLUS MUL DIV MOD ASGN READ WRITE MINUS NEWLINE LT GT DEQ NEQ ELSE IF THEN ENDIF ENDWHILE WHILE DO 
%token START END DECL ENDDECL T INT F BOOL LE GE NOT AND OR AMP MAIN RETURN
%left PLUS MINUS AND OR
%left MUL DIV MOD
%right ASGN
%nonassoc LT GT DEQ NEQ LE GE NOT 
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
%type <nptr> DEQ
%type <nptr> NEQ
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
%%

program : gdeclaration fdeflist mainblock {
											printf("SYMBOL TABLE:\n");
				                            printSymbolTable();
				                            printf("---------------\n");
				       //                      //result = Evaluate($3);
           //                                  codegen($3);
                                            //fprintf(intermediate, "HALT\n");
                                            fclose(intermediate);
				                            printf("executed\n");
				                            exit(1);
                        }
        | gdeclaration mainblock    {

                                            printf("SYMBOL TABLE:\n");
                                            printSymbolTable();
                                            printf("---------------\n");
                                        fclose(intermediate);
                                        printf("executed\n");
                                        exit(1);
                                    }
        ;

gdeclaration : DECL gdlist ENDDECL    {
                                        intermediate = fopen("assemblycode.asm","w+");
                                        if(intermediate == NULL)
                                        {
                                            printf("Unable to locate file\n");
                                            exit(1);
                                        }
                                        fprintf(intermediate, "START\n");
                                        fprintf(intermediate, "MOV SP,%d\n",totalCount - 1);
                                        fprintf(intermediate, "MOV BP,%d\n",totalCount);
                                        fprintf(intermediate, "PUSH R0\n");
                                        fprintf(intermediate, "CALL MAIN\n");
                                        fprintf(intermediate, "HALT\n");
                                        //Ginstall("retvalue",SYMBOL_INTEGER,1,NULL);
                    
                                        }
            |                       {
                                        // printf("IN HERE\n");
                                        intermediate = fopen("assemblycode.asm","w+");
                                        if(intermediate == NULL)
                                        {
                                            printf("Unable to locate file\n");
                                            exit(1);
                                        }
                                        fprintf(intermediate, "START\n");
                                        fprintf(intermediate, "MOV SP,%d\n",totalCount - 1);
                                        fprintf(intermediate, "MOV BP,%d\n",totalCount);
                                        fprintf(intermediate, "PUSH R0\n");
                                        fprintf(intermediate, "CALL MAIN\n");
                                        fprintf(intermediate, "HALT\n");

                                        //Ginstall("retvalue",SYMBOL_INTEGER,1,NULL);


                                     }        //global declaration can be null
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
                            Ginstall($1 -> NAME,declarationType,1,NULL);
                        }
        |ID '['NUM']'  {
                            Gtemp = Glookup($1 -> NAME);
                            if(Gtemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            if ( declarationType == SYMBOL_INTEGER )
                                Ginstall($1 -> NAME,SYMBOL_ARRAY_INT,$3 -> VALUE,NULL);
                            else if ( declarationType == SYMBOL_BOOLEAN )
                                Ginstall($1 -> NAME,SYMBOL_ARRAY_BOOLEAN,$3 -> VALUE,NULL);

                        }
                        
		| ID '(' arglist ')'{
                                Gtemp = Glookup($1 -> NAME);
                                if(Gtemp != NULL)
                                {
                                    printf("Re initialization of identifier\n");
                                    exit(1);
                                }
                                if ( declarationType == SYMBOL_INTEGER )
                                    Ginstall($1 -> NAME,SYMBOL_FUNC_INT,-1, Arghead);
                                else if ( declarationType == SYMBOL_BOOLEAN )
                                    Ginstall($1 -> NAME,SYMBOL_FUNC_BOOLEAN,-1,Arghead);

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
                                    if ( declarationType == SYMBOL_INTEGER )
                                        Ginstall($3 -> NAME,SYMBOL_ARRAY_INT,$5 -> VALUE,NULL);
                                    else if ( declarationType == SYMBOL_BOOLEAN )
                                        Ginstall($3 -> NAME,SYMBOL_ARRAY_BOOLEAN,$5 -> VALUE,NULL);
                                }
                                
		|vlist ',' ID '(' arglist ')'{
                                        Gtemp = Glookup($3 -> NAME);
                                        if(Gtemp != NULL)
                                        {
                                            printf("Re initialization of identifier\n");
                                            exit(1);
                                        }
                                        if ( declarationType == SYMBOL_INTEGER )
                                            Ginstall($3 -> NAME,SYMBOL_FUNC_INT,-1, Arghead);
                                        else if ( declarationType == SYMBOL_BOOLEAN )
                                            Ginstall($3 -> NAME,SYMBOL_FUNC_BOOLEAN,-1,Arghead);

                                        Arghead = NULL;
                                        Argtail = NULL;
                                    }
		;
        
Type :     INT  {
                    declarationType = SYMBOL_INTEGER;
                }

        |  BOOL {
                    declarationType = SYMBOL_BOOLEAN;
                }
        ;

FType :     INT  {FdeclarationType = SYMBOL_INTEGER;}
        |   BOOL {FdeclarationType = SYMBOL_BOOLEAN;}
        ;

arglist :	arg               {}
		|	arglist ';' arg   {}
		|
		;

arg		:	FType fvlist         {} 
		;
		
fvlist	:	ID                     {
										
										// Ltemp = Llookup($1 -> NAME);
			       //                      if(Ltemp != NULL)
			       //                      {
			       //                          printf("Re initialization of variable\n");
			       //                          exit(1);
			       //                      }
          //                               Linstall($1 -> NAME,FdeclarationType);
                                        //only installing... put in local symbol table at declaration of function
                                            Argtemp = Arglookup($1 -> NAME);
                                            if(Argtemp != NULL)
                                            {
                                                printf("Re initialization of variable in Arglist\n");
                                                exit(1);
                                            }

                                            //should change the declaration type
                                            ArgInstall($1 -> NAME,FdeclarationType); 
                                    }
		|    AMP ID                {        
                                            Argtemp = Arglookup($2 -> NAME);

                                            if(Argtemp != NULL)
                                            {
                                                printf("Re initialization of variable in Arglist\n");
                                                exit(1);
                                            }
										    
                                            if ( FdeclarationType == SYMBOL_INTEGER )
                                              ArgInstall($2 -> NAME,SYMBOL_AMP_INTEGER);

                                        else if ( FdeclarationType == SYMBOL_BOOLEAN )
                                              ArgInstall($2 -> NAME,SYMBOL_AMP_BOOLEAN);

                                    }
        |   fvlist ',' ID          {
                                       /* Ltemp = Llookup($3 -> NAME);
			                            if(Ltemp != NULL)
			                            {
			                                printf("Re initialization of variable\n");
			                                exit(1);
			                            }
                                        Linstall($3 -> NAME,FdeclarationType);*/
                                        Argtemp = Arglookup($3 -> NAME);

                                        if(Argtemp != NULL)
                                        {
                                            printf("Re initialization of variable in Arglist\n");
                                            exit(1);
                                        }

                                        ArgInstall($3 -> NAME,FdeclarationType);


                                    }

        |	fvlist ',' AMP ID      {
                                        /*Ltemp = Llookup($4 -> NAME);
			                            if(Ltemp != NULL)
			                            {
			                                printf("Re initialization of variable\n");
			                                exit(1);
			                            }
			                            if(FdeclarationType == SYMBOL_INTEGER)
			                            {
			                            	FdeclarationType = SYMBOL_AMP_INTEGER;	
			                            }
			                            else
			                            {
			                            	FdeclarationType = SYMBOL_AMP_BOOLEAN;	
			                            }
                                        Linstall($4 -> NAME,FdeclarationType);*/

                                        Argtemp = Arglookup($4 -> NAME);

                                        if(Argtemp != NULL)
                                        {
                                            printf("Re initialization of variable in Arglist\n");
                                            exit(1);
                                        }
                                        if ( FdeclarationType == SYMBOL_INTEGER )
                                            ArgInstall($4 -> NAME,SYMBOL_AMP_INTEGER);

                                        else if ( FdeclarationType == SYMBOL_BOOLEAN )
                                            ArgInstall($4 -> NAME,SYMBOL_AMP_BOOLEAN);
                                    }
		;



fdeflist : fdef 				{}
			| fdeflist fdef 	{}
			;

fdef : Type ID '(' arglist ')' '{' ldeclaration body '}'	{  //code to be written
																/*validateFunction($2->NAME,decl_type,$4,$8);
                                                            	$2->Lentry = Lhead;
																codegen_function($2->NAME,$8);
																ReinitialiseLocalVariables();*/
                                                                // printf("IN fdef\n");
                                                                Gtemp = Glookup($2 -> NAME);

                                                                if(Gtemp == NULL)
                                                                {
                                                                    printf("Function not declared in GST\n");
                                                                    exit(1);
                                                                }

                                                                //storing arguments in LST

                                                                Argtemp1 = Arghead;
                                                                Argtemp2 = Gtemp -> Arglist;

                                                                while((Argtemp1 !=NULL)&&(Argtemp2 != NULL))
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

                                                                if((Argtemp1 !=NULL)||(Argtemp2 != NULL))
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

                                                                
                                                                //Ptr3=body and Ptr2 = lsymbol table
                                                                // Gtemp -> BINDING = TreeCreate($1,NODE_FUNC,$2 -> NAME,
                                                                                                           // 0,$4,NULL,$7,$8,NULL);
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
ldec : Type lvlist ';'    {
                                // $$ = Lhead;
                           }
    ;
lvlist : ID              {
                            Ltemp = Llookup($1 -> NAME);
                            if(Ltemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            Linstall($1 -> NAME,declarationType);
                            // $$ = Lhead;
                        }

        |lvlist ',' ID   {
                            Ltemp = Llookup($3 -> NAME);
                            if(Ltemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            Linstall($3 -> NAME,declarationType);

                            // $$ = Lhead;
                        }
		;	

mainblock : INT MAIN '(' ')' '{' ldeclaration body '}'	
							{
								
                                //$2 -> Lentry = Lhead;

                                // printf("IN MAIN\n");
                                fprintf(intermediate, "MAIN:\n");
                                fprintf(intermediate, "PUSH BP\n");
                                fprintf(intermediate, "MOV BP,SP\n");

                                Ltemp = Lhead;

                                while(Ltemp != NULL)
                                {                                                                
                                    fprintf(intermediate, "PUSH R0\n");
                                    Ltemp = Ltemp -> NEXT;
                                }
                                
                                printf("entering\n");
                                codegen($7);
                                printf("entering\n");                              

                                
                                //ptr3=body and ptr2 = lsymbol table
                                // Gtemp -> BINDING = TreeCreate($1,NODE_FUNC,$2 -> NAME,
                                                                                // 0,$4,NULL,$7,$8,NULL);
                                Lhead = NULL;
                                Ltail = NULL;
 							}
	      ; 

body : START slist retstmt END 	{
                                    //printf("created\n");
									$$ = TreeCreate(TYPE_VOID, DEFAULT, NULL,0,NULL,$2,$3,NULL);
                                }
	;


retstmt : RETURN expr ';'	{	
								$$ = TreeCreate($2->TYPE, NODE_RET,NULL,0,NULL,NULL,$2,NULL);
							}
		;

slist : slist stmt   {
							head=(struct Tnode *)malloc(sizeof(struct Tnode ));
							head -> NODE = DEFAULT;
                            head -> Ptr1 = $1;
                            //printf("----------------------\n");
                            //printf("%d\n",head->Ptr1->NODE);
                            head -> Ptr2 = $2;
                            //printf("%d\n",head->Ptr2->NODE);
                           // printf("----------------------\n");
                            $$=head;
                        }   
        | stmt          {
                            $$=$1;
                            //printf("-----%d----\n",$1->NODE);
                                                        
                        }
        
        ;

stmt : ID ASGN expr ';'         {
                                    /*printf(" in ASGN \n");*/

                                    Ltemp = Llookup($1 -> NAME);

                                    if(Ltemp != NULL)
                                    {
                                        if(Ltemp -> TYPE == SYMBOL_INTEGER)
                                        {
                                            $1 -> TYPE = TYPE_INT;
                                        }
                                        else if(Ltemp -> TYPE == SYMBOL_BOOLEAN)
                                        {
                                            $1 -> TYPE = TYPE_BOOL; 
                                        }

                                        
                                    }

                                    else
                                    {
                                        Argtemp = Arglookup($1 -> NAME);
                                        if(Argtemp != NULL)
                                        {
                                            if((Argtemp -> TYPE == SYMBOL_INTEGER) || (Argtemp -> TYPE == SYMBOL_AMP_INTEGER))
                                            {
                                                $1 -> TYPE = TYPE_INT;
                                            }
                                            else if((Argtemp -> TYPE == SYMBOL_BOOLEAN) || (Argtemp -> TYPE == SYMBOL_AMP_BOOLEAN))
                                            {
                                                $1 -> TYPE = TYPE_BOOL; 
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
                                            else if(Gtemp -> TYPE == SYMBOL_ARRAY_BOOLEAN ||Gtemp -> TYPE == SYMBOL_ARRAY_INT )
                                            {
                                                yyerror("conflict in ID NodeType : Expected Variable . Found Array\n");
                                                printf("%s\n",$1 -> NAME);
                                                exit(1);
                                            }
                                            else
                                            {   
                                                $1 -> Gentry = Gtemp;
                                                if(Gtemp -> TYPE == SYMBOL_INTEGER)
                                                {
                                                    $1 -> TYPE = TYPE_INT;
                                                }
                                                else if(Gtemp -> TYPE == SYMBOL_BOOLEAN)
                                                {
                                                    $1 -> TYPE = TYPE_BOOL; 
                                                }
                                                
                                            }
                                        }
                                    }
                                

                                    if($1-> TYPE != $3 -> TYPE)
                                    {
                                        yyerror("conflict in types in assignment\n");
                                        printf("%s\n",$1 -> NAME);
                                        exit(1);
                                    } 
                                    $$ = TreeCreate(TYPE_VOID, NODE_ASGN,NULL,0,NULL,$1,$3,NULL);  
                                }

        | ID '[' expr ']' ASGN expr ';'   {
                                                /*printf(" in ASGN ARRAY\n");*/
                                                Gtemp = Glookup($1 -> NAME);
                                                if(Gtemp == NULL)
                                                {
                                                    printf("Un-declared array\n");
                                                    exit(1);
                                                }
                                                else if(Gtemp -> TYPE == SYMBOL_BOOLEAN ||Gtemp -> TYPE == SYMBOL_INTEGER )
                                                {
                                                    yyerror("conflict in ID NodeType : Expected Variable , Found Array\n");
                                                    printf("%s\n",$1 -> NAME);
                                                    exit(1);
                                                }
                                                else if($3 -> TYPE == TYPE_BOOL)
                                                {
                                                    yyerror("Expected value , Found boolean\n");
                                                    printf("%s\n",$1 -> NAME);
                                                    exit(1);
                                                }
                                                else
                                                {   
                                                    $1 -> Gentry = Gtemp;
                                                    if(Gtemp -> TYPE == SYMBOL_ARRAY_INT)
                                                    {
                                                        $1 -> TYPE = TYPE_INT;
                                                    }
                                                    else if(Gtemp -> TYPE == SYMBOL_ARRAY_BOOLEAN)
                                                    {
                                                        $1 -> TYPE = TYPE_BOOL; 
                                                    }
                                                } 
                                                if($1-> TYPE != $6 -> TYPE)
                                                {
                                                    yyerror("conflict in types in assignment\n");
                                                    printf("%s\n",$1 -> NAME);
                                                    exit(1);
                                                } 
                                                $$ = TreeCreate(TYPE_VOID, NODE_ARRAY_ASGN,NULL,0,NULL,$1,$3,$6); 
                                          }
        | READ '(' ID ')' ';'   {
        							/*printf(" in READ \n");*/ 
                                    Ltemp = Llookup($3 -> NAME);

                                    if(Ltemp != NULL)
                                    {
                                        if(Ltemp -> TYPE == SYMBOL_INTEGER)
                                        {
                                            $3 -> TYPE = TYPE_INT;
                                        }
                                        else if(Ltemp -> TYPE == SYMBOL_BOOLEAN)
                                        {
                                            //$3 -> TYPE = TYPE_BOOL;
                                            yyerror("Boolean variable can not be read\n");
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
                                            if((Argtemp -> TYPE == SYMBOL_INTEGER) || (Argtemp -> TYPE == SYMBOL_AMP_INTEGER))
                                            {
                                                $3 -> TYPE = TYPE_INT;
                                            }
                                            else if((Argtemp -> TYPE == SYMBOL_BOOLEAN) || (Argtemp -> TYPE == SYMBOL_AMP_BOOLEAN))
                                            {
                                                yyerror("Boolean variable can not be read\n");
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
                                            else if(Gtemp -> TYPE == SYMBOL_ARRAY_BOOLEAN ||Gtemp -> TYPE == SYMBOL_ARRAY_INT )
                                            {
                                                yyerror("conflict in ID NodeType : Expected Array . Found Variable\n");
                                                printf("%s\n",$3 -> NAME);
                                                exit(1);
                                            }
                                            else
                                            {   
                                                $3 -> Gentry = Gtemp;
                                                if(Gtemp -> TYPE == SYMBOL_INTEGER)
                                                {
                                                    $3 -> TYPE = TYPE_INT;
                                                }
                                                else if(Gtemp -> TYPE == SYMBOL_BOOLEAN)
                                                {
                                                    //$3 -> TYPE = TYPE_BOOL;
                                                    yyerror("Boolean variable can not be read\n");
                                                    printf("%s\n",$3 -> NAME);
                                                    exit(1);
                                                }
                                            }
                                        }
                                    }
                                    $$ = TreeCreate(TYPE_VOID, NODE_READ,NULL,0,NULL,NULL,$3,NULL); 
        						} 

        | READ '(' ID '[' expr ']' ')' ';'   {
                                                /*printf(" in READ ARR\n");*/  
                                                Gtemp = Glookup($3 -> NAME);
                                                if(Gtemp == NULL)
                                                {
                                                    yyerror("Un-declared array\n");
                                                    exit(1);
                                                }
                                                else if(Gtemp -> TYPE == SYMBOL_BOOLEAN ||Gtemp -> TYPE == SYMBOL_INTEGER )
                                                {
                                                    yyerror("conflict in ID NodeType : Expected Variable , Found Array\n");
                                                    printf("%s\n",$3 -> NAME);
                                                    exit(1);
                                                }          
                                                else if($5 -> TYPE == TYPE_BOOL)
                                                {
                                                    yyerror("Expected value , Found boolean\n");
                                                    printf("%s\n",$3 -> NAME);
                                                    exit(1);
                                                }                                          
                                                else
                                                {   
                                                    $3 -> Gentry = Gtemp;
                                                    if(Gtemp -> TYPE == SYMBOL_ARRAY_INT)
                                                    {
                                                        $3 -> TYPE = TYPE_INT;
                                                    }
                                                    else if(Gtemp -> TYPE == SYMBOL_ARRAY_BOOLEAN)
						                            {
						                                //$3 -> TYPE = TYPE_BOOL;
			 				            				yyerror("Boolean variable can not be read\n");
								                        printf("%s\n",$3 -> NAME);
								             	        exit(1);
						                            }
                                                }
                                                $$ = TreeCreate(TYPE_VOID, NODE_ARRAY_READ,NULL,0,NULL,NULL,$3,$5); 
                                            }
        | WRITE '(' expr ')' ';'  {
        							/*	printf(" in WRITE \n"); */
                                // printf("%d\n",$3 -> TYPE );
									if($3 -> TYPE != TYPE_BOOL)
									{
        								$$ = TreeCreate(TYPE_VOID, NODE_WRITE,NULL,0,NULL,NULL,$3,NULL);
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
                                    if($3 -> TYPE != TYPE_BOOL)
                                    {
                                        yyerror("Expected boolean , Found value\n");
                                        exit(1);
                                    }
        			           		$$ = TreeCreate(TYPE_VOID, NODE_IF,NULL,0,NULL,$3,$6,NULL); 
        			           }
        |IF '(' expr ')' THEN slist ELSE slist ENDIF ';' 
        						{ 
        							/*printf(" in IF_THEN_ELSE \n");*/
        							if($3 -> TYPE != TYPE_BOOL)
                                    {
                                        yyerror("Expected boolean , Found value\n");
                                        exit(1);
                                    }
                                    $$ = TreeCreate(TYPE_VOID, NODE_IF_ELSE,NULL,0,NULL,$3,$6,$8); 
        						}
        |WHILE '(' expr ')' DO slist ENDWHILE ';'
        						{ 
        							/*printf(" in WHILE \n");*/ 
        							if($3 -> TYPE != TYPE_BOOL)
                                    {
                                        yyerror("Expected boolean , Found value\n");
                                        exit(1);
                                    }
                                    $$ = TreeCreate(TYPE_VOID, NODE_WHILE,NULL,0,NULL,$3,$6,NULL); 
        						}
        ;

exprlist : expr                 {
									printf("FIRST : %d\n",$1 -> NODE);
                                    tree_iter = 0;
                                    $$ = $1;
                                }
		|	exprlist ',' expr     {
										printf("SECOND : %d\n",$3 -> NODE);			
                                        indicator = 1;
                                        head = (struct Tnode *)malloc(sizeof(struct Tnode ));
                                        head -> NODE = NODE_EXPR;
                                        head -> Ptr1 = $3;
                                        $3 -> VALUE = ++tree_iter;
                                        head -> Ptr2 = $1;
                                        $$ = head;
                                    }
		;

expr : expr PLUS expr       {
                                /*printf("PLUS\n");*/
                                if($1 -> TYPE == TYPE_INT && $3 -> TYPE == TYPE_INT)
                                {
                                    $$ = TreeCreate(TYPE_INT, NODE_PLUS , NULL,0, NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in PLUS\n");
                                    exit(1);
                                }
                            }
		|expr MINUS expr  	{
                                /*printf("MINUS\n");*/
                                
                                if($1 -> TYPE == TYPE_INT && $3 -> TYPE == TYPE_INT)
                                {
                                    $$ = TreeCreate(TYPE_INT, NODE_MINUS , NULL,0 , NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MINUS\n");
                                    exit(1);
                                }
                            }
		|expr MUL expr      {
                                /*printf("MUL\n");*/
                                
                                if($1 -> TYPE == TYPE_INT && $3 -> TYPE == TYPE_INT)
                                {
                                    $$ = TreeCreate(TYPE_INT, NODE_MUL , NULL,0 , NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MUL\n");
                                    exit(1);
                                }
                            }
        |expr DIV expr      {
                                /*printf("DIV\n");*/
                                
                                if($1 -> TYPE == TYPE_INT && $3 -> TYPE == TYPE_INT)
                                {
                                    $$ = TreeCreate(TYPE_INT, NODE_DIV , NULL,0 , NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MUL\n");
                                    exit(1);
                                }
                            }
        |expr MOD expr      {
                                /*printf("MOD\n");*/
                                
                                if($1 -> TYPE == TYPE_INT && $3 -> TYPE == TYPE_INT)
                                {
                                    $$ = TreeCreate(TYPE_INT, NODE_MOD , NULL,0 , NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MUL\n");
                                    exit(1);
                                }
                            }
        |expr LT expr       {
                                /*printf("LT\n");*/
                                
                                if($1 -> TYPE == TYPE_INT && $3 -> TYPE == TYPE_INT)
                                {
                                    $$ = TreeCreate(TYPE_BOOL, NODE_LT , NULL, 0, NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in LT\n");
                                    exit(1);
                                }
                            }
        |expr LE expr       {
                                /*printf("LT\n");*/
                                
                                if($1 -> TYPE == TYPE_INT && $3 -> TYPE == TYPE_INT)
                                {
                                    $$ = TreeCreate(TYPE_BOOL, NODE_LE , NULL, 0, NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in LE\n");
                                    exit(1);
                                }
                            }
        |expr GT expr       {
                                /*printf("GT\n");*/
                                if($1 -> TYPE == TYPE_INT && $3 -> TYPE == TYPE_INT)
                                {
                                    $$ = TreeCreate(TYPE_BOOL, NODE_GT , NULL, 0, NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in GT\n");
                                    exit(1);
                                }
                            }
        |expr GE expr       {
                                /*printf("GT\n");*/
                                if($1 -> TYPE == TYPE_INT && $3 -> TYPE == TYPE_INT)
                                {
                                    $$ = TreeCreate(TYPE_BOOL, NODE_GE , NULL, 0, NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in GE\n");
                                    exit(1);
                                }
                            }        
        |expr DEQ expr      {
                                /*printf("DEQ\n");*/
                                if($1 -> TYPE == TYPE_INT && $3 -> TYPE == TYPE_INT)
                                {
                                    $$ = TreeCreate(TYPE_BOOL, NODE_DEQ, NULL, 0, NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in DEQ\n");
                                    exit(1);
                                }
                            }
        |expr NEQ expr      {
                                /*printf("NEQ\n");*/
                                if($1 -> TYPE == TYPE_INT && $3 -> TYPE == TYPE_INT)
                                {
                                    $$ = TreeCreate(TYPE_BOOL, NODE_NEQ, NULL, 0, NULL, $1, $3, NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in NEQ\n");
                                    exit(1);
                                }
                            }
        |expr AND expr		{
        						if($1 -> TYPE == TYPE_BOOL && $3 -> TYPE == TYPE_BOOL)
        						{
        							$$ = TreeCreate(TYPE_BOOL, NODE_AND, NULL, 0, NULL, $1, $3, NULL);
        						}
        						else
                                {
                                    yyerror("conflict in operand types in AND\n");
                                    exit(1);
                                }	
        					}
        |expr OR expr		{
        						if($1 -> TYPE == TYPE_BOOL && $3 -> TYPE == TYPE_BOOL)
        						{
        							$$ = TreeCreate(TYPE_BOOL, NODE_OR, NULL, 0, NULL, $1, $3, NULL);
        						}
        						else
                                {
                                    yyerror("conflict in operand types in OR\n");
                                    exit(1);
                                }	
        					}
        |NOT expr			{
        						if($2 -> TYPE == TYPE_BOOL)
        						{
        							$$ = TreeCreate(TYPE_BOOL, NODE_NOT, NULL, 0, NULL, NULL, $2, NULL);
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
        | NUM	            {
                                /*printf("NUM\n");*/
                                $$ = $1;
                            }
        | ID 				{
                                /*printf("ID\n");*/
                                Ltemp = Llookup($1 -> NAME);

                                if(Ltemp != NULL)
                                {
                                    if(Ltemp -> TYPE == SYMBOL_INTEGER)
                                    {
                                        $1 -> TYPE = TYPE_INT;
                                    }
                                    else if(Ltemp -> TYPE == SYMBOL_BOOLEAN)
                                    {
                                        $1 -> TYPE = TYPE_BOOL; 
                                    }
                                    // printf("IN1234\n");
                                    $$ = $1;
                                }

                                else
                                {
                                    Argtemp = Arglookup($1 -> NAME);
                                    if(Argtemp != NULL)
                                    {
                                        if((Argtemp -> TYPE == SYMBOL_INTEGER) || (Argtemp -> TYPE == SYMBOL_AMP_INTEGER))
                                        {
                                            $1 -> TYPE = TYPE_INT;
                                        }
                                        else if((Argtemp -> TYPE == SYMBOL_BOOLEAN) || (Argtemp -> TYPE == SYMBOL_AMP_BOOLEAN))
                                        {
                                            $1 -> TYPE = TYPE_BOOL; 
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
                                        else if(Gtemp -> TYPE == SYMBOL_ARRAY_BOOLEAN ||Gtemp -> TYPE == SYMBOL_ARRAY_INT )
                                        {
                                            yyerror("conflict in ID NodeType : Expected Variable . Found Array\n");
                                            printf("%s\n",$1 -> NAME);
                                            exit(1);
                                        }
                                        else
                                        {   
                                            $1 -> Gentry = Gtemp;
                                            if(Gtemp -> TYPE == SYMBOL_INTEGER)
                                            {
                                                $1 -> TYPE = TYPE_INT;
                                            }
                                            else if(Gtemp -> TYPE == SYMBOL_BOOLEAN)
                                            {
                                                $1 -> TYPE = TYPE_BOOL; 
                                            }
                                            $$ = $1;
                                        }
                                    }
                                 }
                            }

        | ID '[' expr ']'   {
                                /*printf("ID[expr]\n");*/
                                Gtemp = Glookup($1 -> NAME);
                                if(Gtemp == NULL)
                                {
                                    yyerror("Un-declared array\n");
                                    printf("%s\n",$1 -> NAME);
                                    exit(1);
                                }
                                else if(Gtemp -> TYPE == SYMBOL_BOOLEAN ||Gtemp -> TYPE == SYMBOL_INTEGER )
                                {
                                    yyerror("conflict in ID NodeType : Expected Array , Found Variable\n");
                                    printf("%s\n",$1 -> NAME);
                                    exit(1);
                                }
                                else if($3 -> TYPE == TYPE_BOOL)
                                {
                                    yyerror("Expected value , Found boolean\n");
                                    printf("%s\n",$1 -> NAME);
                                    exit(1);
                                }
                                else
                                {   
                                    $1 -> Gentry = Gtemp;
                                    if(Gtemp -> TYPE == SYMBOL_ARRAY_INT)
                                    {
                                        $1 -> TYPE = TYPE_INT;
                                    }
                                    else if(Gtemp -> TYPE == SYMBOL_ARRAY_BOOLEAN)
                                    {
                                        $1 -> TYPE = TYPE_BOOL; 
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

                                    else if(Gtemp -> TYPE == SYMBOL_BOOLEAN ||Gtemp -> TYPE == SYMBOL_INTEGER )
                                    {
                                        yyerror("conflict in ID NodeType : Expected Function . Found Variable\n");
                                        printf("%s\n",$1 -> NAME);
                                        exit(1);
                                    }

                                    else if(Gtemp -> TYPE == SYMBOL_ARRAY_BOOLEAN ||Gtemp -> TYPE == SYMBOL_ARRAY_INT )
                                    {
                                        yyerror("conflict in ID NodeType : Expected Function . Found Array\n");
                                        printf("%s\n",$1 -> NAME);
                                        exit(1);
                                    }
                                    else
                                    {   
                                        $1 -> Gentry = Gtemp;
                                        if(Gtemp -> TYPE == SYMBOL_FUNC_INT)
                                        {
                                            $1 -> TYPE = TYPE_INT;
                                        }
                                        else if(Gtemp -> TYPE == SYMBOL_FUNC_BOOLEAN)
                                        {
                                            $1 -> TYPE = TYPE_BOOL; 
                                        }
                                        
                                    }
                                    Arg_callee = $3 -> Ptr3 = Gtemp -> Arglist;  //used to find the arglist of callee function
                                    //differentiating b/w one and more than one arguments
                                    // printtree($3);
                                    if(indicator == 1)
                                    {
                                        $$ = TreeCreate($1 -> TYPE,NODE_FUNC,$1 -> NAME,0,Gtemp -> Arglist,NULL,$3,NULL);
                                        indicator = 0;
                                    }
                                    else
                                        $$ = TreeCreate($1 -> TYPE,NODE_FUNC,$1 -> NAME,0,Gtemp -> Arglist,NULL,NULL,$3);

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
    if(argc > 1)
    {
        fp = fopen(argv[1],"r");
        if(fp)
            yyin = fp;
    }    
    yyparse(); 
    return 1; 
}
