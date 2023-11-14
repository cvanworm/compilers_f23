# Yacc example
import ply.yacc as yacc
# Get the token map from the lexer.  This is required.
from lexf23 import tokens
# Get the symbol table
from symtablef23 import symbol_add, print_symbol_table, symbol_find
# Get the AST
from astf23 import program_node, function_node, print_ast, node, statements_node
# flags
import sys

def p_program(p):
    'program : K_PROGRAM ID LCURLY function RCURLY'
    p[0] = program_node(p[2], [p[4]])
    symbol_add('global', p[1], p[2])
    print("valid code".upper())
    return p[0]

def p_function(p):
    'function : K_FUNCTION K_INTEGER ID LPAREN RPAREN LCURLY statements RCURLY'
    p[7] = statements_node(p[7])
    p[0] = function_node(p[3], p[2], [p[7]])
    symbol_add('function', p[1], p[3])

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
    '''declare : K_INTEGER ID SEMI
             | K_DOUBLE ID SEMI'''    
    symbol_add('statements', 'id', p[2], '', p[1])
    p[0] = node("DECLARE " + p[2], p[2], p[1])

def p_assign(p):
    '''assign : ID ASSIGN ICONSTANT SEMI
            | ID ASSIGN DCONSTANT SEMI
            | ID ASSIGN math SEMI'''
    err = symbol_find('statements', p[1])
    if err == None:
        sys.exit("Error: variable " + p[1] + " not declared on line " + str(p.lineno(1)))
    symbol_add('statements', 'id', p[1], p[3])
    p[0] = node("ASSIGN " + p[1], p[3], p[1])


def p_print(p):
    '''print : K_PRINT_INTEGER LPAREN ID RPAREN SEMI
             | K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI
             | K_PRINT_DOUBLE LPAREN ID RPAREN SEMI'''
    p[0] = node(p[1] + " " + p[3], p[3], p[1])

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
    err = symbol_find('statements', p[1])
    if err == None:
        sys.exit("Error: variable " + p[1] + " not defined on line " + str(p.lineno(1)))
    p[0] = err

def p_epsilon(p):
    'epsilon :'
    pass

# Error rule for syntax errors
def p_error(p):
    print("Parse error in input!")


# Build the parser
parser = yacc.yacc()

s = open('tiniest.txt','r').read()
p = parser.parse(s)

# print(p)
print_ast(p)

if len(sys.argv) > 1 and sys.argv[1] == "-s":
    print_symbol_table()