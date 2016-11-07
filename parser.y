%defines
%code requires {
  #include <string>
}
%{
  #include <iostream>
  #include <stdlib.h>
  #include <map>
  #include <cmath>

  using namespace std;

  int yylex();
  void yyerror(char const* msg);

  std::map<std::string, int> vars;
%}

/* */
%union {double dbl; int intg; std::string *s;}

%token        BATATA
%token <dbl>  NUMBER
%token <s>    VARIABLE
%token        SQRT SIN COS

%type <dbl>   line expr

%start        line

//Associativité
%left '+' '-'
%left '*' '/' '%'
%precedence BATATA
%right '=' '^'


%%

line: /* empty */                 {;}
    | line expr '\n'              {cout << $2 << endl;}
    ;

expr: NUMBER                    { $$ = $1; }
    //Affectation
    | VARIABLE                  { $$ = vars[*$1]; delete $1;}
    | VARIABLE '=' expr         { $$ = vars[*$1] = $3; delete $1;}
    //Opérations basiques
    | expr '+' expr             { $$ = $1 + $3; }
    | expr '-' expr             { $$ = $1 - $3; }
    | expr '*' expr             { $$ = $1 * $3; }
    | expr '/' expr             { $$ = $1 / $3; }
    //Signes
    | '+' expr %prec BATATA     { $$ =  $2; }
    | '-' expr %prec BATATA     { $$ = -$2; }
    //Puissance
    | expr '^' expr             { $$ = pow($1, $3); }
    //Priorité
    | '(' expr ')'              { $$ =  $2; }
    //Fonctions mathématiques
    | SQRT '(' expr ')'          { $$ = sqrt($3) ; }
    | COS '(' expr ')'           { $$ = round(10000*cos($3))/10000 ; }
    | SIN '(' expr ')'           { $$ = round(10000*sin($3))/10000 ; }
    ;

%%

extern void yyerror(char const* msg) {
  cerr << "Error: " << msg << endl;
  exit(EXIT_FAILURE);
}
