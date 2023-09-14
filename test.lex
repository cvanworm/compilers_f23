/*** Definition Section has one variable
which can be accessed inside yylex()
and main() ***/
%{
#include <ctype.h>
%}
Blank [ |\t]+
Digit [0-9]
Letter [A-Z]|[a-z]
Comment \/\/.*\n 
Keyword do|double|else|exit|function|if|integer|print_double|print_integer|print_string|procedure|read_double|read_integer|read_string|return|string|then|while
Assign :=
Sconstant \"[^\"]*\"


/*** Rule Section has three rules, first rule
matches with capital letters, second rule
matches with any character except newline and
third rule does not take input after the enter***/
%%
{Comment} {printf("COMMENT: %s\n", yytext);}

{Keyword} {int j = 0;
	char tmp[strlen(yytext)];
	while (yytext[j]) {
        tmp[j]=toupper(yytext[j]);
        j++;
    }
	printf("K_%s: %s\n", tmp, yytext);}

{Assign} {printf("ASSIGN_%s", yytext);}

({Letter}|_|$)+({Letter}|{Digit}|_|$)* {printf("IDENTIFIER %s\n", yytext);}

{Sconstant} {printf("SCONSTANT %s\n", yytext);}

{Digit} {printf("%s digit\n", yytext);}

{Blank} {}

\n   {printf("newline\n");}

%%

/*** Code Section prints the number of
capital letter present in the given input***/
int yywrap(){}
int main(){

// Explanation:
// yywrap() - wraps the above rule section
/* yyin - takes the file pointer
		which contains the input*/
/* yylex() - this is the main flex function
		which runs the Rule Section*/
// yytext is the text in the buffer

// Uncomment the lines below
// to take input from file
FILE *fp;
fp = fopen("file.txt","r");
yyin = fp;

yylex();

return 0;
}
