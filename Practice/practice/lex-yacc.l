%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
%}

NUMBER [0-9]+
OP [-|+|*|/|\n]

%%

{NUMBER}  {yylval = atoi(yytext);/*printf("%d ",yylval);*/return NUMBER;}
{OP}      {/*printf("%c ",*yytext);*/return *yytext;}

%%

int yywrap()
{
	printf("wrapping time\n");
	return 1;
}
/*
int main()
{
	yylex();
	return 1;
}
*/