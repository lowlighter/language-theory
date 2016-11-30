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
            const string Process::TABLE = "table";
            const string Process::ERROR = "error";
            const string Process::XS = "x";
            const string Process::YS = "y";
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
        const double C_PI = 3.14159;
        const double C_EXP_E = 2.71828;

    //Fonctions lexer/bison
        int yylex();
        void yyerror(char const* msg) {  }

    //Raccourcis
        Process* current() { return Process::current() ; }
        void eval() { current()->eval() ; current()->jresult(); }
    //Processus principal
        auto master = new Process(Process::MASTER) ;
        int token = 0, plot = 0, table = 0, plots = 1;
%}

    //Liste des membres de yyval
%union {
    double dbl;
    std::string *str;
}
    //Tokens de nombres et variables
%token <dbl>  NUMBER PI EXP_E
%token <str>  VARIABLE FUNCTION FUNCTION_R
%token        FROM TO STEP
%token        IF THEN ELSE

    //Tokens de fonctions
%token PLOT
%token SQRT SIN COS LOG LN EXP ABS POWER

    //Tokens de fin de lignes
%token EOL EOLR

    //Tokens d'erreurs
%token SYNTAX_ERROR

    //Associativité et priorité
%left  SIGN QM DP
%right EQU
%left  PLS MIN
%left  MUL DIV MOD
%right POW
%left  LT GT GTE LTE EEQU DIFF AND OR

    //Types
%type <dbl>   line expr
%type <dbl>   numr

    //Axiome
%start        line

%%

    //Entrée
line: /* Epsilon */                         { ; }
    | line expr EOL                         { current()->store(EOL, plot+table) ; table = plot = 0; eval() ;}
    | line decl EQU expr EOL                { current()->store(EOL) ; Process::close() ; current()->store(EOLR) ; eval() ; }
    | line VARIABLE EQU expr EOL            { current()->store(EQU, *$2) ; current()->store(EOLR) ; eval() ; }
    ;

    //Expression
expr:
    //Priorité
     '(' expr ')'                           { $$ =  $2; }
    //Constantes
    | PI { current()->store(NUMBER, C_PI) ; }
    | EXP_E { current()->store(NUMBER, C_EXP_E) ; }
    //Signes
    | PLS expr %prec SIGN                   { current()->store(SIGN, POS) ; }
    | MIN expr %prec SIGN                   { current()->store(SIGN, NEG) ; }
    //Variables numériques
    | numrs                                 { ; }
    //Blocs
    | plot                                  { plot = 1 ;}
    | range { ; }
    //Opérations basiques
    | expr PLS expr                         { current()->store(PLS) ; }
    | expr MIN expr                         { current()->store(MIN) ; }
    | expr MUL expr                         { current()->store(MUL) ; }
    | expr DIV expr                         { current()->store(DIV) ; }
    //Opérations avancées
    | expr POW expr                         { current()->store(POW) ; }
    //Comparaisons
    | expr LT expr                          { current()->store(LT) ;  }
    | expr GT expr                          { current()->store(GT) ;  }
    | expr LTE expr                         { current()->store(LTE) ;  }
    | expr GTE expr                         { current()->store(GTE) ;  }
    | expr EEQU expr                        { current()->store(EEQU) ;  }
    | expr DIFF expr                        { current()->store(DIFF) ;  }
    | expr AND expr                         { current()-> store(AND) ; }
    | expr OR expr                          { current()->store(OR) ; }
    //Fonctions mathématiques
    | SQRT   '(' expr ')'                   { current()->store(SQRT) ; }
    | COS    '(' expr ')'                   { current()->store(COS)  ; }
    | SIN    '(' expr ')'                   { current()->store(SIN)  ; }
    | LN     '(' expr ')'                   { current()->store(LN)  ; }
    | LOG    '(' expr ')'                   { current()->store(LOG)  ; }
    | EXP    '(' expr ')'                   { current()->store(EXP)  ; }
    | ABS    '(' expr ')'                   { current()->store(ABS)  ; }
    | POWER  '(' expr',' expr')'            { current()->store(POW)  ; }
    // Ternaire
    | expr QM expr DP expr                  {
                                              current()->store(THEN)  ;
                                              current()->store(ELSE)  ;
                                              current()->store(IF)    ;
                                            }
    //Gestion des erreurs
    | error                                 { current()->store(SYNTAX_ERROR) ; }
    ;

    //Déclaration de fonctions et de variables
decl:
      VARIABLE '(' VARIABLE ')'             { Process::open(*$1, *$3) ; }
    ;

    //Nombres, variables et fonctions
numr:
    //Nombre
      NUMBER                                { current()->store(NUMBER, $1) ; }
    //Variables et fonctions
    | VARIABLE                              { current()->store(VARIABLE, *$1) ; }
    | VARIABLE '(' expr ')'                 { current()->store(FUNCTION, *$1) ; }
    ;

    //Nomre, variables et fonctions évalués sur un tableau
numrs:
    //Nombres, variables et fonctions
      numr                                  { ; }
    //Tableau d'évaluation
    | VARIABLE '(' range ')'                { table = 2 ; current()->store(FUNCTION_R, *$1) ; }
    ;

    //Affichage
plot:
      plot_decl                             { plots = 1 ;}
    ;

    //Déclaration de l'affichage
plot_decl:
    PLOT '(' plot_func                      { ; }
;

    //Liste des fonctions à afficher
plot_func:
    VARIABLE ',' plot_func                  { current()->store(FUNCTION_R, plots, *$1) ; plots++ ; }
    | VARIABLE plot_range                   { current()->store(FUNCTION_R, plots, *$1) ; plots++ ; }
;

    //Range d'affichage
plot_range:
    ',' range ')'                           { current()->store(PLOT) ; }

    //Ranges
range: range_from { ; }
    ;

    //Range (from)
range_from:
    '[' expr range_to                       { current()->store(FROM) ; }
    ;

    //Range (to)
range_to:
    ',' expr range_step                     { current()->store(TO) ; }
    ;

    //Range (step)
range_step:
    ']'                                     {  current()->store(NUMBER, 0) ; current()->store(STEP) ; }
    | ',' expr ']'                          { current()->store(STEP) ;}
    ;
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
        case LOG: log(i); break;
        case LN: ln(i); break;
        case EXP: exp(i); break;
        case ABS: abs(i); break;
    //Trigonométrie
        case COS: cos(i); break;
        case SIN: sin(i); break;
    //Gestion des variables
        case EQU: affect(i) ; break;
        case VARIABLE: variable(i) ; break;
    //Appel de fonction
        case FUNCTION: function(i); break;
        case FUNCTION_R: function_r(i); break;
        case FROM: range_start(i); break;
        case TO: range_end(i); break;
        case STEP: range_step(i);break;
    //Affichage
        case PLOT: plot(i); break;
    //Tests logiques
        case LT: lt(i) ; break; case LTE: lte(i) ; break;
        case GT: gt(i) ; break; case GTE: gte(i) ; break;
        case EEQU: eequ(i) ; break;
        case AND: logic_and(i); break; case OR: logic_or(i); break;
    //Blocs logiques
        case IF: logic_if(i); break;
        case THEN: logic_then(i); break;
        case ELSE: logic_else(i); break;
    //Fin de ligne
        case EOL: eol(i); break ;
        case EOLR: eolr(i); break;
        case SYNTAX_ERROR: syntax_error(i); break;
    //Inconnu
        default: unknown(i) ; break;
} return this ; }
