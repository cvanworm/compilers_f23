/*** Definition Section has one variable
which can be accessed inside yylex()
and main() ***/
%{
#include <ctype.h>

%}
Blank [ |\t]+
Digit [0-9]
Int {Digit}+
Float -?(([0-9]+)|(([0-9]*\.[0-9]+)|([0-9]+\.[0-9]*))([dD][-+]?[0-9]+)?)
Letter [A-Z]|[a-z]
Comment \/\/.*
Keyword do|double|else|exit|function|if|integer|print_double|print_integer|print_string|procedure|program|read_double|read_integer|read_string|return|string|then|while
Assignment :=|\+=|-=|\*=|\/=|%=
Bool &&|\|\||==|>=|>|<=|<|!=|!
Math \/|-|--|%|\*|\+|\+\+
Symbol ,|\[|\{|\(|\.|\)|\}|\]|;
Sconstant \"[^\"]*\"
Identifier ({Letter}|_|$)+({Letter}|{Digit}|_|$)*



/*** Rule Section has three rules, first rule
matches with capital letters, second rule
matches with any character except newline and
third rule does not take input after the enter***/
%%

{Comment} {printf("COMMENT: %s\n", yytext);}

{Keyword} {int j = 0;
	char *tmp = (char *) malloc(strlen(yytext));
	while (j<strlen(yytext)) {
        tmp[j]=toupper(yytext[j]);
        j++;
    }
	printf("K_%s: %s\n", tmp, yytext);}

{Assignment} {
	if (strcmp(yytext,":=") == 0){
		printf("ASSIGN: %s\n", yytext);
	}
	else if (strcmp(yytext,"+=") == 0){
		printf("ASSIGN_PLUS: %s\n", yytext);
	}
	else if (strcmp(yytext,"-=") == 0){
		printf("ASSIGN_MINUS: %s\n", yytext);
	}
	else if (strcmp(yytext,"*=") == 0){
		printf("ASSIGN_MULTIPLY: %s\n", yytext);
	}
	else if (strcmp(yytext,"/=") == 0){
		printf("ASSIGN_DIVIDE: %s\n", yytext);
	}
	else if (strcmp(yytext,"%=") == 0){
		printf("ASSIGN_MOD: %s\n", yytext);
	}
}

{Bool} {
    if(strcmp(yytext,"&&") == 0){
        printf("DAND: %s\n", yytext);
    }
    else if(strcmp(yytext,"||") == 0){
        printf("DOR: %s\n", yytext);
    }
    else if(strcmp(yytext,"==") == 0){
        printf("DEQ: %s\n", yytext);
    }
    else if(strcmp(yytext,">=") == 0){
        printf("GEQ: %s\n", yytext);
    }
    else if(strcmp(yytext,">") == 0){
        printf("GT: %s\n", yytext);
    }
    else if(strcmp(yytext,"<=") == 0){
        printf("LEQ: %s\n", yytext);
    }
    else if(strcmp(yytext,"<") == 0){
        printf("LT: %s\n", yytext);
    }
    else if(strcmp(yytext,"!=") == 0){
        printf("NE: %s\n", yytext);
    }
    else if(strcmp(yytext,"!") == 0){
        printf("NOT: %s\n", yytext);
    }
}

{Math} {
	if (strcmp(yytext,"/") == 0){
		printf("DIVIDE: %s\n", yytext);
	}
	else if (strcmp(yytext,"-") == 0){
		printf("MINUS: %s\n", yytext);
	}
	else if (strcmp(yytext,"--") == 0){
		printf("DECREMENT: %s\n", yytext);
	}
	else if (strcmp(yytext,"%") == 0){
		printf("MOD: %s\n", yytext);
	}
	else if (strcmp(yytext,"*") == 0){
		printf("MULTIPLY: %s\n", yytext);
	}
	else if (strcmp(yytext,"+") == 0){
		printf("PLUS: %s\n", yytext);
	}
	else if (strcmp(yytext,"++") == 0){
		printf("INCREMENT: %s\n", yytext);
	}
}

{Symbol} {
	if (strcmp(yytext,",") == 0){
		printf("COMMA: %s\n", yytext);
	}
	else if (strcmp(yytext,"[") == 0){
		printf("LBRACKET: %s\n", yytext);
	}
	else if (strcmp(yytext,"{") == 0){
		printf("LCURLY: %s\n", yytext);
	}
	else if (strcmp(yytext,"(") == 0){
		printf("LPAREN: %s\n", yytext);
	}
	else if (strcmp(yytext,".") == 0){
		printf("PERIOD: %s\n", yytext);
	}
	else if (strcmp(yytext,"]") == 0){
		printf("RBRACKET: %s\n", yytext);
	}
	else if (strcmp(yytext,"}") == 0){
		printf("RCURLY: %s\n", yytext);
	}
	else if (strcmp(yytext,")") == 0){
		printf("RPAREN: %s\n", yytext);
	}
	else if (strcmp(yytext,";") == 0){
		printf("SEMI: %s\n", yytext);
	}
}

{Identifier} {printf("IDENTIFIER: %s\n", yytext);}

{Int} {printf("ICONSTANT: %s\n", yytext);}

{Float} {printf("DCONSTANT: %s\n", yytext);}

{Sconstant} {printf("SCONSTANT: %s\n", yytext);}

{Blank} {}

\n   {}

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
	FILE *ifp;
	ifp = fopen("file.txt","r");
	yyin = ifp;


	yylex();

	return 0;
}
