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
    RETURN = 295,
    ALLOC = 296,
    FREE = 297,
    TYPEDEF = 298,
    TYPE1 = 299,
    ENDTYPE = 300
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
#define ALLOC 296
#define FREE 297
#define TYPEDEF 298
#define TYPE1 299
#define ENDTYPE 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 30 "abstree.y" /* yacc.c:355  */

    struct Tnode * nptr;

#line 228 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 243 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   469

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  222

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
      51,    52,     2,     2,    53,     2,    54,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    81,    81,    89,   128,   129,   132,   133,   135,   138,
     143,   151,   152,   155,   157,   158,   159,   169,   187,   206,
     207,   209,   211,   220,   234,   251,   260,   274,   294,   298,
     302,   314,   315,   316,   328,   329,   330,   333,   336,   346,
     367,   381,   404,   405,   408,   475,   479,   483,   487,   491,
     495,   506,   519,   552,   559,   580,   591,   599,   679,   719,
     791,   828,   849,   859,   869,   879,   958,   980,  1035,  1038,
    1042,  1137,  1167,  1172,  1189,  1201,  1214,  1227,  1240,  1253,
    1266,  1279,  1291,  1303,  1315,  1327,  1338,  1349,  1361,  1386,
    1390,  1394,  1455,  1495,  1498,  1502
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
  "OR", "AMP", "MAIN", "RETURN", "ALLOC", "FREE", "TYPEDEF", "TYPE1",
  "ENDTYPE", "'{'", "'}'", "';'", "'['", "']'", "'('", "')'", "','", "'.'",
  "$accept", "program", "TypeDefBlock", "TypeDefList", "TypeDef",
  "TypeDefhead", "TypeDefBody", "FieldDeclList", "FieldDecl", "TypeName",
  "gdeclaration", "gdlist", "gdec", "vlist", "Type", "FType", "arglist",
  "arg", "fvlist", "fdeflist", "fdef", "ldeclaration", "ldlist", "ldec",
  "lvlist", "mainblock", "body", "retstmt", "slist", "stmt", "FIELD",
  "exprlist", "expr", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   123,   125,    59,    91,
      93,    40,    41,    44,    46
};
# endif

