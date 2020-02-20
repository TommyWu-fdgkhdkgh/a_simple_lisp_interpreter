/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     number = 258,
     id = 259,
     boolVal = 260,
     mod = 261,
     and = 262,
     or = 263,
     not = 264,
     define = 265,
     fun = 266,
     IF = 267,
     print_num = 268,
     print_bool = 269
   };
#endif
/* Tokens.  */
#define number 258
#define id 259
#define boolVal 260
#define mod 261
#define and 262
#define or 263
#define not 264
#define define 265
#define fun 266
#define IF 267
#define print_num 268
#define print_bool 269




/* Copy the first part of user declarations.  */
#line 1 "c.y"

#include <stdio.h>
#include <string.h>
#include "c.h"
void yyerror(const char *message);
struct EXP *global_variable=NULL;/*point to head*/
struct EXP *global_variable_tail=NULL;/* point to tail */

int calc(exp *target,exp *table);/* 遍尋樹，算出該樹的值 */
exp *create_formula(char *operator,exp *p1,exp *p2);
exp *look_symbol_table(exp *which_table,char *variableName);/* 遍尋symbol_table，並返回symbol */
exp *copy_to_new_node(exp *target);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 14 "c.y"
{
	int ival;
	char* word;
	struct NODE  *n;
	struct EXP *e;
	struct symbol_node *symp;

}
/* Line 193 of yacc.c.  */
#line 147 "c.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 160 "c.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  24
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNRULES -- Number of states.  */
#define YYNSTATES  118

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   269

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      15,    16,    19,    17,     2,    18,     2,    20,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      22,    23,    21,     2,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    17,
      20,    25,    30,    32,    34,    36,    38,    40,    42,    44,
      46,    49,    50,    52,    54,    56,    58,    60,    62,    64,
      66,    72,    78,    84,    90,    96,   102,   108,   114,   116,
     118,   120,   126,   132,   137,   143,   145,   147,   150,   156,
     160,   163,   166,   168,   173,   178,   180,   187,   189,   191
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      25,     0,    -1,    26,    -1,    27,    26,    -1,    -1,    30,
      -1,    45,    -1,    29,    -1,    45,    -1,    28,    45,    -1,
      15,    13,    30,    16,    -1,    15,    14,    30,    16,    -1,
       5,    -1,     3,    -1,    46,    -1,    32,    -1,    41,    -1,
      48,    -1,    51,    -1,    53,    -1,    30,    31,    -1,    -1,
      33,    -1,    34,    -1,    35,    -1,    36,    -1,    37,    -1,
      38,    -1,    39,    -1,    40,    -1,    15,    17,    30,    31,
      16,    -1,    15,    18,    30,    30,    16,    -1,    15,    19,
      30,    31,    16,    -1,    15,    20,    30,    30,    16,    -1,
      15,     6,    30,    30,    16,    -1,    15,    21,    30,    30,
      16,    -1,    15,    22,    30,    30,    16,    -1,    15,    23,
      30,    31,    16,    -1,    42,    -1,    43,    -1,    44,    -1,
      15,     7,    30,    31,    16,    -1,    15,     8,    30,    31,
      16,    -1,    15,     9,    30,    16,    -1,    15,    10,    46,
      30,    16,    -1,     4,    -1,     4,    -1,    47,     4,    -1,
      15,    11,    49,    50,    16,    -1,    15,    47,    16,    -1,
      15,    16,    -1,    28,    30,    -1,    30,    -1,    15,    48,
      31,    16,    -1,    15,    52,    31,    16,    -1,     4,    -1,
      15,    12,    54,    55,    56,    16,    -1,    30,    -1,    30,
      -1,    30,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    62,    62,    65,    66,    68,    69,    78,    80,    83,
      90,   102,   118,   132,   140,   143,   146,   149,   152,   155,
     159,   168,   170,   173,   176,   179,   182,   185,   188,   191,
     195,   199,   203,   207,   211,   215,   219,   223,   227,   230,
     233,   237,   241,   245,   249,   254,   266,   275,   290,   307,
     310,   314,   325,   330,   340,   384,   388,   399,   403,   407
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "number", "id", "boolVal", "mod", "and",
  "or", "not", "define", "fun", "IF", "print_num", "print_bool", "'('",
  "')'", "'+'", "'-'", "'*'", "'/'", "'>'", "'<'", "'='", "$accept",
  "PROGRAM", "MORE_STMT", "STMT", "MORE_DEF", "PRINT_STMT", "EXP",
  "MORE_EXP", "NUM_OP", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MODULUS",
  "GREATER", "SMALLER", "EQUAL", "LOGICAL_OP", "AND_OP", "OR_OP", "NOT_OP",
  "DEF_STMT", "VARIABLE", "IDs", "FUN_EXP", "FUN_IDs", "FUN_BODY",
  "FUN_CALL", "FUN_NAME", "IF_EXP", "TEXT_EXP", "THEN_EXP", "ELSE_EXP", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,    40,    41,    43,    45,    42,
      47,    62,    60,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    24,    25,    26,    26,    27,    27,    27,    28,    28,
      29,    29,    30,    30,    30,    30,    30,    30,    30,    30,
      31,    31,    32,    32,    32,    32,    32,    32,    32,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    41,
      41,    42,    43,    44,    45,    46,    47,    47,    48,    49,
      49,    50,    50,    51,    51,    52,    53,    54,    55,    56
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     2,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     5,     5,     5,     5,     5,     5,     1,     1,
       1,     5,     5,     4,     5,     1,     1,     2,     5,     3,
       2,     2,     1,     4,     4,     1,     6,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    13,    45,    12,     0,     0,     2,     4,     7,     5,
      15,    22,    23,    24,    25,    26,    27,    28,    29,    16,
      38,    39,    40,     6,    14,    17,    18,    19,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,    21,     1,     3,
       0,     0,    21,    21,     0,     0,     0,     0,    57,     0,
       0,     0,    21,     0,    21,     0,     0,     0,    21,    21,
       0,     0,     0,     0,     0,    43,     0,    46,    50,     0,
       0,     0,    52,     8,     0,    58,     0,    10,    11,     0,
       0,     0,     0,     0,     0,     0,    20,    53,    54,    34,
      41,    42,    44,    47,    49,    51,     9,    48,    59,     0,
      30,    31,    32,    33,    35,    36,    37,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    81,     8,    69,    70,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    79,    25,    57,    84,    26,    47,    27,
      59,    86,   109
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -56
static const yytype_int8 yypact[] =
{
       1,   -56,   -56,   -56,    81,    13,   -56,     1,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,     7,
       7,     7,     7,    10,     2,     7,     7,     7,     8,     7,
       7,     7,     7,     7,     7,     7,     7,     7,   -56,   -56,
     121,     7,     7,     7,    12,     7,    11,    45,   -56,     7,
      18,    22,     7,     7,     7,     7,     7,     7,     7,     7,
      30,    36,    37,    38,    40,   -56,    42,   -56,   -56,    17,
     101,    45,   -56,   -56,    46,   -56,     7,   -56,   -56,    48,
      52,    53,    54,    55,    56,    57,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,    58,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -56,   -56,    16,   -56,   -56,   -56,     0,   -44,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   -55,    28,   -56,    -3,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -56
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       9,    46,    83,    71,     1,     2,     3,     9,    73,    74,
       1,     2,     3,    48,     2,    77,     4,    56,    89,    34,
      91,   103,    50,    49,    95,    96,   106,    78,    75,    51,
      52,    53,    54,   104,    87,    58,    60,    61,    88,    62,
      63,    64,    65,    66,    67,    68,    97,    46,     1,     2,
       3,    72,    98,    99,   100,    76,   101,    82,   102,    85,
      80,    55,   107,    90,   110,    92,    93,    94,   111,   112,
     113,   114,   115,   116,   117,     0,     0,    46,     0,     0,
       0,   105,     0,     0,     0,    28,   108,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,     0,    39,    40,
      41,    42,    43,    44,    45,    28,     0,    29,    30,    31,
      32,    33,    34,    35,     0,     0,    38,     0,    39,    40,
      41,    42,    43,    44,    45,    28,     0,    29,    30,    31,
      32,     0,    34,    35,     0,     0,    38,     0,    39,    40,
      41,    42,    43,    44,    45
};

