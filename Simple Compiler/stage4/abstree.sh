yacc -d abstree.y
lex abstree.l
gcc lex.yy.c y.tab.c
./a.out
