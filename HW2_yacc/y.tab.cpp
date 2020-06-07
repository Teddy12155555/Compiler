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
     BOOLEAN = 258,
     BREAK = 259,
     CHAR = 260,
     CASE = 261,
     CLASS = 262,
     CONTINUE = 263,
     DEF = 264,
     DO = 265,
     ELSE = 266,
     EXIT = 267,
     FALSE = 268,
     FLOAT = 269,
     FOR = 270,
     IF = 271,
     INT = 272,
     OBJECT = 273,
     PRINT = 274,
     PRINTLN = 275,
     REPEAT = 276,
     RETURN = 277,
     STRING = 278,
     TO = 279,
     TRUE = 280,
     TYPE = 281,
     VAL = 282,
     VAR = 283,
     WHILE = 284,
     ASSIGN = 285,
     READ = 286,
     _NULL_ = 287,
     ID = 288,
     BOOL_VALUE = 289,
     INT_VALUE = 290,
     STRING_VALUE = 291,
     FLOAT_VALUE = 292,
     CHAR_VALUE = 293,
     UMINUS = 294,
     LG_NOT = 295,
     LG_OR = 296,
     LG_AND = 297,
     NOTEQUAL = 298,
     EQUAL = 299,
     MORETHEN = 300,
     MOREEQUAL = 301,
     LESSEQUAL = 302,
     LESSTHEN = 303
   };
#endif
/* Tokens.  */
#define BOOLEAN 258
#define BREAK 259
#define CHAR 260
#define CASE 261
#define CLASS 262
#define CONTINUE 263
#define DEF 264
#define DO 265
#define ELSE 266
#define EXIT 267
#define FALSE 268
#define FLOAT 269
#define FOR 270
#define IF 271
#define INT 272
#define OBJECT 273
#define PRINT 274
#define PRINTLN 275
#define REPEAT 276
#define RETURN 277
#define STRING 278
#define TO 279
#define TRUE 280
#define TYPE 281
#define VAL 282
#define VAR 283
#define WHILE 284
#define ASSIGN 285
#define READ 286
#define _NULL_ 287
#define ID 288
#define BOOL_VALUE 289
#define INT_VALUE 290
#define STRING_VALUE 291
#define FLOAT_VALUE 292
#define CHAR_VALUE 293
#define UMINUS 294
#define LG_NOT 295
#define LG_OR 296
#define LG_AND 297
#define NOTEQUAL 298
#define EQUAL 299
#define MORETHEN 300
#define MOREEQUAL 301
#define LESSEQUAL 302
#define LESSTHEN 303




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include <iostream>
#include "Tables.hpp"
#include "lex.yy.cpp"
#define Trace(s)        {cout << "Parser Msg : " << s << endl;}
#define Warning(t)      {printf(t);printf("\n");} 

