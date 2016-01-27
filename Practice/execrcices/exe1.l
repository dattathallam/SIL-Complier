%{
	#include <stdio.h>
	#include <stdlib.h>
	int newlines = 0;
	int characters = 0;
	int words = 0;
	char *file;
%}

WORD [a-zA-z]+
NL [\n]
%%

{WORD} {words++; characters+= yyleng;}
{NL} {newlines++;}

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
	file = "a.txt";
	yyin = fopen("a.txt","r");
	yylex();
	printf("%d lines %d characters %d spaces %d words\n",newlines+1,characters,words-newlines-1,words);
	return 1;
}