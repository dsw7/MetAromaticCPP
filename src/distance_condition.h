#ifndef CUTOFF_DISTANCE_H
#define CUTOFF_DISTANCE_H
#include <cmath>
#include <iostream>
#include "structs.h"


void norm_vector(std::vector<float> *input_vec, float *norm) {
    double squares = 0.0;
    for (std::vector<float>::iterator it = input_vec->begin(); it != input_vec->end(); ++it) {
        squares += pow(*it, 2);
    }
    *norm = pow(squares, 0.5);
}


void apply_distance_condition(std::vector<preprocessed> *met_data,
                              std::vector<midpoints> *midpoint_data,
                              float cutoff) {
    for (std::vector<preprocessed>::iterator it_sd = met_data->begin(); it_sd != met_data->end(); ++it_sd) {
        if (it_sd->atom == "SD") {
            for (std::vector<midpoints>::iterator it_mp = midpoint_data->begin(); it_mp != midpoint_data->end(); ++it_mp) {
                float norm;
                std::vector<float> vector_v = {
                    it_mp->x_coord - it_sd->x_coord,
                    it_mp->y_coord - it_sd->y_coord,
                    it_mp->z_coord - it_sd->z_coord
                };
                norm_vector(&vector_v, &norm);
                if (norm <= cutoff) {
                    std::cout << it_sd->residue_position << " ";
                    std::cout << it_mp->residue_position << " ";
                    std::cout << it_mp->residue << " ";
                    std::cout << norm << std::endl;
                }
            }
        }
    }
}

#endif