void yyerror(string error_msg){
    cout << "=============== Error ===============" << endl;
    cout << buf << " ( " <<  error_msg <<  ")" << endl;
    cout << "============ Parser Fail ============" << endl;
   exit(-1);
}void yyerror(string error_msg,string t)
{
    cout << "=============== Error ===============" << endl;
    cout << buf << " ( " <<  error_msg <<  ")" << endl;
    cout << "With bad string : " << t << endl;
    cout << "============ Parser Fail ============" << endl;
   exit(-1);
}
// Create a new global tables
GlobalTABLE SYMBOLTABLES;
bool global_INSERT(IDContent * Id);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 27 "parser.y"
{
    float fVAL;
    int iVAL;
    bool bVAL;
    string * sVAL;
    char cVAL;
    DataValue * dataValue;

    // Enum
    ID_DATA_TYPE DATA_TYPE;
    // Block
    map<string, IDContent *>* blockTABLE;
    // Function Call
    vector<DataValue*>* func_CallArgs;
    vector<IDContent*>* func_DeclareArgs;
    IDContent* func_DeclareArg;
}
/* Line 193 of yacc.c.  */
#line 236 "y.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 249 "y.tab.cpp"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   364

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNRULES -- Number of states.  */
#define YYNSTATES  174

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    53,     2,     2,
      59,    60,    51,    49,    61,    50,     2,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    11,    14,    17,    18,    20,    22,
      27,    34,    39,    46,    51,    59,    62,    63,    64,    65,
      76,    77,    79,    83,    87,    90,    91,    92,    98,   101,
     103,   104,   106,   109,   110,   112,   114,   116,   118,   120,
     122,   126,   133,   136,   139,   142,   144,   146,   147,   152,
     154,   157,   158,   165,   171,   172,   176,   179,   182,   186,
     187,   194,   200,   201,   213,   224,   229,   230,   234,   236,
     239,   243,   247,   251,   255,   259,   263,   266,   270,   274,
     278,   282,   286,   290,   292,   294,   299,   303,   305,   307,
     309,   311,   313,   315,   317,   319,   321,   323
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    -1,    18,    33,    64,    54,    65,    55,
      -1,    69,    65,    -1,    66,    65,    -1,    -1,    68,    -1,
      67,    -1,    27,    33,    30,    94,    -1,    27,    33,    56,
      95,    30,    94,    -1,    28,    33,    30,    94,    -1,    28,
      33,    56,    95,    30,    94,    -1,    28,    33,    56,    95,
      -1,    28,    33,    56,    95,    57,    35,    58,    -1,    28,
      33,    -1,    -1,    -1,    -1,     9,    33,    70,    59,    73,
      71,    60,    75,    72,    76,    -1,    -1,    74,    -1,    74,
      61,    73,    -1,    33,    56,    95,    -1,    56,    95,    -1,
      -1,    -1,    54,    77,    79,    78,    55,    -1,    22,    94,
      -1,    22,    -1,    -1,    80,    -1,    80,    79,    -1,    -1,
      81,    -1,    82,    -1,    84,    -1,    89,    -1,    92,    -1,
      66,    -1,    33,    30,    94,    -1,    33,    57,    94,    58,
      30,    94,    -1,    19,    94,    -1,    20,    94,    -1,    31,
      33,    -1,    22,    -1,    94,    -1,    -1,    54,    83,    79,
      55,    -1,    85,    -1,    85,    87,    -1,    -1,    16,    59,
      94,    60,    86,    81,    -1,    16,    59,    94,    60,    82,
      -1,    -1,    11,    88,    81,    -1,    11,    82,    -1,    11,
      85,    -1,    11,    85,    87,    -1,    -1,    29,    59,    94,
      60,    90,    81,    -1,    29,    59,    94,    60,    82,    -1,
      -1,    15,    59,    33,    48,    50,    94,    24,    94,    60,
      91,    81,    -1,    15,    59,    33,    48,    50,    94,    24,
      94,    60,    82,    -1,    33,    59,    93,    60,    -1,    -1,
      94,    61,    93,    -1,    94,    -1,    50,    94,    -1,    94,
      49,    94,    -1,    94,    50,    94,    -1,    94,    51,    94,
      -1,    94,    52,    94,    -1,    94,    42,    94,    -1,    94,
      41,    94,    -1,    40,    94,    -1,    94,    48,    94,    -1,
      94,    47,    94,    -1,    94,    45,    94,    -1,    94,    46,
      94,    -1,    94,    44,    94,    -1,    94,    43,    94,    -1,
      92,    -1,    33,    -1,    33,    57,    94,    58,    -1,    59,
      94,    60,    -1,    96,    -1,    17,    -1,     3,    -1,     5,
      -1,    23,    -1,    14,    -1,    35,    -1,    34,    -1,    38,
      -1,    36,    -1,    37,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    82,    82,    81,   104,   105,   106,   113,   114,   117,
     130,   148,   160,   176,   188,   200,   225,   238,   244,   224,
     256,   260,   267,   275,   288,   293,   298,   297,   311,   316,
     322,   338,   339,   340,   343,   344,   345,   346,   347,   349,
     350,   366,   377,   381,   385,   392,   393,   397,   396,   415,
     416,   418,   417,   427,   430,   429,   439,   440,   441,   449,
     448,   460,   467,   466,   483,   506,   537,   541,   547,   567,
     586,   613,   640,   667,   695,   711,   727,   743,   769,   795,
     822,   849,   879,   909,   911,   924,   944,   949,   957,   961,
     965,   969,   973,   979,   984,   989,   994,   999
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOLEAN", "BREAK", "CHAR", "CASE",
  "CLASS", "CONTINUE", "DEF", "DO", "ELSE", "EXIT", "FALSE", "FLOAT",
  "FOR", "IF", "INT", "OBJECT", "PRINT", "PRINTLN", "REPEAT", "RETURN",
  "STRING", "TO", "TRUE", "TYPE", "VAL", "VAR", "WHILE", "ASSIGN", "READ",
  "_NULL_", "ID", "BOOL_VALUE", "INT_VALUE", "STRING_VALUE", "FLOAT_VALUE",
  "CHAR_VALUE", "UMINUS", "LG_NOT", "LG_OR", "LG_AND", "NOTEQUAL", "EQUAL",
  "MORETHEN", "MOREEQUAL", "LESSEQUAL", "LESSTHEN", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'{'", "'}'", "':'", "'['", "']'", "'('", "')'", "','",
  "$accept", "PROGRAM", "@1", "OBJECT_CONTENTS", "VARIABLES",
  "VAL_VARIABLE", "VAR_VARIABLE", "FUNCTIONS", "@2", "@3", "@4", "ARGS",
  "ARG", "FUNCTION_RETURN_TYPE", "FUNCTION_SCOPE", "@5", "FUNCTION_RETURN",
  "STATEMENTS", "STATEMENT", "SIMPLE_STATEMENT", "BLOCK", "@6",
  "CONDITION_STAMENT", "IF_STAMENT", "@7", "ELSE_STAMENT", "@8",
  "LOOP_STAMENT", "@9", "@10", "FUNCTION_CALL",
  "COMMA_SEPARATED_EXPRESSION", "EXPRESSION", "TYPE_", "DATA_VALUE", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    43,
      45,    42,    47,    37,   123,   125,    58,    91,    93,    40,
      41,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    64,    63,    65,    65,    65,    66,    66,    67,
      67,    68,    68,    68,    68,    68,    70,    71,    72,    69,
      73,    73,    73,    74,    75,    75,    77,    76,    78,    78,
      78,    79,    79,    79,    80,    80,    80,    80,    80,    81,
      81,    81,    81,    81,    81,    81,    81,    83,    82,    84,
      84,    86,    85,    85,    88,    87,    87,    87,    87,    90,
      89,    89,    91,    89,    89,    92,    93,    93,    93,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    95,    95,
      95,    95,    95,    96,    96,    96,    96,    96
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     2,     2,     0,     1,     1,     4,
       6,     4,     6,     4,     7,     2,     0,     0,     0,    10,
       0,     1,     3,     3,     2,     0,     0,     5,     2,     1,
       0,     1,     2,     0,     1,     1,     1,     1,     1,     1,
       3,     6,     2,     2,     2,     1,     1,     0,     4,     1,
       2,     0,     6,     5,     0,     3,     2,     2,     3,     0,
       6,     5,     0,    11,    10,     4,     0,     3,     1,     2,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     1,     1,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     6,     0,     0,     0,
       0,     6,     8,     7,     6,    16,     0,    15,     3,     5,
       4,     0,     0,     0,     0,     0,    20,    84,    94,    93,
      96,    97,    95,     0,     0,     0,    83,     9,    87,    89,
      90,    92,    88,    91,     0,    11,    13,     0,    17,    21,
       0,    66,    76,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,     0,     0,    68,    86,    75,    74,    82,
      81,    79,    80,    78,    77,    70,    71,    72,    73,    10,
      12,     0,    23,    25,    22,    85,    65,    66,    14,     0,
      18,    67,    24,     0,    26,    19,    33,     0,     0,     0,
       0,    45,     0,     0,    84,    47,    39,    30,    31,    34,
      35,    36,    49,    37,    38,    46,     0,     0,    42,    43,
       0,    44,     0,     0,    33,    29,     0,    32,    54,    50,
       0,     0,     0,    40,     0,     0,    28,    27,    56,    57,
       0,     0,    51,    59,    85,    48,    58,    55,     0,    53,
       0,    61,     0,     0,     0,    52,    60,    41,     0,     0,
      62,    64,     0,    63
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    10,   116,    12,    13,    14,    21,    71,
     103,    48,    49,   100,   105,   106,   136,   117,   118,   119,
     120,   134,   121,   122,   160,   139,   150,   123,   162,   172,
      36,    74,   125,    44,    38
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -110
static const yytype_int16 yypact[] =
{
       6,   -12,    58,  -110,  -110,    10,    46,    48,    51,    52,
      24,    46,  -110,  -110,    46,  -110,   -29,   -25,  -110,  -110,
    -110,    30,   134,     3,   134,     3,    60,   -41,  -110,  -110,
    -110,  -110,  -110,   134,   134,   134,  -110,   290,  -110,  -110,
    -110,  -110,  -110,  -110,    65,   290,    -7,    40,  -110,    36,
     134,   134,   312,   290,   174,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,    63,
       3,    41,    60,   254,    43,   153,  -110,   312,   312,    69,
      69,    69,    69,    69,    69,     5,     5,  -110,  -110,   290,
     290,    42,  -110,    50,  -110,  -110,  -110,   134,  -110,     3,
    -110,  -110,  -110,    53,  -110,  -110,    32,    45,    57,   134,
     134,  -110,    66,    76,   -27,  -110,  -110,    90,    32,  -110,
    -110,  -110,   113,  -110,   302,   290,    94,   134,   290,   290,
     134,  -110,   134,   134,    32,   134,    79,  -110,    -1,  -110,
      89,   194,   214,   290,   272,    84,   290,  -110,  -110,   113,
      95,    92,    86,    86,   117,  -110,  -110,  -110,   134,  -110,
      95,  -110,    95,   134,   114,  -110,  -110,   290,   134,   234,
      86,  -110,    95,  -110
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -110,  -110,  -110,    -4,     8,  -110,  -110,  -110,  -110,  -110,
    -110,    71,  -110,  -110,  -110,  -110,  -110,  -109,  -110,   -70,
     -76,  -110,  -110,    11,  -110,    -5,  -110,  -110,  -110,  -110,
     -35,    54,   -22,   -21,  -110
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -84
static const yytype_int16 yytable[] =
{
      37,    22,    45,   132,    46,    24,    39,    19,    40,   137,
      20,    52,    53,    54,    11,   108,    50,    41,    51,    11,
      42,     3,    11,    68,     1,   145,    43,    23,    73,    75,
     133,    25,    51,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,   107,   108,    92,
      69,   109,   110,   115,   111,     7,    65,    66,     4,     8,
       9,   112,   148,   113,     6,   114,    28,    29,    30,    31,
      32,   124,    33,     8,     9,    75,   159,   161,   102,    18,
     157,    15,    34,   124,    16,    17,   115,   128,   129,    26,
     165,    35,   166,    47,   171,    67,    70,    72,    91,   124,
      98,    93,   173,    96,   126,   141,    99,   104,   142,   131,
     143,   144,   135,   146,   109,   110,   127,   111,    63,    64,
      65,    66,     8,     9,   138,   130,   113,   140,   114,    28,
      29,    30,    31,    32,   147,    33,   164,   151,   168,   155,
     115,   167,   158,    94,   156,    34,   169,   163,     0,   149,
       0,   101,     0,     0,    35,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    27,    28,    29,
      30,    31,    32,     0,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,     0,    35,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     0,     0,     0,     0,
       0,     0,     0,     0,    97,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,     0,
       0,     0,     0,     0,    76,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,     0,
       0,     0,     0,     0,   152,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,     0,
       0,     0,     0,     0,   153,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,     0,
       0,     0,     0,     0,   170,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,     0,
       0,     0,    95,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,     0,     0,     0,     0,
     154,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,     0,   -83,   -83,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66
};

static const yytype_int16 yycheck[] =
{
      22,    30,    24,    30,    25,    30,     3,    11,     5,   118,
      14,    33,    34,    35,     6,    16,    57,    14,    59,    11,
      17,    33,    14,    30,    18,   134,    23,    56,    50,    51,
      57,    56,    59,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    15,    16,    70,
      57,    19,    20,    54,    22,     9,    51,    52,     0,    27,
      28,    29,   138,    31,    54,    33,    34,    35,    36,    37,
      38,   106,    40,    27,    28,    97,   152,   153,    99,    55,
     150,    33,    50,   118,    33,    33,    54,   109,   110,    59,
     160,    59,   162,    33,   170,    30,    56,    61,    35,   134,
      58,    60,   172,    60,    59,   127,    56,    54,   130,    33,
     132,   133,    22,   135,    19,    20,    59,    22,    49,    50,
      51,    52,    27,    28,    11,    59,    31,    33,    33,    34,
      35,    36,    37,    38,    55,    40,   158,    48,    24,    55,
      54,   163,    50,    72,   149,    50,   168,    30,    -1,   138,
      -1,    97,    -1,    -1,    59,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    33,    34,    35,
      36,    37,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    58,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      58,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    51,    52,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    63,    33,     0,    64,    54,     9,    27,    28,
      65,    66,    67,    68,    69,    33,    33,    33,    55,    65,
      65,    70,    30,    56,    30,    56,    59,    33,    34,    35,
      36,    37,    38,    40,    50,    59,    92,    94,    96,     3,
       5,    14,    17,    23,    95,    94,    95,    33,    73,    74,
      57,    59,    94,    94,    94,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    30,    30,    57,
      56,    71,    61,    94,    93,    94,    60,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    35,    95,    60,    73,    58,    60,    61,    58,    56,
      75,    93,    95,    72,    54,    76,    77,    15,    16,    19,
      20,    22,    29,    31,    33,    54,    66,    79,    80,    81,
      82,    84,    85,    89,    92,    94,    59,    59,    94,    94,
      59,    33,    30,    57,    83,    22,    78,    79,    11,    87,
      33,    94,    94,    94,    94,    79,    94,    55,    82,    85,
      88,    48,    60,    60,    58,    55,    87,    81,    50,    82,
      86,    82,    90,    30,    94,    81,    81,    94,    24,    94,
      60,    82,    91,    81
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
#line 82 "parser.y"
    {
            
            Trace("========== Parsering Start ! ==========");
            // Symbol Table push 
            // Init with program entry point 
            // and start to pasre
            if(SYMBOLTABLES.insertTABLE(new IDContent(*(yyvsp[(2) - (2)].sVAL),OBJECT_TYPE)))
            {
                cout << "Symbol Tables Successed to Init" << endl;
            }
            else
            {
                yyerror("This ID Already Exist(from OBJ ID)",*(yyvsp[(2) - (2)].sVAL));
            }
            
        }
    break;

  case 3:
#line 99 "parser.y"
    {
            //Trace("");
        }
    break;

  case 9:
#line 118 "parser.y"
    {
                    Trace("VAL ID = EXPRESSION");
                    // Create new const var to gloabl Tables
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*(yyvsp[(2) - (4)].sVAL),CONST_TYPE,(yyvsp[(4) - (4)].dataValue))))
                    {

                    }
                    else
                    {
                        yyerror("ID error",*(yyvsp[(2) - (4)].sVAL));
                    }
                }
    break;

  case 10:
#line 131 "parser.y"
    {
                    Trace("VAL ID : TYPE = EXPRESSION");
                    if((yyvsp[(4) - (6)].DATA_TYPE) != (yyvsp[(6) - (6)].dataValue)->getDataType())
                    {
                        yyerror("Type Error, Not match(assign diff type)");
                    }
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*(yyvsp[(2) - (6)].sVAL),CONST_TYPE,(yyvsp[(6) - (6)].dataValue))))
                    {

                    }
                    else
                    {
                        yyerror("ID error",*(yyvsp[(2) - (6)].sVAL));
                    }
                    
                }
    break;

  case 11:
#line 149 "parser.y"
    {
                    Trace("VAR ID = EXPRESSION");
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*(yyvsp[(2) - (4)].sVAL),VAR_TYPE,(yyvsp[(4) - (4)].dataValue))))
                    {

                    }
                    else
                    {
                        yyerror("ID Error(VAR ID = EXPRESSION)");
                    }
                }
    break;

  case 12:
#line 161 "parser.y"
    {
                    Trace("VAR ID : TYPE = EXPRESSION");
                    if((yyvsp[(4) - (6)].DATA_TYPE) != (yyvsp[(6) - (6)].dataValue)->getDataType())
                    {
                        yyerror("Type Error, Not match(assign diff type)");
                    }
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*(yyvsp[(2) - (6)].sVAL),VAR_TYPE,(yyvsp[(6) - (6)].dataValue))))
                    {

                    }
                    else
                    {
                        yyerror("ID Error(VAR ID : TYPE = EXPRESSION)",*(yyvsp[(2) - (6)].sVAL));
                    }
                }
    break;

  case 13:
#line 177 "parser.y"
    {
                    Trace("VAR ID : TYPE ");
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*(yyvsp[(2) - (4)].sVAL),VAR_TYPE,(yyvsp[(4) - (4)].DATA_TYPE))))
                    {
                        cout << "Debug : Insert " << *(yyvsp[(2) - (4)].sVAL) << " as new ID !!!" << endl;
                    }
                    else
                    {
                        yyerror("ID Error(VAR ID : TYPE )",*(yyvsp[(2) - (4)].sVAL));
                    }
                }
    break;

  case 14:
#line 189 "parser.y"
    {
                    Trace("VAR ID : TYPE [ INT VALUE ]");
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*(yyvsp[(2) - (7)].sVAL),ARRAY_TYPE,(yyvsp[(4) - (7)].DATA_TYPE),(yyvsp[(6) - (7)].iVAL))))
                    {
                        
                    }
                    else
                    {
                        yyerror("ID Error(VAR ID : TYPE [ INT VALUE ])",*(yyvsp[(2) - (7)].sVAL));
                    }
                }
    break;

  case 15:
#line 201 "parser.y"
    {
                    Trace("VAR ID ");
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*(yyvsp[(2) - (2)].sVAL),VAR_TYPE,NIL_TYPE)))
                    {

                    }
                    else
                    {
                        yyerror("ID Error(VAR ID : TYPE )",*(yyvsp[(2) - (2)].sVAL));
                    }
                }
    break;

  case 16:
#line 225 "parser.y"
    {
                Trace("DEF ID");
                if(SYMBOLTABLES.insertTABLE(new IDContent(*(yyvsp[(2) - (2)].sVAL),FUNC_TYPE)))
                {
                    SYMBOLTABLES.pushTABLE();
                }
                else
                {
                    yyerror("Function ID Error, already exist",*(yyvsp[(2) - (2)].sVAL));
                }

            }
    break;

  case 17:
#line 238 "parser.y"
    {
                IDContent * Id = SYMBOLTABLES.lookupTABLE(*(yyvsp[(2) - (5)].sVAL));
                Id->setArgs(*(yyvsp[(5) - (5)].func_DeclareArgs));
                Id->setFuncTable(SYMBOLTABLES.getTopTable());
            }
    break;

  case 18:
#line 244 "parser.y"
    {
                IDContent * Id = SYMBOLTABLES.lookupTABLE(*(yyvsp[(2) - (8)].sVAL));
                Id->setReturnType((yyvsp[(8) - (8)].DATA_TYPE));

            }
    break;

  case 19:
#line 250 "parser.y"
    {
                SYMBOLTABLES.popTABLE();

            }
    break;

  case 20:
#line 256 "parser.y"
    {
            Trace("NONE ARGS");
            (yyval.func_DeclareArgs) = new vector<IDContent*>();
        }
    break;

  case 21:
#line 261 "parser.y"
    {
            Trace("ARG");
            vector<IDContent*> * temp = new vector<IDContent*>();
            temp->push_back((yyvsp[(1) - (1)].func_DeclareArg));
            (yyval.func_DeclareArgs) = temp;
        }
    break;

  case 22:
#line 268 "parser.y"
    {
            Trace("ARG, ");
            (yyval.func_DeclareArgs) = (yyvsp[(3) - (3)].func_DeclareArgs);
            (yyval.func_DeclareArgs)->push_back((yyvsp[(1) - (3)].func_DeclareArg));
        }
    break;

  case 23:
#line 276 "parser.y"
    {
        Trace("ID : TYPE");
        if(SYMBOLTABLES.insertTABLE(new IDContent(*(yyvsp[(1) - (3)].sVAL),VAR_TYPE,(yyvsp[(3) - (3)].DATA_TYPE))))
        {
        }
        else
        {
            yyerror("Function ARG ID Error, already exist",*(yyvsp[(1) - (3)].sVAL));
        }
        (yyval.func_DeclareArg) = new IDContent(*(yyvsp[(1) - (3)].sVAL),VAR_TYPE,(yyvsp[(3) - (3)].DATA_TYPE));
    }
    break;

  case 24:
#line 289 "parser.y"
    {
                            (yyval.DATA_TYPE) = (yyvsp[(2) - (2)].DATA_TYPE);
                        }
    break;

  case 25:
#line 293 "parser.y"
    {
                            (yyval.DATA_TYPE) = NIL_TYPE;
                        }
    break;

  case 26:
#line 298 "parser.y"
    {
                    Trace("FUNCTION SCOPE {");
                    SYMBOLTABLES.pushTABLE();
                }
    break;

  case 27:
#line 303 "parser.y"
    {
                    Trace("FUNCTION SCOPE }");
                    (yyval.blockTABLE) = new map<string,IDContent*>();
                    *(yyval.blockTABLE) = SYMBOLTABLES.getTopTable();
                    
                    SYMBOLTABLES.dumpTABLE();
                    SYMBOLTABLES.popTABLE();
                }
    break;

  case 28:
#line 312 "parser.y"
    {
                        Trace("FUNCTION RETURN EXPRESSION");
                        (yyval.dataValue) = (yyvsp[(2) - (2)].dataValue);
                    }
    break;

  case 29:
#line 317 "parser.y"
    {
                        Trace("FUNCTION RETURN");
                        (yyval.dataValue) = new DataValue();
                    }
    break;

  case 30:
#line 322 "parser.y"
    {
                        Trace("FUNCTION NONE RETURN");
                        (yyval.dataValue) = new DataValue();
                    }
    break;

  case 40:
#line 351 "parser.y"
    {
                        Trace("ID = EXPRESSION");
                        IDContent * temp = SYMBOLTABLES.lookupTABLE(*(yyvsp[(1) - (3)].sVAL));
                        if(temp == NULL)
                            yyerror("ID Error, Not exist in the scope",*(yyvsp[(1) - (3)].sVAL));
                        if(temp->getDeclareType() != VAR_TYPE)
                            yyerror("Type Error, Not allow to assign");

                        if(temp->getDataType() != (yyvsp[(3) - (3)].dataValue)->getDataType())
                        {
                            yyerror("Assign diff Type(etc... assign bool to int)");
                        }
                        temp->setData((yyvsp[(3) - (3)].dataValue));

                    }
    break;

  case 41:
#line 367 "parser.y"
    {
                        Trace("ID [ EXPRESSION ] = EXPRESSION");
                        if((yyvsp[(3) - (6)].dataValue)->getDataType() != INT_TYPE)
                            yyerror("Array index must be Integer");
                        IDContent * temp = SYMBOLTABLES.lookupTABLE(*(yyvsp[(1) - (6)].sVAL));
                        if(temp == NULL)
                            yyerror("ID Error, Not exist in the scope",*(yyvsp[(1) - (6)].sVAL));

                        temp->setArrayData((yyvsp[(3) - (6)].dataValue)->getInt(),(yyvsp[(6) - (6)].dataValue));
                    }
    break;

  case 42:
#line 378 "parser.y"
    {
                        Trace("PRINT EXPRESSION");
                    }
    break;

  case 43:
#line 382 "parser.y"
    {
                        Trace("PRINTLN EXPRESSION");
                    }
    break;

  case 44:
#line 386 "parser.y"
    {
                        Trace("READ ID");
                        IDContent * temp = SYMBOLTABLES.lookupTABLE(*(yyvsp[(2) - (2)].sVAL));
                        if(temp == NULL)
                            yyerror("ID Error, Not exist in the scope",*(yyvsp[(2) - (2)].sVAL));
                    }
    break;

  case 47:
#line 397 "parser.y"
    {
            Trace("BLOCK {");
            SYMBOLTABLES.pushTABLE();
        }
    break;

  case 48:
#line 402 "parser.y"
    {
            (yyval.blockTABLE) = new map<string,IDContent*>();
            *(yyval.blockTABLE) = SYMBOLTABLES.getTopTable();
            Trace("BLOCK }");
            SYMBOLTABLES.dumpTABLE();
            if(! SYMBOLTABLES.popTABLE())
            {
                cout << "DEBUG : vec is empty, can not pop" << endl;
            }
        }
    break;

  case 51:
#line 418 "parser.y"
    {
                Trace("IF ( EXPRESSION )");
                SYMBOLTABLES.pushTABLE();
            }
    break;

  case 52:
#line 423 "parser.y"
    {
                SYMBOLTABLES.dumpTABLE();
                SYMBOLTABLES.popTABLE();
            }
    break;

  case 54:
#line 430 "parser.y"
    {
                    Trace("ELSE");
                    SYMBOLTABLES.pushTABLE();
                }
    break;

  case 55:
#line 435 "parser.y"
    {
                    SYMBOLTABLES.dumpTABLE();
                    SYMBOLTABLES.popTABLE();
                }
    break;

  case 59:
#line 449 "parser.y"
    {
                    SYMBOLTABLES.pushTABLE();
                }
    break;

  case 60:
#line 453 "parser.y"
    {
                    Trace("WHILE ( EXPRESSION )");
                    SYMBOLTABLES.dumpTABLE();
                    SYMBOLTABLES.popTABLE();
                    if((yyvsp[(3) - (6)].dataValue)->getDataType() != BOOL_TYPE)
                        yyerror("While( must be boolean )");
                }
    break;

  case 61:
#line 461 "parser.y"
    {
                    Trace("WHILE ( EXPRESSION ) { }");
                    if((yyvsp[(3) - (5)].dataValue)->getDataType() != BOOL_TYPE)
                        yyerror("While( must be Boolean )");
                }
    break;

  case 62:
#line 467 "parser.y"
    {
                    SYMBOLTABLES.pushTABLE();
                }
    break;

  case 63:
#line 470 "parser.y"
    {
                    Trace("FOR ( ID < - EXPRESSION TO EXPRESSION )");
                    SYMBOLTABLES.dumpTABLE();
                    SYMBOLTABLES.popTABLE();
                    if((yyvsp[(6) - (11)].dataValue)->getDataType() == INT_TYPE && (yyvsp[(8) - (11)].dataValue)->getDataType() == INT_TYPE)
                    {

                    }
                    else
                    {
                        yyerror("For( must be Int )");
                    }
                }
    break;

  case 64:
#line 484 "parser.y"
    {
                    Trace("FOR ( ID < - EXPRESSION TO EXPRESSION ) { }");
                    if((yyvsp[(6) - (10)].dataValue)->getDataType() == INT_TYPE && (yyvsp[(8) - (10)].dataValue)->getDataType() == INT_TYPE)
                    {

                    }
                    else
                    {
                        yyerror("For( must be Int )");
                    }
                }
    break;

  case 65:
#line 507 "parser.y"
    {
                    Trace("CALL_FUNCTION");
                    IDContent * temp = SYMBOLTABLES.lookupTABLE(*(yyvsp[(1) - (4)].sVAL));
                    if(temp == NULL)
                        yyerror("(calling)~~~ID Not Found, This ID is not declare in the scope");
                    if(temp->getDeclareType() != FUNC_TYPE)
                        yyerror("'ID' is not a function",*(yyvsp[(1) - (4)].sVAL));
                    cout << "Going to call size is : " << (yyvsp[(3) - (4)].func_CallArgs)->size() << endl;
                    if((yyvsp[(3) - (4)].func_CallArgs)->size() == temp->getArgs().size())
                    {
                        cout << "------- Calling Right Functing ------" << endl;
                    }
                    else
                    {
                        yyerror("Function Args Not Match");
                    }
                    for(int i=0;i<temp->getArgs().size();i++)
                    {
                        if((*(yyvsp[(3) - (4)].func_CallArgs))[i]->getDataType() != temp->getArgs()[i]->getDataType())
                        {
                            yyerror("Function Args Type Not Match");
                        }
                        else
                        {
                            continue;
                        }
                    }
                    (yyval.dataValue) = new DataValue(temp->getReturnType());
                }
    break;

  case 66:
#line 537 "parser.y"
    {
                                Trace("FUNCTION ARG");
                                (yyval.func_CallArgs) = new vector<DataValue*>();
                            }
    break;

  case 67:
#line 542 "parser.y"
    {
                                Trace("FUNCTION ARG");
                                (yyvsp[(3) - (3)].func_CallArgs)->push_back((yyvsp[(1) - (3)].dataValue));
                                (yyval.func_CallArgs) = (yyvsp[(3) - (3)].func_CallArgs);
                            }
    break;

  case 68:
#line 548 "parser.y"
    {
                                Trace("FUNCTION ARGs");
                                (yyval.func_CallArgs) = new vector<DataValue*>();
                                (yyval.func_CallArgs)->push_back((yyvsp[(1) - (1)].dataValue));
                            }
    break;

  case 69:
#line 568 "parser.y"
    {
        // - (unary)
        // only int and float can do this operation
        Trace("- EXPRESSION");
        switch((yyvsp[(2) - (2)].dataValue)->getDataType())
        {
            case INT_TYPE:
                (yyvsp[(2) - (2)].dataValue)->setInt((-1) * (yyvsp[(2) - (2)].dataValue)->getInt());
                (yyval.dataValue) = (yyvsp[(2) - (2)].dataValue);
                break;
            case FLOAT_TYPE:
                (yyvsp[(2) - (2)].dataValue)->setFloat((-1) * (yyvsp[(2) - (2)].dataValue)->getFloat());
                (yyval.dataValue) = (yyvsp[(2) - (2)].dataValue);
                break;
            default:
                yyerror("Type error(- unary), only Int or Float");
        }
    }
    break;

  case 70:
#line 587 "parser.y"
    {
        // + 
        Trace("EXPRESSION + EXPRESSION");
        DataValue * result = new DataValue();
        if((yyvsp[(1) - (3)].dataValue)->getDataType() == (yyvsp[(3) - (3)].dataValue)->getDataType())
        {
            switch((yyvsp[(1) - (3)].dataValue)->getDataType())
            {
                case INT_TYPE: 
                    result->setType((yyvsp[(1) - (3)].dataValue)->getDataType());
                    result->setInt((yyvsp[(1) - (3)].dataValue)->getInt() + (yyvsp[(3) - (3)].dataValue)->getInt());
                    break;
                case FLOAT_TYPE:
                    result->setType((yyvsp[(1) - (3)].dataValue)->getDataType());
                    result->setFloat((yyvsp[(1) - (3)].dataValue)->getFloat() + (yyvsp[(3) - (3)].dataValue)->getFloat());
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(not equal) while doing Operater + ");
        }
        (yyval.dataValue) = result;
    }
    break;

  case 71:
#line 614 "parser.y"
    {
        // - 
        Trace("EXPRESSION - EXPRESSION");
        DataValue * result = new DataValue();
        if((yyvsp[(1) - (3)].dataValue)->getDataType() == (yyvsp[(3) - (3)].dataValue)->getDataType())
        {
            switch((yyvsp[(1) - (3)].dataValue)->getDataType())
            {
                case INT_TYPE: 
                    result->setType((yyvsp[(1) - (3)].dataValue)->getDataType());
                    result->setInt((yyvsp[(1) - (3)].dataValue)->getInt() - (yyvsp[(3) - (3)].dataValue)->getInt());
                    break;
                case FLOAT_TYPE:
                    result->setType((yyvsp[(1) - (3)].dataValue)->getDataType());
                    result->setFloat((yyvsp[(1) - (3)].dataValue)->getFloat() - (yyvsp[(3) - (3)].dataValue)->getFloat());
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(not equal) while doing Operater - ");
        }
        (yyval.dataValue) = result;
    }
    break;

  case 72:
#line 641 "parser.y"
    {
        // * 
        Trace("EXPRESSION * EXPRESSION");
        DataValue * result = new DataValue();
        if((yyvsp[(1) - (3)].dataValue)->getDataType() == (yyvsp[(3) - (3)].dataValue)->getDataType())
        {
            switch((yyvsp[(1) - (3)].dataValue)->getDataType())
            {
                case INT_TYPE: 
                    result->setType((yyvsp[(1) - (3)].dataValue)->getDataType());
                    result->setInt((yyvsp[(1) - (3)].dataValue)->getInt() * (yyvsp[(3) - (3)].dataValue)->getInt());
                    break;
                case FLOAT_TYPE:
                    result->setType((yyvsp[(1) - (3)].dataValue)->getDataType());
                    result->setFloat((yyvsp[(1) - (3)].dataValue)->getFloat() * (yyvsp[(3) - (3)].dataValue)->getFloat());
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(not equal) while doing Operater * ");
        }
        (yyval.dataValue) = result;
    }
    break;

  case 73:
#line 668 "parser.y"
    {
        // / 
        Trace("EXPRESSION / EXPRESSION");
        DataValue * result = new DataValue();
        if((yyvsp[(1) - (3)].dataValue)->getDataType() == (yyvsp[(3) - (3)].dataValue)->getDataType())
        {
            switch((yyvsp[(1) - (3)].dataValue)->getDataType())
            {
                case INT_TYPE: 
                    result->setType((yyvsp[(1) - (3)].dataValue)->getDataType());
                    result->setInt((yyvsp[(1) - (3)].dataValue)->getInt() / (yyvsp[(3) - (3)].dataValue)->getInt());
                    break;
                case FLOAT_TYPE:
                    result->setType((yyvsp[(1) - (3)].dataValue)->getDataType());
                    result->setFloat((yyvsp[(1) - (3)].dataValue)->getFloat() / (yyvsp[(3) - (3)].dataValue)->getFloat());
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(not equal) while doing Operater / ");
        }
        (yyval.dataValue) = result;
    }
    break;

  case 74:
#line 696 "parser.y"
    {
        // &&
        Trace("EXPRESSION && EXPRESSION");
        DataValue * result = new DataValue();
        if((yyvsp[(1) - (3)].dataValue)->getDataType() == BOOL_TYPE && (yyvsp[(3) - (3)].dataValue)->getDataType() == BOOL_TYPE)
        {
            result->setType(BOOL_TYPE);
            result->setBool((yyvsp[(1) - (3)].dataValue)->getBool() && (yyvsp[(3) - (3)].dataValue)->getBool());
        }
        else
        {
            yyerror("Type error(not Boolean) while doing Logical Operation ");
        }
        (yyval.dataValue) = result;
    }
    break;

  case 75:
#line 712 "parser.y"
    {
        // ||
        Trace("EXPRESSION || EXPRESSION");
        DataValue * result = new DataValue();
        if((yyvsp[(1) - (3)].dataValue)->getDataType() == BOOL_TYPE && (yyvsp[(3) - (3)].dataValue)->getDataType() == BOOL_TYPE)
        {
            result->setType(BOOL_TYPE);
            result->setBool((yyvsp[(1) - (3)].dataValue)->getBool() || (yyvsp[(3) - (3)].dataValue)->getBool());
        }
        else
        {
            yyerror("Type error(not Boolean) while doing Logical Operation ");
        }
        (yyval.dataValue) = result;
    }
    break;

  case 76:
#line 728 "parser.y"
    {
        // !
        Trace("! EXPRESSION");
        DataValue * result = new DataValue();
        if((yyvsp[(2) - (2)].dataValue)->getDataType() == BOOL_TYPE)
        {
            result->setType(BOOL_TYPE);
            result->setBool(!(yyvsp[(2) - (2)].dataValue)->getBool());
        }
        else
        {
            yyerror("Type error(not Boolean) while doing Logical Operation ");
        }
        (yyval.dataValue) = (yyvsp[(2) - (2)].dataValue);
    }
    break;

  case 77:
#line 744 "parser.y"
    {
        // <
        Trace("EXPRESSION < EXPRESSION");
        DataValue * result = new DataValue();
        if((yyvsp[(1) - (3)].dataValue)->getDataType() == (yyvsp[(3) - (3)].dataValue)->getDataType())
        {
            result->setType(BOOL_TYPE);
            switch((yyvsp[(1) - (3)].dataValue)->getDataType())
            {
                case INT_TYPE: 
                    result->setBool((yyvsp[(1) - (3)].dataValue)->getInt() < (yyvsp[(3) - (3)].dataValue)->getInt());
                    break;
                case FLOAT_TYPE:
                    result->setBool((yyvsp[(1) - (3)].dataValue)->getFloat() < (yyvsp[(3) - (3)].dataValue)->getFloat());            
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(only int, float) while doing '<' ");
        }
        (yyval.dataValue) = result;
    }
    break;

  case 78:
#line 770 "parser.y"
    {
        // <=
        Trace("EXPRESSION <= EXPRESSION");
        DataValue * result = new DataValue();
        if((yyvsp[(1) - (3)].dataValue)->getDataType() == (yyvsp[(3) - (3)].dataValue)->getDataType())
        {
            result->setType(BOOL_TYPE);
            switch((yyvsp[(1) - (3)].dataValue)->getDataType())
            {
                case INT_TYPE: 
                    result->setBool((yyvsp[(1) - (3)].dataValue)->getInt() <= (yyvsp[(3) - (3)].dataValue)->getInt());
                    break;
                case FLOAT_TYPE:
                    result->setBool((yyvsp[(1) - (3)].dataValue)->getFloat() <= (yyvsp[(3) - (3)].dataValue)->getFloat());            
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(only int, float) while doing '<=' ");
        }
        (yyval.dataValue) = result;
    }
    break;

  case 79:
#line 796 "parser.y"
    {
        // >
        Trace("EXPRESSION > EXPRESSION");
        DataValue * result = new DataValue();
        if((yyvsp[(1) - (3)].dataValue)->getDataType() == (yyvsp[(3) - (3)].dataValue)->getDataType())
        {
            result->setType(BOOL_TYPE);
            switch((yyvsp[(1) - (3)].dataValue)->getDataType())
            {
                
                case INT_TYPE: 
                    result->setBool((yyvsp[(1) - (3)].dataValue)->getInt() > (yyvsp[(3) - (3)].dataValue)->getInt());
                    break;
                case FLOAT_TYPE:
                    result->setBool((yyvsp[(1) - (3)].dataValue)->getFloat() > (yyvsp[(3) - (3)].dataValue)->getFloat());            
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(only int, float) while doing '>' ");
        }
        (yyval.dataValue) = result;
    }
    break;

  case 80:
#line 823 "parser.y"
    {
        // >=
        Trace("EXPRESSION >= EXPRESSION");
        DataValue * result = new DataValue();
        if((yyvsp[(1) - (3)].dataValue)->getDataType() == (yyvsp[(3) - (3)].dataValue)->getDataType())
        {
            result->setType(BOOL_TYPE);
            switch((yyvsp[(1) - (3)].dataValue)->getDataType())
            {
                
                case INT_TYPE: 
                    result->setBool((yyvsp[(1) - (3)].dataValue)->getInt() >= (yyvsp[(3) - (3)].dataValue)->getInt());
                    break;
                case FLOAT_TYPE:
                    result->setBool((yyvsp[(1) - (3)].dataValue)->getFloat() >= (yyvsp[(3) - (3)].dataValue)->getFloat());            
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(only int, float) while doing '>=' ");
        }
        (yyval.dataValue) = result;
    }
    break;

  case 81:
#line 850 "parser.y"
    {
        // ==
        Trace("EXPRESSION == EXPRESSION");
        DataValue * result = new DataValue();
        if((yyvsp[(1) - (3)].dataValue)->getDataType() == (yyvsp[(3) - (3)].dataValue)->getDataType())
        {
            result->setType(BOOL_TYPE);
            switch((yyvsp[(1) - (3)].dataValue)->getDataType())
            {
                
                case INT_TYPE: 
                    result->setBool((yyvsp[(1) - (3)].dataValue)->getInt() == (yyvsp[(3) - (3)].dataValue)->getInt());
                    break;
                case FLOAT_TYPE:
                    result->setBool((yyvsp[(1) - (3)].dataValue)->getFloat() == (yyvsp[(3) - (3)].dataValue)->getFloat());            
                    break;
                case BOOL_TYPE:
                    result->setBool((yyvsp[(1) - (3)].dataValue)->getBool() == (yyvsp[(3) - (3)].dataValue)->getBool());
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(not equal) while doing '==' ");
        }
        (yyval.dataValue) = result;
    }
    break;

  case 82:
#line 880 "parser.y"
    {
        // !=
        Trace("EXPRESSION != EXPRESSION");
        DataValue * result = new DataValue();
        if((yyvsp[(1) - (3)].dataValue)->getDataType() == (yyvsp[(3) - (3)].dataValue)->getDataType())
        {
            result->setType(BOOL_TYPE);
            switch((yyvsp[(1) - (3)].dataValue)->getDataType())
            {
                
                case INT_TYPE: 
                    result->setBool((yyvsp[(1) - (3)].dataValue)->getInt() != (yyvsp[(3) - (3)].dataValue)->getInt());
                    break;
                case FLOAT_TYPE:
                    result->setBool((yyvsp[(1) - (3)].dataValue)->getFloat() != (yyvsp[(3) - (3)].dataValue)->getFloat());            
                    break;
                case BOOL_TYPE:
                    result->setBool((yyvsp[(1) - (3)].dataValue)->getBool() != (yyvsp[(3) - (3)].dataValue)->getBool());
                    break;
                default:
                    break;
            }
        }
        else
        {
            yyerror("Type error(not equal) while doing '<' ");
        }
        (yyval.dataValue) = result;
    }
    break;

  case 84:
#line 912 "parser.y"
    {
        // ID
        Trace("EXPR_ID");
        IDContent * temp = SYMBOLTABLES.lookupTABLE(*(yyvsp[(1) - (1)].sVAL));
        if(temp == NULL)
            yyerror("ID Not Found, This ID is not declare in the scope",*(yyvsp[(1) - (1)].sVAL));
        if(temp->getDeclareType() == ARRAY_TYPE)
            yyerror("ID Type Error(is a array type)");
        // Find this ID and return as DataValue * type
        (yyval.dataValue) = temp->getData();
        
    }
    break;

  case 85:
#line 925 "parser.y"
    {
        // A [ integer expression ]
        Trace("ID [ EXPRESSION ]");
        if((yyvsp[(3) - (4)].dataValue)->getDataType() != INT_TYPE)
            yyerror("Type Error (Index must be integer)");
        // Check if This ID is in scope
        IDContent * temp = SYMBOLTABLES.lookupTABLE(*(yyvsp[(1) - (4)].sVAL));
        if(temp == NULL)
            yyerror("Array Error, This Array ID is not find in the scope",*(yyvsp[(1) - (4)].sVAL));
        else if(temp->getDeclareType() != ARRAY_TYPE)
            yyerror("Type Error, This ID is not declare as Array");
        else if((yyvsp[(3) - (4)].dataValue)->getInt() < 0 || (yyvsp[(3) - (4)].dataValue)->getInt() > temp->getArrayLen())
            yyerror("Array Error, Index Out of the Range");
        else
        {
            (yyval.dataValue) = temp->getArrayByIndex((yyvsp[(3) - (4)].dataValue)->getInt());
        }

    }
    break;

  case 86:
#line 945 "parser.y"
    {
        (yyval.dataValue) = (yyvsp[(2) - (3)].dataValue);
        Trace("( EXPRESSION )");
    }
    break;

  case 87:
#line 950 "parser.y"
    {
        Trace("DATA_VALUE");
        (yyval.dataValue) = (yyvsp[(1) - (1)].dataValue);
    }
    break;

  case 88:
#line 958 "parser.y"
    {
            (yyval.DATA_TYPE) = INT_TYPE;
        }
    break;

  case 89:
#line 962 "parser.y"
    {
            (yyval.DATA_TYPE) = BOOL_TYPE;
        }
    break;

  case 90:
#line 966 "parser.y"
    {
            (yyval.DATA_TYPE) = CHAR_TYPE;
        }
    break;

  case 91:
#line 970 "parser.y"
    {
            (yyval.DATA_TYPE) = STR_TYPE;
        }
    break;

  case 92:
#line 974 "parser.y"
    {
            (yyval.DATA_TYPE) = FLOAT_TYPE;
        }
    break;

  case 93:
#line 980 "parser.y"
    {
                Trace("INT VALUE");
                (yyval.dataValue) = new DataValue((yyvsp[(1) - (1)].iVAL));
            }
    break;

  case 94:
#line 985 "parser.y"
    {
                Trace("BOOL VALUE");
                (yyval.dataValue) = new DataValue((yyvsp[(1) - (1)].bVAL));
            }
    break;

  case 95:
#line 990 "parser.y"
    {
                Trace("CHAR VALUE");
                (yyval.dataValue) = new DataValue((yyvsp[(1) - (1)].cVAL));
            }
    break;

  case 96:
#line 995 "parser.y"
    {
                Trace("STRING VALUE");
                (yyval.dataValue) = new DataValue((yyvsp[(1) - (1)].sVAL));
            }
    break;

  case 97:
#line 1000 "parser.y"
    {
                Trace("FLOAT VALUE");
                (yyval.dataValue) = new DataValue((yyvsp[(1) - (1)].fVAL));
            }
    break;


/* Line 1267 of yacc.c.  */
#line 2682 "y.tab.cpp"
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


#line 1009 "parser.y"




int main(int argc,char ** argv)
{
    ++argv, --argc; 

	if ( argc > 0 )
	    yyin = fopen( argv[0], "r" );
	else
	    yyin = stdin;

	if(!yyin){
		printf("Load File Failed\n");
		return -1;
	} 

    if (yyparse() == 1)                
        yyerror("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Parsing error!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! !");  
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~Parsing Success~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
    printf("\n");
    //SYMBOLTABLES.dumpTABLE();
}
