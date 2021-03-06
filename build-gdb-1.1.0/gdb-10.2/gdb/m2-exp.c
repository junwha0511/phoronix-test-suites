/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 38 "m2-exp.y"


#include "defs.h"
#include "expression.h"
#include "language.h"
#include "value.h"
#include "parser-defs.h"
#include "m2-lang.h"
#include "bfd.h" /* Required by objfiles.h.  */
#include "symfile.h" /* Required by objfiles.h.  */
#include "objfiles.h" /* For have_full_symbols and have_partial_symbols */
#include "block.h"

#define parse_type(ps) builtin_type (ps->gdbarch ())
#define parse_m2_type(ps) builtin_m2_type (ps->gdbarch ())

/* Remap normal yacc parser interface names (yyparse, yylex, yyerror,
   etc).  */
#define GDB_YY_REMAP_PREFIX m2_
#include "yy-remap.h"

/* The state of the parser, used internally when we are parsing the
   expression.  */

static struct parser_state *pstate = NULL;

int yyparse (void);

static int yylex (void);

static void yyerror (const char *);

static int parse_number (int);

/* The sign of the number being parsed.  */
static int number_sign = 1;


#line 109 "m2-exp.c.tmp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTRPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTRPTR nullptr
#   else
#    define YY_NULLPTRPTR 0
#   endif
#  else
#   define YY_NULLPTRPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


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
    INT = 258,
    HEX = 259,
    ERROR = 260,
    UINT = 261,
    M2_TRUE = 262,
    M2_FALSE = 263,
    CHAR = 264,
    FLOAT = 265,
    STRING = 266,
    NAME = 267,
    BLOCKNAME = 268,
    IDENT = 269,
    VARNAME = 270,
    TYPENAME = 271,
    SIZE = 272,
    CAP = 273,
    ORD = 274,
    HIGH = 275,
    ABS = 276,
    MIN_FUNC = 277,
    MAX_FUNC = 278,
    FLOAT_FUNC = 279,
    VAL = 280,
    CHR = 281,
    ODD = 282,
    TRUNC = 283,
    TSIZE = 284,
    INC = 285,
    DEC = 286,
    INCL = 287,
    EXCL = 288,
    COLONCOLON = 289,
    DOLLAR_VARIABLE = 290,
    ABOVE_COMMA = 291,
    ASSIGN = 292,
    LEQ = 293,
    GEQ = 294,
    NOTEQUAL = 295,
    IN = 296,
    OROR = 297,
    LOGICAL_AND = 298,
    DIV = 299,
    MOD = 300,
    UNARY = 301,
    DOT = 302,
    NOT = 303,
    QID = 304
  };
#endif
/* Tokens.  */
#define INT 258
#define HEX 259
#define ERROR 260
#define UINT 261
#define M2_TRUE 262
#define M2_FALSE 263
#define CHAR 264
#define FLOAT 265
#define STRING 266
#define NAME 267
#define BLOCKNAME 268
#define IDENT 269
#define VARNAME 270
#define TYPENAME 271
#define SIZE 272
#define CAP 273
#define ORD 274
#define HIGH 275
#define ABS 276
#define MIN_FUNC 277
#define MAX_FUNC 278
#define FLOAT_FUNC 279
#define VAL 280
#define CHR 281
#define ODD 282
#define TRUNC 283
#define TSIZE 284
#define INC 285
#define DEC 286
#define INCL 287
#define EXCL 288
#define COLONCOLON 289
#define DOLLAR_VARIABLE 290
#define ABOVE_COMMA 291
#define ASSIGN 292
#define LEQ 293
#define GEQ 294
#define NOTEQUAL 295
#define IN 296
#define OROR 297
#define LOGICAL_AND 298
#define DIV 299
#define MOD 300
#define UNARY 301
#define DOT 302
#define NOT 303
#define QID 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 82 "m2-exp.y"

    LONGEST lval;
    ULONGEST ulval;
    gdb_byte val[16];
    struct symbol *sym;
    struct type *tval;
    struct stoken sval;
    int voidval;
    const struct block *bval;
    enum exp_opcode opcode;
    struct internalvar *ivar;

    struct type **tvec;
    int *ivec;
  

