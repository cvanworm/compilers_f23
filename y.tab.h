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
    K_PROGRAM = 258,               /* K_PROGRAM  */
    IDENTIFIER = 259,              /* IDENTIFIER  */
    LCURLY = 260,                  /* LCURLY  */
    K_FUNCTION = 261,              /* K_FUNCTION  */
    K_INTEGER = 262,               /* K_INTEGER  */
    LPAREN = 263,                  /* LPAREN  */
    RPAREN = 264,                  /* RPAREN  */
    SEMI = 265,                    /* SEMI  */
    ASSIGN = 266,                  /* ASSIGN  */
    ICONSTANT = 267,               /* ICONSTANT  */
    K_PRINT_INTEGER = 268,         /* K_PRINT_INTEGER  */
    K_PRINT_STRING = 269,          /* K_PRINT_STRING  */
    RCURLY = 270,                  /* RCURLY  */
    SCONSTANT = 271,               /* SCONSTANT  */
    K_IF = 272,                    /* K_IF  */
    K_THEN = 273,                  /* K_THEN  */
    DEQ = 274,                     /* DEQ  */
    GEQ = 275,                     /* GEQ  */
    GT = 276,                      /* GT  */
    LEQ = 277,                     /* LEQ  */
    LT = 278,                      /* LT  */
    NE = 279,                      /* NE  */
    NOT = 280,                     /* NOT  */
    DAND = 281,                    /* DAND  */
    DOR = 282,                     /* DOR  */
    K_ELSE = 283                   /* K_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define K_PROGRAM 258
#define IDENTIFIER 259
#define LCURLY 260
#define K_FUNCTION 261
#define K_INTEGER 262
#define LPAREN 263
#define RPAREN 264
#define SEMI 265
#define ASSIGN 266
#define ICONSTANT 267
#define K_PRINT_INTEGER 268
#define K_PRINT_STRING 269
#define RCURLY 270
#define SCONSTANT 271
#define K_IF 272
#define K_THEN 273
#define DEQ 274
#define GEQ 275
#define GT 276
#define LEQ 277
#define LT 278
#define NE 279
#define NOT 280
#define DAND 281
#define DOR 282
#define K_ELSE 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */