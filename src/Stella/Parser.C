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
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         Stellaparse
#define yylex           Stellalex
#define yyerror         Stellaerror
#define yydebug         Stelladebug
#define yynerrs         Stellanerrs

/* First part of user prologue.  */
#line 22 "Stella.y"

/* Begin C preamble code */

#include <algorithm> /* for std::reverse */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Absyn.H"

#define YYMAXDEPTH 10000000

/* The type yyscan_t is defined by flex, but we need it in the parser already. */
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern YY_BUFFER_STATE Stella_scan_string(const char *str, yyscan_t scanner);
extern void Stella_delete_buffer(YY_BUFFER_STATE buf, yyscan_t scanner);

extern void Stellalex_destroy(yyscan_t scanner);
extern char* Stellaget_text(yyscan_t scanner);

extern yyscan_t Stella_initialize_lexer(FILE * inp);

/* End C preamble code */

#line 105 "Parser.C"

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

#include "Bison.H"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL__ERROR_ = 3,                    /* _ERROR_  */
  YYSYMBOL__BANGEQ = 4,                    /* _BANGEQ  */
  YYSYMBOL__AMP = 5,                       /* _AMP  */
  YYSYMBOL__LPAREN = 6,                    /* _LPAREN  */
  YYSYMBOL__RPAREN = 7,                    /* _RPAREN  */
  YYSYMBOL__STAR = 8,                      /* _STAR  */
  YYSYMBOL__PLUS = 9,                      /* _PLUS  */
  YYSYMBOL__COMMA = 10,                    /* _COMMA  */
  YYSYMBOL__MINUS = 11,                    /* _MINUS  */
  YYSYMBOL__RARROW = 12,                   /* _RARROW  */
  YYSYMBOL__DOT = 13,                      /* _DOT  */
  YYSYMBOL__SLASH = 14,                    /* _SLASH  */
  YYSYMBOL__COLON = 15,                    /* _COLON  */
  YYSYMBOL__COLONEQ = 16,                  /* _COLONEQ  */
  YYSYMBOL__SEMI = 17,                     /* _SEMI  */
  YYSYMBOL__LT = 18,                       /* _LT  */
  YYSYMBOL__LDARROW = 19,                  /* _LDARROW  */
  YYSYMBOL__SYMB_11 = 20,                  /* _SYMB_11  */
  YYSYMBOL__EQ = 21,                       /* _EQ  */
  YYSYMBOL__DEQ = 22,                      /* _DEQ  */
  YYSYMBOL__RDARROW = 23,                  /* _RDARROW  */
  YYSYMBOL__GT = 24,                       /* _GT  */
  YYSYMBOL__GTEQ = 25,                     /* _GTEQ  */
  YYSYMBOL__KW_Bool = 26,                  /* _KW_Bool  */
  YYSYMBOL__KW_Bot = 27,                   /* _KW_Bot  */
  YYSYMBOL__SYMB_27 = 28,                  /* _SYMB_27  */
  YYSYMBOL__SYMB_28 = 29,                  /* _SYMB_28  */
  YYSYMBOL__SYMB_29 = 30,                  /* _SYMB_29  */
  YYSYMBOL__KW_Nat = 31,                   /* _KW_Nat  */
  YYSYMBOL__SYMB_32 = 32,                  /* _SYMB_32  */
  YYSYMBOL__SYMB_31 = 33,                  /* _SYMB_31  */
  YYSYMBOL__SYMB_33 = 34,                  /* _SYMB_33  */
  YYSYMBOL__KW_Top = 35,                   /* _KW_Top  */
  YYSYMBOL__KW_Unit = 36,                  /* _KW_Unit  */
  YYSYMBOL__LBRACK = 37,                   /* _LBRACK  */
  YYSYMBOL__RBRACK = 38,                   /* _RBRACK  */
  YYSYMBOL__KW_and = 39,                   /* _KW_and  */
  YYSYMBOL__KW_as = 40,                    /* _KW_as  */
  YYSYMBOL__KW_cast = 41,                  /* _KW_cast  */
  YYSYMBOL__KW_catch = 42,                 /* _KW_catch  */
  YYSYMBOL__KW_cons = 43,                  /* _KW_cons  */
  YYSYMBOL__KW_core = 44,                  /* _KW_core  */
  YYSYMBOL__KW_else = 45,                  /* _KW_else  */
  YYSYMBOL__KW_exception = 46,             /* _KW_exception  */
  YYSYMBOL__KW_extend = 47,                /* _KW_extend  */
  YYSYMBOL__KW_false = 48,                 /* _KW_false  */
  YYSYMBOL__KW_fix = 49,                   /* _KW_fix  */
  YYSYMBOL__KW_fn = 50,                    /* _KW_fn  */
  YYSYMBOL__KW_fold = 51,                  /* _KW_fold  */
  YYSYMBOL__KW_if = 52,                    /* _KW_if  */
  YYSYMBOL__KW_in = 53,                    /* _KW_in  */
  YYSYMBOL__KW_inl = 54,                   /* _KW_inl  */
  YYSYMBOL__KW_inline = 55,                /* _KW_inline  */
  YYSYMBOL__KW_inr = 56,                   /* _KW_inr  */
  YYSYMBOL__KW_language = 57,              /* _KW_language  */
  YYSYMBOL__KW_let = 58,                   /* _KW_let  */
  YYSYMBOL__KW_letrec = 59,                /* _KW_letrec  */
  YYSYMBOL__KW_match = 60,                 /* _KW_match  */
  YYSYMBOL__KW_new = 61,                   /* _KW_new  */
  YYSYMBOL__KW_not = 62,                   /* _KW_not  */
  YYSYMBOL__KW_or = 63,                    /* _KW_or  */
  YYSYMBOL__SYMB_30 = 64,                  /* _SYMB_30  */
  YYSYMBOL__KW_return = 65,                /* _KW_return  */
  YYSYMBOL__KW_succ = 66,                  /* _KW_succ  */
  YYSYMBOL__KW_then = 67,                  /* _KW_then  */
  YYSYMBOL__KW_throw = 68,                 /* _KW_throw  */
  YYSYMBOL__KW_throws = 69,                /* _KW_throws  */
  YYSYMBOL__KW_true = 70,                  /* _KW_true  */
  YYSYMBOL__KW_try = 71,                   /* _KW_try  */
  YYSYMBOL__KW_type = 72,                  /* _KW_type  */
  YYSYMBOL__KW_unfold = 73,                /* _KW_unfold  */
  YYSYMBOL__KW_unit = 74,                  /* _KW_unit  */
  YYSYMBOL__KW_variant = 75,               /* _KW_variant  */
  YYSYMBOL__KW_with = 76,                  /* _KW_with  */
  YYSYMBOL__LBRACE = 77,                   /* _LBRACE  */
  YYSYMBOL__BAR = 78,                      /* _BAR  */
  YYSYMBOL__SYMB_12 = 79,                  /* _SYMB_12  */
  YYSYMBOL__RBRACE = 80,                   /* _RBRACE  */
  YYSYMBOL__KW_77 = 81,                    /* _KW_77  */
  YYSYMBOL_T_ExtensionName = 82,           /* T_ExtensionName  */
  YYSYMBOL_T_MemoryAddress = 83,           /* T_MemoryAddress  */
  YYSYMBOL_T_StellaIdent = 84,             /* T_StellaIdent  */
  YYSYMBOL__INTEGER_ = 85,                 /* _INTEGER_  */
  YYSYMBOL_YYACCEPT = 86,                  /* $accept  */
  YYSYMBOL_Program = 87,                   /* Program  */
  YYSYMBOL_LanguageDecl = 88,              /* LanguageDecl  */
  YYSYMBOL_Extension = 89,                 /* Extension  */
  YYSYMBOL_ListExtensionName = 90,         /* ListExtensionName  */
  YYSYMBOL_ListExtension = 91,             /* ListExtension  */
  YYSYMBOL_Decl = 92,                      /* Decl  */
  YYSYMBOL_ListDecl = 93,                  /* ListDecl  */
  YYSYMBOL_Annotation = 94,                /* Annotation  */
  YYSYMBOL_ListAnnotation = 95,            /* ListAnnotation  */
  YYSYMBOL_ParamDecl = 96,                 /* ParamDecl  */
  YYSYMBOL_ListParamDecl = 97,             /* ListParamDecl  */
  YYSYMBOL_ReturnType = 98,                /* ReturnType  */
  YYSYMBOL_ThrowType = 99,                 /* ThrowType  */
  YYSYMBOL_Type9 = 100,                    /* Type9  */
  YYSYMBOL_ListType9 = 101,                /* ListType9  */
  YYSYMBOL_MatchCase = 102,                /* MatchCase  */
  YYSYMBOL_ListMatchCase = 103,            /* ListMatchCase  */
  YYSYMBOL_OptionalTyping = 104,           /* OptionalTyping  */
  YYSYMBOL_PatternData = 105,              /* PatternData  */
  YYSYMBOL_ExprData = 106,                 /* ExprData  */
  YYSYMBOL_Pattern = 107,                  /* Pattern  */
  YYSYMBOL_ListPattern = 108,              /* ListPattern  */
  YYSYMBOL_LabelledPattern = 109,          /* LabelledPattern  */
  YYSYMBOL_ListLabelledPattern = 110,      /* ListLabelledPattern  */
  YYSYMBOL_Binding = 111,                  /* Binding  */
  YYSYMBOL_ListBinding = 112,              /* ListBinding  */
  YYSYMBOL_Expr = 113,                     /* Expr  */
  YYSYMBOL_ListExpr = 114,                 /* ListExpr  */
  YYSYMBOL_Expr1 = 115,                    /* Expr1  */
  YYSYMBOL_PatternBinding = 116,           /* PatternBinding  */
  YYSYMBOL_ListPatternBinding = 117,       /* ListPatternBinding  */
  YYSYMBOL_Expr2 = 118,                    /* Expr2  */
  YYSYMBOL_Expr3 = 119,                    /* Expr3  */
  YYSYMBOL_Expr4 = 120,                    /* Expr4  */
  YYSYMBOL_Expr5 = 121,                    /* Expr5  */
  YYSYMBOL_Expr6 = 122,                    /* Expr6  */
  YYSYMBOL_Expr7 = 123,                    /* Expr7  */
  YYSYMBOL_Type = 124,                     /* Type  */
  YYSYMBOL_Type1 = 125,                    /* Type1  */
  YYSYMBOL_Type2 = 126,                    /* Type2  */
  YYSYMBOL_Type3 = 127,                    /* Type3  */
  YYSYMBOL_ListType = 128,                 /* ListType  */
  YYSYMBOL_VariantFieldType = 129,         /* VariantFieldType  */
  YYSYMBOL_ListVariantFieldType = 130,     /* ListVariantFieldType  */
  YYSYMBOL_RecordFieldType = 131,          /* RecordFieldType  */
  YYSYMBOL_ListRecordFieldType = 132       /* ListRecordFieldType  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 97 "Stella.y"

void yyerror(YYLTYPE *loc, yyscan_t scanner, YYSTYPE *result, const char *msg)
{
  fprintf(stderr, "error: %d,%d: %s at %s\n",
    loc->first_line, loc->first_column, msg, Stellaget_text(scanner));
}

int yyparse(yyscan_t scanner, YYSTYPE *result);

extern int yylex(YYSTYPE *lvalp, YYLTYPE *llocp, yyscan_t scanner);

#line 283 "Parser.C"


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
typedef yytype_int16 yy_state_t;

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   665

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  367

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   340


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   249,   249,   255,   257,   259,   260,   261,   263,   264,
     266,   267,   268,   269,   271,   272,   279,   281,   282,   284,
     286,   287,   288,   290,   291,   293,   294,   296,   298,   299,
     301,   303,   304,   305,   307,   308,   310,   311,   313,   314,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   331,   332,   333,   335,   337,   338,
     340,   342,   343,   345,   346,   347,   348,   349,   351,   352,
     353,   355,   356,   357,   359,   361,   362,   364,   365,   366,
     367,   368,   369,   370,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   386,   387,   388,   389,   391,   392,
     393,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   420,   421,   422,   423,   424,
     425,   426,   428,   429,   430,   432,   433,   435,   436,   437,
     438,   439,   441,   442,   443,   444,   445,   446,   447,   448,
     450,   451,   452,   454,   456,   457,   458,   460,   462,   463
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
  "\"end of file\"", "error", "\"invalid token\"", "_ERROR_", "_BANGEQ",
  "_AMP", "_LPAREN", "_RPAREN", "_STAR", "_PLUS", "_COMMA", "_MINUS",
  "_RARROW", "_DOT", "_SLASH", "_COLON", "_COLONEQ", "_SEMI", "_LT",
  "_LDARROW", "_SYMB_11", "_EQ", "_DEQ", "_RDARROW", "_GT", "_GTEQ",
  "_KW_Bool", "_KW_Bot", "_SYMB_27", "_SYMB_28", "_SYMB_29", "_KW_Nat",
  "_SYMB_32", "_SYMB_31", "_SYMB_33", "_KW_Top", "_KW_Unit", "_LBRACK",
  "_RBRACK", "_KW_and", "_KW_as", "_KW_cast", "_KW_catch", "_KW_cons",
  "_KW_core", "_KW_else", "_KW_exception", "_KW_extend", "_KW_false",
  "_KW_fix", "_KW_fn", "_KW_fold", "_KW_if", "_KW_in", "_KW_inl",
  "_KW_inline", "_KW_inr", "_KW_language", "_KW_let", "_KW_letrec",
  "_KW_match", "_KW_new", "_KW_not", "_KW_or", "_SYMB_30", "_KW_return",
  "_KW_succ", "_KW_then", "_KW_throw", "_KW_throws", "_KW_true", "_KW_try",
  "_KW_type", "_KW_unfold", "_KW_unit", "_KW_variant", "_KW_with",
  "_LBRACE", "_BAR", "_SYMB_12", "_RBRACE", "_KW_77", "T_ExtensionName",
  "T_MemoryAddress", "T_StellaIdent", "_INTEGER_", "$accept", "Program",
  "LanguageDecl", "Extension", "ListExtensionName", "ListExtension",
  "Decl", "ListDecl", "Annotation", "ListAnnotation", "ParamDecl",
  "ListParamDecl", "ReturnType", "ThrowType", "Type9", "ListType9",
  "MatchCase", "ListMatchCase", "OptionalTyping", "PatternData",
  "ExprData", "Pattern", "ListPattern", "LabelledPattern",
  "ListLabelledPattern", "Binding", "ListBinding", "Expr", "ListExpr",
  "Expr1", "PatternBinding", "ListPatternBinding", "Expr2", "Expr3",
  "Expr4", "Expr5", "Expr6", "Expr7", "Type", "Type1", "Type2", "Type3",
  "ListType", "VariantFieldType", "ListVariantFieldType",
  "RecordFieldType", "ListRecordFieldType", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-282)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -41,   -22,    29,  -282,    14,  -282,    15,  -282,    -8,    50,
      18,   -13,  -282,   -39,   -12,  -282,   -25,    63,  -282,    53,
      16,    54,    17,  -282,  -282,   -13,   128,    82,   128,    93,
    -282,   564,   128,    19,  -282,  -282,  -282,  -282,  -282,   128,
      98,   528,    30,  -282,  -282,  -282,   106,  -282,   128,  -282,
      37,  -282,   116,   110,   117,    47,    90,   128,   114,   120,
      51,   122,    55,   124,   564,  -282,   125,   135,   139,  -282,
     128,  -282,    19,  -282,  -282,   143,   128,   128,  -282,    67,
    -282,   128,  -282,   128,    37,   140,  -282,  -282,   141,  -282,
    -282,   114,  -282,  -282,  -282,  -282,   128,    87,   128,  -282,
     128,    81,  -282,   150,  -282,  -282,  -282,   128,    -9,  -282,
     222,   222,   458,    77,   160,   161,   162,   163,   164,   165,
     222,   166,  -282,   167,   169,   144,   340,   170,   176,   137,
     137,   399,   177,   178,  -282,   181,   183,  -282,   113,   155,
    -282,   281,  -282,  -282,  -282,   115,   179,   182,   602,     6,
    -282,    13,  -282,   187,  -282,   180,   222,   222,   222,   222,
     222,   222,   190,   159,   222,   222,    37,   128,   146,   222,
     222,   137,   118,   137,  -282,   198,   200,   204,  -282,  -282,
     519,  -282,  -282,   194,   206,   171,   172,   142,   458,   222,
     222,   222,   222,   128,   196,   208,   147,   149,  -282,   222,
     340,   399,   458,   458,   399,   399,   399,   399,   399,   564,
     186,   458,   458,   458,   458,   222,   -32,  -282,   222,   152,
     213,   216,   225,   226,   228,   227,   222,  -282,   229,   234,
     237,   207,   340,   240,   241,    34,   215,   239,   219,   137,
     137,   137,   242,   184,   248,   188,   222,   137,   222,   222,
     137,   253,   254,   255,   259,   189,   247,   222,   191,  -282,
    -282,  -282,  -282,    -2,     6,     6,    -2,    -2,    -2,    -2,
      -2,  -282,   564,     6,  -282,  -282,  -282,   260,  -282,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,   222,  -282,   222,
    -282,   202,    22,   232,  -282,  -282,  -282,   137,   137,   212,
     137,  -282,   287,   290,   291,   137,  -282,   218,  -282,  -282,
    -282,  -282,  -282,   230,   220,   280,  -282,  -282,  -282,  -282,
     -34,    22,  -282,   196,  -282,  -282,  -282,   294,   305,   251,
    -282,   340,   310,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
     242,  -282,   137,  -282,   222,   243,   244,  -282,   222,  -282,
     222,  -282,  -282,  -282,  -282,   137,   222,   312,   245,   299,
     246,  -282,  -282,   222,  -282,   256,  -282
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     8,     0,     1,    14,     3,     0,     0,
      17,     5,     9,     0,     0,    15,     0,     6,     4,     0,
       0,     0,     0,    16,    18,     5,     0,     0,     0,     0,
       7,     0,     0,   154,   142,   146,   143,   145,   144,     0,
       0,   150,     0,   148,    12,   134,   136,   141,     0,    11,
      20,   147,     0,    34,   155,     0,     0,   150,   148,   151,
       0,   158,     0,     0,     0,    13,     0,    21,     0,   149,
       0,   153,   154,   139,   140,     0,     0,   150,   137,     0,
     138,     0,   135,     0,    20,    23,    35,   156,     0,   157,
     152,     0,   159,   133,    19,    22,     0,    25,     0,    24,
       0,     0,   132,    28,    26,    27,    14,     0,    17,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      68,     0,   126,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,   125,     0,     0,
     127,    68,   129,   130,   128,     0,    67,    73,    83,    93,
      97,   100,   124,     0,    99,    38,     0,     0,     0,     0,
       0,     0,    69,     0,     0,     0,    20,     0,     0,     0,
       0,     0,     0,    54,    47,     0,     0,     0,    48,    49,
      54,    52,    50,     0,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,    61,     0,     0,    10,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,     0,   131,     0,     0,
       0,     0,     0,     0,     0,     0,    68,    89,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    55,     0,     0,
       0,     0,    52,     0,    58,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,   105,
     104,    63,    71,    82,    90,    91,    77,    78,    81,    79,
      80,    84,     0,    92,    94,    95,    96,     0,   102,   103,
      39,    87,   107,   108,   109,   119,   118,     0,    70,     0,
     120,     0,     0,     0,   114,   115,    53,     0,     0,     0,
      54,    45,     0,     0,     0,     0,    43,     0,    44,    74,
      76,    65,    66,    32,     0,     0,    98,   117,   116,   111,
       0,     0,    60,     0,    62,    85,   101,     0,     0,     0,
     122,     0,     0,    37,    40,    56,    41,    42,    51,    57,
       0,    59,    31,    88,     0,     0,     0,   123,     0,   106,
       0,    72,    46,    33,    30,     0,     0,     0,     0,     0,
       0,   121,    86,     0,   113,     0,   112
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -282,  -282,  -282,  -282,   298,  -282,  -282,   221,  -282,  -282,
    -282,   -78,  -282,  -282,  -282,   231,  -282,   -14,  -282,  -282,
    -282,  -156,  -176,  -282,    27,  -282,    86,  -110,  -128,  -123,
    -282,  -125,   236,   -88,  -145,  -102,  -282,  -281,    -5,  -282,
     -29,  -282,   -45,  -282,   278,  -282,   274
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     9,    18,     6,    15,    10,    24,    16,
      67,    68,    97,   101,   103,   104,   313,   314,    71,   299,
     219,   183,   238,   244,   245,   195,   196,   162,   163,   146,
     184,   185,   147,   148,   149,   150,   151,   152,    59,    45,
      46,    47,    60,    54,    55,    61,    62
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     145,   153,    51,   168,   243,   186,    95,   202,   345,   203,
     154,   330,    75,   197,   212,   235,     1,   237,    -2,   215,
     213,    44,     4,    49,   237,    22,   216,    52,   111,     5,
      23,     7,    90,    19,    56,    82,    20,    13,   209,   210,
     347,   296,   346,    65,   297,   214,   220,   221,   222,   223,
     224,   225,   278,   279,   228,   229,   110,   264,   265,   233,
     234,   211,     8,    14,    13,    86,   273,    12,    11,    17,
     122,    89,    21,    25,    26,    28,    93,   262,    94,   252,
     253,   254,   255,   302,   303,   304,   251,   277,   230,   261,
      14,    99,   137,   102,   315,   105,   140,    48,   288,    50,
      27,    29,   105,    53,    57,   142,   143,   144,   280,   293,
     274,   275,   276,   263,    63,    64,   266,   267,   268,   269,
     270,    66,   310,    69,   335,    70,    73,    72,    74,    76,
      77,    78,    79,    31,    32,    80,   309,    81,   311,   312,
      83,   332,   333,   171,   237,    84,    85,   322,    33,   339,
      88,    91,    96,    98,    34,    35,   100,   172,   106,    36,
     107,   155,   231,    37,    38,    39,   156,   157,   158,   159,
     160,   161,   164,   165,   173,   166,   169,   327,    40,   328,
     271,   167,   170,   188,   189,   174,   315,   190,   256,   191,
     192,   175,   193,   176,   217,   198,   199,   227,   200,   359,
     226,   218,   236,   177,   239,    41,   240,   178,   351,    42,
     241,   179,    43,   232,   180,   246,   247,   257,   258,   250,
     282,   181,   182,   283,   248,   249,   272,   259,   111,   260,
     112,   281,   284,   285,   354,   286,   298,   287,   357,   289,
     358,   290,   113,   325,   291,   292,   360,   294,   295,   300,
     114,   115,   116,   365,   117,   118,   119,   301,   307,   120,
     316,   317,   318,   305,   306,   121,   319,   326,   308,   320,
     122,   123,   124,   125,   126,   323,   127,   331,   128,   329,
     129,   130,   131,   132,   133,   321,   134,   111,   135,   112,
     136,   334,   137,   138,   336,   139,   140,   337,   338,   141,
     343,   113,   340,   344,   348,   142,   143,   144,   342,   114,
     115,   116,   349,   117,   118,   119,   350,   352,   120,   361,
     355,   356,   363,    30,   121,   362,   364,   108,   353,   122,
     123,   124,   125,   126,   341,   127,   366,   128,   109,   129,
     130,   131,   132,   133,   324,   134,   111,   135,   112,   136,
      87,   137,   138,    92,   139,   140,     0,     0,   141,     0,
     113,     0,     0,     0,   142,   194,   144,   187,   114,   115,
     116,     0,   117,   118,   119,     0,     0,   120,     0,     0,
       0,     0,     0,   121,     0,     0,     0,     0,   122,   123,
     124,   125,   126,     0,   127,     0,   128,     0,     0,     0,
     131,   132,   133,     0,   134,   111,   135,   112,   136,     0,
     137,   138,     0,   139,   140,     0,     0,   141,     0,   113,
       0,     0,     0,   142,   143,   144,     0,   114,   115,   116,
       0,   117,   118,   119,     0,     0,   120,     0,     0,     0,
       0,     0,   121,     0,     0,     0,     0,   122,   123,   124,
     125,     0,     0,   127,     0,   128,     0,     0,     0,   131,
     132,   133,     0,   134,   111,   135,   112,   136,     0,   137,
     138,     0,   139,   140,     0,     0,   141,     0,     0,     0,
       0,     0,   142,   143,   144,     0,   114,   115,   116,     0,
     117,   118,   119,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,     0,   122,   123,     0,   125,
       0,     0,   127,     0,   128,     0,     0,     0,     0,   132,
     133,     0,   134,     0,   135,   171,   136,     0,   137,   138,
       0,   139,   140,    31,    32,   141,     0,     0,     0,   172,
       0,   142,   143,   144,     0,     0,     0,     0,    33,     0,
       0,     0,     0,     0,    34,    35,   173,     0,     0,    36,
       0,     0,     0,    37,    38,    39,     0,   174,     0,    31,
      32,     0,     0,   175,     0,   176,     0,     0,    40,     0,
       0,     0,     0,     0,    33,   177,     0,     0,     0,   178,
      34,    35,     0,   179,     0,    36,   180,     0,     0,    37,
      38,    39,     0,   242,   182,    41,   201,     0,     0,    42,
       0,   202,    58,   203,     0,     0,     0,     0,     0,     0,
     204,   205,     0,     0,   206,     0,   207,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,   209,   210,     0,     0,     0,     0,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   211
};

static const yytype_int16 yycheck[] =
{
     110,   111,    31,   126,   180,   130,    84,     9,    42,    11,
     112,   292,    57,   141,     8,   171,    57,   173,     0,     6,
      14,    26,    44,    28,   180,    50,    13,    32,     6,     0,
      55,    17,    77,    72,    39,    64,    75,    46,    40,    41,
     321,     7,    76,    48,    10,    39,   156,   157,   158,   159,
     160,   161,    84,    85,   164,   165,    65,   202,   203,   169,
     170,    63,    47,    72,    46,    70,   211,    17,    76,    82,
      48,    76,    84,    10,    21,    21,    81,   200,    83,   189,
     190,   191,   192,   239,   240,   241,   188,   215,   166,   199,
      72,    96,    70,    98,   250,   100,    74,    15,   226,     6,
      84,    84,   107,    84,     6,    83,    84,    85,   218,   232,
     212,   213,   214,   201,    84,     9,   204,   205,   206,   207,
     208,    84,   247,     7,   300,    15,    79,    10,    38,    15,
      10,    80,    10,     5,     6,    80,   246,    13,   248,   249,
      15,   297,   298,     6,   300,    10,     7,   257,    20,   305,
       7,    84,    12,    12,    26,    27,    69,    20,    77,    31,
      10,    84,   167,    35,    36,    37,     6,     6,     6,     6,
       6,     6,     6,     6,    37,     6,     6,   287,    50,   289,
     209,    37,     6,     6,     6,    48,   342,     6,   193,     6,
      77,    54,    37,    56,     7,    80,    17,    38,    16,   355,
      10,    21,    84,    66,     6,    77,     6,    70,   331,    81,
       6,    74,    84,    67,    77,    21,    10,    21,    10,    77,
       7,    84,    85,     7,    53,    53,    40,    80,     6,    80,
       8,    79,     7,     7,   344,     7,    21,    10,   348,    10,
     350,     7,    20,   272,     7,    38,   356,     7,     7,    10,
      28,    29,    30,   363,    32,    33,    34,    38,    10,    37,
       7,     7,     7,    21,    80,    43,     7,     7,    80,    80,
      48,    49,    50,    51,    52,    84,    54,    45,    56,    77,
      58,    59,    60,    61,    62,    38,    64,     6,    66,     8,
      68,    79,    70,    71,     7,    73,    74,     7,     7,    77,
      80,    20,    84,    23,    10,    83,    84,    85,    78,    28,
      29,    30,     7,    32,    33,    34,    65,     7,    37,     7,
      77,    77,    23,    25,    43,    80,    80,   106,   342,    48,
      49,    50,    51,    52,   307,    54,    80,    56,   107,    58,
      59,    60,    61,    62,   258,    64,     6,    66,     8,    68,
      72,    70,    71,    79,    73,    74,    -1,    -1,    77,    -1,
      20,    -1,    -1,    -1,    83,    84,    85,   131,    28,    29,
      30,    -1,    32,    33,    34,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    -1,    54,    -1,    56,    -1,    -1,    -1,
      60,    61,    62,    -1,    64,     6,    66,     8,    68,    -1,
      70,    71,    -1,    73,    74,    -1,    -1,    77,    -1,    20,
      -1,    -1,    -1,    83,    84,    85,    -1,    28,    29,    30,
      -1,    32,    33,    34,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    -1,    -1,    54,    -1,    56,    -1,    -1,    -1,    60,
      61,    62,    -1,    64,     6,    66,     8,    68,    -1,    70,
      71,    -1,    73,    74,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    -1,    28,    29,    30,    -1,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    48,    49,    -1,    51,
      -1,    -1,    54,    -1,    56,    -1,    -1,    -1,    -1,    61,
      62,    -1,    64,    -1,    66,     6,    68,    -1,    70,    71,
      -1,    73,    74,     5,     6,    77,    -1,    -1,    -1,    20,
      -1,    83,    84,    85,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    37,    -1,    -1,    31,
      -1,    -1,    -1,    35,    36,    37,    -1,    48,    -1,     5,
       6,    -1,    -1,    54,    -1,    56,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    20,    66,    -1,    -1,    -1,    70,
      26,    27,    -1,    74,    -1,    31,    77,    -1,    -1,    35,
      36,    37,    -1,    84,    85,    77,     4,    -1,    -1,    81,
      -1,     9,    84,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,    22,    -1,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    40,    41,    -1,    -1,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    57,    87,    88,    44,     0,    91,    17,    47,    89,
      93,    76,    17,    46,    72,    92,    95,    82,    90,    72,
      75,    84,    50,    55,    94,    10,    21,    84,    21,    84,
      90,     5,     6,    20,    26,    27,    31,    35,    36,    37,
      50,    77,    81,    84,   124,   125,   126,   127,    15,   124,
       6,   126,   124,    84,   129,   130,   124,     6,    84,   124,
     128,   131,   132,    84,     9,   124,    84,    96,    97,     7,
      15,   104,    10,    79,    38,   128,    15,    10,    80,    10,
      80,    13,   126,    15,    10,     7,   124,   130,     7,   124,
     128,    84,   132,   124,   124,    97,    12,    98,    12,   124,
      69,    99,   124,   100,   101,   124,    77,    10,    93,   101,
      65,     6,     8,    20,    28,    29,    30,    32,    33,    34,
      37,    43,    48,    49,    50,    51,    52,    54,    56,    58,
      59,    60,    61,    62,    64,    66,    68,    70,    71,    73,
      74,    77,    83,    84,    85,   113,   115,   118,   119,   120,
     121,   122,   123,   113,   121,    84,     6,     6,     6,     6,
       6,     6,   113,   114,     6,     6,     6,    37,   115,     6,
       6,     6,    20,    37,    48,    54,    56,    66,    70,    74,
      77,    84,    85,   107,   116,   117,   117,   118,     6,     6,
       6,     6,    77,    37,    84,   111,   112,   114,    80,    17,
      16,     4,     9,    11,    18,    19,    22,    24,    25,    40,
      41,    63,     8,    14,    39,     6,    13,     7,    21,   106,
     113,   113,   113,   113,   113,   113,    10,    38,   113,   113,
      97,   124,    67,   113,   113,   107,    84,   107,   108,     6,
       6,     6,    84,   108,   109,   110,    21,    10,    53,    53,
      77,   121,   113,   113,   113,   113,   124,    21,    10,    80,
      80,   113,   115,   119,   120,   120,   119,   119,   119,   119,
     119,   126,    40,   120,   121,   121,   121,   114,    84,    85,
     113,    79,     7,     7,     7,     7,     7,    10,   114,    10,
       7,     7,    38,   115,     7,     7,     7,    10,    21,   105,
      10,    38,   107,   107,   107,    21,    80,    10,    80,   113,
     117,   113,   113,   102,   103,   107,     7,     7,     7,     7,
      80,    38,   113,    84,   112,   126,     7,   113,   113,    77,
     123,    45,   107,   107,    79,   108,     7,     7,     7,   107,
      84,   110,    78,    80,    23,    42,    76,   123,    10,     7,
      65,   115,     7,   103,   113,    77,    77,   113,   113,   107,
     113,     7,    80,    23,    80,   113,    80
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    88,    89,    90,    90,    90,    91,    91,
      92,    92,    92,    92,    93,    93,    94,    95,    95,    96,
      97,    97,    97,    98,    98,    99,    99,   100,   101,   101,
     102,   103,   103,   103,   104,   104,   105,   105,   106,   106,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   108,   108,   108,   109,   110,   110,
     111,   112,   112,   113,   113,   113,   113,   113,   114,   114,
     114,   115,   115,   115,   116,   117,   117,   118,   118,   118,
     118,   118,   118,   118,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   120,   120,   120,   120,   121,   121,
     121,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   123,   123,   123,   123,   123,
     123,   123,   124,   124,   124,   125,   125,   126,   126,   126,
     126,   126,   127,   127,   127,   127,   127,   127,   127,   127,
     128,   128,   128,   129,   130,   130,   130,   131,   132,   132
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     3,     0,     1,     3,     0,     3,
      13,     4,     4,     5,     0,     2,     1,     0,     2,     3,
       0,     1,     3,     0,     2,     0,     2,     1,     1,     3,
       3,     0,     1,     3,     0,     2,     0,     2,     0,     2,
       4,     4,     4,     3,     3,     3,     5,     1,     1,     1,
       1,     4,     1,     3,     0,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     2,     4,     4,     1,     0,     1,
       3,     3,     6,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     4,     8,     4,     5,     3,
       3,     3,     3,     1,     3,     3,     3,     1,     4,     2,
       1,     4,     3,     3,     3,     3,     6,     4,     4,     4,
       1,     4,    10,     8,     4,     4,     4,     4,     4,     4,
       4,     8,     5,     5,     1,     1,     1,     1,     1,     1,
       1,     3,     6,     4,     1,     3,     1,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       0,     1,     3,     2,     0,     1,     3,     3,     1,     3
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
        yyerror (&yylloc, scanner, result, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, scanner, result); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, YYSTYPE *result)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (scanner);
  YY_USE (result);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, YYSTYPE *result)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, scanner, result);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, yyscan_t scanner, YYSTYPE *result)
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), scanner, result);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, scanner, result); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t scanner, YYSTYPE *result)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (scanner);
  YY_USE (result);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t scanner, YYSTYPE *result)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, scanner);
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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: LanguageDecl ListExtension ListDecl  */
#line 249 "Stella.y"
                                              { (yyval.program_) = new Stella::AProgram((yyvsp[-2].languagedecl_), (yyvsp[-1].listextension_), (yyvsp[0].listdecl_)); (yyval.program_)->line_number = (yyloc).first_line; (yyval.program_)->char_number = (yyloc).first_column; result->program_ = (yyval.program_); }
