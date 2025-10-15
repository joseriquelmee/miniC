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
#line 1 "sintaxis.y"

    #define _GNU_SOURCE
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "listaSimbolos.h"
    #include "listaCodigo.h"

    // Funciones necesarias para analisis sintactico    
    extern int yylex();
    void yyerror(const char *msg);
    // Variables externas
    extern int yylineno;
    extern int errores; 
    // Registros 
    int regs[10];
    void iniciar_regs();
    char *obtener_reg(); // $tX
    void liberar_reg(char *reg);
    char *concatenar(char *arg1, char *arg2);
    void imprimirCodigo(ListaC codigo);
    void imprimirSimbolos();
    char *obtener_etiqueta();
    // Lista de símbolos
    Lista l;
    // Tipo del identificador
    Tipo tipo_decl;
    int menos;
    int contador_cadenas = 0;
    int contadorEtiquetas = 1;

#line 103 "sintaxis.tab.c"

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

#include "sintaxis.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PLUSOP = 3,                     /* "+"  */
  YYSYMBOL_MINUSOP = 4,                    /* "-"  */
  YYSYMBOL_MULTOP = 5,                     /* "*"  */
  YYSYMBOL_BARRA = 6,                      /* "/"  */
  YYSYMBOL_LPAREN = 7,                     /* "("  */
  YYSYMBOL_RPAREN = 8,                     /* ")"  */
  YYSYMBOL_LCORCH = 9,                     /* "{"  */
  YYSYMBOL_RCORCH = 10,                    /* "}"  */
  YYSYMBOL_FIN = 11,                       /* ";"  */
  YYSYMBOL_COMMA = 12,                     /* ","  */
  YYSYMBOL_INTLIT = 13,                    /* "numero"  */
  YYSYMBOL_STR = 14,                       /* "string"  */
  YYSYMBOL_ASIGN = 15,                     /* "="  */
  YYSYMBOL_PRINT = 16,                     /* "print"  */
  YYSYMBOL_READ = 17,                      /* "read"  */
  YYSYMBOL_VOID = 18,                      /* "void"  */
  YYSYMBOL_ID = 19,                        /* "id"  */
  YYSYMBOL_VAR = 20,                       /* "var"  */
  YYSYMBOL_CONST = 21,                     /* "const"  */
  YYSYMBOL_IF = 22,                        /* "if"  */
  YYSYMBOL_ELSE = 23,                      /* "else"  */
  YYSYMBOL_WHILE = 24,                     /* "while"  */
  YYSYMBOL_UMINUS = 25,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 26,                  /* $accept  */
  YYSYMBOL_program = 27,                   /* program  */
  YYSYMBOL_inicio = 28,                    /* inicio  */
  YYSYMBOL_declarations = 29,              /* declarations  */
  YYSYMBOL_30_1 = 30,                      /* $@1  */
  YYSYMBOL_31_2 = 31,                      /* $@2  */
  YYSYMBOL_identifier_list = 32,           /* identifier_list  */
  YYSYMBOL_asig = 33,                      /* asig  */
  YYSYMBOL_statement_list = 34,            /* statement_list  */
  YYSYMBOL_statement = 35,                 /* statement  */
  YYSYMBOL_print_list = 36,                /* print_list  */
  YYSYMBOL_print_item = 37,                /* print_item  */
  YYSYMBOL_read_list = 38,                 /* read_list  */
  YYSYMBOL_expression = 39                 /* expression  */
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
typedef yytype_int8 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYLAST   100

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  36
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  77

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


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
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    90,    90,   111,   116,   116,   125,   125,   134,   141,
     146,   157,   173,   199,   206,   211,   236,   241,   277,   299,
     335,   340,   345,   348,   353,   362,   386,   414,   452,   490,
     504,   518,   532,   546,   558,   563,   583
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"+\"", "\"-\"",
  "\"*\"", "\"/\"", "\"(\"", "\")\"", "\"{\"", "\"}\"", "\";\"", "\",\"",
  "\"numero\"", "\"string\"", "\"=\"", "\"print\"", "\"read\"", "\"void\"",
  "\"id\"", "\"var\"", "\"const\"", "\"if\"", "\"else\"", "\"while\"",
  "UMINUS", "$accept", "program", "inicio", "declarations", "$@1", "$@2",
  "identifier_list", "asig", "statement_list", "statement", "print_list",
  "print_item", "read_list", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-70)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -70,     4,   -11,   -70,   -10,    12,    13,    23,   -70,    -4,
     -70,   -70,    17,     9,     9,    24,   -70,   -70,     1,    27,
      34,    46,    50,   -70,    44,    19,   -70,    31,   -70,    28,
      47,    47,   -70,   -70,   -70,    53,   -70,    86,   -70,    82,
      47,    47,    47,    47,   -70,     9,   -70,   -70,   -70,    68,
     -70,     1,    47,    47,    47,    47,   -70,    43,    64,    74,
      80,    86,   -70,   -70,   -70,    90,    90,   -70,   -70,   -70,
     -70,    39,    39,    58,   -70,    39,   -70
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     0,     0,     8,    14,
       4,     6,     0,     0,     0,     0,    14,     2,     0,     0,
       0,     0,     0,    13,    11,     0,     9,     0,    22,     0,
       0,     0,    36,    26,    35,     0,    23,    25,    27,     0,
       0,     0,     0,     0,     5,     0,     7,    16,    33,     0,
      20,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,    12,    10,    34,    24,    29,    30,    31,    32,    28,
      15,     0,     0,    18,    19,     0,    17
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,   -70,   -70,   -70,   -70,   -70,    73,    52,    83,   -69,
     -70,    49,   -70,   -30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     9,    13,    14,    25,    26,    12,    23,
      35,    36,    39,    37
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      48,    49,    73,    74,     3,    30,    76,     4,    31,     5,
      58,    59,    60,    61,    32,    33,    10,    11,    15,     6,
      34,     7,    65,    66,    67,    68,    16,    17,    24,    15,
      44,    45,     8,    18,    19,    28,    20,    16,    47,    21,
      15,    22,    46,    45,    18,    19,    38,    20,    16,    40,
      21,    30,    22,    41,    31,    18,    19,    42,    20,    43,
      32,    21,    69,    22,    50,    51,    34,    52,    53,    54,
      55,    52,    53,    54,    55,    70,    63,    52,    53,    54,
      55,    75,    71,    52,    53,    54,    55,    27,    72,    52,
      53,    54,    55,    56,    57,    54,    55,    62,     0,    29,
      64
};

