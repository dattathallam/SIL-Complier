%{
	#include <stdio.h>
	#include <stdlib.h>
%}

Num [0-9]*
OP [-|+|*|/]
NL [\n]
%%

{Num}  {printf("%s %d",*yytext,yyleng);return Num;}
{OP}      {printf("%c ",*yytext);return *yytext;}
{NL}   {}
%%

int yyerror(const char *s)
{
    printf("\nyyerror : %s\n",s);
	return 1;
}

int yywrap()
{
	printf("wrapping time\n");
	return 1;
}

int main()
{
	yylex();
	return 1;
}