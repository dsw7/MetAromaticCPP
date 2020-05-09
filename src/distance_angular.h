#ifndef DISTANCE_ANGULAR_H
#define DISTANCE_ANGULAR_H
#include <vector>
#include "structs.h"
#include "linalg.h"

void apply_distance_angular_condition(std::vector<lone_pairs> *met_lone_pairs, std::vector<midpoints> *aromatic_midpoints, float cutoff_distance, float cutoff_angle) {
    for (std::vector<lone_pairs>::iterator it_lone_pairs = met_lone_pairs->begin(); it_lone_pairs != met_lone_pairs->end(); ++it_lone_pairs) {
	    for (std::vector<midpoints>::iterator it_midpoints = aromatic_midpoints->begin(); it_midpoints != aromatic_midpoints->end(); ++it_midpoints) {
	    	std::vector<float> vector_v;
	    	float norm;
            linalg::vector_norm(&vector_v, &norm);
	    }
    }


    /*
    for (std::vector<preprocessed>::iterator it_sd = met_data->begin(); it_sd != met_data->end(); ++it_sd) {
        if (it_sd->atom == "SD") {
            for (std::vector<midpoints>::iterator it_mp = midpoint_data->begin(); it_mp != midpoint_data->end(); ++it_mp) {
                float norm;
                std::vector<float> vector_v = {
                    it_mp->x_coord - it_sd->x_coord,
                    it_mp->y_coord - it_sd->y_coord,
                    it_mp->z_coord - it_sd->z_coord
                };
                linalg::vector_norm(&vector_v, &norm);
                if (norm <= cutoff) {
                    std::cout << it_sd->residue_position << " ";
                    std::cout << it_mp->residue_position << " ";
                    std::cout << it_mp->residue << " ";
                    std::cout << norm << std::endl;
                }
            }
        }
    }
    */
}


#endif