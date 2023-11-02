/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "parse.yacc"

   /* Definition section */
  #include<stdio.h>
  #include<stdlib.h>
  #include"hash.h"

  struct hashMap* mp;
  char buffer [sizeof(int)*8+1];
  struct variable* var;
  char* key;
  char* type;
  char* value;

#line 85 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 230 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_SCONSTANT = 4,                  /* SCONSTANT  */
  YYSYMBOL_K_INTEGER = 5,                  /* K_INTEGER  */
  YYSYMBOL_K_STRING = 6,                   /* K_STRING  */
  YYSYMBOL_K_DOUBLE = 7,                   /* K_DOUBLE  */
  YYSYMBOL_ICONSTANT = 8,                  /* ICONSTANT  */
  YYSYMBOL_DCONSTANT = 9,                  /* DCONSTANT  */
  YYSYMBOL_K_PROGRAM = 10,                 /* K_PROGRAM  */
  YYSYMBOL_LCURLY = 11,                    /* LCURLY  */
  YYSYMBOL_K_FUNCTION = 12,                /* K_FUNCTION  */
  YYSYMBOL_LPAREN = 13,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 14,                    /* RPAREN  */
  YYSYMBOL_SEMI = 15,                      /* SEMI  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_K_PRINT_INTEGER = 17,           /* K_PRINT_INTEGER  */
  YYSYMBOL_K_PRINT_STRING = 18,            /* K_PRINT_STRING  */
  YYSYMBOL_RCURLY = 19,                    /* RCURLY  */
  YYSYMBOL_PLUS = 20,                      /* PLUS  */
  YYSYMBOL_MINUS = 21,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 22,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 23,                    /* DIVIDE  */
  YYSYMBOL_DECREMENT = 24,                 /* DECREMENT  */
  YYSYMBOL_INCREMENT = 25,                 /* INCREMENT  */
  YYSYMBOL_K_IF = 26,                      /* K_IF  */
  YYSYMBOL_K_THEN = 27,                    /* K_THEN  */
  YYSYMBOL_DEQ = 28,                       /* DEQ  */
  YYSYMBOL_GEQ = 29,                       /* GEQ  */
  YYSYMBOL_GT = 30,                        /* GT  */
  YYSYMBOL_LEQ = 31,                       /* LEQ  */
  YYSYMBOL_LT = 32,                        /* LT  */
  YYSYMBOL_NE = 33,                        /* NE  */
  YYSYMBOL_NOT = 34,                       /* NOT  */
  YYSYMBOL_DAND = 35,                      /* DAND  */
  YYSYMBOL_DOR = 36,                       /* DOR  */
  YYSYMBOL_K_ELSE = 37,                    /* K_ELSE  */
  YYSYMBOL_K_WHILE = 38,                   /* K_WHILE  */
  YYSYMBOL_K_PROCEDURE = 39,               /* K_PROCEDURE  */
  YYSYMBOL_COMMA = 40,                     /* COMMA  */
  YYSYMBOL_K_RETURN = 41,                  /* K_RETURN  */
  YYSYMBOL_K_DO = 42,                      /* K_DO  */
  YYSYMBOL_K_PRINT_DOUBLE = 43,            /* K_PRINT_DOUBLE  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_code = 45,                      /* code  */
  YYSYMBOL_Program = 46,                   /* Program  */
  YYSYMBOL_FuncProd = 47,                  /* FuncProd  */
  YYSYMBOL_Procedure = 48,                 /* Procedure  */
  YYSYMBOL_Function = 49,                  /* Function  */
  YYSYMBOL_Parameters = 50,                /* Parameters  */
  YYSYMBOL_MoreParams = 51,                /* MoreParams  */
  YYSYMBOL_Type = 52,                      /* Type  */
  YYSYMBOL_Statements = 53,                /* Statements  */
  YYSYMBOL_Statement = 54,                 /* Statement  */
  YYSYMBOL_FunctionCall = 55,              /* FunctionCall  */
  YYSYMBOL_Declare = 56,                   /* Declare  */
  YYSYMBOL_Print = 57,                     /* Print  */
  YYSYMBOL_If = 58,                        /* If  */
  YYSYMBOL_ElseIf = 59,                    /* ElseIf  */
  YYSYMBOL_While = 60,                     /* While  */
  YYSYMBOL_Condition = 61,                 /* Condition  */
  YYSYMBOL_Else = 62,                      /* Else  */
  YYSYMBOL_BoolComp = 63,                  /* BoolComp  */
  YYSYMBOL_Assign = 64,                    /* Assign  */
  YYSYMBOL_IncDec = 65,                    /* IncDec  */
  YYSYMBOL_Math = 66,                      /* Math  */
  YYSYMBOL_Expr = 67,                      /* Expr  */
  YYSYMBOL_Term = 68,                      /* Term  */
  YYSYMBOL_Factor = 69,                    /* Factor  */
  YYSYMBOL_Arguments = 70,                 /* Arguments  */
  YYSYMBOL_MoreArgs = 71,                  /* MoreArgs  */
  YYSYMBOL_Return = 72,                    /* Return  */
  YYSYMBOL_NumConstant = 73,               /* NumConstant  */
  YYSYMBOL_Epsilon = 74                    /* Epsilon  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   255

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    35,    35,    38,    40,    40,    40,    42,    44,    46,
      47,    48,    50,    50,    52,    52,    52,    54,    55,    56,
      57,    59,    60,    61,    62,    63,    65,    67,    69,    70,
      71,    72,    73,    74,    76,    76,    78,    78,    78,    80,
      80,    82,    82,    82,    84,    84,    84,    86,    86,    86,
      86,    86,    86,    88,    89,    90,   102,   104,   104,   106,
     106,   106,   108,   108,   108,   110,   110,   110,   112,   112,
     112,   112,   114,   115,   115,   117,   118,   120,   121,   122,
     123,   124,   126,   129,   131
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "SCONSTANT", "K_INTEGER", "K_STRING", "K_DOUBLE", "ICONSTANT",
  "DCONSTANT", "K_PROGRAM", "LCURLY", "K_FUNCTION", "LPAREN", "RPAREN",
  "SEMI", "ASSIGN", "K_PRINT_INTEGER", "K_PRINT_STRING", "RCURLY", "PLUS",
  "MINUS", "MULTIPLY", "DIVIDE", "DECREMENT", "INCREMENT", "K_IF",
  "K_THEN", "DEQ", "GEQ", "GT", "LEQ", "LT", "NE", "NOT", "DAND", "DOR",
  "K_ELSE", "K_WHILE", "K_PROCEDURE", "COMMA", "K_RETURN", "K_DO",
  "K_PRINT_DOUBLE", "$accept", "code", "Program", "FuncProd", "Procedure",
  "Function", "Parameters", "MoreParams", "Type", "Statements",
  "Statement", "FunctionCall", "Declare", "Print", "If", "ElseIf", "While",
  "Condition", "Else", "BoolComp", "Assign", "IncDec", "Math", "Expr",
  "Term", "Factor", "Arguments", "MoreArgs", "Return", "NumConstant",
  "Epsilon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-125)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,    19,    43,  -125,    34,  -125,     9,    52,    86,    58,
       9,     9,  -125,  -125,  -125,  -125,    99,    98,  -125,  -125,
    -125,   102,    52,    52,   105,   121,  -125,   111,   122,    94,
     127,     6,    52,     6,    13,   131,   137,   143,   144,   150,
     161,   128,     6,  -125,  -125,  -125,     6,     6,  -125,  -125,
    -125,   164,   129,   166,    84,   156,   157,   160,    53,    27,
     180,   180,    31,    56,  -125,  -125,  -125,  -125,   147,   173,
     165,  -125,   148,   171,  -125,    61,   174,  -125,  -125,   145,
     184,   183,    74,    59,  -125,    61,  -125,  -125,  -125,   185,
     186,   187,   188,   163,   189,   190,   191,   192,  -125,   145,
      52,    88,   204,  -125,   193,  -125,   206,   195,  -125,  -125,
     197,   145,  -125,   152,   152,   152,   152,  -125,   198,   199,
     200,   201,  -125,  -125,  -125,  -125,  -125,  -125,    33,   194,
      73,   202,   203,   205,  -125,   166,  -125,   160,   196,  -125,
     179,  -125,  -125,  -125,   208,  -125,    59,  -125,    59,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,   207,   103,     6,  -125,
    -125,  -125,  -125,   209,   206,  -125,   180,     6,   210,   211,
     212,  -125,  -125,   213,    57,  -125,  -125,  -125,  -125,  -125,
     210,     6,   215,  -125,  -125,   214,   180,  -125,   217,   216,
     125,     6,   218,   219,   134,  -125,   218,  -125
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,    84,     0,     0,     0,
      84,    84,     6,    14,    15,    16,     0,     0,     3,     5,
       4,     0,    84,    84,     0,     0,    11,     0,     0,     9,
       0,    84,     0,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    84,    24,    21,    23,    84,    84,    22,    20,
      10,     0,    84,    84,     0,     0,     0,    25,     0,     0,
       0,     0,     0,     0,     7,    17,    18,    19,    12,     0,
       0,    81,    72,     0,    74,    69,     0,    82,    83,     0,
       0,     0,    61,    64,    67,    68,    58,    57,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,    80,     0,     8,     0,     0,    59,    53,
       0,     0,    55,     0,     0,     0,     0,    60,     0,     0,
       0,     0,    47,    48,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,    13,    84,    77,     0,     0,    79,
      75,    73,    26,    70,     0,    69,    62,    68,    63,    65,
      66,    28,    29,    30,    31,    42,    41,     0,    84,    40,
      33,    32,    56,     0,     0,    71,     0,    84,    84,     0,
       0,    76,    43,     0,     0,    35,    38,    46,    39,    78,
      84,    84,     0,    45,    34,     0,     0,    44,     0,     0,
       0,    84,    84,     0,     0,    37,    84,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,  -125,  -125,   107,  -125,  -125,   221,   124,    -4,   -32,
    -124,  -125,  -125,  -125,  -125,    45,  -125,   -59,  -123,  -125,
     167,   -50,   -72,  -125,   -15,     7,    91,    65,  -125,   -61,
      -6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     9,    10,    11,    24,    50,    40,    41,
      42,    43,    44,    45,    46,   175,    47,    94,   176,   128,
      48,    57,    81,    82,    83,    84,    73,   141,    70,    85,
      49
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      12,    52,    95,    16,    12,    12,   159,   110,   104,    34,
      65,    13,    14,    15,    66,    67,    26,    26,    25,    25,
       1,     7,     4,    35,    36,   108,    53,   133,    51,    54,
      91,    92,    37,   168,    96,   117,   155,    55,    56,   144,
      97,    77,    78,     5,    38,     6,    71,    74,     8,    39,
     183,   137,   147,   147,   147,   147,    89,    13,    14,    15,
      34,    90,    13,    14,    15,   102,   192,   156,   181,   195,
     183,    98,    99,   197,    35,    36,    34,    18,    13,    14,
      15,   115,   116,   182,   158,    55,    56,    75,    76,    17,
      35,    36,    77,    78,   113,   114,    51,    79,   146,   148,
      39,   135,    21,   136,    54,    80,    34,   172,    13,    14,
      15,    22,    55,    56,   167,    23,    39,    19,    20,    28,
      35,    36,   149,   150,    29,    30,   169,   188,    34,    74,
      13,    14,    15,    31,    32,   173,   191,    34,    33,    13,
      14,    15,    35,    36,    58,   181,    39,    64,    75,   185,
      59,    35,    36,    77,    78,   145,    60,    61,    79,   193,
      77,    78,   177,    62,    63,    79,    80,    68,    39,    72,
      69,    86,    87,    80,   177,    88,   101,    39,    13,    14,
      15,    77,    78,    93,   105,   107,   177,   100,   106,   109,
     177,   122,   123,   124,   125,   126,   127,   111,   112,   118,
     119,   120,   121,   129,   130,   131,   132,   138,   139,   140,
     142,   143,    99,   151,   152,   153,   154,   160,   161,   164,
     162,   157,   165,   170,   134,   184,   163,   179,   186,   171,
     178,   189,   180,   187,     0,     0,   103,     0,   196,     0,
       0,     0,   166,   190,    27,     0,     0,   174,     0,     0,
       0,     0,     0,     0,     0,   194
};

static const yytype_int16 yycheck[] =
{
       6,    33,    61,     7,    10,    11,   130,    79,    69,     3,
      42,     5,     6,     7,    46,    47,    22,    23,    22,    23,
      10,    12,     3,    17,    18,    75,    13,    99,    32,    16,
       3,     4,    26,   157,     3,    85,     3,    24,    25,   111,
       9,     8,     9,     0,    38,    11,    52,    53,    39,    43,
     174,   101,   113,   114,   115,   116,     3,     5,     6,     7,
       3,     8,     5,     6,     7,    69,   190,   128,    11,   192,
     194,    15,    16,   196,    17,    18,     3,    19,     5,     6,
       7,    22,    23,    26,    11,    24,    25,     3,     4,     3,
      17,    18,     8,     9,    20,    21,   100,    13,   113,   114,
      43,    13,     3,    15,    16,    21,     3,   166,     5,     6,
       7,    13,    24,    25,    11,    13,    43,    10,    11,    14,
      17,    18,   115,   116,     3,    14,   158,   186,     3,   135,
       5,     6,     7,    11,    40,   167,    11,     3,    11,     5,
       6,     7,    17,    18,    13,    11,    43,    19,     3,   181,
      13,    17,    18,     8,     9,     3,    13,    13,    13,   191,
       8,     9,   168,    13,     3,    13,    21,     3,    43,     3,
      41,    15,    15,    21,   180,    15,     3,    43,     5,     6,
       7,     8,     9,     3,    19,    14,   192,    40,    40,    15,
     196,    28,    29,    30,    31,    32,    33,    13,    15,    14,
      14,    14,    14,    14,    14,    14,    14,     3,    15,     3,
      15,    14,    16,    15,    15,    15,    15,    15,    15,    40,
      15,    27,    14,    14,   100,   180,   135,    15,    13,   164,
      19,    14,    19,    19,    -1,    -1,    69,    -1,    19,    -1,
      -1,    -1,    35,    27,    23,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    45,    46,     3,     0,    11,    12,    39,    47,
      48,    49,    74,     5,     6,     7,    52,     3,    19,    47,
      47,     3,    13,    13,    50,    52,    74,    50,    14,     3,
      14,    11,    40,    11,     3,    17,    18,    26,    38,    43,
      52,    53,    54,    55,    56,    57,    58,    60,    64,    74,
      51,    52,    53,    13,    16,    24,    25,    65,    13,    13,
      13,    13,    13,     3,    19,    53,    53,    53,     3,    41,
      72,    74,     3,    70,    74,     3,     4,     8,     9,    13,
      21,    66,    67,    68,    69,    73,    15,    15,    15,     3,
       8,     3,     4,     3,    61,    61,     3,     9,    15,    16,
      40,     3,    52,    64,    73,    19,    40,    14,    65,    15,
      66,    13,    15,    20,    21,    22,    23,    65,    14,    14,
      14,    14,    28,    29,    30,    31,    32,    33,    63,    14,
      14,    14,    14,    66,    51,    13,    15,    65,     3,    15,
       3,    71,    15,    14,    66,     3,    68,    73,    68,    69,
      69,    15,    15,    15,    15,     3,    73,    27,    11,    54,
      15,    15,    15,    70,    40,    14,    35,    11,    54,    53,
      14,    71,    61,    53,    37,    59,    62,    74,    19,    15,
      19,    11,    26,    54,    59,    53,    13,    19,    61,    14,
      27,    11,    54,    53,    37,    62,    19,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    47,    47,    47,    48,    49,    50,
      50,    50,    51,    51,    52,    52,    52,    53,    53,    53,
      53,    54,    54,    54,    54,    54,    55,    56,    57,    57,
      57,    57,    57,    57,    58,    58,    59,    59,    59,    60,
      60,    61,    61,    61,    62,    62,    62,    63,    63,    63,
      63,    63,    63,    64,    64,    64,    64,    65,    65,    66,
      66,    66,    67,    67,    67,    68,    68,    68,    69,    69,
      69,    69,    70,    70,    70,    71,    71,    72,    72,    72,
      72,    72,    73,    73,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     2,     2,     1,     8,    10,     2,
       4,     1,     2,     4,     1,     1,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     2,     5,     3,     5,     5,
       5,     5,     5,     5,     9,     7,    10,     8,     1,     7,
       5,     3,     3,     5,     4,     2,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     4,     5,     2,     2,     2,
       2,     1,     3,     3,     1,     3,     3,     1,     1,     1,
       3,     4,     1,     3,     1,     1,     3,     3,     6,     3,
       2,     1,     1,     1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* code: Program  */
