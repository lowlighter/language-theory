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
        vector<string> Process::RESERVED = {"ans", "pi", "sin", "cos", "tan", "prime", "sqrt", "log", "ln", "exp", "abs", "plot", "update", "e", "true", "false"} ;
    //Initialisation diverse
        map<string, Process*> Process::processes, Process::statements;
        stack<Process*> Process::declared;

    //Namespace
        using namespace std;
        using json = nlohmann::json;

    //Constantes
        const int NEG = -1 ;
        const int POS = +1 ;
        const double C_PI = M_PI;
        const double C_EXP_E = M_E;
        const double C_TRUE = 1;
        const double C_FALSE = 0;
        const int DEFAULT_START = -5 ;
        const int DEFAULT_END = +5 ;
        const int DEFAULT_STEP = 0.1 ;

    //Fonctions lexer/bison
        int yylex();
        void yyerror(char const* msg) {  }

    //Processus principal
        auto master = new Process(Process::MASTER) ;
        int token = 0, plots = 1, stmt = 0, show = 0;
        string update_id;

    //Raccourcis
        Process* current() { return Process::current() ; }
        void eval() { current()->eval() ; current()->jresult(); }
%}

    //Liste des membres de yyval
%union {
    double dbl;
    std::string *str;
}
    //Tokens de nombres et variables
%token <dbl>  NUMBER PI EXP_E
%token <str>  VARIABLE FUNCTION FUNCTION_R
%token        FROM TO STEP RTABLE
%token        IF THEN ELSE TRUE FALSE ISSET
%token        UPDATE

    //Tokens de fonctions
%token PLOT
%token SQRT SIN COS TAN LOG LN EXP ABS POWER PRM MAX MIN ACOS ASIN ATAN SINH COSH TANH ACOSH ASINH ATANH

    //Tokens de fin de lignes
%token EOL EOLR

    //Tokens d'erreurs
%token SYNTAX_ERROR

    //Associativité et priorité
%right EQU FEQU
%left  QM DP
%left  LT GT GTE LTE EEQU DIFF AND OR
%left  PLS SUB
%left  MUL DIV MOD
%right POW
%left  FAC SIGN

    //Types
%type <dbl>   line expr


    //Axiome
%start        line

%%

    //Entrée
line: /* Epsilon */                         { ; }
    | line type                             { eval() ; if (show) { Process::mresult() ; } show = 0; }
    ;

type:
    //Déclaration de fonction
      VARIABLE '(' VARIABLE FEQU            { Process::open(*$1, *$3) ; }
      expr EOL                              { current()->store(EOL) ; Process::close() ; current()->store(EOLR) ; }
    //Déclaration de variable
    | VARIABLE EQU expr EOL                 { current()->store(EQU, *$1) ; current()->store(EOLR) ; }
    //Entrée utilisateur
    | expr EOL                              { current()->store(EOL) ; show = 1 ; }
    //Affichage
    | plot EOL                              { current()->store(EOL, 1, update_id) ; update_id = ""; }
    //Tableau d'évaluation
    | VARIABLE '(' range ')' EOL            { current()->store(RTABLE) ; current()->store(FUNCTION_R, 1, *$1) ; current()->store(EOL) ; }
    ;

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
    | SUB expr %prec SIGN                   { current()->store(SIGN, NEG) ; }
    //Ternaire
    | expr QM { Process::open() ;} ternary  { current()->store(IF) ; current()->store(THEN, stmt) ; current()->store(ELSE, stmt+1) ; stmt+=2 ; }
    //Nombre
    | numr                                  { ; }
    //Opérations basiques
    | expr PLS expr                         { current()->store(PLS) ; }
    | expr SUB expr                         { current()->store(SUB) ; }
    | expr MUL expr                         { current()->store(MUL) ; }
    | expr DIV expr                         { current()->store(DIV) ; }
    | expr MOD expr                         { current()->store(MOD) ; }
    //Opérations avancées
    | expr POW expr                         { current()->store(POW) ; }
    | expr FAC expr                         { current()->store(FAC) ; }
    | expr FAC                              { current()->store(FAC) ; }
    //Comparaisons
    | expr LT expr                          { current()->store(LT) ;  }
    | expr GT expr                          { current()->store(GT) ;  }
    | expr LTE expr                         { current()->store(LTE) ;  }
    | expr GTE expr                         { current()->store(GTE) ;  }
    | expr EEQU expr                        { current()->store(EEQU) ;  }
    | expr DIFF expr                        { current()->store(DIFF) ;  }
    | expr AND expr                         { current()->store(AND) ; }
    | expr OR expr                          { current()->store(OR) ; }
    //Fonctions mathématiques
    | SQRT   '(' expr ')'                   { current()->store(SQRT) ; }
    | COS    '(' expr ')'                   { current()->store(COS)  ; }
    | SIN    '(' expr ')'                   { current()->store(SIN)  ; }
    | TAN    '(' expr ')'                   { current()->store(TAN)  ; }
    | ACOS   '(' expr ')'                   { current()->store(ACOS)  ; }
    | ASIN   '(' expr ')'                   { current()->store(ASIN)  ; }
    | ATAN   '(' expr ')'                   { current()->store(ATAN)  ; }
    | COSH    '(' expr ')'                  { current()->store(COSH)  ; }
    | SINH    '(' expr ')'                  { current()->store(SINH)  ; }
    | TANH    '(' expr ')'                  { current()->store(TANH)  ; }
    | ACOSH   '(' expr ')'                  { current()->store(ACOSH)  ; }
    | ASINH   '(' expr ')'                  { current()->store(ASINH)  ; }
    | ATANH   '(' expr ')'                  { current()->store(ATANH)  ; }
    | LN     '(' expr ')'                   { current()->store(LN)  ; }
    | LOG    '(' expr ')'                   { current()->store(LOG)  ; }
    | EXP    '(' expr ')'                   { current()->store(EXP)  ; }
    | ABS    '(' expr ')'                   { current()->store(ABS)  ; }
    | PRM    '(' expr ')'                   { current()->store(PRM)  ; }
    | POWER  '(' expr',' expr')'            { current()->store(POW)  ; }
    //Fonctions autres
    | ISSET '(' VARIABLE ')'                { current()->store(ISSET, *$3) ; }
    | MAX   '(' expr ',' expr ')'           { current()->store(MAX) ; }
    | MIN   '(' expr ',' expr ')'           { current()->store(MIN) ; }
    //Gestion des erreurs
    | error                                 { current()->store(SYNTAX_ERROR) ; Process::close() ; }
    ;

    //Nombres, variables et fonctions
