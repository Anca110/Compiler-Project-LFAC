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
#line 10 "limbaj.y"

#include <iostream>
#include <vector>
#include <fstream>
#include "SymTable.h"
#include "AST.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;

void yyerror(const char* s);

SymTable* globalScope = nullptr;
SymTable* current = nullptr;
std::vector<SymTable*> allTables;
std::vector<std::string> tempParams;
std::vector<std::string> tempArgs;

int errorCount=0;

SymTable* findClassTable(std::string className)
{
  std::string wanted = "class " + className;

  for (int i = 0; i < (int)allTables.size(); i++)
  {
    if (allTables[i]->getName() == wanted)
      return allTables[i];
  }

  return nullptr;
}


Value::Type toValueType(std::string t)
{
  if (t == "int") return Value::INT;
  if (t == "float") return Value::FLOAT;
  if (t == "bool") return Value::BOOL;
  if (t == "string") return Value::STRING;
  return Value::UNDEF;
}


#line 118 "limbaj.tab.c"

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

#include "limbaj.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TYPE = 3,                       /* TYPE  */
  YYSYMBOL_BOOL = 4,                       /* BOOL  */
  YYSYMBOL_CLASS = 5,                      /* CLASS  */
  YYSYMBOL_FUNCTION = 6,                   /* FUNCTION  */
  YYSYMBOL_ID = 7,                         /* ID  */
  YYSYMBOL_INTVAL = 8,                     /* INTVAL  */
  YYSYMBOL_FLOATVAL = 9,                   /* FLOATVAL  */
  YYSYMBOL_STRVAL = 10,                    /* STRVAL  */
  YYSYMBOL_PRINT = 11,                     /* PRINT  */
  YYSYMBOL_ASSIGN = 12,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 13,                      /* PLUS  */
  YYSYMBOL_MINUS = 14,                     /* MINUS  */
  YYSYMBOL_MULT = 15,                      /* MULT  */
  YYSYMBOL_DIV = 16,                       /* DIV  */
  YYSYMBOL_MOD = 17,                       /* MOD  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_WHILE = 20,                     /* WHILE  */
  YYSYMBOL_FOR = 21,                       /* FOR  */
  YYSYMBOL_BREAK = 22,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 23,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_EQ = 25,                        /* EQ  */
  YYSYMBOL_NEQ = 26,                       /* NEQ  */
  YYSYMBOL_LT = 27,                        /* LT  */
  YYSYMBOL_GT = 28,                        /* GT  */
  YYSYMBOL_LE = 29,                        /* LE  */
  YYSYMBOL_GE = 30,                        /* GE  */
  YYSYMBOL_AND = 31,                       /* AND  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_NOT = 33,                       /* NOT  */
  YYSYMBOL_MAIN = 34,                      /* MAIN  */
  YYSYMBOL_LPAREN = 35,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 36,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 37,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 38,                    /* RBRACE  */
  YYSYMBOL_COMMA = 39,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 40,                 /* SEMICOLON  */
  YYSYMBOL_DOT = 41,                       /* DOT  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_progr = 43,                     /* progr  */
  YYSYMBOL_global_list = 44,               /* global_list  */
  YYSYMBOL_global_def = 45,                /* global_def  */
  YYSYMBOL_global_var_def = 46,            /* global_var_def  */
  YYSYMBOL_class_def = 47,                 /* class_def  */
  YYSYMBOL_48_1 = 48,                      /* $@1  */
  YYSYMBOL_class_body = 49,                /* class_body  */
  YYSYMBOL_class_field = 50,               /* class_field  */
  YYSYMBOL_function_def = 51,              /* function_def  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_param_list_opt = 53,            /* param_list_opt  */
  YYSYMBOL_param_list = 54,                /* param_list  */
  YYSYMBOL_main_section = 55,              /* main_section  */
  YYSYMBOL_main_stmt_list = 56,            /* main_stmt_list  */
  YYSYMBOL_main_stmt = 57,                 /* main_stmt  */
  YYSYMBOL_stmt_list = 58,                 /* stmt_list  */
  YYSYMBOL_stmt = 59,                      /* stmt  */
  YYSYMBOL_simple_stmt = 60,               /* simple_stmt  */
  YYSYMBOL_if_stmt = 61,                   /* if_stmt  */
  YYSYMBOL_stmt_no_else = 62,              /* stmt_no_else  */
  YYSYMBOL_while_stmt = 63,                /* while_stmt  */
  YYSYMBOL_for_stmt = 64,                  /* for_stmt  */
  YYSYMBOL_for_init = 65,                  /* for_init  */
  YYSYMBOL_for_step = 66,                  /* for_step  */
  YYSYMBOL_field_access = 67,              /* field_access  */
  YYSYMBOL_method_call = 68,               /* method_call  */
  YYSYMBOL_function_call = 69,             /* function_call  */
  YYSYMBOL_print_stmt = 70,                /* print_stmt  */
  YYSYMBOL_assign_rhs = 71,                /* assign_rhs  */
  YYSYMBOL_expr_ast = 72,                  /* expr_ast  */
  YYSYMBOL_expr = 73,                      /* expr  */
  YYSYMBOL_bexpr = 74,                     /* bexpr  */
  YYSYMBOL_arg_list_opt = 75,              /* arg_list_opt  */
  YYSYMBOL_76_3 = 76,                      /* $@3  */
  YYSYMBOL_arg_list = 77,                  /* arg_list  */
  YYSYMBOL_return_opt = 78,                /* return_opt  */
  YYSYMBOL_block = 79                      /* block  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   300

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  224

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   126,   126,   130,   131,   135,   136,   137,   141,   157,
     183,   182,   204,   205,   206,   210,   221,   220,   250,   251,
     255,   262,   272,   275,   276,   279,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   332,   333,
     338,   339,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   379,   406,   407,   411,   412,   413,
     418,   422,   426,   430,   435,   481,   538,   588,   596,   598,
     600,   605,   607,   609,   611,   613,   624,   628,   632,   636,
     647,   658,   669,   680,   685,   687,   689,   707,   711,   734,
     736,   738,   740,   742,   747,   748,   749,   750,   751,   752,
     753,   754,   755,   756,   757,   763,   767,   767,   774,   779,
     788,   789,   792
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
  "\"end of file\"", "error", "\"invalid token\"", "TYPE", "BOOL",
  "CLASS", "FUNCTION", "ID", "INTVAL", "FLOATVAL", "STRVAL", "PRINT",
  "ASSIGN", "PLUS", "MINUS", "MULT", "DIV", "MOD", "IF", "ELSE", "WHILE",
  "FOR", "BREAK", "CONTINUE", "RETURN", "EQ", "NEQ", "LT", "GT", "LE",
  "GE", "AND", "OR", "NOT", "MAIN", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "COMMA", "SEMICOLON", "DOT", "$accept", "progr", "global_list",
  "global_def", "global_var_def", "class_def", "$@1", "class_body",
  "class_field", "function_def", "$@2", "param_list_opt", "param_list",
  "main_section", "main_stmt_list", "main_stmt", "stmt_list", "stmt",
  "simple_stmt", "if_stmt", "stmt_no_else", "while_stmt", "for_stmt",
  "for_init", "for_step", "field_access", "method_call", "function_call",
  "print_stmt", "assign_rhs", "expr_ast", "expr", "bexpr", "arg_list_opt",
  "$@3", "arg_list", "return_opt", "block", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-152)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-106)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -152,    11,    73,  -152,    15,    24,    45,    60,   -19,  -152,
    -152,  -152,  -152,  -152,    30,  -152,    48,    37,  -152,  -152,
      55,    99,  -152,   205,  -152,   119,    70,    88,    81,    94,
     101,   103,   109,    69,    97,    16,  -152,  -152,  -152,  -152,
    -152,  -152,    -2,   105,   118,  -152,  -152,     6,  -152,  -152,
     156,    26,   133,   167,    26,    33,    33,   175,  -152,  -152,
    -152,   122,  -152,  -152,  -152,     8,  -152,  -152,   254,   143,
     128,    16,  -152,  -152,  -152,   177,  -152,  -152,  -152,   152,
     183,  -152,   -14,  -152,  -152,  -152,    26,  -152,  -152,  -152,
     127,   165,    16,   168,   246,  -152,    33,    33,   264,    72,
      89,   180,   162,   198,   240,     8,     8,     8,     8,     8,
    -152,   199,   150,   170,   171,    16,  -152,  -152,  -152,  -152,
    -152,  -152,    41,   173,   174,  -152,  -152,   182,   184,  -152,
    -152,   250,    26,    26,    26,    26,  -152,  -152,  -152,   191,
     133,   192,  -152,   222,    92,     8,     8,     8,     8,     8,
       8,    33,    33,    10,   197,    16,    33,  -152,  -152,    74,
      74,  -152,  -152,  -152,   193,    16,  -152,  -152,   200,    16,
    -152,  -152,  -152,  -152,  -152,   157,  -152,   102,   102,  -152,
    -152,    16,   195,  -152,  -152,   254,   254,   254,   254,   254,
     254,  -152,   176,   206,  -152,   225,  -152,  -152,  -152,    42,
    -152,   232,  -152,   233,  -152,  -152,  -152,    33,   197,   238,
    -152,  -152,   140,  -152,   234,   239,    10,    16,   197,   255,
    -152,  -152,    10,  -152
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     0,     0,     0,     4,
       7,     5,     6,     2,     0,    10,     0,     0,    23,     8,
       0,    18,     9,     0,    12,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,   110,    38,    22,    24,    31,
      32,    33,     0,     0,     0,    30,    37,     0,    20,    16,
       0,     0,   106,     0,     0,     0,     0,     0,    34,    35,
      69,    86,    84,    85,    70,     0,    87,   111,    68,     0,
       0,     0,    26,    28,    29,     0,    11,    13,    14,     0,
       0,    73,    75,    71,    72,    74,     0,    76,    78,    77,
       0,     0,     0,    64,     0,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,     0,     0,     0,     0,   110,   112,    39,    40,    47,
      48,    49,     0,     0,     0,    46,    53,     0,     0,    38,
      21,     0,     0,     0,     0,     0,    25,    66,   108,   107,
     106,     0,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    64,    93,    88,
      89,    90,    91,    92,     0,     0,    50,    51,     0,     0,
      42,    44,    45,    27,    15,     0,    83,    79,    80,    81,
      82,     0,     0,    67,    95,    99,   100,   101,   102,   103,
     104,    97,    98,     0,    57,    55,    58,    60,    62,     0,
      54,     0,    52,     0,    17,   109,    65,     0,     0,     0,
      41,    43,     0,    56,     0,     0,     0,     0,     0,     0,
      63,    61,     0,    59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,   236,
    -152,  -152,  -152,  -152,  -152,  -152,   155,  -146,  -147,   262,
    -151,   265,   272,  -152,  -152,   -22,   -21,   -20,   273,    -8,
     -47,   -51,   -37,   147,  -152,  -152,   185,   -23
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     9,    10,    11,    20,    47,    77,    12,
      79,    26,    27,    13,    23,    38,    70,   117,   118,   119,
     195,   120,   121,   102,   215,    66,    88,    89,   125,    67,
      90,    68,    99,    91,    92,   139,    69,   126
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,    42,    43,    44,    98,    98,   194,    94,   197,    75,
      71,     3,     6,   111,   104,    61,    62,    63,    18,   100,
      60,    52,    14,    61,    62,    63,    64,    53,   193,    87,
      81,    15,    87,    82,    83,    84,    85,    95,    72,   131,
      61,    62,    63,    65,    76,    98,   143,    36,   122,   123,
     124,    65,    16,   169,   159,   160,   161,   162,   163,   142,
     144,    86,   213,   127,    87,   219,    96,    17,    97,   194,
      19,   223,   221,   151,   152,   194,     4,    22,     5,     6,
       7,   170,   209,    21,   138,   177,   178,   179,   180,   107,
     108,   109,    24,    51,   185,   186,   187,   188,   189,   190,
      98,    98,    25,   151,   152,    98,    49,     8,   153,    58,
      87,    87,    87,    87,   191,   192,    52,   134,   135,   199,
     151,   152,    53,   151,   152,   154,    48,    50,   184,    54,
     196,   111,   122,   123,   124,   112,    55,    59,    56,    29,
     132,   133,   134,   135,    57,    73,    30,   198,    31,    32,
     113,   114,   115,   122,   123,   124,    98,   201,    74,    80,
     111,   203,   165,   103,   112,    36,   116,   136,    29,  -105,
     212,   151,   152,   205,    93,    30,   216,    31,    32,   113,
     114,   115,   101,   110,   128,    52,   122,   123,   124,   129,
     130,    53,   155,   196,    36,   204,   122,   123,   124,   196,
     111,   137,   156,   140,   112,   157,   164,   151,    29,   220,
     166,   167,    28,   171,   172,    30,    29,    31,    32,   113,
     114,   115,   173,    30,   174,    31,    32,    33,    34,    35,
     181,   206,   183,   200,    36,   105,   106,   107,   108,   109,
     202,   207,    36,    37,   208,   214,   217,   145,   146,   147,
     148,   149,   150,   105,   106,   107,   108,   109,   158,   132,
     133,   134,   135,   132,   133,   134,   135,   105,   106,   107,
     108,   109,   210,   211,   222,   218,   158,   105,   106,   107,
     108,   109,   141,    78,   175,    39,   176,   182,    40,   145,
     146,   147,   148,   149,   150,    41,    45,     0,     0,     0,
     168
};

static const yytype_int16 yycheck[] =
{
      23,    23,    23,    23,    55,    56,   153,    54,   154,     3,
      12,     0,     6,     3,    65,     7,     8,     9,    37,    56,
       4,    35,     7,     7,     8,     9,    10,    41,    18,    51,
       4,     7,    54,     7,     8,     9,    10,     4,    40,    86,
       7,     8,     9,    35,    38,    96,    97,    37,    70,    70,
      70,    35,     7,    12,   105,   106,   107,   108,   109,    96,
      97,    35,   208,    71,    86,   216,    33,     7,    35,   216,
      40,   222,   218,    31,    32,   222,     3,    40,     5,     6,
       7,    40,    40,    35,    92,   132,   133,   134,   135,    15,
      16,    17,    37,    12,   145,   146,   147,   148,   149,   150,
     151,   152,     3,    31,    32,   156,    36,    34,    36,    40,
     132,   133,   134,   135,   151,   152,    35,    15,    16,   156,
      31,    32,    41,    31,    32,    36,     7,    39,    36,    35,
     153,     3,   154,   154,   154,     7,    35,    40,    35,    11,
      13,    14,    15,    16,    35,    40,    18,   155,    20,    21,
      22,    23,    24,   175,   175,   175,   207,   165,    40,     3,
       3,   169,    12,    41,     7,    37,    38,    40,    11,    36,
     207,    31,    32,   181,     7,    18,    36,    20,    21,    22,
      23,    24,     7,    40,     7,    35,   208,   208,   208,    37,
       7,    41,    12,   216,    37,    38,   218,   218,   218,   222,
       3,    36,    40,    35,     7,     7,     7,    31,    11,   217,
      40,    40,     7,    40,    40,    18,    11,    20,    21,    22,
      23,    24,    40,    18,    40,    20,    21,    22,    23,    24,
      39,    36,    40,    40,    37,    13,    14,    15,    16,    17,
      40,    35,    37,    38,    19,     7,    12,    25,    26,    27,
      28,    29,    30,    13,    14,    15,    16,    17,    36,    13,
      14,    15,    16,    13,    14,    15,    16,    13,    14,    15,
      16,    17,    40,    40,    19,    36,    36,    13,    14,    15,
      16,    17,    36,    47,   129,    23,    36,   140,    23,    25,
      26,    27,    28,    29,    30,    23,    23,    -1,    -1,    -1,
     115
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    43,    44,     0,     3,     5,     6,     7,    34,    45,
      46,    47,    51,    55,     7,     7,     7,     7,    37,    40,
      48,    35,    40,    56,    37,     3,    53,    54,     7,    11,
      18,    20,    21,    22,    23,    24,    37,    38,    57,    61,
      63,    64,    67,    68,    69,    70,    79,    49,     7,    36,
      39,    12,    35,    41,    35,    35,    35,    35,    40,    40,
       4,     7,     8,     9,    10,    35,    67,    71,    73,    78,
      58,    12,    40,    40,    40,     3,    38,    50,    51,    52,
       3,     4,     7,     8,     9,    10,    35,    67,    68,    69,
      72,    75,    76,     7,    72,     4,    33,    35,    73,    74,
      74,     7,    65,    41,    73,    13,    14,    15,    16,    17,
      40,     3,     7,    22,    23,    24,    38,    59,    60,    61,
      63,    64,    67,    68,    69,    70,    79,    71,     7,    37,
       7,    72,    13,    14,    15,    16,    40,    36,    71,    77,
      35,    36,    74,    73,    74,    25,    26,    27,    28,    29,
      30,    31,    32,    36,    36,    12,    40,     7,    36,    73,
      73,    73,    73,    73,     7,    12,    40,    40,    78,    12,
      40,    40,    40,    40,    40,    58,    36,    72,    72,    72,
      72,    39,    75,    40,    36,    73,    73,    73,    73,    73,
      73,    74,    74,    18,    60,    62,    79,    59,    71,    74,
      40,    71,    40,    71,    38,    71,    36,    35,    19,    40,
      40,    40,    74,    59,     7,    66,    36,    12,    36,    62,
      71,    59,    19,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    46,    46,
      48,    47,    49,    49,    49,    50,    52,    51,    53,    53,
      54,    54,    55,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    60,    61,    61,    62,    62,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    76,    75,    77,    77,
      78,    78,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     3,     3,
       0,     6,     0,     2,     2,     3,     0,     9,     0,     1,
       2,     4,     4,     0,     2,     4,     2,     4,     2,     2,
       1,     1,     1,     1,     2,     2,     3,     1,     0,     2,
       1,     4,     2,     4,     2,     2,     1,     1,     1,     1,
       2,     2,     3,     1,     3,     5,     7,     1,     1,     7,
       5,     9,     3,     3,     3,     6,     4,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     0,     0,     2,     1,     3,
       0,     1,     3
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
  case 8: /* global_var_def: TYPE ID SEMICOLON  */
