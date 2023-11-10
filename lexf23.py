import ply.lex as lex
from ply.lex import TOKEN

# Reserved words and tokens
reserved = {
    'program' : 'PROGRAM',
    'function' : 'FUNCTION',
    'integer': 'INTEGER',
    'double': 'DOUBLE',
    'print_integer': 'PRINT_INTEGER',
    'print_string': 'PRINT_STRING',
    'print_double': 'PRINT_DOUBLE'
}

# List of token names.   This is always required:
tokens = [
    'ICONSTANT',
    'SCONSTANT',
    'DCONSTANT',
    'ID',
    'KEYWORD',
    'SEMI',
    'RPAREN',
    'LPAREN',
    'LCURLY',
    'RCURLY',
    'ASSIGN',
    'COMMENT'
] + list(reserved.values())

# Regular expression rules for simple tokens
# t_ is a prefix for token
letter = r'[a-zA-Z]'
identifier = r'(' + letter + '|\$|_)(' + letter + '|\$|_|\d){0,31}'
t_SEMI= r';'
t_RPAREN = r'\)'
t_LPAREN = r'\('
t_LCURLY = r'{'
t_RCURLY = r'}'
t_SCONSTANT = r'\"(\\.|[^\"\\])*\"'

# A string containing ignored characters (spaces and tabs)
t_ignore  = ' \t'
t_ignore_COMMENT = r'\#.*'

# A regular expression rule with some action code
@TOKEN(identifier)
def t_KEYWORD(t):
    # matches the identifier regex
    # if the identifier is not a reserved word
    # then it is an ID
    t.type = reserved.get(t.value,'ID')
    return t

def t_DCONSTANT(t):
    r'[+-]?[0-9]+\.[0-9]+'
    t.value = float(t.value)
    return t

def t_ICONSTANT(t):
    r'[0-9]+'
    t.value = int(t.value)
    return t

# def t_DCONSTANT(t):
#     r'[-+]?(?:\d*\.*\d+)'
#     t.value = float(t.value)
#     return t

def t_ASSIGN(t):
    r':='
    return t


# Define a rule so we can track line numbers
def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

# Error handling rule
def t_error(t):
    print("Illegal character '%s'" % t.value[0])
    t.lexer.skip(1)

# Build the lexer
lexer = lex.lex()
# Build the lexer in debug mode
# lexer = lex.lex(debug=True)

# Give the lexer some input
file = open("tiniest.txt", "r")
lexer.input(file.read())

# Tokenize
# while True:
#     tok = lexer.token()                                                               
#     if not tok:                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
#         break      # No more input
#     print(tok)
    # print(f"type: {tok.type}, value: {tok.value}, line#: {tok.lineno}")

# for tok in lexer:                                                                                           
#     print(tok)