#line 273 "m2-exp.c.tmp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or xmalloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
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
       && ! ((defined YYMALLOC || defined xmalloc) \
             && (defined YYFREE || defined xfree)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC xmalloc
#   if ! defined xmalloc && ! defined EXIT_SUCCESS
void *xmalloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE xfree
#   if ! defined xfree && ! defined EXIT_SUCCESS
void xfree (void *); /* INFRINGES ON USER NAME SPACE */
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   890

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

#define YYUNDEFTOK  2
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    45,     2,     2,    49,     2,
      61,    65,    53,    51,    36,    52,     2,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    43,    40,     2,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    68,    58,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,     2,    67,    63,     2,     2,     2,
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
      35,    37,    38,    41,    42,    44,    46,    47,    48,    55,
      56,    57,    59,    62,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   151,   151,   152,   155,   164,   169,   168,   175,   179,
     183,   184,   187,   191,   195,   199,   203,   209,   215,   219,
     225,   229,   233,   237,   241,   246,   250,   257,   261,   268,
     274,   277,   281,   285,   289,   291,   301,   297,   315,   312,
     323,   326,   330,   335,   340,   345,   351,   357,   365,   369,
     373,   377,   381,   385,   389,   393,   397,   399,   403,   407,
     411,   415,   419,   423,   427,   434,   440,   446,   454,   465,
     475,   484,   487,   496,   503,   507,   517,   529,   537,   541,
     559,   598
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "HEX", "ERROR", "UINT", "M2_TRUE",
  "M2_FALSE", "CHAR", "FLOAT", "STRING", "NAME", "BLOCKNAME", "IDENT",
  "VARNAME", "TYPENAME", "SIZE", "CAP", "ORD", "HIGH", "ABS", "MIN_FUNC",
  "MAX_FUNC", "FLOAT_FUNC", "VAL", "CHR", "ODD", "TRUNC", "TSIZE", "INC",
  "DEC", "INCL", "EXCL", "COLONCOLON", "DOLLAR_VARIABLE", "','",
  "ABOVE_COMMA", "ASSIGN", "'<'", "'>'", "LEQ", "GEQ", "'='", "NOTEQUAL",
  "'#'", "IN", "OROR", "LOGICAL_AND", "'&'", "'@'", "'+'", "'-'", "'*'",
  "'/'", "DIV", "MOD", "UNARY", "'^'", "DOT", "'['", "'('", "NOT", "'~'",
  "QID", "')'", "'{'", "'}'", "']'", "$accept", "start", "type_exp", "exp",
  "$@1", "not_exp", "set", "$@2", "$@3", "arglist", "non_empty_arglist",
  "block", "fblock", "variable", "type", YY_NULLPTRPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    44,   291,   292,    60,
      62,   293,   294,    61,   295,    35,   296,   297,   298,    38,
      64,    43,    45,    42,    47,   299,   300,   301,    94,   302,
      91,    40,   303,   126,   304,    41,   123,   125,    93
};
# endif

#define YYPACT_NINF (-89)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-75)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     161,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   222,   -55,   -53,   -28,   -22,   -18,     2,     8,    17,
      28,    29,    30,    31,    32,    34,    35,    36,   -89,   161,
     -89,   161,   -89,   -89,   161,    46,   -89,   805,   161,   -89,
      -6,    -4,   -89,   -21,   161,     7,   -21,   161,   161,   161,
     161,    83,    83,   161,    83,   161,   161,   161,   161,   161,
     161,   161,   161,     7,   161,   307,   805,   -32,   -42,   -89,
     161,   161,   161,   161,   161,   161,   161,   161,   -15,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   -89,    88,
     -89,   -89,     7,    14,   161,   161,   -24,   335,   363,   391,
     419,    37,    38,   447,    65,   475,   503,   531,   559,   251,
     279,   755,   781,     7,   -89,   161,   -89,   161,   829,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   161,   -89,    41,    68,
      90,   146,   205,   205,     7,     7,     7,     7,   -89,   161,
     161,   -89,   -89,   587,   -31,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   161,   -89,   -89,   -89,   -89,   161,   -89,
     161,   -89,   161,   161,   805,     7,   805,   -34,   -33,   -89,
     -89,   615,   643,   671,   699,   727,   161,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   805
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    67,    68,    65,    66,    69,    70,    73,    80,    75,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
       6,     0,    10,    11,    40,     0,     3,     2,     0,    30,
       0,    77,    71,     4,     0,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     0,    41,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     0,
      36,    38,     9,     0,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,    47,     0,    34,     0,    64,    60,
      61,    58,    59,    55,    56,    57,    40,    31,     0,    63,
      62,    48,    53,    54,    49,    50,    51,    52,    29,     0,
      40,    79,    76,     0,     0,    72,    12,    13,    15,    14,
      16,    17,    18,     0,    20,    21,    22,    23,     0,    25,
       0,    27,     0,     0,    42,    45,    43,     0,     0,    46,
      35,     0,     0,     0,     0,     0,     0,    37,    39,    19,
      26,    28,    32,    33,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,   -89,     0,   -89,   -89,    26,   -89,   -89,   -88,
     -89,   -89,   -89,   -89,    54
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    35,    36,    66,    64,    38,    39,   139,   140,    67,
     167,    40,    41,    42,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    10,   176,   115,   115,   115,    47,   144,    48,    79,
      80,    45,    81,    82,    83,    84,    85,    86,    87,    94,
      88,    89,    90,    91,    95,   117,   141,   142,    93,    63,
     -74,    65,   178,    49,   177,   116,   170,    94,    92,    50,
      94,   145,    95,    51,    65,    95,    69,    97,    98,    99,
     100,   126,   168,   103,    43,   105,   106,   107,   108,   109,
     110,   111,   112,    52,   113,    88,    89,    90,    91,    53,
     118,   119,   120,   121,   122,   123,   124,   125,    54,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    68,    55,
      56,    57,    58,    59,   143,    60,    61,    62,    96,    10,
     138,   153,   150,   151,   127,   101,   102,    95,   104,     0,
       0,     0,     0,     0,     0,   164,    80,   165,    81,    82,
      83,    84,    85,    86,    87,     0,    88,    89,    90,    91,
       0,     0,   128,     0,     0,     0,     0,     0,     0,   166,
      81,    82,    83,    84,    85,    86,    87,     0,    88,    89,
      90,    91,     0,   171,     0,     0,     0,     0,   172,     0,
     173,     0,   174,   175,     1,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,     0,   184,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    82,    83,    84,
      85,    86,    87,     0,    88,    89,    90,    91,     0,     0,
       0,     0,    29,    30,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,    33,     1,     0,    34,     2,     3,
       4,     5,     6,     7,     8,     9,     0,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    84,    85,
      86,    87,     0,    88,    89,    90,    91,     0,     0,     0,
       0,     0,     0,    29,    30,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    32,    33,     0,   158,    34,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
       0,    81,    82,    83,    84,    85,    86,    87,     0,    88,
      89,    90,    91,     0,     0,   160,   159,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     0,    81,
      82,    83,    84,    85,    86,    87,     0,    88,    89,    90,
      91,     0,     0,     0,   161,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,     0,    81,    82,    83,
      84,    85,    86,    87,     0,    88,    89,    90,    91,     0,
       0,     0,   114,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     0,    81,    82,    83,    84,    85,
      86,    87,     0,    88,    89,    90,    91,     0,     0,     0,
     146,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,     0,    81,    82,    83,    84,    85,    86,    87,
       0,    88,    89,    90,    91,     0,     0,     0,   147,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
       0,    81,    82,    83,    84,    85,    86,    87,     0,    88,
      89,    90,    91,     0,     0,     0,   148,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     0,    81,
      82,    83,    84,    85,    86,    87,     0,    88,    89,    90,
      91,     0,     0,     0,   149,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,     0,    81,    82,    83,
      84,    85,    86,    87,     0,    88,    89,    90,    91,     0,
       0,     0,   152,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     0,    81,    82,    83,    84,    85,
      86,    87,     0,    88,    89,    90,    91,     0,     0,     0,
     154,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,     0,    81,    82,    83,    84,    85,    86,    87,
       0,    88,    89,    90,    91,     0,     0,     0,   155,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
       0,    81,    82,    83,    84,    85,    86,    87,     0,    88,
      89,    90,    91,     0,     0,     0,   156,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     0,    81,
      82,    83,    84,    85,    86,    87,     0,    88,    89,    90,
      91,     0,     0,     0,   157,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,     0,    81,    82,    83,
      84,    85,    86,    87,     0,    88,    89,    90,    91,     0,
       0,     0,   169,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     0,    81,    82,    83,    84,    85,
      86,    87,     0,    88,    89,    90,    91,     0,     0,     0,
     179,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,     0,    81,    82,    83,    84,    85,    86,    87,
       0,    88,    89,    90,    91,     0,     0,     0,   180,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
       0,    81,    82,    83,    84,    85,    86,    87,     0,    88,
      89,    90,    91,     0,     0,     0,   181,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     0,    81,
      82,    83,    84,    85,    86,    87,     0,    88,    89,    90,
      91,     0,     0,     0,   182,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,     0,    81,    82,    83,
      84,    85,    86,    87,     0,    88,    89,    90,    91,     0,
       0,   162,   183,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     0,    81,    82,    83,    84,    85,
      86,    87,     0,    88,    89,    90,    91,   163,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
       0,    81,    82,    83,    84,    85,    86,    87,     0,    88,
      89,    90,    91,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     0,    81,    82,    83,    84,    85,
      86,    87,     0,    88,    89,    90,    91,   -75,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     0,    81,
      82,    83,    84,    85,    86,    87,     0,    88,    89,    90,
      91
};

static const yytype_int16 yycheck[] =
{
       0,    16,    36,    36,    36,    36,    61,    95,    61,    47,
      48,    11,    50,    51,    52,    53,    54,    55,    56,    61,
      58,    59,    60,    61,    66,    67,    12,    13,    34,    29,
      34,    31,    65,    61,    68,    67,    67,    61,    38,    61,
      61,    65,    66,    61,    44,    66,     0,    47,    48,    49,
      50,    66,   140,    53,     0,    55,    56,    57,    58,    59,
      60,    61,    62,    61,    64,    58,    59,    60,    61,    61,
      70,    71,    72,    73,    74,    75,    76,    77,    61,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    34,    61,
      61,    61,    61,    61,    94,    61,    61,    61,    44,    16,
      12,    36,    65,    65,    78,    51,    52,    66,    54,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    48,   117,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    60,    61,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      50,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      60,    61,    -1,   153,    -1,    -1,    -1,    -1,   158,    -1,
     160,    -1,   162,   163,     3,    -1,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,   176,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    51,    52,    53,
      54,    55,    56,    -1,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,     3,    -1,    66,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    53,    54,
      55,    56,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    -1,    36,    66,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    -1,    -1,    36,    65,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    65,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    65,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      65,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    65,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    65,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    65,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    65,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      65,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    65,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    65,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    65,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    65,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      65,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    65,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    65,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    65,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    61,    -1,
      -1,    36,    65,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    61,    36,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    61,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     6,     7,     8,     9,    10,    11,    12,    13,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    35,    51,
      52,    61,    62,    63,    66,    70,    71,    72,    74,    75,
      80,    81,    82,    83,    61,    72,    83,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    72,    73,    72,    72,    78,    83,     0,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    50,    51,    52,    53,    54,    55,    56,    58,    59,
      60,    61,    72,    34,    61,    66,    83,    72,    72,    72,
      72,    83,    83,    72,    83,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    65,    36,    67,    67,    72,    72,
      72,    72,    72,    72,    72,    72,    66,    75,    83,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    12,    76,
      77,    12,    13,    72,    78,    65,    65,    65,    65,    65,
      65,    65,    65,    36,    65,    65,    65,    65,    36,    65,
      36,    65,    36,    36,    72,    72,    72,    79,    78,    65,
      67,    72,    72,    72,    72,    72,    36,    68,    65,    65,
      65,    65,    65,    65,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    69,    70,    70,    71,    72,    73,    72,    72,    72,
      74,    74,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    75,    75,    76,    72,    77,    72,
      78,    78,    78,    79,    79,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    80,    81,    81,    82,    82,    82,
      82,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     0,     3,     2,     2,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     2,     4,     6,     4,     6,     3,
       1,     3,     6,     6,     3,     4,     0,     5,     0,     5,
       0,     1,     3,     1,     3,     4,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     1,     3,     1,     1,     3,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTRPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTRPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTRPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to xreallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to xreallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 156 "m2-exp.y"
                { write_exp_elt_opcode (pstate, OP_TYPE);
		  write_exp_elt_type (pstate, (yyvsp[0].tval));
		  write_exp_elt_opcode (pstate, OP_TYPE);
		}
#line 1716 "m2-exp.c.tmp"
    break;

  case 5:
#line 165 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_IND); }
#line 1722 "m2-exp.c.tmp"
    break;

  case 6:
#line 169 "m2-exp.y"
                        { number_sign = -1; }
#line 1728 "m2-exp.c.tmp"
    break;

  case 7:
#line 171 "m2-exp.y"
                        { number_sign = 1;
			  write_exp_elt_opcode (pstate, UNOP_NEG); }
#line 1735 "m2-exp.c.tmp"
    break;

  case 8:
#line 176 "m2-exp.y"
                { write_exp_elt_opcode (pstate, UNOP_PLUS); }
#line 1741 "m2-exp.c.tmp"
    break;

  case 9:
#line 180 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_LOGICAL_NOT); }
#line 1747 "m2-exp.c.tmp"
    break;

  case 12:
#line 188 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_CAP); }
#line 1753 "m2-exp.c.tmp"
    break;

  case 13:
#line 192 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_ORD); }
#line 1759 "m2-exp.c.tmp"
    break;

  case 14:
#line 196 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_ABS); }
#line 1765 "m2-exp.c.tmp"
    break;

  case 15:
#line 200 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_HIGH); }
#line 1771 "m2-exp.c.tmp"
    break;

  case 16:
#line 204 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_MIN);
			  write_exp_elt_type (pstate, (yyvsp[-1].tval));
			  write_exp_elt_opcode (pstate, UNOP_MIN); }
#line 1779 "m2-exp.c.tmp"
    break;

  case 17:
#line 210 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_MAX);
			  write_exp_elt_type (pstate, (yyvsp[-1].tval));
			  write_exp_elt_opcode (pstate, UNOP_MAX); }
#line 1787 "m2-exp.c.tmp"
    break;

  case 18:
#line 216 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_FLOAT); }
#line 1793 "m2-exp.c.tmp"
    break;

  case 19:
#line 220 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_VAL);
			  write_exp_elt_type (pstate, (yyvsp[-3].tval));
			  write_exp_elt_opcode (pstate, BINOP_VAL); }
#line 1801 "m2-exp.c.tmp"
    break;

  case 20:
#line 226 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_CHR); }
#line 1807 "m2-exp.c.tmp"
    break;

  case 21:
#line 230 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_ODD); }
#line 1813 "m2-exp.c.tmp"
    break;

  case 22:
#line 234 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_TRUNC); }
#line 1819 "m2-exp.c.tmp"
    break;

  case 23:
#line 238 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_SIZEOF); }
#line 1825 "m2-exp.c.tmp"
    break;

  case 24:
#line 242 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_SIZEOF); }
#line 1831 "m2-exp.c.tmp"
    break;

  case 25:
#line 247 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_PREINCREMENT); }
#line 1837 "m2-exp.c.tmp"
    break;

  case 26:
#line 251 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_ASSIGN_MODIFY);
			  write_exp_elt_opcode (pstate, BINOP_ADD);
			  write_exp_elt_opcode (pstate,
						BINOP_ASSIGN_MODIFY); }
#line 1846 "m2-exp.c.tmp"
    break;

  case 27:
#line 258 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_PREDECREMENT);}
#line 1852 "m2-exp.c.tmp"
    break;

  case 28:
#line 262 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_ASSIGN_MODIFY);
			  write_exp_elt_opcode (pstate, BINOP_SUB);
			  write_exp_elt_opcode (pstate,
						BINOP_ASSIGN_MODIFY); }
#line 1861 "m2-exp.c.tmp"
    break;

  case 29:
#line 269 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, STRUCTOP_STRUCT);
			  write_exp_string (pstate, (yyvsp[0].sval));
			  write_exp_elt_opcode (pstate, STRUCTOP_STRUCT); }
#line 1869 "m2-exp.c.tmp"
    break;

  case 31:
#line 278 "m2-exp.y"
                        { error (_("Sets are not implemented."));}
#line 1875 "m2-exp.c.tmp"
    break;

  case 32:
#line 282 "m2-exp.y"
                        { error (_("Sets are not implemented."));}
#line 1881 "m2-exp.c.tmp"
    break;

  case 33:
#line 286 "m2-exp.y"
                        { error (_("Sets are not implemented."));}
#line 1887 "m2-exp.c.tmp"
    break;

  case 34:
#line 290 "m2-exp.y"
                        { error (_("Sets are not implemented."));}
#line 1893 "m2-exp.c.tmp"
    break;

  case 35:
#line 292 "m2-exp.y"
                        { error (_("Sets are not implemented."));}
#line 1899 "m2-exp.c.tmp"
    break;

  case 36:
#line 301 "m2-exp.y"
                        { pstate->start_arglist(); }
#line 1905 "m2-exp.c.tmp"
    break;

  case 37:
#line 303 "m2-exp.y"
                        {
			  gdb_assert (pstate->arglist_len > 0);
			  write_exp_elt_opcode (pstate, MULTI_SUBSCRIPT);
			  write_exp_elt_longcst (pstate,
						 pstate->end_arglist());
			  write_exp_elt_opcode (pstate, MULTI_SUBSCRIPT);
			}
#line 1917 "m2-exp.c.tmp"
    break;

  case 38:
#line 315 "m2-exp.y"
                        { pstate->start_arglist (); }
#line 1923 "m2-exp.c.tmp"
    break;

  case 39:
#line 317 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, OP_FUNCALL);
			  write_exp_elt_longcst (pstate,
						 pstate->end_arglist ());
			  write_exp_elt_opcode (pstate, OP_FUNCALL); }
#line 1932 "m2-exp.c.tmp"
    break;

  case 41:
#line 327 "m2-exp.y"
                        { pstate->arglist_len = 1; }
#line 1938 "m2-exp.c.tmp"
    break;

  case 42:
#line 331 "m2-exp.y"
                        { pstate->arglist_len++; }
#line 1944 "m2-exp.c.tmp"
    break;

  case 43:
#line 336 "m2-exp.y"
                        { pstate->arglist_len = 1; }
#line 1950 "m2-exp.c.tmp"
    break;

  case 44:
#line 341 "m2-exp.y"
                        { pstate->arglist_len++; }
#line 1956 "m2-exp.c.tmp"
    break;

  case 45:
#line 346 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_MEMVAL);
			  write_exp_elt_type (pstate, (yyvsp[-2].tval));
			  write_exp_elt_opcode (pstate, UNOP_MEMVAL); }
#line 1964 "m2-exp.c.tmp"
    break;

  case 46:
#line 352 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_CAST);
			  write_exp_elt_type (pstate, (yyvsp[-3].tval));
			  write_exp_elt_opcode (pstate, UNOP_CAST); }
#line 1972 "m2-exp.c.tmp"
    break;

  case 47:
#line 358 "m2-exp.y"
                        { }
#line 1978 "m2-exp.c.tmp"
    break;

  case 48:
#line 366 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_REPEAT); }
#line 1984 "m2-exp.c.tmp"
    break;

  case 49:
#line 370 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_MUL); }
#line 1990 "m2-exp.c.tmp"
    break;

  case 50:
#line 374 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_DIV); }
#line 1996 "m2-exp.c.tmp"
    break;

  case 51:
#line 378 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_INTDIV); }
#line 2002 "m2-exp.c.tmp"
    break;

  case 52:
#line 382 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_REM); }
#line 2008 "m2-exp.c.tmp"
    break;

  case 53:
#line 386 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_ADD); }
#line 2014 "m2-exp.c.tmp"
    break;

  case 54:
#line 390 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_SUB); }
#line 2020 "m2-exp.c.tmp"
    break;

  case 55:
#line 394 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_EQUAL); }
#line 2026 "m2-exp.c.tmp"
    break;

  case 56:
#line 398 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_NOTEQUAL); }
#line 2032 "m2-exp.c.tmp"
    break;

  case 57:
#line 400 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_NOTEQUAL); }
#line 2038 "m2-exp.c.tmp"
    break;

  case 58:
#line 404 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_LEQ); }
#line 2044 "m2-exp.c.tmp"
    break;

  case 59:
#line 408 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_GEQ); }
#line 2050 "m2-exp.c.tmp"
    break;

  case 60:
#line 412 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_LESS); }
#line 2056 "m2-exp.c.tmp"
    break;

  case 61:
#line 416 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_GTR); }
#line 2062 "m2-exp.c.tmp"
    break;

  case 62:
#line 420 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_LOGICAL_AND); }
#line 2068 "m2-exp.c.tmp"
    break;

  case 63:
#line 424 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_LOGICAL_OR); }
#line 2074 "m2-exp.c.tmp"
    break;

  case 64:
#line 428 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_ASSIGN); }
#line 2080 "m2-exp.c.tmp"
    break;

  case 65:
#line 435 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, OP_BOOL);
			  write_exp_elt_longcst (pstate, (LONGEST) (yyvsp[0].ulval));
			  write_exp_elt_opcode (pstate, OP_BOOL); }
#line 2088 "m2-exp.c.tmp"
    break;

  case 66:
#line 441 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, OP_BOOL);
			  write_exp_elt_longcst (pstate, (LONGEST) (yyvsp[0].ulval));
			  write_exp_elt_opcode (pstate, OP_BOOL); }
#line 2096 "m2-exp.c.tmp"
    break;

  case 67:
#line 447 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, OP_LONG);
			  write_exp_elt_type (pstate,
					parse_m2_type (pstate)->builtin_int);
			  write_exp_elt_longcst (pstate, (LONGEST) (yyvsp[0].lval));
			  write_exp_elt_opcode (pstate, OP_LONG); }
#line 2106 "m2-exp.c.tmp"
    break;

  case 68:
#line 455 "m2-exp.y"
                        {
			  write_exp_elt_opcode (pstate, OP_LONG);
			  write_exp_elt_type (pstate,
					      parse_m2_type (pstate)
					      ->builtin_card);
			  write_exp_elt_longcst (pstate, (LONGEST) (yyvsp[0].ulval));
			  write_exp_elt_opcode (pstate, OP_LONG);
			}
#line 2119 "m2-exp.c.tmp"
    break;

  case 69:
#line 466 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, OP_LONG);
			  write_exp_elt_type (pstate,
					      parse_m2_type (pstate)
					      ->builtin_char);
			  write_exp_elt_longcst (pstate, (LONGEST) (yyvsp[0].ulval));
			  write_exp_elt_opcode (pstate, OP_LONG); }
#line 2130 "m2-exp.c.tmp"
    break;

  case 70:
#line 476 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, OP_FLOAT);
			  write_exp_elt_type (pstate,
					      parse_m2_type (pstate)
					      ->builtin_real);
			  write_exp_elt_floatcst (pstate, (yyvsp[0].val));
			  write_exp_elt_opcode (pstate, OP_FLOAT); }
#line 2141 "m2-exp.c.tmp"
    break;

  case 72:
