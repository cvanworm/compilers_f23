import ply.lex as lex
from ply.lex import TOKEN

# Reserved words and tokens
reserved = {
    'program' : 'K_PROGRAM',
    'function' : 'K_FUNCTION',
    'integer': 'K_INTEGER',
    'double': 'K_DOUBLE',
    'string': 'K_STRING',
    'print_integer': 'K_PRINT_INTEGER',
    'print_string': 'K_PRINT_STRING',
    'print_double': 'K_PRINT_DOUBLE',
    'do': 'K_DO',
    'while': 'K_WHILE',
    'else': 'K_ELSE',
    'exit': 'K_EXIT',
    'if': 'K_IF',
    'then': 'K_THEN',
    'procedure': 'K_PROCEDURE',
    'read_integer': 'K_READ_INTEGER',
    'read_double': 'K_READ_DOUBLE',
    'read_string': 'K_READ_STRING',
    'return': 'K_RETURN',

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
    'ASSIGN_PLUS',
    'ASSIGN_MINUS',
    'ASSIGN_MULTIPLY',
    'ASSIGN_DIVIDE',
    'ASSIGN_MOD',
    'COMMENT',
    'PLUS',
    'MINUS',
    'TIMES',
    'DIVIDE',
    'DAND',
    'DOR',
    'DEQ',
    'GEQ',
    'GT',
    'LEQ',
    'LT',
    'NE',
    'NOT',
    'DECREMENT',
    'INCREMENT',
    'MOD',
    'COMMA',
    'LBRACKET',
    'RBRACKET',
    'PERIOD',

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
t_PLUS    = r'\+'
t_MINUS   = r'\-'
t_TIMES   = r'\*'
t_DIVIDE  = r'\/'
t_DECREMENT = r'\-\-'
t_INCREMENT = r'\+\+'
t_MOD = r'\%'
t_SCONSTANT = r'\"(\\.|[^\"\\])*\"'
t_ASSIGN = r'\:\='
t_ASSIGN_PLUS = r'\+\='
t_ASSIGN_MINUS = r'\-\='
t_ASSIGN_MULTIPLY = r'\*\='
t_ASSIGN_DIVIDE = r'\/\='
t_ASSIGN_MOD = r'\%\='
t_DAND = r'\&\&'
t_DOR = r'\|\|'
t_DEQ = r'\=\='
t_GEQ = r'\>\='
t_GT = r'\>'
t_LEQ = r'\<\='
t_LT = r'\<'
t_NE = r'\!\='
t_NOT = r'\!'
t_COMMA = r'\,'
t_LBRACKET = r'\['
t_RBRACKET = r'\]'
t_PERIOD = r'\.'




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

