
%{
   /* Definition section */
  #include<stdio.h>
  #include<stdlib.h>
 %}
  
%token K_PROGRAM IDENTIFIER LCURLY K_FUNCTION K_INTEGER LPAREN RPAREN SEMI ASSIGN ICONSTANT K_PRINT_INTEGER K_PRINT_STRING RCURLY SCONSTANT PLUS MINUS MULTIPLY DIVIDE DECREMENT INCREMENT K_STRING K_IF K_THEN DEQ GEQ GT LEQ LT NE NOT DAND DOR K_ELSE K_WHILE
  
/* Rule Section */
%%
code: Program {printf("valid program\n");
             exit(0);}
;
Program: K_PROGRAM IDENTIFIER LCURLY Function RCURLY
;
Function: K_FUNCTION K_INTEGER IDENTIFIER LPAREN RPAREN LCURLY Statements RCURLY
;
Statements: Statement Statements | If Statements | While Statements | Epsilon
;
Statement: Declare | Assign | Print | IDENTIFIER IncDec 
;
Declare: K_INTEGER IDENTIFIER SEMI | K_STRING IDENTIFIER SEMI
;
Print: K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI | K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI
;
If: K_IF LPAREN Condition RPAREN K_THEN LCURLY Statements RCURLY ElseIf | K_IF LPAREN Condition RPAREN K_THEN Statement ElseIf
;
ElseIf: K_ELSE K_IF LPAREN Condition RPAREN K_THEN LCURLY Statements RCURLY Else | K_ELSE K_IF LPAREN Condition RPAREN K_THEN Statement Else | Else
;
While: K_WHILE LPAREN Condition RPAREN LCURLY Statements RCURLY
;
Condition: IDENTIFIER BoolComp ICONSTANT | IDENTIFIER BoolComp IDENTIFIER
;
Else: K_ELSE LCURLY Statements RCURLY | K_ELSE Statement | Epsilon
;
BoolComp: DEQ | GEQ | GT | LEQ | LT | NE
;
Assign: IDENTIFIER ASSIGN SCONSTANT SEMI | IDENTIFIER IncDec SEMI | IDENTIFIER ASSIGN Math SEMI
;
IncDec: INCREMENT SEMI | DECREMENT SEMI
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