#line 142 "limbaj.y"
    {
      if (globalScope->existsLocal(*(yyvsp[-1].Str)))
      {
        std::cerr << "Semantic error at line " << yylineno
                  << ": '" << *(yyvsp[-1].Str) << "' declared twice in global scope\n";
        errorCount++;
      }
      else
      {
        globalScope->addVariable(*(yyvsp[-1].Str), *(yyvsp[-2].Str));
      }

      delete (yyvsp[-2].Str);
      delete (yyvsp[-1].Str);
    }
#line 1364 "limbaj.tab.c"
    break;

  case 9: /* global_var_def: ID ID SEMICOLON  */
#line 158 "limbaj.y"
    {
      // declarare obiect: Car myCar;
      // $1 = "Car" (numele clasei)
      // $2 = "myCar" (numele variabilei)

      if (globalScope->existsLocal(*(yyvsp[-1].Str)))
      {
        std::cerr << "Semantic error at line " << yylineno
                  << ": '" << *(yyvsp[-1].Str) << "' declared twice in global scope\n";
        errorCount++;
      }
      else
      {
        // salvam variabila "myCar" cu tipul "Car"
        globalScope->addVariable(*(yyvsp[-1].Str), *(yyvsp[-2].Str));
      }
      delete (yyvsp[-2].Str);
      delete (yyvsp[-1].Str);
    }