numr:
    //Nombre
      NUMBER                                { current()->store(NUMBER, $1) ; }
    //Variables et fonctions
    | VARIABLE                              { current()->store(VARIABLE, *$1) ;  }
    | VARIABLE '(' expr ')'                 { current()->store(FUNCTION, *$1) ; }
    ;

    //Opérations ternaires
ternary:
      expr                                  { current()->store(EOL) ; Process::close(); Process::open() ; }
      DP expr                               { current()->store(EOL) ; Process::close();  }
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
    ;

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

Process* Process::token(int& i) { switch (tokens[i]) {
    //Nombres et signes
        case NUMBER: number(i) ; break;
        case SIGN: sign(i) ; break;
    //Opérations
        case PLS: add(); break;
        case SUB: sub(); break;
        case MUL: mul(); break;
        case DIV: div(); break;
        case MOD: mod(); break;
    //Fonctions
        case FAC: fac(); break;
        case POW: pow(); break;
        case SQRT: sqrt(); break;
        case LOG: log(); break;
        case LN: ln(); break;
        case EXP: exp(); break;
        case ABS: abs(); break;
        case PRM: prm(); break;
    //Trigonométrie
        case COS: cos(); break;
        case SIN: sin(); break;
        case TAN: tan(); break;
        case ACOS: acos(); break;
        case ASIN: asin(); break;
        case ATAN: atan(); break;
        case COSH: cosh(); break;
        case SINH: sinh(); break;
        case TANH: tanh(); break;
        case ACOSH: acosh(); break;
        case ASINH: asinh(); break;
        case ATANH: atanh(); break;
    //Autre
        case ISSET: v_isset(i); break;
        case MAX: max(); break;
        case MIN: min(); break;
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
        case PLOT: plot(); break;
        case RTABLE: table(); break;
    //Tests logiques
        case LT: lt() ; break; case LTE: lte() ; break;
        case GT: gt() ; break; case GTE: gte() ; break;
        case EEQU: eequ() ; break; case DIFF: diff() ; break;
        case AND: logic_and(); break; case OR: logic_or(); break;
    //Blocs logiques
        case IF: logic_if(i); break;
        case THEN: logic_then(i); break;
        case ELSE: logic_else(i); break;
    //Fin de ligne
        case EOL: eol(i); break ;
        case EOLR: eolr(); break;
        case SYNTAX_ERROR: syntax_error(); break;
    //Inconnu
        default: unknown() ; break;
} return this ; }
