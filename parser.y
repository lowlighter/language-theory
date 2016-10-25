%defines

%{
  #include <iostream>

  using namespace std;

  extern int yylex();
  extern void yyerror(char const* msg);
%}

%union
{
  double dbl;
};

%token<dbl> LITERAL_DBL

%type<dbl> expr
%type<dbl> term

%start root

%%

root: /* empty */
    | root expr '\n'          {cout << $2 << endl;}
    ;

expr: term             {$$ = $1;}
    | expr '+' term    {$$ = $1 + $3;}
    | expr '-' term    {$$ = $1 - $3;}
    ;

term: LITERAL_DBL             {$$ = $1;}
    | term '*' LITERAL_DBL    {$$ = $1 * $3;}
    | term '/' LITERAL_DBL    {$$ = $1 / $3;}
    ;

%%

extern void yyerror(char const* msg) {
  cerr << "Error: " << msg << endl;
}
