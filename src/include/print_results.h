#ifndef PRINT_RESULTS_H
#define PRINT_RESULTS_H

#include <iostream>
#include "structs.h"

void print_csv_results(std::vector<results_single_interaction> *results) {
    std::cout << "ARO-RES,ARO-POS,MET-RES,NORM,MET-THETA,MET-PHI" << std::endl;
    for (std::vector<results_single_interaction>::iterator it = results->begin(); it != results->end(); ++it) {
        std::cout << it->aromatic_residue << ",";
        std::cout << it->aromatic_position << ",";
        std::cout << it->methionine_position << ",";
        std::cout << it->norm << ",";
        std::cout << it->met_theta_angle << ",";
        std::cout << it->met_phi_angle << std::endl;
    }
}

void print_pretty_results(std::vector<results_single_interaction> *results) {
    for (std::vector<results_single_interaction>::iterator it = results->begin(); it != results->end(); ++it) {
        std::cout << "Aromatic residue:      " << it->aromatic_residue << std::endl;
        std::cout << "Aromatic position:     " << it->aromatic_position << std::endl;
        std::cout << "Methionine position:   " << it->methionine_position << std::endl;
        std::cout << "Norm (Angstroms):      " << it->norm << std::endl;
        std::cout << "Met-theta angle (deg): " << it->met_theta_angle << std::endl;
        std::cout << "Met-phi angle (deg):   " << it->met_phi_angle << std::endl;
        std::cout << std::endl;
    }
}

#endif