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
Letter [A-Za-z]
Comment \/\/.*
Keyword do|double|else|exit|function|if|integer|print_double|print_integer|print_string|procedure|program|read_double|read_integer|read_string|return|string|then|while
Assignment :=|\+=|-=|\*=|\/=|%=
Bool &&|\|\||==|>=|>|<=|<|!=|!
Math \/|-|--|%|\*|\+|\+\+
Symbol ,|\[|\{|\(|\.|\)|\}|\]|;
Sconstant \"[^\"]*\"
Identifier ({Letter}|\$|_)({Letter}|\$|_|{Digit}){0,31}
IdError {Digit}+({Letter}|\$|_)+|({Letter}|{Digit}|\$|_){33,}




/*** Rule Section has three rules, first rule
matches with capital letters, second rule
matches with any character except newline and
third rule does not take input after the enter***/
%%

{IdError} {printf("token(IDERROR, %s)\n", yytext);}

{Comment} {printf("token(COMMENT, %s)\n", yytext);}

{Keyword} {int j = 0;
	char *tmp = (char *) malloc(strlen(yytext));
	while (j<strlen(yytext)) {
        tmp[j]=toupper(yytext[j]);
        j++;
    }
	printf("token(K_%s, %s)\n", tmp, yytext);}

{Assignment} {
	if (strcmp(yytext,":=") == 0){
		printf("token(ASSIGN, %s)\n", yytext);
	}
	else if (strcmp(yytext,"+=") == 0){
		printf("token(ASSIGN_PLUS, %s)\n", yytext);
	}
	else if (strcmp(yytext,"-=") == 0){
		printf("token(ASSIGN_MINUS, %s)\n", yytext);
	}
	else if (strcmp(yytext,"*=") == 0){
		printf("token(ASSIGN_MULTIPLY, %s)\n", yytext);
	}
	else if (strcmp(yytext,"/=") == 0){
		printf("token(ASSIGN_DIVIDE, %s)\n", yytext);
	}
	else if (strcmp(yytext,"%=") == 0){
		printf("token(ASSIGN_MOD, %s)\n", yytext);
	}
}

{Bool} {
    if(strcmp(yytext,"&&") == 0){
        printf("token(DAND, %s)\n", yytext);
    }
    else if(strcmp(yytext,"||") == 0){
        printf("token(DOR, %s)\n", yytext);
    }
    else if(strcmp(yytext,"==") == 0){
        printf("token(DEQ, %s)\n", yytext);
    }
    else if(strcmp(yytext,">=") == 0){
        printf("token(GEQ, %s)\n", yytext);
    }
    else if(strcmp(yytext,">") == 0){
        printf("token(GT, %s)\n", yytext);
    }
    else if(strcmp(yytext,"<=") == 0){
        printf("token(LEQ, %s)\n", yytext);
    }
    else if(strcmp(yytext,"<") == 0){
        printf("token(LT, %s)\n", yytext);
    }
    else if(strcmp(yytext,"!=") == 0){
        printf("token(NE, %s)\n", yytext);
    }
    else if(strcmp(yytext,"!") == 0){
        printf("token(NOT, %s)\n", yytext);
    }
}

{Math} {
	if (strcmp(yytext,"/") == 0){
		printf("token(DIVIDE, %s)\n", yytext);
	}
	else if (strcmp(yytext,"-") == 0){
		printf("token(MINUS, %s)\n", yytext);
	}
	else if (strcmp(yytext,"--") == 0){
		printf("token(DECREMENT, %s)\n", yytext);
	}
	else if (strcmp(yytext,"%") == 0){
		printf("token(MOD, %s)\n", yytext);
	}
	else if (strcmp(yytext,"*") == 0){
		printf("token(MULTIPLY, %s)\n", yytext);
	}
	else if (strcmp(yytext,"+") == 0){
		printf("token(PLUS, %s)\n", yytext);
	}
	else if (strcmp(yytext,"++") == 0){
		printf("token(INCREMENT, %s)\n", yytext);
	}
}

{Symbol} {
	if (strcmp(yytext,",") == 0){
		printf("token(COMMA, %s)\n", yytext);
	}
	else if (strcmp(yytext,"[") == 0){
		printf("token(LBRACKET, %s)\n", yytext);
	}
	else if (strcmp(yytext,"{") == 0){
		printf("token(LCURLY, %s)\n", yytext);
	}
	else if (strcmp(yytext,"(") == 0){
		printf("token(LPAREN, %s)\n", yytext);
	}
	else if (strcmp(yytext,".") == 0){
		printf("token(PERIOD, %s)\n", yytext);
	}
	else if (strcmp(yytext,"]") == 0){
		printf("token(RBRACKET, %s)\n", yytext);
	}
	else if (strcmp(yytext,"}") == 0){
		printf("token(RCURLY, %s)\n", yytext);
	}
	else if (strcmp(yytext,")") == 0){
		printf("token(RPAREN, %s)\n", yytext);
	}
	else if (strcmp(yytext,";") == 0){
		printf("token(SEMI, %s)\n", yytext);
	}
}

{Identifier} {printf("token(IDENTIFIER, %s)\n", yytext);}

{Int} {printf("token(ICONSTANT, %s)\n", yytext);}

{Float} {printf("token(DCONSTANT, %s)\n", yytext);}

{Sconstant} {printf("token(SCONSTANT, %s)\n", yytext);}

{Blank} {}

\n   {}

%%

/*** Code Section prints the number of
capital letter present in the given input***/
int yywrap(){}
int main(int argc, char *argv[]){

	// Explanation:
	// yywrap() - wraps the above rule section
	/* yyin - takes the file pointer
			which contains the input*/
	/* yylex() - this is the main flex function
			which runs the Rule Section*/
	// yytext is the text in the buffer

	// Uncomment the lines below
	// to take input from file
	// FILE *ifp;
	// ifp = fopen("file.txt","r");
	// yyin = ifp;


	yylex();

	return 0;
}
