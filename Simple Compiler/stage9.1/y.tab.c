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
#line 1 "abstree.y" /* yacc.c:339  */
 
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "abstree.h"
    #include "symboltable.h"
    #include "symboltable.c"
    #include "aa.c"
    #include "codegen.c"
    int yylex();
    void yyerror(char const *s);
    struct Tnode *root,*head;
    int result;
    FILE * fp;
    extern FILE *yyin;
    extern int yylineno;
    int declarationType ,FdeclarationType;
    struct Gsymbol *Gtemp;
    struct Lsymbol *Ltemp;
    struct ArgStruct *Argtemp1, *Argtemp2;
    int indicator = 0; //for no.of arguments passed
    // int tree_iter = 0;

#line 90 "y.tab.c" /* yacc.c:339  */

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
    NUM = 258,
    ID = 259,
    PLUS = 260,
    MUL = 261,
    DIV = 262,
    MOD = 263,
    ASGN = 264,
    READ = 265,
    WRITE = 266,
    MINUS = 267,
    NEWLINE = 268,
    LT = 269,
    GT = 270,
    DEQ = 271,
    NEQ = 272,
    ELSE = 273,
    IF = 274,
    THEN = 275,
    ENDIF = 276,
    ENDWHILE = 277,
    WHILE = 278,
    DO = 279,
    START = 280,
    END = 281,
    DECL = 282,
    ENDDECL = 283,
    T = 284,
    INT = 285,
    F = 286,
    BOOL = 287,
    LE = 288,
    GE = 289,
    NOT = 290,
    AND = 291,
    OR = 292,
    AMP = 293,
    MAIN = 294,
    RETURN = 295
  };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define PLUS 260
#define MUL 261
#define DIV 262
#define MOD 263
#define ASGN 264
#define READ 265
#define WRITE 266
#define MINUS 267
#define NEWLINE 268
#define LT 269
#define GT 270
#define DEQ 271
#define NEQ 272
#define ELSE 273
#define IF 274
#define THEN 275
#define ENDIF 276
#define ENDWHILE 277
#define WHILE 278
#define DO 279
#define START 280
#define END 281
#define DECL 282
#define ENDDECL 283
#define T 284
#define INT 285
#define F 286
#define BOOL 287
#define LE 288
#define GE 289
#define NOT 290
#define AND 291
#define OR 292
#define AMP 293
#define MAIN 294
#define RETURN 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 26 "abstree.y" /* yacc.c:355  */

    struct Tnode * nptr;

#line 214 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 229 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   389

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      44,    45,     2,     2,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    87,    98,   114,   134,   135,   137,   139,
     148,   162,   177,   186,   199,   216,   220,   225,   226,   229,
     230,   231,   234,   237,   257,   273,   294,   328,   329,   332,
     406,   410,   414,   418,   422,   426,   437,   450,   481,   488,
     493,   504,   512,   590,   630,   702,   739,   760,   770,   780,
     792,   797,   809,   821,   834,   847,   860,   873,   886,   899,
     911,   923,   935,   947,   958,   969,   980,   983,   987,  1055,
    1090,  1093,  1097
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "PLUS", "MUL", "DIV", "MOD",
  "ASGN", "READ", "WRITE", "MINUS", "NEWLINE", "LT", "GT", "DEQ", "NEQ",
  "ELSE", "IF", "THEN", "ENDIF", "ENDWHILE", "WHILE", "DO", "START", "END",
  "DECL", "ENDDECL", "T", "INT", "F", "BOOL", "LE", "GE", "NOT", "AND",
  "OR", "AMP", "MAIN", "RETURN", "';'", "'['", "']'", "'('", "')'", "','",
  "'{'", "'}'", "$accept", "program", "gdeclaration", "gdlist", "gdec",
  "vlist", "Type", "FType", "arglist", "arg", "fvlist", "fdeflist", "fdef",
  "ldeclaration", "ldlist", "ldec", "lvlist", "mainblock", "body",
  "retstmt", "slist", "stmt", "exprlist", "expr", YY_NULLPTR
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
     295,    59,    91,    93,    40,    41,    44,   123,   125
};
# endif

#define YYPACT_NINF -145

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-145)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -14,    33,    20,    62,  -145,  -145,    29,  -145,    46,  -145,
     -12,    52,    62,  -145,  -145,  -145,  -145,    94,   -27,    30,
      55,  -145,  -145,    84,   107,  -145,   117,    57,   107,    68,
    -145,  -145,     4,    23,  -145,   125,    82,    32,  -145,  -145,
     126,    87,   107,  -145,   137,   107,   114,    95,  -145,     8,
    -145,   103,    41,    33,   124,   114,  -145,   150,  -145,  -145,
     151,    92,  -145,   363,   110,   124,  -145,  -145,   -18,  -145,
    -145,    13,   127,   132,   133,   136,    43,  -145,  -145,   120,
    -145,   180,    14,    14,   182,    14,    14,    14,    14,   161,
    -145,  -145,  -145,  -145,   141,  -145,  -145,    14,    14,   237,
     158,     6,    64,    98,   111,   250,  -145,    14,    14,    74,
     145,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,  -145,   179,    14,   148,   152,   184,
     176,  -145,   191,    50,   300,  -145,   324,   328,   328,   328,
     324,    74,    74,    74,    74,    74,    74,   324,   324,    14,
     204,  -145,  -145,   363,   363,  -145,  -145,    14,   287,   157,
     345,   361,   300,  -145,   172,   363,   173,   174,  -145,   366,
    -145,  -145,   181,  -145
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     0,    15,    16,     0,     6,     0,     1,
      15,     0,     0,    27,     3,     4,     7,     9,     0,     0,
       0,    28,     2,     0,    21,     8,     0,     0,    21,     0,
      17,    18,     0,     0,    19,    12,     0,     0,    10,    23,
       0,    22,     0,    11,     0,    21,    31,     0,    24,     0,
      20,     0,     0,     0,     0,    31,    25,     0,    13,    14,
       0,     0,    32,     0,     0,     0,    26,    35,     0,    30,
      33,     0,     0,     0,     0,     0,     0,    41,    37,     0,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      40,    29,    36,    67,    68,    70,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,     0,     0,
       0,    39,     0,     0,    50,    66,    52,    54,    55,    56,
      53,    57,    59,    61,    62,    58,    60,    63,    64,     0,
       0,    44,    46,     0,     0,    69,    72,     0,     0,     0,
       0,     0,    51,    43,     0,     0,     0,     0,    45,     0,
      47,    49,     0,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,  -145,  -145,   211,  -145,    -1,  -145,   -21,   187,
    -145,  -145,   214,   168,  -145,   169,  -145,   219,   167,  -145,
    -144,   -76,  -145,   -82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     7,    18,     8,    32,    33,    34,
      41,    12,    13,    54,    61,    62,    68,    14,    64,    89,
      76,    77,   133,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      90,   100,    11,   102,   103,   104,   105,    37,    39,   160,
     161,    11,    56,     1,    25,   109,   110,    93,    94,    26,
       9,   169,    82,    80,    52,   132,   134,    19,    81,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    40,    95,   150,    96,    57,    71,   126,    97,
      17,   127,    60,    72,    73,    83,    20,    15,    98,     4,
      60,     5,    74,     4,    42,     5,    75,   158,    43,   111,
     112,   113,   114,    42,    27,   162,   115,    47,   116,   117,
     118,   119,    42,    88,    90,    90,    59,    29,    -1,    -1,
      -1,    -1,    10,    90,     5,   156,   157,   120,   121,    28,
     122,   123,    36,   111,   112,   113,   114,    -1,    -1,   128,
     115,    38,   116,   117,   118,   119,   111,   112,   113,   114,
      69,    35,     4,   115,     5,   116,   117,   118,   119,    46,
      48,   120,   121,    49,   122,   123,    23,    30,    24,    31,
      51,    53,    55,   129,   120,   121,    58,   122,   123,    63,
     111,   112,   113,   114,    66,    67,   130,   115,    78,   116,
     117,   118,   119,   111,   112,   113,   114,    44,    91,    45,
     115,    84,   116,   117,   118,   119,    85,    86,   120,   121,
      87,   122,   123,   107,    92,   108,   101,   106,   149,   151,
     135,   120,   121,   152,   122,   123,   111,   112,   113,   114,
     154,   125,   164,   115,   153,   116,   117,   118,   119,   111,
     112,   113,   114,   168,   170,   171,   115,    16,   116,   117,
     118,   119,   173,    65,   120,   121,    21,   122,   123,    50,
      70,    22,    79,     0,   155,     0,     0,   120,   121,     0,
     122,   123,   111,   112,   113,   114,     0,   159,     0,   115,
       0,   116,   117,   118,   119,   111,   112,   113,   114,     0,
       0,     0,   115,     0,   116,   117,   118,   119,     0,     0,
     120,   121,     0,   122,   123,     0,     0,     0,   124,     0,
       0,     0,     0,   120,   121,     0,   122,   123,     0,     0,
       0,   131,   111,   112,   113,   114,     0,     0,     0,   115,
       0,   116,   117,   118,   119,   111,   112,   113,   114,     0,
       0,     0,   115,     0,   116,   117,   118,   119,     0,     0,
     120,   121,     0,   122,   123,     0,     0,     0,   163,     0,
     112,   113,   114,   120,   121,     0,   122,   123,   116,   117,
     118,   119,   116,   117,   118,   119,     0,     0,     0,    71,
       0,     0,     0,     0,     0,    72,    73,   120,   121,     0,
       0,   120,   121,   165,    74,    71,   166,    71,    75,     0,
      71,    72,    73,    72,    73,     0,    72,    73,     0,     0,
      74,     0,    74,   167,    75,    74,    75,   172,     0,    75
};

