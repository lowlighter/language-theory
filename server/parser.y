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
            const string Process::PLOTTED = "plotted";
        //Mots réservés
            vector<string> Process::RESERVED = {"pi", "sin", "cos", "tan", "prime", "sqrt", "log", "ln", "exp", "abs", "plot", "update", "e", "true", "false"} ;
        //Initialisation diverse
            map<string, Process*> Process::processes, Process::statements;
            stack<Process*> Process::declared;

    //Namespace
        using namespace std;
        using json = nlohmann::json;

    //Constantes
        const int NEG = -1 ;
        const int POS = +1 ;
        const double C_PI = 3.14159265359;
        const double C_EXP_E = 2.71828182846;
        const double C_TRUE = 1;
        const double C_FALSE = 0;
        const int DEFAULT_START = -10 ;
        const int DEFAULT_END = +10 ;
        const int DEFAULT_STEP = +1 ;

    //Fonctions lexer/bison
        int yylex();
        void yyerror(char const* msg) {  }

    //Raccourcis
        Process* current() { return Process::current() ; }
        void eval() { current()->eval() ; current()->jresult(); }
    //Processus principal
        auto master = new Process(Process::MASTER) ;
        int token = 0, plot = 0, table = 0, plots = 1, stmt = 0;
        string update_id;
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
%token        IF THEN ELSE TRUE FALSE
%token        UPDATE

    //Tokens de fonctions
%token PLOT
%token SQRT SIN COS TAN LOG LN EXP ABS POWER PRM

    //Tokens de fin de lignes
%token EOL EOLR

    //Tokens d'erreurs
%token SYNTAX_ERROR

    //Associativité et priorité
%left  QM DP
%right EQU
%left  PLS MIN
%left  MUL DIV
%right MOD POW
%left  FAC SIGN
%left  LT GT GTE LTE EEQU DIFF AND OR
%precedence RULE

    //Types
%type <dbl>   line expr
%type <dbl>   numr

    //Axiome
%start        line

%%

    //Entrée
line: /* Epsilon */                         { ; }
    | line expr EOL                         { current()->store(EOL, plot+table, update_id) ; update_id = "" ; table = plot = 0; eval() ;}
    | line decl EQU expr EOL                { current()->store(EOL) ; Process::close() ; current()->store(EOLR) ; eval() ; }
    | line VARIABLE EQU expr EOL            { current()->store(EQU, *$2) ; current()->store(EOLR) ; eval() ; }
    ;

    //Expression
expr:
    //Priorité
     '(' expr ')'                           { $$ =  $2; }
    //Constantes
    | PI                                    { current()->store(NUMBER, C_PI) ; }
    | EXP_E                                 { current()->store(NUMBER, C_EXP_E) ; }
    | TRUE                                  { current()->store(NUMBER, C_TRUE) ; }
    | FALSE                                 { current()->store(NUMBER, C_FALSE) ; }
    //Signes
    | PLS expr %prec SIGN                   { current()->store(SIGN, POS) ; }
    | MIN expr %prec SIGN                   { current()->store(SIGN, NEG) ; }
    //Variables numériques
    | numrs                                 { ; }
    //Blocs
    | plot                                  { plot = 1 ; }
    //Opérations basiques
    | expr PLS expr                         { current()->store(PLS) ; }
    | expr MIN expr                         { current()->store(MIN) ; }
    | expr MUL expr                         { current()->store(MUL) ; }
    | expr DIV expr                         { current()->store(DIV) ; }
    | expr MOD expr                         { current()->store(MOD) ; }
    //Opérations avancées
    | expr POW expr                         { current()->store(POW) ; }
    | expr FAC expr                         { current()->store(FAC) ; }
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
    | TAN    '(' expr ')'                   { current()->store(TAN)  ; }
    | LN     '(' expr ')'                   { current()->store(LN)  ; }
    | LOG    '(' expr ')'                   { current()->store(LOG)  ; }
    | EXP    '(' expr ')'                   { current()->store(EXP)  ; }
    | ABS    '(' expr ')'                   { current()->store(ABS)  ; }
    | PRM    '(' expr ')'                   { current()->store(PRM)  ; }
    | POWER  '(' expr',' expr')'            { current()->store(POW)  ; }
    // Ternaire
    | ternary %prec RULE                    { current()->store(IF) ; current()->store(THEN, stmt) ; current()->store(ELSE, stmt+1) ; stmt+=2 ; }
    //Gestion des erreurs
    | error                                 { current()->store(SYNTAX_ERROR) ; }
    ;

    //Opérations ternaires
ternary:
    expr                                    { Process::open() ;}
    QM expr                                 { current()->store(EOL) ; Process::close(); Process::open() ; }
    DP expr                                 { current()->store(EOL) ; Process::close();  }
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
    | VARIABLE '(' expr ')' %prec RULE      { current()->store(FUNCTION, *$1) ; }
    ;

    //Nomre, variables et fonctions évalués sur un tableau
numrs:
    //Nombres, variables et fonctions
      numr                                  { ; }
    //Tableau d'évaluation
    | VARIABLE '(' range ')'                { table = 2 ; current()->store(FUNCTION_R, 0, *$1) ; }
    ;

    //Affichage
plot:
      plot_decl                             { plots = 1 ; }
    ;

    //Déclaration de l'affichage
plot_decl:
      PLOT '(' plot_func                    { ; }
    | UPDATE '(' VARIABLE ',' plot_func     { update_id = *$3 ; }
;

    //Liste des fonctions à afficher
plot_func:
      VARIABLE ',' plot_func                { current()->store(FUNCTION_R, plots, *$1) ; plots++ ; }
    | VARIABLE ')'                          { current()->store(NUMBER, DEFAULT_START) ; current()->store(NUMBER, DEFAULT_END) ; current()->store(NUMBER, DEFAULT_STEP) ; current()->store(STEP) ; current()->store(TO) ; current()->store(FROM) ; current()->store(PLOT) ; current()->store(FUNCTION_R, plots, *$1) ; plots++ ; }
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
      ']'                                   { current()->store(NUMBER, 0) ; current()->store(STEP) ; }
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
        case MOD: mod(i); break;
    //Fonctions
        case FAC: fac(i); break;
        case POW: pow(i); break;
        case SQRT: sqrt(i); break;
        case LOG: log(i); break;
        case LN: ln(i); break;
        case EXP: exp(i); break;
        case ABS: abs(i); break;
        case PRM: prm(i); break;
    //Trigonométrie
        case COS: cos(i); break;
        case SIN: sin(i); break;
        case TAN: tan(i); break;
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
