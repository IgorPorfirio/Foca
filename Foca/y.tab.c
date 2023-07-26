/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatica.y"

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

int label_i = 0;



#define YYSTYPE atributos



std::vector<std::string> loopStartLabels;
std::vector<std::string> loopEndLabels;

std::map<std::string, std::pair<std::string, std::string>> variableTable; //Nome da variavel, nome temporario e tipo da variavel.
std::map<std::string, std::pair<std::string, std::string>> reverseTable;  //nome temporario, nome da variavel e tipo da variavel

void addVariable(const std::string& nomeVar, const std::string& nomeTemp, const std::string& type) {
    variableTable[nomeVar] = std::make_pair(nomeTemp, type);
	reverseTable[nomeTemp] = std::make_pair(nomeVar, type);
}

std::pair<std::string, std::string> getVariableInfo(const std::string& codeName) {
    return variableTable[codeName];
}

using namespace std;

struct atributos
{
	string label;
	string traducao;
	string tipo;
};



std::string getDominantType(const std::string& tipo1, const std::string& tipo2);
string printDeclaracoes();
int yylex(void);
void yyerror(string);

std::string gen_label();

atributos implicitTypeCast(const atributos& original, const atributos& destino); 


#line 123 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TK_NUM = 258,                  /* TK_NUM  */
    TK_REAL = 259,                 /* TK_REAL  */
    TK_BOOL = 260,                 /* TK_BOOL  */
    TK_CHAR = 261,                 /* TK_CHAR  */
    TK_STRING = 262,               /* TK_STRING  */
    TK_TIPO = 263,                 /* TK_TIPO  */
    TK_MAIN = 264,                 /* TK_MAIN  */
    TK_ID = 265,                   /* TK_ID  */
    TK_FIM = 266,                  /* TK_FIM  */
    TK_ERROR = 267,                /* TK_ERROR  */
    TK_OP = 268,                   /* TK_OP  */
    TK_OP2 = 269,                  /* TK_OP2  */
    TK_RELACIONAL = 270,           /* TK_RELACIONAL  */
    TK_LOGICO = 271,               /* TK_LOGICO  */
    TK_UNARIO = 272,               /* TK_UNARIO  */
    TK_IF = 273,                   /* TK_IF  */
    TK_ELSE = 274,                 /* TK_ELSE  */
    TK_WHILE = 275,                /* TK_WHILE  */
    TK_DO = 276,                   /* TK_DO  */
    TK_FOR = 277,                  /* TK_FOR  */
    TK_BREAK = 278,                /* TK_BREAK  */
    TK_CONTINUE = 279              /* TK_CONTINUE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TK_NUM 258
#define TK_REAL 259
#define TK_BOOL 260
#define TK_CHAR 261
#define TK_STRING 262
#define TK_TIPO 263
#define TK_MAIN 264
#define TK_ID 265
#define TK_FIM 266
#define TK_ERROR 267
#define TK_OP 268
#define TK_OP2 269
#define TK_RELACIONAL 270
#define TK_LOGICO 271
#define TK_UNARIO 272
#define TK_IF 273
#define TK_ELSE 274
#define TK_WHILE 275
#define TK_DO 276
#define TK_FOR 277
#define TK_BREAK 278
#define TK_CONTINUE 279

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_NUM = 3,                     /* TK_NUM  */
  YYSYMBOL_TK_REAL = 4,                    /* TK_REAL  */
  YYSYMBOL_TK_BOOL = 5,                    /* TK_BOOL  */
  YYSYMBOL_TK_CHAR = 6,                    /* TK_CHAR  */
  YYSYMBOL_TK_STRING = 7,                  /* TK_STRING  */
  YYSYMBOL_TK_TIPO = 8,                    /* TK_TIPO  */
  YYSYMBOL_TK_MAIN = 9,                    /* TK_MAIN  */
  YYSYMBOL_TK_ID = 10,                     /* TK_ID  */
  YYSYMBOL_TK_FIM = 11,                    /* TK_FIM  */
  YYSYMBOL_TK_ERROR = 12,                  /* TK_ERROR  */
  YYSYMBOL_TK_OP = 13,                     /* TK_OP  */
  YYSYMBOL_TK_OP2 = 14,                    /* TK_OP2  */
  YYSYMBOL_TK_RELACIONAL = 15,             /* TK_RELACIONAL  */
  YYSYMBOL_TK_LOGICO = 16,                 /* TK_LOGICO  */
  YYSYMBOL_TK_UNARIO = 17,                 /* TK_UNARIO  */
  YYSYMBOL_TK_IF = 18,                     /* TK_IF  */
  YYSYMBOL_TK_ELSE = 19,                   /* TK_ELSE  */
  YYSYMBOL_TK_WHILE = 20,                  /* TK_WHILE  */
  YYSYMBOL_TK_DO = 21,                     /* TK_DO  */
  YYSYMBOL_TK_FOR = 22,                    /* TK_FOR  */
  YYSYMBOL_TK_BREAK = 23,                  /* TK_BREAK  */
  YYSYMBOL_TK_CONTINUE = 24,               /* TK_CONTINUE  */
  YYSYMBOL_25_ = 25,                       /* '('  */
  YYSYMBOL_26_ = 26,                       /* ')'  */
  YYSYMBOL_27_ = 27,                       /* '{'  */
  YYSYMBOL_28_ = 28,                       /* '}'  */
  YYSYMBOL_29_ = 29,                       /* ';'  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_S = 32,                         /* S  */
  YYSYMBOL_BLOCO = 33,                     /* BLOCO  */
  YYSYMBOL_COMANDOS = 34,                  /* COMANDOS  */
  YYSYMBOL_COMANDO = 35,                   /* COMANDO  */
  YYSYMBOL_E = 36                          /* E  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   173

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  6
/* YYNRULES -- Number of rules.  */
#define YYNRULES  32
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  77

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   279


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      25,    26,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
       2,    30,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    86,    86,   102,   106,   111,   115,   119,   124,   137,
     152,   165,   177,   205,   209,   215,   222,   229,   237,   248,
     269,   291,   313,   325,   357,   367,   375,   384,   396,   404,
     408,   419,   434
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_NUM", "TK_REAL",
  "TK_BOOL", "TK_CHAR", "TK_STRING", "TK_TIPO", "TK_MAIN", "TK_ID",
  "TK_FIM", "TK_ERROR", "TK_OP", "TK_OP2", "TK_RELACIONAL", "TK_LOGICO",
  "TK_UNARIO", "TK_IF", "TK_ELSE", "TK_WHILE", "TK_DO", "TK_FOR",
  "TK_BREAK", "TK_CONTINUE", "'('", "')'", "'{'", "'}'", "';'", "'='",
  "$accept", "S", "BLOCO", "COMANDOS", "COMANDO", "E", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-26)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,     9,    20,    -1,   -26,    -4,    96,   -26,   -26,   -26,
     -26,   -26,    46,    27,    35,    36,    96,    38,    41,    50,
      73,    44,   -26,   -26,   105,    -6,    52,   128,   128,   128,
      63,   128,   -26,   -26,    58,   -26,    57,    70,   -26,   128,
     128,   128,   128,   -26,   128,    25,    19,   129,    61,    13,
     128,   -26,   -26,    59,    -3,    15,    25,    25,    25,    96,
      96,   128,   128,    25,   -26,    77,   -26,   133,   111,    96,
      60,   128,   -26,   -26,   147,    96,   -26
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,    25,    26,    27,
      28,    29,     0,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     6,    14,    16,    32,     0,     0,     0,
       0,     0,    17,    18,     0,     5,     0,     0,    13,     0,
       0,     0,     0,    15,     0,    23,     0,     0,     0,     0,
       0,     4,     3,     0,    19,    20,    21,    22,    31,     0,
       0,     0,     0,    24,     7,     8,    10,     0,     0,     0,
       0,     0,     9,    11,     0,     0,    12
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -26,   -26,   -16,    34,   -26,   -25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    22,    23,    24,    25
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      30,     1,    45,    46,    47,    36,    49,    39,    40,    41,
      42,    40,    41,    42,    54,    55,    56,    57,     3,    58,
       4,    53,     6,    43,     5,    63,    39,    40,    41,    42,
      41,    42,    39,    40,    41,    42,    67,    68,    39,    40,
      41,    42,    62,    65,    66,    59,    74,     7,     8,     9,
      10,    11,    12,    72,    13,    37,    26,    27,    38,    76,
      28,    29,    14,    31,    15,    16,    17,    18,    19,    20,
      32,    21,    35,     7,     8,     9,    10,    11,    12,    33,
      13,    34,    44,    48,    50,    51,    61,    64,    14,    73,
      15,    16,    17,    18,    19,    20,    69,    21,    52,     7,
       8,     9,    10,    11,    12,     0,    13,     0,     7,     8,
       9,    10,    11,    12,    14,    13,    15,    16,    17,    18,
      19,    20,     0,    21,    39,    40,    41,    42,    18,    19,
      20,     7,     8,     9,    10,    11,    12,     0,    13,     0,
      71,     0,    39,    40,    41,    42,    39,    40,    41,    42,
       0,     0,     0,    20,     0,    60,     0,     0,     0,    70,
      39,    40,    41,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75
};