#line 1388 "limbaj.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 183 "limbaj.y"
    {
      // 1) Adaugă numele clasei în tabela globală
      // (current ar trebui să fie global aici)
      globalScope->addClass(*(yyvsp[0].Str));
      // 2) Creează tabela (scope-ul) clasei și o leagă de parent (global)
      SymTable* cls = new SymTable(std::string("class ") + *(yyvsp[0].Str), current);
      // 3) O reținem ca s-o printăm la final
      allTables.push_back(cls);
      // 4) Intrăm în scope-ul clasei
      current = cls;
    }
#line 1404 "limbaj.tab.c"
    break;

  case 11: /* class_def: CLASS ID $@1 LBRACE class_body RBRACE  */
#line 195 "limbaj.y"
    {
      // 5) Ieșim din scope-ul clasei -> revenim la părinte (global)
      current = current->getParent();
      // eliberăm string-ul alocat în lexer pentru ID
      delete (yyvsp[-4].Str);
    }
#line 1415 "limbaj.tab.c"
    break;

  case 15: /* class_field: TYPE ID SEMICOLON  */
#line 211 "limbaj.y"
    {
      // adaugă câmpul în tabela curentă (tabela clasei)
      current->addVariable(*(yyvsp[-1].Str), *(yyvsp[-2].Str));
      delete (yyvsp[-2].Str);
      delete (yyvsp[-1].Str);
    }
