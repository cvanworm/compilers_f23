# Yacc example
import ply.yacc as yacc
# Get the token map from the lexer.  This is required.
from lexf23 import tokens
# Get the symbol table
import symtablef23 as symbol_table
# Get the AST
from astf23 import program_node, function_node, print_ast, node, statements_node, procedure_node, logic_node
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

def p_type(p):
    '''type : K_INTEGER
            | K_DOUBLE
            | K_STRING'''
    p[0] = p[1]

def p_return(p):
    '''return : K_RETURN value SEMI'''
    p[0] = {"name": f"RETURN {p[2]}"}

def p_return_empty(p):
    'return : epsilon'
    p[0] = None

def p_function(p):
    'function : K_FUNCTION type ID LPAREN parameter_list RPAREN LCURLY statements return RCURLY'
    p[8] = statements_node([p[8]])
    p[0] = function_node(p[3], p[2], p[8]+[p[9]])
    SymbolTable.add('function', p[1], p[3])

def p_procedure(p):
    'procedure : K_PROCEDURE ID LPAREN parameter_list RPAREN LCURLY statements RCURLY'
    p[7] = statements_node(p[7])
    p[0] = procedure_node(p[2], [p[4]], p[7])
    SymbolTable.add('procedure', p[1], p[2])

   

def p_parameter(p):
    '''parameter : type ID
                 | type ID LBRACKET RBRACKET'''
    if len(p) == 3:
        p[0] = (p[2], p[1])
        SymbolTable.add('parameter', p[1], p[2], '', p[1])
    elif len(p) == 5:
        p[0] = (p[2], f"{p[1]}[]")
        SymbolTable.add('parameter', f"{p[1]}[]", p[2], '', f"{p[1]}[]")


def p_parameter_list(p):
    '''parameter_list : parameter_list COMMA parameter_list
                      | parameter'''
    if len(p) == 4:
        p[0] = [p[3], p[1]]
    else:
        p[0] = p[1]

def p_value(p):
    '''value : ICONSTANT
            | DCONSTANT
            | SCONSTANT
            | ID
            | ID LBRACKET value RBRACKET'''
    if len(p) == 5:
        p[0] = f"{p[1]}[{p[3]}]"
    else:
        p[0] = p[1]

def p_parameter_empty(p):
    'parameter : epsilon'
    p[0] = None




def p_statements(p):
    'statements : statements statements'
    p[0] = [p[2], p[1]]

def p_statements_dapf(p):
    '''statements : declare 
                  | declare_assign   
                  | assign 
                  | print 
                  | while
                  | do
                  | if
                  | read
                  | function_call'''
    p[0] = p[1]

def p_statement_dapf(p):
    '''statement : declare 
                 | declare_assign   
                 | assign 
                 | print 
                 | function_call
                 | read'''
    p[0] = [p[1]]

def p_statements_empty(p):
    'statements : epsilon'
    p[0] = None

def p_declare(p):
    '''declare : type ID SEMI
               | type ID LBRACKET math RBRACKET SEMI''' 
    if len(p) == 7:
        SymbolTable.add('statements', 'id', p[2], [p[4]], f"{p[1]}[{p[4]}]")
        p[0] = node("DECLARE", p[2], f"{p[1]}[{p[4]}]")
    else:
        SymbolTable.add('statements', 'id', p[2], '', p[1])
        p[0] = node("DECLARE", p[2], p[1])

def p_assign(p):
    '''assign : ID ASSIGN value SEMI
            | ID inc_dec SEMI
            | ID ASSIGN math SEMI
            | ID LBRACKET math RBRACKET ASSIGN math SEMI'''
    # err = SymbolTable.get_value('statements', p[1])
    # if err == None:
    #     sys.exit("Error: variable " + p[1] + " not declared on line " + str(p.lineno(1)))
    
    if len(p) == 8:
        SymbolTable.add_array('statements', p[1], p[3], p[6])
        p[0] = node("ASSIGN", p[6], f"{p[1]}[{p[3]}]")
    elif len(p)==4:
        # if p[2] == "++":
            # SymbolTable.add('statements', 'id', p[1], p[1], "++")
        # else:
            # SymbolTable.add('statements', 'id', p[1], p[1], "++")
        p[0] = node("ASSIGN", p[1], p[2])
        
    else:
        SymbolTable.add('statements', 'id', p[1], p[3])
        p[0] = node("ASSIGN", p[3], p[1])

def p_declare_assign(p):
    '''declare_assign : type ID ASSIGN value SEMI'''    
    SymbolTable.add('statements', 'id', p[2], p[4], p[1])
    p[0] = [node("ASSIGN", p[4], p[2]),node("DECLARE", p[2], p[1])]


def p_print(p):
    '''print : K_PRINT_INTEGER LPAREN value RPAREN SEMI
             | K_PRINT_STRING LPAREN value RPAREN SEMI
             | K_PRINT_DOUBLE LPAREN value RPAREN SEMI'''
    p[0] = node("PRINT", p[3], p[1])