#define YYPACT_NINF -187

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-187)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -31,   -17,    29,    44,    60,    74,  -187,    34,  -187,    75,
      75,  -187,  -187,  -187,    83,  -187,  -187,  -187,  -187,    68,
    -187,    70,     0,    75,  -187,  -187,  -187,  -187,  -187,    37,
    -187,    82,  -187,  -187,   107,   -13,    53,    61,  -187,  -187,
    -187,  -187,    92,   117,   112,  -187,   137,   112,    97,  -187,
     100,  -187,  -187,  -187,    28,    25,  -187,   108,    40,   126,
    -187,  -187,   149,   113,   112,  -187,   178,   112,   127,   166,
    -187,    32,  -187,   151,    54,   166,   112,   171,  -187,   201,
    -187,  -187,   171,   214,    71,  -187,   398,   155,  -187,   174,
    -187,    41,  -187,  -187,     6,   172,   173,   175,   182,   189,
     358,  -187,     9,  -187,  -187,  -187,   221,    27,    30,   242,
     243,    30,    30,    30,   244,    30,   215,  -187,   209,   253,
    -187,  -187,   120,  -187,  -187,    30,   210,    30,   206,   289,
     222,  -187,   -32,   140,   118,   131,   170,   156,   157,   324,
    -187,   211,  -187,    30,    30,   146,   212,   183,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      30,  -187,   254,    30,   217,   218,   219,   248,   245,   227,
     228,  -187,   225,   237,    76,   420,   230,  -187,   435,   198,
     198,   198,   435,   146,   146,   146,   146,   146,   146,   435,
     435,    30,   274,  -187,  -187,  -187,   398,   398,  -187,  -187,
     235,  -187,  -187,    30,  -187,   337,   232,    72,   372,  -187,
     420,  -187,   250,   398,   251,   252,  -187,   382,  -187,  -187,
     261,  -187
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,    18,     0,     0,     7,     0,     1,     0,
       0,     9,     4,     6,     0,     8,    30,    28,    29,     0,
      19,     0,     0,     0,    42,     3,    16,    14,    15,     0,
      12,     0,    17,    20,    22,     0,     0,     0,    43,     2,
      10,    11,     0,     0,    36,    21,     0,    36,     0,    13,
       0,    33,    31,    32,     0,     0,    34,    25,     0,     0,
      23,    38,     0,    37,     0,    24,     0,    36,     0,    46,
      39,     0,    35,     0,     0,    46,     0,     0,    40,     0,
      26,    27,     0,     0,     0,    47,     0,     0,    41,     0,
      50,     0,    45,    48,     0,     0,     0,     0,     0,     0,
       0,    56,     0,    52,    44,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
      51,    90,    91,    93,    94,     0,     0,     0,    89,     0,
       0,    70,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,    71,     0,     0,    87,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,    72,     0,    88,    74,    76,
      77,    78,    75,    79,    81,    83,    84,    80,    82,    85,
      86,     0,     0,    59,    69,    61,     0,     0,    67,    68,
       0,    92,    95,     0,    65,     0,     0,     0,     0,    66,
      73,    58,     0,     0,     0,     0,    60,     0,    62,    64,
       0,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -187,  -187,  -187,  -187,   280,  -187,  -187,  -187,   263,  -187,
    -187,  -187,   283,  -187,     2,   -68,   -44,   229,  -187,  -187,
     290,   239,  -187,   231,  -187,   293,   236,  -187,  -186,   -99,
     -86,  -187,  -106
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,     7,    15,    29,    30,    31,
      10,    19,    20,    35,    21,    54,    55,    56,    63,    23,
      24,    77,    84,    85,    91,    25,    87,   116,   100,   101,
     128,   174,   129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     102,   117,   130,    58,    36,   134,   135,   136,    83,   139,
     207,   208,    22,     1,   102,   107,    83,   163,   118,   145,
     164,   147,   109,    74,   133,    22,     4,   217,   138,     8,
     121,   122,    61,   121,   122,    45,    78,   173,   175,    37,
      46,    26,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   108,   123,   192,   124,   123,
     109,   124,   125,   119,    11,   125,    62,    27,   126,    28,
      79,     9,    16,    64,    34,    51,    94,    65,   127,    16,
      14,   127,    95,    96,    40,   205,    42,    26,    64,   105,
     213,    97,    68,   214,   106,    98,    32,   210,    17,    92,
      18,    52,    64,    53,    47,    17,    81,    18,   117,   117,
     102,   102,    48,    27,    99,    28,    51,     4,   117,    12,
      50,   102,   102,   148,   149,   150,   151,   102,   202,   203,
     152,   102,   153,   154,   155,   156,   148,   149,   150,   151,
      49,    57,    52,   152,    53,   153,   154,   155,   156,    59,
      60,   157,   158,    70,   159,   160,    43,    66,    44,    67,
      -1,    -1,    -1,    -1,   157,   158,    71,   159,   160,   143,
     166,   144,    69,    75,   109,   148,   149,   150,   151,    -1,
      -1,    73,   152,   167,   153,   154,   155,   156,   148,   149,
     150,   151,   165,    76,   119,   152,    86,   153,   154,   155,
     156,    80,   103,   157,   158,    88,   159,   160,   169,   170,
     109,   119,   153,   154,   155,   156,   157,   158,    90,   159,
     160,   104,   168,   110,   111,   120,   112,   148,   149,   150,
     151,   157,   158,   113,   152,   177,   153,   154,   155,   156,
     114,   140,   148,   149,   150,   151,   131,   132,   137,   152,
     141,   153,   154,   155,   156,   157,   158,   142,   159,   160,
     119,   146,   172,   191,   176,   193,   194,   195,   196,   197,
     157,   158,   162,   159,   160,   198,   199,   200,   204,   148,
     149,   150,   151,   209,   212,    13,   152,   201,   153,   154,
     155,   156,    41,    72,   148,   149,   150,   151,   216,   218,
     219,   152,    33,   153,   154,   155,   156,   157,   158,   221,
     159,   160,     0,    38,    82,    93,    39,     0,    89,     0,
       0,     0,   157,   158,   206,   159,   160,     0,     0,   148,
     149,   150,   151,     0,     0,     0,   152,   161,   153,   154,
     155,   156,   148,   149,   150,   151,     0,     0,     0,   152,
       0,   153,   154,   155,   156,     0,     0,   157,   158,     0,
     159,   160,    94,     0,     0,     0,     0,     0,    95,    96,
     157,   158,   171,   159,   160,     0,    94,    97,     0,     0,
       0,    98,    95,    96,     0,   211,    94,     0,     0,     0,
       0,    97,    95,    96,   215,    98,     0,     0,   115,     0,
      99,    97,    94,   220,     0,    98,     0,     0,    95,    96,
       0,     0,     0,     0,    99,     0,     0,    97,     0,     0,
       0,    98,     0,     0,    99,   148,   149,   150,   151,     0,
       0,     0,   152,     0,   153,   154,   155,   156,     0,     0,
      99,   149,   150,   151,     0,     0,     0,     0,     0,   153,
     154,   155,   156,   157,   158,     0,   159,   160,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,   158
};

