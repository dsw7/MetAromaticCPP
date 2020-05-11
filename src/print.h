#ifndef PRINT_H
#define PRINT_H

#include <string>
#include <iostream>
#include <vector>
#include "structs.h"

void print_stdout(std::string msg) {
	std::cout << msg << std::endl;
}

void print_stderr(std::string msg) {
	std::cerr << msg << std::endl;
}

void print_results(std::vector<met_aromatic_results> *results) {
    for (std::vector<met_aromatic_results>::iterator it = results->begin(); it != results->end(); ++it) {
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