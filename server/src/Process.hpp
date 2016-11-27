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
                    static const int PRECISION = 10000, DEFAULT_SAMPLE = 10, NEG = -1, POS = +1 ;

                //Noms des champs et données JSON
                    static const string RESULT, RESULTS, VARS, ANSWER, ERROR, GRAPH, MASTER ;
                    json data;

                //Mode verbeux
                    bool verbose = true ;

                //Identifiant (nom) du processus et nom de la variable d'évaluation
                    string id, var;
                //Variables temporaires
                    double a = 0, b = 0, c = 0;

            /* ============================================================================
                GESTION DES ACTIONS
            ============================================================================ */
                //A implémenter dans le parser
                //Permet de gérer les actions à effectuer selon les tokens reçus en paramètre
                    Process* token(int& i);

                //Fin de ligne : Met à jour la variable réponse
                    Process* eol(int i = 0) { return display("\n") ; }
                //Opération non repertoriée
                    Process* unknown(int i = 0) { return display("?") ; }

                //Gestion des nombres et de leurs signes
                    Process* number(int i) { return display(print(values[i]))->push(values[i]) ; }
                    Process* sign(int i) { return display((values[i] > 0 ? "(+)" : "(-)"))->pop(1)->push(values[i]*a) ; }

                //Opération basiques
                    Process* add(int i = 0) { pop(2) ; return display("+")->push(a + b) ; }
                    Process* sub(int i = 0) { pop(2) ; return display("-")->push(a - b) ; }
                    Process* mul(int i = 0) { pop(2) ; return display("*")->push(a * b) ; }
                    Process* div(int i = 0) { pop(2) ; return display("/")->push(a / b) ; }

                //Fonctions
                    Process* pow(int i = 0) { pop(2) ; return display("^")->push(std::pow(b, a)) ; }
                    Process* sqrt(int i = 0) { pop(1) ; return display("SQRT")->push(std::sqrt(a)) ; }

                //Trigonométrie
                    Process* cos(int i = 0) { pop(1) ; return display("COS")->push(round(PRECISION*std::cos(a))/PRECISION) ; }
                    Process* sin(int i = 0) { pop(1) ; return display("SIN")->push(round(PRECISION*std::sin(b))/PRECISION) ; }

                    Process* plot(int i = 0) { data[GRAPH] = true ; return display("[plot]") ; }

                    Process* lt(int i = 0) { pop(2) ; return display("<")->push((b < a) ? 1 : 0) ; }
                    Process* gt(int i = 0) { pop(2) ; return display(">")->push((b > a) ? 1 : 0) ; }

                    Process* logic_if(int i = 0) { return display("IF") ; }
                    Process* logic_then(int i = 0) { return display("THEN") ; }
                    Process* logic_endif(int i = 0) { return display("ENDIF") ; }

                //Affectation (variable)
                    Process* affect(int i) {
                        //Vérification que l'identificateur n'est pas un mot reservé
                            if (!reserved(names[i])) { vars[names[i]] = pop() ; return display("[="+names[i]+"]") ; }
                        //Erreurs
                            auto msg = "Error: Use of reserved keyword "+names[i]+" as variable."; data[ERROR] = msg; red("\r"+msg); return this ;
                    }

                //Récupération (variable)
                    Process* variable(int i) {
                        //Véirification que la variable existe
                            if (vars.count(names[i])) { return display("["+names[i]+"="+print(vars[names[i]])+"]")->push(vars[names[i]]) ; }
                        //Erreurs
                            auto msg = "Error: Undefined variable "+names[i] ; data[ERROR] = msg; red("\r"+msg); push(NAN) ; return this ;
                    }

                //Evaluation (fonction)
                    Process* function(int i) {
                        //Vérification que la fonction existe
                            if (processes.count(names[i])) {
                                auto process = processes[names[i]];
                                auto a = process->vars[process->var] = pop() ;
                                b = process->eval(a) ;
                                return display("["+names[i]+"("+process->var+"="+print(a)+")="+print(b)+"]")->push(b) ;
                            }
                        //Erreurs
                            auto msg = "Error: Undefined call to function "+names[i] ; data[ERROR] = msg; red("\r"+msg); push(NAN) ; return this ;
                    }

                    Process* function_r(int i) {
                        //Vérification que la fonction existe
                            if (processes.count(names[i])) {
                                //Définition de la range
                                    auto from = values[i-3], to = values[i-2], step = values[i-1];
                                    step = (step) ? step : ((double) (to-from)/DEFAULT_SAMPLE);
                                    display("["+names[i]+"("+print(from)+", "+print(to)+", "+(step ? print(step) : "auto")+")]");
                                //Evaluation
                                    vector<double> y_values;
                                    vector<double> x_values;
                                    auto process = processes[names[i]] ;
                                    for (auto j = from; j <= to; j+=step) { y_values.push_back(process->eval(j)); x_values.push_back(j); if (process->verbose) { cout << endl; } }
                                    data["y"] = y_values;
                                    data["x"] = x_values;
                                    return this;
                            }
                        //Erreurs
                            auto msg = "Error: Undefined call to function "+names[i] ; data[ERROR] = msg; red("\r"+msg); push(NAN) ; return this ;
                    }

            /* ============================================================================
                GESTION DES PROCESSUS
            ============================================================================ */
                //Constructeur
                    Process(string name, string var_name = "x") { id = name; var = var_name ; processes[name] = this ; } ;

                //Liste des processus définis et ceux en cours de définition
                    static map<string, Process*> processes;
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
                                    } else { auto msg = "Error: Use of reserved keyword "+name+" as function."; master()->data[ERROR] = msg; red("\r"+msg); }
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
                            Process* pop(int buffer) { a = pop() ; if (buffer == 2) { b = pop() ; } if (buffer == 3) { c = pop() ; } return this ; }

                //Nettoie la pile d'analyse
                    Process* clear () { while (!stacked.empty()) { stacked.pop() ; } return this ; }

            /* ============================================================================
                GESTION DE LA PILE D'ANALYSE (EXPRESSIONS POSTFIXEES)
            ============================================================================ */
                //Exécute le processus
                    double eval () { clear(); for (int i = 0; i < (int) tokens.size(); i++) { token(i) ; } auto tmp = (stacked.size()) ? stacked.top() : NAN ; data[RESULT] = tmp; return tmp; }
                //Evalue le processus en x
                    double eval(double x) { vars[var] = x; return eval() ; }
                //Evalue le processus de a à b par pas de step. Si ce dernier vaut 0, le pas sera calculé automatiquement
                    vector<double> eval(double a, double b, double step = 0) { step = (step) ? step : ((double) (b-a))/DEFAULT_SAMPLE ; vector<double> r ; for (double i = a; i <= b; i++) { r.push_back(eval(i)) ; } ; return r ; }

                //Résultat (json)
                    Process* jresult () {
                        //Enregistrement des variables
                            data[VARS] = vars ;
                        //
                            return this->dump() ;
                    }

            /* ============================================================================
                GESTION DE L'AFFICHAGE ET DU DEBUG
            ============================================================================ */
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
