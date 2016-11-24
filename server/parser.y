%defines
    /* Bibliothèques requises pour générer le .hpp */
%code requires {
  #include <string>
}
%{
    //Bibliothèques
        #include <iostream>
        #include "./../server/src/Process.hpp"

        //Noms des champs
            const string Process::RESULT = "result";
            const string Process::RESULTS = "results";
            const string Process::VARS = "vars";
            const string Process::ANSWER = "ans";
            const string Process::GRAPH = "graph";
            const string Process::MASTER = "master";
            const string Process::ERROR = "error";
        //Mots réservés
            vector<string> Process::RESERVED = {"TEST"} ;
        //Initialisation diverse
            map<string, Process*> Process::processes;
            stack<Process*> Process::declared;

    //Namespace
        using namespace std;
        using json = nlohmann::json;

    //Constantes
        const int NEG = -1 ;
        const int POS = +1 ;

    //Fonctions lexer/bison
        int yylex();
        void yyerror(char const* msg) { cout << "\033[1;31mError: " << msg << "\033[0m" << endl; ; }

    //Raccourcis
        Process* current() { return Process::current() ; }
        void eval() { current()->eval() ; current()->jresult(); }
    //Processus principal
        auto master = new Process(Process::MASTER) ;

        int token = 0;
%}

    //Liste des membres de yyval
%union {
    double dbl;
    std::string *str;
}
    //Tokens de nombres et variables
%token <dbl>  NUMBER
%token <str>  VARIABLE FUNCTION FUNCTION_R
%token <str>  ARRAY
%token        SIGN
%token        EQU
%token        FROM TO STEP
%token        IF THEN ELSE ENDIF

    //Tokens d'opérations
%token PLS '+'
%token MIN '-'
%token MUL '*'
%token DIV '/'
%token MOD '%'
%token POW '^'
%token GT  '>'
%token LT  '<'

    //Tokens de fonctions
%token PLOT RANGE XRANGE YRANGE COLOR
%token SQRT SIN COS
%token EOL RESET

    //Associativité et priorité
%left  '<' '>'
%left  '+' '-'
%left  '*' '/' '%'
%right '^' '='
%precedence SIGN

    //Types
    //%type <dbl>   fcontent params farray
%type <dbl>   line expr
%type <dbl>   numr

    //Axiome
%start        line

%%

//Entrée
line: /* Epsilon */                         { ; }
    | line expr EOL                         { current()->store(EOL) ; eval() ;}
    | line decl '=' expr EOL                { Process::close() ;current()->store(EOL) ; eval() ; }
    ;

//Expression
expr:
    //Priorité
     '(' expr ')'                           { $$ =  $2; }
    //Signes
    | '+' expr %prec SIGN                   { current()->store(SIGN, POS) ; }
    | '-' expr %prec SIGN                   { current()->store(SIGN, NEG) ; }
    //Variables numériques
    | numrs                                 {}
    //Blocs
    | blocs                                 {}
    //Opérations basiques
    | expr '+' expr                         { current()->store(PLS) ; }
    | expr '-' expr                         { current()->store(MIN) ; }
    | expr '*' expr                         { current()->store(MUL) ; }
    | expr '/' expr                         { current()->store(DIV) ; }
    //Opérations avancées
    | expr '^' expr                         { current()->store(POW) ; }
    | expr '<' expr                         { current()->store(LT) ;  }
    | expr '>' expr                         { current()->store(GT) ;  }
    //Fonctions mathématiques
    | SQRT '(' expr ')'                     { current()->store(SQRT) ; }
    | COS '(' expr ')'                      { current()->store(COS)  ; }
    | SIN '(' expr ')'                      { current()->store(SIN)  ; }
    //Gestion des erreurs
    | error                                 { ; }
    ;

//Déclaration de fonctions et de variables
decl:
      VARIABLE '(' VARIABLE ')'             { Process::open(*$1, *$3) ; }
    ;

//Nombres, variables et fonctions
numr:
      NUMBER                                { current()->store(NUMBER, $1) ; }
    | VARIABLE                              { current()->store(VARIABLE, *$1) ; }
    | VARIABLE '(' expr ')'                 { current()->store(FUNCTION, *$1) ; }
    ;

numrs:
      numr                                  { ; }
    | VARIABLE '=' expr                     { current()->store(EQU, *$1) ; }
    | VARIABLE '(' range ')'                { current()->store(FUNCTION_R, *$1) ; }

blocs:
      IF '(' expr ')' stmt                   { current()->store(IF) ; }
     ;

stmt:
      THEN '[' expr ']'                     { current()->store(THEN) ; }
     ;

range:
    | '[' numr ',' numr ']'                 {
                                                current()->store(FROM, $2) ;
                                                current()->store(TO, $4) ;
                                                current()->store(STEP, 0) ;
                                            }
    ;
    //| '[' numr ',' numr ',' numr ']'        {}


    //plot_args: /* Epsilon */                    { ; }
    //| ',' RANGE '='
    //;

    /*
    //
    //| expr ':' expr                         { current()->store(RANGE) ; }
    //Affichage graphique
    //| PLOT '(' expr ')'                     { current()->store(PLOT) ; }


    misc: /* Epsilon                         { ; }
        |
        ;
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

//Définition du comportement des tokens
Process* Process::token(int& i) { switch (tokens[i]) {
    //Nombres et signes
        case NUMBER: number(i) ; break;
        case SIGN: sign(i) ; break;
    //Opérations
        case PLS: add(i); break;
        case MIN: sub(i); break;
        case MUL: mul(i); break;
        case DIV: div(i); break;
    //Fonctions
        case POW: pow(i); break;
        case SQRT: sqrt(i); break;
    //Trigonométrie
        case COS: cos(i); break;
        case SIN: sin(i); break;
    //Gestion des variables
        case EQU: affect(i) ; break;
        case VARIABLE: variable(i) ; break;
    //Appel de fonction
        case FUNCTION: function(i); break;
        case FUNCTION_R: function_r(i); break;
        case FROM: case TO: case STEP: break;
    //
        case LT: lt(i) ; break;
        case GT: gt(i) ; break;
    //
        case IF: logic_if(i); break;
        case THEN: logic_then(i); break;
        case ENDIF: logic_endif(i); break;
    //Fin de ligne
        case EOL: eol(i); break ;
    //Inconnu
        default: unknown(i) ; break;
} return this ; }
