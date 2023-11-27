code = 1

all: parser py

copy: tiniest.txt
	cp ./examples/tiny_example_$(code).txt tiniest.txt

parser: ./yacc/yacc_1_imports.py ./yacc/yacc_2_func_proc_param.py ./yacc/yacc_3_statements.py ./yacc/yacc_4_math.py ./yacc/yacc_5_run.py
	cat ./yacc/yacc_1_imports.py ./yacc/yacc_2_func_proc_param.py ./yacc/yacc_3_statements.py ./yacc/yacc_4_math.py ./yacc/yacc_5_run.py > yaccf23.py


py: yaccf23.py
	python3 yaccf23.py

# py: yaccf23.py
# 	python3 yaccf23.py -all > results.txt

f23: f23.c
	gcc f23.c -lm -o a.out

run: a.out
	./a.out
	
clean: 
	rm parser.out parsetab.py results.txt a.out