#line 1426 "limbaj.tab.c"
    break;

  case 16: /* $@2: %empty  */
#line 221 "limbaj.y"
    {
      // 1) adaugă funcția în tabela globală (cu returnType "unknown")
      globalScope->addFunction(*(yyvsp[-3].Str), "unknown", tempParams);
      // 2) creează tabela funcției (scope nou)
      SymTable* fn = new SymTable(std::string("function ") + *(yyvsp[-3].Str), current);
      allTables.push_back(fn);
      // 3) intră în scope-ul funcției
      current = fn;
      // 4) adaugam parametrii ca variabile in tabela functiei, cu tip real
      for (const auto& p : tempParams)
      {
        // p e de forma "int x" / "float y"
        size_t pos = p.find(' ');
        std::string t = p.substr(0, pos);// tipul
        std::string n = p.substr(pos + 1);// numele
        current->addVariable(n, t);
      }
      // 5) curățăm lista temporară pentru următoarea funcție
      tempParams.clear();
    }
#line 1451 "limbaj.tab.c"
    break;

  case 17: /* function_def: FUNCTION ID LPAREN param_list_opt RPAREN $@2 LBRACE stmt_list RBRACE  */
#line 242 "limbaj.y"
    {
      // ieșim din scope-ul funcției
      current = current->getParent();
      delete (yyvsp[-7].Str);
    }
