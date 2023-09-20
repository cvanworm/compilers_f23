CC = gcc

all: lex clex run

lex: lexer.lex
	lex lexer.lex

clex: lex.yy.c
	$(CC) -g -o clex lex.yy.c

run: clex
	./clex > results.txt

clean: 
	rm clex lex.yy.c results.txt