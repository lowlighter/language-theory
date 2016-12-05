/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 6 "./server/parser.y" /* yacc.c:339  */

    //Bibliothèques
        #include <iostream>
        #include "./../server/src/Process.hpp"

        //Noms des champs
            const string Process::RESULT = "result";
            const string Process::RESULTS = "results";
            const string Process::VARS = "vars";
            const string Process::ANSWER = "ans";
            const string Process::GRAPH = "graph";
            const string Process::MASTER = "master";
            const string Process::TABLE = "table";
            const string Process::ERROR = "error";
            const string Process::XS = "x";
            const string Process::YS = "y";
            const string Process::PLOTTED = "plotted";
        //Mots réservés
            vector<string> Process::RESERVED = {"pi", "sin", "cos", "tan", "prime", "sqrt", "log", "ln", "exp", "abs", "plot", "update", "e", "true", "false"} ;
        //Initialisation diverse
            map<string, Process*> Process::processes, Process::statements;
            stack<Process*> Process::declared;

    //Namespace
        using namespace std;
        using json = nlohmann::json;

    //Constantes
        const int NEG = -1 ;
        const int POS = +1 ;
        const double C_PI = 3.14159;
        const double C_EXP_E = 2.71828;
        const double C_TRUE = 1;
        const double C_FALSE = 0;
        const int DEFAULT_START = -10 ;
        const int DEFAULT_END = +10 ;
        const int DEFAULT_STEP = +1 ;

    //Fonctions lexer/bison
        int yylex();
        void yyerror(char const* msg) {  }

    //Raccourcis
        Process* current() { return Process::current() ; }
        void eval() { current()->eval() ; current()->jresult(); }
    //Processus principal
        auto master = new Process(Process::MASTER) ;
        int token = 0, plot = 0, table = 0, plots = 1, stmt = 0;
        string update_id;

#line 117 "./local/parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
#ifndef YY_YY_LOCAL_PARSER_HPP_INCLUDED
# define YY_YY_LOCAL_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 3 "./server/parser.y" /* yacc.c:355  */

  #include <string>

#line 151 "./local/parser.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    PI = 259,
    EXP_E = 260,
    VARIABLE = 261,
    FUNCTION = 262,
    FUNCTION_R = 263,
    FROM = 264,
    TO = 265,
    STEP = 266,
    IF = 267,
    THEN = 268,
    ELSE = 269,
    TRUE = 270,
    FALSE = 271,
    UPDATE = 272,
    PLOT = 273,
    SQRT = 274,
    SIN = 275,
    COS = 276,
    TAN = 277,
    LOG = 278,
    LN = 279,
    EXP = 280,
    ABS = 281,
    POWER = 282,
    PRM = 283,
    EOL = 284,
    EOLR = 285,
    SYNTAX_ERROR = 286,
    QM = 287,
    DP = 288,
    EQU = 289,
    PLS = 290,
    MIN = 291,
    MUL = 292,
    DIV = 293,
    MOD = 294,
    POW = 295,
    FAC = 296,
    SIGN = 297,
    LT = 298,
    GT = 299,
    GTE = 300,
    LTE = 301,
    EEQU = 302,
    DIFF = 303,
    AND = 304,
    OR = 305,
    RULE = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 58 "./server/parser.y" /* yacc.c:355  */

    double dbl;
    std::string *str;

#line 220 "./local/parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LOCAL_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 235 "./local/parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   546

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      52,    53,     2,     2,    54,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    99,    99,   100,   101,   102,   108,   110,   111,   112,
     113,   115,   116,   118,   120,   122,   123,   124,   125,   126,
     128,   129,   131,   132,   133,   134,   135,   136,   137,   138,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     151,   153,   158,   159,   158,   165,   171,   173,   180,   182,
     187,   192,   193,   198,   199,   200,   205,   208,   213,   218,
     223,   224
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "PI", "EXP_E", "VARIABLE",
  "FUNCTION", "FUNCTION_R", "FROM", "TO", "STEP", "IF", "THEN", "ELSE",
  "TRUE", "FALSE", "UPDATE", "PLOT", "SQRT", "SIN", "COS", "TAN", "LOG",
  "LN", "EXP", "ABS", "POWER", "PRM", "EOL", "EOLR", "SYNTAX_ERROR", "QM",
  "DP", "EQU", "PLS", "MIN", "MUL", "DIV", "MOD", "POW", "FAC", "SIGN",
  "LT", "GT", "GTE", "LTE", "EEQU", "DIFF", "AND", "OR", "RULE", "'('",
  "')'", "','", "'['", "']'", "$accept", "line", "expr", "ternary", "$@1",
  "$@2", "decl", "numr", "numrs", "plot", "plot_decl", "plot_func",
  "plot_range", "range", "range_from", "range_to", "range_step", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    40,    41,    44,    91,    93
};
# endif

