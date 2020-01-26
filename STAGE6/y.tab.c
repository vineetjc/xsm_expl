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
#line 1 "t2.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#include "t2.h"
	#include "t2.c"
	int yylex(void);
	int yyerror(char const *);
	struct Gsymbol *Groot = NULL;
	struct Lsymbol *Lroot = NULL;
	struct Typetable *Troot = NULL;
	struct Typetable *returnType = NULL;
	int bindval = 0;
	int lbindval = 0;
	int startCount = 0;
	int fIndex = 0;

#line 85 "y.tab.c" /* yacc.c:339  */

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
    BEG = 258,
    READ = 259,
    WRITE = 260,
    DO = 261,
    WHILE = 262,
    IF = 263,
    THEN = 264,
    ELSE = 265,
    ENDIF = 266,
    ENDWHILE = 267,
    ID = 268,
    DECL = 269,
    ENDDECL = 270,
    BREAK = 271,
    CONTINUE = 272,
    REPEAT = 273,
    UNTIL = 274,
    STRING = 275,
    MAIN = 276,
    NUM = 277,
    PLUS = 278,
    MINUS = 279,
    MUL = 280,
    DIV = 281,
    END = 282,
    NTEQ = 283,
    CONDEQ = 284,
    INT = 285,
    STR = 286,
    RETURN = 287,
    AND = 288,
    TYPE = 289,
    ENDTYPE = 290,
    NULLTYPE = 291,
    INITIALISE = 292,
    ALLOC = 293,
    FREE = 294,
    EQ = 295,
    LT = 296,
    GT = 297,
    LE = 298,
    GE = 299,
    MOD = 300
  };
#endif
/* Tokens.  */
#define BEG 258
#define READ 259
#define WRITE 260
#define DO 261
#define WHILE 262
#define IF 263
#define THEN 264
#define ELSE 265
#define ENDIF 266
#define ENDWHILE 267
#define ID 268
#define DECL 269
#define ENDDECL 270
#define BREAK 271
#define CONTINUE 272
#define REPEAT 273
#define UNTIL 274
#define STRING 275
#define MAIN 276
#define NUM 277
#define PLUS 278
#define MINUS 279
#define MUL 280
#define DIV 281
#define END 282
#define NTEQ 283
#define CONDEQ 284
#define INT 285
#define STR 286
#define RETURN 287
#define AND 288
#define TYPE 289
#define ENDTYPE 290
#define NULLTYPE 291
#define INITIALISE 292
#define ALLOC 293
#define FREE 294
#define EQ 295
#define LT 296
#define GT 297
#define LE 298
#define GE 299
#define MOD 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "t2.y" /* yacc.c:355  */

	struct tnode* treeNode;
	struct Gsymbol* GTableNode;
	struct Lsymbol* LTableNode;
	struct Paramstruct* paramlist;
	struct Typetable* typeNode;
	struct Fieldlist* fieldNode;
	int number;

#line 225 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 242 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   627

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  247

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
      52,    53,     2,     2,    49,     2,    54,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
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
       0,    44,    44,    45,    46,    47,    48,    49,    50,    51,
      54,    55,    58,    59,    62,    62,    68,    72,    77,    82,
      83,    84,    96,    97,   100,   101,   104,   107,   108,   111,
     127,   145,   163,   188,   195,   201,   204,   205,   208,   250,
     278,   282,   288,   289,   292,   297,   315,   321,   325,   331,
     332,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   347,   375,   389,   394,   395,   402,   438,   453,   459,
     495,   531,   537,   571,   577,   578,   581,   584,   587,   590,
     593,   596,   602,   645,   664,   669,   674,   679,   684,   689,
     694,   699,   704,   709,   715,   720,   725,   726,   731,   736,
     741,   752,   780,   791,   802,   805,   809
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BEG", "READ", "WRITE", "DO", "WHILE",
  "IF", "THEN", "ELSE", "ENDIF", "ENDWHILE", "ID", "DECL", "ENDDECL",
  "BREAK", "CONTINUE", "REPEAT", "UNTIL", "STRING", "MAIN", "NUM", "PLUS",
  "MINUS", "MUL", "DIV", "END", "NTEQ", "CONDEQ", "INT", "STR", "RETURN",
  "AND", "TYPE", "ENDTYPE", "NULLTYPE", "INITIALISE", "ALLOC", "FREE",
  "EQ", "LT", "GT", "LE", "GE", "MOD", "'{'", "'}'", "';'", "','", "'['",
  "']'", "'('", "')'", "'.'", "$accept", "Program", "TypeDefBlock",
  "TypeDefList", "TypeDef", "$@1", "FieldDeclList", "FieldDecl", "Type",
  "GDeclBlock", "GDeclList", "GDecl", "GidList", "Gid", "ParamList",
  "Param", "FDefBlock", "FDef", "MainBlock", "LDeclBlock", "LDeclList",
  "LDecl", "IdList", "Body", "Slist", "Stmt", "InputStmt", "OutputStmt",
  "AsgStmt", "IfStmt", "WhileStmt", "BreakStmt", "ContinueStmt",
  "RepeatUntilStmt", "DoWhileStmt", "RetStmt", "FIELD", "expr", "ArgList", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   123,   125,    59,    44,
      91,    93,    40,    41,    46
};
# endif

