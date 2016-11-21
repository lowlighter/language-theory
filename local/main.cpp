#include "parser.hpp"
#include <iostream>

extern int yy_scan_string(const char *);

int main(int argc, char const *argv[]) {
    yyparse();
    return EXIT_SUCCESS;
}