#line 35 "parse.yacc"
              {printf("valid code\n"); printHash();
             exit(0);}
#line 1422 "y.tab.c"
    break;

  case 3: /* Program: K_PROGRAM IDENTIFIER LCURLY FuncProd RCURLY  */
#line 38 "parse.yacc"
                                                     {printf("Program node: %s\n", (yyvsp[-3].sval));printStars();}
#line 1428 "y.tab.c"
    break;

  case 7: /* Procedure: K_PROCEDURE IDENTIFIER LPAREN Parameters RPAREN LCURLY Statements RCURLY  */
#line 42 "parse.yacc"
                                                                                    {printf("Procedure node: \n"); printStars();}
#line 1434 "y.tab.c"
    break;

  case 8: /* Function: K_FUNCTION Type IDENTIFIER LPAREN Parameters RPAREN LCURLY Statements Return RCURLY  */
#line 44 "parse.yacc"
                                                                                              {printf("Function node: %s\n", (yyvsp[-7].sval)); printStars();}
#line 1440 "y.tab.c"
    break;

  case 9: /* Parameters: Type IDENTIFIER  */
#line 46 "parse.yacc"
                            {printf("Parameters node\n");}
#line 1446 "y.tab.c"
    break;

  case 10: /* Parameters: Type IDENTIFIER COMMA MoreParams  */