#line 1677 "Parser.C"
    break;

  case 3: /* LanguageDecl: _KW_language _KW_core _SEMI  */
#line 255 "Stella.y"
                                           { (yyval.languagedecl_) = new Stella::LanguageCore(); (yyval.languagedecl_)->line_number = (yyloc).first_line; (yyval.languagedecl_)->char_number = (yyloc).first_column; result->languagedecl_ = (yyval.languagedecl_); }
#line 1683 "Parser.C"
    break;

  case 4: /* Extension: _KW_extend _KW_with ListExtensionName  */
#line 257 "Stella.y"
                                                  { std::reverse((yyvsp[0].listextensionname_)->begin(),(yyvsp[0].listextensionname_)->end()) ;(yyval.extension_) = new Stella::AnExtension((yyvsp[0].listextensionname_)); (yyval.extension_)->line_number = (yyloc).first_line; (yyval.extension_)->char_number = (yyloc).first_column; result->extension_ = (yyval.extension_); }
#line 1689 "Parser.C"
    break;

  case 5: /* ListExtensionName: %empty  */
#line 259 "Stella.y"
                                { (yyval.listextensionname_) = new Stella::ListExtensionName(); result->listextensionname_ = (yyval.listextensionname_); }
#line 1695 "Parser.C"
    break;

  case 6: /* ListExtensionName: T_ExtensionName  */
