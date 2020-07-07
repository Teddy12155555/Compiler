/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 31 "parser.y"
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
/* Line 1529 of yacc.c.  */
#line 163 "y.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

