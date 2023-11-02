/*** Definition Section has one variable
which can be accessed inside yylex()
and main() ***/
%{
#include <ctype.h>
#include "y.tab.h"

%}
Blank [ |\t]+
Digit [0-9]
Int -?{Digit}+
Float -?(([0-9]+)|(([0-9]*\.[0-9]+)|([0-9]+\.[0-9]*))([dD][-+]?[0-9]+)?)
Letter [A-Za-z]
Comment \/\/.*
K_DO do
K_DOUBLE double
K_ELSE else
K_EXIT exit
K_FUNCTION function
K_IF if
K_INTEGER integer
K_PRINT_DOUBLE print_double
K_PRINT_INTEGER print_integer
K_PRINT_STRING print_string
K_PROCEDURE procedure
K_PROGRAM program
K_READ_DOUBLE read_double
K_READ_INTEGER read_integer
K_READ_STRING read_string
K_RETURN return
K_STRING string
K_THEN then
K_WHILE while
Assignment :=|\+=|-=|\*=|\/=|%=
Bool &&|\|\||==|>=|>|<=|<|!=|!
Math \/|-|--|%|\*|\+|\+\+
Symbol ,|\[|\{|\(|\.|\)|\}|\]|;
Sconstant \"(\\.|[^"\\])*\"
Identifier ({Letter}|\$|_)({Letter}|\$|_|{Digit}){0,31}
IdError {Digit}+({Letter}|\$|_)+|({Letter}|{Digit}|\$|_){33,}




/*** Rule Section has three rules, first rule
matches with capital letters, second rule
matches with any character except newline and
third rule does not take input after the enter***/
%%

{IdError} {
	printf("token(IDERROR, %s)\n", yytext);
	// return IDERROR;
	}

{Comment} {
	printf("token(COMMENT, %s)\n", yytext);
	// return COMMENT;
}

{K_DO} {
	printf("token(K_DO, %s)\n", yytext);
	return K_DO;
}

{K_DOUBLE} {
	printf("token(K_DOUBLE, %s)\n", yytext);
	return K_DOUBLE;
}

{K_ELSE} {
	printf("token(K_ELSE, %s)\n", yytext);
	return K_ELSE;
}

{K_EXIT} {
	printf("token(K_EXIT, %s)\n", yytext);
	// return K_EXIT;
}

{K_FUNCTION} {
	// printf("token(K_FUNCTION, %s)\n", yytext);
	return K_FUNCTION;
}

{K_IF} {
	printf("token(K_IF, %s)\n", yytext);
	return K_IF;
}

{K_INTEGER} {
	// printf("%s\n", yytext);
	yylval.sval = strdup(yytext);
	return K_INTEGER;
}

{K_PRINT_DOUBLE} {
	printf("token(K_PRINT_DOUBLE, %s)\n", yytext);
	return K_PRINT_DOUBLE;
}

{K_PRINT_INTEGER} {
	// printf("token(K_PRINT_INTEGER, %s)\n", yytext);
	return K_PRINT_INTEGER;
}

{K_PRINT_STRING} {
	// printf("token(K_PRINT_STRING, %s)\n", yytext);
	return K_PRINT_STRING;
}

{K_PROCEDURE} {
	printf("token(K_PROCEDURE, %s)\n", yytext);
	return K_PROCEDURE;
}

{K_PROGRAM} {
	// printf("token(K_PROGRAM, %s)\n", yytext);
	return K_PROGRAM;
}

{K_READ_DOUBLE} {
	printf("token(K_READ_DOUBLE, %s)\n", yytext);
	// return K_READ_DOUBLE;
}

{K_READ_INTEGER} {
	printf("token(K_READ_INTEGER, %s)\n", yytext);
	// return K_READ_INTEGER;
}

{K_READ_STRING} {
	printf("token(K_READ_STRING, %s)\n", yytext);
	// return K_READ_STRING;
}

{K_RETURN} {
	printf("token(K_RETURN, %s)\n", yytext);
	return K_RETURN;
}

{K_STRING} {
	// printf("token(K_STRING, %s)\n", yytext);
	yylval.sval = strdup(yytext);
	return K_STRING;
}

{K_THEN} {
	printf("token(K_THEN, %s)\n", yytext);
	return K_THEN;
}

{K_WHILE} {
	printf("token(K_WHILE, %s)\n", yytext);
	return K_WHILE;
}

{Assignment} {
	if (strcmp(yytext,":=") == 0){
		// printf("token(ASSIGN, %s)\n", yytext);
		return ASSIGN;
	}
	else if (strcmp(yytext,"+=") == 0){
		printf("token(ASSIGN_PLUS, %s)\n", yytext);
		// return ASSIGN_PLUS;
	}
	else if (strcmp(yytext,"-=") == 0){
		printf("token(ASSIGN_MINUS, %s)\n", yytext);
		// return ASSIGN_MINUS;
	}
	else if (strcmp(yytext,"*=") == 0){
		printf("token(ASSIGN_MULTIPLY, %s)\n", yytext);
		// return ASSIGN_MULTIPLY;
	}
	else if (strcmp(yytext,"/=") == 0){
		printf("token(ASSIGN_DIVIDE, %s)\n", yytext);
		// return ASSIGN_DIVIDE;
	}
	else if (strcmp(yytext,"%=") == 0){
		printf("token(ASSIGN_MOD, %s)\n", yytext);
		// return ASSIGN_MOD;
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
		// return MOD;
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
		// return LBRACKET;
	}
	else if (strcmp(yytext,"{") == 0){
		// printf("token(LCURLY, %s)\n", yytext);
		return LCURLY;
	}
	else if (strcmp(yytext,"(") == 0){
		// printf("token(LPAREN, %s)\n", yytext);
		return LPAREN;
	}
	else if (strcmp(yytext,".") == 0){
		printf("token(PERIOD, %s)\n", yytext);
		// return PERIOD;
	}
	else if (strcmp(yytext,"]") == 0){
		printf("token(RBRACKET, %s)\n", yytext);
		// return RBRACKET;
	}
	else if (strcmp(yytext,"}") == 0){
		// printf("token(RCURLY, %s)\n", yytext);
		return RCURLY;
	}
	else if (strcmp(yytext,")") == 0){
		// printf("token(RPAREN, %s)\n", yytext);
		return RPAREN;
	}
	else if (strcmp(yytext,";") == 0){
		// printf("token(SEMI, %s)\n", yytext);
		return SEMI;
	}
}

{Identifier} {
	// printf("IDENTIFIER: %s\n", yytext);
	yylval.sval = strdup(yytext);
	return IDENTIFIER;}

{Int} {
	// printf("token(ICONSTANT, %s)\n", yytext);
	// yylval.ival = atoi(yytext);
	yylval.sval = strdup(yytext);
	return ICONSTANT;
}

{Float} {
	// printf("token(DCONSTANT, %s)\n", yytext);
	yylval.dval = atof(yytext);
	return DCONSTANT;
}

{Sconstant} {
	// printf("token(SCONSTANT, %s)\n", yytext);
	yylval.sval = strdup(yytext);
	return SCONSTANT;
}

{Blank} {}

\n   {}

%%

/*** Code Section prints the number of
capital letter present in the given input***/
int yywrap(){
	return 1;
}

