%{
  #include <iostream>
  #include <vector>
  #include <string>

  using namespace std;

  vector<string> tokens;

%}

%%
("+"|"-"|"*"|"/")     {tokens.push_back("operator");}
[0-9]+                {tokens.push_back("number");}
%%

int yywrap() {return 1;}

int main(int argc, char *argv[]) {
  yylex();
  for(auto elt : tokens) {
    cout << elt << endl;
  }
  return 0;
}