static const yytype_int16 yycheck[] =
{
      86,   100,   108,    47,     4,   111,   112,   113,    76,   115,
     196,   197,    10,    44,   100,     9,    84,    49,     9,   125,
      52,   127,    54,    67,   110,    23,    43,   213,   114,     0,
       3,     4,     4,     3,     4,    48,     4,   143,   144,    39,
      53,     4,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,    49,    29,   163,    31,    29,
      54,    31,    35,    54,     4,    35,    38,    30,    41,    32,
      38,    27,     4,    48,     4,     4,     4,    52,    51,     4,
      46,    51,    10,    11,    47,   191,     4,     4,    48,    48,
      18,    19,    52,    21,    53,    23,    28,   203,    30,    28,
      32,    30,    48,    32,    51,    30,    52,    32,   207,   208,
     196,   197,    51,    30,    42,    32,     4,    43,   217,    45,
       3,   207,   208,     5,     6,     7,     8,   213,    52,    53,
      12,   217,    14,    15,    16,    17,     5,     6,     7,     8,
      48,     4,    30,    12,    32,    14,    15,    16,    17,    52,
      50,    33,    34,     4,    36,    37,    49,    49,    51,    51,
      14,    15,    16,    17,    33,    34,    53,    36,    37,    49,
      52,    51,    46,    46,    54,     5,     6,     7,     8,    33,
      34,     3,    12,    52,    14,    15,    16,    17,     5,     6,
       7,     8,    52,    27,    54,    12,    25,    14,    15,    16,
      17,    50,    47,    33,    34,     4,    36,    37,    52,    52,
      54,    54,    14,    15,    16,    17,    33,    34,     4,    36,
      37,    47,    52,    51,    51,     4,    51,     5,     6,     7,
       8,    33,    34,    51,    12,    52,    14,    15,    16,    17,
      51,    26,     5,     6,     7,     8,     4,     4,     4,    12,
      41,    14,    15,    16,    17,    33,    34,     4,    36,    37,
      54,    51,    51,     9,    52,    48,    48,    48,    20,    24,
      33,    34,    50,    36,    37,    48,    48,    52,    48,     5,
       6,     7,     8,    48,    52,     5,    12,    50,    14,    15,
      16,    17,    29,    64,     5,     6,     7,     8,    48,    48,
      48,    12,    19,    14,    15,    16,    17,    33,    34,    48,
      36,    37,    -1,    23,    75,    84,    23,    -1,    82,    -1,
      -1,    -1,    33,    34,    50,    36,    37,    -1,    -1,     5,
       6,     7,     8,    -1,    -1,    -1,    12,    48,    14,    15,
      16,    17,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    14,    15,    16,    17,    -1,    -1,    33,    34,    -1,
      36,    37,     4,    -1,    -1,    -1,    -1,    -1,    10,    11,
      33,    34,    48,    36,    37,    -1,     4,    19,    -1,    -1,
      -1,    23,    10,    11,    -1,    48,     4,    -1,    -1,    -1,
      -1,    19,    10,    11,    22,    23,    -1,    -1,    40,    -1,
      42,    19,     4,    21,    -1,    23,    -1,    -1,    10,    11,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    19,    -1,    -1,
      -1,    23,    -1,    -1,    42,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    -1,    14,    15,    16,    17,    -1,    -1,
      42,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    33,    34,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    56,    57,    43,    58,    59,    60,     0,    27,
      65,     4,    45,    59,    46,    61,     4,    30,    32,    66,
      67,    69,    69,    74,    75,    80,     4,    30,    32,    62,
      63,    64,    28,    67,     4,    68,     4,    39,    75,    80,
      47,    63,     4,    49,    51,    48,    53,    51,    51,    48,
       3,     4,    30,    32,    70,    71,    72,     4,    71,    52,
      50,     4,    38,    73,    48,    52,    49,    51,    52,    46,
       4,    53,    72,     3,    71,    46,    27,    76,     4,    38,
      50,    52,    76,    70,    77,    78,    25,    81,     4,    81,
       4,    79,    28,    78,     4,    10,    11,    19,    23,    42,
      83,    84,    85,    47,    47,    48,    53,     9,    49,    54,
      51,    51,    51,    51,    51,    40,    82,    84,     9,    54,
       4,     3,     4,    29,    31,    35,    41,    51,    85,    87,
      87,     4,     4,    85,    87,    87,    87,     4,    85,    87,
      26,    41,     4,    49,    51,    87,    51,    87,     5,     6,
       7,     8,    12,    14,    15,    16,    17,    33,    34,    36,
      37,    48,    50,    49,    52,    52,    52,    52,    52,    52,
      52,    48,    51,    87,    86,    87,    52,    52,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,     9,    87,    48,    48,    48,    20,    24,    48,    48,
      52,    50,    52,    53,    48,    87,    50,    83,    83,    48,
      87,    48,    52,    18,    21,    22,    48,    83,    48,    48,
      21,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    58,    58,    59,    60,
      61,    62,    62,    63,    64,    64,    64,    65,    65,    66,
      66,    67,    68,    68,    68,    68,    68,    68,    69,    69,
      69,    70,    70,    70,    71,    71,    71,    72,    73,    73,
      73,    73,    74,    74,    75,    76,    76,    77,    77,    78,
      79,    79,    80,    81,    82,    83,    83,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      85,    85,    86,    86,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     3,     0,     2,     1,     2,     2,
       3,     2,     1,     3,     1,     1,     1,     3,     0,     1,
       2,     3,     1,     4,     4,     3,     6,     6,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     2,     1,     2,
       3,     4,     1,     2,     9,     3,     0,     1,     2,     3,
       1,     3,     8,     4,     3,     2,     1,     4,     7,     5,
       8,     5,     8,    10,     8,     6,     6,     5,     5,     5,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     1,
       1,     1,     4,     1,     1,     4
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
#line 81 "abstree.y" /* yacc.c:1646  */
    {
                                            // printf("SYMBOL TABLE:\n");
                                            // printSymbolTable();
                                            // printf("---------------\n");

                                            fclose(intermediate);
                                            exit(1);
                        }
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 89 "abstree.y" /* yacc.c:1646  */
    {

                                            // printf("SYMBOL TABLE:\n");
                                            // printSymbolTable();
                                            // printf("---------------\n");
                                            fclose(intermediate);
                                            exit(1);
                                    }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 138 "abstree.y" /* yacc.c:1646  */
    { 
                                    id_name = (yyvsp[0].nptr) -> NAME; 
                                    TypeInstall((yyvsp[0].nptr) -> NAME,NULL); //fieldlist is initialized to null
                               }
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 143 "abstree.y" /* yacc.c:1646  */
    { 
                                            temp1 = TypeLookup(id_name);
                                            temp1 -> fields = FieldHead;
                                            FieldHead = NULL;
                                            FieldTail = NULL;
                                      }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 155 "abstree.y" /* yacc.c:1646  */
    {FieldInstall(temp1,(yyvsp[-1].nptr) -> NAME);}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 157 "abstree.y" /* yacc.c:1646  */
    {temp1 = TypeLookup("integer");}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 158 "abstree.y" /* yacc.c:1646  */
    {temp1 = TypeLookup("boolean");}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 159 "abstree.y" /* yacc.c:1646  */
    {
                                temp1 = TypeLookup((yyvsp[0].nptr) -> NAME);
                                if(temp1 == NULL)
                                {
                                    yyerror("Un-declared udt\n");
                                    exit(1);
                                }
                            }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 169 "abstree.y" /* yacc.c:1646  */
    {
                                        intermediate = fopen("assemblycode.asm","w+");
                                        if(intermediate == NULL)
                                        {
                                            printf("Unable to locate file\n");
                                            exit(1);
                                        }
                                        alloc();
                                        freeheap();
                                        fprintf(intermediate, "START\n");
                                        initialize();
                                        fprintf(intermediate, "MOV SP,%d\n",totalCount - 1);
                                        fprintf(intermediate, "MOV BP,%d\n",totalCount);
                                        fprintf(intermediate, "PUSH R0\n");
                                        fprintf(intermediate, "CALL MAIN\n");
                                        fprintf(intermediate, "HALT\n");
                    
                                        }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 187 "abstree.y" /* yacc.c:1646  */
    {
                                        intermediate = fopen("assemblycode.asm","w+");
                                        if(intermediate == NULL)
                                        {
                                            printf("Unable to locate file\n");
                                            exit(1);
                                        }
                                        alloc();
                                        freeheap();
                                        fprintf(intermediate, "START\n");
                                        initialize();
                                        fprintf(intermediate, "MOV SP,%d\n",totalCount - 1);
                                        fprintf(intermediate, "MOV BP,%d\n",totalCount);
                                        fprintf(intermediate, "PUSH R0\n");
                                        fprintf(intermediate, "CALL MAIN\n");
                                        fprintf(intermediate, "HALT\n");

                                     }
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 206 "abstree.y" /* yacc.c:1646  */
    {}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 207 "abstree.y" /* yacc.c:1646  */
    {}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 209 "abstree.y" /* yacc.c:1646  */
    {}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 211 "abstree.y" /* yacc.c:1646  */
    {
                            Gtemp = Glookup((yyvsp[0].nptr) -> NAME);
                            if(Gtemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            Ginstall((yyvsp[0].nptr) -> NAME,declarationType,1,NULL);
                        }
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 220 "abstree.y" /* yacc.c:1646  */
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

                        }
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 234 "abstree.y" /* yacc.c:1646  */
    {
                                declcount++;
                                Gtemp = Glookup((yyvsp[-3].nptr) -> NAME);
                                if(Gtemp != NULL)
                                {
                                    printf("Re initialization of identifier\n");
                                    exit(1);
                                }
                                Ginstall((yyvsp[-3].nptr) -> NAME,declarationType,-1, Arghead);
                                // if ( declarationType == SYMBOL_INTEGER )
                                //     Ginstall($1 -> NAME,SYMBOL_FUNC_INT,-1, Arghead);
                                // else if ( declarationType == SYMBOL_BOOLEAN )
                                //     Ginstall($1 -> NAME,SYMBOL_FUNC_BOOLEAN,-1,Arghead);

                                Arghead = NULL;
                                Argtail = NULL;
                            }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 251 "abstree.y" /* yacc.c:1646  */
    {
                            Gtemp = Glookup((yyvsp[0].nptr) -> NAME);
                            if(Gtemp != NULL)
                            {
                                printf("Re initialization of variable\n");
                                exit(1);
                            }
                            Ginstall((yyvsp[0].nptr) -> NAME,declarationType,1,NULL);
                        }
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 260 "abstree.y" /* yacc.c:1646  */
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
                                }
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 274 "abstree.y" /* yacc.c:1646  */
    {
                                        declcount++;

                                        Gtemp = Glookup((yyvsp[-3].nptr) -> NAME);
                                        if(Gtemp != NULL)
                                        {
                                            printf("Re initialization of identifier\n");
                                            exit(1);
                                        }
                                        Ginstall((yyvsp[-3].nptr) -> NAME,declarationType,-1, Arghead);
                                        // if ( declarationType == SYMBOL_INTEGER )
                                        //     Ginstall($3 -> NAME,SYMBOL_FUNC_INT,-1, Arghead);
                                        // else if ( declarationType == SYMBOL_BOOLEAN )
                                        //     Ginstall($3 -> NAME,SYMBOL_FUNC_BOOLEAN,-1,Arghead);

                                        Arghead = NULL;
                                        Argtail = NULL;
                                    }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 294 "abstree.y" /* yacc.c:1646  */
    {
                    declarationType = TypeLookup("integer");
                }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 298 "abstree.y" /* yacc.c:1646  */
    {
                    declarationType = TypeLookup("boolean");
                }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 302 "abstree.y" /* yacc.c:1646  */
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
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 314 "abstree.y" /* yacc.c:1646  */
    {FdeclarationType = TypeLookup("integer");}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 315 "abstree.y" /* yacc.c:1646  */
    {FdeclarationType = TypeLookup("boolean");}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 316 "abstree.y" /* yacc.c:1646  */
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
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 328 "abstree.y" /* yacc.c:1646  */
    {}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 329 "abstree.y" /* yacc.c:1646  */
    {}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 333 "abstree.y" /* yacc.c:1646  */
    {}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 336 "abstree.y" /* yacc.c:1646  */
    {
                                            Argtemp = Arglookup((yyvsp[0].nptr) -> NAME);
                                            if(Argtemp != NULL)
                                            {
                                                printf("Re initialization of variable in Arglist\n");
                                                exit(1);
                                            }

                                            ArgInstall((yyvsp[0].nptr) -> NAME,FdeclarationType); 
                                    }
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 346 "abstree.y" /* yacc.c:1646  */
    {        
                                            Argtemp = Arglookup((yyvsp[0].nptr) -> NAME);

                                            if(Argtemp != NULL)
                                            {
                                                printf("Re initialization of variable in Arglist\n");
                                                exit(1);
                                            }
                                            
                                            if ( FdeclarationType == TypeLookup("integer") )
                                              ArgInstall((yyvsp[0].nptr) -> NAME,TypeLookup("amp_integer"));

                                        else if ( FdeclarationType == TypeLookup("boolean") )
                                              ArgInstall((yyvsp[0].nptr) -> NAME,TypeLookup("amp_boolean"));
                                          else
                                            {
                                                yyerror("Referencing udt is illegal\n");
                                                exit(1);
                                            }

                                    }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 367 "abstree.y" /* yacc.c:1646  */
    {
                                        Argtemp = Arglookup((yyvsp[0].nptr) -> NAME);

                                        if(Argtemp != NULL)
                                        {
                                            printf("Re initialization of variable in Arglist\n");
                                            exit(1);
                                        }

                                        ArgInstall((yyvsp[0].nptr) -> NAME,FdeclarationType);


                                    }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 381 "abstree.y" /* yacc.c:1646  */
    {
                                        Argtemp = Arglookup((yyvsp[0].nptr) -> NAME);

                                        if(Argtemp != NULL)
                                        {
                                            printf("Re initialization of variable in Arglist\n");
                                            exit(1);
                                        }
                                        if ( FdeclarationType == TypeLookup("integer") )
                                            ArgInstall((yyvsp[0].nptr) -> NAME,TypeLookup("amp_integer"));

                                        else if ( FdeclarationType == TypeLookup("boolean") )
                                            ArgInstall((yyvsp[0].nptr) -> NAME,TypeLookup("amp_boolean"));
                                        else
                                        {
                                            yyerror("Referencing udt is illegal\n");
                                            exit(1);
                                        }
                                    }
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 404 "abstree.y" /* yacc.c:1646  */
    {}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 405 "abstree.y" /* yacc.c:1646  */
    {}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 408 "abstree.y" /* yacc.c:1646  */
    {  
                                                                // printf("IN fdef\n");
                                                                defcount++;
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

                                                                Arghead = NULL;
                                                                Argtail = NULL;
                                                                Lhead = NULL;
                                                                Ltail = NULL;
                                                            }
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 475 "abstree.y" /* yacc.c:1646  */
    {
                                            // $$ = $2;

                                        }
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 479 "abstree.y" /* yacc.c:1646  */
    { 
                                        //$$ = NULL;
                                     }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 483 "abstree.y" /* yacc.c:1646  */
    {
                                // $$ = Lhead;
                            }
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 487 "abstree.y" /* yacc.c:1646  */
    {
                                // $$ = Lhead;
                            }
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 491 "abstree.y" /* yacc.c:1646  */
    {
                                // $$ = Lhead;
                           }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 495 "abstree.y" /* yacc.c:1646  */
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
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 506 "abstree.y" /* yacc.c:1646  */
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
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 520 "abstree.y" /* yacc.c:1646  */
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
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 552 "abstree.y" /* yacc.c:1646  */
    {
                                    //printf("created\n");
                                    (yyval.nptr) = TreeCreate(TypeLookup("void"), DEFAULT, NULL,0,NULL,(yyvsp[-2].nptr),(yyvsp[-1].nptr),NULL);
                                }
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 559 "abstree.y" /* yacc.c:1646  */
    {   
                                // if(declarationType == SYMBOL_INTEGER)
                                // {
                                //     functype = TYPE_INT;
                                // }
                                // if(declarationType == SYMBOL_BOOLEAN)
                                // {
                                //     functype = TYPE_BOOL;
                                // }
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
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 580 "abstree.y" /* yacc.c:1646  */
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
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 591 "abstree.y" /* yacc.c:1646  */
    {
                            (yyval.nptr)=(yyvsp[0].nptr);
                            //printf("-----%d----\n",$1->NODE);
                                                        
                        }
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 599 "abstree.y" /* yacc.c:1646  */
    {
                                    /*printf(" in ASGN \n");*/

                                    Ltemp = Llookup((yyvsp[-3].nptr) -> NAME);

                                    if(Ltemp != NULL)
                                    {
                                        (yyvsp[-3].nptr) -> TYPE = Ltemp -> TYPE;
                                        // if(Ltemp -> TYPE == SYMBOL_INTEGER)
                                        // {
                                        //     $1 -> TYPE = TYPE_INT;
                                        // }
                                        // else if(Ltemp -> TYPE == SYMBOL_BOOLEAN)
                                        // {
                                        //     $1 -> TYPE = TYPE_BOOL; 
                                        // }

                                        
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
                                                // if(Gtemp -> TYPE == SYMBOL_INTEGER)
                                                // {
                                                //     $1 -> TYPE = TYPE_INT;
                                                // }
                                                // else if(Gtemp -> TYPE == SYMBOL_BOOLEAN)
                                                // {
                                                //     $1 -> TYPE = TYPE_BOOL; 
                                                // }
                                                
                                            }
                                        }
                                    }
                                

                                    if((yyvsp[-3].nptr)-> TYPE != (yyvsp[-1].nptr) -> TYPE)
                                    {
                                        yyerror("conflict in types in assignment\n");
                                        printf("%s\n",(yyvsp[-3].nptr) -> NAME);
                                        exit(1);
                                    } 
                                    (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_ASGN,NULL,0,NULL,(yyvsp[-3].nptr),(yyvsp[-1].nptr),NULL);  
                                }
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 679 "abstree.y" /* yacc.c:1646  */
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
                                                else if((yyvsp[-4].nptr) -> TYPE == TypeLookup("boolean"))
                                                {
                                                    yyerror("Expected value , Found boolean\n");
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
                                                    yyerror("conflict in types in assignment\n");
                                                    printf("%s\n",(yyvsp[-6].nptr) -> NAME);
                                                    exit(1);
                                                } 
                                                (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_ARRAY_ASGN,NULL,0,NULL,(yyvsp[-6].nptr),(yyvsp[-4].nptr),(yyvsp[-1].nptr)); 
                                          }
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 719 "abstree.y" /* yacc.c:1646  */
    {
                                    /*printf(" in READ \n");*/ 
                                    Ltemp = Llookup((yyvsp[-2].nptr) -> NAME);

                                    if(Ltemp != NULL)
                                    {
                                        if(Ltemp -> TYPE == TypeLookup("integer"))
                                        {
                                            (yyvsp[-2].nptr) -> TYPE = TypeLookup("integer");
                                        }
                                        else if(Ltemp -> TYPE == TypeLookup("boolean"))
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
                                            if((Argtemp -> TYPE == TypeLookup("integer")) || (Argtemp -> TYPE == TypeLookup("amp_integer")))
                                            {
                                                (yyvsp[-2].nptr) -> TYPE = TypeLookup("integer");
                                            }
                                            else if((Argtemp -> TYPE == TypeLookup("boolean")) || (Argtemp -> TYPE == TypeLookup("amp_boolean")))
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
                                            else if(Gtemp -> TYPE == TypeLookup("array_boolean") ||Gtemp -> TYPE == TypeLookup("array_integer") )
                                            {
                                                yyerror("conflict in ID NodeType : Expected Array . Found Variable\n");
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
                                                else if(Gtemp -> TYPE == TypeLookup("boolean"))
                                                {
                                                    //$3 -> TYPE = TYPE_BOOL;
                                                    yyerror("Boolean variable can not be read\n");
                                                    printf("%s\n",(yyvsp[-2].nptr) -> NAME);
                                                    exit(1);
                                                }
                                            }
                                        }
                                    }
                                    (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_READ,NULL,0,NULL,NULL,(yyvsp[-2].nptr),NULL); 
                                }
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 791 "abstree.y" /* yacc.c:1646  */
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
                                                else if((yyvsp[-3].nptr) -> TYPE == TypeLookup("boolean"))
                                                {
                                                    yyerror("Expected value , Found boolean\n");
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
                                                    else if(Gtemp -> TYPE == TypeLookup("array_boolean"))
                                                    {
                                                        //$3 -> TYPE = TYPE_BOOL;
                                                        yyerror("Boolean variable can not be read\n");
                                                        printf("%s\n",(yyvsp[-5].nptr) -> NAME);
                                                        exit(1);
                                                    }
                                                }
                                                (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_ARRAY_READ,NULL,0,NULL,NULL,(yyvsp[-5].nptr),(yyvsp[-3].nptr)); 
                                            }