#line 260 "Stella.y"
                    { (yyval.listextensionname_) = new Stella::ListExtensionName(); (yyval.listextensionname_)->push_back((yyvsp[0]._string)); result->listextensionname_ = (yyval.listextensionname_); }
#line 1701 "Parser.C"
    break;

  case 7: /* ListExtensionName: T_ExtensionName _COMMA ListExtensionName  */
#line 261 "Stella.y"
                                             { (yyvsp[0].listextensionname_)->push_back((yyvsp[-2]._string)); (yyval.listextensionname_) = (yyvsp[0].listextensionname_); result->listextensionname_ = (yyval.listextensionname_); }
#line 1707 "Parser.C"
    break;

  case 8: /* ListExtension: %empty  */
#line 263 "Stella.y"
                            { (yyval.listextension_) = new Stella::ListExtension(); result->listextension_ = (yyval.listextension_); }
#line 1713 "Parser.C"
    break;

  case 9: /* ListExtension: ListExtension Extension _SEMI  */
#line 264 "Stella.y"
                                  { (yyvsp[-2].listextension_)->push_back((yyvsp[-1].extension_)); (yyval.listextension_) = (yyvsp[-2].listextension_); result->listextension_ = (yyval.listextension_); }
#line 1719 "Parser.C"
    break;

  case 10: /* Decl: ListAnnotation _KW_fn T_StellaIdent _LPAREN ListParamDecl _RPAREN ReturnType ThrowType _LBRACE ListDecl _KW_return Expr _RBRACE  */
#line 266 "Stella.y"
                                                                                                                                       { std::reverse((yyvsp[-8].listparamdecl_)->begin(),(yyvsp[-8].listparamdecl_)->end()) ;(yyval.decl_) = new Stella::DeclFun((yyvsp[-12].listannotation_), (yyvsp[-10]._string), (yyvsp[-8].listparamdecl_), (yyvsp[-6].returntype_), (yyvsp[-5].throwtype_), (yyvsp[-3].listdecl_), (yyvsp[-1].expr_)); (yyval.decl_)->line_number = (yyloc).first_line; (yyval.decl_)->char_number = (yyloc).first_column; result->decl_ = (yyval.decl_); }
