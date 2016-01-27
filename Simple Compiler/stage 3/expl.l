%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
%}

%%

[a-z]	{yylval.character = yytext[0];/* printf("%c ",*yytext);*/return ID;}
[0-9]+	{yylval.integer = atoi(yytext);/* printf("%d ",atoi(yytext));*/return NUM;}
"read"	{/* printf("READ ");*/return READ;}
"write"	{/*  printf("WRITE ");*/return WRITE;}
[=]		{/*  printf("ASGN ");*/return ASGN;}
[ \t] 	{}
"-"		{/*printf("- ");*/return MINUS;}
"+"		{/*printf("+ ");*/return PLUS;}
"*"		{/*printf("* ");*/return MUL;}
[()] 	{/*printf("PAR ");*/return *yytext;}
";"		{/*printf("SC ");*/return *yytext;}
[\n] 	{/*printf("NL ");*/return NEWLINE;}
. 		{yyerror("unknown character\n");exit(1);}

%%

int yywrap()
{
	return 1;
}

/*
void yyerror(char const *s)
{
    printf("yyerror %s",s);
    return;
}

int main()
{
	yylex();
	return 0;
}
*/