
%{
   /* Definition section */
  #include<stdio.h>
  #include<stdlib.h>
 %}

%union {
    double dval;
    char* sval;
}

%token <sval> IDENTIFIER
  
%token K_PROGRAM LCURLY K_FUNCTION K_INTEGER LPAREN RPAREN SEMI ASSIGN ICONSTANT K_PRINT_INTEGER K_PRINT_STRING RCURLY SCONSTANT PLUS MINUS MULTIPLY DIVIDE DECREMENT INCREMENT K_STRING K_IF K_THEN DEQ GEQ GT LEQ LT NE NOT DAND DOR K_ELSE K_WHILE K_PROCEDURE COMMA K_RETURN K_DOUBLE K_DO
  
/* Rule Section */
%%
code: Program {printf("valid program\n");
             exit(0);}
;
Program: K_PROGRAM IDENTIFIER LCURLY FuncProd RCURLY {printf("program %s\n",$2);}
;
FuncProd: Function FuncProd | Procedure FuncProd | Epsilon
;
Procedure: K_PROCEDURE IDENTIFIER LPAREN Parameters RPAREN LCURLY Statements RCURLY
;
Function: K_FUNCTION Type IDENTIFIER LPAREN Parameters RPAREN LCURLY Statements Return RCURLY
;
Parameters: Type IDENTIFIER | Type IDENTIFIER COMMA MoreParams | Epsilon
;
MoreParams: Type IDENTIFIER | Type IDENTIFIER COMMA MoreParams
;
Type: K_INTEGER | K_STRING | K_DOUBLE
;
Statements: Statement Statements | If Statements | While Statements | Epsilon
;
Statement: Declare | Assign | Print | IDENTIFIER IncDec 
;
Declare: Type IDENTIFIER SEMI
;
Print: K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI | K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI
;
If: K_IF LPAREN Condition RPAREN K_THEN LCURLY Statements RCURLY ElseIf | K_IF LPAREN Condition RPAREN K_THEN Statement ElseIf
;
ElseIf: K_ELSE K_IF LPAREN Condition RPAREN K_THEN LCURLY Statements RCURLY Else | K_ELSE K_IF LPAREN Condition RPAREN K_THEN Statement Else | Else
;
While: K_WHILE LPAREN Condition RPAREN LCURLY Statements RCURLY | K_WHILE LPAREN Condition RPAREN Statement
;
Condition: IDENTIFIER BoolComp ICONSTANT | IDENTIFIER BoolComp IDENTIFIER | IDENTIFIER BoolComp ICONSTANT DAND Condition
;
Else: K_ELSE LCURLY Statements RCURLY | K_ELSE Statement | Epsilon
;
BoolComp: DEQ | GEQ | GT | LEQ | LT | NE
;
Assign: IDENTIFIER ASSIGN SCONSTANT SEMI | IDENTIFIER IncDec SEMI | IDENTIFIER ASSIGN Math SEMI | Type IDENTIFIER ASSIGN Math SEMI
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
Arguments: IDENTIFIER | IDENTIFIER COMMA MoreArgs | Epsilon
;
MoreArgs: IDENTIFIER | IDENTIFIER COMMA MoreArgs
;
Return: K_RETURN IDENTIFIER SEMI | K_RETURN IDENTIFIER LPAREN Arguments RPAREN SEMI | K_RETURN ICONSTANT SEMI | K_RETURN Assign | Epsilon
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