#define YYPACT_NINF -107

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-107)))

#define YYTABLE_NINF -44

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -107,    49,  -107,  -107,  -107,  -107,  -107,   -28,  -107,  -107,
     -48,   -43,   -39,   -27,   -26,   -25,   -24,    -8,    -6,    -5,
      -1,     6,   101,   101,   101,   133,  -107,    25,  -107,  -107,
    -107,  -107,   101,     1,    54,    55,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,    10,    95,    95,   255,
    -107,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,    31,   101,   155,    26,
     101,    27,  -107,    24,   -42,  -107,   274,   293,   312,   331,
     350,   369,   388,   407,   215,   426,    28,  -107,   496,   496,
      47,    47,    47,    47,    95,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,   101,   177,  -107,  -107,   235,  -107,    55,
    -107,     2,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,   101,  -107,   482,  -107,   101,  -107,  -107,  -107,    29,
     445,    56,   111,  -107,  -107,   101,   101,  -107,  -107,   464,
     193,  -107
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    41,    46,     7,     8,    47,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,    40,     0,    48,    13,
      14,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    47,    11,    12,    42,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,    57,     0,     0,    51,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,     0,     6,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    25,    24,    26,
      27,    28,    29,     0,    42,     5,    45,    42,    49,     0,
      54,     0,    55,    30,    32,    31,    33,    35,    34,    36,
      37,     0,    38,    42,     4,     0,    58,    52,    53,     0,
      42,     0,    42,    56,    39,     0,     0,    60,    59,    44,
      42,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -107,  -107,   -22,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,  -106,  -107,   -13,  -107,  -107,  -107
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,    26,    66,   131,    27,    28,    29,    30,
      31,    75,   112,    71,    72,   126,   138
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,    48,    49,   127,    34,   128,    32,    69,    74,    35,
      68,   110,   111,    36,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    33,    37,    38,    39,    40,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    41,   104,    42,    43,   107,     2,
       3,    44,     4,     5,     6,     7,    70,    70,    45,    67,
      73,    74,    86,   103,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   109,   106,
     108,   123,   133,    70,    22,    23,    55,    56,    57,   135,
      58,    59,    60,    61,    62,    63,    64,    65,   129,   130,
       0,    24,     3,   132,     4,     5,     6,    46,     0,     0,
       0,     0,     0,   139,   140,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,     0,     0,     0,     0,     0,    22,    23,    58,    59,
      60,    61,    62,    63,    64,    65,    51,    52,    53,    54,
      55,    56,    57,    24,    58,    59,    60,    61,    62,    63,
      64,    65,    50,     0,     0,   136,     0,   137,    51,    52,
      53,    54,    55,    56,    57,     0,    58,    59,    60,    61,
      62,    63,    64,    65,   105,     0,     0,     0,     0,     0,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,   124,     0,     0,     0,
       0,     0,    51,    52,    53,    54,    55,    56,    57,     0,
      58,    59,    60,    61,    62,    63,    64,    65,    51,    52,
      53,    54,    55,    56,    57,     0,    58,    59,    60,    61,
      62,    63,    64,    65,     0,     0,     0,     0,     0,   141,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,     0,     0,     0,   121,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,     0,     0,     0,   125,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,     0,     0,    87,    51,
      52,    53,    54,    55,    56,    57,     0,    58,    59,    60,
      61,    62,    63,    64,    65,     0,     0,   113,    51,    52,
      53,    54,    55,    56,    57,     0,    58,    59,    60,    61,
      62,    63,    64,    65,     0,     0,   114,    51,    52,    53,
      54,    55,    56,    57,     0,    58,    59,    60,    61,    62,
      63,    64,    65,     0,     0,   115,    51,    52,    53,    54,
      55,    56,    57,     0,    58,    59,    60,    61,    62,    63,
      64,    65,     0,     0,   116,    51,    52,    53,    54,    55,
      56,    57,     0,    58,    59,    60,    61,    62,    63,    64,
      65,     0,     0,   117,    51,    52,    53,    54,    55,    56,
      57,     0,    58,    59,    60,    61,    62,    63,    64,    65,
       0,     0,   118,    51,    52,    53,    54,    55,    56,    57,
       0,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,   119,    51,    52,    53,    54,    55,    56,    57,     0,
      58,    59,    60,    61,    62,    63,    64,    65,     0,     0,
     120,    51,    52,    53,    54,    55,    56,    57,     0,    58,
      59,    60,    61,    62,    63,    64,    65,     0,     0,   122,
      51,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,   -42,     0,   134,    51,
      52,    53,    54,    55,    56,    57,     0,    58,    59,    60,
      61,    62,    63,    64,    65,   -43,     0,    51,    52,    53,
      54,    55,    56,    57,     0,    58,    59,    60,    61,    62,
      63,    64,    65,    53,    54,    55,    56,    57,     0,    58,
      59,    60,    61,    62,    63,    64,    65
};

