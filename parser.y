%defines

%{
  #include <iostream>
  #include <stdlib.h>

  using namespace std;

  int yylex();
  void yyerror(char const* msg);

  long int sym[26];
%}

%union {double dbl; int intg;}

%token BATATA
%token <dbl>  NUMBER
%token <intg> VARIABLE
%token        PRINT

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
    | VARIABLE                  { $$ = sym[$1]; }
    | VARIABLE '=' expr         { $$ = sym[$1] = $3; }
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