static const yytype_int8 yycheck[] =
{
      16,     8,    27,    28,    29,    21,    31,    13,    14,    15,
      16,    14,    15,    16,    39,    40,    41,    42,     9,    44,
       0,    37,    26,    29,    25,    50,    13,    14,    15,    16,
      15,    16,    13,    14,    15,    16,    61,    62,    13,    14,
      15,    16,    29,    59,    60,    26,    71,     3,     4,     5,
       6,     7,     8,    69,    10,    21,    10,    30,    24,    75,
      25,    25,    18,    25,    20,    21,    22,    23,    24,    25,
      29,    27,    28,     3,     4,     5,     6,     7,     8,    29,
      10,     8,    30,    20,    26,    28,    25,    28,    18,    29,
      20,    21,    22,    23,    24,    25,    19,    27,    28,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,     3,     4,
       5,     6,     7,     8,    18,    10,    20,    21,    22,    23,
      24,    25,    -1,    27,    13,    14,    15,    16,    23,    24,
      25,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      29,    -1,    13,    14,    15,    16,    13,    14,    15,    16,
      -1,    -1,    -1,    25,    -1,    26,    -1,    -1,    -1,    26,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    32,     9,     0,    25,    26,     3,     4,     5,
       6,     7,     8,    10,    18,    20,    21,    22,    23,    24,
      25,    27,    33,    34,    35,    36,    10,    30,    25,    25,
      33,    25,    29,    29,     8,    28,    33,    34,    34,    13,
      14,    15,    16,    29,    30,    36,    36,    36,    20,    36,
      26,    28,    28,    33,    36,    36,    36,    36,    36,    26,
      26,    25,    29,    36,    28,    33,    33,    36,    36,    19,
      26,    29,    33,    29,    36,    26,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    34,    34,    35,    35,    35,    35,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     3,     2,     1,     4,     5,     7,
       5,     7,     9,     2,     1,     2,     1,     2,     2,     3,
       3,     3,     3,     3,     4,     1,     1,     1,     1,     1,
       1,     4,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* S: TK_TIPO TK_MAIN '(' ')' BLOCO  */
#line 87 "sintatica.y"
                        {
				if(yyvsp[-4].tipo != "int")
				{
					cout << yyvsp[-3].label;
					yyerror(" main deve ser do tipo int");
				}
				cout << "\n/*Compilador FOCA*/\n\n";
				cout << "#include <iostream>\n#iCompilador>\n#include<stdio.h>\n\n";
				cout << "int main(void)\n{\n";
				cout << printDeclaracoes() <<"\n"; // Printa declarações de variaveis
	 			cout << yyvsp[0].traducao << "\n"; // Print a tradução do código
				cout << "\treturn 0;\n}" << endl;
			}
#line 1302 "y.tab.c"
    break;

  case 3: /* BLOCO: '{' COMANDOS '}'  */
#line 103 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao;
			}
