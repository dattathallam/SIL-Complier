%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	char d[1000];
	char* file1;
%}

WORD [a-zA-Z]*
NL 		['\n']
SP 		[ ]
%%

{WORD}  {
			if(yyleng == 3)
			{
				if(*yytext == 'A')
				{
					strcpy(d,yytext);
					printf("%s\n",d);
				}
			}
		
		}
{NL}   {}
{SP}	{}
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
	file1 = "b.txt";
	yyin = fopen("b.txt","r");
	yylex();
	return 1;
}