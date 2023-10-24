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
 

#line 78 "y.tab.c"

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
    K_DO = 297                     /* K_DO  */
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 8 "parse.yacc"

    double dval;
    int ival;
    char* sval;

#line 221 "y.tab.c"

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
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_code = 44,                      /* code  */
  YYSYMBOL_Program = 45,                   /* Program  */
  YYSYMBOL_FuncProd = 46,                  /* FuncProd  */
  YYSYMBOL_Procedure = 47,                 /* Procedure  */
  YYSYMBOL_Function = 48,                  /* Function  */
  YYSYMBOL_Parameters = 49,                /* Parameters  */
  YYSYMBOL_MoreParams = 50,                /* MoreParams  */
  YYSYMBOL_Type = 51,                      /* Type  */
  YYSYMBOL_Statements = 52,                /* Statements  */
  YYSYMBOL_Statement = 53,                 /* Statement  */
  YYSYMBOL_Declare = 54,                   /* Declare  */
  YYSYMBOL_Print = 55,                     /* Print  */
  YYSYMBOL_If = 56,                        /* If  */
  YYSYMBOL_ElseIf = 57,                    /* ElseIf  */
  YYSYMBOL_While = 58,                     /* While  */
  YYSYMBOL_Condition = 59,                 /* Condition  */
  YYSYMBOL_Else = 60,                      /* Else  */
  YYSYMBOL_BoolComp = 61,                  /* BoolComp  */
  YYSYMBOL_Assign = 62,                    /* Assign  */
  YYSYMBOL_IncDec = 63,                    /* IncDec  */
  YYSYMBOL_Math = 64,                      /* Math  */
  YYSYMBOL_Expr = 65,                      /* Expr  */
  YYSYMBOL_Term = 66,                      /* Term  */
  YYSYMBOL_Factor = 67,                    /* Factor  */
  YYSYMBOL_Arguments = 68,                 /* Arguments  */
  YYSYMBOL_MoreArgs = 69,                  /* MoreArgs  */
  YYSYMBOL_Return = 70,                    /* Return  */
  YYSYMBOL_NumConstant = 71,               /* NumConstant  */
  YYSYMBOL_Epsilon = 72                    /* Epsilon  */
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
#define YYLAST   229

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    26,    26,    29,    31,    31,    31,    33,    35,    37,
      38,    39,    41,    41,    43,    43,    43,    45,    45,    45,
      45,    47,    47,    47,    47,    49,    51,    51,    53,    53,
      55,    55,    55,    57,    57,    59,    59,    59,    61,    61,
      61,    63,    63,    63,    63,    63,    63,    65,    66,    67,
      68,    70,    70,    72,    72,    72,    74,    74,    74,    76,
      76,    76,    78,    78,    78,    78,    80,    80,    80,    82,
      82,    84,    85,    86,    87,    88,    90,    90,    92
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
  "$accept", "code", "Program", "FuncProd", "Procedure", "Function",
  "Parameters", "MoreParams", "Type", "Statements", "Statement", "Declare",
  "Print", "If", "ElseIf", "While", "Condition", "Else", "BoolComp",
  "Assign", "IncDec", "Math", "Expr", "Term", "Factor", "Arguments",
  "MoreArgs", "Return", "NumConstant", "Epsilon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-166)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      46,     4,    15,  -166,    20,  -166,    -3,    33,    57,    55,
      -3,    -3,  -166,  -166,  -166,  -166,    78,    74,  -166,  -166,
    -166,    89,    33,    33,    92,   114,  -166,   109,   116,    93,
     117,    17,    33,    17,     5,   124,   125,   130,   131,   139,
     126,    17,  -166,  -166,    17,    17,  -166,  -166,  -166,   146,
     123,    67,   150,   151,   153,   166,   174,   167,   167,    68,
    -166,  -166,  -166,  -166,   140,   152,   135,  -166,    70,   164,
    -166,  -166,    24,   168,   169,    80,    88,  -166,    70,  -166,
    -166,  -166,   171,   172,   144,   173,   175,  -166,    24,    33,
      83,   179,  -166,   176,  -166,  -166,  -166,   178,    24,  -166,
      69,    69,    69,    69,  -166,   180,   181,  -166,  -166,  -166,
    -166,  -166,  -166,    60,   156,    86,   182,  -166,   185,  -166,
     153,   177,  -166,  -166,   184,  -166,    88,  -166,    88,  -166,
    -166,  -166,  -166,  -166,   155,   113,    17,  -166,  -166,   154,
     186,  -166,  -166,   167,    17,   162,   183,   198,   188,  -166,
     187,    47,  -166,  -166,  -166,  -166,   165,  -166,  -166,   162,
      17,   191,  -166,   198,  -166,   189,   167,  -166,  -166,   193,
     190,   129,    17,   192,   194,   145,  -166,   192,  -166
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,    78,     0,     0,     0,
      78,    78,     6,    14,    15,    16,     0,     0,     3,     5,
       4,     0,    78,    78,     0,     0,    11,     0,     0,     9,
       0,    78,     0,    78,     0,     0,     0,     0,     0,     0,
       0,    78,    21,    23,    78,    78,    22,    20,    10,     0,
      78,     0,     0,     0,    24,     0,     0,     0,     0,     0,
       7,    17,    18,    19,    12,     0,     0,    75,    63,     0,
      76,    77,     0,     0,     0,    55,    58,    61,    62,    52,
      51,    48,     0,     0,     0,     0,     0,    25,     0,     0,
       0,     0,    74,     0,     8,    53,    47,     0,     0,    49,
       0,     0,     0,     0,    54,     0,     0,    41,    42,    43,
      44,    45,    46,     0,     0,     0,     0,    13,    78,    71,
       0,     0,    73,    64,     0,    63,    56,    62,    57,    59,
      60,    26,    27,    36,    35,     0,    78,    34,    50,    66,
       0,    68,    65,     0,    78,    78,     0,     0,     0,    37,
       0,     0,    29,    32,    40,    33,    69,    67,    72,    78,
      78,     0,    39,     0,    28,     0,     0,    70,    38,     0,
       0,     0,    78,    78,     0,     0,    31,    78,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,  -166,   104,  -166,  -166,   195,   120,    -4,   -31,
    -109,  -166,  -166,  -166,    51,  -166,   -57,  -165,  -166,   147,
     -11,   -47,  -166,    21,    23,  -166,    48,  -166,   -54,    -6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     9,    10,    11,    24,    48,    39,    40,
      41,    42,    43,    44,   152,    45,    85,   153,   113,    46,
      54,    74,    75,    76,    77,   140,   157,    66,    78,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      12,    86,    50,    16,    12,    12,   137,     4,   176,     7,
      61,    93,   178,    62,    63,     5,    26,    26,    25,    25,
      34,    51,    13,    14,    15,    97,   145,    68,    49,    52,
      53,     6,    70,    71,    35,    36,     8,    72,    13,    14,
      15,   116,   162,    37,    67,    73,   127,   127,   127,   127,
      34,   124,    13,    14,    15,    38,     1,    95,   160,   134,
      17,    91,   173,   133,    35,    36,   162,   104,    70,    71,
      68,    69,   125,   161,    18,    70,    71,    70,    71,   120,
      72,    21,    72,    87,    88,    49,   149,    22,    73,    34,
      73,    13,    14,    15,    52,    53,   118,   136,   119,    51,
     100,   101,    23,    35,    36,   146,    28,    52,    53,   169,
     102,   103,   141,   150,    19,    20,    34,    29,    13,    14,
      15,   126,   128,    30,   144,   129,   130,    31,    33,   165,
      35,    36,    34,    32,    13,    14,    15,    55,    56,   154,
     172,   174,    59,    57,    58,    60,    35,    36,    34,    64,
      13,    14,    15,   154,    94,    90,   160,    13,    14,    15,
      70,    71,    35,    36,    65,    79,    80,   154,    81,    82,
      84,   154,   107,   108,   109,   110,   111,   112,    83,    96,
      89,    98,   121,   135,    99,   105,   106,   114,   139,   115,
     143,   122,   123,    88,   147,   131,   132,   138,   142,   151,
     148,   156,   155,   158,   166,   163,   159,   170,   168,   117,
     164,   167,    92,   177,     0,     0,     0,   171,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   175
};

