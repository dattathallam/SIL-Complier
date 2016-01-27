%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    void yyerror();
    int yylex();
    char c = ' ';
    int i = 0; 
%}

%token VARIABLE
%token ER
%token NL

%%

start :  expr NL    {exit(1);}
    ;

expr:  VARIABLE     {printf("Valid variable\n");}
    | ER            {printf("Invalid variable\n");}
    ;

%%

void yyerror(const char *s) 
{ 
    printf("\nyyerror : %s\n",s);
    return; 
} 

yylex()
{
    char input[1000];
    if (c == '\n')
        return NL;
    c = getchar();
    if (!('a' <= c && c <= 'z' ) || (c == '\n')){
        c = '\n';
        return ER;
    }
    while(c != '\n')
    {
        c = getchar();
        if (!((c == '\n' ) || ( '0' <= c && c <= '9') || ('a' <= c && c <= 'z')))
            return ER;  
    }
    
    return VARIABLE;
}

int main()
{
    c = ' ';
    yyparse();
    return 1;
}