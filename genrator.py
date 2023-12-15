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
    
def declare_array(name, size, file):
    """Prints generated code for an array declaration to yourmain.h

    Parameters:
    name (string): Name of the array
    size (int): Size of the array
    file (string): Name of the file to write to

    Returns:
    memory (string): Memory address range of the array
    """
    file.write(f"int {name} = allocate_in_Mem( {size} );\n")
    file.write(f"F23_Time += {access_times['else']};\n")

def assign_array(name, type, value, loc, filename):
    """Prints generated code for an integer assignment to yourmain.h

    Parameters:
    name (string): Name of the array
    type (string): Type of the array
    value (int): Value of the integer
    loc (int): Memory address of the array
    filename (string): Name of the file to write to

    """
    if type == "integer":
        filename.write(f"R[1] = {value};\n")
        filename.write(f"F23_Time += {access_times['R']};\n")
        filename.write(f"Mem[{name}+{loc}] = R[1];\n")
        filename.write(f"F23_Time += {access_times['Mem']} + {access_times['R']};\n")
    else:
        filename.write(f"F[1] = {value};\n")
        filename.write(f"F23_Time += {access_times['F']};\n")
        filename.write(f"FMem[{name}+{loc*2}] = F[1];\n")
        filename.write(f"F23_Time += {access_times['Mem']} + {access_times['F']};\n")

    
  

def assign_string(scope, name):
    """Prints generated code for an string assignment to yourmain.h

    Parameters:
    scope (string): Scope of the symbol
    name (string): Name of the symbol

    Returns:
    """
    #I am not sure what to do here yet









