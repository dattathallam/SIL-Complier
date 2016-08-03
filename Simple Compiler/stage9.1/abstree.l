%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
    #include "abstree.h"
	int number;
	char * variable;
%}

%%

[0-9]+	{
			number = atoi(yytext);
			yylval.nptr = TreeCreate(TYPE_INT,NODE_NUM,NULL,number,NULL,NULL,NULL,NULL);
			/*printf("%d \n",atoi(yytext));*/
			return NUM;
		}
"main"	{ /*printf("MAIN");*/ return MAIN;}
"AND"	{ /*printf("AND");*/return AND;}
"OR"	{ /*printf("OR");*/return OR;}
"NOT"	{ /*printf("NOT");*/return NOT;}
"read"	{ /*printf("READ ");*/return READ;}
"write"	{  /*printf("WRITE ");*/return WRITE;}
"if"	{return IF;}
"else"	{return ELSE;}
"then"	{return THEN;}
"endif"	{return ENDIF;}
"while" {return WHILE;}
"do"	{return DO;}
"endwhile" {return ENDWHILE;}
"begin"	{return START;}
"end"	{return END;}
"decl"	{return DECL;}
"enddecl" {return ENDDECL;}
"return" {return RETURN;}
"true"	{
			yylval.nptr = TreeCreate(TYPE_BOOL,NODE_T,NULL,TRUE,NULL,NULL,NULL,NULL);
			return T;
		}
"false"	{
			yylval.nptr = TreeCreate(TYPE_BOOL,NODE_F,NULL,FALSE,NULL,NULL,NULL,NULL);
			return F;
		}
"integer"	{return INT;}
"boolean"	{return BOOL;}
[a-zA-Z][a-zA-Z0-9]*	{
			variable = malloc(sizeof(yytext));
			strcpy(variable,yytext);
			yylval.nptr = TreeCreate(TYPE_INT,NODE_ID,variable,0,NULL,NULL,NULL,NULL); 
			/* 
			printf("%s \n",variable);
			*/
			return ID;
		}
[{}]		{return *yytext;}
"&"		{return AMP;}
"<="	{return LE;}
">="	{return GE;}
"<"		{return LT;}
">"		{return GT;}
"=="	{return DEQ;}
"!="	{return NEQ;}
"="		{  /*printf("ASGN \n");*/return ASGN;}
"-"		{/*printf("- ");*/return MINUS;}
"+"		{/*printf("+ \n");*/return PLUS;}
"*"		{/*printf("* ");*/return MUL;}
"/"		{/*printf("/ ");*/return DIV;}
"%"		{/*printf("% ");*/return MOD;}
[ \t] 	{}
"["		{return *yytext;}
"]"		{return *yytext;}
[()] 	{/*printf("PAR ");*/return *yytext;}
[,;]		{/*printf("SC ");*/return *yytext;}
[\n] 	{/*printf("NL ");return NEWLINE;*/}
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