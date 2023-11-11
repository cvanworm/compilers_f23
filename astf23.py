from bigtree import nested_dict_to_tree

def program_node(id, children):
    """Creates and returns a program node

    Parameters:
    id (string): Name of the program
    children (list[node]): List of children nodes

    Returns:
    node:Program node

    """
    return {"name": "PROGRAM", "node": id, "children": children}


def function_node(id, return_type, children):
    """Creates and returns a function node

    Parameters:
    id (string): Name of the function
    return_type (string): Return type of the function
    children (list[node]): List of children nodes

    Returns:
    node:Function node

    """
    if children == [None]:
        return {
            "name": "FUNCTION",
            "node": id,
            "return_type": return_type,
        }
    return {
        "name": "FUNCTION",
        "node": id,
        "return_type": return_type,
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
    # print("LEAVES",leaves)
    return leaves


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


def print_ast(ast):
    """Prints the AST in a tree format

    Parameters:
    ast (node): Root node of the AST

    """
    root = nested_dict_to_tree(ast)
    print('\n{:=^80}'.format("Abstract Syntax Tree"))
    root.show(attr_list=["node", "return_type"])
    print("="*80)
