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
        //Mots réservés
            vector<string> Process::RESERVED = {"TEST"} ;
        //Initialisation diverse
            map<string, Process*> Process::processes;
            stack<Process*> Process::declared;

    //Namespace
        using namespace std;
        using json = nlohmann::json;

    //Constantes
        const int NEG = -1 ;
        const int POS = +1 ;
        const double C_PI = 3.14159;
        const double C_EXP_E = 2.71828;

    //Fonctions lexer/bison
        int yylex();
        void yyerror(char const* msg) {  }

    //Raccourcis
        Process* current() { return Process::current() ; }
        void eval() { current()->eval() ; current()->jresult(); }
    //Processus principal
        auto master = new Process(Process::MASTER) ;
        int token = 0, plot = 0, table = 0, plots = 0;

#line 108 "./local/parser.cpp" /* yacc.c:339  */

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

#line 142 "./local/parser.cpp" /* yacc.c:355  */

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
    PLOT = 270,
    SQRT = 271,
    SIN = 272,
    COS = 273,
    LOG = 274,
    LN = 275,
    EXP = 276,
    ABS = 277,
    POWER = 278,
    EOL = 279,
    EOLR = 280,
    SYNTAX_ERROR = 281,
    EQU = 282,
    PLS = 283,
    MIN = 284,
    MUL = 285,
    DIV = 286,
    MOD = 287,
    LT = 288,
    GT = 289,
    GTE = 290,
    LTE = 291,
    EEQU = 292,
    DIFF = 293,
    AND = 294,
    OR = 295,
    POW = 296,
    SIGN = 297,
    QM = 298,
    DP = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 49 "./server/parser.y" /* yacc.c:355  */

    double dbl;
    std::string *str;

#line 204 "./local/parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LOCAL_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 219 "./local/parser.cpp" /* yacc.c:358  */

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
#define YYLAST   523

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

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
      45,    46,     2,     2,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    87,    87,    88,    89,    90,    96,    98,    99,   101,
     102,   104,   106,   107,   109,   110,   111,   112,   114,   116,
     117,   118,   119,   120,   121,   122,   123,   125,   126,   127,
     128,   129,   130,   131,   132,   134,   140,   145,   151,   153,
     154,   160,   162,   168,   171,   175,   176,   181,   184,   189,
     194,   195,   200
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "PI", "EXP_E", "VARIABLE",
  "FUNCTION", "FUNCTION_R", "FROM", "TO", "STEP", "IF", "THEN", "ELSE",
  "PLOT", "SQRT", "SIN", "COS", "LOG", "LN", "EXP", "ABS", "POWER", "EOL",
  "EOLR", "SYNTAX_ERROR", "EQU", "PLS", "MIN", "MUL", "DIV", "MOD", "LT",
  "GT", "GTE", "LTE", "EEQU", "DIFF", "AND", "OR", "POW", "SIGN", "QM",
  "DP", "'('", "')'", "','", "'['", "']'", "$accept", "line", "expr",
  "decl", "numr", "numrs", "plot", "plot_decl", "plot_func", "plot_range",
  "range", "range_from", "range_to", "range_step", YY_NULLPTR
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
     295,   296,   297,   298,   299,    40,    41,    44,    91,    93
};
# endif

