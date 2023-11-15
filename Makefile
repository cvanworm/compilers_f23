code = 1

all: copy py

copy: tiniest.txt
	cp ./examples/tiny_example_$(code).txt tiniest.txt

py: yaccf23.py
	python3 yaccf23.py -all > results.txt

clean: 
	rm parser.out parsetab.py results.txt
