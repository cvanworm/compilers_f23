/*** Definition Section has one variable
which can be accessed inside yylex()
and main() ***/
%{
#include <ctype.h>
#include "y.tab.h"

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

{IdError} {
	printf("token(IDERROR, %s)\n", yytext);
	return IDERROR;
	}

{Comment} {
	printf("token(COMMENT, %s)\n", yytext);
	return COMMENT;
}

{Keyword} {int j = 2;
	char *tmp = (char *) malloc(strlen(yytext)+2);
	tmp[0] = 'K';
	tmp[1] = '_';
	while (j<strlen(yytext)+2) {
        tmp[j]=toupper(yytext[j-2]);
        j++;
    }
	printf("token(%s, %s)\n", tmp, yytext);
	return tmp; }

{Assignment} {
	if (strcmp(yytext,":=") == 0){
		printf("token(ASSIGN, %s)\n", yytext);
		return ASSIGN;
	}
	else if (strcmp(yytext,"+=") == 0){
		printf("token(ASSIGN_PLUS, %s)\n", yytext);
		return ASSIGN_PLUS;
	}
	else if (strcmp(yytext,"-=") == 0){
		printf("token(ASSIGN_MINUS, %s)\n", yytext);
		return ASSIGN_MINUS;
	}
	else if (strcmp(yytext,"*=") == 0){
		printf("token(ASSIGN_MULTIPLY, %s)\n", yytext);
		return ASSIGN_MULTIPLY;
	}
	else if (strcmp(yytext,"/=") == 0){
		printf("token(ASSIGN_DIVIDE, %s)\n", yytext);
		return ASSIGN_DIVIDE;
	}
	else if (strcmp(yytext,"%=") == 0){
		printf("token(ASSIGN_MOD, %s)\n", yytext);
		return ASSIGN_MOD;
	}
}

{Bool} {
    if(strcmp(yytext,"&&") == 0){
        printf("token(DAND, %s)\n", yytext);
		return DAND;
    }
    else if(strcmp(yytext,"||") == 0){
        printf("token(DOR, %s)\n", yytext);
		return DOR;
    }
    else if(strcmp(yytext,"==") == 0){
        printf("token(DEQ, %s)\n", yytext);
		return DEQ;
    }
    else if(strcmp(yytext,">=") == 0){
        printf("token(GEQ, %s)\n", yytext);
		return GEQ;
    }
    else if(strcmp(yytext,">") == 0){
        printf("token(GT, %s)\n", yytext);
		return GT;
    }
    else if(strcmp(yytext,"<=") == 0){
        printf("token(LEQ, %s)\n", yytext);
		return LEQ;
    }
    else if(strcmp(yytext,"<") == 0){
        printf("token(LT, %s)\n", yytext);
		return LT;
    }
    else if(strcmp(yytext,"!=") == 0){
        printf("token(NE, %s)\n", yytext);
		return NE;
    }
    else if(strcmp(yytext,"!") == 0){
        printf("token(NOT, %s)\n", yytext);
		return NOT;
    }
}

{Math} {
	if (strcmp(yytext,"/") == 0){
		printf("token(DIVIDE, %s)\n", yytext);
		return DIVIDE;
	}
	else if (strcmp(yytext,"-") == 0){
		printf("token(MINUS, %s)\n", yytext);
		return MINUS;
	}
	else if (strcmp(yytext,"--") == 0){
		printf("token(DECREMENT, %s)\n", yytext);
		return DECREMENT;
	}
	else if (strcmp(yytext,"%") == 0){
		printf("token(MOD, %s)\n", yytext);
		return MOD;
	}
	else if (strcmp(yytext,"*") == 0){
		printf("token(MULTIPLY, %s)\n", yytext);
		return MULTIPLY;
	}
	else if (strcmp(yytext,"+") == 0){
		printf("token(PLUS, %s)\n", yytext);
		return PLUS;
	}
	else if (strcmp(yytext,"++") == 0){
		printf("token(INCREMENT, %s)\n", yytext);
		return INCREMENT;
	}
}

{Symbol} {
	if (strcmp(yytext,",") == 0){
		printf("token(COMMA, %s)\n", yytext);
		return COMMA;
	}
	else if (strcmp(yytext,"[") == 0){
		printf("token(LBRACKET, %s)\n", yytext);
		return LBRACKET;
	}
	else if (strcmp(yytext,"{") == 0){
		printf("token(LCURLY, %s)\n", yytext);
		return LCURLY;
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
int yywrap(){
	return 1;
}

