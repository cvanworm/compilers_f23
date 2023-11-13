from bigtree import nested_dict_to_tree

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

def statements_node(children):
    """Creates and returns a statements node, reformats children

    Parameters:
    children (list[node]): List of nested children nodes

    Returns:
    node:Statements node

    """
    return {
        "name": "STATEMENTS",
        "children": get_children(children),
    }

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
    return {
        "name": token,
        "children": [
            {"name": left},
            {"name": right},
        ],
    }


def add_node_numbers(ast):
    """Adds node numbers to the AST

    Parameters:
    ast (node): Root node of the AST

    Returns:
    node:Root node of the AST with node numbers
    """
    def add_node_numbers_helper(ast, node_number):
        if "children" not in ast:
            # ast["name"] += ' ' + str(node_number)
            # node_number += 1
            # print("AST", ast)
            pass
        else:
            ast["name"] += ' #' + str(node_number)
            # ast["node#"] = str(node_number)
            for child in ast["children"]:
                node_number += 1
                child = add_node_numbers_helper(child, node_number)
        return ast
    ast = add_node_numbers_helper(ast, 0)
    return ast

   


def print_ast(ast):
    """Prints the AST in a tree format

    Parameters:
    ast (node): Root node of the AST

    """
    ast = add_node_numbers(ast)
    root = nested_dict_to_tree(ast)
    print('\n{:=^80}'.format("Abstract Syntax Tree"))
    root.show(attr_list=["id", "return_type", "parameters", "node#"])
    # root.show(attr_list=["node", "return_type", "node#"])
    print("="*80)

declare = node("DECLARE", 'integer', 'i')
statements = statements_node(declare)
function = function_node("main", "integer", [statements])
root = program_node("tiny", [function])

# print("ROOT", root)
# print_ast(add_node_numbers(root))