static const yytype_int8 yycheck[] =
{
      30,    31,    71,    72,     0,     4,    75,    18,     7,    19,
      40,    41,    42,    43,    13,    14,    20,    21,     1,     7,
      19,     8,    52,    53,    54,    55,     9,    10,    19,     1,
      11,    12,     9,    16,    17,    11,    19,     9,    10,    22,
       1,    24,    11,    12,    16,    17,    19,    19,     9,    15,
      22,     4,    24,     7,     7,    16,    17,     7,    19,    15,
      13,    22,    19,    24,    11,    12,    19,     3,     4,     5,
       6,     3,     4,     5,     6,    11,     8,     3,     4,     5,
       6,    23,     8,     3,     4,     5,     6,    14,     8,     3,
       4,     5,     6,    11,    12,     5,     6,    45,    -1,    16,
      51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    27,    28,     0,    18,    19,     7,     8,     9,    29,
      20,    21,    34,    30,    31,     1,     9,    10,    16,    17,
      19,    22,    24,    35,    19,    32,    33,    32,    11,    34,
       4,     7,    13,    14,    19,    36,    37,    39,    19,    38,
      15,     7,     7,    15,    11,    12,    11,    10,    39,    39,
      11,    12,     3,     4,     5,     6,    11,    12,    39,    39,
      39,    39,    33,     8,    37,    39,    39,    39,    39,    19,
      11,     8,     8,    35,    35,    23,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    26,    27,    28,    30,    29,    31,    29,    29,    32,
      32,    33,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    35,    35,    36,    36,    37,    37,    38,    38,    39,
      39,    39,    39,    39,    39,    39,    39
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     9,     0,     0,     5,     0,     5,     0,     1,
       3,     1,     3,     2,     0,     4,     3,     7,     5,     5,
       3,     3,     2,     1,     3,     1,     1,     1,     3,     3,
       3,     3,     3,     2,     3,     1,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* program: inicio "void" "id" "(" ")" "{" declarations statement_list "}"  */
#line 91 "sintaxis.y"
                    {
                        if(errores == 0){
                            (yyval.codigo) = creaLC();
                            concatenaLC((yyval.codigo), (yyvsp[-2].codigo));
                            concatenaLC((yyval.codigo), (yyvsp[-1].codigo));
                            liberaLC((yyvsp[-2].codigo));
                            liberaLC((yyvsp[-1].codigo));
                            Operacion o;
                            o.op = "jr";
                            o.res = "$ra";
                            o.arg1 = NULL;
                            o.arg2 = NULL;
                            insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
                            imprimirSimbolos();
                            imprimirCodigo((yyval.codigo));
                            liberaLS(l);
                            liberaLC((yyval.codigo));
                        }
                    }
#line 1463 "sintaxis.tab.c"
    break;

  case 3: /* inicio: %empty  */
#line 111 "sintaxis.y"
                                {
                        l = creaLS(); 
                        memset(regs, 0, 10);
                }
#line 1472 "sintaxis.tab.c"
    break;

  case 4: /* $@1: %empty  */
#line 116 "sintaxis.y"
                                   { tipo_decl = VARIABLE; }
#line 1478 "sintaxis.tab.c"
    break;

  case 5: /* declarations: declarations "var" $@1 identifier_list ";"  */
#line 116 "sintaxis.y"
                                                                                                      {
                    if(errores == 0){
                        (yyval.codigo) = creaLC();
                        concatenaLC((yyval.codigo), (yyvsp[-4].codigo));
                        concatenaLC((yyval.codigo), (yyvsp[-1].codigo));
                        liberaLC((yyvsp[-4].codigo));
                        liberaLC((yyvsp[-1].codigo));
                    }
                }
#line 1492 "sintaxis.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 125 "sintaxis.y"
                                     { tipo_decl = CONSTANTE; }
#line 1498 "sintaxis.tab.c"
    break;

  case 7: /* declarations: declarations "const" $@2 identifier_list ";"  */
#line 125 "sintaxis.y"
                                                                                                      {
                    if(errores == 0){
                        (yyval.codigo) = creaLC();
                        concatenaLC((yyval.codigo), (yyvsp[-4].codigo));
                        concatenaLC((yyval.codigo), (yyvsp[-1].codigo));
                        liberaLC((yyvsp[-4].codigo));
                        liberaLC((yyvsp[-1].codigo));
                    }
                }
#line 1512 "sintaxis.tab.c"
    break;

  case 8: /* declarations: %empty  */
#line 134 "sintaxis.y"
                            { 
                    if(errores == 0){
                        (yyval.codigo) = creaLC();
                    }
                }
#line 1522 "sintaxis.tab.c"
    break;

  case 9: /* identifier_list: asig  */
#line 141 "sintaxis.y"
                                               {
                    if(errores == 0){
                        (yyval.codigo) = (yyvsp[0].codigo);
                    }
                }
#line 1532 "sintaxis.tab.c"
    break;

  case 10: /* identifier_list: identifier_list "," asig  */
#line 146 "sintaxis.y"
                                               {
                    if(errores == 0){
                        (yyval.codigo) = creaLC();
                        concatenaLC((yyval.codigo), (yyvsp[-2].codigo));
                        concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                        liberaLC((yyvsp[-2].codigo));
                        liberaLC((yyvsp[0].codigo));
                    }
		        }
#line 1546 "sintaxis.tab.c"
    break;

  case 11: /* asig: "id"  */
#line 157 "sintaxis.y"
                     {   
                    PosicionLista p = buscaLS(l,(yyvsp[0].cadena));
                    if (p == finalLS(l)) {
                        Simbolo aux;
                        aux.nombre = (yyvsp[0].cadena);
                        aux.tipo = tipo_decl;
                        insertaLS(l,finalLS(l),aux);
                        if(errores == 0){
                            (yyval.codigo) = creaLC();
                        }   
                    } else {
                        printf("Error: identificador %s redeclarado en linea %d\n", (yyvsp[0].cadena), yylineno);
                        errores++;
                    }                                                  
                                                       
                }
#line 1567 "sintaxis.tab.c"
    break;

  case 12: /* asig: "id" "=" expression  */
#line 173 "sintaxis.y"
                                    {
                    PosicionLista p = buscaLS(l,(yyvsp[-2].cadena));
                    if (p == finalLS(l)) {
                        Simbolo aux;
                        aux.nombre = (yyvsp[-2].cadena);
                        aux.tipo = tipo_decl;
                        insertaLS(l,finalLS(l),aux);  
                        if(errores == 0){
                            (yyval.codigo) = (yyvsp[0].codigo);
                            Operacion oper;
                            oper.op = "sw";
                            oper.res = recuperaResLC((yyvsp[0].codigo));
                            char *d;
                            asprintf(&d, "_%s", (yyvsp[-2].cadena));
                            oper.arg1 = d;
                            oper.arg2 = NULL;
                            insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                            liberar_reg(oper.res);
                        }  
                    } else {
                        printf("Error: identificador %s redeclarado en linea %d\n", (yyvsp[-2].cadena), yylineno);
                        errores++;
                    }  
                }
#line 1596 "sintaxis.tab.c"
    break;

  case 13: /* statement_list: statement_list statement  */
#line 199 "sintaxis.y"
                                           {
                    if (errores == 0) {
                        (yyval.codigo) = (yyvsp[-1].codigo);
                        concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                        liberaLC((yyvsp[0].codigo));
                    }
                }
#line 1608 "sintaxis.tab.c"
    break;

  case 14: /* statement_list: %empty  */
#line 206 "sintaxis.y"
                         { 
                    if(errores == 0){ (yyval.codigo) = creaLC(); }
                }
#line 1616 "sintaxis.tab.c"
    break;

  case 15: /* statement: "id" "=" expression ";"  */
#line 211 "sintaxis.y"
                                        {
                    PosicionLista p = buscaLS(l,(yyvsp[-3].cadena));
                    if (p == finalLS(l)){
                        printf("Error: identificador %s no declarado en linea %d\n", (yyvsp[-3].cadena), yylineno);
                        errores++;
                    }else{
                        Simbolo sim = recuperaLS(l, p);
                        if (sim.tipo == CONSTANTE){
                            printf("Error en linea %d: identificador %s es constante\n", yylineno, (yyvsp[-3].cadena));
                            errores++;  
                        }
                    }
                    if (errores == 0) {
                        (yyval.codigo) = (yyvsp[-1].codigo);
                        Operacion oper;
                        oper.op = "sw";
                        oper.res = recuperaResLC((yyvsp[-1].codigo));
                        char *d;
                        asprintf(&d, "_%s", (yyvsp[-3].cadena));
                        oper.arg1 = d;
                        oper.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                        liberar_reg(oper.res);
                    }
                }
#line 1646 "sintaxis.tab.c"
    break;

  case 16: /* statement: "{" statement_list "}"  */
#line 236 "sintaxis.y"
                                         {
                    if (errores == 0){
                        (yyval.codigo) = (yyvsp[-1].codigo);
                    }
			    }
#line 1656 "sintaxis.tab.c"
    break;

  case 17: /* statement: "if" "(" expression ")" statement "else" statement  */
#line 241 "sintaxis.y"
                                                                   {
                    if (errores == 0){
                        (yyval.codigo) = (yyvsp[-4].codigo);
                        Operacion o;
                        o.op = "beqz";
                        o.res = recuperaResLC((yyvsp[-4].codigo));
                        char *etiqueta1 = obtener_etiqueta();
                        o.arg1 = etiqueta1;
                        o.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
                        concatenaLC((yyval.codigo), (yyvsp[-2].codigo));
                        liberar_reg(o.res);
                        Operacion o1;
                        o1.op = "b";
                        char *etiqueta2 = obtener_etiqueta();
                        o1.res = etiqueta2;
                        o1.arg1 = NULL;
                        o1.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), o1);
                        Operacion o2;
                        o2.op = "etiq";
                        o2.res = etiqueta1;
                        o2.arg1 = NULL;
                        o2.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), o2);
                        concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                        Operacion o3;
                        o3.op = "etiq";
                        o3.res = etiqueta2;
                        o3.arg1 = NULL;
                        o3.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), o3);
                        liberaLC((yyvsp[-2].codigo));
                        liberaLC((yyvsp[0].codigo));
                    }
			    }
