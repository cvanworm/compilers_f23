/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    SCONSTANT = 259,               /* SCONSTANT  */
    K_INTEGER = 260,               /* K_INTEGER  */
    K_STRING = 261,                /* K_STRING  */
    K_DOUBLE = 262,                /* K_DOUBLE  */
    ICONSTANT = 263,               /* ICONSTANT  */
    DCONSTANT = 264,               /* DCONSTANT  */
    K_PROGRAM = 265,               /* K_PROGRAM  */
    LCURLY = 266,                  /* LCURLY  */
    K_FUNCTION = 267,              /* K_FUNCTION  */
    LPAREN = 268,                  /* LPAREN  */
    RPAREN = 269,                  /* RPAREN  */
    SEMI = 270,                    /* SEMI  */
    ASSIGN = 271,                  /* ASSIGN  */
    K_PRINT_INTEGER = 272,         /* K_PRINT_INTEGER  */
    K_PRINT_STRING = 273,          /* K_PRINT_STRING  */
    RCURLY = 274,                  /* RCURLY  */
    PLUS = 275,                    /* PLUS  */
    MINUS = 276,                   /* MINUS  */
    MULTIPLY = 277,                /* MULTIPLY  */
    DIVIDE = 278,                  /* DIVIDE  */
    DECREMENT = 279,               /* DECREMENT  */
    INCREMENT = 280,               /* INCREMENT  */
    K_IF = 281,                    /* K_IF  */
    K_THEN = 282,                  /* K_THEN  */
    DEQ = 283,                     /* DEQ  */
    GEQ = 284,                     /* GEQ  */
    GT = 285,                      /* GT  */
    LEQ = 286,                     /* LEQ  */
    LT = 287,                      /* LT  */
    NE = 288,                      /* NE  */
    NOT = 289,                     /* NOT  */
    DAND = 290,                    /* DAND  */
    DOR = 291,                     /* DOR  */
    K_ELSE = 292,                  /* K_ELSE  */
    K_WHILE = 293,                 /* K_WHILE  */
    K_PROCEDURE = 294,             /* K_PROCEDURE  */
    COMMA = 295,                   /* COMMA  */
    K_RETURN = 296,                /* K_RETURN  */
    K_DO = 297,                    /* K_DO  */
    K_PRINT_DOUBLE = 298           /* K_PRINT_DOUBLE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define SCONSTANT 259
#define K_INTEGER 260
#define K_STRING 261
#define K_DOUBLE 262
#define ICONSTANT 263
#define DCONSTANT 264
#define K_PROGRAM 265
#define LCURLY 266
#define K_FUNCTION 267
#define LPAREN 268
#define RPAREN 269
#define SEMI 270
#define ASSIGN 271
#define K_PRINT_INTEGER 272
#define K_PRINT_STRING 273
#define RCURLY 274
#define PLUS 275
#define MINUS 276
#define MULTIPLY 277
#define DIVIDE 278
#define DECREMENT 279
#define INCREMENT 280
#define K_IF 281
#define K_THEN 282
#define DEQ 283
#define GEQ 284
#define GT 285
#define LEQ 286
#define LT 287
#define NE 288
#define NOT 289
#define DAND 290
#define DOR 291
#define K_ELSE 292
#define K_WHILE 293
#define K_PROCEDURE 294
#define COMMA 295
#define K_RETURN 296
#define K_DO 297
#define K_PRINT_DOUBLE 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "parse.yacc"

    double dval;
    int ival;
    char* sval;

#line 159 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
