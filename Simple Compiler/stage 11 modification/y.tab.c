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
    #include "userdtype.c"

    int yylex();
    void yyerror(char const *s);
    struct Tnode *head1,*head;
    int result;
    FILE * fp;
    extern FILE *yyin;
    extern int yylineno;
    struct FieldList *ftemp;
    struct TypeTable *declarationType ,*FdeclarationType,*functype,*temp1,*temp2;
    struct Gsymbol *Gtemp;
    struct Lsymbol *Ltemp;
    struct ArgStruct *Argtemp1, *Argtemp2;
    int indicator = 0; //for no.of arguments passed
    int declcount = 0,defcount = 0,exprcount = 0;
    char* id_name;

#line 94 "y.tab.c" /* yacc.c:339  */

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
    DARRAY = 280,
    START = 281,
    END = 282,
    DECL = 283,
    ENDDECL = 284,
    T = 285,
    INT = 286,
    F = 287,
    BOOL = 288,
    LE = 289,
    GE = 290,
    NOT = 291,
    AND = 292,
    OR = 293,
    AMP = 294,
    MAIN = 295,
    RETURN = 296,
    ALLOC = 297,
    FREE = 298,
    TYPEDEF = 299,
    TYPE1 = 300,
    ENDTYPE = 301,
    NILL = 302,
    DEQNILL = 303,
    NEQNILL = 304
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
#define DARRAY 280
#define START 281
#define END 282
#define DECL 283
#define ENDDECL 284
#define T 285
#define INT 286
#define F 287
#define BOOL 288
#define LE 289
#define GE 290
#define NOT 291
#define AND 292
#define OR 293
#define AMP 294
#define MAIN 295
#define RETURN 296
#define ALLOC 297
#define FREE 298
#define TYPEDEF 299
#define TYPE1 300
#define ENDTYPE 301
#define NILL 302
#define DEQNILL 303
#define NEQNILL 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 30 "abstree.y" /* yacc.c:355  */

    struct Tnode * nptr;

#line 236 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 251 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   494

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  244

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

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
      55,    56,     2,     2,    57,     2,    58,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    52,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    93,   104,   105,   108,   109,   111,   114,
     119,   133,   134,   137,   142,   143,   144,   154,   172,   191,
     192,   194,   196,   208,   226,   238,   247,   267,   282,   286,
     289,   292,   304,   305,   306,   307,   319,   320,   321,   324,
     327,   339,   357,   369,   391,   392,   395,   463,   467,   471,
     475,   479,   483,   496,   509,   542,   546,   553,   566,   577,
     585,   649,   689,   761,   798,   819,   829,   839,   849,   908,
    1006,  1032,  1053,  1123,  1182,  1196,  1210,  1273,  1288,  1385,
    1417,  1422,  1440,  1456,  1468,  1480,  1492,  1504,  1516,  1528,
    1540,  1552,  1564,  1576,  1587,  1598,  1610,  1613,  1617,  1621,
    1678,  1718,  1721,  1725,  1769,  1792,  1868,  1944,  1955
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "PLUS", "MUL", "DIV", "MOD",
  "ASGN", "READ", "WRITE", "MINUS", "NEWLINE", "LT", "GT", "DEQ", "NEQ",
  "ELSE", "IF", "THEN", "ENDIF", "ENDWHILE", "WHILE", "DO", "DARRAY",
  "START", "END", "DECL", "ENDDECL", "T", "INT", "F", "BOOL", "LE", "GE",
  "NOT", "AND", "OR", "AMP", "MAIN", "RETURN", "ALLOC", "FREE", "TYPEDEF",
  "TYPE1", "ENDTYPE", "NILL", "DEQNILL", "NEQNILL", "'{'", "'}'", "';'",
  "'['", "']'", "'('", "')'", "','", "'.'", "$accept", "program",
  "TypeDefBlock", "TypeDefList", "TypeDef", "TypeDefhead", "TypeDefBody",
  "FieldDeclList", "FieldDecl", "TypeName", "gdeclaration", "gdlist",
  "gdec", "vlist", "Type", "FType", "arglist", "arg", "fvlist", "fdeflist",
  "fdef", "ldeclaration", "ldlist", "ldec", "lvlist", "mainblock", "body",
  "retstmt", "slist", "stmt", "FIELD", "exprlist", "expr", YY_NULLPTR
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
     123,   125,    59,    91,    93,    40,    41,    44,    46
};
# endif

#define YYPACT_NINF -208

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-208)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -41,    27,    84,    83,   114,   -24,  -208,    81,  -208,   267,
     267,  -208,  -208,  -208,   104,  -208,  -208,  -208,  -208,  -208,
      -2,  -208,   120,    -1,   267,  -208,  -208,  -208,  -208,  -208,
     129,  -208,   157,  -208,  -208,    41,   -33,   109,   116,  -208,
    -208,  -208,  -208,   125,   184,   307,  -208,   191,   307,   152,
    -208,   162,  -208,  -208,  -208,  -208,     1,    78,  -208,   128,
      86,   167,  -208,  -208,   214,   164,   307,  -208,   223,   307,
     177,   200,  -208,    28,  -208,   188,   122,   200,   307,   204,
    -208,   239,  -208,  -208,   204,   241,   277,  -208,   399,   205,
    -208,   212,  -208,    46,  -208,  -208,    21,   213,   219,   221,
     234,    77,   235,   228,   399,  -208,     6,  -208,  -208,  -208,
     274,    40,    77,   297,   299,    77,    77,    77,  -208,   176,
    -208,  -208,    77,    77,   121,   313,   300,  -208,   278,  -208,
      74,   303,  -208,   257,   260,   270,   329,    85,  -208,    59,
     126,   138,   151,   185,  -208,  -208,    77,    30,   338,   198,
    -208,  -208,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,  -208,   140,   153,  -208,   268,
     272,   363,  -208,    33,   253,  -208,  -208,   317,    77,   287,
     290,   304,   311,   325,   245,  -208,   -11,   447,  -208,   459,
     454,   454,   454,   459,   338,   338,   132,   340,   338,   338,
     459,   459,   306,   308,   305,  -208,  -208,   310,   232,   322,
      77,   279,  -208,  -208,  -208,   437,   437,  -208,  -208,    77,
    -208,  -208,   324,  -208,   330,  -208,   379,   327,   254,   401,
     447,  -208,  -208,  -208,   336,   437,   337,   347,  -208,   415,
    -208,  -208,   350,  -208
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,    18,     0,     0,     7,     0,     1,     0,
       0,     9,     4,     6,     0,     8,    31,    30,    28,    29,
       0,    19,     0,     0,     0,    44,     3,    16,    14,    15,
       0,    12,     0,    17,    20,    22,     0,     0,     0,    45,
       2,    10,    11,     0,     0,    38,    21,     0,    38,     0,
      13,     0,    35,    34,    32,    33,     0,     0,    36,    25,
       0,     0,    23,    40,     0,    39,     0,    24,     0,    38,
       0,    48,    41,     0,    37,     0,     0,    48,     0,     0,
      42,     0,    26,    27,     0,     0,     0,    49,     0,     0,
      43,     0,    52,     0,    47,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59,     0,    54,    46,    51,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    99,
     101,   102,     0,     0,    97,     0,     0,    56,     0,    58,
       0,     0,    53,     0,     0,     0,     0,     0,    78,     0,
       0,     0,     0,     0,   105,   106,     0,     0,    95,     0,
     107,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,     0,     0,    55,     0,
       0,     0,    79,     0,     0,    76,    60,     0,     0,     0,
       0,     0,     0,     0,     0,   104,     0,    80,    96,    82,
      84,    85,    86,    83,    87,    89,    91,    92,    88,    90,
      93,    94,     0,     0,     0,    77,    71,     0,     0,     0,
       0,     0,    62,    75,    64,     0,     0,   100,   103,     0,
      73,    74,     0,    69,     0,    72,     0,     0,     0,     0,
      81,    70,    68,    61,     0,     0,     0,     0,    63,     0,
      65,    67,     0,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -208,  -208,  -208,  -208,   354,  -208,  -208,  -208,   360,  -208,
    -208,  -208,   372,  -208,    51,   -65,   -34,   341,  -208,  -208,
     380,   331,  -208,   320,  -208,   397,   343,   326,  -207,  -103,
     -88,  -208,  -105
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,     7,    15,    30,    31,    32,
      10,    20,    21,    36,    22,    56,    57,    58,    65,    24,
      25,    79,    86,    87,    93,    26,    89,   103,   104,   105,
     124,   186,   125
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     106,   129,    16,    37,     1,    63,   136,   137,   228,   229,
     141,   142,   143,    85,    60,   130,   106,   148,   149,    46,
       4,    85,    12,    17,    47,   171,   140,    33,   239,    18,
     111,    19,    80,   118,   119,    76,   118,   119,   167,    38,
      64,   184,   187,   118,   119,   218,   219,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     120,    23,   121,   120,   131,   121,   122,    81,   208,   122,
     120,     4,   121,   211,   112,    23,   122,   118,   119,   113,
     118,   119,   133,   134,     8,   123,   185,   135,   123,   207,
     152,   153,   154,   155,    44,   123,    45,   156,   109,   157,
     158,   159,   160,   110,   120,   226,   121,   120,    27,   121,
     122,     9,   178,   122,   230,   179,   169,   113,    11,   161,
     162,   170,   163,   164,    35,   129,   129,   106,   106,   123,
      66,    14,   123,    27,    67,    28,   129,    29,    66,   177,
     106,   106,    70,   152,   153,   154,   155,   106,   159,   160,
     156,   106,   157,   158,   159,   160,   152,   153,   154,   155,
      28,    43,    29,   156,    48,   157,   158,   159,   160,   150,
     151,    49,   161,   162,    66,   163,   164,    50,    83,   131,
      41,    68,   180,    69,   131,   161,   162,    51,   163,   164,
     152,   153,   154,   155,   181,    59,   202,   156,   113,   157,
     158,   159,   160,   152,   153,   154,   155,   182,    61,   203,
     156,   131,   157,   158,   159,   160,    62,    71,    72,   161,
     162,    73,   163,   164,   144,   145,    75,    77,    78,   146,
      88,   147,   161,   162,   113,   163,   164,   152,   153,   154,
     155,   183,    82,    90,   156,    92,   157,   158,   159,   160,
     152,   153,   154,   155,   188,   127,   107,   156,    96,   157,
     158,   159,   160,   108,    97,    98,   161,   162,   114,   163,
     164,    16,   235,    99,   115,   236,   116,   100,   132,   161,
     162,    52,   163,   164,   152,   153,   154,   155,   224,   117,
     126,   156,    17,   157,   158,   159,   160,   102,    18,   217,
      19,   138,    53,   139,   166,   168,    94,   172,    54,   209,
      55,    52,   173,   161,   162,   174,   163,   164,   152,   153,
     154,   155,   175,   204,   205,   156,   210,   157,   158,   159,
     160,   215,    53,   227,   152,   153,   154,   155,    54,   212,
      55,   156,   213,   157,   158,   159,   160,   161,   162,   216,
     163,   164,    -1,    -1,   159,   160,   214,   160,   220,    13,
     221,   222,   223,   161,   162,   165,   163,   164,   152,   153,
     154,   155,    -1,    -1,   225,   156,   231,   157,   158,   159,
     160,   176,   232,   234,   152,   153,   154,   155,   238,   240,
      42,   156,    34,   157,   158,   159,   160,   161,   162,   241,
     163,   164,   243,    96,    39,    96,    95,    74,    84,    97,
      98,    97,    98,   161,   162,   206,   163,   164,    99,    96,
      99,    40,   100,   237,   100,    97,    98,    91,     0,     0,
     128,   233,     0,     0,    99,     0,   242,     0,   100,     0,
     101,    96,   102,     0,   102,     0,     0,    97,    98,     0,
       0,     0,   152,   153,   154,   155,    99,     0,   102,   156,
     100,   157,   158,   159,   160,   153,   154,   155,   157,   158,
     159,   160,     0,   157,   158,   159,   160,     0,     0,     0,
     102,   161,   162,     0,   163,   164,     0,     0,   161,   162,
       0,     0,     0,   161,   162
};

