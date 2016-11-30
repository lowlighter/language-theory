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
    VARIABLE = 259,
    FUNCTION = 260,
    FUNCTION_R = 261,
    ARRAY = 262,
    FROM = 263,
    TO = 264,
    STEP = 265,
    IF = 266,
    THEN = 267,
    ELSE = 268,
    ENDIF = 269,
    PLOT = 270,
    RANGE = 271,
    XRANGE = 272,
    YRANGE = 273,
    COLOR = 274,
    SQRT = 275,
    SIN = 276,
    COS = 277,
    LOG = 278,
    LN = 279,
    EXP = 280,
    ABS = 281,
    POWER = 282,
    EOL = 283,
    EOLR = 284,
    RESET = 285,
    SYNTAX_ERROR = 286,
    LT = 287,
    GT = 288,
    EEQU = 289,
    DIFF = 290,
    GTE = 291,
    LTE = 292,
    PLS = 293,
    MIN = 294,
    MUL = 295,
    DIV = 296,
    MOD = 297,
    POW = 298,
    EQU = 299,
    SIGN = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 47 "parser.y" /* yacc.c:1909  */

    double dbl;
    std::string *str;

#line 111 "parser.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