#line 1725 "Parser.C"
    break;

  case 11: /* Decl: _KW_type T_StellaIdent _EQ Type  */
#line 267 "Stella.y"
                                    { (yyval.decl_) = new Stella::DeclTypeAlias((yyvsp[-2]._string), (yyvsp[0].type_)); (yyval.decl_)->line_number = (yyloc).first_line; (yyval.decl_)->char_number = (yyloc).first_column; result->decl_ = (yyval.decl_); }
#line 1731 "Parser.C"
    break;

  case 12: /* Decl: _KW_exception _KW_type _EQ Type  */
#line 268 "Stella.y"
                                    { (yyval.decl_) = new Stella::DeclExceptionType((yyvsp[0].type_)); (yyval.decl_)->line_number = (yyloc).first_line; (yyval.decl_)->char_number = (yyloc).first_column; result->decl_ = (yyval.decl_); }
#line 1737 "Parser.C"
    break;

  case 13: /* Decl: _KW_exception _KW_variant T_StellaIdent _COLON Type  */
#line 269 "Stella.y"
                                                        { (yyval.decl_) = new Stella::DeclExceptionVariant((yyvsp[-2]._string), (yyvsp[0].type_)); (yyval.decl_)->line_number = (yyloc).first_line; (yyval.decl_)->char_number = (yyloc).first_column; result->decl_ = (yyval.decl_); }
#line 1743 "Parser.C"
    break;

  case 14: /* ListDecl: %empty  */
#line 271 "Stella.y"
                       { (yyval.listdecl_) = new Stella::ListDecl(); result->listdecl_ = (yyval.listdecl_); }
#line 1749 "Parser.C"
    break;

  case 15: /* ListDecl: ListDecl Decl  */
#line 272 "Stella.y"
                  { (yyvsp[-1].listdecl_)->push_back((yyvsp[0].decl_)); (yyval.listdecl_) = (yyvsp[-1].listdecl_); result->listdecl_ = (yyval.listdecl_); }
#line 1755 "Parser.C"
    break;

  case 16: /* Annotation: _KW_inline  */
#line 279 "Stella.y"
                        { (yyval.annotation_) = new Stella::InlineAnnotation(); (yyval.annotation_)->line_number = (yyloc).first_line; (yyval.annotation_)->char_number = (yyloc).first_column; result->annotation_ = (yyval.annotation_); }
#line 1761 "Parser.C"
    break;

  case 17: /* ListAnnotation: %empty  */
#line 281 "Stella.y"
                             { (yyval.listannotation_) = new Stella::ListAnnotation(); result->listannotation_ = (yyval.listannotation_); }
#line 1767 "Parser.C"
    break;

  case 18: /* ListAnnotation: ListAnnotation Annotation  */
#line 282 "Stella.y"
                              { (yyvsp[-1].listannotation_)->push_back((yyvsp[0].annotation_)); (yyval.listannotation_) = (yyvsp[-1].listannotation_); result->listannotation_ = (yyval.listannotation_); }
#line 1773 "Parser.C"
    break;

  case 19: /* ParamDecl: T_StellaIdent _COLON Type  */
#line 284 "Stella.y"
                                      { (yyval.paramdecl_) = new Stella::AParamDecl((yyvsp[-2]._string), (yyvsp[0].type_)); (yyval.paramdecl_)->line_number = (yyloc).first_line; (yyval.paramdecl_)->char_number = (yyloc).first_column; result->paramdecl_ = (yyval.paramdecl_); }
#line 1779 "Parser.C"
    break;

  case 20: /* ListParamDecl: %empty  */
#line 286 "Stella.y"
                            { (yyval.listparamdecl_) = new Stella::ListParamDecl(); result->listparamdecl_ = (yyval.listparamdecl_); }
#line 1785 "Parser.C"
    break;

  case 21: /* ListParamDecl: ParamDecl  */
#line 287 "Stella.y"
              { (yyval.listparamdecl_) = new Stella::ListParamDecl(); (yyval.listparamdecl_)->push_back((yyvsp[0].paramdecl_)); result->listparamdecl_ = (yyval.listparamdecl_); }
#line 1791 "Parser.C"
    break;

  case 22: /* ListParamDecl: ParamDecl _COMMA ListParamDecl  */
#line 288 "Stella.y"
                                   { (yyvsp[0].listparamdecl_)->push_back((yyvsp[-2].paramdecl_)); (yyval.listparamdecl_) = (yyvsp[0].listparamdecl_); result->listparamdecl_ = (yyval.listparamdecl_); }
#line 1797 "Parser.C"
    break;

  case 23: /* ReturnType: %empty  */
#line 290 "Stella.y"
                         { (yyval.returntype_) = new Stella::NoReturnType(); (yyval.returntype_)->line_number = (yyloc).first_line; (yyval.returntype_)->char_number = (yyloc).first_column; result->returntype_ = (yyval.returntype_); }
#line 1803 "Parser.C"
    break;

  case 24: /* ReturnType: _RARROW Type  */
#line 291 "Stella.y"
                 { (yyval.returntype_) = new Stella::SomeReturnType((yyvsp[0].type_)); (yyval.returntype_)->line_number = (yyloc).first_line; (yyval.returntype_)->char_number = (yyloc).first_column; result->returntype_ = (yyval.returntype_); }
#line 1809 "Parser.C"
    break;

  case 25: /* ThrowType: %empty  */
#line 293 "Stella.y"
                        { (yyval.throwtype_) = new Stella::NoThrowType(); (yyval.throwtype_)->line_number = (yyloc).first_line; (yyval.throwtype_)->char_number = (yyloc).first_column; result->throwtype_ = (yyval.throwtype_); }
#line 1815 "Parser.C"
    break;

  case 26: /* ThrowType: _KW_throws ListType9  */
#line 294 "Stella.y"
                         { std::reverse((yyvsp[0].listtype_)->begin(),(yyvsp[0].listtype_)->end()) ;(yyval.throwtype_) = new Stella::SomeThrowType((yyvsp[0].listtype_)); (yyval.throwtype_)->line_number = (yyloc).first_line; (yyval.throwtype_)->char_number = (yyloc).first_column; result->throwtype_ = (yyval.throwtype_); }
#line 1821 "Parser.C"
    break;

  case 27: /* Type9: Type  */
#line 296 "Stella.y"
             { (yyval.type_) = (yyvsp[0].type_); (yyval.type_)->line_number = (yyloc).first_line; (yyval.type_)->char_number = (yyloc).first_column; result->type_ = (yyval.type_); }
#line 1827 "Parser.C"
    break;

  case 28: /* ListType9: Type9  */
#line 298 "Stella.y"
                  { (yyval.listtype_) = new Stella::ListType(); (yyval.listtype_)->push_back((yyvsp[0].type_)); result->listtype_ = (yyval.listtype_); }
#line 1833 "Parser.C"
    break;

  case 29: /* ListType9: Type9 _COMMA ListType9  */
#line 299 "Stella.y"
                           { (yyvsp[0].listtype_)->push_back((yyvsp[-2].type_)); (yyval.listtype_) = (yyvsp[0].listtype_); result->listtype_ = (yyval.listtype_); }
#line 1839 "Parser.C"
    break;

  case 30: /* MatchCase: Pattern _RDARROW Expr  */
#line 301 "Stella.y"
                                  { (yyval.matchcase_) = new Stella::AMatchCase((yyvsp[-2].pattern_), (yyvsp[0].expr_)); (yyval.matchcase_)->line_number = (yyloc).first_line; (yyval.matchcase_)->char_number = (yyloc).first_column; result->matchcase_ = (yyval.matchcase_); }
#line 1845 "Parser.C"
    break;

  case 31: /* ListMatchCase: %empty  */
#line 303 "Stella.y"
                            { (yyval.listmatchcase_) = new Stella::ListMatchCase(); result->listmatchcase_ = (yyval.listmatchcase_); }
#line 1851 "Parser.C"
    break;

  case 32: /* ListMatchCase: MatchCase  */
#line 304 "Stella.y"
              { (yyval.listmatchcase_) = new Stella::ListMatchCase(); (yyval.listmatchcase_)->push_back((yyvsp[0].matchcase_)); result->listmatchcase_ = (yyval.listmatchcase_); }
#line 1857 "Parser.C"
    break;

  case 33: /* ListMatchCase: MatchCase _BAR ListMatchCase  */
#line 305 "Stella.y"
                                 { (yyvsp[0].listmatchcase_)->push_back((yyvsp[-2].matchcase_)); (yyval.listmatchcase_) = (yyvsp[0].listmatchcase_); result->listmatchcase_ = (yyval.listmatchcase_); }
#line 1863 "Parser.C"
    break;

  case 34: /* OptionalTyping: %empty  */
#line 307 "Stella.y"
                             { (yyval.optionaltyping_) = new Stella::NoTyping(); (yyval.optionaltyping_)->line_number = (yyloc).first_line; (yyval.optionaltyping_)->char_number = (yyloc).first_column; result->optionaltyping_ = (yyval.optionaltyping_); }
#line 1869 "Parser.C"
    break;

  case 35: /* OptionalTyping: _COLON Type  */
#line 308 "Stella.y"
                { (yyval.optionaltyping_) = new Stella::SomeTyping((yyvsp[0].type_)); (yyval.optionaltyping_)->line_number = (yyloc).first_line; (yyval.optionaltyping_)->char_number = (yyloc).first_column; result->optionaltyping_ = (yyval.optionaltyping_); }
#line 1875 "Parser.C"
    break;

  case 36: /* PatternData: %empty  */
#line 310 "Stella.y"
                          { (yyval.patterndata_) = new Stella::NoPatternData(); (yyval.patterndata_)->line_number = (yyloc).first_line; (yyval.patterndata_)->char_number = (yyloc).first_column; result->patterndata_ = (yyval.patterndata_); }
#line 1881 "Parser.C"
    break;

  case 37: /* PatternData: _EQ Pattern  */
#line 311 "Stella.y"
                { (yyval.patterndata_) = new Stella::SomePatternData((yyvsp[0].pattern_)); (yyval.patterndata_)->line_number = (yyloc).first_line; (yyval.patterndata_)->char_number = (yyloc).first_column; result->patterndata_ = (yyval.patterndata_); }
#line 1887 "Parser.C"
    break;

  case 38: /* ExprData: %empty  */
#line 313 "Stella.y"
                       { (yyval.exprdata_) = new Stella::NoExprData(); (yyval.exprdata_)->line_number = (yyloc).first_line; (yyval.exprdata_)->char_number = (yyloc).first_column; result->exprdata_ = (yyval.exprdata_); }
#line 1893 "Parser.C"
    break;

  case 39: /* ExprData: _EQ Expr  */
#line 314 "Stella.y"
             { (yyval.exprdata_) = new Stella::SomeExprData((yyvsp[0].expr_)); (yyval.exprdata_)->line_number = (yyloc).first_line; (yyval.exprdata_)->char_number = (yyloc).first_column; result->exprdata_ = (yyval.exprdata_); }
#line 1899 "Parser.C"
    break;

  case 40: /* Pattern: _SYMB_11 T_StellaIdent PatternData _SYMB_12  */
#line 316 "Stella.y"
                                                      { (yyval.pattern_) = new Stella::PatternVariant((yyvsp[-2]._string), (yyvsp[-1].patterndata_)); (yyval.pattern_)->line_number = (yyloc).first_line; (yyval.pattern_)->char_number = (yyloc).first_column; result->pattern_ = (yyval.pattern_); }
#line 1905 "Parser.C"
    break;

  case 41: /* Pattern: _KW_inl _LPAREN Pattern _RPAREN  */
#line 317 "Stella.y"
                                    { (yyval.pattern_) = new Stella::PatternInl((yyvsp[-1].pattern_)); (yyval.pattern_)->line_number = (yyloc).first_line; (yyval.pattern_)->char_number = (yyloc).first_column; result->pattern_ = (yyval.pattern_); }
#line 1911 "Parser.C"
    break;

  case 42: /* Pattern: _KW_inr _LPAREN Pattern _RPAREN  */
#line 318 "Stella.y"
                                    { (yyval.pattern_) = new Stella::PatternInr((yyvsp[-1].pattern_)); (yyval.pattern_)->line_number = (yyloc).first_line; (yyval.pattern_)->char_number = (yyloc).first_column; result->pattern_ = (yyval.pattern_); }
#line 1917 "Parser.C"
    break;

  case 43: /* Pattern: _LBRACE ListPattern _RBRACE  */
#line 319 "Stella.y"
                                { std::reverse((yyvsp[-1].listpattern_)->begin(),(yyvsp[-1].listpattern_)->end()) ;(yyval.pattern_) = new Stella::PatternTuple((yyvsp[-1].listpattern_)); (yyval.pattern_)->line_number = (yyloc).first_line; (yyval.pattern_)->char_number = (yyloc).first_column; result->pattern_ = (yyval.pattern_); }
