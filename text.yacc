
%{
   /* Definition section */
  #include<stdio.h>
  #include<stdlib.h>
 %}
  
%token K_PROGRAM IDENTIFIER LCURLY K_FUNCTION K_INTEGER LPAREN RPAREN SEMI ASSIGN ICONSTANT K_PRINT_INTEGER K_PRINT_STRING RCURLY SCONSTANT PLUS MINUS MULTIPLY DIVIDE DECREMENT INCREMENT K_STRING
  
/* Rule Section */
%%
code: Program {printf("valid program\n");
             exit(0);}
;
Program: K_PROGRAM IDENTIFIER LCURLY Function RCURLY
;
Function: K_FUNCTION K_INTEGER IDENTIFIER LPAREN RPAREN LCURLY Statements RCURLY
;
Statements: Statement Statements | Epsilon
;
Statement: Declare | Assign | Print | IDENTIFIER IncDec
;
Declare: K_INTEGER IDENTIFIER SEMI | K_STRING IDENTIFIER SEMI
;
Assign: IDENTIFIER ASSIGN SCONSTANT SEMI | IDENTIFIER IncDec SEMI | IDENTIFIER ASSIGN Math SEMI
;
Print: K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI | K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI
;
IncDec: INCREMENT | DECREMENT
;
Math: IDENTIFIER IncDec | ICONSTANT IncDec | Expr
;
Expr: Expr PLUS Term | Expr MINUS Term | Term
;
Term: Term MULTIPLY Factor | Term DIVIDE Factor | Factor
;
Factor: ICONSTANT | IDENTIFIER | LPAREN Math RPAREN | MINUS LPAREN Math RPAREN
;
Epsilon: ;



%%
  
int yyerror(char *msg)
 {
  printf("invalid program: %s\n", msg);
  exit(0);
 }
  
  
//driver code 
main()
 {
  /* printf("enter the string\n"); */
  yyparse();
 }