#line 47 "parse.yacc"
                                   {printf("More Parameters node\n");}
#line 1452 "y.tab.c"
    break;

  case 14: /* Type: K_INTEGER  */
#line 52 "parse.yacc"
                { (yyval.sval) = (yyvsp[0].sval); }
#line 1458 "y.tab.c"
    break;

  case 15: /* Type: K_STRING  */
#line 52 "parse.yacc"
                                        { (yyval.sval) = (yyvsp[0].sval); }
#line 1464 "y.tab.c"
    break;

  case 16: /* Type: K_DOUBLE  */
#line 52 "parse.yacc"
                                                                { (yyval.sval) = (yyvsp[0].sval);}
#line 1470 "y.tab.c"
    break;

  case 20: /* Statements: Epsilon  */
#line 57 "parse.yacc"
          {printf("Statements node:\n"); printStars();}
#line 1476 "y.tab.c"
    break;

  case 26: /* FunctionCall: IDENTIFIER LPAREN Arguments RPAREN SEMI  */
#line 65 "parse.yacc"
                                                      {printf("%s\nFunction Call node: \n", (yyvsp[-4].sval));printStars();}
#line 1482 "y.tab.c"
    break;

  case 27: /* Declare: Type IDENTIFIER SEMI  */
#line 67 "parse.yacc"
                              {printf("%s\n%s\nDeclare node: \n", (yyvsp[-1].sval), (yyvsp[-2].sval));printStars();}
