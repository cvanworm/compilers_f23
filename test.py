
statements = [
    [
        [
            {'name': 'DECLARE', 'children': [{'name': 'double'},{'name': 'k'}]},
            {'name': 'DECLARE', 'children': [{'name': 'double'}, {'name': 'c'}]}
        ], 
            {'name': 'DECLARE', 'children': [{'name': 'double'}, {'name': 'a'}]}
    ], 
            {'name': 'DECLARE', 'children': [{'name': 'integer'}, {'name': 'i'}]}
]

leaves = []

def find_leaves(nested):
    if type(nested) == dict:
        leaves.append(nested)
    elif type(nested) == list and len(nested) > 0:
        find_leaves(nested.pop())
        find_leaves(nested)
        
# for statement in statements:
#     find_leaves(statement)
find_leaves(statements)

for leaf in leaves:
    print(leaf)