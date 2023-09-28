code = fib.f23

all: lex yacc clex run

lex: lexer.lex
	lex lexer.lex

yacc: text.yacc
	yacc -d text.yacc

clex: lex.yy.c
	gcc -o clex lex.yy.c y.tab.c -w

run: clex
	./clex < $(code) > results.txt

clean: 
	rm clex lex.yy.c results.txt y.tab.c y.tab.h
