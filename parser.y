%defines
%code requires {
  #include <string>
}
%{
  #include <iostream>
  #include <stdlib.h>
  #include <map>

  using namespace std;

  int yylex();
  void yyerror(char const* msg);

  std::map<std::string, int> vars;
%}

%union {double dbl; int intg; std::string *s;}

%token        BATATA
%token <dbl>  NUMBER
%token <s>    VARIABLE

%type <dbl>   line expr

%start        line

%right '='
%left '+' '-'
%left '*' '/' '%'
%right BATATA

%%

line: /* empty */                 {;}
    | line expr '\n'              {cout << $2 << endl;}
    ;

expr: NUMBER                    { $$ = $1; }
    | VARIABLE                  { $$ = vars[*$1]; }
    | VARIABLE '=' expr         { $$ = vars[*$1] = $3; }
    | expr '+' expr             { $$ = $1 + $3; }
    | expr '-' expr             { $$ = $1 - $3; }
    | expr '*' expr             { $$ = $1 * $3; }
    | expr '/' expr             { $$ = $1 / $3; }
    | '+' expr %prec BATATA     { $$ =  $2; }
    | '-' expr %prec BATATA     { $$ = -$2; }
    | '(' expr ')'              { $$ =  $2; }
    ;

%%

extern void yyerror(char const* msg) {
  cerr << "Error: " << msg << endl;
  exit(EXIT_FAILURE);
}
