/* A Bison parser, made by GNU Bison 2.0.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_EOF = 258,
     T_ERROR = 259,
     T_DOT = 260,
     T_SEMICOLON = 261,
     T_EQ = 262,
     T_COLON = 263,
     T_LEFTBRACKET = 264,
     T_RIGHTBRACKET = 265,
     T_LEFTPAR = 266,
     T_RIGHTPAR = 267,
     T_COMMA = 268,
     T_LESSTHAN = 269,
     T_GREATERTHAN = 270,
     T_ADD = 271,
     T_SUB = 272,
     T_MUL = 273,
     T_RDIV = 274,
     T_OF = 275,
     T_IF = 276,
     T_DO = 277,
     T_ASSIGN = 278,
     T_NOTEQ = 279,
     T_OR = 280,
     T_VAR = 281,
     T_END = 282,
     T_AND = 283,
     T_IDIV = 284,
     T_MOD = 285,
     T_NOT = 286,
     T_THEN = 287,
     T_ELSE = 288,
     T_CONST = 289,
     T_ARRAY = 290,
     T_BEGIN = 291,
     T_WHILE = 292,
     T_ELSIF = 293,
     T_RETURN = 294,
     T_STRINGCONST = 295,
     T_IDENT = 296,
     T_PROGRAM = 297,
     T_PROCEDURE = 298,
     T_FUNCTION = 299,
     T_INTNUM = 300,
     T_REALNUM = 301
   };
#endif
#define T_EOF 258
#define T_ERROR 259
#define T_DOT 260
#define T_SEMICOLON 261
#define T_EQ 262
#define T_COLON 263
#define T_LEFTBRACKET 264
#define T_RIGHTBRACKET 265
#define T_LEFTPAR 266
#define T_RIGHTPAR 267
#define T_COMMA 268
#define T_LESSTHAN 269
#define T_GREATERTHAN 270
#define T_ADD 271
#define T_SUB 272
#define T_MUL 273
#define T_RDIV 274
#define T_OF 275
#define T_IF 276
#define T_DO 277
#define T_ASSIGN 278
#define T_NOTEQ 279
#define T_OR 280
#define T_VAR 281
#define T_END 282
#define T_AND 283
#define T_IDIV 284
#define T_MOD 285
#define T_NOT 286
#define T_THEN 287
#define T_ELSE 288
#define T_CONST 289
#define T_ARRAY 290
#define T_BEGIN 291
#define T_WHILE 292
#define T_ELSIF 293
#define T_RETURN 294
#define T_STRINGCONST 295
#define T_IDENT 296
#define T_PROGRAM 297
#define T_PROCEDURE 298
#define T_FUNCTION 299
#define T_INTNUM 300
#define T_REALNUM 301




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include <iostream>
#include "semantic.hh"
#include "optimize.hh"
#include "codegen.hh"

/* Defined in parser.cc */
extern char *yytext;

/* Nr of errors encountered so far. Only generate quads & assembler if
   error_count == 0. Defined in error.cc. */
extern int error_count;

/* Defined in symtab.cc. */
extern symbol_table *sym_tab;

/* Defined in semantic.cc. */
extern semantic *type_checker;

/* Defined in codegen.cc. */
extern code_generator *code_gen;

/* From scanner.l output. */
extern int yylex();

/* Defined in error.hh. */
extern void yyerror(string);

/* All these defined in main.cc. They represent some of the flags
   given to the 'diesel' script. */
extern bool print_ast;
extern bool print_quads;
extern bool typecheck;
extern bool optimize;
extern bool quads;
extern bool assembler;

#define YYDEBUG 1

/* Have this defined to give better error messages. Using it causes
   some bison warnings at compiler compile time, however. Use as you
   wish. Not mandatory. */
