/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "texcc.y" /* yacc.c:339  */

  
  //#include "lib.h"
  #include "lib.c"
  #define TEXCC_ERROR_GENERAL 4

  void yyerror(char*);

  // Functions and global variables provided by Lex.
  int yylex();
  void texcc_lexer_free();
  extern FILE* yyin;

#line 80 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TEXSCI_BEGIN = 258,
    TEXSCI_END = 259,
    BLANKLINE = 260,
    MBOX = 261,
    IF = 262,
    PRINTTEXT = 263,
    PRINTINT = 264,
    LEFTARROW = 265,
    LOCAL = 266,
    MINUX = 267,
    PLUS = 268,
    MINUS = 269,
    MULT = 270,
    ASSIGN = 271,
    CARACFIN = 272,
    DIV = 273,
    IN = 274,
    GLOBAL = 275,
    INPUT = 276,
    OUTPUT = 277,
    EMPTY = 278,
    TYPEREAL = 279,
    OPAR = 280,
    CPAR = 281,
    TYPEINT = 282,
    EGAL = 283,
    PRINTREAL = 284,
    ID = 285,
    PHRASE = 286,
    UMINUS = 287,
    REAL = 288,
    INTEGER = 289
  };
#endif
/* Tokens.  */
#define TEXSCI_BEGIN 258
#define TEXSCI_END 259
#define BLANKLINE 260
#define MBOX 261
#define IF 262
#define PRINTTEXT 263
#define PRINTINT 264
#define LEFTARROW 265
#define LOCAL 266
#define MINUX 267
#define PLUS 268
#define MINUS 269
#define MULT 270
#define ASSIGN 271
#define CARACFIN 272
#define DIV 273
#define IN 274
#define GLOBAL 275
#define INPUT 276
#define OUTPUT 277
#define EMPTY 278
#define TYPEREAL 279
#define OPAR 280
#define CPAR 281
#define TYPEINT 282
#define EGAL 283
#define PRINTREAL 284
#define ID 285
#define PHRASE 286
#define UMINUS 287
#define REAL 288
#define INTEGER 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "texcc.y" /* yacc.c:355  */

    long int value;
    char *name;
    float valuefloat;
    struct {
        struct symbol * ptr;
    } exprval;

#line 197 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 214 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   148

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  35
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    37,     2,     2,     2,
      39,    40,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    42,    42,    43,    47,    52,    57,    65,    66,    70,
      71,    72,    73,    77,    78,    82,    88,    94,    98,    99,
     103,   112,   123,   139,   155,   166,   186,   193,   200,   218,
     236,   248,   265,   282,   292,   296
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TEXSCI_BEGIN", "TEXSCI_END",
  "BLANKLINE", "MBOX", "IF", "PRINTTEXT", "PRINTINT", "LEFTARROW", "LOCAL",
  "MINUX", "PLUS", "MINUS", "MULT", "ASSIGN", "CARACFIN", "DIV", "IN",
  "GLOBAL", "INPUT", "OUTPUT", "EMPTY", "TYPEREAL", "OPAR", "CPAR",
  "TYPEINT", "EGAL", "PRINTREAL", "ID", "PHRASE", "UMINUS", "REAL",
  "INTEGER", "'{'", "'}'", "'$'", "','", "'('", "')'", "$accept",
  "algorithm_list", "algorithm", "typeVariable_list", "typeVariable",
  "list_ID", "declarationID", "commandes_list", "commande", "condition",
  "expr", YY_NULLPTR
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
     285,   286,   287,   288,   289,   123,   125,    36,    44,    40,
      41
};
# endif

