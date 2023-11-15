# Yacc example
import ply.yacc as yacc
# Get the token map from the lexer.  This is required.
from lexf23 import tokens
# Get the symbol table
import symtablef23 as symbol_table
# Get the AST
from astf23 import program_node, function_node, print_ast, node, statements_node, procedure_node
# code generation
from codegenf23 import main
# flags
import sys

def p_program(p):
    'program : K_PROGRAM ID LCURLY program_body RCURLY'
    p[0] = program_node(p[2], [p[4]])
    SymbolTable.add('global', p[1], p[2])
    print("valid code".upper())
    return p[0]

def p_program_body(p):
    '''program_body : program_body program_body'''
    p[0] = [p[2], p[1]]

def p_program_body_fp(p):
    '''program_body : function
                    | procedure'''
    p[0] = p[1]

def p_program_body_empty(p):
    'program_body : epsilon'
    p[0] = None

def p_function(p):
    'function : K_FUNCTION K_INTEGER ID LPAREN RPAREN LCURLY statements RCURLY'
    p[7] = statements_node(p[7])
    p[0] = function_node(p[3], p[2], p[7])
    SymbolTable.add('function', p[1], p[3])

def p_procedure(p):
    'procedure : K_PROCEDURE ID LPAREN parameter_list RPAREN LCURLY statements RCURLY'
    p[7] = statements_node(p[7])
    p[0] = procedure_node(p[2], [p[4]], p[7])
    SymbolTable.add('procedure', p[1], p[2])

def p_parameter_list(p):
    '''parameter_list : parameter_list COMMA parameter
                      | parameter'''
    if len(p) == 4:
        p[0] = [p[3], p[1]]
    else:
        p[0] = p[1]

def p_parameter(p):
    '''parameter : K_INTEGER ID
                | K_DOUBLE ID
                | K_STRING ID'''
    p[0] = (p[2], p[1])
    SymbolTable.add('parameter', p[1], p[2], '', p[1])

def p_parameter_empty(p):
    'parameter : epsilon'
    p[0] = None


def p_statements(p):
    'statements : statements statements'
    p[0] = [p[2], p[1]]

def p_statements_dapf(p):
    '''statements : declare 
                  | assign 
                  | print 
                  | function_call'''
    p[0] = p[1]

def p_statements_empty(p):
    'statements : epsilon'
    p[0] = None

def p_declare(p):
    '''declare : K_INTEGER ID SEMI
             | K_DOUBLE ID SEMI'''    
    SymbolTable.add('statements', 'id', p[2], '', p[1])
    p[0] = node("DECLARE", p[2], p[1])

def p_assign(p):
    '''assign : ID ASSIGN ICONSTANT SEMI
            | ID ASSIGN DCONSTANT SEMI
            | ID ASSIGN SCONSTANT SEMI
            | ID ASSIGN math SEMI'''
    err = SymbolTable.get_value('statements', p[1])
    if err == None:
        sys.exit("Error: variable " + p[1] + " not declared on line " + str(p.lineno(1)))
    SymbolTable.add('statements', 'id', p[1], p[3])
    p[0] = node("ASSIGN", p[3], p[1])


def p_print(p):
    '''print : K_PRINT_INTEGER LPAREN ID RPAREN SEMI
             | K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI
             | K_PRINT_STRING LPAREN ID RPAREN SEMI
             | K_PRINT_DOUBLE LPAREN ID RPAREN SEMI'''
    p[0] = node("PRINT", p[3], p[1])

def p_function_call(p):
    'function_call : ID LPAREN ID RPAREN SEMI'
    p[0] = node("function call", p[1], p[3])

def p_math(p):
    'math : expression'
    p[0] = p[1]

def p_expression(p):
    '''expression : expression PLUS term
                | expression MINUS term'''
    print("p[1]", p[1])
    print("p[2]", p[2])
    if p[2] == '+':
        p[0] = p[1] + p[3]
    else:
        p[0] = p[1] - p[3]

def p_expression_term(p):
    'expression : term'
    p[0] = p[1]

def p_term(p):
    '''term : term TIMES factor
            | term DIVIDE factor'''
    print("Term:", p[2], p[1], p[3])
    if p[2] == '*':
        p[0] = p[1] * p[3]
    else:
        p[0] = p[1] / p[3]

def p_term_factor(p):
    'term : factor'
    p[0] = p[1]

def p_factor_expr(p):
    '''factor : LPAREN expression RPAREN
              | MINUS LPAREN expression RPAREN'''
    if p[1] == '(':
        # p[0] = ("Factor:", p[1], p[2], p[3])    
        # p[2] = p[2]
        # p[0] = leaf_node("") 
        p[0] = (p[2])  
    else:
        # p[0] = ("Factor:", p[1], p[2], p[3], p[4])
        p[0] = -(p[3])

def p_factor_num(p):
    '''factor : ICONSTANT
            | DCONSTANT'''
    p[0] = p[1]

def p_factor_id(p):
    'factor : ID'
    err = SymbolTable.get_value('statements', p[1])
    if err == None:
        sys.exit("Error: variable " + p[1] + " not defined on line " + str(p.lineno(1)))
    p[0] = err

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
parser = yacc.yacc()

# SymbolTable instance
SymbolTable = symbol_table.SymbolTable()

s = open('tiniest.txt','r').read()
p = parser.parse(s)

main(p, SymbolTable)

if len(sys.argv) > 1:
    if sys.argv[1] == "-s":
        SymbolTable.print()
    elif sys.argv[1] == "-a":
        print_ast(p)
    elif sys.argv[1] == "-r":
        print(p)
    elif sys.argv[1] == "-all":
        print(p)
        print_ast(p)
        SymbolTable.print()