#line 1310 "y.tab.c"
    break;

  case 4: /* BLOCO: '{' BLOCO '}'  */
#line 107 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao;
			}
#line 1318 "y.tab.c"
    break;

  case 5: /* BLOCO: '{' '}'  */
#line 112 "sintatica.y"
                        {
				yyval.traducao = "";
			}
#line 1326 "y.tab.c"
    break;

  case 6: /* BLOCO: COMANDOS  */
#line 116 "sintatica.y"
                        {
				yyval.traducao = yyvsp[0].traducao;
			}
#line 1334 "y.tab.c"
    break;

  case 7: /* BLOCO: '{' COMANDOS BLOCO '}'  */
#line 120 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-2].traducao + yyvsp[-1].traducao;
			}
#line 1342 "y.tab.c"
    break;

  case 8: /* BLOCO: TK_IF '(' E ')' BLOCO  */
#line 125 "sintatica.y"
                        {

				std::string labelIf = gen_label();
		        std::string labelEnd = gen_label();


				yyval.traducao = yyvsp[-2].traducao + "\tif (" + yyvsp[-2].label + ") goto " + labelIf + ";\n"
                       + "\tgoto " + labelEnd + ";\n"
                       + labelIf + ":\n"
                       + labelEnd + ":\n";
			}
