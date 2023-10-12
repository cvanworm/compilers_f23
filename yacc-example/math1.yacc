%union {
    double dval;
    char* sval;
}

%token <sval> NAME
%token <dval> NUMBER
%left '-' '+'
%left '*' '/'
%nonassoc UMINUS
%type <dval> expression
f
%%

statement_list: statement '\n'
| statement_list statement '\n'
;
statement: NAME '=' expression { printf("%s= %g\n", $1,$3); }
| expression { printf("= %g\n", $1); }
;
expression: expression '+' expression { $$ = $1 + $3; }
| expression '-' expression { $$ = $1 - $3; }
| expression '*' expression { $$ = $1 * $3; }
| expression '/' expression
{ if($3 == 0.0)
        yyerror("divide by zero");
    else
        $$ = $1 / $3;
}
| '-' expression %prec UMINUS { $$ = -$2; }
| '(' expression ')' { $$ = $2; }
| NUMBER
| NAME { $<sval>$ = $1; }
;
%%

int yyerror(char *msg)
 {
  printf("invalid string\n");
  exit(0);
 }

 main()
 {
  printf("enter the string\n");
  yyparse();
 }