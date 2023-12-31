# Tree visualization
from bigtree import nested_dict_to_tree
# Create deep copy of tree for node number visualization
import copy

def program_node(id, children):
    """Creates and returns a program node

    Parameters:
    id (string): Name of the program
    children (list[node]): List of children nodes

    Returns:
    node:Program node

    """
    # print("CHILDREN", get_children(children))
    return {"name": "PROGRAM", "id": id, "children": get_children(children)}


def function_node(id, return_type, children):
    """Creates and returns a function node

    Parameters:
    id (string): Name of the function
    return_type (string): Return type of the function
    children (list[node]): List of children nodes

    Returns:
    node:Function node

    """
    return {
        "name": "FUNCTION",
        "id": id,
        "return_type": return_type,
        "children": children,
    }

def procedure_node(id, parameters, children):
    """Creates and returns a procedure node

    Parameters:
    id (string): Name of the procedure
    parameters (list[tuple]): List of parameters
    children (list[node]): List of children nodes

    Returns:
    node:Procedure node

    """
    return {
        "name": "PROCEDURE",
        "id": id,
        "parameters": get_parameters(parameters),
        "children": children,
    }

def logic_node(name, condition, children):
    """Creates and returns a loop node

    Parameters:
    id (string): Name of the loop
    condition (string): Condition of the loop
    children (list[node]): List of children nodes

    Returns:
    node:Loop node

    """
    if condition == "":
        return {
            "name": name,
            "children": get_children(children),
        }
    else:
        return {
            "name": name,
            "condition": f"({condition})",
            "children": get_children(children),
        }

def statements_node(children):
    """Creates and returns a statements node, reformats children

    Parameters:
    children (list[node]): List of nested children nodes

    Returns:
    node:Statements node

    """
    # return {
    #     "name": "STATEMENTS",
    #     "children": get_children(children),
    # }
    return get_children(children)

def find_leaves(leaves, nested):
    if type(nested) == dict:
        leaves.append(nested)
    elif type(nested) == list and len(nested) > 0:
        find_leaves(leaves, nested.pop())
        find_leaves(leaves, nested)

def get_children(children):
    leaves = []
    find_leaves(leaves, children)
    return leaves

def find_parameters(params, nested):
    if type(nested) == tuple:
        params.append(nested)
    elif type(nested) == list and len(nested) > 0:
        find_parameters(params, nested.pop())
        find_parameters(params, nested)

def get_parameters(parameters):
    params = []
    find_parameters(params, parameters)
    return params

def node(token, left, right):
    """Creates and returns a generic node with exactly TWO children

    Parameters:
    token (string): Name of the node
    left (node): Left child node
    right (node): Right child node

    Returns:
    node:generic node

    """
    if type(left) != dict:
        left = {"name": left}
    if type(right) != dict:
        right = {"name": right}
    return {
        "name": token,
        "children": [
            left,
            right,
        ],
    }

def func_call_node(id, children):
    """Creates and returns a function call node

    Parameters:
    id (string): Name of the function
    children (list[node]): List of arguments passed to function

    Returns:
    node:Function call node

    """
    return {
        "name": "FUNCTION CALL",
        "id": id,
        "children": get_children(children),
    }

def return_node(children):
    """Creates and returns a return node

    Parameters:
    children (list[node]): List of children nodes

    Returns:
    node:Return node

    """
    if type(children) != dict:
        children = {"name": children}
    return {
        "name": "RETURN",
        "children": [children],
    }

test = []

def add_node_numbers(ast):
    """Adds node numbers to the AST

    Parameters:
    ast (node): Root node of the AST

    Returns:
    node:Root node of the AST with node numbers
    """
    def add_node_numbers_helper(ast):
        if "children" in ast:
            ast["name"] += ' #' + str(len(test))
            for child in ast["children"]:
                test.append(1)
                child = add_node_numbers_helper(child)
        else:
            ast["name"] = str(ast["name"]) + ' #' + str(len(test))

    ast = add_node_numbers_helper(ast)

   


def print_ast(ast):
    """Prints the AST in a tree format

    Parameters:
    ast (node): Root node of the AST

    """
    copy_ast = copy.deepcopy(ast)
    add_node_numbers(copy_ast)
    root = nested_dict_to_tree(copy_ast)
    print('\n{:=^100}'.format("Abstract Syntax Tree"))
    root.show(attr_list=["id", "return_type", "parameters", "node#", 'condition'])
    # root.show(attr_list=["node", "return_type", "node#"])
    print("="*100)

    
    
    
