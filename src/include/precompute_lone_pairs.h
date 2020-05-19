#ifndef PRECOMPUTE_LONE_PAIRS_H
#define PRECOMPUTE_LONE_PAIRS_H
#include <vector>
#include <iostream>
#include <set>
#include "structs.h"
#include "cross_product_method.h"

void get_lone_pairs_from_group(std::vector<preprocessed> *group, int residue_position, lone_pairs *lone_pair_results) {
    std::vector<float> coord_cg, coord_sd, coord_ce;
    for (std::vector<preprocessed>::iterator it = group->begin(); it != group->end(); ++it) {
        if (it->atom == "CG") {
            coord_cg = it->atomic_coords;            
        }
        else if (it->atom == "SD") {
            coord_sd = it->atomic_coords;            
        }
        else if (it->atom == "CE") {
            coord_ce = it->atomic_coords;
        }
    }

    std::vector<float> vector_a, vector_g;
    CrossProductMethod cp_lone_pairs(&coord_cg, &coord_sd, &coord_ce);
    cp_lone_pairs.get_vector_a(&vector_a);
    cp_lone_pairs.get_vector_g(&vector_g);

    lone_pair_results->vector_a = vector_a;
    lone_pair_results->vector_g = vector_g;
    lone_pair_results->coord_sd = coord_sd;
    lone_pair_results->residue_position = residue_position;
}

bool get_lone_pairs(std::vector<preprocessed> *met_data, std::vector<lone_pairs> *met_lone_pairs) {
    // get unique residue positions
    std::set<int> residue_positions;
	for (std::vector<preprocessed>::iterator it = met_data->begin(); it != met_data->end(); ++it) {
	 	residue_positions.insert(it->residue_position);
    }

    for (std::set<int>::iterator it_res = residue_positions.begin(); it_res != residue_positions.end(); ++it_res) {
        // group data according to unique residues
        std::vector<preprocessed> group;
        for (std::vector<preprocessed>::iterator it = met_data->begin(); it != met_data->end(); ++it) {
            if(it->residue_position == *it_res) {
                group.push_back(*it);
            }
        }

        if (group.size() != 3) {
            return false;
        }

        // get the lone pairs from the groups
        lone_pairs lone_pair_results;
        get_lone_pairs_from_group(&group, *it_res, &lone_pair_results);
        met_lone_pairs->push_back(lone_pair_results);
    }
    return true;
}

#endif