#line 1697 "sintaxis.tab.c"
    break;

  case 18: /* statement: "if" "(" expression ")" statement  */
#line 277 "sintaxis.y"
                                                                            {
                    if (errores == 0){
                        (yyval.codigo) = (yyvsp[-2].codigo);
                        char *etiqueta1 = obtener_etiqueta();
                        Operacion o;
                        o.op = "beqz";
                        o.res = recuperaResLC((yyvsp[-2].codigo));
                        o.arg1 = etiqueta1;
                        o.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
                        concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                        liberar_reg(o.res);
                        liberaLC((yyvsp[0].codigo));
                        Operacion o1;
                        o1.op = "etiq";
                        o1.res = etiqueta1;
                        o1.arg1 = NULL;
                        o1.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), o1);
                    }

				}
#line 1724 "sintaxis.tab.c"
    break;

  case 19: /* statement: "while" "(" expression ")" statement  */
#line 299 "sintaxis.y"
                                                                            {
                    if (errores == 0){
                        (yyval.codigo) = creaLC();
                        char * etiqueta1 = obtener_etiqueta();
                        Operacion o;
                        o.op = "etiq";
                        o.res = etiqueta1;
                        o.arg1 = NULL;
                        o.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
                        concatenaLC((yyval.codigo), (yyvsp[-2].codigo));
                        Operacion o1;
                        o1.op = "beqz";
                        o1.res = recuperaResLC((yyvsp[-2].codigo));
                        char *etiqueta2 = obtener_etiqueta();
                        o1.arg1 = etiqueta2;
                        o1.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), o1);
                        concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                        Operacion o2;
                        o2.op = "b";
                        o2.res = etiqueta1;
                        o2.arg1 = NULL;
                        o2.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), o2);
                        Operacion o3;
                        o3.op = "etiq";
                        o3.res = etiqueta2;
                        o3.arg1 = NULL;
                        o3.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), o3);
                        liberaLC((yyvsp[-2].codigo));
                        liberaLC((yyvsp[0].codigo));
                        liberar_reg(o1.res);
                    }
				}