#line 1461 "limbaj.tab.c"
    break;

  case 20: /* param_list: TYPE ID  */
#line 256 "limbaj.y"
    {
      // salvam ca text: "int x" / "float y" / etc
      tempParams.push_back(*(yyvsp[-1].Str) + std::string(" ") + *(yyvsp[0].Str));
      delete (yyvsp[-1].Str);
      delete (yyvsp[0].Str);
    }
#line 1472 "limbaj.tab.c"
    break;

  case 21: /* param_list: param_list COMMA TYPE ID  */
#line 263 "limbaj.y"
    {
      tempParams.push_back(*(yyvsp[-1].Str) + std::string(" ") + *(yyvsp[0].Str));
      delete (yyvsp[-1].Str);
      delete (yyvsp[0].Str);
    }
#line 1482 "limbaj.tab.c"
    break;

  case 25: /* main_stmt: ID ASSIGN expr_ast SEMICOLON  */
#line 280 "limbaj.y"
    {
      SymTable::Symbol* s = current->lookup(*(yyvsp[-3].Str));

      if (s == nullptr)
      {
        std::cerr << "Semantic error at line " << yylineno
                  << ": variable '" << *(yyvsp[-3].Str) << "' used but not declared\n";
        errorCount++;
      }
      else
      {
        Value::Type leftT = toValueType(s->type);

        if ((yyvsp[-1].node)->exprType == Value::UNDEF)
        {
          std::cerr << "Semantic error at line " << yylineno
                    << ": operands have different types in expression\n";
          errorCount++;
        }
        else if (leftT != (yyvsp[-1].node)->exprType)
        {
          std::cerr << "Semantic error at line " << yylineno
                    << ": assignment type mismatch for '" << *(yyvsp[-3].Str)
                    << "': left is '" << s->type
                    << "' but right has different type\n";
          errorCount++;
        }
        else
        {
          ASTNode* idNode = ASTNode::makeId(*(yyvsp[-3].Str), leftT);
          ASTNode* asg = ASTNode::makeAssign(idNode, (yyvsp[-1].node));
          asg->eval(current);
        }
      }

      delete (yyvsp[-3].Str);
    }
#line 1524 "limbaj.tab.c"
    break;

  case 41: /* stmt: ID ASSIGN assign_rhs SEMICOLON  */
#line 340 "limbaj.y"
  {
    SymTable::Symbol* s = current->lookup(*(yyvsp[-3].Str));

    if (s == nullptr)
    {
      std::cerr << "Semantic error at line " << yylineno
                << ": variable '" << *(yyvsp[-3].Str) << "' used but not declared\n";
      errorCount++;
    }
    else
    {
      if (s->type != *(yyvsp[-1].Str))
      {
        std::cerr << "Semantic error at line " << yylineno
                  << ": assignment type mismatch for '" << *(yyvsp[-3].Str)
                  << "': left is '" << s->type
                  << "' but right is '" << *(yyvsp[-1].Str) << "'\n";
        errorCount++;
      }
    }

    delete (yyvsp[-3].Str);
    delete (yyvsp[-1].Str);
  }
#line 1553 "limbaj.tab.c"
    break;

  case 54: /* simple_stmt: TYPE ID SEMICOLON  */
#line 380 "limbaj.y"
    {//current=tabela de simboluri a scope-ului curent
      // daca e deja declarat in acelasi scope -> eroare
      if (current->existsLocal(*(yyvsp[-1].Str)))
      {
        //std::cerr pt a afisa erori
        //yylineno(din limbaj.l) care tine minte linia curenta din test.txt
        std::cerr << "Semantic error at line " << yylineno
                  << ": '" << *(yyvsp[-1].Str) << "' declared twice in scope '" 
                  << current->getName() << "'\n";
        //ex:Semantic error at line 12: 'r' declared twice in scope 'function add'

        errorCount++;//tine minte nr total de rori
      }
      else
      {
        // daca nu exista, il adaugam normal in tabela
        current->addVariable(*(yyvsp[-1].Str), *(yyvsp[-2].Str));
      }

      delete (yyvsp[-2].Str);
      delete (yyvsp[-1].Str);
    }
