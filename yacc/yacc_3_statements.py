


def p_statements(p):
    'statements : statements statements'
    p[0] = [p[2], p[1]]

def p_statements_dapf(p):
    '''statements : declare 
                  | declare_assign   
                  | assign 
                  | print 
                  | while
                  | read
                  | function_call'''
    p[0] = p[1]

def p_statement_dapf(p):
    '''statement : declare 
                 | declare_assign   
                 | assign 
                 | print 
                 | while
                 | function_call
                 | read'''
    p[0] = [p[1]]

def p_statements_empty(p):
    'statements : epsilon'
    p[0] = None

def p_declare(p):
    '''declare : type ID SEMI'''    
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

def p_declare_assign(p):
    '''declare_assign : type ID ASSIGN value SEMI'''    
    SymbolTable.add('statements', 'id', p[2], p[4], p[1])
    p[0] = [node("ASSIGN", p[2], p[4]),node("DECLARE", p[2], p[1])]


def p_print(p):
    '''print : K_PRINT_INTEGER LPAREN ID RPAREN SEMI
             | K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI
             | K_PRINT_STRING LPAREN ID RPAREN SEMI
             | K_PRINT_DOUBLE LPAREN ID RPAREN SEMI'''
    p[0] = node("PRINT", p[3], p[1])

def p_read(p):
    '''read : K_READ_INTEGER LPAREN ID RPAREN SEMI'''
    p[0] = node("READ", p[3], p[1])

def p_function_call(p):
    'function_call : ID LPAREN ID RPAREN SEMI'
    p[0] = node("function call", p[1], p[3])

