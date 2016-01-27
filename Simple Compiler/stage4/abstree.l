%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
    #include "abstree.h"
	int number;
%}

%%

[a-z]	{yylval.nptr = TreeCreate(TYPE_VOID,NODE_ID,yytext,0,NULL,NULL,NULL,NULL); /*printf("%c \n",*yytext);*/return ID;}
[0-9]+	{ number = atoi(yytext);yylval.nptr = TreeCreate(TYPE_INT,NODE_NUM,NULL,number,NULL,NULL,NULL,NULL);
					/*printf("%d \n",atoi(yytext));*/return NUM;}
"read"	{ /*printf("READ ");*/return READ;}
"write"	{  /*printf("WRITE ");*/return WRITE;}
"if"	{return IF;}
"else"	{return ELSE;}
"then"	{return THEN;}
"endif"	{return ENDIF;}
"while" {return WHILE;}
"do"	{return DO;}
"endwhile" {return ENDWHILE;}
"<"		{return LT;}
">"		{return GT;}
"=="	{return DEQ;}
[=]		{ /* printf("ASGN \n");*/return ASGN;}
[ \t] 	{}
"-"		{/*printf("- ");*/return MINUS;}
"+"		{/*printf("+ \n");*/return PLUS;}
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