#line 2417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 828 "abstree.y" /* yacc.c:1646  */
    {
                                    /*  printf(" in WRITE \n"); */
                                // printf("%d\n",$3 -> TYPE );
                                    if((yyvsp[-2].nptr) -> TYPE == TypeLookup("integer") || (yyvsp[-2].nptr) -> TYPE == TypeLookup("amp_integer"))
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
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 850 "abstree.y" /* yacc.c:1646  */
    { 
                                    /*printf(" in IF_THEN \n");*/
                                    if((yyvsp[-5].nptr) -> TYPE != TypeLookup("boolean"))
                                    {
                                        yyerror("Expected boolean , Found value in if\n");
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_IF,NULL,0,NULL,(yyvsp[-5].nptr),(yyvsp[-2].nptr),NULL); 
                               }
#line 2457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 860 "abstree.y" /* yacc.c:1646  */
    { 
                                    /*printf(" in IF_THEN_ELSE \n");*/
                                    if((yyvsp[-7].nptr) -> TYPE != TypeLookup("boolean"))
                                    {
                                        yyerror("Expected boolean , Found value in if else\n");
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_IF_ELSE,NULL,0,NULL,(yyvsp[-7].nptr),(yyvsp[-4].nptr),(yyvsp[-2].nptr)); 
                                }
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 870 "abstree.y" /* yacc.c:1646  */
    { 
                                    /*printf(" in WHILE \n");*/ 
                                    if((yyvsp[-5].nptr) -> TYPE != TypeLookup("boolean"))
                                    {
                                        yyerror("Expected boolean , Found value in while\n");
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_WHILE,NULL,0,NULL,(yyvsp[-5].nptr),(yyvsp[-2].nptr),NULL); 
                                }
#line 2485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 879 "abstree.y" /* yacc.c:1646  */
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
                                                else
                                                {
                                                    (yyvsp[-5].nptr) -> TYPE = TypeLookup(Ltemp -> TYPE);
                                                }
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
                                                else
                                                {
                                                    (yyvsp[-5].nptr) -> TYPE = TypeLookup(Argtemp -> TYPE);
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
                                                    yyerror("conflict in ID NodeType : Expected udt Variable . Found Array\n");
                                                    printf("%s\n",(yyvsp[-5].nptr) -> NAME);
                                                    exit(1);
                                                }
                                                else if(Gtemp -> TYPE == TypeLookup("boolean") ||Gtemp -> TYPE == TypeLookup("integer"))
                                                {
                                                    yyerror("Cannot ALLOC to boolean or integer variable\n");
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
#line 2569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 958 "abstree.y" /* yacc.c:1646  */
    {
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
                                            else if(head -> TYPE == TypeLookup("array_integer") || head -> TYPE == TypeLookup("array_boolean") )
                                            {
                                                    yyerror("Cannot ALLOC to array type variable\n");
                                                    exit(1);
                                            }
                                            else
                                            {
                                                head = TreeCreate(TypeLookup("integer"),NODE_ALLOC,NULL,0,NULL,NULL,NULL,NULL);
                                                (yyval.nptr) = TreeCreate(TypeLookup("void"), NODE_ASGN,NULL,0,NULL,(yyvsp[-5].nptr),head,NULL);        
                                            }
                                        }
#line 2596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 980 "abstree.y" /* yacc.c:1646  */
    {
                                            Ltemp = Llookup((yyvsp[-2].nptr) -> NAME);
                                            if(Ltemp != NULL)
                                            {
                                                if(Ltemp -> TYPE == TypeLookup("integer") || Ltemp -> TYPE == TypeLookup("boolean"))
                                                {
                                                    yyerror("can not free a non udt\n");
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
                                                }
                                            }  
                                            (yyval.nptr) = TreeCreate(TypeLookup("void"),NODE_FREE,NULL,0,NULL,NULL,(yyvsp[-2].nptr),NULL); 
                                        }
#line 2656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1035 "abstree.y" /* yacc.c:1646  */
    {
                                            (yyval.nptr) = TreeCreate(TypeLookup("void"),NODE_FREE,NULL,0,NULL,NULL,(yyvsp[-2].nptr),NULL); 
                                    }
#line 2664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1038 "abstree.y" /* yacc.c:1646  */
    {
                                            (yyval.nptr) = TreeCreate(TypeLookup("void"),NODE_READ,NULL,0,NULL,NULL,(yyvsp[-2].nptr),NULL); 
                                    }
#line 2672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1042 "abstree.y" /* yacc.c:1646  */
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

                                        (yyval.nptr) = (yyvsp[-2].nptr);
                                    }
                                }
                            }
                        }