#line 488 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, OP_LONG);
			  write_exp_elt_type (pstate,
					    parse_type (pstate)->builtin_int);
			  write_exp_elt_longcst (pstate,
						 (LONGEST) TYPE_LENGTH ((yyvsp[-1].tval)));
			  write_exp_elt_opcode (pstate, OP_LONG); }
#line 2152 "m2-exp.c.tmp"
    break;

  case 73:
#line 497 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, OP_M2_STRING);
			  write_exp_string (pstate, (yyvsp[0].sval));
			  write_exp_elt_opcode (pstate, OP_M2_STRING); }
#line 2160 "m2-exp.c.tmp"
    break;

  case 74:
#line 504 "m2-exp.y"
                        { (yyval.bval) = SYMBOL_BLOCK_VALUE((yyvsp[0].sym)); }
#line 2166 "m2-exp.c.tmp"
    break;

  case 75:
#line 508 "m2-exp.y"
                        { struct symbol *sym
			    = lookup_symbol (copy_name ((yyvsp[0].sval)).c_str (),
					     pstate->expression_context_block,
					     VAR_DOMAIN, 0).symbol;
			  (yyval.sym) = sym;}
#line 2176 "m2-exp.c.tmp"
    break;

  case 76:
#line 518 "m2-exp.y"
                        { struct symbol *tem
			    = lookup_symbol (copy_name ((yyvsp[0].sval)).c_str (), (yyvsp[-2].bval),
					     VAR_DOMAIN, 0).symbol;
			  if (!tem || SYMBOL_CLASS (tem) != LOC_BLOCK)
			    error (_("No function \"%s\" in specified context."),
				   copy_name ((yyvsp[0].sval)).c_str ());
			  (yyval.sym) = tem;
			}
#line 2189 "m2-exp.c.tmp"
    break;

  case 77:
#line 530 "m2-exp.y"
                        { write_exp_elt_opcode (pstate, OP_VAR_VALUE);
			  write_exp_elt_block (pstate, NULL);
			  write_exp_elt_sym (pstate, (yyvsp[0].sym));
			  write_exp_elt_opcode (pstate, OP_VAR_VALUE); }
#line 2198 "m2-exp.c.tmp"
    break;

  case 79:
#line 542 "m2-exp.y"
                        { struct block_symbol sym
			    = lookup_symbol (copy_name ((yyvsp[0].sval)).c_str (), (yyvsp[-2].bval),
					     VAR_DOMAIN, 0);

			  if (sym.symbol == 0)
			    error (_("No symbol \"%s\" in specified context."),
				   copy_name ((yyvsp[0].sval)).c_str ());
			  if (symbol_read_needs_frame (sym.symbol))
			    pstate->block_tracker->update (sym);

			  write_exp_elt_opcode (pstate, OP_VAR_VALUE);
			  write_exp_elt_block (pstate, sym.block);
			  write_exp_elt_sym (pstate, sym.symbol);
			  write_exp_elt_opcode (pstate, OP_VAR_VALUE); }
#line 2217 "m2-exp.c.tmp"
    break;

  case 80:
#line 560 "m2-exp.y"
                        { struct block_symbol sym;
			  struct field_of_this_result is_a_field_of_this;

			  sym
			    = lookup_symbol (copy_name ((yyvsp[0].sval)).c_str (),
					     pstate->expression_context_block,
					     VAR_DOMAIN,
					     &is_a_field_of_this);

			  if (sym.symbol)
			    {
			      if (symbol_read_needs_frame (sym.symbol))
				pstate->block_tracker->update (sym);

			      write_exp_elt_opcode (pstate, OP_VAR_VALUE);
			      write_exp_elt_block (pstate, sym.block);
			      write_exp_elt_sym (pstate, sym.symbol);
			      write_exp_elt_opcode (pstate, OP_VAR_VALUE);
			    }
			  else
			    {
			      struct bound_minimal_symbol msymbol;
			      std::string arg = copy_name ((yyvsp[0].sval));

			      msymbol =
				lookup_bound_minimal_symbol (arg.c_str ());
			      if (msymbol.minsym != NULL)
				write_exp_msymbol (pstate, msymbol);
			      else if (!have_full_symbols () && !have_partial_symbols ())
				error (_("No symbol table is loaded.  Use the \"symbol-file\" command."));
			      else
				error (_("No symbol \"%s\" in current context."),
				       arg.c_str ());
			    }
			}
#line 2257 "m2-exp.c.tmp"
    break;

  case 81:
#line 599 "m2-exp.y"
                        { (yyval.tval)
			    = lookup_typename (pstate->language (),
					       copy_name ((yyvsp[0].sval)).c_str (),
					       pstate->expression_context_block,
					       0);
			}
#line 2268 "m2-exp.c.tmp"
    break;


#line 2272 "m2-exp.c.tmp"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 608 "m2-exp.y"


/* Take care of parsing a number (anything that starts with a digit).
   Set yylval and return the token type; update lexptr.
   LEN is the number of characters in it.  */

/*** Needs some error checking for the float case ***/

