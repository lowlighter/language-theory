%defines
    /* Bibliothèques requises pour générer le .hpp */
%code requires {
  #include <string>
}
%{
    //Bibliothèques
        #include <iostream>
        #include <cmath>
        #include <map>
        #include <stack>
        #include <vector>

    //Constantes
        const int PREC = 10000 ;

    //Namespace
        using namespace std;

    //Fonctions lexer/bison
        int yylex();
        void yyerror(char const* msg) { cerr << "Error: " << msg << endl; exit(EXIT_FAILURE); }

    //Expressions parsées et préparées
        vector<int> prepared ;
    //Valeurs des tokens
        vector<double> values ;
    //Liste des variables
        map<string, double> vars ;

    //Stocke un token et sa valeur dans leur tableaux respectifs
        void store(int token, double value = 0) { prepared.push_back(token) ; values.push_back(value) ; }

    //Récupére la dernière valeur de la pile passée en paramètre
        double retrieve(stack<double>& stacked) { auto tmp = stacked.top() ; stacked.pop() ; return tmp ; }

    //Fonction d'évaluation
        double eval(double x = 0, bool verbose = false);
%}

    //Liste des membres de yyval
%union {
    double dbl;
    std::string *str;
}
    //Tokens de nombres et variables
%token <dbl>  NUMBER
%token <str>  VARIABLE
%token <str>  ARRAY
%token        SIGN

    //Tokens d'opérations
%token PLS '+'
%token MIN '-'
%token MUL '*'
%token DIV '/'
%token MOD '%'
%token POW '^'

    //Tokens de fonctions
%token PLOT RANGE XRANGE YRANGE COLOR
%token SQRT SIN COS

    //Associativité et priorité

%left  PLS MIN
%left  MUL DIV MOD
%right POW
%precedence SIGN

    //Types
%type <dbl>   fcontent params farray
%type <dbl>   line expr

    //Axiome
%start        line

%%

line: /* Epsilon */                         { ; }
    | line expr                         { cout << eval(0) << endl; }
    ;

expr:
    //Nombre et variables
      NUMBER                                { store(NUMBER, $1) ; }
    | VARIABLE                              { store(VARIABLE, 0) ; }
    //Opérations basiques
    | expr '+' expr                         { store(PLS) ; }
    | expr '-' expr                         { store(MIN) ; }
    | expr '*' expr                         { store(MUL) ; }
    | expr '/' expr                         { store(DIV) ; }
    //Opérations avancées
    | expr '^' expr                         { store(POW) ; }
    //Fonctions mathématiques
    | SQRT '(' expr ')'                     { store(SQRT) ; }
    | COS '(' expr ')'                      { store(COS)  ; }
    | SIN '(' expr ')'                      { store(SIN)  ; }
    //Priorité
    | '(' expr ')'                          { $$ =  $2; }
    //Signes
    //| '+' expr %prec SIGN                   { $$ =  $2; }
    //| '-' expr %prec SIGN                   { $$ = -$2; }
    /*
        | PLOT '(' fcontent ')'           { $$ = $3;}
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
    ;

%%

double eval(double x, bool verbose) {
    //Pile de préparation
        stack<double> preparation ;
        double tmp = 0 ;

    //Parcours de la chaîne de préparation
        for (int i = 0; i < prepared.size(); i++) { switch (prepared[i]) {

            //Nombre : Ajout dans la pile
                case NUMBER:
                    if (verbose) { cout << values[i] << " " ; }
                    preparation.push(values[i]) ;
                    break;

            //Variable : Ajout de la valeur dans la pile
                case VARIABLE:
                    if (verbose) { cout << "x" << " " ; }
                    preparation.push(x) ;
                    break;

            //Addition : Addition des deux dernières valeurs empilées
                case PLS:
                    if (verbose) { cout << "+" << " " ; }
                    tmp = retrieve(preparation) ;
                    preparation.push(tmp + retrieve(preparation)) ;
                    break;

            //Soustraction : Soustraction des deux dernières valeurs empilées
                case MIN:
                    if (verbose) { cout << "-" << " " ; }
                    tmp = retrieve(preparation) ;
                    preparation.push(retrieve(preparation) - tmp) ;
                    break;

            //Multiplication : Multiplication des deux dernières valeurs empilées
                case MUL:
                    if (verbose) { cout << "*" << " " ; }
                    tmp = retrieve(preparation) ;
                    preparation.push(tmp * retrieve(preparation)) ;
                    break;

            //Division : Division des deux dernières valeurs empilées
                case DIV:
                    if (verbose) { cout << "/" << " " ; }
                    tmp = retrieve(preparation) ;
                    preparation.push(retrieve(preparation) / tmp) ;
                    break;

            //Puissance : Puissance des deux dernières valeurs empilées
                case POW:
                    if (verbose) { cout << "POW" << " " ; }
                    tmp = retrieve(preparation) ;
                    preparation.push(pow(retrieve(preparation), tmp)) ;
                    break;

            //Racine : Racine de la dernière valeur
                case SQRT:
                    if (verbose) { cout << "SQRT" << " " ; }
                    preparation.push(sqrt(retrieve(preparation))) ;
                    break;

            //Cosinus : Cosinus de la dernière valeur
                case COS:
                    if (verbose) { cout << "COS" << " " ; }
                    preparation.push(round(PREC*cos(retrieve(preparation))/PREC)) ;
                    break;

            //Sinus : Sinus de la dernière valeur
                case SIN:
                    if (verbose) { cout << "SIN" << " " ; }
                    preparation.push(round(PREC*sin(retrieve(preparation))/PREC)) ;
                    break;

            //Comportement par défaut
                default:
                    if (verbose) { cout << "[?]" << " "; }
                    break;
        } }

    //Résultat
        return preparation.top() ;
}