#line 2772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1137 "abstree.y" /* yacc.c:1646  */
    {
                            head1 = head = (yyvsp[-2].nptr);
                            while(head -> Ptr2 != NULL)
                            {
                                head = head -> Ptr2;
                            }
                            temp1 = head -> TYPE;
                            if(temp1 != TypeLookup("boolean") && temp1 != TypeLookup("integer"))
                            {
                                ftemp = FieldLookup((yyvsp[0].nptr) -> NAME,temp1 -> fields);
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
#line 2805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1167 "abstree.y" /* yacc.c:1646  */
    {
                                    // printf("FIRST : %d\n",$1 -> NODE);
                                    exprcount = 1;
                                    (yyval.nptr) = (yyvsp[0].nptr);
                                }
#line 2815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1172 "abstree.y" /* yacc.c:1646  */
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
#line 2835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1189 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("PLUS\n");*/
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
#line 2852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1201 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("MINUS\n");*/
                                
                                if((yyvsp[-2].nptr) -> TYPE == TypeLookup("integer") && (yyvsp[0].nptr) -> TYPE == TypeLookup("integer"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("integer"), NODE_MINUS , NULL,0 , NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MINUS\n");
                                    exit(1);
                                }
                            }
#line 2870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1214 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("MUL\n");*/
                                
                                if((yyvsp[-2].nptr) -> TYPE == TypeLookup("integer") && (yyvsp[0].nptr) -> TYPE == TypeLookup("integer"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("integer"), NODE_MUL , NULL,0 , NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MUL\n");
                                    exit(1);
                                }
                            }
#line 2888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1227 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("DIV\n");*/
                                
                                if((yyvsp[-2].nptr) -> TYPE == TypeLookup("integer") && (yyvsp[0].nptr) -> TYPE == TypeLookup("integer"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("integer"), NODE_DIV , NULL,0 , NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MUL\n");
                                    exit(1);
                                }
                            }
#line 2906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1240 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("MOD\n");*/
                                
                                if((yyvsp[-2].nptr) -> TYPE == TypeLookup("integer") && (yyvsp[0].nptr) -> TYPE == TypeLookup("integer"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("integer"), NODE_MOD , NULL,0 , NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in MUL\n");
                                    exit(1);
                                }
                            }
#line 2924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1253 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("LT\n");*/
                                
                                if((yyvsp[-2].nptr) -> TYPE == TypeLookup("integer") && (yyvsp[0].nptr) -> TYPE == TypeLookup("integer"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("boolean"), NODE_LT , NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in LT\n");
                                    exit(1);
                                }
                            }
#line 2942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1266 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("LT\n");*/
                                
                                if((yyvsp[-2].nptr) -> TYPE == TypeLookup("integer") && (yyvsp[0].nptr) -> TYPE == TypeLookup("integer"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("boolean"), NODE_LE , NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in LE\n");
                                    exit(1);
                                }
                            }
#line 2960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1279 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("GT\n");*/
                                if((yyvsp[-2].nptr) -> TYPE == TypeLookup("integer") && (yyvsp[0].nptr) -> TYPE == TypeLookup("integer"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("boolean"), NODE_GT , NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in GT\n");
                                    exit(1);
                                }
                            }
#line 2977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1291 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("GT\n");*/
                                if((yyvsp[-2].nptr) -> TYPE == TypeLookup("integer") && (yyvsp[0].nptr) -> TYPE == TypeLookup("integer"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("boolean"), NODE_GE , NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in GE\n");
                                    exit(1);
                                }
                            }
#line 2994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1303 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("DEQ\n");*/
                                if((yyvsp[-2].nptr) -> TYPE == TypeLookup("integer") && (yyvsp[0].nptr) -> TYPE == TypeLookup("integer"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("boolean"), NODE_DEQ, NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in DEQ\n");
                                    exit(1);
                                }
                            }
#line 3011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1315 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("NEQ\n");*/
                                if((yyvsp[-2].nptr) -> TYPE == TypeLookup("integer") && (yyvsp[0].nptr) -> TYPE == TypeLookup("integer"))
                                {
                                    (yyval.nptr) = TreeCreate(TypeLookup("boolean"), NODE_NEQ, NULL, 0, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                                }
                                else
                                {
                                    yyerror("conflict in operand types in NEQ\n");
                                    exit(1);
                                }
                            }
#line 3028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1327 "abstree.y" /* yacc.c:1646  */
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
#line 3044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1338 "abstree.y" /* yacc.c:1646  */
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
#line 3060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1349 "abstree.y" /* yacc.c:1646  */
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
#line 3077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1361 "abstree.y" /* yacc.c:1646  */
    {
                                (yyval.nptr) = (yyvsp[-1].nptr);
                            }
#line 3085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1386 "abstree.y" /* yacc.c:1646  */
    {
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 3093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1390 "abstree.y" /* yacc.c:1646  */
    {
                                /*printf("NUM\n");*/
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 3102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1394 "abstree.y" /* yacc.c:1646  */
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
                                            // if(Gtemp -> TYPE == SYMBOL_INTEGER)
                                            // {
                                            //     $1 -> TYPE = TYPE_INT;
                                            // }
                                            // else if(Gtemp -> TYPE == SYMBOL_BOOLEAN)
                                            // {
                                            //     $1 -> TYPE = TYPE_BOOL; 
                                            // }
                                            (yyval.nptr) = (yyvsp[0].nptr);
                                        }
                                    }
                                 }
                            }
