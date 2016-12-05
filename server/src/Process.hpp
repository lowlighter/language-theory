#ifndef PROCESS_HPP
#define PROCESS_HPP
    //Bibliothèques
        #include <cmath>
        #include <map>
        #include <stack>
        #include <vector>
        #include "json.hpp"

    //Namespace
        using namespace std;
        using json = nlohmann::json;

    //Factorielle
        inline int factorial(int n) { return n > 1 ? n*factorial(n-1) : 1 ; }
        inline bool prime(int n) {
            if(n < 2) { return false; }
            if(n == 2) { return true; }
            if(n % 2 == 0) { return false; }
            for(int i=3; (i*i) <= n; i+=2) { if(n % i == 0 ) { return false; } }
            return true;
        }

    //Processus
        class Process {
            public:
            /* ============================================================================
                PARAMETRES ET CONSTANTES
            ============================================================================ */
                //Liste des mots clés reservés
                    static vector<string> RESERVED;
                        //Retourne true si le mot envoyé est reservé
                            static bool reserved(string word) { return (find(RESERVED.begin(), RESERVED.end(), word) != RESERVED.end()) ; }

                //Précision des nombres flottants et valeurs des signes
                    static const int DEFAULT_SAMPLE = 10000, NEG = -1, POS = +1 ;

                //Noms des champs et données JSON
                    static const string RESULT, RESULTS, VARS, ANSWER, ERROR, GRAPH, MASTER, TABLE, XS, YS, PLOTTED ;
                    json data;

                //Mode verbeux
                    bool verbose = false;
                    bool vresult = true ;

                //Identifiant (nom) du processus et nom de la variable d'évaluation
                    string id, var;
                //Variables temporaires
                    double a = 0, b = 0, c = 0;
                    vector< vector<double> > xs, ys;
                    vector<string> plotted;

            /* ============================================================================
                GESTION DES ACTIONS
            ============================================================================ */
                //A implémenter dans le parser
                //Permet de gérer les actions à effectuer selon les tokens reçus en paramètre
                    Process* token(int& i);

                //Fin de ligne : Met à jour la variable réponse
                    Process* eol(int i = 0) {
                        //Données JSON
                            data[TABLE] = (values[i] == 2);
                            if (names[i].size() > 1) { data[GRAPH] = names[i] ; } else { data[GRAPH] = (values[i] == 1); }
                            if (!rerror) { data[ERROR] = false ; } else { rerror = false; } ;
                        //Affichage
                            rreturn = true ;
                            return display("(;)\n") ;
                    }
                    Process* eolr() { if (!rerror) { data[ERROR] = false ; } else { rerror = false; } ; data[GRAPH] = rreturn = false ; return display("(§)\n") ; }
                //Opération non repertoriée
                    Process* unknown() { return display("?") ; }

                //Gestion des nombres et de leurs signes
                    Process* number(int i) { return display(print(values[i]))->push(values[i]) ; }
                    Process* sign(int i) { pop(1) ; return display((values[i] > 0 ? "(+)" : "(-)"))->push(values[i]*a) ; }

                //Opération basiques
                    Process* add() { pop(2) ; return display("+")->push(b + a) ; }
                    Process* sub() { pop(2) ; return display("-")->push(b - a) ; }
                    Process* mul() { pop(2) ; return display("*")->push(b * a) ; }
                    Process* div() { pop(2) ; return display("/")->push(b / a) ; }

                //Fonctions
                    Process* prm() { pop(1) ; return display("PRIME")->push(prime(a)) ; }
                    Process* mod() { pop(2) ; return display("mod")->push(fmod(b, a)) ; }
                    Process* pow() { pop(2) ; return display("^")->push(std::pow(b, a)) ; }
                    Process* fac() { pop(1) ; return display("!")->push(factorial(a)) ; }
                    Process* sqrt() { pop(1) ; return display("SQRT")->push(a >= 0 ? std::sqrt(a) : NAN) ; }
                    Process* log() { pop(1) ; return display("LOG")->push(std::log10(a)) ; }
                    Process* ln() { pop(1) ; return display("LN")->push(std::log(a)) ; }
                    Process* exp() { pop(1) ; return display("EXP")->push(std::exp(a)) ; }
                    Process* abs() { pop(1) ; return display("ABS")->push(std::abs(a)) ; }

                //Autres fonctions
                    Process* v_isset(int i = 0) { return display("[isset("+names[i]+")]")->push(vars.count(names[i])) ; }
                    Process* max() { pop(2) ; return display("max("+print(a)+","+print(b)+")")->push(std::max(a, b)) ; }
                    Process* min() { pop(2) ; return display("min("+print(a)+","+print(b)+")")->push(std::min(a, b)) ; }

                //Trigonométrie
                    Process* cos() { pop(1) ; return display("COS")->push(std::cos(a)) ; }
                    Process* sin() { pop(1) ; return display("SIN")->push(std::sin(a)) ; }
                    Process* tan() { pop(1) ; return display("TAN")->push(std::tan(a)) ; }

                //Affichage
                    Process* plot() { xs.clear(); ys.clear(); plotted.clear(); return display("[plot]") ; }
                    Process* table() { xs.clear(); ys.clear(); plotted.clear(); return display("[table]") ; }

                //Comparaison
                    Process* lt() { pop(2) ; return display("<")->push((b < a) ? 1 : 0) ; }
                    Process* gt() { pop(2) ; return display(">")->push((b > a) ? 1 : 0) ; }
                    Process* lte() { pop(2) ; return display("<=")->push((b <= a) ? 1 : 0) ; }
                    Process* gte() { pop(2) ; return display(">=")->push((b >= a) ? 1 : 0) ; }
                    Process* eequ() { pop(2) ; return display("==")->push((b == a) ? 1 : 0) ; }
                    Process* diff() { pop(2) ; return display("!=")->push((b != a) ? 1 : 0) ; }

                //Structure logique
                    Process* logic_if(int i = 0) { pop(3);
                        //Récupération du statement
                            auto process = statements[print(values[i+(a ? 1 : 2)])] ;
                        //Application du contexte
                            process->vars.clear();
                            for (auto it = vars.begin(); it != vars.end(); it++) { process->vars[it->first] = it->second ; }
                        //Evaluation
                            auto r = process->eval();
                            return display("{if;"+string(a ? "true" : "false")+";"+print(r)+"}")->push(r) ;
                    }
                    Process* logic_then(int i = 0) { return display("(then=stmt_"+print(values[i])+")") ; }
                    Process* logic_else(int i = 0) { return display("(else=stmt_"+print(values[i])+")") ; }

                //Logique combinatoire
                    Process* logic_and() { pop(2) ; return display("&&")->push(a && b) ; }
                    Process* logic_or() { pop(2) ; return display("||")->push(a || b) ; }

                //Affectation (variable)
                    Process* affect(int i = 0) {
                        //Vérification que l'identificateur n'est pas un mot reservé
                            if (!reserved(names[i])) { vars[names[i]] = pop() ; return display("[="+names[i]+"]") ; }
                        //Erreurs
                            return (error("Error: Use of reserved keyword "+names[i]+" as variable."), this);
                    }

                //Erreur de syntaxe
                    Process* syntax_error() {
                        //Erreurs
                            return (error("Error: Syntax error."), this);
                    }

                //Récupération (variable)
                    Process* variable(int i = 0) {
                        //Véirification que la variable existe
                            if (vars.count(names[i])) { return display("["+names[i]+"="+print(vars[names[i]])+"]")->push(vars[names[i]]) ; }
                            if (master()->vars.count(names[i])) { return display("[global_"+names[i]+"="+print(vars[names[i]])+"]")->push(master()->vars[names[i]]) ; }
                        //Erreurs
                            push(NAN);
                            return (error("Error: Undefined variable "+names[i]+"."), this);
                    }

                //Evaluation (fonction)
                    Process* function(int i = 0) {
                        //Vérification que la fonction existe
                            if (processes.count(names[i])) {
                                auto process = processes[names[i]];
                                auto a = process->vars[process->var] = pop() ;
                            //Application du contexte
                                process->vars.clear();
                                for (auto it = vars.begin(); it != vars.end(); it++) { process->vars[it->first] = it->second ; }
                                b = process->eval(a) ;
                                return display("["+names[i]+"("+process->var+"="+print(a)+")="+print(b)+"]")->push(b) ;
                            }
                        //Erreurs
                            push(NAN) ;
                            return (error("Error: Undefined call to function "+names[i]+"."), this) ;
                    }

                //Sous-fonction
                    Process* function_r(int i = 0) {
                        //Vérification que la fonction existe
                            if (processes.count(names[i])) {
                                //Définition de la range
                                    auto offset = values[i];
                                    auto from = values[i-1-offset], to = values[i-2-offset], step = values[i-3-offset];
                                    step = (step) ? step : ((double) (to-from)/DEFAULT_SAMPLE);
                                    display("["+names[i]+"("+print(from)+", "+print(to)+", "+(step ? print(step) : "auto")+")]");
                                    if (!step) { return (error("Error: Couldn't compute range"), this); }
                                //Evaluation
                                    vector<double> xv, yv;
                                    auto process = processes[names[i]] ;
                                    for (auto j = from; j <= to; j+=step) { yv.push_back(process->eval(j)); xv.push_back(j); if (process->verbose) { cout << endl; } }
                                //Retour
                                    xs.push_back(xv); ys.push_back(yv); plotted.push_back(process->id) ;
                                    return this;
                            }
                        //Erreurs
                            push(NAN) ;
                            return (error("Error: Undefined call to function "+names[i]+"."), this) ;
                    }

                //Ranges
                    Process* range_start(int i = 0) { values[i] = pop() ; return display("(from"+print(values[i])+")") ; }
                    Process* range_end(int i = 0) { values[i] = pop() ; return display("(to"+print(values[i])+")") ; }
                    Process* range_step(int i = 0) { values[i] = pop() ; return display("(step"+print(values[i])+")") ; }

            /* ============================================================================
                GESTION DES PROCESSUS
            ============================================================================ */
                //Constructeur
                    Process(string name, string var_name = "x") { id = name; var = var_name ; processes[name] = this ; } ;
                    Process(bool stmt) { if (stmt) { id = to_string(statements.size()); statements[id] = this ; var = "x" ; } }

                //Liste des processus définis et ceux en cours de définition
                    static map<string, Process*> processes, statements;
                    static stack<Process*> declared;
                        //Retourne le processus principal
                            static Process* master() { return processes.count(MASTER) ? processes[MASTER] : NULL ; }
                        //Retourne le processus en cours
                            static Process* current() { return declared.size() ? declared.top() : master() ; }
                        //Termine la déclaration d'un processus
                            static Process* close() { return (declared.size()) ? (declared.pop(), current()) : current() ; }
                        //Déclare un nouveau processus
                            static Process* open(string name, string var_name) {
                                //Ajout du nouveau processus à la liste des processus en cours de déclaration
                                    if (!reserved(name)) {
                                        declared.push(processes[name] = new Process(name, var_name));
                                        return current()->display("["+name+"("+var_name+")]") ;
                                    } else { error("Error: Use of reserved keyword "+name+" as function.") ; }
                                    return master() ;
                            }
                        //Déclare un nouvel état
                            static Process* open() {
                                //Ajout du nouveau processus à la liste des processus en cours de déclaration
                                    auto stmt = new Process(true);
                                    declared.push(stmt);
                                    return current()->display("[stmt_"+stmt->id+"]") ;
                            }

            /* ============================================================================
                GESTION DES TOKENS
            ============================================================================ */
                //Liste des tokens, valeurs et noms
                    vector<int> tokens ;
                    vector<double> values ;
                    vector<string> names ;

                //Enregistre dans les listes appropriées le token, sa valeur et son nom
                    Process* store(int token, double value = 0, string name = "#") { tokens.push_back(token) ; values.push_back(value) ; names.push_back(name) ; return this ; }
                        //Surchage pour stocker les valeurs n'ayant qu'un nom en donnée
                            Process* store(int token, string name) { return store(token, NAN, name) ; }

            /* ============================================================================
                GESTION DE LA PILE D'ANALYSE (EXPRESSIONS POSTFIXEES)
            ============================================================================ */
                //Liste des variables et des fonctions déclarées
                    map<string, double> vars ;
                    map<string, Process*> funcs ;
                //Pile de l'analyse sémantique
                    stack<double> stacked ;

                //Rajoute une valeur à la pile d'analyse
                    Process* push (double value) { stacked.push(value) ; return this ; }
                //Retourne et supprime la dernière valeur de la pile d'analyse
                    double pop () { if (stacked.size()) { auto tmp = stacked.top() ; stacked.pop() ; return tmp ; } else { return 0 ;} }
                        //Surchage permettant de récupérer jusqu'à 3 valeurs dans les variables tampons a, b et c
                            Process* pop(int buffer) { a = pop() ; if (buffer >= 2) { b = pop() ; } if (buffer >= 3) { c = pop() ; } return this ; }

                //Nettoie la pile d'analyse
                    Process* clear () { while (!stacked.empty()) { stacked.pop() ; } return this ; }

            /* ============================================================================
                GESTION DE LA PILE D'ANALYSE (EXPRESSIONS POSTFIXEES)
            ============================================================================ */
                //
                    double rresult = NAN; bool rreturn = false, rerror = false ;
                //Exécute le processus
                    double eval () { clear(); for (int i = 0; i < (int) tokens.size(); i++) { token(i) ; } return result() ; }
                //Evalue le processus en x
                    double eval(double x) { vars[var] = x; return eval() ; }
                //Evalue le processus de a à b par pas de step. Si ce dernier vaut 0, le pas sera calculé automatiquement
                    vector<double> eval(double a, double b, double step = 0) { step = (step) ? step : ((double) (b-a))/DEFAULT_SAMPLE ; vector<double> r ; for (double i = a; i <= b; i++) { r.push_back(eval(i)) ; } ; return r ; }
                //
                    double result() { rresult = (stacked.size()) ? stacked.top() : NAN ; vars[ANSWER] = rreturn ? rresult : NAN ; return vars[ANSWER] ; }
                    static void mresult() { if (master()->vresult) { ; cout << master()->rresult << endl ; } }
                //Résultat (json)
                    Process* jresult () {
                        //Enregistrement des variables
                            data[VARS] = vars ;
                            data[RESULT] = result();
                            data[XS] = xs;
                            data[YS] = ys;
                            data[PLOTTED] = plotted;
                        //Affichage
                            if (verbose) { this->dump() ; }

                            return this ;
                    }

            /* ============================================================================
                GESTION DE L'AFFICHAGE ET DU DEBUG
            ============================================================================ */
                //Gestion des erreurs
                    static Process* error(string msg) {
                        master()->rerror = true ;
                        master()->data[ERROR] = msg;
                        if (master()->verbose) { red("\r"+msg); }
                    }
                //Affiche le contenu des données json
                    Process* dump() { green(data.dump()) ; cout << endl ; return this ; }
                //Affiche la notation polonaise si le mode verbeux est actif
                    Process* display(string action) { if (verbose) { blue(" "+action) ; } ; return this ; }
                //Affiche d'une couleur différente le texte passé en paramètre
                    static void red(string text)   { cout << "\033[1;31m" << text << "\033[0m" ; }
                    static void green(string text) { cout << "\033[1;32m" << text << "\033[0m" ; }
                    static void blue(string text)  { cout << "\033[1;36m" << text << "\033[0m" ; }

                //Formatage de l'affichage
                    static string print(double a) { auto str = to_string(a) ;
                        //Supprime les 0 et les points inutiles
                            str.erase(str.find_last_not_of('0')+1, string::npos);
                            if (str.back() == '.') { str.erase(str.find_last_not_of('.')+1, string::npos); }
                        return str;
                    }
        };
#endif
