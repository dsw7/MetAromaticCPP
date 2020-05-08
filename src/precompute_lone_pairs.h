#ifndef PRECOMPUTE_LONE_PAIRS_H
#define PRECOMPUTE_LONE_PAIRS_H
#include <vector>
#include <iostream>
#include <set>
#include "structs.h"
#include "linalg.h"



void get_lone_pairs_from_group(std::vector<preprocessed> *group) {
    std::vector<float> coord_cg, coord_sd, coord_ce;
    for (std::vector<preprocessed>::iterator it = group->begin(); it != group->end(); ++it) {
        if (it->atom == "CG") {
            coord_ce = {it->x_coord, it->y_coord, it->z_coord};
        }
        else if (it->atom == "SD") {
            coord_sd = {it->x_coord, it->y_coord, it->z_coord};
        }
        else if (it->atom == "CE") {
            coord_cg = {it->x_coord, it->y_coord, it->z_coord};
        }
    }

    std::vector<float> vector_a, vector_g;
    linalg::vector_subtract(&coord_ce, &coord_sd, &vector_a);
    linalg::vector_subtract(&coord_cg, &coord_sd, &vector_g);
}

void get_lone_pairs(std::vector<preprocessed> *met_data) {
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

        get_lone_pairs_from_group(&group);
    }
}

#endif