#define YYPACT_NINF -96

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-96)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      83,   -96,    19,   -16,   -96,     4,    54,   177,    17,    46,
      46,   -96,   -96,   -96,    68,   135,   -96,    36,   -96,    -4,
     -96,   -96,    46,    46,   -96,    49,    46,   -96,   -96,   -96,
       1,    25,   -96,   -96,   -96,    45,    39,   -96,   -96,    46,
     -96,   -96,    19,   -96,    93,    19,   -96,    68,    75,    19,
     -96,   116,    -7,   -96,    85,    71,   -96,   126,    81,   -96,
     132,   -96,    19,   112,   -96,   -96,    19,   148,   -96,   -96,
     113,   -96,   126,   160,   180,   -96,   247,   117,   -96,   148,
     -96,    61,   -96,   -96,   131,   157,   247,   167,   169,   152,
     136,   176,   247,    80,   173,   247,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   185,    32,   -96,   182,
     -96,   217,   223,   105,   264,   -96,    80,    80,    67,    80,
     233,   -96,   -96,   181,   187,   -96,   -96,   -96,    80,   193,
     452,   235,   -96,   229,   -96,    70,   237,   -96,   -96,   151,
      89,   204,   265,   206,   288,   311,   209,   215,   478,   380,
     -96,    80,    80,    -9,   334,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,   -96,   102,   125,
     -96,   221,   504,   -96,    80,   214,   226,   228,   230,    80,
     269,   274,   231,   232,   -96,   252,   530,   404,   -96,   582,
      84,   -96,   -19,   -19,   254,   254,   -19,   -19,   582,   -19,
     -19,   -19,   -19,   254,   249,   251,   242,   -96,   428,   -96,
     -96,   -96,   -96,   357,   247,   247,   253,   256,    80,   -96,
     -96,    80,   -96,   -96,   -96,   257,   262,    -3,   210,   164,
     -96,   -96,   556,   582,   -96,   271,   -96,   272,   247,   275,
     -96,   -96,   -96,   227,   -96,   276,   -96
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    21,     0,    19,    20,     0,     0,     0,     0,     0,
       0,    37,     9,    19,     0,     0,    25,     0,    14,     0,
      13,     1,     0,     0,     6,     0,     0,     7,    36,     8,
      29,     0,    28,    22,    24,     0,     0,    10,    12,     0,
       3,     4,    34,     5,     0,    34,    26,     0,     0,     0,
       2,     0,     0,    33,     0,     0,    27,    41,     0,    17,
       0,    35,     0,     0,    30,    31,     0,     0,    15,    16,
       0,    32,    41,     0,     0,    43,     0,     0,    18,     0,
      46,     0,    40,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,     0,    39,     0,
      44,     0,     0,     0,     0,    60,     0,     0,     0,     0,
       0,    77,    78,     0,   101,    98,    97,    99,     0,   104,
       0,     0,    49,    60,    48,     0,     0,    38,    45,     0,
       0,    98,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,     0,     0,
      47,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    66,     0,     0,     0,   102,   106,
       0,    96,    84,    85,    86,    87,    93,    94,    95,    89,
      90,    91,    92,    88,     0,     0,     0,    68,     0,    61,
      63,    65,    64,     0,     0,     0,     0,     0,     0,    79,
     100,     0,   103,    72,    73,     0,     0,     0,     0,     0,
      69,    70,     0,   105,    71,     0,    80,     0,     0,     0,
      67,    62,    76,     0,    75,     0,    74
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -96,   -96,   -96,   -96,   281,   -96,   -96,   244,    33,   315,
     -96,   310,   -96,   279,   282,   266,    30,     2,   137,   270,
     -96,   273,   -96,   259,   -84,   -94,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -61,   -76,   -95,   -96
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,    19,    20,    36,    58,    59,     8,     9,
      15,    16,    31,    32,    52,    53,    10,    11,    12,    67,
      74,    75,    81,    77,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   115,   129,   130,   190
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     107,   132,   114,   214,   124,    17,   157,   158,   123,    18,
     107,   125,    28,   126,   161,   106,   107,    18,   142,   107,
     132,   144,   145,   148,   149,    28,   166,   127,    28,   132,
      25,    37,     1,   154,   133,    14,   140,    23,   107,    26,
     172,    28,    62,   128,   188,   236,    63,   107,    14,    13,
       4,    44,    39,    45,    21,   169,   186,   187,   189,     1,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   135,    46,    47,    51,     3,     4,    51,   208,
     124,    30,    60,   124,   213,    49,   136,   125,    35,   126,
     125,    60,   126,   124,     1,    51,     1,     2,    48,    73,
     125,    42,   126,   127,   146,   147,   127,    73,   171,   110,
     111,    13,     4,     3,     4,    54,   127,     5,   124,   128,
      62,    57,   128,   232,    65,   141,   233,   126,    68,    61,
     228,   229,   128,   221,   132,   132,    64,   222,   107,   107,
      66,   127,   176,   136,    24,    70,    27,    29,     1,   132,
      33,    76,   107,   107,   243,   204,   120,   128,    72,    40,
      41,    78,   107,    43,   108,    13,     4,   107,    84,    85,
      86,    87,    88,    80,   238,   239,    50,    89,   205,   136,
      90,    91,    92,   112,   121,    84,    85,    86,    87,    88,
       1,     2,   118,     1,    89,    82,    93,    90,    91,    92,
     151,   174,   119,    94,   175,   120,   120,     3,     4,   113,
      13,     4,   134,    93,    84,    85,    86,    87,    88,   116,
      94,   117,   237,    89,   122,   131,    90,    91,    92,   137,
     138,    84,    85,    86,    87,    88,   139,   152,   245,   153,
      89,   120,    93,    90,    91,    92,   150,   136,   168,    94,
     173,    84,    85,    86,    87,    88,   170,   177,   179,    93,
      89,   182,   209,    90,    91,    92,    94,   183,    84,    85,
      86,   143,    88,   206,   210,   214,   211,    89,   212,    93,
      90,    91,    92,   215,   216,   217,    94,   161,   155,   156,
     157,   158,   218,   159,   160,   225,    93,   223,   161,   224,
      38,   230,    69,    94,   231,   234,   162,   163,   164,   165,
     166,   155,   156,   157,   158,   235,   159,   160,   178,   241,
     242,   161,    22,   244,   246,    34,    56,    55,    71,   162,
     163,   164,   165,   166,   155,   156,   157,   158,   109,   159,
     160,   180,    79,     0,   161,     0,     0,    83,     0,     0,
       0,     0,   162,   163,   164,   165,   166,   155,   156,   157,
     158,     0,   159,   160,   181,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,   162,   163,   164,   165,   166,
     155,   156,   157,   158,     0,   159,   160,   191,     0,     0,
     161,     0,     0,     0,     0,     0,     0,     0,   162,   163,
     164,   165,   166,   155,   156,   157,   158,     0,   159,   160,
     227,     0,     0,   161,     0,     0,     0,     0,     0,     0,
       0,   162,   163,   164,   165,   166,     0,   155,   156,   157,
     158,   185,   159,   160,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,   162,   163,   164,   165,   166,
       0,   155,   156,   157,   158,   220,   159,   160,     0,     0,
       0,   161,     0,     0,     0,     0,     0,     0,     0,   162,
     163,   164,   165,   166,     0,   155,   156,   157,   158,   226,
     159,   160,     0,     0,     0,   161,     0,     0,     0,     0,
       0,     0,     0,   162,   163,   164,   165,   166,     0,     0,
     167,   155,   156,   157,   158,     0,   159,   160,     0,     0,
       0,   161,     0,     0,     0,     0,     0,     0,     0,   162,
     163,   164,   165,   166,     0,     0,   184,   155,   156,   157,
     158,     0,   159,   160,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,   162,   163,   164,   165,   166,
       0,     0,   207,   155,   156,   157,   158,     0,   159,   160,
       0,     0,     0,   161,     0,     0,     0,     0,     0,     0,
       0,   162,   163,   164,   165,   166,     0,     0,   219,   155,
     156,   157,   158,     0,   159,   160,     0,     0,     0,   161,
       0,     0,     0,     0,     0,     0,     0,   162,   163,   164,
     165,   166,     0,     0,   240,   155,   156,   157,   158,     0,
     159,   160,     0,     0,     0,   161,     0,     0,     0,     0,
       0,     0,     0,   162,   163,   164,   165,   166
};

