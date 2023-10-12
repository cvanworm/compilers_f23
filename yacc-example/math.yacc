
%{
   /* Definition section */
  #include<stdio.h>
  #include<stdlib.h>
  %}

%token MINUS PLUS EQUAL

%token <vblno> NAME
%token <dval> NUMBER
%type <dval> expression

%%
statement: NAME EQUAL expression { printf("= %d\n", $1); }
| expression { printf("= %d\n", $1); }
;
expression: expression PLUS NUMBER { printf("%d + %d ", $1, $3); $$ = $1 + $3; }
| expression MINUS NUMBER { $$ = $1 - $3; }
| NUMBER { $$ = $1; }
;

%% 

int yyerror(char *msg)
 {
  printf("invalid string\n");
  exit(0);
 }
  
  
//driver code 
main()
 {
  printf("enter the equation\n");
  yyparse();
 }