#define YYPACT_NINF -35

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-35)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -35,    69,   -35,   -35,   -35,   -35,   -35,   -25,   -22,   -21,
     -20,   -19,   -18,   -16,    -6,    -4,    -3,   106,   106,   106,
     106,   187,     3,   -35,   -35,   -35,   -35,   -35,   -35,   106,
     140,    34,   106,   106,   106,   106,   106,   106,   106,   106,
      16,   -35,   -35,   275,   203,   -35,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   223,   -24,   294,    -2,    15,   -35,   313,   332,   351,
     370,   389,   408,   427,   239,   106,   -35,   106,   -35,   480,
     480,   -30,   -30,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   465,   259,   -35,   -35,   -35,   -35,    -5,   -35,
     -35,   -35,   -35,   -35,   -35,   -35,   -35,   106,   143,   106,
     -35,   -35,    17,   446,   106,   -35,   -35,   -35,   -35,   -35,
     165,   -35
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    36,    38,     7,     8,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,    11,    12,    43,    13,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,     9,    10,     0,     0,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,     0,    13,     0,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     0,    49,    14,
      15,    16,    17,    19,    20,    22,    21,    23,    24,    25,
      26,    18,     0,     0,     5,    37,    40,    42,     0,    46,
      27,    29,    28,    31,    30,    32,    33,     0,     0,     0,
       4,    45,     0,     0,     0,    50,    51,    35,    47,    34,
       0,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -35,   -35,    -1,   -35,   -35,   -35,   -35,   -35,   -34,   -35,
     -15,   -35,   -35,   -35
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    63,    22,    23,    24,    25,    26,    66,    99,
      27,    28,    78,   116
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      21,    65,    29,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    58,    59,    59,    64,    41,    42,    43,    44,
      30,    75,    95,    31,    32,    33,    34,    35,    61,    36,
      60,    67,    68,    69,    70,    71,    72,    73,    74,    37,
      65,    38,    39,    20,    97,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      64,    75,    98,   118,   111,     0,     0,     0,     0,     2,
       3,     0,     4,     5,     6,     7,   108,     0,     0,     0,
       0,     0,     0,   112,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     0,     0,     0,     0,    17,    18,     0,
       0,     0,     0,     0,     0,     0,   113,     3,   117,     4,
       5,     6,    40,   120,    19,     0,     0,    20,     0,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       0,     0,     0,     0,    17,    18,     0,     0,     0,     0,
       0,     3,     0,     4,     5,     6,    62,     0,     0,     0,
       0,    19,     0,     0,    20,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     0,     0,     0,     0,    17,    18,
       0,    46,    47,    48,    49,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    19,    59,     0,    20,     0,
     114,     0,   115,    46,    47,    48,    49,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,     0,    59,     0,
       0,    45,     0,     0,   121,    46,    47,    48,    49,     0,
      50,    51,    52,    53,    54,    55,    56,    57,    58,     0,
      59,    46,    47,    48,    49,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,     0,    59,    94,     0,     0,
      77,    46,    47,    48,    49,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,     0,    59,    46,    47,    48,
      49,     0,    50,    51,    52,    53,    54,    55,    56,    57,
      58,     0,    59,   110,     0,     0,   107,    46,    47,    48,
      49,     0,    50,    51,    52,    53,    54,    55,    56,    57,
      58,     0,    59,    46,    47,    48,    49,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,     0,    59,     0,
       0,    76,    46,    47,    48,    49,     0,    50,    51,    52,
      53,    54,    55,    56,    57,    58,     0,    59,     0,     0,
      96,    46,    47,    48,    49,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,     0,    59,     0,     0,   100,
      46,    47,    48,    49,     0,    50,    51,    52,    53,    54,
      55,    56,    57,    58,     0,    59,     0,     0,   101,    46,
      47,    48,    49,     0,    50,    51,    52,    53,    54,    55,
      56,    57,    58,     0,    59,     0,     0,   102,    46,    47,
      48,    49,     0,    50,    51,    52,    53,    54,    55,    56,
      57,    58,     0,    59,     0,     0,   103,    46,    47,    48,
      49,     0,    50,    51,    52,    53,    54,    55,    56,    57,
      58,     0,    59,     0,     0,   104,    46,    47,    48,    49,
       0,    50,    51,    52,    53,    54,    55,    56,    57,    58,
       0,    59,     0,     0,   105,    46,    47,    48,    49,     0,
      50,    51,    52,    53,    54,    55,    56,    57,    58,     0,
      59,     0,     0,   106,    46,    47,    48,    49,     0,    50,
      51,    52,    53,    54,    55,    56,    57,    58,     0,    59,
       0,     0,   119,    46,    47,    48,    49,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,     0,    59,   109,
      48,    49,     0,    50,    51,    52,    53,    54,    55,    56,
      57,    58,     0,    59
};