#line 3167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1455 "abstree.y" /* yacc.c:1646  */
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
#line 3212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1495 "abstree.y" /* yacc.c:1646  */
    {
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 3220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1498 "abstree.y" /* yacc.c:1646  */
    {
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 3228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1502 "abstree.y" /* yacc.c:1646  */
    {
                                    Gtemp = Glookup((yyvsp[-3].nptr) -> NAME);

                                    if(Gtemp == NULL)
                                    {
                                        yyerror("Un-declared function \n");
                                        exit(1);
                                    }
                                    // temp1 = TypeLookup("integer");
                                    // temp2 = TypeLookup("boolean");
                                    // else if(Gtemp -> TYPE == temp2 || Gtemp -> TYPE == temp1 )
                                    // {
                                    //     yyerror("conflict in ID NodeType : Expected Function . Found Variable\n");
                                    //     printf("%s\n",$1 -> NAME);
                                    //     exit(1);
                                    // }
                                    // temp1 = TypeLookup("array_integer");
                                    // temp2 = TypeLookup("array_boolean");
                                    // else if(Gtemp -> TYPE == temp2 ||Gtemp -> TYPE == temp1 )
                                    // {
                                    //     yyerror("conflict in ID NodeType : Expected Function . Found Array\n");
                                    //     printf("%s\n",$1 -> NAME);
                                    //     exit(1);
                                    // }
                                    
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
                                        // if(Gtemp -> TYPE == temp1)
                                        // {
                                        //     $1 -> TYPE = TYPE_INT;
                                        // }
                                        // else if(Gtemp -> TYPE == temp2)
                                        // {
                                        //     $1 -> TYPE = TYPE_BOOL; 
                                        // }
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
                                    // Arg_callee = Gtemp -> Arglist;  //used to find the arglist of callee function
                                    //differentiating b/w one and more than one arguments
                                    if(indicator == 1)
                                    {
                                        (yyval.nptr) = TreeCreate((yyvsp[-3].nptr) -> TYPE,NODE_FUNC,(yyvsp[-3].nptr) -> NAME,0,Gtemp -> Arglist,NULL,(yyvsp[-1].nptr),NULL);
                                        indicator = 0;
                                    }

                                    else
                                        (yyval.nptr) = TreeCreate((yyvsp[-3].nptr) -> TYPE,NODE_FUNC,(yyvsp[-3].nptr) -> NAME,0,Gtemp -> Arglist,NULL,NULL,(yyvsp[-1].nptr));

                                }
#line 3302 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3306 "y.tab.c" /* yacc.c:1646  */
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
#line 1574 "abstree.y" /* yacc.c:1906  */


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