#line 1923 "Parser.C"
    break;

  case 44: /* Pattern: _LBRACE ListLabelledPattern _RBRACE  */
#line 320 "Stella.y"
                                        { std::reverse((yyvsp[-1].listlabelledpattern_)->begin(),(yyvsp[-1].listlabelledpattern_)->end()) ;(yyval.pattern_) = new Stella::PatternRecord((yyvsp[-1].listlabelledpattern_)); (yyval.pattern_)->line_number = (yyloc).first_line; (yyval.pattern_)->char_number = (yyloc).first_column; result->pattern_ = (yyval.pattern_); }
#line 1929 "Parser.C"
    break;

  case 45: /* Pattern: _LBRACK ListPattern _RBRACK  */
#line 321 "Stella.y"
                                { std::reverse((yyvsp[-1].listpattern_)->begin(),(yyvsp[-1].listpattern_)->end()) ;(yyval.pattern_) = new Stella::PatternList((yyvsp[-1].listpattern_)); (yyval.pattern_)->line_number = (yyloc).first_line; (yyval.pattern_)->char_number = (yyloc).first_column; result->pattern_ = (yyval.pattern_); }
#line 1935 "Parser.C"
    break;

  case 46: /* Pattern: _LPAREN Pattern _COMMA Pattern _RPAREN  */
#line 322 "Stella.y"
                                           { (yyval.pattern_) = new Stella::PatternCons((yyvsp[-3].pattern_), (yyvsp[-1].pattern_)); (yyval.pattern_)->line_number = (yyloc).first_line; (yyval.pattern_)->char_number = (yyloc).first_column; result->pattern_ = (yyval.pattern_); }
#line 1941 "Parser.C"
    break;

  case 47: /* Pattern: _KW_false  */
#line 323 "Stella.y"
              { (yyval.pattern_) = new Stella::PatternFalse(); (yyval.pattern_)->line_number = (yyloc).first_line; (yyval.pattern_)->char_number = (yyloc).first_column; result->pattern_ = (yyval.pattern_); }
#line 1947 "Parser.C"
    break;

  case 48: /* Pattern: _KW_true  */
#line 324 "Stella.y"
             { (yyval.pattern_) = new Stella::PatternTrue(); (yyval.pattern_)->line_number = (yyloc).first_line; (yyval.pattern_)->char_number = (yyloc).first_column; result->pattern_ = (yyval.pattern_); }
#line 1953 "Parser.C"
    break;

  case 49: /* Pattern: _KW_unit  */
#line 325 "Stella.y"
             { (yyval.pattern_) = new Stella::PatternUnit(); (yyval.pattern_)->line_number = (yyloc).first_line; (yyval.pattern_)->char_number = (yyloc).first_column; result->pattern_ = (yyval.pattern_); }
#line 1959 "Parser.C"
    break;

  case 50: /* Pattern: _INTEGER_  */
#line 326 "Stella.y"
              { (yyval.pattern_) = new Stella::PatternInt((yyvsp[0]._int)); (yyval.pattern_)->line_number = (yyloc).first_line; (yyval.pattern_)->char_number = (yyloc).first_column; result->pattern_ = (yyval.pattern_); }
#line 1965 "Parser.C"
    break;

  case 51: /* Pattern: _KW_succ _LPAREN Pattern _RPAREN  */
#line 327 "Stella.y"
                                     { (yyval.pattern_) = new Stella::PatternSucc((yyvsp[-1].pattern_)); (yyval.pattern_)->line_number = (yyloc).first_line; (yyval.pattern_)->char_number = (yyloc).first_column; result->pattern_ = (yyval.pattern_); }
#line 1971 "Parser.C"
    break;

  case 52: /* Pattern: T_StellaIdent  */
#line 328 "Stella.y"
                  { (yyval.pattern_) = new Stella::PatternVar((yyvsp[0]._string)); (yyval.pattern_)->line_number = (yyloc).first_line; (yyval.pattern_)->char_number = (yyloc).first_column; result->pattern_ = (yyval.pattern_); }
#line 1977 "Parser.C"
    break;

  case 53: /* Pattern: _LPAREN Pattern _RPAREN  */
#line 329 "Stella.y"
                            { (yyval.pattern_) = (yyvsp[-1].pattern_); (yyval.pattern_)->line_number = (yyloc).first_line; (yyval.pattern_)->char_number = (yyloc).first_column; result->pattern_ = (yyval.pattern_); }
#line 1983 "Parser.C"
    break;

  case 54: /* ListPattern: %empty  */
#line 331 "Stella.y"
                          { (yyval.listpattern_) = new Stella::ListPattern(); result->listpattern_ = (yyval.listpattern_); }
#line 1989 "Parser.C"
    break;

  case 55: /* ListPattern: Pattern  */
#line 332 "Stella.y"
            { (yyval.listpattern_) = new Stella::ListPattern(); (yyval.listpattern_)->push_back((yyvsp[0].pattern_)); result->listpattern_ = (yyval.listpattern_); }
#line 1995 "Parser.C"
    break;

  case 56: /* ListPattern: Pattern _COMMA ListPattern  */
#line 333 "Stella.y"
                               { (yyvsp[0].listpattern_)->push_back((yyvsp[-2].pattern_)); (yyval.listpattern_) = (yyvsp[0].listpattern_); result->listpattern_ = (yyval.listpattern_); }
#line 2001 "Parser.C"
    break;

  case 57: /* LabelledPattern: T_StellaIdent _EQ Pattern  */
#line 335 "Stella.y"
                                            { (yyval.labelledpattern_) = new Stella::ALabelledPattern((yyvsp[-2]._string), (yyvsp[0].pattern_)); (yyval.labelledpattern_)->line_number = (yyloc).first_line; (yyval.labelledpattern_)->char_number = (yyloc).first_column; result->labelledpattern_ = (yyval.labelledpattern_); }
#line 2007 "Parser.C"
    break;

  case 58: /* ListLabelledPattern: LabelledPattern  */
#line 337 "Stella.y"
                                      { (yyval.listlabelledpattern_) = new Stella::ListLabelledPattern(); (yyval.listlabelledpattern_)->push_back((yyvsp[0].labelledpattern_)); result->listlabelledpattern_ = (yyval.listlabelledpattern_); }
#line 2013 "Parser.C"
    break;

  case 59: /* ListLabelledPattern: LabelledPattern _COMMA ListLabelledPattern  */
#line 338 "Stella.y"
                                               { (yyvsp[0].listlabelledpattern_)->push_back((yyvsp[-2].labelledpattern_)); (yyval.listlabelledpattern_) = (yyvsp[0].listlabelledpattern_); result->listlabelledpattern_ = (yyval.listlabelledpattern_); }
#line 2019 "Parser.C"
    break;

  case 60: /* Binding: T_StellaIdent _EQ Expr  */
#line 340 "Stella.y"
                                 { (yyval.binding_) = new Stella::ABinding((yyvsp[-2]._string), (yyvsp[0].expr_)); (yyval.binding_)->line_number = (yyloc).first_line; (yyval.binding_)->char_number = (yyloc).first_column; result->binding_ = (yyval.binding_); }
#line 2025 "Parser.C"
    break;

  case 61: /* ListBinding: Binding  */
#line 342 "Stella.y"
                      { (yyval.listbinding_) = new Stella::ListBinding(); (yyval.listbinding_)->push_back((yyvsp[0].binding_)); result->listbinding_ = (yyval.listbinding_); }
#line 2031 "Parser.C"
    break;

  case 62: /* ListBinding: Binding _COMMA ListBinding  */
#line 343 "Stella.y"
                               { (yyvsp[0].listbinding_)->push_back((yyvsp[-2].binding_)); (yyval.listbinding_) = (yyvsp[0].listbinding_); result->listbinding_ = (yyval.listbinding_); }
#line 2037 "Parser.C"
    break;

  case 63: /* Expr: Expr1 _SEMI Expr  */
