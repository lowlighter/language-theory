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

%start root

%%

root: /* empty */
    | root expr '\n'          {cout << $2 << endl;}
    ;

expr: LITERAL_DBL             {$$ = $1;}
    | expr '+' LITERAL_DBL    {$$ = $1 + $3;}
    | expr '-' LITERAL_DBL    {$$ = $1 - $3;}
    ;

%%

extern void yyerror(char const* msg) {
  cerr << "Lexer error: " << msg << endl;
}
