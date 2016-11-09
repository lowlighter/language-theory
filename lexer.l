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
xrange       (?i:x(range)?)
yrange       (?i:y(range)?)
color        (?i:c(olor)?)
endline      \n


/* Règles flex */
%%

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