/* #define YYERROR_VERBOSE */


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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 54 "parser.y"
typedef union YYSTYPE {
    ast_node             *ast;
    ast_id               *id;
    ast_stmt_list        *statement_list;
    ast_statement        *statement;
    ast_expr_list        *expression_list;
    ast_expression       *expression;
    ast_elsif_list       *elsif_list;
    ast_elsif            *elsif;
    ast_lvalue           *lvalue;
    ast_functioncall     *function_call;
    ast_functionhead     *function_head;
    ast_procedurehead    *procedure_head;
    ast_integer          *integer;
    ast_real             *real;

    long                  ival;
    double                rval;
    pool_index            str;
    pool_index            pool_p;
} YYSTYPE;
/* Line 190 of yacc.c.  */
#line 235 "parser.cc"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 213 of yacc.c.  */
#line 259 "parser.cc"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYLTYPE_IS_TRIVIAL) && YYLTYPE_IS_TRIVIAL \
             && defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
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
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   439

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  45
/* YYNRULES -- Number of rules. */
#define YYNRULES  107
/* YYNRULES -- Number of states. */
#define YYNSTATES  213

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     8,    13,    16,    19,    22,    23,    25,
      28,    33,    38,    43,    48,    53,    58,    63,    68,    71,
      72,    74,    77,    82,    92,   102,   104,   105,   107,   110,
     115,   120,   126,   134,   137,   140,   144,   148,   149,   151,
     155,   159,   163,   165,   169,   177,   185,   191,   197,   203,
     209,   214,   219,   223,   227,   230,   233,   235,   236,   238,
     243,   248,   250,   255,   260,   263,   264,   269,   272,   273,
     275,   276,   278,   282,   284,   288,   292,   296,   300,   302,
     305,   308,   312,   316,   320,   322,   326,   330,   334,   338,
     342,   344,   346,   348,   350,   353,   357,   362,   363,   365,
     367,   369,   371,   373,   375,   377,   379,   381
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      48,     0,    -1,    49,    57,    67,     5,    -1,    50,     6,
      51,    54,    -1,    42,    41,    -1,    34,    52,    -1,     1,
      52,    -1,    -1,    53,    -1,    52,    53,    -1,    41,     7,
      82,     6,    -1,    41,     7,    83,     6,    -1,    41,     7,
      40,     6,    -1,    41,     7,    85,     6,    -1,    41,     7,
       1,     6,    -1,    41,     7,    83,     1,    -1,    41,     7,
      82,     1,    -1,    41,     7,    85,     1,    -1,    26,    55,
      -1,    -1,    56,    -1,    55,    56,    -1,    41,     8,    84,
       6,    -1,    41,     8,    35,     9,    82,    10,    20,    84,
       6,    -1,    41,     8,    35,     9,    85,    10,    20,    84,
       6,    -1,    58,    -1,    -1,    59,    -1,    58,    59,    -1,
      60,    57,    67,     6,    -1,    61,    57,    67,     6,    -1,
      62,    64,     6,    51,    54,    -1,    63,    64,     8,    84,
       6,    51,    54,    -1,    43,    41,    -1,    44,    41,    -1,
      11,    65,    12,    -1,    11,     1,    12,    -1,    -1,    66,
      -1,    65,     6,    66,    -1,    41,     8,    84,    -1,    36,
      68,    27,    -1,    69,    -1,    68,     6,    69,    -1,    21,
      77,    32,    68,    72,    74,    27,    -1,    21,     1,    32,
      68,    72,    74,    27,    -1,    37,    77,    22,    68,    27,
      -1,    37,    77,    22,     1,    27,    -1,    37,     1,    22,
      68,    27,    -1,    37,     1,    22,     1,    27,    -1,    88,
      11,    75,    12,    -1,    88,    11,     1,    12,    -1,    70,
      23,    77,    -1,    70,    23,     1,    -1,    39,    77,    -1,
      39,     1,    -1,    39,    -1,    -1,    86,    -1,    90,     9,
      77,    10,    -1,    90,     9,     1,    10,    -1,    87,    -1,
      90,     9,    77,    10,    -1,    90,     9,     1,    10,    -1,
      72,    73,    -1,    -1,    38,    77,    32,    68,    -1,    33,
      68,    -1,    -1,    76,    -1,    -1,    77,    -1,    76,    13,
      77,    -1,    78,    -1,    77,     7,    78,    -1,    77,    24,
      78,    -1,    77,    14,    78,    -1,    77,    15,    78,    -1,
      79,    -1,    16,    79,    -1,    17,    79,    -1,    78,    25,
      79,    -1,    78,    16,    79,    -1,    78,    17,    79,    -1,
      80,    -1,    79,    28,    80,    -1,    79,    18,    80,    -1,
      79,    19,    80,    -1,    79,    29,    80,    -1,    79,    30,
      80,    -1,    71,    -1,    81,    -1,    82,    -1,    83,    -1,
      31,    80,    -1,    11,    77,    12,    -1,    89,    11,    75,
      12,    -1,    -1,    45,    -1,    46,    -1,    91,    -1,    91,
      -1,    91,    -1,    91,    -1,    91,    -1,    91,    -1,    91,
      -1,    41,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   124,   124,   173,   180,   200,   201,   202,   206,   207,
     211,   220,   229,   233,   259,   263,   267,   271,   278,   279,
     283,   284,   288,   297,   308,   360,   361,   365,   366,   370,
     418,   469,   476,   485,   505,   527,   532,   538,   544,   549,
     555,   573,   582,   596,   614,   623,   628,   637,   642,   647,
     652,   661,   666,   675,   680,   689,   693,   704,   710,   714,
     720,   728,   733,   740,   748,   758,   764,   776,   782,   788,
     794,   800,   809,   821,   826,   835,   844,   853,   865,   870,
     880,   889,   898,   907,   919,   925,   934,   943,   952,   960,
     971,   975,   979,   983,   987,   995,  1004,  1014,  1019,  1032,
    1045,  1060,  1074,  1087,  1104,  1118,  1132,  1146
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_EOF", "T_ERROR", "T_DOT",
  "T_SEMICOLON", "T_EQ", "T_COLON", "T_LEFTBRACKET", "T_RIGHTBRACKET",
  "T_LEFTPAR", "T_RIGHTPAR", "T_COMMA", "T_LESSTHAN", "T_GREATERTHAN",
  "T_ADD", "T_SUB", "T_MUL", "T_RDIV", "T_OF", "T_IF", "T_DO", "T_ASSIGN",
  "T_NOTEQ", "T_OR", "T_VAR", "T_END", "T_AND", "T_IDIV", "T_MOD", "T_NOT",
  "T_THEN", "T_ELSE", "T_CONST", "T_ARRAY", "T_BEGIN", "T_WHILE",
  "T_ELSIF", "T_RETURN", "T_STRINGCONST", "T_IDENT", "T_PROGRAM",
  "T_PROCEDURE", "T_FUNCTION", "T_INTNUM", "T_REALNUM", "$accept",
  "program", "prog_decl", "prog_head", "const_part", "const_decls",
  "const_decl", "variable_part", "var_decls", "var_decl", "subprog_part",
  "subprog_decls", "subprog_decl", "proc_decl", "func_decl", "proc_head",
  "func_head", "opt_param_list", "param_list", "param", "comp_stmt",
  "stmt_list", "stmt", "lvariable", "rvariable", "elsif_list", "elsif",
  "else_part", "opt_expr_list", "expr_list", "expr", "simple_expr", "term",
  "factor", "func_call", "integer", "real", "type_id", "const_id",
  "lvar_id", "rvar_id", "proc_id", "func_id", "array_id", "id", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    47,    48,    49,    50,    51,    51,    51,    52,    52,
      53,    53,    53,    53,    53,    53,    53,    53,    54,    54,
      55,    55,    56,    56,    56,    57,    57,    58,    58,    59,
      59,    60,    61,    62,    63,    64,    64,    64,    65,    65,
      66,    67,    68,    68,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      70,    71,    71,    71,    72,    72,    73,    74,    74,    75,
      75,    76,    76,    77,    77,    77,    77,    77,    78,    78,
      78,    78,    78,    78,    79,    79,    79,    79,    79,    79,
      80,    80,    80,    80,    80,    80,    81,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     4,     4,     2,     2,     2,     0,     1,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     2,     0,
       1,     2,     4,     9,     9,     1,     0,     1,     2,     4,
       4,     5,     7,     2,     2,     3,     3,     0,     1,     3,
       3,     3,     1,     3,     7,     7,     5,     5,     5,     5,
       4,     4,     3,     3,     2,     2,     1,     0,     1,     4,
       4,     1,     4,     4,     2,     0,     4,     2,     0,     1,
       0,     1,     3,     1,     3,     3,     3,     3,     1,     2,
       2,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     2,     3,     4,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,    26,     0,     4,     1,     0,     0,     0,
      25,    27,    26,    26,    37,    37,     0,    33,    34,    57,
       0,    28,     0,     0,     0,     0,     0,     0,     0,    19,
       0,     0,     0,   107,     0,    42,     0,    58,     0,     0,
     102,     2,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     6,     8,     5,     0,     3,     0,    97,    97,    97,
      97,    98,    99,    90,     0,    73,    78,    84,    91,    92,
      93,    61,     0,     0,   103,     0,     0,    55,    54,    57,
      41,     0,     0,     0,    29,    30,    36,     0,     0,    35,
      19,     0,   100,     0,     9,     0,    18,    20,    57,     0,
      79,    80,    94,    97,    97,    97,    97,    57,    97,    97,
      97,    97,    97,    97,    97,    97,    97,     0,     0,     0,
      43,    53,    52,     0,     0,    69,    71,     0,     0,    40,
      39,    31,     0,     0,     0,     0,     0,     0,   101,     0,
      21,    65,    95,    74,    76,    77,    75,    65,    82,    83,
      81,    86,    87,    85,    88,    89,     0,     0,     0,     0,
       0,     0,     0,    51,    50,    97,    60,    59,    19,    14,
      12,    16,    10,    15,    11,    17,    13,     0,     0,    68,
      68,    96,    63,    62,    49,    48,    47,    46,    72,    32,
       0,    22,    57,    97,    64,     0,     0,     0,     0,    67,
       0,    45,    44,     0,     0,    57,     0,     0,    66,     0,
       0,    23,    24
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     2,     3,     4,    29,    51,    52,    55,    96,    97,
       9,    10,    11,    12,    13,    14,    15,    25,    46,    47,
      20,    34,    35,    36,    63,   179,   194,   195,   124,   125,
     126,    65,    66,    67,    68,    69,    70,    91,   137,    37,
      71,    38,    72,    73,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -98