static const yytype_int16 yycheck[] =
{
      76,    95,    86,     6,    13,    21,    25,    26,    92,    13,
      86,    20,    10,    22,    33,    76,    92,    13,   113,    95,
     114,   116,   117,   118,   119,    23,    45,    36,    26,   123,
      13,    35,    13,   128,    95,     2,   112,     7,   114,     9,
     135,    39,    49,    52,    53,    48,    53,   123,    15,    30,
      31,    50,    22,    52,     0,   131,   151,   152,   153,    13,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    40,    48,    49,    42,    30,    31,    45,   174,
      13,    13,    49,    13,   179,    46,    54,    20,    52,    22,
      20,    58,    22,    13,    13,    62,    13,    14,    53,    66,
      20,    52,    22,    36,    37,    38,    36,    74,    38,    48,
      49,    30,    31,    30,    31,    22,    36,    34,    13,    52,
      49,    46,    52,   218,    53,    20,   221,    22,    47,    13,
     214,   215,    52,    49,   228,   229,    51,    53,   214,   215,
      14,    36,    53,    54,     7,    13,     9,    10,    13,   243,
      15,     3,   228,   229,   238,    53,    54,    52,    46,    22,
      23,    48,   238,    26,    47,    30,    31,   243,     4,     5,
       6,     7,     8,    13,    10,    11,    39,    13,    53,    54,
      16,    17,    18,    52,    48,     4,     5,     6,     7,     8,
      13,    14,    40,    13,    13,    15,    32,    16,    17,    18,
      19,    50,    50,    39,    53,    54,    54,    30,    31,    52,
      30,    31,    27,    32,     4,     5,     6,     7,     8,    52,
      39,    52,    12,    13,    48,    52,    16,    17,    18,    47,
      13,     4,     5,     6,     7,     8,    13,    50,    11,    52,
      13,    54,    32,    16,    17,    18,    13,    54,    13,    39,
      13,     4,     5,     6,     7,     8,    27,    53,    52,    32,
      13,    52,    48,    16,    17,    18,    39,    52,     4,     5,
       6,     7,     8,    52,    48,     6,    48,    13,    48,    32,
      16,    17,    18,     9,    53,    53,    39,    33,    23,    24,
      25,    26,    40,    28,    29,    53,    32,    48,    33,    48,
      19,    48,    58,    39,    48,    48,    41,    42,    43,    44,
      45,    23,    24,    25,    26,    53,    28,    29,    53,    48,
      48,    33,     7,    48,    48,    15,    47,    45,    62,    41,
      42,    43,    44,    45,    23,    24,    25,    26,    79,    28,
      29,    53,    72,    -1,    33,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    23,    24,    25,
      26,    -1,    28,    29,    53,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      23,    24,    25,    26,    -1,    28,    29,    53,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    23,    24,    25,    26,    -1,    28,    29,
      53,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    -1,    23,    24,    25,
      26,    51,    28,    29,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      -1,    23,    24,    25,    26,    51,    28,    29,    -1,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    -1,    23,    24,    25,    26,    51,
      28,    29,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    -1,    -1,
      48,    23,    24,    25,    26,    -1,    28,    29,    -1,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    -1,    -1,    48,    23,    24,    25,
      26,    -1,    28,    29,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      -1,    -1,    48,    23,    24,    25,    26,    -1,    28,    29,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    -1,    -1,    48,    23,
      24,    25,    26,    -1,    28,    29,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    -1,    -1,    48,    23,    24,    25,    26,    -1,
      28,    29,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    14,    30,    31,    34,    56,    57,    63,    64,
      71,    72,    73,    30,    63,    65,    66,    21,    13,    58,
      59,     0,    64,    71,    73,    13,    71,    73,    72,    73,
      13,    67,    68,    15,    66,    52,    60,    35,    59,    71,
      73,    73,    52,    73,    50,    52,    48,    49,    53,    46,
      73,    63,    69,    70,    22,    69,    68,    46,    61,    62,
      63,    13,    49,    53,    51,    53,    14,    74,    47,    62,
      13,    70,    46,    63,    75,    76,     3,    78,    48,    74,
      13,    77,    15,    76,     4,     5,     6,     7,     8,    13,
      16,    17,    18,    32,    39,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    47,    78,
      48,    49,    52,    52,    79,    90,    52,    52,    40,    50,
      54,    48,    48,    79,    13,    20,    22,    36,    52,    91,
      92,    52,    80,    90,    27,    40,    54,    47,    13,    13,
      91,    20,    92,     7,    92,    92,    37,    38,    92,    92,
      13,    19,    50,    52,    92,    23,    24,    25,    26,    28,
      29,    33,    41,    42,    43,    44,    45,    48,    13,    91,
      27,    38,    92,    13,    50,    53,    53,    53,    53,    52,
      53,    53,    52,    52,    48,    51,    92,    92,    53,    92,
      93,    53,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    53,    53,    52,    48,    92,    48,
      48,    48,    48,    92,     6,     9,    53,    53,    40,    48,
      51,    49,    53,    48,    48,    53,    51,    53,    79,    79,
      48,    48,    92,    92,    48,    53,    48,    12,    10,    11,
      48,    48,    48,    79,    48,    11,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    57,    58,    58,    60,    59,    61,    61,    62,    63,
      63,    63,    64,    64,    65,    65,    66,    67,    67,    68,
      68,    68,    69,    69,    69,    70,    71,    71,    72,    73,
      74,    74,    75,    75,    76,    77,    77,    78,    78,    79,
      79,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    81,    81,    81,    82,    82,    83,    83,    83,    83,
      83,    83,    83,    83,    84,    84,    85,    86,    87,    88,
      89,    90,    91,    91,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     3,     3,     2,     2,     2,     1,
       3,     0,     2,     1,     0,     5,     2,     1,     3,     1,
       1,     1,     3,     0,     2,     1,     3,     3,     1,     1,
       4,     4,     3,     1,     0,     2,     2,     1,     9,     8,
       3,     0,     2,     1,     3,     3,     1,     4,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     8,     5,     5,     5,     4,     7,     4,     6,
       6,     6,     5,     5,    10,     8,     8,     2,     2,     5,
       7,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       4,     1,     3,     4,     1,     3,     1
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
        case 10:
#line 54 "t2.y" /* yacc.c:1646  */
    {printTypeTable(&Troot);}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 58 "t2.y" /* yacc.c:1646  */
    {fIndex = 0;}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 59 "t2.y" /* yacc.c:1646  */
    {fIndex = 0;}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 62 "t2.y" /* yacc.c:1646  */
    {TInstall(&Troot, (yyvsp[0].treeNode)->varname, 0, NULL);}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 62 "t2.y" /* yacc.c:1646  */
    {
																									struct Typetable *tempType = TLookup(&Troot, (yyvsp[-4].treeNode)->varname);
																									addFields(&tempType, (yyvsp[-1].fieldNode));
																								}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 68 "t2.y" /* yacc.c:1646  */
    {
													FAppendNode(&((yyvsp[-1].fieldNode)), (yyvsp[0].fieldNode));
													(yyval.fieldNode) = (yyvsp[-1].fieldNode);
												}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 72 "t2.y" /* yacc.c:1646  */
    {
										(yyval.fieldNode) = (yyvsp[0].fieldNode);
									}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 77 "t2.y" /* yacc.c:1646  */
    {
										fIndex++;
										(yyval.fieldNode) = createFieldNode((yyvsp[-1].treeNode)->varname, fIndex, (yyvsp[-2].typeNode));
									}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 82 "t2.y" /* yacc.c:1646  */
    {(yyval.typeNode) = TLookup(&Troot, "int");}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 83 "t2.y" /* yacc.c:1646  */
    {(yyval.typeNode) = TLookup(&Troot, "str");}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 84 "t2.y" /* yacc.c:1646  */
    {
							struct Typetable *temp = NULL;
							temp = TLookup(&Troot, (yyvsp[0].treeNode)->varname);
							if(temp == NULL)
							{
								printf("User-defined type not yet defined.\n");
								exit(1);
							}
							(yyval.typeNode) = temp;
						}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 96 "t2.y" /* yacc.c:1646  */
    {printGSymbolTable(&Groot);}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 104 "t2.y" /* yacc.c:1646  */
    {GAssignType(&Groot, (yyvsp[-2].typeNode));}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 111 "t2.y" /* yacc.c:1646  */
    {
									struct Gsymbol *temp = NULL;
									temp = GLookup(&Groot, (yyvsp[0].treeNode)->varname);
									if(temp == NULL)
									{
										//
										//printf("%s\n", $<treeNode>1->varname);
										GInstall(&Groot, (yyvsp[0].treeNode)->varname, NULL, 1, NULL);
										//
									}
									else
									{
										printf("Error. Variable declared twice.\n");
										exit(1);
									}
								}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 127 "t2.y" /* yacc.c:1646  */
    {
									struct Gsymbol *temp = NULL;
									temp = GLookup(&Groot, (yyvsp[-3].treeNode)->varname);
									struct Typetable *tempType = TLookup(&Troot, "int");
									(yyvsp[-1].treeNode)->type = tempType;
									if(temp == NULL)
									{
										//
										//printf("%s\n", $<treeNode>1->varname);
										GInstall(&Groot, (yyvsp[-3].treeNode)->varname, NULL, (yyvsp[-1].treeNode)->val, NULL);
										//
									}
									else
									{
										printf("Error. Array name declared twice.\n");
										exit(1);
									}
								}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 145 "t2.y" /* yacc.c:1646  */
    {
									struct Gsymbol *temp = NULL;
									temp = GLookup(&Groot, (yyvsp[-3].treeNode)->varname);
									if(temp == NULL)
									{
										//
										//printf("%s\n", $<treeNode>1->varname);
										GInstall(&Groot, (yyvsp[-3].treeNode)->varname, NULL, -1, (yyvsp[-1].paramlist));
										//
									}
									else
									{
										printf("Error. Function name declared twice.\n");
										exit(1);
									}
								}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 163 "t2.y" /* yacc.c:1646  */
    {
										//lbindval = 0;
										struct Paramstruct *temp = NULL;
										if((yyvsp[-2].paramlist) == NULL)
											printf("Null parameter\n");
										else
											printf("Not Null parameter\n");
										printf("%s\t%s\n",(yyvsp[-2].paramlist)->name, (yyvsp[0].paramlist)->name);
										temp = ParamLookup(&((yyvsp[-2].paramlist)), (yyvsp[0].paramlist)->name);
										printf("Lookup over\n");
										if(temp == NULL)
										{
											printf("temp is null\n");
											appendParamNode(&((yyvsp[-2].paramlist)),(yyvsp[0].paramlist));
											bindval--;
											LAppendNode(&Lroot, LInstall((yyvsp[0].paramlist)->name, (yyvsp[0].paramlist)->type, bindval));
											printf("Appending done.\n");
											(yyval.paramlist) = (yyvsp[-2].paramlist);
										}
										else
										{
											printf("Error. Parameter name already used in function.\n");
											exit(1);
										}
									}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 188 "t2.y" /* yacc.c:1646  */
    {
										//lbindval = 0;
										Lroot = NULL;
										bindval = -3;
										LAppendNode(&Lroot, LInstall((yyvsp[0].paramlist)->name, (yyvsp[0].paramlist)->type, bindval));
										(yyval.paramlist) = (yyvsp[0].paramlist);
									}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 195 "t2.y" /* yacc.c:1646  */
    {
										//lbindval = 0;
										(yyval.paramlist) = NULL;
									}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 201 "t2.y" /* yacc.c:1646  */
    {(yyval.paramlist) = createParamNode((yyvsp[0].treeNode)->varname, (yyvsp[-1].typeNode));}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 208 "t2.y" /* yacc.c:1646  */
    {
																printf("Function Definition of %s.\n", (yyvsp[-7].treeNode)->varname);
																if(returnType != (yyvsp[-8].typeNode))
																{
																	printf("return type : %s \t def return type : %s \n", returnType->name, (yyvsp[-8].typeNode)->name);
																	printf("Error. Return type mismatch.\n");
																	exit(1);
																}
																returnType = NULL;
																struct Gsymbol *temp = NULL;
																temp = GLookup(&Groot, (yyvsp[-7].treeNode)->varname);
																//1.\n");
																if(temp == NULL)
																{
																	printf("Function not globally declared.\n");
																	exit(1);
																}
																printf("Label No : %d\n", temp->fLabel);
																checkNameEqv(&temp, &((yyvsp[-5].paramlist)));
																//2.\n");
																//addParametersToLST(&Lroot, &($<paramlist>4));
																//printLSymbolTable(&Lroot);
																if(startCount == 0)
																{
																	print_header();
																	store_answer();
																	startCount = 1;
																}
																initFuncCode(temp->fLabel, &Lroot);
																//3.\n");
																int p = codeGen((yyvsp[-1].treeNode));
																//4.\n");
																endFuncCode(&Lroot);
																//evaluate($<treeNode>8);
																inorder((yyvsp[-1].treeNode));
																printf("Complete.\n");
																free(Lroot);
																free((yyvsp[-1].treeNode));
																Lroot = NULL;
															}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 250 "t2.y" /* yacc.c:1646  */
    {
															printf("Main Definition.\n");
															struct Typetable *tempType = TLookup(&Troot, "int");
															if(returnType != tempType)
															{
																printf("Error. Return type mismatch.\n");
																exit(1);
															}
															returnType = NULL;
															//printGSymbolTable(&Groot);
															if(startCount == 0)
															{
																print_header();
																store_answer();
																startCount = 1;
															}
															initFuncCode(-1, &Lroot);
															int p = codeGen((yyvsp[-1].treeNode));
															endFuncCode(&Lroot);
															//evaluate($<treeNode>7);
															inorder((yyvsp[-1].treeNode));
															printf("Complete.\n");
															free(Lroot);
															free((yyvsp[-1].treeNode));
															Lroot = NULL;
														}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 278 "t2.y" /* yacc.c:1646  */
    {
											lbindval = 0;
											printLSymbolTable(&Lroot);
										}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 282 "t2.y" /* yacc.c:1646  */
    {
											lbindval = 0;
											printLSymbolTable(&Lroot);
										}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 292 "t2.y" /* yacc.c:1646  */
    {
									LAssignType(&Lroot, (yyvsp[-2].typeNode));
								}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 297 "t2.y" /* yacc.c:1646  */
    {
									struct Lsymbol *temp = NULL;
									temp = LLookup(&Lroot, (yyvsp[0].treeNode)->varname);
									if(temp == NULL)
									{
										//
										//printf("%s\n", $<treeNode>1->varname);
										lbindval++;
										struct Lsymbol *temp2 = LInstall((yyvsp[0].treeNode)->varname, NULL, lbindval);
										LAppendNode(&Lroot, temp2);
										//
									}
									else
									{
										printf("Error. Variable declared twice.\n");
										exit(1);
									}
								}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 315 "t2.y" /* yacc.c:1646  */
    {
									lbindval++;
									LAppendNode(&Lroot, LInstall((yyvsp[0].treeNode)->varname, NULL, lbindval));
								}
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 321 "t2.y" /* yacc.c:1646  */
    {
										(yyval.treeNode) = createTree(0,NULL,NULL,NODE_CONN,NULL,NULL,NULL,(yyvsp[-2].treeNode),NULL,(yyvsp[-1].treeNode));
										returnType = (yyvsp[-1].treeNode)->type;
									}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 325 "t2.y" /* yacc.c:1646  */
    {
										(yyval.treeNode) = (yyvsp[-1].treeNode);
										returnType = (yyvsp[-1].treeNode)->type;
									}
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 331 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = createTree(0,NULL,NULL,NODE_CONN,NULL,NULL,NULL,(yyvsp[-1].treeNode),NULL,(yyvsp[0].treeNode));}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 332 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);}
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 335 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 336 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);}
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 337 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 338 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);}
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 339 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);}
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 340 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 341 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);}
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 342 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 343 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);}
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 344 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);}
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 347 "t2.y" /* yacc.c:1646  */
    {
									int flag = 0;
									struct Lsymbol *temp = LLookup(&Lroot, (yyvsp[-2].treeNode)->varname);
									struct Gsymbol *temp2 = NULL;
									if(temp == NULL)
									{
										flag++;
										printf("Not in LST.\n");
										temp2 = GLookup(&Groot, (yyvsp[-2].treeNode)->varname);
										if(temp2 == NULL)
										{
											printf("Variable not declared.\n");
											exit(1);
										}
									}
									if(flag == 0)
									{
										(yyvsp[-2].treeNode)->Lentry = temp;
										(yyvsp[-2].treeNode)->type = temp->type;
									}
									else
									{
										(yyvsp[-2].treeNode)->Gentry = temp2;
										(yyvsp[-2].treeNode)->type = temp2->type;
									}
									(yyval.treeNode) = createTree(0,NULL,NULL,NODE_READ,NULL,NULL,NULL,(yyvsp[-2].treeNode),NULL,NULL);
								}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 375 "t2.y" /* yacc.c:1646  */
    {
											//i again.\n");
											struct Gsymbol *temp1 = GLookup(&Groot, (yyvsp[-5].treeNode)->varname);
											if(temp1 == NULL)
											{
												printf("Array not declared.\n");
												exit(1);
											}
											(yyvsp[-5].treeNode)->Gentry = temp1;
											(yyvsp[-5].treeNode)->type = temp1->type;
											struct tnode *arrNode = createTree(0,(yyvsp[-5].treeNode)->type,NULL,NODE_ARR,NULL,NULL,NULL,(yyvsp[-5].treeNode),NULL,(yyvsp[-3].treeNode));
											(yyval.treeNode) = createTree(0,NULL,NULL,NODE_READ,NULL,NULL,NULL,arrNode,NULL,NULL);
											}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 389 "t2.y" /* yacc.c:1646  */
    {
											(yyval.treeNode) = createTree(0,NULL,NULL,NODE_READ,NULL,NULL,NULL,(yyvsp[-2].treeNode),NULL,NULL);
										}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 394 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = createTree(0,NULL,NULL,NODE_WRITE,NULL,NULL,NULL,(yyvsp[-2].treeNode),NULL,NULL);}
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 395 "t2.y" /* yacc.c:1646  */
    {
										struct Typetable *tempType = TLookup(&Troot, "str");
										(yyvsp[-2].treeNode)->type = tempType;
										(yyval.treeNode) = createTree(0,NULL,NULL,NODE_WRITE,NULL,NULL,NULL,(yyvsp[-2].treeNode),NULL,NULL);
									}
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 402 "t2.y" /* yacc.c:1646  */
    {
								int flag = 0;
								struct Lsymbol *tempNode = LLookup(&Lroot, (yyvsp[-3].treeNode)->varname);
								struct Gsymbol *tempNode2 = NULL;
								if(tempNode == NULL)
								{
									flag++;
									printf("Not in LST.\n");
									printf("%s\n", (yyvsp[-3].treeNode)->varname);
									tempNode2 = GLookup(&Groot, (yyvsp[-3].treeNode)->varname);
									if(tempNode2 == NULL)
									{
										printf("Variable not declared.\n");
										exit(1);
									}
									printf("There in GST.\n");
								}
								if(flag == 0)
								{
									(yyvsp[-3].treeNode)->Lentry = tempNode;
									(yyvsp[-3].treeNode)->type = tempNode->type;
								}
								else
								{
									//printf("There in GST2.\n");
									(yyvsp[-3].treeNode)->Gentry = tempNode2;
									//printf("%s\n", tempNode2->name);
									//printf("There in GST3.\n");
									(yyvsp[-3].treeNode)->type = tempNode2->type;
									//printf("There in GST4.\n");
								}
								char *temp = (char *)malloc(sizeof(char));
								strcpy(temp, "=");
								(yyval.treeNode) = createTree(0,NULL,temp,NODE_ASSGN,NULL,NULL,NULL,(yyvsp[-3].treeNode),NULL,(yyvsp[-1].treeNode));
							}
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 438 "t2.y" /* yacc.c:1646  */
    {
										struct Gsymbol *temp1 = GLookup(&Groot, (yyvsp[-6].treeNode)->varname);
										if(temp1 == NULL)
										{
											printf("Array not declared.\n");
											exit(1);
										}
										(yyvsp[-6].treeNode)->Gentry = temp1;
										(yyvsp[-6].treeNode)->type = temp1->type;
										char *temp = (char *)malloc(sizeof(char));
										strcpy(temp, "=");
										struct tnode *arrNode = createTree(0,(yyvsp[-6].treeNode)->type,NULL,NODE_ARR,NULL,NULL,NULL,(yyvsp[-6].treeNode),NULL,(yyvsp[-4].treeNode));
										(yyval.treeNode) = createTree(0,NULL,temp,NODE_ASSGN,NULL,NULL,NULL,arrNode,NULL,(yyvsp[-1].treeNode));
									}
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 453 "t2.y" /* yacc.c:1646  */
    {
									char *temp = (char *)malloc(sizeof(char));
									strcpy(temp, "=");
									(yyval.treeNode) = createTree(0,NULL,temp,NODE_ASSGN,NULL,NULL,NULL,(yyvsp[-3].treeNode),NULL,(yyvsp[-1].treeNode));
								}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 459 "t2.y" /* yacc.c:1646  */
    {
												int flag = 0;
												struct Lsymbol *tempNode = LLookup(&Lroot, (yyvsp[-5].treeNode)->varname);
												struct Gsymbol *tempNode2 = NULL;
												if(tempNode == NULL)
												{
													flag++;
													printf("Not in LST.\n");
													printf("%s\n", (yyvsp[-5].treeNode)->varname);
													tempNode2 = GLookup(&Groot, (yyvsp[-5].treeNode)->varname);
													if(tempNode2 == NULL)
													{
														printf("Variable not declared.\n");
														exit(1);
													}
													printf("There in GST.\n");
												}
												if(flag == 0)
												{
													(yyvsp[-5].treeNode)->Lentry = tempNode;
													(yyvsp[-5].treeNode)->type = tempNode->type;
												}
												else
												{
													//printf("There in GST2.\n");
													(yyvsp[-5].treeNode)->Gentry = tempNode2;
													//printf("%s\n", tempNode2->name);
													//printf("There in GST3.\n");
													(yyvsp[-5].treeNode)->type = tempNode2->type;
													//printf("There in GST4.\n");
												}
												(yyvsp[-3].treeNode)->type = (yyvsp[-5].treeNode)->type;
												char *temp = (char *)malloc(sizeof(char));
												strcpy(temp, "=");
												(yyval.treeNode) = createTree(0,NULL,temp,NODE_ASSGN,NULL,NULL,NULL,(yyvsp[-5].treeNode),NULL,(yyvsp[-3].treeNode));
											}
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 495 "t2.y" /* yacc.c:1646  */
    {
										int flag = 0;
										struct Lsymbol *tempNode = LLookup(&Lroot, (yyvsp[-5].treeNode)->varname);
										struct Gsymbol *tempNode2 = NULL;
										if(tempNode == NULL)
										{
											flag++;
											printf("Not in LST.\n");
											printf("%s\n", (yyvsp[-5].treeNode)->varname);
											tempNode2 = GLookup(&Groot, (yyvsp[-5].treeNode)->varname);
											if(tempNode2 == NULL)
											{
												printf("Variable not declared.\n");
												exit(1);
											}
											printf("There in GST.\n");
										}
										if(flag == 0)
										{
											(yyvsp[-5].treeNode)->Lentry = tempNode;
											(yyvsp[-5].treeNode)->type = tempNode->type;
										}
										else
										{
											//printf("There in GST2.\n");
											(yyvsp[-5].treeNode)->Gentry = tempNode2;
											//printf("%s\n", tempNode2->name);
											//printf("There in GST3.\n");
											(yyvsp[-5].treeNode)->type = tempNode2->type;
											//printf("There in GST4.\n");
										}
										(yyvsp[-3].treeNode)->type = (yyvsp[-5].treeNode)->type;
										char *temp = (char *)malloc(sizeof(char));
										strcpy(temp, "=");
										(yyval.treeNode) = createTree(0,NULL,temp,NODE_ASSGN,NULL,NULL,NULL,(yyvsp[-5].treeNode),NULL,(yyvsp[-3].treeNode));
									}
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 531 "t2.y" /* yacc.c:1646  */
    {
											(yyvsp[-3].treeNode)->type = getFieldType(&((yyvsp[-5].treeNode)));
											char *temp = (char *)malloc(sizeof(char));
											strcpy(temp, "=");
											(yyval.treeNode) = createTree(0,NULL,temp,NODE_ASSGN,NULL,NULL,NULL,(yyvsp[-5].treeNode),NULL,(yyvsp[-3].treeNode));
										}
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 537 "t2.y" /* yacc.c:1646  */
    {
											int flag = 0;
											struct Lsymbol *tempNode = LLookup(&Lroot, (yyvsp[-2].treeNode)->varname);
											struct Gsymbol *tempNode2 = NULL;
											if(tempNode == NULL)
											{
												flag++;
												printf("Not in LST.\n");
												printf("%s\n", (yyvsp[-2].treeNode)->varname);
												tempNode2 = GLookup(&Groot, (yyvsp[-2].treeNode)->varname);
												if(tempNode2 == NULL)
												{
													printf("Variable not declared.\n");
													exit(1);
												}
												printf("There in GST.\n");
											}
											if(flag == 0)
											{
												(yyvsp[-2].treeNode)->Lentry = tempNode;
												(yyvsp[-2].treeNode)->type = tempNode->type;
											}
											else
											{
												//printf("There in GST2.\n");
												(yyvsp[-2].treeNode)->Gentry = tempNode2;
												//printf("%s\n", tempNode2->name);
												//printf("There in GST3.\n");
												(yyvsp[-2].treeNode)->type = tempNode2->type;
												//printf("There in GST4.\n");
											}
											(yyvsp[-4].treeNode)->left = (yyvsp[-2].treeNode);
											(yyval.treeNode) = (yyvsp[-4].treeNode);
										}