#line 1358 "y.tab.c"
    break;

  case 9: /* BLOCO: TK_IF '(' E ')' BLOCO TK_ELSE BLOCO  */
#line 138 "sintatica.y"
                        {
				std::string labelIf = gen_label();
				std::string labelElse = gen_label();
    			std::string labelEnd = gen_label();

				yyval.traducao = yyvsp[-4].traducao + "\tif (" + yyvsp[-4].label + ") goto " + labelIf + ";\n"
                + "\tgoto " + labelElse + ";\n"
                + labelIf + ":\n"
                + yyvsp[-2].traducao + "\tgoto " + labelEnd + ";\n"
                + labelElse + ":\n"
                + yyvsp[0].traducao
                + labelEnd + ":\n";
			}
#line 1376 "y.tab.c"
    break;

  case 10: /* BLOCO: TK_WHILE '(' E ')' BLOCO  */
#line 153 "sintatica.y"
                        {
				std::string labelWhile = gen_label();
				std::string labelEnd = gen_label();

				yyval.traducao = labelWhile + ":\n" 
                            + yyvsp[-2].traducao 
                            + "\tif (" + yyvsp[-2].label + ") goto " + labelEnd + ";\n" // Condição de Saída
                            + yyvsp[0].traducao 
                            + "\tgoto " + labelWhile + ";\n" 
                            + labelEnd + ":\n"; 
			}
#line 1392 "y.tab.c"
    break;

  case 11: /* BLOCO: TK_DO BLOCO TK_WHILE '(' E ')' ';'  */
#line 166 "sintatica.y"
                        {
				std::string labelWhile = gen_label();
				std::string labelEnd = gen_label();

				yyval.traducao = labelWhile + ":\n"
                            + yyvsp[-5].traducao 
                            + yyvsp[-2].traducao 
                            + "\tif (" + yyvsp[-2].label + ") goto " + labelWhile + ";\n" // condição de repetição
                            + labelEnd + ":\n";
			}
#line 1407 "y.tab.c"
    break;

  case 12: /* BLOCO: TK_FOR '(' E ';' E ';' E ')' BLOCO  */
#line 178 "sintatica.y"
                        {
				std::string labelFor = gen_label();
				std::string labelEnd = gen_label();


				loopStartLabels.push_back(labelFor);
			    loopEndLabels.push_back(labelEnd);
				

				if(yyvsp[-6].tipo == "bool")
					yyerror("Indice não do for não pode ser do tipo booleano");
				if(yyvsp[-4].tipo != "bool")
					yyerror("Condição do for deve ser do tipo booleano");
				if(yyvsp[-2].tipo == "bool")
					yyerror("atualização do for não deve ser do tipo booleano");

				yyval.traducao = yyvsp[-6].traducao 
                            + labelFor + ":\n" 
                            + yyvsp[-4].traducao 
                            + "\tif (!(" + yyvsp[-4].label + ")) goto " + labelEnd + ";\n" 
                            + yyvsp[0].traducao 
                            + yyvsp[-2].traducao 
                            + "\tgoto " + labelFor + ";\n" 
                            + labelEnd + ":\n"; 
			}
#line 1437 "y.tab.c"
    break;

  case 13: /* COMANDOS: COMANDO COMANDOS  */
#line 206 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1445 "y.tab.c"
    break;

  case 14: /* COMANDOS: COMANDO  */
