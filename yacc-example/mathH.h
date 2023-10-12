#define NSYMS 20 /* Max number of symbols*/

struct symtab {
    char *name;
    double value;
} symtab[NSYMS];
//  Takes a name as argument and returns a pointer to the symbol table entry for that name, or NULL if not found.
struct symtab *symlook();