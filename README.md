# Lexer
This lexer outputs a series of tokens for a predefined language to a file named `results.txt`. This program is a part of the compiler project for the course "Compiler Construction" at the University of Wyoming. **Languages include**: flex and C

### How to run
- `$ make ` to compile and run lexer on our example program (fib.f23)
- `$ make code=mg.f23 ` to compile and run lexer on the class program (mg.f23)
- `$ make clean ` to remove extra files.

### Technologies
This program uses flex. To download flex on Linux use the commands below. [Read more here](https://www.geeksforgeeks.org/flex-fast-lexical-analyzer-generator/)
- `$ sudo apt-get update`
- `$ sudo apt-get install flex`

### Authors
- Calvin VanWormer
- Alicia Thoney