#line 2273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 571 "t2.y" /* yacc.c:1646  */
    {
											(yyvsp[-4].treeNode)->left = (yyvsp[-2].treeNode);
											(yyval.treeNode) = (yyvsp[-4].treeNode);
										}
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 577 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = createTree(0,NULL,NULL,NODE_IF,NULL,NULL,NULL,(yyvsp[-7].treeNode),(yyvsp[-4].treeNode),(yyvsp[-2].treeNode));}
#line 2288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 578 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = createTree(0,NULL,NULL,NODE_IF,NULL,NULL,NULL,(yyvsp[-5].treeNode),(yyvsp[-2].treeNode),NULL);}
#line 2294 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 581 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = createTree(0,NULL,NULL,NODE_WHILE,NULL,NULL,NULL,(yyvsp[-5].treeNode),NULL,(yyvsp[-2].treeNode));}
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 584 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = createTree(0,NULL,NULL,NODE_BREAK,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 587 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = createTree(0,NULL,NULL,NODE_CONTINUE,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 590 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = createTree(0,NULL,NULL,NODE_REPUNTIL,NULL,NULL,NULL,(yyvsp[-3].treeNode),NULL,(yyvsp[-1].treeNode));}
#line 2318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 593 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = createTree(0,NULL,NULL,NODE_DOWHILE,NULL,NULL,NULL,(yyvsp[-5].treeNode),NULL,(yyvsp[-2].treeNode));}
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 596 "t2.y" /* yacc.c:1646  */
    {
								//lbindval = 0;
								(yyval.treeNode) = createTree(0,(yyvsp[-1].treeNode)->type,NULL,NODE_RETURN,NULL,NULL,NULL,(yyvsp[-1].treeNode),NULL,NULL);
							}
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 602 "t2.y" /* yacc.c:1646  */
    {
								int flag = 0;
								struct Lsymbol *tempNode = LLookup(&Lroot, (yyvsp[-2].treeNode)->varname);
								struct Gsymbol *tempNode2 = NULL;
								if(tempNode == NULL)
								{
									flag++;
									printf("Not in LST.\n");
									tempNode2 = GLookup(&Groot, (yyvsp[-2].treeNode)->varname);
									if(tempNode2 == NULL)
									{
										printf("Variable not declared.\n");
										exit(1);
									}
									printf("There in GST.\n");
								}
								if(flag == 0)
								{
									(yyvsp[-2].treeNode)->Lentry = tempNode;
									(yyvsp[-2].treeNode)->type = tempNode->type;
								}
								else
								{
									//printf("There in GST2.\n");
									(yyvsp[-2].treeNode)->Gentry = tempNode2;
									//printf("%s\n", tempNode2->name);
									//printf("There in GST3.\n");
									(yyvsp[-2].treeNode)->type = tempNode2->type;
									//printf("There in GST4.\n");
								}
								struct Fieldlist *tempNode3 = FLookup(&((yyvsp[-2].treeNode)->type), (yyvsp[0].treeNode)->varname);
								if(tempNode3 == NULL)
								{
									printf("Invalid member of user-defined type accessed.\n");
									exit(0);
								}
								(yyvsp[0].treeNode)->type = tempNode3->type;
								(yyvsp[0].treeNode)->nodetype = NODE_FIELD;
								(yyvsp[-2].treeNode)->nodetype = NODE_FIELD;
								//struct tnode *memberNode = createTree(0,tempNode3->type,tempNode3->name,NODE_FIELD,NULL,NULL,NULL,NULL,NULL,NULL);
								(yyvsp[-2].treeNode)->left = (yyvsp[0].treeNode);
								(yyval.treeNode) = (yyvsp[-2].treeNode);
							}
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 645 "t2.y" /* yacc.c:1646  */
    {
				  				struct tnode *tempNode = (yyvsp[-2].treeNode);
								while(tempNode->left)
								{
									tempNode = tempNode->left;
								}
				  				struct Fieldlist *tempNode3 = FLookup(&(tempNode->type), (yyvsp[0].treeNode)->varname);
								if(tempNode3 == NULL)
								{
									printf("Invalid member of user-defined type accessed.\n");
									exit(0);
								}
				  				(yyvsp[0].treeNode)->type = tempNode3->type;
								(yyvsp[0].treeNode)->nodetype = NODE_FIELD;
								tempNode->left = (yyvsp[0].treeNode);
								(yyval.treeNode) = (yyvsp[-2].treeNode);
			  				}
#line 2403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 664 "t2.y" /* yacc.c:1646  */
    {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "+");
				struct Typetable *tempType = TLookup(&Troot, "int");
				(yyval.treeNode) = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,(yyvsp[-2].treeNode),NULL,(yyvsp[0].treeNode));}
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 669 "t2.y" /* yacc.c:1646  */
    {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "-");
				struct Typetable *tempType = TLookup(&Troot, "int");
				(yyval.treeNode) = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,(yyvsp[-2].treeNode),NULL,(yyvsp[0].treeNode));}