#line 1765 "sintaxis.tab.c"
    break;

  case 20: /* statement: "print" print_list ";"  */
#line 335 "sintaxis.y"
                                       { 
			        if (errores == 0){
				        (yyval.codigo) = (yyvsp[-1].codigo);
				    }
			    }
#line 1775 "sintaxis.tab.c"
    break;

  case 21: /* statement: "read" read_list ";"  */
#line 340 "sintaxis.y"
                                     { 
			        if (errores == 0){
				        (yyval.codigo) = (yyvsp[-1].codigo);
				    } 
                }
#line 1785 "sintaxis.tab.c"
    break;

  case 22: /* statement: error ";"  */
#line 345 "sintaxis.y"
                            { (yyval.codigo) = creaLC(); }
#line 1791 "sintaxis.tab.c"
    break;

  case 23: /* print_list: print_item  */
#line 348 "sintaxis.y"
                             { 
                    if (errores == 0){
                        (yyval.codigo) = (yyvsp[0].codigo); 
                    }
		        }
#line 1801 "sintaxis.tab.c"
    break;

  case 24: /* print_list: print_list "," print_item  */
#line 353 "sintaxis.y"
                                            {
                    if (errores == 0) { 
                        (yyval.codigo) = (yyvsp[-2].codigo);
                        concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                        liberaLC((yyvsp[0].codigo)); 
                    }
                }
