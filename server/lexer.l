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
number      [0-9]+(\.[0-9]+)?
variable    [a-zA-Z_][a-zA-Z_0-9]*
sqrt        (?i:sqrt)
sin         (?i:sin(us)?)
cos         (?i:cos(inus)?)
log         (?i:log?)
ln          (?i:ln?)
exp         (?i:exp?)
abs         (?i:abs?)
pi          (?i:pi)
e           (?i:e)
plot        (?i:plot)

    /* Parameters */
color       (?i:rc(olor)?)
endline     \n

%%
    /* Règles flex */

    /* Opérations */
\=            { return EQU ; }
\+            { return PLS; }
\-            { return MIN; }
\*            { return MUL ;}
\/            { return DIV ; }


    /* Comparaisons */
\<            { return LT ; }
\>            { return GT ; }
\<\=          { return GTE ; }
\>\=          { return LTE ; }
\=\=          { return EEQU ; }
!\=           { return DIFF ; }

    /* Structure */
\(            { return '(' ; }
\)            { return ')' ; }
\[            { return '[' ; }
\]            { return ']' ; }
\,            { return ',' ; }

    /* Ternaire */
\?            { return QM ; }
\:            { return DP ; }

    /* Logique */
\&{2}         { return AND ; }
\|{2}         { return OR ; }

    /* Fonctions mathématiques */
{sqrt}        { return SQRT; }
{sin}         { return SIN; }
{cos}         { return COS; }
{log}         { return LOG; }
{ln}          { return LN; }
{exp}         { return EXP; }
{abs}         { return ABS; }
\%            { return MOD ; }
\^            { return POW ; }

    /* Affichage */
{plot}        { return PLOT; }
update        { return UPDATE; }

    /* Constantes */
{pi}          { return PI ; }
{e}           { return EXP_E ;}

    /* Nombre et variable */
{number}      { yylval.dbl = atof(yytext); return NUMBER; }
{variable}    { yylval.str = new string(yytext); return VARIABLE; }

    /* Fin de ligne */
{endline}     { return EOL ; }

    /* Autre */
.             {;}

%%
