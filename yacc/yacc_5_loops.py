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
