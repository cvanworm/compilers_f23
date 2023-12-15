from genrator import assign_int, print_variable, print_sconstant, assign_double, declare_array, assign_array, print_array

import symtablef23 as symbol_table

import re

SI = [] # Stack Register index
FI = [] # Frame Register index
IR = 1 # Integer Register index
FR = 1 # Float Register index

def main(pst, tree):
    global file
    global SymbolTable
    global full_tree
    global Parse_SymbolTable
    Parse_SymbolTable = pst
    full_tree = tree
    SymbolTable = symbol_table.SymbolTable("walking")
    var_count = Parse_SymbolTable.get_symbol_counts()
    if var_count % 2 != 0:
        var_count += 1
    # SymbolTable.print()

    # exit()
    file = open("yourmain.h", "w+")
    file.write("int yourmain() {\n")
    file.write(f"SR -= {var_count};\n")
    file.write("FR = SR;\n")
    file.write(f"FR += {var_count}/2;\n")
               
    find_node(tree, "FUNCTION", "main")
    file.write(f"SR += {var_count};\n")
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
            # print("PARAMETERS:", parameters)
            # print("ARGS:", args)
            for i in range(len(args)):
                # print("Parameters:", args[i][0], args[i][1], parameters[i][0], parameters[i][1])
                SymbolTable.add('id', parameters[i][0], args[i][0], parameters[i][1])
                # print("Name:", parameters[i][0])
                # print("Value:", args[i][0])
                assign_code(parameters[i][0], args[i][0])

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
            name = tree['children'][1]['name']
            if type(value) == str:
                value = evaluate(value)
            if '[' in name:
                name = name.split('[')
                index = name[1][:-1]
                #TODO: add value to symbol table
                # SymbolTable.add_array(name[0], index, value)
            else:
                SymbolTable.add('id', name, value)
            assign_code(tree['children'][1]['name'],value)
        elif tree['name'] == 'DECLARE':
            print("Declare", tree['children'])
            SymbolTable.add('id', tree['children'][0]['name'], '', tree['children'][1]['name'])
            declare_code(tree['children'][0]['name'])
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


def assign_code(name,value):
    # print("VALUE:", value)
    # print("NAME:", name)
    if '[' in name:
        name = name.split('[')
        type = SymbolTable.get_type(name[0])
        type = type.split('[')[0]
        location = int(name[1][:-1])
        # print("loc:",location)
        assign_array(name[0], type, value, location, file)
        # value = SymbolTable.get_value(name)
    else:
        type = SymbolTable.get_type(name)
        # value = SymbolTable.get_value(name)
        mem = SymbolTable.get_mem(name)
        if type == 'integer':
            if not mem:
                memory_location = assign_int(value, len(SI), IR, file)
                SI.append(1)
            else:
                print("MEM:", mem)
                memory_location = assign_int(value, int(mem.split(" ")[2][:-1]), IR, file)

        if type == 'double':
            if not mem:
                memory_location = assign_double(value, len(FI), FR, file)
                FI.append(1)
                FI.append(1)
            else:
                print("MEM:", mem)
                memory_location = assign_double(value, int(mem.split(" ")[2][:-1]), FR, file)
        SymbolTable.add_mem(name, memory_location)
    

def print_code(name):
    if name[0] == '"':
        print_sconstant(name, file)
    elif '[' in name:
        name = name.split('[')
        location = int(name[1][:-1])
        type = SymbolTable.get_type(name[0])
        type = type.split('[')[0]
        print_array(name[0], type, location, file)
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

def declare_code(name):
    arr_type = SymbolTable.get_type(name)
    print("ARR TYPE:", arr_type)

    if '[' in arr_type:
        arr_type = arr_type.split('[')
        array_type = arr_type[0]
        
        #TODO: check if array size is math expression
        size = int(arr_type[1][:-1])

        if array_type == 'double':
            size = size*2

        declare_array(name, size, file)
        memory_location = f"Mem[{name}] - Mem[{name}+{size-1}]"
        SymbolTable.add_mem(name, memory_location)
