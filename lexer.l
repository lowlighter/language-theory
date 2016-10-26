%option noyywrap

%{
  #include <string>
  #include "parser.hpp"

  using namespace std;

  extern int yyparse();
%}

operator    [*\+\-\/\=\(\)]
number      [0-9]+(\.[0-9]+)?
variable    [a-zA-Z_][a-zA-Z_0-9]*
endline     \n

%%

{operator}    {return yytext[0];}

{number}      {
                yylval.dbl = atof(yytext);
                return NUMBER;
              }

{variable}    {
                yylval.s = new string(yytext);
                return VARIABLE;
              }

{endline}     {return '\n';}

.             {;}

%%
