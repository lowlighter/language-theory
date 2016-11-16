#include "parser.hpp"
#include <iostream>

extern double eval(double x, bool verbose = false);
extern int yy_scan_string(const char *);

int main(int argc, char const *argv[]) {

    yy_scan_string("x*2");
    yyparse();

    //std::cout << "====" << std::endl ;
    //for (int i = 0; i < 10; i ++) {
    //    std::cout << i << " = " << eval(i) << std::endl ;
    //}

}
