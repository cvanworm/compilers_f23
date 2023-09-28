
%{
   /* Definition section */
  #include<stdio.h>
  #include<stdlib.h>
 %}
  
%token K_PROGRAM IDENTIFIER LCURLY K_FUNCTION K_INTEGER LPAREN RPAREN SEMI ASSIGN ICONSTANT K_PRINT_INTEGER K_PRINT_STRING RCURLY SCONSTANT
  
/* Rule Section */
%%
code: Program {printf("valid program\n");
             exit(0);}
;
Program: K_PROGRAM IDENTIFIER LCURLY Function RCURLY
;
Function: K_FUNCTION K_INTEGER IDENTIFIER LPAREN RPAREN LCURLY Statements RCURLY 
;
Statements: Declare Statements | Assign Statements | Print Statements | Epsilon
;
Declare: K_INTEGER IDENTIFIER SEMI
;
Assign: IDENTIFIER ASSIGN ICONSTANT SEMI
;
Print: K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI | K_PRINT_STRING LPAREN SCONSTANT RPAREN
;
Epsilon: ;



%%
  
int yyerror(char *msg)
 {
  printf("invalid string\n");
  exit(0);
 }
  
  
//driver code 
main()
 {
  /* printf("enter the string\n"); */
  yyparse();
 }