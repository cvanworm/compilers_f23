
%{
   /* Definition section */
  #include<stdio.h>
  #include<stdlib.h>
 %}
  
%token K_PROGRAM IDENTIFIER LCURLY K_FUNCTION K_INTEGER LPAREN RPAREN SEMI ASSIGN ICONSTANT K_PRINT_INTEGER K_PRINT_STRING RCURLY SCONSTANT K_IF K_THEN DEQ GEQ GT LEQ LT NE NOT DAND DOR K_ELSE
  
/* Rule Section */
%%
code: Program {printf("valid program\n");
             exit(0);}
;
Program: K_PROGRAM IDENTIFIER LCURLY Function RCURLY
;
Function: K_FUNCTION K_INTEGER IDENTIFIER LPAREN RPAREN LCURLY Statements RCURLY 
;
Statements: Declare Statements | Assign Statements | Print Statements | Epsilon | If Statements
;
Declare: K_INTEGER IDENTIFIER SEMI
;
Assign: IDENTIFIER ASSIGN ICONSTANT SEMI
;
Print: K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI | K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI
;
If: K_IF LPAREN Condition RPAREN K_THEN LCURLY Statements RCURLY ElseIf | K_IF LPAREN Condition RPAREN K_THEN SpecialStatement ElseIf
;
ElseIf: K_ELSE K_IF LPAREN Condition RPAREN K_THEN LCURLY Statements RCURLY Else | K_ELSE K_IF LPAREN Condition RPAREN K_THEN SpecialStatement Else | Else
;
Condition: IDENTIFIER BoolComp ICONSTANT
;
Else: K_ELSE LCURLY Statements RCURLY | K_ELSE SpecialStatement | Epsilon
;
BoolComp: DEQ | GEQ | GT | LEQ | LT | NE
;
SpecialStatement: Print | Assign | Declare
;
Epsilon: ;



%%
  
int yyerror(char *msg)
 {
  printf("invalid program\n");
  exit(0);
 }
  
  
//driver code 
main()
 {
  /* printf("enter the string\n"); */
  yyparse();
 }