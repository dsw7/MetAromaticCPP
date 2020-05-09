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
	std::cout << "Preprocessed contents data:" << std::endl;	
	std::cout << "-------------------------" << std::endl;
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
	std::cout << std::endl;
}

void debug_midpoints(std::vector<midpoints> *data) {
	std::cout << "Midpoint results:" << std::endl;
	std::cout << "-------------------------" << std::endl;
    for (std::vector<midpoints>::iterator it = data->begin(); it != data->end(); ++it) {
	    std::cout << it->residue << " ";
	    std::cout << it->chain << " ";
	    std::cout << it->residue_position << " ";
	    print_vector(it->midpoint, "Midpoint coordinates:");
	}
	std::cout << std::endl;
}

void debug_lone_pairs(std::vector<lone_pairs> *data) {
	std::cout << "Lone pairs results:" << std::endl;
	std::cout << "-------------------------" << std::endl;
    for (std::vector<lone_pairs>::iterator it = data->begin(); it != data->end(); ++it) {
	    std::cout << "Residue position: " << it->residue_position << std::endl;
	    print_vector(it->vector_a, "Vector a:");
	    print_vector(it->vector_g, "Vector g:");
	    print_vector(it->coord_sd, "Original SD coordinates:");
	}
	std::cout << std::endl;
}

#endif