code = tiny_example_1.txt

all: lex yacc clex run py

lex: lexer.lex
	lex lexer.lex

yacc: parse.yacc
	yacc -d parse.yacc

clex: lex.yy.c
	gcc -o clex lex.yy.c y.tab.c -w

run: clex
	./clex < $(code) > results.txt

py: addNodeNums.py
	python3 addNodeNums.py

clean: 
	rm clex lex.yy.c results.txt y.tab.c y.tab.h