#line 1580 "limbaj.tab.c"
    break;

  case 62: /* for_init: ID ASSIGN assign_rhs  */
#line 426 "limbaj.y"
                           { delete (yyvsp[-2].Str); }
#line 1586 "limbaj.tab.c"
    break;

  case 63: /* for_step: ID ASSIGN assign_rhs  */
#line 430 "limbaj.y"
                           { delete (yyvsp[-2].Str); }
#line 1592 "limbaj.tab.c"
    break;

  case 64: /* field_access: ID DOT ID  */
#line 436 "limbaj.y"
    {/*myCar există (a fost declarat)
      myCar este un obiect al unei clase (Car)
      în clasa Car există field-ul speed*/

      // $1 = numele obiectului (myCar)
      // $3 = numele field-ului (speed)

      SymTable::Symbol* obj = current->lookup(*(yyvsp[-2].Str));

      // 1) obiectul exista?
      if (obj == nullptr)//nu l a gasit nici in scope-ul curent si nici in parinte=> n a fost declarat simbolul
      {
        std::cerr << "Semantic error at line " << yylineno
                  << ": object '" << *(yyvsp[-2].Str) << "' not declared\n";
        errorCount++;
      }
      else//daca exista=>intoarce pointer la Symbol
      {
        // 2) gasim tabela clasei lui (ex: class Car)
        SymTable* cls = findClassTable(obj->type);

        if (cls == nullptr)//nu exista clasa simbolului
        {
          std::cerr << "Semantic error at line " << yylineno
                    << ": class '" << obj->type << "' not found for object '" << *(yyvsp[-2].Str) << "'\n";
          errorCount++;
        }
        else//a gasit clasa din care face parte
        {
          // 3) field-ul exista in clasa?
          if (cls->lookupLocal(*(yyvsp[0].Str)) == nullptr)
          {
            std::cerr << "Semantic error at line " << yylineno
                      << ": field '" << *(yyvsp[0].Str) << "' not found in class '" << obj->type << "'\n";
            errorCount++;
          }
        }
      }

      delete (yyvsp[-2].Str);
      delete (yyvsp[0].Str);
    }
#line 1639 "limbaj.tab.c"
    break;

  case 65: /* method_call: ID DOT ID LPAREN arg_list_opt RPAREN  */
#line 482 "limbaj.y"
    {
      // $1 = obiectul (myCar)
      // $3 = metoda (setSpeed)

      SymTable::Symbol* obj = current->lookup(*(yyvsp[-5].Str));

      // 1) obiectul exista?
      if (obj == nullptr)
      {
        std::cerr << "Semantic error at line " << yylineno
                  << ": object '" << *(yyvsp[-5].Str) << "' not declared\n";
        errorCount++;
      }
      else
      {
        // 2) gasim tabela clasei lui
        SymTable* cls = findClassTable(obj->type);

        if (cls == nullptr)
        {
          std::cerr << "Semantic error at line " << yylineno
                    << ": class '" << obj->type << "' not found for object '" << *(yyvsp[-5].Str) << "'\n";
          errorCount++;
        }
        else
        {
          // 3) metoda exista in clasa?
          SymTable::Symbol* m = cls->lookupLocal(*(yyvsp[-3].Str));

          if (m == nullptr)
          {
            std::cerr << "Semantic error at line " << yylineno
                      << ": method '" << *(yyvsp[-3].Str) << "' not found in class '" << obj->type << "'\n";
            errorCount++;
          }
          else
          {
            // optional: verificam sa fie chiar "Function"
            if (m->kind != SymTable::Kind::Function)
            {
              std::cerr << "Semantic error at line " << yylineno
                        << ": '" << *(yyvsp[-3].Str) << "' is not a method in class '" << obj->type << "'\n";
              errorCount++;
            }
          }
        }
      }

      tempArgs.clear();

      delete (yyvsp[-5].Str);
      delete (yyvsp[-3].Str);
    }
#line 1697 "limbaj.tab.c"
    break;

  case 66: /* function_call: ID LPAREN arg_list_opt RPAREN  */
#line 539 "limbaj.y"
    {
      // cautam functia in global
      SymTable::Symbol* fn = globalScope->lookupLocal(*(yyvsp[-3].Str));

      if (fn == nullptr || fn->kind != SymTable::Kind::Function)
      {
        std::cerr << "Semantic error at line " << yylineno
                  << ": function '" << *(yyvsp[-3].Str) << "' not declared\n";
        errorCount++;
      }
      else
      {
        // 1) verificam numarul de argumente
        if ((int)fn->params.size() != (int)tempArgs.size())
        {
          std::cerr << "Semantic error at line " << yylineno
                    << ": function '" << *(yyvsp[-3].Str) << "' called with "
                    << tempArgs.size() << " args but expects "
                    << fn->params.size() << "\n";
          errorCount++;
        }
        else
        {
          // 2) verificam tipurile argumentelor
          for (int i = 0; i < (int)fn->params.size(); i++)
          {
            // fiecare param e text "int x"
            std::string p = fn->params[i];
            size_t pos = p.find(' ');
            std::string expected = p.substr(0, pos);

            if (expected != tempArgs[i] && tempArgs[i] != "undef")
            {
              std::cerr << "Semantic error at line " << yylineno
                        << ": in call of '" << *(yyvsp[-3].Str) << "', argument " << (i+1)
                        << " has type '" << tempArgs[i]
                        << "' but expected '" << expected << "'\n";
              errorCount++;
            }
          }
        }
      }

      delete (yyvsp[-3].Str);
    }