static const yytype_int16 yycheck[] =
{
      76,    83,     3,    85,    86,    87,    88,    28,     4,   153,
     154,    12,     4,    27,    41,    97,    98,     3,     4,    46,
       0,   165,     9,    41,    45,   107,   108,    39,    46,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    38,    29,   126,    31,    38,     4,    42,    35,
       4,    45,    53,    10,    11,    42,     4,    28,    44,    30,
      61,    32,    19,    30,    41,    32,    23,   149,    45,     5,
       6,     7,     8,    41,    44,   157,    12,    45,    14,    15,
      16,    17,    41,    40,   160,   161,    45,     3,    14,    15,
      16,    17,    30,   169,    32,    45,    46,    33,    34,    44,
      36,    37,    45,     5,     6,     7,     8,    33,    34,    45,
      12,    43,    14,    15,    16,    17,     5,     6,     7,     8,
      28,     4,    30,    12,    32,    14,    15,    16,    17,    47,
       4,    33,    34,    46,    36,    37,    42,    30,    44,    32,
       3,    27,    47,    45,    33,    34,    43,    36,    37,    25,
       5,     6,     7,     8,     4,     4,    45,    12,    48,    14,
      15,    16,    17,     5,     6,     7,     8,    42,    48,    44,
      12,    44,    14,    15,    16,    17,    44,    44,    33,    34,
      44,    36,    37,    42,     4,    44,     4,    26,     9,    41,
      45,    33,    34,    41,    36,    37,     5,     6,     7,     8,
      24,    43,    45,    12,    20,    14,    15,    16,    17,     5,
       6,     7,     8,    41,    41,    41,    12,     6,    14,    15,
      16,    17,    41,    55,    33,    34,    12,    36,    37,    42,
      61,    12,    65,    -1,    43,    -1,    -1,    33,    34,    -1,
      36,    37,     5,     6,     7,     8,    -1,    43,    -1,    12,
      -1,    14,    15,    16,    17,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    -1,    14,    15,    16,    17,    -1,    -1,
      33,    34,    -1,    36,    37,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    -1,    -1,
      -1,    41,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    14,    15,    16,    17,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    -1,    14,    15,    16,    17,    -1,    -1,
      33,    34,    -1,    36,    37,    -1,    -1,    -1,    41,    -1,
       6,     7,     8,    33,    34,    -1,    36,    37,    14,    15,
      16,    17,    14,    15,    16,    17,    -1,    -1,    -1,     4,
      -1,    -1,    -1,    -1,    -1,    10,    11,    33,    34,    -1,
      -1,    33,    34,    18,    19,     4,    21,     4,    23,    -1,
       4,    10,    11,    10,    11,    -1,    10,    11,    -1,    -1,
      19,    -1,    19,    22,    23,    19,    23,    21,    -1,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    50,    51,    30,    32,    52,    53,    55,     0,
      30,    55,    60,    61,    66,    28,    53,     4,    54,    39,
       4,    61,    66,    42,    44,    41,    46,    44,    44,     3,
      30,    32,    56,    57,    58,     4,    45,    57,    43,     4,
      38,    59,    41,    45,    42,    44,    47,    45,     4,    46,
      58,     3,    57,    27,    62,    47,     4,    38,    43,    45,
      55,    63,    64,    25,    67,    62,     4,     4,    65,    28,
      64,     4,    10,    11,    19,    23,    69,    70,    48,    67,
      41,    46,     9,    42,    44,    44,    44,    44,    40,    68,
      70,    48,     4,     3,     4,    29,    31,    35,    44,    72,
      72,     4,    72,    72,    72,    72,    26,    42,    44,    72,
      72,     5,     6,     7,     8,    12,    14,    15,    16,    17,
      33,    34,    36,    37,    41,    43,    42,    45,    45,    45,
      45,    41,    72,    71,    72,    45,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,     9,
      72,    41,    41,    20,    24,    43,    45,    46,    72,    43,
      69,    69,    72,    41,    45,    18,    21,    22,    41,    69,
      41,    41,    21,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    52,    53,    54,
      54,    54,    54,    54,    54,    55,    55,    56,    56,    57,
      57,    57,    58,    59,    59,    59,    59,    60,    60,    61,
      62,    62,    63,    63,    64,    65,    65,    66,    67,    68,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     3,     0,     1,     2,     3,     1,
       4,     4,     3,     6,     6,     1,     1,     1,     1,     1,
       3,     0,     2,     1,     2,     3,     4,     1,     2,     9,
       3,     0,     1,     2,     3,     1,     3,     8,     4,     3,
       2,     1,     4,     7,     5,     8,     5,     8,    10,     8,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     1,     1,     4,
       1,     1,     4
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
#line 76 "abstree.y" /* yacc.c:1646  */
    {
											printf("SYMBOL TABLE:\n");
				                            printSymbolTable();
				                            printf("---------------\n");
				       //                      //result = Evaluate($3);
           //                                  codegen($3);
                                            //fprintf(intermediate, "HALT\n");
                                            fclose(intermediate);
				                            printf("executed\n");
				                            exit(1);
                        }
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 87 "abstree.y" /* yacc.c:1646  */
    {

                                            printf("SYMBOL TABLE:\n");
                                            printSymbolTable();
                                            printf("---------------\n");
                                        fclose(intermediate);
                                        printf("executed\n");
                                        exit(1);
                                    }
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 98 "abstree.y" /* yacc.c:1646  */
    {
                                        intermediate = fopen("assemblycode.asm","w+");
                                        if(intermediate == NULL)
                                        {
                                            printf("Unable to locate file\n");
                                            exit(1);
                                        }
                                        fprintf(intermediate, "START\n");
                                        fprintf(intermediate, "MOV SP,%d\n",totalCount - 1);
                                        fprintf(intermediate, "MOV BP,%d\n",totalCount);
                                        fprintf(intermediate, "PUSH R0\n");
                                        fprintf(intermediate, "CALL MAIN\n");
                                        fprintf(intermediate, "HALT\n");
                                        //Ginstall("retvalue",SYMBOL_INTEGER,1,NULL);
                    
                                        }
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 114 "abstree.y" /* yacc.c:1646  */
    {
                                        // printf("IN HERE\n");
                                        intermediate = fopen("assemblycode.asm","w+");
                                        if(intermediate == NULL)
                                        {
                                            printf("Unable to locate file\n");
                                            exit(1);
                                        }
                                        fprintf(intermediate, "START\n");
                                        fprintf(intermediate, "MOV SP,%d\n",totalCount - 1);
                                        fprintf(intermediate, "MOV BP,%d\n",totalCount);
                                        fprintf(intermediate, "PUSH R0\n");
                                        fprintf(intermediate, "CALL MAIN\n");
                                        fprintf(intermediate, "HALT\n");

                                        //Ginstall("retvalue",SYMBOL_INTEGER,1,NULL);


                                     }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 134 "abstree.y" /* yacc.c:1646  */
    {}
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 135 "abstree.y" /* yacc.c:1646  */
    {}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 137 "abstree.y" /* yacc.c:1646  */
    {}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 139 "abstree.y" /* yacc.c:1646  */
    {
                            Gtemp = Glookup((yyvsp[0].nptr) -> NAME);
                            if(Gtemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            Ginstall((yyvsp[0].nptr) -> NAME,declarationType,1,NULL);
                        }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 148 "abstree.y" /* yacc.c:1646  */
    {
                            Gtemp = Glookup((yyvsp[-3].nptr) -> NAME);
                            if(Gtemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            if ( declarationType == SYMBOL_INTEGER )
                                Ginstall((yyvsp[-3].nptr) -> NAME,SYMBOL_ARRAY_INT,(yyvsp[-1].nptr) -> VALUE,NULL);
                            else if ( declarationType == SYMBOL_BOOLEAN )
                                Ginstall((yyvsp[-3].nptr) -> NAME,SYMBOL_ARRAY_BOOLEAN,(yyvsp[-1].nptr) -> VALUE,NULL);

                        }
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 162 "abstree.y" /* yacc.c:1646  */
    {
                                Gtemp = Glookup((yyvsp[-3].nptr) -> NAME);
                                if(Gtemp != NULL)
                                {
                                    printf("Re initialization of identifier\n");
                                    exit(1);
                                }
                                if ( declarationType == SYMBOL_INTEGER )
                                    Ginstall((yyvsp[-3].nptr) -> NAME,SYMBOL_FUNC_INT,-1, Arghead);
                                else if ( declarationType == SYMBOL_BOOLEAN )
                                    Ginstall((yyvsp[-3].nptr) -> NAME,SYMBOL_FUNC_BOOLEAN,-1,Arghead);

                                Arghead = NULL;
                                Argtail = NULL;
                            }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 177 "abstree.y" /* yacc.c:1646  */
    {
                            Gtemp = Glookup((yyvsp[0].nptr) -> NAME);
                            if(Gtemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            Ginstall((yyvsp[0].nptr) -> NAME,declarationType,1,NULL);
                        }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 186 "abstree.y" /* yacc.c:1646  */
    {
                                    Gtemp = Glookup((yyvsp[-3].nptr) -> NAME);
                                    if(Gtemp != NULL)
                                    {
                                        printf("Re initialization of variable\n");
                                        exit(1);
                                    }
                                    if ( declarationType == SYMBOL_INTEGER )
                                        Ginstall((yyvsp[-3].nptr) -> NAME,SYMBOL_ARRAY_INT,(yyvsp[-1].nptr) -> VALUE,NULL);
                                    else if ( declarationType == SYMBOL_BOOLEAN )
                                        Ginstall((yyvsp[-3].nptr) -> NAME,SYMBOL_ARRAY_BOOLEAN,(yyvsp[-1].nptr) -> VALUE,NULL);
                                }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 199 "abstree.y" /* yacc.c:1646  */
    {
                                        Gtemp = Glookup((yyvsp[-3].nptr) -> NAME);
                                        if(Gtemp != NULL)
                                        {
                                            printf("Re initialization of identifier\n");
                                            exit(1);
                                        }
                                        if ( declarationType == SYMBOL_INTEGER )
                                            Ginstall((yyvsp[-3].nptr) -> NAME,SYMBOL_FUNC_INT,-1, Arghead);
                                        else if ( declarationType == SYMBOL_BOOLEAN )
                                            Ginstall((yyvsp[-3].nptr) -> NAME,SYMBOL_FUNC_BOOLEAN,-1,Arghead);

                                        Arghead = NULL;
                                        Argtail = NULL;
                                    }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 216 "abstree.y" /* yacc.c:1646  */
    {
                    declarationType = SYMBOL_INTEGER;
                }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 220 "abstree.y" /* yacc.c:1646  */
    {
                    declarationType = SYMBOL_BOOLEAN;
                }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 225 "abstree.y" /* yacc.c:1646  */
    {FdeclarationType = SYMBOL_INTEGER;}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 226 "abstree.y" /* yacc.c:1646  */
    {FdeclarationType = SYMBOL_BOOLEAN;}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 229 "abstree.y" /* yacc.c:1646  */
    {}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 230 "abstree.y" /* yacc.c:1646  */
    {}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 234 "abstree.y" /* yacc.c:1646  */
    {}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 237 "abstree.y" /* yacc.c:1646  */
    {
										
										// Ltemp = Llookup($1 -> NAME);
			       //                      if(Ltemp != NULL)
			       //                      {
			       //                          printf("Re initialization of variable\n");
			       //                          exit(1);
			       //                      }
          //                               Linstall($1 -> NAME,FdeclarationType);
                                        //only installing... put in local symbol table at declaration of function
                                            Argtemp = Arglookup((yyvsp[0].nptr) -> NAME);
                                            if(Argtemp != NULL)
                                            {
                                                printf("Re initialization of variable in Arglist\n");
                                                exit(1);
                                            }

                                            //should change the declaration type
                                            ArgInstall((yyvsp[0].nptr) -> NAME,FdeclarationType); 
                                    }
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 257 "abstree.y" /* yacc.c:1646  */
    {        
                                            Argtemp = Arglookup((yyvsp[0].nptr) -> NAME);

                                            if(Argtemp != NULL)
                                            {
                                                printf("Re initialization of variable in Arglist\n");
                                                exit(1);
                                            }
										    
                                            if ( FdeclarationType == SYMBOL_INTEGER )
                                              ArgInstall((yyvsp[0].nptr) -> NAME,SYMBOL_AMP_INTEGER);

                                        else if ( FdeclarationType == SYMBOL_BOOLEAN )
                                              ArgInstall((yyvsp[0].nptr) -> NAME,SYMBOL_AMP_BOOLEAN);

                                    }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 273 "abstree.y" /* yacc.c:1646  */
    {
                                       /* Ltemp = Llookup($3 -> NAME);
			                            if(Ltemp != NULL)
			                            {
			                                printf("Re initialization of variable\n");
			                                exit(1);
			                            }
                                        Linstall($3 -> NAME,FdeclarationType);*/
                                        Argtemp = Arglookup((yyvsp[0].nptr) -> NAME);

                                        if(Argtemp != NULL)
                                        {
                                            printf("Re initialization of variable in Arglist\n");
                                            exit(1);
                                        }

                                        ArgInstall((yyvsp[0].nptr) -> NAME,FdeclarationType);


                                    }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 294 "abstree.y" /* yacc.c:1646  */
    {
                                        /*Ltemp = Llookup($4 -> NAME);
			                            if(Ltemp != NULL)
			                            {
			                                printf("Re initialization of variable\n");
			                                exit(1);
			                            }
			                            if(FdeclarationType == SYMBOL_INTEGER)
			                            {
			                            	FdeclarationType = SYMBOL_AMP_INTEGER;	
			                            }
			                            else
			                            {
			                            	FdeclarationType = SYMBOL_AMP_BOOLEAN;	
			                            }
                                        Linstall($4 -> NAME,FdeclarationType);*/

                                        Argtemp = Arglookup((yyvsp[0].nptr) -> NAME);

                                        if(Argtemp != NULL)
                                        {
                                            printf("Re initialization of variable in Arglist\n");
                                            exit(1);
                                        }
                                        if ( FdeclarationType == SYMBOL_INTEGER )
                                            ArgInstall((yyvsp[0].nptr) -> NAME,SYMBOL_AMP_INTEGER);

                                        else if ( FdeclarationType == SYMBOL_BOOLEAN )
                                            ArgInstall((yyvsp[0].nptr) -> NAME,SYMBOL_AMP_BOOLEAN);
                                    }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 328 "abstree.y" /* yacc.c:1646  */
    {}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 329 "abstree.y" /* yacc.c:1646  */
    {}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 332 "abstree.y" /* yacc.c:1646  */
    {  //code to be written
																/*validateFunction($2->NAME,decl_type,$4,$8);
                                                            	$2->Lentry = Lhead;
																codegen_function($2->NAME,$8);
																ReinitialiseLocalVariables();*/
                                                                // printf("IN fdef\n");
                                                                Gtemp = Glookup((yyvsp[-7].nptr) -> NAME);

                                                                if(Gtemp == NULL)
                                                                {
                                                                    printf("Function not declared in GST\n");
                                                                    exit(1);
                                                                }

                                                                //storing arguments in LST

                                                                Argtemp1 = Arghead;
                                                                Argtemp2 = Gtemp -> Arglist;

                                                                while((Argtemp1 !=NULL)&&(Argtemp2 != NULL))
                                                                {
                                                                    if (strcmp(Argtemp1 -> NAME,Argtemp2 -> NAME) == 0)
                                                                    {
                                                                        if (Argtemp1 -> TYPE != Argtemp2 -> TYPE)
                                                                        {
                                                                            printf("Conflict in argument types \n");
                                                                            exit(1);
                                                                        }
                                                                    }
                                                                    else
                                                                    {
                                                                        printf("Conflict in argument names \n");
                                                                        exit(1);
                                                                    }

                                                                    Argtemp1 = Argtemp1 -> NEXT;
                                                                    Argtemp2 = Argtemp2 -> NEXT;
                                                                }

                                                                if((Argtemp1 !=NULL)||(Argtemp2 != NULL))
                                                                {
                                                                    printf("Unequal number of arguments \n");
                                                                    exit(1);
                                                                }

                                                                (yyvsp[-7].nptr) -> Lentry = Lhead;

                                                                fprintf(intermediate, "F%d:\n",Gtemp -> BINDING);
                                                                fprintf(intermediate, "PUSH BP\n");
                                                                fprintf(intermediate, "MOV BP,SP\n");

                                                                Ltemp = Lhead;

                                                                while(Ltemp != NULL)
                                                                {                                                               
                                                                    fprintf(intermediate, "PUSH R0\n");
                                                                    Ltemp = Ltemp -> NEXT;
                                                                }                                                               

                                                                // printf("entering..\n");
                                                                codegen((yyvsp[-1].nptr));
                                                                // printf("entering..\n");

                                                                
                                                                //Ptr3=body and Ptr2 = lsymbol table
                                                                // Gtemp -> BINDING = TreeCreate($1,NODE_FUNC,$2 -> NAME,
                                                                                                           // 0,$4,NULL,$7,$8,NULL);
                                                                Arghead = NULL;
                                                                Argtail = NULL;
                                                                Lhead = NULL;
                                                                Ltail = NULL;
															}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 406 "abstree.y" /* yacc.c:1646  */
    {
                                            // $$ = $2;

                                        }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 410 "abstree.y" /* yacc.c:1646  */
    { 
                                        //$$ = NULL;
                                     }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 414 "abstree.y" /* yacc.c:1646  */
    {
                                // $$ = Lhead;
                            }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 418 "abstree.y" /* yacc.c:1646  */
    {
                                // $$ = Lhead;
                            }
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 422 "abstree.y" /* yacc.c:1646  */
    {
                                // $$ = Lhead;
                           }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 426 "abstree.y" /* yacc.c:1646  */
    {
                            Ltemp = Llookup((yyvsp[0].nptr) -> NAME);
                            if(Ltemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            Linstall((yyvsp[0].nptr) -> NAME,declarationType);
                            // $$ = Lhead;
                        }
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 437 "abstree.y" /* yacc.c:1646  */
    {
                            Ltemp = Llookup((yyvsp[0].nptr) -> NAME);
                            if(Ltemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            Linstall((yyvsp[0].nptr) -> NAME,declarationType);

                            // $$ = Lhead;
                        }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 451 "abstree.y" /* yacc.c:1646  */
    {
								
                                //$2 -> Lentry = Lhead;

                                // printf("IN MAIN\n");
                                fprintf(intermediate, "MAIN:\n");
                                fprintf(intermediate, "PUSH BP\n");
                                fprintf(intermediate, "MOV BP,SP\n");

                                Ltemp = Lhead;

                                while(Ltemp != NULL)
                                {                                                                
                                    fprintf(intermediate, "PUSH R0\n");
                                    Ltemp = Ltemp -> NEXT;
                                }
                                
                                printf("entering\n");
                                codegen((yyvsp[-1].nptr));
                                printf("entering\n");                              

                                
                                //ptr3=body and ptr2 = lsymbol table
                                // Gtemp -> BINDING = TreeCreate($1,NODE_FUNC,$2 -> NAME,
                                                                                // 0,$4,NULL,$7,$8,NULL);
                                Lhead = NULL;
                                Ltail = NULL;
 							}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 481 "abstree.y" /* yacc.c:1646  */
    {
                                    //printf("created\n");
									(yyval.nptr) = TreeCreate(TYPE_VOID, DEFAULT, NULL,0,NULL,(yyvsp[-2].nptr),(yyvsp[-1].nptr),NULL);
                                }
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 488 "abstree.y" /* yacc.c:1646  */
    {	
								(yyval.nptr) = TreeCreate((yyvsp[-1].nptr)->TYPE, NODE_RET,NULL,0,NULL,NULL,(yyvsp[-1].nptr),NULL);
							}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 493 "abstree.y" /* yacc.c:1646  */
    {
							head=(struct Tnode *)malloc(sizeof(struct Tnode ));
							head -> NODE = DEFAULT;
                            head -> Ptr1 = (yyvsp[-1].nptr);
                            //printf("----------------------\n");
                            //printf("%d\n",head->Ptr1->NODE);
                            head -> Ptr2 = (yyvsp[0].nptr);
                            //printf("%d\n",head->Ptr2->NODE);
                           // printf("----------------------\n");
                            (yyval.nptr)=head;
                        }
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 504 "abstree.y" /* yacc.c:1646  */
    {
                            (yyval.nptr)=(yyvsp[0].nptr);
                            //printf("-----%d----\n",$1->NODE);
                                                        
                        }
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 512 "abstree.y" /* yacc.c:1646  */
    {
                                    /*printf(" in ASGN \n");*/

                                    Ltemp = Llookup((yyvsp[-3].nptr) -> NAME);

                                    if(Ltemp != NULL)
                                    {
                                        if(Ltemp -> TYPE == SYMBOL_INTEGER)
                                        {
                                            (yyvsp[-3].nptr) -> TYPE = TYPE_INT;
                                        }
                                        else if(Ltemp -> TYPE == SYMBOL_BOOLEAN)
                                        {
                                            (yyvsp[-3].nptr) -> TYPE = TYPE_BOOL; 
                                        }

                                        
                                    }

                                    else
                                    {
                                        Argtemp = Arglookup((yyvsp[-3].nptr) -> NAME);
                                        if(Argtemp != NULL)
                                        {
                                            if((Argtemp -> TYPE == SYMBOL_INTEGER) || (Argtemp -> TYPE == SYMBOL_AMP_INTEGER))
                                            {
                                                (yyvsp[-3].nptr) -> TYPE = TYPE_INT;
                                            }
                                            else if((Argtemp -> TYPE == SYMBOL_BOOLEAN) || (Argtemp -> TYPE == SYMBOL_AMP_BOOLEAN))
                                            {
                                                (yyvsp[-3].nptr) -> TYPE = TYPE_BOOL; 
                                            }

                                            
                                        }

                                        else
                                        {

                                            Gtemp = Glookup((yyvsp[-3].nptr) -> NAME);
                                            if(Gtemp == NULL)
                                            {
                                                yyerror("Un-declared variable\n");
                                                printf("%s\n",(yyvsp[-3].nptr) -> NAME);
                                                exit(1);
                                            }
                                            else if(Gtemp -> TYPE == SYMBOL_ARRAY_BOOLEAN ||Gtemp -> TYPE == SYMBOL_ARRAY_INT )
                                            {
                                                yyerror("conflict in ID NodeType : Expected Variable . Found Array\n");
                                                printf("%s\n",(yyvsp[-3].nptr) -> NAME);
                                                exit(1);
                                            }
                                            else
                                            {   
                                                (yyvsp[-3].nptr) -> Gentry = Gtemp;
                                                if(Gtemp -> TYPE == SYMBOL_INTEGER)
                                                {
                                                    (yyvsp[-3].nptr) -> TYPE = TYPE_INT;
                                                }
                                                else if(Gtemp -> TYPE == SYMBOL_BOOLEAN)
                                                {
                                                    (yyvsp[-3].nptr) -> TYPE = TYPE_BOOL; 
                                                }
                                                
                                            }
                                        }
                                    }
                                

                                    if((yyvsp[-3].nptr)-> TYPE != (yyvsp[-1].nptr) -> TYPE)
                                    {
                                        yyerror("conflict in types in assignment\n");
                                        printf("%s\n",(yyvsp[-3].nptr) -> NAME);
                                        exit(1);
                                    } 
                                    (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_ASGN,NULL,0,NULL,(yyvsp[-3].nptr),(yyvsp[-1].nptr),NULL);  
                                }
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 590 "abstree.y" /* yacc.c:1646  */
    {
                                                /*printf(" in ASGN ARRAY\n");*/
                                                Gtemp = Glookup((yyvsp[-6].nptr) -> NAME);
                                                if(Gtemp == NULL)
                                                {
                                                    printf("Un-declared array\n");
                                                    exit(1);
                                                }
                                                else if(Gtemp -> TYPE == SYMBOL_BOOLEAN ||Gtemp -> TYPE == SYMBOL_INTEGER )
                                                {
                                                    yyerror("conflict in ID NodeType : Expected Variable , Found Array\n");
                                                    printf("%s\n",(yyvsp[-6].nptr) -> NAME);
                                                    exit(1);
                                                }
                                                else if((yyvsp[-4].nptr) -> TYPE == TYPE_BOOL)
                                                {
                                                    yyerror("Expected value , Found boolean\n");
                                                    printf("%s\n",(yyvsp[-6].nptr) -> NAME);
                                                    exit(1);
                                                }
                                                else
                                                {   
                                                    (yyvsp[-6].nptr) -> Gentry = Gtemp;
                                                    if(Gtemp -> TYPE == SYMBOL_ARRAY_INT)
                                                    {
                                                        (yyvsp[-6].nptr) -> TYPE = TYPE_INT;
                                                    }
                                                    else if(Gtemp -> TYPE == SYMBOL_ARRAY_BOOLEAN)
                                                    {
                                                        (yyvsp[-6].nptr) -> TYPE = TYPE_BOOL; 
                                                    }
                                                } 
                                                if((yyvsp[-6].nptr)-> TYPE != (yyvsp[-1].nptr) -> TYPE)
                                                {
                                                    yyerror("conflict in types in assignment\n");
                                                    printf("%s\n",(yyvsp[-6].nptr) -> NAME);
                                                    exit(1);
                                                } 
                                                (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_ARRAY_ASGN,NULL,0,NULL,(yyvsp[-6].nptr),(yyvsp[-4].nptr),(yyvsp[-1].nptr)); 
                                          }
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 630 "abstree.y" /* yacc.c:1646  */
    {
        							/*printf(" in READ \n");*/ 
                                    Ltemp = Llookup((yyvsp[-2].nptr) -> NAME);

                                    if(Ltemp != NULL)
                                    {
                                        if(Ltemp -> TYPE == SYMBOL_INTEGER)
                                        {
                                            (yyvsp[-2].nptr) -> TYPE = TYPE_INT;
                                        }
                                        else if(Ltemp -> TYPE == SYMBOL_BOOLEAN)
                                        {
                                            //$3 -> TYPE = TYPE_BOOL;
                                            yyerror("Boolean variable can not be read\n");
                                            printf("%s\n",(yyvsp[-2].nptr) -> NAME);
                                            exit(1);
                                        }
                                        
                                    }

                                    else
                                    {
                                        Argtemp = Arglookup((yyvsp[-2].nptr) -> NAME);
                                        // printf("%d\n",Argtemp -> TYPE );
                                        if(Argtemp != NULL)
                                        {
                                            if((Argtemp -> TYPE == SYMBOL_INTEGER) || (Argtemp -> TYPE == SYMBOL_AMP_INTEGER))
                                            {
                                                (yyvsp[-2].nptr) -> TYPE = TYPE_INT;
                                            }
                                            else if((Argtemp -> TYPE == SYMBOL_BOOLEAN) || (Argtemp -> TYPE == SYMBOL_AMP_BOOLEAN))
                                            {
                                                yyerror("Boolean variable can not be read\n");
                                                printf("%s\n",(yyvsp[-2].nptr) -> NAME);
                                                exit(1);
                                            }
                                        }

                                        else
                                        {
                                            Gtemp = Glookup((yyvsp[-2].nptr) -> NAME);
                                            if(Gtemp == NULL)
                                            {
                                                printf("Un-declared variable\n");
                                                exit(1);
                                            }
                                            else if(Gtemp -> TYPE == SYMBOL_ARRAY_BOOLEAN ||Gtemp -> TYPE == SYMBOL_ARRAY_INT )
                                            {
                                                yyerror("conflict in ID NodeType : Expected Array . Found Variable\n");
                                                printf("%s\n",(yyvsp[-2].nptr) -> NAME);
                                                exit(1);
                                            }
                                            else
                                            {   
                                                (yyvsp[-2].nptr) -> Gentry = Gtemp;
                                                if(Gtemp -> TYPE == SYMBOL_INTEGER)
                                                {
                                                    (yyvsp[-2].nptr) -> TYPE = TYPE_INT;
                                                }
                                                else if(Gtemp -> TYPE == SYMBOL_BOOLEAN)
                                                {
                                                    //$3 -> TYPE = TYPE_BOOL;
                                                    yyerror("Boolean variable can not be read\n");
                                                    printf("%s\n",(yyvsp[-2].nptr) -> NAME);
                                                    exit(1);
                                                }
                                            }
                                        }
                                    }
                                    (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_READ,NULL,0,NULL,NULL,(yyvsp[-2].nptr),NULL); 
        						}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 702 "abstree.y" /* yacc.c:1646  */
    {
                                                /*printf(" in READ ARR\n");*/  
                                                Gtemp = Glookup((yyvsp[-5].nptr) -> NAME);
                                                if(Gtemp == NULL)
                                                {
                                                    yyerror("Un-declared array\n");
                                                    exit(1);
                                                }
                                                else if(Gtemp -> TYPE == SYMBOL_BOOLEAN ||Gtemp -> TYPE == SYMBOL_INTEGER )
                                                {
                                                    yyerror("conflict in ID NodeType : Expected Variable , Found Array\n");
                                                    printf("%s\n",(yyvsp[-5].nptr) -> NAME);
                                                    exit(1);
                                                }          
                                                else if((yyvsp[-3].nptr) -> TYPE == TYPE_BOOL)
                                                {
                                                    yyerror("Expected value , Found boolean\n");
                                                    printf("%s\n",(yyvsp[-5].nptr) -> NAME);
                                                    exit(1);
                                                }                                          
                                                else
                                                {   
                                                    (yyvsp[-5].nptr) -> Gentry = Gtemp;
                                                    if(Gtemp -> TYPE == SYMBOL_ARRAY_INT)
                                                    {
                                                        (yyvsp[-5].nptr) -> TYPE = TYPE_INT;
                                                    }
                                                    else if(Gtemp -> TYPE == SYMBOL_ARRAY_BOOLEAN)
						                            {
						                                //$3 -> TYPE = TYPE_BOOL;
			 				            				yyerror("Boolean variable can not be read\n");
								                        printf("%s\n",(yyvsp[-5].nptr) -> NAME);
								             	        exit(1);
						                            }
                                                }
                                                (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_ARRAY_READ,NULL,0,NULL,NULL,(yyvsp[-5].nptr),(yyvsp[-3].nptr)); 
                                            }
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 739 "abstree.y" /* yacc.c:1646  */
    {
        							/*	printf(" in WRITE \n"); */
                                // printf("%d\n",$3 -> TYPE );
									if((yyvsp[-2].nptr) -> TYPE != TYPE_BOOL)
									{
        								(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_WRITE,NULL,0,NULL,NULL,(yyvsp[-2].nptr),NULL);
        							}
        							else
        							{
        								yyerror("Boolean variable can not be written\n");
		                                if((yyvsp[-2].nptr) -> Ptr1 != NULL)
		                                {
		                                	printf("%s\n",(yyvsp[-2].nptr) -> Ptr1 -> NAME);
		                         	    }
		                         	    else
		                         	    {
		                         	    	printf("%s\n",(yyvsp[-2].nptr) -> NAME);
		                         	    }
		                         	    exit(1);
		                         	}	
        						}
#line 2311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 761 "abstree.y" /* yacc.c:1646  */
    { 
        			           		/*printf(" in IF_THEN \n");*/
                                    if((yyvsp[-5].nptr) -> TYPE != TYPE_BOOL)
                                    {
                                        yyerror("Expected boolean , Found value\n");
                                        exit(1);
                                    }
        			           		(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_IF,NULL,0,NULL,(yyvsp[-5].nptr),(yyvsp[-2].nptr),NULL); 
        			           }
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 771 "abstree.y" /* yacc.c:1646  */
    { 
        							/*printf(" in IF_THEN_ELSE \n");*/
        							if((yyvsp[-7].nptr) -> TYPE != TYPE_BOOL)
                                    {
                                        yyerror("Expected boolean , Found value\n");
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_IF_ELSE,NULL,0,NULL,(yyvsp[-7].nptr),(yyvsp[-4].nptr),(yyvsp[-2].nptr)); 
        						}
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 781 "abstree.y" /* yacc.c:1646  */
    { 
        							/*printf(" in WHILE \n");*/ 
        							if((yyvsp[-5].nptr) -> TYPE != TYPE_BOOL)
                                    {
                                        yyerror("Expected boolean , Found value\n");
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_WHILE,NULL,0,NULL,(yyvsp[-5].nptr),(yyvsp[-2].nptr),NULL); 
        						}
#line 2353 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 792 "abstree.y" /* yacc.c:1646  */
    {
									printf("FIRST : %d\n",(yyvsp[0].nptr) -> NODE);
                                    tree_iter = 0;
                                    (yyval.nptr) = (yyvsp[0].nptr);
                                }
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 797 "abstree.y" /* yacc.c:1646  */
    {
										printf("SECOND : %d\n",(yyvsp[0].nptr) -> NODE);			
                                        indicator = 1;
                                        head = (struct Tnode *)malloc(sizeof(struct Tnode ));
                                        head -> NODE = NODE_EXPR;
                                        head -> Ptr1 = (yyvsp[0].nptr);
                                        (yyvsp[0].nptr) -> VALUE = ++tree_iter;
                                        head -> Ptr2 = (yyvsp[-2].nptr);
                                        (yyval.nptr) = head;
                                    }
#line 2378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 809 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("PLUS\n");*/
                                if((yyvsp[-2].nptr) -> TYPE == TYPE_INT && (yyvsp[0].nptr) -> TYPE == TYPE_INT)
                                {
                                    (yyval.nptr) = TreeCreate(TYPE_INT, NODE_PLUS , NULL,0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in PLUS\n");
                                    exit(1);
                                }
                            }
#line 2395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 821 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("MINUS\n");*/
                                
                                if((yyvsp[-2].nptr) -> TYPE == TYPE_INT && (yyvsp[0].nptr) -> TYPE == TYPE_INT)
                                {
                                    (yyval.nptr) = TreeCreate(TYPE_INT, NODE_MINUS , NULL,0 , NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MINUS\n");
                                    exit(1);
                                }
                            }
#line 2413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 834 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("MUL\n");*/
                                
                                if((yyvsp[-2].nptr) -> TYPE == TYPE_INT && (yyvsp[0].nptr) -> TYPE == TYPE_INT)
                                {
                                    (yyval.nptr) = TreeCreate(TYPE_INT, NODE_MUL , NULL,0 , NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MUL\n");
                                    exit(1);
                                }
                            }
#line 2431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 847 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("DIV\n");*/
                                
                                if((yyvsp[-2].nptr) -> TYPE == TYPE_INT && (yyvsp[0].nptr) -> TYPE == TYPE_INT)
                                {
                                    (yyval.nptr) = TreeCreate(TYPE_INT, NODE_DIV , NULL,0 , NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MUL\n");
                                    exit(1);
                                }
                            }
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 860 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("MOD\n");*/
                                
                                if((yyvsp[-2].nptr) -> TYPE == TYPE_INT && (yyvsp[0].nptr) -> TYPE == TYPE_INT)
                                {
                                    (yyval.nptr) = TreeCreate(TYPE_INT, NODE_MOD , NULL,0 , NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MUL\n");
                                    exit(1);
                                }
                            }
#line 2467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 873 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("LT\n");*/
                                
                                if((yyvsp[-2].nptr) -> TYPE == TYPE_INT && (yyvsp[0].nptr) -> TYPE == TYPE_INT)
                                {
                                    (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_LT , NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in LT\n");
                                    exit(1);
                                }
                            }
#line 2485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 886 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("LT\n");*/
                                
                                if((yyvsp[-2].nptr) -> TYPE == TYPE_INT && (yyvsp[0].nptr) -> TYPE == TYPE_INT)
                                {
                                    (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_LE , NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in LE\n");
                                    exit(1);
                                }
                            }
#line 2503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 899 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("GT\n");*/
                                if((yyvsp[-2].nptr) -> TYPE == TYPE_INT && (yyvsp[0].nptr) -> TYPE == TYPE_INT)
                                {
                                    (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_GT , NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in GT\n");
                                    exit(1);
                                }
                            }
#line 2520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 911 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("GT\n");*/
                                if((yyvsp[-2].nptr) -> TYPE == TYPE_INT && (yyvsp[0].nptr) -> TYPE == TYPE_INT)
                                {
                                    (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_GE , NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in GE\n");
                                    exit(1);
                                }
                            }
#line 2537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 923 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("DEQ\n");*/
                                if((yyvsp[-2].nptr) -> TYPE == TYPE_INT && (yyvsp[0].nptr) -> TYPE == TYPE_INT)
                                {
                                    (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_DEQ, NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in DEQ\n");
                                    exit(1);
                                }
                            }
#line 2554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 935 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("NEQ\n");*/
                                if((yyvsp[-2].nptr) -> TYPE == TYPE_INT && (yyvsp[0].nptr) -> TYPE == TYPE_INT)
                                {
                                    (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_NEQ, NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in NEQ\n");
                                    exit(1);
                                }
                            }
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 947 "abstree.y" /* yacc.c:1646  */
    {
        						if((yyvsp[-2].nptr) -> TYPE == TYPE_BOOL && (yyvsp[0].nptr) -> TYPE == TYPE_BOOL)
        						{
        							(yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_AND, NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
        						}
        						else
                                {
                                    yyerror("conflict in operand types in AND\n");
                                    exit(1);
                                }	
        					}
#line 2587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 958 "abstree.y" /* yacc.c:1646  */
    {
        						if((yyvsp[-2].nptr) -> TYPE == TYPE_BOOL && (yyvsp[0].nptr) -> TYPE == TYPE_BOOL)
        						{
        							(yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_OR, NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
        						}
        						else
                                {
                                    yyerror("conflict in operand types in OR\n");
                                    exit(1);
                                }	
        					}
#line 2603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 969 "abstree.y" /* yacc.c:1646  */
    {
        						if((yyvsp[0].nptr) -> TYPE == TYPE_BOOL)
        						{
        							(yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_NOT, NULL, 0, NULL, NULL, (yyvsp[0].nptr), NULL);
        						}
        						else
                                {
                                    yyerror("conflict in operand type in NOT\n");
                                    exit(1);
                                }	
        					}
#line 2619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 980 "abstree.y" /* yacc.c:1646  */
    {
                                (yyval.nptr) = (yyvsp[-1].nptr);
                            }
#line 2627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 983 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("NUM\n");*/
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 2636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 987 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("ID\n");*/
                                Ltemp = Llookup((yyvsp[0].nptr) -> NAME);

                                if(Ltemp != NULL)
                                {
                                    if(Ltemp -> TYPE == SYMBOL_INTEGER)
                                    {
                                        (yyvsp[0].nptr) -> TYPE = TYPE_INT;
                                    }
                                    else if(Ltemp -> TYPE == SYMBOL_BOOLEAN)
                                    {
                                        (yyvsp[0].nptr) -> TYPE = TYPE_BOOL; 
                                    }
                                    // printf("IN1234\n");
                                    (yyval.nptr) = (yyvsp[0].nptr);
                                }

                                else
                                {
                                    Argtemp = Arglookup((yyvsp[0].nptr) -> NAME);
                                    if(Argtemp != NULL)
                                    {
                                        if((Argtemp -> TYPE == SYMBOL_INTEGER) || (Argtemp -> TYPE == SYMBOL_AMP_INTEGER))
                                        {
                                            (yyvsp[0].nptr) -> TYPE = TYPE_INT;
                                        }
                                        else if((Argtemp -> TYPE == SYMBOL_BOOLEAN) || (Argtemp -> TYPE == SYMBOL_AMP_BOOLEAN))
                                        {
                                            (yyvsp[0].nptr) -> TYPE = TYPE_BOOL; 
                                        }

                                        (yyval.nptr) = (yyvsp[0].nptr);
                                    }

                                    else
                                    {

                                        Gtemp = Glookup((yyvsp[0].nptr) -> NAME);
                                        if(Gtemp == NULL)
                                        {
                                            yyerror("Un-declared variable\n");
                                            printf("%s\n",(yyvsp[0].nptr) -> NAME);
                                            exit(1);
                                        }
                                        else if(Gtemp -> TYPE == SYMBOL_ARRAY_BOOLEAN ||Gtemp -> TYPE == SYMBOL_ARRAY_INT )
                                        {
                                            yyerror("conflict in ID NodeType : Expected Variable . Found Array\n");
                                            printf("%s\n",(yyvsp[0].nptr) -> NAME);
                                            exit(1);
                                        }
                                        else
                                        {   
                                            (yyvsp[0].nptr) -> Gentry = Gtemp;
                                            if(Gtemp -> TYPE == SYMBOL_INTEGER)
                                            {
                                                (yyvsp[0].nptr) -> TYPE = TYPE_INT;
                                            }
                                            else if(Gtemp -> TYPE == SYMBOL_BOOLEAN)
                                            {
                                                (yyvsp[0].nptr) -> TYPE = TYPE_BOOL; 
                                            }
                                            (yyval.nptr) = (yyvsp[0].nptr);
                                        }
                                    }
                                 }
                            }
#line 2708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1055 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("ID[expr]\n");*/
                                Gtemp = Glookup((yyvsp[-3].nptr) -> NAME);
                                if(Gtemp == NULL)
                                {
                                    yyerror("Un-declared array\n");
                                    printf("%s\n",(yyvsp[-3].nptr) -> NAME);
                                    exit(1);
                                }
                                else if(Gtemp -> TYPE == SYMBOL_BOOLEAN ||Gtemp -> TYPE == SYMBOL_INTEGER )
                                {
                                    yyerror("conflict in ID NodeType : Expected Array , Found Variable\n");
                                    printf("%s\n",(yyvsp[-3].nptr) -> NAME);
                                    exit(1);
                                }
                                else if((yyvsp[-1].nptr) -> TYPE == TYPE_BOOL)
                                {
                                    yyerror("Expected value , Found boolean\n");
                                    printf("%s\n",(yyvsp[-3].nptr) -> NAME);
                                    exit(1);
                                }
                                else
                                {   
                                    (yyvsp[-3].nptr) -> Gentry = Gtemp;
                                    if(Gtemp -> TYPE == SYMBOL_ARRAY_INT)
                                    {
                                        (yyvsp[-3].nptr) -> TYPE = TYPE_INT;
                                    }
                                    else if(Gtemp -> TYPE == SYMBOL_ARRAY_BOOLEAN)
                                    {
                                        (yyvsp[-3].nptr) -> TYPE = TYPE_BOOL; 
                                    }
                                    (yyval.nptr) = TreeCreate((yyvsp[-3].nptr) -> TYPE,NODE_ARRAY,NULL,0,NULL,(yyvsp[-3].nptr),(yyvsp[-1].nptr),NULL);
                                }
                            }
#line 2748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1090 "abstree.y" /* yacc.c:1646  */
    {
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 2756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1093 "abstree.y" /* yacc.c:1646  */
    {
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 2764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1097 "abstree.y" /* yacc.c:1646  */
    {
                                    Gtemp = Glookup((yyvsp[-3].nptr) -> NAME);

                                    if(Gtemp == NULL)
                                    {
                                        yyerror("Un-declared function \n");
                                        exit(1);
                                    }

                                    else if(Gtemp -> TYPE == SYMBOL_BOOLEAN ||Gtemp -> TYPE == SYMBOL_INTEGER )
                                    {
                                        yyerror("conflict in ID NodeType : Expected Function . Found Variable\n");
                                        printf("%s\n",(yyvsp[-3].nptr) -> NAME);
                                        exit(1);
                                    }

                                    else if(Gtemp -> TYPE == SYMBOL_ARRAY_BOOLEAN ||Gtemp -> TYPE == SYMBOL_ARRAY_INT )
                                    {
                                        yyerror("conflict in ID NodeType : Expected Function . Found Array\n");
                                        printf("%s\n",(yyvsp[-3].nptr) -> NAME);
                                        exit(1);
                                    }
                                    else
                                    {   
                                        (yyvsp[-3].nptr) -> Gentry = Gtemp;
                                        if(Gtemp -> TYPE == SYMBOL_FUNC_INT)
                                        {
                                            (yyvsp[-3].nptr) -> TYPE = TYPE_INT;
                                        }
                                        else if(Gtemp -> TYPE == SYMBOL_FUNC_BOOLEAN)
                                        {
                                            (yyvsp[-3].nptr) -> TYPE = TYPE_BOOL; 
                                        }
                                        
                                    }
                                    Arg_callee = (yyvsp[-1].nptr) -> Ptr3 = Gtemp -> Arglist;  //used to find the arglist of callee function
                                    //differentiating b/w one and more than one arguments
                                    // printtree($3);
                                    if(indicator == 1)
                                    {
                                        (yyval.nptr) = TreeCreate((yyvsp[-3].nptr) -> TYPE,NODE_FUNC,(yyvsp[-3].nptr) -> NAME,0,Gtemp -> Arglist,NULL,(yyvsp[-1].nptr),NULL);
                                        indicator = 0;
                                    }
                                    else
                                        (yyval.nptr) = TreeCreate((yyvsp[-3].nptr) -> TYPE,NODE_FUNC,(yyvsp[-3].nptr) -> NAME,0,Gtemp -> Arglist,NULL,NULL,(yyvsp[-1].nptr));

                                }
#line 2816 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2820 "y.tab.c" /* yacc.c:1646  */
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
#line 1147 "abstree.y" /* yacc.c:1906  */


void yyerror(char const *s) 
{ 
    printf("yyerror  %s\n",s); 
    return ;
} 

int main(int argc,char* argv[]) 
{ 
    if(argc > 1)
    {
        fp = fopen(argv[1],"r");
        if(fp)
            yyin = fp;
    }    
    yyparse(); 
    return 1; 
}
