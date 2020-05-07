#ifndef PRECOMPUTE_LONE_PAIRS_H
#define PRECOMPUTE_LONE_PAIRS_H

#include <vector>
#include <iostream>
#include "structs.h"


void debug_preprocessed(std::vector<preprocessed>::iterator inst) {
    std::cout << inst->residue << " ";
    std::cout << inst->atom << " ";
    std::cout << inst->chain << " ";
    std::cout << inst->residue_position << " ";
    std::cout << inst->x_coord << " ";
    std::cout << inst->y_coord << " ";
    std::cout << inst->z_coord << " ";
    std::cout << std::endl;
}

void get_lone_pairs(std::vector<preprocessed> *met_data) {
	for (std::vector<preprocessed>::iterator it = met_data->begin(); it != met_data->end(); ++it) {
	    debug_preprocessed(it);
    }
}

#endif