#line 1813 "sintaxis.tab.c"
    break;

  case 25: /* print_item: expression  */
#line 362 "sintaxis.y"
                                 { 
		            if (errores == 0 ){                                           
                        (yyval.codigo) = (yyvsp[0].codigo);
                        Operacion oper;
                        oper.op = "move";
                        oper.res = "$a0";
                        oper.arg1 = recuperaResLC((yyvsp[0].codigo));
                        oper.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                        liberar_reg(oper.arg1);
                        Operacion oper1;
                        oper1.op = "li";
                        oper1.res = "$v0";
                        oper1.arg1 = "1";
                        oper1.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper1);
                        Operacion oper2;
                        oper2.op = "syscall";
                        oper2.arg1 = NULL;
                        oper2.arg2 = NULL;
                        oper2.res = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper2);
		            }
		        }
#line 1842 "sintaxis.tab.c"
    break;

  case 26: /* print_item: "string"  */
#line 386 "sintaxis.y"
                      {
                    if (errores == 0){
                        Simbolo aux;
                        aux.nombre = (yyvsp[0].cadena);
                        aux.tipo = CADENA;
                        aux.valor = contador_cadenas;
                        insertaLS(l, finalLS(l), aux);
                        (yyval.codigo) = creaLC();
                        Operacion oper;
                        oper.op = "li";
                        oper.res = "$v0";
                        oper.arg1 = "4";
                        oper.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                        oper.op = "la";
                        oper.res = "$a0";
                        char *s;
                        asprintf(&s, "$str%d", contador_cadenas++);
                        oper.arg1 = s;
                        oper.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                        oper.op = "syscall";
                        oper.res = oper.arg1 = oper.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                    }
		        }
