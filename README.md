# Overview
This program is a part of the compiler project for the course "Compiler Construction" at the University of Wyoming. **Languages include**: lex, yacc, and C

## Lexer
Our lexer (lexer.lex) returns a series of tokens to our parser.

## Parser
Our parser (parse.yacc) defines a context free grammar that outlines the structure of the language given in class. **Note**: This parser does not parse the entire class language.


## How to run
- `$ make ` to compile and run lexer on tiny example 1 (tiny_example_1.txt)
- `$ make code=tiny_example_2.txt ` to compile and run parser on the other tiny example
- `$ make clean ` to remove extra files.

## Technologies
This program uses lex and yacc. To download lex on Linux use the commands below. [Read more here](https://www.geeksforgeeks.org/flex-fast-lexical-analyzer-generator/)
- `$ sudo apt-get update`
- `$ sudo apt-get install flex`

### Authors
- Calvin VanWormer
- Alicia Thoney