def p_read(p):
    '''read : K_READ_INTEGER LPAREN ID RPAREN SEMI'''
    p[0] = node("READ", p[3], p[1])

def p_function_call(p):
    'function_call : ID LPAREN ID RPAREN SEMI'
    p[0] = node("function call", p[1], p[3])

def p_inc_dec(p):
    '''inc_dec : INCREMENT
               | DECREMENT'''
    p[0] = p[1]

def p_math(p):
    '''math : expression
          | factor inc_dec'''
    if len(p) == 3:
        if p[2] == '++':
            p[0] = f"{p[1]}++"
        else:
            p[0] = f"{p[1]}--"
    else:
        p[0] = p[1]
    print ("p[0]", p[0])

def p_expression(p):
    '''expression : expression PLUS term
                | expression MINUS term'''
    # print("p[1]", p[1])
    # print("p[2]", p[2])
    if p[2] == '+':
        p[0] = f"{p[1]} + {p[3]}"
    else:
        p[0] = f"{p[1]} - {p[3]}"

def p_expression_term(p):
    'expression : term'
    p[0] = p[1]

def p_term(p):
    '''term : term TIMES factor
            | term DIVIDE factor'''
    print("Term:", p[2], p[1], p[3])
    if p[2] == '*':
        p[0] = f"{p[1]} * {p[3]}"
    else:
        p[0] = f"{p[1]} / {p[3]}"

def p_term_factor(p):
    '''term : factor
            | MINUS factor'''
    if len(p) == 3:
        p[0] = f"-{p[2]}"
    else:
        p[0] = p[1]

def p_factor_expr(p):
    '''factor : LPAREN expression RPAREN
              | MINUS LPAREN expression RPAREN'''
    if p[1] == '(':
        # p[0] = ("Factor:", p[1], p[2], p[3])    
        # p[2] = p[2]
        # p[0] = leaf_node("") 
        p[0] = f"{(p[2])}"
    else:
        # p[0] = ("Factor:", p[1], p[2], p[3], p[4])
        p[0] = f"{-(p[3])}"

def p_factor_num(p):
    '''factor : ICONSTANT
            | DCONSTANT'''
    p[0] = p[1]

def p_factor_id(p):
    'factor : ID'
    # err = SymbolTable.get_value('statements', p[1])
    # if err == None:
    #     print("Error: variable " + p[1] + " not defined on line " + str(p.lineno(1)))
    #     p[0] = p[1]
    p[0] = p[1]

def p_factor_array(p):
    'factor : ID LBRACKET math RBRACKET'
    p[0] = f"{p[1]}[{p[3]}]"

def p_bool_op(p):
    '''bool_op : DAND
               | DOR
               | DEQ
               | GEQ
               | GT
               | LEQ
               | LT
               | NE
               | NOT '''
    p[0] = p[1]

def p_condition(p):
    '''condition : value bool_op value'''
    p[0] = f"{p[1]} {p[2]} {p[3]}"

def p_bool(p):
    '''bool : condition bool_op condition
            | condition'''
    if len(p) == 4:
        p[0] = f"{p[1]} {p[2]} {p[3]}"
    else:
        p[0] = p[1]

def p_while_statement(p):
    '''while : K_WHILE LPAREN bool RPAREN statement'''
    p[0] = logic_node("WHILE", p[3], p[5])

def p_while_statements(p):
    '''while : K_WHILE LPAREN bool RPAREN LCURLY statements RCURLY'''
    p[0] = logic_node("WHILE", p[3], [p[6]])

def p_do_assign(p):
    '''do_assign : ID ASSIGN ICONSTANT'''
    p[0] = f"{p[1]} := {p[3]}"

def p_do_statements(p):
    '''do : K_DO LPAREN do_assign SEMI condition SEMI ID inc_dec RPAREN LCURLY statements RCURLY'''
    p[0] = logic_node("DO", f"({p[3]}; {p[5]}; {p[7]}{p[8]})", [p[11]])


def p_if_statements(p):
    '''if : K_IF LPAREN bool RPAREN K_THEN LCURLY statements RCURLY else_if'''
    p[0] = logic_node("IF", p[3], p[7])

def p_if_statement(p):
    '''if : K_IF LPAREN bool RPAREN K_THEN statement else_if'''
    p[0] = logic_node("IF", p[3], p[6])

def p_else_if_statements(p):
    '''else_if : K_ELSE K_IF LPAREN bool RPAREN K_THEN LCURLY statements RCURLY else'''

def p_else_if_statement(p):
    '''else_if : K_ELSE K_IF LPAREN bool RPAREN K_THEN statement else'''

def p_else_if(p):
    '''else_if : else'''

def p_else_statements(p):
    '''else : K_ELSE LCURLY statements RCURLY'''

def p_else_statement(p):
    '''else : K_ELSE statement'''

def p_else_empty(p):
    '''else : epsilon'''
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

# main(p, SymbolTable)

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

