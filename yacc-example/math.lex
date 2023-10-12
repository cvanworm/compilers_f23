#define NAME 257
#define NUMBER 258
#define UMINUS 259
typedef union {
double dval;
int vblno;
} YYSTYPE;
extern YYSTYPE yylval

%{
#include "y.tab.h"
extern int yylval;
extern char* yystype;
%}
%%
[a-z] {  yystype = yytext; return NAME;}
[0-9]+ { yylval = atoi(yytext); return NUMBER; }
[ \t\s] ; /* ignore whitespace */
[\-] {return MINUS;}
[\+] {return PLUS;}
[=] {return EQUAL;}

\n return 0; /* logical EOF */
. return yytext[0];
%%

int yywrap() 
{ 
   return 1; 
}