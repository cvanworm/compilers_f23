CC = gcc

all: lex clex run

lex: lexer.lex
	lex lexer.lex

clex: lex.yy.c
	$(CC) -g -o clex lex.yy.c

run: clex
	./clex < mg.f23 > results.txt

clean: 
	rm clex lex.yy.c results.txt