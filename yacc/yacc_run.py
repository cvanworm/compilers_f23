def p_epsilon(p):
    'epsilon :'
    pass

# Error rule for syntax errors
def p_error(p):
    print("Parse error in input!")
    print(f"Failed on line {p.lineno} at token {p.type} with value {p.value}")


if len(sys.argv) > 1:
    if sys.argv[1] == "-help":
        print("Usage: python3 yaccf23.py [option]")
        print("Options:")
        print("-s\tprint symbol table")
        print("-a\tprint abstract syntax tree")
        print("-r\tprint raw parse data")
        print("-all\tprint symbol table and abstract syntax tree")
        exit()


# Build the parser
parser = yacc.yacc(debug=True)

# SymbolTable instance
SymbolTable = symbol_table.SymbolTable("Parsing")

s = open('tiniest.txt','r').read()
p = parser.parse(s)


if len(sys.argv) > 1:
    if sys.argv[1] == "-s":
        SymbolTable.print()
    elif sys.argv[1] == "-a":
        print_ast(p)
    elif sys.argv[1] == "-r":
        print(p)
    elif sys.argv[1] == "-all":
        # print(p)
        print_ast(p)
        SymbolTable.print()

main(SymbolTable, p)