#line 2421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 674 "t2.y" /* yacc.c:1646  */
    {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "*");
				struct Typetable *tempType = TLookup(&Troot, "int");
				(yyval.treeNode) = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,(yyvsp[-2].treeNode),NULL,(yyvsp[0].treeNode));}
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 679 "t2.y" /* yacc.c:1646  */
    {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "/");
				struct Typetable *tempType = TLookup(&Troot, "int");
				(yyval.treeNode) = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,(yyvsp[-2].treeNode),NULL,(yyvsp[0].treeNode));}
#line 2439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 684 "t2.y" /* yacc.c:1646  */
    {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "%");
				struct Typetable *tempType = TLookup(&Troot, "int");
				(yyval.treeNode) = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,(yyvsp[-2].treeNode),NULL,(yyvsp[0].treeNode));}
#line 2448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 689 "t2.y" /* yacc.c:1646  */
    {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, "<");
				struct Typetable *tempType = TLookup(&Troot, "bool");
				(yyval.treeNode) = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,(yyvsp[-2].treeNode),NULL,(yyvsp[0].treeNode));}
#line 2457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 694 "t2.y" /* yacc.c:1646  */
    {char *temp = (char *)malloc(sizeof(char));
				strcpy(temp, ">");
				struct Typetable *tempType = TLookup(&Troot, "bool");
				(yyval.treeNode) = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,(yyvsp[-2].treeNode),NULL,(yyvsp[0].treeNode));}
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 699 "t2.y" /* yacc.c:1646  */
    {char *temp = (char *)malloc(2*sizeof(char));
				strcpy(temp, "<=");
				struct Typetable *tempType = TLookup(&Troot, "bool");
				(yyval.treeNode) = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,(yyvsp[-2].treeNode),NULL,(yyvsp[0].treeNode));}
