%option noyywrap

%{
  #include "parser.hpp"

  extern int yyparse();
%}

operator  [*\+\-\/]
number    [0-9]+(\.[0-9]+)?
parenthes [()]

%%

{operator}  { return yytext[0]; }

{number}    {
              yylval.dbl = atof(yytext);
              return LITERAL_DBL;
            }

\n          {return '\n';}
.

%%
