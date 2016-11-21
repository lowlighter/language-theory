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
                        //Utilitaire permettant de déterminer si le nom de la variable est reservé ou non
                            bool reserved(string name) { return (find(RESERVED.begin(), RESERVED.end(), name) != RESERVED.end()) ; }

                //Précision des nombres flottants
                    static const int PRECISION = 10000 ;

                //Signes
                    static const int NEG = -1 ;
                    static const int POS = +1 ;

                //Mode verbeux
                    bool verbose = false ;

                //Résultats (au format json)
                    static const string RESULT ;
                    static const string VARS ;
                    static const string ANSWER ;
                    static const string GRAPH ;
                    json data;

            /* ============================================================================
                GESTION DES TOKENS
            ============================================================================ */
                //Liste des tokens
                    vector<int> tokens ;
                //Valeurs des tokens
                    vector<double> values ;
                //Liste des noms
                    vector<string> names ;

                //Enregistre dans les listes appropriées le token, sa valeur et son nom
                    Process* store(int token, double value = 0, string name = "") { tokens.push_back(token) ; values.push_back(value) ; names.push_back(name) ; }
                        //Raccourci pour stocker les tokens sans valeurs
                            Process* store(int token, string name) { store(token, NAN, name) ; }

            /* ============================================================================
                GESTION DE LA NOTATION POSTFIXEE
            ============================================================================ */
                //Liste des variables déclarées
                    map<string, double> vars ;

                //Pile de l'analyse sémantique
                    stack<double> stacked ;
                        //Retourne la dernière valeur de la pile et la retire de celle-ci
                            double pop () { auto tmp = stacked.top() ; stacked.pop() ; return tmp ; }
                                //Raccourci pour faire pop jusqu'a 3 valeurs de la pule
                                    double a = 0, b = 0, c = 0;
                                    Process* pop(int buffer) { a = pop() ; if (buffer == 2) { b = pop() ; } if (buffer == 3) { c = pop() ; } return this ; }
                        //Rajoute une valeur à la pile
                            Process* push (double value) { stacked.push(value) ; return this ; }
                            Process* clear () { vars.clear() ; while (!stacked.empty()) { stacked.pop() ; } ; return this ; }

                //Méthode d'évaluation
                    Process* eval () { clear() ; for (int i = 0; i < tokens.size(); i++) { token(i) ; } ; return jresult() ; }
                        //Méthode à implémenter dans le parser qui permet de gérer les actions à effectuer selon les différents tokens
                            Process* token(int i);
                        //Retourne le réusultat final des entrées
                            double result() { return (stacked.size()) ? stacked.top() : NAN ; }
                        //Résultat (json)
                            Process* jresult () {
                                data[RESULT] = result() ;
                                data[VARS] = vars ;
                                data[GRAPH] = false ;
                                return this->dump() ;
                            }

                //Affiche la notation polonaise si le mode verbeux est actif
                    Process* display(string action) { if (verbose) { cout << " " << action ; } ; return this ; }

                //Affiche le contenu des données json
                    Process* dump() { cout << data.dump() << endl ; return this ; }

            /* ============================================================================
                GESTION DES ACTIONS
            ============================================================================ */
                //Fin de ligne : Met à jour la variable "ANSWER"
                    Process* eol() { vars[ANSWER] = result() ; return display(";\n") ; }

                //Gestion des nombres et de leurs signes
                    Process* number(int i) { return display(to_string(values[i]))->push(values[i]) ; } //string()
                    Process* sign(int i) { return display((values[i] > 0 ? "(+)" : "(-)"))->pop(1)->push(values[i]*a) ; }

                //Opération basiques
                    Process* add() { this->pop(2) ; return display("+")->push(a + b) ; }
                    Process* sub() { this->pop(2) ; return display("-")->push(a - b) ; }
                    Process* mul() { this->pop(2) ; return display("*")->push(a * b) ; }
                    Process* div() { this->pop(2) ; return display("/")->push(a / b) ; }

                //Opération non repertoriée
                    Process* unknown() { return display("?") ; }

                //Fonction
                    Process* pow() { this->pop(2) ; return display("^")->push(std::pow(b, a)) ; }
                    Process* sqrt() { this->pop(1) ; return display("SQRT")->push(std::sqrt(a)) ; }

                //Trigonométrie
                    Process* cos() { this->pop(1) ; return display("COS")->push(round(PRECISION*std::cos(a))/PRECISION) ; }
                    Process* sin() { this->pop(1) ; return display("SIN")->push(round(PRECISION*std::sin(b))/PRECISION) ; }

                //Gestion des variables
                    Process* affect(int i) {
                        if (!reserved(names[i])) { vars[names[i]] = pop() ; return display("="+names[i]) ; }
                        cout << "\nError: Use of reserved keyword " << names[i] << " as variable." << endl ; return this ;
                    }

                    Process* variable(int i) {
                        if (vars.count(names[i])) { return display(names[i]+"="+to_string(vars[names[i]]))->push(vars[names[i]]) ; }
                        cout << endl << "Error: Undefined variable "+names[i] << endl ; push(NAN) ; return this ;
                    }
        };
    //Noms des champs
        const string Process::RESULT = "result";
        const string Process::VARS = "vars";
        const string Process::ANSWER = "ans";
        const string Process::GRAPH = "graph";
    //Mots réservés
        vector<string> Process::RESERVED = {"TEST"} ;
#endif
