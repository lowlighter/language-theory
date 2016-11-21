%defines
    /* Bibliothèques requises pour générer le .hpp */
%code requires {
  #include <string>
}
%{
    //Bibliothèques
        #include <iostream>
        #include "./../server/src/Process.hpp"

    //Namespace
        using namespace std;
        using json = nlohmann::json;

    //Constantes
        const int NEG = -1 ;
        const int POS = +1 ;

    //Fonctions lexer/bison
        int yylex();
        void yyerror(char const* msg) { cerr << "Error: " << msg << endl; exit(EXIT_FAILURE); }

    //Processus principal
        auto master = new Process() ;
        auto process = master ;
%}

    //Liste des membres de yyval
%union {
    double dbl;
    std::string *str;
}
    //Tokens de nombres et variables
%token <dbl>  NUMBER
%token <str>  VARIABLE FUNCTION
%token <str>  ARRAY
%token        SIGN
%token        FROM TO STEP

    //Tokens d'opérations
%token PLS '+'
%token MIN '-'
%token MUL '*'
%token DIV '/'
%token MOD '%'
%token POW '^'
%token EQU '='
%token EOL ';'

    //Tokens de fonctions
%token PLOT RANGE XRANGE YRANGE COLOR
%token SQRT SIN COS

    //Associativité et priorité
%left  '+' '-'
%left  '*' '/' '%'
%right '^' '='
%precedence SIGN

    //Types
    //%type <dbl>   fcontent params farray
%type <dbl>   line expr

    //Axiome
%start        line

%%

line: /* Epsilon */                         { ; }
    | line expr '\n'                        { process->store(EOL) ; process->eval() ; }
    ;

expr:
    //Nombre et variables
      NUMBER                                { process->store(NUMBER, $1) ; }
    | VARIABLE                              { process->store(VARIABLE, *$1) ; }
    //Affectation de variable et de fonction
    | VARIABLE '=' expr                     { process->store(EQU, *$1) ; }
    //| VARIABLE '(' expr ')' '=' expr        { process->store(FUNCTION, *$1) ; }
    //Opérations basiques
    | expr '+' expr                         { process->store(PLS) ; }
    | expr '-' expr                         { process->store(MIN) ; }
    | expr '*' expr                         { process->store(MUL) ; }
    | expr '/' expr                         { process->store(DIV) ; }
    //Opérations avancées
    | expr '^' expr                         { process->store(POW) ; }
    //Fonctions mathématiques
    | SQRT '(' expr ')'                     { process->store(SQRT) ; }
    | COS '(' expr ')'                      { process->store(COS)  ; }
    | SIN '(' expr ')'                      { process->store(SIN)  ; }
    //Priorité
    | '(' expr ')'                          { $$ =  $2; }
    //Signes
    | '+' expr %prec SIGN                   { process->store(SIGN, POS) ; }
    | '-' expr %prec SIGN                   { process->store(SIGN, NEG) ; }
    //
    | expr ':' expr                         { process->store(TO) ; process->store(FROM) ; }
    //Affichage graphique
    | PLOT '(' expr ')'                     { process->store(PLOT) ; }
    ;



    //plot_args: /* Epsilon */                    { ; }
    //| ',' RANGE '='
    //;

    /*
    fcontent: /* empty *//*                 { ; }
        | expr params                     { $$ = $1; }
        ;

    params: /* empty *//*                   { ; }
        | ',' RANGE '=' '[' farray ']' params    { ; }
        | ',' XRANGE '=' '[' farray ']' params   { ; }
        | ',' YRANGE '=' '[' farray ']' params   { ; }
        ;

    farray: /* empty *//*                   { ; }
        | expr ',' farray                 { ; }
        | expr                            { ; }
    */
    //;

%%

Process* Process::token(int i) { switch (tokens[i]) {
    case EOL: eol(); break ;
    case SIGN: sign(i) ; break;
    case NUMBER: number(i) ; break;
    case EQU: affect(i) ; break;
    case VARIABLE: variable(i) ; break;
    case PLS: add(); break;
    case MIN: sub(); break;
    case MUL: mul(); break;
    case DIV: div(); break;
    case POW: pow(); break;
    case SQRT: sqrt(); break;
    case COS: cos(); break;
    case SIN: sin(); break;

    default: unknown() ; break;
    }
}