#line 2475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 704 "t2.y" /* yacc.c:1646  */
    {char *temp = (char *)malloc(2*sizeof(char));
				strcpy(temp, ">=");
				struct Typetable *tempType = TLookup(&Troot, "bool");
				(yyval.treeNode) = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,(yyvsp[-2].treeNode),NULL,(yyvsp[0].treeNode));}
#line 2484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 709 "t2.y" /* yacc.c:1646  */
    {char *temp = (char *)malloc(2*sizeof(char));
				strcpy(temp, "!=");
				struct Typetable *tempType = TLookup(&Troot, "bool");
				//printf("Node Type: %d\n", booltype);
				(yyval.treeNode) = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,(yyvsp[-2].treeNode),NULL,(yyvsp[0].treeNode));}
#line 2494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 715 "t2.y" /* yacc.c:1646  */
    {char *temp = (char *)malloc(2*sizeof(char));
				strcpy(temp, "==");
				struct Typetable *tempType = TLookup(&Troot, "bool");
				(yyval.treeNode) = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,(yyvsp[-2].treeNode),NULL,(yyvsp[0].treeNode));}
#line 2503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 720 "t2.y" /* yacc.c:1646  */
    {char *temp = (char *)malloc(2*sizeof(char));
				strcpy(temp, "&&");
				struct Typetable *tempType = TLookup(&Troot, "bool");
				(yyval.treeNode) = createTree(0,tempType,temp,NODE_EX,NULL,NULL,NULL,(yyvsp[-2].treeNode),NULL,(yyvsp[0].treeNode));}
