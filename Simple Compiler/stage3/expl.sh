yacc -d expl.y
lex expl.l
gcc lex.yy.c y.tab.c -o expl
./expl