static int
parse_number (int olen)
{
  const char *p = pstate->lexptr;
  LONGEST n = 0;
  LONGEST prevn = 0;
  int c,i,ischar=0;
  int base = input_radix;
  int len = olen;
  int unsigned_p = number_sign == 1 ? 1 : 0;

  if(p[len-1] == 'H')
  {
     base = 16;
     len--;
  }
  else if(p[len-1] == 'C' || p[len-1] == 'B')
  {
     base = 8;
     ischar = p[len-1] == 'C';
     len--;
  }

  /* Scan the number */
  for (c = 0; c < len; c++)
  {
    if (p[c] == '.' && base == 10)
      {
	/* It's a float since it contains a point.  */
	if (!parse_float (p, len,
			  parse_m2_type (pstate)->builtin_real,
			  yylval.val))
	  return ERROR;

	pstate->lexptr += len;
	return FLOAT;
      }
    if (p[c] == '.' && base != 10)
       error (_("Floating point numbers must be base 10."));
    if (base == 10 && (p[c] < '0' || p[c] > '9'))
       error (_("Invalid digit \'%c\' in number."),p[c]);
 }

  while (len-- > 0)
    {
      c = *p++;
      n *= base;
      if( base == 8 && (c == '8' || c == '9'))
	 error (_("Invalid digit \'%c\' in octal number."),c);
      if (c >= '0' && c <= '9')
	i = c - '0';
      else
	{
	  if (base == 16 && c >= 'A' && c <= 'F')
	    i = c - 'A' + 10;
	  else
	     return ERROR;
	}
      n+=i;
      if(i >= base)
	 return ERROR;
      if(!unsigned_p && number_sign == 1 && (prevn >= n))
	 unsigned_p=1;		/* Try something unsigned */
      /* Don't do the range check if n==i and i==0, since that special
	 case will give an overflow error.  */
      if(RANGE_CHECK && n!=i && i)
      {
	 if((unsigned_p && (unsigned)prevn >= (unsigned)n) ||
	    ((!unsigned_p && number_sign==-1) && -prevn <= -n))
	    range_error (_("Overflow on numeric constant."));
      }
	 prevn=n;
    }

  pstate->lexptr = p;
  if(*p == 'B' || *p == 'C' || *p == 'H')
     pstate->lexptr++;			/* Advance past B,C or H */

  if (ischar)
  {
     yylval.ulval = n;
     return CHAR;
  }
  else if ( unsigned_p && number_sign == 1)
  {
     yylval.ulval = n;
     return UINT;
  }
  else if((unsigned_p && (n<0))) {
     range_error (_("Overflow on numeric constant -- number too large."));
     /* But, this can return if range_check == range_warn.  */
  }
  yylval.lval = n;
  return INT;
}


/* Some tokens */

static struct
{
   char name[2];
   int token;
} tokentab2[] =
{
    { {'<', '>'},    NOTEQUAL 	},
    { {':', '='},    ASSIGN	},
    { {'<', '='},    LEQ	},
    { {'>', '='},    GEQ	},
    { {':', ':'},    COLONCOLON },

};

/* Some specific keywords */

struct keyword {
   char keyw[10];
   int token;
};

static struct keyword keytab[] =
{
    {"OR" ,   OROR	 },
    {"IN",    IN         },/* Note space after IN */
    {"AND",   LOGICAL_AND},
    {"ABS",   ABS	 },
    {"CHR",   CHR	 },
    {"DEC",   DEC	 },
    {"NOT",   NOT	 },
    {"DIV",   DIV    	 },
    {"INC",   INC	 },
    {"MAX",   MAX_FUNC	 },
    {"MIN",   MIN_FUNC	 },
    {"MOD",   MOD	 },
    {"ODD",   ODD	 },
    {"CAP",   CAP	 },
    {"ORD",   ORD	 },
    {"VAL",   VAL	 },
    {"EXCL",  EXCL	 },
    {"HIGH",  HIGH       },
    {"INCL",  INCL	 },
    {"SIZE",  SIZE       },
    {"FLOAT", FLOAT_FUNC },
    {"TRUNC", TRUNC	 },
    {"TSIZE", SIZE       },
};


/* Depth of parentheses.  */
static int paren_depth;

/* Read one token, getting characters through lexptr.  */

/* This is where we will check to make sure that the language and the
   operators used are compatible  */