#line 345 "Stella.y"
                        { (yyval.expr_) = new Stella::Sequence((yyvsp[-2].expr_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2043 "Parser.C"
    break;

  case 64: /* Expr: Expr1 _SEMI  */
#line 346 "Stella.y"
                { (yyval.expr_) = (yyvsp[-1].expr_); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2049 "Parser.C"
    break;

  case 65: /* Expr: _KW_let ListPatternBinding _KW_in Expr  */
#line 347 "Stella.y"
                                           { std::reverse((yyvsp[-2].listpatternbinding_)->begin(),(yyvsp[-2].listpatternbinding_)->end()) ;(yyval.expr_) = new Stella::Let((yyvsp[-2].listpatternbinding_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2055 "Parser.C"
    break;

  case 66: /* Expr: _KW_letrec ListPatternBinding _KW_in Expr  */
#line 348 "Stella.y"
                                              { std::reverse((yyvsp[-2].listpatternbinding_)->begin(),(yyvsp[-2].listpatternbinding_)->end()) ;(yyval.expr_) = new Stella::LetRec((yyvsp[-2].listpatternbinding_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2061 "Parser.C"
    break;

  case 67: /* Expr: Expr1  */
#line 349 "Stella.y"
          { (yyval.expr_) = (yyvsp[0].expr_); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2067 "Parser.C"
    break;

  case 68: /* ListExpr: %empty  */
#line 351 "Stella.y"
                       { (yyval.listexpr_) = new Stella::ListExpr(); result->listexpr_ = (yyval.listexpr_); }
#line 2073 "Parser.C"
    break;

  case 69: /* ListExpr: Expr  */
#line 352 "Stella.y"
         { (yyval.listexpr_) = new Stella::ListExpr(); (yyval.listexpr_)->push_back((yyvsp[0].expr_)); result->listexpr_ = (yyval.listexpr_); }
#line 2079 "Parser.C"
    break;

  case 70: /* ListExpr: Expr _COMMA ListExpr  */
#line 353 "Stella.y"
                         { (yyvsp[0].listexpr_)->push_back((yyvsp[-2].expr_)); (yyval.listexpr_) = (yyvsp[0].listexpr_); result->listexpr_ = (yyval.listexpr_); }
#line 2085 "Parser.C"
    break;

  case 71: /* Expr1: Expr2 _COLONEQ Expr1  */
#line 355 "Stella.y"
                             { (yyval.expr_) = new Stella::Assign((yyvsp[-2].expr_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2091 "Parser.C"
    break;

  case 72: /* Expr1: _KW_if Expr1 _KW_then Expr1 _KW_else Expr1  */
#line 356 "Stella.y"
                                               { (yyval.expr_) = new Stella::If((yyvsp[-4].expr_), (yyvsp[-2].expr_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2097 "Parser.C"
    break;

  case 73: /* Expr1: Expr2  */
#line 357 "Stella.y"
          { (yyval.expr_) = (yyvsp[0].expr_); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2103 "Parser.C"
    break;

  case 74: /* PatternBinding: Pattern _EQ Expr  */
#line 359 "Stella.y"
                                  { (yyval.patternbinding_) = new Stella::APatternBinding((yyvsp[-2].pattern_), (yyvsp[0].expr_)); (yyval.patternbinding_)->line_number = (yyloc).first_line; (yyval.patternbinding_)->char_number = (yyloc).first_column; result->patternbinding_ = (yyval.patternbinding_); }
#line 2109 "Parser.C"
    break;

  case 75: /* ListPatternBinding: PatternBinding  */
#line 361 "Stella.y"
                                    { (yyval.listpatternbinding_) = new Stella::ListPatternBinding(); (yyval.listpatternbinding_)->push_back((yyvsp[0].patternbinding_)); result->listpatternbinding_ = (yyval.listpatternbinding_); }
#line 2115 "Parser.C"
    break;

  case 76: /* ListPatternBinding: PatternBinding _COMMA ListPatternBinding  */
#line 362 "Stella.y"
                                             { (yyvsp[0].listpatternbinding_)->push_back((yyvsp[-2].patternbinding_)); (yyval.listpatternbinding_) = (yyvsp[0].listpatternbinding_); result->listpatternbinding_ = (yyval.listpatternbinding_); }
#line 2121 "Parser.C"
    break;

  case 77: /* Expr2: Expr3 _LT Expr3  */
#line 364 "Stella.y"
                        { (yyval.expr_) = new Stella::LessThan((yyvsp[-2].expr_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2127 "Parser.C"
    break;

  case 78: /* Expr2: Expr3 _LDARROW Expr3  */
#line 365 "Stella.y"
                         { (yyval.expr_) = new Stella::LessThanOrEqual((yyvsp[-2].expr_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2133 "Parser.C"
    break;

  case 79: /* Expr2: Expr3 _GT Expr3  */
#line 366 "Stella.y"
                    { (yyval.expr_) = new Stella::GreaterThan((yyvsp[-2].expr_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2139 "Parser.C"
    break;

  case 80: /* Expr2: Expr3 _GTEQ Expr3  */
#line 367 "Stella.y"
                      { (yyval.expr_) = new Stella::GreaterThanOrEqual((yyvsp[-2].expr_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2145 "Parser.C"
    break;

  case 81: /* Expr2: Expr3 _DEQ Expr3  */
#line 368 "Stella.y"
                     { (yyval.expr_) = new Stella::Equal((yyvsp[-2].expr_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2151 "Parser.C"
    break;

  case 82: /* Expr2: Expr3 _BANGEQ Expr3  */
#line 369 "Stella.y"
                        { (yyval.expr_) = new Stella::NotEqual((yyvsp[-2].expr_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2157 "Parser.C"
    break;

  case 83: /* Expr2: Expr3  */
#line 370 "Stella.y"
          { (yyval.expr_) = (yyvsp[0].expr_); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2163 "Parser.C"
    break;

  case 84: /* Expr3: Expr3 _KW_as Type2  */
#line 375 "Stella.y"
                           { (yyval.expr_) = new Stella::TypeAsc((yyvsp[-2].expr_), (yyvsp[0].type_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2169 "Parser.C"
    break;

  case 85: /* Expr3: Expr3 _KW_cast _KW_as Type2  */
#line 376 "Stella.y"
                                { (yyval.expr_) = new Stella::TypeCast((yyvsp[-3].expr_), (yyvsp[0].type_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2175 "Parser.C"
    break;

  case 86: /* Expr3: _KW_fn _LPAREN ListParamDecl _RPAREN _LBRACE _KW_return Expr _RBRACE  */
#line 377 "Stella.y"
                                                                         { std::reverse((yyvsp[-5].listparamdecl_)->begin(),(yyvsp[-5].listparamdecl_)->end()) ;(yyval.expr_) = new Stella::Abstraction((yyvsp[-5].listparamdecl_), (yyvsp[-1].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2181 "Parser.C"
    break;

  case 87: /* Expr3: _SYMB_11 T_StellaIdent ExprData _SYMB_12  */
#line 378 "Stella.y"
                                             { (yyval.expr_) = new Stella::Variant((yyvsp[-2]._string), (yyvsp[-1].exprdata_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2187 "Parser.C"
    break;

  case 88: /* Expr3: _KW_match Expr2 _LBRACE ListMatchCase _RBRACE  */
#line 379 "Stella.y"
                                                  { std::reverse((yyvsp[-1].listmatchcase_)->begin(),(yyvsp[-1].listmatchcase_)->end()) ;(yyval.expr_) = new Stella::Match((yyvsp[-3].expr_), (yyvsp[-1].listmatchcase_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2193 "Parser.C"
    break;

  case 89: /* Expr3: _LBRACK ListExpr _RBRACK  */
#line 380 "Stella.y"
                             { std::reverse((yyvsp[-1].listexpr_)->begin(),(yyvsp[-1].listexpr_)->end()) ;(yyval.expr_) = new Stella::List((yyvsp[-1].listexpr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2199 "Parser.C"
    break;

  case 90: /* Expr3: Expr3 _PLUS Expr4  */
#line 381 "Stella.y"
                      { (yyval.expr_) = new Stella::Add((yyvsp[-2].expr_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2205 "Parser.C"
    break;

  case 91: /* Expr3: Expr3 _MINUS Expr4  */
#line 382 "Stella.y"
                       { (yyval.expr_) = new Stella::Subtract((yyvsp[-2].expr_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2211 "Parser.C"
    break;

  case 92: /* Expr3: Expr3 _KW_or Expr4  */
#line 383 "Stella.y"
                       { (yyval.expr_) = new Stella::LogicOr((yyvsp[-2].expr_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2217 "Parser.C"
    break;

  case 93: /* Expr3: Expr4  */
#line 384 "Stella.y"
          { (yyval.expr_) = (yyvsp[0].expr_); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2223 "Parser.C"
    break;

  case 94: /* Expr4: Expr4 _STAR Expr5  */
#line 386 "Stella.y"
                          { (yyval.expr_) = new Stella::Multiply((yyvsp[-2].expr_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2229 "Parser.C"
    break;

  case 95: /* Expr4: Expr4 _SLASH Expr5  */
#line 387 "Stella.y"
                       { (yyval.expr_) = new Stella::Divide((yyvsp[-2].expr_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2235 "Parser.C"
    break;

  case 96: /* Expr4: Expr4 _KW_and Expr5  */
#line 388 "Stella.y"
                        { (yyval.expr_) = new Stella::LogicAnd((yyvsp[-2].expr_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2241 "Parser.C"
    break;

  case 97: /* Expr4: Expr5  */
#line 389 "Stella.y"
          { (yyval.expr_) = (yyvsp[0].expr_); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2247 "Parser.C"
    break;

  case 98: /* Expr5: _KW_new _LPAREN Expr5 _RPAREN  */
#line 391 "Stella.y"
                                      { (yyval.expr_) = new Stella::Ref((yyvsp[-1].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2253 "Parser.C"
    break;

  case 99: /* Expr5: _STAR Expr5  */
#line 392 "Stella.y"
                { (yyval.expr_) = new Stella::Deref((yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2259 "Parser.C"
    break;

  case 100: /* Expr5: Expr6  */
#line 393 "Stella.y"
          { (yyval.expr_) = (yyvsp[0].expr_); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2265 "Parser.C"
    break;

  case 101: /* Expr6: Expr6 _LPAREN ListExpr _RPAREN  */
#line 395 "Stella.y"
                                       { std::reverse((yyvsp[-1].listexpr_)->begin(),(yyvsp[-1].listexpr_)->end()) ;(yyval.expr_) = new Stella::Application((yyvsp[-3].expr_), (yyvsp[-1].listexpr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2271 "Parser.C"
    break;

  case 102: /* Expr6: Expr6 _DOT T_StellaIdent  */
#line 396 "Stella.y"
                             { (yyval.expr_) = new Stella::DotRecord((yyvsp[-2].expr_), (yyvsp[0]._string)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2277 "Parser.C"
    break;

  case 103: /* Expr6: Expr6 _DOT _INTEGER_  */
#line 397 "Stella.y"
                         { (yyval.expr_) = new Stella::DotTuple((yyvsp[-2].expr_), (yyvsp[0]._int)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2283 "Parser.C"
    break;

  case 104: /* Expr6: _LBRACE ListExpr _RBRACE  */
#line 398 "Stella.y"
                             { std::reverse((yyvsp[-1].listexpr_)->begin(),(yyvsp[-1].listexpr_)->end()) ;(yyval.expr_) = new Stella::Tuple((yyvsp[-1].listexpr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2289 "Parser.C"
    break;

  case 105: /* Expr6: _LBRACE ListBinding _RBRACE  */
#line 399 "Stella.y"
                                { std::reverse((yyvsp[-1].listbinding_)->begin(),(yyvsp[-1].listbinding_)->end()) ;(yyval.expr_) = new Stella::Record((yyvsp[-1].listbinding_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2295 "Parser.C"
    break;

  case 106: /* Expr6: _KW_cons _LPAREN Expr _COMMA Expr _RPAREN  */
#line 400 "Stella.y"
                                              { (yyval.expr_) = new Stella::ConsList((yyvsp[-3].expr_), (yyvsp[-1].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2301 "Parser.C"
    break;

  case 107: /* Expr6: _SYMB_27 _LPAREN Expr _RPAREN  */
#line 401 "Stella.y"
                                  { (yyval.expr_) = new Stella::Head((yyvsp[-1].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2307 "Parser.C"
    break;

  case 108: /* Expr6: _SYMB_28 _LPAREN Expr _RPAREN  */
#line 402 "Stella.y"
                                  { (yyval.expr_) = new Stella::IsEmpty((yyvsp[-1].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2313 "Parser.C"
    break;

  case 109: /* Expr6: _SYMB_29 _LPAREN Expr _RPAREN  */
#line 403 "Stella.y"
                                  { (yyval.expr_) = new Stella::Tail((yyvsp[-1].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2319 "Parser.C"
    break;

  case 110: /* Expr6: _SYMB_30  */
#line 404 "Stella.y"
             { (yyval.expr_) = new Stella::Panic(); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2325 "Parser.C"
    break;

  case 111: /* Expr6: _KW_throw _LPAREN Expr _RPAREN  */
#line 405 "Stella.y"
                                   { (yyval.expr_) = new Stella::Throw((yyvsp[-1].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2331 "Parser.C"
    break;

  case 112: /* Expr6: _KW_try _LBRACE Expr _RBRACE _KW_catch _LBRACE Pattern _RDARROW Expr _RBRACE  */
#line 406 "Stella.y"
                                                                                 { (yyval.expr_) = new Stella::TryCatch((yyvsp[-7].expr_), (yyvsp[-3].pattern_), (yyvsp[-1].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2337 "Parser.C"
    break;

  case 113: /* Expr6: _KW_try _LBRACE Expr _RBRACE _KW_with _LBRACE Expr _RBRACE  */
#line 407 "Stella.y"
                                                               { (yyval.expr_) = new Stella::TryWith((yyvsp[-5].expr_), (yyvsp[-1].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2343 "Parser.C"
    break;

  case 114: /* Expr6: _KW_inl _LPAREN Expr _RPAREN  */
#line 408 "Stella.y"
                                 { (yyval.expr_) = new Stella::Inl((yyvsp[-1].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2349 "Parser.C"
    break;

  case 115: /* Expr6: _KW_inr _LPAREN Expr _RPAREN  */
#line 409 "Stella.y"
                                 { (yyval.expr_) = new Stella::Inr((yyvsp[-1].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2355 "Parser.C"
    break;

  case 116: /* Expr6: _KW_succ _LPAREN Expr _RPAREN  */
#line 410 "Stella.y"
                                  { (yyval.expr_) = new Stella::Succ((yyvsp[-1].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2361 "Parser.C"
    break;

  case 117: /* Expr6: _KW_not _LPAREN Expr _RPAREN  */
#line 411 "Stella.y"
                                 { (yyval.expr_) = new Stella::LogicNot((yyvsp[-1].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2367 "Parser.C"
    break;

  case 118: /* Expr6: _SYMB_31 _LPAREN Expr _RPAREN  */
#line 412 "Stella.y"
                                  { (yyval.expr_) = new Stella::Pred((yyvsp[-1].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2373 "Parser.C"
    break;

  case 119: /* Expr6: _SYMB_32 _LPAREN Expr _RPAREN  */
#line 413 "Stella.y"
                                  { (yyval.expr_) = new Stella::IsZero((yyvsp[-1].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2379 "Parser.C"
    break;

  case 120: /* Expr6: _KW_fix _LPAREN Expr _RPAREN  */
#line 414 "Stella.y"
                                 { (yyval.expr_) = new Stella::Fix((yyvsp[-1].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2385 "Parser.C"
    break;

  case 121: /* Expr6: _SYMB_33 _LPAREN Expr _COMMA Expr _COMMA Expr _RPAREN  */
#line 415 "Stella.y"
                                                          { (yyval.expr_) = new Stella::NatRec((yyvsp[-5].expr_), (yyvsp[-3].expr_), (yyvsp[-1].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2391 "Parser.C"
    break;

  case 122: /* Expr6: _KW_fold _LBRACK Type _RBRACK Expr7  */
#line 416 "Stella.y"
                                        { (yyval.expr_) = new Stella::Fold((yyvsp[-2].type_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2397 "Parser.C"
    break;

  case 123: /* Expr6: _KW_unfold _LBRACK Type _RBRACK Expr7  */
#line 417 "Stella.y"
                                          { (yyval.expr_) = new Stella::Unfold((yyvsp[-2].type_), (yyvsp[0].expr_)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2403 "Parser.C"
    break;

  case 124: /* Expr6: Expr7  */
#line 418 "Stella.y"
          { (yyval.expr_) = (yyvsp[0].expr_); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2409 "Parser.C"
    break;

  case 125: /* Expr7: _KW_true  */
#line 420 "Stella.y"
                 { (yyval.expr_) = new Stella::ConstTrue(); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2415 "Parser.C"
    break;

  case 126: /* Expr7: _KW_false  */
#line 421 "Stella.y"
              { (yyval.expr_) = new Stella::ConstFalse(); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2421 "Parser.C"
    break;

  case 127: /* Expr7: _KW_unit  */
#line 422 "Stella.y"
             { (yyval.expr_) = new Stella::ConstUnit(); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2427 "Parser.C"
    break;

  case 128: /* Expr7: _INTEGER_  */
#line 423 "Stella.y"
              { (yyval.expr_) = new Stella::ConstInt((yyvsp[0]._int)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2433 "Parser.C"
    break;

  case 129: /* Expr7: T_MemoryAddress  */
#line 424 "Stella.y"
                    { (yyval.expr_) = new Stella::ConstMemory((yyvsp[0]._string)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2439 "Parser.C"
    break;

  case 130: /* Expr7: T_StellaIdent  */
#line 425 "Stella.y"
                  { (yyval.expr_) = new Stella::Var((yyvsp[0]._string)); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2445 "Parser.C"
    break;

  case 131: /* Expr7: _LPAREN Expr _RPAREN  */
#line 426 "Stella.y"
                         { (yyval.expr_) = (yyvsp[-1].expr_); (yyval.expr_)->line_number = (yyloc).first_line; (yyval.expr_)->char_number = (yyloc).first_column; result->expr_ = (yyval.expr_); }
#line 2451 "Parser.C"
    break;

  case 132: /* Type: _KW_fn _LPAREN ListType _RPAREN _RARROW Type  */
#line 428 "Stella.y"
                                                    { std::reverse((yyvsp[-3].listtype_)->begin(),(yyvsp[-3].listtype_)->end()) ;(yyval.type_) = new Stella::TypeFun((yyvsp[-3].listtype_), (yyvsp[0].type_)); (yyval.type_)->line_number = (yyloc).first_line; (yyval.type_)->char_number = (yyloc).first_column; result->type_ = (yyval.type_); }
#line 2457 "Parser.C"
    break;

  case 133: /* Type: _KW_77 T_StellaIdent _DOT Type  */
#line 429 "Stella.y"
                                   { (yyval.type_) = new Stella::TypeRec((yyvsp[-2]._string), (yyvsp[0].type_)); (yyval.type_)->line_number = (yyloc).first_line; (yyval.type_)->char_number = (yyloc).first_column; result->type_ = (yyval.type_); }
#line 2463 "Parser.C"
    break;

  case 134: /* Type: Type1  */
#line 430 "Stella.y"
          { (yyval.type_) = (yyvsp[0].type_); (yyval.type_)->line_number = (yyloc).first_line; (yyval.type_)->char_number = (yyloc).first_column; result->type_ = (yyval.type_); }
#line 2469 "Parser.C"
    break;

  case 135: /* Type1: Type2 _PLUS Type2  */
#line 432 "Stella.y"
                          { (yyval.type_) = new Stella::TypeSum((yyvsp[-2].type_), (yyvsp[0].type_)); (yyval.type_)->line_number = (yyloc).first_line; (yyval.type_)->char_number = (yyloc).first_column; result->type_ = (yyval.type_); }
#line 2475 "Parser.C"
    break;

  case 136: /* Type1: Type2  */
#line 433 "Stella.y"
          { (yyval.type_) = (yyvsp[0].type_); (yyval.type_)->line_number = (yyloc).first_line; (yyval.type_)->char_number = (yyloc).first_column; result->type_ = (yyval.type_); }
#line 2481 "Parser.C"
    break;

  case 137: /* Type2: _LBRACE ListType _RBRACE  */
#line 435 "Stella.y"
                                 { std::reverse((yyvsp[-1].listtype_)->begin(),(yyvsp[-1].listtype_)->end()) ;(yyval.type_) = new Stella::TypeTuple((yyvsp[-1].listtype_)); (yyval.type_)->line_number = (yyloc).first_line; (yyval.type_)->char_number = (yyloc).first_column; result->type_ = (yyval.type_); }
#line 2487 "Parser.C"
    break;

  case 138: /* Type2: _LBRACE ListRecordFieldType _RBRACE  */
#line 436 "Stella.y"
                                        { std::reverse((yyvsp[-1].listrecordfieldtype_)->begin(),(yyvsp[-1].listrecordfieldtype_)->end()) ;(yyval.type_) = new Stella::TypeRecord((yyvsp[-1].listrecordfieldtype_)); (yyval.type_)->line_number = (yyloc).first_line; (yyval.type_)->char_number = (yyloc).first_column; result->type_ = (yyval.type_); }
#line 2493 "Parser.C"
    break;

  case 139: /* Type2: _SYMB_11 ListVariantFieldType _SYMB_12  */
#line 437 "Stella.y"
                                           { std::reverse((yyvsp[-1].listvariantfieldtype_)->begin(),(yyvsp[-1].listvariantfieldtype_)->end()) ;(yyval.type_) = new Stella::TypeVariant((yyvsp[-1].listvariantfieldtype_)); (yyval.type_)->line_number = (yyloc).first_line; (yyval.type_)->char_number = (yyloc).first_column; result->type_ = (yyval.type_); }
#line 2499 "Parser.C"
    break;

  case 140: /* Type2: _LBRACK Type _RBRACK  */
#line 438 "Stella.y"
                         { (yyval.type_) = new Stella::TypeList((yyvsp[-1].type_)); (yyval.type_)->line_number = (yyloc).first_line; (yyval.type_)->char_number = (yyloc).first_column; result->type_ = (yyval.type_); }
#line 2505 "Parser.C"
    break;

  case 141: /* Type2: Type3  */
#line 439 "Stella.y"
          { (yyval.type_) = (yyvsp[0].type_); (yyval.type_)->line_number = (yyloc).first_line; (yyval.type_)->char_number = (yyloc).first_column; result->type_ = (yyval.type_); }
#line 2511 "Parser.C"
    break;

  case 142: /* Type3: _KW_Bool  */
#line 441 "Stella.y"
                 { (yyval.type_) = new Stella::TypeBool(); (yyval.type_)->line_number = (yyloc).first_line; (yyval.type_)->char_number = (yyloc).first_column; result->type_ = (yyval.type_); }
#line 2517 "Parser.C"
    break;

  case 143: /* Type3: _KW_Nat  */
#line 442 "Stella.y"
            { (yyval.type_) = new Stella::TypeNat(); (yyval.type_)->line_number = (yyloc).first_line; (yyval.type_)->char_number = (yyloc).first_column; result->type_ = (yyval.type_); }
#line 2523 "Parser.C"
    break;

  case 144: /* Type3: _KW_Unit  */
#line 443 "Stella.y"
             { (yyval.type_) = new Stella::TypeUnit(); (yyval.type_)->line_number = (yyloc).first_line; (yyval.type_)->char_number = (yyloc).first_column; result->type_ = (yyval.type_); }
#line 2529 "Parser.C"
    break;

  case 145: /* Type3: _KW_Top  */
#line 444 "Stella.y"
            { (yyval.type_) = new Stella::TypeTop(); (yyval.type_)->line_number = (yyloc).first_line; (yyval.type_)->char_number = (yyloc).first_column; result->type_ = (yyval.type_); }
#line 2535 "Parser.C"
    break;

  case 146: /* Type3: _KW_Bot  */
#line 445 "Stella.y"
            { (yyval.type_) = new Stella::TypeBottom(); (yyval.type_)->line_number = (yyloc).first_line; (yyval.type_)->char_number = (yyloc).first_column; result->type_ = (yyval.type_); }
#line 2541 "Parser.C"
    break;

  case 147: /* Type3: _AMP Type2  */
#line 446 "Stella.y"
               { (yyval.type_) = new Stella::TypeRef((yyvsp[0].type_)); (yyval.type_)->line_number = (yyloc).first_line; (yyval.type_)->char_number = (yyloc).first_column; result->type_ = (yyval.type_); }
#line 2547 "Parser.C"
    break;

  case 148: /* Type3: T_StellaIdent  */
#line 447 "Stella.y"
                  { (yyval.type_) = new Stella::TypeVar((yyvsp[0]._string)); (yyval.type_)->line_number = (yyloc).first_line; (yyval.type_)->char_number = (yyloc).first_column; result->type_ = (yyval.type_); }
#line 2553 "Parser.C"
    break;

  case 149: /* Type3: _LPAREN Type _RPAREN  */
#line 448 "Stella.y"
                         { (yyval.type_) = (yyvsp[-1].type_); (yyval.type_)->line_number = (yyloc).first_line; (yyval.type_)->char_number = (yyloc).first_column; result->type_ = (yyval.type_); }
#line 2559 "Parser.C"
    break;

  case 150: /* ListType: %empty  */
#line 450 "Stella.y"
                       { (yyval.listtype_) = new Stella::ListType(); result->listtype_ = (yyval.listtype_); }
#line 2565 "Parser.C"
    break;

  case 151: /* ListType: Type  */
#line 451 "Stella.y"
         { (yyval.listtype_) = new Stella::ListType(); (yyval.listtype_)->push_back((yyvsp[0].type_)); result->listtype_ = (yyval.listtype_); }
#line 2571 "Parser.C"
    break;

  case 152: /* ListType: Type _COMMA ListType  */
#line 452 "Stella.y"
                         { (yyvsp[0].listtype_)->push_back((yyvsp[-2].type_)); (yyval.listtype_) = (yyvsp[0].listtype_); result->listtype_ = (yyval.listtype_); }
#line 2577 "Parser.C"
    break;

  case 153: /* VariantFieldType: T_StellaIdent OptionalTyping  */
#line 454 "Stella.y"
                                                { (yyval.variantfieldtype_) = new Stella::AVariantFieldType((yyvsp[-1]._string), (yyvsp[0].optionaltyping_)); (yyval.variantfieldtype_)->line_number = (yyloc).first_line; (yyval.variantfieldtype_)->char_number = (yyloc).first_column; result->variantfieldtype_ = (yyval.variantfieldtype_); }
#line 2583 "Parser.C"
    break;

  case 154: /* ListVariantFieldType: %empty  */
#line 456 "Stella.y"
                                   { (yyval.listvariantfieldtype_) = new Stella::ListVariantFieldType(); result->listvariantfieldtype_ = (yyval.listvariantfieldtype_); }
#line 2589 "Parser.C"
    break;

  case 155: /* ListVariantFieldType: VariantFieldType  */
#line 457 "Stella.y"
                     { (yyval.listvariantfieldtype_) = new Stella::ListVariantFieldType(); (yyval.listvariantfieldtype_)->push_back((yyvsp[0].variantfieldtype_)); result->listvariantfieldtype_ = (yyval.listvariantfieldtype_); }
#line 2595 "Parser.C"
    break;

  case 156: /* ListVariantFieldType: VariantFieldType _COMMA ListVariantFieldType  */
#line 458 "Stella.y"
                                                 { (yyvsp[0].listvariantfieldtype_)->push_back((yyvsp[-2].variantfieldtype_)); (yyval.listvariantfieldtype_) = (yyvsp[0].listvariantfieldtype_); result->listvariantfieldtype_ = (yyval.listvariantfieldtype_); }
#line 2601 "Parser.C"
    break;

  case 157: /* RecordFieldType: T_StellaIdent _COLON Type  */
#line 460 "Stella.y"
                                            { (yyval.recordfieldtype_) = new Stella::ARecordFieldType((yyvsp[-2]._string), (yyvsp[0].type_)); (yyval.recordfieldtype_)->line_number = (yyloc).first_line; (yyval.recordfieldtype_)->char_number = (yyloc).first_column; result->recordfieldtype_ = (yyval.recordfieldtype_); }
#line 2607 "Parser.C"
    break;

  case 158: /* ListRecordFieldType: RecordFieldType  */
#line 462 "Stella.y"
                                      { (yyval.listrecordfieldtype_) = new Stella::ListRecordFieldType(); (yyval.listrecordfieldtype_)->push_back((yyvsp[0].recordfieldtype_)); result->listrecordfieldtype_ = (yyval.listrecordfieldtype_); }
#line 2613 "Parser.C"
    break;

  case 159: /* ListRecordFieldType: RecordFieldType _COMMA ListRecordFieldType  */
#line 463 "Stella.y"
                                               { (yyvsp[0].listrecordfieldtype_)->push_back((yyvsp[-2].recordfieldtype_)); (yyval.listrecordfieldtype_) = (yyvsp[0].listrecordfieldtype_); result->listrecordfieldtype_ = (yyval.listrecordfieldtype_); }
#line 2619 "Parser.C"
    break;


#line 2623 "Parser.C"

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
  *++yylsp = yyloc;

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
      yyerror (&yylloc, scanner, result, YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc, scanner, result);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, scanner, result);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
  yyerror (&yylloc, scanner, result, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, scanner, result);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, scanner, result);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 468 "Stella.y"


namespace Stella
{
/* Entrypoint: parse Program* from file. */
Program* pProgram(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.program_;
  }
}

/* Entrypoint: parse Program* from string. */
Program* psProgram(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.program_;
  }
}

/* Entrypoint: parse ListStellaIdent* from file. */
ListStellaIdent* pListStellaIdent(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.liststellaident_->begin(), result.liststellaident_->end());
    return result.liststellaident_;
  }
}

/* Entrypoint: parse ListStellaIdent* from string. */
ListStellaIdent* psListStellaIdent(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.liststellaident_->begin(), result.liststellaident_->end());
    return result.liststellaident_;
  }
}

/* Entrypoint: parse LanguageDecl* from file. */
LanguageDecl* pLanguageDecl(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.languagedecl_;
  }
}

/* Entrypoint: parse LanguageDecl* from string. */
LanguageDecl* psLanguageDecl(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.languagedecl_;
  }
}

/* Entrypoint: parse Extension* from file. */
Extension* pExtension(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.extension_;
  }
}

/* Entrypoint: parse Extension* from string. */
Extension* psExtension(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.extension_;
  }
}

/* Entrypoint: parse ListExtensionName* from file. */
ListExtensionName* pListExtensionName(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listextensionname_->begin(), result.listextensionname_->end());
    return result.listextensionname_;
  }
}

/* Entrypoint: parse ListExtensionName* from string. */
ListExtensionName* psListExtensionName(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listextensionname_->begin(), result.listextensionname_->end());
    return result.listextensionname_;
  }
}

/* Entrypoint: parse ListExtension* from file. */
ListExtension* pListExtension(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.listextension_;
  }
}

/* Entrypoint: parse ListExtension* from string. */
ListExtension* psListExtension(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.listextension_;
  }
}

/* Entrypoint: parse Decl* from file. */
Decl* pDecl(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.decl_;
  }
}

/* Entrypoint: parse Decl* from string. */
Decl* psDecl(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.decl_;
  }
}

/* Entrypoint: parse ListDecl* from file. */
ListDecl* pListDecl(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.listdecl_;
  }
}

/* Entrypoint: parse ListDecl* from string. */
ListDecl* psListDecl(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.listdecl_;
  }
}

/* Entrypoint: parse LocalDecl* from file. */
LocalDecl* pLocalDecl(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.localdecl_;
  }
}

/* Entrypoint: parse LocalDecl* from string. */
LocalDecl* psLocalDecl(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.localdecl_;
  }
}

/* Entrypoint: parse ListLocalDecl* from file. */
ListLocalDecl* pListLocalDecl(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.listlocaldecl_;
  }
}

/* Entrypoint: parse ListLocalDecl* from string. */
ListLocalDecl* psListLocalDecl(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.listlocaldecl_;
  }
}

/* Entrypoint: parse Annotation* from file. */
Annotation* pAnnotation(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.annotation_;
  }
}

/* Entrypoint: parse Annotation* from string. */
Annotation* psAnnotation(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.annotation_;
  }
}

/* Entrypoint: parse ListAnnotation* from file. */
ListAnnotation* pListAnnotation(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.listannotation_;
  }
}

/* Entrypoint: parse ListAnnotation* from string. */
ListAnnotation* psListAnnotation(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.listannotation_;
  }
}

/* Entrypoint: parse ParamDecl* from file. */
ParamDecl* pParamDecl(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.paramdecl_;
  }
}

/* Entrypoint: parse ParamDecl* from string. */
ParamDecl* psParamDecl(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.paramdecl_;
  }
}

/* Entrypoint: parse ListParamDecl* from file. */
ListParamDecl* pListParamDecl(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listparamdecl_->begin(), result.listparamdecl_->end());
    return result.listparamdecl_;
  }
}

/* Entrypoint: parse ListParamDecl* from string. */
ListParamDecl* psListParamDecl(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listparamdecl_->begin(), result.listparamdecl_->end());
    return result.listparamdecl_;
  }
}

/* Entrypoint: parse ReturnType* from file. */
ReturnType* pReturnType(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.returntype_;
  }
}

/* Entrypoint: parse ReturnType* from string. */
ReturnType* psReturnType(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.returntype_;
  }
}

/* Entrypoint: parse ThrowType* from file. */
ThrowType* pThrowType(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.throwtype_;
  }
}

/* Entrypoint: parse ThrowType* from string. */
ThrowType* psThrowType(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.throwtype_;
  }
}

/* Entrypoint: parse Type* from file. */
Type* pType9(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.type_;
  }
}

/* Entrypoint: parse Type* from string. */
Type* psType9(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.type_;
  }
}

/* Entrypoint: parse ListType* from file. */
ListType* pListType9(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listtype_->begin(), result.listtype_->end());
    return result.listtype_;
  }
}

/* Entrypoint: parse ListType* from string. */
ListType* psListType9(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listtype_->begin(), result.listtype_->end());
    return result.listtype_;
  }
}

/* Entrypoint: parse MatchCase* from file. */
MatchCase* pMatchCase(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.matchcase_;
  }
}

/* Entrypoint: parse MatchCase* from string. */
MatchCase* psMatchCase(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.matchcase_;
  }
}

/* Entrypoint: parse ListMatchCase* from file. */
ListMatchCase* pListMatchCase(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listmatchcase_->begin(), result.listmatchcase_->end());
    return result.listmatchcase_;
  }
}

/* Entrypoint: parse ListMatchCase* from string. */
ListMatchCase* psListMatchCase(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listmatchcase_->begin(), result.listmatchcase_->end());
    return result.listmatchcase_;
  }
}

/* Entrypoint: parse OptionalTyping* from file. */
OptionalTyping* pOptionalTyping(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.optionaltyping_;
  }
}

/* Entrypoint: parse OptionalTyping* from string. */
OptionalTyping* psOptionalTyping(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.optionaltyping_;
  }
}

/* Entrypoint: parse PatternData* from file. */
PatternData* pPatternData(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.patterndata_;
  }
}

/* Entrypoint: parse PatternData* from string. */
PatternData* psPatternData(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.patterndata_;
  }
}

/* Entrypoint: parse ExprData* from file. */
ExprData* pExprData(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exprdata_;
  }
}

/* Entrypoint: parse ExprData* from string. */
ExprData* psExprData(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exprdata_;
  }
}

/* Entrypoint: parse Pattern* from file. */
Pattern* pPattern(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.pattern_;
  }
}

/* Entrypoint: parse Pattern* from string. */
Pattern* psPattern(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.pattern_;
  }
}

/* Entrypoint: parse ListPattern* from file. */
ListPattern* pListPattern(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listpattern_->begin(), result.listpattern_->end());
    return result.listpattern_;
  }
}

/* Entrypoint: parse ListPattern* from string. */
ListPattern* psListPattern(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listpattern_->begin(), result.listpattern_->end());
    return result.listpattern_;
  }
}

/* Entrypoint: parse LabelledPattern* from file. */
LabelledPattern* pLabelledPattern(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.labelledpattern_;
  }
}

/* Entrypoint: parse LabelledPattern* from string. */
LabelledPattern* psLabelledPattern(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.labelledpattern_;
  }
}

/* Entrypoint: parse ListLabelledPattern* from file. */
ListLabelledPattern* pListLabelledPattern(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listlabelledpattern_->begin(), result.listlabelledpattern_->end());
    return result.listlabelledpattern_;
  }
}

/* Entrypoint: parse ListLabelledPattern* from string. */
ListLabelledPattern* psListLabelledPattern(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listlabelledpattern_->begin(), result.listlabelledpattern_->end());
    return result.listlabelledpattern_;
  }
}

/* Entrypoint: parse Binding* from file. */
Binding* pBinding(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.binding_;
  }
}

/* Entrypoint: parse Binding* from string. */
Binding* psBinding(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.binding_;
  }
}

/* Entrypoint: parse ListBinding* from file. */
ListBinding* pListBinding(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listbinding_->begin(), result.listbinding_->end());
    return result.listbinding_;
  }
}

/* Entrypoint: parse ListBinding* from string. */
ListBinding* psListBinding(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listbinding_->begin(), result.listbinding_->end());
    return result.listbinding_;
  }
}

/* Entrypoint: parse Expr* from file. */
Expr* pExpr(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.expr_;
  }
}

/* Entrypoint: parse Expr* from string. */
Expr* psExpr(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.expr_;
  }
}

/* Entrypoint: parse ListExpr* from file. */
ListExpr* pListExpr(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listexpr_->begin(), result.listexpr_->end());
    return result.listexpr_;
  }
}

/* Entrypoint: parse ListExpr* from string. */
ListExpr* psListExpr(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listexpr_->begin(), result.listexpr_->end());
    return result.listexpr_;
  }
}

/* Entrypoint: parse Expr* from file. */
Expr* pExpr1(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.expr_;
  }
}

/* Entrypoint: parse Expr* from string. */
Expr* psExpr1(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.expr_;
  }
}

/* Entrypoint: parse PatternBinding* from file. */
PatternBinding* pPatternBinding(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.patternbinding_;
  }
}

/* Entrypoint: parse PatternBinding* from string. */
PatternBinding* psPatternBinding(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.patternbinding_;
  }
}

/* Entrypoint: parse ListPatternBinding* from file. */
ListPatternBinding* pListPatternBinding(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listpatternbinding_->begin(), result.listpatternbinding_->end());
    return result.listpatternbinding_;
  }
}

/* Entrypoint: parse ListPatternBinding* from string. */
ListPatternBinding* psListPatternBinding(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listpatternbinding_->begin(), result.listpatternbinding_->end());
    return result.listpatternbinding_;
  }
}

/* Entrypoint: parse Expr* from file. */
Expr* pExpr2(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.expr_;
  }
}

/* Entrypoint: parse Expr* from string. */
Expr* psExpr2(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.expr_;
  }
}

/* Entrypoint: parse ListExpr* from file. */
ListExpr* pListExpr2(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listexpr_->begin(), result.listexpr_->end());
    return result.listexpr_;
  }
}

/* Entrypoint: parse ListExpr* from string. */
ListExpr* psListExpr2(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listexpr_->begin(), result.listexpr_->end());
    return result.listexpr_;
  }
}

/* Entrypoint: parse Expr* from file. */
Expr* pExpr3(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.expr_;
  }
}

/* Entrypoint: parse Expr* from string. */
Expr* psExpr3(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.expr_;
  }
}

/* Entrypoint: parse Expr* from file. */
Expr* pExpr4(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.expr_;
  }
}

/* Entrypoint: parse Expr* from string. */
Expr* psExpr4(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.expr_;
  }
}

/* Entrypoint: parse Expr* from file. */
Expr* pExpr5(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.expr_;
  }
}

/* Entrypoint: parse Expr* from string. */
Expr* psExpr5(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.expr_;
  }
}

/* Entrypoint: parse Expr* from file. */
Expr* pExpr6(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.expr_;
  }
}

/* Entrypoint: parse Expr* from string. */
Expr* psExpr6(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.expr_;
  }
}

/* Entrypoint: parse Expr* from file. */
Expr* pExpr7(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.expr_;
  }
}

/* Entrypoint: parse Expr* from string. */
Expr* psExpr7(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.expr_;
  }
}

/* Entrypoint: parse Type* from file. */
Type* pType(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.type_;
  }
}

/* Entrypoint: parse Type* from string. */
Type* psType(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.type_;
  }
}

/* Entrypoint: parse Type* from file. */
Type* pType1(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.type_;
  }
}

/* Entrypoint: parse Type* from string. */
Type* psType1(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.type_;
  }
}

/* Entrypoint: parse Type* from file. */
Type* pType2(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.type_;
  }
}

/* Entrypoint: parse Type* from string. */
Type* psType2(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.type_;
  }
}

/* Entrypoint: parse Type* from file. */
Type* pType3(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.type_;
  }
}

/* Entrypoint: parse Type* from string. */
Type* psType3(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.type_;
  }
}

/* Entrypoint: parse ListType* from file. */
ListType* pListType(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listtype_->begin(), result.listtype_->end());
    return result.listtype_;
  }
}

/* Entrypoint: parse ListType* from string. */
ListType* psListType(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listtype_->begin(), result.listtype_->end());
    return result.listtype_;
  }
}

/* Entrypoint: parse VariantFieldType* from file. */
VariantFieldType* pVariantFieldType(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.variantfieldtype_;
  }
}

/* Entrypoint: parse VariantFieldType* from string. */
VariantFieldType* psVariantFieldType(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.variantfieldtype_;
  }
}

/* Entrypoint: parse ListVariantFieldType* from file. */
ListVariantFieldType* pListVariantFieldType(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listvariantfieldtype_->begin(), result.listvariantfieldtype_->end());
    return result.listvariantfieldtype_;
  }
}

/* Entrypoint: parse ListVariantFieldType* from string. */
ListVariantFieldType* psListVariantFieldType(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listvariantfieldtype_->begin(), result.listvariantfieldtype_->end());
    return result.listvariantfieldtype_;
  }
}

/* Entrypoint: parse RecordFieldType* from file. */
RecordFieldType* pRecordFieldType(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.recordfieldtype_;
  }
}

/* Entrypoint: parse RecordFieldType* from string. */
RecordFieldType* psRecordFieldType(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.recordfieldtype_;
  }
}

/* Entrypoint: parse ListRecordFieldType* from file. */
ListRecordFieldType* pListRecordFieldType(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listrecordfieldtype_->begin(), result.listrecordfieldtype_->end());
    return result.listrecordfieldtype_;
  }
}

/* Entrypoint: parse ListRecordFieldType* from string. */
ListRecordFieldType* psListRecordFieldType(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listrecordfieldtype_->begin(), result.listrecordfieldtype_->end());
    return result.listrecordfieldtype_;
  }
}

/* Entrypoint: parse Typing* from file. */
Typing* pTyping(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.typing_;
  }
}

/* Entrypoint: parse Typing* from string. */
Typing* psTyping(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = Stella_initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = Stella_scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  Stella_delete_buffer(buf, scanner);
  Stellalex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.typing_;
  }
}


}