#line 1747 "limbaj.tab.c"
    break;

  case 67: /* print_stmt: PRINT LPAREN expr_ast RPAREN SEMICOLON  */
#line 589 "limbaj.y"
    {
      ASTNode* p = ASTNode::makePrint((yyvsp[-2].node));//face nodul print
      p->eval(current);//il evalueaza si afiseaza
    }
#line 1756 "limbaj.tab.c"
    break;

  case 68: /* assign_rhs: expr  */
#line 597 "limbaj.y"
    { (yyval.Str) = (yyvsp[0].Str); }
#line 1762 "limbaj.tab.c"
    break;

  case 69: /* assign_rhs: BOOL  */
#line 599 "limbaj.y"
    { (yyval.Str) = new std::string("bool"); }
#line 1768 "limbaj.tab.c"
    break;

  case 70: /* assign_rhs: STRVAL  */
#line 601 "limbaj.y"
    { (yyval.Str) = new std::string("string"); delete (yyvsp[0].Str); }
#line 1774 "limbaj.tab.c"
    break;

  case 71: /* expr_ast: INTVAL  */
#line 606 "limbaj.y"
    { (yyval.node) = ASTNode::makeInt((yyvsp[0].ival)); }
#line 1780 "limbaj.tab.c"
    break;

  case 72: /* expr_ast: FLOATVAL  */
#line 608 "limbaj.y"
    { (yyval.node) = ASTNode::makeFloat((yyvsp[0].fval)); }
#line 1786 "limbaj.tab.c"
    break;

  case 73: /* expr_ast: BOOL  */
#line 610 "limbaj.y"
    { (yyval.node) = ASTNode::makeBool((yyvsp[0].bval)); }
#line 1792 "limbaj.tab.c"
    break;

  case 74: /* expr_ast: STRVAL  */
#line 612 "limbaj.y"
    { (yyval.node) = ASTNode::makeString(*(yyvsp[0].Str)); delete (yyvsp[0].Str); }
#line 1798 "limbaj.tab.c"
    break;

  case 75: /* expr_ast: ID  */
#line 614 "limbaj.y"
    {
      SymTable::Symbol* s = current->lookup(*(yyvsp[0].Str));
      Value::Type vt = Value::UNDEF;

      if (s != nullptr)
        vt = toValueType(s->type);

      (yyval.node) = ASTNode::makeId(*(yyvsp[0].Str), vt);
      delete (yyvsp[0].Str);
    }
#line 1813 "limbaj.tab.c"
    break;

  case 76: /* expr_ast: field_access  */
#line 625 "limbaj.y"
    {
      (yyval.node) = ASTNode::makeOther(Value::UNDEF);
    }
#line 1821 "limbaj.tab.c"
    break;

  case 77: /* expr_ast: function_call  */
#line 629 "limbaj.y"
    {
      (yyval.node) = ASTNode::makeOther(Value::UNDEF);
    }
#line 1829 "limbaj.tab.c"
    break;

  case 78: /* expr_ast: method_call  */
#line 633 "limbaj.y"
    {
      (yyval.node) = ASTNode::makeOther(Value::UNDEF);
    }
#line 1837 "limbaj.tab.c"
    break;

  case 79: /* expr_ast: expr_ast PLUS expr_ast  */
#line 637 "limbaj.y"
{
  Value::Type t;

  if ((yyvsp[-2].node)->exprType == (yyvsp[0].node)->exprType)
    t = (yyvsp[-2].node)->exprType;
  else
    t = Value::UNDEF;

  (yyval.node) = ASTNode::makeBinary(ASTNode::PLUS_NODE, (yyvsp[-2].node), (yyvsp[0].node), t);
}
#line 1852 "limbaj.tab.c"
    break;

  case 80: /* expr_ast: expr_ast MINUS expr_ast  */
#line 648 "limbaj.y"
{
  Value::Type t;

  if ((yyvsp[-2].node)->exprType == (yyvsp[0].node)->exprType)
    t = (yyvsp[-2].node)->exprType;
  else
    t = Value::UNDEF;

  (yyval.node) = ASTNode::makeBinary(ASTNode::MINUS_NODE, (yyvsp[-2].node), (yyvsp[0].node), t);
}
#line 1867 "limbaj.tab.c"
    break;

  case 81: /* expr_ast: expr_ast MULT expr_ast  */
#line 659 "limbaj.y"
{
  Value::Type t;

  if ((yyvsp[-2].node)->exprType == (yyvsp[0].node)->exprType)
    t = (yyvsp[-2].node)->exprType;
  else
    t = Value::UNDEF;

  (yyval.node) = ASTNode::makeBinary(ASTNode::MULT_NODE, (yyvsp[-2].node), (yyvsp[0].node), t);
}
#line 1882 "limbaj.tab.c"
    break;

  case 82: /* expr_ast: expr_ast DIV expr_ast  */
#line 670 "limbaj.y"
{
  Value::Type t;

  if ((yyvsp[-2].node)->exprType == (yyvsp[0].node)->exprType)
    t = (yyvsp[-2].node)->exprType;
  else
    t = Value::UNDEF;

  (yyval.node) = ASTNode::makeBinary(ASTNode::DIV_NODE, (yyvsp[-2].node), (yyvsp[0].node), t);
}
#line 1897 "limbaj.tab.c"
    break;

  case 83: /* expr_ast: LPAREN expr_ast RPAREN  */
