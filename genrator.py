access_times = {
    "R": 1,
    "F": 2,
    "Mem": 20,
    "int /": 19,
    "int %": 20,
    "double /": 38,
    "double %": 40,
    "Function call": 100,
    "else": 1
}

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
    filename.write(f"F23_Time += {access_times['R']};\n")
    filename.write(f"Mem[SR + {stack_index}] = R[{ir_index}];\n")
    filename.write(f"F23_Time += {access_times['Mem']} + {access_times['R']};\n")

    return f"Mem[SR + {stack_index}]"

def assign_double(value, frame_index, fr_index, filename):
    """Prints generated code for an double assignment to yourmain.h

    Parameters:
    value (double): Value of the double
    frame_index (int): Current index on frame register
    fr_index (int): Current index of next empty float register
    filename (string): Name of the file to write to

    Returns:
    memory (string): Memory address of the variable
    """
    filename.write(f"F[{fr_index}] = {value};\n")
    filename.write(f"F23_Time += {access_times['F']};\n")
    filename.write(f"FMem[FR + {frame_index}] = F[{fr_index}];\n")
    filename.write(f"F23_Time += {access_times['Mem']} + {access_times['F']};\n")

    return f"FMem[FR + {frame_index}]"


def print_sconstant(sconstant, filename):
    """Prints generated code for a string constant to yourmain.h

    Parameters:
    sconstant (string): Value of the string literal
    filename (string): Name of the file to write to
    """
    filename.write(f"print_string({sconstant});\n")
    filename.write(f"F23_Time += 1;\n")

def print_variable(mem, type, filename):
    """Prints generated code for a variable print statement to yourmain.h regardless of type

    Parameters:
    mem (string): Memory address of the variable
    type (string): Type of the variable
    filename (string): Name of the file to write to
    """
    if type == "integer":
        filename.write(f"print_int({mem});\n")
        filename.write(f"F23_Time += {access_times['Mem']};\n")
    elif type == "double":
        filename.write(f"print_double({mem});\n")
        filename.write(f"F23_Time += {access_times['Mem']};\n")
    


def assign_string(scope, name):
    """Prints generated code for an string assignment to yourmain.h

    Parameters:
    scope (string): Scope of the symbol
    name (string): Name of the symbol

    Returns:
    """
    #I am not sure what to do here yet
    pass

def create_condition(left, right, bool_op, filename):
    """Prints generated code for a condition to yourmain.h

    Parameters:
    """
    filename.write(f"R[1] =  {left};\n")
    filename.write(f"F23_Time += {access_times['R']};\n")
    filename.write(f"R[2] =  {right};\n")
    filename.write(f"F23_Time += {access_times['R']};\n")
    filename.write(f"R[3] =  R[1] {bool_op} R[2];\n")
    filename.write(f"F23_Time += {access_times['R']};\n")
    filename.write(f"if (R[3] == 1) goto If;\n")
    filename.write(f"if (R[3] != 1) goto Else;\n")

def create_goto(name, filename):
    filename.write(f"{name}: \n")

def close_goto(filename, end=""):
    if end != "":
        filename.write(f"goto {end};\n")







