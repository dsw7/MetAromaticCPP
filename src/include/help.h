#ifndef HELP_H
#define HELP_H

#include <iostream>

void print_help() {
    std::cerr << "Usage: $ ./met_aromatic <--ai|--batch> ";
    std::cerr << "[code]|[path_to_batch_file, num_threads]" << std::endl;
}

void invalid_query() {
    std::cerr << "Invalid query type. ";
    print_help();
}

#endif
