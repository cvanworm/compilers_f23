


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

