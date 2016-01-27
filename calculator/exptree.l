%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
	int number;

%}

NUMBER  [0-9]+
OP 		[-|+|*|/]

%%

{NUMBER} {number =  atoi(yytext);/*printf("%d ",number);exit(1);*/yylval = makeLeafNode(number); return NUMBER;}
{OP}	{return *yytext;}
[\t] 	{}
[()] 	{return *yytext;}
[\n] 	{return NL;}
. 		{yyerror("unknown character\n");exit(1);}

%%

int yywrap()
{
	return 1;
}
