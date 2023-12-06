code = scope

all: copy parser py 

copy: tiniest.txt
	cp ./examples/${code}.f23 tiniest.txt

# copy: tiniest.txt
# 	cp ./examples/tiny_example_$(code).txt tiniest.txt


parser: ./yacc/*.py
	cat ./yacc/yacc_1* ./yacc/yacc_2* ./yacc/yacc_3* ./yacc/yacc_4* ./yacc/yacc_5* ./yacc/yacc_run.py > yaccf23.py


py: yaccf23.py
	python3 yaccf23.py -all 

# py: yaccf23.py
# 	python3 yaccf23.py -all > results.txt

f23: f23.c
	gcc f23.c -lm -o a.out

run: a.out
	./a.out
	
clean: 
	rm parser.out parsetab.py results.txt a.out
