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

%%
    /* Règles flex */

    /* Opérations */
\=            { return EQU ; }
\+            { return PLS; }
\-            { return MIN; }
\*            { return MUL ;}
\/            { return DIV ; }
\%            { return MOD ; }


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
\|{2}         { return OR  ; }

    /* Fonctions mathématiques */
prime         { return PRM ; }
sqrt          { return SQRT; }
sin           { return SIN ; }
cos           { return COS ; }
tan           { return TAN ; }
log           { return LOG ; }
ln            { return LN  ; }
exp           { return EXP ; }
abs           { return ABS ; }
\%            { return MOD ; }
\^            { return POW ; }
\!            { return FAC ; }

    /* Affichage */
plot          { return PLOT   ; }
update        { return UPDATE ; }

    /* Constantes */
pi            { return PI ; }
e             { return EXP_E ;}
true          { return TRUE ; }
false         { return FALSE ; }

    /* Nombre et variable */
{number}      { yylval.dbl = atof(yytext); return NUMBER; }
{variable}    { yylval.str = new string(yytext); return VARIABLE; }

    /* Fin de ligne */
\n            { return EOL ; }

    /* Autre */
.             {;}

%%
