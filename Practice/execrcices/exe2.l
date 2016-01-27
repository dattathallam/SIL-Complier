%{
	#include <stdio.h>
	#include <stdlib.h>
	int c1 =0;
	int c2 = 0 , c3 = 0;
%}

INTEGER [0-9]+
FP      [0-9]*['.'][0-9]*
NL      [\n]
%%

{INTEGER}  {c1++;}
{FP}       {c2++;}
{NL}       {c3++;}
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
	printf("%d ints %d floats %d numbers\n",c1,c2,c3);
	return 1;
}