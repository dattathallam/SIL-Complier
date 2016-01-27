%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	char d[1000];
	char* file1;
	int ind1 = 0;
	int ind3 = 0;
%}

WORD [a-zA-Z0-9]*
CM      [ '//' | '/*' | '*/' ]
NL		[\n]
SP      [' ']
%%

{WORD}  {
			printf("WORD ");
			/*if(ind1 == 1 || ind3 == 1)
			{
				strcpy(d,yytext);printf("%s",d);
			}*/
		}

{CM}	{
			printf("entered ");
			if(strcmp("/*",yytext) == 0 )
			{
				printf("MC1 ");
				/*
				printf("*");
				if(ind1 == 0 && ind3 == 0)
				{
					ind1 = 1;
				}*/
			}
			else if(strcmp("*/",yytext) == 0 )
			{
				printf("MC2\n");
				/*
				printf("*");
				if(ind1 == 1)
					ind1 = 0;
					*/	
			}
			else if(strcmp("//",yytext) == 0 )
			{
				printf("SC ");
				/*
				printf("/");
				if(ind3 == 0 && ind1 == 0)
				{
					ind3 = 1;
				}
				*/
			}
		}

{NL}	{printf("NL ");/*ind3 = 0;printf("\n");*/}
{SP}     {}
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
	file1 = "c.txt";
	yyin = fopen("c.txt","r");
	yylex();
	return 1;
}