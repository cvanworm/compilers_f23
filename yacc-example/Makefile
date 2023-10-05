all: lex yacc clex run

lex: ab.lex
	lex ab.lex

yacc: ab.yacc
	yacc -d ab.yacc

clex: lex.yy.c
	gcc -o clex lex.yy.c y.tab.c -w

run: clex
	./clex

clean: 
	rm clex lex.yy.c results.txt y.tab.c y.tab.h
