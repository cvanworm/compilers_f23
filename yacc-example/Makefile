all: lex yacc clex run

lex: math1.lex
	lex math1.lex

yacc: math1.yacc
	yacc -d math1.yacc

clex: lex.yy.c
	gcc -o clex lex.yy.c y.tab.c -w

run: clex
	./clex

clean: 
	rm clex lex.yy.c results.txt y.tab.c y.tab.h
