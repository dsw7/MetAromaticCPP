#ifndef PRINT_H
#define PRINT_H
#include <iostream>
#include <vector>
#include "structs.h"

void print_results(std::vector<results_single_interaction> *results) {
    for (std::vector<results_single_interaction>::iterator it = results->begin(); it != results->end(); ++it) {
        std::cout << it->aromatic_residue << " ";
        std::cout << it->aromatic_residue_position << " ";
        std::cout << it->methionine_residue << " ";
        std::cout << it->methionine_residue_position << " ";
        std::cout << it->norm << " ";
        std::cout << it->met_theta << " ";
        std::cout << it->met_phi << " ";
        std::cout << std::endl;
    }
}

#endif