from genrator import assign_int, print_variable, print_sconstant

import symtablef23 as symbol_table

import re

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

SI = []
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
    # SymbolTable.print()

    # exit()
    file = open("yourmain.h", "w+")
    file.write("int yourmain() {\n")
    file.write(f"SR -= {Parse_SymbolTable.get_symbol_counts()};\n")
    find_node(tree, "FUNCTION", "main")
    file.write(f"SR += {Parse_SymbolTable.get_symbol_counts()};\n")
    file.write("return 0;\n")
    file.write("}\n")
    file.close()


def find_node(tree, token, name, args=[]):
    if 'children' not in tree:
        return
    elif tree['name'] == token and tree['id'] == name:
        # print("MAIN", tree)
        SymbolTable.new_scope(name)
        # check if token is procedure or function and has args
        if (token == 'FUNCTION' or token == 'PROCEDURE') and len(tree['parameters'])>0:
            parameters = tree['parameters']
            print("PARAMETERS:", parameters)
            print("ARGS:", args)
            for i in range(len(args)):
                print("Parameters:", args[i][0], args[i][1], parameters[i][0], parameters[i][1])
                SymbolTable.add('id', parameters[i][0], args[i][0], parameters[i][1], args[i][1])

        walk(tree)
        SymbolTable.print()
        SymbolTable.pop_scope()
        return
    else:
        for child in tree['children']:
                find_node(child, token, name, args)

def walk(tree):
    if 'children' not in tree:
        return
    else:
        if tree['name'] == 'ASSIGN':
            print("Assign", tree['children'])
            value = tree['children'][0]['name']
            if not str(value).isdigit():
                value = evaluate(value)
            SymbolTable.add('id', tree['children'][1]['name'], value)
            assign_code(tree['children'][1]['name'])
        elif tree['name'] == 'DECLARE':
            print("Declare",)
            SymbolTable.add('id', tree['children'][0]['name'], '', tree['children'][1]['name'])
            # assign_code('statements', tree['children'][1]['name'])
        elif tree['name'] == 'PRINT':
            print("Print", tree['children'][0]['name'])
            print_code(tree['children'][0]['name'])
        elif tree['name'] == 'FUNCTION CALL':
            print(f"{tree['id']}()")
            # Get type of function/procedure
            token = Parse_SymbolTable.get_token(tree['id'])

            # Bundle the arguments as a list of (value, memory_location)
            args = []
            for child in tree['children']:
                    # TODO: get value and mem location
                    value = SymbolTable.get_value(child['name'])
                    mem = SymbolTable.get_mem(child['name'])
                    args.append((value, mem))
            # reverse the args
            args.reverse()
            print("ARGS:", args)
            # Continue walking the tree
            find_node(full_tree, token, tree['id'], args)

            

        else:
            for child in tree['children']:
                walk(child)


def assign_code(name):
    type = SymbolTable.get_type(name)
    value = SymbolTable.get_value(name)
    mem = SymbolTable.get_mem(name)
    if type == 'integer':
        if not mem:
            memory_location = assign_int(value, len(SI), IR, file)
            SI.append(1)
        else:
            print("MEM:", mem)
            memory_location = assign_int(value, int(mem.split(" ")[2][:-1]), IR, file)
    SymbolTable.add_mem(name, memory_location)
    

def print_code(name):
    if name[0] == '"':
        print_sconstant(name, file)
    else:
        type = SymbolTable.get_type(name)
        mem = SymbolTable.get_mem(name)
        print("TEST:", type, mem)
        print_variable(mem, type, file)

def evaluate(expr):
    letter = r'[a-zA-Z]'
    identifier = r'(' + letter + '|\$|_)(' + letter + '|\$|_|\d){0,31}'
    print("EXPR:", expr)
    ids = re.search( identifier, expr)
    while ids != None:
        print("IDS:", ids.group())
        value = SymbolTable.get_value(ids.group())
        expr = expr.replace(ids.group(), str(value))
        ids = re.search( identifier, expr)
    return eval(expr)
