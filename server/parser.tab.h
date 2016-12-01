/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 3 "parser.y" /* yacc.c:1909  */

  #include <string>

#line 48 "parser.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    PI = 259,
    EXP_E = 260,
    VARIABLE = 261,
    FUNCTION = 262,
    FUNCTION_R = 263,
    FROM = 264,
    TO = 265,
    STEP = 266,
    IF = 267,
    THEN = 268,
    ELSE = 269,
    TRUE = 270,
    FALSE = 271,
    UPDATE = 272,
    PLOT = 273,
    SQRT = 274,
    SIN = 275,
    COS = 276,
    TAN = 277,
    LOG = 278,
    LN = 279,
    EXP = 280,
    ABS = 281,
    POWER = 282,
    PRM = 283,
    EOL = 284,
    EOLR = 285,
    SYNTAX_ERROR = 286,
    QM = 287,
    DP = 288,
    EQU = 289,
    PLS = 290,
    MIN = 291,
    MUL = 292,
    DIV = 293,
    MOD = 294,
    POW = 295,
    FAC = 296,
    SIGN = 297,
    LT = 298,
    GT = 299,
    GTE = 300,
    LTE = 301,
    EEQU = 302,
    DIFF = 303,
    AND = 304,
    OR = 305,
    RULE = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 58 "parser.y" /* yacc.c:1909  */

    double dbl;
    std::string *str;

#line 117 "parser.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