static const yytype_int8 yycheck[] =
{
       0,     4,    57,    47,     3,     4,     5,     7,    52,    53,
       3,     4,     5,     0,     4,     4,    15,    15,    62,    11,
      64,     4,    15,     7,    68,    69,    81,    16,    16,    29,
      30,    31,    32,    16,    16,    35,    36,    37,    16,    39,
      40,    41,    42,    43,    44,    45,    16,    50,     3,     4,
       5,    51,    16,    16,    16,    55,    16,    57,    16,    59,
      15,    33,    16,    63,    16,    65,    66,    67,    16,    16,
      16,    16,    16,    16,    16,    -1,    -1,    80,    -1,    -1,
      -1,    81,    -1,    -1,    -1,     4,    86,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    21,    22,    23,     4,    -1,     6,     7,     8,
       9,    10,    11,    12,    -1,    -1,    15,    -1,    17,    18,
      19,    20,    21,    22,    23,     4,    -1,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    15,    -1,    17,    18,
      19,    20,    21,    22,    23
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    15,    25,    26,    27,    29,    30,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    48,    51,    53,     4,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    17,
      18,    19,    20,    21,    22,    23,    48,    52,     0,    26,
      15,    30,    30,    30,    30,    46,    15,    49,    30,    54,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      31,    31,    30,    31,    31,    16,    30,     4,    16,    47,
      15,    28,    30,    45,    50,    30,    55,    16,    16,    31,
      30,    31,    30,    30,    30,    31,    31,    16,    16,    16,
      16,    16,    16,     4,    16,    30,    45,    16,    30,    56,
      16,    16,    16,    16,    16,    16,    16,    16
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 62 "c.y"
    {
						;}
    break;

  case 4:
#line 66 "c.y"
    {(yyval.e)=NULL;;}
    break;

  case 5:
#line 68 "c.y"
    { calc((yyvsp[(1) - (1)].e),global_variable); ;}
    break;

  case 6:
#line 69 "c.y"
    {
								if(global_variable==NULL){
									global_variable=(yyvsp[(1) - (1)].e);
									global_variable_tail=(yyvsp[(1) - (1)].e);
								}else{
									global_variable_tail->next=(yyvsp[(1) - (1)].e);
									global_variable_tail=(yyvsp[(1) - (1)].e);
								}
					;}
    break;

  case 8:
#line 80 "c.y"
    {
								(yyval.e)=(yyvsp[(1) - (1)].e);
							;}
    break;

  case 9:
#line 83 "c.y"
    {
								exp *wp=(yyvsp[(1) - (2)].e);
								for(;wp->next;wp=wp->next){}
								wp->next=(yyvsp[(2) - (2)].e);
								(yyval.e)=(yyvsp[(1) - (2)].e);
							;}
    break;

  case 10:
#line 90 "c.y"
    {
									int type_check;
									type_check=calc((yyvsp[(3) - (4)].e),global_variable);
									if(type_check==-1){
										return 0;
									}
									if(strcmp((yyvsp[(3) - (4)].e)->type,"int")==0){
											printf("%d\n",(yyvsp[(3) - (4)].e)->value);
									}else{
											printf("not int!\n");
									}
								;}
    break;

  case 11:
#line 102 "c.y"
    {
									int type_check;
									type_check=calc((yyvsp[(3) - (4)].e),global_variable);
									if(type_check==-1){
										return 0;
									}
									if(strcmp((yyvsp[(3) - (4)].e)->type,"boolVal")==0){
											if((yyvsp[(3) - (4)].e)->value==1){
												printf("#t\n");
											}
											else if((yyvsp[(3) - (4)].e)->value==0){
												printf("#f\n");
											}
									}
								;}
    break;

  case 12:
#line 118 "c.y"
    {
					int a;
					if(strcmp((yyvsp[(1) - (1)].word),"#t")==0){
						a=1;
					}else if(strcmp((yyvsp[(1) - (1)].word),"#f")==0){
						a=0;
					}
					(yyval.e)=(exp *)malloc(sizeof(exp));
					(yyval.e)->type="boolVal";
					(yyval.e)->type_2="const";
					(yyval.e)->value=a;
					(yyval.e)->next=NULL;
					(yyval.e)->parameters=NULL;
				;}
    break;

  case 13:
#line 132 "c.y"
    {
					(yyval.e)=(exp *)malloc(sizeof(exp));
					(yyval.e)->type="int";
					(yyval.e)->type_2="const";
					(yyval.e)->value=(yyvsp[(1) - (1)].ival);
					(yyval.e)->next=NULL;
					(yyval.e)->parameters=NULL;
				;}
    break;

  case 14:
#line 140 "c.y"
    {
					(yyval.e)=(yyvsp[(1) - (1)].e);
				;}
    break;

  case 15:
#line 143 "c.y"
    {
					(yyval.e)=(yyvsp[(1) - (1)].e);
				;}
    break;

  case 16:
#line 146 "c.y"
    {
					(yyval.e)=(yyvsp[(1) - (1)].e);
				;}
    break;

  case 17:
#line 149 "c.y"
    {
					(yyval.e)=(yyvsp[(1) - (1)].e);
				;}
    break;

  case 18:
#line 152 "c.y"
    {
					(yyval.e)=(yyvsp[(1) - (1)].e);
				;}
    break;

  case 19:
#line 155 "c.y"
    {
					(yyval.e)=(yyvsp[(1) - (1)].e);
				;}
    break;

  case 20:
#line 159 "c.y"
    {
								if((yyvsp[(2) - (2)].e)==NULL){
									(yyvsp[(1) - (2)].e)->next=NULL;
									(yyval.e)=(yyvsp[(1) - (2)].e);
								}else{
									(yyvsp[(1) - (2)].e)->next=(yyvsp[(2) - (2)].e);
									(yyval.e)=(yyvsp[(1) - (2)].e);
								}
							;}
    break;

  case 21:
#line 168 "c.y"
    {(yyval.e)=NULL;;}
    break;

  case 22:
#line 170 "c.y"
    {
							(yyval.e)=(yyvsp[(1) - (1)].e);
						;}
    break;

  case 23:
#line 173 "c.y"
    {
							(yyval.e)=(yyvsp[(1) - (1)].e);
						;}
    break;

  case 24:
#line 176 "c.y"
    {
							(yyval.e)=(yyvsp[(1) - (1)].e);
						;}
    break;

  case 25:
#line 179 "c.y"
    {
							(yyval.e)=(yyvsp[(1) - (1)].e);
						;}
    break;

  case 26:
#line 182 "c.y"
    {
							(yyval.e)=(yyvsp[(1) - (1)].e);
						;}
    break;

  case 27:
#line 185 "c.y"
    {
							(yyval.e)=(yyvsp[(1) - (1)].e);
						;}
    break;

  case 28:
#line 188 "c.y"
    {
							(yyval.e)=(yyvsp[(1) - (1)].e);
						;}
    break;

  case 29:
#line 191 "c.y"
    {
							(yyval.e)=(yyvsp[(1) - (1)].e);
						;}
    break;

  case 30:
#line 195 "c.y"
    {
						(yyval.e)=create_formula("+",(yyvsp[(3) - (5)].e),(yyvsp[(4) - (5)].e));
					;}
    break;

  case 31:
#line 199 "c.y"
    {
						(yyval.e)=create_formula("-",(yyvsp[(3) - (5)].e),(yyvsp[(4) - (5)].e));
					;}
    break;

  case 32:
#line 203 "c.y"
    {
						(yyval.e)=create_formula("*",(yyvsp[(3) - (5)].e),(yyvsp[(4) - (5)].e));
							;}
    break;

  case 33:
#line 207 "c.y"
    {
						(yyval.e)=create_formula("/",(yyvsp[(3) - (5)].e),(yyvsp[(4) - (5)].e));
						;}
    break;

  case 34:
#line 211 "c.y"
    {
						(yyval.e)=create_formula("mod",(yyvsp[(3) - (5)].e),(yyvsp[(4) - (5)].e));
						;}
    break;

  case 35:
#line 215 "c.y"
    {
						(yyval.e)=create_formula(">",(yyvsp[(3) - (5)].e),(yyvsp[(4) - (5)].e));
						;}
    break;

  case 36:
#line 219 "c.y"
    {
						(yyval.e)=create_formula("<",(yyvsp[(3) - (5)].e),(yyvsp[(4) - (5)].e));
						;}
    break;

  case 37:
#line 223 "c.y"
    {
						(yyval.e)=create_formula("=",(yyvsp[(3) - (5)].e),(yyvsp[(4) - (5)].e));
						;}
    break;

  case 38:
#line 227 "c.y"
    {
									(yyval.e)=(yyvsp[(1) - (1)].e);
								;}
    break;

  case 39:
#line 230 "c.y"
    {
									(yyval.e)=(yyvsp[(1) - (1)].e);;
								;}
    break;

  case 40:
#line 233 "c.y"
    {
									(yyval.e)=(yyvsp[(1) - (1)].e);
								;}
    break;

  case 41:
#line 237 "c.y"
    {
								(yyval.e)=create_formula("and",(yyvsp[(3) - (5)].e),(yyvsp[(4) - (5)].e));
						;}
    break;

  case 42:
#line 241 "c.y"
    {
								(yyval.e)=create_formula("or",(yyvsp[(3) - (5)].e),(yyvsp[(4) - (5)].e));
						;}
    break;

  case 43:
#line 245 "c.y"
    {
							(yyval.e)=create_formula("not",(yyvsp[(3) - (4)].e),NULL);
						;}
    break;

  case 44:
#line 249 "c.y"
    {
								(yyvsp[(4) - (5)].e)->variableName=(yyvsp[(3) - (5)].e)->variableName;
								(yyval.e)=(yyvsp[(4) - (5)].e);
							;}
    break;

  case 45:
#line 254 "c.y"
    {
								(yyval.e)=(exp *)malloc(sizeof(exp));
								(yyval.e)->type="unInit";
								(yyval.e)->type_2="variable";
								(yyval.e)->isVariable=1;
								(yyval.e)->variableName=(yyvsp[(1) - (1)].word);
								(yyval.e)->value=0;
								(yyval.e)->next=NULL;
								(yyval.e)->funbody=NULL;
								(yyval.e)->parameters=NULL;
							;}
    break;

  case 46:
#line 266 "c.y"
    {
						(yyval.e)=(exp *)malloc(sizeof(exp));
						(yyval.e)->type="unInit";
						(yyval.e)->type_2="variable";
						(yyval.e)->variableName=(yyvsp[(1) - (1)].word);
						(yyval.e)->value=0;
						(yyval.e)->next=NULL;
						(yyval.e)->parameters=NULL;
				;}
    break;

  case 47:
#line 275 "c.y"
    {
						exp *p=(exp *)malloc(sizeof(exp));
						p->type="unInit";
						p->type_2="variable";
						p->variableName=(yyvsp[(2) - (2)].word);
						p->value=0;
						p->next=NULL;
						p->parameters=NULL;

						exp *wp=(yyvsp[(1) - (2)].e);
						for(;wp->next;wp=wp->next){}
						wp->next=p;
						(yyval.e)=(yyvsp[(1) - (2)].e);
				;}
    break;

  case 48:
#line 290 "c.y"
    {
							(yyval.e)=(exp *)malloc(sizeof(exp));
							(yyval.e)->type=(yyvsp[(4) - (5)].e)->type;
							(yyval.e)->type_2="fun";
							(yyval.e)->next=NULL;
							(yyval.e)->funbody=(yyvsp[(4) - (5)].e);
							(yyval.e)->local_variable=(yyvsp[(3) - (5)].e);

							if((yyvsp[(4) - (5)].e)->temp_variable!=NULL){
								exp *p=(yyval.e)->local_variable;
								for(;p->next;p=p->next){}
								p->next=(yyvsp[(4) - (5)].e)->temp_variable;
								(yyvsp[(4) - (5)].e)->temp_variable=NULL;
							}
							exp *a=(yyval.e)->local_variable;
						;}
    break;

  case 49:
#line 307 "c.y"
    {
							(yyval.e)=(yyvsp[(2) - (3)].e);
						;}
    break;

  case 50:
#line 310 "c.y"
    {
							(yyval.e)=NULL;
						;}
    break;

  case 51:
#line 314 "c.y"
    {
							/*
								用一個新的欄位:temp_variable
								暫時存放定義的變數
								在reduce成fun_exp的時候，再放到fun_exp的
								local_variable裡，並把temp_variable設成null
							*/

							(yyval.e)=(yyvsp[(2) - (2)].e);
							(yyval.e)->temp_variable=(yyvsp[(1) - (2)].e);
						;}
    break;

  case 52:
#line 325 "c.y"
    {
							(yyval.e)=(yyvsp[(1) - (1)].e);
							(yyval.e)->temp_variable=NULL;
						;}
    break;

  case 53:
#line 330 "c.y"
    {
							(yyval.e)=(exp *)malloc(sizeof(exp));
							(yyval.e)->type=(yyvsp[(2) - (4)].e)->type;
							(yyval.e)->type_2="fun_call";
							(yyval.e)->next=NULL;
							(yyval.e)->funbody=(yyvsp[(2) - (4)].e)->funbody;
							(yyval.e)->local_variable=(yyvsp[(2) - (4)].e)->local_variable;
							(yyval.e)->local_exp=(yyvsp[(3) - (4)].e);
							(yyval.e)->variableName=NULL;
						;}
    break;

  case 54:
#line 340 "c.y"
    {
							exp *f;
							exp *i;
							(yyval.e)=(exp *)malloc(sizeof(exp));
							f=look_symbol_table(global_variable,(yyvsp[(2) - (4)].word));
							if(f!=NULL &&  f->funbody!=NULL && strcmp(f->funbody->type_2,"fun")==0){
									(yyval.e)->type="unInit";
									(yyval.e)->type_2="fun";
									(yyval.e)->isVariable=1;
									(yyval.e)->next=NULL;
									(yyval.e)->funbody=f->funbody->funbody;
									if(f->local_exp==NULL){
										(yyval.e)->local_exp=(yyvsp[(3) - (4)].e);
									}else{
										(yyval.e)->local_exp=(yyvsp[(3) - (4)].e);
										i=(yyval.e)->local_exp;
										for(;i->next;i=i->next){}
										i->next=f->local_exp;
									}
									if(f->funbody->local_variable!=NULL){
										(yyval.e)->local_variable=f->funbody->local_variable;
										i=(yyval.e)->local_variable;
										if(f->local_variable!=NULL){
											for(;i->next;i=i->next){}
											i->next=f->local_variable;
										}
									}else{
										if(f->local_variable!=NULL){
											(yyval.e)->local_variable=f->local_variable;
										}
									}
							}else{
									(yyval.e)=(exp *)malloc(sizeof(exp));
									(yyval.e)->type="unInit";
									(yyval.e)->type_2="fun_call";
									(yyval.e)->isVariable=1;
									(yyval.e)->variableName=(yyvsp[(2) - (4)].word);
									(yyval.e)->next=NULL;
									(yyval.e)->funbody=NULL;
									(yyval.e)->local_variable=NULL;
									(yyval.e)->local_exp=(yyvsp[(3) - (4)].e);
							}
						;}
    break;

  case 55:
#line 384 "c.y"
    {
								(yyval.word)=(yyvsp[(1) - (1)].word);
							;}
    break;

  case 56:
#line 388 "c.y"
    {
							(yyval.e)=(exp *)malloc(sizeof(exp));
							(yyval.e)->next=NULL;
							(yyval.e)->type="unInit";
							(yyval.e)->type_2="if";
							(yyval.e)->parameters=NULL;
							(yyval.e)->text=(yyvsp[(3) - (6)].e);
							(yyval.e)->then=(yyvsp[(4) - (6)].e);
							(yyval.e)->el=(yyvsp[(5) - (6)].e);
						;}
    break;

  case 57:
#line 399 "c.y"
    {
							(yyval.e)=(yyvsp[(1) - (1)].e);
						;}
    break;

  case 58:
#line 403 "c.y"
    {
							(yyval.e)=(yyvsp[(1) - (1)].e);
						;}
    break;

  case 59:
#line 407 "c.y"
    {
							(yyval.e)=(yyvsp[(1) - (1)].e);
						;}
    break;


/* Line 1267 of yacc.c.  */
#line 1993 "c.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 413 "c.y"


void tra_table(exp *table){
	for(;table;table=table->next){
		printf("name:%s\n",table->variableName);
	}
}


exp *look_symbol_table(exp *which_table,char *variableName){
	exp *wp=which_table;
	for(;wp;wp=wp->next){
		if(strcmp(wp->variableName,variableName)==0){
			return wp;
		}
	}
	return NULL;
}
exp *create_formula(char *operator,exp *p1,exp *p2){

	exp *n;
	n=(exp *)malloc(sizeof(exp));
	n->next=NULL;
	n->parameters=NULL;
	if(strcmp(operator,"and")==0 ||
		strcmp(operator,"or")==0 	||
		strcmp(operator,"not")==0 ||
		strcmp(operator,"<")==0 ||
		strcmp(operator,">")==0 ||
		strcmp(operator,"=")==0
	){
		n->type="boolVal";
	}else{
		n->type="int";
	}

	p1->next=p2;
	exp *wp=p1;
	exp *new_node;
	exp *last_parameter;
	for(;wp;wp=wp->next){
		new_node=(exp *)malloc(sizeof(exp));
		new_node->type=wp->type;
		new_node->type_2=wp->type_2;
		new_node->variableName=wp->variableName;
		new_node->isVariable=wp->isVariable;
		new_node->value=wp->value;
		new_node->next=NULL;
		new_node->funbody=wp->funbody;
		new_node->local_exp=wp->local_exp;
		new_node->local_variable=wp->local_variable;
		new_node->operator=wp->operator;
		new_node->parameters=wp->parameters;
		new_node->text=wp->text;
		new_node->then=wp->then;
		new_node->el=wp->el;

		if(n->parameters==NULL){
			n->parameters=new_node;
			last_parameter=new_node;
		}
		else{
			last_parameter->next=new_node;
			last_parameter=new_node;
		}
	}
	n->type_2="formula";
	n->operator=operator;
	n->value=0;

	return n;
}
int calc(exp *t , exp *table){
	int type_check;


	if(t->isVariable==1){
		exp *p=look_symbol_table(table,t->variableName);
		if(strcmp(t->type_2,"fun_call")!=0){
			t->value=p->value;
			t->type=p->type;
			t->type_2=p->type_2;
			t->operator=p->operator;
			t->parameters=p->parameters;
			t->funbody=p->funbody;
			t->local_variable=p->local_variable;
			t->local_exp=p->local_exp;
			t->text=p->text;
			t->then=p->then;
			t->el=p->el;

		}else{
			t->type=p->type;
			t->funbody=p->funbody;
			t->local_variable=NULL;
			exp *a=p->local_variable;
			int j=0;
			exp *k;
			/*錯在這裡，fun sqare的區域變數離奇地變成NULL*/
			/*這裡是將查到的fun的local_variable，複製到我的fun_call上*/
			for(;a;a=a->next){
				exp *n=(exp *)malloc(sizeof(exp));
				n->type=a->type;
				n->type_2=a->type_2;
				n->local_variable=a->local_variable;
				//錯的，local_variable要用複製的
				/*
					這裡其實可以用另一個解法
					只要紀錄區域變數有幾個，再做一些變化，就可以解決這個問題。
				*/
				n->funbody=a->funbody;
				n->variableName=a->variableName;
				if(t->local_variable==NULL){
					t->local_variable=n;
				}else{
					for(k=t->local_variable;k->next;k=k->next){}
					k->next=n;
				}
			}
			if(p->local_exp!=NULL){
				k=t->local_exp;
				for(;k->next;k=k->next){}
				k->next=p->local_exp;
			}

		}

	}
	if(strcmp(t->type_2,"formula")==0){
		if(strcmp(t->operator,"+")==0){
			int sum=0;
			exp *p=t->parameters;
			for(;p;p=p->next){
				type_check=calc(p,table);
				if(type_check==-1){
					return -1;
				}
				if(strcmp(p->type,"int")!=0){
					printf("type error , should be number in operate +!\n");
					return -1;
				}
				sum+=p->value;
			}
			t->value=sum;
		}
		else if(strcmp(t->operator,"*")==0){
			int sum=1;
			exp *p=t->parameters;

			p=t->parameters;
			for(;p;p=p->next){
				type_check=calc(p,table);
				if(type_check==-1){
					return -1;
				}

				if(strcmp(p->type,"int")!=0){
					printf("type error , should be number in operate *!\n");
					return -1;
				}
				sum*=p->value;
			}
			t->value=sum;
		}else if(strcmp(t->operator,"-")==0){
			int sum;
			exp *p=t->parameters;
			exp *a,*b;
			a=p;
			b=p->next;
			type_check=calc(a,table);
			if(type_check==-1){
				return -1;
			}

			type_check=calc(b,table);
			if(type_check==-1){
				return -1;
			}
			if(strcmp(a->type,"int")!=0 || strcmp(b->type,"int")!=0){
				printf("type error , should be number in operate -!\n");
				return -1;
			}
			sum=a->value-b->value;
			t->value=sum;
		}else if(strcmp(t->operator,"/")==0){
			int sum;
			exp *p=t->parameters;
			exp *a,*b;
			a=p;
			b=p->next;
			type_check=calc(a,table);
			if(type_check==-1){
				return -1;
			}
			type_check=calc(b,table);
			if(type_check==-1){
				return -1;
			}
			if(strcmp(a->type,"int")!=0 || strcmp(b->type,"int")!=0){
				printf("type error , should be number in operate /!\n");
				return -1;
			}
			sum=a->value/b->value;
			t->value=sum;
		}else if(strcmp(t->operator,"mod")==0){
			int sum;
			exp *p=t->parameters;
			exp *a,*b;
			a=p;
			b=p->next;
			type_check=calc(a,table);
			if(type_check==-1){
				return -1;
			}
			type_check=calc(b,table);
			if(type_check==-1){
				return -1;
			}
			if(strcmp(a->type,"int")!=0 || strcmp(b->type,"int")!=0){
				printf("type error , should be number in operate mod!\n");
				return -1;
			}
			sum=a->value%b->value;
			t->value=sum;
		}else if(strcmp(t->operator,">")==0){
			int sum;
			exp *p=t->parameters;
			exp *a,*b;
			a=p;
			b=p->next;
			type_check=calc(a,table);
			if(type_check==-1){
				return -1;
			}
			type_check=calc(b,table);
			if(type_check==-1){
				return -1;
			}
			if(strcmp(a->type,"int")!=0 || strcmp(b->type,"int")!=0){
				printf("type error , should be number in operate >!\n");
				return -1;
			}
			if(a->value>b->value)
				sum=1;
			else
				sum=0;
			t->value=sum;
		}else if(strcmp(t->operator,"<")==0){
			int sum;
			exp *p=t->parameters;
			exp *a,*b;
			a=p;
			b=p->next;
			type_check=calc(a,table);
			if(type_check==-1){
				return -1;
			}
			type_check=calc(b,table);
			if(type_check==-1){
				return -1;
			}
			if(strcmp(a->type,"int")!=0 || strcmp(b->type,"int")!=0){
				printf("type error , should be number in operate <!\n");
				return -1;
			}
			if(a->value<b->value)
				sum=1;
			else
				sum=0;
			t->value=sum;
		}else if(strcmp(t->operator,"=")==0){
			int sum=1;
			int a;
			int flag=0;
			exp *p=t->parameters;
			for(;p;p=p->next){
				type_check=calc(p,table);
				if(type_check==-1){
					return -1;
				}
				if(strcmp(p->type,"int")!=0){
					printf("type error , should be number in operate -1!\n");
					return -1;
				}
				if(flag==0){
					a=p->value;
					flag=1;
				}else{
					if(a!=p->value){
						sum=0;
					}
				}
			}
			t->value=sum;
		}else if(strcmp(t->operator,"and")==0){
			int sum=1;
			exp *p=t->parameters;
			for(;p;p=p->next){
				type_check=calc(p,table);
				if(type_check==-1){
					return -1;
				}
				if(strcmp(p->type,"boolVal")!=0){
					printf("type error , should be bool in operate and!\n");
					return -1;
				}
				sum&=p->value;
			}
			t->value=sum;
		}else if(strcmp(t->operator,"or")==0){
			int sum=0;
			int a;
			exp *p=t->parameters;
			for(;p;p=p->next){
				type_check=calc(p,table);
				if(type_check==-1){
					return -1;
				}
				if(strcmp(p->type,"boolVal")!=0){
					printf("type error , should be bool in operate or!\n");
					return -1;
				}
				sum|=p->value;
			}
			t->value=sum;
		}else if(strcmp(t->operator,"not")==0){
			int sum=0;
			int a;
			exp *p=t->parameters;
			type_check=calc(p,table);
			if(type_check==-1){
				return -1;
			}
			if(strcmp(p->type,"boolVal")!=0){
				printf("type error , should be bool in operate not!\n");
				return -1;
			}
			if(p->value==1)
				sum=0;
			else
				sum=1;
			t->value=sum;
		}
	}else if(strcmp(t->type_2,"if")==0){
		exp *p=table;
		type_check=calc(t->text,table);
		if(type_check==-1){
			return -1;
		}
		if(strcmp(t->text->type,"boolVal")!=0){
			printf("type errpr , should be bool in if's text!\n");
			return -1;
			}


		if(t->text->value==1){
		/*then*/
			type_check=calc(t->then,table);
			if(type_check==-1){
				return -1;
			}
			t->type=t->then->type;
			t->value=t->then->value;
		}else if(t->text->value==0){
		/*else*/
			type_check=calc(t->el,table);
			if(type_check==-1){
				return -1;
			}
			t->type=t->el->type;
			t->value=t->el->value;
		}
	}else if(strcmp(t->type_2,"fun_call")==0){

		exp *q=t->local_variable;
		exp *p=t->local_exp;
		exp *new_table;
		q=t->local_variable;
		for(;p;p=p->next,q=q->next){
			type_check=calc(p,table);
			if(type_check==-1){
				return -1;
			}
			q->type=p->type;
			//q->type_2=p->type_2;
			q->value=p->value;
			q->operator=p->operator;
		  q->parameters=p->parameters;
			q->funbody=p->funbody;
			q->local_variable=p->local_variable;
			q->local_exp=p->local_exp;
			q->text=p->text;
			q->then=p->then;
			q->el=p->el;
		}

		q=t->local_variable;
		if(q!=NULL){
			for(;q->next;q=q->next){}
			q->next=global_variable;
			q=t->local_variable;
			new_table=q;
		}else{
			new_table=global_variable;
		}
		/*
			假如funbody是fun，就沒辦法calc出值。
			所以需要多作處理，形成閉包
		*/
		type_check=calc(t->funbody,new_table);
		if(type_check==-1){
			return -1;
		}
		t->value=t->funbody->value;
		t->type=t->funbody->type;
	}
	return 1;
}

void yyerror(const char *message)
{
	fprintf(stderr, "%s\n",message);
}

int main(int argc, char *argv[])
{
    yyparse();
    return(0);
}
/*
	1.
	在FUN_CALL的時候檢查funbody的type是不是fun
	假如是的話，就要多做處理

	a.把exp塞到區域變數裡
  b.把區域變數塞到funbody的區域變數的後面
	c.回傳fun


*/