#line 1873 "sintaxis.tab.c"
    break;

  case 27: /* read_list: "id"  */
#line 414 "sintaxis.y"
                     {
                    PosicionLista p = buscaLS(l,(yyvsp[0].cadena));
                    if (p == finalLS(l)){
                        printf("Error: identificador %s no declarado en linea %d\n", (yyvsp[0].cadena), yylineno);
                        errores++;
                    }else{

                        Simbolo sim = recuperaLS(l, p);
                        if (sim.tipo == CONSTANTE){
                            printf("Error: identificador %s es constanteen linea %d\n",(yyvsp[0].cadena), yylineno);
                            errores++;  
                        }
                    }
                    if (errores == 0){
                        (yyval.codigo) = creaLC();
                        Operacion oper;
                        oper.op = "li";
                        oper.res = "$v0";
                        oper.arg1 = "5";
                        oper.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                        Operacion oper1;
                        oper1.op = "syscall";
                        oper1.res = NULL;
                        oper1.arg1 =NULL;
                        oper1.arg2  =NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper1);
                        Operacion oper2;
                        oper2.op = "sw";
                        oper2.res = "$v0";
                        char *dir;
                        asprintf(&dir, "_%s", (yyvsp[0].cadena));
                        oper2.arg1 = dir;
                        oper2.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper2);			
                    }  
                    
                }
#line 1916 "sintaxis.tab.c"
    break;

  case 28: /* read_list: read_list "," "id"  */
