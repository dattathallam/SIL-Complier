yacc -d cal.y
lex cal.l
gcc lex.yy.c y.tab.c -o calc
./calc