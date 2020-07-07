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
#define Trace(s)        //{cout << "Parser Msg : " << s << endl;}
#define Warning(t)      {printf(t);printf("\n");} 

bool isHasMain = false;
// yyeror define
void yyerror(string error_msg){
    cout << "=============== Error ===============" << endl;
    cout << buf << " ( " <<  error_msg <<  " )" << endl;
    cout << "============ Parser Fail ============" << endl;
    cout << "Terminal Casuse By Error" << endl << endl;
    exit(-1);
}
void yyerror(string error_msg,string t)
{
    cout << "=============== Error ===============" << endl;
    cout << buf << " ( " <<  error_msg <<  ")" << endl;
    cout << "With bad string : " << t << endl;
    cout << "============ Parser Fail ============" << endl;
    cout << "Terminal Casuse By Error" << endl << endl;
    exit(-1);
}
// Create a new global tables
GlobalTABLE SYMBOLTABLES;
bool global_INSERT(IDContent * Id);

// Java 
streampos fp;
int varStackID = 0;
int tabCounts = 1;
// extern vars
fstream JavaCode;
int JumpCount;
//

string className = "";
// some bool flags
bool returnFlag = false;
bool IsElseIf = false;
//
vector<vector<int>> IfJumpPoints;
vector<vector<int>> WhileJumpPoints;



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
#line 50 "parser.y"
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
#line 258 "y.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 271 "y.tab.cpp"

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
#define YYLAST   372

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNRULES -- Number of states.  */
#define YYNSTATES  181

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
      23,    29,    30,    38,    43,    50,    55,    63,    66,    67,
      68,    69,    80,    81,    83,    87,    91,    94,    95,    96,
     102,   105,   107,   108,   110,   113,   114,   116,   118,   120,
     122,   124,   126,   130,   137,   138,   142,   143,   147,   150,
     152,   154,   157,   158,   163,   165,   166,   175,   182,   183,
     184,   186,   189,   191,   194,   196,   199,   200,   201,   209,
     210,   222,   233,   238,   239,   243,   245,   248,   252,   256,
     260,   264,   268,   272,   275,   279,   283,   287,   291,   295,
     299,   301,   303,   308,   312,   314,   316,   318,   320,   322,
     324,   326,   328,   330,   332
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    -1,    18,    33,    64,    54,    65,    55,
      -1,    71,    65,    -1,    66,    65,    -1,    -1,    70,    -1,
      67,    -1,    -1,    27,    33,    68,    30,   102,    -1,    -1,
      27,    33,    56,   103,    69,    30,   102,    -1,    28,    33,
      30,   102,    -1,    28,    33,    56,   103,    30,   102,    -1,
      28,    33,    56,   103,    -1,    28,    33,    56,   103,    57,
      35,    58,    -1,    28,    33,    -1,    -1,    -1,    -1,     9,
      33,    72,    59,    75,    73,    60,    77,    74,    78,    -1,
      -1,    76,    -1,    76,    61,    75,    -1,    33,    56,   103,
      -1,    56,   103,    -1,    -1,    -1,    54,    79,    81,    80,
      55,    -1,    22,   102,    -1,    22,    -1,    -1,    82,    -1,
      82,    81,    -1,    -1,    83,    -1,    86,    -1,    88,    -1,
      96,    -1,   100,    -1,    66,    -1,    33,    30,   102,    -1,
      33,    57,   102,    58,    30,   102,    -1,    -1,    19,    84,
     102,    -1,    -1,    20,    85,   102,    -1,    31,    33,    -1,
      22,    -1,   102,    -1,    22,   102,    -1,    -1,    54,    87,
      81,    55,    -1,    89,    -1,    -1,    16,    59,   102,    60,
      91,    93,    90,    95,    -1,    16,    59,   102,    60,    91,
      93,    -1,    -1,    -1,    86,    -1,    92,    83,    -1,    86,
      -1,    92,    83,    -1,    11,    -1,    11,    93,    -1,    -1,
      -1,    29,    97,    59,   102,    60,    98,    94,    -1,    -1,
      15,    59,    33,    48,    50,   102,    24,   102,    60,    99,
      83,    -1,    15,    59,    33,    48,    50,   102,    24,   102,
      60,    86,    -1,    33,    59,   101,    60,    -1,    -1,   102,
      61,   101,    -1,   102,    -1,    50,   102,    -1,   102,    49,
     102,    -1,   102,    50,   102,    -1,   102,    51,   102,    -1,
     102,    52,   102,    -1,   102,    42,   102,    -1,   102,    41,
     102,    -1,    40,   102,    -1,   102,    48,   102,    -1,   102,
      47,   102,    -1,   102,    45,   102,    -1,   102,    46,   102,
      -1,   102,    44,   102,    -1,   102,    43,   102,    -1,   100,
      -1,    33,    -1,    33,    57,   102,    58,    -1,    59,   102,
      60,    -1,   104,    -1,    17,    -1,     3,    -1,     5,    -1,
      23,    -1,    14,    -1,    35,    -1,    34,    -1,    38,    -1,
      36,    -1,    37,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   108,   108,   107,   133,   134,   135,   142,   143,   147,
     146,   165,   164,   187,   212,   242,   269,   281,   320,   334,
     340,   319,   404,   408,   415,   423,   438,   444,   450,   449,
     464,   469,   475,   491,   492,   493,   496,   497,   498,   499,
     500,   502,   503,   543,   556,   555,   572,   571,   586,   593,
     598,   599,   607,   606,   625,   649,   648,   663,   686,   711,
     715,   721,   728,   734,   741,   755,   772,   785,   771,   817,
     816,   834,   859,   914,   918,   924,   944,   964,   992,  1020,
    1048,  1084,  1101,  1118,  1135,  1162,  1189,  1217,  1245,  1276,
    1307,  1309,  1360,  1380,  1385,  1393,  1397,  1401,  1405,  1409,
    1415,  1421,  1435,  1440,  1446
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
  "VAL_VARIABLE", "@2", "@3", "VAR_VARIABLE", "FUNCTIONS", "@4", "@5",
  "@6", "ARGS", "ARG", "FUNCTION_RETURN_TYPE", "FUNCTION_SCOPE", "@7",
  "FUNCTION_RETURN", "STATEMENTS", "STATEMENT", "SIMPLE_STATEMENT", "@8",
  "@9", "BLOCK", "@10", "CONDITION_STAMENT", "IF_STAMENT", "@11",
  "IF_SCOPE", "PUSH_TABLE", "BLOCK_OR_SIMPLE", "WHILE_BLOCK_OR_SIMPLE",
  "ELSE_STAMENT", "LOOP_STAMENT", "@12", "@13", "@14", "FUNCTION_CALL",
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
       0,    62,    64,    63,    65,    65,    65,    66,    66,    68,
      67,    69,    67,    70,    70,    70,    70,    70,    72,    73,
      74,    71,    75,    75,    75,    76,    77,    77,    79,    78,
      80,    80,    80,    81,    81,    81,    82,    82,    82,    82,
      82,    83,    83,    83,    84,    83,    85,    83,    83,    83,
      83,    83,    87,    86,    88,    90,    89,    89,    91,    92,
      93,    93,    94,    94,    95,    95,    97,    98,    96,    99,
      96,    96,   100,   101,   101,   101,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   103,   103,   103,   103,   103,
     104,   104,   104,   104,   104
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     2,     2,     0,     1,     1,     0,
       5,     0,     7,     4,     6,     4,     7,     2,     0,     0,
       0,    10,     0,     1,     3,     3,     2,     0,     0,     5,
       2,     1,     0,     1,     2,     0,     1,     1,     1,     1,
       1,     1,     3,     6,     0,     3,     0,     3,     2,     1,
       1,     2,     0,     4,     1,     0,     8,     6,     0,     0,
       1,     2,     1,     2,     1,     2,     0,     0,     7,     0,
      11,    10,     4,     0,     3,     1,     2,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       1,     1,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     6,     0,     0,     0,
       0,     6,     8,     7,     6,    18,     9,    17,     3,     5,
       4,     0,     0,     0,     0,     0,    22,    96,    97,    99,
      95,    98,    11,     0,    91,   101,   100,   103,   104,   102,
       0,     0,     0,    90,    13,    94,    15,     0,    19,    23,
       0,    10,     0,    73,    83,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,    75,    93,    82,
      81,    89,    88,    86,    87,    85,    84,    77,    78,    79,
      80,    14,     0,    25,    27,    24,    12,    92,    72,    73,
      16,     0,    20,    74,    26,     0,    28,    21,    35,     0,
       0,    44,    46,    49,    66,     0,    91,    52,    41,    32,
      33,    36,    37,    38,    54,    39,    40,    50,     0,     0,
       0,     0,    51,     0,    48,     0,     0,    35,    31,     0,
      34,     0,     0,    45,    47,     0,    42,     0,     0,    30,
      29,     0,    58,     0,    92,    53,     0,    59,    67,     0,
       0,    60,     0,    57,    59,    43,     0,    61,     0,    62,
       0,    68,     0,    59,    56,    63,    69,    65,    71,     0,
      70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    10,   118,    12,    23,    50,    13,    14,
      21,    72,   105,    48,    49,   102,   107,   108,   139,   119,
     120,   121,   130,   131,   122,   137,   123,   124,   168,   157,
     162,   163,   171,   174,   125,   133,   164,   179,    43,    76,
     127,    32,    45
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -152
static const yytype_int16 yypact[] =
{
      -3,    -7,    49,  -152,  -152,    -1,    -4,    24,    47,    48,
      27,    -4,  -152,  -152,    -4,  -152,    31,   -29,  -152,  -152,
    -152,    34,    74,    66,   142,    74,    65,  -152,  -152,  -152,
    -152,  -152,  -152,   142,   -47,  -152,  -152,  -152,  -152,  -152,
     142,   142,   142,  -152,   298,  -152,   -26,    44,  -152,    42,
      78,   298,   142,   142,   320,   298,   182,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
      69,    74,    50,    65,   142,   262,    53,   161,  -152,   320,
     320,    10,    10,    10,    10,    10,    10,   -32,   -32,  -152,
    -152,   298,    51,  -152,    59,  -152,   298,  -152,  -152,   142,
    -152,    74,  -152,  -152,  -152,    62,  -152,  -152,    36,    58,
      60,  -152,  -152,   142,  -152,    85,   -27,  -152,  -152,    98,
      36,  -152,  -152,  -152,  -152,  -152,   310,   298,    91,   142,
     142,   142,   298,    67,  -152,   142,   142,    36,   142,    72,
    -152,    80,   202,   298,   298,   142,   298,   280,    89,   298,
    -152,    79,  -152,   222,   115,  -152,   142,    93,  -152,   142,
     122,  -152,   103,   137,    93,   298,   142,  -152,   138,  -152,
     103,  -152,   242,    -8,  -152,  -152,    93,  -152,  -152,   103,
    -152
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,  -152,  -152,     0,    88,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,    77,  -152,  -152,  -152,  -152,  -152,   -52,
    -152,   -78,  -152,  -152,  -151,  -152,  -152,  -152,  -152,  -152,
     -31,   -22,  -152,  -152,  -152,  -152,  -152,  -152,   -54,    55,
     -24,   -23,  -152
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -91
static const yytype_int16 yytable[] =
{
      44,    24,    46,   135,    69,     7,   161,   -64,   -64,    51,
      52,    19,    53,   169,    20,     1,    54,    55,    56,    67,
      68,   -64,   161,     8,     9,   178,     3,    25,    75,    77,
     136,    70,    53,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   117,   -64,    93,     4,
      96,   109,   110,     6,   126,   111,   112,    15,   113,    65,
      66,    67,    68,     8,     9,   114,   126,   115,   140,   116,
      35,    36,    37,    38,    39,    77,    40,    27,   104,    28,
      16,    17,    18,   126,   167,   148,    41,    22,    29,   132,
     117,    30,   175,    26,    11,    42,    33,    31,    47,    11,
      71,   180,    11,    73,    92,   142,   143,   144,    74,   100,
      94,   146,   147,    98,   149,   101,   106,   128,   134,   129,
     138,   153,   111,   112,   141,   113,   145,   150,   151,   156,
       8,     9,   160,   170,   115,   165,   116,    35,    36,    37,
      38,    39,   172,    40,   155,   159,   166,   117,   -55,   173,
      95,   177,     0,    41,   103,     0,     0,     0,     0,     0,
       0,     0,    42,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    34,    35,    36,    37,    38,
      39,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,     0,     0,     0,     0,
       0,    42,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,     0,     0,     0,     0,     0,
       0,     0,    99,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,     0,     0,     0,     0,
       0,     0,    78,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,     0,     0,     0,     0,
       0,     0,   152,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,     0,     0,     0,     0,
       0,     0,   158,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,     0,     0,     0,     0,
       0,     0,   176,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,     0,     0,     0,     0,
      97,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,     0,     0,     0,     0,   154,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
       0,   -90,   -90,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68
};

static const yytype_int16 yycheck[] =
{
      24,    30,    25,    30,    30,     9,   157,    15,    16,    33,
      57,    11,    59,   164,    14,    18,    40,    41,    42,    51,
      52,    29,   173,    27,    28,   176,    33,    56,    52,    53,
      57,    57,    59,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    54,    55,    71,     0,
      74,    15,    16,    54,   108,    19,    20,    33,    22,    49,
      50,    51,    52,    27,    28,    29,   120,    31,   120,    33,
      34,    35,    36,    37,    38,    99,    40,     3,   101,     5,
      33,    33,    55,   137,   162,   137,    50,    56,    14,   113,
      54,    17,   170,    59,     6,    59,    30,    23,    33,    11,
      56,   179,    14,    61,    35,   129,   130,   131,    30,    58,
      60,   135,   136,    60,   138,    56,    54,    59,    33,    59,
      22,   145,    19,    20,    33,    22,    59,    55,    48,    50,
      27,    28,   156,   164,    31,   159,    33,    34,    35,    36,
      37,    38,   166,    40,    55,    30,    24,    54,    11,    11,
      73,   173,    -1,    50,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    33,    34,    35,    36,    37,
      38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      58,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,    52,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    63,    33,     0,    64,    54,     9,    27,    28,
      65,    66,    67,    70,    71,    33,    33,    33,    55,    65,
      65,    72,    56,    68,    30,    56,    59,     3,     5,    14,
      17,    23,   103,    30,    33,    34,    35,    36,    37,    38,
      40,    50,    59,   100,   102,   104,   103,    33,    75,    76,
      69,   102,    57,    59,   102,   102,   102,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    30,
      57,    56,    73,    61,    30,   102,   101,   102,    60,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,    35,   103,    60,    75,   102,    58,    60,    61,
      58,    56,    77,   101,   103,    74,    54,    78,    79,    15,
      16,    19,    20,    22,    29,    31,    33,    54,    66,    81,
      82,    83,    86,    88,    89,    96,   100,   102,    59,    59,
      84,    85,   102,    97,    33,    30,    57,    87,    22,    80,
      81,    33,   102,   102,   102,    59,   102,   102,    81,   102,
      55,    48,    60,   102,    58,    55,    50,    91,    60,    30,
     102,    86,    92,    93,    98,   102,    24,    83,    90,    86,
      92,    94,   102,    11,    95,    83,    60,    93,    86,    99,
      83
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
#line 108 "parser.y"
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

            className = *(yyvsp[(2) - (2)].sVAL);
            JavaCode << "class " << *(yyvsp[(2) - (2)].sVAL) << "{" << endl;
        }
    break;

  case 3:
#line 127 "parser.y"
    {
            //Trace("");
            JavaCode << "}" << endl;
        }
    break;

  case 9:
#line 147 "parser.y"
    {
                    fp = JavaCode.tellg();
                }
    break;

  case 10:
#line 151 "parser.y"
    {
                    Trace("VAL ID = EXPRESSION");
                    // Create new const var to gloabl Tables
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*(yyvsp[(2) - (5)].sVAL),CONST_TYPE,(yyvsp[(5) - (5)].dataValue))))
                    {

                    }
                    else
                    {
                        yyerror("ID error",*(yyvsp[(2) - (5)].sVAL));
                    }
                    JavaCode.seekg(fp);
                }
    break;

  case 11:
#line 165 "parser.y"
    {
                    fp = JavaCode.tellg();
                }
    break;

  case 12:
#line 169 "parser.y"
    {
                    Trace("VAL ID : TYPE = EXPRESSION");
                    if((yyvsp[(4) - (7)].DATA_TYPE) != (yyvsp[(7) - (7)].dataValue)->getDataType())
                    {
                        yyerror("Type Error, Not match(assign diff type)");
                    }
                    // Create new const var to gloabl Tables
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*(yyvsp[(2) - (7)].sVAL),CONST_TYPE,(yyvsp[(7) - (7)].dataValue))))
                    {
                        // Successed
                    }
                    else
                    {
                        yyerror("ID error",*(yyvsp[(2) - (7)].sVAL));
                    }
                    JavaCode.seekg(fp);
                }
    break;

  case 13:
#line 188 "parser.y"
    {
                    Trace("VAR ID = EXPRESSION");
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*(yyvsp[(2) - (4)].sVAL),VAR_TYPE,(yyvsp[(4) - (4)].dataValue))))
                    {

                    }
                    else
                    {
                        yyerror("ID Error(VAR ID = EXPRESSION)");
                    }

                    IDContent * Id = SYMBOLTABLES.lookupTABLE(*(yyvsp[(2) - (4)].sVAL));
                    if (SYMBOLTABLES.getTop() == 0)
                    {
                        GlobalVarCode(*(yyvsp[(2) - (4)].sVAL));
                        JavaCode << "\t\tputstatic int " << className << "." << *(yyvsp[(2) - (4)].sVAL) << endl;
                    }
                    else
                    {
                        Id->stackID = varStackID;
                        StoreCode(varStackID++);
                        
                    }
                }
    break;

  case 14:
#line 213 "parser.y"
    {
                    
                    Trace("VAR ID : TYPE = EXPRESSION");
                    if((yyvsp[(4) - (6)].DATA_TYPE) != (yyvsp[(6) - (6)].dataValue)->getDataType())
                    {
                        yyerror("Type Error, Not match(assign diff type)");
                    }
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*(yyvsp[(2) - (6)].sVAL),VAR_TYPE,(yyvsp[(6) - (6)].dataValue))))
                    {
                        // create new id(var)
                    }  
                    else
                    {
                        yyerror("ID Error(VAR ID : TYPE = EXPRESSION)",*(yyvsp[(2) - (6)].sVAL));
                    }

                    IDContent * Id = SYMBOLTABLES.lookupTABLE(*(yyvsp[(2) - (6)].sVAL));
                    if (SYMBOLTABLES.getTop() == 0)
                    {
                        GlobalVarCode(*(yyvsp[(2) - (6)].sVAL));
                        JavaCode << "\t\tputstatic int " << className << "." << *(yyvsp[(2) - (6)].sVAL) << endl;
                    }
                    else
                    {
                        Id->stackID = varStackID;
                        StoreCode(varStackID++);
                    }

                }
    break;

  case 15:
#line 243 "parser.y"
    {
                    Trace("VAR ID : TYPE ");
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*(yyvsp[(2) - (4)].sVAL),VAR_TYPE,(yyvsp[(4) - (4)].DATA_TYPE))))
                    {
                        //cout << "Debug : Insert " << *$2 << " as new ID !!!" << endl;
                        
                    }
                    else
                    {
                        yyerror("ID Error(VAR ID : TYPE )",*(yyvsp[(2) - (4)].sVAL));
                    }

                    IDContent * Id = SYMBOLTABLES.lookupTABLE(*(yyvsp[(2) - (4)].sVAL));
                    if (SYMBOLTABLES.getTop() == 0)
                    {
                        GlobalVarCode(*(yyvsp[(2) - (4)].sVAL));
                        //JavaCode << "\t\tputstatic int " << className << "." << *$2 << endl;
                    }
                    else
                    {
                        PushCode(0);
                        Id->stackID = varStackID;
                        StoreCode(varStackID++);
                    }

                }
    break;

  case 16:
#line 270 "parser.y"
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

  case 17:
#line 282 "parser.y"
    {
                    Trace("VAR ID ");
                    if(SYMBOLTABLES.insertTABLE(new IDContent(*(yyvsp[(2) - (2)].sVAL),VAR_TYPE,NIL_TYPE)))
                    {

                    }
                    else
                    {
                        yyerror("ID Error(VAR ID : TYPE )",*(yyvsp[(2) - (2)].sVAL));
                    }

                    IDContent * Id = SYMBOLTABLES.lookupTABLE(*(yyvsp[(2) - (2)].sVAL));
                    if (SYMBOLTABLES.getTop() == 0)
                    {
                        GlobalVarCode(*(yyvsp[(2) - (2)].sVAL));
                        //JavaCode << "\t\tputstatic int " << className << "." << *$2 << endl;
                    }
                    else
                    {
                        PushCode(0);
                        Id->stackID = varStackID;
                        StoreCode(varStackID++);
                    }

                }
    break;

  case 18:
#line 320 "parser.y"
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
                returnFlag = false;
                varStackID = 0;
            }
    break;

  case 19:
#line 334 "parser.y"
    {
                IDContent * Id = SYMBOLTABLES.lookupTABLE(*(yyvsp[(2) - (5)].sVAL));
                Id->setArgs(*(yyvsp[(5) - (5)].func_DeclareArgs));
                Id->setFuncTable(SYMBOLTABLES.getTopTable());
            }
    break;

  case 20:
#line 340 "parser.y"
    {
                IDContent * Id = SYMBOLTABLES.lookupTABLE(*(yyvsp[(2) - (8)].sVAL));
                Id->setReturnType((yyvsp[(8) - (8)].DATA_TYPE));

                if (*(yyvsp[(2) - (8)].sVAL) == "main")
                {
                    cout << "has a main ! \n";
                    isHasMain = true;

                    JavaCode << "\tmethod public static void main(java.lang.String[])" << endl;
                    JavaCode << "\tmax_stack 15" << endl << "\tmax_locals 15" << endl;
                    JavaCode << "\t{" << endl;
                    
                }
                else
                {
                    // Func no return
                    if(Id->getReturnType() == NIL_TYPE)
                    {
                        JavaCode << "\tmethod public static void " << *(yyvsp[(2) - (8)].sVAL);
                    }
                    else
                    {
                        // func return something
                        JavaCode << "\tmethod public static " << getIdDataTypeCode((yyvsp[(8) - (8)].DATA_TYPE)) << " " << *(yyvsp[(2) - (8)].sVAL);
                    }
                    if((yyvsp[(5) - (8)].func_DeclareArgs)->size() == 0){
                        JavaCode << "()" << endl;
                    }
                    else
                    {
                        JavaCode << "(";
                        int count = (yyvsp[(5) - (8)].func_DeclareArgs)->size()-1;
                        for(int i = count;i >= 0 ;i--)
                        {
                            if(i == count){
                                JavaCode << getIdDataTypeCode((*(yyvsp[(5) - (8)].func_DeclareArgs))[i]->getDataType());
                            }
                            else{
                                JavaCode << "," <<  getIdDataTypeCode((*(yyvsp[(5) - (8)].func_DeclareArgs))[i]->getDataType());
                            }
                        }
                        JavaCode << ")" << endl;
                    }
                    JavaCode << "\tmax_stack 15" << endl << "\tmax_locals 15" << endl; 
                    JavaCode << "\t{" << endl;
                }

            }
    break;

  case 21:
#line 390 "parser.y"
    {
                
                SYMBOLTABLES.popTABLE();

                if((yyvsp[(8) - (10)].DATA_TYPE) == NIL_TYPE && !returnFlag)
                {
                    JavaCode << "\t\treturn" << endl;
                }
                JavaCode << "\t\treturn" << endl;
                JavaCode << "\t}" << endl;

            }
    break;

  case 22:
#line 404 "parser.y"
    {
            Trace("NONE ARGS");
            (yyval.func_DeclareArgs) = new vector<IDContent*>();
        }
    break;

  case 23:
#line 409 "parser.y"
    {
            Trace("ARG");
            vector<IDContent*> * temp = new vector<IDContent*>();
            temp->push_back((yyvsp[(1) - (1)].func_DeclareArg));
            (yyval.func_DeclareArgs) = temp;
        }
    break;

  case 24:
#line 416 "parser.y"
    {
            Trace("ARG, ");
            (yyval.func_DeclareArgs) = (yyvsp[(3) - (3)].func_DeclareArgs);
            (yyval.func_DeclareArgs)->push_back((yyvsp[(1) - (3)].func_DeclareArg));
        }
    break;

  case 25:
#line 424 "parser.y"
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
        IDContent * temp = SYMBOLTABLES.lookupTABLE(*(yyvsp[(1) - (3)].sVAL));
        temp->stackID = varStackID++;
    }
    break;

  case 26:
#line 439 "parser.y"
    {
                            // return diff type
                            (yyval.DATA_TYPE) = (yyvsp[(2) - (2)].DATA_TYPE);
                        }
    break;

  case 27:
#line 444 "parser.y"
    {
                            // no type define
                            (yyval.DATA_TYPE) = NIL_TYPE;
                        }
    break;

  case 28:
#line 450 "parser.y"
    {
                    Trace("FUNCTION SCOPE {");
                    SYMBOLTABLES.pushTABLE();
                    cout << "~~~~~~~~~~~~~HERE!!!!!!!!!!!!!!\n";
                }
    break;

  case 29:
#line 456 "parser.y"
    {
                    Trace("FUNCTION SCOPE }");
                    (yyval.blockTABLE) = new map<string,IDContent*>();
                    // save a func id table because function call need
                    *(yyval.blockTABLE) = SYMBOLTABLES.getTopTable();
                    //SYMBOLTABLES.dumpTABLE();
                    SYMBOLTABLES.popTABLE();
                }
    break;

  case 30:
#line 465 "parser.y"
    {
                        Trace("FUNCTION RETURN EXPRESSION");
                        (yyval.dataValue) = (yyvsp[(2) - (2)].dataValue);
                    }
    break;

  case 31:
#line 470 "parser.y"
    {
                        Trace("FUNCTION RETURN");
                        (yyval.dataValue) = new DataValue();
                    }
    break;

  case 32:
#line 475 "parser.y"
    {
                        Trace("FUNCTION NONE RETURN");
                        (yyval.dataValue) = new DataValue();
                    }
    break;

  case 42:
#line 504 "parser.y"
    {
                        Trace("ID = EXPRESSION");
                        IDContent * temp = SYMBOLTABLES.lookupTABLE(*(yyvsp[(1) - (3)].sVAL));
                        if(temp == NULL)
                            yyerror("ID Error, Not exist in the scope",*(yyvsp[(1) - (3)].sVAL));
                        if(temp->getDeclareType() != VAR_TYPE)
                            yyerror("Type Error, Not allow to assign");
                        
                        if(temp->getData()->isHasValue)
                        {
                            cout << "Fuck at : " << getIdDataTypeStr(temp->getDataType()) << endl;
                            if(temp->getDataType() != (yyvsp[(3) - (3)].dataValue)->getDataType())
                            {
                                cout << "Bad assignment : " << *(yyvsp[(1) - (3)].sVAL) << endl;
                                yyerror("Assign diff Type(etc... assign bool to int)",getIdDataTypeStr((yyvsp[(3) - (3)].dataValue)->getDataType()));
                            }
                            else
                            {
                                temp->setData((yyvsp[(3) - (3)].dataValue));
                            }
                        }
                        else
                        {
                            temp->setData((yyvsp[(3) - (3)].dataValue));
                            temp->getData()->isHasValue = true;
                            
                        }

                        if(temp->stackID == -1)
                        {
                            JavaCode << "\t\tputstatic int " << className << "." << *(yyvsp[(1) - (3)].sVAL) << endl;
                        }
                        else
                        {
                            JavaCode << "\t\tistore " << (temp->stackID) << endl;
                        }


                    }
    break;

  case 43:
#line 544 "parser.y"
    {
                        Trace("ID [ EXPRESSION ] = EXPRESSION");
                        if((yyvsp[(3) - (6)].dataValue)->getDataType() != INT_TYPE)
                            yyerror("Array index must be Integer");
                        IDContent * temp = SYMBOLTABLES.lookupTABLE(*(yyvsp[(1) - (6)].sVAL));
                        if(temp == NULL)
                            yyerror("ID Error, Not exist in the scope",*(yyvsp[(1) - (6)].sVAL));
                        if(temp->getDeclareType() != ARRAY_TYPE)
                            yyerror("This ID is not Array Type",*(yyvsp[(1) - (6)].sVAL));
                        temp->setArrayData((yyvsp[(3) - (6)].dataValue)->getInt(),(yyvsp[(6) - (6)].dataValue));
                    }
    break;

  case 44:
#line 556 "parser.y"
    {
                        PrintCode();
                    }
    break;

  case 45:
#line 560 "parser.y"
    {
                        
                        Trace("PRINT EXPRESSION");
                        if((yyvsp[(3) - (3)].dataValue)->getDataType() == BOOL_TYPE)
                        {
                            JavaCode << "\t\tinvokevirtual void java.io.PrintStream.print(boolean)" << endl;
                        }else
                        {
                            JavaCode << "\t\tinvokevirtual void java.io.PrintStream.print(" << getIdDataTypeCode( (yyvsp[(3) - (3)].dataValue)->getDataType() ) << ")" << endl;
                        }
                    }
    break;

  case 46:
#line 572 "parser.y"
    {
                        PrintCode();
                    }
    break;

  case 47:
#line 575 "parser.y"
    {
                        Trace("PRINTLN EXPRESSION");
                        if((yyvsp[(3) - (3)].dataValue)->getDataType() == BOOL_TYPE)
                        {
                            JavaCode << "\t\tinvokevirtual void java.io.PrintStream.println(boolean)" << endl;
                        }else
                        {
                            JavaCode << "\t\tinvokevirtual void java.io.PrintStream.println(" << getIdDataTypeCode( (yyvsp[(3) - (3)].dataValue)->getDataType() ) << ")" << endl;
                        }
                        
                    }
    break;

  case 48:
#line 587 "parser.y"
    {
                        Trace("READ ID");
                        IDContent * temp = SYMBOLTABLES.lookupTABLE(*(yyvsp[(2) - (2)].sVAL));
                        if(temp == NULL)
                            yyerror("ID Error, Not exist in the scope",*(yyvsp[(2) - (2)].sVAL));
                    }
    break;

  case 49:
#line 594 "parser.y"
    {
                        returnFlag = true;
                        JavaCode << "\t\treturn" << endl;
                    }
    break;

  case 51:
#line 600 "parser.y"
    {
                        returnFlag = true;
                        JavaCode << "\t\tireturn" << endl;
                    }
    break;

  case 52:
#line 607 "parser.y"
    {
            Trace("BLOCK {");
            SYMBOLTABLES.pushTABLE();
        }
    break;

  case 53:
#line 612 "parser.y"
    {
            (yyval.blockTABLE) = new map<string,IDContent*>();
            *(yyval.blockTABLE) = SYMBOLTABLES.getTopTable();
            Trace("BLOCK }");
            //SYMBOLTABLES.dumpTABLE();
            if(! SYMBOLTABLES.popTABLE())
            {
                cout << "DEBUG : vec is empty, can not pop" << endl;
            }
        }
    break;

  case 55:
#line 649 "parser.y"
    {
                if((yyvsp[(3) - (6)].dataValue)->getDataType() != BOOL_TYPE)
                        yyerror("if ( must be boolean )");

                vector<int> temp = IfJumpPoints[IfJumpPoints.size()-1];
                int temp2 = temp[temp.size()-1];
                temp.pop_back();
                IfJumpPoints[IfJumpPoints.size()-1] = temp;
                JavaCode << "\tL" << temp2 <<  ":" << endl;


            }
    break;

  case 57:
#line 663 "parser.y"
    {
            if((yyvsp[(3) - (6)].dataValue)->getDataType() != BOOL_TYPE)
                        yyerror("if ( must be boolean )");

            if((yyvsp[(6) - (6)].bVAL))
            {
                SYMBOLTABLES.popTABLE();
            }
            vector<int> temp = IfJumpPoints[IfJumpPoints.size()-1];



            if (temp.size() == 2){
                JavaCode << "\tL" << temp[temp.size()-1] << ":" << endl;
                JavaCode << "\t\tgoto L" << temp[0] << endl;
            }
            int l = temp[0];
            JavaCode << "\tL" << l <<  ":" << endl;
            IfJumpPoints.pop_back();
        }
    break;

  case 58:
#line 686 "parser.y"
    {
                if(!IsElseIf)
                {
                    cout << "LabelNum : " << JumpCount << endl;
                    vector<int> temp;
                    IfJumpPoints.push_back(temp); 
                    IfJumpPoints[IfJumpPoints.size()-1].push_back(JumpCount++);
                    IfJumpPoints[IfJumpPoints.size()-1].push_back(JumpCount++);
                    cout << "Debug Start ----------------\n";
                    for(int i=0;i<IfJumpPoints.size();i++)
                    {
                        cout << "[" << i << "] : " << IfJumpPoints[i][IfJumpPoints[i].size()-1] << endl;
                    }
                    cout << "Debug End ----------------\n";
                }
                else
                {
                    IfJumpPoints[IfJumpPoints.size()-1].push_back(JumpCount++);
                }
                vector<int> temp = IfJumpPoints[IfJumpPoints.size()-1];
                JavaCode << "\t\tifeq L" << temp[temp.size()-1] << endl;
                IsElseIf = false;
            }
    break;

  case 59:
#line 711 "parser.y"
    {
                SYMBOLTABLES.pushTABLE();
            }
    break;

  case 60:
#line 716 "parser.y"
    {
                    (yyval.bVAL) = false;
                    JavaCode << "\t\tgoto L" << IfJumpPoints[IfJumpPoints.size()-1][0] << endl;
                }
    break;

  case 61:
#line 722 "parser.y"
    {
                    (yyval.bVAL) = true;
                    JavaCode << "\t\tgoto L" << IfJumpPoints[IfJumpPoints.size()-1][0] << endl;
                }
    break;

  case 62:
#line 729 "parser.y"
    {
                        (yyval.bVAL) = false;
                        JavaCode << "\t\tgoto Lbegin" << WhileJumpPoints[WhileJumpPoints.size()-1][0]  << endl;
                    }
    break;

  case 63:
#line 735 "parser.y"
    {
                        (yyval.bVAL) = true;
                        JavaCode << "\t\tgoto Lbegin" << WhileJumpPoints[WhileJumpPoints.size()-1][0] << endl;
                    }
    break;

  case 64:
#line 742 "parser.y"
    {
                    Trace("ELSE");
                    SYMBOLTABLES.pushTABLE();
                    IsElseIf = true;
                }
    break;

  case 65:
#line 756 "parser.y"
    {
                    if((yyvsp[(2) - (2)].bVAL))
                    {
                        SYMBOLTABLES.pushTABLE();
                    }
                    vector<int> temp = IfJumpPoints[IfJumpPoints.size()-1];
                    JavaCode << "\tL" << temp[0] << ":" << endl; 
                    IfJumpPoints.pop_back();
                }
    break;

  case 66:
#line 772 "parser.y"
    {
                    vector<int> temp;
                    for(int i=0;i<4;i++)
                    {
                        // L begin,true,false,exit
                        temp.push_back(JumpCount++);
                    }
                    WhileJumpPoints.push_back(temp);
                    
                    JavaCode << "\t\tgoto Lbegin" << WhileJumpPoints[WhileJumpPoints.size()-1][0] << endl;
                    JavaCode << "\tLbegin" << WhileJumpPoints[WhileJumpPoints.size()-1][0] << ":" << endl;
                }
    break;

  case 67:
#line 785 "parser.y"
    {
                    //SYMBOLTABLES.pushTABLE();
                    JavaCode << "\t\tifeq Lexit" << WhileJumpPoints[WhileJumpPoints.size()-1][3] << endl;
                    JavaCode << "\t\tgoto Ltrue" << WhileJumpPoints[WhileJumpPoints.size()-1][3] << endl;
                    JavaCode << "\tLtrue" << WhileJumpPoints[WhileJumpPoints.size()-1][3] << ":" << endl;
                }
    break;

  case 68:
#line 792 "parser.y"
    {
                    if((yyvsp[(4) - (7)].dataValue)->getDataType() != BOOL_TYPE)
                        yyerror("While( must be boolean )");
                    if((yyvsp[(7) - (7)].bVAL))
                        SYMBOLTABLES.popTABLE();
                    JavaCode << "\tLexit" << WhileJumpPoints[WhileJumpPoints.size()-1][3] << ":" << endl;
                    WhileJumpPoints.pop_back();
                }
    break;

  case 69:
#line 817 "parser.y"
    {
                    SYMBOLTABLES.pushTABLE();
                }
    break;

  case 70:
#line 820 "parser.y"
    {
                    Trace("FOR ( ID < - EXPRESSION TO EXPRESSION )");
                    //SYMBOLTABLES.dumpTABLE();
                    SYMBOLTABLES.popTABLE();
                    // only accep int
                    if((yyvsp[(6) - (11)].dataValue)->getDataType() == INT_TYPE && (yyvsp[(8) - (11)].dataValue)->getDataType() == INT_TYPE)
                    {

                    }
                    else
                    {
                        yyerror("For( must be Int )");
                    }
                }
    break;

  case 71:
#line 835 "parser.y"
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

  case 72:
#line 860 "parser.y"
    {
                    Trace("CALL_FUNCTION");
                    IDContent * temp = SYMBOLTABLES.lookupTABLE(*(yyvsp[(1) - (4)].sVAL));
                    if(temp == NULL)
                        yyerror("(calling)~~~ID Not Found, This ID is not declare in the scope");
                    if(temp->getDeclareType() != FUNC_TYPE)
                        yyerror("'ID' is not a function",*(yyvsp[(1) - (4)].sVAL));
                    cout << "Going to call size is : " << (yyvsp[(3) - (4)].func_CallArgs)->size() << endl;
                    // match same args functs
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
                        // check all arg's type
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

                    if(temp->getReturnType() == NIL_TYPE)
                    {
                        JavaCode << "\t\tinvokestatic void " << className << "." << *(yyvsp[(1) - (4)].sVAL) << "(" ;
                    }
                    else
                    {
                        JavaCode << "\t\tinvokestatic int " << className << "." << *(yyvsp[(1) - (4)].sVAL) << "(" ;
                    }

                    //JavaCode << "\t\tinvokestatic int " << className << "." << *$1 << "(" ;
                    for(int i=(yyvsp[(3) - (4)].func_CallArgs)->size()-1;i>=0;--i){
                        if(i == (yyvsp[(3) - (4)].func_CallArgs)->size()-1)
                        {
                            JavaCode << getIdDataTypeCode((*(yyvsp[(3) - (4)].func_CallArgs))[i]->getDataType());
                        }
                        else
                        {
                            JavaCode << "," <<  getIdDataTypeCode((*(yyvsp[(3) - (4)].func_CallArgs))[i]->getDataType());
                        }
                    }
                    JavaCode << ")" << endl;
                }
    break;

  case 73:
#line 914 "parser.y"
    {
                                Trace("FUNCTION ARG");
                                (yyval.func_CallArgs) = new vector<DataValue*>();
                            }
    break;

  case 74:
#line 919 "parser.y"
    {
                                Trace("FUNCTION ARG");
                                (yyvsp[(3) - (3)].func_CallArgs)->push_back((yyvsp[(1) - (3)].dataValue));
                                (yyval.func_CallArgs) = (yyvsp[(3) - (3)].func_CallArgs);
                            }
    break;

  case 75:
#line 925 "parser.y"
    {
                                Trace("FUNCTION ARGs");
                                (yyval.func_CallArgs) = new vector<DataValue*>();
                                (yyval.func_CallArgs)->push_back((yyvsp[(1) - (1)].dataValue));
                            }
    break;

  case 76:
#line 945 "parser.y"
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
        OpCode('n');
    }
    break;

  case 77:
#line 965 "parser.y"
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
        OpCode('+');
    }
    break;

  case 78:
#line 993 "parser.y"
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
        OpCode('-');
    }
    break;

  case 79:
#line 1021 "parser.y"
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
        OpCode('*');
    }
    break;

  case 80:
#line 1049 "parser.y"
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
                    //int temp  = $1->getInt() ;
                    cout << "Debug : " << result->getDataType() << endl;
                    result->setInt(0);
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
        //cout << "Debug : " << result->getDataType() << endl;
        (yyval.dataValue) = result;
        OpCode('/');
    }
    break;

  case 81:
#line 1085 "parser.y"
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
        OpCode('&');
    }
    break;

  case 82:
#line 1102 "parser.y"
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
        OpCode('|');
    }
    break;

  case 83:
#line 1119 "parser.y"
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
        OpCode('!');
    }
    break;

  case 84:
#line 1136 "parser.y"
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
        LogicOpCode(0);
    }
    break;

  case 85:
#line 1163 "parser.y"
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
        LogicOpCode(1);
    }
    break;

  case 86:
#line 1190 "parser.y"
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
        LogicOpCode(3);
    }
    break;

  case 87:
#line 1218 "parser.y"
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
        LogicOpCode(4);
    }
    break;

  case 88:
#line 1246 "parser.y"
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
        LogicOpCode(2);
    }
    break;

  case 89:
#line 1277 "parser.y"
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
        LogicOpCode(5);
    }
    break;

  case 91:
#line 1310 "parser.y"
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
        // Java
        DataValue * data = temp->getData();
        int value;
        if(temp->getDeclareType() == CONST_TYPE)
        {
            //cout << "_______Here!!!!!!!!!!!!!!!!!!!!!!\n";
            if(data->getDataType() == INT_TYPE)
            {
                PushCode(data->getInt());
            }
            else if(data->getDataType() == BOOL_TYPE)
            {
                if(data->getBool())
                {
                    PushCode(1);   //true
                }
                else
                {
                    PushCode(0);    //false
                }
            }
            else //string
            {
                JavaCode << "\t\tldc " <<  "\"" << *(data->getStr()) << "\"" << endl;
            }
        }
        else
        {
            //cout << "Here!!!!!!!!!!!!!!!!!!!!!!\n";
            if(temp->stackID == -1)
            {
                JavaCode << "\t\tgetstatic int " << className << "." << *(yyvsp[(1) - (1)].sVAL) << endl;
            }
            else
            {
                LoadCode(temp->stackID);
            }
        }

    }
    break;

  case 92:
#line 1361 "parser.y"
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

  case 93:
#line 1381 "parser.y"
    {
        (yyval.dataValue) = (yyvsp[(2) - (3)].dataValue);
        Trace("( EXPRESSION )");
    }
    break;

  case 94:
#line 1386 "parser.y"
    {
        Trace("DATA_VALUE");
        (yyval.dataValue) = (yyvsp[(1) - (1)].dataValue);
    }
    break;

  case 95:
#line 1394 "parser.y"
    {
            (yyval.DATA_TYPE) = INT_TYPE;
        }
    break;

  case 96:
#line 1398 "parser.y"
    {
            (yyval.DATA_TYPE) = BOOL_TYPE;
        }
    break;

  case 97:
#line 1402 "parser.y"
    {
            (yyval.DATA_TYPE) = CHAR_TYPE;
        }
    break;

  case 98:
#line 1406 "parser.y"
    {
            (yyval.DATA_TYPE) = STR_TYPE;
        }
    break;

  case 99:
#line 1410 "parser.y"
    {
            (yyval.DATA_TYPE) = FLOAT_TYPE;
        }
    break;

  case 100:
#line 1416 "parser.y"
    {
                Trace("INT VALUE");
                (yyval.dataValue) = new DataValue((yyvsp[(1) - (1)].iVAL));
                PushCode((yyvsp[(1) - (1)].iVAL));
            }
    break;

  case 101:
#line 1422 "parser.y"
    {
                Trace("BOOL VALUE");
                (yyval.dataValue) = new DataValue((yyvsp[(1) - (1)].bVAL));
                if((yyvsp[(1) - (1)].bVAL))
                {
                    PushCode(1);
                }
                else
                {
                    PushCode(0);
                }
                
            }
    break;

  case 102:
#line 1436 "parser.y"
    {
                Trace("CHAR VALUE");
                (yyval.dataValue) = new DataValue((yyvsp[(1) - (1)].cVAL));
            }
    break;

  case 103:
#line 1441 "parser.y"
    {
                Trace("STRING VALUE");
                (yyval.dataValue) = new DataValue((yyvsp[(1) - (1)].sVAL));
                JavaCode << "\t\tldc "  << "\"" << *(yyvsp[(1) - (1)].sVAL) << "\"" << endl;
            }
    break;

  case 104:
#line 1447 "parser.y"
    {
                Trace("FLOAT VALUE");
                (yyval.dataValue) = new DataValue((yyvsp[(1) - (1)].fVAL));
            }
    break;


/* Line 1267 of yacc.c.  */
#line 3123 "y.tab.cpp"
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


#line 1454 "parser.y"


int main(int argc,char ** argv)
{
    ++argv, --argc; 
    string filename;
	if ( argc > 0 )
    {
	    yyin = fopen( argv[0], "r" );
        filename = string(argv[0]);
        filename = filename +  ".jasm";
        JavaCode.open(filename,ios::out);
    }
	else
    {
	    yyin = stdin;
        JavaCode.open("JaveByteCode.jasm",ios::out);
    }

    if(!JavaCode){
        cout << "Can't build JavaByteCode file !\n";
        exit(1);
    }

	if(!yyin){
		printf("Load File Failed\n");
		return -1;
	} 

    if (yyparse() == 1)                
            yyerror("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Parsing error!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! !");
    else
    {
        printf("\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~Parsing Success~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
        printf("\n");
        if(isHasMain)
        {
            SYMBOLTABLES.dumpTABLE();
            cout << "JaveByteCode File : " << filename << "has been built\n";
        }
        else
        {
            cout << "No main() exist !\n";
        }
    }  
    
}
