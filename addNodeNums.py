# open and store results from parser
lines = open("results.txt", 'r').readlines()

# Add node numbers
node = 0
i = len(lines)-1
while i >= 0:
    if "node" in lines[i]:
        lines[i] = "NODE " + str(node) + ": " + lines[i]
        node += 1 
    i -= 1

# write lines to results.txt from list
f = open("results.txt", "w")
for line in lines:
    f.write(line)




