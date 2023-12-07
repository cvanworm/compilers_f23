from genrator import assign_int, print_variable, print_sconstant

import symtablef23 as symbol_table

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

def main(pst, tree):
    global file
    global SymbolTable
    global full_tree
    global Parse_SymbolTable
    Parse_SymbolTable = pst
    full_tree = tree
    SymbolTable = symbol_table.SymbolTable("walking")
    find_node(tree, "FUNCTION", "main")
    # SymbolTable.print()

    exit()
    file = open("yourmain.h", "w+")
    file.write("int yourmain() {\n")
    file.write(f"SR -= {SymbolTable.get_symbol_counts()};\n")
    walk(tree)
    file.write(f"SR += {SymbolTable.get_symbol_counts()};\n")
    file.write("return 0;\n")
    file.write("}\n")
    file.close()


def find_node(tree, token, name):
    if 'children' not in tree:
        return
    elif tree['name'] == token and tree['id'] == name:
        print("MAIN", tree)
        SymbolTable.new_scope(name)
        walk(tree)
        SymbolTable.print()
        SymbolTable.pop_scope()
        return
    else:
        for child in tree['children']:
                find_node(child, token, name)

def walk(tree):
    if 'children' not in tree:
        return
    else:
        if tree['name'] == 'ASSIGN':
            print("Assign", )
            # assign_code('statements', tree['children'][1]['name'])
            SymbolTable.add('id', tree['children'][1]['name'], tree['children'][0]['name'])
        elif tree['name'] == 'DECLARE':
            print("Declare",)
            SymbolTable.add('id', tree['children'][0]['name'], '', tree['children'][1]['name'])
            # assign_code('statements', tree['children'][1]['name'])
        elif tree['name'] == 'PRINT':
            print("Print", tree['children'][0]['name'])
            # print_code('statements', tree['children'][0]['name'])
        elif tree['name'] == 'FUNCTION CALL':
            print(f"{tree['id']}()")
            # Get type of function/procedure
            token = Parse_SymbolTable.get_token(tree['id'])

            # Bundle the arguments as a list of (value, memory_location)
            args = []
            for child in tree['children']:
                    # TODO: get value and mem location
                    args.append(child['name'])
            # reverse the args
            args.reverse()
            print("ARGS:", args)
            # Continue walking the tree
            find_node(full_tree, token, tree['id'])

            

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
