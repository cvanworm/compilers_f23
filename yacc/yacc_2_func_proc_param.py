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

def p_function_statements(p):
    '''function_statements : function_statements function_statements'''
    p[0] = [p[2], p[1]]

def p_function_statements_fp(p):
    '''function_statements : statements
                           | procedure '''
    p[0] = p[1]

def p_function(p):
    'function : K_FUNCTION type ID LPAREN parameter_list RPAREN LCURLY function_statements RCURLY'
    p[8] = statements_node([p[8]])
    p[0] = function_node(p[3], p[2], p[8])
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

