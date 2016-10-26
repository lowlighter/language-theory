%option noyywrap

%{
  #include "parser.hpp"

  extern int yyparse();
%}

operator    [*\+\-\/]
number      [0-9]+(\.[0-9]+)?
variable    [a-zA-Z_][a-zA-Z_0-9]*
parenthes   [()]
print       print
endline     \n

%%

{print}       {return PRINT;}

{operator}    {return yytext[0];}

{parenthes}    {return yytext[0];}

{number}      {
                yylval.dbl = atof(yytext);
                return NUMBER;
              }

{variable}    {
                yylval.intg = yytext[0] - 'a';
                return VARIABLE;
              }

{endline}     {return '\n';}

.             {;}

%%
