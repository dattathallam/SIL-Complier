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
    int declarationType ;
    struct Gsymbol *Gtemp;
%}

%union
{
    struct Tnode * nptr;
};

%token NUM ID PLUS MUL ASGN READ WRITE MINUS NEWLINE LT GT DEQ ELSE IF THEN ENDIF ENDWHILE WHILE DO 
%token START END DECL ENDDECL T INT F BOOL LE GE
%left PLUS MINUS
%left MUL
%right ASGN
%nonassoc LT GT DEQ LE GE
%type <nptr> T
%type <nptr> F
%type <nptr> NUM  
%type <nptr> ID
%type <nptr> PLUS
%type <nptr> MUL
%type <nptr> READ
%type <nptr> WRITE
%type <nptr> MINUS
%type <nptr> LT
%type <nptr> GT
%type <nptr> LE
%type <nptr> GE
%type <nptr> DEQ
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
%%

program : declaration START slist END {
                            printSymbolTable();
                            //result = Evaluate($3);
                            intermediate_codegen($3);
                            printf("executed\n");
                            exit(1);
                        }
        ;
declaration : DECL dlist ENDDECL    {}
            ;
dlist : dec             {}
        | dlist dec     {}
        ;
dec : Type vlist ';'    {}
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
        ;
Type :     INT  {declarationType = SYMBOL_INTEGER;}
        |  BOOL {declarationType = SYMBOL_BOOLEAN;}
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
                                    Gtemp = Glookup($1 -> NAME);
                                    if(Gtemp == NULL)
                                    {
                                        printf("Un-declared variable\n");
                                        exit(1);
                                    }
                                    else if(Gtemp -> TYPE == SYMBOL_ARRAY_BOOLEAN ||Gtemp -> TYPE == SYMBOL_ARRAY_INT )
                                    {
                                        yyerror("conflict in ID NodeType : Expected Array . Found Variable\n");
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
        							Gtemp = Glookup($3 -> NAME);
                                    if(Gtemp == NULL)
                                    {
                                        printf("Un-declared variable\n");
                                        exit(1);
                                    }
                                    else if(Gtemp -> TYPE == SYMBOL_ARRAY_BOOLEAN ||Gtemp -> TYPE == SYMBOL_ARRAY_INT )
                                    {
                                        yyerror("conflict in ID NodeType : Expected Array . Found Variable\n");
                                        printf("%s",$3 -> NAME);
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
                                            $3 -> TYPE = TYPE_BOOL; 
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
                                                    printf("%s",$3 -> NAME);
                                                    exit(1);
                                                }          
                                                else if($5 -> TYPE == TYPE_BOOL)
                                                {
                                                    yyerror("Expected value , Found boolean\n");
                                                    printf("%s",$3 -> NAME);
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
                                                        $3 -> TYPE = TYPE_BOOL; 
                                                    }
                                                }
                                                $$ = TreeCreate(TYPE_VOID, NODE_ARRAY_READ,NULL,0,NULL,NULL,$3,$5); 
                                            }
        | WRITE '(' expr ')' ';'  {
        							/*	printf(" in WRITE \n"); */
        							$$ = TreeCreate(TYPE_VOID, NODE_WRITE,NULL,0,NULL,NULL,$3,NULL);	
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
        | '(' expr ')'      {
                                $$ = $2;
                            }
        | NUM	            {
                                /*printf("NUM\n");*/
                                $$ = $1;
                            }
        | ID 				{
                                /*printf("ID\n");*/
                                Gtemp = Glookup($1 -> NAME);
                                if(Gtemp == NULL)
                                {
                                    yyerror("Un-declared variable\n");
                                    printf("%s\n",$1 -> NAME);
                                    exit(1);
                                }
                                else if(Gtemp -> TYPE == SYMBOL_ARRAY_BOOLEAN ||Gtemp -> TYPE == SYMBOL_ARRAY_INT )
                                {
                                    yyerror("conflict in ID NodeType : Expected Array . Found Variable\n");
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
                                    $$ = TreeCreate($1 -> TYPE,NODE_ARRAY,NULL,0,NULL,$1,$3,NULL);
                                }
                            }
        | T                 {
                                $$ = $1;
                            }
        | F                 {
                                $$ = $1;
                            }

        ;

%%

void yyerror(char const *s) 
{ 
     printf("yyerror - line %d %s\n",yylineno,s); 
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
