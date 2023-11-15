sym_table = []

# add symbol to table
def symbol_add(scope, token, name, value='', symtype=''):
    """Adds a symbol to the symbol table, or updates its value if it already exists

    Parameters:
    scope (string): Scope of the symbol
    token (string): Token of the symbol
    name (string): Name of the symbol
    value (string): Value of the symbol
    symtype (string): Type of the symbol

    """
    symbol = {
        'scope': scope,
        'token': token,
        'name': name,
        'value': value,
        'type': symtype
    }
    # check if symbol already exists at scope
    for sym in sym_table:
        if sym['scope'] == scope and sym['name'] == name:
            sym['value'] = value
            return
    # otherwise add symbol to table
    sym_table.append(symbol)

# retrive symbol from table
def symbol_find(scope, name):
    """Finds a symbol in the symbol table

    Parameters:
    scope (string): Scope of the symbol
    name (string): Name of the symbol

    Returns:
    symbol || none:Symbol if found, None otherwise
    
    """
    for symbol in sym_table:
        if symbol['scope'] == scope and symbol['name'] == name:
            return symbol['value']
    return None

def symbol_add_mem(scope, name, memory):
    for symbol in sym_table:
        if symbol['scope'] == scope and symbol['name'] == name:
            symbol['memory'] = memory
            return
        
def symbol_get_type(scope, name):
    for symbol in sym_table:
        if symbol['scope'] == scope and symbol['name'] == name:
            return symbol['type']
    return None

def symbol_count():
    return len(sym_table)

def stack_size():
    r = 0
    fr = 0
    

def get_symbol_table():
    return sym_table

def print_symbol_table():
    print('\n{:=^100}'.format("SYMBOL TABLE"))
    print("\n{:<16}{:<16}{:<16}{:<23}{:<16}{:<16}".format("Scope", "Token", "Name", "Value", "Type", "Memory"))
    for symbol in sym_table:
        # print(symbol['scope'], "\t\t", symbol['token'], "\t\t", symbol['name'], "\t\t", symbol['value'], "\t\t", symbol['type'])
        if "memory" in symbol:
            print("{:<16}{:<16}{:<16}{:<23}{:<16}{:<16}".format(symbol['scope'], str(symbol['token']), symbol['name'], str(symbol['value']), symbol['type'], symbol['memory']))
        else:
            print("{:<16}{:<16}{:<16}{:<23}{:<16}".format(symbol['scope'], str(symbol['token']), symbol['name'], str(symbol['value']), symbol['type']))
    print("\nNumber of symbols:" , symbol_count())
    print("="*100)