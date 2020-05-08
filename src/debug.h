#ifndef DEBUG_H
#define DEBUG_H
#include <iostream>
#include <vector>
#include "structs.h"

void debug_preprocessed(std::vector<preprocessed> *data) {
    for (std::vector<preprocessed>::iterator it = data->begin(); it != data->end(); ++it) {
	    std::cout << it->residue << " ";
	    std::cout << it->atom << " ";
	    std::cout << it->chain << " ";
	    std::cout << it->residue_position << " ";
	    std::cout << it->x_coord << " ";
	    std::cout << it->y_coord << " ";
	    std::cout << it->z_coord << " ";
	    std::cout << std::endl;
	}
}

void debug_midpoints(std::vector<midpoints> *data) {
    for (std::vector<midpoints>::iterator it = data->begin(); it != data->end(); ++it) {
	    std::cout << it->residue << " ";
	    std::cout << it->chain << " ";
	    std::cout << it->residue_position << " ";
	    std::cout << it->x_coord << " ";
	    std::cout << it->y_coord << " ";
	    std::cout << it->z_coord << " ";
	    std::cout << std::endl;
	}
}

#endif