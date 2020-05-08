#ifndef DEBUG_H
#define DEBUG_H
#include <iostream>
#include <vector>
#include "structs.h"

void print_vector(std::vector<float> vec, std::string msg) {
	std::cout << msg << " ";
    for (std::vector<float>::iterator it = vec.begin(); it != vec.end(); ++it) {
	    std::cout << *it << " ";
	}	
	std::cout << std::endl;
}

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

void debug_lone_pairs(std::vector<lone_pairs> *data) {
    for (std::vector<lone_pairs>::iterator it = data->begin(); it != data->end(); ++it) {
	    std::cout << "Residue position: " << it->residue_position << std::endl;
	    print_vector(it->vector_a, "Vector a:");
	    print_vector(it->vector_g, "Vector g:");
	    print_vector(it->coord_sd, "SD coordinates:");
	}
}

#endif