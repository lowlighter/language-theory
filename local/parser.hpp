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

#ifndef YY_YY_LOCAL_PARSER_HPP_INCLUDED
# define YY_YY_LOCAL_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 3 "./server/parser.y" /* yacc.c:1909  */

  #include <string>

#line 48 "./local/parser.hpp" /* yacc.c:1909  */

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
    PLOT = 270,
    SQRT = 271,
    SIN = 272,
    COS = 273,
    LOG = 274,
    LN = 275,
    EXP = 276,
    ABS = 277,
    POWER = 278,
    EOL = 279,
    EOLR = 280,
    SYNTAX_ERROR = 281,
    EQU = 282,
    PLS = 283,
    MIN = 284,
    MUL = 285,
    DIV = 286,
    MOD = 287,
    LT = 288,
    GT = 289,
    GTE = 290,
    LTE = 291,
    EEQU = 292,
    DIFF = 293,
    AND = 294,
    OR = 295,
    POW = 296,
    SIGN = 297,
    QM = 298,
    DP = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 49 "./server/parser.y" /* yacc.c:1909  */

    double dbl;
    std::string *str;

#line 110 "./local/parser.hpp" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LOCAL_PARSER_HPP_INCLUDED  */