#define YYPACT_NINF -42

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-42)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      20,    28,    49,   -42,     4,   -42,   -42,    43,    45,    -2,
      46,    47,    50,    51,    48,   -42,   -42,    52,    16,    -1,
     -42,    53,    54,    55,    56,     3,   -42,    59,    60,    70,
     -42,   -42,   -12,   -12,   -12,   -12,     0,    66,    61,    18,
      11,   -42,    64,   -23,   -42,    -9,    37,    40,   -42,    11,
      63,    57,    62,    65,    11,   -42,   -42,   -42,     6,    24,
      67,   -12,    69,    71,    72,    58,     3,    73,    74,    75,
     -42,    11,    11,    11,    11,    82,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,     2,    78,   -18,    25,    39,    39,   -42,
     -42,   -42,   -42,    76,    77,    79,    80,    81,    44,    83,
      84,    85,    86,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    89,   102,   103,   104,   105,   -42,   -42,
     -42,   -42,   -42
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     0,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     5,     0,     0,     0,
      19,     0,     0,     0,     0,     0,     7,     0,     0,     0,
       4,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,     0,     0,    14,     0,     0,     0,     6,     0,
       0,     0,     0,     0,     0,    33,    35,    34,     0,     0,
       0,     0,     0,     0,     0,    27,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,    16,    15,     9,    13,
      10,    11,    12,     0,     0,     0,     0,    28,    29,    31,
      32,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,    22,
      21,    23,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -42,   -42,   113,   -42,    88,    27,    87,   -24,   -19,   -42,
     -41
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    14,    15,    43,    44,    19,    20,    38,
      58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,    36,    16,    30,    48,    17,    17,    17,    65,    17,
      17,    41,    94,    70,    60,    61,    95,    31,    42,    71,
      72,    73,    28,     1,    74,    54,    51,    52,    62,    61,
      87,    88,    89,    90,     7,    18,    18,    18,    92,    18,
      18,    55,    83,    75,    56,    57,    29,    53,    76,     5,
       9,    77,     1,    25,    73,    96,    10,    74,    97,    10,
      45,    46,    47,     4,    31,    11,    12,    13,    11,    12,
      13,    71,    72,    73,    63,    61,    74,    64,    61,     8,
      40,    21,    22,    59,   103,    23,    24,    27,     0,    37,
      32,    33,    34,    35,    49,    39,    67,    50,    66,    91,
       0,    68,    26,    78,    69,    80,   118,    81,    82,    93,
      84,    85,    86,    98,    99,     6,   100,   101,   102,   119,
     120,   121,   122,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79
};