static int
yylex (void)
{
  int c;
  int namelen;
  int i;
  const char *tokstart;
  char quote;

 retry:

  pstate->prev_lexptr = pstate->lexptr;

  tokstart = pstate->lexptr;


  /* See if it is a special token of length 2 */
  for( i = 0 ; i < (int) (sizeof tokentab2 / sizeof tokentab2[0]) ; i++)
     if (strncmp (tokentab2[i].name, tokstart, 2) == 0)
     {
	pstate->lexptr += 2;
	return tokentab2[i].token;
     }

  switch (c = *tokstart)
    {
    case 0:
      return 0;

    case ' ':
    case '\t':
    case '\n':
      pstate->lexptr++;
      goto retry;

    case '(':
      paren_depth++;
      pstate->lexptr++;
      return c;

    case ')':
      if (paren_depth == 0)
	return 0;
      paren_depth--;
      pstate->lexptr++;
      return c;

    case ',':
      if (pstate->comma_terminates && paren_depth == 0)
	return 0;
      pstate->lexptr++;
      return c;

    case '.':
      /* Might be a floating point number.  */
      if (pstate->lexptr[1] >= '0' && pstate->lexptr[1] <= '9')
	break;			/* Falls into number code.  */
      else
      {
	 pstate->lexptr++;
	 return DOT;
      }

/* These are character tokens that appear as-is in the YACC grammar */
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '<':
    case '>':
    case '[':
    case ']':
    case '=':
    case '{':
    case '}':
    case '#':
    case '@':
    case '~':
    case '&':
      pstate->lexptr++;
      return c;

    case '\'' :
    case '"':
      quote = c;
      for (namelen = 1; (c = tokstart[namelen]) != quote && c != '\0'; namelen++)
	if (c == '\\')
	  {
	    c = tokstart[++namelen];
	    if (c >= '0' && c <= '9')
	      {
		c = tokstart[++namelen];
		if (c >= '0' && c <= '9')
		  c = tokstart[++namelen];
	      }
	  }
      if(c != quote)
	 error (_("Unterminated string or character constant."));
      yylval.sval.ptr = tokstart + 1;
      yylval.sval.length = namelen - 1;
      pstate->lexptr += namelen + 1;

      if(namelen == 2)  	/* Single character */
      {
	   yylval.ulval = tokstart[1];
	   return CHAR;
      }
      else
	 return STRING;
    }

  /* Is it a number?  */
  /* Note:  We have already dealt with the case of the token '.'.
     See case '.' above.  */
  if ((c >= '0' && c <= '9'))
    {
      /* It's a number.  */
      int got_dot = 0, got_e = 0;
      const char *p = tokstart;
      int toktype;

      for (++p ;; ++p)
	{
	  if (!got_e && (*p == 'e' || *p == 'E'))
	    got_dot = got_e = 1;
	  else if (!got_dot && *p == '.')
	    got_dot = 1;
	  else if (got_e && (p[-1] == 'e' || p[-1] == 'E')
		   && (*p == '-' || *p == '+'))
	    /* This is the sign of the exponent, not the end of the
	       number.  */
	    continue;
	  else if ((*p < '0' || *p > '9') &&
		   (*p < 'A' || *p > 'F') &&
		   (*p != 'H'))  /* Modula-2 hexadecimal number */
	    break;
	}
	toktype = parse_number (p - tokstart);
        if (toktype == ERROR)
	  {
	    char *err_copy = (char *) alloca (p - tokstart + 1);

	    memcpy (err_copy, tokstart, p - tokstart);
	    err_copy[p - tokstart] = 0;
	    error (_("Invalid number \"%s\"."), err_copy);
	  }
	pstate->lexptr = p;
	return toktype;
    }

  if (!(c == '_' || c == '$'
	|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
    /* We must have come across a bad character (e.g. ';').  */
    error (_("Invalid character '%c' in expression."), c);

  /* It's a name.  See how long it is.  */
  namelen = 0;
  for (c = tokstart[namelen];
       (c == '_' || c == '$' || (c >= '0' && c <= '9')
	|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
       c = tokstart[++namelen])
    ;

  /* The token "if" terminates the expression and is NOT
     removed from the input stream.  */
  if (namelen == 2 && tokstart[0] == 'i' && tokstart[1] == 'f')
    {
      return 0;
    }

  pstate->lexptr += namelen;

  /*  Lookup special keywords */
  for(i = 0 ; i < (int) (sizeof(keytab) / sizeof(keytab[0])) ; i++)
     if (namelen == strlen (keytab[i].keyw)
	 && strncmp (tokstart, keytab[i].keyw, namelen) == 0)
	   return keytab[i].token;

  yylval.sval.ptr = tokstart;
  yylval.sval.length = namelen;

  if (*tokstart == '$')
    {
      write_dollar_variable (pstate, yylval.sval);
      return DOLLAR_VARIABLE;
    }

  /* Use token-type BLOCKNAME for symbols that happen to be defined as
     functions.  If this is not so, then ...
     Use token-type TYPENAME for symbols that happen to be defined
     currently as names of types; NAME for other symbols.
     The caller is not constrained to care about the distinction.  */
 {
    std::string tmp = copy_name (yylval.sval);
    struct symbol *sym;

    if (lookup_symtab (tmp.c_str ()))
      return BLOCKNAME;
    sym = lookup_symbol (tmp.c_str (), pstate->expression_context_block,
			 VAR_DOMAIN, 0).symbol;
    if (sym && SYMBOL_CLASS (sym) == LOC_BLOCK)
      return BLOCKNAME;
    if (lookup_typename (pstate->language (),
			 tmp.c_str (), pstate->expression_context_block, 1))
      return TYPENAME;

    if(sym)
    {
      switch(SYMBOL_CLASS (sym))
       {
       case LOC_STATIC:
       case LOC_REGISTER:
       case LOC_ARG:
       case LOC_REF_ARG:
       case LOC_REGPARM_ADDR:
       case LOC_LOCAL:
       case LOC_CONST:
       case LOC_CONST_BYTES:
       case LOC_OPTIMIZED_OUT:
       case LOC_COMPUTED:
	  return NAME;

       case LOC_TYPEDEF:
	  return TYPENAME;

       case LOC_BLOCK:
	  return BLOCKNAME;

       case LOC_UNDEF:
	  error (_("internal:  Undefined class in m2lex()"));

       case LOC_LABEL:
       case LOC_UNRESOLVED:
	  error (_("internal:  Unforseen case in m2lex()"));

       default:
	  error (_("unhandled token in m2lex()"));
	  break;
       }
    }
    else
    {
       /* Built-in BOOLEAN type.  This is sort of a hack.  */
       if (strncmp (tokstart, "TRUE", 4) == 0)
       {
	  yylval.ulval = 1;
	  return M2_TRUE;
       }
       else if (strncmp (tokstart, "FALSE", 5) == 0)
       {
	  yylval.ulval = 0;
	  return M2_FALSE;
       }
    }

    /* Must be another type of name...  */
    return NAME;
 }
}

int
m2_parse (struct parser_state *par_state)
{
  /* Setting up the parser state.  */
  scoped_restore pstate_restore = make_scoped_restore (&pstate);
  gdb_assert (par_state != NULL);
  pstate = par_state;
  paren_depth = 0;

  return yyparse ();
}

static void
yyerror (const char *msg)
{
  if (pstate->prev_lexptr)
    pstate->lexptr = pstate->prev_lexptr;

  error (_("A %s in expression, near `%s'."), msg, pstate->lexptr);
}
