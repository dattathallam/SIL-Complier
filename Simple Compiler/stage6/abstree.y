%{ 
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "abstree.h"
    #include "symboltable.h"
    #include "symboltable.c"
    #include "aa.c"
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
                            result = Evaluate($3);
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
        |vlist ',' ID   {
                            Gtemp = Glookup($3 -> NAME);
                            if(Gtemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            Ginstall($3 -> NAME,declarationType,1,NULL);
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
                                    $$ = TreeCreate(TYPE_VOID, NODE_ASGN,NULL,0,NULL,$1,$3,NULL);  
                                }
        | READ '(' ID ')' ';'   {
        							/*printf(" in READ \n");*/  
        							Gtemp = Glookup($3 -> NAME);
                                    if(Gtemp == NULL)
                                    {
                                        printf("Un-declared variable\n");
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
        | WRITE '(' expr ')' ';'  {
        							/*	printf(" in WRITE \n"); */
        							$$ = TreeCreate(TYPE_VOID, NODE_WRITE,NULL,0,NULL,NULL,$3,NULL);	
        						}
        |IF '(' expr ')' THEN slist ENDIF ';' 
        			           { 
        			           		/*printf(" in IF_THEN \n");*/
        			           		$$ = TreeCreate(TYPE_VOID, NODE_IF,NULL,0,NULL,$3,$6,NULL); 
        			           }
        |IF '(' expr ')' THEN slist ELSE slist ENDIF ';' 
        						{ 
        							/*printf(" in IF_THEN_ELSE \n");*/
        							$$ = TreeCreate(TYPE_VOID, NODE_IF_ELSE,NULL,0,NULL,$3,$6,$8); 
        						}
        |WHILE '(' expr ')' DO slist ENDWHILE ';'
        						{ 
        							/*printf(" in WHILE \n");*/ 
        							$$ = TreeCreate(TYPE_VOID, NODE_WHILE,NULL,0,NULL,$3,$6,NULL); 
        						}
        ;


expr : expr PLUS expr        {/*printf("PLUS\n");*/$$ = TreeCreate(TYPE_INT, NODE_PLUS , NULL,0, NULL, $1, $3, NULL);}
		|expr MINUS expr  	 {/*printf("MINUS\n");*/$$ = TreeCreate(TYPE_INT, NODE_MINUS , NULL,0 , NULL, $1, $3, NULL);}
		|expr MUL expr       {/*printf("MUL\n");*/$$ = TreeCreate(TYPE_INT, NODE_MUL , NULL,0 , NULL, $1, $3, NULL);}
        |expr LT expr        {/*printf("LT\n");*/$$ = TreeCreate(TYPE_BOOL, NODE_LT , NULL, 0, NULL, $1, $3, NULL);}
        |expr GT expr        {/*printf("GT\n");*/$$ = TreeCreate(TYPE_BOOL, NODE_GT , NULL, 0, NULL, $1, $3, NULL);}
        |expr DEQ expr       {/*printf("DEQ\n");*/$$ = TreeCreate(TYPE_BOOL, NODE_DEQ , NULL,0, NULL, $1, $3, NULL);}
        | '(' expr ')'       {$$ = $2;}
        | NUM	             {/*printf("NUM\n");*/$$ = $1;}
        | ID 				 {
                                /*printf("ID\n");*/
                                Gtemp = Glookup($1 -> NAME);
                                if(Gtemp == NULL)
                                {
                                    printf("Un-declared variable\n");
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
        | T 				{$$ = $1;}
        | F					{$$ = $1;}
        ;

%%

void yyerror(char const *s) 
{ 
     printf("yyerror - line %d : character %d %s\n",yylineno,yychar,s); 
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