static const yytype_int8 yycheck[] =
{
       1,     6,    27,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    41,    43,    43,    30,    17,    18,    19,    20,
      45,    45,    46,    45,    45,    45,    45,    45,    29,    45,
      27,    32,    33,    34,    35,    36,    37,    38,    39,    45,
       6,    45,    45,    48,    46,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      75,    45,    47,    46,    98,    -1,    -1,    -1,    -1,     0,
       1,    -1,     3,     4,     5,     6,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,     1,   109,     3,
       4,     5,     6,   114,    45,    -1,    -1,    48,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    48,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      -1,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    45,    43,    -1,    48,    -1,
      47,    -1,    49,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    -1,
      -1,    24,    -1,    -1,    49,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      43,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    24,    -1,    -1,
      47,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    24,    -1,    -1,    47,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    -1,
      -1,    46,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    -1,    -1,
      46,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    -1,    -1,    46,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    43,    -1,    -1,    46,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    -1,    -1,    46,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    43,    -1,    -1,    46,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    -1,    -1,    46,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    43,    -1,    -1,    46,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      43,    -1,    -1,    46,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    43,
      -1,    -1,    46,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    44,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,     0,     1,     3,     4,     5,     6,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    28,    29,    45,
      48,    52,    53,    54,    55,    56,    57,    60,    61,    27,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
       6,    52,    52,    52,    52,    24,    28,    29,    30,    31,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    43,
      27,    52,     6,    52,    60,     6,    58,    52,    52,    52,
      52,    52,    52,    52,    52,    45,    46,    47,    62,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    24,    46,    46,    46,    47,    59,
      46,    46,    46,    46,    46,    46,    46,    47,    52,    44,
      24,    58,    60,    52,    47,    49,    63,    52,    46,    46,
      52,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    53,    54,    54,
      54,    55,    55,    56,    57,    58,    58,    59,    60,    61,
      62,    62,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     5,     5,     3,     1,     1,     2,
       2,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     4,     4,
       4,     4,     4,     4,     6,     5,     1,     4,     1,     1,
       4,     1,     4,     1,     3,     3,     2,     3,     1,     3,
       3,     3,     3
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
#line 87 "./server/parser.y" /* yacc.c:1646  */
    { ; }
#line 1455 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 88 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(EOL, plot+table) ; table = plot = 0; eval() ;}
#line 1461 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 89 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(EOL) ; Process::close() ; current()->store(EOLR) ; eval() ; }
#line 1467 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 90 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(EQU, *(yyvsp[-3].str)) ; current()->store(EOL) ; current()->store(EOLR) ; eval() ; }
#line 1473 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 96 "./server/parser.y" /* yacc.c:1646  */
    { (yyval.dbl) =  (yyvsp[-1].dbl); }
#line 1479 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 98 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(NUMBER, C_PI) ; }
#line 1485 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 99 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(NUMBER, C_EXP_E) ; }
#line 1491 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 101 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(SIGN, POS) ; }
#line 1497 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 102 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(SIGN, NEG) ; }
#line 1503 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 104 "./server/parser.y" /* yacc.c:1646  */
    { ; }
#line 1509 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 106 "./server/parser.y" /* yacc.c:1646  */
    { plot = 1 ;}
#line 1515 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 107 "./server/parser.y" /* yacc.c:1646  */
    { ; }
#line 1521 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 109 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(PLS) ; }
#line 1527 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 110 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(MIN) ; }
#line 1533 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 111 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(MUL) ; }
#line 1539 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 112 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(DIV) ; }
#line 1545 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 114 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(POW) ; }
#line 1551 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 116 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(LT) ;  }
#line 1557 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 117 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(GT) ;  }
#line 1563 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 118 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(LTE) ;  }
#line 1569 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 119 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(GTE) ;  }
#line 1575 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 120 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(EEQU) ;  }
#line 1581 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 121 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(DIFF) ;  }
#line 1587 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 122 "./server/parser.y" /* yacc.c:1646  */
    { current()-> store(AND) ; }
#line 1593 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 123 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(OR) ; }
#line 1599 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 125 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(SQRT) ; }
#line 1605 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 126 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(COS)  ; }
#line 1611 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 127 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(SIN)  ; }
#line 1617 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 128 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(LN)  ; }
#line 1623 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 129 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(LOG)  ; }
#line 1629 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 130 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(EXP)  ; }
#line 1635 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 131 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(ABS)  ; }
#line 1641 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 132 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(POW)  ; }
#line 1647 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 134 "./server/parser.y" /* yacc.c:1646  */
    {
                                              current()->store(THEN)  ;
                                              current()->store(ELSE)  ;
                                              current()->store(IF)    ;
                                            }
#line 1657 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 140 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(SYNTAX_ERROR) ; }
#line 1663 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 145 "./server/parser.y" /* yacc.c:1646  */
    { Process::open(*(yyvsp[-3].str), *(yyvsp[-1].str)) ; }
#line 1669 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 151 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(NUMBER, (yyvsp[0].dbl)) ; }
#line 1675 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 153 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(VARIABLE, *(yyvsp[0].str)) ; }
#line 1681 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 154 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(FUNCTION, *(yyvsp[-3].str)) ; }
#line 1687 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 160 "./server/parser.y" /* yacc.c:1646  */
    { ; }
#line 1693 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 162 "./server/parser.y" /* yacc.c:1646  */
    { table = 2 ; current()->store(FUNCTION_R, *(yyvsp[-3].str)) ; }
#line 1699 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 168 "./server/parser.y" /* yacc.c:1646  */
    { plots = 1 ;}
#line 1705 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 171 "./server/parser.y" /* yacc.c:1646  */
    {}
#line 1711 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 175 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(FUNCTION_R, plots, *(yyvsp[-2].str)) ; plots++ ; }
#line 1717 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 176 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(FUNCTION_R, plots, *(yyvsp[-1].str)) ; plots++ ; }
#line 1723 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 181 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(PLOT) ; }
#line 1729 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 184 "./server/parser.y" /* yacc.c:1646  */
    { ; }
#line 1735 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 189 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(FROM) ; }
#line 1741 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 194 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(TO) ; }
#line 1747 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 195 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(TO) ; }
#line 1753 "./local/parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 200 "./server/parser.y" /* yacc.c:1646  */
    { current()->store(STEP) ;}
#line 1759 "./local/parser.cpp" /* yacc.c:1646  */
    break;


#line 1763 "./local/parser.cpp" /* yacc.c:1646  */
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
#line 202 "./server/parser.y" /* yacc.c:1906  */


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
    //Fonctions
        case POW: pow(i); break;
        case SQRT: sqrt(i); break;
        case LOG: log(i); break;
        case LN: ln(i); break;
        case EXP: exp(i); break;
        case ABS: abs(i); break;
    //Trigonométrie
        case COS: cos(i); break;
        case SIN: sin(i); break;
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