#line 681 "limbaj.y"
    { (yyval.node) = (yyvsp[-1].node); }
#line 1903 "limbaj.tab.c"
    break;

  case 84: /* expr: INTVAL  */
#line 686 "limbaj.y"
    { (yyval.Str) = new std::string("int"); }
#line 1909 "limbaj.tab.c"
    break;

  case 85: /* expr: FLOATVAL  */
#line 688 "limbaj.y"
    { (yyval.Str) = new std::string("float"); }
#line 1915 "limbaj.tab.c"
    break;

  case 86: /* expr: ID  */
#line 690 "limbaj.y"
    {
      SymTable::Symbol* s = current->lookup(*(yyvsp[0].Str));
      if (s == nullptr)
      {
        std::cerr << "Semantic error at line " << yylineno
                  << ": variable '" << *(yyvsp[0].Str) << "' used but not declared\n";
        errorCount++;
        (yyval.Str) = new std::string("undef");
      }
      else
      {
        // daca exista, tipul expresiei e tipul variabilei
        (yyval.Str) = new std::string(s->type);
      }

      delete (yyvsp[0].Str);
    }
#line 1937 "limbaj.tab.c"
    break;

  case 87: /* expr: field_access  */
#line 708 "limbaj.y"
    {
      (yyval.Str) = new std::string("undef");
    }
#line 1945 "limbaj.tab.c"
    break;

  case 88: /* expr: expr PLUS expr  */
#line 712 "limbaj.y"
  {
    // $1 = tipul expresiei din stanga (ex: "int")
    // $3 = tipul expresiei din dreapta (ex: "float")

    if (*(yyvsp[-2].Str) != *(yyvsp[0].Str))
    {
      std::cerr << "Semantic error at line " << yylineno
                << ": operands have different types for '+': '" << *(yyvsp[-2].Str)
                << "' and '" << *(yyvsp[0].Str) << "'\n";
      errorCount++;
      (yyval.Str) = new std::string("undef");
      //$$ e tipul expresiei intregi(ce intoarce)
    }
    else
    {
      // daca sunt egale, rezultatul are acelasi tip
      (yyval.Str) = new std::string(*(yyvsp[-2].Str));
    }

    delete (yyvsp[-2].Str);
    delete (yyvsp[0].Str);
  }
#line 1972 "limbaj.tab.c"
    break;

  case 89: /* expr: expr MINUS expr  */
#line 735 "limbaj.y"
    { delete (yyvsp[-2].Str); delete (yyvsp[0].Str); (yyval.Str) = new std::string("undef"); }
#line 1978 "limbaj.tab.c"
    break;

  case 90: /* expr: expr MULT expr  */
#line 737 "limbaj.y"
    { delete (yyvsp[-2].Str); delete (yyvsp[0].Str); (yyval.Str) = new std::string("undef"); }
#line 1984 "limbaj.tab.c"
    break;

  case 91: /* expr: expr DIV expr  */
#line 739 "limbaj.y"
    { delete (yyvsp[-2].Str); delete (yyvsp[0].Str); (yyval.Str) = new std::string("undef"); }
#line 1990 "limbaj.tab.c"
    break;

  case 92: /* expr: expr MOD expr  */
#line 741 "limbaj.y"
    { delete (yyvsp[-2].Str); delete (yyvsp[0].Str); (yyval.Str) = new std::string("undef"); }
#line 1996 "limbaj.tab.c"
    break;

  case 93: /* expr: LPAREN expr RPAREN  */
#line 743 "limbaj.y"
    { (yyval.Str) = (yyvsp[-1].Str); }
#line 2002 "limbaj.tab.c"
    break;

  case 105: /* arg_list_opt: %empty  */
#line 763 "limbaj.y"
    {
      tempArgs.clear();
    }
#line 2010 "limbaj.tab.c"
    break;

  case 106: /* $@3: %empty  */
#line 767 "limbaj.y"
    {
      tempArgs.clear();// se executa si cand avem argumente
    }
#line 2018 "limbaj.tab.c"
    break;

  case 108: /* arg_list: assign_rhs  */
#line 775 "limbaj.y"
    {
      tempArgs.push_back(*(yyvsp[0].Str));
      delete (yyvsp[0].Str);
    }
#line 2027 "limbaj.tab.c"
    break;

  case 109: /* arg_list: arg_list COMMA assign_rhs  */
#line 780 "limbaj.y"
    {
      tempArgs.push_back(*(yyvsp[0].Str));
      delete (yyvsp[0].Str);
    }
#line 2036 "limbaj.tab.c"
    break;


#line 2040 "limbaj.tab.c"

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

#line 795 "limbaj.y"



void yyerror(const char* s) {
  std::cerr << "error: " << s << " at line: " << yylineno << "\n";
}

int main(int argc, char** argv) 
{
  if (argc > 1) yyin = fopen(argv[1], "r");
  globalScope = new SymTable("global", nullptr);
  current = globalScope;
  allTables.push_back(globalScope);

  yyparse();

  std::ofstream fout("tables.txt");

  for (int i = 0; i < (int)allTables.size(); i++)
  {
    allTables[i]->print(fout);
  }

  fout.close();

  std::cout << "Parsed OK (for current .l tokens).\n";
  return 0;
}