static const yytype_int16 yycheck[] =
{
      22,    23,    24,   109,    52,   111,    34,     6,     6,    52,
      32,    53,    54,    52,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    52,    52,    52,    52,    52,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    52,    67,    52,    52,    70,     0,
       1,    52,     3,     4,     5,     6,    55,    55,    52,    34,
       6,     6,    52,    32,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    54,    53,
      53,   103,    53,    55,    35,    36,    39,    40,    41,    33,
      43,    44,    45,    46,    47,    48,    49,    50,   111,   121,
      -1,    52,     1,   125,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,   135,   136,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    43,    44,
      45,    46,    47,    48,    49,    50,    35,    36,    37,    38,
      39,    40,    41,    52,    43,    44,    45,    46,    47,    48,
      49,    50,    29,    -1,    -1,    54,    -1,    56,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    29,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    29,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,    56,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    54,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    54,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    53,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    53,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    53,    35,    36,    37,
      38,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    53,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,    53,    35,    36,    37,    38,    39,
      40,    41,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    53,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    53,    35,    36,    37,    38,    39,    40,    41,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    53,    35,    36,    37,    38,    39,    40,    41,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      53,    35,    36,    37,    38,    39,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    -1,    53,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    32,    -1,    53,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    37,    38,    39,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    49,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,     0,     1,     3,     4,     5,     6,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    35,    36,    52,    59,    60,    63,    64,    65,
      66,    67,    34,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,     6,    59,    59,    59,
      29,    35,    36,    37,    38,    39,    40,    41,    43,    44,
      45,    46,    47,    48,    49,    50,    61,    34,    59,     6,
      55,    70,    71,     6,     6,    68,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    52,    53,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    32,    59,    29,    53,    59,    53,    54,
      53,    54,    69,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    53,    59,    29,    54,    72,    68,    68,    70,
      59,    62,    59,    53,    53,    33,    54,    56,    73,    59,
      59,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    61,    62,    60,    63,    64,    64,    65,    65,
      66,    67,    67,    68,    68,    68,    69,    70,    71,    72,
      73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     5,     5,     3,     1,     1,     1,
       1,     2,     2,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       1,     1,     0,     0,     7,     4,     1,     1,     1,     4,
       1,     3,     5,     3,     2,     2,     3,     1,     3,     3,
       1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 99 "./server/parser.y" /* yacc.c:1646  */
    { ; }
#line 1487 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 100 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(EOL, plot+table, update_id) ; update_id = "" ; table = plot = 0; eval() ;}
#line 1493 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 101 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(EOL) ; Process::close() ; current()->store(EOLR) ; eval() ; }
#line 1499 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 102 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(EQU, *(yyvsp[-3].str)) ; current()->store(EOLR) ; eval() ; }
#line 1505 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 108 "./server/parser.y" /* yacc.c:1646  */
    { (yyval.dbl) =  (yyvsp[-1].dbl); }
#line 1511 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 110 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(NUMBER, C_PI) ; }
#line 1517 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 111 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(NUMBER, C_EXP_E) ; }
#line 1523 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 112 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(NUMBER, C_TRUE) ; }
#line 1529 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 113 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(NUMBER, C_FALSE) ; }
#line 1535 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 115 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(SIGN, POS) ; }
#line 1541 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 116 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(SIGN, NEG) ; }
#line 1547 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 118 "./server/parser.y" /* yacc.c:1646  */
    { ; }
#line 1553 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 120 "./server/parser.y" /* yacc.c:1646  */
    { plot = 1 ; }
#line 1559 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 122 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(PLS) ; }
#line 1565 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 123 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(MIN) ; }
#line 1571 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 124 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(MUL) ; }
#line 1577 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 125 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(DIV) ; }
#line 1583 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 126 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(MOD) ; }
#line 1589 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 128 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(POW) ; }
#line 1595 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 129 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(FAC) ; }
#line 1601 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 131 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(LT) ;  }
#line 1607 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 132 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(GT) ;  }
#line 1613 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 133 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(LTE) ;  }
#line 1619 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 134 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(GTE) ;  }
#line 1625 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 135 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(EEQU) ;  }
#line 1631 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 136 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(DIFF) ;  }
#line 1637 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 137 "./server/parser.y" /* yacc.c:1646  */
    { current()-> store(AND) ; }
#line 1643 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 138 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(OR) ; }
#line 1649 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 140 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(SQRT) ; }
#line 1655 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 141 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(COS)  ; }
#line 1661 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 142 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(SIN)  ; }
#line 1667 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 143 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(TAN)  ; }
#line 1673 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 144 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(LN)  ; }
#line 1679 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 145 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(LOG)  ; }
#line 1685 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 146 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(EXP)  ; }
#line 1691 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 147 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(ABS)  ; }
#line 1697 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 148 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(PRM)  ; }
#line 1703 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 149 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(POW)  ; }
#line 1709 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 151 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(IF) ; current()->store(THEN, stmt) ; current()->store(ELSE, stmt+1) ; stmt+=2 ; }
#line 1715 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 153 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(SYNTAX_ERROR) ; }
#line 1721 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 158 "./server/parser.y" /* yacc.c:1646  */
    { Process::open() ;}
#line 1727 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 159 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(EOL) ; Process::close(); Process::open() ; }
#line 1733 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 160 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(EOL) ; Process::close();  }
#line 1739 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 165 "./server/parser.y" /* yacc.c:1646  */
    { Process::open(*(yyvsp[-3].str), *(yyvsp[-1].str)) ; }
#line 1745 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 171 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(NUMBER, (yyvsp[0].dbl)) ; }
#line 1751 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 173 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(VARIABLE, *(yyvsp[0].str)) ; }
#line 1757 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 180 "./server/parser.y" /* yacc.c:1646  */
    { ; }
#line 1763 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 182 "./server/parser.y" /* yacc.c:1646  */
    { table = 2 ; current()->store(FUNCTION_R, 0, *(yyvsp[-3].str)) ; }
#line 1769 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 187 "./server/parser.y" /* yacc.c:1646  */
    { plots = 1 ; }
#line 1775 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 192 "./server/parser.y" /* yacc.c:1646  */
    { ; }
#line 1781 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 193 "./server/parser.y" /* yacc.c:1646  */
    { update_id = *(yyvsp[-2].str) ; }
#line 1787 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 198 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(FUNCTION_R, plots, *(yyvsp[-2].str)) ; plots++ ; }
#line 1793 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 199 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(NUMBER, DEFAULT_START) ; current()->store(NUMBER, DEFAULT_END) ; current()->store(NUMBER, DEFAULT_STEP) ; current()->store(STEP) ; current()->store(TO) ; current()->store(FROM) ; current()->store(PLOT) ; current()->store(FUNCTION_R, plots, *(yyvsp[-1].str)) ; plots++ ; }
#line 1799 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 200 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(FUNCTION_R, plots, *(yyvsp[-1].str)) ; plots++ ; }
#line 1805 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 205 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(PLOT) ; }
#line 1811 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 208 "./server/parser.y" /* yacc.c:1646  */
    { ; }
#line 1817 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 213 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(FROM) ; }
#line 1823 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 218 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(TO) ; }
#line 1829 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 223 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(NUMBER, 0) ; current()->store(STEP) ; }
#line 1835 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 224 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(STEP) ;}
#line 1841 "./local/parser.cpp" /* yacc.c:1646  */
    break;


#line 1845 "./local/parser.cpp" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 226 "./server/parser.y" /* yacc.c:1906  */


//Définition du comportement des tokens
Process* Process::token(int& i) { switch (tokens[i]) {
    //Nombres et signes
        case NUMBER: number(i) ; break;
        case SIGN: sign(i) ; break;
    //Opérations
        case PLS: add(i); break;
        case MIN: sub(i); break;
        case MUL: mul(i); break;
        case DIV: div(i); break;
        case MOD: mod(i); break;
    //Fonctions
        case FAC: fac(i); break;
        case POW: pow(i); break;
        case SQRT: sqrt(i); break;
        case LOG: log(i); break;
        case LN: ln(i); break;
        case EXP: exp(i); break;
        case ABS: abs(i); break;
        case PRM: prm(i); break;
    //Trigonométrie
        case COS: cos(i); break;
        case SIN: sin(i); break;
        case TAN: tan(i); break;
    //Gestion des variables
        case EQU: affect(i) ; break;
        case VARIABLE: variable(i) ; break;
    //Appel de fonction
        case FUNCTION: function(i); break;
        case FUNCTION_R: function_r(i); break;
        case FROM: range_start(i); break;
        case TO: range_end(i); break;
        case STEP: range_step(i);break;
    //Affichage
        case PLOT: plot(i); break;
    //Tests logiques
        case LT: lt(i) ; break; case LTE: lte(i) ; break;
        case GT: gt(i) ; break; case GTE: gte(i) ; break;
        case EEQU: eequ(i) ; break;
        case AND: logic_and(i); break; case OR: logic_or(i); break;
    //Blocs logiques
        case IF: logic_if(i); break;
        case THEN: logic_then(i); break;
        case ELSE: logic_else(i); break;
    //Fin de ligne
        case EOL: eol(i); break ;
        case EOLR: eolr(i); break;
        case SYNTAX_ERROR: syntax_error(i); break;
    //Inconnu
        default: unknown(i) ; break;
} return this ; }
