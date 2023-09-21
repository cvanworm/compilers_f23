
%{
   /* Definition section */
  #include<stdio.h>
  #include<stdlib.h>
 %}
  
%token A B NL COMMENT
  
/* Rule Section */
%%
stmt: COMMENT {printf("valid string\n");
             exit(0);}
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