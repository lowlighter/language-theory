    /* Options */
%option noyywrap

    /* Déclarations C++ */
%{
    //Inclusion
        #include <string>
        #include <iostream>
        #include "parser.hpp"
    //Namespace
        using namespace std;
    //Déclaration de la fonction de parsing
      extern int yyparse();
%}

    /* Déclarations Flex */
operator    [*\+\-\/\=\(\)\^\,\[\]]
number      [0-9]+(\.[0-9]+)?
variable    [a-zA-Z_][a-zA-Z_0-9]*
sqrt        (?i:sqrt)
sin         (?i:sin(us)?)
cos         (?i:cos(inus)?)
pi          (?i:pi)
plot        (?i:plot)
array       (\[[0-9]*\])

    /* Parameters */
range        (?i:r(ange)?)
xrange       (?i:rx(range)?)
yrange       (?i:ry(range)?)
color        (?i:rc(olor)?)
endline      \n

%%
    /* Règles flex */

{operator}    { return yytext[0]; }

{sqrt}        { return SQRT; }

{sin}         { return SIN; }

{cos}         { return COS; }

{plot}        { return PLOT; }

{range}       { return RANGE; }

{xrange}       { return XRANGE; }

{yrange}       { return YRANGE; }

{pi}          {
                yylval.dbl = 3.14159 ;
                return NUMBER ;
              }

{variable}    {
              yylval.str = new string(yytext);
              return VARIABLE;
            }

{number}      {
                yylval.dbl = atof(yytext);
                return NUMBER;
              }



{endline}     { return '\n';}

.             {;}

%%