#line 1488 "y.tab.c"
    break;

  case 28: /* Print: K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI  */
#line 69 "parse.yacc"
                                                     {printf("%s\nprint_integer\nprint node: \n", (yyvsp[-2].sval)); printStars();}
#line 1494 "y.tab.c"
    break;

  case 29: /* Print: K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI  */
#line 70 "parse.yacc"
                                               {printf("%s\nprint_integer\nprint node: \n", (yyvsp[-2].sval)); printStars();}
#line 1500 "y.tab.c"
    break;

  case 30: /* Print: K_PRINT_STRING LPAREN IDENTIFIER RPAREN SEMI  */
#line 71 "parse.yacc"
                                               {printf("%s\nprint_string\nprint node: \n", (yyvsp[-2].sval)); printStars();}
#line 1506 "y.tab.c"
    break;

  case 31: /* Print: K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI  */
#line 72 "parse.yacc"
                                              {printf("%s\nprint_string\nprint node: \n", (yyvsp[-2].sval)); printStars();}
#line 1512 "y.tab.c"
    break;

  case 32: /* Print: K_PRINT_DOUBLE LPAREN DCONSTANT RPAREN SEMI  */
#line 73 "parse.yacc"
                                              {printf("%s\nprint_double\nprint node: \n", (yyvsp[-2].dval)); printStars();}