#line 210 "sintatica.y"
                        {
				yyval.traducao = yyvsp[0].traducao;
			}
#line 1453 "y.tab.c"
    break;

  case 15: /* COMANDO: E ';'  */
#line 216 "sintatica.y"
                        {
				yyval.label = yyvsp[-1].label;
				yyval.traducao = yyvsp[-1].traducao;
				yyval.tipo = yyvsp[-1].tipo;
			}
#line 1463 "y.tab.c"
    break;

  case 16: /* COMANDO: E  */
#line 223 "sintatica.y"
                        {
				yyval.label = yyvsp[0].label;
				yyval.traducao = yyvsp[0].traducao;
				yyval.tipo = yyvsp[0].tipo;
			}
#line 1473 "y.tab.c"
    break;

  case 17: /* COMANDO: TK_BREAK ';'  */
#line 230 "sintatica.y"
                        {
				
				if (loopEndLabels.empty()) {
				yyerror("Break precisa estar em um laço");
				}
				yyval.traducao = "\tgoto " + loopEndLabels.back() + ";\n";
			}
#line 1485 "y.tab.c"
    break;

  case 18: /* COMANDO: TK_CONTINUE ';'  */
#line 239 "sintatica.y"
                        {
				if (loopStartLabels.empty()) {
					yyerror("Continue precisa estar em um laço");
				}
				yyval.traducao = "\tgoto " + loopStartLabels.back() + ";\n";
			}
#line 1496 "y.tab.c"
    break;

  case 19: /* E: E TK_OP E  */
#line 249 "sintatica.y"
                        {	
				if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool")
					yyerror("Operação entre não booleanos não é possível");
				std::string label = gen_label();
				addVariable(label, label, yyvsp[-2].tipo);
				yyval.label = label;
				yyval.tipo = getDominantType(yyvsp[-2].tipo, yyvsp[0].tipo);
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;
				if (yyvsp[-2].tipo != yyval.tipo) {
					atributos typecast = implicitTypeCast(yyvsp[-2], yyval);
					yyval.traducao += typecast.traducao;
					yyvsp[-2].label = typecast.label;
				}
				if (yyvsp[0].tipo != yyval.tipo) {
					atributos typecast = implicitTypeCast(yyvsp[0], yyval);
					yyval.traducao += typecast.traducao;
					yyvsp[0].label = typecast.label;
				}
				yyval.traducao += "\t" + yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].label + " " + yyvsp[0].label + ";\n";
			}
#line 1521 "y.tab.c"
    break;

  case 20: /* E: E TK_OP2 E  */
#line 270 "sintatica.y"
                        {	
				if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool")
					yyerror("Operação entre não booleanos não é possível");
				std::string label = gen_label();
				addVariable(label, label, yyvsp[-2].tipo);
				yyval.label = label;
				yyval.tipo = getDominantType(yyvsp[-2].tipo, yyvsp[0].tipo);
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;
				if (yyvsp[-2].tipo != yyval.tipo) {
					atributos typecast = implicitTypeCast(yyvsp[-2], yyval);
					yyval.traducao += typecast.traducao;
					yyvsp[-2].label = typecast.label;
				}
				if (yyvsp[0].tipo != yyval.tipo) {
					atributos typecast = implicitTypeCast(yyvsp[0], yyval);
					yyval.traducao += typecast.traducao;
					yyvsp[0].label = typecast.label;
				}
				yyval.traducao += "\t" + yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].label + " " + yyvsp[0].label + ";\n";
			}
#line 1546 "y.tab.c"
    break;

  case 21: /* E: E TK_RELACIONAL E  */
#line 292 "sintatica.y"
                        {
				if(yyvsp[-2].tipo == "bool" || yyvsp[0].tipo == "bool")
					yyerror("Operação entre não booleanos não é possível");
				std::string label = gen_label();
				addVariable(label, label, yyvsp[-2].tipo);
				yyval.label = label;
				yyval.tipo = getDominantType(yyvsp[-2].tipo, yyvsp[0].tipo);
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;
				if (yyvsp[-2].tipo != yyval.tipo) {
					atributos typecast = implicitTypeCast(yyvsp[-2], yyval);
					yyval.traducao += typecast.traducao;
					yyvsp[-2].label = typecast.label;
				}
				if (yyvsp[0].tipo != yyval.tipo) {
					atributos typecast = implicitTypeCast(yyvsp[0], yyval);
					yyval.traducao += typecast.traducao;
					yyvsp[0].label = typecast.label;
				}
				yyval.tipo = "bool";
				yyval.traducao += "\t" + yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].label + " " + yyvsp[0].label + ";\n";
			}
