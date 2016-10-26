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

%token <dbl>  NUMBER
%token <intg> VARIABLE
%token        PRINT

%type <dbl>   line expr factor term

%start        line

%left '+' '-' '*' '/'

%%

line: /* empty */               {;}
    | line expr '\n'            {cout << $2 << endl;}
    | line VARIABLE expr '\n'   { sym[$2] = $3;}
    | line PRINT VARIABLE '\n'  {cout << sym[$3] << endl;}
    ;

expr: factor                    {$$ = $1;}
    | expr '+' term             {$$ = $1 + $3;}
    | expr '-' term             {$$ = $1 - $3;}
    ;

factor: term                    {$$ = $1;}
    | expr '*' NUMBER           {$$ = $1 * $3;}
    | expr '/' NUMBER           {
                                  if($3) {
                                    $$ = $1 / $3;
                                  } else {
                                    yyerror("Division by zero");
                                  }
                                }
    ;

term: NUMBER                    {$$ = $1;}
    | '(' expr ')'              {$$ = $2;}
    ;

%%

extern void yyerror(char const* msg) {
  cerr << "Error: " << msg << endl;
  exit(EXIT_FAILURE);
}