#line 1518 "y.tab.c"
    break;

  case 33: /* Print: K_PRINT_DOUBLE LPAREN IDENTIFIER RPAREN SEMI  */
#line 74 "parse.yacc"
                                               {printf("%s\nprint_double\nprint node: \n", (yyvsp[-2].sval)); printStars();}
#line 1524 "y.tab.c"
    break;

  case 53: /* Assign: IDENTIFIER ASSIGN SCONSTANT SEMI  */
#line 88 "parse.yacc"
                                         {printf("%s\n%s\nAssign node: \n", (yyvsp[-1].sval), (yyvsp[-3].sval));printStars();}
#line 1530 "y.tab.c"
    break;

  case 55: /* Assign: IDENTIFIER ASSIGN Math SEMI  */
#line 90 "parse.yacc"
                              {
  printf("%s\nAssign node: \n", (yyvsp[-3].sval));
  key = (char*) (yyvsp[-3].sval);
  printf("id: %s type: %s value %s\n", key, type, value);
  struct variable* var = (struct variable*)malloc(sizeof(struct variable));
  var->type = type;
	var->value = value;
	insert(mp, key, var);
  printf("id: %s var struct %s,%s\n", key, var->type, var->value);
  printHash(key);
  printStars();
  }
#line 1547 "y.tab.c"
    break;

  case 69: /* Factor: IDENTIFIER  */