#line 1572 "y.tab.c"
    break;

  case 22: /* E: E TK_LOGICO E  */
#line 314 "sintatica.y"
                        {
				if(yyvsp[-2].tipo != "bool" || yyvsp[0].tipo != "bool")
					yyerror("Operação lógica entre não booleanos não é possível");
				std::string label = gen_label();
				addVariable(label, label, yyvsp[-2].tipo);
				yyval.label = label;
				yyval.tipo = "bool";
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].label + " " + yyvsp[0].label + ";\n";
			}
#line 1586 "y.tab.c"
    break;

  case 23: /* E: TK_ID '=' E  */
#line 326 "sintatica.y"
                        {
				if (variableTable.find(yyvsp[-2].label) == variableTable.end()) 
   					 yyerror("\n" + yyvsp[-2].label + " não foi declarada");
				
				if(yyvsp[-2].tipo == "bool" && yyvsp[0].tipo != "bool")
					 yyerror("booleano não pode receber não booleano");
				yyval.tipo = getDominantType(yyvsp[-2].tipo, yyvsp[0].tipo);
				if(yyvsp[-2].tipo != yyval.tipo)
				{
					atributos typecast = implicitTypeCast(yyvsp[-2], yyval);
					yyval.traducao += typecast.traducao;
					//
					variableTable[yyvsp[-2].label] = std::make_pair(typecast.label, typecast.tipo);
					//cout << variableTable[$1.label].first;
					yyvsp[-2].label = typecast.label;
					
				}
				if (yyvsp[0].tipo != yyval.tipo) {
					atributos typecast = implicitTypeCast(yyvsp[0], yyval);
					yyval.traducao += typecast.traducao;
					yyvsp[0].label = typecast.label;
				}
				yyval.label = yyvsp[-2].label; // Label da expressão = Label/nome da variavel

				auto id = variableTable.find(yyvsp[-2].label);
				
				yyval.traducao = yyvsp[0].traducao + "\t" + id->second.first + " = " + yyvsp[0].label + ";\n"; //mantem tradução da expressão + Nome da variavel = Variavel temporaria da expressão 
				yyval.tipo = yyvsp[-2].tipo;
				 				
			}
#line 1621 "y.tab.c"
    break;

  case 24: /* E: '(' TK_TIPO ')' E  */
#line 358 "sintatica.y"
                        {
				yyval.label =  gen_label();
				addVariable(yyval.label, yyval.label, yyvsp[-2].tipo);
				yyval.tipo = yyvsp[-2].traducao;
				yyval.traducao = yyvsp[0].traducao + "\t" + yyval.label + " = (" +yyvsp[-2].traducao +")" + yyvsp[0].label + ";\n";
				
				
			}
#line 1634 "y.tab.c"
    break;

  case 25: /* E: TK_NUM  */
