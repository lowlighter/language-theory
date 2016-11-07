/* Options */
%option noyywrap

/* Déclarations C++ */
%{
    //Inclusion
        #include <string>
        #include "parser.hpp"
    //Namespace
        using namespace std;
    //Déclaration de la fonction de parsing
      extern int yyparse();
%}

/* Déclarations Flex */
operator    [*\+\-\/\=\(\)\^]
number      [0-9]+(\.[0-9]+)?
variable    [a-zA-Z_][a-zA-Z_0-9]*
endline     \n


/* Règles flex */
%%

{operator}    { return yytext[0]; }

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