static const yytype_int8 yycheck[] =
{
      19,    25,     4,     4,     4,     7,     7,     7,    49,     7,
       7,    23,    30,    54,    37,    38,    34,    36,    30,    13,
      14,    15,     6,     3,    18,    14,     8,     9,    37,    38,
      71,    72,    73,    74,    30,    37,    37,    37,    36,    37,
      37,    30,    66,    37,    33,    34,    30,    29,    24,     0,
       5,    27,     3,     5,    15,    30,    11,    18,    33,    11,
      33,    34,    35,    35,    83,    20,    21,    22,    20,    21,
      22,    13,    14,    15,    37,    38,    18,    37,    38,    36,
      10,    35,    35,    19,    40,    35,    35,    35,    -1,    30,
      37,    37,    37,    37,    28,    35,    39,    36,    35,    17,
      -1,    39,    14,    36,    39,    36,    17,    36,    36,    31,
      37,    37,    37,    37,    37,     2,    37,    37,    37,    17,
      17,    17,    17,    40,    40,    40,    40,    36,    36,    36,
      36,    36,    -1,    37,    37,    37,    37,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    42,    43,    35,     0,    43,    30,    36,     5,
      11,    20,    21,    22,    44,    45,     4,     7,    37,    48,
      49,    35,    35,    35,    35,     5,    45,    35,     6,    30,
       4,    49,    37,    37,    37,    37,    48,    30,    50,    35,
      10,    23,    30,    46,    47,    46,    46,    46,     4,    28,
      36,     8,     9,    29,    14,    30,    33,    34,    51,    19,
      37,    38,    37,    37,    37,    51,    35,    39,    39,    39,
      51,    13,    14,    15,    18,    37,    24,    27,    36,    47,
      36,    36,    36,    48,    37,    37,    37,    51,    51,    51,
      51,    17,    36,    31,    30,    34,    30,    33,    37,    37,
      37,    37,    37,    40,    40,    40,    40,    40,    36,    36,
      36,    36,    36,    37,    37,    37,    37,    37,    17,    17,
      17,    17,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    43,    44,    44,    45,
      45,    45,    45,    46,    46,    47,    47,    47,    48,    48,
      49,    49,    49,    49,    49,    49,    49,    50,    51,    51,
      51,    51,    51,    51,    51,    51
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     7,     6,     8,     2,     1,     6,
       6,     6,     6,     3,     1,     3,     3,     1,     2,     1,
      12,    12,    12,    12,    12,     6,     7,     3,     3,     3,
       2,     3,     3,     1,     1,     1
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
        case 4:
#line 48 "texcc.y" /* yacc.c:1646  */
    {
      fprintf(stderr, "[texcc] info: algorithm \"%s\" parsed\n", (yyvsp[-4].name));
      free((yyvsp[-4].name));
    }
#line 1371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 53 "texcc.y" /* yacc.c:1646  */
    {
      fprintf(stderr, "[texcc] info: algorithm \"%s\" parsed\n", (yyvsp[-3].name));
      free((yyvsp[-3].name));
    }
#line 1380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 58 "texcc.y" /* yacc.c:1646  */
    {
      fprintf(stderr, "[texcc] info: algorithm \"%s\" parsed\n", (yyvsp[-5].name));
      free((yyvsp[-5].name));
    }
#line 1389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 83 "texcc.y" /* yacc.c:1646  */
    {
      struct symbol * id = symtable_get(SYMTAB,(yyvsp[-2].name));
      if ( id == NULL )
          id = symtable_put(SYMTAB,(yyvsp[-2].name));
    }
#line 1399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 89 "texcc.y" /* yacc.c:1646  */
    {
      struct symbol * id = symtable_get(SYMTAB,(yyvsp[-2].name));
      if ( id == NULL )
          id = symtable_put_reel(SYMTAB,(yyvsp[-2].name));
    }
#line 1409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 104 "texcc.y" /* yacc.c:1646  */
    {
    struct symbol * id = symtable_get(SYMTAB,(yyvsp[-5].name));
    if ( id == NULL )
    {
        id = symtable_put_phrase(SYMTAB,(yyvsp[-5].name));
    }
    gencode(CODE,CALL_PRINT_TEXT,id,NULL,NULL);
  }
#line 1422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 113 "texcc.y" /* yacc.c:1646  */
    {
    struct symbol * id = symtable_const(SYMTAB,(yyvsp[-5].value));
    if(id->kind == CONSTANT){
      gencode(CODE,CALL_PRINT,id,NULL,NULL);
    }
    else{
      fprintf(stderr, "\nErreur: printInt(float)\n");
      exit(3);
    }
  }
#line 1437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 124 "texcc.y" /* yacc.c:1646  */
    {
    struct symbol * id = symtable_get(SYMTAB,(yyvsp[-5].name));
    if ( id == NULL )
    {
        fprintf(stderr,"\nName '%s' undeclared\n",(yyvsp[-5].name));
        exit(3);
    }
    if(id->kind == NAME){
      gencode(CODE,CALL_PRINT,id,NULL,NULL);
    }
    else{
      fprintf(stderr, "\nErreur: printInt(float)\n");
      exit(3);
    }
  }
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 140 "texcc.y" /* yacc.c:1646  */
    {
    struct symbol * id = symtable_get(SYMTAB,(yyvsp[-5].name));
    if ( id == NULL )
    {
        fprintf(stderr,"\nName '%s' undeclared\n",(yyvsp[-5].name));
        exit(3);
    }
    if(id->kind == NAMEREEL){
      gencode(CODE,CALL_PRINT,id,NULL,NULL);
    }
    else{
      fprintf(stderr, "\nErreur: printReal(int)\n");
      exit(3);
    }
  }
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 156 "texcc.y" /* yacc.c:1646  */
    {
    struct symbol * id = symtable_reel(SYMTAB,(yyvsp[-5].valuefloat));
    if(id->kind == REEL){
      gencode(CODE,CALL_PRINT,id,NULL,NULL);
    }
    else{
      fprintf(stderr, "\nErreur: printReal(int)\n");
      exit(3);
    }
  }
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 167 "texcc.y" /* yacc.c:1646  */
    {
    struct symbol * id = symtable_get(SYMTAB,(yyvsp[-4].name));
    if ( id == NULL )
    {
        fprintf(stderr,"\nName '%s' undeclared\n",(yyvsp[-4].name));
        exit(3);
    }
    else if( ((id->kind == NAMEREEL && (yyvsp[-2].exprval).ptr->kind == REEL) || (id->kind == NAMEREEL && (yyvsp[-2].exprval).ptr->kind == NAMEREEL)) ||
      ((id->kind == NAME && (yyvsp[-2].exprval).ptr->kind == CONSTANT) || (id->kind == NAME && (yyvsp[-2].exprval).ptr->kind == NAME)) ) {
    printf("\n\n%u\n", id->kind);
    printf("%u\n\n", (yyvsp[-2].exprval).ptr->kind);

      gencode(CODE,COPY,id,(yyvsp[-2].exprval).ptr,NULL);
    }
    else{
      printf("\nProblème de types\n");
      exit(3);
    }
  }
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 187 "texcc.y" /* yacc.c:1646  */
    {

  }
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 194 "texcc.y" /* yacc.c:1646  */
    {
      
    }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 201 "texcc.y" /* yacc.c:1646  */
    { 
    if( ((yyvsp[-2].exprval).ptr->kind == NAME||(yyvsp[-2].exprval).ptr->kind == CONSTANT) && ((yyvsp[0].exprval).ptr->kind == NAME||(yyvsp[0].exprval).ptr->kind == CONSTANT) ) {
      
      (yyval.exprval).ptr = newtemp(SYMTAB);
      gencode(CODE,BOP_PLUS,(yyval.exprval).ptr,(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);

    }
    else if( ((yyvsp[-2].exprval).ptr->kind == NAMEREEL||(yyvsp[-2].exprval).ptr->kind == REEL) && ((yyvsp[0].exprval).ptr->kind == NAMEREEL||(yyvsp[0].exprval).ptr->kind == REEL) ){
      (yyval.exprval).ptr = newtempreel(SYMTAB);
      gencode(CODE,BOP_PLUS,(yyval.exprval).ptr,(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);
    }
    else{
      printf("\nProblème de types\n");
      exit(3);
    }

  }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 219 "texcc.y" /* yacc.c:1646  */
    { 
    if( ((yyvsp[-2].exprval).ptr->kind == NAME||(yyvsp[-2].exprval).ptr->kind == CONSTANT) && ((yyvsp[0].exprval).ptr->kind == NAME||(yyvsp[0].exprval).ptr->kind == CONSTANT) ) {
      
      (yyval.exprval).ptr = newtemp(SYMTAB);
      gencode(CODE,BOP_MINUS,(yyval.exprval).ptr,(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);

    }
    else if( ((yyvsp[-2].exprval).ptr->kind == NAMEREEL||(yyvsp[-2].exprval).ptr->kind == REEL) && ((yyvsp[0].exprval).ptr->kind == NAMEREEL||(yyvsp[0].exprval).ptr->kind == REEL) ){
      (yyval.exprval).ptr = newtempreel(SYMTAB);
      gencode(CODE,BOP_MINUS,(yyval.exprval).ptr,(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);
    }
    else{
      printf("\nProblème de types\n");
      exit(3);
    }

  }
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 237 "texcc.y" /* yacc.c:1646  */
    { 
    if( (yyvsp[0].exprval).ptr->kind == NAME ){
      (yyval.exprval).ptr = newtemp(SYMTAB);
      gencode(CODE,UOP_MINUS,(yyval.exprval).ptr,(yyvsp[0].exprval).ptr,NULL); 
    }
    else{
      (yyval.exprval).ptr = newtempreel(SYMTAB);
      gencode(CODE,UOP_MINUS,(yyval.exprval).ptr,(yyvsp[0].exprval).ptr,NULL);
    }

  }
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 249 "texcc.y" /* yacc.c:1646  */
    { 
    if( ((yyvsp[-2].exprval).ptr->kind == NAME||(yyvsp[-2].exprval).ptr->kind == CONSTANT) && ((yyvsp[0].exprval).ptr->kind == NAME||(yyvsp[0].exprval).ptr->kind == CONSTANT) ) {
      
      (yyval.exprval).ptr = newtemp(SYMTAB);
      gencode(CODE,BOP_MULT,(yyval.exprval).ptr,(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);

    }
    else if( ((yyvsp[-2].exprval).ptr->kind == NAMEREEL||(yyvsp[-2].exprval).ptr->kind == REEL) && ((yyvsp[0].exprval).ptr->kind == NAMEREEL||(yyvsp[0].exprval).ptr->kind == REEL) ){
      (yyval.exprval).ptr = newtempreel(SYMTAB);
      gencode(CODE,BOP_MULT,(yyval.exprval).ptr,(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);
    }
    else{
      printf("\nProblème de types\n");
      exit(3);
    }
  }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 266 "texcc.y" /* yacc.c:1646  */
    {
    if( ((yyvsp[-2].exprval).ptr->kind == NAME||(yyvsp[-2].exprval).ptr->kind == CONSTANT) && ((yyvsp[0].exprval).ptr->kind == NAME||(yyvsp[0].exprval).ptr->kind == CONSTANT) ) {
      
      (yyval.exprval).ptr = newtemp(SYMTAB);
      gencode(CODE,BOP_DIV,(yyval.exprval).ptr,(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);

    }
    else if( ((yyvsp[-2].exprval).ptr->kind == NAMEREEL||(yyvsp[-2].exprval).ptr->kind == REEL) && ((yyvsp[0].exprval).ptr->kind == NAMEREEL||(yyvsp[0].exprval).ptr->kind == REEL) ){
      (yyval.exprval).ptr = newtempreel(SYMTAB);
      gencode(CODE,BOP_DIV,(yyval.exprval).ptr,(yyvsp[-2].exprval).ptr,(yyvsp[0].exprval).ptr);
    }
    else{
      printf("\nProblème de types\n");
      exit(3);
    }
  }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 283 "texcc.y" /* yacc.c:1646  */
    { 
    struct symbol * id = symtable_get(SYMTAB,(yyvsp[0].name));
    if ( id == NULL )
    {
        fprintf(stderr,"\nName '%s' undeclared\n",(yyvsp[0].name));
        exit(1);
    }
    (yyval.exprval).ptr = id;
  }
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 293 "texcc.y" /* yacc.c:1646  */
    { 
    (yyval.exprval).ptr = symtable_const(SYMTAB,(yyvsp[0].value));
  }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 297 "texcc.y" /* yacc.c:1646  */
    {
    (yyval.exprval).ptr = symtable_reel(SYMTAB,(yyvsp[0].valuefloat));
  }
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1668 "y.tab.c" /* yacc.c:1646  */
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
#line 303 "texcc.y" /* yacc.c:1906  */


void yyerror(char *s) {
  printf(" %s\n ", s);
  exit(2);
}

int main(int argc, char* argv[]) {
  SYMTAB = symtable_new();
  CODE = code_new();
  //fprintf(stderr,"\n\n\n\n\n\n\n%s %s %s\n\n\n\n\n\n\n", argv[0], argv[1], argv[2]);
  if (argc == 2) {
    if ((yyin = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "[texcc] error: unable to open file %s\n", argv[1]);
      exit(TEXCC_ERROR_GENERAL);
    }
  } else {
    fprintf(stderr, "[texcc] usage: %s input_file\n", argv[0]);
    exit(TEXCC_ERROR_GENERAL);
  }

  yyparse();
  
  symtable_dump(SYMTAB);
  symtable_dump_mips(SYMTAB);
  
  code_dump(CODE);
  code_dump_mips(CODE);
  symtable_free(SYMTAB);
  code_free(CODE);

  fclose(yyin);
  texcc_lexer_free();
  return EXIT_SUCCESS;
}