#line 2512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 725 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[-1].treeNode);}
#line 2518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 726 "t2.y" /* yacc.c:1646  */
    {
					struct Typetable *tempType = TLookup(&Troot, "int");
					(yyvsp[0].treeNode)->type = tempType;
					(yyval.treeNode) = (yyvsp[0].treeNode);
				}
#line 2528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 731 "t2.y" /* yacc.c:1646  */
    {
						struct Typetable *tempType = TLookup(&Troot, "str");
						(yyvsp[0].treeNode)->type = tempType;
						(yyval.treeNode) = (yyvsp[0].treeNode);
					}
#line 2538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 736 "t2.y" /* yacc.c:1646  */
    {
					struct Typetable *tempType = TLookup(&Troot, "null");
					(yyvsp[0].treeNode)->type = tempType;
					(yyval.treeNode) = (yyvsp[0].treeNode);
				}
#line 2548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 741 "t2.y" /* yacc.c:1646  */
    {
						struct Gsymbol *temp1 = GLookup(&Groot, (yyvsp[-3].treeNode)->varname);
						if(temp1 == NULL)
						{
							printf("Array not declared.\n");
							exit(1);
						}
						(yyvsp[-3].treeNode)->Gentry = temp1;
						(yyvsp[-3].treeNode)->type = temp1->type;
						(yyval.treeNode) = createTree(0,temp1->type,NULL,NODE_ARR,NULL,NULL,NULL,(yyvsp[-3].treeNode),NULL,(yyvsp[-1].treeNode));
					}
