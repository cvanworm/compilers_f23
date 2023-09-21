CC = gcc

all: lex clex run

lex: ab.lex
	lex ab.lex

clex: lex.yy.c
	$(CC) -g -o clex lex.yy.c

run: clex
	./clex < $(code) > results.txt

clean: 
	rm clex lex.yy.c results.txt
