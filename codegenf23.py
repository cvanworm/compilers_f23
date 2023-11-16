from genrator import assign_int, print_variable, print_sconstant

access_times = {
    "R": 1,
    "F": 2,
    "Mem": 20,
    "int /": 19,
    "int %": 20,
    "double /": 38,
    "double %": 40,
    "Function call": 100,
    # "Everything else": 1,
}
SI = 0
IR = 1
FR = 1

def main(tree, symboltable):
    global file
    global SymbolTable
    SymbolTable = symboltable
    file = open("yourmain.h", "w+")
    file.write("int yourmain() {\n")
    file.write(f"SR -= {SymbolTable.get_symbol_counts()};\n")
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
        elif tree['name'] == 'PRINT':
            print_code('statements', tree['children'][0]['name'])
        else:
            for child in tree['children']:
                walk(child)


def assign_code(scope, name):
    type = SymbolTable.get_type(scope, name)
    value = SymbolTable.get_value(scope, name)
    print(type)
    print(value)
    print(name)
    if type == 'integer':
        memory_location = assign_int(value, SI, IR, file)
        # IR += 1

    SymbolTable.add_mem(scope, name, memory_location)
    

def print_code(scope, name):
    if name[0] == '"':
        print_sconstant(name, file)
    else:
        type = SymbolTable.get_type(scope, name)
        mem = SymbolTable.get_mem(scope, name)
        print_variable(mem, type, file)
