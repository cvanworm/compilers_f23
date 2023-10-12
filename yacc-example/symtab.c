#include "mathH.h"
struct symtab *
symlook(s)
char *s;
{
    char *p;
    struct symtab *sp;
    for (sp = symtab; sp < &symtab[NSYMS]; sp++)
    {
        /* is it already here? */
        if (sp->name && !strcmp(sp->name, s))
            return sp;
        /* is it free */
        if (!sp->name)
        {
            sp->name = strdup(s);
            return sp;
        }
        /* otherwise continue to next */
    }
    yyerror("Too many symbols");
    exit(1); /* cannot continue */
} /* symlook */