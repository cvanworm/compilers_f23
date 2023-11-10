from bigtree import nested_dict_to_tree

def program_node(id, children):
    "name of program (string)"
    "children nodes (list)"
    return {"name": "PROGRAM", "node": id, "children": children}


def function_node(id, return_type, children):
    """name of function (string)
    children nodes (list)"""
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
    """children nodes (list)"""
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


def leaf_node(token, left, right):
    """token (string)
    value (string)"""
    return {
        "name": token,
        "children": [
            {"name": left},
            {"name": right},
        ],
    }


def print_ast(ast):
    root = nested_dict_to_tree(ast)
    root.show(attr_list=["node", "return_type"])
