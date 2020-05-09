#ifndef DISTANCE_ANGULAR_H
#define DISTANCE_ANGULAR_H
#include <vector>
#include <iostream>
#include "structs.h"
#include "linalg.h"

void apply_distance_angular_condition(std::vector<lone_pairs> *met_lone_pairs, std::vector<midpoints> *aromatic_midpoints, float cutoff_distance, float cutoff_angle) {
    for (std::vector<lone_pairs>::iterator it_lone_pairs = met_lone_pairs->begin(); it_lone_pairs != met_lone_pairs->end(); ++it_lone_pairs) {
	    for (std::vector<midpoints>::iterator it_midpoints = aromatic_midpoints->begin(); it_midpoints != aromatic_midpoints->end(); ++it_midpoints) {
	    	std::vector<float> vector_v;
	    	float norm_vector_v;
	    	linalg::vector_subtract(&it_midpoints->midpoint, &it_lone_pairs->coord_sd, &vector_v);
            linalg::vector_norm(&vector_v, &norm_vector_v);
            std::cout << norm_vector_v << std::endl;
            if (norm_vector_v <= cutoff_distance) {

                std::cout << it_lone_pairs->residue_position << " ";
                std::cout << it_midpoints->residue_position << " ";
                std::cout << it_midpoints->residue << " ";
                std::cout << norm_vector_v << std::endl;


            }
	    }
    }
}

#endif