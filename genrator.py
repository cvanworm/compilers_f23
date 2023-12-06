access_times = {
    "R": 1,
    "F": 2,
    "Mem": 20,
    "int /": 19,
    "int %": 20,
    "double /": 38,
    "double %": 40,
    "function call": 100,
    "else": 1,
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
    filename.write(f"F23_Time += {access_times['else']};\n")

def print_variable(mem, type, filename):
    """Prints generated code for a variable print statement to yourmain.h regardless of type

    Parameters:
    mem (string): Memory address of the variable
    type (string): Type of the variable
    filename (string): Name of the file to write to
    """
    if type == "integer":
        filename.write(f"print_int({mem});\n")
        filename.write(f"F23_Time += {access_times['Mem']} + {access_times['R']};\n")

    elif type == "double":
        filename.write(f"print_double({mem});\n")
        filename.write(f"F23_Time += {access_times['Mem']} + {access_times['F']};\n")

# def declare_array(value, size, filename):

def function_call(function_name, ir_index, arguments, filename):
    """Prints generated code for a function call to yourmain.h

    Parameters:
    function_name (string): Name of the function
    arguments (list): List of memory locations of arguments
    filename (string): Name of the file to write to
    """
    for arg in arguments:
        filename.write(f"R[{ir_index}] = {arg};\n")
        filename.write(f"F23_Time += {access_times['R']};\n")
        ir_index += 1

    #TODO: How to format call in godegen
        
    filename.write(f"F23_Time += {access_times['function call']};\n")









