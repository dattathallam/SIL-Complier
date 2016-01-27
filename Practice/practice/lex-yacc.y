%{
    #include <stdio.h>
    #include <stdlib.h>
    int yylex();
    void yyerror();
%}

%token NUMBER
%left '-' '+'
%left '*' '/'

%%

start :  expr '\n'    {exit(1);}
    ;

expr:  expr '+' expr    {printf("+ ");}
    | expr '-' expr     {printf("- ");}
    | expr '*' expr     {printf("* ");}
    | expr '/' expr     {printf("/ ");}
    | NUMBER            {printf("%d ",$1);}
    ;
%%

void yyerror(const char *s) 
{ 
    printf("\nyyerror : %s\n",s);
    return; 
} 

int main()
{
    yyparse();
    return 1;
}