#line 452 "sintaxis.y"
                                   {
                    PosicionLista p = buscaLS(l,(yyvsp[0].cadena));
                    if (p == finalLS(l)){
                        printf("Error: identificador %s no declarado en linea %d\n", (yyvsp[0].cadena), yylineno);
                        errores++;
                    }else{
			            Simbolo sim = recuperaLS(l, p);
			            if (sim.tipo == CONSTANTE){
			                printf("Error en linea %d: identificador %s es constante\n", yylineno, (yyvsp[0].cadena));
                            errores++;  
				        }
			        }
                    if (errores == 0){
                        (yyval.codigo) = (yyvsp[-2].codigo);
                        Operacion oper;
                        oper.op = "li";
                        oper.res = "$v0";
                        oper.arg1 = "5";
                        oper.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                        Operacion oper1;
                        oper1.op = "syscall";
                        oper1.res = NULL;
                        oper1.arg1 =NULL;
                        oper1.arg2  =NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper1);
                        Operacion oper2;
                        oper2.op = "sw";
                        oper2.res = "$v0";
                        char *dir;
                        asprintf(&dir, "_%s", (yyvsp[0].cadena));
                        oper2.arg1 = dir;
                        oper2.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper2);			
                    }  
                }
#line 1957 "sintaxis.tab.c"
    break;

  case 29: /* expression: expression "+" expression  */
#line 490 "sintaxis.y"
                                                                            {
                    if (errores == 0){
                        (yyval.codigo) = (yyvsp[-2].codigo);
                        concatenaLC((yyval.codigo),(yyvsp[0].codigo));
                        Operacion oper;
                        oper.op = "add";
                        oper.res = recuperaResLC((yyvsp[-2].codigo));
                        oper.arg1 = recuperaResLC((yyvsp[-2].codigo));
                        oper.arg2 = recuperaResLC((yyvsp[0].codigo));
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                        liberaLC((yyvsp[0].codigo));
                        liberar_reg(oper.arg2);
                    }
                }
#line 1976 "sintaxis.tab.c"
    break;

  case 30: /* expression: expression "-" expression  */
#line 504 "sintaxis.y"
                                                                            {
                    if (errores == 0){
                        (yyval.codigo) = (yyvsp[-2].codigo);
                        concatenaLC((yyval.codigo),(yyvsp[0].codigo));
                        Operacion oper;
                        oper.op = "sub";
                        oper.res = recuperaResLC((yyvsp[-2].codigo));
                        oper.arg1 = recuperaResLC((yyvsp[-2].codigo));
                        oper.arg2 = recuperaResLC((yyvsp[0].codigo));
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                        liberaLC((yyvsp[0].codigo));
                        liberar_reg(oper.arg2);
                    }
                }
#line 1995 "sintaxis.tab.c"
    break;

  case 31: /* expression: expression "*" expression  */
#line 518 "sintaxis.y"
                                                                            {
                    if (errores == 0){
                        (yyval.codigo) = (yyvsp[-2].codigo);
                        concatenaLC((yyval.codigo),(yyvsp[0].codigo));
                        Operacion oper;
                        oper.op = "mul";
                        oper.res = recuperaResLC((yyvsp[-2].codigo));
                        oper.arg1 = recuperaResLC((yyvsp[-2].codigo));
                        oper.arg2 = recuperaResLC((yyvsp[0].codigo));
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                        liberaLC((yyvsp[0].codigo));
                        liberar_reg(oper.arg2);
                    }
                }
#line 2014 "sintaxis.tab.c"
    break;

  case 32: /* expression: expression "/" expression  */
#line 532 "sintaxis.y"
                                                                            {
                    if (errores == 0){
                        (yyval.codigo) = (yyvsp[-2].codigo);
                        concatenaLC((yyval.codigo),(yyvsp[0].codigo));
                        Operacion oper;
                        oper.op = "div";
                        oper.res = recuperaResLC((yyvsp[-2].codigo));
                        oper.arg1 = recuperaResLC((yyvsp[-2].codigo));
                        oper.arg2 = recuperaResLC((yyvsp[0].codigo));
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                        liberaLC((yyvsp[0].codigo));
                        liberar_reg(oper.arg2);
                    }
                }
#line 2033 "sintaxis.tab.c"
    break;

  case 33: /* expression: "-" expression  */
#line 546 "sintaxis.y"
                                               { 
                    if (errores == 0) {
                        (yyval.codigo) = (yyvsp[0].codigo);
                        Operacion oper;
                        oper.op = "neg";
                        oper.res = recuperaResLC((yyvsp[0].codigo));
                        oper.arg1 = recuperaResLC((yyvsp[0].codigo));
                        oper.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
                    
                    }
		        }