static const short int yypact[] =
{
     -14,   -24,    40,   -18,    44,   -98,   -98,    55,    63,    42,
     -18,   -98,   -18,   -18,    79,    79,    83,   -98,   -98,    46,
     120,   -98,    42,    42,    11,   104,   135,   123,   123,   141,
     253,   286,   117,   -98,     7,   -98,   131,   -98,   150,   163,
     105,   -98,   175,   178,   181,   186,    21,   -98,    83,   155,
     190,   123,   -98,   123,   169,   -98,   187,   375,    66,    66,
      66,   -98,   -98,   -98,   142,   113,   228,   -98,   -98,   -98,
     -98,   -98,   205,   209,   128,   198,    91,   -98,   381,    46,
     -98,   184,   220,   319,   -98,   -98,   -98,   155,   182,   -98,
     141,   218,   -98,    35,   -98,   232,   169,   -98,    46,   168,
     228,   228,   -98,   375,   375,   375,   375,    46,    66,    66,
      66,    66,    66,    66,    66,    66,   373,   352,    10,    18,
     -98,   -98,   381,   214,   216,   229,   381,   231,   393,   -98,
     -98,   -98,    83,   237,   246,    37,    47,    88,   -98,    -6,
     -98,   247,   -98,   113,   113,   113,   113,   247,   228,   228,
     228,   -98,   -98,   -98,   -98,   -98,   243,   249,   415,   235,
      14,   236,    17,   -98,   -98,   375,   -98,   -98,   141,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   264,   268,   132,
     132,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   381,   -98,
       1,   -98,    46,   375,   -98,   248,   252,   266,   270,   247,
     145,   -98,   -98,   269,   271,    46,   155,   155,   247,   280,
     282,   -98,   -98
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
     -98,   -98,   -98,   -98,   -39,   262,   100,   -82,   -98,   196,
      49,   -98,   285,   -98,   -98,   -98,   -98,   281,   -98,   219,
     156,   -97,   227,   -98,   -98,   162,   -98,   133,   202,   -98,
     -25,   101,   -44,   -42,   -98,   -89,   226,   -85,   122,   -98,
     -98,   -98,   -98,   -16,   -19
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -107
static const short int yytable[] =
{
      40,   141,   129,    39,   135,    64,    76,    78,   131,    90,
     147,   159,    44,    79,   100,   101,   -57,     5,   102,   161,
      79,   160,   162,    79,   -57,     7,     8,    88,     1,   177,
      92,    30,    99,    89,    80,    33,   133,   -57,   171,    30,
       6,   185,    33,   172,   187,   -57,    61,    31,   173,    32,
      16,    33,    45,   174,   178,    31,   122,    32,   128,    33,
      40,    22,    23,    39,   148,   149,   150,    30,    92,   151,
     152,   153,   154,   155,   138,   134,    33,    57,    19,    40,
      61,    62,    39,    31,    27,    32,   189,    33,    40,   175,
      24,    39,   158,   168,   176,   199,    17,    60,   103,    40,
      40,   197,    39,    39,    18,   104,   105,    33,   208,    -7,
      48,    61,    62,   119,  -106,   106,  -104,    28,    77,    -7,
      92,   209,   210,   -56,   -97,    41,    -7,    -7,    57,   108,
     109,   -97,   -97,    58,    59,   -97,   -97,  -106,   110,  -105,
     188,   -97,   -97,    49,   -56,   -97,   -97,   -97,    60,   103,
     -56,    94,   103,    94,    81,   -56,   104,   105,    33,   104,
     105,    82,    61,    62,    50,   192,   106,    54,   200,   106,
     193,   138,    83,    40,   107,   103,    39,   205,    42,    43,
     142,    84,   104,   105,    85,   121,    40,    92,    92,    39,
     -97,   -97,   106,    86,    87,    57,    33,    93,   -97,   -97,
      58,    59,   -97,   -97,   143,   144,   145,   146,   -97,   -97,
      95,   -97,   -97,   -97,   -97,    60,   116,   -97,   117,    98,
     118,   123,   -97,    45,   132,    33,   163,   -97,   164,    61,
      62,    57,   -70,   -97,   -97,   -97,    58,    59,   -97,   -97,
     139,   166,   165,   169,   -97,   -97,   111,   112,   -97,   -97,
     -97,    60,   170,    79,    56,   181,   113,   114,   115,   182,
     -97,    33,   184,   186,    57,    61,    62,   -97,   -97,    58,
      59,   -97,   -97,   190,   191,   201,   203,   -97,   -97,   202,
     204,   -97,   -97,   -97,    60,   -97,   211,    75,   212,   206,
      53,   207,   140,   -97,    33,    21,    26,    57,    61,    62,
     -97,   -97,    58,    59,   -97,   -97,   120,   130,   -97,   180,
     -97,   -97,   198,   196,   -97,   -97,   -97,    60,   156,   136,
     127,     0,     0,     0,     0,     0,   -97,    33,     0,   -97,
      57,    61,    62,   -97,   -97,    58,    59,   -97,   -97,     0,
       0,     0,     0,   -97,   -97,     0,     0,   -97,   -97,   -97,
      60,     0,     0,   157,     0,     0,     0,     0,     0,   -97,
      33,     0,   -97,    57,    61,    62,   -97,   -97,    58,    59,
     -97,   -97,     0,     0,     0,     0,   -97,   -97,     0,     0,
     -97,   -97,   -97,    60,    57,   -70,    57,     0,   103,    58,
      59,    58,    59,    33,     0,   104,   105,    61,    62,     0,
     103,     0,     0,   167,    60,   106,    60,   104,   105,     0,
       0,     0,     0,     0,    33,     0,    33,   106,    61,    62,
      61,    62,   103,     0,     0,   183,     0,     0,     0,   104,
     105,     0,     0,     0,     0,     0,     0,     0,     0,   106
};

static const short int yycheck[] =
{
      19,    98,    87,    19,    93,    30,    31,    32,    90,    48,
     107,     1,     1,     6,    58,    59,     6,    41,    60,     1,
       6,   118,   119,     6,     6,    43,    44,     6,    42,    35,
      49,    21,    57,    12,    27,    41,     1,    27,     1,    21,
       0,    27,    41,     6,    27,    27,    45,    37,     1,    39,
       6,    41,    41,     6,   139,    37,    81,    39,    83,    41,
      79,    12,    13,    79,   108,   109,   110,    21,    87,   111,
     112,   113,   114,   115,    93,    40,    41,    11,    36,    98,
      45,    46,    98,    37,     1,    39,   168,    41,   107,     1,
      11,   107,   117,   132,     6,   192,    41,    31,     7,   118,
     119,   190,   118,   119,    41,    14,    15,    41,   205,    26,
       6,    45,    46,    22,     9,    24,    11,    34,     1,    36,
     139,   206,   207,     6,     7,     5,    43,    44,    11,    16,
      17,    14,    15,    16,    17,    18,    19,     9,    25,    11,
     165,    24,    25,     8,    27,    28,    29,    30,    31,     7,
      33,    51,     7,    53,    23,    38,    14,    15,    41,    14,
      15,    11,    45,    46,    41,    33,    24,    26,   193,    24,
      38,   190,     9,   192,    32,     7,   192,    32,    22,    23,
      12,     6,    14,    15,     6,     1,   205,   206,   207,   205,
       6,     7,    24,    12,     8,    11,    41,     7,    14,    15,
      16,    17,    18,    19,   103,   104,   105,   106,    24,    25,
      41,    27,    28,    29,    30,    31,    11,    33,     9,    32,
      22,     1,    38,    41,     6,    41,    12,     7,    12,    45,
      46,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       8,    10,    13,     6,    24,    25,    18,    19,    28,    29,
      30,    31,     6,     6,     1,    12,    28,    29,    30,    10,
       7,    41,    27,    27,    11,    45,    46,    14,    15,    16,
      17,    18,    19,     9,     6,    27,    10,    24,    25,    27,
      10,    28,    29,    30,    31,    32,     6,     1,     6,    20,
      28,    20,    96,     7,    41,    10,    15,    11,    45,    46,
      14,    15,    16,    17,    18,    19,    79,    88,    22,   147,
      24,    25,   190,   180,    28,    29,    30,    31,   116,    93,
       1,    -1,    -1,    -1,    -1,    -1,     7,    41,    -1,    10,
      11,    45,    46,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    24,    25,    -1,    -1,    28,    29,    30,
      31,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,     7,
      41,    -1,    10,    11,    45,    46,    14,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,
      28,    29,    30,    31,    11,    12,    11,    -1,     7,    16,
      17,    16,    17,    41,    -1,    14,    15,    45,    46,    -1,
       7,    -1,    -1,    10,    31,    24,    31,    14,    15,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    41,    24,    45,    46,
      45,    46,     7,    -1,    -1,    10,    -1,    -1,    -1,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    42,    48,    49,    50,    41,     0,    43,    44,    57,
      58,    59,    60,    61,    62,    63,     6,    41,    41,    36,
      67,    59,    57,    57,    11,    64,    64,     1,    34,    51,
      21,    37,    39,    41,    68,    69,    70,    86,    88,    90,
      91,     5,    67,    67,     1,    41,    65,    66,     6,     8,
      41,    52,    53,    52,    26,    54,     1,    11,    16,    17,
      31,    45,    46,    71,    77,    78,    79,    80,    81,    82,
      83,    87,    89,    90,    91,     1,    77,     1,    77,     6,
      27,    23,    11,     9,     6,     6,    12,     8,     6,    12,
      51,    84,    91,     7,    53,    41,    55,    56,    32,    77,
      79,    79,    80,     7,    14,    15,    24,    32,    16,    17,
      25,    18,    19,    28,    29,    30,    11,     9,    22,    22,
      69,     1,    77,     1,    75,    76,    77,     1,    77,    84,
      66,    54,     6,     1,    40,    82,    83,    85,    91,     8,
      56,    68,    12,    78,    78,    78,    78,    68,    79,    79,
      79,    80,    80,    80,    80,    80,    75,     1,    77,     1,
      68,     1,    68,    12,    12,    13,    10,    10,    51,     6,
       6,     1,     6,     1,     6,     1,     6,    35,    84,    72,
      72,    12,    10,    10,    27,    27,    27,    27,    77,    54,
       9,     6,    33,    38,    73,    74,    74,    82,    85,    68,
      77,    27,    27,    10,    10,    32,    20,    20,    68,    84,
      84,     6,     6
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
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
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Type, Value, Location);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
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
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;
  (void) yylocationp;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  fprintf (yyoutput, ": ");

# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;
  (void) yylocationp;

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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
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
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  register short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended. */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

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
  yylsp = yyls;
#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif


  yyvsp[0] = yylval;
    yylsp[0] = yylloc;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

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

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
  *++yylsp = yylloc;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, yylsp - yylen, yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 125 "parser.y"
    {

                    symbol *env = sym_tab->get_symbol((yyvsp[-3].procedure_head)->sym_p);

                    // The status variables here depend on what flags were
                    // passed to the compiler. See the 'diesel' script for
                    // more information.
                    if (typecheck) {
                        type_checker->do_typecheck(env, (yyvsp[-1].statement_list));
                    }

                    if (print_ast) {
                        cout << "\nUnoptimized AST for global level" << endl;
                        cout << (ast_stmt_list *)(yyvsp[-1].statement_list) << endl;
                    }

                    if (optimize) {
                        optimizer->do_optimize((yyvsp[-1].statement_list));
                        if(print_ast) {
                            cout << "\nOptimized AST for global level" << endl;
                            cout << (ast_stmt_list *)(yyvsp[-1].statement_list) << endl;
                        }
                    }
                    if (error_count == 0) {
                        if (quads) {
                            quad_list *q = (yyvsp[-3].procedure_head)->do_quads((yyvsp[-1].statement_list));
                            if (print_quads) {
                                cout << "\nQuad list for global level" << endl;
                                cout << (quad_list *)q << endl;
                            }

                            if (assembler) {
                                cout << "Generating assembler, global level"
                                     << endl;
                                code_gen->generate_assembler(q, env);
                            }
                        }
                    } else {
                        cout << "Found " << error_count << " errors. "
                             << "Compilation aborted.\n";
                    }

                    // We close the global scope.
                    sym_tab->close_scope();
                ;}
    break;

  case 3:
#line 174 "parser.y"
    {
		  (yyval.procedure_head) = (yyvsp[-3].procedure_head);
                ;}
    break;

  case 4:
#line 181 "parser.y"
    {
		  position_information *pos =
		    new position_information((yylsp[-1]).first_line,
					     (yylsp[-1]).first_column);
		  // We add the function id to the symbol table.
		  sym_index proc_loc = sym_tab->enter_procedure(pos,
								(yyvsp[0].pool_p));
		  // Open a new scope.
		  sym_tab->open_scope();
		  // This AST node is just a temporary node which we create
		  // here in order to be able to provide the symbol table
		  // index for the procedure to the proc_decl production
		  // above. It's needed for code generation.
		  (yyval.procedure_head) = new ast_procedurehead(pos,
					     proc_loc);;
                ;}
    break;

  case 10:
#line 212 "parser.y"
    {
                    /* Your code here */
		  
		  position_information *pos =
		    new position_information((yylsp[-3]).first_line,
					     (yylsp[-3]).first_column);
		  sym_tab->enter_constant(pos, (yyvsp[-3].pool_p), integer_type, (yyvsp[-1].integer)->value);
                ;}
    break;

  case 11:
#line 221 "parser.y"
    {
                    /* Your code here */
                
		  position_information *pos =
		    new position_information((yylsp[-3]).first_line,
					     (yylsp[-3]).first_column);
		  sym_tab->enter_constant(pos, (yyvsp[-3].pool_p), real_type, (yyvsp[-1].real)->value);
		;}
    break;

  case 12:
#line 230 "parser.y"
    {
                    // This isn't implemented in Diesel... Do nothing.
                ;}
    break;

  case 13:
#line 234 "parser.y"
    {

                    // This part of code is a bit ugly, but it's needed to
                    // allow constructions like this:
                    // constant foo = 5;
                    // constant bar = foo;
                    // ...now, why would anyone want to do that?
                    /* Your code here */
		  
		  position_information *pos =
		    new position_information((yylsp[-3]).first_line,
					     (yylsp[-3]).first_column);
		  symbol* sym  = sym_tab->get_symbol((yyvsp[-1].id)->sym_p);
		  if (sym == NULL || sym->tag != SYM_CONST) {
		    type_error(pos) << "bad index in const declaration: " << yytext << endl << flush;
		  }
		  else {
		    constant_symbol* con = sym->get_constant_symbol();
		    if(con->type == integer_type) 
		      sym_tab->enter_constant(pos, (yyvsp[-3].pool_p), con->type, con->const_value.ival);
		    
		    if(con->type == real_type) 
		      sym_tab->enter_constant(pos, (yyvsp[-3].pool_p), con->type, con->const_value.rval);
		  }
		;}
    break;

  case 14:
#line 260 "parser.y"
    {
		  yyerror("Can't assign constant, error in right-handside.");
		;}
    break;

  case 15:
#line 264 "parser.y"
    {
		  yyerror("Can't assign constant, missing semicolon.");
		;}
    break;

  case 16:
#line 268 "parser.y"
    {
		  yyerror("Can't assign constant, missing semicolon.");
		;}
    break;

  case 17:
#line 272 "parser.y"
    {
		  yyerror("Can't assign constant, missing semicolon.");
		;}
    break;

  case 22:
#line 289 "parser.y"
    {
		  /* Your code here */
		  
		  position_information *pos =
		    new position_information((yylsp[-3]).first_line,
					     (yylsp[-3]).first_column);
		  sym_tab->enter_variable(pos, (yyvsp[-3].pool_p), (yyvsp[-1].id)->sym_p);
		;}
    break;

  case 23:
#line 298 "parser.y"
    {
		  /* Your code here */
		  position_information *pos =
		    new position_information((yylsp[-8]).first_line,
                                                 (yylsp[-8]).first_column);
		  sym_tab->enter_array(pos,
				       (yyvsp[-8].pool_p),
				       (yyvsp[-1].id)->sym_p,
				       (yyvsp[-4].integer)->value);
		;}
    break;

  case 24:
#line 309 "parser.y"
    {
                    // We enter an array: pool_pointer, type pointer,
                    // the id type of the constant, and the value of the
                    // constant.
                    position_information *pos =
                        new position_information((yylsp[-8]).first_line,
                                                 (yylsp[-8]).first_column);

                    // Ideally we should be able to just enter the array and
                    // defer index type checking to the semantic phase.
                    // However, since a constant can represent a real value,
                    // and the enter_array() method only accepts integer
                    // values for cardinality, we have to prevent entering an
                    // array with a float index here, or the compiler would
                    // crash.
                    // However, to make the compiler install the array,
                    // so we won't get a ton of complaints about this array
                    // being undeclared later on, we cheat and install it
                     // anyway with an illegal cardinality - which we _can_
                    // defer checking until the semantic phase.

                    // Find the const_id's symbol in the symbol table.
                    symbol *tmp =
                        sym_tab->get_symbol((yyvsp[-4].id)->sym_p);

                    // Make sure it exists. This should belong in a later pass,
                    // but if we don't do it here and NULL is returned (which
                    // shouldn't happen if you've done everything right, but
                    // paranoia never hurts) the compiler would crash.
                    if(tmp == NULL || tmp->tag != SYM_CONST) {
                        type_error(pos) << "bad index in array declaration: "
                                        << yytext << endl << flush;
                    } else {
                        constant_symbol *con = tmp->get_constant_symbol();
                        if (con->type == integer_type) {
                            sym_tab->enter_array(pos,
                                                 (yyvsp[-8].pool_p),
                                                 (yyvsp[-1].id)->sym_p,
                                                 con->const_value.ival);
                        } else {
                            sym_tab->enter_array(pos,
                                                 (yyvsp[-8].pool_p),
                                                 (yyvsp[-1].id)->sym_p,
                                                 ILLEGAL_ARRAY_CARD);
                        }
                    }
                ;}
    break;

  case 29:
#line 371 "parser.y"
    {

                    symbol *env = sym_tab->get_symbol((yyvsp[-3].procedure_head)->sym_p);

                    if (typecheck) {
                        type_checker->do_typecheck(env, (yyvsp[-1].statement_list));
                    }

                    if (print_ast) {
                        cout << "\nUnoptimized AST for \""
                             << sym_tab->pool_lookup(env->id)
                             << "\"" << endl;
                        cout << (ast_stmt_list *)(yyvsp[-1].statement_list) << endl;
                    }

                    if (optimize) {
                        optimizer->do_optimize((yyvsp[-1].statement_list));
                        if (print_ast) {
                            cout << "\nOptimized AST for \""
                                 << sym_tab->pool_lookup(env->id)
                                 << "\"" << endl;
                            cout << (ast_stmt_list*)(yyvsp[-1].statement_list) << endl;
                        }
                    }

                    if (error_count == 0) {
                        if (quads) {
                            quad_list *q = (yyvsp[-3].procedure_head)->do_quads((yyvsp[-1].statement_list));
                            if (print_quads) {
                                cout << "\nQuad list for \""
                                     << sym_tab->pool_lookup(env->id)
                                     << "\"" << endl;
                                cout << (quad_list *)q << endl;
                            }

                            if (assembler) {
                                cout << "Generating assembler for procedure \""
                                     << sym_tab->pool_lookup(env->id)
                                     << "\"" << endl;
                                code_gen->generate_assembler(q, env);
                            }
                        }
                    }

                    // Close the current scope.
                    sym_tab->close_scope();
                ;}
    break;

  case 30:
#line 419 "parser.y"
    {

                    symbol *env = sym_tab->get_symbol((yyvsp[-3].function_head)->sym_p);

                    if (typecheck) {
                        type_checker->do_typecheck(env, (yyvsp[-1].statement_list));
                    }

                    if (print_ast) {
                        cout << "\nUnoptimized AST for \""
                             << sym_tab->pool_lookup(env->id)
                             << "\"" << endl;
                        cout << (ast_stmt_list *)(yyvsp[-1].statement_list) << endl;
                    }

                    if (optimize) {
                        optimizer->do_optimize((yyvsp[-1].statement_list));
                        if (print_ast) {
                            cout << "\nOptimized AST for \""
                                 << sym_tab->pool_lookup(env->id)
                                 << "\"" << endl;
                            cout << (ast_stmt_list *)(yyvsp[-1].statement_list) << endl;
                        }
                    }

                    if (error_count == 0) {
                        if (quads) {
                            quad_list *q = (yyvsp[-3].function_head)->do_quads((yyvsp[-1].statement_list));
                            if (print_quads) {
                                cout << "\nQuad list for \""
                                     << sym_tab->pool_lookup(env->id)
                                     << "\"" << endl;
                                cout << (quad_list *)q << endl;
                            }

                            if (assembler) {
                                cout << "Generating assembler for function \""
                                     << sym_tab->pool_lookup(env->id) << "\""
                                     << endl;
                                code_gen->generate_assembler(q, env);
                            }
                        }
                    }

                    // Close the current scope.
                    sym_tab->close_scope();
                ;}
    break;

  case 31:
#line 470 "parser.y"
    {
                    (yyval.procedure_head) = (yyvsp[-4].procedure_head);
                ;}
    break;

  case 32:
#line 477 "parser.y"
    {
                    /* Your code here */
		  sym_tab->set_symbol_type((yyvsp[-6].function_head)->sym_p, (yyvsp[-3].id)->sym_p);
		  (yyval.function_head) = (yyvsp[-6].function_head);
                ;}
    break;

  case 33:
#line 486 "parser.y"
    {
                    position_information *pos =
                        new position_information((yylsp[-1]).first_line,
                                                 (yylsp[-1]).first_column);
                    // We add the function id to the symbol table.
                    sym_index proc_loc = sym_tab->enter_procedure(pos,
                                                                  (yyvsp[0].pool_p));
                    // Open a new scope.
                    sym_tab->open_scope();
                    // This AST node is just a temporary node which we create
                    // here in order to be able to provide the symbol table
                    // index for the procedure to the proc_decl production
                    // above. It's needed for code generation.
                    (yyval.procedure_head) = new ast_procedurehead(pos,
                                               proc_loc);
                ;}
    break;

  case 34:
#line 506 "parser.y"
    {
                    position_information *pos =
                        new position_information((yylsp[-1]).first_line,
                                                 (yylsp[-1]).first_column);
                    // We add the function id to the symbol table.
                    sym_index func_loc = sym_tab->enter_function(pos,
                                                                 (yyvsp[0].pool_p));
                    // Open a new scope.
                    sym_tab->open_scope();

                    // This AST node is just a temporary node which we create
                    // here in order to be able to provide the symbol table
                    // index for the function to the func_decl production
                    // above. We need it to be able to set the return type
                    // and also later on for code generation.
                    (yyval.function_head) = new ast_functionhead(pos,
                                              func_loc);
                ;}
    break;

  case 35:
#line 528 "parser.y"
    {
                    /* Your code here */
		  (yyval.expression_list) = (yyvsp[-1].expression_list);
		;}
    break;

  case 36:
#line 533 "parser.y"
    {
		  yyerror("Error in parameters");
		  (yyval.expression_list) = NULL;
                ;}
    break;

  case 37:
#line 538 "parser.y"
    {
		  (yyval.expression_list) = NULL;
		;}
    break;

  case 38:
#line 545 "parser.y"
    {
                    /* Note that we use expr_lists for parameters. This
                       is thus simply a place-holder in the grammar. */
                ;}
    break;

  case 39:
#line 550 "parser.y"
    {
                ;}
    break;

  case 40:
#line 556 "parser.y"
    {
                    position_information *pos =
                        new position_information((yylsp[-2]).first_line,
                                                 (yylsp[-2]).first_column);

                    // Enter parameter into the symbol table. The linking of
                    // parameters and things is taken care of in the
                    // enter_parameter function, which is worth taking a
                    // second look at.
                    sym_index param_loc =
                        sym_tab->enter_parameter(pos,
                                                 (yyvsp[-2].pool_p),
                                                 (yyvsp[0].id)->sym_p);
                ;}
    break;

  case 41:
#line 574 "parser.y"
    {
                    /* Your code here */
		  (yyval.statement_list) = (yyvsp[-1].statement_list);
		
                ;}
    break;

  case 42:
#line 583 "parser.y"
    {
		  /* Your code here */
		  position_information *pos =
		    new position_information(
					     (yylsp[0]).first_line,
					     (yylsp[0]).first_column);
		  if ((yyvsp[0].statement) == NULL){
		    (yyval.statement_list) = NULL;
		  }
		  else{
		    (yyval.statement_list) = new ast_stmt_list(pos, (yyvsp[0].statement));
		  }
                ;}
    break;

  case 43:
#line 597 "parser.y"
    {
                    /* Your code here */
		  position_information *pos =
		    new position_information(
					     (yylsp[-2]).first_line,
					     (yylsp[-2]).first_column);
		  
		  if((yyvsp[0].statement) == NULL) {
		    (yyval.statement_list) = (yyvsp[-2].statement_list);
		  }
		  else{
		    (yyval.statement_list) = new ast_stmt_list(pos, (yyvsp[0].statement), (yyvsp[-2].statement_list));
		  }
                ;}
    break;

  case 44:
#line 615 "parser.y"
    {
                    /* Your code here */
		  position_information *pos =
		    new position_information((yylsp[-6]).first_line,
					     (yylsp[-6]).first_column);
		  (yyval.statement) = new ast_if(pos, (yyvsp[-5].expression), (yyvsp[-3].statement_list), (yyvsp[-2].elsif_list), (yyvsp[-1].statement_list));
		  
		;}
    break;

  case 45:
#line 624 "parser.y"
    {
		  yyerror("Error in if-condtion");
		  (yyval.statement) = NULL;
		;}
    break;

  case 46:
#line 629 "parser.y"
    {
                    /* Your code here */
		  position_information *pos =
		    new position_information((yylsp[-4]).first_line,
					     (yylsp[-4]).first_column);
		  (yyval.statement) = new ast_while(pos, (yyvsp[-3].expression), (yyvsp[-1].statement_list));
		
                ;}
    break;

  case 47:
#line 638 "parser.y"
    {
		  yyerror("Error in do-body");
		  (yyval.statement) = NULL;
		;}
    break;

  case 48:
#line 643 "parser.y"
    {
		  yyerror("Error in while-condition");
		  (yyval.statement) = NULL;
		;}
    break;

  case 49:
#line 648 "parser.y"
    {
		  yyerror("Error in while-condition and do-body");
		  (yyval.statement) = NULL;
		;}
    break;

  case 50:
#line 653 "parser.y"
    {
		  /* Your code here */
		  position_information *pos =
		    new position_information((yylsp[-3]).first_line,
					     (yylsp[-3]).first_column);
		  (yyval.statement) = new ast_procedurecall(pos, (yyvsp[-3].id), (yyvsp[-1].expression_list));
		
                ;}
    break;

  case 51:
#line 662 "parser.y"
    {
		  yyerror("Can't call procedure, error in arguments");
		  (yyval.statement) = NULL;
		;}
    break;

  case 52:
#line 667 "parser.y"
    {
                    /* Your code here */
		  position_information *pos =
		    new position_information((yylsp[-2]).first_line,
					     (yylsp[-2]).first_column);
		  (yyval.statement) = new ast_assign(pos, (yyvsp[-2].lvalue), (yyvsp[0].expression));
		
                ;}
    break;

  case 53:
#line 676 "parser.y"
    {
		  yyerror("Can't assign, error in right expression");
		  (yyval.statement) = NULL;
		;}
    break;

  case 54:
#line 681 "parser.y"
    {
		  /* Your code here */
		  position_information *pos =
		    new position_information((yylsp[-1]).first_line,
					     (yylsp[-1]).first_column);
		  (yyval.statement) = new ast_return(pos, (yyvsp[0].expression));
		
                ;}
    break;

  case 55:
#line 690 "parser.y"
    {
		  (yyval.statement) = NULL;
                ;}
    break;

  case 56:
#line 694 "parser.y"
    {
		  /* Your code here */
		  position_information *pos =
		    new position_information((yylsp[0]).first_line,
					     (yylsp[0]).first_column);
		  (yyval.statement) = new ast_return(pos); 
		
                ;}
    break;

  case 57:
#line 704 "parser.y"
    {
		  (yyval.statement) = NULL;
		  /* Your code here */
                ;}
    break;

  case 58:
#line 711 "parser.y"
    {
		  (yyval.lvalue) = (yyvsp[0].id);
                ;}
    break;

  case 59:
#line 715 "parser.y"
    {
                    (yyval.lvalue) = new ast_indexed((yyvsp[-3].id)->pos,
                                         (yyvsp[-3].id),
                                         (yyvsp[-1].expression));
                ;}
    break;

  case 60:
#line 721 "parser.y"
    {
		  yyerror("Error in index expression");
		  (yyval.lvalue) = NULL;
                ;}
    break;

  case 61:
#line 729 "parser.y"
    {
                    /* Your code here */
		  (yyval.expression) = (yyvsp[0].id);
                ;}
    break;

  case 62:
#line 734 "parser.y"
    {
                    /* Your code here */
		  (yyval.expression) = new ast_indexed((yyvsp[-3].id)->pos,
				       (yyvsp[-3].id),
				       (yyvsp[-1].expression));
		;}
    break;

  case 63:
#line 741 "parser.y"
    {
		  yyerror("Error in index expression");
		  (yyval.expression) = NULL;
                ;}
    break;

  case 64:
#line 749 "parser.y"
    {
                    /* Your code here */
		  position_information *pos =
		    new position_information((yylsp[-1]).first_line,
					     (yylsp[-1]).first_column);
		  (yyval.elsif_list) = new ast_elsif_list(pos, (yyvsp[0].elsif), (yyvsp[-1].elsif_list));
		
                ;}
    break;

  case 65:
#line 758 "parser.y"
    {
		  (yyval.elsif_list) = NULL;
                ;}
    break;

  case 66:
#line 765 "parser.y"
    {
                    /* Your code here */
		  position_information *pos =
		    new position_information((yylsp[-3]).first_line,
					     (yylsp[-3]).first_column);
		  (yyval.elsif) = new ast_elsif(pos, (yyvsp[-2].expression), (yyvsp[0].statement_list));
		
                ;}
    break;

  case 67:
#line 777 "parser.y"
    {
                    /* Your code here */
		  (yyval.statement_list) = (yyvsp[0].statement_list);
		;}
    break;

  case 68:
#line 782 "parser.y"
    {
		  (yyval.statement_list) = NULL;
		;}
    break;

  case 69:
#line 789 "parser.y"
    {
                    /* Your code here */
		  (yyval.expression_list) = (yyvsp[0].expression_list);
                ;}
    break;

  case 70:
#line 794 "parser.y"
    {
		  (yyval.expression_list) = NULL;
		;}
    break;

  case 71:
#line 801 "parser.y"
    {
                    /* Your code here */
		  position_information *pos =
		    new position_information((yylsp[0]).first_line,
					     (yylsp[0]).first_column);
		  (yyval.expression_list) = new ast_expr_list(pos, (yyvsp[0].expression));
                
		;}
    break;

  case 72:
#line 810 "parser.y"
    {
                    /* Your code here */
		  position_information *pos =
		    new position_information((yylsp[-2]).first_line,
					     (yylsp[-2]).first_column);
		  (yyval.expression_list) = new ast_expr_list(pos, (yyvsp[0].expression), (yyvsp[-2].expression_list));
                
		;}
    break;

  case 73:
#line 822 "parser.y"
    {
                    /* Your code here */
		  (yyval.expression) = (yyvsp[0].expression);
		;}
    break;

  case 74:
#line 827 "parser.y"
    {
                    /* Your code here */
		  position_information *pos =
		    new position_information((yylsp[-2]).first_line,
					     (yylsp[-2]).first_column);
		  (yyval.expression) = new ast_equal(pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                
		;}
    break;

  case 75:
#line 836 "parser.y"
    {
                    /* Your code here */
                position_information *pos =
		    new position_information((yylsp[-2]).first_line,
					     (yylsp[-2]).first_column);
		(yyval.expression) = new ast_notequal(pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                
		;}
    break;

  case 76:
#line 845 "parser.y"
    {
                    /* Your code here */
                position_information *pos =
		    new position_information((yylsp[-2]).first_line,
					     (yylsp[-2]).first_column);
		(yyval.expression) = new ast_lessthan(pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                
		;}
    break;

  case 77:
#line 854 "parser.y"
    {
                    /* Your code here */
                position_information *pos =
		    new position_information((yylsp[-2]).first_line,
					     (yylsp[-2]).first_column);
		(yyval.expression) = new ast_greaterthan(pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                
		;}
    break;

  case 78:
#line 866 "parser.y"
    {
                    /* Your code here */
		  (yyval.expression) = (yyvsp[0].expression);
		;}
    break;

  case 79:
#line 871 "parser.y"
    {
                    /* Your code here */
                  /*position_information *pos =
		    new position_information(@1.first_line,
					     @1.first_column);
		  $$ = new ast_add(pos, $1, $3);
		  */
		  (yyval.expression) = (yyvsp[0].expression);
		;}
    break;

  case 80:
#line 881 "parser.y"
    {
                    /* Your code here */
                  position_information *pos =
		    new position_information((yylsp[-1]).first_line,
					     (yylsp[-1]).first_column);
		  (yyval.expression) = new ast_uminus(pos, (yyvsp[0].expression));
                
	;}
    break;

  case 81:
#line 890 "parser.y"
    {
                    /* Your code here */
                  position_information *pos =
		    new position_information((yylsp[-2]).first_line,
					     (yylsp[-2]).first_column);
		  (yyval.expression) = new ast_or(pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                
		;}
    break;

  case 82:
#line 899 "parser.y"
    {
                    /* Your code here */
                  position_information *pos =
		    new position_information((yylsp[-2]).first_line,
					     (yylsp[-2]).first_column);
		  (yyval.expression) = new ast_add(pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                
		;}
    break;

  case 83:
#line 908 "parser.y"
    {
                    /* Your code here */
		  position_information *pos =
		    new position_information((yylsp[-2]).first_line,
					     (yylsp[-2]).first_column);
		  (yyval.expression) = new ast_sub(pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                  
		;}
    break;

  case 84:
#line 920 "parser.y"
    {
		  
		  /* Your code here */
		  (yyval.expression) = (yyvsp[0].expression);
                ;}
    break;

  case 85:
#line 926 "parser.y"
    {
		  /* Your code here */
		  
		  position_information *pos =
		    new position_information((yylsp[-2]).first_line,
					     (yylsp[-2]).first_column);
		  (yyval.expression) = new ast_and(pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                ;}
    break;

  case 86:
#line 935 "parser.y"
    {
                    /* Your code here */

		  position_information *pos =
		    new position_information((yylsp[-2]).first_line,
					     (yylsp[-2]).first_column);
		  (yyval.expression) = new ast_mult(pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                ;}
    break;

  case 87:
#line 944 "parser.y"
    {
                    /* Your code here */

		  position_information *pos =
		    new position_information((yylsp[-2]).first_line,
					     (yylsp[-2]).first_column);
		  (yyval.expression) = new ast_divide(pos, (yyvsp[-2].expression), (yyvsp[0].expression));
                ;}
    break;

  case 88:
#line 953 "parser.y"
    {
                    /* Your code here */
		  position_information *pos =
		    new position_information((yylsp[-2]).first_line,
					     (yylsp[-2]).first_column);
		  (yyval.expression) = new ast_idiv(pos, (yyvsp[-2].expression), (yyvsp[0].expression)); 
                ;}
    break;

  case 89:
#line 961 "parser.y"
    {
                    /* Your code here */
		  position_information *pos =
		    new position_information((yylsp[-2]).first_line,
					     (yylsp[-2]).first_column);
		  (yyval.expression) = new ast_mod(pos, (yyvsp[-2].expression), (yyvsp[0].expression)); 
                ;}
    break;

  case 90:
#line 972 "parser.y"
    {
		  (yyval.expression) = (yyvsp[0].expression);
                ;}
    break;

  case 91:
#line 976 "parser.y"
    {
		  (yyval.expression) = (yyvsp[0].function_call);
                ;}
    break;

  case 92:
#line 980 "parser.y"
    {
                    (yyval.expression) = (yyvsp[0].integer);
                ;}
    break;

  case 93:
#line 984 "parser.y"
    {
                    (yyval.expression) = (yyvsp[0].real);
                ;}
    break;

  case 94:
#line 988 "parser.y"
    {
		  position_information *pos =
		    new position_information((yylsp[-1]).first_line,
					     (yylsp[-1]).first_column);
		  (yyval.expression) = new ast_not(pos, (yyvsp[0].expression));
                    /* Your code here */
                ;}
    break;

  case 95:
#line 996 "parser.y"
    {
                    /* Your code here */
		  (yyval.expression) = (yyvsp[-1].expression);
		;}
    break;

  case 96:
#line 1005 "parser.y"
    {
		  /* Your code here */
		  position_information *pos =
		    new position_information((yylsp[-3]).first_line,
					     (yylsp[-3]).first_column);
		  (yyval.function_call) = new ast_functioncall(pos, 
					    (yyvsp[-3].id), 
					    (yyvsp[-1].expression_list));		  
		;}
    break;

  case 98:
#line 1020 "parser.y"
    {
                    position_information *pos =
                        new position_information((yylsp[0]).first_line,
                                                 (yylsp[0]).first_column);

                    // We need to pass on the value AND the position here.
                    (yyval.integer) = new ast_integer(pos,
                                         (yyvsp[0].ival));
                ;}
    break;

  case 99:
#line 1033 "parser.y"
    {
                    position_information *pos =
                        new position_information((yylsp[0]).first_line,
                                                 (yylsp[0]).first_column);

                    // We create a new real constant.
                    (yyval.real) = new ast_real(pos,
                                      (yyvsp[0].rval));
                ;}
    break;

  case 100:
#line 1046 "parser.y"
    {
                    // Make sure this id is really declared as a type.
                    // debug() << "type_id -> id: "
                    //       << sym_tab->get_symbol($1->sym_p) << endl;
                    if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_NAMETYPE) {
                        type_error((yyvsp[0].id)->pos) << "not declared "
                                            << "as type: "
                                            << yytext << endl << flush;
                    }
                    (yyval.id) = (yyvsp[0].id);
                ;}
    break;

  case 101:
#line 1061 "parser.y"
    {
                    // Make sure this id is really declared as a constant.
                    // debug() << "const_id -> id: " << $1->sym_p << endl;
                    if(sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_CONST) {
                        type_error((yyvsp[0].id)->pos) << "not declared "
                                            << "as constant: "
                                            << yytext << flush;
                    }
                    (yyval.id) = (yyvsp[0].id);
                ;}
    break;

  case 102:
#line 1075 "parser.y"
    {
                    // Make sure this id is really declared as an lvariable.
                    // debug() << "lvar_id -> id: " << $1->sym_p << endl;
                    if (sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_VAR &&
                       sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_PARAM) {
                        type_error((yyvsp[0].id)->pos) << "not declared "
                                            << "as variable or parameter: "
                                            << yytext << endl << flush;
                    }
                    (yyval.id) = (yyvsp[0].id);
                ;}
    break;

  case 103:
#line 1088 "parser.y"
    {
                    // Make sure this id is really declared as an rvariable.
                    // debug() << "rvar_id -> id: " << $1->sym_p << endl;
                    if (sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_VAR &&
                       sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_PARAM &&
                       sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_CONST) {
                        type_error((yyvsp[0].id)->pos) << "not declared "
                                            << "as variable, parameter or "
                                            << "constant: "
                                            << yytext << endl << flush;
                    }
                    (yyval.id) = (yyvsp[0].id);
                ;}
    break;

  case 104:
#line 1105 "parser.y"
    {
                    // Make sure this id is really declared as a procedure.
                    // debug() << "proc_id -> id: " << $1->sym_p << endl;
                    if (sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_PROC) {
                        type_error((yyvsp[0].id)->pos) << "not declared "
                                            << "as procedure: "
                                            << yytext << endl << flush;
                    }
                    (yyval.id) = (yyvsp[0].id);
                ;}
    break;

  case 105:
#line 1119 "parser.y"
    {
		  // Make sure this id is really declared as a function.
		  // debug() << "func_id -> id: " << $1->sym_p << endl;
		  if (sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_FUNC) {
                        type_error((yyvsp[0].id)->pos) << "not declared "
                                            << "as function: "
                                            << yytext << endl << flush;
                    }
                    (yyval.id) = (yyvsp[0].id);
                ;}
    break;

  case 106:
#line 1133 "parser.y"
    {
                    // Make sure this id is really declared as an array.
                    // debug() << "array_id -> id: " << $1->sym_p << endl;
                    if (sym_tab->get_symbol_tag((yyvsp[0].id)->sym_p) != SYM_ARRAY) {
                        type_error((yyvsp[0].id)->pos) << "not declared "
                                            << "as array: "
                                            << yytext << endl << flush;
                    }
                    (yyval.id) = (yyvsp[0].id);
                ;}
    break;

  case 107:
#line 1147 "parser.y"
    {
		  
                    sym_index sym_p;    // Used to find previous use of symbol.
                    position_information *pos =
                        new position_information((yylsp[0]).first_line,
                                                 (yylsp[0]).first_column);

                    // Make sure the symbol was declared before it is used.
                    sym_p = sym_tab->lookup_symbol((yyvsp[0].pool_p));
		 
		    // debug() << "id -> T_IDENT: " << sym_p << " "
                    //            << sym_tab->pool_lookup($1) << endl;
                    if (sym_p == NULL_SYM) {
                        type_error(pos) << "not declared: "
                                        << yytext << endl << flush;
                    }
                    // Create a new ast_id node with pos, symptr.
                    (yyval.id) = new ast_id(pos,
                                    sym_p);
                    (yyval.id)->type = sym_tab->get_symbol_type(sym_p);
                ;}
    break;


    }

/* Line 1037 of yacc.c.  */
#line 2610 "parser.cc"

  yyvsp -= yylen;
  yyssp -= yylen;
  yylsp -= yylen;

  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {
                 yyerror_range[0] = *yylsp;
		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 yydestruct ("Error: popping",
                             yystos[*yyssp], yyvsp, yylsp);
	       }
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval, &yylloc);
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

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

  yyerror_range[0] = yylsp[1-yylen];
  yylsp -= yylen;
  yyvsp -= yylen;
  yyssp -= yylen;
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping", yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though. */
  YYLLOC_DEFAULT (yyloc, yyerror_range - 1, 2);
  *++yylsp = yyloc;

  /* Shift the error token. */
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
  yydestruct ("Error: discarding lookahead",
              yytoken, &yylval, &yylloc);
  yychar = YYEMPTY;
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 1171 "parser.y"


