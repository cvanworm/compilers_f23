
%{
   /* Definition section */
  #include<stdio.h>
  #include<stdlib.h>
 %}
  
%token IDERROR COMMENT ASSIGN ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MULTIPLY ASSIGN_DIVIDE ASSIGN_MOD DAND 
  
/* Rule Section */
%%
stmt: COMMENT {printf("valid string\n");}
   | COMMENT stmt
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
  /* printf("enter the string\n"); */
  yyparse();
 }