#line 112 "parse.yacc"
                                 { (yyval.sval) = (yyvsp[0].sval); }
#line 1553 "y.tab.c"
    break;

  case 72: /* Arguments: IDENTIFIER  */
#line 114 "parse.yacc"
                      {printf("%s\nArgument: \n", (yyvsp[0].sval));}
#line 1559 "y.tab.c"
    break;

  case 75: /* MoreArgs: IDENTIFIER  */
#line 117 "parse.yacc"
                     {printf("%s\nArgument: \n", (yyvsp[0].sval));}
#line 1565 "y.tab.c"
    break;

  case 76: /* MoreArgs: IDENTIFIER COMMA MoreArgs  */
#line 118 "parse.yacc"
                            {printf("%s\nArgument: \n", (yyvsp[-2].sval));}
#line 1571 "y.tab.c"
    break;

  case 82: /* NumConstant: ICONSTANT  */
#line 126 "parse.yacc"
                       { (yyval.sval) = (yyvsp[0].sval); printf("%s\n", (yyvsp[0].sval)); 
  type = "int";
	value = (yyvsp[0].sval); }
#line 1579 "y.tab.c"
    break;

  case 83: /* NumConstant: DCONSTANT  */
#line 129 "parse.yacc"
            { (yyval.dval) = (yyvsp[0].dval); printf("%f\n", (yyvsp[0].dval)); }
#line 1585 "y.tab.c"
    break;


#line 1589 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 135 "parse.yacc"

  
int yyerror(char *msg)
 {
  printf("invalid program: %s\n", msg);
  exit(0);
 }

printStars()
{
  for(int i=0;i<50;i++)
  {
    printf("*");
  }
  //print new line
   printf("\n");
}
  
  
//driver code 
main()
 {
  mp = (struct hashMap*)malloc(sizeof(struct hashMap));
  initializeHashMap(mp);
  /* printf("enter the string\n"); */
  /* printf("hello"); */
  yyparse();

  

 }

 printHash(char* k){
  /* struct variable* var1 = (struct variable*)malloc(sizeof(struct variable));

  var1->type = "int";
  var1->value = "15";
  insert(mp, "test", var1);

  struct variable* s1 = search(mp, "test");
  printf("Val found: %s\n", s1->value); */
  


  /* char* test = "var "; */
  struct variable* s = search(mp, k);
  printf("key found: |%s|\n", key);
  /* print type of key */
  printf("Type found: %s\n", s->type);
  printf("Val found: %s\n", s->value);
 }
