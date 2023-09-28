
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
Program: K_PROGRAM IDENTIFIER LCURLY Function RCURLY {printf("Top node\n");}
;
Function: K_FUNCTION K_INTEGER IDENTIFIER LPAREN RPAREN LCURLY Statements RCURLY {printf("Function node\n");}
;
Statements: Declare Statements | Assign Statements | Print Statements | Epsilon {printf("Statement node\n");}
;
Declare: K_INTEGER IDENTIFIER SEMI {printf("Declare node\n");}
;
Assign: IDENTIFIER ASSIGN ICONSTANT SEMI {printf("Assign node\n");}
;
Print: K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI | K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI {printf("Print node\n");}
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