#line 2050 "sintaxis.tab.c"
    break;

  case 34: /* expression: "(" expression ")"  */
#line 558 "sintaxis.y"
                                                {
                    if (errores == 0){
                        (yyval.codigo) = (yyvsp[-1].codigo);
                    }
		        }
#line 2060 "sintaxis.tab.c"
    break;

  case 35: /* expression: "id"  */
#line 563 "sintaxis.y"
                     {
                    PosicionLista p = buscaLS(l,(yyvsp[0].cadena));
                    if (p == finalLS(l)){
                        printf("Error: identificador %s no declarado en linea %d\n", (yyvsp[0].cadena), yylineno);
                        errores++;
                    }
                    // Generación de código
                    if (errores == 0) {
                        (yyval.codigo) = creaLC();
                        Operacion oper;
                        oper.op = "lw";
                        oper.res = obtener_reg();
                        char *dir;
                        asprintf(&dir, "_%s", (yyvsp[0].cadena));
                        oper.arg1 = dir;
                        oper.arg2 = NULL;
                        insertaLC((yyval.codigo),finalLC((yyval.codigo)), oper);
                        guardaResLC((yyval.codigo), oper.res);
                    }
		        }
#line 2085 "sintaxis.tab.c"
    break;

  case 36: /* expression: "numero"  */
#line 583 "sintaxis.y"
                          {
                    if (errores == 0){
                        (yyval.codigo) = creaLC();
                        Operacion oper;
                        oper.op = "li";
                        oper.res = obtener_reg();
                        oper.arg1 = (yyvsp[0].cadena);
                        oper.arg2 = NULL;
                        insertaLC((yyval.codigo),finalLC((yyval.codigo)), oper);
                        guardaResLC((yyval.codigo), oper.res);
                    }
		        }
#line 2102 "sintaxis.tab.c"
    break;


#line 2106 "sintaxis.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 596 "sintaxis.y"


void yyerror(const char *msg) {
    errores++;
    printf("Error en linea %d: %s\n", yylineno, msg);    
}

char *obtener_reg(){
    char reg[4]; // $tX
    for(int i = 0; i <10; i++){
        if(regs[i] == 0){
            sprintf(reg, "$t%d",i);
            regs[i] = 1;
            return strdup(reg);
        }
    }
    printf("Error: no quedan registros libres\n");
    exit(1);
}

void liberar_reg(char *reg){
    // reg == $tX
    int i = reg[2] - '0';
    regs[i] = 0;
}

char *concatenar(char *arg1, char *arg2){
    int l = strlen(arg1) + strlen(arg2);
    char *res = (char *) malloc(l);
    sprintf(res, "%s%s",arg1,arg2);
    return res;
}

void imprimirCodigo(ListaC codigo){
    PosicionListaC p = inicioLC(codigo);
    Operacion oper;
    while(p != finalLC(codigo)){
        oper = recuperaLC(codigo,p);
        if(!strcmp(oper.op, "etiq")){
                printf("%s:\n", oper.res);
        }else{
            printf("    %s",oper.op);
            if (oper.res) printf(" %s",oper.res);
            if (oper.arg1) printf(",%s",oper.arg1);
            if (oper.arg2) printf(",%s",oper.arg2);
            printf("\n");     
        }
         p = siguienteLC(codigo,p);
    }
}

void imprimirSimbolos(){
    PosicionLista p = inicioLS(l);
    printf(".data\n");
    while(p != finalLS(l)){
        Simbolo aux = recuperaLS(l, p);
        if(aux.tipo == CADENA){
            printf("$str%d:\n   .asciiz %s\n", aux.valor, aux.nombre);
        }else{
            printf("_%s:\n      .word 0\n", aux.nombre);
        }
        p = siguienteLS(l,p);
    }
    printf(".text\n.globl main\nmain:\n");
}

char * obtener_etiqueta(){
	char etiq[32];
	sprintf(etiq, "$l%d", contadorEtiquetas++);
        return strdup(etiq);

}