static const yytype_int16 yycheck[] =
{
       6,    58,    33,     7,    10,    11,   115,     3,   173,    12,
      41,    65,   177,    44,    45,     0,    22,    23,    22,    23,
       3,    16,     5,     6,     7,    72,   135,     3,    32,    24,
      25,    11,     8,     9,    17,    18,    39,    13,     5,     6,
       7,    88,   151,    26,    50,    21,   100,   101,   102,   103,
       3,    98,     5,     6,     7,    38,    10,    68,    11,   113,
       3,    65,   171,     3,    17,    18,   175,    78,     8,     9,
       3,     4,     3,    26,    19,     8,     9,     8,     9,    90,
      13,     3,    13,    15,    16,    89,   143,    13,    21,     3,
      21,     5,     6,     7,    24,    25,    13,    11,    15,    16,
      20,    21,    13,    17,    18,   136,    14,    24,    25,   166,
      22,    23,   118,   144,    10,    11,     3,     3,     5,     6,
       7,   100,   101,    14,    11,   102,   103,    11,    11,   160,
      17,    18,     3,    40,     5,     6,     7,    13,    13,   145,
      11,   172,     3,    13,    13,    19,    17,    18,     3,     3,
       5,     6,     7,   159,    19,     3,    11,     5,     6,     7,
       8,     9,    17,    18,    41,    15,    15,   173,    15,     3,
       3,   177,    28,    29,    30,    31,    32,    33,     4,    15,
      40,    13,     3,    27,    15,    14,    14,    14,     3,    14,
      35,    15,    14,    16,    40,    15,    15,    15,    14,    37,
      14,     3,    19,    15,    13,    40,    19,    14,    19,    89,
     159,   163,    65,    19,    -1,    -1,    -1,    27,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    44,    45,     3,     0,    11,    12,    39,    46,
      47,    48,    72,     5,     6,     7,    51,     3,    19,    46,
      46,     3,    13,    13,    49,    51,    72,    49,    14,     3,
      14,    11,    40,    11,     3,    17,    18,    26,    38,    51,
      52,    53,    54,    55,    56,    58,    62,    72,    50,    51,
      52,    16,    24,    25,    63,    13,    13,    13,    13,     3,
      19,    52,    52,    52,     3,    41,    70,    72,     3,     4,
       8,     9,    13,    21,    64,    65,    66,    67,    71,    15,
      15,    15,     3,     4,     3,    59,    59,    15,    16,    40,
       3,    51,    62,    71,    19,    63,    15,    64,    13,    15,
      20,    21,    22,    23,    63,    14,    14,    28,    29,    30,
      31,    32,    33,    61,    14,    14,    64,    50,    13,    15,
      63,     3,    15,    14,    64,     3,    66,    71,    66,    67,
      67,    15,    15,     3,    71,    27,    11,    53,    15,     3,
      68,    72,    14,    35,    11,    53,    52,    40,    14,    59,
      52,    37,    57,    60,    72,    19,     3,    69,    15,    19,
      11,    26,    53,    40,    57,    52,    13,    69,    19,    59,
      14,    27,    11,    53,    52,    37,    60,    19,    60
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    46,    46,    46,    47,    48,    49,
      49,    49,    50,    50,    51,    51,    51,    52,    52,    52,
      52,    53,    53,    53,    53,    54,    55,    55,    56,    56,
      57,    57,    57,    58,    58,    59,    59,    59,    60,    60,
      60,    61,    61,    61,    61,    61,    61,    62,    62,    62,
      62,    63,    63,    64,    64,    64,    65,    65,    65,    66,
      66,    66,    67,    67,    67,    67,    68,    68,    68,    69,
      69,    70,    70,    70,    70,    70,    71,    71,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     2,     2,     1,     8,    10,     2,
       4,     1,     2,     4,     1,     1,     1,     2,     2,     2,
       1,     1,     1,     1,     2,     3,     5,     5,     9,     7,
      10,     8,     1,     7,     5,     3,     3,     5,     4,     2,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     4,
       5,     2,     2,     2,     2,     1,     3,     3,     1,     3,
       3,     1,     1,     1,     3,     4,     1,     3,     1,     1,
       3,     3,     6,     3,     2,     1,     1,     1,     0
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
#line 26 "parse.yacc"
              {printf("valid code\n");
             exit(0);}
#line 1393 "y.tab.c"
    break;

  case 3: /* Program: K_PROGRAM IDENTIFIER LCURLY FuncProd RCURLY  */
#line 29 "parse.yacc"
                                                     {printf("Program node: %s\n", (yyvsp[-3].sval));printStars();}
#line 1399 "y.tab.c"
    break;

  case 7: /* Procedure: K_PROCEDURE IDENTIFIER LPAREN Parameters RPAREN LCURLY Statements RCURLY  */
#line 33 "parse.yacc"
                                                                                    {printf("Procedure node: \n"); printStars();}
#line 1405 "y.tab.c"
    break;

  case 8: /* Function: K_FUNCTION Type IDENTIFIER LPAREN Parameters RPAREN LCURLY Statements Return RCURLY  */
#line 35 "parse.yacc"
                                                                                              {printf("Function node: %s\n", (yyvsp[-7].sval)); printStars();}
#line 1411 "y.tab.c"
    break;

  case 9: /* Parameters: Type IDENTIFIER  */
#line 37 "parse.yacc"
                            {printf("Parameters node\n");}
#line 1417 "y.tab.c"
    break;

  case 10: /* Parameters: Type IDENTIFIER COMMA MoreParams  */
#line 38 "parse.yacc"
                                   {printf("More Parameters node\n");}
#line 1423 "y.tab.c"
    break;

  case 14: /* Type: K_INTEGER  */
#line 43 "parse.yacc"
                { (yyval.sval) = (yyvsp[0].sval); }
#line 1429 "y.tab.c"
    break;

  case 15: /* Type: K_STRING  */
#line 43 "parse.yacc"
                                        { (yyval.sval) = (yyvsp[0].sval); }
#line 1435 "y.tab.c"
    break;

  case 16: /* Type: K_DOUBLE  */
#line 43 "parse.yacc"
                                                                { (yyval.sval) = (yyvsp[0].sval);}
#line 1441 "y.tab.c"
    break;

  case 20: /* Statements: Epsilon  */
#line 45 "parse.yacc"
                                                                              {printf("Statements node:\n"); printStars();}
#line 1447 "y.tab.c"
    break;

  case 25: /* Declare: Type IDENTIFIER SEMI  */
#line 49 "parse.yacc"
                              {printf("%s\n%s\nDeclare node: \n", (yyvsp[-1].sval), (yyvsp[-2].sval));printStars();}
#line 1453 "y.tab.c"
    break;

  case 26: /* Print: K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI  */
#line 51 "parse.yacc"
                                                     {printf("%s\nprint_integer\nprint node: \n", (yyvsp[-2].sval)); printStars();}
#line 1459 "y.tab.c"
    break;

  case 27: /* Print: K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI  */
#line 51 "parse.yacc"
                                                                                                                                                                    {printf("%s\nprint_string\nprint node: \n", (yyvsp[-2].sval)); printStars();}
#line 1465 "y.tab.c"
    break;

  case 49: /* Assign: IDENTIFIER ASSIGN Math SEMI  */
#line 67 "parse.yacc"
                              {printf("%s\nAssign node: \n", (yyvsp[-3].sval)); printStars();}
#line 1471 "y.tab.c"
    break;

  case 63: /* Factor: IDENTIFIER  */
#line 78 "parse.yacc"
                                 { (yyval.sval) = (yyvsp[0].sval); }
#line 1477 "y.tab.c"
    break;

  case 76: /* NumConstant: ICONSTANT  */
#line 90 "parse.yacc"
                       { (yyval.ival) = (yyvsp[0].ival); printf("%d\n", (yyvsp[0].ival)); }
#line 1483 "y.tab.c"
    break;

  case 77: /* NumConstant: DCONSTANT  */
#line 90 "parse.yacc"
                                                                          { (yyval.dval) = (yyvsp[0].dval); printf("%f\n", (yyvsp[0].dval)); }
#line 1489 "y.tab.c"
    break;


#line 1493 "y.tab.c"

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

#line 96 "parse.yacc"

  
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
  /* printf("enter the string\n"); */
  yyparse();
 }
