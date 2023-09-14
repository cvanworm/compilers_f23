/*** Definition Section has one variable
which can be accessed inside yylex()
and main() ***/
%{
int cap_count = 0;
int int_count = 0;
%}

/*** Rule Section has three rules, first rule
matches with capital letters, second rule
matches with any character except newline and
third rule does not take input after the enter***/
%%
[A-Za-z]+ {printf("%s word\n", yytext);
	cap_count++;}

[0-9] {printf("%s integer\n", yytext);
      int_count++;}

.	 {printf("%s not a word\n", yytext);}

\n    {return 0;}

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
printf("\nNumber of words "
	"in the given input - %d\n", cap_count);

printf("\nNumber of Integers"
	"in the given input - %d\n", int_count);
return 0;
}
