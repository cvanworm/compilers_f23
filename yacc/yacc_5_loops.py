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
    '''condition : math bool_op math '''
    # p[0] = f"{p[1]} {p[2]} {p[3]}"
    p[0] = node(p[2], p[1], p[3])

def p_condition_func(p):
    '''condition : function_call bool_op math '''
    p[0] = f"{p[1]} {p[2]} {p[3]}"

    # TODO

def p_bool(p):
    '''bool : condition bool_op condition
            | condition'''
    if len(p) == 4:
        # p[0] = f"{p[1]} {p[2]} {p[3]}"
        p[0] = {"name": "CONDITION", "children": [node(p[2], p[1], p[3])]}
    else:
        # p[0] = p[1]
        p[0] = {"name": "CONDITION", "children": [p[1]]}

def p_while_statement(p):
    '''while : K_WHILE LPAREN bool RPAREN statement'''
    # p[0] = logic_node("WHILE", p[3], p[5])
    p[0] = logic_node(f"WHILE-{len(whiles)}", [p[5]] + [p[3]])
    whiles.append(1)

def p_while_statements(p):
    '''while : K_WHILE LPAREN bool RPAREN LCURLY statements RCURLY'''
    p[0] = logic_node(f"WHILE-{len(whiles)}", [p[6]] + [p[3]])
    whiles.append(1)

def p_do_assign(p):
    '''do_assign : ID ASSIGN ICONSTANT'''
    # p[0] = f"{p[1]} := {p[3]}"
    p[0] = node("ASSIGN", p[3], p[1])

def p_do_statements(p):
    '''do : K_DO LPAREN do_assign SEMI condition SEMI ID inc_dec RPAREN LCURLY statements RCURLY'''
    # p[0] = logic_node("DO", f"({p[3]}; {p[5]}; {p[7]}{p[8]})", [p[11]])
    condition_node = logic_node("INFO", [node("CHANGE", p[8], p[7])] + [logic_node("CONDITION", [p[5]])] + [p[3]])
    p[0] = logic_node(f"DO-{len(dos)}", [p[11]] + [condition_node])
    dos.append(1)

def p_do_statement(p):
    '''do : K_DO LPAREN do_assign SEMI condition SEMI ID inc_dec RPAREN statement'''
    # p[0] = logic_node("DO", f"({p[3]}; {p[5]}; {p[7]}{p[8]})", [p[10]])
    p[0] = logic_node(f"DO-{len(dos)}", [p[10]])
    dos.append(1)


def p_if_statements(p):
    '''if : K_IF LPAREN bool RPAREN K_THEN LCURLY statements RCURLY else_if'''
    print(f"p[9] {[p[9]]}")
    # p[0] = {"name": "LOGIC", "children": [p[3]] + [logic_node("IF", p[7])] + [p[9]]}
    p[3]['name'] += f"-IF-{(len(ifs))}"
    p[0] = logic_node(f"LOGIC-{len(ifs)}",  [p[9]] + [logic_node(f"IF-{len(ifs)}", p[7])] + [p[3]])
    ifs.append(1)

def p_if_statement(p):
    '''if : K_IF LPAREN bool RPAREN K_THEN statement else_if'''
    p[3]['name'] += f"-IF-{(len(ifs))}"
    p[0] = logic_node(f"LOGIC-{len(ifs)}", [p[7]] + [logic_node(f"IF-{len(ifs)}", p[6])] + [p[3]] )
    ifs.append(1)

def p_else_if_statements(p):
    '''else_if : K_ELSE K_IF LPAREN bool RPAREN K_THEN LCURLY statements RCURLY else'''
    p[4]['name'] += f"-ELSE IF-{(len(ifs))}"
    p[0] = [p[10]] + [logic_node(f"ELSE IF-{len(ifs)}", p[8])] + [p[4]]

def p_else_if_statement(p):
    '''else_if : K_ELSE K_IF LPAREN bool RPAREN K_THEN statement else'''
    p[4]['name'] += f"-ELSE IF-{(len(ifs))}"
    p[0] = [p[8]] + [logic_node(f"ELSE IF-{len(ifs)}", p[7])] + [p[4]]

def p_else_if(p):
    '''else_if : else'''
    p[0] = p[1]

def p_else_statements(p):
    '''else : K_ELSE LCURLY statements RCURLY'''
    p[0] = logic_node(f"ELSE-{len(ifs)}", p[3])

def p_else_statement(p):
    '''else : K_ELSE statement'''
    p[0] = logic_node(f"ELSE-{len(ifs)}", p[2])

def p_else_empty(p):
    '''else : epsilon'''
    

