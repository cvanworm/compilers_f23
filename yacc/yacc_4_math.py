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

