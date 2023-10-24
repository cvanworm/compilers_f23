
%{
   /* Definition section */
  #include<stdio.h>
  #include<stdlib.h>
 %}

%union {
    double dval;
    int ival;
    char* sval;
}

%token <sval> IDENTIFIER SCONSTANT K_INTEGER K_STRING K_DOUBLE

%token <ival> ICONSTANT

%token <dval> DCONSTANT

%type <sval> Type
  
%token K_PROGRAM LCURLY K_FUNCTION  LPAREN RPAREN SEMI ASSIGN K_PRINT_INTEGER K_PRINT_STRING RCURLY PLUS MINUS MULTIPLY DIVIDE DECREMENT INCREMENT  K_IF K_THEN DEQ GEQ GT LEQ LT NE NOT DAND DOR K_ELSE K_WHILE K_PROCEDURE COMMA K_RETURN K_DO
  
/* Rule Section */
%%
code: Program {printf("valid code\n");
             exit(0);}
;
Program: K_PROGRAM IDENTIFIER LCURLY FuncProd RCURLY {printf("Program node: %s\n", $2);printStars();}
;
FuncProd: Function FuncProd | Procedure FuncProd | Epsilon
;
Procedure: K_PROCEDURE IDENTIFIER LPAREN Parameters RPAREN LCURLY Statements RCURLY {printf("Procedure node: \n"); printStars();}
;
Function: K_FUNCTION Type IDENTIFIER LPAREN Parameters RPAREN LCURLY Statements Return RCURLY {printf("Function node: %s\n", $3); printStars();}
;
Parameters: Type IDENTIFIER {printf("Parameters node\n");}
| Type IDENTIFIER COMMA MoreParams {printf("More Parameters node\n");}
| Epsilon
;
MoreParams: Type IDENTIFIER | Type IDENTIFIER COMMA MoreParams
;
Type: K_INTEGER { $$ = $1; } | K_STRING { $$ = $1; } | K_DOUBLE { $$ = $1;}
;
Statements: Statement Statements | If Statements | While Statements | Epsilon {printf("Statements node:\n"); printStars();}
;
Statement: Declare | Assign | Print | IDENTIFIER IncDec 
;
Declare: Type IDENTIFIER SEMI {printf("%s\n%s\nDeclare node: \n", $2, $1);printStars();}
;
Print: K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI {printf("%s\nprint_integer\nprint node: \n", $3); printStars();} | K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI {printf("%s\nprint_string\nprint node: \n", $3); printStars();}
;
If: K_IF LPAREN Condition RPAREN K_THEN LCURLY Statements RCURLY ElseIf | K_IF LPAREN Condition RPAREN K_THEN Statement ElseIf
;
ElseIf: K_ELSE K_IF LPAREN Condition RPAREN K_THEN LCURLY Statements RCURLY Else | K_ELSE K_IF LPAREN Condition RPAREN K_THEN Statement Else | Else
;
While: K_WHILE LPAREN Condition RPAREN LCURLY Statements RCURLY | K_WHILE LPAREN Condition RPAREN Statement
;
Condition: IDENTIFIER BoolComp NumConstant | IDENTIFIER BoolComp IDENTIFIER | IDENTIFIER BoolComp NumConstant DAND Condition
;
Else: K_ELSE LCURLY Statements RCURLY | K_ELSE Statement | Epsilon
;
BoolComp: DEQ | GEQ | GT | LEQ | LT | NE
;
Assign: IDENTIFIER ASSIGN SCONSTANT SEMI 
| IDENTIFIER IncDec SEMI
| IDENTIFIER ASSIGN Math SEMI {printf("%s\nAssign node: \n", $1); printStars();}
| Type IDENTIFIER ASSIGN Math SEMI 
;
IncDec: INCREMENT SEMI | DECREMENT SEMI
;
Math: IDENTIFIER IncDec | NumConstant IncDec | Expr
;
Expr: Expr PLUS Term | Expr MINUS Term | Term
;
Term: Term MULTIPLY Factor | Term DIVIDE Factor | Factor
;
Factor: NumConstant | IDENTIFIER { $<sval>$ = $1; }| LPAREN Math RPAREN | MINUS LPAREN Math RPAREN
;
Arguments: IDENTIFIER | IDENTIFIER COMMA MoreArgs | Epsilon
;
MoreArgs: IDENTIFIER | IDENTIFIER COMMA MoreArgs
;
Return: K_RETURN IDENTIFIER SEMI
| K_RETURN IDENTIFIER LPAREN Arguments RPAREN SEMI
| K_RETURN NumConstant SEMI
| K_RETURN Assign
| Epsilon
;
NumConstant: ICONSTANT { $<ival>$ = $1; printf("%d\n", $1); } | DCONSTANT { $<dval>$ = $1; printf("%f\n", $1); }
;
Epsilon: ;



%%
  
int yyerror(char *msg)
 {
  printf("invalid program: %s\n", msg);
  exit(0);
 }

printStars()
{
  for(int i=0;i<50;i++)
  {
    printf("*");
  }
  //print new line
   printf("\n");
}
  
  
//driver code 
main()
 {
  /* printf("enter the string\n"); */
  yyparse();
 }