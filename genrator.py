def assign_int(value, stack_index, ir_index, filename):
    """Prints generated code for an integer assignment to yourmain.h

    Parameters:
    value (int): Value of the integer
    stack_index (int): Current index on stack
    ir_index (int): Current index of next empty integer register
    filename (string): Name of the file to write to

    Returns:
    memory (string): Memory address of the variable
    """

    filename.write(f"R[{ir_index}] = {value};\n")
    filename.write(f"F23_Time += 1;\n")
    filename.write(f"Mem[SR + {stack_index}] = R[{ir_index}];\n")
    filename.write(f"F23_Time += 20 + 1;\n")

    return f"Mem[SR + {stack_index}]"


def assign_float(scope, name, stack_index, fr_index, filename):
    """Prints generated code for an float assignment to yourmain.h

    Parameters:
    scope (string): Scope of the symbol
    name (string): Name of the symbol
    stack_index (int): Current index on stack
    fr_index (int): Current index of next empty float register
    filename (string): Name of the file to write to

    Returns:
    fr_index: Current index of next empty float register
    """
    value = symbol_find(scope, name)

    filename.write(f"F[{fr_index}] = {value}\n")
    filename.write(f"F23_Time += 1\n")
    filename.write(f"*(double*)Mem[SR + {stack_index}] = F[{fr_index}]\n")
    filename.write(f"F23_Time += 20 + 1\n")


def assign_string(scope, name):
    """Prints generated code for an string assignment to yourmain.h

    Parameters:
    scope (string): Scope of the symbol
    name (string): Name of the symbol

    Returns:
    """
    #I am not sure what to do here yet


def print_variable(mem, type, filename):
    """Prints generated code for a variable print statement to yourmain.h regardless of type

    Parameters:
    mem (string): Memory address of the variable
    type (string): Type of the variable
    filename (string): Name of the file to write to
    """
    if type == "integer":
        filename.write(f"print_int({mem});\n")
    filename.write(f"F23_Time += 20;\n")

def print_string_literal(value, filename):
    """Prints generated code for a string literal print statement to yourmain.h

    Parameters:
    value (string): Value of the string literal
    filename (string): Name of the file to write to
    """
    filename.write(f"Mem[] = {value}\n")
    filename.write(f"F23_Time += 20\n")
    filename.write(f"print_int(Mem[])\n")
    filename.write(f"F23_Time += 20\n")




