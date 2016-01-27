%{
    #include <stdio.h>
    #include <stdlib.h>
    int yylex();
    void yyerror();
    int *var[26];
%}

%union
{
	int integer;
	char character;
};

%token NUM ID PLUS MUL ASGN READ WRITE MINUS NEWLINE
%left PLUS MINUS
%left MUL
%type <integer>   NUM  
%type <character> ID
%type <integer> expr
%type <integer> slist
%type <integer> stmt

%%

program : slist NEWLINE	{
							printf("executed\n");
							exit(1);
						}
		;
slist : slist stmt  	{

						}   
		| stmt   		{
				
						}
    	;

stmt : ID ASGN expr ';'			{
									if(var[$1-'a'] == NULL)
									{
									    var[$1 - 'a'] = malloc(sizeof(int));
									}
									*var[$1 - 'a'] = $3;
									/*printf("--ASGN--\n");*/

								}
		| READ '(' ID ')' ';'   {
									if(var[$3-'a'] == NULL)
									{
									    var[$3 - 'a'] = malloc(sizeof(int));
									}
									scanf("%d",var[$3-'a']);
									/*printf("--READ--\n");*/

								} 
		| WRITE '(' expr ')' ';'{
									printf("%d\n",$3);
									/*printf("--WRITE--\n");*/
								}
		;

expr : expr PLUS expr        {$$ = $1+$3;}
		|expr MINUS expr	{$$ = $1-$3;}
		|expr MUL expr      {$$ = $1*$3;}
        | '(' expr ')'      {$$ = $2;}
        | NUM	            {$$ = $1;}
        | ID 				{
        						if(var[$1 - 'a'] == NULL)
        						{
        							printf("unassigned variable\n");
        						}
        						else
        						{
        							$$ = *var[$1 - 'a'];
        						}
        					}
        ;
%%

void yyerror(char const *s)
{
    printf("yyerror %s\n",s);
    return;
}

int main()
{
	yyparse();
	return 1;
}
