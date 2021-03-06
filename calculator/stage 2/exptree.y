%{ 
    #include <stdio.h>
    #include <stdlib.h>
    #include "exptree.h"
    #include "exptree.c"
    int yylex(void);
    void yyerror(char const *s);
    #define YYSTYPE tnode *

%}


%token NUMBER
%token NL
%left '-' '+' 
%left '*' '/'

%%

program : program expr NL  {    
                        $$ = $2;
                        printf("Answer : %d\n",evaluate($2));
                    }
        |
        ;

expr : expr '+' expr        {$$ = makeOperatorNode('+',$1,$3);}
        | expr '-' expr     {$$ = makeOperatorNode('-',$1,$3);}
        | expr '*' expr     {$$ = makeOperatorNode('*',$1,$3);}
        | expr '/' expr     {$$ = makeOperatorNode('/',$1,$3);}
        | '(' expr ')'      {$$ = $2;}
        | NUMBER            {$$ = $1;}
        ;
 

%%

void yyerror(char const *s)
{
	printf("yyerror - line %d : character %d %s",yylineno,yychar,s);
	return;
}


int main(void) 
{
   yyparse();
   return 0;
}
