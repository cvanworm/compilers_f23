from genrator import assign_int,assign_double, print_variable, print_sconstant

SI = 0 # Stack Register index
FI = 0 # Frame Register index
IR = 1 # Integer Register index
FR = 1 # Float Register index

#TODO: fix symbol table functions

def main(tree, symboltable):
    global file
    global SymbolTable
    SymbolTable = symboltable
    file = open("yourmain.h", "w+")
    file.write("int yourmain() {\n")
    file.write(f"SR -= {SymbolTable.get_symbol_counts()};\n")
    file.write(f"FR = SR")
    file.write(f"FR += SR/2")
    walk(tree)
    file.write(f"SR += {SymbolTable.get_symbol_counts()};\n")
    file.write("return 0;\n")
    file.write("}\n")
    file.close()

def walk(tree):
    if 'children' not in tree:
        return
    else:
        if tree['name'] == 'ASSIGN':
            assign_code('statements', tree['children'][1]['name'])
        elif tree['name'] == 'DECLARE':
            declare_code()
        elif tree['name'] == 'PRINT':
            print_code('statements', tree['children'][0]['name'])
        elif tree['name'] == 'WHILE':
            while_code(tree['children'][0]['name'])
        elif tree['name'] == 'DO':
            do_code(['children'][0]['name'])
        elif tree['name'] == 'FUNCTION':
            function_code()
        else:
            for child in tree['children']:
                walk(child)


def assign_code(scope, name):
    type = SymbolTable.get_type(scope, name)
    value = SymbolTable.get_value(scope, name)

    # if type(value) == 'string':
    #     value = eval(value)

    if type == 'integer':
        memory_location = assign_int(value, SI, IR, file)
        IR += 1
    elif type == 'double':
        memory_location = assign_double(value, FI, FR, file)
    elif type =='double[':
        memory_location = addign_double_array()

    SymbolTable.add_mem(scope, name, memory_location)
    
def declare_code():
    return 0

def print_code(scope, name):
    if name[0] == '"':
        print_sconstant(name, file)
    else:
        type = SymbolTable.get_type(scope, name)
        mem = SymbolTable.get_mem(scope, name)
        print_variable(mem, type, file)

#TODO: handle function calls
def function_code():
    
    return 0

def while_code(statement):
    return 0

def do_code(statement):
    return 0

