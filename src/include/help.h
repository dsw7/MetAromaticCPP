#ifndef HELP_H
#define HELP_H

#include <iostream>

void print_help() {
    std::cerr << "Usage: $ ./met_aromatic --ai <pdb-code>" << std::endl;
}

void invalid_query() {
    std::cerr << "Invalid query. ";
    print_help();
}

#endif