#line 368 "sintatica.y"
                        {
				yyval.label = gen_label();
				addVariable(yyval.label, yyval.label, yyvsp[0].tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n"; //tem n = valor do numero
				yyval.tipo = yyvsp[0].tipo;
			}
#line 1645 "y.tab.c"
    break;

  case 26: /* E: TK_REAL  */
#line 376 "sintatica.y"
                        {
				yyval.label = gen_label();
				addVariable(yyval.label, yyval.label, yyvsp[0].tipo);
				
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n"; 
				yyval.tipo = yyvsp[0].tipo;
			}
#line 1657 "y.tab.c"
    break;

  case 27: /* E: TK_BOOL  */
#line 385 "sintatica.y"
                        {
				yyval.label = gen_label();
				addVariable(yyval.label, yyval.label, yyvsp[0].tipo);
				
				if(yyval.traducao == "TRUE")
					yyval.traducao = "\t" + yyval.label + " = " + "1" + ";\t\t\t\t//boolean TRUE\n"; 
				else
					yyval.traducao = "\t" + yyval.label + " = " + "0" + ";\t\t\t\t//boolean FALSE\n"; 
				yyval.tipo = yyvsp[0].tipo;
			}
#line 1672 "y.tab.c"
    break;

  case 28: /* E: TK_CHAR  */
#line 397 "sintatica.y"
                        {
				yyval.label = gen_label();
				addVariable(yyval.label, yyval.label, yyvsp[0].tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].traducao + ";\n";
        		yyval.tipo = "char";
			}
#line 1683 "y.tab.c"
    break;

  case 29: /* E: TK_STRING  */
#line 405 "sintatica.y"
                        {
				
			}
#line 1691 "y.tab.c"
    break;

  case 30: /* E: TK_ID  */
#line 409 "sintatica.y"
                        {			
				if (variableTable.find(yyvsp[0].label) == variableTable.end()) 
   					yyerror("\n" + yyvsp[0].label + " não foi declarada");
				std::string label = gen_label();
				yyval.label = label; //temp n
				yyval.traducao = "\t" + label + " = " + yyvsp[0].traducao + ";\n"; 
				yyval.tipo = variableTable[yyvsp[0].label].second;
			}
#line 1704 "y.tab.c"
    break;

  case 31: /* E: TK_TIPO TK_ID '=' E  */
#line 420 "sintatica.y"
                        {
				//std::string label = gen_label();
				if(yyvsp[-3].tipo != yyvsp[0].tipo)
					yyerror("tipos incompativeis");
				if (variableTable.find(yyvsp[-2].label) != variableTable.end())
					yyerror("variavel ja foi declarada");
					
				yyval.label = gen_label();
				addVariable(yyvsp[-2].label, yyval.label, yyvsp[-3].tipo);
				yyval.traducao = yyvsp[0].traducao + "\t" + yyvsp[-2].label + " = " + yyvsp[0].label + ";\n";
				yyval.tipo = yyvsp[-3].tipo;
				
			}
#line 1722 "y.tab.c"
    break;

  case 32: /* E: TK_TIPO TK_ID  */
#line 435 "sintatica.y"
                        {
						
				yyval.label = gen_label();
				addVariable(yyvsp[0].label, yyval.label, yyvsp[-1].tipo);
				yyval.traducao = "";
				yyval.tipo = yyvsp[-1].tipo;
				
			}
#line 1735 "y.tab.c"
    break;


#line 1739 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 449 "sintatica.y"


#include "lex.yy.c"

int yyparse();

std::string gen_label()
{
	std::stringstream label;
    label << "temp" << label_i++;
    return label.str();
}

std::string getDominantType(const std::string& tipo1, const std::string& tipo2) {
    if (tipo1 == "float" || tipo2 == "float") {
        return "float";
    } else {
        return "int";
    }
}

atributos implicitTypeCast(const atributos& original, const atributos& destino) {
    atributos result;
    result.label = gen_label();
	
    if (original.tipo != destino.tipo) {
        
    	result.traducao = "\t" + result.label + " = " + "(" + destino.tipo + ")" + original.label + ";\n";
        
    } else {
        // No type casting needed, assign the original value
        result.traducao = "\t" + result.label + " = " + original.label + ";\n";
    }
	
    result.tipo = destino.tipo;
	addVariable(result.label, result.label, result.tipo);
    return result;
}

string printDeclaracoes()
{
	stringstream declaracoes; 
	
	for(int i = 0; i < label_i; i++)
	{
		string variable = "temp" + to_string(i);

		if (reverseTable.find(variable) == reverseTable.end())
		{
			declaracoes << "\tint temp" << i <<";\n";
		}else
		{
			const auto& entry = reverseTable.find(variable)->second;
            string variableType = entry.second;
			if(variableType == "bool")
				variableType = "int";
            const string& variableName = entry.first;
            declaracoes << "\t" << variableType << " " << variable << ";\t\t\t\t// variavel " << variableName << "\n";
		}
		
	}
	
	
	
	return declaracoes.str();
}

int main( int argc, char* argv[] )
{
	yyparse(); //retorna 0 se a gramatica é valida, e 1 para invalida

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}				
