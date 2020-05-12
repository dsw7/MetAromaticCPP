#ifndef DISTANCE_ANGULAR_H
#define DISTANCE_ANGULAR_H
#include <vector>
#include <iostream>
#include "structs.h"
#include "linalg.h"
#include "debug.h"

void apply_distance_angular_condition(std::vector<lone_pairs> *met_lone_pairs,
                                      std::vector<midpoints> *aromatic_midpoints,
                                      float cutoff_distance,
                                      float cutoff_angle,
                                      std::vector<results_single_interaction> *results) {
    for (std::vector<lone_pairs>::iterator it_lone_pairs = met_lone_pairs->begin(); it_lone_pairs != met_lone_pairs->end(); ++it_lone_pairs) {
	    for (std::vector<midpoints>::iterator it_midpoints = aromatic_midpoints->begin(); it_midpoints != aromatic_midpoints->end(); ++it_midpoints) {
	    	std::vector<float> vector_v;
	    	float norm_vector_v;
	    	linalg::vector_subtract(&it_midpoints->midpoint, &it_lone_pairs->coord_sd, &vector_v);
            linalg::vector_norm(&vector_v, &norm_vector_v);
            if (norm_vector_v <= cutoff_distance) {
                float met_theta, met_phi;
                linalg::vector_angle(&vector_v, &it_lone_pairs->vector_a, &met_theta);
                linalg::vector_angle(&vector_v, &it_lone_pairs->vector_g, &met_phi);
                if (met_theta <= cutoff_angle || met_phi <= cutoff_angle) {
                    results_single_interaction vec_results;
                    vec_results.aromatic_residue = it_midpoints->residue;
                    vec_results.aromatic_residue_position = it_midpoints->residue_position;
                    vec_results.methionine_residue = "MET";
                    vec_results.methionine_residue_position = it_lone_pairs->residue_position;
                    vec_results.norm = norm_vector_v;
                    vec_results.met_theta = met_theta;
                    vec_results.met_phi = met_phi;
                    results->push_back(vec_results);
                }
            }
	    }
    }
}

#endif