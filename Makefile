CC = gcc

all: lex clex run

lex: test.lex
	lex test.lex

clex: lex.yy.c
	$(CC) -g -o clex lex.yy.c

run: clex
	./clex > results.txt

clean: 
	rm clex lex.yy.c