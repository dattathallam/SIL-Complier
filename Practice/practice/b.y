%{
    #include <stdio.h>
    #include <stdlib.h>
    int yylex();
    void yyerror();
    int pos = 0;
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

int yylex()
{
    int c; 
    c = getchar(); 
    if(isdigit(c)) 
    { 
        yylval = c - '0';
        return NUMBER; 
    } 
    return c; 
}

int main()
{
    yyparse();
    return 1;
}