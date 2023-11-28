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
    p[0] = loop_node("WHILE", p[3], p[5])

def p_while_statements(p):
    '''while : K_WHILE LPAREN bool RPAREN LCURLY statements RCURLY'''
    p[0] = loop_node("WHILE", p[3], [p[6]])

