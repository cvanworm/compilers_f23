# Overview
This program is a part of the compiler project for the course "Compiler Construction" at the University of Wyoming. **Languages include**: ply, python **Libraries included:** bigtree

## Lexer
Our lexer (lexf23.py) returns a series of tokens to our parser.

## Parser
Our parser (yaccf23.py) defines a context free grammar that outlines the structure of the language given in class. This file is split into 6 seperate python files that are compiled into yaccf23.py at compile time. These files can be found in the yacc folder.

## Symbol Table
Our symbol table (symbol_table.py) is a list that stores the variables and their values and other helpful information.

## Abstract Syntax Tree
Our abstract syntax tree (astf23.py) is a tree that stores the structure of the program. It is used to help generate the code.

## Code Generator
Our code generator (codegenf23.py) generates code for the program. It walks the abstract syntax tree and generates code for each node. This file calls functions in genrator.py (spelled wrong once, kept it for fun) to actually output lines of code to yourmain.h.

## Our examples
Our class language, individual examples, and tiny examples can be found in the examples folder.

## How to run
- `$ make ` to compile and run tiny example 1 (tiny_example_1.txt)
- `$ make code=2 ` to compile and run on the other tiny example
- `$ make clean ` to remove extra files.

## Technologies
This program uses ply and bigtree. Ply is the Python yacc and lex library. Bigtree is a library used to visualize the abstract syntax tree. To download these libraries on Linux use the commands below. [Read more here](https://www.geeksforgeeks.org/flex-fast-lexical-analyzer-generator/)
- `$ sudo apt install python3-pip`
- `$ pip install ply`
- `$ pip install 'bigtree[all]'`

### Authors
- Calvin VanWormer
- Alicia Thoney