#line 2564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 752 "t2.y" /* yacc.c:1646  */
    {
					int flag = 0;
					struct Lsymbol *temp = LLookup(&Lroot, (yyvsp[0].treeNode)->varname);
					struct Gsymbol *temp2 = NULL;
					if(temp == NULL)
					{
						flag++;
						printf("Not in LST.\n");
						temp2 = GLookup(&Groot, (yyvsp[0].treeNode)->varname);
						if(temp2 == NULL)
						{
							printf("Variable not declared.\n");
							exit(1);
						}
					}
					printf("There in GST.\n");
					if(flag == 0)
					{
						(yyvsp[0].treeNode)->Lentry = temp;
						(yyvsp[0].treeNode)->type = temp->type;
					}
					else
					{
						(yyvsp[0].treeNode)->Gentry = temp2;
						(yyvsp[0].treeNode)->type = temp2->type;
					}
					(yyval.treeNode) = (yyvsp[0].treeNode);
				}
#line 2597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 780 "t2.y" /* yacc.c:1646  */
    {
								struct Gsymbol *temp = GLookup(&Groot, (yyvsp[-2].treeNode)->varname);
								if(temp == NULL)
								{
									printf("Function not declared.\n");
									exit(1);
								}
								(yyvsp[-2].treeNode)->Gentry = temp;
								(yyvsp[-2].treeNode)->type = temp->type;
								(yyval.treeNode) = createTree(0,(yyvsp[-2].treeNode)->type,(yyvsp[-2].treeNode)->varname,NODE_FUNCTION,(yyvsp[-2].treeNode)->Gentry,NULL,NULL,NULL,NULL,NULL);
							}
#line 2613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 791 "t2.y" /* yacc.c:1646  */
    {
								struct Gsymbol *temp = GLookup(&Groot, (yyvsp[-3].treeNode)->varname);
								if(temp == NULL)
								{
									printf("Function not declared.\n");
									exit(1);
								}
								(yyvsp[-3].treeNode)->Gentry = temp;
								(yyvsp[-3].treeNode)->type = temp->type;
								(yyval.treeNode) = createTree(0,(yyvsp[-3].treeNode)->type,(yyvsp[-3].treeNode)->varname,NODE_FUNCTION,(yyvsp[-3].treeNode)->Gentry,NULL,NULL,(yyvsp[-1].treeNode),NULL,NULL);
							}
#line 2629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 802 "t2.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);}
#line 2635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 805 "t2.y" /* yacc.c:1646  */
    {
									appendArg(&((yyvsp[-2].treeNode)),(yyvsp[0].treeNode));
									(yyval.treeNode) = (yyvsp[-2].treeNode);
								}
#line 2644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 809 "t2.y" /* yacc.c:1646  */
    {
									(yyval.treeNode) = (yyvsp[0].treeNode);
								}
#line 2652 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2656 "y.tab.c" /* yacc.c:1646  */
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
#line 814 "t2.y" /* yacc.c:1906  */


int yyerror(char const *s)
{
    printf("yyerror %s",s);
}

int main(int argc, char *argv[])
{
	FILE *fptr;
	if(argc > 1)
	{
		fptr = fopen(argv[1], "r");
		if(fptr)
		{
			yyin = fptr;
		}
	}
	xsm_file = fopen("code.xsm", "w");
	infile = fopen("input.txt", "r");
	outfile = fopen("output.txt", "w");
	TypeTableCreate(&Troot);
	printf("Initial Type Table.\n");
	printTypeTable(&Troot);
	yyparse();
	if(fptr)
		fclose(fptr);
	fclose(xsm_file);
	fclose(infile);
	fclose(outfile);
	return 0;
}
