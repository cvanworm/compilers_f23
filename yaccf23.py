# Yacc example
import ply.yacc as yacc
# Get the token map from the lexer.  This is required.
from lexf23 import tokens
# Get the symbol table
from symtablef23 import symbol_add, print_symbol_table
# Get the AST
from astf23 import program_node, function_node, print_ast, leaf_node, statements_node
# flags
import sys

def p_program(p):
    'program : PROGRAM ID LCURLY function RCURLY'
    p[0] = program_node(p[2], [p[4]])
    symbol_add('global', p[1], p[2])
    print("valid code".upper())
    return p[0]

def p_function(p):
    'function : FUNCTION INTEGER ID LPAREN RPAREN LCURLY statements RCURLY'
    p[7] = statements_node(p[7])
    p[0] = function_node(p[3], p[2], [p[7]])
    symbol_add('Function', p[1], p[3])

def p_statements(p):
    'statements : statements statements'
    p[0] = [p[2], p[1]]

def p_statements_empty(p):
    'statements : epsilon'
    p[0] = None

def p_statements_dap(p):
    '''statements : declare 
                | assign 
                | print '''
    p[0] = p[1]

def p_declare(p):
    '''declare : INTEGER ID SEMI
             | DOUBLE ID SEMI'''    
    symbol_add('statements', 'id', p[2], None, p[1])
    p[0] = leaf_node("DECLARE " + p[2], p[2], p[1])

def p_assign(p):
    '''assign : ID ASSIGN ICONSTANT SEMI
            | ID ASSIGN DCONSTANT SEMI'''
    symbol_add('statements', 'id', p[1], p[3])
    p[0] = leaf_node("ASSIGN " + p[1], p[3], p[1])


def p_print(p):
    '''print : PRINT_INTEGER LPAREN ID RPAREN SEMI
             | PRINT_STRING LPAREN SCONSTANT RPAREN SEMI
             | PRINT_DOUBLE LPAREN ID RPAREN SEMI'''
    p[0] = leaf_node(p[1] + " " + p[3], p[3], p[1])


def p_epsilon(p):
    'epsilon :'
    pass

# Error rule for syntax errors
def p_error(p):
    print("Syntax error in input!")


# Build the parser
parser = yacc.yacc()

s = open('tiniest.txt','r').read()
p = parser.parse(s)

print_ast(p)

if len(sys.argv) > 1 and sys.argv[1] == "-s":
    print_symbol_table()