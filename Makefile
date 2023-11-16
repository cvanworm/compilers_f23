code = 1

all: copy py f23 run

copy: tiniest.txt
	cp ./examples/tiny_example_$(code).txt tiniest.txt

py: yaccf23.py
	python3 yaccf23.py -all > results.txt

f23: f23.c
	gcc f23.c -lm -o a.out

run: a.out
	./a.out
	
clean: 
	rm parser.out parsetab.py results.txt a.out