static const yytype_int16 yycheck[] =
{
      88,   104,     4,     4,    45,     4,   111,   112,   215,   216,
     115,   116,   117,    78,    48,     9,   104,   122,   123,    52,
      44,    86,    46,    25,    57,   130,   114,    29,   235,    31,
       9,    33,     4,     3,     4,    69,     3,     4,   126,    40,
      39,   146,   147,     3,     4,    56,    57,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      30,    10,    32,    30,    58,    32,    36,    39,   173,    36,
      30,    44,    32,   178,    53,    24,    36,     3,     4,    58,
       3,     4,    42,    43,     0,    55,    56,    47,    55,    56,
       5,     6,     7,     8,    53,    55,    55,    12,    52,    14,
      15,    16,    17,    57,    30,   210,    32,    30,     4,    32,
      36,    28,    53,    36,   219,    56,    42,    58,     4,    34,
      35,    47,    37,    38,     4,   228,   229,   215,   216,    55,
      52,    50,    55,     4,    56,    31,   239,    33,    52,    54,
     228,   229,    56,     5,     6,     7,     8,   235,    16,    17,
      12,   239,    14,    15,    16,    17,     5,     6,     7,     8,
      31,     4,    33,    12,    55,    14,    15,    16,    17,    48,
      49,    55,    34,    35,    52,    37,    38,    52,    56,    58,
      51,    53,    56,    55,    58,    34,    35,     3,    37,    38,
       5,     6,     7,     8,    56,     4,    56,    12,    58,    14,
      15,    16,    17,     5,     6,     7,     8,    56,    56,    56,
      12,    58,    14,    15,    16,    17,    54,    50,     4,    34,
      35,    57,    37,    38,    48,    49,     3,    50,    28,    53,
      26,    55,    34,    35,    58,    37,    38,     5,     6,     7,
       8,    56,    54,     4,    12,     4,    14,    15,    16,    17,
       5,     6,     7,     8,    56,    27,    51,    12,     4,    14,
      15,    16,    17,    51,    10,    11,    34,    35,    55,    37,
      38,     4,    18,    19,    55,    21,    55,    23,     4,    34,
      35,     4,    37,    38,     5,     6,     7,     8,    56,    55,
      55,    12,    25,    14,    15,    16,    17,    43,    31,    54,
      33,     4,    25,     4,     4,    27,    29,     4,    31,    56,
      33,     4,    55,    34,    35,    55,    37,    38,     5,     6,
       7,     8,    52,    55,    52,    12,     9,    14,    15,    16,
      17,    20,    25,    54,     5,     6,     7,     8,    31,    52,
      33,    12,    52,    14,    15,    16,    17,    34,    35,    24,
      37,    38,    14,    15,    16,    17,    52,    17,    52,     5,
      52,    56,    52,    34,    35,    52,    37,    38,     5,     6,
       7,     8,    34,    35,    52,    12,    52,    14,    15,    16,
      17,    52,    52,    56,     5,     6,     7,     8,    52,    52,
      30,    12,    20,    14,    15,    16,    17,    34,    35,    52,
      37,    38,    52,     4,    24,     4,    86,    66,    77,    10,
      11,    10,    11,    34,    35,    52,    37,    38,    19,     4,
      19,    24,    23,    22,    23,    10,    11,    84,    -1,    -1,
     104,    52,    -1,    -1,    19,    -1,    21,    -1,    23,    -1,
      41,     4,    43,    -1,    43,    -1,    -1,    10,    11,    -1,
      -1,    -1,     5,     6,     7,     8,    19,    -1,    43,    12,
      23,    14,    15,    16,    17,     6,     7,     8,    14,    15,
      16,    17,    -1,    14,    15,    16,    17,    -1,    -1,    -1,
      43,    34,    35,    -1,    37,    38,    -1,    -1,    34,    35,
      -1,    -1,    -1,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    60,    61,    44,    62,    63,    64,     0,    28,
      69,     4,    46,    63,    50,    65,     4,    25,    31,    33,
      70,    71,    73,    73,    78,    79,    84,     4,    31,    33,
      66,    67,    68,    29,    71,     4,    72,     4,    40,    79,
      84,    51,    67,     4,    53,    55,    52,    57,    55,    55,
      52,     3,     4,    25,    31,    33,    74,    75,    76,     4,
      75,    56,    54,     4,    39,    77,    52,    56,    53,    55,
      56,    50,     4,    57,    76,     3,    75,    50,    28,    80,
       4,    39,    54,    56,    80,    74,    81,    82,    26,    85,
       4,    85,     4,    83,    29,    82,     4,    10,    11,    19,
      23,    41,    43,    86,    87,    88,    89,    51,    51,    52,
      57,     9,    53,    58,    55,    55,    55,    55,     3,     4,
      30,    32,    36,    55,    89,    91,    55,    27,    86,    88,
       9,    58,     4,    42,    43,    47,    91,    91,     4,     4,
      89,    91,    91,    91,    48,    49,    53,    55,    91,    91,
      48,    49,     5,     6,     7,     8,    12,    14,    15,    16,
      17,    34,    35,    37,    38,    52,     4,    89,    27,    42,
      47,    91,     4,    55,    55,    52,    52,    54,    53,    56,
      56,    56,    56,    56,    91,    56,    90,    91,    56,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    56,    56,    55,    52,    52,    56,    91,    56,
       9,    91,    52,    52,    52,    20,    24,    54,    56,    57,
      52,    52,    56,    52,    56,    52,    91,    54,    87,    87,
      91,    52,    52,    52,    56,    18,    21,    22,    52,    87,
      52,    52,    21,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    62,    62,    63,    64,
      65,    66,    66,    67,    68,    68,    68,    69,    69,    70,
      70,    71,    72,    72,    72,    72,    72,    72,    73,    73,
      73,    73,    74,    74,    74,    74,    75,    75,    75,    76,
      77,    77,    77,    77,    78,    78,    79,    80,    80,    81,
      81,    82,    83,    83,    84,    85,    85,    86,    87,    87,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    89,    89,
      90,    90,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     3,     0,     2,     1,     2,     2,
       3,     2,     1,     3,     1,     1,     1,     3,     0,     1,
       2,     3,     1,     4,     4,     3,     6,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     0,     2,
       1,     2,     3,     4,     1,     2,     9,     3,     0,     1,
       2,     3,     1,     3,     8,     4,     3,     3,     2,     1,
       4,     7,     5,     8,     5,     8,    10,     8,     7,     6,
       6,     4,     6,     5,     5,     5,     4,     4,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     1,     1,     1,
       4,     1,     1,     4,     3,     2,     2,     2,     2
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
#line 85 "abstree.y" /* yacc.c:1646  */
    {
                                            // printf("SYMBOL TABLE:\n");
                                            // printSymbolTable();
                                            // printf("---------------\n");

                                            fclose(intermediate);
                                            exit(1);
                        }
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 93 "abstree.y" /* yacc.c:1646  */
    {

                                            // printf("SYMBOL TABLE:\n");
                                            // printSymbolTable();
                                            // printf("---------------\n");
                                            fclose(intermediate);
                                            exit(1);
                                    }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 114 "abstree.y" /* yacc.c:1646  */
    { 
                                    id_name = (yyvsp[0].nptr) -> NAME; 
                                    TypeInstall((yyvsp[0].nptr) -> NAME,NULL); //fieldlist is initialized to null
                               }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 119 "abstree.y" /* yacc.c:1646  */
    { 
                                            temp1 = TypeLookup(id_name);
                                            temp1 -> fields = FieldHead;
                           					ftemp = FieldHead;
                           					// while(ftemp != NULL)
                           					// {
                           					// 	printf("%s : %s\n",ftemp -> NAME,ftemp -> type -> NAME );
                           					// 	ftemp = ftemp -> NEXT;
                           					// }                 
                                            FieldHead = NULL;
                                            FieldTail = NULL;
                                      }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 137 "abstree.y" /* yacc.c:1646  */
    {
									// printf("%s\n",temp1 -> NAME );
									FieldInstall(temp1,(yyvsp[-1].nptr) -> NAME);
								}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 142 "abstree.y" /* yacc.c:1646  */
    {temp1 = TypeLookup("integer");}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 143 "abstree.y" /* yacc.c:1646  */
    {temp1 = TypeLookup("boolean");}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 144 "abstree.y" /* yacc.c:1646  */
    {
                                temp1 = TypeLookup((yyvsp[0].nptr) -> NAME);
                                if(temp1 == NULL)
                                {
                                    yyerror("Un-declared udt\n");
                                    exit(1);
                                }
                            }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 154 "abstree.y" /* yacc.c:1646  */
    {
                                        intermediate = fopen("assemblycode.asm","w+");
                                        if(intermediate == NULL)
                                        {
                                            printf("Unable to locate file\n");
                                            exit(1);
                                        }
                                        // alloc();
                                        // freeheap();
                                        fprintf(intermediate, "START\n");
                                        // initialize();
                                        fprintf(intermediate, "MOV SP,%d\n",totalCount - 1);
                                        fprintf(intermediate, "MOV BP,%d\n",totalCount);
                                        fprintf(intermediate, "PUSH R0\n");
                                        fprintf(intermediate, "CALL MAIN\n");
                                        fprintf(intermediate, "HALT\n");
                    
                                        }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 172 "abstree.y" /* yacc.c:1646  */
    {
                                        intermediate = fopen("assemblycode.asm","w+");
                                        if(intermediate == NULL)
                                        {
                                            printf("Unable to locate file\n");
                                            exit(1);
                                        }
                                        // alloc();
                                        // freeheap();
                                        fprintf(intermediate, "START\n");
                                        initialize();
                                        fprintf(intermediate, "MOV SP,%d\n",totalCount - 1);
                                        fprintf(intermediate, "MOV BP,%d\n",totalCount);
                                        fprintf(intermediate, "PUSH R0\n");
                                        fprintf(intermediate, "CALL MAIN\n");
                                        fprintf(intermediate, "HALT\n");

                                     }
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 191 "abstree.y" /* yacc.c:1646  */
    {}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 192 "abstree.y" /* yacc.c:1646  */
    {}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 194 "abstree.y" /* yacc.c:1646  */
    {}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 196 "abstree.y" /* yacc.c:1646  */
    {
                            Gtemp = Glookup((yyvsp[0].nptr) -> NAME);
                            if(Gtemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            if(declarationType == TypeLookup("darray"))
                            {
                                Ginstall((yyvsp[0].nptr) -> NAME,declarationType,1,NULL);                                
                            }
                        }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 208 "abstree.y" /* yacc.c:1646  */
    {
                            Gtemp = Glookup((yyvsp[-3].nptr) -> NAME);
                            if(Gtemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            if ( declarationType == TypeLookup("integer") )
                                Ginstall((yyvsp[-3].nptr) -> NAME,TypeLookup("array_integer"),(yyvsp[-1].nptr) -> VALUE,NULL);
                            else if ( declarationType == TypeLookup("boolean") )
                                Ginstall((yyvsp[-3].nptr) -> NAME,TypeLookup("array_boolean"),(yyvsp[-1].nptr) -> VALUE,NULL);
                            else
                            {
                            	yyerror("arrays of udt is not allowed\n");
                            	exit(1);
                            }
                        }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 226 "abstree.y" /* yacc.c:1646  */
    {
                                declcount++; //  to keep track of number of functions declared
                                Gtemp = Glookup((yyvsp[-3].nptr) -> NAME);
                                if(Gtemp != NULL)
                                {
                                    printf("Re initialization of identifier\n");
                                    exit(1);
                                }
                                Ginstall((yyvsp[-3].nptr) -> NAME,declarationType,-1, Arghead);
                                Arghead = NULL;
                                Argtail = NULL;
                            }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 238 "abstree.y" /* yacc.c:1646  */
    {
                            Gtemp = Glookup((yyvsp[0].nptr) -> NAME);
                            if(Gtemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            Ginstall((yyvsp[0].nptr) -> NAME,declarationType,1,NULL);
                        }
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 247 "abstree.y" /* yacc.c:1646  */
    {
                                    Gtemp = Glookup((yyvsp[-3].nptr) -> NAME);
                                    if(Gtemp != NULL)
                                    {
                                        printf("Re initialization of variable\n");
                                        exit(1);
                                    }

                                    if ( declarationType == TypeLookup("integer") )
                                        Ginstall((yyvsp[-3].nptr) -> NAME,TypeLookup("array_integer"),(yyvsp[-1].nptr) -> VALUE,NULL);
                                    else if ( declarationType == TypeLookup("boolean") )
                                        Ginstall((yyvsp[-3].nptr) -> NAME,TypeLookup("array_boolean"),(yyvsp[-1].nptr) -> VALUE,NULL);
        							else
		                            {
		                            	yyerror("arrays of udt is not allowed\n");
		                            	exit(1);
		                            }

                                }
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 267 "abstree.y" /* yacc.c:1646  */
    {
                                        declcount++; //  to keep track of number of functions declared

                                        Gtemp = Glookup((yyvsp[-3].nptr) -> NAME);
                                        if(Gtemp != NULL)
                                        {
                                            printf("Re initialization of identifier\n");
                                            exit(1);
                                        }
                                        Ginstall((yyvsp[-3].nptr) -> NAME,declarationType,-1, Arghead);
                                        Arghead = NULL;
                                        Argtail = NULL;
                                    }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 282 "abstree.y" /* yacc.c:1646  */
    {
                    declarationType = TypeLookup("integer");
                }
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 286 "abstree.y" /* yacc.c:1646  */
    {
                    declarationType = TypeLookup("boolean");
                }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 289 "abstree.y" /* yacc.c:1646  */
    {
                    declarationType = TypeLookup("darray");
                    }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 292 "abstree.y" /* yacc.c:1646  */
    {
                    temp1 = TypeLookup((yyvsp[0].nptr) -> NAME);
                    if(temp1 != NULL)
                        declarationType = TypeLookup((yyvsp[0].nptr) -> NAME);
                    else
                    {
                        yyerror("Unknown user-defined type\n");
                        exit(1);
                    }
                }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 304 "abstree.y" /* yacc.c:1646  */
    {FdeclarationType = TypeLookup("integer");}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 305 "abstree.y" /* yacc.c:1646  */
    {FdeclarationType = TypeLookup("boolean");}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 306 "abstree.y" /* yacc.c:1646  */
    {FdeclarationType = TypeLookup("darray");}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 307 "abstree.y" /* yacc.c:1646  */
    {
                   temp1 = TypeLookup((yyvsp[0].nptr) -> NAME);
                    if(temp1 != NULL)
                        FdeclarationType = TypeLookup((yyvsp[0].nptr) -> NAME);
                    else
                    {
                        yyerror("Unknown user-defined type\n");
                        exit(1);
                    }
                }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 319 "abstree.y" /* yacc.c:1646  */
    {}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 320 "abstree.y" /* yacc.c:1646  */
    {}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 324 "abstree.y" /* yacc.c:1646  */
    {}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 327 "abstree.y" /* yacc.c:1646  */
    {
                                        // printf("%s\n", $1 -> NAME);
                                        // printf("%s\n", FdeclarationType -> NAME);
                                        Argtemp = Arglookup((yyvsp[0].nptr) -> NAME);
                                        if(Argtemp != NULL)
                                        {
                                            printf("Re initialization of variable in Arglist\n");
                                            exit(1);
                                        }

                                        ArgInstall((yyvsp[0].nptr) -> NAME,FdeclarationType,0); 
                                    }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 339 "abstree.y" /* yacc.c:1646  */
    {        
                                            Argtemp = Arglookup((yyvsp[0].nptr) -> NAME);

                                            if(Argtemp != NULL)
                                            {
                                                printf("Re initialization of variable in Arglist\n");
                                                exit(1);
                                            }
                                            
                                            if ( FdeclarationType == TypeLookup("integer") )
                                            	ArgInstall((yyvsp[0].nptr) -> NAME,TypeLookup("amp_integer"),1);
	                                        else if ( FdeclarationType == TypeLookup("boolean") )
                                            	ArgInstall((yyvsp[0].nptr) -> NAME,TypeLookup("amp_boolean"),1);
    	                                    else
                                            {
												ArgInstall((yyvsp[0].nptr) -> NAME,FdeclarationType,1);
		                                    }
		                            }
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 357 "abstree.y" /* yacc.c:1646  */
    {
                                        Argtemp = Arglookup((yyvsp[0].nptr) -> NAME);

                                        if(Argtemp != NULL)
                                        {
                                            printf("Re initialization of variable in Arglist\n");
                                            exit(1);
                                        }

                                        ArgInstall((yyvsp[0].nptr) -> NAME,FdeclarationType,0); 
                                    }
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 369 "abstree.y" /* yacc.c:1646  */
    {
                                        Argtemp = Arglookup((yyvsp[0].nptr) -> NAME);

                                        if(Argtemp != NULL)
                                        {
                                            printf("Re initialization of variable in Arglist\n");
                                            exit(1);
                                        }
                                        if ( FdeclarationType == TypeLookup("integer") )
                                            ArgInstall((yyvsp[0].nptr) -> NAME,TypeLookup("amp_integer"),1);

                                        else if ( FdeclarationType == TypeLookup("boolean") )
                                            ArgInstall((yyvsp[0].nptr) -> NAME,TypeLookup("amp_boolean"),1);
	                                    else
                                        {
											ArgInstall((yyvsp[0].nptr) -> NAME,FdeclarationType,1);
	                                    }
                                    }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 391 "abstree.y" /* yacc.c:1646  */
    {}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 392 "abstree.y" /* yacc.c:1646  */
    {}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 395 "abstree.y" /* yacc.c:1646  */
    {  
                                                                // printf("IN fdef\n");
                                                                defcount++; //  to keep track of number of functions defined

                                                                Gtemp = Glookup((yyvsp[-7].nptr) -> NAME);

                                                                if(Gtemp == NULL)
                                                                {
                                                                    printf("Function not declared in GST\n");
                                                                    exit(1);
                                                                }

                                                                //storing arguments in LST

                                                                Argtemp1 = Arghead;
                                                                Argtemp2 = Gtemp -> Arglist;

                                                                while((Argtemp1 != NULL)&&(Argtemp2 != NULL))
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

                                                                if((Argtemp1 != NULL)||(Argtemp2 != NULL))
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

                                                                Arghead = NULL;
                                                                Argtail = NULL;
                                                                Lhead = NULL;
                                                                Ltail = NULL;
                                                            }
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 463 "abstree.y" /* yacc.c:1646  */
    {
                                            // $$ = $2;

                                        }
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 467 "abstree.y" /* yacc.c:1646  */
    { 
                                        //$$ = NULL;
                                     }
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 471 "abstree.y" /* yacc.c:1646  */
    {
                                // $$ = Lhead;
                            }
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 475 "abstree.y" /* yacc.c:1646  */
    {
                                // $$ = Lhead;
                            }
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 479 "abstree.y" /* yacc.c:1646  */
    {
                                // $$ = Lhead;
                           }
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 483 "abstree.y" /* yacc.c:1646  */
    {
                            // printf("%s\n",$1 -> NAME );
                            // printf("%s\n", FdeclarationType -> NAME);
                            Ltemp = Llookup((yyvsp[0].nptr) -> NAME);
                            if(Ltemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            Linstall((yyvsp[0].nptr) -> NAME,FdeclarationType);
                            // $$ = Lhead;
                        }
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 496 "abstree.y" /* yacc.c:1646  */
    {
                            Ltemp = Llookup((yyvsp[0].nptr) -> NAME);
                            if(Ltemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            Linstall((yyvsp[0].nptr) -> NAME,FdeclarationType);

                            // $$ = Lhead;
                        }
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 510 "abstree.y" /* yacc.c:1646  */
    {
                                if(declcount != defcount)
                                {
                                    yyerror("All functions declared need to be defined\n");
                                    exit(1);
                                }
                                //$2 -> Lentry = Lhead;
                                if(declarationType != TypeLookup("integer"))
                                {
                                    yyerror("Main return type should be of integer type\n");
                                    exit(1);
                                }
                                fprintf(intermediate, "MAIN:\n");
                                fprintf(intermediate, "PUSH BP\n");
                                fprintf(intermediate, "MOV BP,SP\n");

                                Ltemp = Lhead;

                                while(Ltemp != NULL)
                                {                                                                
                                    fprintf(intermediate, "PUSH R0\n");
                                    Ltemp = Ltemp -> NEXT;
                                }
                                
                                //printf("entering\n");
                                codegen((yyvsp[-1].nptr));
                                // printf("entering\n");                              
                                Lhead = NULL;
                                Ltail = NULL;
                            }
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 542 "abstree.y" /* yacc.c:1646  */
    {
                                    //printf("created\n");
                                    (yyval.nptr) = TreeCreate(TypeLookup("void"), DEFAULT, NULL,0,NULL,(yyvsp[-2].nptr),(yyvsp[-1].nptr),NULL);
                                }
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 546 "abstree.y" /* yacc.c:1646  */
    {
                                    //printf("created\n");
                                    (yyval.nptr) = TreeCreate(TypeLookup("void"), DEFAULT, NULL,0,NULL,NULL,(yyvsp[-1].nptr),NULL);
                                }
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 553 "abstree.y" /* yacc.c:1646  */
    {   
                                if(declarationType == (yyvsp[-1].nptr) -> TYPE)                              
                                    (yyval.nptr) = TreeCreate((yyvsp[-1].nptr)->TYPE, NODE_RET,NULL,0,NULL,NULL,(yyvsp[-1].nptr),NULL);
                                else
                                {
                                    // printf("functype : %d\n",functype );
                                    // printf("exprtype : %d\n",$2 -> TYPE );
                                    yyerror("return type do not match with the function return type\n");
                                    exit(1);
                                }
                            }
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 566 "abstree.y" /* yacc.c:1646  */
    {
                            head = (struct Tnode *)malloc(sizeof(struct Tnode ));
                            head -> NODE = DEFAULT;
                            head -> Ptr1 = (yyvsp[-1].nptr);
                            //printf("----------------------\n");
                            //printf("%d\n",head->Ptr1->NODE);
                            head -> Ptr2 = (yyvsp[0].nptr);
                            //printf("%d\n",head->Ptr2->NODE);
                            // printf("----------------------\n");
                            (yyval.nptr) = head;
                        }
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 577 "abstree.y" /* yacc.c:1646  */
    {
                            (yyval.nptr) = (yyvsp[0].nptr);
                            //printf("-----%d----\n",$1->NODE);
                                                        
                        }
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 585 "abstree.y" /* yacc.c:1646  */
    {
                                    /*printf(" in ASGN \n");*/

                                    Ltemp = Llookup((yyvsp[-3].nptr) -> NAME);

                                    if(Ltemp != NULL)
                                    {
                                        (yyvsp[-3].nptr) -> TYPE = Ltemp -> TYPE;
                                    }

                                    else
                                    {
                                        Argtemp = Arglookup((yyvsp[-3].nptr) -> NAME);
                                        if(Argtemp != NULL)
                                        {
                                            if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                            {
                                                (yyvsp[-3].nptr) -> TYPE = TypeLookup("integer");
                                            }
                                            else if((Argtemp -> TYPE == TypeLookup("boolean")) || (Argtemp -> TYPE == TypeLookup("amp_boolean")))
                                            {
                                                (yyvsp[-3].nptr) -> TYPE = TypeLookup("boolean"); 
                                            }
                                            else
                                            {
                                            	(yyvsp[-3].nptr) -> TYPE = Argtemp -> TYPE;	
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
                                            else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                            {
                                                yyerror("conflict in ID NodeType : Expected Variable . Found Array\n");
                                                printf("%s\n",(yyvsp[-3].nptr) -> NAME);
                                                exit(1);
                                            }
                                            else
                                            {   
                                                (yyvsp[-3].nptr) -> Gentry = Gtemp;
                                                (yyvsp[-3].nptr) -> TYPE = Gtemp -> TYPE;
                                            }
                                        }
                                    }
                                    if((yyvsp[-3].nptr)-> TYPE != (yyvsp[-1].nptr) -> TYPE)
                                    {
                                        printf("%s\n",(yyvsp[-3].nptr) -> TYPE -> NAME );
                                        printf("%s\n",(yyvsp[-1].nptr) -> NAME);

                                        yyerror("conflict in types in assignment 1\n");
                                        printf("%s\n",(yyvsp[-3].nptr) -> NAME);
                                        exit(1);
                                    } 
                                    (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_ASGN,NULL,0,NULL,(yyvsp[-3].nptr),(yyvsp[-1].nptr),NULL);  
                                }
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 649 "abstree.y" /* yacc.c:1646  */
    {
                                                /*printf(" in ASGN ARRAY\n");*/
                                                Gtemp = Glookup((yyvsp[-6].nptr) -> NAME);
                                                if(Gtemp == NULL)
                                                {
                                                    printf("Un-declared array\n");
                                                    exit(1);
                                                }
                                                else if(Gtemp -> TYPE == TypeLookup("boolean") ||Gtemp -> TYPE == TypeLookup("integer") )
                                                {
                                                    yyerror("conflict in ID NodeType : Expected Variable , Found Array\n");
                                                    printf("%s\n",(yyvsp[-6].nptr) -> NAME);
                                                    exit(1);
                                                }
                                                else if((yyvsp[-4].nptr) -> TYPE != TypeLookup("integer"))
                                                {
                                                    yyerror("Expected value \n");
                                                    printf("%s\n",(yyvsp[-6].nptr) -> NAME);
                                                    exit(1);
                                                }
                                                else
                                                {   
                                                    (yyvsp[-6].nptr) -> Gentry = Gtemp;
                                                    if(Gtemp -> TYPE == TypeLookup("array_integer"))
                                                    {
                                                        (yyvsp[-6].nptr) -> TYPE = TypeLookup("integer");
                                                    }
                                                    else if(Gtemp -> TYPE == TypeLookup("array_boolean"))
                                                    {
                                                        (yyvsp[-6].nptr) -> TYPE = TypeLookup("boolean"); 
                                                    }
                                                } 
                                                if((yyvsp[-6].nptr)-> TYPE != (yyvsp[-1].nptr) -> TYPE)
                                                {
                                                    yyerror("conflict in types in assignment 2\n");
                                                    printf("%s\n",(yyvsp[-6].nptr) -> NAME);
                                                    exit(1);
                                                } 
                                                (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_ARRAY_ASGN,NULL,0,NULL,(yyvsp[-6].nptr),(yyvsp[-4].nptr),(yyvsp[-1].nptr)); 
                                          }
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 689 "abstree.y" /* yacc.c:1646  */
    {
                                    /*printf(" in READ \n");*/ 
                                    Ltemp = Llookup((yyvsp[-2].nptr) -> NAME);

                                    if(Ltemp != NULL)
                                    {
                                        if(Ltemp -> TYPE == TypeLookup("integer"))
                                        {
                                            (yyvsp[-2].nptr) -> TYPE = TypeLookup("integer");
                                        }
                                        else 
                                        {
                                            //$3 -> TYPE = TYPE_BOOL;
                                            yyerror("variables other than integer can not be read\n");
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
                                            if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                            {
                                                (yyvsp[-2].nptr) -> TYPE = TypeLookup("integer");
                                            }
                                            else
                                            {
                                            	yyerror("variables other than integer can not be read\n");
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
                                            else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                            {
                                                yyerror("conflict in ID NodeType : Expected Variable . Found Array\n");
                                                printf("%s\n",(yyvsp[-2].nptr) -> NAME);
                                                exit(1);
                                            }
                                            else
                                            {   
                                                (yyvsp[-2].nptr) -> Gentry = Gtemp;
                                                if(Gtemp -> TYPE == TypeLookup("integer"))
                                                {
                                                    (yyvsp[-2].nptr) -> TYPE = TypeLookup("integer");
                                                }
                                                else
                                                {
                                                    //$3 -> TYPE = TYPE_BOOL;
                                            		yyerror("variables other than integer can not be read\n");
                                                    printf("%s\n",(yyvsp[-2].nptr) -> NAME);
                                                    exit(1);
                                                }
                                            }
                                        }
                                    }
                                    (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_READ,NULL,0,NULL,NULL,(yyvsp[-2].nptr),NULL); 
                                }
#line 2408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 761 "abstree.y" /* yacc.c:1646  */
    {
                                                /*printf(" in READ ARR\n");*/  
                                                Gtemp = Glookup((yyvsp[-5].nptr) -> NAME);
                                                if(Gtemp == NULL)
                                                {
                                                    yyerror("Un-declared array\n");
                                                    exit(1);
                                                }
                                                else if(Gtemp -> TYPE == TypeLookup("boolean") ||Gtemp -> TYPE == TypeLookup("integer") )
                                                {
                                                    yyerror("conflict in ID NodeType : Expected Variable , Found Array\n");
                                                    printf("%s\n",(yyvsp[-5].nptr) -> NAME);
                                                    exit(1);
                                                }          
                                                else if((yyvsp[-3].nptr) -> TYPE != TypeLookup("integer"))
                                                {
                                                    yyerror("Expected value\n");
                                                    printf("%s\n",(yyvsp[-5].nptr) -> NAME);
                                                    exit(1);
                                                }                                          
                                                else
                                                {   
                                                    (yyvsp[-5].nptr) -> Gentry = Gtemp;
                                                    if(Gtemp -> TYPE == TypeLookup("array_integer"))
                                                    {
                                                        (yyvsp[-5].nptr) -> TYPE = TypeLookup("integer");
                                                    }
                                                    else
                                                    {
                                                        //$3 -> TYPE = TYPE_BOOL;
                                                        yyerror("array variables other than integer cannot be read\n");
                                                        printf("%s\n",(yyvsp[-5].nptr) -> NAME);
                                                        exit(1);
                                                    }
                                                }
                                                (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_ARRAY_READ,NULL,0,NULL,NULL,(yyvsp[-5].nptr),(yyvsp[-3].nptr)); 
                                            }
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 798 "abstree.y" /* yacc.c:1646  */
    {
                                    /*  printf(" in WRITE \n"); */
                                     // printf("%d\n",$3 -> TYPE );
                                    if( (yyvsp[-2].nptr) -> TYPE != TypeLookup("boolean") || (yyvsp[-2].nptr) -> TYPE != TypeLookup("amp_boolean"))
                                    {
                                        (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_WRITE,NULL,0,NULL,NULL,(yyvsp[-2].nptr),NULL);
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
#line 2476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 820 "abstree.y" /* yacc.c:1646  */
    { 
                                    /*printf(" in IF_THEN \n");*/
                                    if((yyvsp[-5].nptr) -> TYPE != TypeLookup("boolean"))
                                    {
                                        yyerror("Expected boolean , Found value in if\n");
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_IF,NULL,0,NULL,(yyvsp[-5].nptr),(yyvsp[-2].nptr),NULL); 
                               }
#line 2490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 830 "abstree.y" /* yacc.c:1646  */
    { 
                                    // printf(" in IF_THEN_ELSE \n");
                                    if((yyvsp[-7].nptr) -> TYPE != TypeLookup("boolean"))
                                    {
                                        yyerror("Expected boolean , Found value in if else\n");
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_IF_ELSE,NULL,0,NULL,(yyvsp[-7].nptr),(yyvsp[-4].nptr),(yyvsp[-2].nptr)); 
                                }
#line 2504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 840 "abstree.y" /* yacc.c:1646  */
    { 
                                    // printf(" in WHILE \n"); 
                                    if((yyvsp[-5].nptr) -> TYPE != TypeLookup("boolean"))
                                    {
                                        yyerror("Expected boolean , Found value in while\n");
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_WHILE,NULL,0,NULL,(yyvsp[-5].nptr),(yyvsp[-2].nptr),NULL); 
                                }
#line 2518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 850 "abstree.y" /* yacc.c:1646  */
    {
                                          Ltemp = Llookup((yyvsp[-6].nptr) -> NAME);

                                        if(Ltemp != NULL)
                                        {
                                             if(Ltemp -> TYPE != TypeLookup("darray"))
                                                {
                                                    //$1 -> TYPE = TypeLookup("integer");
                                                    yyerror("Cannot ALLOC expr to non darray variable\n");
                                                    exit(1);
                                                }
                                                else 
                                                {
                                                    (yyvsp[-6].nptr) -> TYPE = TypeLookup(Ltemp -> TYPE);
                                                }
                                        }
                                        else
                                        {
                                            Argtemp = Arglookup((yyvsp[-6].nptr) -> NAME);
                                            if(Argtemp != NULL)
                                            {
                                                if(Argtemp -> TYPE != TypeLookup("darray") )
                                                {
                                                    //$1 -> TYPE = TypeLookup("integer");
                                                    yyerror("Cannot ALLOC to integer variable\n");
                                                    exit(1);
                                                }
                                                else
                                                {
                                                    (yyvsp[-6].nptr) -> TYPE = TypeLookup(Argtemp -> TYPE);
                                                }       
                                            }

                                            else
                                            {
                                                Gtemp = Glookup((yyvsp[-6].nptr) -> NAME);
                                                if(Gtemp == NULL)
                                                {
                                                    yyerror("Un-declared variable\n");
                                                    printf("%s\n",(yyvsp[-6].nptr) -> NAME);
                                                    exit(1);
                                                }
                                                else if(Gtemp -> TYPE != TypeLookup("darray") )
                                                {
                                                    yyerror("alloc expr can not be assigned to non darray variables\n");
                                                    printf("%s\n",(yyvsp[-6].nptr) -> NAME);
                                                    exit(1);
                                                }
                                                else
                                                {   
                                                    (yyvsp[-6].nptr) -> Gentry = Gtemp;
                                                    (yyvsp[-6].nptr) -> TYPE = Gtemp -> TYPE;
                                                }
                                            }
                                        }
                                            head = TreeCreate(TypeLookup("integer"),NODE_ALLOC1,NULL,0,NULL,NULL,(yyvsp[-2].nptr),NULL);
                                            (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_ASGN,NULL,0,NULL,(yyvsp[-6].nptr),head,NULL);           
                                        }
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 908 "abstree.y" /* yacc.c:1646  */
    {
                                        /*printf(" in ALLOC ASGN \n");*/

                                        Ltemp = Llookup((yyvsp[-5].nptr) -> NAME);

                                        if(Ltemp != NULL)
                                        {
                                             if(Ltemp -> TYPE == TypeLookup("integer"))
                                                {
                                                    //$1 -> TYPE = TypeLookup("integer");
                                                    yyerror("Cannot ALLOC to integer variable\n");
                                                    exit(1);
                                                }
                                                else if(Ltemp -> TYPE == TypeLookup("boolean"))
                                                {
                                                    // $1 -> TYPE = TypeLookup("boolean"); 
                                                    yyerror("Cannot ALLOC to boolean variable\n");
                                                    exit(1);

                                                }
                                                else if(Ltemp -> TYPE == TypeLookup("darray"))
                                                {

                                                    yyerror("Cannot ALLOC to darray variable\n");
                                                    exit(1);
                                                }
                                                else
                                                    (yyvsp[-5].nptr) -> TYPE = TypeLookup(Ltemp -> TYPE);
                                        }
                                        else
                                        {
                                            Argtemp = Arglookup((yyvsp[-5].nptr) -> NAME);
                                            if(Argtemp != NULL)
                                            {
                                                if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                                {
                                                    //$1 -> TYPE = TypeLookup("integer");
                                                    yyerror("Cannot ALLOC to integer variable\n");
                                                    exit(1);
                                                }
                                                else if((Argtemp -> TYPE == TypeLookup("boolean")) || (Argtemp -> TYPE == TypeLookup("amp_boolean")))
                                                {
                                                    // $1 -> TYPE = TypeLookup("boolean"); 
                                                    yyerror("Cannot ALLOC to boolean variable\n");
                                                    exit(1);

                                                }
                                                else if(Argtemp -> TYPE == TypeLookup("darray"))
                                                 {
                                                    // $1 -> TYPE = TypeLookup("boolean"); 
                                                    yyerror("Cannot ALLOC to darray variable\n");
                                                    exit(1);

                                                }   
                                                else    
                                                    (yyvsp[-5].nptr) -> TYPE = TypeLookup(Argtemp -> TYPE);
                                            }

                                            else
                                            {
                                                Gtemp = Glookup((yyvsp[-5].nptr) -> NAME);
                                                if(Gtemp == NULL)
                                                {
                                                    yyerror("Un-declared variable\n");
                                                    printf("%s\n",(yyvsp[-5].nptr) -> NAME);
                                                    exit(1);
                                                }
                                                else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                                {
                                                    yyerror("conflict in ID NodeType : Expected udt Variable . Found Array\n");
                                                    printf("%s\n",(yyvsp[-5].nptr) -> NAME);
                                                    exit(1);
                                                }
                                                else if(Gtemp -> TYPE == TypeLookup("boolean") ||Gtemp -> TYPE == TypeLookup("integer"))
                                                {
                                                    yyerror("Cannot ALLOC to boolean or integer variable\n");
                                                    exit(1);
                                                }
                                                else if(Gtemp -> TYPE == TypeLookup("boolean") ||Gtemp -> TYPE == TypeLookup("integer"))
                                                {
                                                    yyerror("Cannot ALLOC to boolean or integer variable\n");
                                                    exit(1);
                                                }
                                                else if(Gtemp -> TYPE == TypeLookup("darray"))
                                                {
                                                    yyerror("Cannot ALLOC to darray variable\n");
                                                    exit(1);
                                                }
                                                else
                                                {   
                                                    (yyvsp[-5].nptr) -> Gentry = Gtemp;
                                                    (yyvsp[-5].nptr) -> TYPE = Gtemp -> TYPE;
                                                }
                                            }
                                        }
                                            head = TreeCreate(TypeLookup("integer"),NODE_ALLOC,NULL,0,NULL,NULL,NULL,NULL);
                                            (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_ASGN,NULL,0,NULL,(yyvsp[-5].nptr),head,NULL); 
                                    }
#line 2684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1006 "abstree.y" /* yacc.c:1646  */
    {
											// printf("FIELDASGN\n");
                                            head = (yyvsp[-5].nptr);
                                            while(head -> Ptr2 != NULL)
                                            {
                                                head = head -> Ptr2;
                                            }
                                            if(head -> TYPE == TypeLookup("integer") || head -> TYPE == TypeLookup("boolean") )
                                            {
                                               yyerror("Cannot ALLOC to boolean or integer variable\n");
                                                    exit(1);
                                            }
                                            // else if(head -> TYPE == TypeLookup("array_integer") || head -> TYPE == TypeLookup("array_boolean") )
                                            // {
                                            //         yyerror("Cannot ALLOC to array type variable\n");
                                            //         exit(1);
                                            // }
                                            else
                                            {
                                                head = TreeCreate(TypeLookup("integer"),NODE_ALLOC,NULL,0,NULL,NULL,NULL,NULL);
                                                (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_ASGN,NULL,0,NULL,(yyvsp[-5].nptr),head,NULL);        
                                            }
											

                                        }
#line 2714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1032 "abstree.y" /* yacc.c:1646  */
    {
											// printf("FASGN\n");
                                            head  = (yyvsp[-3].nptr);
                                            while(head -> Ptr2 != NULL)
                                            {
                                                head = head -> Ptr2;
                                            }
                                            head1 = (yyvsp[-1].nptr);
                                            while(head1 -> Ptr2 != NULL)
                                            {
                                                head1 = head1 -> Ptr2;
                                            }
                                            if(head1 -> TYPE == head -> TYPE)
                                                (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_ASGN,NULL,0,NULL,(yyvsp[-3].nptr),(yyvsp[-1].nptr),NULL);        
                                            else
                                            {
                                                yyerror("conflicting assignment types in field\n");
                                                exit(1);
                                            }
                                        }
#line 2739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1053 "abstree.y" /* yacc.c:1646  */
    {
                                                  Ltemp = Llookup((yyvsp[-5].nptr) -> NAME);
                                            if(Ltemp != NULL)
                                            {
                                                if(Ltemp -> TYPE != TypeLookup("darray") )
                                                {
                                                    yyerror("can not free a non darray\n");
                                                    exit(1);
                                                }
                                                (yyvsp[-5].nptr) -> TYPE = Ltemp -> TYPE;

                                            }
                                            else
                                            {
                                                Argtemp = Arglookup((yyvsp[-5].nptr) -> NAME);
                                                if(Argtemp != NULL)
                                                {
                                                    if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                                    {
                                                        //$1 -> TYPE = TypeLookup("integer");
                                                        yyerror("Cannot free integer variable\n");
                                                        exit(1);
                                                    }
                                                    else if((Argtemp -> TYPE == TypeLookup("boolean")) || (Argtemp -> TYPE == TypeLookup("amp_boolean")))
                                                    {
                                                        // $1 -> TYPE = TypeLookup("boolean"); 
                                                        yyerror("Cannot free  boolean variable\n");
                                                        exit(1);

                                                    }
                                                    if(Argtemp -> TYPE == TypeLookup("darray"))
                                                        (yyvsp[-5].nptr) -> TYPE = Argtemp -> TYPE;
                                                    else
                                                    {
                                                        yyerror("error\n");
                                                        exit(1);
                                                    }
                                                }

                                                else
                                                {
                                                    Gtemp = Glookup((yyvsp[-5].nptr) -> NAME);
                                                    if(Gtemp == NULL)
                                                    {
                                                        yyerror("Un-declared variable\n");
                                                        printf("%s\n",(yyvsp[-5].nptr) -> NAME);
                                                        exit(1);
                                                    }
                                                    else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                                    {
                                                        yyerror("can not free array\n");
                                                        printf("%s\n",(yyvsp[-5].nptr) -> NAME);
                                                        exit(1);
                                                    }
                                                    else if(Gtemp -> TYPE == TypeLookup("boolean") ||Gtemp -> TYPE == TypeLookup("integer"))
                                                    {
                                                        yyerror("Cannot free boolean or integer variable\n");
                                                        exit(1);
                                                    }
                                                    if(Argtemp -> TYPE == TypeLookup("darray"))
                                                        (yyvsp[-5].nptr) -> TYPE = Gtemp -> TYPE;
                                                    else
                                                    {
                                                        yyerror("error");
                                                        exit(1);
                                                    }
                                                }
                                            }  
                                            (yyval.nptr) = TreeCreate(TypeLookup("void"),NODE_FREE1,NULL,0,NULL,NULL,(yyvsp[-5].nptr),NULL);
                                        }
#line 2814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1123 "abstree.y" /* yacc.c:1646  */
    {
                                            Ltemp = Llookup((yyvsp[-2].nptr) -> NAME);
                                            if(Ltemp != NULL)
                                            {
                                                if(Ltemp -> TYPE == TypeLookup("integer") || Ltemp -> TYPE == TypeLookup("boolean"))
                                                {
                                                    yyerror("can not free a non udt\n");
                                                    exit(1);
                                                }
                                                (yyvsp[-2].nptr) -> TYPE = Ltemp -> TYPE;

                                            }
                                            else
                                            {
                                                Argtemp = Arglookup((yyvsp[-2].nptr) -> NAME);
                                                if(Argtemp != NULL)
                                                {
                                                    if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                                    {
                                                        //$1 -> TYPE = TypeLookup("integer");
                                                        yyerror("Cannot free integer variable\n");
                                                        exit(1);
                                                    }
                                                    else if((Argtemp -> TYPE == TypeLookup("boolean")) || (Argtemp -> TYPE == TypeLookup("amp_boolean")))
                                                    {
                                                        // $1 -> TYPE = TypeLookup("boolean"); 
                                                        yyerror("Cannot free  boolean variable\n");
                                                        exit(1);

                                                    }
                                                	(yyvsp[-2].nptr) -> TYPE = Argtemp -> TYPE;
                                                }

                                                else
                                                {
                                                    Gtemp = Glookup((yyvsp[-2].nptr) -> NAME);
                                                    if(Gtemp == NULL)
                                                    {
                                                        yyerror("Un-declared variable\n");
                                                        printf("%s\n",(yyvsp[-2].nptr) -> NAME);
                                                        exit(1);
                                                    }
                                                    else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                                    {
                                                        yyerror("can not free array\n");
                                                        printf("%s\n",(yyvsp[-2].nptr) -> NAME);
                                                        exit(1);
                                                    }
                                                    else if(Gtemp -> TYPE == TypeLookup("boolean") ||Gtemp -> TYPE == TypeLookup("integer"))
                                                    {
                                                        yyerror("Cannot free boolean or integer variable\n");
                                                        exit(1);
                                                    }
                                                	(yyvsp[-2].nptr) -> TYPE = Gtemp -> TYPE;

                                                }
                                            }  
                                            (yyval.nptr) = TreeCreate(TypeLookup("void"),NODE_FREE,NULL,0,NULL,NULL,(yyvsp[-2].nptr),NULL); 
                                        }
#line 2878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1182 "abstree.y" /* yacc.c:1646  */
    {
                                            head  = (yyvsp[-2].nptr);
                                            while(head -> Ptr2 != NULL)
                                            {
                                                head = head -> Ptr2;
                                            }
                                            
                                            if(head -> TYPE == TypeLookup("integer") || head -> TYPE == TypeLookup("boolean"))
                                            {
                                                yyerror("cannot FREE non-udt\n");
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TypeLookup("void"),NODE_FREE,NULL,0,NULL,NULL,(yyvsp[-2].nptr),NULL); 
                                    }
#line 2897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1196 "abstree.y" /* yacc.c:1646  */
    {
                                            head  = (yyvsp[-2].nptr);
                                            while(head -> Ptr2 != NULL)
                                            {
                                                head = head -> Ptr2;
                                            }
                                            
                                            if(head -> TYPE != TypeLookup("integer"))
                                            {
                                                yyerror("cannot READ a udt or boolean type\n");
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TypeLookup("void"),NODE_READ,NULL,0,NULL,NULL,(yyvsp[-2].nptr),NULL); 
                                    }
#line 2916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1210 "abstree.y" /* yacc.c:1646  */
    {
                                Ltemp = Llookup((yyvsp[-3].nptr) -> NAME);

                                if(Ltemp != NULL)
                                {
                                    if(Ltemp -> TYPE == TypeLookup("integer") || Ltemp -> TYPE == TypeLookup("boolean"))
                                    {
                                        yyerror("integers and booleans can not be assigned null\n");
                                        exit(1); 
                                    }
                                    (yyvsp[-3].nptr) -> TYPE = Ltemp -> TYPE;
                                }
                                else
                                {
                                    Argtemp = Arglookup((yyvsp[-3].nptr) -> NAME);
                                    if(Argtemp != NULL)
                                    {
                                        if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                        {
                                            yyerror("integers can not be assigned null\n");
                                            exit(1);
                                        }
                                        else if((Argtemp -> TYPE == TypeLookup("boolean")) || (Argtemp -> TYPE == TypeLookup("amp_boolean")))
                                        {
                                            yyerror("boolean can not be assigned null\n");
                                            exit(1); 
                                        }
                                        else
                                        {
                                        	(yyvsp[-3].nptr) -> TYPE = Argtemp -> TYPE;	
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
                                        else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                        {
                                            yyerror("conflict in ID NodeType : Expected Variable . Found Array\n");
                                            printf("%s\n",(yyvsp[-3].nptr) -> NAME);
                                            exit(1);
                                        }
                                        else
                                        {   
                                            if(Gtemp -> TYPE == TypeLookup("integer") || Gtemp -> TYPE == TypeLookup("boolean"))
                                            {
                                                yyerror("integers and booleans can not be assigned null\n");
                                                exit(1); 
                                            }
                                            (yyvsp[-3].nptr) -> Gentry = Gtemp;
                                            (yyvsp[-3].nptr) -> TYPE = Gtemp -> TYPE;  
                                        }
                                    }
                                }
                                (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_ASGN,NULL,0,NULL,(yyvsp[-3].nptr),(yyvsp[-1].nptr),NULL);
        					}
#line 2984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1273 "abstree.y" /* yacc.c:1646  */
    {
                                head  = (yyvsp[-3].nptr);
                                while(head -> Ptr2 != NULL)
                                {
                                    head = head -> Ptr2;
                                }
                                
                                if(head -> TYPE == TypeLookup("integer") || head -> TYPE == TypeLookup("boolean"))
                                {
                                    yyerror("cannot assign null to a non-udt\n");
                                    exit(1);
                                }
								(yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_ASGN,NULL,0,NULL,(yyvsp[-3].nptr),(yyvsp[-1].nptr),NULL); 
						    }
#line 3003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1288 "abstree.y" /* yacc.c:1646  */
    {
                            (yyvsp[-2].nptr) -> NODE = NODE_FIELD;
                            Ltemp = Llookup((yyvsp[-2].nptr) -> NAME);
                            if(Ltemp != NULL)
                            {
                                (yyvsp[-2].nptr) -> TYPE = Ltemp -> TYPE;

                                ftemp = FieldLookup((yyvsp[0].nptr) -> NAME,(yyvsp[-2].nptr) -> TYPE -> fields);
                                if(ftemp != NULL)
                                {
                                    (yyvsp[0].nptr) -> TYPE = ftemp -> type;
                                    (yyvsp[-2].nptr) -> Ptr2 = (yyvsp[0].nptr);                        
                                    (yyval.nptr) = (yyvsp[-2].nptr);
                                }
                                else
                                {
                                    yyerror("Un-declared field variable\n");
                                    exit(1);
                                }
                            }

                            else
                            {
                                Argtemp = Arglookup((yyvsp[-2].nptr) -> NAME);
                                if(Argtemp != NULL)
                                {
                                    if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                    {
                                        yyerror(" . opearation over integer type is not allowed\n");
                                        exit(1);
                                    }
                                    else if((Argtemp -> TYPE == TypeLookup("boolean")) || (Argtemp -> TYPE == TypeLookup("amp_boolean")))
                                    {
                                        yyerror(" . opearation over boolean type is not allowed\n");
                                        exit(1);
                                    }
                                    (yyvsp[-2].nptr) -> TYPE = Argtemp -> TYPE;                                        
                                    ftemp = FieldLookup((yyvsp[0].nptr) -> NAME,(yyvsp[-2].nptr) -> TYPE -> fields);
                                    if(ftemp != NULL)
                                    {
                                        (yyvsp[0].nptr) -> TYPE = ftemp -> type;
                                        (yyvsp[-2].nptr) -> Ptr2 = (yyvsp[0].nptr);                        
                                        (yyval.nptr) = (yyvsp[-2].nptr);
                                    }
                                    else
                                    {
                                        yyerror("Un-declared field variable\n");
                                        exit(1);
                                    }

                                }

                                else
                                {
                                    Gtemp = Glookup((yyvsp[-2].nptr) -> NAME);
                                    if(Gtemp == NULL)
                                    {
                                        yyerror("Un-declared variable\n");
                                        printf("%s\n",(yyvsp[-2].nptr) -> NAME);
                                        exit(1);
                                    }
                                    else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                    {
                                        yyerror(" . opearation over arrays found\n");
                                        printf("%s\n",(yyvsp[-2].nptr) -> NAME);
                                        exit(1);
                                    }
                                    else if(Gtemp -> TYPE == TypeLookup("boolean") ||Gtemp -> TYPE == TypeLookup("integer") )
                                    {
                                        yyerror(" . opearation over integer or boolean found\n");
                                        printf("%s\n",(yyvsp[-2].nptr) -> NAME);
                                        exit(1);
                                    }
                                    else
                                    {   
                                        (yyvsp[-2].nptr) -> Gentry = Gtemp;   
                                        (yyvsp[-2].nptr) -> TYPE = Gtemp -> TYPE;
                            			// printf("%s\n",Gtemp -> TYPE -> NAME);
                                        // printf("%s\n",$3 -> NAME );
                                        ftemp = FieldLookup((yyvsp[0].nptr) -> NAME,(yyvsp[-2].nptr) -> TYPE -> fields);
                                        if(ftemp != NULL)
                                        {
                                            (yyvsp[0].nptr) -> TYPE = ftemp -> type;
                            			// 	printf("%s\n",ftemp -> type -> NAME);
                                            (yyvsp[-2].nptr) -> Ptr2 = (yyvsp[0].nptr);                        
                                        }
                                        else
                                        {
                                            yyerror("Un-declared field variable\n");
                                            exit(1);
                                        }

                                        (yyval.nptr) = (yyvsp[-2].nptr);
                                    }
                                }
                            }
                        }
#line 3105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1385 "abstree.y" /* yacc.c:1646  */
    {
                            head1 = head = (yyvsp[-2].nptr);
                            while(head -> Ptr2 != NULL)
                            {
                                head = head -> Ptr2;
                            }
                            temp1 = head -> TYPE;
                            	// printf("%s\n",temp1 -> NAME);
                            if(temp1 != TypeLookup("boolean") && temp1 != TypeLookup("integer"))
                            {
                                ftemp = FieldLookup((yyvsp[0].nptr) -> NAME,temp1 -> fields);
          						// printf("IN FIELD\n");
                                if(ftemp != NULL)
                                {
                                    (yyvsp[0].nptr) -> TYPE = ftemp -> type;
                                    head -> Ptr2 = (yyvsp[0].nptr);
                                    (yyval.nptr) = head1;
                                }
                                else
                                {
                                    yyerror("Un-declared field variable\n");
                                    exit(1);
                                }
                            }
                            else
                            {
                                yyerror("Illegal access of identifier\n");
                                exit(1);
                            }
                        }
#line 3140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1417 "abstree.y" /* yacc.c:1646  */
    {
                                    // printf("FIRST : %d\n",$1 -> NODE);
                                    exprcount = 1;
                                    (yyval.nptr) = (yyvsp[0].nptr);
                                }
#line 3150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1422 "abstree.y" /* yacc.c:1646  */
    {
                                        // printf("SECOND : %d\n",$3 -> NODE);         
                                        indicator = 1;
                                        exprcount++;
                                        head = (struct Tnode *)malloc(sizeof(struct Tnode ));
                                        head -> NODE = NODE_EXPR;
                                        head -> Ptr1 = (yyvsp[0].nptr);
                                        // $3 -> VALUE = ++tree_iter;
                                        //printf("----------------------\n");
                                        //printf("%d\n",head->Ptr1->NODE);
                                        head -> Ptr2 = (yyvsp[-2].nptr);
                                        //printf("%d\n",head->Ptr2->NODE);
                                       // printf("----------------------\n");
                                        (yyval.nptr) = head;
                                    }
#line 3170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1440 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("PLUS\n");*/
                                // printf("%s\n",$1 -> TYPE -> NAME );
                                // printf("%d\n",$1 ->  NODE );
                                // printf("%s\n",$3 -> TYPE -> NAME );
                                // printf("%s\n",$3 -> VALUE );
                                if((yyvsp[-2].nptr) -> TYPE == TypeLookup("integer") && (yyvsp[0].nptr) -> TYPE == TypeLookup("integer"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("integer"), NODE_PLUS , NULL,0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in PLUS\n");
                                    exit(1);
                                }
                            }
#line 3191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1456 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("MINUS\n");*/
                                if((yyvsp[-2].nptr) -> TYPE != TypeLookup("boolean") && (yyvsp[0].nptr) -> TYPE != TypeLookup("boolean"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("integer"), NODE_MINUS , NULL,0 , NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MINUS\n");
                                    exit(1);
                                }
                            }
#line 3208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1468 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("MUL\n");*/
                                if((yyvsp[-2].nptr) -> TYPE != TypeLookup("boolean") && (yyvsp[0].nptr) -> TYPE != TypeLookup("boolean"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("integer"), NODE_MUL , NULL,0 , NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MUL\n");
                                    exit(1);
                                }
                            }
#line 3225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1480 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("DIV\n");*/
                                if((yyvsp[-2].nptr) -> TYPE != TypeLookup("boolean") && (yyvsp[0].nptr) -> TYPE != TypeLookup("boolean"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("integer"), NODE_DIV , NULL,0 , NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MUL\n");
                                    exit(1);
                                }
                            }
#line 3242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1492 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("MOD\n");*/
                                if((yyvsp[-2].nptr) -> TYPE != TypeLookup("boolean") && (yyvsp[0].nptr) -> TYPE != TypeLookup("boolean"))
                               	{
                                    (yyval.nptr) = TreeCreate(TypeLookup("integer"), NODE_MOD , NULL,0 , NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MUL\n");
                                    exit(1);
                                }
                            }
#line 3259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1504 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("LT\n");*/
                                if((yyvsp[-2].nptr) -> TYPE != TypeLookup("boolean") && (yyvsp[0].nptr) -> TYPE != TypeLookup("boolean"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("boolean"), NODE_LT , NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in LT\n");
                                    exit(1);
                                }
                            }
#line 3276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1516 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("LT\n");*/
                                if((yyvsp[-2].nptr) -> TYPE != TypeLookup("boolean") && (yyvsp[0].nptr) -> TYPE != TypeLookup("boolean"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("boolean"), NODE_LE , NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in LE\n");
                                    exit(1);
                                }
                            }
#line 3293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1528 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("GT\n");*/
                                if((yyvsp[-2].nptr) -> TYPE != TypeLookup("boolean") && (yyvsp[0].nptr) -> TYPE != TypeLookup("boolean"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("boolean"), NODE_GT , NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in GT\n");
                                    exit(1);
                                }
                            }
#line 3310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1540 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("GT\n");*/
                                if((yyvsp[-2].nptr) -> TYPE != TypeLookup("boolean") && (yyvsp[0].nptr) -> TYPE !=  TypeLookup("boolean"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("boolean"), NODE_GE , NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in GE\n");
                                    exit(1);
                                }
                            }
#line 3327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1552 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("DEQ\n");*/
                                if((yyvsp[-2].nptr) -> TYPE != TypeLookup("boolean") && (yyvsp[0].nptr) -> TYPE != TypeLookup("boolean"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("boolean"), NODE_DEQ, NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in DEQ\n");
                                    exit(1);
                                }
                            }
#line 3344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1564 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("NEQ\n");*/
                                if((yyvsp[-2].nptr) -> TYPE != TypeLookup("boolean") && (yyvsp[0].nptr) -> TYPE != TypeLookup("boolean"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("boolean"), NODE_NEQ, NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in NEQ\n");
                                    exit(1);
                                }
                            }
#line 3361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1576 "abstree.y" /* yacc.c:1646  */
    {
                                if((yyvsp[-2].nptr) -> TYPE == TypeLookup("boolean") && (yyvsp[0].nptr) -> TYPE == TypeLookup("boolean"))
                                {
                                    (yyval.nptr) = TreeCreate((yyvsp[-2].nptr) -> TYPE, NODE_AND, NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in AND\n");
                                    exit(1);
                                }   
                            }
#line 3377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1587 "abstree.y" /* yacc.c:1646  */
    {
                                if((yyvsp[-2].nptr) -> TYPE == TypeLookup("boolean") && (yyvsp[0].nptr) -> TYPE == TypeLookup("boolean"))
                                {
                                    (yyval.nptr) = TreeCreate((yyvsp[-2].nptr) -> TYPE, NODE_OR, NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in OR\n");
                                    exit(1);
                                }   
                            }
#line 3393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1598 "abstree.y" /* yacc.c:1646  */
    {

                                if((yyvsp[0].nptr) -> TYPE == TypeLookup("boolean"))
                                {
                                    (yyval.nptr) = TreeCreate((yyvsp[0].nptr) -> TYPE, NODE_NOT, NULL, 0, NULL, NULL, (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand type in NOT\n");
                                    exit(1);
                                }   
                            }
#line 3410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1610 "abstree.y" /* yacc.c:1646  */
    {
                                (yyval.nptr) = (yyvsp[-1].nptr);
                            }
#line 3418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1613 "abstree.y" /* yacc.c:1646  */
    {
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 3426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1617 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("NUM\n");*/
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 3435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1621 "abstree.y" /* yacc.c:1646  */
    {
                                // printf("ID\n");
                                Ltemp = Llookup((yyvsp[0].nptr) -> NAME);

                                if(Ltemp != NULL)
                                {
                                    (yyvsp[0].nptr) -> TYPE = Ltemp -> TYPE;
                                    (yyval.nptr) = (yyvsp[0].nptr);
                                }

                                else
                                {
                                    Argtemp = Arglookup((yyvsp[0].nptr) -> NAME);
                                    if(Argtemp != NULL)
                                    {
                                        if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                        {
                                            (yyvsp[0].nptr) -> TYPE = TypeLookup("integer");
                                        }
                                        else if((Argtemp -> TYPE == TypeLookup("boolean")) || (Argtemp -> TYPE == TypeLookup("amp_boolean")))
                                        {
                                            (yyvsp[0].nptr) -> TYPE = TypeLookup("boolean"); 
                                        }
                                        else
                                        {
                                            (yyvsp[0].nptr) -> TYPE = Argtemp -> TYPE;
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
                                        else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                        {
                                            yyerror("conflict in ID NodeType : Expected Variable . Found Array\n");
                                            printf("%s\n",(yyvsp[0].nptr) -> NAME);
                                            exit(1);
                                        }
                                        else
                                        {   
                                            (yyvsp[0].nptr) -> Gentry = Gtemp;
                                            (yyvsp[0].nptr) -> TYPE = Gtemp -> TYPE;
                                            (yyval.nptr) = (yyvsp[0].nptr);
                                        }
                                    }
                                 }
                            }
#line 3496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1678 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("ID[expr]\n");*/
                                Gtemp = Glookup((yyvsp[-3].nptr) -> NAME);
                                temp1 = TypeLookup("integer");
                                temp2 = TypeLookup("boolean");

                                if(Gtemp == NULL)
                                {
                                    yyerror("Un-declared array\n");
                                    printf("%s\n",(yyvsp[-3].nptr) -> NAME);
                                    exit(1);
                                }
                                else if(Gtemp -> TYPE == temp2 ||Gtemp -> TYPE == temp1 )
                                {
                                    yyerror("conflict in ID NodeType : Expected Array , Found Variable\n");
                                    printf("%s\n",(yyvsp[-3].nptr) -> NAME);
                                    exit(1);
                                }
                                else if((yyvsp[-1].nptr) -> TYPE == temp2)
                                {
                                    yyerror("Expected value , Found boolean\n");
                                    printf("%s\n",(yyvsp[-3].nptr) -> NAME);
                                    exit(1);
                                }
                                else
                                {   
                                    temp1 = TypeLookup("array_integer");
                                    temp2 = TypeLookup("array_boolean");
                                    (yyvsp[-3].nptr) -> Gentry = Gtemp;
                                    if(Gtemp -> TYPE == temp1)
                                    {
                                        (yyvsp[-3].nptr) -> TYPE = TypeLookup("integer");
                                    }
                                    else if(Gtemp -> TYPE == temp2)
                                    {
                                        (yyvsp[-3].nptr) -> TYPE = TypeLookup("boolean");
                                    }
                                    (yyval.nptr) = TreeCreate((yyvsp[-3].nptr) -> TYPE,NODE_ARRAY,NULL,0,NULL,(yyvsp[-3].nptr),(yyvsp[-1].nptr),NULL);
                                }
                            }
#line 3541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1718 "abstree.y" /* yacc.c:1646  */
    {
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 3549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1721 "abstree.y" /* yacc.c:1646  */
    {
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 3557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1725 "abstree.y" /* yacc.c:1646  */
    {
                                Gtemp = Glookup((yyvsp[-3].nptr) -> NAME);

                                if(Gtemp == NULL)
                                {
                                    yyerror("Un-declared function \n");
                                    exit(1);
                                }

                                if(Gtemp -> SIZE != -1)
                                {
                                    yyerror("conflict in ID NodeType : Expected Function \n");
                                    printf("%s\n",(yyvsp[-3].nptr) -> NAME);
                                    exit(1);
                                }
                                else
                                {   
                                    (yyvsp[-3].nptr) -> Gentry = Gtemp;
                                    (yyvsp[-3].nptr) -> TYPE = Gtemp -> TYPE;
                                }

                                (yyvsp[-1].nptr) -> Ptr3 = Gtemp -> Arglist;
                                Arg_callee = Gtemp -> Arglist;
                                while(Arg_callee != NULL)
                                {
                                    exprcount--;
                                    Arg_callee = Arg_callee -> NEXT;
                                }
                                if(exprcount)
                                {
                                    yyerror("Unequal number of arguments\n");
                                    exit(1);
                                }
                                //differentiating b/w one and more than one arguments
                                if(indicator == 1)
                                {
                                    (yyval.nptr) = TreeCreate((yyvsp[-3].nptr) -> TYPE,NODE_FUNC,(yyvsp[-3].nptr) -> NAME,0,Gtemp -> Arglist,NULL,(yyvsp[-1].nptr),NULL);
                                    indicator = 0;
                                }

                                else
                                    (yyval.nptr) = TreeCreate((yyvsp[-3].nptr) -> TYPE,NODE_FUNC,(yyvsp[-3].nptr) -> NAME,0,Gtemp -> Arglist,NULL,NULL,(yyvsp[-1].nptr));
                                }
#line 3605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1769 "abstree.y" /* yacc.c:1646  */
    {
                                    Gtemp = Glookup((yyvsp[-2].nptr) -> NAME);

                                    if(Gtemp == NULL)
                                    {
                                        yyerror("Un-declared function \n");
                                        exit(1);
                                    }

                                    if(Gtemp -> SIZE != -1)
                                    {
                                        yyerror("conflict in ID NodeType : Expected Function \n");
                                        printf("%s\n",(yyvsp[-2].nptr) -> NAME);
                                        exit(1);
                                    }
                                    else
                                    {   
                                        (yyvsp[-2].nptr) -> Gentry = Gtemp;
                                        (yyvsp[-2].nptr) -> TYPE = Gtemp -> TYPE;
                                    }
                                        (yyval.nptr) = TreeCreate((yyvsp[-2].nptr) -> TYPE,NODE_FUNC,(yyvsp[-2].nptr) -> NAME,0,Gtemp -> Arglist,NULL,NULL,NULL);
                                }
#line 3632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1792 "abstree.y" /* yacc.c:1646  */
    {
   						    Ltemp = Llookup((yyvsp[-1].nptr) -> NAME);
                            if(Ltemp != NULL)
                            {
                            	    if(Ltemp -> TYPE == TypeLookup("integer"))
                                    {
                                        yyerror("can not assign null to integer\n");
                                        exit(1);
                                    }
                                    else if(Ltemp -> TYPE == TypeLookup("boolean"))
                                    {
                                        yyerror("can not assign null to boolean\n");
                                        exit(1);
                                    }
                                    else
                                    {
	                                    (yyvsp[-1].nptr) -> TYPE = Ltemp -> TYPE;
	                                }
                            }
                            else
                            {
                                Argtemp = Arglookup((yyvsp[-1].nptr) -> NAME);
                                if(Argtemp != NULL)
                                {
                                    if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                    {
                                        yyerror("can not assign null to integer\n");
                                        exit(1);
                                    }
                                    else if((Argtemp -> TYPE == TypeLookup("boolean")) || (Argtemp -> TYPE == TypeLookup("amp_boolean")))
                                    {
                                        yyerror("can not assign null to boolean\n");
                                        exit(1);
                                    }
                                    else
                                    {
                                    	(yyvsp[-1].nptr) -> TYPE = Argtemp -> TYPE;
                                    }
                                }

                                else
                                {

                                    Gtemp = Glookup((yyvsp[-1].nptr) -> NAME);
                                    if(Gtemp == NULL)
                                    {
                                        yyerror("Un-declared variable\n");
                                        printf("%s\n",(yyvsp[-1].nptr) -> NAME);
                                        exit(1);
                                    }
                                    else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                    {
                                        yyerror("conflict in ID NodeType : Expected Variable . Found Array\n");
                                        printf("%s\n",(yyvsp[-1].nptr) -> NAME);
                                        exit(1);
                                    }
                                    if(Gtemp -> TYPE == TypeLookup("integer"))
                                    {
                                        yyerror("can not assign null to integer\n");
                                        exit(1);
                                    }
                                    else if(Gtemp -> TYPE == TypeLookup("boolean"))
                                    {
                                        yyerror("can not assign null to boolean\n");
                                        exit(1);
                                    }
                                    else
                                    {   
                                        (yyvsp[-1].nptr) -> Gentry = Gtemp;
                                        (yyvsp[-1].nptr) -> TYPE = Gtemp -> TYPE;
                                       
                                    }
                                }
                            }
	                    	(yyval.nptr) = TreeCreate(TypeLookup("boolean"), NODE_DEQ, NULL, 0, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
		    		}
#line 3713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1868 "abstree.y" /* yacc.c:1646  */
    {
    					Ltemp = Llookup((yyvsp[-1].nptr) -> NAME);
                        if(Ltemp != NULL)
                        {
                        	    if(Ltemp -> TYPE == TypeLookup("integer"))
                                {
                                    yyerror("can not assign null to integer in NEQ\n");
                                    exit(1);
                                }
                                else if(Ltemp -> TYPE == TypeLookup("boolean"))
                                {
                                    yyerror("can not assign null to boolean in NEQ\n");
                                    exit(1);
                                }
                                else
                                {
                                    (yyvsp[-1].nptr) -> TYPE = Ltemp -> TYPE;
                                }
                        }
                        else
                        {
                            Argtemp = Arglookup((yyvsp[-1].nptr) -> NAME);
                            if(Argtemp != NULL)
                            {
                                if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                {
                                    yyerror("can not assign null to integer in NEQ\n");
                                    exit(1);
                                }
                                else if((Argtemp -> TYPE == TypeLookup("boolean")) || (Argtemp -> TYPE == TypeLookup("amp_boolean")))
                                {
                                    yyerror("can not assign null to boolean in NEQ\n");
                                    exit(1);
                                }
                                else
                                {
                                	(yyvsp[-1].nptr) -> TYPE = Argtemp -> TYPE;
                                }
                            }

                            else
                            {

                                Gtemp = Glookup((yyvsp[-1].nptr) -> NAME);
                                if(Gtemp == NULL)
                                {
                                    yyerror("Un-declared variable\n");
                                    printf("%s\n",(yyvsp[-1].nptr) -> NAME);
                                    exit(1);
                                }
                                else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                {
                                    yyerror("conflict in ID NodeType : Expected Variable . Found Array in NEQ\n");
                                    printf("%s\n",(yyvsp[-1].nptr) -> NAME);
                                    exit(1);
                                }
                                if(Gtemp -> TYPE == TypeLookup("integer"))
                                {
                                    yyerror("can not assign null to integer in NEQ\n");
                                    exit(1);
                                }
                                else if(Gtemp -> TYPE == TypeLookup("boolean"))
                                {
                                    yyerror("can not assign null to boolean in NEQ\n");
                                    exit(1);
                                }
                                else
                                {   
                                    (yyvsp[-1].nptr) -> Gentry = Gtemp;
                                    (yyvsp[-1].nptr) -> TYPE = Gtemp -> TYPE;
                                   
                                }
                            }
                        }
                        	(yyval.nptr) = TreeCreate(TypeLookup("boolean"), NODE_NEQ, NULL, 0, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
        				}
#line 3794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1944 "abstree.y" /* yacc.c:1646  */
    {
        					if((yyvsp[-1].nptr) -> TYPE != TypeLookup("boolean") && (yyvsp[-1].nptr) -> TYPE != TypeLookup("integer"))
                            {
                                (yyval.nptr) = TreeCreate(TypeLookup("boolean"), NODE_DEQ, NULL, 0, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                            }
                            else
                            {
                                yyerror("conflict in operand types in DEQ\n");
                                exit(1);
                            }
        				}
#line 3810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1955 "abstree.y" /* yacc.c:1646  */
    {
                            
                            if((yyvsp[-1].nptr) -> TYPE != TypeLookup("boolean") && (yyvsp[-1].nptr) -> TYPE != TypeLookup("integer"))
                            {
                                (yyval.nptr) = TreeCreate(TypeLookup("boolean"), NODE_NEQ, NULL, 0, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                            }
                            else
                            {
                                yyerror("conflict in operand types in NEQ\n");
                                exit(1);
                            }
                            
        				}
#line 3828 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3832 "y.tab.c" /* yacc.c:1646  */
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
#line 1970 "abstree.y" /* yacc.c:1906  */


void yyerror(char const *s) 
{ 
    printf("yyerror  %s\n",s); 
    return ;
} 

int main(int argc,char* argv[]) 
{ 
    TypeInstall("integer",NULL);
    TypeInstall("boolean",NULL);
    TypeInstall("array_integer",NULL);
    TypeInstall("array_boolean",NULL);
    TypeInstall("amp_integer",NULL);
    TypeInstall("amp_boolean",NULL);
    TypeInstall("void",NULL);
    TypeInstall("darray",NULL);
    // printf("installation of TypeTable\n");
    
    if(argc > 1)
    {
        fp = fopen(argv[1],"r");
        if(fp)
            yyin = fp;
    }    
    yyparse(); 
    // printf("installation of TypeTable\n");
    return 1; 
}
